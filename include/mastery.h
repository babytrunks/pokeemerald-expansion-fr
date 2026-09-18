#ifndef GUARD_MASTERY_H
#define GUARD_MASTERY_H

#include "constants/mastery.h"

// One challenge shared by every species that points at it
// Completes once per save, the reward is handed out once
struct Mastery
{
    const u8 *title;       // shown on the pop up plate, keep it under about 12 characters
    const u8 *description; // shown on the summary screen mastery page
    u16 reward;            // ITEM_ constant handed over on completion
    u16 param;             // meaning depends on event, see enum MasteryEvent
    u8 event;              // enum MasteryEvent
    u8 targetCount;        // ticks needed to complete, must fit in a u8
    bool8 perBattle;       // progress resets every battle so targetCount must be hit in one
    u8 levelUnlocked;      // leave unset for always unlocked, else the mon must be at least this level
};

extern const struct Mastery gMasteries[MASTERY_COUNT];

u32 GetSpeciesMastery(u32 species);
bool32 IsMasteryCompleted(u32 masteryId);
u32 GetMasteryProgress(u32 masteryId);
bool32 IsMasteryUnlockedAtLevel(u32 masteryId, u32 level);
void ClearPerBattleMasteryProgress(void);
void TryTickMastery(u32 battler, u32 event, u32 param);
void TryTickMasteryAtMoveEnd(void);

#endif // GUARD_MASTERY_H
