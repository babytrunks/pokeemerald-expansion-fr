Route3_Frlg_MapScripts::
	.byte 0

Route3_EventScript_Youngster::
	msgbox Route3_Text_TunnelFromCeruleanTiring, MSGBOX_NPC
	end

Route3_EventScript_RouteSign::
	msgbox Route3_Text_RouteSign, MSGBOX_SIGN
	end

Route3_EventScript_CamperQuest::
    lockall
    goto_if_quest_complete QUEST_FIND_BERRY_JUICE, Route3_EventScript_CamperHowIsTheGrass
    goto_if_quest_active QUEST_FIND_BERRY_JUICE, Route3_EventScript_CamperQuestCheckForBerryJuice
    msgbox Route3_Text_DroppedBerryJuiceQuest, MSGBOX_NPC
    closemessage
    setflag FLAG_SYS_QUEST_MENU_GET
    questmenu QUEST_MENU_SET_ACTIVE QUEST_FIND_BERRY_JUICE
    openquestmenu
    startquest QUEST_FIND_BERRY_JUICE
    end

Route3_EventScript_CamperHowIsTheGrass::
    goto_if_set FLAG_BADGE06_GET, Route3_EventScript_CamperRCEvent
Route3_EventScript_CamperHowIsTheGrassEnd::
    msgbox Route3_Text_CamperHowIsTheGrass, MSGBOX_NPC
    release
    end

Route3_EventScript_CamperRCEvent::
    goto_if_set FLAG_BERRY_COMPLETED_RC_EVENT, Route3_EventScript_CamperHowIsTheGrassEnd
    goto_if_set FLAG_BERRY_ENABLE_RC_EVENT, Route3_Camper_HeGotRCNow
    msgbox Route3_Text_CamperHowIsTheGrass, MSGBOX_NPC
    release
    end

Route3_Camper_HeGotRCNow::
    msgbox Route3_Text_ShuckleGotRCNow, MSGBOX_NPC
    giveitem ITEM_RARE_CANDY
    setflag FLAG_BERRY_COMPLETED_RC_EVENT
    release
    end

Route3_EventScript_CamperQuestCheckForBerryJuice::
    checkitem ITEM_BERRY_JUICE
    goto_if_eq VAR_RESULT, TRUE, Route3_EventScript_CamperQuestDoYouWantToGive
    msgbox Route3_Text_DroppedBerryJuiceQuest, MSGBOX_NPC
    releaseall
    end

Route3_EventScript_CamperQuestDoYouWantToGive::
    faceplayer
    msgbox Route3_Text_DoYouWantToGiveBerryJuice
    closemessage
    msgbox Route3_Text_GiveCamperBerryJuice, MSGBOX_YESNO
    switch VAR_RESULT
    goto_if_eq VAR_RESULT, YES, Route3_EventScript_CamperQuest_GiveBerryReceiveGrass
	goto_if_eq VAR_RESULT, NO, Route3_EventScript_CamperQuest_Reject  

    end

Route3_EventScript_CamperQuest_GiveBerryReceiveGrass::
    msgbox Route3_Text_PlayerGaveCamperBerryJuice
    closemessage
    removeitem ITEM_BERRY_JUICE
    checkflag FLAG_BADGE02_GET
    call_if_unset FLAG_BADGE02_GET, EventScript_Camper_SetCandyFlag 
    msgbox Route3_Text_CamperGiveGrassMon
	setflag FLAG_RARE_POKEMON_SCREEN
	setflag FLAG_3_PERFECT_IVS 
    setvar VAR_RARE_POKEMON_COUNTER, 1
    factory_generaterentalmons
	factory_rentmons
	waitstate
	clearflag FLAG_RARE_POKEMON_SCREEN
	clearflag FLAG_3_PERFECT_IVS
    completequest QUEST_FIND_BERRY_JUICE
    waitmessage
    release
    end

EventScript_Camper_SetCandyFlag::
    setflag FLAG_BERRY_ENABLE_RC_EVENT
    return


Route3_EventScript_CamperQuest_Reject::
    msgbox Route3_Text_AwShuckles
    closemessage
    releaseall
    end

Route3_EventScript_Shuckle::
    playmoncry SPECIES_SHUCKLE, CRY_MODE_NORMAL
    msgbox Route3_Text_Shuckle, MSGBOX_NPC
    waitmoncry
    release
    end

Route3_Text_TunnelFromCeruleanTiring::
    .string "Whew… I better take a rest…\n"
    .string "Groan…\p"
    .string "That tunnel from CERULEAN takes a\n"
    .string "lot out of you!$"

Route3_Text_ColtonIntro::
    .string "Hey!\n"
    .string "I saw you in Viridian Forest!$"

Route3_Text_ColtonDefeat::
    .string "You beat me again!$"

Route3_Text_ColtonPostBattle::
    .string "There are other kinds of Pokémon\n"
    .string "than the ones you find in forests.$"

Route3_Text_BenIntro::
    .string "Hi!\n"
    .string "I like shorts!\p"
    .string "They're delightfully comfy and\n"
    .string "easy to wear!$"

Route3_Text_BenDefeat::
    .string "I don't believe it!$"

Route3_Text_BenPostBattle::
    .string "Are you using a Pokémon CENTER's\n"
    .string "PC for storing your Pokémon?\p"
    .string "Each BOX can hold up to\n"
    .string "30 Pokémon.$"

Route3_Text_JaniceIntro::
    .string "Excuse me!\n"
    .string "You looked at me, didn't you?$"

Route3_Text_JaniceDefeat::
    .string "You're mean!$"

Route3_Text_JanicePostBattle::
    .string "You shouldn't be staring if you\n"
    .string "don't want to battle!$"

Route3_Text_GregIntro::
    .string "Are you a TRAINER?\n"
    .string "Let's get with it right away!$"

Route3_Text_GregDefeat::
    .string "If I had new Pokémon, I would've\n"
    .string "won!$"

Route3_Text_GregPostBattle::
    .string "If a Pokémon BOX on the PC gets\n"
    .string "full, just switch to another BOX.$"

Route3_Text_SallyIntro::
    .string "That look you gave me…\n"
    .string "It's so intriguing!$"

Route3_Text_SallyDefeat::
    .string "Be nice!$"

Route3_Text_SallyPostBattle::
    .string "You can avoid battles by not\n"
    .string "letting TRAINERS see you.$"

Route3_Text_CalvinIntro::
    .string "Hey! You're not wearing shorts!\n"
    .string "What's wrong with you?$"

Route3_Text_CalvinDefeat::
    .string "Lost!\n"
    .string "Lost! Lost!$"

Route3_Text_CalvinPostBattle::
    .string "I always wear shorts, even in\n"
    .string "winter. That's my policy.$"

Route3_Text_JamesIntro::
    .string "I'll battle you with the Pokémon\n"
    .string "I just caught.$"

Route3_Text_JamesDefeat::
    .string "Done like dinner!$"

Route3_Text_JamesPostBattle::
    .string "Trained Pokémon are stronger than\n"
    .string "the wild ones.$"

Route3_Text_RobinIntro::
    .string "Eek!\n"
    .string "Did you touch me?$"

Route3_Text_RobinDefeat::
    .string "That's it?$"

Route3_Text_RobinPostBattle::
    .string "Route 4 is at the foot of\n"
    .string "Mt. Moon.$"

Route3_Text_RouteSign::
    .string "Route 3\n"
    .string "Mt. Moon AHEAD$"

Route3_Text_DroppedBerryJuiceQuest::
    .string "{COLOR BLUE}Hey there! I dropped a Berry Juice\n"
    .string "somewhere in Mt. Moon.\p"
    .string "I can't be bothered to find it now.\n"
    .string "Do you wanna give it a go?\p"
    .string "I got some sweet Grass Pokémon to give\n"
    .string "in exchange.$"

Route3_Text_DoYouWantToGiveBerryJuice::
    .string "{COLOR BLUE}Oh nice! That's my Berry Juice I've been\n"
    .string "looking for! But…\p"
    .string "Are you sure you want to give it up?\n"
    .string "You know what they say, finders\l"
    .string "keepers. It is a useful held item\l"
    .string "early in your journey.$"

Route3_Text_GiveCamperBerryJuice::
    .string "Give the Camper a Berry Juice?$"

Route3_Text_AwShuckles::
    .string "{COLOR BLUE}Aw Shuckles! Fine, fine…$"

Route3_Text_PlayerGaveCamperBerryJuice::
    .string "{PLAYER} gave the Camper a Berry Juice.$"

Route3_Text_Shuckle::
    .string "Shuckle!$"

Route3_Text_CamperGiveGrassMon::
    .string "{COLOR BLUE}Thanks! My Shuckle's going to be\n"
    .string "pleased! Anyway, as promised…$"

Route3_Text_CamperHowIsTheGrass::
    .string "{COLOR BLUE}Hey! Hope your journey is going\n"
    .string "well.$"

Route3_Text_ShuckleGotRCNow::
    .string "{COLOR BLUE}Hey buddy! While you were out on\n"
    .string "your journey, my Shuckle turned that Berry\l"
    .string "Juice into a Rare Candy!\p"
    .string "You've got a heck of a lot of badges\n"
    .string "now! Here, you should take it.$"