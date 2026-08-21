ViridianForest_Frlg_2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianForest_2_OnTransition
	.byte 0

@ The Pichu bullying scene is only present while the Light Ball quest is
@ active and the rescue hasn't happened yet
ViridianForest_2_OnTransition::
	setvar VAR_VIRIDIAN_FOREST_QUEST, 1
	setflag FLAG_HIDE_VIRIDIAN_FOREST_2_PICHU_BULLIES
	goto_if_set FLAG_RESCUED_SPIKY_PICHU, ViridianForest_2_EventScript_PichuSceneInactive
	goto_if_quest_active QUEST_LIGHT_BALL, ViridianForest_2_EventScript_ShowPichuScene
	end

ViridianForest_2_EventScript_ShowPichuScene::
	clearflag FLAG_HIDE_VIRIDIAN_FOREST_2_PICHU_BULLIES
	setvar VAR_VIRIDIAN_FOREST_QUEST, 0
	end

ViridianForest_2_EventScript_PichuSceneInactive::
	end

ViridianForest_2_EventScript_PichuBullyTriggerUp::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	waitse
	applymovement LOCALID_PLAYER, ViridianForest_2_Movement_PlayerApproachUp
	waitmovement 0
	goto ViridianForest_2_EventScript_PichuBullyScene
	end

ViridianForest_2_EventScript_PichuBullyTriggerDown::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	waitse
	applymovement LOCALID_PLAYER, ViridianForest_2_Movement_PlayerApproachDown
	waitmovement 0
	goto ViridianForest_2_EventScript_PichuBullyScene
	end

ViridianForest_2_EventScript_PichuBullyScene::
	waitse
	playmoncry SPECIES_PICHU, CRY_MODE_ENCOUNTER
	msgbox ViridianForest_2_Text_PichuBeingBullied
	closemessage
	waitmoncry
	applymovement LOCALID_VIRIDIAN_FOREST_PICHU_BULLY_1, ViridianForest_2_Movement_BullyNoticePlayer
	applymovement LOCALID_VIRIDIAN_FOREST_PICHU_BULLY_2, ViridianForest_2_Movement_BullyNoticePlayer
	playse SE_PIN
	waitmovement 0
	waitse
	msgbox ViridianForest_2_Text_BulliesTurnOnYou
	closemessage
	setflag FLAG_DONT_RANDOMIZE
	setflag FLAG_CANT_CATCH
	setflag FLAG_CANT_RUN
	setwildbattle SPECIES_PICHU, 10, ITEM_NONE, SPECIES_PICHU, 10, ITEM_NONE
	createmon 1, 0, SPECIES_PICHU, 10, ITEM_NONE, 0, NATURE_HARDY, 1, MON_FEMALE, 0, 0, 0, 0 , 0, 0, 31, 31, 31, 31, 31, 31, MOVE_PLAY_NICE, MOVE_TICKLE, MOVE_SWEET_KISS, MOVE_CHARM, TRUE, FALSE, 0, 0  
	createmon 1, 1, SPECIES_PICHU, 10, ITEM_NONE, 0, NATURE_HARDY, 1, MON_MALE, 0, 0, 0, 0 , 0, 0, 31, 31, 31, 31, 31, 31, MOVE_SHOCK_WAVE, MOVE_GRASS_KNOT, MOVE_FAKE_OUT, MOVE_SWIFT, TRUE, FALSE, 0, 0  	

	setwildonevstwo
	dowildbattle
	clearflag FLAG_DONT_RANDOMIZE
	clearflag FLAG_CANT_CATCH
	clearflag FLAG_CANT_RUN
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ViridianForest_2_EventScript_PichuBulliesDefeated
	releaseall
	end

ViridianForest_2_EventScript_PichuBulliesDefeated::
	playse SE_FLEE
	applymovement LOCALID_VIRIDIAN_FOREST_PICHU_BULLY_1, ViridianForest_2_Movement_Bully1Flee
	applymovement LOCALID_VIRIDIAN_FOREST_PICHU_BULLY_2, ViridianForest_2_Movement_Bully2Flee
	waitmovement 0
	removeobject LOCALID_VIRIDIAN_FOREST_PICHU_BULLY_1
	removeobject LOCALID_VIRIDIAN_FOREST_PICHU_BULLY_2
	msgbox ViridianForest_2_Text_BulliesFled
	closemessage
	applymovement LOCALID_VIRIDIAN_FOREST_SPIKY_PICHU, ViridianForest_2_Movement_SpikyPichuApproach
	waitmovement 0
	waitse
	playmoncry SPECIES_PICHU_SPIKY_EARED, CRY_MODE_NORMAL
	msgbox ViridianForest_2_Text_PichuLooksUpAtYou
	waitmoncry
	closemessage
	applymovement LOCALID_VIRIDIAN_FOREST_SPIKY_PICHU, ViridianForest_2_Movement_SpikyPichuApproachIntoPlayer
	waitmovement 0
	questmenu QUEST_MENU_SET_REWARD, QUEST_LIGHT_BALL
	setvar VAR_VIRIDIAN_FOREST_QUEST, 1
	setflag FLAG_DONT_RANDOMIZE
	givemon SPECIES_PICHU_SPIKY_EARED, 10, ITEM_ZAP_PLATE, move1=MOVE_VOLT_TACKLE, move2=MOVE_HELPING_HAND, move3=MOVE_SWAGGER, move4=MOVE_PAIN_SPLIT
	clearflag FLAG_DONT_RANDOMIZE
	removeobject LOCALID_VIRIDIAN_FOREST_SPIKY_PICHU
	goto_if_eq VAR_RESULT, 0, ViridianForest_2_EventScript_SpikyPichuJoinsParty
	goto_if_eq VAR_RESULT, 1, ViridianForest_2_EventScript_SpikyPichuToPC
	@ goto_if_eq VAR_RESULT, 2, ViridianForest_2_EventScript_NoRoomForSpikyPichu
	releaseall
	end

ViridianForest_2_EventScript_SpikyPichuJoinsParty::
	playfanfare MUS_LEVEL_UP
	message ViridianForest_2_Text_PichuJoined
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_PICHU_SPIKY_EARED
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianForest_2_EventScript_FinishPichuRescue
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto ViridianForest_2_EventScript_FinishPichuRescue
	end

ViridianForest_2_EventScript_SpikyPichuToPC::
	playfanfare MUS_LEVEL_UP
	message ViridianForest_2_Text_PichuJoined
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_PICHU_SPIKY_EARED
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianForest_2_EventScript_SpikyPichuTransferToPC
	call Common_EventScript_NameReceivedBoxMon
	goto ViridianForest_2_EventScript_SpikyPichuTransferToPC
	end

ViridianForest_2_EventScript_SpikyPichuTransferToPC::
	call Common_EventScript_TransferredToPC
	goto ViridianForest_2_EventScript_FinishPichuRescue
	end

ViridianForest_2_EventScript_FinishPichuRescue::
	setflag FLAG_RESCUED_SPIKY_PICHU
	setvar VAR_TEMP_0, 1
	releaseall
	end

ViridianForest_2_EventScript_NoRoomForSpikyPichu::
	msgbox ViridianForest_2_Text_NoRoomForPichu
	closemessage
	setvar VAR_TEMP_0, 1
	releaseall
	end

ViridianForest_2_Movement_PlayerApproachUp:
	walk_left
	walk_left
	step_end

ViridianForest_2_Movement_PlayerApproachDown:
	walk_up
	walk_left
	walk_left
	step_end

ViridianForest_2_Movement_BullyNoticePlayer:
	emote_exclamation_mark
	face_player
	step_end

ViridianForest_2_Movement_Bully1Flee:
	walk_faster_down
	walk_faster_down
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_up
	walk_faster_right
	walk_faster_right
	walk_faster_right
	step_end

ViridianForest_2_Movement_Bully2Flee:
	delay_16
	delay_16
	walk_faster_down
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_up
	walk_faster_right
	walk_faster_right
	walk_faster_right
	step_end

ViridianForest_2_Movement_SpikyPichuApproach:
	walk_slow_down
	walk_slow_right
	face_player
	emote_heart
	step_end

ViridianForest_2_Movement_SpikyPichuApproachIntoPlayer:
	walk_slow_right
	step_end

ViridianForest_2_Text_PichuBeingBullied::
    .string "Two Pichu are ganging up on a\n"
    .string "smaller Pichu!$"

ViridianForest_2_Text_BulliesTurnOnYou::
    .string "The bullies whirled around,\n"
    .string "crackling with sparks!\p"
    .string "They're attacking together!$"

ViridianForest_2_Text_BulliesFled::
    .string "The bullies scampered off into\n"
    .string "the tall grass!$"

ViridianForest_2_Text_PichuLooksUpAtYou::
    .string "The little Pichu looks up at you\n"
    .string "with sparkling eyes…\p"
    .string "It seems to want to come along!$"

ViridianForest_2_Text_PichuJoined::
    .string "{PLAYER} rescued the little Pichu!$"

ViridianForest_2_Text_NoRoomForPichu::
    .string "You have no room for the little\n"
    .string "Pichu…\p"
    .string "It looks at you sadly as you\n"
    .string "step away.$"

ViridianForest_2_EventScript_ItemTMElectroweb::
	finditem ITEM_TM_ELECTROWEB
	end

Viridian_Forest_2_EventScript_Virizion::
	lock
	faceplayer
	setwildbattle SPECIES_VIRIZION, 50
	waitse
	playmoncry SPECIES_VIRIZION, CRY_MODE_ENCOUNTER
	message Text_Gyaoo
	waitmessage
	waitmoncry
	delay 10
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, 0
	waitbuttonpress
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Viridian_Forest_2_EventScript_DefeatedVirizion
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Viridian_Forest_2_EventScript_RanFromVirizion
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Viridian_Forest_2_EventScript_RanFromVirizion
	
	setflag FLAG_FOUGHT_VIRIZION
	goto EventScript_RemoveStaticMon
	release
	end

Viridian_Forest_2_EventScript_DefeatedVirizion::
	setflag FLAG_FOUGHT_VIRIZION
	goto EventScript_RemoveStaticMon
	end

Viridian_Forest_2_EventScript_RanFromVirizion::
	release
	end
