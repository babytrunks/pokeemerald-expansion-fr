RockTunnel_Extra_Frlg_MapScripts::
	@ map_script MAP_SCRIPT_ON_TRANSITION, RockTunnel_Extra_OnTransition
	@ map_script MAP_SCRIPT_ON_RESUME, RockTunnel_Extra_OnResume
	.byte 0

RockTunnel_Extra_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, RockTunnel_Extra_EventScript_TryRemoveTerrakion
	end

RockTunnel_Extra_EventScript_TryRemoveTerrakion::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

RockTunnel_Extra_OnTransition::
	call_if_unset FLAG_FOUGHT_TERRAKION, RockTunnel_Extra_EventScript_ShowTerrakion
	end

RockTunnel_Extra_EventScript_ShowTerrakion::
	clearflag FLAG_HIDE_TERRAKION
	return


RockTunnel_Extra_EventScript_Terrakion::
	lock
	faceplayer
	setwildbattle SPECIES_TERRAKION, 50
	waitse
	playmoncry SPECIES_TERRAKION, CRY_MODE_ENCOUNTER
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
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, RockTunnel_Extra_EventScript_DefeatedTerrakion
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, RockTunnel_Extra_EventScript_RanFromTerrakion
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, RockTunnel_Extra_EventScript_RanFromTerrakion
	setflag FLAG_FOUGHT_TERRAKION
	release
	end

RockTunnel_Extra_EventScript_DefeatedTerrakion::
	setflag FLAG_FOUGHT_TERRAKION
	goto EventScript_RemoveStaticMon
	end

RockTunnel_Extra_EventScript_RanFromTerrakion::
	release
	end
