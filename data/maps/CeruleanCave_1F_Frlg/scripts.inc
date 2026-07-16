CeruleanCave_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeruleanCave_1F_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCave_1F_OnTransition
	.byte 0

CeruleanCave_1F_OnFrame::
	map_script_2 VAR_VIRIDIAN_TRIGGER_CERULEAN_CAVE, 1, EventScript_CeruleanCave_1F_OnFrameBrendanRockets
	.2byte 0
	
CeruleanCave_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_CERULEAN_CAVE_1F
	goto_if_eq VAR_VIRIDIAN_TRIGGER_CERULEAN_CAVE, 2, CeruleanCave_1F_EventScript_UpdateArianaPositions
	end

CeruleanCave_1F_EventScript_UpdateArianaPositions::
	setobjectxyperm LOCALID_CERULEAN_CAVE_ARIANA_1F, 33, 18
	end

EventScript_CeruleanCave_1F_OnFrameBrendanRockets::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	setspeaker SP_NAME_BRENDAN
	msgbox CeruleanCave_1F_Text_CoastIsClear
	setspeaker SP_NAME_ARIANA
	msgbox CeruleanCave_1F_Text_WellIfItIsnt
	applymovement LOCALID_CERULEAN_CAVE_ARIANA_1F, CeruleanCave1F_Movement_ArianaApproach
	waitmovement 0
	setspeaker SP_NAME_BRENDAN
	playse SE_LEDGE
	applymovement LOCALID_CERULEAN_CAVE_BRENDAN, CeruleanCave1F_Movement_BrendanJump
	waitmovement 0 
	waitse
	msgbox CeruleanCave_1F_Text_AghTeamRocket
	setspeaker SP_NAME_ARIANA
	msgbox CeruleanCave_1F_Text_TakenCareOf
	setspeaker SP_NAME_BRENDAN
	applymovement LOCALID_CERULEAN_CAVE_BRENDAN, Common_Movement_FaceDown
	waitmovement 0
	msgbox CeruleanCave_1F_Text_GoOn
	applymovement LOCALID_CERULEAN_CAVE_BRENDAN, Common_Movement_FaceUp
	waitmovement 0
	setspeaker SP_NAME_ARIANA
	msgbox CeruleanCave_1F_Text_TskWhatever
	waitbuttonpress
	setvar VAR_VIRIDIAN_TRIGGER_CERULEAN_CAVE, 2
	release
	end

CeruleanCave1F_Movement_BrendanJump::
	jump_in_place_up
	step_end

CeruleanCave1F_Movement_ArianaApproach::
	walk_left 
	walk_left
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCave_1F_EventScript_Brendan::
	lock
	faceplayer
	setspeaker SP_NAME_BRENDAN
	msgbox CeruleanCave_1F_Text_GoOn, MSGBOX_AUTOCLOSE
 	applymovement LOCALID_CERULEAN_CAVE_BRENDAN, Common_Movement_FaceUp
	waitmovement 0
	release
	end

CeruleanCave_1F_EventScript_Ariana::
	lock
	faceplayer
	setspeaker SP_NAME_ARIANA
	msgbox CeruleanCave_1F_Text_WhatAreYouLookingAt, MSGBOX_AUTOCLOSE
 	applymovement LOCALID_CERULEAN_CAVE_ARIANA_1F, Common_Movement_FaceDown
	waitmovement 0
	release
	end

CeruleanCave_1F_Trigger_ArcherAriana::
	applymovement LOCALID_PLAYER Common_Movement_FaceDown
	waitmovement 0
	playse SE_EXIT 
	addobject LOCALID_CERULEAN_CAVE_ARCHER
	waitse
	playse SE_PIN
	applymovement LOCALID_PLAYER Common_Movement_ExclamationMark
	waitmovement 0
	waitse
	applymovement LOCALID_PLAYER Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_CERULEAN_CAVE_ARCHER, CeruleanCave1F_Movement_ArcherApproach
	waitmovement 0
	playse SE_EXIT 
	addobject LOCALID_CERULEAN_CAVE_ARIANA_2
	waitse
	applymovement LOCALID_CERULEAN_CAVE_ARIANA_2, CeruleanCave1F_Movement_ArianaApproach2
	waitmovement 0
	setspeaker SP_NAME_ARCHER
	msgbox CeruleanCave_1F_Text_WellWellWell
	setspeaker SP_NAME_ARIANA
	msgbox CeruleanCave_1F_Text_GiveItUp
	setspeaker SP_NAME_ARCHER
	msgbox CeruleanCave_1F_Text_NotGonnaBudge
	trainerbattle_no_intro TRAINER_CERULEAN_CAVE_ARCHER, CeruleanCave1F_Text_ArcherDefeat
	setspeaker SP_NAME_ARIANA
	msgbox CeruleanCave_1F_Text_ComeOnArcher
	setspeaker SP_NAME_ARCHER
	msgbox CeruleanCave_1F_Text_BrendanWeakenedMe
	setspeaker SP_NAME_ARIANA
	msgbox CeruleanCave_1F_Text_WhateverKid
	trainerbattle_no_intro TRAINER_CERULEAN_CAVE_ARIANA, CeruleanCave1F_Text_ArianaDefeat
	setspeaker SP_NAME_ARIANA
	msgbox CeruleanCave1F_Text_ArianaHowCouldThisBet
	setspeaker SP_NAME_ARCHER
	msgbox CeruleanCave1F_Text_ArcherWouldntUnderstand MSGBOX_AUTOCLOSE
	applymovement LOCALID_CERULEAN_CAVE_ARIANA_2, CeruleanCave1F_Movement_ArianaLeaveFight
	waitmovement 0
	removeobject LOCALID_CERULEAN_CAVE_ARIANA_2
	playse SE_EXIT 
	waitse
	applymovement LOCALID_CERULEAN_CAVE_ARCHER, CeruleanCave1F_Movement_ArcherLeaveFight
	waitmovement 0
	removeobject LOCALID_CERULEAN_CAVE_ARCHER
	playse SE_EXIT 
	waitse
	msgbox CeruleanCave1F_Text_AccidentallyDropped
	giveitem ITEM_HOUNDOOMINITE
	giveitem ITEM_MAWILITE
	setvar VAR_TRIGGER_CERULEAN_CAVE_ARCHER_ARIANA 1
	setflag FLAG_DEFEATED_CERULEAN_ARCHER_ARIANA
	release
	end


CeruleanCave1F_Movement_ArcherApproach::
	walk_down
	walk_right
	face_down
	step_end

CeruleanCave1F_Movement_ArianaApproach2:
	walk_down
	step_end

CeruleanCave1F_Movement_ArianaLeaveFight:
	walk_up
	step_end

CeruleanCave1F_Movement_ArcherLeaveFight:
	walk_left
	walk_up
	step_end 

CeruleanCave_1F_Text_CoastIsClear::
	.string "Hm, seems the coast is clear.$"

CeruleanCave_1F_Text_WellIfItIsnt::
	.string "Well well, if it isn't the two scrubs\n"
	.string "back in Silph Co.$"

CeruleanCave_1F_Text_AghTeamRocket::
	.string "Agh! Team Rocket!\p"
	.string "I knew it!\p"
	.string "What do you think you're doing?!$"

CeruleanCave_1F_Text_TakenCareOf::
	.string "It doesn't concern you.\p"
	.string "I'll have you taken care of.$"

CeruleanCave_1F_Text_GoOn::
	.string "{PLAYER}, go on ahead!\p"
	.string "I'll catch up with you later!$"

CeruleanCave_1F_Text_TskWhatever::
	.string "Tsk, whatever.\p"
	.string "I'll just have to handle you\n"
	.string "later.$"

CeruleanCave_1F_Text_WhatAreYouLookingAt::
	.string "What are you looking at?\n"
	.string "I'll take care of you later.$"

CeruleanCave_1F_Text_WellWellWell::
	.string "Well, well well.\n"
	.string "What do we have here?$"

CeruleanCave_1F_Text_GiveItUp::
	.string "You're cornered, buddy.\n"
	.string "Just give it up and head home.$"

CeruleanCave_1F_Text_NotGonnaBudge::
	.string "Not gonna budge?\n"
	.string "Even in a two vs one?\p"
	.string "Well, it's your funeral.$"

CeruleanCave1F_Text_ArcherDefeat::
	.string "No! Forgive me Giovanni!$"

CeruleanCave_1F_Text_ComeOnArcher::
	.string "Oh come on, Archer.\p"
	.string "Always making me clean up after\n"
	.string "you.$"

CeruleanCave_1F_Text_BrendanWeakenedMe::
	.string "Shush. I only lost because that\n"
	.string "other twerp weakened my squad.$"

CeruleanCave_1F_Text_WhateverKid::
	.string "Sure. Let me show you how it's done.$"

CeruleanCave1F_Text_ArianaDefeat::
	.string "I've been shattered…$"

CeruleanCave1F_Text_ArianaHowCouldThisBet::
	.string "How could this be?!$"

CeruleanCave1F_Text_ArcherWouldntUnderstand::
	.string "Tsk, someone like you could never\n"
	.string "understand Team Rocket's aspirations.\p"
	.string "You can try challenge the boss, but\n"
	.string "I doubt even you can stop him now.\p"
	.string "Hmph, take care.$"

CeruleanCave1F_Text_AccidentallyDropped::
	.string "It appears they've accidentally\n"
	.string "dropped some items on the ground…$"
