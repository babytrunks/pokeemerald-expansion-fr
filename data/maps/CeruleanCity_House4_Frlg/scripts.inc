CeruleanCity_House4_Frlg_MapScripts::
	.byte 0

@ Puzzle battle, the old man lends the player 6 mons and the player picks 3
@ The real party is backed up by PuzzleBattle_Begin and restored by PuzzleBattle_End
@ Every exit path below must reach PuzzleBattle_End or the player loses their team
CeruleanCity_House4_EventScript_PuzzleMan::
	lock
	faceplayer
	goto_if_set FLAG_PUZZLE_BATTLE_1_SOLVED, CeruleanCity_House4_EventScript_AlreadySolved
	msgbox CeruleanCity_House4_Text_CareToEntertainMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeruleanCity_House4_EventScript_Declined
	msgbox CeruleanCity_House4_Text_WisdomReward
	special PuzzleBattle_Begin
	setvar VAR_0x8004, TRAINER_PUZZLE_BATTLE_PLAYER_TEAM_1
	special PuzzleBattle_LoadTeam
	goto CeruleanCity_House4_EventScript_PuzzleMenu
	end

CeruleanCity_House4_EventScript_PuzzleMenu::
	message CeruleanCity_House4_Text_WhatWouldYouLikeToDo
	waitmessage
	multichoice 0, 0, MULTI_PUZZLE_BATTLE, FALSE
	switch VAR_RESULT
	case 0, CeruleanCity_House4_EventScript_ViewPlayerTeam
	case 1, CeruleanCity_House4_EventScript_ViewOpponentTeam
	case 2, CeruleanCity_House4_EventScript_ExplainRules
	case 3, CeruleanCity_House4_EventScript_StartPuzzleBattle
	case MULTI_B_PRESSED, CeruleanCity_House4_EventScript_BackOut
	goto CeruleanCity_House4_EventScript_BackOut
	end

CeruleanCity_House4_EventScript_ViewPlayerTeam::
	setvar VAR_0x8004, TRAINER_PUZZLE_BATTLE_PLAYER_TEAM_1
	special PuzzleBattle_LoadTeam
	special ShowPuzzleBattleTeam
	waitstate
	lock
	faceplayer
	goto CeruleanCity_House4_EventScript_PuzzleMenu
	end

CeruleanCity_House4_EventScript_ViewOpponentTeam::
	setvar VAR_0x8004, TRAINER_PUZZLE_BATTLE_OPP_TEAM_1
	special PuzzleBattle_LoadTeam
	special ShowPuzzleBattleTeam
	waitstate
	lock
	faceplayer
	goto CeruleanCity_House4_EventScript_PuzzleMenu
	end

CeruleanCity_House4_EventScript_ExplainRules::
	msgbox CeruleanCity_House4_Text_PuzzleRules
	goto CeruleanCity_House4_EventScript_PuzzleMenu
	end

CeruleanCity_House4_EventScript_StartPuzzleBattle::
	@ Reload the loaners in case the player was last looking at the old man's team
	setvar VAR_0x8004, TRAINER_PUZZLE_BATTLE_PLAYER_TEAM_1
	special PuzzleBattle_LoadTeam
	fadescreen FADE_TO_BLACK
	special ChoosePuzzleBattleParty
	waitstate
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House4_EventScript_PuzzleMenu
	special ReducePlayerPartyToSelectedMons
	trainerbattle_earlyrival TRAINER_PUZZLE_BATTLE_OPP_TEAM_1, RIVAL_BATTLE_HEAL_AFTER, CeruleanCity_House4_Text_CoachDefeat, CeruleanCity_House4_Text_CoachVictory
	@ Restore the real party before anything else can go wrong
	special PuzzleBattle_End
	@ earlyrival sets VAR_RESULT to TRUE when the player lost
	goto_if_eq VAR_RESULT, TRUE, CeruleanCity_House4_EventScript_PuzzleLost
	setflag FLAG_MOVE_RELEARNER_UNLOCKED
	setflag FLAG_PUZZLE_BATTLE_1_SOLVED
	msgbox CeruleanCity_House4_Text_Congratulations
	release
	end

CeruleanCity_House4_EventScript_PuzzleLost::
	msgbox CeruleanCity_House4_Text_TryAgainNextTime
	release
	end

CeruleanCity_House4_EventScript_BackOut::
	special PuzzleBattle_End
	msgbox CeruleanCity_House4_Text_ComeBackWhenReady
	release
	end

CeruleanCity_House4_EventScript_Declined::
	msgbox CeruleanCity_House4_Text_SuitYourself
	release
	end

CeruleanCity_House4_EventScript_AlreadySolved::
	msgbox CeruleanCity_House4_Text_AlreadySolved
	release
	end

CeruleanCity_House4_Text_CareToEntertainMe::
	.string "Sigh…\n"
	.string "Too much time, too little to do…\p"
	.string "You there! You have the look of\n"
	.string "someone who thinks.\p"
	.string "Would you care to entertain an old\n"
	.string "man by solving a puzzle?$"

CeruleanCity_House4_Text_SuitYourself::
	.string "Hmph. Suit yourself.\p"
	.string "I'll be right here if you change\n"
	.string "your mind.$"

CeruleanCity_House4_Text_WisdomReward::
	.string "Splendid!\p"
	.string "I've spent a lifetime studying how\n"
	.string "Pokémon remember their moves.\p"
	.string "Solve my puzzle, and I'll share that\n"
	.string "wisdom with you.\p"
	.string "You'll be able to have your Pokémon\n"
	.string "recall forgotten moves yourself,\l"
	.string "anywhere, any time.$"

CeruleanCity_House4_Text_WhatWouldYouLikeToDo::
	.string "What would you like to do?$"

CeruleanCity_House4_Text_PuzzleRules::
	.string "The rules are simple.\p"
	.string "You select 3 Pokémon from 6\n"
	.string "that I provide for you.\p"
	.string "I assure you that among these choices\n"
	.string "lie a guaranteed path to victory.\p"
	.string "The order I send out my Pokémon will\n"
	.string "stay consistent, and I will not\l"
	.string "manually switch.$"

CeruleanCity_House4_Text_CoachDefeat::
	.string "Ha! You found it!\n"
	.string "I knew that mind of yours was sharp.$"

CeruleanCity_House4_Text_CoachVictory::
	.string "Not quite.\n"
	.string "The answer was there all along.$"

CeruleanCity_House4_Text_Congratulations::
	.string "Wonderful! Simply wonderful!\p"
	.string "A promise is a promise.\n"
	.string "Let me share what I know.\p"
	.string "From now on, view a Pokémon's moves\n"
	.string "in its summary and press START.\p"
	.string "It will recall a move it once knew.\n"
	.string "Use that gift wisely.$"

CeruleanCity_House4_Text_TryAgainNextTime::
	.string "A shame.\p"
	.string "Don't fret, your own Pokémon are\n"
	.string "safe and sound.\p"
	.string "Think it over, and try again\n"
	.string "next time.$"

CeruleanCity_House4_Text_ComeBackWhenReady::
	.string "Take your time.\n"
	.string "The puzzle isn't going anywhere.$"

CeruleanCity_House4_Text_AlreadySolved::
	.string "Ah, my clever friend!\p"
	.string "I've no puzzles left worthy of you.\n"
	.string "Put my wisdom to good use.$"
