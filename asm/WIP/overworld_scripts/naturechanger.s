.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_MINIMAL_GRINDING_MODE, 0x1032
.equ FLAG_HARDCORE_MODE, 0x1034
.equ FLAG_RESTRICT_MODE, 0x103C
.equ FLAG_POKEMON_RANDOMIZER, 0x940 
.equ FLAG_POKEMON_LEARNSET_RANDOMIZER, 0x941 
.equ FLAG_ABILITY_RANDOMIZER, 0x942
.equ FLAG_SCALED_RANDOMIZER, 0x93A
.equ FLAG_INSTANT_HP, 0x107A
.equ FLAG_EASY_MODE, 0x1033
.equ FLAG_SCALED_RANDOMIZER, 0x93A

.equ FLAG_HIDE_FOLLOWER, 0x1054
.equ FLAG_DONT_MAKE_FOLLOWER_REAPPEAR, 0x1080
.equ FLAG_GIFT_PRIMAL_DIALGA, 0x1084
.equ FLAG_BEAT_GAME, 0x82C
.equ FLAG_GIFT_ZACIAN, 0x1085
.equ FLAG_GIFT_ZAMAZENTA, 0x1086
.equ FLAG_GIFT_ETERNATUS, 0x1087
.equ FLAG_GIFT_CALYREX_S, 0x1088
.equ FLAG_GIFT_CALYREX_ICE, 0x1089
.equ FLAG_GIFT_GIRATINA, 0x108A
.equ FLAG_GIFT_DARKRAI, 0x108B
.equ FLAG_GIFT_PALKIA, 0x108C 
.equ FLAG_GIFT_RESHIRAM, 0x108D
.equ FLAG_GIFT_ZEKROM, 0x108E
.equ FLAG_GIFT_YVELTAL, 0x108F
.equ FLAG_GIFT_XERNEAS, 0x1090
.equ FLAG_GIFT_DEOXYS, 0x1091
.equ FLAG_GIVE_SEVIIANS, 0x1092
.equ FLAG_GIFT_RAYQUAZA, 0x1093
.equ FLAG_GIVE_MEGAS, 0x1094
.equ FLAG_GIVE_RANDOM_6, 0x1095
.equ FLAG_GIFT_HOOH, 0x1098
.equ FLAG_GIFT_LUGIA, 0x1099

.global EventScript_NatureChanger
EventScript_NatureChanger:
    lock
    faceplayer 
    goto DisplayOptions

DisplayOptions:
    setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_LabelNatureChanger
	special 0x25
	setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_LevelCap
	special 0x25
    setvar 0x8006 0x2 @third item
    loadpointer 0x0 gText_GenderSwap
    special 0x25
    setvar 0x8006 0x3
    loadpointer 0x0 gText_ModeInfo
    special 0x25
    setvar 0x8006 0x4
    loadpointer 0x0 gText_MysteryGift
    special 0x25
    preparemsg gText_PCChooseOption
    waitmsg
    multichoice 0x0 0x0 0x23 0x0
    compare LASTRESULT 0x0
    if 0x1 _goto NatureChangeStuff
    compare LASTRESULT 0x1
    if 0x1 _goto LevelCapStuff
    compare LASTRESULT 0x2
    if 0x1 _goto GenderSwapStuff
    @ compare LASTRESULT 0x3 
    @ if 0x1 _goto ToggleInstantHPBar
    compare LASTRESULT 0x3
    if 0x1 _goto ShowModeOptions
    compare LASTRESULT 0x4
    if 0x1 _goto MysteryGift
    release
    end

ShowModeOptions:
    msgbox gText_YouArePlayingOn MSG_NORMAL
    checkflag FLAG_HARDCORE_MODE
    if 0x1 _goto DisplayHCMode
    checkflag FLAG_EASY_MODE
    if 0x1 _goto DisplayEasyMode
    checkflag FLAG_POKEMON_RANDOMIZER
    if 0x1 _goto DisplayRandomizer
    checkflag FLAG_RESTRICT_MODE
    if 0x1 _goto DisplayRestrictMode
    msgbox gText_MsgAskToGoDownEasy MSG_YESNO
    compare LASTRESULT YES
    if equal _goto AskEasyAgain
    goto DisplayOptions

AskEasyAgain:
    msgbox gText_AreYouSureEasy MSG_YESNO
    compare LASTRESULT YES
    if equal _goto SetToEasy
    goto DisplayOptions

SetToEasy:
    sound 0x58
    msgbox gText_SwitchedToEasy MSG_KEEPOPEN
    pause 0x8
    closeonkeypress
    checksound
    setflag FLAG_EASY_MODE
    release
    end

DisplayEasyMode:
    msgbox gText_DisplayEasyMode MSG_NORMAL
    checkflag FLAG_POKEMON_RANDOMIZER
    if 0x1 _call PokemonRandomizer
    checkflag FLAG_ABILITY_RANDOMIZER
    if 0x1 _call AbilityRandomizer
    checkflag FLAG_POKEMON_LEARNSET_RANDOMIZER
    if 0x1 _call LearnsetRandomizer
    checkflag FLAG_SCALED_RANDOMIZER
    if 0x1 _call DisplayScaled
    release
    end

DisplayRestrictMode:
    msgbox gText_RestrictMode MSG_NORMAL
    release
    end

DisplayHCMode:
    msgbox gText_DisplayHCMode MSG_NORMAL
    checkflag FLAG_SCALED_RANDOMIZER
    if 0x1 _call DisplayScaled
    release
    end

DisplayScaled:
    msgbox gText_ScaledRandomizer MSG_NORMAL
    return

PokemonRandomizer:
    msgbox gText_SpeciesRandomizer_PC MSG_NORMAL
    return

DisplayRandomizer:
    msgbox gText_SpeciesRandomizer_PC MSG_NORMAL
    checkflag FLAG_ABILITY_RANDOMIZER
    if 0x1 _call AbilityRandomizer
    checkflag FLAG_POKEMON_LEARNSET_RANDOMIZER
    if 0x1 _call LearnsetRandomizer
    checkflag FLAG_SCALED_RANDOMIZER
    if 0x1 _call DisplayScaled
    release
    end

AbilityRandomizer:
    msgbox gText_AbilityRandomizer_Text MSG_NORMAL
    return

LearnsetRandomizer:
    msgbox gText_LearnsetRandomizer_Text MSG_NORMAL
    return

GenderSwapStuff:
	msgbox gText_DoYouWantGenderSwap MSG_YESNO
	compare LASTRESULT NO
	if equal _goto DisplayOptions
	setvar 0x8003 0x0 
    special 0x9F 
    waitstate 
    compare 0x8004 0x6
    if greaterorequal _goto DisplayOptions
	callasm CheckIfCanSwapGender + 1
	compare LASTRESULT TRUE
	if 0x0 _goto CantDo
	msgbox gText_Gender_DoYouWantTo MSG_YESNO
	compare LASTRESULT NO
	if equal _goto GenderSwapStuff
	callasm ChangeMonGender + 1
	msgbox gText_Gender_SuccesfullySwapped MSG_FACE
    release
    end


LevelCapStuff:
    callasm WhatIsLevelCap + 1
    buffernumber 0x0 LASTRESULT
    msgbox gText_CurrentLevelCap MSG_NORMAL
    release
    end

CantDo:
	msgbox gText_GenderSwapperCantDo MSG_FACE
	release
	end

NatureChangeStuff:
    msgbox gText_NatureChanger1 MSG_YESNO 
    compare LASTRESULT YES 
    if 0x0 _goto CancelThis
	setvar 0x8003 0x0 
    special 0x9F 
    waitstate 
    compare 0x8004 0x6
    if greaterorequal _goto RegCancel 
    goto FirstList2 
	release 
	end 

FirstList2:
    setvar 0x8000 0x6
    setvar 0x8001 0x6
    copyvar 0x5106 0x8004
    setvar 0x8004 0x0 
    preparemsg gText_NatureChanger2 
    waitmsg
    special 0x158
    waitstate 
    copyvar 0x8004 0x5106  
    compare LASTRESULT 0x0
    if 0x1 _goto Adamant
    compare LASTRESULT 0x1
    if 0x1 _goto Modest 
    compare LASTRESULT 0x2
    if 0x1 _goto Timid 
    compare LASTRESULT 0x3 
    if 0x1 _goto Jolly 
    compare LASTRESULT 0x4
    if 0x1 _goto Hasty 
    compare LASTRESULT 0x5 
    if 0x1 _goto Naive 
    compare LASTRESULT 0x6
    if 0x1 _goto Mild 
    compare LASTRESULT 0x7
    if 0x1 _goto Naughty
    compare LASTRESULT 0x8
    if 0x1 _goto Rash 
    compare LASTRESULT 0x9
    if 0x1 _goto Lonely
    compare LASTRESULT 0xA
    if 0x1 _goto Brave 
    compare LASTRESULT 0xB 
    if 0x1 _goto Quiet 
    compare LASTRESULT 0xC
    if 0x1 _goto Calm 
    compare LASTRESULT 0xD
    if 0x1 _goto Impish 
    compare LASTRESULT 0xE
    if 0x1 _goto Sassy 
    compare LASTRESULT 0xF 
    if 0x1 _goto Careful 
    compare LASTRESULT 0x10
    if 0x1 _goto Relaxed 
    compare LASTRESULT 0x11
    if 0x1 _goto Bold 
    compare LASTRESULT 0x12
    if 0x1 _goto Bashful
    compare LASTRESULT 0x13
    if 0x1 _goto Lax
    compare LASTRESULT 0x14
    if 0x1 _goto Gentle
    goto CancelThis 
    end 

Bashful:
    callasm SwitchMonNatureBashful + 1
    goto EndThisScript 

Lax:
    callasm SwitchMonNatureLax + 1
    goto EndThisScript 
    
Gentle:
    callasm SwitchMonNatureGentle + 1
    goto EndThisScript 
Adamant: 
    callasm SwitchMonNatureAdamant + 1
    goto EndThisScript 

Lonely:
	callasm SwitchMonNatureLonely + 1
    goto EndThisScript 

Brave:
	callasm SwitchMonNatureBrave + 1
    goto EndThisScript 

Naughty:
	callasm SwitchMonNatureNaughty + 1
    goto EndThisScript 

Bold:
	callasm SwitchMonNatureBold + 1
    goto EndThisScript 

Relaxed:
	callasm SwitchMonNatureRelaxed + 1
    goto EndThisScript 

Impish:
	callasm SwitchMonNatureImpish + 1
    goto EndThisScript 

Timid:
	callasm SwitchMonNatureTimid + 1
    goto EndThisScript 

Hasty:
	callasm SwitchMonNatureHasty + 1
    goto EndThisScript 

Jolly:
	callasm SwitchMonNatureJolly + 1
    goto EndThisScript 

Naive:
	callasm SwitchMonNatureNaive + 1
    goto EndThisScript 

Modest:
	callasm SwitchMonNatureModest + 1
    goto EndThisScript 

Mild:
	callasm SwitchMonNatureMild + 1
    goto EndThisScript 

Quiet:
	callasm SwitchMonNatureQuiet + 1
    goto EndThisScript 

Rash:
	callasm SwitchMonNatureRash + 1
    goto EndThisScript 

Calm:
	callasm SwitchMonNatureCalm + 1
    goto EndThisScript 

Sassy:
	callasm SwitchMonNatureSassy + 1
    goto EndThisScript 

Careful:
	callasm SwitchMonNatureCareful + 1
    goto EndThisScript 

CancelThis:
	release 
	end 

CancelThis2:
    msgbox gText_NatureChanger4 MSG_NORMAL 
	release 
	end 

EndThisScript: 
	msgbox gText_NatureChanger3 MSG_NORMAL
    msgbox gText_NatureChanger3_2 MSG_KEEPOPEN
    sound 0x1
    checksound
    pause 0x3
    closeonkeypress
	msgbox gText_NatureChanger4 MSG_NORMAL 
	release 
	end 

NotEnoughMoney:
    msgbox gText_Saffron_ManyTutors2 MSG_NORMAL 
    hidemoney 0x00 0x00
    release 
    end 

RegCancel:
	release 
	end 

.global EventScript_GuardTopFloor
EventScript_GuardTopFloor:
    checkflag FLAG_MINIMAL_GRINDING_MODE
    if 0x0 _goto Disappear
    msgbox gText_GuardTopFloorDisappearBanned MSG_FACE
    release
    end
    
Disappear:
    msgbox gText_GuardTopFloorDisappear1 MSG_FACE
    fadescreen 0x1
	hidesprite 0x800F
	sound 0x9
	checksound
	fadescreen 0x0
    release
    end


.global EventScript_ShortNurseJoy
EventScript_ShortNurseJoy:
    lock
    faceplayer
    @ checkflag FLAG_FOLLOWER_IN_PROGRESS
    @ if 0x1 _call CheckIfNeedToPreventStuff
    special 0xE1
    compare LASTRESULT 0x1
    if equal _call PutPkmnInBall
    applymovement 0x800F FaceLeft
    waitmovement 0x0
    doanimation 0x19
    waitanimation 0x19
    applymovement 0x800F FaceDown
    waitmovement 0x0
    special 0x0
    applymovement 0x800F NurseBow
    waitmovement 0x0
    @ callasm CheckIfPkmnOkToFollow + 1
	@ compare LASTRESULT YES
	@ if equal _call EventSetFollowerVisible
EndOfNurseJoy:
    applymovement 0xFF FaceDown
    waitmovement 0x0
    copyvar 0x5129 0x512A 
    release
    end

CheckIfNeedToPreventStuff:
    checkflag FLAG_HIDE_FOLLOWER
    if 0x1 _call SetDontMakeReappearFlag
    return

SetDontMakeReappearFlag:
    setflag FLAG_DONT_MAKE_FOLLOWER_REAPPEAR
    return

EventSetFollowerVisible:
    checkflag FLAG_FOLLOWER_IN_PROGRESS
    if SET _call MakeEmAppearNShit
    return

MakeEmAppearNShit:
    checkflag FLAG_DONT_MAKE_FOLLOWER_REAPPEAR
    if 0x1 _goto ClearFlagAndEnd
    special 0xD3
    fadescreen 0x1
    @ callasm UpdateFollowerPokemonGraphic
    callasm CloneAndCreate
	sound 0xF
	checksound
	fadescreen 0x0
    callasm SetFollowerVisible
    sound 0x1C
    callasm FollowerApplyMovementJumpInPlace
    checksound
    cry 0x5130 0x0
    waitcry
    return

ClearFlagAndEnd:
    clearflag FLAG_DONT_MAKE_FOLLOWER_REAPPEAR
    goto EndOfNurseJoy

AppearNoDestroy:
    special 0xD3
    fadescreen 0x1
    @ callasm UpdateFollowerPokemonGraphic
    callasm CreateNoDestroy
	sound 0xF
	checksound
	fadescreen 0x0
    callasm SetFollowerVisible
    sound 0x1C
    callasm FollowerApplyMovementJumpInPlace
    checksound
    cry 0x5130 0x0
    waitcry
    return

PutPkmnInBall:
    special 0xD3
    pause 0x2
    sound 0x15
    callasm FollowerApplyMovementHappy
    checksound
    pause 0x2
    fadescreen 0x1
	callasm SetFollowerInvisible + 1 
	sound 0xF
	checksound
	fadescreen 0x0
    applymovement PLAYER LookUp
    waitmovement 0x0 
    return

LookUp:
    .byte look_up
    .byte end_m

FaceLeft:
    .byte look_left
    .byte end_m

FaceDown:
    .byte look_down
    .byte end_m

NurseBow: 
    .byte nurse_bow
    .byte end_m

.global EventScript_DebugMenu
EventScript_DebugMenu:
    lock
    faceplayer
    setvar 0x8004 0x0
    setvar 0x8000 0x0
    setvar 0x8001 0x6
    preparemsg gText_DebugMenu
    waitmsg
    special 0x158
    waitstate 
    compare LASTRESULT 0x0
    if 0x1 _goto GivePokemon
    compare LASTRESULT 0x1
    if 0x1 _goto DebugMenu_GiveItem
    compare LASTRESULT 0x2
    if 0x1 _goto DebugMenu_MaxCoinage
    compare LASTRESULT 0x3 
    if 0x1 _goto DebugMenu_SetFlag
    compare LASTRESULT 0x4
    if 0x1 _goto DebugMenu_ClearFlag
    compare LASTRESULT 0x5 
    if 0x1 _goto DebugMenu_WildBattle
    compare LASTRESULT 0x6
    if 0x1 _goto DebugMenu_Trainer
    compare LASTRESULT 0x7
    if 0x1 _goto MakeShiny
    compare LASTRESULT 0x8
    if 0x1 _goto MakeHisuian
    compare LASTRESULT 0x9
    if 0x1 _goto SetToLevelCap
    compare LASTRESULT 0xA
    if 0x1 _goto GiveAllTMs
    release
    end 

GivePokemon:
    msgbox gText_EnterSpeciesNumber MSG_NORMAL
    special 0xB3
    waitstate
    compare LASTRESULT 0xFFFF
    if equal _goto NotValidNumber
    setflag FLAG_DONT_RANDOMIZE
    bufferpokemon 0x0 LASTRESULT
    givepokemon LASTRESULT 0x5 0x0 0x0 0x0 0x0 
    preparemsg gText_ReceivedDebugPokemon @"[player] received the [buffer1]\nf..."
	waitmsg
	fanfare 0x13E
	waitfanfare
    clearflag FLAG_DONT_RANDOMIZE
    release
    end

NotValidNumber:
    msgbox gText_InvalidNumber MSG_NORMAL
    release
    end

DebugMenu_GiveItem:
    msgbox gText_EnterItemNumber MSG_NORMAL
    special 0xB3
    waitstate
    compare LASTRESULT 0xFFFF
    if equal _goto NotValidNumber
    giveitem LASTRESULT 0x99 MSG_OBTAIN
    release
    end

DebugMenu_MaxCoinage:
    addmoney 0x99999
    msgbox gText_DebugMenu_GivenMoney MSG_NORMAL
    release
    end

DebugMenu_SetFlag:
    msgbox gText_EnterFlagNumber MSG_NORMAL
    special 0xB3
    waitstate
    compare LASTRESULT 0xFFFF
    if equal _goto NotValidNumber
    callasm SetFlagInLastResult
    preparemsg gText_DebugFlagSet
	waitmsg
    release
    end

DebugMenu_ClearFlag:
    msgbox gText_EnterFlagNumber MSG_NORMAL
    special 0xB3
    waitstate
    compare LASTRESULT 0xFFFF
    if equal _goto NotValidNumber
    callasm ClearFlagInLastResult
    preparemsg gText_DebugFlagSet
	waitmsg
    release
    end

DebugMenu_WildBattle:
    msgbox gText_EnterSpeciesNumber MSG_NORMAL
    special 0xB3
    waitstate
    compare LASTRESULT 0xFFFF
    if equal _goto NotValidNumber
    @ setwildbattle LASTRESULT 5 0x0
    @ dowildbattle
    callasm StartWildBattleInLastResult
    release
    end

DebugMenu_Trainer:
    msgbox gText_EnterTrainerNumber MSG_NORMAL
    special 0xB3
    waitstate
    compare LASTRESULT 0xFFFF
    if equal _goto NotValidNumber
    callasm VarSetTerrainInHardcoreMode
    trainerbattle3 0x3 LASTRESULT 0x0 gText_peepeePooPoo
    @ callasm StartTrainerBattleInLastResult
    release
    end

MakeShiny:
    setvar 0x8003 0x0 
    special 0x9F 
    waitstate 
    compare 0x8004 0x6
    if greaterorequal _goto End
	callasm MakeMonShiny
    release
    end

MakeHisuian:
    setvar 0x8003 0x0
    special 0x9F
    waitstate
    compare 0x8004 0x6
    if greaterorequal _goto End
    callasm MakeMonHisuian
    release
    end

End:
    release
    end

FindDifficultyOptions:
    msgbox gText_YouArePLayingWithTheseOptions MSG_NORMAL
    callasm DisplayDifficultyOptions
    msgbox gText_DisplayStuff MSG_KEEPOPEN
    pause 0x30
    closeonkeypress
    @checkflag FLAG_HARDCORE_MODE
    @if 0x1 _goto PrintHardcoreMode
    @checkflag FLAG_POKEMON_RANDOMIZER 
    @ if 0x1 _call PokemonRandomizer
    @ checkflag FLAG_ABILITY_RANDOMIZER
    @ if 0x1 _call AbilityRandomizer
    @ checkflag FLAG_POKEMON_LEARNSET_RANDOMIZER
    @ if 0x1 _call LearnsetRandomizer
    @ checkflag FLAG_EASY_MODE
    @ if 0x1 _call EasyMode
    @ checkflag FLAG_RESTRICT_MODE 
    @ if 0x1 _call RestrictedMode
    @ checkflag FLAG_MINIMAL_GRINDING_MODE
    @ if 0x1 _call MinimalGrindingMode
    release
    end

PrintHardcoreMode:
@    msgbox gText_PrintHardcoreMode MSG_NORMAL
    release
    end

@ PokemonRandomizer:
 @   checkflag FLAG_SCALED_RANDOMIZER 
 @   if 0x1 _call SpeciesRandomizerHard
 @   checkflag FLAG_SCALED_RANDOMIZER
 @   if 0x0 _call NormalPokemonRandomizer
@    return

@ NormalPokemonRandomizer:
@    msgbox gText_Misc_PkmnRandomizer MSG_NORMAL
@    return

@ AbilityRandomizer:
@    msgbox gText_Misc_AbilityRandomizer MSG_NORMAL
@    return

@ LearnsetRandomizer:
@    msgbox gText_Misc_LearnsetRandomizer MSG_NORMAL
@    return

@ EasyMode:
@    msgbox gText_Misc_LearnsetRandomizer MSG_NORMAL
@    return

@RestrictedMode:
@    msgbox gText_Misc_RestrictedMode MSG_NORMAL
@   return


@MinimalGrindingMode:
@    msgbox gText_Misc_MgMode MSG_NORMAL
@    return

ToggleInstantHPBar:
    msgbox gText_NatureChanger_InstantHPInfo MSG_NORMAL
    checkflag FLAG_INSTANT_HP
    if 0x0 _goto AskTurnOnInstantHP
    msgbox gText_NatureChanger_TurnOffInstaHP MSG_YESNO
    compare LASTRESULT YES
    if equal _goto TurnOffInstantHP
    release
    end

TurnOffInstantHP:
    clearflag FLAG_INSTANT_HP
    msgbox gText_NatureChanger_TurnedOffInstaHP MSG_KEEPOPEN
    pause 0x3
    closeonkeypress
    release
    end

AskTurnOnInstantHP:
    msgbox gText_NatureChanger_TurnOnInstaHP MSG_YESNO
    compare LASTRESULT YES
    if equal _goto TurnOnInstaHP
    release
    end

TurnOnInstaHP:
    setflag FLAG_INSTANT_HP
    msgbox gText_NatureChanger_TurnedOnInstaHP MSG_KEEPOPEN
    pause 0x3
    closeonkeypress
    release
    end

MysteryGift:
    msgbox gText_MysteryGiftAsk MSG_YESNO
    compare LASTRESULT YES
    if equal _goto InputGiftCode
    release
    end

NotEligible:
    msgbox gText_NeedNewGamePlus MSG_NORMAL
    release 
    end
InputGiftCode:
    special 0x12C
	waitstate
	loadpointer 0x0 gText_RayquazaCode
	special 0x12D
	compare LASTRESULT 0x0
	if equal _goto GiveRayquaza
    loadpointer 0x0 gText_PrimalDialgaCode
    special 0x12D
    compare LASTRESULT 0x0
    if equal _goto GivePrimalDialga
    loadpointer 0x0 gText_ZacianCode
    special 0x12D
    compare LASTRESULT 0x0
    if equal _goto GiveZacian
    loadpointer 0x0 gText_ZamazentaCode
    special 0x12D
    compare LASTRESULT 0x0
    if equal _goto GiveZamazenta

    loadpointer 0x0 gText_Eternatus
    special 0x12D
    compare LASTRESULT 0x0
    if equal _goto GiveEternatus

    loadpointer 0x0 gText_CalyrexSCode
    special 0x12D
    compare LASTRESULT 0x0
    if equal _goto GiveCalyrexS

    loadpointer 0x0 gText_CalyrexIceCode 
    special 0x12D
    compare LASTRESULT 0x0
    if equal _goto GiveCalyrexIce

    loadpointer 0x0 gText_GiratinaCode
    special 0x12D
    compare LASTRESULT 0x0
    if equal _goto GiveGiratina

    loadpointer 0x0 gText_ReshiramCode
    special 0x12D
    compare LASTRESULT 0x0
    if equal _goto GiveReshiram

    loadpointer 0x0 gText_ZekromCode
    special 0x12D
    compare LASTRESULT 0x0
    if equal _goto GiveZekrom
    loadpointer 0x0 gText_YveltalCode
    special 0x12D
    compare LASTRESULT 0x0
    if equal _goto GiveYveltal
    loadpointer 0x0 gText_XerneasCode
    special 0x12D
    compare LASTRESULT 0x0
    if equal _goto GiveXerneas
    loadpointer 0x0 gText_DeoxysCode
    special 0x12D
    compare LASTRESULT 0x0
    if equal _goto GiveDeoxys
    loadpointer 0x0 gText_PalkiaCode
    special 0x12D
    compare LASTRESULT 0x0
    if equal _goto GivePalkia
    loadpointer 0x0 gText_DarkraiCode
    special 0x12D
    compare LASTRESULT 0x0
    if equal _goto GiveDarkrai
    loadpointer 0x0 gText_HoOhCode
    special 0x12D
    compare LASTRESULT 0x0
    if equal _goto GiveHoOh
    loadpointer 0x0 gText_LugiaCode
    special 0x12D
    compare LASTRESULT 0x0
    if equal _goto GiveLugia
    loadpointer 0x0 gText_Seviian
    special 0x12D
    compare LASTRESULT 0x0
    if equal _goto GiveSeviianForms
    loadpointer 0x0 gText_MegaCode
    special 0x12D
    compare LASTRESULT 0x0
    if equal _goto GiveMegaStones
    loadpointer 0x0 gText_Random6
    special 0x12D
    compare LASTRESULT 0x0
    if equal _goto Give6RandomMons
    loadpointer 0x0 gText_SkipPuzzle
    special 0x12D
    compare LASTRESULT 0x0
    if equal _goto SetSkipPuzzle
    loadpointer 0x0 gText_MiraidonCode
    special 0x12D
    compare LASTRESULT 0x0
    if equal _goto GiveMiraidon
    loadpointer 0x0 gText_KoraidonCode
    special 0x12D
    compare LASTRESULT 0x0
    if equal _goto GiveKoraidon

    loadpointer 0x0 gText_Groudon
    special 0x12D
    compare LASTRESULT 0x0
    if equal _goto GiveGroudon

	goto NoThatsNotIt

NeedToBeatGame:
    msgbox gText_NeedToBeatGift MSG_NORMAL
    release 
    end


AlreadyGave:
    msgbox gText_AlreadyRedeemed MSG_NORMAL
    release
    end

GivePrimalDialga:
    checkflag FLAG_GIFT_PRIMAL_DIALGA
    if 0x1 _goto AlreadyGave
    checkflag FLAG_BEAT_GAME
    if 0x0 _goto NeedToBeatGame
    cry SPECIES_DIALGA 0x0
    showpokepic SPECIES_DIALGA_PRIMAL 0x0A 0x03
    waitcry
    pause 0x5
    fanfare 0x13E
    msgbox gText_YouReceivedPrimalDialga MSG_KEEPOPEN
    pause 0xA
    waitfanfare
    hidepokepic
    closeonkeypress
    givepokemon SPECIES_DIALGA 85 ITEM_ADAMANT_ORB 0x0 0x0 0x0
    setflag FLAG_GIFT_PRIMAL_DIALGA
    release
    end


GiveZacian:
    checkflag FLAG_GIFT_ZACIAN
    if 0x1 _goto AlreadyGave
    checkflag FLAG_BEAT_GAME
    if 0x0 _goto NeedToBeatGame
    cry SPECIES_ZACIAN 0x0
    showpokepic SPECIES_ZACIAN 0x0A 0x03
    waitcry
    pause 0x5
    fanfare 0x13E
    bufferpokemon 0x0 SPECIES_ZACIAN
    msgbox gText_YouReceivedGiftPokemonBreak MSG_KEEPOPEN
    pause 0xA
    waitfanfare
    hidepokepic
    closeonkeypress
    givepokemon SPECIES_ZACIAN 85 ITEM_RUSTED_SWORD 0x0 0x0 0x0
    setflag FLAG_GIFT_ZACIAN
    release
    end

GiveLugia:
    checkflag FLAG_GIFT_LUGIA
    if 0x1 _goto AlreadyGave
    checkflag FLAG_BEAT_GAME
    if 0x0 _goto NeedToBeatGame
    cry SPECIES_LUGIA 0x0
    showpokepic SPECIES_LUGIA 0x0A 0x03
    waitcry
    pause 0x5
    fanfare 0x13E
    bufferpokemon 0x0 SPECIES_LUGIA
    msgbox gText_YouReceivedGiftPokemon MSG_KEEPOPEN
    pause 0xA
    waitfanfare
    hidepokepic
    closeonkeypress
    givepokemon SPECIES_LUGIA 85 0x0 0x0 0x0 0x0
    setflag FLAG_GIFT_LUGIA
    release
    end

GiveHoOh:
    checkflag FLAG_GIFT_HOOH
    if 0x1 _goto AlreadyGave
    checkflag FLAG_BEAT_GAME
    if 0x0 _goto NeedToBeatGame 
    cry SPECIES_HO_OH 0x0
    setflag FLAG_HIDDEN_ABILITY
    showpokepic SPECIES_HO_OH 0x0A 0x03
    waitcry
    pause 0x5
    fanfare 0x13E
    bufferpokemon 0x0 SPECIES_HO_OH
    msgbox gText_YouReceivedGiftPokemon MSG_KEEPOPEN
    pause 0xA
    waitfanfare
    hidepokepic
    closeonkeypress
    givepokemon SPECIES_HO_OH 85 0x0 0x0 0x0 0x0
    setflag FLAG_GIFT_HOOH
    release
    end


GiveZamazenta:
    checkflag FLAG_GIFT_ZAMAZENTA
    if 0x1 _goto AlreadyGave
    checkflag FLAG_BEAT_GAME
    if 0x0 _goto NeedToBeatGame
    cry SPECIES_ZAMAZENTA 0x0
    showpokepic SPECIES_ZAMAZENTA 0x0A 0x03
    waitcry
    pause 0x5
    fanfare 0x13E
    bufferpokemon 0x0 SPECIES_ZAMAZENTA
    msgbox gText_YouReceivedGiftPokemon MSG_KEEPOPEN
    pause 0xA
    waitfanfare
    hidepokepic
    closeonkeypress
    givepokemon SPECIES_ZAMAZENTA 85 ITEM_RUSTED_SHIELD 0x0 0x0 0x0
    setflag FLAG_GIFT_ZAMAZENTA
    release
    end

GiveEternatus:
    checkflag FLAG_GIFT_ETERNATUS
    if 0x1 _goto AlreadyGave
    checkflag FLAG_BEAT_GAME
    if 0x0 _goto NeedToBeatGame
    cry SPECIES_ETERNATUS 0x0
    showpokepic SPECIES_ETERNATUS_ETERNAMAX 0x0A 0x03
    waitcry
    pause 0x5
    fanfare 0x13E
    bufferpokemon 0x0 SPECIES_ETERNATUS
    msgbox gText_YouReceiveEternatus MSG_KEEPOPEN
    pause 0xA
    waitfanfare
    hidepokepic
    closeonkeypress
    givepokemon SPECIES_ETERNATUS 85 ITEM_ETERNAMAX_ORB 0x0 0x0 0x0
    setflag FLAG_GIFT_ETERNATUS
    release
    end

GiveCalyrexS:
    checkflag FLAG_GIFT_CALYREX_S
    if 0x1 _goto AlreadyGave
    checkflag FLAG_BEAT_GAME
    if 0x0 _goto NeedToBeatGame
    cry SPECIES_CALYREX_SHADOW 0x0
    showpokepic SPECIES_CALYREX_SHADOW 0x0A 0x03
    waitcry
    pause 0x5
    fanfare 0x13E
    bufferpokemon 0x0 SPECIES_CALYREX_SHADOW
    msgbox gText_YouReceivedGiftPokemonBreak MSG_KEEPOPEN
    pause 0xA
    waitfanfare
    hidepokepic
    closeonkeypress
    givepokemon SPECIES_CALYREX_SHADOW 85 0x0 0x0 0x0 0x0
    setflag FLAG_GIFT_CALYREX_S
    release
    end

GiveCalyrexIce:
    checkflag FLAG_GIFT_CALYREX_ICE
    if 0x1 _goto AlreadyGave
    checkflag FLAG_BEAT_GAME
    if 0x0 _goto NeedToBeatGame
    cry SPECIES_CALYREX_ICE 0x0
    showpokepic SPECIES_CALYREX_ICE 0x0A 0x03
    waitcry
    pause 0x5
    fanfare 0x13E
    bufferpokemon 0x0 SPECIES_CALYREX_ICE
    msgbox gText_YouReceivedGiftPokemon MSG_KEEPOPEN
    pause 0xA
    waitfanfare
    hidepokepic
    closeonkeypress
    givepokemon SPECIES_CALYREX_ICE 85 0x0 0x0 0x0 0x0
    setflag FLAG_GIFT_CALYREX_ICE
    release
    end

GiveGiratina:
    checkflag FLAG_GIFT_GIRATINA
    if 0x1 _goto AlreadyGave
    checkflag FLAG_BEAT_GAME
    if 0x0 _goto NeedToBeatGame
    cry SPECIES_GIRATINA 0x0
    showpokepic SPECIES_GIRATINA_ORIGIN 0x0A 0x03
    waitcry
    pause 0x5
    fanfare 0x13E
    bufferpokemon 0x0 SPECIES_GIRATINA
    msgbox gText_YouReceivedGiftPokemon MSG_KEEPOPEN
    pause 0xA
    hidepokepic
    waitfanfare
    closeonkeypress
    setvar 0x8000 MOVE_SPIRITSHACKLE
    setvar 0x8001 MOVE_DRAGONHAMMER
    setvar 0x8002 MOVE_SHADOWSNEAK @moves 
    setvar 0x8003 MOVE_EARTHQUAKE 
    setvar 0x8004 NATURE_NAIVE @nature 
    setvar 0x8005 0x0 
    setvar 0x8006 31
    setvar 0x8007 31
    setvar 0x8008 31
    setvar 0x8009 31
    setvar 0x800A 31
    setvar 0x800B 31
    givepokemon SPECIES_GIRATINA 85 ITEM_GRISEOUS_ORB 0x0 0x1 0x0
    setflag FLAG_GIFT_GIRATINA
    release
    end

GiveReshiram:
    checkflag FLAG_GIFT_RESHIRAM
    if 0x1 _goto AlreadyGave
    checkflag FLAG_BEAT_GAME
    if 0x0 _goto NeedToBeatGame
    cry SPECIES_RESHIRAM 0x0
    showpokepic SPECIES_RESHIRAM 0x0A 0x03
    waitcry
    pause 0x5
    fanfare 0x13E
    bufferpokemon 0x0 SPECIES_RESHIRAM
    msgbox gText_YouReceivedGiftPokemon MSG_KEEPOPEN
    pause 0xA
    waitfanfare
    hidepokepic
    closeonkeypress
    givepokemon SPECIES_RESHIRAM 85 0x0 0x0 0x0 0x0
    setflag FLAG_GIFT_RESHIRAM
    release
    end

GiveZekrom:
    checkflag FLAG_GIFT_ZEKROM
    if 0x1 _goto AlreadyGave
    checkflag FLAG_BEAT_GAME
    if 0x0 _goto NeedToBeatGame
    cry SPECIES_ZEKROM 0x0
    showpokepic SPECIES_ZEKROM 0x0A 0x03
    waitcry
    pause 0x5
    fanfare 0x13E
    bufferpokemon 0x0 SPECIES_ZEKROM
    msgbox gText_YouReceivedGiftPokemon MSG_KEEPOPEN
    pause 0xA
    waitfanfare
    hidepokepic
    closeonkeypress
    givepokemon SPECIES_ZEKROM 85 0x0 0x0 0x0 0x0
    setflag FLAG_GIFT_ZEKROM
    release
    end

GiveYveltal:
    checkflag FLAG_GIFT_YVELTAL
    if 0x1 _goto AlreadyGave
    checkflag FLAG_BEAT_GAME
    if 0x0 _goto NeedToBeatGame
    cry SPECIES_YVELTAL 0x0
    showpokepic SPECIES_YVELTAL 0x0A 0x03
    waitcry
    pause 0x5
    fanfare 0x13E
    bufferpokemon 0x0 SPECIES_YVELTAL
    msgbox gText_YouReceivedGiftPokemon MSG_KEEPOPEN
    pause 0xA
    waitfanfare
    hidepokepic
    closeonkeypress
    setvar 0x8000 MOVE_DARKHOLE
    setvar 0x8001 MOVE_OBLIVIONWING
    setvar 0x8002 MOVE_SUCKERPUNCH @moves 
    setvar 0x8003 MOVE_ROOST 
    setvar 0x8004 NATURE_NAIVE @nature 
    setvar 0x8005 0x0 
    setvar 0x8006 31
    setvar 0x8007 31
    setvar 0x8008 31
    setvar 0x8009 31
    setvar 0x800A 31
    setvar 0x800B 31
    givepokemon SPECIES_YVELTAL 85 0x0 0x0 0x1 0x0
    setflag FLAG_GIFT_YVELTAL
    release
    end

GiveXerneas:
    checkflag FLAG_GIFT_XERNEAS
    if 0x1 _goto AlreadyGave
    checkflag FLAG_BEAT_GAME
    if 0x0 _goto NeedToBeatGame
    cry SPECIES_XERNEAS 0x0
    showpokepic SPECIES_XERNEAS 0x0A 0x03
    waitcry
    pause 0x5
    fanfare 0x13E
    bufferpokemon 0x0 SPECIES_XERNEAS
    msgbox gText_YouReceivedGiftPokemon MSG_KEEPOPEN
    pause 0xA
    waitfanfare
    hidepokepic
    closeonkeypress
    givepokemon SPECIES_XERNEAS 85 0x0 0x0 0x0 0x0
    setflag FLAG_GIFT_XERNEAS
    release
    end

GiveDeoxys:
    checkflag FLAG_GIFT_DEOXYS
    if 0x1 _goto AlreadyGave
    checkflag FLAG_BEAT_GAME
    if 0x0 _goto NeedToBeatGame
    cry SPECIES_DEOXYS 0x0
    showpokepic SPECIES_DEOXYS 0x0A 0x03
    waitcry
    pause 0x5
    fanfare 0x13E
    bufferpokemon 0x0 SPECIES_DEOXYS
    msgbox gText_YouReceivedGiftPokemon MSG_KEEPOPEN
    pause 0xA
    waitfanfare
    hidepokepic
    closeonkeypress
    setvar 0x8000 MOVE_MYSTICALPOWER
    setvar 0x8001 MOVE_EXTREMESPEED
    setvar 0x8002 MOVE_ICEBEAM @moves 
    setvar 0x8003 MOVE_KNOCKOFF 
    setvar 0x8004 NATURE_NAIVE @nature 
    setvar 0x8005 0x0 
    setvar 0x8006 31
    setvar 0x8007 31
    setvar 0x8008 31
    setvar 0x8009 31
    setvar 0x800A 31
    setvar 0x800B 31
    givepokemon SPECIES_DEOXYS 85 0x0 0x0 0x1 0x0
    setflag FLAG_GIFT_DEOXYS
    release
    end


GivePalkia:
    checkflag FLAG_GIFT_PALKIA
    if 0x1 _goto AlreadyGave
    checkflag FLAG_BEAT_GAME
    if 0x0 _goto NeedToBeatGame
    cry SPECIES_PALKIA 0x0
    showpokepic SPECIES_PALKIA 0x0A 0x03
    waitcry
    pause 0x5
    fanfare 0x13E
    bufferpokemon 0x0 SPECIES_PALKIA
    msgbox gText_YouReceivedGiftPokemon MSG_KEEPOPEN
    pause 0xA
    waitfanfare
    hidepokepic
    closeonkeypress
    givepokemon SPECIES_PALKIA 85 0x0 0x0 0x0 0x0
    setflag FLAG_GIFT_PALKIA
    release
    end

GiveDarkrai:
    checkflag FLAG_GIFT_DARKRAI
    if 0x1 _goto AlreadyGave
    checkflag FLAG_BEAT_GAME
    if 0x0 _goto NeedToBeatGame
    cry SPECIES_DARKRAI 0x0
    showpokepic SPECIES_DARKRAI 0x0A 0x03
    waitcry
    pause 0x5
    fanfare 0x13E
    bufferpokemon 0x0 SPECIES_DARKRAI
    msgbox gText_YouReceivedGiftPokemon MSG_KEEPOPEN
    pause 0xA
    waitfanfare
    hidepokepic
    closeonkeypress
    setvar 0x8000 MOVE_DARKHOLE
    setvar 0x8001 MOVE_FOCUSBLAST
    setvar 0x8002 MOVE_NASTYPLOT 
    setvar 0x8003 MOVE_DARKVOID 
    setvar 0x8004 NATURE_TIMID @nature 
    setvar 0x8005 0x0 
    setvar 0x8006 31
    setvar 0x8007 31
    setvar 0x8008 31
    setvar 0x8009 31
    setvar 0x800A 31
    setvar 0x800B 31
    givepokemon SPECIES_DARKRAI 85 0x0 0x0 0x1 0x0
    setflag FLAG_GIFT_DARKRAI
    release
    end

GiveRayquaza:
    checkflag FLAG_GIFT_RAYQUAZA
    if 0x1 _goto AlreadyGave
    checkflag FLAG_BEAT_GAME
    if 0x0 _goto NeedToBeatGame
    cry SPECIES_RAYQUAZA 0x0
    showpokepic SPECIES_RAYQUAZA_MEGA 0x0A 0x03
    waitcry
    pause 0x5
    fanfare 0x13E
    bufferpokemon 0x0 SPECIES_RAYQUAZA
    msgbox gText_YouReceivedGiftPokemonBreak MSG_KEEPOPEN
    pause 0xA
    waitfanfare
    hidepokepic
    closeonkeypress
    setvar 0x8000 MOVE_DRAGONASCENT
    setvar 0x8001 MOVE_EARTHQUAKE
    setvar 0x8002 MOVE_VCREATE 
    setvar 0x8003 MOVE_EXTREMESPEED
    setvar 0x8004 NATURE_JOLLY @nature 
    setvar 0x8005 0x0 
    setvar 0x8006 31
    setvar 0x8007 31
    setvar 0x8008 31
    setvar 0x8009 31
    setvar 0x800A 31
    setvar 0x800B 31
    givepokemon SPECIES_RAYQUAZA 85 0x0 0x0 0x1 0x0
    setflag FLAG_GIFT_RAYQUAZA
    release
    end
.equ FLAG_GIFT_MIRAIDON, 0x109E
.equ FLAG_GIFT_KORAIDON, 0x109F
.equ FLAG_GIFT_GROUDON,  0x109A

GiveMiraidon:
    checkflag FLAG_GIFT_MIRAIDON
    if 0x1 _goto AlreadyGave
    checkflag FLAG_BEAT_GAME
    if 0x0 _goto NeedToBeatGame 
    cry SPECIES_MIRAIDON 0x0
    showpokepic SPECIES_MIRAIDON 0x0A 0x03
    waitcry
    pause 0x5
    fanfare 0x13E
    bufferpokemon 0x0 SPECIES_MIRAIDON
    msgbox gText_YouReceivedGiftPokemon MSG_KEEPOPEN
    pause 0xA
    waitfanfare
    hidepokepic
    closeonkeypress
    givepokemon SPECIES_MIRAIDON 85 0x0 0x0 0x0 0x0
    setflag FLAG_GIFT_MIRAIDON
    release
    end

GiveKoraidon:
    checkflag FLAG_GIFT_KORAIDON
    if 0x1 _goto AlreadyGave
    checkflag FLAG_BEAT_GAME
    if 0x0 _goto NeedToBeatGame 
    cry SPECIES_KORAIDON 0x0
    showpokepic SPECIES_KORAIDON 0x0A 0x03
    waitcry
    pause 0x5
    fanfare 0x13E
    bufferpokemon 0x0 SPECIES_KORAIDON
    msgbox gText_YouReceivedGiftPokemon MSG_KEEPOPEN
    pause 0xA
    waitfanfare
    hidepokepic
    closeonkeypress
    givepokemon SPECIES_KORAIDON 85 0x0 0x0 0x0 0x0
    setflag FLAG_GIFT_KORAIDON
    release
    end


GiveGroudon:
    checkflag FLAG_GIFT_GROUDON
    if 0x1 _goto AlreadyGave
    checkflag FLAG_BEAT_GAME
    if 0x0 _goto NeedToBeatGame 
    cry SPECIES_GROUDON 0x0
    showpokepic SPECIES_GROUDON 0x0A 0x03
    waitcry
    pause 0x5
    fanfare 0x13E
    bufferpokemon 0x0 SPECIES_GROUDON
    msgbox gText_YouReceivedGiftPokemon MSG_KEEPOPEN
    pause 0xA
    waitfanfare
    hidepokepic
    closeonkeypress
    givepokemon SPECIES_GROUDON 85 ITEM_RED_ORB 0x0 0x0 0x0
    setflag FLAG_GIFT_GROUDON
    release
    end

GiveSeviianForms:
    checkflag FLAG_GIVE_SEVIIANS
    if 0x1 _goto AlreadyGave
    checkflag FLAG_NEW_GAME_PLUS
    if 0x0 _goto NotEligible
    cry SPECIES_DODUO_S 0x0
    showpokepic SPECIES_DODUO_S 0x0A 0x03
    givepokemon SPECIES_DODUO_S 0x5 0x0 0x0 0x0 0x0
    waitcry
    pause 0x20 
    hidepokepic

    cry SPECIES_TEDDIURSA_S 0x0
    showpokepic SPECIES_TEDDIURSA_S 0x0A 0x03
    givepokemon SPECIES_TEDDIURSA_S 0x5 0x0 0x0 0x0 0x0
    waitcry
    pause 0x20 
    hidepokepic

    cry SPECIES_MANTYKE_S 0x0
    showpokepic SPECIES_MANTYKE_S 0x0A 0x03
    givepokemon SPECIES_MANTYKE_S 0x5 0x0 0x0 0x0 0x0
    waitcry
    pause 0x5
    hidepokepic

    cry SPECIES_FEEBAS_S 0x0
    showpokepic SPECIES_FEEBAS_S 0x0A 0x03
    givepokemon SPECIES_FEEBAS_S 0x5 0x0 0x0 0x0 0x0
    waitcry
    pause 0x20 
    hidepokepic
    cry SPECIES_CLAUNCHER_S 0x0
    showpokepic SPECIES_CLAUNCHER_S 0x0A 0x03
    givepokemon SPECIES_CLAUNCHER_S 0x5 0x0 0x0 0x0 0x0
    waitcry
    pause 0x20 
    hidepokepic
    cry SPECIES_SIZZLIPEDE_S 0x0
    showpokepic SPECIES_SIZZLIPEDE_S 0x0A 0x03
    givepokemon SPECIES_SIZZLIPEDE_S 0x5 0x0 0x0 0x0 0x0
    waitcry
    pause 0x20 
    hidepokepic
    cry SPECIES_DHELMISE_S 0x0
    showpokepic SPECIES_DHELMISE_S 0x0A 0x03
    givepokemon SPECIES_DHELMISE_S 0x5 0x0 0x0 0x0 0x0
    waitcry
    pause 0x20 
    hidepokepic
    cry SPECIES_WISHIWASHI_SEVI 0x0
    showpokepic SPECIES_WISHIWASHI_SEVI 0x0A 0x03
    givepokemon SPECIES_WISHIWASHI_SEVI 0x5 0x0 0x0 0x0 0x0
    waitcry
    pause 0x20 
    hidepokepic

    cry SPECIES_BLITZLE_S 0x0
    showpokepic SPECIES_BLITZLE_S 0x0A 0x03
    givepokemon SPECIES_BLITZLE_S 0x5 0x0 0x0 0x0 0x0
    waitcry
    pause 0x20 
    hidepokepic
    cry SPECIES_CARNIVINE_S 0x0
    showpokepic SPECIES_CARNIVINE_S 0x0A 0x03
    givepokemon SPECIES_CARNIVINE_S 0x5 0x0 0x0 0x0 0x0
    waitcry
    pause 0x20 
    hidepokepic

    cry SPECIES_NOIBAT_S 0x0
    showpokepic SPECIES_NOIBAT_S 0x0A 0x03
    givepokemon SPECIES_NOIBAT_S 0x5 0x0 0x0 0x0 0x0
    waitcry
    pause 0x20 
    hidepokepic

    cry SPECIES_NYMBLE_S 0x0
    showpokepic SPECIES_NYMBLE_S 0x0A 0x03
    givepokemon SPECIES_NYMBLE_S 0x5 0x0 0x0 0x0 0x0
    waitcry
    pause 0x20 
    hidepokepic
    fanfare 0x13E

    msgbox gText_YouReceivedAllSeviians MSG_KEEPOPEN
    waitfanfare
    pause 0x5
    closeonkeypress
    setflag FLAG_GIVE_SEVIIANS
    release
    end


NoThatsNotIt:
    msgbox gText_MmThatIncorrect MSG_NORMAL
    release
    end

GiveMegaStones:
    checkflag FLAG_NEW_GAME_PLUS
    if 0x0 _goto NotEligible
    checkflag FLAG_GIVE_MEGAS
    if 0x1 _goto AlreadyGave
    checkflag 0x822
    if 0x1 _goto GiveMegas
    checkflag 0x823
    if 0x1 _goto GiveMegas
    msgbox gText_NeedBadgesForThis MSG_NORMAL
    release
    end

GiveMegas:
    @ checkitem ITEM_MEGA_RING 0x1
    @ compare 0x800D 0x1
    @ if 0x0 _call GiveItemMegaRing
    giveitem ITEM_VENUSAURITE 0x1 MSG_OBTAIN
    giveitem ITEM_CHARIZARDITE_X 0x1 MSG_OBTAIN
    giveitem ITEM_CHARIZARDITE_Y 0x1 MSG_OBTAIN
    giveitem ITEM_BLASTOISINITE 0x1 MSG_OBTAIN
    giveitem ITEM_BEEDRILLITE 0x1 MSG_OBTAIN
    giveitem ITEM_PIDGEOTITE 0x1 MSG_OBTAIN
    giveitem ITEM_ALAKAZITE 0x1 MSG_OBTAIN
    giveitem ITEM_SLOWBRONITE 0x1 MSG_OBTAIN
    giveitem ITEM_GENGARITE 0x1 MSG_OBTAIN
    giveitem ITEM_KANGASKHANITE 0x1 MSG_OBTAIN
    giveitem ITEM_PINSIRITE 0x1 MSG_OBTAIN
    giveitem ITEM_AERODACTYLITE 0x1 MSG_OBTAIN
    giveitem ITEM_MEWTWONITE_X 0x1 MSG_OBTAIN
    giveitem ITEM_MEWTWONITE_Y 0x1 MSG_OBTAIN
    giveitem ITEM_AMPHAROSITE 0x1 MSG_OBTAIN
    giveitem ITEM_STEELIXITE 0x1 MSG_OBTAIN
    giveitem ITEM_SCIZORITE  0x1 MSG_OBTAIN
    giveitem ITEM_HERACRONITE 0x1 MSG_OBTAIN
    giveitem ITEM_HOUNDOOMINITE 0x1 MSG_OBTAIN   
    giveitem ITEM_TYRANITARITE 0x1 MSG_OBTAIN   
    giveitem ITEM_SCEPTILITE 0x1 MSG_OBTAIN 
    giveitem ITEM_BLAZIKENITE 0x1 MSG_OBTAIN  
    giveitem ITEM_SWAMPERTITE 0x1 MSG_OBTAIN  
    giveitem ITEM_GARDEVOIRITE 0x1 MSG_OBTAIN  
    giveitem ITEM_SABLENITE 0x1 MSG_OBTAIN  
    giveitem ITEM_MAWILITE 0x1 MSG_OBTAIN   
    giveitem ITEM_AGGRONITE 0x1 MSG_OBTAIN  
    giveitem ITEM_MEDICHAMITE 0x1 MSG_OBTAIN 
    giveitem ITEM_MANECTITE 0x1 MSG_OBTAIN 
    giveitem ITEM_SHARPEDONITE 0x1 MSG_OBTAIN 
    giveitem ITEM_CAMERUPTITE 0x1 MSG_OBTAIN 
    giveitem ITEM_ALTARIANITE 0x1 MSG_OBTAIN 
    giveitem ITEM_BANETTITE 0x1 MSG_OBTAIN 
    giveitem ITEM_ABSOLITE 0x1 MSG_OBTAIN 
    giveitem ITEM_GLALITITE 0x1 MSG_OBTAIN 
    giveitem ITEM_SALAMENCITE 0x1 MSG_OBTAIN 
    giveitem ITEM_METAGROSSITE 0x1 MSG_OBTAIN 
    giveitem ITEM_LATIASITE 0x1 MSG_OBTAIN 
    giveitem ITEM_LATIOSITE 0x1 MSG_OBTAIN 
    giveitem ITEM_LOPUNNITE 0x1 MSG_OBTAIN 
    giveitem ITEM_GARCHOMPITE 0x1 MSG_OBTAIN   
    giveitem ITEM_LUCARIONITE 0x1 MSG_OBTAIN  
    giveitem ITEM_ABOMASITE 0x1 MSG_OBTAIN 
    giveitem ITEM_GALLADITE 0x1 MSG_OBTAIN 
    giveitem ITEM_AUDINITE 0x1 MSG_OBTAIN 
    giveitem ITEM_DIANCITE 0x1 MSG_OBTAIN
    giveitem ITEM_MACHAMPITE 0x1 MSG_OBTAIN   
    giveitem ITEM_LAPRASITE 0x1 MSG_OBTAIN    
    giveitem ITEM_BUTTERFRITE 0x1 MSG_OBTAIN  
    giveitem ITEM_GARBODORITE 0x1 MSG_OBTAIN  
    giveitem ITEM_SNORLAXITE 0x1 MSG_OBTAIN   
    giveitem ITEM_KINGLERITE 0x1 MSG_OBTAIN   
    giveitem ITEM_TOXTRICITITE 0x1 MSG_OBTAIN  
    giveitem ITEM_COALOSSITE 0x1 MSG_OBTAIN    
    giveitem ITEM_DURALUDONITE 0x1 MSG_OBTAIN   
    giveitem ITEM_DREDNAWITE 0x1 MSG_OBTAIN  
    giveitem ITEM_COPPERAJITE 0x1 MSG_OBTAIN 
    giveitem ITEM_APPLITE 0x1 MSG_OBTAIN     
    giveitem ITEM_ORBEETLITE 0x1 MSG_OBTAIN   
    giveitem ITEM_CENTISKITE 0x1 MSG_OBTAIN  
    giveitem ITEM_SANDACONDITE 0x1 MSG_OBTAIN
    giveitem ITEM_ALCREMITE 0x1 MSG_OBTAIN   
    giveitem ITEM_GYARADOSITE 0x1 MSG_OBTAIN   
    setflag FLAG_GIVE_MEGAS
    @ setvar 0x5042 0x1 
    release
    end

GiveItemMegaRing:
    giveitem ITEM_MEGA_RING 0x1 MSG_OBTAIN
    return

Give6RandomMons:
    checkflag FLAG_NEW_GAME_PLUS
    if 0x0 _goto NotEligible
    checkflag FLAG_GIVE_RANDOM_6
    if 0x1 _goto AlreadyGave
    callasm Give6RandomMonsAsm + 1
    showpokepic 0x5142 0x0A 0x03
    cry 0x5142 0x0
    waitcry
    pause 0x30
    hidepokepic
    showpokepic 0x5143 0x0A 0x03
    cry 0x5143 0x0
    waitcry
    pause 0x30
    hidepokepic
    showpokepic 0x5144 0x0A 0x03
    cry 0x5144 0x0
    waitcry
    pause 0x30
    hidepokepic
    showpokepic 0x5145 0x0A 0x03
    cry 0x5145 0x0
    waitcry
    pause 0x30
    hidepokepic
    showpokepic 0x5146 0x0A 0x03
    cry 0x5146 0x0
    waitcry
    pause 0x30
    hidepokepic
    showpokepic 0x5147 0x0A 0x03
    cry 0x5147 0x0
    waitcry
    pause 0x30
    hidepokepic
    givepokemon 0x5142 0x5 0x0 0x0 0x0 0x0
    givepokemon 0x5143 0x5 0x0 0x0 0x0 0x0
    givepokemon 0x5144 0x5 0x0 0x0 0x0 0x0
    givepokemon 0x5145 0x5 0x0 0x0 0x0 0x0
    givepokemon 0x5146 0x5 0x0 0x0 0x0 0x0
    givepokemon 0x5147 0x5 0x0 0x0 0x0 0x0
    setflag FLAG_GIVE_RANDOM_6
    setvar VAR_TEMPORARY_VALUE_3 0x0
    setvar VAR_TEMPORARY_VALUE_4 0x0
    setvar VAR_TEMPORARY_VALUE 0x0
    setvar VAR_TEMPORARY_VALUE_2 0x0
    setvar VAR_TEMPORARY_VALUE_5 0x0
    setvar VAR_TEMPORARY_VALUE_6 0x0
    setvar VAR_TEMPORARY_VALUE_7 0x0
    release
    end

SetSkipPuzzle:
    checkflag FLAG_NEW_GAME_PLUS
    if 0x0 _goto NotEligible
    checkflag FLAG_NEW_GAME_PUZZLE
    if 0x1 _goto AlreadyGave
    msgbox gText_YouCanSKipPuzzle MSG_NORMAL
    setflag FLAG_NEW_GAME_PUZZLE
    release
    end

SetToLevelCap:
    setvar 0x8003 0x0 
    special 0x9F 
    waitstate 
    compare 0x8004 0x6
    if greaterorequal _goto End
	callasm SetToLevelCapAsm + 1
    compare LASTRESULT 0x0
    if equal _goto AlreadyAtLevelCap
    msgbox gText_SetToLevelCap MSG_KEEPOPEN
    sound 0x58
    checksound
    pause 0x5
    closeonkeypress 
    special 0x0
    release
    end

GiveAllTMs:
    setvar LASTRESULT 0x4
    callasm DebugMenu_ProcessGiveItem
    release
    end 

AlreadyAtLevelCap:
    msgbox gText_AlreadyAtLevelCap MSG_NORMAL
    release
    end
