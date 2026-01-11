SSAnne_1F_Corridor_Frlg_MapScripts::
	.byte 0

SSAnne_1F_Corridor_EventScript_WorkerM::
	msgbox SSAnne_1F_Corridor_Text_LeStrongSilentType, MSGBOX_NPC
	end

SSAnne_1F_Corridor_EventScript_Sailor::
	msgbox SSAnne_1F_Corridor_Text_PassengersAreRestless, MSGBOX_NPC
	end

SSAnne_1F_Corridor_EventScript_LassDouble::
	trainerbattle_two_trainers TRAINER_ANN, SSAnne_1F_Room2_Text_AnnDefeat, TRAINER_BROOKS, SSAnne_2F_Room2_Text_BrooksDefeat
	end

SSAnne_1F_Corridor_EventScript_GentlemanDouble::
	trainerbattle_two_trainers TRAINER_BROOKS, SSAnne_2F_Room2_Text_BrooksDefeat, TRAINER_ANN, SSAnne_1F_Room2_Text_AnnDefeat
	end

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
