#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "battle_gimmick.h"
#include "battle_z_move.h"
#include "battle_setup.h"
#include "battle_util.h"
#include "item.h"
#include "palette.h"
#include "pokemon.h"
#include "sprite.h"
#include "util.h"
#include "test_runner.h"

#include "data/gimmicks.h"

// Populates gBattleStruct->gimmick.usableGimmick for each battler.
void AssignUsableGimmicks(void)
{
    u32 battler, gimmick;
    for (battler = 0; battler < gBattlersCount; ++battler)
    {
        gBattleStruct->gimmick.usableGimmick[battler] = GIMMICK_NONE;
        for (gimmick = 0; gimmick < GIMMICKS_COUNT; ++gimmick)
        {
            if (CanActivateGimmick(battler, gimmick))
            {
                gBattleStruct->gimmick.usableGimmick[battler] = gimmick;
                break;
            }
        }
    }
}

// Returns whether a battler is able to use a gimmick. Checks consumption and gimmick specific functions.
bool32 CanActivateGimmick(u32 battler, enum Gimmick gimmick)
{
    return gGimmicksInfo[gimmick].CanActivate != NULL && gGimmicksInfo[gimmick].CanActivate(battler);
}

// Returns whether the player has a gimmick selected while in the move selection menu.
bool32 IsGimmickSelected(u32 battler, enum Gimmick gimmick)
{
    // There's no player select in tests, but some gimmicks need to test choice before they are fully activated.
    if (TESTING)
        return (gBattleStruct->gimmick.toActivate & (1u << battler)) && gBattleStruct->gimmick.usableGimmick[battler] == gimmick;
    else
        return gBattleStruct->gimmick.usableGimmick[battler] == gimmick && gBattleStruct->gimmick.playerSelect;
}

// Sets a battler as having a gimmick active using their party index.
void SetActiveGimmick(u32 battler, enum Gimmick gimmick)
{
    gBattleStruct->gimmick.activeGimmick[GetBattlerSide(battler)][gBattlerPartyIndexes[battler]] = gimmick;
}

// Returns a battler's active gimmick, if any.
enum Gimmick GetActiveGimmick(u32 battler)
{
    return gBattleStruct->gimmick.activeGimmick[GetBattlerSide(battler)][gBattlerPartyIndexes[battler]];
}

// Returns whether a trainer mon is intended to use an unrestrictive gimmick via .useGimmick (i.e Tera).
bool32 ShouldTrainerBattlerUseGimmick(u32 battler, enum Gimmick gimmick)
{
    // There are no trainer party settings in battles, but the AI needs to know which gimmick to use.
    if (TESTING)
    {
        return gimmick == TestRunner_Battle_GetChosenGimmick(GetBattlerSide(battler), gBattlerPartyIndexes[battler]);
    }
    // The player can bypass these checks because they can choose through the controller.
    else if (IsOnPlayerSide(battler)
         && !((gBattleTypeFlags & BATTLE_TYPE_MULTI) && battler == B_POSITION_PLAYER_RIGHT))
    {
        return TRUE;
    }
    // Check the trainer party data to see if a gimmick is intended.
    else
    {
        if (gimmick == GIMMICK_TERA && gBattleStruct->opponentMonCanTera & 1 << gBattlerPartyIndexes[battler])
            return TRUE;
        if (gimmick == GIMMICK_DYNAMAX && gBattleStruct->opponentMonCanDynamax & 1 << gBattlerPartyIndexes[battler])
            return TRUE;
    }

    return FALSE;
}

// Returns whether a trainer has used a gimmick during a battle.
bool32 HasTrainerUsedGimmick(u32 battler, enum Gimmick gimmick)
{
    if (IsDoubleBattle() && IsPartnerMonFromSameTrainer(battler))
    {
        u32 partner = BATTLE_PARTNER(battler);
        if (gBattleStruct->gimmick.activated[partner][gimmick]
         || ((gBattleStruct->gimmick.toActivate & (1u << partner)) && gBattleStruct->gimmick.usableGimmick[partner] == gimmick))
            return TRUE;
    }

    return gBattleStruct->gimmick.activated[battler][gimmick];
}

// Sets a gimmick as used by a trainer with checks for Multi Battles.
void SetGimmickAsActivated(u32 battler, enum Gimmick gimmick)
{
    gBattleStruct->gimmick.activated[battler][gimmick] = TRUE;
    if (IsDoubleBattle() && IsPartnerMonFromSameTrainer(battler))
        gBattleStruct->gimmick.activated[BATTLE_PARTNER(battler)][gimmick] = TRUE;
}

#define SINGLES_GIMMICK_TRIGGER_POS_X_OPTIMAL (34)
#define SINGLES_GIMMICK_TRIGGER_POS_X_SLIDE (16)
#define SINGLES_GIMMICK_TRIGGER_POS_Y_DIFF (-7)

#define DOUBLES_GIMMICK_TRIGGER_POS_X_OPTIMAL (34)
#define DOUBLES_GIMMICK_TRIGGER_POS_X_SLIDE (16)
#define DOUBLES_GIMMICK_TRIGGER_POS_Y_DIFF (-3)

#define GIMMICK_TRIGGER_SLIDE_SPEED 2

#define tBattler      data[0]
#define tHide         data[1]
#define tSelectBounce data[2]

static const s8 sGimmickTriggerSelectBounce[] = {-1, -2, -2, -1, 0, 1, 0};

static s32 GetGimmickTriggerSlideMovement(s32 currentX, s32 targetX)
{
    if (currentX < targetX)
        return min(GIMMICK_TRIGGER_SLIDE_SPEED, targetX - currentX);
    if (currentX > targetX)
        return -min(GIMMICK_TRIGGER_SLIDE_SPEED, currentX - targetX);
    return 0;
}

void ChangeGimmickTriggerSprite(u32 spriteId, u32 animId)
{
    struct Sprite *sprite;

    if (spriteId >= MAX_SPRITES || !gSprites[spriteId].inUse)
        return;

    sprite = &gSprites[spriteId];
    if (sprite->animNum != animId)
    {
        StartSpriteAnim(sprite, animId);
        sprite->tSelectBounce = ARRAY_COUNT(sGimmickTriggerSelectBounce);
    }
}

void CreateGimmickTriggerSprite(u32 battler)
{
    const struct GimmickInfo * gimmick = &gGimmicksInfo[gBattleStruct->gimmick.usableGimmick[battler]];
    const struct SpriteSheet *triggerSheet = gimmick->triggerSheet;
    u32 paletteNum;
    u16 tileStart;

    if (GetBattlerCoordsIndex(battler) == BATTLE_COORDS_DOUBLES && gimmick->triggerSheetDoubles != NULL)
        triggerSheet = gimmick->triggerSheetDoubles;

    // Exit if there shouldn't be a sprite produced.
    if (!IsOnPlayerSide(battler)
     || gBattleStruct->gimmick.usableGimmick[battler] == GIMMICK_NONE
     || triggerSheet == NULL
     || HasTrainerUsedGimmick(battler, gBattleStruct->gimmick.usableGimmick[battler]))
    {
        return;
    }

    // Both resource grabs below would otherwise fail silently, and battle runs
    // the OBJ palette table right to its limit: the trigger currently lands in
    // the last free slot, so the next feature that wants one during move
    // selection would make this icon vanish with no other symptom.
    paletteNum = LoadSpritePalette(gimmick->triggerPal);
    if (paletteNum == 0xFF)
    {
        DebugPrintfLevel(MGBA_LOG_ERROR, "GIMMICK TRIGGER: no free OBJ palette slot for tag 0x%04X", gimmick->triggerPal->tag);
        return;
    }

    // Every trigger uses the same tags so the existing allocation can be reused.
    // Refresh both resources when changing battlers, otherwise quickly moving
    // between two different gimmicks can show the previous icon or palette.
    LoadPalette(gimmick->triggerPal->data, OBJ_PLTT_ID(paletteNum), PLTT_SIZE_4BPP);

    tileStart = GetSpriteTileStartByTag(TAG_GIMMICK_TRIGGER_TILE);
    if (tileStart == 0xFFFF)
    {
        LoadSpriteSheet(triggerSheet);
        tileStart = GetSpriteTileStartByTag(TAG_GIMMICK_TRIGGER_TILE);
        if (tileStart == 0xFFFF)
        {
            DebugPrintfLevel(MGBA_LOG_ERROR, "GIMMICK TRIGGER: no free OBJ VRAM for %d bytes (tag 0x%04X)",
                             triggerSheet->size, TAG_GIMMICK_TRIGGER_TILE);
            return;
        }
    }
    else
    {
        CpuCopy32(triggerSheet->data,
                  (void *)(OBJ_VRAM0 + TILE_SIZE_4BPP * tileStart),
                  triggerSheet->size);
    }

    if (gBattleStruct->gimmick.triggerSpriteId == 0xFF)
    {
        if (GetBattlerCoordsIndex(battler) == BATTLE_COORDS_DOUBLES)
            gBattleStruct->gimmick.triggerSpriteId = CreateSprite(gimmick->triggerTemplate,
                                                                  gSprites[gHealthboxSpriteIds[battler]].x - DOUBLES_GIMMICK_TRIGGER_POS_X_SLIDE,
                                                                  gSprites[gHealthboxSpriteIds[battler]].y - DOUBLES_GIMMICK_TRIGGER_POS_Y_DIFF, 0);
        else
            gBattleStruct->gimmick.triggerSpriteId = CreateSprite(gimmick->triggerTemplate,
                                                                  gSprites[gHealthboxSpriteIds[battler]].x - SINGLES_GIMMICK_TRIGGER_POS_X_SLIDE,
                                                                  gSprites[gHealthboxSpriteIds[battler]].y - SINGLES_GIMMICK_TRIGGER_POS_Y_DIFF, 0);

        if (gBattleStruct->gimmick.triggerSpriteId >= MAX_SPRITES)
        {
            gBattleStruct->gimmick.triggerSpriteId = 0xFF;
            return;
        }
    }

    gSprites[gBattleStruct->gimmick.triggerSpriteId].tBattler = battler;
    gSprites[gBattleStruct->gimmick.triggerSpriteId].tHide = FALSE;
    gSprites[gBattleStruct->gimmick.triggerSpriteId].oam.paletteNum = paletteNum;

    ChangeGimmickTriggerSprite(gBattleStruct->gimmick.triggerSpriteId, 0);
}

bool32 IsGimmickTriggerSpriteActive(void)
{
    if (GetSpriteTileStartByTag(TAG_GIMMICK_TRIGGER_TILE) == 0xFFFF)
        return FALSE;
    else if (IndexOfSpritePaletteTag(TAG_GIMMICK_TRIGGER_PAL) != 0xFF)
        return TRUE;
    else
        return FALSE;
}

bool32 IsGimmickTriggerSpriteMatchingBattler(u32 battler)
{
    if (battler == gSprites[gBattleStruct->gimmick.triggerSpriteId].tBattler)
        return TRUE;
    return FALSE;
}

void HideGimmickTriggerSprite(void)
{
    if (gBattleStruct->gimmick.triggerSpriteId != 0xFF)
    {
        ChangeGimmickTriggerSprite(gBattleStruct->gimmick.triggerSpriteId, 0);
        gSprites[gBattleStruct->gimmick.triggerSpriteId].tHide = TRUE;
        gSprites[gBattleStruct->gimmick.triggerSpriteId].tSelectBounce = 0;
    }
}

void DestroyGimmickTriggerSprite(void)
{
    if (gBattleStruct->gimmick.triggerSpriteId != 0xFF)
        DestroySprite(&gSprites[gBattleStruct->gimmick.triggerSpriteId]);
    gBattleStruct->gimmick.triggerSpriteId = 0xFF;
    FreeSpritePaletteByTag(TAG_GIMMICK_TRIGGER_PAL);
    FreeSpriteTilesByTag(TAG_GIMMICK_TRIGGER_TILE);
}

static void SpriteCb_GimmickTrigger(struct Sprite *sprite)
{
    s32 xSlide, xOptimal;
    s32 targetX;
    s32 yDiff;
    s32 bounceOffset = 0;
    struct Sprite *healthbox = &gSprites[gHealthboxSpriteIds[sprite->tBattler]];
    s32 xHealthbox = healthbox->x;

    if (GetBattlerCoordsIndex(sprite->tBattler) == BATTLE_COORDS_DOUBLES)
    {
        xSlide = DOUBLES_GIMMICK_TRIGGER_POS_X_SLIDE;
        xOptimal = DOUBLES_GIMMICK_TRIGGER_POS_X_OPTIMAL;
        yDiff = DOUBLES_GIMMICK_TRIGGER_POS_Y_DIFF;
    }
    else
    {
        xSlide = SINGLES_GIMMICK_TRIGGER_POS_X_SLIDE;
        xOptimal = SINGLES_GIMMICK_TRIGGER_POS_X_OPTIMAL;
        yDiff = SINGLES_GIMMICK_TRIGGER_POS_Y_DIFF;
    }

    if (sprite->tHide)
    {
        targetX = xHealthbox - xSlide;
        sprite->x += GetGimmickTriggerSlideMovement(sprite->x, targetX);
        if (sprite->x == targetX)
        {
            DestroyGimmickTriggerSprite();
            return;
        }
    }
    else
    {
        // Edge case: in doubles, if selecting move and next mon's action too fast, the second battler's gimmick icon uses the x from the first battler's gimmick icon
        if (sprite->y != healthbox->y - yDiff)
            sprite->x = xHealthbox - xSlide;

        targetX = xHealthbox - xOptimal;
        sprite->x += GetGimmickTriggerSlideMovement(sprite->x, targetX);
    }

    // Keep the trigger behind the healthbox for the entire transition. The
    // solid pointed cap masks it naturally instead of a priority swap flashing
    // one frame of the icon across the bar.
    sprite->oam.priority = 2;

    sprite->y = healthbox->y - yDiff;

    if (sprite->tSelectBounce > 0)
    {
        u32 frame = ARRAY_COUNT(sGimmickTriggerSelectBounce) - sprite->tSelectBounce;
        bounceOffset = sGimmickTriggerSelectBounce[frame];
        sprite->tSelectBounce--;
    }

    // y already carries the static layout offset; y2 should only follow the
    // healthbox bounce plus the brief selection response.
    sprite->y2 = healthbox->y2 + bounceOffset;
}

#undef tBattler
#undef tHide
#undef tSelectBounce

// for sprite data fields
#define tBattler        data[0]
#define tPosX           data[2]
#define tLevelXDelta    data[3] // X position depends whether level has 3, 2 or 1 digit

// data fields for healthboxMain
// oam.affineParam holds healthboxRight spriteId
#define hMain_Battler               data[6]

void LoadIndicatorSpritesGfx(void)
{
    LoadSpritePalette(&sSpritePalette_MiscIndicator);
    LoadSpritePalette(&sSpritePalette_MegaIndicator);
    LoadSpritePalette(&sSpritePalette_TeraIndicator);
}

static void SpriteCb_GimmickIndicator(struct Sprite *sprite)
{
    u32 battler = sprite->tBattler;

    sprite->x = gSprites[gHealthboxSpriteIds[battler]].x + sprite->tPosX + sprite->tLevelXDelta;
    sprite->x2 = gSprites[gHealthboxSpriteIds[battler]].x2;
    sprite->y2 = gSprites[gHealthboxSpriteIds[battler]].y2;
}

static inline u32 GetIndicatorSpriteId(u32 healthboxId)
{
    return gBattleStruct->gimmick.indicatorSpriteId[gSprites[healthboxId].hMain_Battler];
}

const u32 *GetIndicatorSpriteSrc(u32 battler)
{
    u32 gimmick = GetActiveGimmick(battler);

    if (IsBattlerPrimalReverted(battler))
    {
        if (gBattleMons[battler].species == SPECIES_GROUDON_PRIMAL)
            return (u32 *)&sOmegaIndicatorGfx;
        else
            return (u32 *)&sAlphaIndicatorGfx;
    }
    else if (gimmick == GIMMICK_TERA) // special case
    {
        return (u32 *)sTeraIndicatorDataPtrs[GetBattlerTeraType(battler)];
    }
    else if (gGimmicksInfo[gimmick].indicatorData != NULL)
    {
        return (u32 *)gGimmicksInfo[gimmick].indicatorData;
    }
    else
    {
        return NULL;
    }
}

const u32 *GetTeraIndicatorSpriteSrc(u32 type)
{
    if (type >= ARRAY_COUNT(sTeraIndicatorDataPtrs))
        type = TYPE_NORMAL;
    return (const u32 *)sTeraIndicatorDataPtrs[type];
}

u32 GetIndicatorPalTag(u32 battler)
{
    u32 gimmick = GetActiveGimmick(battler);
    if (IsBattlerPrimalReverted(battler))
        return TAG_MISC_INDICATOR_PAL;
    else if (gGimmicksInfo[gimmick].indicatorPalTag != 0)
        return gGimmicksInfo[gimmick].indicatorPalTag;
    else
        return TAG_NONE;
}

#define INDICATOR_SIZE (8 * 16 / 2)

static const struct SpritePalette *GetIndicatorSpritePalette(u32 palTag)
{
    switch (palTag)
    {
    case TAG_MEGA_INDICATOR_PAL:
        return &sSpritePalette_MegaIndicator;
    case TAG_TERA_INDICATOR_PAL:
        return &sSpritePalette_TeraIndicator;
    default:
        return &sSpritePalette_MiscIndicator;
    }
}

void UpdateIndicatorVisibilityAndType(u32 healthboxId, bool32 invisible)
{
    u32 battler = gSprites[healthboxId].hMain_Battler;
    u32 palTag = GetIndicatorPalTag(battler);
    struct Sprite *sprite = &gSprites[GetIndicatorSpriteId(healthboxId)];

    if (GetIndicatorSpriteId(healthboxId) == 0) // safari zone means the player doesn't have an indicator sprite id
        return;

    if (palTag != TAG_NONE)
    {
        u32 palSlot = IndexOfSpritePaletteTag(palTag);

        // Battle anims can leave this slot blended in gPlttBufferFaded, and nothing
        // re-syncs sprite palettes mid-battle, so rewrite the colors on every update.
        // Skipped during fades: LoadPalette would overwrite the faded buffer at full
        // brightness, and the fade itself restores the slot from the unfaded buffer.
        if (palSlot != 0xFF && !gPaletteFade.active)
            LoadPalette(GetIndicatorSpritePalette(palTag)->data, OBJ_PLTT_ID(palSlot), PLTT_SIZE_4BPP);

        sprite->oam.paletteNum = palSlot;
        sprite->invisible = invisible;

        u32 *dst = (u32 *)(OBJ_VRAM0 + TILE_SIZE_4BPP * GetSpriteTileStartByTag(BATTLER_INDICATOR_TAG + battler));

        const u32 *src = GetIndicatorSpriteSrc(battler);

        for (u32 i = 0; i < INDICATOR_SIZE / 4; i++)
            dst[i] = src[i];
    }
    else // in case of error
    {
        sprite->invisible = TRUE;
    }
}

#undef INDICATOR_SIZE

void UpdateIndicatorOamPriority(u32 healthboxId, u32 oamPriority)
{
    gSprites[GetIndicatorSpriteId(healthboxId)].oam.priority = oamPriority;
}

void UpdateIndicatorLevelData(u32 healthboxId, u32 level)
{
    s32 xDelta = 0;

    if (level >= 100)
        xDelta -= 4;
    else if (level < 10)
        xDelta += 5;

    gSprites[GetIndicatorSpriteId(healthboxId)].tLevelXDelta = xDelta;
}

static const s8 sIndicatorPositions[][2] =
{
    [B_POSITION_PLAYER_LEFT] = {49, -9},
    [B_POSITION_OPPONENT_LEFT] = {40, -9},
    [B_POSITION_PLAYER_RIGHT] = {48, -9},
    [B_POSITION_OPPONENT_RIGHT] = {40, -9},
};

void CreateIndicatorSprite(u32 battler)
{
    u32 position, spriteId;
    s16 xHealthbox = 0, x = 0, y = 0;

    position = GetBattlerPosition(battler);
    GetBattlerHealthboxCoords(battler, &xHealthbox, &y);

    x = sIndicatorPositions[position][0];
    y += sIndicatorPositions[position][1];

    LoadSpriteSheet(&sBattler_GimmickSpritesheets[battler]);
    spriteId = CreateSprite(&(sSpriteTemplate_BattlerIndicators[battler]), 0, y, 0);
    gBattleStruct->gimmick.indicatorSpriteId[battler] = spriteId;
    gSprites[spriteId].tBattler = battler;
    gSprites[spriteId].tPosX = x;
    gSprites[spriteId].invisible = FALSE;
}

#undef tBattler
#undef tPosX
#undef tLevelXDelta

#undef hMain_Battler
