.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s" 

.equ VAR_GMOLTRES_DAILY, 0x5116
.equ VAR_LORELEI_FORECAST, 0x513E

.global EventScript_closecombat_Start
EventScript_closecombat_Start:
	lock
	faceplayer
	textcolor 0x0
	checkflag 0x987 @flag here
	if 0x1 _goto EventScript_closecombat_Cost
	msgbox gText_closecombat_1 0x5
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_closecombat_Cancel
	msgbox gText_closecombat_3 0x6
	setvar 0x8005 0x78 @change here
	call EventScript_closecombat_Teach
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_closecombat_Cancel
	setflag 0x987 @flag here
	msgbox gText_closecombat_4 0x6
	release
	end

EventScript_closecombat_Teach:
	special 0x18D
	waitstate
	return

EventScript_closecombat_Cost:
	showmoney 0x00 0x00 0x00
	msgbox gText_closecombat_1 0x6
	msgbox gText_closecombat_2 0x5
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_closecombat_Cancelhide
	checkmoney 0x2710 0x00 @money here
	compare 0x800D 0x1
	if 0x0 _goto EventScript_closecombat_Nomoney
	msgbox gText_closecombat_3 0x6
	hidemoney 0x00 0x00
	setvar 0x8005 0x78 @change this
	call EventScript_closecombat_Teach
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_closecombat_Cancel
	showmoney 0x00 0x00 0x00
	msgbox gText_closecombat_Wait 0x6
	removemoney 0x2710 0x00 @money here
	sound 0x58
	updatemoney 0x00 0x00 0x00
	msgbox gText_closecombat_4 0x6
	checksound
	hidemoney 0x0 0x0
	release
	end

EventScript_closecombat_Cancel:
	msgbox gText_closecombat_No 0x6
	release
	end

EventScript_closecombat_Cancelhide:
	hidemoney 0x00 0x00
	msgbox gText_closecombat_No 0x6
	release
	end

EventScript_closecombat_Nomoney:
	msgbox gText_closecombat_Poor 0x6
	hidemoney 0x00 0x00
	release
	end

.global EventScript_PokemonLeagueChick
EventScript_PokemonLeagueChick:
	checkflag 0x82C
	if 0x1 _goto DoneWGame
	msgbox gText_ShitsHard1 MSG_FACE 
	release 
	end 

DoneWGame:
	msgbox gText_ShitsHard2 MSG_FACE 
	release 
	end 

Moveback2:
    release 
    end

.global EventScript_VictoryRoad_Moltres
EventScript_VictoryRoad_Moltres:
    lock
    faceplayer
    cry 0x92 0x2
    preparemsg gText_VictoryRoad_Moltres1 
    waitmsg
    waitcry
    pause 0xA
    playsong 0x156 0x0
    waitkeypress
    wildbattle 0x92 0x46 0x00
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x4
    if 0x1 _goto Moveback2
    fadescreen 0x1
    hidesprite 0x800F
    setflag 0x99B
	setvar 0x8000 VAR_GMOLTRES_DAILY
    setvar 0x8001 0x0
    special 0xA1
    fadescreen 0x0
    release
    end

.global EventScript_VictoryRoad_GalarMoltres
EventScript_VictoryRoad_GalarMoltres:
    lock
    faceplayer
    cry SPECIES_MOLTRES 0x2
    preparemsg gText_PowerPlant_Zapdos1 
    waitmsg
    waitcry
    pause 0xA
    playsong 0x156 0x0
    waitkeypress
    wildbattle SPECIES_MOLTRES_G 0x46 0x00
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x4
    if 0x1 _goto Moveback2
    fadescreen 0x1
    hidesprite 0x800F
    setflag 0x102A
	setflag 0x102B
    fadescreen 0x0
    release
    end

.global gMapScripts_VictoryRoad
gMapScripts_VictoryRoad:
    mapscript MAP_SCRIPT_ON_TRANSITION HideGMoltresIfNotReady
	mapscript MAP_SCRIPT_ON_LOAD SetUpPuzzleBlocksFloor2
    .byte MAP_SCRIPT_TERMIN

.global gMapScripts_VictoryRoad1
gMapScripts_VictoryRoad1:
	mapscript MAP_SCRIPT_ON_LOAD SetUpPuzzleBlocksFloor1
	.byte MAP_SCRIPT_TERMIN

.global gMapScripts_VictoryRoad3
gMapScripts_VictoryRoad3:
	mapscript MAP_SCRIPT_ON_LOAD SetUpPuzzleBlocksFloor3
	.byte MAP_SCRIPT_TERMIN

HideGMoltresIfNotReady:
	checkflag 0x99B
	if 0x0 _goto HideGMoltres
	checkflag 0x102B
	if 0x1 _goto HideGMoltres
	setvar 0x8000 VAR_GMOLTRES_DAILY
    setvar 0x8001 0x0
    special2 LASTRESULT 0xA0
    compare LASTRESULT 0x0 
    if equal _goto HideGMoltres
	clearflag 0x102A
	showsprite 0x10
	end 

HideGMoltres:
	hidesprite 0x10
	setflag 0x102A
	end

.global EventScript_AllGen8_Mons
EventScript_AllGen8_Mons:
	lock
	faceplayer
	givepokemon SPECIES_SPECTRIER 0x23 0x0 0x0 0x0 0x0
	givepokemon SPECIES_GLASTRIER 0x23 0x0 0x0 0x0 0x0
	givepokemon SPECIES_DRACOVISH 0x23 0x0 0x0 0x0 0x0
	givepokemon SPECIES_ARCTOVISH 0x23 0x0 0x0 0x0 0x0
	givepokemon SPECIES_ARCTOZOLT 0x23 0x0 0x0 0x0 0x0
	end

.global EventScript_MeadowPlate
EventScript_MeadowPlate:
	lock
	faceplayer
	setflag 0x1032
	end

SetUpPuzzleBlocksFloor2:
	compare 0x4065 0x64
	if 0x5 _call SetBlock1
	@ compare 0x4065 0x64
	@ if 0x1 _call ClearBlock1
	compare 0x4066 0x64
	if 0x5 _call 0x8160FC2
	@ ompare 0x4066 0x64
	@ if 0x1 _call ClearBlock2
	end

SetBlock1:
	setmaptile 0xD 0xA 0x307 0x1
	setmaptile 0xD 0xB 0x317 0x1
	return

SetBlock2:
	setmaptile 0x21 0x10 0x307 0x1
	setmaptile 0x21 0x11 0x317 0x1
	return

ClearBlock1:
	setmaptile 0xD 0xA 0x281 0x0
	setmaptile 0xD 0xB 0x281 0x0
	movesprite2 0xB 0x2 0x13
	return

ClearBlock2:
	setmaptile 0x21 0x10 0x281 0x0
	setmaptile 0x21 0x11 0x281 0x0
	movesprite2 0xC 0xE 0x13
	return

.global EventScript_Setvar_5054
EventScript_Setvar_5054:
	lock
	faceplayer
	msgbox gText_brendanbattleleft_6 MSG_NORMAL
	cleartrainerflag 0x1E5
	cleartrainerflag 0x7E
	cleartrainerflag 0x1E2
	warp 0x1 20 0x0 0x0 0x0
	@ clearflag 0x269
	@ clearflag 0x26A
	@ clearflag 0x26B
	@ cleartrainerflag 0xD7
	@ cleartrainerflag 0xB3
	@ cleartrainerflag 0xB4
	release
	end

Peepee:
	msgbox gText_Viridian_LassRepel1_2 MSG_NORMAL
	release
	end

SetUpPuzzleBlocksFloor1:
	compare 0x4064 0x64
	if 0x1 _call ClearBlockFloor1
	compare 0x4064 0x64
	if 0x5 _call SetBlockFloor1 
	end

ClearBlockFloor1:
	setmaptile 0xC 0xE 0x2D1 0x0
	setmaptile 0xC 0xF 0x2E1 0x0
	movesprite2 0x5 0x14 0x10
	return

SetBlockFloor1:
	setmaptile 0xC 0xE 0x307 0x1
	setmaptile 0xC 0xF 0x317 0x1
	return

SetUpPuzzleBlocksFloor3:
	compare 0x4067 0x64
	if 0x5 _call SetBlockFloor3
	compare 0x4067 0x64
	if 0x1 _call ClearBlockFloor3
	end

SetBlockFloor3:
	setmaptile 0xC 0xC 0x307 0x1
	setmaptile 0xC 0xD 0x317 0x1
	return

ClearBlockFloor3:
	movesprite2 0xA 0x7 0x7
	return

.equ FORECAST_HAIL, 0x0
.equ FORECAST_RAIN, 0x1

.global EventScript_EliteFour_LoreleiForecast
EventScript_EliteFour_LoreleiForecast:
	msgbox gText_EliteFour_LoreleiForecast1 MSG_FACE 
	checkflag 0x82c
	if SET _goto AlreadyAmChampion
	compare VAR_LORELEI_FORECAST FORECAST_HAIL
	if equal _goto LoreleiHasHail
	compare VAR_LORELEI_FORECAST FORECAST_RAIN
	if equal _goto LoreleiHasRain
	end

LoreleiHasRain:
	msgbox gText_EliteFour_LoreleiForecastRain MSG_FACE
	release
	end

LoreleiHasHail:
	msgbox gText_EliteFour_LoreleiForecastHail MSG_FACE
	release
	end

AlreadyAmChampion:
	msgbox gText_EliteFour_LoreleiForecast2 MSG_NORMAL
	release
	end
