#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_message.h"
#include "main.h"
#include "menu.h"
#include "menu_helpers.h"
#include "scanline_effect.h"
#include "palette.h"
#include "party_menu.h"
#include "pokemon_icon.h"
#include "sprite.h"
#include "item.h"
#include "task.h"
#include "bg.h"
#include "gpu_regs.h"
#include "window.h"
#include "text.h"
#include "text_window.h"
#include "international_string_util.h"
#include "strings.h"
#include "battle_ai_main.h"
#include "battle_ai_util.h"
#include "list_menu.h"
#include "decompress.h"
#include "trainer_pokemon_sprites.h"
#include "malloc.h"
#include "string_util.h"
#include "util.h"
#include "data.h"
#include "reshow_battle_screen.h"
#include "constants/abilities.h"
#include "constants/party_menu.h"
#include "constants/moves.h"
#include "constants/items.h"
#include "constants/rgb.h"

struct BattleInfoMenu
{
    u8 battlerId:2;
    u8 aiBattlerId:2;

    u8 battlerWindowId;

    u8 mainListWindowId;
    u8 mainListTaskId;
    u8 currentMainListItemId;

    u8 activeWindow;

    u8 aiViewState;
    u8 aiMonSpriteId;
    u8 aiMovesWindowId;

    union
    {
        u8 aiIconSpriteIds[MAX_BATTLERS_COUNT];
        u8 aiPartyIcons[PARTY_SIZE];
    } spriteIds;
};

enum
{
    LIST_ITEM_AI_PARTY,
    LIST_ITEM_STAT_STAGES,
    LIST_ITEM_SIDE_STATUS,
    LIST_ITEM_COUNT
};

enum
{
    ACTIVE_WIN_MAIN,
};

// const rom data
static const struct ListMenuItem sMainListItems[] =
{
    {COMPOUND_STRING("AI Party"),     LIST_ITEM_AI_PARTY},
    {COMPOUND_STRING("Stat Stages"),  LIST_ITEM_STAT_STAGES},
    {COMPOUND_STRING("Side Status"),  LIST_ITEM_SIDE_STATUS},
};

static const struct ListMenuTemplate sMainListTemplate =
{
    .items = sMainListItems,
    .moveCursorFunc = NULL,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sMainListItems),
    .maxShowed = 3,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 1,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = 1,
    .cursorKind = 0
};

static const struct WindowTemplate sMainListWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 11,
    .height = 6,
    .paletteNum = 0xF,
    .baseBlock = 0x1
};

static const struct WindowTemplate sBattlerWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 10,
    .tilemapTop = 0,
    .width = 14,
    .height = 2,
    .paletteNum = 0xF,
    .baseBlock = 0x1B5
};

static const struct BgTemplate sBgTemplates[] =
{
   {
       .bg = 0,
       .charBaseIndex = 0,
       .mapBaseIndex = 31,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 1,
       .baseTile = 0
   },
   {
       .bg = 1,
       .charBaseIndex = 2,
       .mapBaseIndex = 20,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 0,
       .baseTile = 0
   }
};

static const u16 sBgColor[] = {RGB_WHITE};

// Forward declarations
static void Task_InfoMenuFadeOut(u8 taskId);
static void Task_InfoMenuProcessInput(u8 taskId);
static void Task_InfoMenuFadeIn(u8 taskId);
static void Task_ShowAiParty(u8 taskId);
static void Task_ShowStatStages(u8 taskId);
static void Task_ShowSideStatus(u8 taskId);

// code
static struct BattleInfoMenu *GetStructPtr(u8 taskId)
{
    u8 *taskDataPtr = (u8 *)(&gTasks[taskId].data[0]);
    return (struct BattleInfoMenu*)(T1_READ_PTR(taskDataPtr));
}

static void SetStructPtr(u8 taskId, void *ptr)
{
    u32 structPtr = (u32)(ptr);
    u8 *taskDataPtr = (u8 *)(&gTasks[taskId].data[0]);

    taskDataPtr[0] = structPtr >> 0;
    taskDataPtr[1] = structPtr >> 8;
    taskDataPtr[2] = structPtr >> 16;
    taskDataPtr[3] = structPtr >> 24;
}

static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_BattleInfoMenu(void)
{
    u8 taskId;
    struct BattleInfoMenu *data;

    switch (gMain.state)
    {
    default:
    case 0:
        SetVBlankCallback(NULL);
        gMain.state++;
        break;
    case 1:
        ResetVramOamAndBgCntRegs();
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
        ResetAllBgsCoordinates();
        FreeAllWindowBuffers();
        DeactivateAllTextPrinters();
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        ShowBg(1);
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        gMain.state++;
        break;
    case 3:
        LoadPalette(sBgColor, 0, 2);
        LoadPalette(GetOverworldTextboxPalettePtr(), 0xf0, 16);
        gMain.state++;
        break;
    case 4:
        taskId = CreateTask(Task_InfoMenuFadeIn, 0);
        data = AllocZeroed(sizeof(struct BattleInfoMenu));
        SetStructPtr(taskId, data);

        data->battlerId = gBattleStruct->debugBattler;

        data->mainListWindowId = AddWindow(&sMainListWindowTemplate);

        gMultiuseListMenuTemplate = sMainListTemplate;
        gMultiuseListMenuTemplate.windowId = data->mainListWindowId;
        data->mainListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);

        data->currentMainListItemId = 0;
        data->activeWindow = ACTIVE_WIN_MAIN;
        CopyWindowToVram(data->mainListWindowId, COPYWIN_FULL);
        gMain.state++;
        break;
    case 5:
        BeginNormalPaletteFade(-1, 0, 0x10, 0, 0);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        return;
    }
}

static void Task_InfoMenuFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_InfoMenuProcessInput;
}

static void Task_InfoMenuProcessInput(u8 taskId)
{
    s32 listItemId = 0;
    struct BattleInfoMenu *data = GetStructPtr(taskId);

    // Exit the menu.
    if (JOY_NEW(SELECT_BUTTON) || JOY_NEW(B_BUTTON))
    {
        BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
        gTasks[taskId].func = Task_InfoMenuFadeOut;
        return;
    }

    listItemId = ListMenu_ProcessInput(data->mainListTaskId);
    if (listItemId != LIST_CANCEL && listItemId != LIST_NOTHING_CHOSEN && listItemId < LIST_ITEM_COUNT)
    {
        if (JOY_NEW(A_BUTTON))
        {
            data->currentMainListItemId = listItemId;
            switch (listItemId)
            {
            case LIST_ITEM_AI_PARTY:
                data->aiViewState = 0;
                gTasks[taskId].func = Task_ShowAiParty;
                return;
            case LIST_ITEM_STAT_STAGES:
                data->aiViewState = 0;
                gTasks[taskId].func = Task_ShowStatStages;
                return;
            case LIST_ITEM_SIDE_STATUS:
                data->aiViewState = 0;
                gTasks[taskId].func = Task_ShowSideStatus;
                return;
            }
        }
    }
}

static void Task_InfoMenuFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        struct BattleInfoMenu *data = GetStructPtr(taskId);
        DestroyListMenuTask(data->mainListTaskId, 0, 0);
        FreeAllWindowBuffers();
        gBattleStruct->debugBattler = data->battlerId;
        Free(data);
        DestroyTask(taskId);
        SetMainCallback2(ReshowBattleScreenAfterMenu);
    }
}

// ==================== AI PARTY VIEW ====================

#define sConditionSpriteId data[1]

static void PutAiPartyText(struct BattleInfoMenu *data)
{
    u32 i, j, count;
    u8 *text = Alloc(0x50), *txtPtr;
    struct AiPartyMon *aiMons = gAiPartyData->mons[GetBattlerSide(data->aiBattlerId)];

    FillWindowPixelBuffer(data->aiMovesWindowId, 0x11);
    count = gAiPartyData->count[GetBattlerSide(data->aiBattlerId)];
    for (i = 0; i < count; i++)
    {
        if (aiMons[i].wasSentInBattle)
        {
            text[0] = CHAR_LV;
            txtPtr = ConvertIntToDecimalStringN(text + 1, aiMons[i].level, STR_CONV_MODE_LEFT_ALIGN, 3);
            *txtPtr++ = CHAR_SPACE;
            if (aiMons[i].gender == MON_MALE)
                *txtPtr++ = CHAR_MALE;
            else if (aiMons[i].gender == MON_FEMALE)
                *txtPtr++ = CHAR_FEMALE;
            *txtPtr = EOS;
            AddTextPrinterParameterized5(data->aiMovesWindowId, FONT_SMALL_NARROW, text, i * 41, 0, 0, NULL, 0, 0);

            txtPtr = StringCopyN(text, gAbilitiesInfo[aiMons[i].ability].name, 7);
            *txtPtr = EOS;
            AddTextPrinterParameterized5(data->aiMovesWindowId, FONT_SMALL_NARROW, text, i * 41, 15, 0, NULL, 0, 0);

            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                txtPtr = StringCopyN(text, GetMoveName(aiMons[i].moves[j]), 8);
                *txtPtr = EOS;
                AddTextPrinterParameterized5(data->aiMovesWindowId, FONT_SMALL_NARROW, text, i * 41, 35 + j * 15, 0, NULL, 0, 0);
            }

            txtPtr = StringCopyN(text, GetItemName(aiMons[i].item), 7);
            *txtPtr = EOS;
            AddTextPrinterParameterized5(data->aiMovesWindowId, FONT_SMALL_NARROW, text, i * 41, 35 + j * 15, 0, NULL, 0, 0);
        }
        else
        {
            StringCopy(text, COMPOUND_STRING("???"));
            AddTextPrinterParameterized5(data->aiMovesWindowId, FONT_SMALL_NARROW, text, i * 41, 0, 0, NULL, 0, 0);
        }
    }

    CopyWindowToVram(data->aiMovesWindowId, COPYWIN_FULL);
    Free(text);
}

static void SwitchToMainMenuFromAiParty(u8 taskId)
{
    u32 i;
    struct BattleInfoMenu *data = GetStructPtr(taskId);

    FreeMonIconPalettes();
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (data->spriteIds.aiPartyIcons[i] != 0xFF)
        {
            DestroySpriteAndFreeResources(&gSprites[gSprites[data->spriteIds.aiPartyIcons[i]].sConditionSpriteId]);
            FreeAndDestroyMonIconSprite(&gSprites[data->spriteIds.aiPartyIcons[i]]);
        }
    }
    ClearWindowTilemap(data->aiMovesWindowId);
    RemoveWindow(data->aiMovesWindowId);

    gTasks[taskId].func = Task_InfoMenuProcessInput;
}

static void Task_ShowAiParty(u8 taskId)
{
    u32 i, ailment;
    struct WindowTemplate winTemplate;
    struct AiPartyMon *aiMons;
    struct BattleInfoMenu *data = GetStructPtr(taskId);

    switch (data->aiViewState)
    {
    case 0:
        HideBg(0);
        ShowBg(1);

        LoadMonIconPalettes();
        LoadPartyMenuAilmentGfx();

        // Force to AI side
        data->aiBattlerId = data->battlerId;
        while (!BattlerHasAi(data->aiBattlerId))
        {
            if (++data->aiBattlerId >= gBattlersCount)
                data->aiBattlerId = 0;
        }

        aiMons = gAiPartyData->mons[B_SIDE_OPPONENT];
        for (i = 0; i < gEnemyPartyCount; i++)
        {
            u16 species = SPECIES_NONE; // Question mark
            struct Pokemon *mon= &gEnemyParty[i];
            // if (aiMons[i].wasSentInBattle && aiMons[i].species)
            species = GetMonData(mon, MON_DATA_SPECIES);
            data->spriteIds.aiPartyIcons[i] = CreateMonIcon(species, SpriteCallbackDummy, (i * 41) + 15, 7, 1, 0);
            gSprites[data->spriteIds.aiPartyIcons[i]].oam.priority = 0;

            gSprites[data->spriteIds.aiPartyIcons[i]].sConditionSpriteId = CreateSprite(&gSpriteTemplate_StatusIcons, (i * 41) + 15, 7, 0);
            gSprites[gSprites[data->spriteIds.aiPartyIcons[i]].sConditionSpriteId].oam.priority = 0;
            u32 ailment = GetMonData(mon, MON_DATA_STATUS);

            if (GetMonData(mon, MON_DATA_HP) == 0)
                ailment = AILMENT_FNT;
            if (ailment != AILMENT_NONE)
                StartSpriteAnim(&gSprites[gSprites[data->spriteIds.aiPartyIcons[i]].sConditionSpriteId], ailment - 1);
            else
                gSprites[gSprites[data->spriteIds.aiPartyIcons[i]].sConditionSpriteId].invisible = TRUE;
            
        }
        for (; i < PARTY_SIZE; i++)
            data->spriteIds.aiPartyIcons[i] = 0xFF;
        data->aiViewState++;
        break;
    case 1:
        winTemplate = CreateWindowTemplate(1, 0, 3, 29, 16, 15, 0x150);
        data->aiMovesWindowId = AddWindow(&winTemplate);
        PutWindowTilemap(data->aiMovesWindowId);
        PutAiPartyText(data);
        data->aiViewState++;
        break;
    case 2:
        if (JOY_NEW(SELECT_BUTTON | B_BUTTON))
        {
            SwitchToMainMenuFromAiParty(taskId);
            HideBg(1);
            ShowBg(0);
            return;
        }
        break;
    }
}

#undef sConditionSpriteId

// ==================== STAT STAGES VIEW ====================

static void PrintStatStagesForBattler(struct BattleInfoMenu *data)
{
    u32 i;
    u8 text[20];

    FillWindowPixelBuffer(data->aiMovesWindowId, 0x11);

    // Print battler name header
    {
        u8 header[POKEMON_NAME_LENGTH + 10];
        header[0] = CHAR_0 + data->battlerId;
        header[1] = CHAR_SPACE;
        header[2] = CHAR_HYPHEN;
        header[3] = CHAR_SPACE;
        StringCopy(&header[4], gBattleMons[data->battlerId].nickname);
        AddTextPrinterParameterized(data->aiMovesWindowId, FONT_NORMAL, header, 3, 0, 0, NULL);
    }

    for (i = 0; i < NUM_BATTLE_STATS - 1; i++)
    {
        u8 *txtPtr = StringCopy(text, gStatNamesTable[STAT_ATK + i]);
        txtPtr[0] = CHAR_SPACE;
        if (gBattleMons[data->battlerId].statStages[STAT_ATK + i] >= DEFAULT_STAT_STAGE)
        {
            txtPtr[1] = CHAR_PLUS;
            txtPtr[2] = CHAR_0 + (gBattleMons[data->battlerId].statStages[STAT_ATK + i] - DEFAULT_STAT_STAGE);
        }
        else
        {
            txtPtr[1] = CHAR_HYPHEN;
            txtPtr[2] = CHAR_6 - (gBattleMons[data->battlerId].statStages[STAT_ATK + i]);
        }
        txtPtr[3] = EOS;

        AddTextPrinterParameterized(data->aiMovesWindowId, FONT_NORMAL, text, 3, (i + 1) * 15, 0, NULL);
    }

    CopyWindowToVram(data->aiMovesWindowId, COPYWIN_FULL);
}

static void SwitchToMainMenuFromSubView(u8 taskId)
{
    struct BattleInfoMenu *data = GetStructPtr(taskId);

    ClearWindowTilemap(data->aiMovesWindowId);
    RemoveWindow(data->aiMovesWindowId);

    gTasks[taskId].func = Task_InfoMenuProcessInput;
}

static void Task_ShowStatStages(u8 taskId)
{
    struct WindowTemplate winTemplate;
    struct BattleInfoMenu *data = GetStructPtr(taskId);

    switch (data->aiViewState)
    {
    case 0:
        HideBg(0);
        ShowBg(1);

        winTemplate = CreateWindowTemplate(1, 0, 2, 20, 18, 15, 0x200);
        data->aiMovesWindowId = AddWindow(&winTemplate);
        PutWindowTilemap(data->aiMovesWindowId);
        PrintStatStagesForBattler(data);
        data->aiViewState++;
        break;
    case 1:
        if (JOY_NEW(R_BUTTON))
        {
            if (data->battlerId++ == gBattlersCount - 1)
                data->battlerId = 0;
            PrintStatStagesForBattler(data);
        }
        else if (JOY_NEW(L_BUTTON))
        {
            if (data->battlerId-- == 0)
                data->battlerId = gBattlersCount - 1;
            PrintStatStagesForBattler(data);
        }
        else if (JOY_NEW(SELECT_BUTTON | B_BUTTON))
        {
            SwitchToMainMenuFromSubView(taskId);
            HideBg(1);
            ShowBg(0);
            return;
        }
        break;
    }
}

// ==================== SIDE STATUS VIEW ====================

struct SideStatusEntry
{
    const u8 *name;
    u32 statusFlag;
};

static const struct SideStatusEntry sSideStatusEntries[] =
{
    {COMPOUND_STRING("Reflect"),          SIDE_STATUS_REFLECT},
    {COMPOUND_STRING("Light Screen"),     SIDE_STATUS_LIGHTSCREEN},
    {COMPOUND_STRING("Safeguard"),        SIDE_STATUS_SAFEGUARD},
    {COMPOUND_STRING("Mist"),             SIDE_STATUS_MIST},
    {COMPOUND_STRING("Tailwind"),         SIDE_STATUS_TAILWIND},
    {COMPOUND_STRING("Aurora Veil"),      SIDE_STATUS_AURORA_VEIL},
    {COMPOUND_STRING("Lucky Chant"),      SIDE_STATUS_LUCKY_CHANT},
};

static u16 GetSideStatusTimer(const struct SideTimer *sideTimer, u32 index)
{
    switch (index)
    {
    case 0: return sideTimer->reflectTimer;
    case 1: return sideTimer->lightscreenTimer;
    case 2: return sideTimer->safeguardTimer;
    case 3: return sideTimer->mistTimer;
    case 4: return sideTimer->tailwindTimer;
    case 5: return sideTimer->auroraVeilTimer;
    case 6: return sideTimer->luckyChantTimer;
    default: return 0;
    }
}

static void PrintSideStatusInfo(struct BattleInfoMenu *data)
{
    u32 i, side;
    u8 text[30];
    u8 *txtPtr;

    FillWindowPixelBuffer(data->aiMovesWindowId, 0x11);

    // Player side header
    AddTextPrinterParameterized(data->aiMovesWindowId, FONT_NORMAL, COMPOUND_STRING("Player Side"), 3, 0, 0, NULL);
    side = B_SIDE_PLAYER;
    for (i = 0; i < ARRAY_COUNT(sSideStatusEntries); i++)
    {
        u16 timer = GetSideStatusTimer(&gSideTimers[side], i);
        txtPtr = StringCopy(text, sSideStatusEntries[i].name);
        *txtPtr++ = CHAR_SPACE;
        if (gSideStatuses[side] & sSideStatusEntries[i].statusFlag)
        {
            txtPtr = ConvertIntToDecimalStringN(txtPtr, timer, STR_CONV_MODE_LEFT_ALIGN, 2);
        }
        else
        {
            *txtPtr++ = CHAR_HYPHEN;
        }
        *txtPtr = EOS;
        AddTextPrinterParameterized(data->aiMovesWindowId, FONT_SMALL, text, 3, 15 + i * 12, 0, NULL);
    }

    // Opponent side header
    AddTextPrinterParameterized(data->aiMovesWindowId, FONT_NORMAL, COMPOUND_STRING("Opponent Side"), 3, 15 + ARRAY_COUNT(sSideStatusEntries) * 12 + 5, 0, NULL);
    side = B_SIDE_OPPONENT;
    for (i = 0; i < ARRAY_COUNT(sSideStatusEntries); i++)
    {
        u16 timer = GetSideStatusTimer(&gSideTimers[side], i);
        txtPtr = StringCopy(text, sSideStatusEntries[i].name);
        *txtPtr++ = CHAR_SPACE;
        if (gSideStatuses[side] & sSideStatusEntries[i].statusFlag)
        {
            txtPtr = ConvertIntToDecimalStringN(txtPtr, timer, STR_CONV_MODE_LEFT_ALIGN, 2);
        }
        else
        {
            *txtPtr++ = CHAR_HYPHEN;
        }
        *txtPtr = EOS;
        AddTextPrinterParameterized(data->aiMovesWindowId, FONT_SMALL, text, 3, 15 + ARRAY_COUNT(sSideStatusEntries) * 12 + 20 + i * 12, 0, NULL);
    }

    CopyWindowToVram(data->aiMovesWindowId, COPYWIN_FULL);
}

static void Task_ShowSideStatus(u8 taskId)
{
    struct WindowTemplate winTemplate;
    struct BattleInfoMenu *data = GetStructPtr(taskId);

    switch (data->aiViewState)
    {
    case 0:
        HideBg(0);
        ShowBg(1);

        winTemplate = CreateWindowTemplate(1, 0, 0, 26, 20, 15, 0x200);
        data->aiMovesWindowId = AddWindow(&winTemplate);
        PutWindowTilemap(data->aiMovesWindowId);
        PrintSideStatusInfo(data);
        data->aiViewState++;
        break;
    case 1:
        if (JOY_NEW(SELECT_BUTTON | B_BUTTON))
        {
            SwitchToMainMenuFromSubView(taskId);
            HideBg(1);
            ShowBg(0);
            return;
        }
        break;
    }
}
