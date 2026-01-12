SSAnne_1F_Corridor_Frlg_MapScripts::
	.byte 0

SSAnne_1F_Corridor_EventScript_WorkerM::
	msgbox SSAnne_1F_Corridor_Text_LeStrongSilentType, MSGBOX_NPC
	end

SSAnne_1F_Corridor_EventScript_Sailor::
	msgbox SSAnne_1F_Corridor_Text_PassengersAreRestless, MSGBOX_NPC
	end

SSAnne_1F_Corridor_EventScript_LassDouble_Trigger::
SSAnne_1F_Corridor_EventScript_LassDouble::
    lock
    goto_if_defeated TRAINER_ANN, SSAnne_1F_Corridor_AnnBeaten
    applymovement LOCALID_SSANNE_ANN, SSAnne_1F_Corridor_Movement_GirlFacePlayer
    waitmovement 0
    playbgm TRAINER_ENCOUNTER_MUSIC_COOL, FALSE
    setspeaker SP_NAME_ANN
    msgbox SSAnne_1F_Room2_Text_AnnIntro
    applymovement LOCALID_SSANNE_BROOKS, Common_Movement_ExclamationMark
    waitmovement 0
    playbgm MUS_ENCOUNTER_MALE, FALSE
    setspeaker SP_NAME_BROOKS
    msgbox SSAnne_2F_Room2_Text_BrooksIntro
	trainerbattle_two_trainers TRAINER_ANN, SSAnne_1F_Room2_Text_AnnDefeat, TRAINER_BROOKS, SSAnne_2F_Room2_Text_BrooksDefeat
	settrainerflag TRAINER_ANN
    settrainerflag TRAINER_BROOKS
    setvar VAR_SS_ANNE_ANN_BROOKS_BATTLE, 0x1
    end

SSAnne_1F_Corridor_AnnBeaten::
    lock
    faceplayer
    msgbox SSAnne_1F_Room2_Text_AnnDefeat, MSGBOX_AUTOCLOSE
    release
    end
    
SSAnne_1F_Corridor_EventScript_GentlemanDouble::
	msgbox SSAnne_2F_Room2_Text_BrooksPostBattle, MSGBOX_AUTOCLOSE
    end

SSAnne_1F_Corridor_Movement_GirlFacePlayer:
    emote_exclamation_mark
    face_player
    step_end

SSAnne_1F_Corridor_Text_LeStrongSilentType::
    .string "Bonjour!\n"
    .string "I am le waiter on this ship!\p"
    .string "I will be happy to serve you\n"
    .string "anything you please!\p"
    .string "… … …\n"
    .string "Ah! Le strong silent type!$"

SSAnne_1F_Corridor_Text_PassengersAreRestless::
    .string "The passengers are restless from\n"
    .string "this long voyage.\p"
    .string "You might be challenged by the\n"
    .string "more bored ones!$"

SSAnne_1F_Room2_Text_AnnDefeat::
    .string "Oh, no!\n"
    .string "I went around the world for these!$"

SSAnne_2F_Room2_Text_BrooksIntro::
    .string "Competing against the young keeps\n"
    .string "me youthful.$"

SSAnne_2F_Room2_Text_BrooksDefeat::
    .string "Good match!\n"
    .string "Ah, I feel young again!$"

SSAnne_2F_Room2_Text_BrooksPostBattle::
    .string "Fifteen years ago, I would\n"
    .string "have won!$"

