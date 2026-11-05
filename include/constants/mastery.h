#ifndef GUARD_CONSTANTS_MASTERY_H
#define GUARD_CONSTANTS_MASTERY_H

// Kinds of in battle event a mastery can listen for
// param meaning is noted per entry, unused params should be 0
enum MasteryEvent
{
    MASTERY_EVENT_NONE,
    MASTERY_EVENT_ABILITY_BOOSTED_MOVE, // param is the ability that boosted the move
    MASTERY_EVENT_MAGNITUDE_LEVEL,      // param is the magnitude number, 4 to 10
    MASTERY_EVENT_MOVE_USED,            // param is the move
    MASTERY_EVENT_KO_WITH_TYPE,         // param is the type that landed the KO
    MASTERY_EVENT_SUPER_EFFECTIVE_HIT,  // param unused
    MASTERY_EVENT_SUPER_EFFECTIVE_KO,   // param is the type of the super effective move that landed the KO
};

// Mastery ids, 0 means the species has no mastery
// Keep MASTERY_LAST pointing at the final entry
// Ids are append only, renumbering scrambles progress stored in old saves
#define MASTERY_NONE                0
#define MASTERY_WILD_GROWTH     1
#define MASTERY_TREMOR_SENSE        2
#define MASTERY_LINGERING_EMBER     3
#define MASTERY_RISING_TIDE         4
#define MASTERY_TRICKSTER           5
#define MASTERY_PECK_FROM_ABOVE     6

#define MASTERY_LAST                MASTERY_PECK_FROM_ABOVE
#define MASTERY_COUNT               (MASTERY_LAST + 1)

// Save footprint is fixed so adding masteries never shifts the rest of SaveBlock1
// Never lower this, and never size the save arrays by MASTERY_COUNT
#define MASTERY_SAVE_SLOTS          256
#define NUM_MASTERY_FLAG_BYTES      ROUND_BITS_TO_BYTES(MASTERY_SAVE_SLOTS)

// Longest description in gMasteries, used for the summary page stack buffer
#define MASTERY_MAX_DESCRIPTION_LENGTH 128

#endif // GUARD_CONSTANTS_MASTERY_H
