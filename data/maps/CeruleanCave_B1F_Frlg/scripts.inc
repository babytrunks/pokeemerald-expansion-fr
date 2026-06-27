CeruleanCave_B1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CeruleanCave_B1F_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCave_B1F_OnTransition
	.byte 0

CeruleanCave_B1F_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, CeruleanCave_B1F_EventScript_TryRemoveMewtwo
	end

EventScript_ceruleangiovanni_Start_Left::
	applymovement LOCALID_PLAYER, CeruleanCave_Movement_WalkUpLeft
	waitmovement 0
	goto EventScript_ceruleangiovanni_Start

EventScript_ceruleangiovanni_Start_Right::
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	goto EventScript_ceruleangiovanni_Start

EventScript_ceruleangiovanni_Start::
	lockall
	fadeoutbgm 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_CERULEAN_CAVE_GIOVANNI, Common_Movement_FaceDown 
	waitmovement 0
	setspeaker SP_NAME_GIOVANNI
	msgbox gText_ceruleangiovanni_1
	applymovement LOCALID_CERULEAN_CAVE_GIOVANNI, Common_Movement_FaceUp
	waitmovement 0
	setspeaker SP_NAME_GIOVANNI
	msgbox gText_ceruleangiovanni_2
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, 0
	setspeaker SP_NAME_GIOVANNI
	msgbox gText_ceruleangiovanni_3
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
	msgbox gText_ceruleangiovanni_4
	waitmoncry
	playse SE_BALL_OPEN
	setspeaker SP_NAME_GIOVANNI

	msgbox gText_ceruleangiovanni_5
	removeobject LOCALID_CERULEAN_CAVE_MEWTWO 
	addobject LOCALID_CERULEAN_CAVE_MEWTWO_POKEBALL
	waitse
	playse SE_BALL_BOUNCE_1
	waitse
	msgbox gText_ceruleangiovanni_6
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_1
	waitse
	fadeoutbgm 0
	setspeaker SP_NAME_GIOVANNI
	msgbox gText_ceruleangiovanni_7
	applymovement LOCALID_CERULEAN_CAVE_GIOVANNI, Common_Movement_FaceDown
	waitmovement 0
	setspeaker SP_NAME_GIOVANNI
	msgbox gText_ceruleangiovanni_8
	setspeaker SP_NAME_UNKNOWN
	msgbox gText_ceruleangiovanni_8_2
	applymovement LOCALID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	waitbuttonpress
	playse SE_M_METRONOME
	applymovement LOCALID_PLAYER, Common_Movement_QuestionMark  
	applymovement LOCALID_CERULEAN_CAVE_GIOVANNI, Common_Movement_QuestionMark 
	waitmovement 0 
	waitse 
	fadescreen 0x1 
	playse SE_M_FLY
	waitse 
	addobject LOCALID_CERULEAN_CAVE_LANCE
	fadescreen 0
	fadeinbgm 0x2 
	playse SE_PIN
	applymovement LOCALID_CERULEAN_CAVE_GIOVANNI, Common_Movement_ExclamationMark
	waitmovement 0 
	waitse 
	setspeaker SP_NAME_LANCE
	msgbox gText_ceruleangiovanni_8_3  
	setspeaker SP_NAME_GIOVANNI
	msgbox gText_ceruleangiovanni_8_4 
	applymovement LOCALID_CERULEAN_CAVE_LANCE, Common_Movement_FaceRight
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0 
	setspeaker SP_NAME_LANCE
	msgbox gText_ceruleangiovanni_8_5 
	applymovement LOCALID_CERULEAN_CAVE_LANCE, Common_Movement_FaceUp
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0 
	setspeaker SP_NAME_GIOVANNI
	msgbox gText_ceruleangiovanni_8_6 
	goto CeruleanCave_EventScript_StartSelectPokemon
	end

CeruleanCave_Movement_WalkUpLeft::
	walk_up
	walk_right
	face_up
	step_end

CeruleanCave_EventScript_StartSelectPokemon:
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, 0
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_eq VAR_RESULT, 0, CeruleanCave_EventScript_StartSelectPokemon
	@ special 0x28
	multi_2_vs_1 TRAINER_SILPH_CO_ARCHER, SilphCo_11F_Text_ArcherDefeat, PARTNER_CERULEAN_CAVE_LANCE
	setflag FLAG_DEFEATED_GIOVANNI_CERULEAN_CAVE
	setvar VAR_TRIGGER_CERULEAN_CAVE_GIOVANNI, 1
	msgbox gText_ceruleangiovanni_9
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
	waitmoncry
	removeobject LOCALID_CERULEAN_CAVE_MEWTWO_POKEBALL
	addobject LOCALID_CERULEAN_CAVE_MEWTWO
	playse SE_BALL_OPEN
	waitse
	setspeaker SP_NAME_GIOVANNI
	msgbox gText_ceruleangiovanni_BrokeOutOfMyBall
	setspeaker SP_NAME_MEWTWO
	msgbox gText_ceruleangiovanni_10
	setvar VAR_0x8004, 8  @ vertical pan
	setvar VAR_0x8005, 8  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 8  @ shake delay
	special ShakeScreen
	waitstate
	warp MAP_ROUTE4, 3
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

gText_ceruleangiovanni_1::
	.string "I see you've come to stop me\n"
	.string "yet again…$"

gText_ceruleangiovanni_2::
	.string "Unfortunately, you won't be the hero\n"
	.string "this time.\p"
	.string "You're too late.$"

gText_ceruleangiovanni_3::
	.string "Mewtwo! You're mine!$"

gText_ceruleangiovanni_4::
	.string "Mew!$"

gText_ceruleangiovanni_5::
	.string "Master Ball, go!$"

gText_ceruleangiovanni_6::
	.string "…$"

gText_ceruleangiovanni_Defeated::
	.string "W-what?!\n"
	.string "Impossible…$"

gText_ceruleangiovanni_7::
	.string "Aha! The Master Ball my scientists\n"
	.string "made works!\p"
	.string "And attaching this Mega Stone that\n"
	.string "we've worked hard on…\p"
	.string "I'm practically invincible!$"

gText_ceruleangiovanni_8::
	.string "You still dare to stop me, knowing\n"
	.string "I have Mega Mewtwo?\p"
	.string "Well, the honor is mine, you insolent\n"
	.string "child!$"

gText_ceruleangiovanni_8_2::
	.string "Woah, things are getting out of\n"
	.string "hand here…$"

gText_ceruleangiovanni_8_3::
	.string "Hi there, just the champion stopping\n"
	.string "by to help put an end to this\l"
	.string "mess.$"

gText_ceruleangiovanni_8_4::
	.string "Hm, no matter.\n"
	.string "I can't possibly be stopped with\l"
	.string "Mega Mewtwo.$"

gText_ceruleangiovanni_8_5::
	.string "Sorry, {PLAYER}, was it?\n"
	.string "I came here rather short of notice,\l"
	.string "so I don't have my best Pokémon on me.\p"
	.string "You'll have to help me out here.$"

gText_ceruleangiovanni_8_6::
	.string "Have at me then, you fools!$"

gText_ceruleangiovanni_9::
	.string "Even with Mega Mewtwo,\n"
	.string "I've fallen by your hands.$"

gText_ceruleangiovanni_BrokeOutOfMyBall::
	.string "What?!\n"
	.string "Mewtwo escaped out of my Master Ball!$"

gText_ceruleangiovanni_10::
	.string "Yes… you are UNWORTHY!!!$"

