CeruleanCity_House5_Frlg_MapScripts::
	.byte 0

CeruleanCity_House5_EventScript_FangTutorMan::
	lock
	faceplayer
    goto_if_quest_complete QUEST_FANG_TUTOR, CeruleanCity_House5_EventScript_TeachFangs	
	goto_if_quest_active QUEST_FANG_TUTOR, CeruleanCity_House5_EventScript_CheckBoy
	msgbox CeruleanCity_House1_Text_LookingForGoodBoy
	msgbox CeruleanCity_House1_Text_BringMeAGoodBoy
    setflag FLAG_SYS_QUEST_MENU_GET
 	questmenu QUEST_MENU_SET_ACTIVE QUEST_FANG_TUTOR
    openquestmenu
    startquest QUEST_FANG_TUTOR
	release
	end

CeruleanCity_House5_EventScript_CheckBoy:
	msgbox CeruleanCity_House1_Text_BringMeAGoodBoy
	callnative CheckFollowerPokemonIsDog
	goto_if_eq VAR_RESULT, NO, CeruleanCity_House5_EventScript_ThatsNotADog
	setvar 0x8004, 0
	special BufferMonNickname
	msgbox CeruleanCity_House1_Text_HesJustLikeHim
	completequest QUEST_FANG_TUTOR
    waitmessage
    release
    end
CeruleanCity_House5_EventScript_ThatsNotADog: 
	msgbox CeruleanCity_House1_Text_ThatsNotAGoodBoy
	release
	end

CeruleanCity_House5_EventScript_TeachFangs:
	msgbox CeruleanCity_House1_Text_DoYouWantFangTutor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeruleanCity_House5_EventScript_NoInterestInFangs
	dynmultichoice 25, 0, 0, 3, 0, DYN_MULTICHOICE_CB_NONE, gText_FireFang, gText_IceFang, gText_ThunderFang
	@ return
	switch VAR_RESULT
	case 0, CeruleanCity_House5_EventScript_TeachFireFang
	case 1, CeruleanCity_House5_EventScript_TeachIceFang
	case 2, CeruleanCity_House5_EventScript_TeachThunderFang

CeruleanCity_House5_EventScript_NoInterestInFangs::
	msgbox CeruleanCity_House1_Text_HopeToSeeYouAgain
	release
	end

CeruleanCity_House5_EventScript_TeachFireFang:
	setvar VAR_0x8005, MOVE_FIRE_FANG
	goto CeruleanCity_House5_EventScript_FinishFangs

CeruleanCity_House5_EventScript_TeachIceFang:
	setvar VAR_0x8005, MOVE_ICE_FANG
	goto CeruleanCity_House5_EventScript_FinishFangs

CeruleanCity_House5_EventScript_TeachThunderFang:
	setvar VAR_0x8005, MOVE_THUNDER_FANG
	goto CeruleanCity_House5_EventScript_FinishFangs

CeruleanCity_House5_EventScript_FinishFangs:
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House5_EventScript_NoInterestInFangs
	msgbox CeruleanCity_House1_Text_TaughtFangs
	release
	end


CeruleanCity_House1_Text_LookingForGoodBoy::
    .string "Hello traveler. I have a small\n"
    .string "request.\p"
    .string "My lovely Arcanine passed away\n"
    .string "recently. My heart is in pieces.\p"
    .string "He lived a fulfilling life, yes.\n"
    .string "But now in my old age I'm all alone.\p"

CeruleanCity_House1_Text_BringMeAGoodBoy:
	.string "Can you show me a good dog?\n"
	.string "I need something to lift my spirits.\p"
	.string "I can teach you the Fang moves in\n"
	.string "return.$"

CeruleanCity_House1_Text_HopeToSeeYouAgain::
    .string "That's fine, then.\n"
    .string "I'll hope to see you back again.$"


CeruleanCity_House1_Text_ThatsNotAGoodBoy::
	.string ".{PAUSE 50}.{PAUSE 50}.{PAUSE 50}Aw, that's not what I'm looking\n"
	.string "for.$"

CeruleanCity_House1_Text_HesJustLikeHim:
	.string "Oh… your {STR_VAR_1}…{PAUSE 200}\n"
	.string "Wow, what a beautiful smile!\l"
	.string "And its smell… {PAUSE 200}\p"
	.string "It reminds me of my old Arcanine.\n"
	.string "Thank you traveler, you've made my\l"
	.string "day!\p"
	.string "For your help, I can teach you\n"
	.string "various fang moves. Just talk to me\l"
	.string "if I could be of assistance.$"

CeruleanCity_House1_Text_DoYouWantFangTutor:
	.string "Do your Pokémon want to learn\n"
	.string "the fang moves?$"

CeruleanCity_House1_Text_TaughtFangs:
	.string "And there you have it!\n"
	.string "I hope those jaws bite hard!$"

gText_IceFang:
	.string "Ice Fang$"

gText_FireFang:
	.string "Fire Fang$"

gText_ThunderFang:
	.string "Thunder Fang$"

