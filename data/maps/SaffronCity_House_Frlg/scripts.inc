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
    .string "Mew!$"

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

