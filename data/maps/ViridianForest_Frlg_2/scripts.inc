ViridianForest_Frlg_2_MapScripts::
	.byte 0

ViridianForest_2_EventScript_ItemTMElectroweb::
	finditem ITEM_TM_ELECTROWEB
	end

Viridian_Forest_2_EventScript_Virizion::
	lock
	faceplayer
	setwildbattle SPECIES_VIRIZION, 50
	waitse
	playmoncry SPECIES_VIRIZION, CRY_MODE_ENCOUNTER
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
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Viridian_Forest_2_EventScript_DefeatedVirizion
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Viridian_Forest_2_EventScript_RanFromVirizion
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Viridian_Forest_2_EventScript_RanFromVirizion
	setflag FLAG_FOUGHT_VIRIZION
	release
	end

Viridian_Forest_2_EventScript_DefeatedVirizion::
	setflag FLAG_FOUGHT_VIRIZION
	goto EventScript_RemoveStaticMon
	end

Viridian_Forest_2_EventScript_RanFromVirizion::
	release
	end
