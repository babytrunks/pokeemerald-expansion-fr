#ifndef GUARD_RAC_MENU_H
#define GUARD_RAC_MENU_H

#include "event_data.h"

// =============================================================================
// Randomizer and Challenges menu
// Settings are stored as bits in game flags starting at FLAG_0x300.
// 73 flags total: 0x300-0x348
// All flags default to 0 (cleared) on new game.
// Non-zero defaults are set explicitly in CB2_InitRacMenu.
// =============================================================================

// --- MODE (0x300-0x309) ---
#define FLAG_RAC_GAMEMODE            0x300  // 0=recommended preset, 1=custom
#define FLAG_RAC_INFINITE_TMS        0x301
#define FLAG_RAC_SURVIVE_POISON      0x302
#define FLAG_RAC_SYNCHRONIZE         0x303
#define FLAG_RAC_STURDY              0x304
#define FLAG_RAC_MINTS               0x305
#define FLAG_RAC_NEW_CITRUS          0x306
#define FLAG_RAC_FAIRY_TYPES         0x307
#define FLAG_RAC_MODERN_MOVES        0x308
#define FLAG_RAC_LEGENDARY_ABILITIES 0x309

// --- FEATURES (0x30A-0x310) ---
// Shiny chance: 3-bit value: 0=1/8192, 1=1/4096, 2=1/2048, 3=1/1024, 4=1/512
#define FLAG_RAC_SHINY_CHANCE_BIT0   0x30A
#define FLAG_RAC_SHINY_CHANCE_BIT1   0x30B
#define FLAG_RAC_SHINY_CHANCE_BIT2   0x30C
#define FLAG_RAC_RTC_TYPE            0x30D  // 0=real RTC, 1=fake RTC
#define FLAG_RAC_ITEM_DROP           0x30E
#define FLAG_RAC_FRONTIER_BANS       0x30F
#define FLAG_RAC_SHINY_COLORS        0x310

// --- RANDOMIZER (0x311-0x320) ---
#define FLAG_RAC_RANDOMIZER          0x311  // master toggle
#define FLAG_RAC_RAND_STARTER        0x312
#define FLAG_RAC_RAND_WILD           0x313
#define FLAG_RAC_RAND_TRAINER        0x314
#define FLAG_RAC_RAND_STATIC         0x315
#define FLAG_RAC_RAND_BALANCING      0x316  // 1=balancing enabled (default)
#define FLAG_RAC_RAND_LEGENDARIES    0x317
#define FLAG_RAC_RAND_TYPES          0x318
#define FLAG_RAC_RAND_MOVES          0x319
#define FLAG_RAC_RAND_ABILITIES      0x31A
#define FLAG_RAC_RAND_EVOLUTIONS     0x31B
#define FLAG_RAC_RAND_EVO_METHODS    0x31C
#define FLAG_RAC_RAND_TYPE_EFFEC     0x31D
#define FLAG_RAC_RAND_ITEMS          0x31E
#define FLAG_RAC_RAND_CHAOS          0x31F
#define FLAG_RAC_RAND_MAPBASED       0x320  // 1=map-based (default)

// --- NUZLOCKE (0x321-0x327) ---
// Nuzlocke mode: 2-bit: 0=off, 1=easy, 2=normal, 3=hardcore
#define FLAG_RAC_NUZLOCKE_MODE_BIT0  0x321
#define FLAG_RAC_NUZLOCKE_MODE_BIT1  0x322
#define FLAG_RAC_NUZLOCKE_SPECIES    0x323  // 1=enabled (default)
#define FLAG_RAC_NUZLOCKE_SHINY      0x324  // 1=enabled (default)
#define FLAG_RAC_NUZLOCKE_NICKNAMING 0x325  // 1=enabled (default)
#define FLAG_RAC_NUZLOCKE_DELETION   0x326
#define FLAG_RAC_NUZLOCKE_RARE_CANDY 0x327

// --- DIFFICULTY (0x328-0x339) ---
// Party limit: 3-bit: 0=6, 1=5, 2=4, 3=3, 4=2, 5=1
#define FLAG_RAC_PARTY_LIMIT_BIT0    0x328
#define FLAG_RAC_PARTY_LIMIT_BIT1    0x329
#define FLAG_RAC_PARTY_LIMIT_BIT2    0x32A
// Level cap: 2-bit: 0=off, 1=badge-based, 2=next-gym
#define FLAG_RAC_LEVEL_CAP_BIT0      0x32B
#define FLAG_RAC_LEVEL_CAP_BIT1      0x32C
// Exp multiplier: 2-bit: 0=x1, 1=x0.75, 2=x0.5, 3=x0.25
#define FLAG_RAC_EXP_MULT_BIT0       0x32D
#define FLAG_RAC_EXP_MULT_BIT1       0x32E
#define FLAG_RAC_NO_ITEMS_PLAYER     0x32F
#define FLAG_RAC_NO_ITEMS_TRAINER    0x330
#define FLAG_RAC_NO_EVS              0x331
// Trainer IVs: 2-bit: 0=0, 1=8, 2=15, 3=31
#define FLAG_RAC_TRAINER_IVS_BIT0    0x332
#define FLAG_RAC_TRAINER_IVS_BIT1    0x333
// Trainer EVs: 2-bit: 0=off, 1=low, 2=half, 3=full
#define FLAG_RAC_TRAINER_EVS_BIT0    0x334
#define FLAG_RAC_TRAINER_EVS_BIT1    0x335
// Player IVs: 2-bit: 0=0, 1=15, 2=31
#define FLAG_RAC_PLAYER_IVS_BIT0     0x336
#define FLAG_RAC_PLAYER_IVS_BIT1     0x337
#define FLAG_RAC_LESS_ESCAPES        0x338
#define FLAG_RAC_ESCAPE_ROPE_DIG     0x339

// --- CHALLENGES (0x33A-0x348) ---
#define FLAG_RAC_POKECENTER          0x33A  // 0=unlimited, 1=none
#define FLAG_RAC_PC_HEAL             0x33B
// Expensive: 2-bit: 0=off, 1=x5, 2=x10, 3=x50
#define FLAG_RAC_EXPENSIVE_BIT0      0x33C
#define FLAG_RAC_EXPENSIVE_BIT1      0x33D
// Evo limit: 2-bit: 0=off, 1=first stage, 2=no evolutions
#define FLAG_RAC_EVO_LIMIT_BIT0      0x33E
#define FLAG_RAC_EVO_LIMIT_BIT1      0x33F
// One-type challenge: 5-bit: 0=off, TYPE_NORMAL(1) to TYPE_STELLAR(20)
#define FLAG_RAC_ONE_TYPE_BIT0       0x340
#define FLAG_RAC_ONE_TYPE_BIT1       0x341
#define FLAG_RAC_ONE_TYPE_BIT2       0x342
#define FLAG_RAC_ONE_TYPE_BIT3       0x343
#define FLAG_RAC_ONE_TYPE_BIT4       0x344
// BST equalizer: 2-bit: 0=off, 1=100, 2=255, 3=500
#define FLAG_RAC_BST_EQ_BIT0         0x345
#define FLAG_RAC_BST_EQ_BIT1         0x346
#define FLAG_RAC_MIRROR              0x347
#define FLAG_RAC_MIRROR_THIEF        0x348

// =============================================================================
// Bit-packed flag access helpers
// =============================================================================

static inline u8 RacGetBits(u16 startFlag, u8 numBits)
{
    u8 i, val = 0;
    for (i = 0; i < numBits; i++)
        if (FlagGet(startFlag + i))
            val |= (u8)(1 << i);
    return val;
}

static inline void RacSetBits(u16 startFlag, u8 numBits, u8 value)
{
    u8 i;
    for (i = 0; i < numBits; i++)
    {
        if (value & (1 << i))
            FlagSet(startFlag + i);
        else
            FlagClear(startFlag + i);
    }
}

// =============================================================================
// Accessor macros used by game logic
// =============================================================================

// MODE
#define IsInfiniteTMsEnabled()         FlagGet(FLAG_RAC_INFINITE_TMS)
#define IsSurvivePoisonEnabled()        FlagGet(FLAG_RAC_SURVIVE_POISON)
#define IsModernSynchronize()           FlagGet(FLAG_RAC_SYNCHRONIZE)
#define IsModernSturdy()                FlagGet(FLAG_RAC_STURDY)
#define IsMintsEnabled()                FlagGet(FLAG_RAC_MINTS)
#define IsModernCitrus()                FlagGet(FLAG_RAC_NEW_CITRUS)
#define IsFairyTypeEnabled()            FlagGet(FLAG_RAC_FAIRY_TYPES)
#define IsModernMoves()                 FlagGet(FLAG_RAC_MODERN_MOVES)
#define IsLegendaryAbilitiesEnabled()   FlagGet(FLAG_RAC_LEGENDARY_ABILITIES)

// FEATURES
#define GetShinyChance()                RacGetBits(FLAG_RAC_SHINY_CHANCE_BIT0, 3)
#define IsWildItemDropEnabled()         FlagGet(FLAG_RAC_ITEM_DROP)
#define IsFrontierBansEnabled()         FlagGet(FLAG_RAC_FRONTIER_BANS)
#define IsModernShinyColors()           FlagGet(FLAG_RAC_SHINY_COLORS)

// RANDOMIZER
#define IsRandomizerActivated()         FlagGet(FLAG_RAC_RANDOMIZER)
#define IsRandomStarterEnabled()        FlagGet(FLAG_RAC_RAND_STARTER)
#define IsRandomWildEnabled()           FlagGet(FLAG_RAC_RAND_WILD)
#define IsRandomTrainerEnabled()        FlagGet(FLAG_RAC_RAND_TRAINER)
#define IsRandomStaticEnabled()         FlagGet(FLAG_RAC_RAND_STATIC)
#define IsRandomBalancingEnabled()      FlagGet(FLAG_RAC_RAND_BALANCING)
#define IsRandomLegendariesEnabled()    FlagGet(FLAG_RAC_RAND_LEGENDARIES)
#define IsRandomTypesEnabled()          FlagGet(FLAG_RAC_RAND_TYPES)
#define IsRandomMovesEnabled()          FlagGet(FLAG_RAC_RAND_MOVES)
#define IsRandomAbilitiesEnabled()      FlagGet(FLAG_RAC_RAND_ABILITIES)
#define IsRandomEvolutionsEnabled()     FlagGet(FLAG_RAC_RAND_EVOLUTIONS)
#define IsRandomEvoMethodsEnabled()     FlagGet(FLAG_RAC_RAND_EVO_METHODS)
#define IsRandomTypeEffecEnabled()      FlagGet(FLAG_RAC_RAND_TYPE_EFFEC)
#define IsRandomItemsEnabled()          FlagGet(FLAG_RAC_RAND_ITEMS)
#define IsRandomChaosEnabled()          FlagGet(FLAG_RAC_RAND_CHAOS)
#define IsRandomMapBasedEnabled()       FlagGet(FLAG_RAC_RAND_MAPBASED)

// NUZLOCKE
#define GetNuzlockeMode()               RacGetBits(FLAG_RAC_NUZLOCKE_MODE_BIT0, 2)
#define IsNuzlockeActive()              (GetNuzlockeMode() >= 2)
#define IsNuzlockeEasyMode()            (GetNuzlockeMode() == 1)
#define IsNuzlockeHardcore()            (GetNuzlockeMode() == 3)
#define IsNuzlockeSpeciesClause()       FlagGet(FLAG_RAC_NUZLOCKE_SPECIES)
#define IsNuzlockeShinyClause()         FlagGet(FLAG_RAC_NUZLOCKE_SHINY)
#define IsNuzlockeNicknaming()          FlagGet(FLAG_RAC_NUZLOCKE_NICKNAMING)
#define IsNuzlockeDeletion()            FlagGet(FLAG_RAC_NUZLOCKE_DELETION)
#define IsNuzlockeRareCandyEnabled()    FlagGet(FLAG_RAC_NUZLOCKE_RARE_CANDY)

// DIFFICULTY
#define GetPartyLimit()                 RacGetBits(FLAG_RAC_PARTY_LIMIT_BIT0, 3)
#define GetLevelCap()                   RacGetBits(FLAG_RAC_LEVEL_CAP_BIT0, 2)
#define GetExpMultiplier()              RacGetBits(FLAG_RAC_EXP_MULT_BIT0, 2)
#define IsNoItemsPlayer()               FlagGet(FLAG_RAC_NO_ITEMS_PLAYER)
#define IsNoItemsTrainer()              FlagGet(FLAG_RAC_NO_ITEMS_TRAINER)
#define IsNoEVsEnabled()                FlagGet(FLAG_RAC_NO_EVS)
#define GetTrainerIVs()                 RacGetBits(FLAG_RAC_TRAINER_IVS_BIT0, 2)
#define GetTrainerEVs()                 RacGetBits(FLAG_RAC_TRAINER_EVS_BIT0, 2)
#define GetPlayerIVs()                  RacGetBits(FLAG_RAC_PLAYER_IVS_BIT0, 2)
#define IsLessEscapesEnabled()          FlagGet(FLAG_RAC_LESS_ESCAPES)
#define IsEscapeRopeDigDisabled()       FlagGet(FLAG_RAC_ESCAPE_ROPE_DIG)

// CHALLENGES
#define IsPokecenterLimited()           FlagGet(FLAG_RAC_POKECENTER)
#define IsPCHealEnabled()               FlagGet(FLAG_RAC_PC_HEAL)
#define GetExpensiveMultiplier()        RacGetBits(FLAG_RAC_EXPENSIVE_BIT0, 2)
#define GetEvoLimit()                   RacGetBits(FLAG_RAC_EVO_LIMIT_BIT0, 2)
// One-type challenge: TYPE_NONE(0)=off, TYPE_NORMAL(1)-TYPE_STELLAR(20)=active
#define GetOneTypeChallenge()           RacGetBits(FLAG_RAC_ONE_TYPE_BIT0, 5)
#define IsOneTypeChallengeActive()      (GetOneTypeChallenge() != 0)
#define GetBSTEqualizer()               RacGetBits(FLAG_RAC_BST_EQ_BIT0, 2)
#define IsMirrorModeEnabled()           FlagGet(FLAG_RAC_MIRROR)
#define IsMirrorThiefEnabled()          FlagGet(FLAG_RAC_MIRROR_THIEF)

// Compound accessors
#define AreAnyChallengesActive()        (IsNuzlockeActive() || IsNuzlockeEasyMode() || GetPartyLimit() \
                                         || GetLevelCap() || IsNoItemsPlayer() || IsNoItemsTrainer() \
                                         || IsOneTypeChallengeActive())

void CB2_InitRacMenu(void);

#endif // GUARD_RAC_MENU_H
