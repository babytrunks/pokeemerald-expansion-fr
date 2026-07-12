CinnabarIsland_PokemonLab_ResearchRoom_Frlg_MapScripts::
	.byte 0

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_MegaScientist::
	lock
	faceplayer
	goto_if_quest_complete QUEST_MEGA_MAYHEM, CinnabarIsland_PokemonLab_ResearchRoom_EventScript_MegaScientistDone
	goto_if_quest_reward QUEST_MEGA_MAYHEM, CinnabarIsland_PokemonLab_ResearchRoom_EventScript_MegaScientistReward
	goto_if_quest_active QUEST_MEGA_MAYHEM, CinnabarIsland_PokemonLab_ResearchRoom_EventScript_MegaScientistReminder
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_MegaIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ResearchRoom_EventScript_MegaScientistDecline
	setflag FLAG_SYS_QUEST_MENU_GET
	startquest QUEST_MEGA_MAYHEM
	release
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_MegaScientistDecline::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_MegaDecline
	release
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_MegaScientistReminder::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_MegaReminder
	release
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_MegaScientistReward::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_MegaWow
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	completequest QUEST_MEGA_MAYHEM
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_MegaThanks
	giveitem ITEM_AERODACTYLITE
	release
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_MegaScientistDone::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_MegaAlreadyDone
	release
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_Scientist::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_EeveeCanEvolveIntroThreeMons, MSGBOX_NPC
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_Computer::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_LegendaryBirdEmail, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_AmberPipe::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_AnAmberPipe, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_ResearchRoom_Text_EeveeCanEvolveIntroThreeMons::
    .string "Eevee can evolve into one of three\n"
    .string "kinds of Pokémon.$"

CinnabarIsland_PokemonLab_ResearchRoom_Text_LegendaryBirdEmail::
    .string "There's an e-mail message.\p"
    .string "… … …\p"
    .string "There are three legendary bird\n"
    .string "Pokémon.\p"
    .string "They are Articuno, Zapdos, and\n"
    .string "Moltres.\p"
    .string "Their whereabouts are unknown.\p"
    .string "We plan to explore the cavern\n"
    .string "close to Cerulean.\p"
    .string "From: Pokémon Research Team…$"

CinnabarIsland_PokemonLab_ResearchRoom_Text_AnAmberPipe::
    .string "An amber pipe!$"

CinnabarIsland_PokemonLab_ResearchRoom_Text_MegaIntro::
    .string "Ah, a trainer! Perfect timing.\p"
    .string "I'm a scientist studying the secrets\n"
    .string "of Mega Evolution.\p"
    .string "Lately I've heard the wildest rumors…\n"
    .string "A rogue Pokémon roaming the Safari\l"
    .string "Zone, radiating Mega energy!\p"
    .string "A WILD Pokémon Mega Evolving with no\n"
    .string "trainer? Preposterous! And yet…\p"
    .string "I must know the truth. Would you\n"
    .string "investigate it for me? I'll make it\l"
    .string "worth your while.$"

CinnabarIsland_PokemonLab_ResearchRoom_Text_MegaDecline::
    .string "No? A pity. Come back if you have a\n"
    .string "change of heart.$"

CinnabarIsland_PokemonLab_ResearchRoom_Text_MegaReminder::
    .string "The rogue Mega was last seen on the\n"
    .string "east side of the Safari Zone.\p"
    .string "Track it down, and be careful! It's\n"
    .string "no ordinary wild Pokémon.$"

CinnabarIsland_PokemonLab_ResearchRoom_Text_MegaWow::
    .string "You actually faced it? Astounding!\p"
    .string "So it's true… even wild Pokémon can\n"
    .string "Mega Evolve under the right\l"
    .string "conditions.\p"
    .string "This rewrites everything we thought\n"
    .string "we knew. Marvelous work!$"

CinnabarIsland_PokemonLab_ResearchRoom_Text_MegaThanks::
    .string "Please, take this for your trouble.\p"
    .string "A Mega Stone, fittingly. May it serve\n"
    .string "you better than it served that poor\l"
    .string "wild creature.$"

CinnabarIsland_PokemonLab_ResearchRoom_Text_MegaAlreadyDone::
    .string "Thanks to you, my research has taken\n"
    .string "a great leap forward.\p"
    .string "Wild Mega Evolution… how interesting.$"

