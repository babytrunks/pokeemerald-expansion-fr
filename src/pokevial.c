#include "global.h"
#include "pokevial.h"
#include "constants/items.h"
#include "graphics.h"
#include "math_util.h"
#include "random.h"
#include "event_data.h"

static void PokevialFixDoseOverflow(void);

static void PokevialInit()
{
    if (VarGet(VAR_POKEVIAL_MAX_SIZE) < VIAL_MIN_SIZE)
    {
        VarSet(VAR_POKEVIAL_MAX_SIZE,VIAL_MIN_SIZE );
        VarSet(VAR_POKEVIAL_CURRENT_DOSE,VIAL_MIN_SIZE );
    }
}

u32 PokevialGetDose()
{
    // PokevialInit();
    return VarGet(VAR_POKEVIAL_CURRENT_DOSE); 
}

u32 PokevialGetSize()
{
    // PokevialInit();
    return VarGet(VAR_POKEVIAL_MAX_SIZE);
}

void PokevialSizeUp(u8 sizeIncrease)
{
    VarSet(VAR_POKEVIAL_MAX_SIZE, VarGet(VAR_POKEVIAL_MAX_SIZE) + sizeIncrease);
}

void PokevialDoseUp(u8 doseIncrease)
{
    VarSet(VAR_POKEVIAL_CURRENT_DOSE, VarGet(VAR_POKEVIAL_CURRENT_DOSE) + doseIncrease);
}

void PokevialSizeDown(u8 sizeDecrease)
{
    VarSet(VAR_POKEVIAL_MAX_SIZE, VarGet(VAR_POKEVIAL_MAX_SIZE) - sizeDecrease);
    PokevialFixDoseOverflow();
}

void PokevialDoseDown(u8 doseDecrease)
{
    VarSet(VAR_POKEVIAL_CURRENT_DOSE, VarGet(VAR_POKEVIAL_CURRENT_DOSE) - doseDecrease);
}

static void PokevialFixDoseOverflow(void)
{
    PokevialDoseUp(0);
}

bool32 PokevialRefill()
{
    if (PokevialGetDose() == PokevialGetSize())
        return FALSE;

    VarSet(VAR_POKEVIAL_CURRENT_DOSE, VarGet(VAR_POKEVIAL_MAX_SIZE));
    return TRUE;
}

const u32 *const pokevialIconIndex[VIAL_NUM_STATES] =
{
    gItemIcon_Pokevial0,
    gItemIcon_Pokevial1,
    gItemIcon_Pokevial2,
    gItemIcon_Pokevial3,
    gItemIcon_Pokevial4,
    gItemIcon_Pokevial5,
    gItemIcon_Pokevial6,
    gItemIcon_Pokevial7,
    gItemIcon_Pokevial8,
    gItemIcon_Pokevial9,
    gItemIcon_Pokevial
};

static u32 PokevialGetVialPercent(void)
{
    u32 dose = PokevialGetDose(), size = PokevialGetSize(), vialPercent = 0;

    if (dose == EMPTY_VIAL)
        return POKEVIAL_ICON_PERCENT_0;

    if (dose == size)
        return POKEVIAL_ICON_PERCENT_100;

    vialPercent = (dose * 10 / size);

    return (vialPercent == EMPTY_VIAL && dose > EMPTY_VIAL) ? POKEVIAL_ICON_PERCENT_10 : vialPercent;
}

const void *PokevialGetDoseIcon(void)
{
    return pokevialIconIndex[PokevialGetVialPercent()];
}