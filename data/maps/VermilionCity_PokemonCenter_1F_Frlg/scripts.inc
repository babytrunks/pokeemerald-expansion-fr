VermilionCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VermilionCity_PokemonCenter_1F_OnFrame
	.byte 0

VermilionCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_VERMILION_CITY
	end

VermilionCity_PokemonCenter_1F_OnFrame::
	map_script_2 VAR_RECEIVED_VERMILION_SEVII, 0, VermilionCity_PokemonCenter_1F_EventScript_SeviiAide
	.2byte 0

VermilionCity_PokemonCenter_1F_EventScript_SeviiAide::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	playse SE_PIN
	applymovement LOCALID_VERMILION_PC_AIDE, Common_Movement_ExclamationMark
	waitmovement 0
	waitse
	applymovement LOCALID_VERMILION_PC_AIDE, VermilionCity_PokemonCenter_1F_Movement_AideApproach
	waitmovement 0
	msgbox VermilionCity_PokemonCenter_1F_Text_OakSeviiResearch
	setflag FLAG_RARE_POKEMON_SCREEN
	setvar VAR_RARE_POKEMON_COUNTER, 3
	factory_generaterentalmons
	factory_rentmons
	waitstate
	clearflag FLAG_RARE_POKEMON_SCREEN
	clearflag FLAG_3_PERFECT_IVS
	clearflag FLAG_FORCE_SHINY
	msgbox VermilionCity_PokemonCenter_1F_Text_AideMustLeave
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_VERMILION_PC_AIDE
	setflag FLAG_RECEIVED_VERMILION_SEVII
	fadescreen FADE_FROM_BLACK
	setvar VAR_RECEIVED_VERMILION_SEVII, 1
	releaseall
	end

VermilionCity_PokemonCenter_1F_Movement_AideApproach::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

VermilionCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call Common_EventScript_PkmnCenterNurse
	release
	end

VermilionCity_PokemonCenter_1F_EventScript_Man::
	msgbox VermilionCity_PokemonCenter_1F_Text_PoisonedMonFaintedWhileWalking, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_EventScript_Hiker::
	msgbox VermilionCity_PokemonCenter_1F_Text_TrainerMonsStrongerThanWild, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox VermilionCity_PokemonCenter_1F_Text_AllMonWeakToSpecificTypes, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_EventScript_VSSeekerWoman::
	lock
	faceplayer
	@ goto_if_set FLAG_GOT_VS_SEEKER, VermilionCity_PokemonCenter_1F_EventScript_ExplainVSSeeker
	msgbox VermilionCity_PokemonCenter_1F_Text_UrgeToBattleSomeoneAgain
	@ setflag FLAG_GOT_VS_SEEKER
	@ giveitem ITEM_VS_SEEKER
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	msgbox VermilionCity_PokemonCenter_1F_Text_UseDeviceForRematches
	release
	end

VermilionCity_PokemonCenter_1F_EventScript_ExplainVSSeeker::
	msgbox VermilionCity_PokemonCenter_1F_Text_ExplainVSSeeker
	release
	end

VermilionCity_PokemonCenter_1F_Text_TrainerMonsStrongerThanWild::
    .string "Even if they are the same level,\n"
    .string "Pokémon can have very different\l"
    .string "stats and abilities.\p"
    .string "A Pokémon raised by a trainer can\n"
    .string "be stronger than one in the wild.$"

VermilionCity_PokemonCenter_1F_Text_PoisonedMonFaintedWhileWalking::
    .string "My Pokémon was poisoned!\n"
    .string "And then it dealt even more damage!\p"
    .string "Some Pokémon got Guts!$"

VermilionCity_PokemonCenter_1F_Text_AllMonWeakToSpecificTypes::
    .string "It is true that a higher-level\n"
    .string "Pokémon will be more powerful…\p"
    .string "But, all Pokémon will have weak\n"
    .string "points against specific types.\p"
    .string "So, there appears to be no\n"
    .string "universally strong Pokémon.\p"
    .string "Except Mega Rayquaza.\n"
    .string "That thing is busted!$"

VermilionCity_PokemonCenter_1F_Text_UrgeToBattleSomeoneAgain::
    .string "The urge to battle with someone\n"
    .string "you've tangled with before…\p"
    .string "Have you ever had that urge?\n"
    .string "I'm sure you have.\p"
    .string "I wanted to battle certain people\n"
    .string "again over and over, too.\p"
    .string "So, I've been giving these away.\n"
    .string "Please, take one!$"

VermilionCity_PokemonCenter_1F_Text_UseDeviceForRematches::
    .string "Use that device and you'll find\n"
    .string "Trainers looking for a rematch.\p"
    .string "You have to charge its battery to\n"
    .string "use it, though.$"

VermilionCity_PokemonCenter_1F_Text_ExplainVSSeeker::
    .string "How do you use the VS Seeker?\n"
    .string "There's nothing to it.\p"
    .string "Use it like beep-beep-beep, and\n"
    .string "Trainers around you will notice.\p"
    .string "If any Trainer wants a rematch,\n"
    .string "it will let you know immediately.\p"
    .string "Charge its battery and use it\n"
    .string "while you're on a road.$"

VermilionCity_PokemonCenter_1F_Text_OakSeviiResearch::
    .string "Oh! You must be {PLAYER}!\p"
    .string "I'm one of Professor Oak's aides.\n"
    .string "The professor's research has\l"
    .string "turned up something exciting!\p"
    .string "Interesting new Pokémon have been\n"
    .string "found residing in the Sevii Islands!\p"
    .string "Here, have your pick and help\n"
    .string "further his research!$"

VermilionCity_PokemonCenter_1F_Text_AideMustLeave::
    .string "Splendid choice!\p"
    .string "Do take good care of it, and let\n"
    .string "the professor know what you learn.\p"
    .string "Well then, I must be off.\n"
    .string "There's always research to be done!$"
