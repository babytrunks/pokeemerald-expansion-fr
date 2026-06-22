PokemonMansion_3F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonMansion_3F_OnLoad
	.byte 0

PokemonMansion_3F_OnLoad::
	call_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_PressSwitch_3F
	end

PokemonMansion_3F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 2
	call PokemonMansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

PokemonMansion_3F_EventScript_DiaryFeb6th::
	msgbox PokemonMansion_1F_Text_MewGaveBirthToMewtwo, MSGBOX_SIGN
	end

PokemonMansion_3F_EventScript_Simon::
	trainerbattle_single TRAINER_BURGLAR_SIMON, PokemonMansion_1F_Text_SimonIntro, PokemonMansion_1F_Text_SimonDefeat
	msgbox PokemonMansion_1F_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_3F_EventScript_Braydon::
	trainerbattle_single TRAINER_SCIENTIST_BRAYDON, PokemonMansion_1F_Text_BraydonIntro, PokemonMansion_1F_Text_BraydonDefeat
	msgbox PokemonMansion_1F_Text_BraydonPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_3F_EventScript_VitaminQuest::
	lock
	faceplayer
	goto_if_quest_complete QUEST_RARE_EXTRACT, PokemonMansion_3F_EventScript_VitaminQuestDone
	goto_if_quest_active QUEST_RARE_EXTRACT, PokemonMansion_3F_EventScript_VitaminQuestCheck
	setflag FLAG_SYS_QUEST_MENU_GET
	msgbox PokemonMansion_3F_Text_VitaminQuestIntro
	closemessage
	questmenu QUEST_MENU_SET_ACTIVE QUEST_RARE_EXTRACT
	openquestmenu
	startquest QUEST_RARE_EXTRACT
	release
	end

PokemonMansion_3F_EventScript_VitaminQuestCheck::
	checkitem ITEM_RARE_EXTRACT
	goto_if_eq VAR_RESULT, TRUE, PokemonMansion_3F_EventScript_VitaminQuestReward
	msgbox PokemonMansion_3F_Text_VitaminQuestNotYet
	release
	end

PokemonMansion_3F_EventScript_VitaminQuestReward::
	msgbox PokemonMansion_3F_Text_VitaminQuestCongrats
	removeitem ITEM_RARE_EXTRACT
	giveitem ITEM_DREAM_PATCH, 3
	giveitem ITEM_HP_UP, 2
	giveitem ITEM_PROTEIN, 2
	giveitem ITEM_IRON, 2
	giveitem ITEM_CALCIUM, 2
	giveitem ITEM_ZINC, 2
	giveitem ITEM_CARBOS, 2
	completequest QUEST_RARE_EXTRACT
	release
	end

PokemonMansion_3F_EventScript_VitaminQuestDone::
	msgbox PokemonMansion_3F_Text_VitaminQuestPostQuest
	release
	end

PokemonMansion_3F_Text_VitaminQuestIntro::
	.string "…Oh dang. Those badges aren't just for\n"
	.string "show, are they?\p"
	.string "I need a tough trainer like you for\n"
	.string "something.\p"
	.string "My crew moves… product, I guess you\n"
	.string "could say. And right now I'm short\l"
	.string "one very special ingredient.\p"
	.string "There's a Rare Extract stashed in\n"
	.string "Silph Co's 7th floor.\p"
	.string "It's locked behind an orange crate.\p"
	.string "According to my intel, the crate's\n"
	.string "sort of like a sliding door.\p"
	.string "There's a secret button underneath\n"
	.string "and the crate should move.\p"
	.string "Bring me that Extract and I'll make it\n"
	.string "worth your while.\p"
	.string "Watch your back, though. Other bad\n"
	.string "actors are sniffing around for it too.$"

PokemonMansion_3F_Text_VitaminQuestNotYet::
	.string "Empty-handed? The Rare Extract's\n"
	.string "still up in Silph Co, 7th floor.\p"
	.string "Hurry, we're not the only ones after\n"
	.string "it.$"

PokemonMansion_3F_Text_VitaminQuestCongrats::
	.string "Well, I'll be… you actually pulled it\n"
	.string "off.\p"
	.string "You a straight DOG. Hand it over\n"
	.string "and take your cut.$"

PokemonMansion_3F_Text_VitaminQuestPostQuest::
	.string "Sorry, I don't have anymore goodies\n"
	.string "for you. I got a lot of clients to\l"
	.string "to appease.$"

PokemonMansion_1F_Text_SimonIntro::
    .string "This place is, like, huge!$"

PokemonMansion_1F_Text_SimonDefeat::
    .string "Ayah!$"

PokemonMansion_1F_Text_SimonPostBattle::
    .string "I wonder where my partner went.$"

PokemonMansion_1F_Text_BraydonIntro::
    .string "My mentor once lived here.$"

PokemonMansion_1F_Text_BraydonDefeat::
    .string "Whew!\n"
    .string "Overwhelming!$"

PokemonMansion_1F_Text_BraydonPostBattle::
    .string "So, you're stuck?\n"
    .string "Try jumping off over there!$"

PokemonMansion_1F_Text_MewGaveBirthToMewtwo::
    .string "Diary: Feb. 6\n"
    .string "Mew gave birth.\p"
    .string "We named the newborn Mewtwo.$"
