SaffronCity_House_Frlg_MapScripts::
	.byte 0

SaffronCity_House_EventScript_Lass::
	msgbox SaffronCity_House_Text_DontLookAtMyLetter, MSGBOX_NPC
	end

SaffronCity_House_EventScript_Youngster::
	msgbox SaffronCity_House_Text_GettingCopycatPokeDoll, MSGBOX_NPC
	end

SaffronCity_House_EventScript_Pidgey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TRANQUILL, CRY_MODE_NORMAL
	msgbox SaffronCity_House_Text_Pidgey
	waitmoncry
	release
	end

SaffronCity_House_EventScript_Glameow::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_GLAMEOW, CRY_MODE_NORMAL
	msgbox SaffronCity_House_Text_Glameow
	waitmoncry
	release
	end

SaffronCity_House_EventScript_Litten::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_LITTEN, CRY_MODE_NORMAL
	msgbox SaffronCity_House_Text_Litten
	waitmoncry
	release
	end

SaffronCity_House_EventScript_Meowstic::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEOWSTIC, CRY_MODE_NORMAL
	msgbox SaffronCity_House_Text_Meowstic
	waitmoncry
	release
	end

SaffronCity_House_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox SaffronCity_House_Text_Skitty
	waitmoncry
	release
	end

SaffronCity_House_EventScript_Letter::
	msgbox SaffronCity_House_Text_ExplainPPUp, MSGBOX_SIGN
	end

SaffronCity_House_EventScript_CatLady::
	lock
	faceplayer
	goto_if_quest_complete QUEST_CRAZY_CAT_LADY, SaffronCity_House_EventScript_CatLadyDone
	goto_if_quest_active QUEST_CRAZY_CAT_LADY, SaffronCity_House_EventScript_CatLadyCheck
	setflag FLAG_SYS_QUEST_MENU_GET
	msgbox SaffronCity_House_Text_CatLadyIntro
	closemessage
	questmenu QUEST_MENU_SET_ACTIVE QUEST_CRAZY_CAT_LADY
	openquestmenu
	startquest QUEST_CRAZY_CAT_LADY
	release
	end

SaffronCity_House_EventScript_CatLadyCheck::
	callnative IsFollowerFeline
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_House_EventScript_CatLadyReward
	msgbox SaffronCity_House_Text_CatLadyNotYet
	release
	end

SaffronCity_House_EventScript_CatLadyReward::
	msgbox SaffronCity_House_Text_CatLadyCongrats
	giveitem ITEM_MEOWSTICITE
	completequest QUEST_CRAZY_CAT_LADY
	release
	end

SaffronCity_House_EventScript_CatLadyDone::
	msgbox SaffronCity_House_Text_CatLadyPostQuest
	release
	end

SaffronCity_House_Text_DontLookAtMyLetter::
    .string "…Don't take it the wrong way.\n"
    .string "I hope to see you soon!\p"
    .string "…Hey!\n"
    .string "Don't look at my letter!$"

SaffronCity_House_Text_Pidgey::
    .string "Quil!$"

SaffronCity_House_Text_Glameow::
    .string "Nyaa!$"

SaffronCity_House_Text_Litten::
    .string "Mrow!$"

SaffronCity_House_Text_Meowstic::
    .string "Nya!$"

SaffronCity_House_Text_Skitty::
    .string "Uhhh, meow?$"

SaffronCity_House_Text_GettingCopycatPokeDoll::
    .string "The COPYCAT is cute!\n"
    .string "I'm getting her a POKé DOLL.$"

SaffronCity_House_Text_ExplainPPUp::
    .string "I was given a PP UP as a gift.\p"
    .string "It's used to increase the PP of\n"
    .string "a Pokémon's move.\p"
    .string "I should use it on a powerful move\n"
    .string "with only a few PP, but…\p"
	.string "I think you have other needs.$"

SaffronCity_House_Text_CatLadyIntro::
    .string "Hee hee… do you hear them?\n"
    .string "My darlings, purring all around!\p"
    .string "I am the crazy cat lady of Saffron!\n"
    .string "But I've seen every kitty in this\l"
    .string "house a thousand times over…\p"
    .string "Oh, would you show me your cat?\n"
    .string "Bring me a feline Pokémon!\p"
    .string "Let it walk beside you, and let me\n"
    .string "gaze upon its precious face!$"

SaffronCity_House_Text_CatLadyNotYet::
    .string "Hmm? Let me see your little\n"
    .string "companion…\p"
    .string "…That's no cat!\n"
    .string "I want to see a feline, dearie.\p"
    .string "Let one lead the way, then come\n"
    .string "back to me.$"

SaffronCity_House_Text_CatLadyCongrats::
    .string "Oh! OH!\p"
    .string "Look at those whiskers!\n"
    .string "Those darling little paws!\p"
    .string "What a perfect, precious kitty!\n"
    .string "I could just melt!\p"
    .string "Here, take this. A treasure for a\n"
    .string "true cat lover like yourself!$"

SaffronCity_House_Text_CatLadyPostQuest::
    .string "Thank you for showing me your\n"
    .string "wonderful kitty, dearie.$"

