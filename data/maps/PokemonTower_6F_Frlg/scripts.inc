PokemonTower_6F_Frlg_MapScripts::
	.byte 0

PokemonTower_6F_EventScript_MarowakGhost::
	lockall
	textcolor NPC_TEXT_COLOR_MON
	msgbox PokemonTower_6F_Text_BeGoneIntruders
	checkitem ITEM_SILPH_SCOPE
	goto_if_eq VAR_RESULT, TRUE, StartMarowakTotemBattle
	setwildbattle SPECIES_MAROWAK, 40
	special StartMarowakBattle
	waitstate
	goto_if_eq VAR_RESULT, FALSE, PokemonTower_6F_EventScript_DefeatedMarowakGhost  @ VAR_RESULT set by CB2_EndMarowakBattle
	applymovement LOCALID_PLAYER, PokemonTower_6F_Movement_ForcePlayerUp
	waitmovement 0
	releaseall
	end

StartMarowakTotemBattle::
	setflag FLAG_DONT_RANDOMIZE
	setflag FLAG_CANT_CATCH
	setvar VAR_PRESET_TOTEM_BOSS BOSS_POKEMON_TOWER_MAROWAK
	settotemboost B_POSITION_OPPONENT_LEFT, 2, 2, 2, 0, 2
	setwildbattle SPECIES_MAROWAK_ALOLA, 36, ITEM_THICK_CLUB, SPECIES_BASCULEGION_F, 36, ITEM_COLBUR_BERRY
	createmon 1, 0, SPECIES_MAROWAK_ALOLA, 39, ITEM_THICK_CLUB, 0, NATURE_ADAMANT, 1, MON_FEMALE, 0, 0, 0, 0 , 0, 0, 31, 31, 31, 31, 31, 31, MOVE_BONEMERANG, MOVE_FIRE_PUNCH, MOVE_SHADOW_BONE, MOVE_THUNDER_PUNCH, FALSE, FALSE, 0, 0  
	createmon 1, 1, SPECIES_BASCULEGION_F, 36, ITEM_COLBUR_BERRY, 0, NATURE_MODEST, 1, MON_MALE, 0, 0, 0, 0 , 0, 0, 31, 31, 31, 31, 31, 31, MOVE_SHADOW_BALL, MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_AQUA_JET, TRUE, FALSE, 0, 0  	
	@ callnative CreateTotemPartnerHaunter
	setwildonevstwo
	dowildbattle
	clearflag FLAG_DONT_RANDOMIZE
	clearflag FLAG_CANT_CATCH
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PokemonTower_6F_EventScript_DefeatedMarowakGhost
	applymovement LOCALID_PLAYER, PokemonTower_6F_Movement_ForcePlayerUp
	waitmovement 0
	releaseall
	end

PokemonTower_6F_EventScript_DefeatedMarowakGhost::
	message PokemonTower_6F_Text_GhostWasCubonesMother
	waitmessage
	waitse
	playmoncry SPECIES_MAROWAK, CRY_MODE_NORMAL
	waitbuttonpress
	waitmoncry
	msgbox PokemonTower_6F_Text_MothersSpiritWasCalmed
	setflag FLAG_DEFEATED_MAROWAK_GHOST
	setvar VAR_MAP_SCENE_POKEMON_TOWER_6F, 1
	releaseall
	end

PokemonTower_6F_Movement_ForcePlayerUp::
	walk_up
	step_end

PokemonTower_6F_EventScript_Angelica::
	trainerbattle_single TRAINER_CHANNELER_ANGELICA, PokemonTower_6F_Text_AngelicaIntro, PokemonTower_6F_Text_AngelicaDefeat
	msgbox PokemonTower_6F_Text_AngelicaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_6F_EventScript_Emilia::
	trainerbattle_single TRAINER_CHANNELER_EMILIA, PokemonTower_6F_Text_EmiliaIntro, PokemonTower_6F_Text_EmiliaDefeat
	msgbox PokemonTower_6F_Text_EmiliaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_6F_EventScript_Jennifer::
	trainerbattle_single TRAINER_CHANNELER_JENNIFER, PokemonTower_6F_Text_JenniferIntro, PokemonTower_6F_Text_JenniferDefeat
	msgbox PokemonTower_6F_Text_JenniferPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_6F_Text_AngelicaIntro::
    .string "Give…me…\n"
    .string "blood…$"

PokemonTower_6F_Text_AngelicaDefeat::
    .string "Groan!$"

PokemonTower_6F_Text_AngelicaPostBattle::
    .string "I feel anemic and weak…$"

PokemonTower_6F_Text_EmiliaIntro::
    .string "Urff…\n"
    .string "Kwaah!$"

PokemonTower_6F_Text_EmiliaDefeat::
    .string "Something fell out!$"

PokemonTower_6F_Text_EmiliaPostBattle::
    .string "My hair didn't fall out!\n"
    .string "It was a malevolent spirit!$"

PokemonTower_6F_Text_JenniferIntro::
    .string "Ke…ke…ke…\n"
    .string "ke…ke…ke!$"

PokemonTower_6F_Text_JenniferDefeat::
    .string "Keee!$"

PokemonTower_6F_Text_JenniferPostBattle::
    .string "What's going on here?$"

PokemonTower_6F_Text_BeGoneIntruders::
    .string "Be gone…\n"
    .string "Intruders…$"

PokemonTower_6F_Text_GhostWasCubonesMother::
    .string "The ghost was the restless spirit\n"
    .string "of CUBONE's mother!$"

PokemonTower_6F_Text_MothersSpiritWasCalmed::
    .string "The mother's spirit was calmed.\p"
    .string "It departed to the afterlife…$"

