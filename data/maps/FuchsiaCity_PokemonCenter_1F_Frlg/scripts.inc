FuchsiaCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FuchsiaCity_PokemonCenter_1F_OnFrame
	.byte 0

FuchsiaCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_FUCHSIA_CITY
	end

FuchsiaCity_PokemonCenter_1F_OnFrame::
	map_script_2 VAR_RECEIVED_FUCHSIA_SEVII, 0, FuchsiaCity_PokemonCenter_1F_EventScript_SeviiAide
	.2byte 0

FuchsiaCity_PokemonCenter_1F_EventScript_SeviiAide::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	playse SE_PIN
	applymovement LOCALID_FUSCHIA_PC_AIDE, Common_Movement_ExclamationMark
	waitmovement 0
	waitse
	applymovement LOCALID_FUSCHIA_PC_AIDE, FuchsiaCity_PokemonCenter_1F_Movement_AideApproach
	waitmovement 0
	msgbox FuchsiaCity_PokemonCenter_1F_Text_OakSeviiResearch
	setflag FLAG_RARE_POKEMON_SCREEN
	setvar VAR_RARE_POKEMON_COUNTER, 3
	copyvar VAR_RARE_POKEMON_EXCLUDE_SPECIES, VAR_VERMILION_CHOSEN_SEVII
	factory_generaterentalmons
	factory_rentmons
	waitstate
	setvar VAR_RARE_POKEMON_EXCLUDE_SPECIES, SPECIES_NONE
	clearflag FLAG_RARE_POKEMON_SCREEN
	clearflag FLAG_3_PERFECT_IVS
	clearflag FLAG_FORCE_SHINY
	msgbox FuchsiaCity_PokemonCenter_1F_Text_AideMustLeave
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_FUSCHIA_PC_AIDE
	setflag FLAG_RECEIVED_FUCHSIA_SEVII
	fadescreen FADE_FROM_BLACK
	setvar VAR_RECEIVED_FUCHSIA_SEVII, 1
	releaseall
	end

FuchsiaCity_PokemonCenter_1F_Movement_AideApproach::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

FuchsiaCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call Common_EventScript_PkmnCenterNurse
	release
	end

FuchsiaCity_PokemonCenter_1F_EventScript_Man::
	msgbox FuchsiaCity_PokemonCenter_1F_Text_CantBecomeGoodTrainerWithOneMon, MSGBOX_NPC
	end

FuchsiaCity_PokemonCenter_1F_EventScript_CooltrainerF::
	msgbox FuchsiaCity_PokemonCenter_1F_Text_PokemonLeagueWestOfViridian, MSGBOX_NPC
	end

FuchsiaCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox FuchsiaCity_PokemonCenter_1F_Text_VisitSafariZoneForPokedex, MSGBOX_NPC
	end

FuchsiaCity_PokemonCenter_1F_Text_CantBecomeGoodTrainerWithOneMon::
    .string "You can't become a good Trainer\n"
    .string "with just one strong Pokémon.\p"
    .string "But raising many Pokémon evenly\n"
    .string "is no easy task, either.$"

FuchsiaCity_PokemonCenter_1F_Text_PokemonLeagueWestOfViridian::
    .string "There's a narrow trail west of\n"
    .string "Viridian City.\p"
    .string "It goes to the Pokémon League HQ.\n"
    .string "The HQ governs all Trainers.$"

FuchsiaCity_PokemonCenter_1F_Text_VisitSafariZoneForPokedex::
    .string "If you're working on a Pokédex,\n"
    .string "visit the Safari Zone.\p"
    .string "All sorts of rare Pokémon breed\n"
    .string "there.$"

FuchsiaCity_PokemonCenter_1F_Text_OakSeviiResearch::
    .string "Oh, {PLAYER}! I heard about you\n"
    .string "from my colleague back in\l"
    .string "Vermilion City!\p"
    .string "I'm also one of Professor Oak's\n"
    .string "aides, studying the Pokémon of\l"
    .string "the Sevii Islands.\p"
    .string "We've turned up a few more\n"
    .string "interesting specimens since then!\p"
    .string "Go on, have your pick and help\n"
    .string "further his research!$"

FuchsiaCity_PokemonCenter_1F_Text_AideMustLeave::
    .string "Splendid choice!\p"
    .string "Do take good care of it, and\n"
    .string "I'll let the professor know how\l"
    .string "our research is coming along.\p"
    .string "Well then, I must be off.\n"
    .string "There's always more to learn!$"

