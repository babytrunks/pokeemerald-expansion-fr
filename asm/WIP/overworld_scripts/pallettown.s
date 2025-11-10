.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s" 

.equ FLAG_EASY_MODE, 0x1033
.equ FLAG_HARDCORE_MODE, 0x1034
.equ FLAG_RESTRICT_MODE, 0x103C
.equ FLAG_SYS_SAVE_HIDE, 0x91D
.equ JOHTO_STARTER, 2
.equ HOENN_STARTER, 3
.equ SINNOH_STARTER, 4
.equ UNOVA_STARTER, 5
.equ KALOS_STARTER, 6
.equ ALOLA_STARTER, 7
.equ GALAR_STARTER, 8
.equ PALDEA_STARTER, 9
.equ FLAG_BEAT_PROF_OAK, 0x107D

.global gMapScripts_PalletTownHome
gMapScripts_PalletTownHome:
    mapscript MAP_SCRIPT_ON_TRANSITION SetVar_PalletTownHome
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScripts_PalletTownHome
    .byte MAP_SCRIPT_TERMIN

.global gMapScripts_PalletTownPlayerHome
gMapScripts_PalletTownPlayerHome:
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScripts_PalletTownPlayerHome
    .byte MAP_SCRIPT_TERMIN

LevelScripts_PalletTownHome:
    levelscript 0x5108, 0, LevelScript_PalletTownHome
    levelscript 0x5100, 2, LevelScript_PalletTownAskStarterRegion
    .hword MAP_SCRIPT_TERMIN

LevelScripts_PalletTownPlayerHome:
    levelscript 0x5100, 0, LevelScript_PalletTownPlayerHome_2
    .byte MAP_SCRIPT_TERMIN

LevelScript_PalletTownPlayerHome:
    setvar 0x5100 0x2
    @ setvar 0x407C 0x2
    setflag FLAG_SYS_SAVE_HIDE
    fadescreen 0x1
    fadeoutbgm 0x0
    sethealingplace 0x1
    msgbox gText_PleaseStop MSG_KEEPOPEN
    pause 0x70
    closeonkeypress
    callasm CheckIfHallOfFame
    compare LASTRESULT 0x1
    if equal _call SetHofFlag
    msgbox gText_DoYouWantDefinitiveEdition MSG_YESNO
    compare LASTRESULT YES
    if equal _goto DefinitiveEdition
    msgbox gText_DoYouWantMinGrinding MSG_YESNO
    compare LASTRESULT YES
    if equal _call setmingrinding
    msgbox gText_DoYouWantHardcoreMode MSG_YESNO
    compare LASTRESULT YES
    if equal _goto sethardcoremode
    msgbox gText_DoYouWantRestrictMode MSG_YESNO
    compare LASTRESULT YES
    if equal _goto setrestrictmode
    msgbox gText_DoYouWantEasyMode MSG_YESNO
    compare LASTRESULT YES
    if equal _call seteasymode
    goto AskRandomizer

LevelScript_PalletTownPlayerHome_2:
    setvar 0x5100 0x2
    setflag FLAG_SYS_SAVE_HIDE
    fadescreen 0x1
    fadeoutbgm 0x0
    sethealingplace 0x1
    msgbox gText_PleaseStop MSG_KEEPOPEN
    pause 0x30
    closeonkeypress
    callasm CheckIfHallOfFame
    compare LASTRESULT 0x1
    if equal _call SetHofFlag
    msgbox gText_DoYouWantDefinitiveEdition MSG_YESNO
    compare LASTRESULT YES
    if equal _goto DefinitiveEdition

ShowCustomRROptions:
    setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_DifficultyOptions
	special 0x25
    checkflag FLAG_MINIMAL_GRINDING_MODE
    if 0x0 _call SetMGMTextOFF
    checkflag FLAG_MINIMAL_GRINDING_MODE
    if 0x1 _call SetMGMTextON
    setvar 0x8006 0x2 @third item
    loadpointer 0x0 gText_RandomizerOptions
    special 0x25
    setvar 0x8006 0x3
    loadpointer 0x0 gText_Done
    special 0x25
    preparemsg gText_WhichOptionToCustomize
    waitmsg
    multichoice 0x0 0x0 0x22 0x1
    compare LASTRESULT 0x0
    if 0x1 _goto DifficultyOptions
    compare LASTRESULT 0x1
    if 0x1 _goto MGMModeAsk
    compare LASTRESULT 0x2
    if 0x1 _goto RandomizerOptions
    compare LASTRESULT 0x3
    if 0x1 _goto DoneWithOptions

SetMGMTextOFF:
	setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_MinimalGrindingMode
	special 0x25
    return

SetMGMTextON:
	setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_MinimalGrindingModeON
	special 0x25
    return

DifficultyOptions:
    call SetNormalModeText
DifficultyOptions2:
    call SetRestrictedText
    call SetHardcoreTExt
    call SetEasyText
    setvar 0x8006 0x4 @fifth item
    loadpointer 0x0 gText_Done
    special 0x25
    preparemsg gText_WhichDifficulty
    waitmsg
    multichoice 0x0 0x0 0x23 0x0
    compare LASTRESULT 0x0
    if 0x1 _goto ToggleNormal
    compare LASTRESULT 0x1
    if 0x1 _goto ToggleRestricted
    compare LASTRESULT 0x2
    if 0x1 _goto ToggleHardcore
    compare LASTRESULT 0x3
    if 0x1 _goto ToggleEasy
    compare LASTRESULT 0x4
    if 0x1 _goto DoneWithDifficultyOptions
    goto DoneWithDifficultyOptions

SetNormalModeText:
    checkflag FLAG_RESTRICT_MODE
    if 0x1 _goto SetNormalTextOFF
    checkflag FLAG_EASY_MODE
    if 0x1 _goto SetNormalTextOFF
    checkflag FLAG_HARDCORE_MODE
    if 0x1 _goto SetNormalTextOFF
    setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_NormalModeON
	special 0x25
    goto DifficultyOptions2

SetNormalTextOFF:
    setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_NormalMode
	special 0x25
    goto DifficultyOptions2

SetRestrictedText:
    checkflag FLAG_RESTRICT_MODE
    if 0x1 _call SetRestrictTextON
    checkflag FLAG_RESTRICT_MODE
    if 0x0 _call SetRestrictTextOFF
    return

SetRestrictTextOFF:
	setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_Restricted
	special 0x25
    return 

SetRestrictTextON:
	setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_RestrictedON
	special 0x25
    return 

SetHardcoreTExt:
    checkflag FLAG_HARDCORE_MODE
    if 0x1 _call SetHardcoreTextON
    checkflag FLAG_HARDCORE_MODE
    if 0x0 _call SetHardcoreTextOFF
    return

SetHardcoreTextOFF:
    setvar 0x8006 0x2 @third item
    loadpointer 0x0 gText_Hardcore
    special 0x25
    return

SetHardcoreTextON:
    setvar 0x8006 0x2 @third item
    loadpointer 0x0 gText_HardcoreON
    special 0x25
    return


SetEasyText:
    checkflag FLAG_EASY_MODE
    if 0x1 _call SetEasyTextON
    checkflag FLAG_EASY_MODE
    if 0x0 _call SetEasyTextOFF
    return

SetEasyTextON:
    setvar 0x8006 0x3 @fourth Item
    loadpointer 0x0 gText_EasyModeON
    special 0x25
    return

SetEasyTextOFF:
    setvar 0x8006 0x3 @fourth Item
    loadpointer 0x0 gText_EasyModeTxt
    special 0x25
    return

ToggleNormal:
    checkflag FLAG_RESTRICT_MODE
    if 0x1 _goto AskNormalON
    checkflag FLAG_EASY_MODE
    if 0x1 _goto AskNormalON
    checkflag FLAG_HARDCORE_MODE
    if 0x1 _goto AskNormalON
    msgbox gText_NormalModeInfo MSG_KEEPOPEN
    pause 0x5
    closeonkeypress
    goto DifficultyOptions

AskNormalON:
    msgbox gText_NormalModeInfoOn MSG_YESNO
    if equal _goto ToggleNormalModeON
    goto DifficultyOptions
    
ToggleNormalModeON:
    clearflag FLAG_HARDCORE_MODE
    clearflag FLAG_EASY_MODE
    clearflag FLAG_RESTRICT_MODE
    sound 0x30
    msgbox gText_NormalDifficultySet MSG_NORMAL
    checksound
    goto DifficultyOptions

ToggleRestricted:
    checkflag FLAG_RESTRICT_MODE
    if 0x1 _goto AskRestrictedOFF
    checkflag FLAG_RESTRICT_MODE
    if 0x0 _goto AskRestrictedON

AskRestrictedOFF:
    msgbox gText_DoYouWantRestrictModeOFF MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto SetRestrictedOff
    goto DifficultyOptions

AskRestrictedON:
    msgbox gText_DoYouWantRestrictMode MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto SetRestrictedOn
    goto DifficultyOptions
SetRestrictedOn:
    clearflag FLAG_HARDCORE_MODE
    clearflag FLAG_EASY_MODE 
    setflag FLAG_RESTRICT_MODE
    sound 0x30
    msgbox gText_restrictmodeset MSG_NORMAL
    checksound
    goto DifficultyOptions

SetRestrictedOff:
    clearflag FLAG_RESTRICT_MODE
    sound 0x3
    msgbox gText_restrictmodesetOff MSG_NORMAL
    checksound
    goto DifficultyOptions

ToggleHardcore:
    checkflag FLAG_HARDCORE_MODE
    if 0x1 _goto AskHardcoreOFF
    checkflag FLAG_RESTRICT_MODE
    if 0x0 _goto AskHardcoreON

AskHardcoreOFF:
    msgbox gText_DoYouWantHardcoreModeOFF MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto SetHardcoreOff
    goto DifficultyOptions

AskHardcoreON:
    msgbox gText_DoYouWantHardcoreMode MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto SetHardcoreOn
    goto DifficultyOptions

SetHardcoreOff:
    clearflag FLAG_HARDCORE_MODE
    sound 0x3
    msgbox gText_HardcoreModeTurnedOff MSG_NORMAL
    checksound
    goto DifficultyOptions

SetHardcoreOn:
    setflag FLAG_HARDCORE_MODE
    setflag FLAG_MINIMAL_GRINDING_MODE
    clearflag FLAG_EASY_MODE
    clearflag FLAG_RESTRICT_MODE
    sound 0x30
    msgbox gText_hardcoremodeset MSG_NORMAL
    checksound
    sound 0x30
    msgbox gText_setmingrinding MSG_NORMAL
    checksound 
    goto DifficultyOptions

ToggleEasy:
    checkflag FLAG_EASY_MODE
    if 0x1 _goto AskEasyOFF
    checkflag FLAG_EASY_MODE
    if 0x0 _goto AskEasyON

AskEasyOFF:
    msgbox gText_DoYouWantEasyModeOFF MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto SetEasyOff
    goto DifficultyOptions

AskEasyON:
    msgbox gText_DoYouWantEasyMode MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto SetEasyOn
    goto DifficultyOptions

SetEasyOff:
    clearflag FLAG_EASY_MODE
    sound 0x3
    msgbox gText_easymodesetOFF MSG_NORMAL
    goto DifficultyOptions

SetEasyOn:
    setflag FLAG_EASY_MODE
    clearflag FLAG_RESTRICT_MODE
    clearflag FLAG_HARDCORE_MODE
    sound 0x30
    msgbox gText_easymodeset MSG_NORMAL
    checksound
    goto DifficultyOptions

DoneWithDifficultyOptions:
    goto ShowCustomRROptions

MGMModeAsk:
    checkflag FLAG_MINIMAL_GRINDING_MODE 
    if 0x0 _goto MGMModeAskOn
    goto MGMModeAskOff

MGMModeAskOn:
    msgbox gText_DoYouWantMinGrinding MSG_YESNO
    compare LASTRESULT YES
    if 0x1 _call setmingrinding2
    goto ShowCustomRROptions

MGMModeAskOff:
    checkflag FLAG_HARDCORE_MODE
    if 0x1 _goto CantPlayWithHC
    msgbox gText_DoYouWantMinGrindingOff MSG_YESNO
    compare LASTRESULT YES
    if 0x1 _call clearmindgrinding
    goto ShowCustomRROptions

CantPlayWithHC:
    msgbox gText_MinGrindingInfo MSG_NORMAL
    goto ShowCustomRROptions

clearmindgrinding:
    clearflag FLAG_MINIMAL_GRINDING_MODE
    sound 0x3
    msgbox gText_clearmingrinding MSG_KEEPOPEN
    checksound
    closeonkeypress 
    return
setmingrinding2:
    setflag FLAG_MINIMAL_GRINDING_MODE
    sound 0x30
    msgbox gText_setmingrinding MSG_KEEPOPEN
    checksound
    closeonkeypress 
    return

RandomizerOptions:
    call SetSpeciesText
ContinueAfterSpeciesText:
    call SetAbilityText
    call SetMoveText
    setvar 0x8006 0x3 @fourth item
    loadpointer 0x0 gText_Done
    special 0x25
    preparemsg gText_WhichRandomizerOptionToCustomize
    waitmsg
    multichoice 0x0 0x0 0x22 0x0
    compare LASTRESULT 0x0
    if 0x1 _goto ToggleSpecies
    compare LASTRESULT 0x1
    if 0x1 _goto ToggleAbility
    compare LASTRESULT 0x2
    if 0x1 _goto ToggleMoves
    compare LASTRESULT 0x3
    if 0x1 _goto DoneWithRandomizer
    goto DoneWithRandomizer

ToggleSpecies:
    call SetSpeciesNormalText
    call SetSpeciesScaledText
    setvar 0x8006 0x2
    loadpointer 0x0 gText_Done
    special 0x25
    preparemsg gText_WhichSpeciesOption
    waitmsg
    multichoice 0x0 0x0 0x21 0x0
    compare LASTRESULT 0x0
    if 0x1 _goto ToggleDefaultSpecies
    compare LASTRESULT 0x1
    if 0x1 _goto ToggleScaledSpecies
    compare LASTRESULT 0x2
    if 0x1 _goto DoneWithSpeciesRandomizer
    goto DoneWithSpeciesRandomizer

ToggleDefaultSpecies:
    checkflag FLAG_POKEMON_RANDOMIZER
    if 0x0 _goto AskSetSpeciesRandomizerOn
    checkflag FLAG_POKEMON_RANDOMIZER
    if 0x1 _goto AskSetSpeciesRandomizerOff

AskSetSpeciesRandomizerOn:
    msgbox gText_DoYouWantRandomizer MSG_YESNO
    compare LASTRESULT 0x1
    if equal _goto SetSpeciesRandomiozerON
    goto ToggleSpecies


SetSpeciesRandomiozerON:
    clearflag FLAG_SCALED_RANDOMIZER
    setflag FLAG_POKEMON_RANDOMIZER
    sound 0x30
    msgbox gText_RandomizerSet MSG_NORMAL
    goto ToggleSpecies

AskSetSpeciesRandomizerOff:
    msgbox gText_DoYouWantRandomizerOFF MSG_YESNO
    compare LASTRESULT 0x1
    if equal _goto SetSpeciesRandomizerOFF
    goto ToggleSpecies

SetSpeciesRandomizerOFF:
    clearflag FLAG_POKEMON_RANDOMIZER
    sound 0x3
    msgbox gText_RandomizerSetOFF MSG_NORMAL
    goto ToggleSpecies

ToggleScaledSpecies:
    checkflag FLAG_SCALED_RANDOMIZER
    if 0x0 _goto AskScaledRandomizer
    checkflag FLAG_SCALED_RANDOMIZER
    if 0x1 _goto AskScaledRandomizerOFF

AskScaledRandomizer:
    msgbox gText_ScaledRandomizerInfo MSG_YESNO
    compare LASTRESULT 0x1
    if equal _goto SetScaledSpeciesON
    goto ToggleSpecies

AskScaledRandomizerOFF:
    msgbox gText_ScaledRandomizerInfoOFF MSG_YESNO
    compare LASTRESULT 0x1
    if equal _goto SetScaledSpeciesOFF
    goto ToggleSpecies

SetScaledSpeciesOFF:
    sound 0x3
    msgbox gText_ScaledRandomizerTurnedOff MSG_NORMAL
    checksound
    clearflag FLAG_SCALED_RANDOMIZER
    goto ToggleSpecies

SetScaledSpeciesON:
    sound 0x30
    msgbox gText_ScaledRandomizerTurnedOn MSG_NORMAL
    checksound
    clearflag FLAG_POKEMON_RANDOMIZER
    setflag FLAG_SCALED_RANDOMIZER
    goto ToggleSpecies

SetSpeciesNormalText:
    checkflag FLAG_POKEMON_RANDOMIZER
    if 0x0 _call SetSpeciesNormalTextOFF
    checkflag FLAG_POKEMON_RANDOMIZER
    if 0x1 _call SetSpeciesNormalTextON
    return

SetSpeciesNormalTextON:
    setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_SpeciesNormalRandomizerON
	special 0x25
    return

SetSpeciesNormalTextOFF:
    setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_SpeciesNormalRandomizer
	special 0x25
    return


SetSpeciesText:
    checkflag FLAG_POKEMON_RANDOMIZER
    if 0x1 _goto SetSpeciesTextON
    checkflag FLAG_SCALED_RANDOMIZER
    if 0x1 _goto SetSpeciesTextON
    goto SetSpeciesTextOFF

SetSpeciesScaledText:
    checkflag FLAG_SCALED_RANDOMIZER
    if 0x0 _call SetSpeciesScaledTextOFF
    checkflag FLAG_SCALED_RANDOMIZER
    if 0x1 _call SetSpeciesScaledTextON
    return

SetSpeciesScaledTextOFF:
    setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_ScaledRandomizerOFF
	special 0x25
    return

SetSpeciesScaledTextON:
    setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_ScaledRandomizerON
	special 0x25
    return

SetSpeciesTextON:
    setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_SpeciesRandomizerON
	special 0x25
    goto ContinueAfterSpeciesText

SetSpeciesTextOFF:
    setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_SpeciesRandomizerTxt
	special 0x25
    goto ContinueAfterSpeciesText

SetAbilityText:
    checkflag FLAG_ABILITY_RANDOMIZER
    if 0x1 _call SetAbilityTextON
    checkflag FLAG_ABILITY_RANDOMIZER
    if 0x0 _call SetAbilityTextOFF
    return

SetAbilityTextON:
	setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_AbilityRandomizerON
	special 0x25
    return

SetAbilityTextOFF:
	setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_AbilityRandomizer
	special 0x25
    return

SetMoveText:
    checkflag FLAG_POKEMON_LEARNSET_RANDOMIZER
    if 0x1 _call SetMoveTextON
    checkflag FLAG_POKEMON_LEARNSET_RANDOMIZER
    if 0x0 _call SetMoveTextOFF
    return

SetMoveTextOFF:
    setvar 0x8006 0x2 @third item
    loadpointer 0x0 gText_MoveRandomizer
    special 0x25
    return

SetMoveTextON:
    setvar 0x8006 0x2 @third item
    loadpointer 0x0 gText_MoveRandomizerON
    special 0x25
    return

ToggleAbility:
    checkflag FLAG_ABILITY_RANDOMIZER
    if 0x0 _goto AskAbilityOn
    checkflag FLAG_ABILITY_RANDOMIZER
    if 0x1 _goto AskAbilityOff

ToggleMoves:
    checkflag FLAG_POKEMON_LEARNSET_RANDOMIZER
    if 0x0 _goto AskMoveOn
    checkflag FLAG_POKEMON_LEARNSET_RANDOMIZER
    if 0x1 _goto AskMoveOff

CantToggleMove:
    msgbox gText_CantToggleMoveIn MSG_NORMAL
    goto RandomizerOptions

CantToggleAbility:
    msgbox gText_CantToggleAbilityIn MSG_NORMAL
    goto RandomizerOptions

AskMoveOn:
    msgbox gText_DoYouWantLearnsets MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto SetMoveON
    goto RandomizerOptions

AskMoveOff:
    msgbox gText_DoYouWantLearnsetsOFF MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto SetMoveOFF
    goto RandomizerOptions

SetMoveON:
    setflag FLAG_POKEMON_LEARNSET_RANDOMIZER
    sound 0x30
    msgbox gText_RandomLearnsets MSG_NORMAL
    checksound
    goto RandomizerOptions

SetMoveOFF:
    clearflag FLAG_POKEMON_LEARNSET_RANDOMIZER
    sound 0x3
    msgbox gText_RandomLearnsetsOFF MSG_NORMAL
    checksound
    goto RandomizerOptions

AskAbilityOn:
    msgbox gText_DoYouWantAbility MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto SetAbilityON
    goto RandomizerOptions

AskAbilityOff:
    msgbox gText_DoYouWantAbilityOFF MSG_YESNO
    compare LASTRESULT 0x1
    if 0x1 _goto SetAbilityOFF
    goto RandomizerOptions

SetAbilityON:
    setflag FLAG_ABILITY_RANDOMIZER
    sound 0x30
    msgbox gText_RandomAbilitySet MSG_NORMAL
    checksound
    goto RandomizerOptions

SetAbilityOFF:
    clearflag FLAG_ABILITY_RANDOMIZER
    sound 0x3
    msgbox gText_RandomAbilityOff MSG_NORMAL
    checksound
    goto RandomizerOptions

DoneWithOptions:
    sound 0x30
    goto endofscript

DoneWithRandomizer:
    goto ShowCustomRROptions

DoneWithSpeciesRandomizer:
    goto RandomizerOptions



LevelScript_PalletTownAskStarterRegion:
    applymovement 0x1 FaceRight
    waitmovement 0x0
    goto AskStarters
    end

AskStarters:
    msgbox gText_Pallet_ProfAsks MSG_YESNO
    compare LASTRESULT YES 
    if equal _goto SetStarters
    goto OhOkay

OhOkay:
    msgbox gText_Pallet_OkTakeCare MSG_NORMAL
    goto AskStarterEnd
    end

endofstarterscript:
    goto AskStarterEnd
    end

AskStarterEnd:
    setvar 0x5100 0x1
    applymovement 0x1 FaceLeft
    waitmovement 0x0
    release
    end

SetStarters:
    setvar 0x8004 0x0
    setvar 0x8000 0xC
    setvar 0x8001 0x6
    preparemsg gText_WhichRegion
    waitmsg
    special 0x158
    waitstate 
    compare LASTRESULT 0x0
    if 0x1 _goto JohtoStarter
    compare LASTRESULT 0x1
    if 0x1 _goto HoennStarter
    compare LASTRESULT 0x2
    if 0x1 _goto SinnohStarter
    compare LASTRESULT 0x3 
    if 0x1 _goto UnovaStarter
    compare LASTRESULT 0x4
    if 0x1 _goto KalosStarter 
    compare LASTRESULT 0x5 
    if 0x1 _goto AlolanStarter 
    compare LASTRESULT 0x6
    if 0x1 _goto GalarStarter
    compare LASTRESULT 0x7
    if 0x1 _goto PaldeaStarter
    goto AskStarters
    end 

JohtoStarter: 
    setvar 0x5123 JOHTO_STARTER
    msgbox gText_JohtoStarter MSG_NORMAL
    goto endofstarterscript

HoennStarter:
    setvar 0x5123 HOENN_STARTER
    msgbox gText_HoennStarter MSG_NORMAL
    goto endofstarterscript

SinnohStarter:
    setvar 0x5123 SINNOH_STARTER
    msgbox gText_SinnohStarter MSG_NORMAL
    goto endofstarterscript

UnovaStarter:
    setvar 0x5123 UNOVA_STARTER
    msgbox gText_UnovaStarter MSG_NORMAL
    goto endofstarterscript

KalosStarter:
    setvar 0x5123 KALOS_STARTER
    msgbox gText_KalosStarter MSG_NORMAL
    goto endofstarterscript

AlolanStarter: 
    setvar 0x5123 ALOLA_STARTER
    msgbox gText_AlolaStarter MSG_NORMAL
    goto endofstarterscript

GalarStarter:
    setvar 0x5123 GALAR_STARTER
    msgbox gText_GalarStarter MSG_NORMAL
    goto endofstarterscript

PaldeaStarter:
    setvar 0x5123 PALDEA_STARTER
    msgbox gText_PaldeaStarter MSG_NORMAL
    goto endofstarterscript

endofscript: 
    checkflag FLAG_HARDCORE_MODE
    if 0x1 _call ToggleBoosterEnergy
    checkflag FLAG_RESTRICT_MODE
    if 0x1 _call ToggleBoosterEnergy
    fadescreen 0x0
    @ clearflag 0x1046
    @ warp 0x4 0x1 0x1 0x0 0x0
    fadeinbgm 0x0 
    release
    end 

ToggleBoosterEnergy:
    setflag 0x1B8 @Flag for booster Energy in cerulean cave
    setflag 0x973 @Flag for Light Clay in Celadon
    setflag 0x975 @Psyshock TM in underground path
    return

.global EventScript_AskRandomizer
EventScript_AskRandomizer:
    clearflag FLAG_SYS_SAVE_HIDE
    @ callasm CheckIfHallOfFame
    @ compare LASTRESULT 0x1
    @ if equal _goto SetHofFlag
    goto EndRandomizerScript

EndRandomizerScript:
    setvar 0x511B 0x1
    setvar 0x407C 0x2 @this clears the pokemon center flag
    release
    end

SetHofFlag:
    setflag FLAG_NEW_GAME_PLUS
    @ setflag 0x828
    @ callasm GiveNewGamePlusPokemon + 1
    sound 0x30 
    msgbox gText_NewGamePlus MSG_KEEPOPEN
    pause 0xA 
    closeonkeypress
    checksound
    return

AskRandomizer:
    @ checkflag FLAG_HARDCORE_MODE
    @ if 0x1 _goto EndRandomizerScript
    @ checkflag FLAG_RESTRICT_MODE
    @ if 0x1 _goto EndRandomizerScript
    @ applymovement 0xFF FaceLeft
    @ waitmovement 0x0
    msgbox gText_DoYouWantRandomizer MSG_YESNO 
    compare LASTRESULT YES 
    if equal _call setrandom 
    checkflag FLAG_HARDCORE_MODE
    if 0x1 _goto askscaledrandomizer
    msgbox gText_DoYouWantAbility MSG_YESNO  
    compare LASTRESULT YES 
    if equal _call setability 
    msgbox gText_DoYouWantLearnsets MSG_YESNO 
    compare LASTRESULT YES 
    if equal _call setlearnsets
    msgbox gText_ScaledRandomizerInfo MSG_YESNO 
    compare LASTRESULT YES
    if equal _call setscaledrandomizer
    @ setvar 0x511B 0x1
    goto endofscript
    release
    end

DefinitiveEdition:
    sound 0x30 
    msgbox gText_DefinitiveEdition MSG_KEEPOPEN
    checksound
    closeonkeypress
    goto endofscript

sethardcoremode:
    setflag FLAG_HARDCORE_MODE
    checkflag 0x1032
    if 0x0 _call setmingrinding
    setflag 0x1032
    sound 0x30 
    msgbox gText_hardcoremodeset MSG_KEEPOPEN
    checksound
    closeonkeypress
    @ msgbox gText_hardcoremodescaledrando MSG_NORMAL
    goto AskRandomizer

askscaledrandomizer:
    msgbox gText_ScaledRandomizerInfo MSG_YESNO
    compare LASTRESULT 0x1
    if equal _call setscaledrandomizer
    goto endofscript

setscaledrandomizer:
    setflag 0x940
    setflag 0x93A 
    sound 0x30
    msgbox gText_ScaledRandomizerTurnedOn MSG_KEEPOPEN 
    checksound
    closeonkeypress 
    return 
    
setrestrictmode:
    setflag FLAG_RESTRICT_MODE
    sound 0x30 
    msgbox gText_restrictmodeset MSG_KEEPOPEN
    checksound
    closeonkeypress
    goto askscaledrandomizer

seteasymode:
    setflag FLAG_EASY_MODE
    sound 0x30
    msgbox gText_easymodeset MSG_KEEPOPEN
    checksound 
    closeonkeypress
    return

setmingrinding:
    setflag 0x1032
    sound 0x30
    msgbox gText_setmingrinding MSG_KEEPOPEN
    checksound
    closeonkeypress 
    return

setrandom:
    setflag 0x940 
    sound 0x30
    msgbox gText_RandomizerSet MSG_KEEPOPEN
    checksound
    closeonkeypress 
    return 
 
SetHard: 
    setflag 0x93A 
    sound 0x30
    msgbox gText_RandomizerSetHard MSG_KEEPOPEN 
    checksound
    closeonkeypress 
    return 

setability:
    setflag 0x942
    sound 0x30
    msgbox gText_RandomAbilitySet MSG_KEEPOPEN
    checksound
    closeonkeypress 
    return 

setlearnsets:
    setflag 0x941
    sound 0x30
    msgbox gText_RandomLearnsets MSG_KEEPOPEN
    checksound
    closeonkeypress 
    return 

SetVar_PalletTownHome:
    compare 0x5108 0x2
    if equal _goto TheEnd
    checkflag 0x82C 
    if 0x1 _goto SetTheVar 
    end

TheEnd:
    end 

SetTheVar:
    setvar 0x5108 0x0
    end

LevelScript_PalletTownHome:
    lock
    checkflag 0x82C
    if 0x1 _goto End
    setvar 0x5108 0x1
    release
    end

End: 
    getplayerpos 0x5109 0x510A
    compare 0x5109 0x4
    if 0x1 _call FaceDownMov
    compare 0x5109 0xA
    if 0x1 _call FaceRightMov
    msgbox gText_Pallet_Mom MSG_NORMAL
    msgbox gText_Pallet_Mom2 MSG_NORMAL
    checkflag 0x103F
    if 0x1 _call MomCarePackage
    applymovement 0x1 FaceLeft
    waitmovement 0x0
    setvar 0x5108 0x2
    release
    end

MomCarePackage:
    giveitem ITEM_CHOICE_SCARF 0xA MSG_OBTAIN
    giveitem ITEM_CHOICE_SPECS 0xA MSG_OBTAIN
    giveitem ITEM_CHOICE_BAND 0xA MSG_OBTAIN
    giveitem ITEM_ROCKY_HELMET 0xA MSG_OBTAIN
    giveitem ITEM_EVIOLITE 0xA MSG_OBTAIN
    return 
    
FaceDownMov:
    applymovement 0x1 FaceDown
    waitmovement 0x0
    return

FaceRightMov:
    applymovement 0x1 FaceRight
    waitmovement 0x0
    return

FaceDown:
    .byte look_down
    .byte end_m

FaceRight:
    .byte look_right
    .byte end_m

FaceLeft:
    .byte look_left
    .byte end_m

.global EventScript_Pallet_Technology
EventScript_Pallet_Technology:
    msgbox gText_Pallet_Technology1 MSG_FACE 
    release 
    end 

.global EventScript_Pallet_AutoRunSign
EventScript_Pallet_AutoRunSign:
    lock 
    msgbox gText_Pallet_AutoRunSign1 MSG_SIGN
    release 
    end 

.global EventScript_mom_Start
EventScript_mom_Start:
	lock
	faceplayer
    checkflag 0x82C
    if 0x1 _goto EventScript_mom_RestCelebrate
	checkflag 0x258
	if 0x1 _goto EventScript_mom_TakeARest
	checkgender
	compare LASTRESULT 0x0
	if 0x1 _call EventScript_mom_Allboys
	compare LASTRESULT 0x1
	if 0x1 _call EventScript_mom_AllGirls
	closeonkeypress
	applymovement 0x1 EventScript_mom_Movement
	waitmovement 0x0
	release
	end

EventScript_mom_TakeARest:
	msgbox gText_mom_RestText MSG_KEEPOPEN @"Mom: [player]!\nYou should take a ..."
	closeonkeypress
	call EventScript_mom_Rest
	msgbox gText_mom_LookGreat MSG_KEEPOPEN @"Mom: Oh, good! You and your\nPokém..."
	release
	end

EventScript_mom_RestCelebrate:
    msgbox gText_mom_RestText2 MSG_KEEPOPEN @"Mom: [player]!\nYou should take a ..."
	closeonkeypress
	call EventScript_mom_Rest
	msgbox gText_mom_LetsCelebrate MSG_YESNO 
    compare LASTRESULT NO
    if equal _goto WhyCelebrate
    setvar 0x8005 0x15
    special 0x18D
    waitstate
    compare LASTRESULT 0x0
    if 0x1 _goto WhyCelebrate
    msgbox gText_mom_GreatJob MSG_NORMAL
    applymovement 0x1 EventScript_mom_Movement
	waitmovement 0x0
    release 
	end

WhyCelebrate:
    msgbox gText_mom_WhyCelebrate MSG_NORMAL
    applymovement 0x1 EventScript_mom_Movement
	waitmovement 0x0
    release
    end 

EventScript_mom_Allboys:
	msgbox gText_mom_AllBoysTxt MSG_KEEPOPEN @"Mom: [.]Right.\nAll boys leave hom..."
	return

EventScript_mom_AllGirls:
	msgbox gText_mom_AllGirlsTxt MSG_KEEPOPEN @"Mom: [.]Right.\nAll girls dream of..."
	return

EventScript_mom_Rest:
	fadescreen 0x1
	fanfare 0x100
	waitfanfare
	special 0x0
	fadescreen 0x0
	return

EventScript_mom_Movement:
    .byte 0x5A
    .byte 0xFE

	@---------------
.global EventScript_StarterPokemon_Start_Grass
EventScript_StarterPokemon_Start_Grass:
	lock
	faceplayer
	setvar 0x4001 0x0
	setvar 0x4002 0x1
    setvar 0x5124 0x1 @var to hold starter
    bufferpokemon 0x1 0x1
    setvar 0x5125 0x1 @option chosen
	setvar 0x4003 0x4
	setvar 0x4004 0x7
	compare 0x4055 0x3
	if 0x4 _goto EventScript_StarterPokemon_LastPkmn
	compare 0x4055 0x2
	if 0x1 _goto EventScript_StarterPokemon_TakeStarter
	msgbox gText_StarterPokemon_ContainPkmn MSG_KEEPOPEN @"Those are Poké Balls.\nThey contai..."
	release
	end

.global EventScript_StarterPokemon_Start_Water
EventScript_StarterPokemon_Start_Water:
	lock
	faceplayer
	setvar 0x4001 0x1
	setvar 0x4002 0x1
    setvar 0x5124 0x7 @var to hold starter
    bufferpokemon 0x1 0x7
    setvar 0x5125 0x2 @option chosen
	setvar 0x4003 0x1
	setvar 0x4004 0x5
	compare 0x4055 0x3
	if 0x4 _goto EventScript_StarterPokemon_LastPkmn
	compare 0x4055 0x2
	if 0x1 _goto EventScript_StarterPokemon_TakeStarter
	msgbox gText_StarterPokemon_ContainPkmn MSG_KEEPOPEN @"Those are Poké Balls.\nThey contai..."
	release
	end

.global EventScript_StarterPokemon_Start_Fire
EventScript_StarterPokemon_Start_Fire:
	lock
	faceplayer
	setvar 0x4001 0x2
	setvar 0x4002 0x1
    setvar 0x5124 0x4 @var to hold starter
    bufferpokemon 0x1 0x4
    setvar 0x5125 0x3 @option chosen
	setvar 0x4003 0x7
	setvar 0x4004 0x6
	compare 0x4055 0x3
	if 0x4 _goto EventScript_StarterPokemon_LastPkmn
	compare 0x4055 0x2
	if 0x1 _goto EventScript_StarterPokemon_TakeStarter
	msgbox gText_StarterPokemon_ContainPkmn MSG_KEEPOPEN @"Those are Poké Balls.\nThey contai..."
	release
	end
	@---------------
EventScript_StarterPokemon_LastPkmn:
	msgbox gText_StarterPokemon_MsgLastPkmn MSG_KEEPOPEN @"That@s Prof. Oak@s last Pokémon."
	release
	end

	@---------------
EventScript_StarterPokemon_TakeStarter:
    compare 0x5123 0x0 
    if notequal _goto setstartervars
    goto TakeStarterScript

TakeStarterScript:
	applymovement 0x4 EventScript_StarterPokemon_FaceRight
	waitmovement 0x0
	showpokepic 0x5124 0xA 0x3
	textcolor 0x0
	compare 0x5125 0x1
	if 0x1 _goto EventScript_StarterPokemon_GrassStarter
	compare 0x5125 0x2
	if 0x1 _goto EventScript_StarterPokemon_WaterStarter
	compare 0x5125 0x3
	if 0x1 _goto EventScript_StarterPokemon_FireStarter
	end

setstartervars:
    compare 0x5123 0x2
    if equal _goto SetVarsJohto
    compare 0x5123 0x3
    if equal _goto SetVarsHoenn
    compare 0x5123 0x4
    if equal _goto SetVarsSinnoh
    compare 0x5123 0x5
    if equal _goto SetVarsUnova
    compare 0x5123 0x6
    if equal _goto SetVarsKalos
    compare 0x5123 0x7
    if equal _goto SetVarsAlola
    compare 0x5123 0x8
    if equal _goto SetVarsGalar
    compare 0x5123 0x9
    if equal _goto SetVarsPaldea
SetVarsJohto:
    compare 0x5125 0x1 
    if equal _goto SetChikorita
    compare 0x5125 0x2
    if equal _goto SetTotodile
    compare 0x5125 0x3
    if equal _goto SetCyndaquil
    end

SetVarsHoenn:
    compare 0x5125 0x1 
    if equal _goto SetTreecko
    compare 0x5125 0x2
    if equal _goto SetMudkip
    compare 0x5125 0x3
    if equal _goto SetTorchic
    end

SetVarsSinnoh:
    compare 0x5125 0x1 
    if equal _goto SetTurtwig
    compare 0x5125 0x2
    if equal _goto SetPiplup
    compare 0x5125 0x3
    if equal _goto SetChimchar
    end

SetVarsUnova:
    compare 0x5125 0x1 
    if equal _goto SetSnivy
    compare 0x5125 0x2
    if equal _goto SetOshawott
    compare 0x5125 0x3
    if equal _goto SetTepig
    end

SetVarsKalos:
    compare 0x5125 0x1 
    if equal _goto SetChespin
    compare 0x5125 0x2
    if equal _goto SetFroakie
    compare 0x5125 0x3
    if equal _goto SetFennekin
    end

SetVarsAlola:
    compare 0x5125 0x1 
    if equal _goto SetRowlet
    compare 0x5125 0x2
    if equal _goto SetPopplio
    compare 0x5125 0x3
    if equal _goto SetLitten
    end

SetVarsGalar:
    compare 0x5125 0x1 
    if equal _goto SetGrookey
    compare 0x5125 0x2
    if equal _goto SetSobble
    compare 0x5125 0x3
    if equal _goto SetScorbunny
    end

SetVarsPaldea:
    compare 0x5125 0x1 
    if equal _goto SetSprigatito
    compare 0x5125 0x2
    if equal _goto SetQuaxly
    compare 0x5125 0x3
    if equal _goto SetFuecoco
    end

SetChikorita: 
    setvar 0x5124 0x98
    bufferpokemon 0x1 0x98
    goto TakeStarterScript

SetTotodile:
    setvar 0x5124 0x9E
    bufferpokemon 0x1 0x9E
    goto TakeStarterScript

SetCyndaquil:
    setvar 0x5124 0x9B
    bufferpokemon 0x1 0x9B
    goto TakeStarterScript

SetTreecko: 
    setvar 0x5124 0x115
    bufferpokemon 0x1 0x115
    goto TakeStarterScript

SetMudkip: 
    setvar 0x5124 0x11B
    bufferpokemon 0x1 0x11B
    goto TakeStarterScript

SetTorchic: 
    setvar 0x5124 0x118
    bufferpokemon 0x1 0x118
    goto TakeStarterScript

SetTurtwig: 
    setvar 0x5124 0x1B8
    bufferpokemon 0x1 0x1B8
    goto TakeStarterScript

SetPiplup:
    setvar 0x5124 0x1BE
    bufferpokemon 0x1 0x1BE
    goto TakeStarterScript

SetChimchar:
    setvar 0x5124 0x1BB
    bufferpokemon 0x1 0x1BB
    goto TakeStarterScript

SetSnivy:
    setvar 0x5124 0x224
    bufferpokemon 0x1 0x224
    goto TakeStarterScript

SetOshawott:
    setvar 0x5124 0x22A
    bufferpokemon 0x1 0x22A
    goto TakeStarterScript

SetTepig:
    setvar 0x5124 0x227
    bufferpokemon 0x1 0x227
    goto TakeStarterScript

SetChespin: 
    setvar 0x5124 0x2F6
    bufferpokemon 0x1 0x2F6
    goto TakeStarterScript

SetFroakie:
    setvar 0x5124 0x2FC
    bufferpokemon 0x1 0x2FC
    goto TakeStarterScript

SetFennekin:
    setvar 0x5124 0x2F9
    bufferpokemon 0x1 0x2F9
    goto TakeStarterScript

SetRowlet:
    setvar 0x5124 0x3AB
    bufferpokemon 0x1 0x3AB
    goto TakeStarterScript

SetPopplio:
    setvar 0x5124 0x3B1
    bufferpokemon 0x1 0x3B1
    goto TakeStarterScript

SetLitten:
    setvar 0x5124 0x3AE
    bufferpokemon 0x1 0x3AE
    goto TakeStarterScript

SetGrookey:
    setvar 0x5124 0x44E
    bufferpokemon 0x1 0x44E
    goto TakeStarterScript

SetSobble:
    setvar 0x5124 0x454
    bufferpokemon 0x1 0x454
    goto TakeStarterScript

SetScorbunny:
    setvar 0x5124 0x451
    bufferpokemon 0x1 0x451
    goto TakeStarterScript

SetSprigatito:
    setvar 0x5124 SPECIES_SPRIGATITO
    bufferpokemon 0x1 SPECIES_SPRIGATITO
    goto TakeStarterScript

SetQuaxly:
    setvar 0x5124 SPECIES_QUAXLY
    bufferpokemon 0x1 SPECIES_QUAXLY
    goto TakeStarterScript

SetFuecoco:
    setvar 0x5124 SPECIES_FUECOCO
    bufferpokemon 0x1 SPECIES_FUECOCO
    goto TakeStarterScript

	@---------------

EventScript_StarterPokemon_GrassStarter:
	msgbox gText_StarterPokemon_Bulbasaurtxt MSG_YESNO @"I see! Bulbasaur is your choice.\n..."
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_StarterPokemon_ReceivePkmn
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_StarterPokemon_NoPkmn
	end

	@---------------
EventScript_StarterPokemon_WaterStarter:
	msgbox gText_StarterPokemon_Squirtletxt MSG_YESNO @"Hm! Squirtle is your choice.\nIt@s..."
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_StarterPokemon_ReceivePkmn
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_StarterPokemon_NoPkmn
	end

	@---------------
EventScript_StarterPokemon_FireStarter:
	msgbox gText_StarterPokemon_Charmandertxt MSG_YESNO @"Ah! Charmander is your choice.\nYo..."
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_StarterPokemon_ReceivePkmn
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_StarterPokemon_NoPkmn
	end

	@---------------
EventScript_StarterPokemon_ReceivePkmn:
	hidepokepic
	hidesprite LASTTALKED
	msgbox gText_StarterPokemon_Energetic MSG_KEEPOPEN @"This Pokémon is really quite\nener..."
	call EventScript_StarterPokemon_Copyvarscript
	setflag 0x828
	setflag 0x291
	givepokemon 0x5124 0x5 0x8B 0x0 0x0 0x0
	copyvar 0x4031 0x4001
	bufferpokemon 0x0 0x5124
	preparemsg gText_StarterPokemon_Receivedthepkmn @"[player] received the [buffer1]\nf..."
	waitmsg
	fanfare 0x13E
	waitfanfare
	msgbox gText_StarterPokemon_Givenickname MSG_YESNO @"Do you want to give a nickname to\..."
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_StarterPokemon_Nicknamestuff
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_StarterPokemon_Endofstarterscript
	end

	@---------------
EventScript_StarterPokemon_NoPkmn:
	hidepokepic
	release
	end

	@---------------
EventScript_StarterPokemon_Copyvarscript:
	copyvar 0x8012 0x8013
	return

	@---------------
EventScript_StarterPokemon_Nicknamestuff:
	setvar 0x8004 0x0
	call EventScript_StarterPokemon_Nicknameit
	goto EventScript_StarterPokemon_Endofstarterscript

	@---------------
EventScript_StarterPokemon_Endofstarterscript:
	closeonkeypress
EndOfStarterScript2:
	compare 0x4001 0x0
	if 0x1 _goto EventScript_StarterPokemon_Grassmove
	compare 0x4001 0x1
	if 0x1 _goto EventScript_StarterPokemon_Watermove
	compare 0x4001 0x2
	if 0x1 _goto EventScript_StarterPokemon_Firemove
	end

	@---------------
EventScript_StarterPokemon_Nicknameit:
	fadescreen 0x1
	special 0x9E
	waitstate
	return

	@---------------
EventScript_StarterPokemon_Grassmove:
	applymovement 0x8 EventScript_StarterPokemon_Grassmovement
	waitmovement 0x0
	goto EventScript_StarterPokemon_Endofscript

	@---------------
EventScript_StarterPokemon_Watermove:
	applymovement 0x8 EventScript_StarterPokemon_Watermovement
	waitmovement 0x0
	goto EventScript_StarterPokemon_Endofscript

	@---------------
EventScript_StarterPokemon_Firemove:
	applymovement 0x8 EventScript_StarterPokemon_Firemovement
	waitmovement 0x0
	goto EventScript_StarterPokemon_Endofscript

	@---------------
EventScript_StarterPokemon_Endofscript:
	textcolor 0x0
	msgbox gText_StarterPokemon_Rivaltake MSG_KEEPOPEN @"[rival]: I@ll take this one, then!"
    closeonkeypress
    compare 0x5123 0x0 
    if notequal _goto GoBackToOak
	hidesprite 0x4004
	textcolor 0x3
	bufferpokemon 0x0 0x4003
	preparemsg gText_StarterPokemon_Rivalreceive @"[rival] received the [buffer1]\nfr..."
	waitmsg
	fanfare 0x13E
	waitfanfare
	setvar 0x4055 0x3
	checkflag 0x83E
	if 0x1 _call EventScript_StarterPokemon_Setvarthing
	release
	end

GoBackToOak:
    compare 0x4004 0x7
    if equal _goto GaryMoveFromFire
    compare 0x4004 0x6
    if equal _goto GaryMoveFromWater
    compare 0x4004 0x5
    if equal _goto GaryMoveFromGrass
    end

GaryGetStarter:
    msgbox gText_Pallet_GaryWantKanto MSG_NORMAL
	textcolor 0x3
	bufferpokemon 0x0 0x4003
	preparemsg gText_StarterPokemon_Rivalreceive @"[rival] received the [buffer1]\nfr..."
	waitmsg
	fanfare 0x13E
	waitfanfare
    closeonkeypress
	setvar 0x4055 0x3
	checkflag 0x83E
	if 0x1 _call EventScript_StarterPokemon_Setvarthing
    return

GaryMoveFromFire:
    applymovement 0x8 MoveGaryFireToOak
    waitmovement 0x0 
    applymovement 0x4 LookDown
    waitmovement 0x0
    call GaryGetStarter
    applymovement 0x8 MoveGaryOakToFire
    waitmovement 0x0 
    msgbox gText_PalletGary_WayCooler MSG_NORMAL
    release
    end

GaryMoveFromWater:
    applymovement 0x8 MoveGaryWaterToOak
    waitmovement 0x0 
    applymovement 0x4 LookDown
    waitmovement 0x0
    call GaryGetStarter
    applymovement 0x8 MoveGaryOakToWater
    waitmovement 0x0 
    msgbox gText_PalletGary_WayCooler MSG_NORMAL
    release
    end

GaryMoveFromGrass:
    applymovement 0x8 MoveGaryGrassToOak
    waitmovement 0x0 
    applymovement 0x4 LookDown
    waitmovement 0x0
    call GaryGetStarter
    applymovement 0x8 MoveGaryOakToGrass
    waitmovement 0x0 
    msgbox gText_PalletGary_WayCooler MSG_NORMAL
    release
    end
	@---------------
EventScript_StarterPokemon_Setvarthing:
	setvar 0x4070 0x1
	return

LookDown:
    .byte look_down
    .byte end_m

MoveGaryFireToOak:
    .byte walk_down
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_up
    .byte walk_up
    .byte end_m

MoveGaryOakToFire:
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_up
    .byte end_m

MoveGaryGrassToOak:
    .byte walk_left
    .byte walk_left
    .byte walk_up
    .byte end_m

MoveGaryOakToGrass:
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte look_up
    .byte end_m

MoveGaryWaterToOak:
    .byte walk_down
    .byte walk_left
    .byte walk_left
    .byte walk_left
    .byte walk_up
    .byte walk_up
    .byte end_m

MoveGaryOakToWater:
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_up
    .byte end_m

EventScript_StarterPokemon_FaceRight:
.byte 0x3
.byte 0xFE

EventScript_StarterPokemon_Grassmovement:
.byte 0x10
.byte 0x10
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x11
.byte 0xFE

EventScript_StarterPokemon_Watermovement:
.byte 0x10
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x2E
.byte 0xFE

EventScript_StarterPokemon_Firemovement:
.byte 0x10
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x2E
.byte 0xFE


.global EventScript_CheatCodes_NES
EventScript_CheatCodes_NES:
    lock
    msgboxsign
    msgbox gText_CheatCodes_AskInput MSG_YESNO
    compare LASTRESULT YES
    if equal _goto TryCheatCodes
    release
    end

TryCheatCodes:
    special 0x12C
	waitstate
	loadpointer 0x0 gText_CheatString
	special 0x12D
	compare LASTRESULT 0x0
	if equal _goto SetRareFlag
    loadpointer 0x0 gText_DexAll
    special 0x12D
    compare LASTRESULT 0x0
    if equal _goto SetDexAll
    loadpointer 0x0 gText_ToxicString
    special 0x12D
    compare LASTRESULT 0x0
    if equal _goto SetToxicFlag
    loadpointer 0x0 gText_TeamPreviewString
    special 0x12D
    compare LASTRESULT 0x0
    if equal _goto SetTeamPreviewCheat
    loadpointer 0x0 gText_EZCatch
    special 0x12D
    compare LASTRESULT 0x0
    if equal _goto SetEzCatchCheat
	goto NoThatsNotIt

SetRareFlag:
    checkflag 0x1040
    if 0x1 _goto AlreadySet
    msgbox gText_NES_RareCandySet MSG_NORMAL
    setflag 0x1040
    release
    end

SetEzCatchCheat:
    checkflag FLAG_EASY_CATCH_CHEAT
    if 0x1 _goto AlreadySet
    msgbox gText_NES_EZCatchSet MSG_NORMAL
    setflag FLAG_EASY_CATCH_CHEAT
    release
    end

SetDexAll:
    checkflag 0x1056
    if 0x1 _goto AlreadySet
    msgbox gText_NES_DexAllSet MSG_NORMAL
    @ callasm SetAllPokemonCaught 
    setflag 0x1056
    release
    end

AlreadySet:
    msgbox gText_NES_AlreadySet MSG_NORMAL
    release
    end

SetToxicFlag:
    checkflag 0x103F
    if 0x1 _goto AlreadySet
    msgbox gText_SetCarePackage MSG_NORMAL
    setflag 0x103F
    release
    end

SetTeamPreviewCheat:
    checkflag FLAG_TEAM_PREVIEW_CHEAT
    if 0x1 _goto AlreadySet
    msgbox gText_SetTeamPreviewCheat MSG_NORMAL
    setflag FLAG_TEAM_PREVIEW_CHEAT
    release
    end

NoThatsNotIt:
    msgbox gText_InvalidCode MSG_NORMAL
    release
    end

.global EventScript_PalletTown_TimeChangerAide
EventScript_PalletTown_TimeChangerAide:
    lockall
    faceplayer
    checkflag FLAG_UNLOCK_TIME_CHANGER
    if SET _goto PalletTown_TimeChangerAideDone
    msgbox gText_TimeChangerAide_1 MSG_YESNO
    compare LASTRESULT NO
    if equal _goto EndThis
    setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_TimeChangerAurora
	special 0x25
	setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_TimeChangerPancham
	special 0x25
    setvar 0x8006 0x2 @third item
	loadpointer 0x0 gText_TimeChangerEevee
	special 0x25
    setvar 0x8006 0x3 @fourth item
	loadpointer 0x0 gText_TimeChangercubone
	special 0x25
    preparemsg gText_TimeChangerAide_2
    waitmsg
    multichoice 0x0 0x0 0x22 0x1
    compare LASTRESULT 0x1
    if equal _goto SecondQuestionTime
    goto ThatsIncorrect

SecondQuestionTime:
    msgbox gText_TimeChangerAide_Correct MSG_NORMAL
    setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_TimeChanger5PM
	special 0x25
	setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_TimeChanger8PM
	special 0x25
    setvar 0x8006 0x2 @third item
	loadpointer 0x0 gText_TimeChanger11PM
	special 0x25
    preparemsg gText_TimeChangerAide_3
    waitmsg
    multichoice 0x0 0x0 0x21 0x1
    compare LASTRESULT 0x0
    if equal _goto ThirdQuestionTime
    goto ThatsIncorrect

ThirdQuestionTime:
    msgbox gText_TimeChangerAide_CorrectFinal MSG_NORMAL
    setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_TimeChangerAide_2023
	special 0x25
	setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_TimeChangerAide_2030
	special 0x25
    setvar 0x8006 0x2 @third item
	loadpointer 0x0 gText_TimeChangerAide_Never
	special 0x25
    preparemsg gText_TimeChangerAide_4
    waitmsg
    multichoice 0x0 0x0 0x21 0x1
    compare LASTRESULT 0x2
    if equal _goto GiveTimeChanger
    goto ThatsIncorrect

GiveTimeChanger:
    msgbox gText_TimeChangerAide_5 MSG_NORMAL
    fanfare 0x13E
    msgbox gText_TimeChanger_Unlock MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    setflag FLAG_UNLOCK_TIME_CHANGER
    goto PalletTown_TimeChangerAideDone
PalletTown_TimeChangerAideDone:
    msgbox gText_TimeChangerAide_6 MSG_FACE
    release
    end

EndThis:
    release
    end

ThatsIncorrect:
    msgbox gText_TimeChangerAide_NotCorrect MSG_NORMAL
    release
    end

.global EventScript_PalletTown_ProfOak
EventScript_PalletTown_ProfOak:
    lock
    faceplayer
    checkitem ITEM_Z_POWER_RING 0x1
    compare LASTRESULT 0x1
    if greaterorequal _goto TimeToFightOak
    checkflag 0x2
    if 0x1 _goto 0x8169600
    compare 0x4055 0x9
    if 0x1 _goto 0x8169903
    compare 0x4055 0x8
    if 0x1 _goto 0x8169A6E
    compare 0x4052 0x1
    if 0x1 _goto 0x8169903
    compare 0x4055 0x6
    if 0x1 _goto 0x81698D6
    compare 0x4057 0x1
    if 0x4 _goto 0x816961E
    compare 0x4055 0x4
    if 0x1 _goto 0x8169614
    compare 0x4055 0x3
    if 0x1 _goto 0x816960A
    msgbox 0x818E116 MSG_KEEPOPEN 
    release
    end

TimeToFightOak:
    checkflag FLAG_BEAT_PROF_OAK
    if 0x1 _goto EndOfOak
    msgbox gText_PalletTown_OakFight1 MSG_YESNO
    compare LASTRESULT NO
    if equal _goto ScaredOfOak
    msgbox gText_PalletTown_OakFight2 MSG_NORMAL
    @ setflag FLAG_SMALL_TRAINER_LEVELS
    trainerbattle3 0x3 0xC8 0x0 gText_PalletTown_OakWarmup
    msgbox gText_PalletTown_OakStillGot MSG_NORMAL
    @ setflag FLAG_SMALL_TRAINER_LEVELS
    trainerbattle3 0x3 0xD2 0x0 gText_PalletTown_LossForReal
    msgbox gText_PalletTown_OakFight3 MSG_NORMAL
    giveitem ITEM_EEVIUM_Z 0x1 MSG_OBTAIN
    setflag FLAG_BEAT_PROF_OAK
EndOfOak:
    msgbox gText_PalletTown_OakFight4 MSG_NORMAL
    release
    end

ScaredOfOak:
    msgbox gText_PalletTown_OakScared MSG_NORMAL
    release
    end

@tm78 low sweep tm87 swagger
@tm88 pluck tm108 snarl tm111 smackdown

#org 0x165894
.global EventScript_TrainerTipsRepoint
EventScript_TrainerTipsRepoint:
    textcolor 0x1
    msgbox 0x81B1D0B MSG_KEEPOPEN 
    closeonkeypress
    pause 0x14
    textcolor 0x3
    setflag 0x83E
    setvar 0x4070 0x1
    setvar 0x4002 0x0
    special 0x170
    special 0x171
    signmsg
    msgbox gText_pallettown_trainertips MSG_KEEPOPEN 
    normalmsg
    return

.global EventScript_OakAideStop
EventScript_OakAideStop:
    checkflag 0x109A
    if 0x1 _goto AideAlreadyFought
    checkflag 0x829
    if 0x1 _goto CanBattleAide
    msgbox gText_PalletTown_AideStop1 MSG_KEEPOPEN
    pause 0x5
    closeonkeypress
    release
    end

CanBattleAide:
    msgbox gText_PalletTown_AideBattle1 MSG_NORMAL
    callasm CheckPlayerPartyCount + 1
    compare LASTRESULT 0x1
    if equal _call MightNeedMore
    msgbox gText_PalletTown_AideBattle2 MSG_YESNO
    compare LASTRESULT NO
    if equal _goto AideRejectedBattle
    trainerbattle3 0x3 0x1E 0x0 gText_Pallet_ProfAideDefeat
    msgbox gText_PalletProfAideBattle3 MSG_KEEPOPEN
    pause 0x5
    closeonkeypress
    giveitem ITEM_TM22 0x1 MSG_OBTAIN
    msgbox gText_PalletProfAideBattle4 MSG_NORMAL
    setflag 0x109A
    setvar 0x5148 0x1
    release
    end

AideAlreadyFought:
    msgbox gText_Pallet_ProfDoneText MSG_NORMAL
    release
    end

AideRejectedBattle:
    msgbox gText_PalletProfAideRejected MSG_NORMAL
    release
    end

AideRejectedBattleTile:
    msgbox gText_PalletProfAideRejected MSG_NORMAL
    applymovement 0xFF MoveUp
    waitmovement 0x0
    applymovement 0x4 LookUp
    waitmovement 0x0
    release
    end

MightNeedMore:
    msgbox gText_PalletTown_NeedMoreThan1 MSG_KEEPOPEN
    pause 0x8
    closeonkeypress
    return


.global EventScript_OakAideStopTile
EventScript_OakAideStopTile:
    checkflag 0x239
    if 0x1 _goto DoNothing
    checkflag 0x829
    if 0x1 _goto BattleTile
    applymovement 0x4 LookRight
    waitmovement 0x0
    applymovement 0xFF LookLeft
    waitmovement 0x0
    msgbox gText_PalletTown_AideStop2 MSG_KEEPOPEN
    pause 0x5
    closeonkeypress
    applymovement 0xFF MoveUp
    waitmovement 0x0
    applymovement 0x4 LookUp
    waitmovement 0x0
    release
    end


DoNothing:
    setvar 0x5148 0x1
    release
    end

BattleTile:
    applymovement 0x4 LookRight
    waitmovement 0x0
    applymovement 0xFF LookLeft
    waitmovement 0x0
    msgbox gText_PalletTown_AideBattle1 MSG_NORMAL
    callasm CheckPlayerPartyCount + 1
    compare LASTRESULT 0x1
    if equal _call MightNeedMore
    msgbox gText_PalletTown_AideBattle2 MSG_YESNO
    compare LASTRESULT NO
    if equal _goto AideRejectedBattleTile
    trainerbattle3 0x3 0x1E 0x0 gText_Pallet_ProfAideDefeat
    msgbox gText_PalletProfAideBattle3 MSG_KEEPOPEN
    pause 0x5
    closeonkeypress
    giveitem ITEM_TM22 0x1 MSG_OBTAIN
    msgbox gText_PalletProfAideBattle4 MSG_NORMAL
    setflag 0x109A
    setvar 0x5148 0x1
    release
    end

LookRight:
    .byte look_right
    .byte end_m

LookUp:
    .byte look_up
    .byte end_m

LookLeft:
    .byte look_left
    .byte end_m

MoveUp:
    .byte walk_up
    .byte end_m

.global EventScript_StuffulPalletTown
EventScript_StuffulPalletTown:
    cry SPECIES_STUFFUL 0x2
    msgbox gText_Pallet_Stufful MSG_KEEPOPEN
    waitcry
    pause 0x5
    closeonkeypress
    applymovement 0x800F Disappoint
    waitmovement 0x0
    release
    end

Disappoint:
    .byte say_cross
    .byte end_m

.global EventScript_StuffulLass
EventScript_StuffulLass:
    msgbox gText_Pallet_LassStuff1 MSG_KEEPOPEN
    pause 0x5
    closeonkeypress
    applymovement 0x5 JumpUp
    waitmovement 0x0
    cry SPECIES_STUFFUL 0x0
    msgbox gText_Pallet_Stufful MSG_KEEPOPEN
    waitcry
    pause 0x5
    closeonkeypress
    applymovement 0x4 LookUp
    waitmovement 0x0
    msgbox gText_Pallet_LassStuff2 MSG_KEEPOPEN
    pause 0x5
    closeonkeypress
    applymovement 0x4 LookLeft
    waitmovement 0x0
    release
    end


JumpUp:
    .byte jump_onspot_right
    .byte end_m
