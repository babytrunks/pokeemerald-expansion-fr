SSAnne_2F_Corridor_Frlg_MapScripts::
	.byte 0

SSAnne_2F_Corridor_EventScript_SailorDouble_Trigger::
SSAnne_2F_Corridor_EventScript_SailorDouble::
    lock
    goto_if_defeated TRAINER_SAILOR_TREVOR, SSAnne_2F_Corridor_TrevorBeaten
    applymovement LOCALID_SSANNE_TREVOR, SSAnne_2F_Corridor_Movement_SailorFacePlayer
    waitmovement 0
    playbgm MUS_ENCOUNTER_COOL, FALSE
    setspeaker SP_NAME_TREVOR
    msgbox SSAnne_Deck_Text_TrevorIntro
    applymovement LOCALID_SSANNE_EDMOND, Common_Movement_ExclamationMark
    waitmovement 0
    playbgm MUS_ENCOUNTER_COOL, FALSE
    setspeaker SP_NAME_EDMOND
    msgbox SSAnne_Deck_Text_EdmondIntro
	trainerbattle_two_trainers TRAINER_SAILOR_TREVOR, SSAnne_Deck_Text_EdmondDefeat, TRAINER_SAILOR_EDMOND, SSAnne_Deck_Text_TrevorDefeat
	settrainerflag TRAINER_SAILOR_TREVOR
    settrainerflag TRAINER_SAILOR_EDMOND
    setvar VAR_SS_ANNE_TREVOR_EDMOND_BATTLE, 0x1
    end

SSAnne_2F_Corridor_Movement_SailorFacePlayer:
	emote_exclamation_mark
	face_player
	step_end

SSAnne_2F_Corridor_TrevorBeaten:
	msgbox SSAnne_Deck_Text_TrevorPostBattle, MSGBOX_AUTOCLOSE
	release
	end

SSAnne_2F_Corridor_EventScript_Edmond:
	msgbox SSAnne_Deck_Text_EdmondPostBattle, MSGBOX_AUTOCLOSE
	release
	end

SSAnne_2F_Corridor_EventScript_RivalTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto SSAnne_2F_Corridor_EventScript_RivalTrigger
	end

SSAnne_2F_Corridor_EventScript_RivalTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	goto SSAnne_2F_Corridor_EventScript_RivalTrigger
	end

SSAnne_2F_Corridor_EventScript_RivalTriggerRight::
	lockall
	setvar VAR_TEMP_1, 2
	goto SSAnne_2F_Corridor_EventScript_RivalTrigger
	end

SSAnne_2F_Corridor_EventScript_RivalTrigger::
	textcolor NPC_TEXT_COLOR_MALE
	playse SE_EXIT
	delay 5
	playbgm MUS_ENCOUNTER_BRENDAN, 0
	addobject LOCALID_SS_ANNE_RIVAL
	delay 10
	applymovement LOCALID_SS_ANNE_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 20
	call_if_eq VAR_TEMP_1, 0, SSAnne_2F_Corridor_EventScript_RivalApproachLeft
	call_if_eq VAR_TEMP_1, 1, SSAnne_2F_Corridor_EventScript_RivalApproachMid
	call_if_eq VAR_TEMP_1, 2, SSAnne_2F_Corridor_EventScript_RivalApproachRight
	setspeaker SP_NAME_BRENDAN
	msgbox SSAnne_2F_Corridor_Text_RivalIntro
	setvar VAR_LAST_TALKED, LOCALID_SS_ANNE_RIVAL
	trainerbattle_no_intro TRAINER_BRENDAN_2, SSAnne_2F_Corridor_Text_RivalDefeat
	setspeaker SP_NAME_BRENDAN
	msgbox SSAnne_2F_Corridor_Text_RivalPostBattle
	closemessage
	giveitem ITEM_FIRE_STONE
	setspeaker SP_NAME_BRENDAN
	msgbox SSAnne_2F_Corridor_Text_RivalPostBattle2
	delay 10
	playbgm MUS_ENCOUNTER_BRENDAN, 0
	call_if_eq VAR_TEMP_1, 0, SSAnne_2F_Corridor_EventScript_RivalExitLeft
	call_if_eq VAR_TEMP_1, 1, SSAnne_2F_Corridor_EventScript_RivalExitMid
	call_if_eq VAR_TEMP_1, 2, SSAnne_2F_Corridor_EventScript_RivalExitRight
	fadedefaultbgm
	removeobject LOCALID_SS_ANNE_RIVAL
	setvar VAR_MAP_SCENE_S_S_ANNE_2F_CORRIDOR, 1
	releaseall
	end

SSAnne_2F_Corridor_EventScript_RivalApproachLeft::
	applymovement LOCALID_SS_ANNE_RIVAL, SSAnne_2F_Corridor_Movement_RivalApproachLeft
	waitmovement 0
	return

SSAnne_2F_Corridor_EventScript_RivalApproachMid::
	applymovement LOCALID_SS_ANNE_RIVAL, SSAnne_2F_Corridor_Movement_RivalApproachMid
	applymovement LOCALID_PLAYER, SSAnne_2F_Corridor_Movement_PlayerFaceRivalMid
	waitmovement 0
	return

SSAnne_2F_Corridor_EventScript_RivalApproachRight::
	applymovement LOCALID_PLAYER, SSAnne_2F_Corridor_Movement_PlayerFaceRivalRight
	applymovement LOCALID_SS_ANNE_RIVAL, SSAnne_2F_Corridor_Movement_RivalApproachRight
	waitmovement 0
	return

SSAnne_2F_Corridor_EventScript_RivalExitLeft::
	applymovement LOCALID_SS_ANNE_RIVAL, SSAnne_2F_Corridor_Movement_RivalExitLeft
	waitmovement 0
	return

SSAnne_2F_Corridor_EventScript_RivalExitMid::
	applymovement LOCALID_SS_ANNE_RIVAL, SSAnne_2F_Corridor_Movement_RivalExitMid
	waitmovement 0
	return

SSAnne_2F_Corridor_EventScript_RivalExitRight::
	applymovement LOCALID_SS_ANNE_RIVAL, SSAnne_2F_Corridor_Movement_RivalExitRight
	waitmovement 0
	return

SSAnne_2F_Corridor_Movement_PlayerFaceRivalRight::
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SSAnne_2F_Corridor_Movement_PlayerFaceRivalMid::
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SSAnne_2F_Corridor_Movement_RivalApproachLeft::
	walk_down
	walk_down
	walk_down
	step_end

SSAnne_2F_Corridor_Movement_RivalApproachMid::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

SSAnne_2F_Corridor_Movement_RivalApproachRight::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	delay_4
	step_end

SSAnne_2F_Corridor_Movement_RivalExitLeft::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SSAnne_2F_Corridor_Movement_RivalExitMid::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SSAnne_2F_Corridor_Movement_RivalExitRight::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SSAnne_2F_Corridor_EventScript_Sailor::
	msgbox SSAnne_2F_Corridor_Text_ThisShipIsLuxuryLiner, MSGBOX_NPC
	end

SSAnne_2F_Corridor_Text_ThisShipIsLuxuryLiner::
    .string "This ship, she is a luxury liner for\n"
    .string "TRAINERS of the world!\p"
    .string "At every port, we hold parties with\n"
    .string "invited TRAINERS.$"

SSAnne_2F_Corridor_Text_RivalIntro::
	.string "{COLOR BLUE}Oh hey {PLAYER}!\n"
	.string "It's been a while.\p"
	.string "I've snagged two badges since we\n"
	.string "first met.\p"
	.string "…You too huh? I thought so!\p"
	.string "Let's put each other to the test.$"

SSAnne_2F_Corridor_Text_RivalDefeat::
  	.string "Drat, wasted yet again…$"

SSAnne_2F_Corridor_Text_RivalPostBattle::
    .string "{COLOR BLUE}There's a Cut master on board.\n"
    .string "It'll be handy to get through\l"
    .string "those pesky trees.\p"
    .string "In the meantime, I've got something\n"
    .string "you may find useful.$"

SSAnne_2F_Corridor_Text_RivalPostBattle2::
  .string "{COLOR BLUE}Well, it's back to training for me.\p"
  .string "Thanks for the battle, {PLAYER}.$"

SSAnne_Deck_Text_EdmondIntro::
    .string "Hey, matey!\p"
    .string "Let's do a little jig!$"

SSAnne_Deck_Text_EdmondDefeat::
    .string "You're impressive!$"

SSAnne_Deck_Text_EdmondPostBattle::
    .string "How many kinds of Pokémon do you\n"
    .string "think there are in this big world?$"

SSAnne_Deck_Text_TrevorIntro::
    .string "Ahoy, there!\n"
    .string "Are you seasick?$"

SSAnne_Deck_Text_TrevorDefeat::
    .string "I was just careless!$"

SSAnne_Deck_Text_TrevorPostBattle::
    .string "My pa said there are 100 kinds of\n"
    .string "Pokémon. I think there are more.$"
