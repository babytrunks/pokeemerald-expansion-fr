#ifndef GUARD_CONSTANTS_TRAINER_TYPES_H
#define GUARD_CONSTANTS_TRAINER_TYPES_H

#define TRAINER_TYPE_NONE               0
#define TRAINER_TYPE_NORMAL             1
#define TRAINER_TYPE_SEE_ALL_DIRECTIONS 2
#define TRAINER_TYPE_BURIED             3
#define TRAINER_TYPE_QUEST_GIVER        4
// Behaves like TRAINER_TYPE_NONE (no sight line, talk-to only) but shows a
// menacing icon while the trainer in ObjectEventTemplate.iconParam is undefeated.
#define TRAINER_TYPE_MENACING           5

#endif  // GUARD_CONSTANTS_TRAINER_TYPES_H
