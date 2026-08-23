LavenderTown_House1_Frlg_MapScripts::
	.byte 0

LavenderTown_House1_EventScript_CooltrainerF::
	lock
	faceplayer
	goto_if_eq VAR_SILPH_CO_GHOST_QUEST, 1, LavenderTown_House1_EventScript_GhostGirlAccept
	goto_if_set FLAG_RESCUED_MR_FUJI, LavenderTown_House1_EventScript_CooltrainerFGhostGone
	msgbox LavenderTown_House1_Text_RocketsKilledCubonesMother
	release
	end

@ She tags along to Silph Co 1F, the arrival scene runs from that map
LavenderTown_House1_EventScript_GhostGirlAccept::
	msgbox LavenderTown_House1_Text_GhostGirlAccepts
	closemessage
	setvar VAR_SILPH_CO_GHOST_QUEST, 2
	fadescreen FADE_TO_BLACK
	warp MAP_SILPH_CO_1F, 33, 20
	waitstate
	release
	end

LavenderTown_House1_EventScript_CooltrainerFGhostGone::
	msgbox LavenderTown_House1_Text_GhostOfPokemonTowerIsGone
	release
	end

LavenderTown_House1_EventScript_Cubone::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CUBONE, CRY_MODE_NORMAL
	msgbox LavenderTown_House1_Text_Cubone
	waitmoncry
	release
	end

LavenderTown_House1_Text_Cubone::
    .string "Cubone: Kyarugoo!$"

LavenderTown_House1_Text_GhostGirlAccepts::
    .string "A ghost in Silph Co.?\p"
    .string "Has the old man's age finally caught\n"
    .string "up with him?\p"
    .string "…Still. Things have been quiet since\n"
    .string "Cubone's mother found peace.\p"
    .string "I've nothing better to do.\n"
    .string "Fine. I'll take a look.$"

LavenderTown_House1_Text_RocketsKilledCubonesMother::
    .string "Those horrible Rockets!\n"
    .string "They deserve no mercy!\p"
    .string "That poor Cubone's mother…\p"
    .string "It was killed trying to escape from\n"
    .string "Team Rocket.$"

LavenderTown_House1_Text_GhostOfPokemonTowerIsGone::
    .string "The ghost of Pokémon Tower is\n"
    .string "gone!\p"
    .string "Someone must have soothed its\n"
    .string "restless spirit!$"

