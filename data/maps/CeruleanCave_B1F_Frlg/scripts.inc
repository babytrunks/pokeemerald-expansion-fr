CeruleanCave_B1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CeruleanCave_B1F_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCave_B1F_OnTransition
	.byte 0

CeruleanCave_B1F_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, CeruleanCave_B1F_EventScript_TryRemoveMewtwo
	end

.global EventScript_ceruleangiovanni_Start
EventScript_ceruleangiovanni_Start:
	lockall
	fadeoutbgm 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0x0
	applymovement LOCALID_CERULEAN_CAVE_GIOVANNI, Common_Movement_FaceDown 
	waitmovement 0x0
	msgbox gText_ceruleangiovanni_1
	applymovement LOCALID_CERULEAN_CAVE_GIOVANNI, Common_Movement_FaceUp
	waitmovement 0x0
	msgbox gText_ceruleangiovanni_2
	applymovement LOCALID_CERULEAN_CAVE_GIOVANNI, EventScript_ceruleangiovanni_Goup
	waitmovement 0x0
	playsong 0x156 0x0
	msgbox gText_ceruleangiovanni_3
	cry 0x96 0x2
	msgbox gText_ceruleangiovanni_4
	waitcry
	sound 0x36
	msgbox gText_ceruleangiovanni_5
	hidesprite 0x3 @mewtwo
	setflag 0x81
	clearflag 0x200
	showsprite 0x10 @pokeball
	checksound
	sound 0x31
	checksound
	msgbox gText_ceruleangiovanni_6
	sound 0x31
	checksound
	sound 0x10
	checksound
	fadeoutbgm 0x3
	msgbox gText_ceruleangiovanni_7
	applymovement LOCALID_CERULEAN_CAVE_GIOVANNI, EventScript_ceruleangiovanni_Lookdown
	msgbox gText_ceruleangiovanni_8
	msgbox gText_ceruleangiovanni_8_2 MSG_KEEPOPEN
	closeonkeypress 
	setflag 0x200 @pokeball and lance 
	sound 0xB3
	applymovement 0xFF Confused  
	applymovement LOCALID_CERULEAN_CAVE_GIOVANNI, Confused 
	waitmovement 0x0 
	checksound 
	fadescreen 0x1 
	sound 0x97
	checksound 
	showsprite 0x13
	fadescreen 0x0
	fadeinbgm 0x2 
	@ applymovement 0x13 Lance_Comeup 
	@ waitmovement 0x0 
	sound 0x15
	applymovement LOCALID_CERULEAN_CAVE_GIOVANNI, Exclamation 
	waitmovement 0x0 
	checksound 
	msgbox gText_ceruleangiovanni_8_3 MSG_NORMAL 
	msgbox gText_ceruleangiovanni_8_4 MSG_NORMAL
	applymovement 0x13 EventScript_ceruleangiovanni_Lookleft
	applymovement 0xFF EventScript_ceruleangiovanni_Lookright
	waitmovement 0x0 
	msgbox gText_ceruleangiovanni_8_5 MSG_NORMAL
	applymovement 0x13 EventScript_ceruleangiovanni_Lookup
	applymovement 0xFF EventScript_ceruleangiovanni_Lookup
	waitmovement 0x0 
	msgbox gText_ceruleangiovanni_8_6 MSG_NORMAL
	goto StartSelectPokemon
	end

LookUp:
	.byte look_up
	.byte end_m

StartSelectPokemon:
	special 0x27
	special 0xF5
	waitstate
    compare LASTRESULT NO
	if equal _goto StartSelectPokemon
	special 0x28
	setflag FLAG_TAG_BATTLE 
	checkflag FLAG_HARDCORE_MODE
	if 0x1 _call SetTerrain
	setvar VAR_PARTNER 0x27 @Lance partner 
	setvar VAR_PARTNER_BACKSPRITE @Lance Backsprite 
	clearflag 0x81 @mewtwo
	special 0x0
	setflag 0x915 @disable bag
	setflag FLAG_TRANSFORM_BATTLE
	trainerbattle3 0x3 0x45 0x0 gText_ceruleangiovanni_Defeated
	fadeoutbgm 0x1
	msgbox gText_ceruleangiovanni_9 0x4
	closeonkeypress
	msgbox gText_ceruleangiovanni_Awaydialogue
	applymovement LOCALID_CERULEAN_CAVE_GIOVANNI, EventScript_ceruleangiovanni_Lookleft
	waitmovement 0x0
	msgbox gText_ceruleangiovanni_10
	applymovement LOCALID_CERULEAN_CAVE_GIOVANNI, EventScript_ceruleangiovanni_Lookright
	waitmovement 0x0
	msgbox gText_ceruleangiovanni_11
	clearflag 0x980
	clearflag 0x981
	showsprite 0x11
	showsprite 0x12
	applymovement 0x11 EventScript_ceruleangiovanni_Comeup @ariana
	applymovement 0x12 EventScript_ceruleangiovanni_Comeup @archer
	waitmovement 0x0
	msgbox gText_ceruleangiovanni_12
	sound 0x15
	applymovement LOCALID_CERULEAN_CAVE_GIOVANNI, EventScript_ceruleangiovanni_Surprised
	checksound
	waitmovement 0x0
	applymovement 0x13 EventScript_ceruleangiovanni_Lookdown
	waitmovement 0x0 
	applymovement LOCALID_CERULEAN_CAVE_GIOVANNI, EventScript_ceruleangiovanni_Lookdown
	msgbox gText_ceruleangiovanni_13
	applymovement 0x12 EventScript_ceruleangiovanni_Movealil
	waitmovement 0x0
	msgbox gText_ceruleangiovanni_14
	applymovement 0x11 EventScript_ceruleangiovanni_Movealil
	waitmovement 0x0
	msgbox gText_ceruleangiovanni_15
	msgbox gText_ceruleangiovanni_16
	msgbox gText_ceruleangiovanni_17
	sound 0xA
	applymovement 0x12 EventScript_ceruleangiovanni_Jumpup @jump
	checksound
	waitmovement 0x0
	msgbox gText_ceruleangiovanni_18
	applymovement 0x11 EventScript_ceruleangiovanni_Movealil
	waitmovement 0x0
	msgbox gText_ceruleangiovanni_19
	msgbox gText_ceruleangiovanni_20
	applymovement LOCALID_CERULEAN_CAVE_GIOVANNI, EventScript_ceruleangiovanni_Lookup
	waitmovement 0x0
	msgbox gText_ceruleangiovanni_21
	setvar 0x5053 0x1
	setvar 0x5054 0x1
	applymovement LOCALID_CERULEAN_CAVE_GIOVANNI, EventScript_ceruleangiovanni_Lookdown
	waitmovement 0x0
	msgbox gText_ceruleangiovanni_22
	fadeinbgm 0x1
	sound 0x35
	hidesprite 0x10 @hidepokeball, mewtwo reappear
	showsprite 0x3
	checksound
	applymovement LOCALID_CERULEAN_CAVE_GIOVANNI, EventScript_ceruleangiovanni_Lookup
	applymovement 0x13 EventScript_ceruleangiovanni_Lookup
	waitmovement 0x0
	sound 0x15
	applymovement LOCALID_CERULEAN_CAVE_GIOVANNI, EventScript_ceruleangiovanni_Surprised2
	applymovement 0xFF EventScript_ceruleangiovanni_Surprised2
	applymovement 0x11 EventScript_ceruleangiovanni_Surprised2
	applymovement 0x12 EventScript_ceruleangiovanni_Surprised2
	applymovement 0x13 EventScript_ceruleangiovanni_Surprised2
	checksound
	waitmovement 0x0
	setflag 0x980
	setflag 0x981
	setflag 0x982 @defeated giovanni
	clearflag 0x920 @this for the level script about to ensue
	clearflag 0x976 @same as above
	clearflag 0x977 @same as above
	msgbox gText_ceruleangiovanni_23
	cry 0x96 0x2
	msgbox gText_ceruleangiovanni_24
	waitcry
	setvar 0x8004 0x8
	setvar 0x8005 0x8
	setvar 0x8006 0x8
	setvar 0x8007 0x8
	special 0x136
	clearflag 0x200 
	pause 0x50
	warp 0x3 0x16 0x3 0x0 0x0
	end


CeruleanCave_B1F_EventScript_TryRemoveMewtwo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

CeruleanCave_B1F_OnTransition::
	call_if_unset FLAG_FOUGHT_MEWTWO, CeruleanCave_B1F_EventScript_ShowMewtwo
	end

CeruleanCave_B1F_EventScript_ShowMewtwo::
	clearflag FLAG_HIDE_MEWTWO
	return

CeruleanCave_B1F_EventScript_Mewtwo::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
	message CeruleanCave_B1F_Text_Mew
	waitmessage
	waitmoncry
	delay 20
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, 0
	waitbuttonpress
	setwildbattle SPECIES_MEWTWO, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CeruleanCave_B1F_EventScript_DefeatedMewtwo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CeruleanCave_B1F_EventScript_RanFromMewtwo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CeruleanCave_B1F_EventScript_RanFromMewtwo
	setflag FLAG_FOUGHT_MEWTWO
	release
	end

CeruleanCave_B1F_EventScript_DefeatedMewtwo::
	setflag FLAG_FOUGHT_MEWTWO
	goto EventScript_RemoveStaticMon
	end

CeruleanCave_B1F_EventScript_RanFromMewtwo::
	setvar VAR_0x8004, SPECIES_MEWTWO
	goto EventScript_MonFlewAway
	end

CeruleanCave_B1F_Text_Mew::
    .string "Mew!$"

