#include "global.h"
#include "event_data.h"
#include "pokedex.h"
#include "gba/isagbprint.h"
#include "constants/opponents.h"

#define SPECIAL_FLAGS_SIZE  (NUM_SPECIAL_FLAGS / 8)  // 8 flags per byte
#define TEMP_FLAGS_SIZE     (NUM_TEMP_FLAGS / 8)
#define DAILY_FLAGS_SIZE    (NUM_DAILY_FLAGS / 8)
#define TEMP_VARS_SIZE      (NUM_TEMP_VARS * 2)      // 1/2 var per byte

#if TRAINER_FLAG_WATCH && !defined(NDEBUG)
// Byte range of gSaveBlock1Ptr->flags[] covered by the trainer band (0x500-0x7FF).
#define TRAINER_FLAG_BYTE_START (TRAINER_FLAGS_START / 8)                          // 0xA0
#define TRAINER_FLAG_BYTE_END   (TRAINER_FLAGS_END / 8)                            // 0xFF
#define TRAINER_FLAG_BYTE_COUNT (TRAINER_FLAG_BYTE_END - TRAINER_FLAG_BYTE_START + 1)
// Set by FlagSet() whenever it legitimately touches the trainer band, so the
// per-frame watchdog can tell a real FlagSet apart from a raw memory smash.
static bool8 sTrainerFlagWriteThisFrame = FALSE;

// Specific trainers to call out with a distinctive ">>> WATCHED" line (easy to grep
// for in the mGBA log). Add or remove ids here as needed.
#define IS_WATCHED_TRAINER(trainerId) \
    ((trainerId) == TRAINER_BURGLAR_DUSTY || (trainerId) == TRAINER_PICNICKER_CAITLIN)
#endif

EWRAM_DATA u16 gSpecialVar_0x8000 = 0;
EWRAM_DATA u16 gSpecialVar_0x8001 = 0;
EWRAM_DATA u16 gSpecialVar_0x8002 = 0;
EWRAM_DATA u16 gSpecialVar_0x8003 = 0;
EWRAM_DATA u16 gSpecialVar_0x8004 = 0;
EWRAM_DATA u16 gSpecialVar_0x8005 = 0;
EWRAM_DATA u16 gSpecialVar_0x8006 = 0;
EWRAM_DATA u16 gSpecialVar_0x8007 = 0;
EWRAM_DATA u16 gSpecialVar_0x8008 = 0;
EWRAM_DATA u16 gSpecialVar_0x8009 = 0;
EWRAM_DATA u16 gSpecialVar_0x800A = 0;
EWRAM_DATA u16 gSpecialVar_0x800B = 0;
EWRAM_DATA u16 gSpecialVar_Result = 0;
EWRAM_DATA u16 gSpecialVar_LastTalked = 0;
EWRAM_DATA u16 gSpecialVar_Facing = 0;
EWRAM_DATA u16 gSpecialVar_MonBoxId = 0;
EWRAM_DATA u16 gSpecialVar_MonBoxPos = 0;
EWRAM_DATA u16 gSpecialVar_Unused_0x8014 = 0;
EWRAM_DATA static u8 sSpecialFlags[SPECIAL_FLAGS_SIZE] = {0};

#if TESTING
#define TEST_FLAGS_SIZE     1
#define TEST_VARS_SIZE      8
EWRAM_DATA static u8 sTestFlags[TEST_FLAGS_SIZE] = {0};
EWRAM_DATA static u16 sTestVars[TEST_VARS_SIZE] = {0};
#endif // TESTING

extern u16 *const gSpecialVars[];

const u16 gBadgeFlags[NUM_BADGES] =
{
    FLAG_BADGE01_GET,
    FLAG_BADGE02_GET,
    FLAG_BADGE03_GET,
    FLAG_BADGE04_GET,
    FLAG_BADGE05_GET,
    FLAG_BADGE06_GET,
    FLAG_BADGE07_GET,
    FLAG_BADGE08_GET,
};

void InitEventData(void)
{
    memset(gSaveBlock1Ptr->flags, 0, sizeof(gSaveBlock1Ptr->flags));
    memset(gSaveBlock1Ptr->vars, 0, sizeof(gSaveBlock1Ptr->vars));
    memset(sSpecialFlags, 0, sizeof(sSpecialFlags));
}

void ClearTempFieldEventData(void)
{
    memset(&gSaveBlock1Ptr->flags[TEMP_FLAGS_START / 8], 0, TEMP_FLAGS_SIZE);
    memset(&gSaveBlock1Ptr->vars[TEMP_VARS_START - VARS_START], 0, TEMP_VARS_SIZE);
    FlagClear(FLAG_SYS_ENC_UP_ITEM);
    FlagClear(FLAG_SYS_ENC_DOWN_ITEM);
    FlagClear(FLAG_SYS_USE_STRENGTH);
    FlagClear(FLAG_SYS_CTRL_OBJ_DELETE);
    FlagClear(FLAG_NURSE_UNION_ROOM_REMINDER);
}

void ClearDailyFlags(void)
{
    memset(&gSaveBlock1Ptr->flags[DAILY_FLAGS_START / 8], 0, DAILY_FLAGS_SIZE);
}

void DisableNationalPokedex(void)
{
    u16 *nationalDexVar = GetVarPointer(VAR_NATIONAL_DEX);
    gSaveBlock2Ptr->pokedex.nationalMagic = 0;
    *nationalDexVar = 0;
    FlagClear(FLAG_SYS_NATIONAL_DEX);
}

void EnableNationalPokedex(void)
{
    u16 *nationalDexVar = GetVarPointer(VAR_NATIONAL_DEX);
    gSaveBlock2Ptr->pokedex.nationalMagic = 0xDA;
    *nationalDexVar = 0x302;
    FlagSet(FLAG_SYS_NATIONAL_DEX);
    gSaveBlock2Ptr->pokedex.mode = DEX_MODE_NATIONAL;
    gSaveBlock2Ptr->pokedex.order = 0;
    ResetPokedexScrollPositions();
}

bool32 IsNationalPokedexEnabled(void)
{
    if (gSaveBlock2Ptr->pokedex.nationalMagic == 0xDA && VarGet(VAR_NATIONAL_DEX) == 0x302 && FlagGet(FLAG_SYS_NATIONAL_DEX))
        return TRUE;
    else
        return FALSE;
}

void DisableMysteryEvent(void)
{
    FlagClear(FLAG_SYS_MYSTERY_EVENT_ENABLE);
}

void EnableMysteryEvent(void)
{
    FlagSet(FLAG_SYS_MYSTERY_EVENT_ENABLE);
}

bool32 IsMysteryEventEnabled(void)
{
    return FlagGet(FLAG_SYS_MYSTERY_EVENT_ENABLE);
}

void DisableMysteryGift(void)
{
    FlagClear(FLAG_SYS_MYSTERY_GIFT_ENABLE);
}

void EnableMysteryGift(void)
{
    FlagSet(FLAG_SYS_MYSTERY_GIFT_ENABLE);
}

bool32 IsMysteryGiftEnabled(void)
{
    return FlagGet(FLAG_SYS_MYSTERY_GIFT_ENABLE);
}

void ClearMysteryGiftFlags(void)
{
    FlagClear(FLAG_MYSTERY_GIFT_DONE);
    FlagClear(FLAG_MYSTERY_GIFT_1);
    FlagClear(FLAG_MYSTERY_GIFT_2);
    FlagClear(FLAG_MYSTERY_GIFT_3);
    FlagClear(FLAG_MYSTERY_GIFT_4);
    FlagClear(FLAG_MYSTERY_GIFT_5);
    FlagClear(FLAG_MYSTERY_GIFT_6);
    FlagClear(FLAG_MYSTERY_GIFT_7);
    FlagClear(FLAG_MYSTERY_GIFT_8);
    FlagClear(FLAG_MYSTERY_GIFT_9);
    FlagClear(FLAG_MYSTERY_GIFT_10);
    FlagClear(FLAG_MYSTERY_GIFT_11);
    FlagClear(FLAG_MYSTERY_GIFT_12);
    FlagClear(FLAG_MYSTERY_GIFT_13);
    FlagClear(FLAG_MYSTERY_GIFT_14);
    FlagClear(FLAG_MYSTERY_GIFT_15);
}

void ClearMysteryGiftVars(void)
{
    VarSet(VAR_GIFT_PICHU_SLOT, 0);
    VarSet(VAR_GIFT_UNUSED_1, 0);
    VarSet(VAR_GIFT_UNUSED_2, 0);
    VarSet(VAR_GIFT_UNUSED_3, 0);
    VarSet(VAR_GIFT_UNUSED_4, 0);
    VarSet(VAR_GIFT_UNUSED_5, 0);
    VarSet(VAR_GIFT_UNUSED_6, 0);
    VarSet(VAR_GIFT_UNUSED_7, 0);
}

void DisableResetRTC(void)
{
    VarSet(VAR_RESET_RTC_ENABLE, 0);
    FlagClear(FLAG_SYS_RESET_RTC_ENABLE);
}

void EnableResetRTC(void)
{
    VarSet(VAR_RESET_RTC_ENABLE, 0x920);
    FlagSet(FLAG_SYS_RESET_RTC_ENABLE);
}

bool32 CanResetRTC(void)
{
    if (FlagGet(FLAG_SYS_RESET_RTC_ENABLE) && VarGet(VAR_RESET_RTC_ENABLE) == 0x920)
        return TRUE;
    else
        return FALSE;
}

u16 *GetVarPointer(u16 id)
{
    if (id < VARS_START)
        return NULL;
    else if (id < SPECIAL_VARS_START)
        return &gSaveBlock1Ptr->vars[id - VARS_START];
#if TESTING
    else if (id >= TESTING_VARS_START)
        return &sTestVars[id - TESTING_VARS_START];
#endif // TESTING
    else
        return gSpecialVars[id - SPECIAL_VARS_START];
}

u16 VarGet(u16 id)
{
    u16 *ptr = GetVarPointer(id);
    if (!ptr)
        return id;
    return *ptr;
}

u16 VarGetIfExist(u16 id)
{
    u16 *ptr = GetVarPointer(id);
    if (!ptr)
        return 65535;
    return *ptr;
}

bool8 VarSet(u16 id, u16 value)
{
    u16 *ptr = GetVarPointer(id);
    if (!ptr)
        return FALSE;
    *ptr = value;
    return TRUE;
}

u16 VarGetObjectEventGraphicsId(u8 id)
{
    return VarGet(VAR_OBJ_GFX_ID_0 + id);
}

u8 *GetFlagPointer(u16 id)
{
    if (id == 0)
        return NULL;
    else if (id < SPECIAL_FLAGS_START)
        return &gSaveBlock1Ptr->flags[id / 8];
#if TESTING
    else if (id >= TESTING_FLAGS_START)
        return &sTestFlags[(id - TESTING_FLAGS_START) / 8];
#endif // TESTING
    else
        return &sSpecialFlags[(id - SPECIAL_FLAGS_START) / 8];
}

u8 FlagSet(u16 id)
{
    u8 *ptr = GetFlagPointer(id);
    if (ptr)
        *ptr |= 1 << (id & 7);
#if TRAINER_FLAG_WATCH && !defined(NDEBUG)
    if (id >= TRAINER_FLAGS_START && id <= TRAINER_FLAGS_END)
    {
        u32 trainerId = id - TRAINER_FLAGS_START;
        sTrainerFlagWriteThisFrame = TRUE;
        if (IS_WATCHED_TRAINER(trainerId))
            DebugPrintf(">>> WATCHED SET trainer=%u id=0x%X map=%u.%u LR=0x%X",
                        trainerId, id, gSaveBlock1Ptr->location.mapGroup,
                        gSaveBlock1Ptr->location.mapNum, (u32)__builtin_return_address(0));
        else
            DebugPrintf("FLAGSET trainer=%u id=0x%X map=%u.%u LR=0x%X",
                        trainerId, id, gSaveBlock1Ptr->location.mapGroup,
                        gSaveBlock1Ptr->location.mapNum, (u32)__builtin_return_address(0));
    }
    else if (id >= FLAGS_COUNT)
    {
        DebugPrintf("FLAGSET OOB id=0x%X LR=0x%X", id, (u32)__builtin_return_address(0));
    }
#endif
    return 0;
}

u8 FlagToggle(u16 id)
{
    u8 *ptr = GetFlagPointer(id);
    if (ptr)
        *ptr ^= 1 << (id & 7);
#if TRAINER_FLAG_WATCH && !defined(NDEBUG)
    if (id >= TRAINER_FLAGS_START && id <= TRAINER_FLAGS_END)
    {
        sTrainerFlagWriteThisFrame = TRUE;
        DebugPrintf("FLAGTOGGLE trainer=%u id=0x%X LR=0x%X",
                    id - TRAINER_FLAGS_START, id, (u32)__builtin_return_address(0));
    }
#endif
    return 0;
}

u8 FlagClear(u16 id)
{
    u8 *ptr = GetFlagPointer(id);
    if (ptr)
        *ptr &= ~(1 << (id & 7));
#if TRAINER_FLAG_WATCH && !defined(NDEBUG)
    if (id >= TRAINER_FLAGS_START && id <= TRAINER_FLAGS_END)
        DebugPrintf("FLAGCLEAR trainer=%u id=0x%X LR=0x%X",
                    id - TRAINER_FLAGS_START, id, (u32)__builtin_return_address(0));
#endif
    return 0;
}

#if TRAINER_FLAG_WATCH && !defined(NDEBUG)
// Runs once per frame from AgbMainLoop. Diffs the trainer-flag byte region of the
// save against a shadow copy and logs any bit that becomes set. "RAW-WRITE!" means
// no FlagSet touched the band that frame -> the corruption came from a stray/OOB
// memory write, and the contiguous run of changed bytes points at the smash.
void WatchTrainerFlags(void)
{
    static u8 sShadow[TRAINER_FLAG_BYTE_COUNT];
    static bool8 sInitialized = FALSE;
    const u8 *flags;
    u32 i, bit;

    if (gSaveBlock1Ptr == NULL)
        return;

    flags = &gSaveBlock1Ptr->flags[TRAINER_FLAG_BYTE_START];

    if (!sInitialized)
    {
        for (i = 0; i < TRAINER_FLAG_BYTE_COUNT; i++)
            sShadow[i] = flags[i];
        sInitialized = TRUE;
        sTrainerFlagWriteThisFrame = FALSE;
        return;
    }

    for (i = 0; i < TRAINER_FLAG_BYTE_COUNT; i++)
    {
        u8 newlySet = flags[i] & ~sShadow[i];
        if (newlySet)
        {
            u32 byteIdx = TRAINER_FLAG_BYTE_START + i;
            DebugPrintf("TRAINER_FLAG_WATCH %s byte[0x%X] 0x%X->0x%X map=%u.%u",
                        sTrainerFlagWriteThisFrame ? "viaFlagSet" : "RAW-WRITE!",
                        byteIdx, sShadow[i], flags[i],
                        gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum);
            for (bit = 0; bit < 8; bit++)
            {
                if (newlySet & (1 << bit))
                {
                    u32 flagId = byteIdx * 8 + bit;
                    u32 trainerId = flagId - TRAINER_FLAGS_START;
                    if (IS_WATCHED_TRAINER(trainerId))
                        DebugPrintf(">>> WATCHED trainer=%u flag=0x%X map=%u.%u (%s)", trainerId, flagId,
                                    gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum,
                                    sTrainerFlagWriteThisFrame ? "viaFlagSet" : "RAW-WRITE!");
                    else
                        DebugPrintf("   trainer=%u flag=0x%X", trainerId, flagId);
                }
            }
        }
        sShadow[i] = flags[i];
    }
    sTrainerFlagWriteThisFrame = FALSE;
}
#endif

bool8 FlagGet(u16 id)
{
    u8 *ptr = GetFlagPointer(id);

    if (!ptr)
        return FALSE;

    if (!(((*ptr) >> (id & 7)) & 1))
        return FALSE;

    return TRUE;
}
