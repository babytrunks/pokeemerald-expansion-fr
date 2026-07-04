SafariZone_Extra_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SafariZoneExtra_OnTransition
	.byte 0

SafariZoneExtra_OnTransition:
	gettimeofday
	call_if_eq VAR_0x8000, TIME_NIGHT, SafariZoneExtra_OnTransition_NightMoltres
	call_if_ne VAR_0x8000, TIME_NIGHT, SafariZoneExtra_OnTransition_DayMoltres
	goto_if_set FLAG_FOUGHT_MOLTRES, SafariZoneExtra_OnTransition_HideMoltres
	end

SafariZoneExtra_OnTransition_HideMoltres::
	setflag FLAG_HIDE_MOLTRES
	setflag FLAG_HIDE_MOLTRES_GALAR
	end

SafariZoneExtra_OnTransition_NightMoltres::
	setflag FLAG_HIDE_MOLTRES
	clearflag FLAG_HIDE_MOLTRES_GALAR
	return

SafariZoneExtra_OnTransition_DayMoltres::
	setflag FLAG_HIDE_MOLTRES_GALAR
	clearflag FLAG_HIDE_MOLTRES
	return

SafariZoneExtra_EventScript_Moltres::
	lock
	faceplayer
	setwildbattle SPECIES_MOLTRES, 50
	waitse
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
	message Text_Gyaoo
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
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SafariZoneExtra_EventScript_DefeatedMoltres
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SafariZoneExtra_EventScript_RanFromMoltres
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SafariZoneExtra_EventScript_RanFromMoltres
	setflag FLAG_FOUGHT_MOLTRES
	goto EventScript_RemoveStaticMon
	release
	end

SafariZoneExtra_EventScript_DefeatedMoltres::
	setflag FLAG_FOUGHT_MOLTRES
	goto EventScript_RemoveStaticMon
	end

SafariZoneExtra_EventScript_RanFromMoltres::
	@ setvar VAR_0x8004, SPECIES_MOLTRES
	@ goto EventScript_MonFlewAway
	release
	end


SafariZoneExtra_EventScript_MoltresGalar::
	lock
	faceplayer
	setwildbattle SPECIES_MOLTRES_GALAR, 50
	waitse
	playmoncry SPECIES_MOLTRES_GALAR, CRY_MODE_ENCOUNTER
	message Text_Gyaoo
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
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SafariZoneExtra_EventScript_DefeatedMoltresGalar
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SafariZoneExtra_EventScript_RanFromMoltresGalar
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SafariZoneExtra_EventScript_RanFromMoltresGalar
	setflag FLAG_FOUGHT_MOLTRES
	goto EventScript_RemoveStaticMon
	release
	end

SafariZoneExtra_EventScript_DefeatedMoltresGalar::
	setflag FLAG_FOUGHT_MOLTRES
	goto EventScript_RemoveStaticMon
	end

SafariZoneExtra_EventScript_RanFromMoltresGalar::
	@ setvar VAR_0x8004, SPECIES_MOLTRES
	@ goto EventScript_MonFlewAway
	release
	end
