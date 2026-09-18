#include "global.h"
#include "battle.h"
#include "battle_message.h"
#include "battle_util.h"
#include "item.h"
#include "mastery.h"
#include "move.h"
#include "pokemon.h"
#include "string_util.h"
#include "constants/abilities.h"
#include "constants/battle.h"
#include "constants/items.h"
#include "constants/moves.h"

#include "data/mastery.h"

STATIC_ASSERT(MASTERY_COUNT <= MASTERY_SAVE_SLOTS, MasteryCountExceedsSaveSlots);


static const u8 sText_MasteryPlateTop[] = _("Mastery!");
static const u8 sText_MasteryMsg[] = _("{B_ATK_NAME_WITH_PREFIX} mastered its talent!\pIt obtained the {B_BUFF1}!");


// Masteries only advance against trainers 
static bool32 IsMasteryBattle(void)
{
    return (gBattleTypeFlags & BATTLE_TYPE_TRAINER) != 0;
}

u32 GetSpeciesMastery(u32 species)
{
    if (species >= NUM_SPECIES)
        return MASTERY_NONE;

    return gSpeciesInfo[species].mastery;
}

bool32 IsMasteryCompleted(u32 masteryId)
{
    if (masteryId == MASTERY_NONE || masteryId >= MASTERY_COUNT)
        return FALSE;

    return (gSaveBlock1Ptr->masteryCompleted[masteryId / 8] & (1 << (masteryId % 8))) != 0;
}

static void SetMasteryCompleted(u32 masteryId)
{
    gSaveBlock1Ptr->masteryCompleted[masteryId / 8] |= 1 << (masteryId % 8);
}

u32 GetMasteryProgress(u32 masteryId)
{
    if (masteryId == MASTERY_NONE || masteryId >= MASTERY_COUNT)
        return 0;

    return gSaveBlock1Ptr->masteryProgress[masteryId];
}

// An unset levelUnlocked is zero so every level clears the gate
bool32 IsMasteryUnlockedAtLevel(u32 masteryId, u32 level)
{
    if (masteryId == MASTERY_NONE || masteryId >= MASTERY_COUNT)
        return FALSE;

    return level >= gMasteries[masteryId].levelUnlocked;
}

// Single battle masteries start over every battle so their run has to be unbroken
// Completed ones keep their count because the summary bar fills from it
void ClearPerBattleMasteryProgress(void)
{
    u32 masteryId;

    for (masteryId = MASTERY_NONE + 1; masteryId < MASTERY_COUNT; masteryId++)
    {
        if (gMasteries[masteryId].perBattle && !IsMasteryCompleted(masteryId))
            gSaveBlock1Ptr->masteryProgress[masteryId] = 0;
    }
}

// Advances the mastery of the battlers species if the event matches
void TryTickMastery(u32 battler, u32 event, u32 param)
{
    u32 masteryId, species;
    const struct Mastery *mastery;
    struct Pokemon *mon;

    if (!IsMasteryBattle())
        return;
    if (!IsOnPlayerSide(battler))
        return;

    mon = GetBattlerMon(battler);
    species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    masteryId = GetSpeciesMastery(species);
    if (masteryId == MASTERY_NONE)
        return;
    if (IsMasteryCompleted(masteryId))
        return;

    mastery = &gMasteries[masteryId];
    if (mastery->event != event || mastery->param != param)
        return;

    // A locked mastery ignores every event so it cannot be started early
    if (!IsMasteryUnlockedAtLevel(masteryId, GetMonData(mon, MON_DATA_LEVEL, NULL)))
        return;

    // Counter is a u8 so targetCount can never exceed 255
    if (gSaveBlock1Ptr->masteryProgress[masteryId] < mastery->targetCount)
        gSaveBlock1Ptr->masteryProgress[masteryId]++;

    if (gSaveBlock1Ptr->masteryProgress[masteryId] < mastery->targetCount)
        return;

    SetMasteryCompleted(masteryId);

    // Bag full means the reward is lost, the mastery still counts as done
    AddBagItem(mastery->reward, 1);

    // A banner may already be pending this move, the reward still stands either way
    if (QueueBattleNotification(sText_MasteryPlateTop, mastery->title, sText_MasteryMsg))
    {
        gBattleStruct->masteryRewardItem = mastery->reward;
        gBattleStruct->notificationKind = NOTIFICATION_KIND_MASTERY;
        PREPARE_ITEM_BUFFER(gBattleTextBuff1, mastery->reward)
    }
}

// Runs once per move resolution so spread moves cannot double count
void TryTickMasteryAtMoveEnd(void)
{
    u32 ability = gBattleStruct->masteryBoostAbility[gBattlerAttacker];

    gBattleStruct->masteryBoostAbility[gBattlerAttacker] = ABILITY_NONE;

    if (ability != ABILITY_NONE)
        TryTickMastery(gBattlerAttacker, MASTERY_EVENT_ABILITY_BOOSTED_MOVE, ability);

    // Magnitude 10 is the 150 base power roll, the displayed number is never stored
    if (GetMoveEffect(gCurrentMove) == EFFECT_MAGNITUDE
     && gBattleStruct->magnitudeBasePower == 150
     && !(gBattleStruct->moveResultFlags[gBattlerTarget] & (MOVE_RESULT_MISSED | MOVE_RESULT_DOESNT_AFFECT_FOE | MOVE_RESULT_NO_EFFECT)))
        TryTickMastery(gBattlerAttacker, MASTERY_EVENT_MAGNITUDE_LEVEL, 10);
}
