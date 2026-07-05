MtMoon_Extra_Frlg_MapScripts::
	.byte 0

MtMoon_Extra_EventScript_Cobalion::
	lock
	faceplayer
	setwildbattle SPECIES_COBALION, 50
	waitse
	playmoncry SPECIES_COBALION, CRY_MODE_ENCOUNTER
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
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MtMoon_Extra_EventScript_DefeatedCobalion
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MtMoon_Extra_EventScript_RanFromCobalion
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MtMoon_Extra_EventScript_RanFromCobalion
	setflag FLAG_FOUGHT_COBALION
	goto EventScript_RemoveStaticMon
	release
	end

MtMoon_Extra_EventScript_DefeatedCobalion::
	setflag FLAG_FOUGHT_COBALION
	goto EventScript_RemoveStaticMon
	end

MtMoon_Extra_EventScript_RanFromCobalion::
	release
	end
