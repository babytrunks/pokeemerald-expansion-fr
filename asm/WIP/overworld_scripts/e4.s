.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ VAR_TERRAIN, 0x5000
.equ VAR_WEATHER, 0x5118
.equ WEATHER_HAIL, 3 
.equ WEATHER_HEAVY_RAIN, 6
.equ FLAG_HARDCORE_MODE, 0x1034
.equ VAR_BATTLE_AURAS, 0x5119
.equ AURA_SHADOWTAG_STRING, 24 
.equ AURA_ICE_DEFENSE_STRING, 7
.equ PERMA_TRICK_ROOM_STRING, 2
.equ AURA_SOLIDROCK_STRING, 4
.equ MISTY_TERRAIN, 3
.equ PSYCHIC_TERRAIN, 4
.equ AURA_CANT_HAZARD_CONTROL_STRING, 8
.equ AURA_STATUSMIST_STRING, 25
.equ LEVEL_SCRIPT_PKMN_LEAGUE, 0x513D
.equ VAR_LORELEI_FORECAST, 0x513E

@ .equ AURA_RAINBOW_STRING, 23

.global gMapScripts_Lance
gMapScripts_Lance:
    mapscript MAP_SCRIPT_ON_RESUME LanceCallspecial
    mapscript MAP_SCRIPT_ON_LOAD 0x816294D
	mapscript MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE SpriteFace
	mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScripts_Lance
    .byte MAP_SCRIPT_TERMIN

LanceCallspecial:
	setvar 0x8004 0x3
	special 0x1A1
	setflag 0x926
	end

SpriteFace:
	spriteface 0xFF 0x2
	end

LevelScripts_Lance:
	levelscript 0x4068, 3, 0x8162987
	.hword MAP_SCRIPT_TERMIN

.global gMapScripts_Champion
gMapScripts_Champion:
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScripts_Champion
    mapscript MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE Hof_LevelScriptsFace
	mapscript MAP_SCRIPT_ON_RESUME Champion_CheckTrainerBattle
    .byte MAP_SCRIPT_TERMIN

.global gMapScripts_HallOfFame
gMapScripts_HallOfFame:
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScripts_HallOfFame
    mapscript MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE Hof_LevelScriptsFace
    .byte MAP_SCRIPT_TERMIN

LevelScripts_HallOfFame:
    levelscript 0x4001, 0, LevelScript_HallOfFame
    .hword MAP_SCRIPT_TERMIN

LevelScripts_Champion:
	levelscript 0x4001, 0, LevelScript_Champion

Hof_LevelScriptsFace:
	levelscript 0x4001, 0, Hof_LevelScriptFace
	.hword MAP_SCRIPT_TERMIN

Champion_CheckTrainerBattle:
	goto 0x8162AF2
	end

.global EventScript_lorelei_Start
EventScript_lorelei_Start:
	lock
	faceplayer
	@ setflag FLAG_SMALL_TRAINER_LEVELS
	setvar 0x8004 0x9
	setvar 0x8005 0x2
	special 0x174
	checkflag 0x4B8
	if 0x1 _goto EventScript_lorelei_Defeat
	special 0x0
	setvar 0x8004 0x9
	setvar 0x8005 0x0
	special 0x173
	setvar 0x8004 0x9
	setvar 0x8005 0x1
	special 0x173
	callasm CheckViableMons + 1
	compare LASTRESULT YES
	if equal _call SetPlaceholderPartner
	checkflag 0x82C
	if 0x0 _call EventScript_lorelei_Firstmatch
	checkflag 0x82C
	if 0x1 _call EventScript_lorelei_Rematch
	setflag 0x3
	setflag 0x5
	checkflag 0x82C
	if 0x0 _goto EventScript_lorelei_Firstbattle
	checkflag 0x82C
	if 0x1 _goto EventScript_lorelei_Rematchbattle
	end

SetPlaceholderPartner:
	setflag 0x908
	setvar 0x5011 0x1 
	setvar 0x5012 0x8
	return 

EventScript_lorelei_Defeat:
	msgbox gText_lorelei_Postbattlemsg MSG_KEEPOPEN @"You@re better than I thought.\nGo ..."
	release
	end

EventScript_lorelei_Firstmatch:
	msgbox gText_lorelei_Firstmsg MSG_KEEPOPEN @"Welcome to the POK�MON LEAGUE.\pI ..."
	return

EventScript_lorelei_Rematch:
	msgbox gText_lorelei_Rematchmsg MSG_KEEPOPEN @"Welcome to the POK�MON LEAGUE.\pI,..."
	return

EventScript_lorelei_Firstbattle:
	setflag 0x915
	compare VAR_LORELEI_FORECAST 0x0
	if equal _goto EventScript_lorelei_Option1
	goto EventScript_lorelei_Option2
	end

EventScript_lorelei_Option1:
	checkflag FLAG_HARDCORE_MODE
	if 0x1 _call SetHail
	trainerbattle3 0x3 0x4D 0x0 gText_lorelei_Defeatmsg
	goto EventScript_lorelei_End
	end 

EventScript_lorelei_Option2:
	checkflag FLAG_HARDCORE_MODE
	if 0x1 _call SetHeavyRain
	trainerbattle3 0x3 0x4E 0x0 gText_lorelei_Defeatmsg
	goto EventScript_lorelei_End
	end 

SetHeavyRain:
	setvar VAR_WEATHER WEATHER_HEAVY_RAIN
	@ setvar VAR_BATTLE_AURAS, AURA_STATUSMIST_STRING
	return

SetHail:
	setvar VAR_WEATHER WEATHER_HAIL
	@ setvar VAR_BATTLE_AURAS, AURA_STATUSMIST_STRING
	@ setvar VAR_BATTLE_AURAS AURA_ICE_DEFENSE_STRING
	return

EventScript_lorelei_Rematchbattle:
	setflag 0x915
	setflag 0x90E
	random 0x2
	compare 0x800D 0x0
	if 0x1 _goto EventScript_lorelei_Option1
	compare 0x800D 0x1
	if 0x1 _goto EventScript_lorelei_Option2
	end 

EventScript_lorelei_End:
	clearflag 0x5
	setflag 0x4B8
	call EventScript_lorelei_Moveshit
	msgbox gText_lorelei_Postbattlemsg MSG_KEEPOPEN @"You@re better than I thought.\nGo ..."
    msgbox gText_LetMeHeal MSG_YESNO 
    compare LASTRESULT NO 
    if equal _goto EndThis 
    special 0x0
	fadescreen 0x1
	sound 0x1
	checksound
	fadescreen 0x0
	release
	end

EndThis:
    release 
    end 

EventScript_lorelei_Moveshit:
	applymovement 0x800F EventScript_lorelei_Movement
	waitmovement 0x0
	sound 0x8
	call EventScript_lorelei_Tiles
	special 0x8E
	setflag 0x4
	return

EventScript_lorelei_Tiles:
	setmaptile 0x6 0x1 0x28E 0x1
	setmaptile 0x6 0x2 0x296 0x0
	return

EventScript_lorelei_Movement:
.byte 0x1C
.byte 0x1C
.byte 0xFE

.global EventScript_bruno_Start
EventScript_bruno_Start:
	lock
	faceplayer
	@ setflag FLAG_SMALL_TRAINER_LEVELS
	setvar 0x8004 0xA
	setvar 0x8005 0x2
	special 0x174
	checkflag 0x4B9
	if 0x1 _goto EventScript_bruno_Postdefeat
	setvar 0x8004 0xA
	setvar 0x8005 0x0
	special 0x173
	setvar 0x8004 0xA
	setvar 0x8005 0x1
	special 0x173
	msgbox gText_bruno_Prebattlemsg MSG_KEEPOPEN
	setflag 0x3
	setflag 0x5
	checkflag 0x82C
	if 0x0 _goto EventScript_bruno_Firstbattle
	checkflag 0x82C
	if 0x1 _goto EventScript_bruno_Rematch
	end


	@---------------
EventScript_bruno_Postdefeat:
	msgbox gText_bruno_Postdefeatmsg MSG_KEEPOPEN @"My job is done.\nGo face your next..."
	closeonkeypress
	compare PLAYERFACING 0x2
	if 0x1 _call EventScript_bruno_2
	compare PLAYERFACING 0x1
	if 0x1 _call EventScript_bruno_1
	compare PLAYERFACING 0x3
	if 0x1 _call EventScript_bruno_3
	compare PLAYERFACING 0x4
	if 0x1 _call EventScript_bruno_3
	release
	end

EventScript_bruno_Firstbattle:
	setflag 0x915
	checkflag FLAG_HARDCORE_MODE
	if 0x1 _call SetBrunoAura
	random 0x2
	compare 0x800D 0x0
	if 0x1 _goto EventScript_bruno_Option1
	compare 0x800D 0x1
	if 0x1 _goto EventScript_bruno_Option2
	end

SetBrunoAura:
	@ setvar VAR_BATTLE_AURAS AURA_SOLIDROCK_STRING
	setvar VAR_TERRAIN MISTY_TERRAIN
	return

EventScript_bruno_Option1:
	trainerbattle3 0x3 0x50 0x0 gText_bruno_Defeatmsg
	goto EventScript_bruno_End
	end

EventScript_bruno_Option2:
	trainerbattle3 0x3 0x51 0x0 gText_bruno_Defeatmsg
	goto EventScript_bruno_End
	end

EventScript_bruno_Rematch:
	setflag 0x915
	setflag 0x90E
	goto EventScript_bruno_Firstbattle
	@ random 0x3
	@ compare 0x800D 0x0
	@ if 0x1 _goto EventScript_bruno_Option4
	@ compare 0x800D 0x1
	@ if 0x1 _goto EventScript_bruno_Option5
	@ compare 0x800D 0x2
	@ if 0x1 _goto EventScript_bruno_Option6
	end

EventScript_bruno_Option4:
	trainerbattle3 0x3 0x1E 0x0 gText_bruno_Defeatmsg
	goto EventScript_bruno_End
	end

EventScript_bruno_Option5:
	trainerbattle3 0x3 0x1F 0x0 gText_bruno_Defeatmsg
	goto EventScript_bruno_End
	end

EventScript_bruno_Option6:
	trainerbattle3 0x3 0x20 0x0 gText_bruno_Defeatmsg
	goto EventScript_bruno_End
	end

	@---------------
EventScript_bruno_End:
	clearflag 0x5
	setflag 0x4B9
	call EventScript_bruno_Moveshit
	msgbox gText_bruno_Postdefeatmsg MSG_KEEPOPEN @"My job is done.\nGo face your next..."
	closeonkeypress
    msgbox gText_LetMeHeal MSG_YESNO 
    compare LASTRESULT NO 
    if equal _goto EndThis 
    special 0x0
	fadescreen 0x1
	sound 0x1
	checksound
	fadescreen 0x0
	compare PLAYERFACING 0x2
	if 0x1 _call EventScript_bruno_2
	compare PLAYERFACING 0x1
	if 0x1 _call EventScript_bruno_1
	compare PLAYERFACING 0x3
	if 0x1 _call EventScript_bruno_3
	compare PLAYERFACING 0x4
	if 0x1 _call EventScript_bruno_3
	release
	end

	@---------------
EventScript_bruno_2:
	applymovement 0x1 EventScript_bruno_Move2
	waitmovement 0x0
	return

	@---------------
EventScript_bruno_1:
	applymovement 0x1 EventScript_bruno_Move1
	waitmovement 0x0
	return

	@---------------
EventScript_bruno_3:
	applymovement 0x1 EventScript_bruno_Move3
	waitmovement 0x0
	return

	@---------------
EventScript_bruno_Moveshit:
	applymovement 0x800F EventScript_bruno_Delay
	waitmovement 0x0
	sound 0x8
	call EventScript_bruno_Tileshit
	special 0x8E
	setflag 0x4
	return

	@---------------
EventScript_bruno_Tileshit:
	setmaptile 0x6 0x1 0x28E 0x1
	setmaptile 0x6 0x2 0x296 0x0
	return


	@---------
	@ Strings
	@---------




	@-----------
	@ Movements
	@-----------
EventScript_bruno_Move2:
.byte 0x30
.byte 0xFE

EventScript_bruno_Move1:
.byte 0x2F
.byte 0xFE

EventScript_bruno_Move3:
.byte 0x2D
.byte 0xFE

EventScript_bruno_Delay:
.byte 0x1C
.byte 0x1C
.byte 0xFE

.global EventScript_agatha_Start
EventScript_agatha_Start:
	lock
	faceplayer
	@ setflag FLAG_SMALL_TRAINER_LEVELS
	setvar 0x8004 0xB
	setvar 0x8005 0x2
	special 0x174
	checkflag 0x4BA
	if 0x1 _goto EventScript_agatha_Afterdefeat
	setvar 0x8004 0xB
	setvar 0x8005 0x0
	special 0x173
	setvar 0x8004 0xB
	setvar 0x8005 0x4
	special 0x173
	setvar 0x8004 0x0
	setvar 0x8005 0x4
	special 0x173
	msgbox gText_agatha_Prebattlemsg 0x6
	setflag 0x3
	setflag 0x5
	checkflag 0x82C
	if 0x0 _goto EventScript_agatha_Firstbattle
	checkflag 0x82C
	if 0x1 _goto EventScript_agatha_Rematch
	end

	@---------------
EventScript_agatha_Afterdefeat:
	msgbox gText_agatha_Postdefeatmsg MSG_KEEPOPEN @"You win!\pI see what the old duff ..."
	release
	end

	@---------------
EventScript_agatha_Firstbattle:
	setflag 0x915
	checkflag FLAG_HARDCORE_MODE
	if 0x1 _call SetAgathaAura
	random 0x2
	compare 0x800D 0x0
	if 0x1 _goto EventScript_agatha_Option1
	compare 0x800D 0x1
	if 0x1 _goto EventScript_agatha_Option2
	end

SetAgathaAura:
	@ setvar VAR_BATTLE_AURAS AURA_SHADOWTAG_STRING
	setvar VAR_TERRAIN PSYCHIC_TERRAIN
	return

EventScript_agatha_Option1:
	trainerbattle3 0x3 0x53 0x0 gText_agatha_Defeatmsg
	goto EventScript_agatha_End
	end

EventScript_agatha_Option2:
	trainerbattle3 0x3 0x54 0x0 gText_agatha_Defeatmsg
	goto EventScript_agatha_End
	end

	@---------------
EventScript_agatha_Rematch:
	setflag 0x915
	setflag 0x90E
	goto EventScript_agatha_Firstbattle
	@ random 0x3
	@ compare 0x800D 0x0
	@ if 0x1 _goto EventScript_agatha_Option4
	@ compare 0x800D 0x1
	@ if 0x1 _goto EventScript_agatha_Option5
	@ compare 0x800D 0x2
	@ if 0x1 _goto EventScript_agatha_Option6
	end

EventScript_agatha_Option4:
	trainerbattle3 0x3 0x21 0x0 gText_agatha_Defeatmsg
	goto EventScript_agatha_End
	end

EventScript_agatha_Option5:
	trainerbattle3 0x3 0x22 0x0 gText_agatha_Defeatmsg
	goto EventScript_agatha_End
	end

EventScript_agatha_Option6:
	trainerbattle3 0x3 0x23 0x0 gText_agatha_Defeatmsg
	goto EventScript_agatha_End
	end

	@---------------
EventScript_agatha_End:
	clearflag 0x5
	setflag 0x4BA
	call EventScript_agatha_Endstuff
	msgbox gText_agatha_Postdefeatmsg MSG_KEEPOPEN @"You win!\pI see what the old duff ..."
    msgbox gText_LetMeHeal MSG_YESNO 
    compare LASTRESULT NO 
    if equal _goto EndThis 
    special 0x0
	fadescreen 0x1
	sound 0x1
	checksound
	fadescreen 0x0
	release
	end

	@---------------
EventScript_agatha_Endstuff:
	applymovement 0x800F EventScript_agatha_Delay
	waitmovement 0x0
	sound 0x8
	call EventScript_agatha_Tileshit
	special 0x8E
	setflag 0x4
	return

	@---------------
EventScript_agatha_Tileshit:
	setmaptile 0x6 0x1 0x28E 0x1
	setmaptile 0x6 0x2 0x296 0x0
	return

EventScript_agatha_Delay:
.byte 0x1C
.byte 0x1C
.byte 0xFE

.global EventScript_lance_Start
EventScript_lance_Start:
	lock
	faceplayer
	@ setflag FLAG_SMALL_TRAINER_LEVELS
	setvar 0x8004 0xC
	setvar 0x8005 0x2
	special 0x174
	checkflag 0x4BB
	if 0x1 _goto EventScript_lance_Postdefeat
	setvar 0x8004 0xC
	setvar 0x8005 0x0
	special 0x173
	setvar 0x8004 0xC
	setvar 0x8005 0x1
	special 0x173
	checkflag 0x82C
	if 0x0 _call EventScript_lance_Prebattle
	checkflag 0x82C
	if 0x1 _call EventScript_lance_Prebattle2
	setflag 0x3
	setflag 0x5
	checkflag 0x82C
	if 0x0 _goto EventScript_lance_Firstbattle
	checkflag 0x82C
	if 0x1 _goto EventScript_lance_Rematch
	end

	@---------------
EventScript_lance_Postdefeat:
	msgbox gText_lance_Postdefeatmsg MSG_KEEPOPEN @"I still can@t believe my dragons\n..."
	release
	end

	@---------------
EventScript_lance_Prebattle:
	msgbox gText_lance_Prebattlemsg MSG_KEEPOPEN @"Ah! I@ve heard about you,\n[player..."
	return

	@---------------
EventScript_lance_Prebattle2:
	msgbox gText_lance_Prebattlemsg2 MSG_KEEPOPEN @"Ah!\nSo, you@ve returned, [player]..."
	return

	@---------------
EventScript_lance_Firstbattle:
	setflag 0x915
	checkflag FLAG_HARDCORE_MODE
	if 0x1 _call SetLance
	random 0x2
	compare 0x800D 0x0
	if 0x1 _goto EventScript_lance_Option1
	compare 0x800D 0x1
	if 0x1 _goto EventScript_lance_Option2
	end

SetLance:
	setvar VAR_BATTLE_AURAS AURA_CANT_HAZARD_CONTROL_STRING
	return

EventScript_lance_Option1:
	trainerbattle3 0x3 0x56 0x0 gText_lance_Defeatmsg
	goto EventScript_lance_End
	end

EventScript_lance_Option2:
	trainerbattle3 0x3 0x57 0x0 gText_lance_Defeatmsg
	goto EventScript_lance_End
	end

	@---------------
EventScript_lance_Rematch:
	setflag 0x915
	setflag 0x90E 
	goto EventScript_lance_Firstbattle
	@ random 0x3
	@ compare 0x800D 0x0
	@ if 0x1 _goto EventScript_lance_Option4
	@ compare 0x800D 0x1
	@ if 0x1 _goto EventScript_lance_Option5
	@ compare 0x800D 0x2
	@ if 0x1 _goto EventScript_lance_Option6
	end

EventScript_lance_Option4:
	trainerbattle3 0x3 0x24 0x0 gText_lance_Defeatmsg
	goto EventScript_lance_End
	end

EventScript_lance_Option5:
	trainerbattle3 0x3 0x25 0x0 gText_lance_Defeatmsg
	goto EventScript_lance_End
	end

EventScript_lance_Option6:
	trainerbattle3 0x3 0x26 0x0 gText_lance_Defeatmsg
	goto EventScript_lance_End
	end


	@---------------
EventScript_lance_End:
	clearflag 0x5
	setvar 0x8004 0x0
	special 0xAA
	setflag 0x4BB
	call EventScript_lance_Tileshit
	msgbox gText_lance_Postdefeatmsg MSG_KEEPOPEN @"I still can@t believe my dragons\n..."
	closeonkeypress
    msgbox gText_LetMeHeal MSG_YESNO 
    compare LASTRESULT NO 
    if equal _goto EndThis 
    special 0x0
	fadescreen 0x1
	sound 0x1
	checksound
	fadescreen 0x0
	release
	end

	@---------------
EventScript_lance_Tileshit:
	applymovement 0x800F EventScript_lance_Delay
	waitmovement 0x0
	sound 0x8
	setmaptile 0x6 0x4 0x28E 0x1
	setmaptile 0x6 0x5 0x296 0x0
	special 0x8E
	setflag 0x4
	return

EventScript_lance_Delay:
.byte 0x1C
.byte 0x1C
.byte 0xFE


.global EventScript_E4nurse_Start
EventScript_E4nurse_Start:
	lock
	faceplayer
	special 0x0
	fadescreen 0x1
	sound 0x1
	checksound
	fadescreen 0x0
	msgbox gText_E4nurse_1 0x6 
	copyvar 0x5129 0x512A 
	release
	end

.global EventScript_E4LanceInfo_Start
EventScript_E4LanceInfo_Start:
	setvar 0x8004 0xC
	setvar 0x8005 0x5
	special 0x173
	msgbox gText_E4LanceInfo MSG_FACE 
	release 
	end 

.global EventScript_TileProcScale
EventScript_TileProcScale:
	checkflag 0x82C
	if 0x1 _call SetScaleFlag
	release
	end

SetScaleFlag:
	setflag 0x90E
	return

	@---------------
LevelScript_HallOfFame:
	lockall
	textcolor 0x0
	@ setflag FLAG_SMALL_TRAINER_LEVELS
	applymovement 0xFF EventScript_hof_MoveUp
	waitmovement 0x0
	applymovement 0x1 Movementone
	applymovement 0xFF Movementtwo
	waitmovement 0x0
	pause 0x12
	@ callasm SetStringForHof
	msgbox gText_hof_Oaktalk MSG_KEEPOPEN @"Oak: Er-hem!\nCongratulations, [pl..."
	closeonkeypress
	applymovement 0x1 EventScript_hof_FaceUp
	applymovement 0xFF EventScript_hof_FaceUp
	waitmovement 0x0
	pause 0x14
	doanimation 0x3E
	waitanimation 0x3E
	pause 0x28
	setvar 0x4001 0x1
	call EventScript_hof_Scriptnum2
	sethealingplace 0x1
	@ fadescreendelay 0x1 0x18
	fadescreen 0x1 
	special 0x110
	waitstate
	releaseall
	end

	@---------------
EventScript_hof_Scriptnum2:
	clearflag 0x9D
	call EventScript_hof_Scriptnum3
	special 0xA9
	special2 LASTRESULT 0x193
	compare LASTRESULT 0x0
	if 0x1 _call EventScript_hof_Setvarthingy
	call EventScript_hof_Clearflags
	return

	@---------------
EventScript_hof_Scriptnum3:
	clearflag 0x4B8
	clearflag 0x4B9
	clearflag 0x4BA
	clearflag 0x4BB
	clearflag 0x4BC
	cleartrainerflag 0x1B6
	cleartrainerflag 0x1B7
	cleartrainerflag 0x1B8
	cleartrainerflag 0x2E3
	cleartrainerflag 0x2E4
	cleartrainerflag 0x2E5
	setvar 0x4068 0x0
	return

	@---------------
EventScript_hof_Setvarthingy:
	setvar 0x4050 0x2
	return

	@---------------
EventScript_hof_Clearflags:
	clearflag 0x2F5
	clearflag 0x2F6
	clearflag 0x2F7
	return


	@---------
	@ Strings
	@---------


	@-----------
	@ Movements
EventScript_hof_MoveUp:
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0xFE

Movementone:
	.byte 0x2F
	.byte 0xFE

Movementtwo:
.byte 0x30
.byte 0xFE

EventScript_hof_FaceUp:
.byte 0x2E
.byte 0xFE

Hof_LevelScriptFace:
	spriteface 0xFF 0x2
	end

LevelScript_Champion:
	lockall
	textcolor 0x0
	setflag 0x2
	applymovement 0xFF EventScript_champion_StepUp
	waitmovement 0x0
	pause 0x14
	setflag 0x926
	checkflag 0x82C
	if 0x0 _call EventScript_champion_FirstMsg
	checkflag 0x82C
	if 0x1 _call EventScript_champion_SecondMsg
	special 0x187
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_champion_Callsomething
	setflag 0x3
	setflag 0x5
	playsong2 0x138
	@ checkflag FLAG_HARDCORE_MODE
	@ if 0x1 _call SetChampionAura
	checkflag 0x82C
	if 0x0 _call EventScript_champion_SetBattle
	checkflag 0x82C
	if 0x1 _goto EventScript_champion_SetRematchBattle
EndChampionGary:
	setflag 0x4
	clearflag 0x5
	setflag 0x4BC
	setflag 0x4
	msgbox gText_champion_LossMsgWhy MSG_KEEPOPEN @"Why?\nWhy did I lose?\pI never mad..."
	playsong 0x159 0x0
	showsprite 0x2
	msgbox gText_champion_OakPlayer MSG_KEEPOPEN @"Oak: [player]!"
	closeonkeypress
	applymovement 0xFF EventScript_champion_MovementsTwo
	applymovement 0x1 EventScript_champion_DelayMovement
	applymovement 0x2 EventScript_champion_StepUp2
	waitmovement 0x0
	pause 0x19
	special2 LASTRESULT 0x162
	bufferpokemon 0x0 LASTRESULT
	msgbox gText_champion_SoYouWon MSG_KEEPOPEN @"Oak: So, you@ve won!\nSincerely, c..."
	applymovement 0x2 EventScript_champion_MovementsThree
	applymovement 0x1 EventScript_champion_MovementsFour
	waitmovement 0x0
	msgbox gText_champion_OakDisappointed MSG_KEEPOPEN @"Oak: [rival][.]\nI@m disappointed ..."
	closeonkeypress
	applymovement 0x2 EventScript_champion_MovementsFive
	waitmovement 0x0
	pause 0x14
	msgbox gText_champion_OakURChampion MSG_KEEPOPEN @"Oak: [player].\pYou understand tha..."
	closeonkeypress
	pause 0xD
	applymovement 0x2 EventScript_champion_MovementsSix
	applymovement 0xFF EventScript_champion_MovementsSeven
	waitmovement 0x0
	setvar 0x4001 0x1
	warp 0x1 0x50 0xFF 0x5 0xC
	waitstate
	releaseall
	end

SetChampionAura:
	setvar VAR_BATTLE_AURAS, AURA_STATUSMIST_STRING
	return

EventScript_champion_FirstMsg:
	checkflag FLAG_HARDCORE_MODE
	if 0x1 _call EventScript_champion_FirstMsgHardcore
	checkflag FLAG_HARDCORE_MODE
	if 0x0 _call EventScript_champion_FirstMsgNormal
	return

EventScript_champion_FirstMsgHardcore:
	msgbox gText_champion_FirstMsgTxtHardcore MSG_KEEPOPEN @"[rival]: Hey, [player]!\pI was loo..."
	return

EventScript_champion_FirstMsgNormal:
	msgbox gText_champion_FirstMsgTxt MSG_KEEPOPEN @"[rival]: Hey, [player]!\pI was loo..."
	return

EventScript_champion_SecondMsg:
	checkflag FLAG_HARDCORE_MODE
	if 0x1 _call EventScript_champion_SecondMsgHardcore
	checkflag FLAG_HARDCORE_MODE
	if 0x0 _call EventScript_champion_SecondMsgNormal
	return

EventScript_champion_SecondMsgHardcore:
	msgbox gText_champion_SecondMsgTextHardcore MSG_KEEPOPEN @"[rival]: Hey, [player]!\pYou came ..."
	return

EventScript_champion_SecondMsgNormal:
	msgbox gText_champion_SecondMsgText MSG_KEEPOPEN @"[rival]: Hey, [player]!\pYou came ..."
	return

EventScript_champion_Callsomething:
	call EventScript_champion_SetVar
	releaseall
	end


EventScript_champion_SetBattle:
	compare 0x4031 0x2
	if 0x1 _call EventScript_champion_BattleOne
	compare 0x4031 0x1
	if 0x1 _call EventScript_champion_BattleTwo
	compare 0x4031 0x0
	if 0x1 _call EventScript_champion_BattleThree
	return

EventScript_champion_SetRematchBattle:
	random 0x3
	compare 0x800D 0x0
	if 0x1 _goto EventScript_champion_BattleRematchOne
	compare 0x800D 0x1
	if 0x1 _goto EventScript_champion_BattleRematchTwo
	compare 0x800D 0x2
	if 0x1 _goto EventScript_champion_BattleRematchThree
	return

	@---------------
EventScript_champion_SetVar:
	setvar 0x4001 0x1
	return

	@---------------
EventScript_champion_BattleOne:
	trainerbattle3 0x3 0x1B6 0x0 gText_champion_LossMsg
	return

	@---------------
EventScript_champion_BattleTwo:
	trainerbattle3 0x3 0x1B7 0x0 gText_champion_LossMsg
	return

	@---------------
EventScript_champion_BattleThree:
	trainerbattle3 0x3 0x1B8 0x0 gText_champion_LossMsg
	return

EventScript_champion_BattleRematchOne:
	trainerbattle3 0x3 0x1B6 0x0 gText_champion_LossMsg
	goto EndChampionGary

EventScript_champion_BattleRematchTwo:
	trainerbattle3 0x3 0x1B7 0x0 gText_champion_LossMsg
	goto EndChampionGary
EventScript_champion_BattleRematchThree:
	trainerbattle3 0x3 0x1B8 0x0 gText_champion_LossMsg
	goto EndChampionGary
	@-----------
	@ Movements
	@-----------
EventScript_champion_StepUp:
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0xFE

EventScript_champion_MovementsTwo:
.byte 0x1B
.byte 0x2D
.byte 0x1C
.byte 0x1C
.byte 0x1C
.byte 0x1C
.byte 0x1C
.byte 0x1C
.byte 0x1C
.byte 0x2F
.byte 0xFE

EventScript_champion_DelayMovement:
.byte 0x1C
.byte 0x1C
.byte 0x1C
.byte 0x1C
.byte 0x1C
.byte 0x1C
.byte 0x1C
.byte 0x1C
.byte 0x1C
.byte 0x2F
.byte 0xFE

EventScript_champion_StepUp2:
.byte 0x1C
.byte 0x1C
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0x12
.byte 0x11
.byte 0x11
.byte 0x2D
.byte 0x1C
.byte 0xFE

EventScript_champion_MovementsThree:
.byte 0x30
.byte 0xFE

EventScript_champion_MovementsFour:
.byte 0x2F
.byte 0xFE

EventScript_champion_MovementsFive:
.byte 0x2D
.byte 0xFE

EventScript_champion_MovementsSix:
.byte 0x11
.byte 0x11
.byte 0x13
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0x1B
.byte 0x60
.byte 0xFE

EventScript_champion_MovementsSeven:
.byte 0x1C
.byte 0x12
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0x13
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0x1B
.byte 0x60
.byte 0xFE



.global gMapScripts_PokemonLeague
gMapScripts_PokemonLeague:
    @ mapscript MAP_SCRIPT_ON_RESUME 0x81BC05C
	mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScriptsPokemonLeague
	mapscript MAP_SCRIPT_ON_TRANSITION MapEntryScript_PkmnLeague
    .byte MAP_SCRIPT_TERMIN

MapEntryScript_PkmnLeague:
	sethealingplace 0xA
    end 

LevelScriptsPokemonLeague:
	levelscript LEVEL_SCRIPT_PKMN_LEAGUE, 0, LevelScriptPokemonLeague
	.byte MAP_SCRIPT_TERMIN

LevelScriptPokemonLeague:
	lockall
	random 0x2
	compare 0x800D 0x0
	if 0x1 _goto SetVarHail
	compare 0x800D 0x1 
	if 0x1 _goto SetVarRain
	releaseall
	end

SetVarHail:
	setvar VAR_LORELEI_FORECAST 0x0
	setvar LEVEL_SCRIPT_PKMN_LEAGUE 0x1
	releaseall
	end

SetVarRain:
	setvar VAR_LORELEI_FORECAST 0x1
	setvar LEVEL_SCRIPT_PKMN_LEAGUE 0x1
	releaseall
	end
