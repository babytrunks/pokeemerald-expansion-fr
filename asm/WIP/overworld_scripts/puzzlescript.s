.thumb
.align 2

.include "../asm_defines.s"
.include "../xse_commands.s"
.include "../xse_defines.s"

.equ FLAG_ACTIVATE_POKEVIAL, 0x1047
.equ VAR_MAX_POKEVIAL, 0x512A

.global TestPuzzleBattle
TestPuzzleBattle:
    setflag 0x1042
    setvar 0x5127 0x0
    special 0x27 @Backup
    special 0x28 @Need to have original team when saving game
    @ special 0x23 @Save game
    @ waitstate
    callasm GivePuzzleTeam
    special 0xF5 @Choose Pokémon to fight with
    waitstate
    trainerbattle3 0x3 0x7 0x0 gText_falkner_Defeat
    release
    end

.global EventScript_PokeVialPuzzleBattle
EventScript_PokeVialPuzzleBattle:
    lock
    faceplayer
    checkflag FLAG_ACTIVATE_POKEVIAL
    if 0x1 _goto Alreadydone
    checkflag FLAG_NEW_GAME_PUZZLE
    if 0x1 _goto YouWinPokeVial
    msgbox gText_PokeVial_Teacher MSG_YESNO
    compare LASTRESULT NO
    if equal _goto EndVialPuzzleBattle
    special 0x23 @Save game
    waitstate
    goto ChooseTeam

TheRules:
    msgbox gText_PokeVial_Rules MSG_NORMAL
    goto ChooseTeam

ChooseTeam:
    setvar 0x5127 0x0
    special 0x27 @Backup
    special 0x28 @Need to have original team when saving game
    setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_ViewMyTeam
	special 0x25
	setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_OpponentsTeam
	special 0x25
    setvar 0x8006 0x2 @third item
    loadpointer 0x0 gText_HearRules
    special 0x25
    setvar 0x8006 0x3 @fourth item
    loadpointer 0x0 gText_StartBattle
    special 0x25
    preparemsg gText_WhatPuzzleAction
    waitmsg
    multichoice 0x0 0x0 0x22 0x0
    compare LASTRESULT 0x0
    if 0x1 _goto ViewYourTeam
    compare LASTRESULT 0x1
    if 0x1 _goto ViewOpponentsTeam
    compare LASTRESULT 0x2
    if 0x1 _goto TheRules
    compare LASTRESULT 0x3
    if 0x1 _goto StartBattle
    goto DoYouWantToCancel
    end

StartBattle:
    msgbox gText_PokeVial_LetsBegin MSG_NORMAL
    setflag 0x1042
    callasm GivePuzzleTeam
    special 0xF5 @Choose Pokémon to fight with
    waitstate
    compare LASTRESULT NO
    if equal _goto DoYouWantToCancel
    setvar 0x8000 0xFEFE
    trainerbattle9 0x9 0x7 0x0 gText_PokeVialPuzzle_Defeat gText_Puzzle_YouLoseBattle
    compare LASTRESULT 0x1
    if equal _goto YouLosePokeVialBattle

YouWinPokeVial:
    msgbox gText_PokeVial_NicelyDone MSG_NORMAL
    preparemsg gText_PokeVial_ReceivedPokeVial
	waitmsg
	fanfare 0x13E
	waitfanfare
    msgbox gText_PokeVial_HowToUse MSG_NORMAL
    setflag FLAG_ACTIVATE_POKEVIAL
    setvar VAR_MAX_POKEVIAL 0x6
    setvar 0x5129 0x1
    release
    end

YouLosePokeVialBattle:
    msgbox gText_Puzzle_LossPokeVial MSG_NORMAL
    release
    end

ViewYourTeam:
    setflag FLAG_NO_ELIGIBLE
    setflag FLAG_DONT_RANDOMIZE
    callasm GivePuzzleTeam
    special 0xF5
    waitstate
    clearflag FLAG_NO_ELIGIBLE
    clearflag FLAG_DONT_RANDOMIZE
    goto ChooseTeam

ViewOpponentsTeam:
    setvar 0x512B 0x7
    setflag FLAG_NO_ELIGIBLE
    setflag FLAG_DONT_RANDOMIZE
    callasm GiveOpponentPuzzleTeam
    special 0xF5
    waitstate
    clearflag FLAG_NO_ELIGIBLE
    clearflag FLAG_DONT_RANDOMIZE
    goto ChooseTeam

Alreadydone:
    msgbox gText_PokeVial_HowToUse MSG_NORMAL
    release
    end

DoYouWantToCancel: 
    clearflag 0x1042
    msgbox gText_PokeVial_TryAnotherTime MSG_YESNO
    compare LASTRESULT NO
    if equal _goto ChooseTeam
    special 0x28
    msgbox gText_PokeVial_OkNextTime MSG_NORMAL 
    release
    end

EndVialPuzzleBattle:
    release
    end



.global EventScript_PuzzleBattleMoveReminder
EventScript_PuzzleBattleMoveReminder:
    lock
    faceplayer
    checkflag FLAG_ACTIVATE_MOVEREMEMBER
    if 0x1 _goto AlreadydoneMoveRemember
    checkflag FLAG_NEW_GAME_PUZZLE
    if 0x1 _goto YouWinMoveReminder
    msgbox gText_Puzzle_MoveRemember MSG_YESNO
    compare LASTRESULT NO
    if equal _goto EndVialPuzzleBattle
    special 0x23 @Save game
    waitstate
    goto ChooseTeamMoveReminder

ChooseTeamMoveReminder:
    setvar 0x5127 0x1
    special 0x27 @Backup
    special 0x28 @Need to have original team when saving game
    setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_ViewMyTeam
	special 0x25
	setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_OpponentsTeam
	special 0x25
    setvar 0x8006 0x2 @third item
    loadpointer 0x0 gText_HearRules
    special 0x25
    setvar 0x8006 0x3 @fourth item
    loadpointer 0x0 gText_StartBattle
    special 0x25
    preparemsg gText_WhatPuzzleAction
    waitmsg
    multichoice 0x0 0x0 0x22 0x0
    compare LASTRESULT 0x0
    if 0x1 _goto ViewYourTeamMoveReminder
    compare LASTRESULT 0x1
    if 0x1 _goto ViewOpponentsTeamMoveReminder
    compare LASTRESULT 0x2
    if 0x1 _goto TheRules2
    compare LASTRESULT 0x3
    if 0x1 _goto StartBattleMoveReminder
    goto DoYouWantToCancelMoveReminder
    end

TheRules2:
    msgbox gText_PokeVial_Rules MSG_NORMAL
    goto ChooseTeamMoveReminder

DoYouWantToCancelMoveReminder:
    clearflag 0x1042
    msgbox gText_PokeVial_TryAnotherTime MSG_YESNO
    compare LASTRESULT NO
    if equal _goto ChooseTeamMoveReminder
    special 0x28
    msgbox gText_MoveReminder_OkNextTime MSG_NORMAL 
    release
    end

StartBattleMoveReminder:
    msgbox gText_PokeVial_LetsBegin MSG_NORMAL
    setvar 0x5127 0x1
    setflag 0x1042
    callasm GivePuzzleTeam
    special 0xF5 @Choose Pokémon to fight with
    waitstate
    compare LASTRESULT NO
    if equal _goto DoYouWantToCancelMoveReminder
    setvar 0x8000 0xFEFE
    trainerbattle9 0x9 0x6 0x0 gText_PokeVialPuzzle_Defeat gText_Puzzle2_YouLoseBattle
    compare LASTRESULT 0x1
	if equal _goto YouLoseMoveReminder

YouWinMoveReminder:
    setflag FLAG_ACTIVATE_MOVEREMEMBER
    msgbox gText_Puzzle_MoveReminder MSG_NORMAL
WhichPokemon:
    msgbox 0x81A2CC3 MSG_KEEPOPEN @Which Pokémon needs tutoring?"
    special 0xDB
    waitstate
    compare 0x8004 0x6
    if 0x4 _goto EndVialPuzzleBattle
    special 0x148
    compare LASTRESULT 0x1
    if 0x1 _goto 0x8171790
    compare 0x8005 0x0
    if 0x1 _goto 0x8171782
    goto WhichMoveToTeach
    release
    end

YouLoseMoveReminder:
    msgbox gText_Puzzle_LossMoveReminder MSG_NORMAL
    release
    end

ViewYourTeamMoveReminder:
    setflag FLAG_NO_ELIGIBLE
    setflag FLAG_DONT_RANDOMIZE
    callasm GivePuzzleTeam
    special 0xF5
    waitstate
    clearflag FLAG_NO_ELIGIBLE
    clearflag FLAG_DONT_RANDOMIZE
    goto ChooseTeamMoveReminder

ViewOpponentsTeamMoveReminder:
    setvar 0x512B 0x6
    setflag FLAG_NO_ELIGIBLE
    setflag FLAG_DONT_RANDOMIZE
    callasm GiveOpponentPuzzleTeam
    special 0xF5
    waitstate
    clearflag FLAG_NO_ELIGIBLE
    clearflag FLAG_DONT_RANDOMIZE
    goto ChooseTeamMoveReminder

AlreadydoneMoveRemember:
    goto WhichPokemon

WhichMoveToTeach:
    msgbox 0x81A2CE1 MSG_KEEPOPEN @Which move should I teach?"
    special 0xE0
    waitstate
    compare 0x8004 0x0
    if 0x1 _goto WhichPokemon
    msgbox gText_Puzzle_IfYourPokemonNeed MSG_NORMAL
    goto EndVialPuzzleBattle
    end
