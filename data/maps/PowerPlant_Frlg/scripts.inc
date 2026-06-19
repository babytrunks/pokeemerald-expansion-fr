PowerPlant_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PowerPlant_OnTransition
	.byte 0

PowerPlant_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_POWER_PLANT
	call_if_unset FLAG_FOUGHT_POWER_PLANT_ELECTRODE_1, PowerPlant_EventScript_ShowElectrode1
	call_if_unset FLAG_FOUGHT_POWER_PLANT_ELECTRODE_2, PowerPlant_EventScript_ShowElectrode2
	gettimeofday
	call_if_eq VAR_0x8000, TIME_NIGHT, PowerPlant_OnTransition_NightZapdos
	call_if_ne VAR_0x8000, TIME_NIGHT, PowerPlant_OnTransition_DayZapdos

	goto_if_set FLAG_FOUGHT_ZAPDOS, PowerPlant_OnTransition_HideZapdos
	end

PowerPlant_OnTransition_NightZapdos::
	setflag FLAG_HIDE_ZAPDOS
	clearflag FLAG_HIDE_ZAPDOS_GALAR
	return

PowerPlant_OnTransition_HideZapdos::
	setflag FLAG_HIDE_ZAPDOS
	setflag FLAG_HIDE_ZAPDOS_GALAR
	end

PowerPlant_OnTransition_DayZapdos:
	clearflag FLAG_HIDE_ZAPDOS
	setflag FLAG_HIDE_ZAPDOS_GALAR
	return


PowerPlant_EventScript_ShowElectrode1::
	clearflag FLAG_HIDE_POWER_PLANT_ELECTRODE_1
	return

PowerPlant_EventScript_ShowElectrode2::
	clearflag FLAG_HIDE_POWER_PLANT_ELECTRODE_2
	return

PowerPlant_EventScript_Zapdos::
	lock
	faceplayer
	setwildbattle SPECIES_ZAPDOS, 50
	waitse
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
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
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PowerPlant_EventScript_DefeatedZapdos
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PowerPlant_EventScript_RanFromZapdos
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PowerPlant_EventScript_RanFromZapdos
	setflag FLAG_FOUGHT_ZAPDOS
	release
	end

PowerPlant_EventScript_DefeatedZapdos::
	setflag FLAG_FOUGHT_ZAPDOS
	goto EventScript_RemoveStaticMon
	end

PowerPlant_EventScript_RanFromZapdos::
	@ setvar VAR_0x8004, SPECIES_ZAPDOS
	@ goto EventScript_MonFlewAway
	release
	end

PowerPlant_EventScript_ZapdosGalar::
	lock
	faceplayer
	setwildbattle SPECIES_ZAPDOS_GALAR, 50
	waitse
	playmoncry SPECIES_ZAPDOS_GALAR, CRY_MODE_ENCOUNTER
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
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PowerPlant_EventScript_DefeatedZapdosGalar
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PowerPlant_EventScript_RanFromZapdosGalar
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PowerPlant_EventScript_RanFromZapdosGalar
	setflag FLAG_FOUGHT_ZAPDOS
	release
	end

PowerPlant_EventScript_DefeatedZapdosGalar::
	setflag FLAG_FOUGHT_ZAPDOS
	goto EventScript_RemoveStaticMon
	end

PowerPlant_EventScript_RanFromZapdosGalar::
	setvar VAR_0x8004, SPECIES_ZAPDOS_GALAR
	goto EventScript_MonFlewAway
	end

PowerPlant_EventScript_Electrode1::
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 34
	waitse
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PowerPlant_EventScript_FoughtElectrode1
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PowerPlant_EventScript_FoughtElectrode1
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PowerPlant_EventScript_FoughtElectrode1
	setflag FLAG_FOUGHT_POWER_PLANT_ELECTRODE_1
	release
	end

PowerPlant_EventScript_FoughtElectrode1::
	setflag FLAG_FOUGHT_POWER_PLANT_ELECTRODE_1
	goto EventScript_RemoveStaticMon
	end

PowerPlant_EventScript_Electrode2::
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 34
	waitse
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PowerPlant_EventScript_FoughtElectrode2
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PowerPlant_EventScript_FoughtElectrode2
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PowerPlant_EventScript_FoughtElectrode2
	setflag FLAG_FOUGHT_POWER_PLANT_ELECTRODE_2
	release
	end

PowerPlant_EventScript_FoughtElectrode2::
	setflag FLAG_FOUGHT_POWER_PLANT_ELECTRODE_2
	goto EventScript_RemoveStaticMon
	end

PowerPlant_EventScript_JojoFan::
    lockall
    faceplayer
    setspeaker SP_NAME_UNKNOWN
    msgbox gText_jojo_fan_askChallenge, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, 1, EventScript_JojoFan_Battle
    msgbox gText_jojo_fan_Reject
    release
    end

EventScript_JojoFan_Battle::
    setspeaker SP_NAME_UNKNOWN
    msgbox gText_jojo_fan_2
    @ special HealPlayerParty                 
    setflag FLAG_ZA_WARUDO_BATTLE
	trainerbattle_no_intro TRAINER_POWER_PLANT_JOJO_FAN, jojo_fan_Text_Defeat  
    setflag FLAG_DEFEATED_POWER_PLANT_JOJO_FAN
	clearflag FLAG_ZA_WARUDO_BATTLE
	setspeaker SP_NAME_JOJO_FAN
    msgbox gText_jojo_fan_3
    giveitem ITEM_TM_CLOSE_COMBAT
    setspeaker SP_NAME_JOJO_FAN
    msgbox gText_jojo_fan_4
	givemon SPECIES_OGERPON, 55, ITEM_CORNERSTONE_MASK
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, EventScript_JojoFan_ReceiveOgerponParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, EventScript_JojoFan_ReceiveOgerponPC
	@ goto_if_eq VAR_RESULT, MON_CANT_GIVE, Common_EventScript_NoMoreRoomForPokemon
	end

EventScript_JojoFan_ReceiveOgerponParty::
	playfanfare MUS_LEVEL_UP
	message gText_jojo_fan_5
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_OGERPON
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_JojoFan_LeaveScene
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto EventScript_JojoFan_LeaveScene
	end

EventScript_JojoFan_ReceiveOgerponPC::
	playfanfare MUS_LEVEL_UP
	message gText_jojo_fan_5
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_OGERPON
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_JojoFan_OgerponTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto EventScript_JojoFan_OgerponTransferredToPC
	end

EventScript_JojoFan_OgerponTransferredToPC::
	bufferspeciesname STR_VAR_1, SPECIES_OGERPON
	goto EventScript_JojoFan_LeaveScene
	end

EventScript_JojoFan_LeaveScene::
	msgbox gText_jojo_fan_6
    fadescreen FADE_TO_BLACK
    playse SE_EXIT
    waitse
    removeobject LOCALID_POWER_PLANT_JOJO_FAN
    fadescreen FADE_FROM_BLACK
    release
    end


gText_jojo_fan_askChallenge::
  .string "Ho… Are you approaching me?$"

gText_jojo_fan_Reject::
  .string "Heh, my aura frightens you, doesn't it?$"

gText_jojo_fan_2::
	.string "Ho… Then come as close as you'd\n"
	.string "like!$"

jojo_fan_Text_Defeat::
	.string "Yare yare daze…$"

gText_jojo_fan_3::
	.string "How could my team of Jojo references\n"
	.string "lose?!\p"
	.string "Sugoi. Take this.$"

gText_jojo_fan_4::
	.string "Not just that, let me give you the\n"
	.string "Pokémon capable of wearing the\l"
	.string "Stone Mask.$"

gText_jojo_fan_5::
	.string "You received an Ogerpon!$"

gText_jojo_fan_6::
	.string "That's all I got, baka.\n"
	.string "See you around, I guess.$"
