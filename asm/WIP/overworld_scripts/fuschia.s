.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s" 

.equ FLAG_HARDCORE_MODE, 0x1034
.equ VAR_BATTLE_AURAS, 0x5119
.equ VAR_BATTLE_TAILWIND_STRING, 5
.equ FLAG_MINIMAL_GRINDING_MODE, 0x1032

.global EventScript_Fuschia_OakAid
EventScript_Fuschia_OakAid:
    checkflag 0x999 
    if 0x1 _goto AidDone
	msgbox gText_Fuschia_OakAid1 MSG_FACE 
    giveitem ITEM_TOXIC_ORB 0x1 MSG_OBTAIN 
    giveitem ITEM_FLAME_ORB 0x1 MSG_OBTAIN 
    setflag 0x999
    goto AidDone
	end

AidDone:
    msgbox gText_Fuschia_OakAid2 MSG_FACE 
    release 
    end 

.global EventScript_Fuschia_NastyPlot
EventScript_Fuschia_NastyPlot:
    lock
    faceplayer 
	msgbox gText_Fuschia_NastyPlot1 MSG_YESNO
    compare LASTRESULT YES 
    if NO _goto Cancel
    setvar 0x8005 0x4C
    special 0x18D
    waitstate
    compare LASTRESULT 0x0
    if 0x1 _goto Cancel
    msgbox gText_Fuschia_NastyPlot2 MSG_FACE 
    release 
	end

Cancel:
    msgbox gText_Fuschia_NastyPlot3 MSG_FACE 
    release 
    end 

.global EventScript_Fuschia_EggTutor2
EventScript_Fuschia_EggTutor2:
    lock
    faceplayer
    textcolor 0x0
	checkflag FLAG_NEW_GAME_PUZZLE
	if 0x1 _goto YouGotItLol
    checkflag 0x104D
    if 0x1 _goto TeachMove2
	msgbox gText_Fuschia_GuessCry1 MSG_NORMAL
	msgbox gText_Fuschia_GuessCry1_1 MSG_YESNO
	compare LASTRESULT NO
	if equal _goto Cancel1 
	msgbox gText_Fuschia_GuessCry2 MSG_NORMAL

PokemonOne:
	fadeoutbgm 0x1
	pause 0x1
	cry SPECIES_MAGMAR 0x0
	msgbox gText_Fuschia_DotDotDot MSG_KEEPOPEN
	waitcry
	closeonkeypress
	msgbox gText_Fuschia_WhichOne MSG_KEEPOPEN
	fadeinbgm 0x1
	pause 0x1
	closeonkeypress
	special 0x12C
	waitstate
	loadpointer 0x0 gText_Magmar
	special 0x12D
	compare LASTRESULT 0x0
	if equal _goto PokemonTwo
	call checkiffunny
	sound 0x1A
	msgbox gText_Fuschia_GuessCry4 MSG_KEEPOPEN @if we got here that means we guessed incorrect
	checksound
	closeonkeypress
	goto TryAgainOne
	end

checkiffunny:
	loadpointer 0x0 gText_Gulpin
	special 0x12D
	compare LASTRESULT 0x0
	if equal _goto GulpinDeezNuts
	loadpointer 0x0 gText_Rhydon
	special 0x12D
	compare LASTRESULT 0x0
	if equal _goto RhydonDeezNuts
	return

GulpinDeezNuts:
	fadeinbgm 0x1
	msgbox gText_Fuschia_GuessGulpin MSG_NORMAL
	release
	end

RhydonDeezNuts:
	fadeinbgm 0x1
	msgbox gText_Fuschia_GuessRhydon MSG_NORMAL
	release
	end

PokemonTwo:
	setflag FLAG_DONT_RANDOMIZE
	showpokepic SPECIES_MAGMAR 0x0A 0x03
	cry SPECIES_MAGMAR 0x0
	msgbox gText_Fuschia_GuessCry3_1 MSG_KEEPOPEN
	waitcry
	closeonkeypress
	hidepokepic
	msgbox gText_Fuschia_GuessCry3 MSG_NORMAL
	goto StartPokemonTwo
	end

StartPokemonTwo:
	msgbox gText_Fuschia_DotDotDot MSG_KEEPOPEN
	fadeoutbgm 0x1
	pause 0x1
	cry SPECIES_NINCADA 0x0
	waitcry
	closeonkeypress
	msgbox gText_Fuschia_WhichOne MSG_NORMAL
	fadeinbgm 0x1
	pause 0x1
	special 0x12C
	waitstate
	loadpointer 0x0 gText_Nincada
	special 0x12D
	compare LASTRESULT 0x0
	if equal _goto PokemonThree
	call checkiffunny
	sound 0x1A
	msgbox gText_Fuschia_GuessCry4 MSG_KEEPOPEN @if we got here that means we guessed incorrect
	checksound
	closeonkeypress
	goto TryAgainTwo
	end

PokemonThree:
	showpokepic SPECIES_NINCADA 0x0A 0x03
	cry SPECIES_NINCADA 0x0
	msgbox gText_Fuschia_GuessCry6_1 MSG_KEEPOPEN
	waitcry
	closeonkeypress
	hidepokepic
	msgbox gText_Fuschia_GuessCry6 MSG_NORMAL
	goto StartPokemonThree
	end

StartPokemonThree:
	msgbox gText_Fuschia_DotDotDot MSG_KEEPOPEN
	fadeoutbgm 0x1
	pause 0x1
	cry SPECIES_GALLADE 0x0
	waitcry
	closeonkeypress
	msgbox gText_Fuschia_WhichOne MSG_NORMAL
	fadeinbgm 0x1
	pause 0x1
	special 0x12C
	waitstate
	loadpointer 0x0 gText_Gallade
	special 0x12D
	compare LASTRESULT 0x0
	if equal _goto PokemonFour
	call checkiffunny
	sound 0x1A
	msgbox gText_Fuschia_GuessCry4 MSG_KEEPOPEN @if we got here that means we guessed incorrect
	checksound
	closeonkeypress
	goto TryAgainThree
	end

PokemonFour:
	showpokepic SPECIES_GALLADE 0x0A 0x03
	cry SPECIES_GALLADE 0x0
	msgbox gText_Fuschia_GuessCry7_1 MSG_KEEPOPEN
	waitcry
	closeonkeypress
	hidepokepic
	msgbox gText_Fuschia_GuessCry7 MSG_NORMAL
	goto StartPokemonFour
	end

StartPokemonFour:
	msgbox gText_Fuschia_DotDotDot MSG_KEEPOPEN
	fadeoutbgm 0x1
	pause 0x1
	cry SPECIES_KOMALA 0x0
	waitcry
	closeonkeypress
	msgbox gText_Fuschia_WhichOne MSG_NORMAL
	fadeinbgm 0x1
	pause 0x1
	special 0x12C
	waitstate
	loadpointer 0x0 gText_Komala
	special 0x12D
	compare LASTRESULT 0x0
	if equal _goto GotThemCorrect 
	call checkiffunny
	sound 0x1A
	msgbox gText_Fuschia_GuessCry4 MSG_KEEPOPEN @if we got here that means we guessed incorrect
	checksound
	closeonkeypress
	goto TryAgainFour
	end

GotThemCorrect:
	showpokepic SPECIES_KOMALA 0x0A 0x03
	cry SPECIES_KOMALA 0x0
	msgbox gText_Fuschia_GuessCryFinal MSG_KEEPOPEN
	waitcry
	closeonkeypress
	hidepokepic
YouGotItLol:
	msgbox gText_Fuschia_YouGotIt MSG_NORMAL
	setflag	0x104D
	clearflag FLAG_DONT_RANDOMIZE
	goto TeachMove2
	end

TryAgain:
	msgbox gText_FuschiaGuessCry5 MSG_YESNO
	compare LASTRESULT NO
	if equal _goto TryAgainNextTime
	return

TryAgainOne:
	call TryAgain
	goto PokemonOne

TryAgainTwo:
	call TryAgain
	goto StartPokemonTwo

TryAgainThree:
	call TryAgain
	goto StartPokemonThree

TryAgainFour:
	call TryAgain
	goto StartPokemonFour

TryAgainNextTime:
	clearflag FLAG_DONT_RANDOMIZE
	fadeinbgm 0x1
	msgbox gText_TryAgainNextTime MSG_NORMAL
	release
	end

TeachMove2:
    msgbox gText_Fuschia_Egg2 MSG_YESNO
    compare LASTRESULT 0x0
    if 0x1 _goto Cancel1
    msgbox gText_Fuschia_Egg3 MSG_NORMAL
    call Teach
    msgbox gText_Fuschia_EggWhichMove MSG_NORMAL
    call TeachMoves
    textcolor 0x3
    msgbox gText_Fuschia_Egg4 MSG_NORMAL
    clearflag 0x917
    release
    end

NeedScale:
    msgbox gText_Fuschia_Egg1 MSG_NORMAL
    release
    end

Teach:
    setflag 0x917
    special 0xDB
    waitstate
    compare 0x8004 0x6
    if 0x4 _goto Cancel1
    special 0x148 @check if its an egg
    compare LASTRESULT 0x1
    if 0x1 _goto CancelNo3
    compare 0x8005 0x0
    if 0x1 _goto CancelNo
    return

TeachMoves:
    special 0xE0
    waitstate
    compare 0x8004 0x0
    if 0x1 _goto Cancel1
    return

Cancel1:
    clearflag 0x917
    msgbox gText_Fuschia_EggNo MSG_NORMAL
    release
    end

CancelNo:
    clearflag 0x917
    msgbox gText_Fuschia_EggNo2 MSG_NORMAL
    release
    end

CancelNo3:
    clearflag 0x917
    msgbox gText_Fuschia_EggNo3 MSG_NORMAL
    release
    end


.global EventScript_Fuschia_DoubleBattle
EventScript_Fuschia_DoubleBattle:
    lock
    faceplayer 
    checkflag 0x910
    if 0x1 _goto TurnOff
    msgbox gText_FuschiaDouble1 MSG_YESNO 
    compare LASTRESULT 0x1
    if NO _goto CancelThis
    setflag 0x910
    msgbox gText_FuschiaDouble2 MSG_NORMAL
	@ msgbox gText_FuschiaDoubleOof MSG_FACE 
    release 
    end 

TurnOff:
    msgbox gText_FuschiaDouble3 MSG_YESNO
    compare LASTRESULT YES 
    if NO _goto CancelThis
    clearflag 0x910
    msgbox gText_FuschiaDouble4 MSG_NORMAL 
    release 
    end 

CancelThis:
    msgbox gText_FuschiaDouble5 MSG_NORMAL 
    release 
    end 

.global EventScript_substitute_Start
EventScript_substitute_Start:
	textcolor 0x0
    lock 
    faceplayer 
	checkflag 0x2C8
	if 0x1 _goto EventScript_substitute_Done
	msgbox gText_substitute_3 0x5
	compare LASTRESULT 0x1
	if 0x1 _call EventScript_substitute_Take
	msgbox gText_substitute_6 0x6
	release
	end

EventScript_substitute_Take:
	msgbox gText_substitute_4 0x6
	giveitem ITEM_TM90 0x1 MSG_OBTAIN
	setflag 0x2C8
	msgbox gText_substitute_5 0x6
	release
	end

EventScript_substitute_Done:
	msgbox gText_substitute_5 0x6
	release
	end

.global EventScript_brendanfuschia_Start
EventScript_brendanfuschia_Start:
	call SetFollowerToFollowScript
	clearflag 0x200
	opendoor 0x18 0x5
	waitdooranim 
	showsprite 0x11
	applymovement 0xFF EventScript_brendanfuschia_Movedown
	waitmovement 0x0
	applymovement 0xFF EventScript_brendanfuschia_Lookup
	waitmovement 0x0
	applymovement 0x11 EventScript_brendanfuschia_Movedown
	waitmovement 0x0
	closedoor 0x18 0x5
	waitdooranim
	textcolor 0x00
	msgbox gText_brendanfuschia_1 0x6
	setflag 0x200
    setflag 0x90E 
	setflag 0x926 
	trainerbattle3 0x3 0x39 0x0 gText_brendanfuschia_Defeat
	msgbox gText_brendanfuschia_2 0x6
	giveitem ITEM_HM06 0x1 MSG_OBTAIN @Rock smash 
	msgbox gText_brendanfuschia_3 0x6
	setvar 0x5043 0x1
	applymovement 0x11 EventScript_brendanfuschia_Movedown2
	waitmovement 0x0
	hidesprite 0x11
	setflag 0x200
	checkflag 0x103F
	if 0x1 _call GetMaxPPUps
	release
	end

GetMaxPPUps:
	msgbox gText_CarePackageFind MSG_NORMAL
	giveitem ITEM_PP_MAX 0x99 MSG_OBTAIN
	return

EventScript_brendanfuschia_Movedown:
.byte 0x10
.byte 0xFE

EventScript_brendanfuschia_Lookup:
.byte walk_down
.byte walk_up
.byte 0xFE

EventScript_brendanfuschia_Movedown2:
.byte 0x12
.byte 0x10
.byte 0x10
.byte 0x10
.byte 0x12
.byte 0x12
.byte 0x10
.byte 0x10
.byte 0x10
.byte 0x10
.byte walk_left
.byte walk_left
.byte walk_left
.byte walk_left
.byte walk_left
.byte 0xFE

.global EventScript_nursegivemedicine_Start
EventScript_nursegivemedicine_Start:
	lock
	faceplayer
	checkitem ITEM_MEDICINE 0x1 @check if player has medicine
	compare 0x800D 0x1
	if 0x4 _goto EventScript_nursegivemedicine_Thankyou
	msgbox gText_nursegivemedicine_3 0x6
	checkflag 0x947
	if 0x1 _goto EventScript_nursegivemedicine_Better
	checkflag 0x945
	if 0x1 _goto EventScript_nursegivemedicine_Givemedicine
	setflag 0x944
	release
	end

EventScript_nursegivemedicine_Givemedicine:
	msgbox gText_nursegivemedicine_4 0x6
	giveitem ITEM_MEDICINE 0x1 MSG_OBTAIN
	msgbox gText_nursegivemedicine_5 0x6
	release
	end

EventScript_nursegivemedicine_Thankyou:
	msgbox gText_nursegivemedicine_5 0x6
	release
	end

EventScript_nursegivemedicine_Better:
	msgbox gText_nursegivemedicine_6 0x6
	release
	end

.global EventScript_earthpower_start
EventScript_earthpower_start:
	lock
	faceplayer
	textcolor 0x0
	checkflag 0x986
	if 0x1 _goto EventScript_earthpowerstart2
	msgbox gText_earthpower MSG_YESNO @"Make foes shudder with the\nforce ..."
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_earthpower_NahNoHide
	msgbox gText_earthpower_Which MSG_NORMAL @"Which Pok�mon should I teach\nEart..."
	setvar 0x8005 0x2F
	call teach
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_earthpower_NahNoHide
	setflag 0x986
	msgbox gText_earthpower_gogetem MSG_NORMAL @"Go get em bud."
	release
	end

EventScript_earthpowerstart2:
	showmoney 0x0 0x0 0x0
	msgbox gText_earthpower MSG_FACE @"Make foes shudder with the\nforce ..."
	msgbox gText_earthpower_Cost MSG_YESNO @"It@ll cost [$]10000 now."
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_earthpower_No
	checkmoney 0x2710 0x0
	compare LASTRESULT 0x1
	if 0x0 _goto EventScript_earthpower_NoMoney
	msgbox gText_earthpower_Which MSG_NORMAL @"Which Pok�mon should I teach\nEart..."
	hidemoney 0x0 0x0
	setvar 0x8005 0x2F
	call teach
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_earthpower_NahNoHide
	showmoney 0x0 0x0 0x0
	msgbox gText_earthpower_dot MSG_NORMAL @"[.]"
	removemoney 0x2710 0x0
	sound 0x58
	updatemoney 0x0 0x0 0x0
	msgbox gText_earthpower_gogetem MSG_NORMAL @"Go get em bud."
	checksound
	hidemoney 0x0 0x0
	release
	end

EventScript_earthpower_NahNoHide:
	msgbox gText_earthpower_essential MSG_NORMAL @"No?\pIt@s an essential move."
	release
	end

	@---------------
teach:
	special 0x18D
	waitstate
	return

	@---------------
EventScript_earthpower_No:
	hidemoney 0x0 0x0
	msgbox gText_earthpower_essential MSG_NORMAL @"No?\pIt@s an essential move."
	release
	end

	@---------------
EventScript_earthpower_NoMoney:
	msgbox gText_earthpower_notenough MSG_NORMAL @"[.]You don@t have enough money."
	hidemoney 0x0 0x0
	release
	end

.global EventScript_koga_Start
EventScript_koga_Start:
	lock
	faceplayer
	checkflag 0x824
	if 0x1 _goto EventScript_koga_Defeated
	setflag 0x915
	special 0x0
	checkflag FLAG_HARDCORE_MODE
	if 0x1 _call SetTailwind
	trainerbattle1 0x1 0x1A2 0x0 gText_koga_EncounterText gText_koga_DefeatText EventScript_koga_WonPointer
	release
	end

SetTailwind:
	setvar VAR_BATTLE_AURAS VAR_BATTLE_TAILWIND_STRING
	return

EventScript_koga_Defeated:
	lock
	faceplayer
	checkflag 0x964
	if 0x1 _goto EventScript_koga_Done
	checkflag FLAG_MINIMAL_GRINDING_MODE
	if 0x1 _goto MinGrindingModePerfectPkmn
	msgbox gText_koga_Perfectpokemon 0x6
	bufferfirstpokemon 0x00
	msgbox gText_koga_Thepokemon 0x6
	setvar 0x8003 0x0 @From party
	setvar 0x8004 0x0 @1st Pokemon
	setvar 0x8005 0x3 @check speed EVs
	special2 LASTRESULT 0x7
	buffernumber 0x0 LASTRESULT @Buffer speed EVs to [buffer1]
	compare LASTRESULT 150
	if 0x4 _goto EventScript_koga_Veryfast
	msgbox gText_koga_Notquite 0x6
	release
	end

MinGrindingModePerfectPkmn:
	msgbox gText_koga_PerfectpokemonMinimal 0x6
	bufferfirstpokemon 0x00
	msgbox gText_koga_Thepokemon 0x6
	setvar 0x8003 0x0 @From party
	setvar 0x8004 0x0 @1st Pokemon
	callasm CheckIfKogaApproves + 1
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_koga_Veryfast
	msgbox gText_koga_Notquite 0x6
	release
	end

EventScript_koga_WonPointer:
	msgbox gText_koga_TMInfomsg 0x6
	giveitem ITEM_TM36 0x1 MSG_OBTAIN @sludge bomb
	settrainerflag 0x126
	settrainerflag 0x127
	settrainerflag 0x120
	settrainerflag 0x121
	settrainerflag 0x124
	settrainerflag 0x125
	setflag 0x824
	clearflag 0x915
	msgbox gText_koga_Givetm 0x6
	msgbox gText_koga_Helloagain 0x6
	checkflag FLAG_MINIMAL_GRINDING_MODE
	if 0x1 _goto WonPointerMinGrindingMode 
	msgbox gText_koga_Perfectpokemon 0x6
	release
	end

WonPointerMinGrindingMode:
	msgbox gText_koga_PerfectpokemonMinimal 0x6
	release
	end

EventScript_koga_Done:
	msgbox gText_koga_Donemsg 0x6
	release
	end

EventScript_koga_Veryfast:
	msgbox gText_koga_Perfect 0x6
	giveitem ITEM_TOXTRICITITE 0x1 MSG_OBTAIN 
	msgbox gText_koga_Charmmsg 0x6
	giveitem ITEM_LIFE_ORB 0x1 MSG_OBTAIN @Life Orb
	setflag 0x964
	release
	end

.global EventScript_Fuschia_SandacondaBattle
EventScript_Fuschia_SandacondaBattle:
	checkflag 0x102F
	if 0x1 _goto SandacondaDone
	lock
	faceplayer
	applymovement 0x800F FacePlayer
	waitmovement 0x0
	msgbox gText_Fuschia_Sandaconda1 MSG_YESNO 
	compare LASTRESULT NO
	if equal _goto SandacondaReject
	msgbox gText_Fuschia_Sandaconda2 MSG_FACE
	setflag 0x90E
	special 0x0
	trainerbattle3 0x3 0xF 0x0 gText_Fuschia_SandacondaDefeat
	applymovement 0x800F FacePlayer
	waitmovement 0x0
	msgbox gText_Fuschia_Sandaconda3 MSG_FACE
	giveitem ITEM_SANDACONDITE 0x1 MSG_OBTAIN
	msgbox gText_Fuschia_Sandaconda4 MSG_FACE
	giveitem ITEM_POWER_HERB 0x1 MSG_OBTAIN
	faceplayer 
	setflag 0x102F
	goto SandacondaDone
	end

SandacondaDone:
	msgbox gText_Fuschia_Sandaconda5 MSG_FACE
	release
	end

SandacondaReject:
	msgbox gText_Fuschia_SandacondaReject MSG_FACE
	release
	end

FacePlayer:
	.byte face_player
	.byte end_m

EventScript_Hardcoremode_CheckifDoneRematches:
	goto CheckIfRematchesDone
	end

SetVarCheck: 
	setvar 0x511A 0x1
	release
	end

CheckIfRematchesDone:
	checkflag 0x959 @Pewter 
	if 0x0 _goto Closed
	checkflag 0x932 @Cerulean
	if 0x0 _goto Closed
	checkflag 0x934 @Vermilion
	if 0x0 _goto Closed
	goto SetVarCheck
	end

Closed:
	applymovement 0xFF FaceForward
	waitmovement 0x0 
	msgbox gText_Fuschia_Closed MSG_SIGN
	applymovement 0xFF GoBackward
	waitmovement 0x0
	release
	end

FaceForward:
	.byte look_up
	.byte end_m

GoBackward: 
	.byte walk_down
	.byte end_m

.global EventScript_Fuschia_CarePackage
EventScript_Fuschia_CarePackage:
	checkflag 0x103F
	if 0x1 _call FuschiaCarePackage
	release
	setvar 0x5126 0x1 
	end

FuschiaCarePackage:
	applymovement 0xFF StayInPLace
	waitmovement 0x0
	checkflag FLAG_HARDCORE_MODE
	if 0x0 _call GiveDampRock
	call GiveOtherCareItems
	return
	release
	end

StayInPLace:
	.byte lock_facing
	.byte end_m


GiveDampRock:
	giveitem ITEM_DAMP_ROCK 0xA MSG_OBTAIN
	giveitem ITEM_ICY_ROCK 0xA MSG_OBTAIN
	giveitem ITEM_GRASSY_SEED 0xA MSG_OBTAIN
	return

GiveOtherCareItems:
	giveitem ITEM_HEART_SCALE 0xA MSG_OBTAIN
	giveitem ITEM_KINGS_ROCK 0xA MSG_OBTAIN
	giveitem ITEM_LIECHI_BERRY 0xA MSG_OBTAIN
	giveitem ITEM_METAL_POWDER 0xA MSG_OBTAIN
	giveitem ITEM_PETAYA_BERRY 0xA MSG_OBTAIN
	giveitem ITEM_PINK_NECTAR 0xA MSG_OBTAIN
	giveitem ITEM_SALAC_BERRY 0xA MSG_OBTAIN
	giveitem ITEM_YELLOW_NECTAR 0xA MSG_OBTAIN
	return


.global EventScript_SafariZoneCarePackage
EventScript_SafariZoneCarePackage:
	msgbox gText_Safari_WhereMyBf MSG_FACE 
	checkflag 0x103F
	if 0x1 _goto GiveCareSafariPackage
	end


GiveCareSafariPackage:
	checkflag 0x1041
	if 0x1 _goto Nothing
	msgbox gText_Safari_WouldveGaveToErik MSG_FACE
	giveitem ITEM_DEEP_SEA_SCALE 0xA MSG_OBTAIN
	giveitem ITEM_EXPERT_BELT 0xA MSG_OBTAIN
	giveitem ITEM_LUCKY_PUNCH 0xA MSG_OBTAIN
	checkflag FLAG_HARDCORE_MODE
	if 0x0 _call GiveSmooth
Nothing:
	release
	end

GiveSmooth:
	giveitem ITEM_SMOOTH_ROCK 0xA MSG_OBTAIN
	return

.global EventScript_Fuschia_Dracovish
EventScript_Fuschia_Dracovish:
	setvar 0x8004 SPECIES_DRACOVISH
	special 0x163
	showpokepic SPECIES_DRACOVISH 0xA 0x3
	msgbox gText_Fuschia_Dracovish MSG_KEEPOPEN 
	hidepokepic
	releaseall
	end

.global EventScript_Fuschia_Milotic
EventScript_Fuschia_Milotic:
	setvar 0x8004 SPECIES_MILOTIC
	special 0x163
	showpokepic SPECIES_MILOTIC 0xA 0x3
	msgbox gText_Fuschia_Milotic MSG_KEEPOPEN 
	hidepokepic
	releaseall
	end

.global EventScript_Fuschia_Slowbro
EventScript_Fuschia_Slowbro:
	setvar 0x8004 SPECIES_SLOWBRO
	special 0x163
	showpokepic SPECIES_SLOWBRO 0xA 0x3
	msgbox gText_Fuschia_Slowbro MSG_KEEPOPEN 
	hidepokepic
	releaseall
	end

.global EventScript_Fuschia_GuyZoo
EventScript_Fuschia_GuyZoo:
	msgbox gText_Fuschia_GuyZoo1 MSG_FACE 
	release
	end



.global gMapScripts_FuschiaCity
gMapScripts_FuschiaCity:
	mapscript MAP_SCRIPT_ON_TRANSITION HideSprite_FuschiaSeviianEgg
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScripts_FuschiaPokemonCenter
    .byte MAP_SCRIPT_TERMIN

HideSprite_FuschiaSeviianEgg:
	sethealingplace 0x8
	release
	end
	

LevelScripts_FuschiaPokemonCenter:
    levelscript 0x5149, 0, LevelScript_FuschiaCitySeviianEgg
    .hword MAP_SCRIPT_TERMIN

LevelScript_FuschiaCitySeviianEgg:
	setvar 0x5149 0x1
	applymovement 0x6 LookLeft
	waitmovement 0x0
	pause 0x5
	sound 0x15
	applymovement 0x6 Exclaim
	waitmovement 0x0
	checksound
	msgbox gText_FuschiaSeviiEgg_1 MSG_KEEPOPEN
	closeonkeypress
	applymovement 0x6 WalkToYou
	waitmovement 0x0 
	applymovement 0xFF FaceRight
	waitmovement 0x0
	msgbox gText_FuschiaSeviiEgg_2 MSG_NORMAL
	special2 LASTRESULT 0x83
    compare LASTRESULT 0x6
    if notequal _goto ReceiveEgg  @if we have a slot open 
	msgbox gText_FuschiaSeviiEgg_3 MSG_NORMAL
	applymovement 0x6 WalkBack
	waitmovement 0x0
	release
	end

FaceRight:
	.byte look_right
	.byte end_m

ReceiveEgg:
	callasm GiveSeviianEgg2
	msgbox gText_Celadon_ReceivedEgg MSG_KEEPOPEN
	fanfare 0x13E
	waitfanfare
	closeonkeypress
	msgbox gText_FuschiaSeviiEgg_4 MSG_NORMAL
	applymovement 0xFF MakeRoom
	applymovement 0x6 Leave
	waitmovement 0x0
	sound 0x9
	checksound
	hidesprite 0x6
	setflag 0x10A0
	release
	end

LookLeft:
	.byte look_left
	.byte end_m

Exclaim: 
	.byte exclaim
	.byte end_m

WalkToYou:
	.byte walk_left
	.byte walk_left
	.byte walk_left
	.byte end_m

WalkBack:
	.byte walk_right
	.byte walk_right
	.byte walk_right
	.byte look_up
	.byte end_m

Leave:
	.byte walk_left
	.byte look_down
	.byte end_m

MakeRoom:
	.byte walk_up
	.byte look_down
	.byte end_m

LookUp:
	.byte look_up
	.byte end_m

.global EventScript_FuschiaCitySeviianEgg
EventScript_FuschiaCitySeviianEgg:
	lock
	faceplayer
	msgbox gText_FuschiaSeviiEgg_5 MSG_NORMAL
	special2 LASTRESULT 0x83
    compare LASTRESULT 0x6
    if notequal _goto ReceiveEgg2  @if we have a slot open 
	msgbox gText_FuschiaSeviiEgg_6 MSG_NORMAL
	applymovement 0x6 LookUp
	waitmovement 0x0
	release
	end

ReceiveEgg2:
	msgbox gText_FuschiaSeviiEgg_7 MSG_NORMAL
	callasm GiveSeviianEgg2
	msgbox gText_Celadon_ReceivedEgg MSG_KEEPOPEN
	fanfare 0x13E
	waitfanfare
	closeonkeypress
	msgbox gText_FuschiaSeviiEgg_4 MSG_NORMAL
	fadescreen 0x1
	hidesprite 0x6
	sound 0x9
	checksound
	fadescreen 0x0
	setflag 0x10A0
	release
	end
	