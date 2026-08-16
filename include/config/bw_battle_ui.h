#ifndef GUARD_CONFIG_BW_BATTLE_UI_H
#define GUARD_CONFIG_BW_BATTLE_UI_H

#include "config/battle.h"

// Black/White-styled lower battle screen: message box, action box, move box and shared cursor.
// The healthboxes are a separate port, controlled only by BW_BATTLE_UI_HEALTHBOX_ENGINE_FONT below.

#define BW_BATTLE_UI                (TRUE)

#define BW_BATTLE_UI_TEXTBOX        (TRUE)  // BW1-styled textbox. With BW_BATTLE_UI_INPUTBOX off, the gen3 navigation menu is kept.
#define BW_BATTLE_UI_INPUTBOX       (TRUE)  // Action box, move box and cursor. Requires BW_BATTLE_UI_TEXTBOX.

#define BW_BATTLE_UI_HEALTHBOX_ENGINE_FONT  (TRUE)  // Draws healthbox nickname and level with the engine's outlined fonts, not bw_name_font.png.

// Config safeguards, do not delete unless you know what you're doing!
#if (B_MOVE_REARRANGEMENT_IN_BATTLE < GEN_4)
#error "pokeemerald-expansion's `B_MOVE_REARRANGEMENT_IN_BATTLE' config is unsupported by `BW_BATTLE_UI'!"
#endif

#if (BW_BATTLE_UI_TEXTBOX != TRUE && BW_BATTLE_UI_INPUTBOX == TRUE)
#error "The config `BW_BATTLE_UI_INPUTBOX' requires `BW_BATTLE_UI_TEXTBOX' to be both set to `TRUE'!"
#endif

#endif // GUARD_CONFIG_BW_BATTLE_UI_H
