#ifndef GUARD_BATTLE_FACTORY_H
#define GUARD_BATTLE_FACTORY_H

void CallBattleFactoryFunction(void);
bool8 InBattleFactory(void);
u8 GetFactoryMonFixedIV(u8 challengeNum, bool8 isLastBattle);
void FillFactoryBrainParty(void);
u8 GetNumPastRentalsRank(u8 battleMode, u8 lvlMode);
u64 GetAiScriptsInBattleFactory(void);
void SetMonMoveAvoidReturn(struct Pokemon *mon, u16 moveArg, u8 moveSlot);
bool32 IsStarterSelectScreen(void);
u16 GetRareScreenMonSpecies(u16 species);
void GetRareScreenStarterSpecies(u16 *species);

#endif // GUARD_BATTLE_FACTORY_H
