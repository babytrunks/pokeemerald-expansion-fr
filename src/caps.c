#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "caps.h"
#include "pokemon.h"
#include "util.h"

#define LEVEL_CAP_COUNT 14
u32 GetCurrentLevelCap(void)
{
    static const u32 sLevelCapFlagMap[LEVEL_CAP_COUNT][2] =
    {
        {FLAG_BADGE01_GET, 14},
        {FLAG_BEAT_MT_MOON_ARCHER, 18},
        {FLAG_BADGE02_GET, LEVEL_CAP_GYM_2},
        {FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_CAPTAIN_STERN, 25},
        {FLAG_BADGE03_GET, LEVEL_CAP_GYM_3}, //28
        {FLAG_BADGE04_GET, LEVEL_CAP_GYM_4}, //35
        {FLAG_HIDE_CELADON_ROCKETS, LEVEL_CAP_GIOVANNI_CELADON}, //37
        {FLAG_DEFEATED_MAROWAK_GHOST, 39},
        {FLAG_HIDE_SAFFRON_ROCKETS, LEVEL_CAP_GIOVANNI_SILPH_CO}, //43
        {FLAG_BADGE05_GET, LEVEL_CAP_GYM_5}, //45
        {FLAG_BADGE06_GET, LEVEL_CAP_GYM_6}, //54
        {FLAG_BADGE07_GET, LEVEL_CAP_GYM_7}, //60
        {FLAG_BADGE08_GET, LEVEL_CAP_GYM_8}, //68
        {FLAG_IS_CHAMPION, LEVEL_CAP_IS_CHAMPION}, // 71
    };

    u32 i;
    u8 capIndex = 0;
    if (B_LEVEL_CAP_TYPE == LEVEL_CAP_FLAG_LIST)
    {
        for (i = 0; i < ARRAY_COUNT(sLevelCapFlagMap); i++)
        {
            if (FlagGet(sLevelCapFlagMap[i][0]))
                capIndex++;
        }
    }
    else if (B_LEVEL_CAP_TYPE == LEVEL_CAP_VARIABLE)
    {
        return VarGet(B_LEVEL_CAP_VARIABLE);
    }

    if (capIndex >= LEVEL_CAP_COUNT) 
        return MAX_LEVEL;
    else if (FlagGet(FLAG_EASY_MODE))
        return MathMax(sLevelCapFlagMap[capIndex][1] + 2, MAX_LEVEL);
    else
        return sLevelCapFlagMap[capIndex][1];

    return MAX_LEVEL;
}

u32 GetSoftLevelCapExpValue(u32 level, u32 expValue)
{
    static const u32 sExpScalingDown[5] = { 4, 8, 16, 32, 64 };
    static const u32 sExpScalingUp[5]   = { 16, 8, 4, 2, 1 };

    u32 levelDifference;
    u32 currentLevelCap = GetCurrentLevelCap();

    if (B_EXP_CAP_TYPE == EXP_CAP_NONE)
        return expValue;

    if (level < currentLevelCap)
    {
        if (B_LEVEL_CAP_EXP_UP)
        {
            levelDifference = currentLevelCap - level;
            if (levelDifference > ARRAY_COUNT(sExpScalingUp) - 1)
                return expValue + (expValue / sExpScalingUp[ARRAY_COUNT(sExpScalingUp) - 1]);
            else
                return expValue + (expValue / sExpScalingUp[levelDifference]);
        }
        else
        {
            return expValue;
        }
    }
    else if (B_EXP_CAP_TYPE == EXP_CAP_HARD)
    {
        return 0;
    }
    else if (B_EXP_CAP_TYPE == EXP_CAP_SOFT)
    {
        levelDifference = level - currentLevelCap;
        if (levelDifference > ARRAY_COUNT(sExpScalingDown) - 1)
            return expValue / sExpScalingDown[ARRAY_COUNT(sExpScalingDown) - 1];
        else
            return expValue / sExpScalingDown[levelDifference];
    }
    else
    {
       return expValue;
    }
}
