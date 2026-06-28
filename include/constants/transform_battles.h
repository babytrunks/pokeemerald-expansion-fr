#ifndef GUARD_CONSTANTS_TRANSFORM_BATTLES_H
#define GUARD_CONSTANTS_TRANSFORM_BATTLES_H

// Indices into sTransformBattleTable (src/battle_script_commands.c), selected via
// VAR_TRANSFORM_BATTLE_TYPE. When FLAG_TRANSFORM_BATTLE is set and an opponent's
// species matches the table entry's fromSpecies, it transforms (full HP + Mega
// Evolution animation) instead of fainting, once per battle.
#define TRANSFORM_BATTLE_MEWTWO   0
// add future transformations here

#endif // GUARD_CONSTANTS_TRANSFORM_BATTLES_H
