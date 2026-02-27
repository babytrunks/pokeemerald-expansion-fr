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


void CB2_InitRacMenu(void);

#endif // GUARD_RAC_MENU_H
