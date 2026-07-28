## How to use the battle status menu

The Battle Info is a replica from modern games. 
It shows the current snapshot of the battle. 
That includes Pokémon's stat stages, volatile conditions, 
Ability / Item for the player side, and field statuses.

-- TODO: explain the enums and description
### How to add new field statuses or volatiles to the menu

#### 1. Adding new battler volatiles 
There are 3 options:
```C
static void TryAddActiveStatus(
                enum BattleStatus status, 
                u32 status, 
                enum BattleSide side
            );
```
`TryAddActiveStatus` is used for volatiles without a timer, meaning they persist until the battle is over
It is also used when a timer is unknown
```C

static void TryAddActiveStatusTimer(
                enum BattleStatus status, 
                u32 remaining, 
                u32 baseTotal, 
                enum BattleSide side
            );
```
`TryAddActiveStatusTimer` is used for volatiles that expire. 
`remaining` is the time until it runs out. 
`baseTotal` is the maximum amount of turns.

#### 2. Field conditions
```C
static void TryAddActiveFieldStatus(
                enum BattleStatus status, 
                u32 fieldStatus, 
                u32 timer, 
                u32 totalTimer, 
                enum BattleSide side
            );
```
`TryAddActiveFieldStatus` is used for field statuses like Trick Room.
If it's a permanent status, the timer will be ignored so the values passed can be zero.

```C
static void TryAddActiveSideStatus(
                enum BattleStatus status, 
                u32 sideStatus, 
                u32 timer, 
                u32 totalTimer, 
                enum BattleSide side
            );
```
`TryAddActiveSideStatus` is used  for side statuses like Light Screen.
As previously, if it's a permanent status, the timer will be ignored so the values passed can be zero.

### 3. Weather and Terrain
Weather and Terrain have extra functions, `TryAddActiveWeather` and `TryAddActiveTerrain`.
If a new weather/terrain is added, the compiler will usually throw an error to add it.

## Pages

The menu is a small page state machine driven by `Task_BattleInfoLoadPage`.
`sData->nextPage` holds the page being moved to; `B_INFO_STATE_CLEAR_PAGE` tears down
`sData->page`, swaps in `nextPage`, and `B_INFO_STATE_ENTER_PAGE` builds it back up.
`BattleInfoPageEnter` / `BattleInfoPageExit` map a page to its `*Enter` / `*Exit` pair,
so adding a page means adding an entry to `enum BattleMenuPages` plus those two switches
and a branch in `Task_BattleMenuStatus_HandleInput`.

| Page | Opened with | Back |
| --- | --- | --- |
| `B_INFO_PAGE_OVERVIEW` | `B_BATTLE_STATUS_MENU_BUTTON` from the action menu | `B` exits the menu |
| `B_INFO_PAGE_DETAIL` | `A` on an overview card (`L`/`R` cycle battlers) | `B` |
| `B_INFO_PAGE_ENEMY_PARTY` | `R` on the overview page | `B` or `R` |

### The Enemy Party page

Shows the opposing party the player has scouted so far. It replaces the old standalone
R-button menu (`src/battle_info_menu.c`), which is still in the tree but no longer
reachable — `B_SHOW_BATTLE_INFO_BUTTON` is `FALSE` and `HandleInputChooseAction` no
longer emits `B_ACTION_BATTLE_INFO`. Set that config back to `TRUE` and restore the
`R_BUTTON` branch in `src/battle_controller_player.c` to bring it back.

Data comes from `gAiPartyData->mons[B_SIDE_OPPONENT]`, populated by `Ai_InitPartyStruct`
at the start of every battle. Visibility follows the old menu's rules:

- Species icons and status icons are drawn for the **whole** party, scouted or not.
  To hide unscouted species instead, gate the loop in `EnemyPartyCreateRosterSprites`
  on `EnemyPartyIsSlotScouted(i)`.
- Level, ability, held item and moves only appear once `wasSentInBattle` is set for
  that slot; until then the info card shows `???`.

Note that `B_INFO_OPPOSING_INFORMATION` deliberately does **not** gate this page — it
only controls whether the *detail* page reveals abilities/items for opposing battlers.

The page reuses the overview's four windows (`WIN_LABEL_TOP`, `WIN_ROW_ENEMY`,
`WIN_ROW_PLAYER`, `WIN_LABEL_BOTTOM`) because its roster and info cards line up with the
overview's battler rows, so no extra window templates or base blocks are needed. Layout
constants live in `include/constants/battle_info.h` under `B_INFO_PARTY_*`.
