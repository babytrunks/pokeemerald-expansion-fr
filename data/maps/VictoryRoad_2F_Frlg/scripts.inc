VictoryRoad_2F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VictoryRoad_2F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_2F_OnTransition
	.byte 0

VictoryRoad_2F_OnTransition::
	call_if_eq VAR_VICTORY_ROAD_MYTHICAL, VICTORY_ROAD_MYTHICAL_UNSET, VictoryRoad_2F_EventScript_SeedMythical
	call_if_eq VAR_VICTORY_ROAD_MYTHICAL, VICTORY_ROAD_MYTHICAL_VICTINI, VictoryRoad_2F_EventScript_SetVictiniGfx
	call_if_eq VAR_VICTORY_ROAD_MYTHICAL, VICTORY_ROAD_MYTHICAL_MANAPHY, VictoryRoad_2F_EventScript_SetManaphyGfx
	call_if_eq VAR_VICTORY_ROAD_MYTHICAL, VICTORY_ROAD_MYTHICAL_ZARUDE, VictoryRoad_2F_EventScript_SetZarudeGfx
	end

@ Trainer ID mod three decides which mythical this save file starts on
VictoryRoad_2F_EventScript_SeedMythical::
	specialvar VAR_RESULT, GetPlayerTrainerIdModThree
	call_if_eq VAR_RESULT, 0, VictoryRoad_2F_EventScript_SetMythicalVictini
	call_if_eq VAR_RESULT, 1, VictoryRoad_2F_EventScript_SetMythicalManaphy
	call_if_eq VAR_RESULT, 2, VictoryRoad_2F_EventScript_SetMythicalZarude
	return

@ Called from the Champions Room so each League win brings the next one back
VictoryRoad_2F_EventScript_RespawnMythical::
	clearflag FLAG_HIDE_VICTORY_ROAD_MYTHICAL
	goto_if_eq VAR_VICTORY_ROAD_MYTHICAL, VICTORY_ROAD_MYTHICAL_VICTINI, VictoryRoad_2F_EventScript_SetMythicalManaphy
	goto_if_eq VAR_VICTORY_ROAD_MYTHICAL, VICTORY_ROAD_MYTHICAL_MANAPHY, VictoryRoad_2F_EventScript_SetMythicalZarude
	goto VictoryRoad_2F_EventScript_SetMythicalVictini

@ All three of these return to whoever called or jumped in
VictoryRoad_2F_EventScript_SetMythicalVictini::
	setvar VAR_VICTORY_ROAD_MYTHICAL, VICTORY_ROAD_MYTHICAL_VICTINI
	return

VictoryRoad_2F_EventScript_SetMythicalManaphy::
	setvar VAR_VICTORY_ROAD_MYTHICAL, VICTORY_ROAD_MYTHICAL_MANAPHY
	return

VictoryRoad_2F_EventScript_SetMythicalZarude::
	setvar VAR_VICTORY_ROAD_MYTHICAL, VICTORY_ROAD_MYTHICAL_ZARUDE
	return

VictoryRoad_2F_EventScript_SetVictiniGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES(VICTINI)
	return

VictoryRoad_2F_EventScript_SetManaphyGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES(MANAPHY)
	return

VictoryRoad_2F_EventScript_SetZarudeGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES(ZARUDE)
	return

VictoryRoad_2F_OnLoad::
	call_if_ne VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER1, 100, VictoryRoad_2F_EventScript_SetRockBarrier1
	call_if_ne VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER2, 100, VictoryRoad_2F_EventScript_SetRockBarrier2
	call_if_eq VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER1, 100, VictoryRoad_2F_EventScript_RestoreBoulder1
	call_if_eq VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER2, 100, VictoryRoad_2F_EventScript_RestoreBoulder2
	end

@ Puts each boulder back on its switch once that switch is solved
VictoryRoad_2F_EventScript_RestoreBoulder1::
	setobjectxyperm LOCALID_VICTORY_ROAD_2F_BOULDER1, 2, 19
	return

VictoryRoad_2F_EventScript_RestoreBoulder2::
	setobjectxyperm LOCALID_VICTORY_ROAD_2F_BOULDER2, 14, 19
	return

VictoryRoad_2F_EventScript_SetRockBarrier1::
	setmetatile 13, 10, METATILE_Cave_RockBarrier_Top, 1
	setmetatile 13, 11, METATILE_Cave_RockBarrier_Bottom, 1
	return

VictoryRoad_2F_EventScript_SetRockBarrier2::
	setmetatile 33, 16, METATILE_Cave_RockBarrier_Top, 1
	setmetatile 33, 17, METATILE_Cave_RockBarrier_Bottom, 1
	return

VictoryRoad_2F_EventScript_FloorSwitch1::
	lockall
	goto_if_eq VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER1, 100, VictoryRoad_2F_EventScript_FloorSwitch1AlreadyPressed
	setmetatile 13, 10, METATILE_Cave_Floor_Ledge_Top, 0
	setmetatile 13, 11, METATILE_Cave_Floor_Ledge_Bottom, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm LOCALID_VICTORY_ROAD_2F_BOULDER1
	setvar VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER1, 100
	releaseall
	end

VictoryRoad_2F_EventScript_FloorSwitch1AlreadyPressed::
	releaseall
	end

VictoryRoad_2F_EventScript_FloorSwitch2::
	lockall
	goto_if_eq VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER2, 100, VictoryRoad_2F_EventScript_FloorSwitch2AlreadyPressed
	setmetatile 33, 16, METATILE_Cave_Floor_Ledge_Top, 0
	setmetatile 33, 17, METATILE_Cave_Floor_Ledge_Bottom, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm LOCALID_VICTORY_ROAD_2F_BOULDER2
	setvar VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER2, 100
	releaseall
	end

VictoryRoad_2F_EventScript_FloorSwitch2AlreadyPressed::
	releaseall
	end

VictoryRoad_2F_EventScript_Dawson::
	trainerbattle_single TRAINER_POKEMANIAC_DAWSON, VictoryRoad_2F_Text_DawsonIntro, VictoryRoad_2F_Text_DawsonDefeat
	msgbox VictoryRoad_2F_Text_DawsonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_EventScript_Daisuke::
	trainerbattle_single TRAINER_BLACK_BELT_DAISUKE, VictoryRoad_2F_Text_DaisukeIntro, VictoryRoad_2F_Text_DaisukeDefeat
	msgbox VictoryRoad_2F_Text_DaisukePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_EventScript_Nelson::
	trainerbattle_single TRAINER_JUGGLER_NELSON, VictoryRoad_2F_Text_NelsonIntro, VictoryRoad_2F_Text_NelsonDefeat
	msgbox VictoryRoad_2F_Text_NelsonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_EventScript_Gregory::
	trainerbattle_single TRAINER_JUGGLER_GREGORY, VictoryRoad_2F_Text_GregoryIntro, VictoryRoad_2F_Text_GregoryDefeat
	msgbox VictoryRoad_2F_Text_GregoryPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_EventScript_Vincent::
	trainerbattle_single TRAINER_TAMER_VINCENT, VictoryRoad_2F_Text_VincentIntro, VictoryRoad_2F_Text_VincentDefeat
	msgbox VictoryRoad_2F_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
	end

@ Reads the same var as the on transition graphics so both always agree
VictoryRoad_2F_EventScript_Mythical::
	lock
	faceplayer
	goto_if_eq VAR_VICTORY_ROAD_MYTHICAL, VICTORY_ROAD_MYTHICAL_MANAPHY, VictoryRoad_2F_EventScript_Manaphy
	goto_if_eq VAR_VICTORY_ROAD_MYTHICAL, VICTORY_ROAD_MYTHICAL_ZARUDE, VictoryRoad_2F_EventScript_Zarude
	goto VictoryRoad_2F_EventScript_Victini
	end

VictoryRoad_2F_EventScript_Victini::
	setwildbattle SPECIES_VICTINI, 65
	waitse
	playmoncry SPECIES_VICTINI, CRY_MODE_ENCOUNTER
	message VictoryRoad_2F_Text_VictiniCry
	goto VictoryRoad_2F_EventScript_MythicalBattle
	end

VictoryRoad_2F_EventScript_Manaphy::
	setwildbattle SPECIES_MANAPHY, 65
	waitse
	playmoncry SPECIES_MANAPHY, CRY_MODE_ENCOUNTER
	message VictoryRoad_2F_Text_ManaphyCry
	goto VictoryRoad_2F_EventScript_MythicalBattle
	end

VictoryRoad_2F_EventScript_Zarude::
	setwildbattle SPECIES_ZARUDE, 65
	waitse
	playmoncry SPECIES_ZARUDE, CRY_MODE_ENCOUNTER
	message VictoryRoad_2F_Text_ZarudeCry
	goto VictoryRoad_2F_EventScript_MythicalBattle
	end

@ Every branch queues its own cry text before jumping in here
VictoryRoad_2F_EventScript_MythicalBattle::
	waitmessage
	waitmoncry
	delay 10
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, 0
	waitbuttonpress
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VictoryRoad_2F_EventScript_MythicalStays
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VictoryRoad_2F_EventScript_MythicalStays
	setflag FLAG_HIDE_VICTORY_ROAD_MYTHICAL
	goto EventScript_RemoveStaticMon
	end

@ Fleeing leaves it on the map so the player can try again
VictoryRoad_2F_EventScript_MythicalStays::
	release
	end

VictoryRoad_2F_Text_VictiniCry::
	.string "Vii!$"

VictoryRoad_2F_Text_ManaphyCry::
	.string "Fwaah!$"

VictoryRoad_2F_Text_ZarudeCry::
	.string "Gwooooh!$"

VictoryRoad_2F_EventScript_VitamaxGiver::
	lock
	faceplayer
	goto_if_set FLAG_VICTORY_ROAD_GAVE_VITAMAX, VictoryRoad_2F_EventScript_VitamaxGave
	msgbox VictoryRoad_2F_Text_VitamaxGive, MSGBOX_NPC
	giveitem ITEM_VITAMAX
	setflag FLAG_VICTORY_ROAD_GAVE_VITAMAX
	release
	end

VictoryRoad_2F_EventScript_VitamaxGave::
	msgbox VictoryRoad_2F_Text_KeepDriveGoing
	release
	end

VictoryRoad_2F_Text_VitamaxGive::
    .string "You should be proud of yourself,\n"
    .string "having battled your way through\l"
    .string "Victory Road so courageously.\p"
    .string "In recognition of your feat,\n"
    .string "take this powerful item.$"

VictoryRoad_2F_Text_KeepDriveGoing::
    .string "Keep that drive going for the\n"
    .string "Pokémon League!\p"
    .string "Take a run at them and knock 'em\n"
    .string "out!$"


VictoryRoad_2F_Text_DawsonIntro::
    .string "If you can get through here,\n"
    .string "you can go meet the Elite Four.$"

VictoryRoad_2F_Text_DawsonDefeat::
    .string "No!\n"
    .string "Unbelievable!$"

VictoryRoad_2F_Text_DawsonPostBattle::
    .string "I can beat you when it comes to\n"
    .string "knowledge about Pokémon!$"

VictoryRoad_2F_Text_DaisukeIntro::
    .string "This here is Victory Road.\n"
    .string "It's the final test for Trainers!$"

VictoryRoad_2F_Text_DaisukeDefeat::
    .string "Atcho!$"

VictoryRoad_2F_Text_DaisukePostBattle::
    .string "If you get stuck, try moving some\n"
    .string "boulders around.$"

VictoryRoad_2F_Text_NelsonIntro::
    .string "Ah, so you wish to challenge the\n"
    .string "Elite Four?$"

VictoryRoad_2F_Text_NelsonDefeat::
    .string "You got me!$"

VictoryRoad_2F_Text_NelsonPostBattle::
    .string "{RIVAL} also came through here.$"

VictoryRoad_2F_Text_VincentIntro::
    .string "Come on!\n"
    .string "I'll whip you!$"

VictoryRoad_2F_Text_VincentDefeat::
    .string "I got whipped!$"

VictoryRoad_2F_Text_VincentPostBattle::
    .string "You earned the right to be on\n"
    .string "Victory Road…$"

VictoryRoad_2F_Text_GregoryIntro::
    .string "Is Victory Road too tough?$"

VictoryRoad_2F_Text_GregoryDefeat::
    .string "Well done!$"

VictoryRoad_2F_Text_GregoryPostBattle::
    .string "Many Trainers give up their\n"
    .string "challenge here and go home.$"
