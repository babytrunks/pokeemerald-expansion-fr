RockTunnel_Extra_Frlg_MapScripts::
	@ map_script MAP_SCRIPT_ON_TRANSITION, RockTunnel_Extra_OnTransition
	@ map_script MAP_SCRIPT_ON_RESUME, RockTunnel_Extra_OnResume
	map_script MAP_SCRIPT_ON_LOAD, RockTunnel_Extra_LoadTiles
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

RockTunnel_Extra_LoadTiles::
	call_if_eq VAR_ROCK_TUNNEL_EXTRA_STRENGTH_1, 100, RockTunnel_Extra_ClearRockPath1
	call_if_eq VAR_ROCK_TUNNEL_EXTRA_STRENGTH_2, 100, RockTunnel_Extra_ClearRockPath2
	call_if_eq VAR_ROCK_TUNNEL_EXTRA_STRENGTH_3, 100, RockTunnel_Extra_ClearRockPath3
	end

RockTunnel_Extra_ClearRockPath1:
    setmetatile 0x1B, 0x1E, 0x281, 0x0  
    setmetatile 0x1B, 0x1F, 0x281, 0x0
    setmetatile 0x1C, 0x1E, 0x281, 0x0
    setmetatile 0x1C, 0x1F, 0x281, 0x0
	setobjectxyperm LOCALID_ROCK_TUNNEL_EXTRA_BOULDER_1, 1, 18
	return


RockTunnel_Extra_ClearRockPath2:
    setmetatile 0x1F, 0x07, 0x281, 0x0  @ verify correct metatile for Rock Tunnel floor
    setmetatile 0x1F, 0x08, 0x281, 0x0
    setmetatile 0x20, 0x07, 0x281, 0x0
    setmetatile 0x20, 0x08, 0x281, 0x0
	setobjectxyperm LOCALID_ROCK_TUNNEL_EXTRA_BOULDER_2, 29, 19
	return

RockTunnel_Extra_ClearRockPath3:
    setmetatile 0x5, 0xB, 0x281, 0x0  @ verify correct metatile for Rock Tunnel floor
    setmetatile 0x5, 0xC, 0x281, 0x0
    setmetatile 0x6, 0xB, 0x281, 0x0
    setmetatile 0x6, 0xC, 0x281, 0x0
	setobjectxyperm LOCALID_ROCK_TUNNEL_EXTRA_BOULDER_3, 41, 1
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
	setflag FLAG_HIDE_TERRAKION
	goto EventScript_RemoveStaticMon
	release
	end

RockTunnel_Extra_EventScript_DefeatedTerrakion::
	setflag FLAG_FOUGHT_TERRAKION
	goto EventScript_RemoveStaticMon
	end

RockTunnel_Extra_EventScript_RanFromTerrakion::
	release
	end

RockTunnel_Extra_EventScript_Heatran::
	lock
	faceplayer
	setwildbattle SPECIES_HEATRAN, 50
	waitse
	playmoncry SPECIES_HEATRAN, CRY_MODE_ENCOUNTER
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
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, RockTunnel_Extra_EventScript_DefeatedHeatran
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, RockTunnel_Extra_EventScript_RanFromHeatran
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, RockTunnel_Extra_EventScript_RanFromHeatran
	setflag FLAG_FOUGHT_HEATRAN
	release
	end

RockTunnel_Extra_EventScript_DefeatedHeatran::
	setflag FLAG_FOUGHT_HEATRAN
	goto EventScript_RemoveStaticMon
	end

RockTunnel_Extra_EventScript_RanFromHeatran::
	release
	end

EventScript_StrengthTile1::
    setmetatile 0x1B, 0x1E, 0x281, 0x0  @ verify correct metatile for Rock Tunnel floor
    setmetatile 0x1B, 0x1F, 0x281, 0x0
    setmetatile 0x1C, 0x1E, 0x281, 0x0
    setmetatile 0x1C, 0x1F, 0x281, 0x0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm LOCALID_ROCK_TUNNEL_EXTRA_BOULDER_1
	setvar VAR_ROCK_TUNNEL_EXTRA_STRENGTH_1, 100
    releaseall
    end

EventScript_StrengthTile2::
    setmetatile 0x1F, 0x07, 0x281, 0x0  @ verify correct metatile for Rock Tunnel floor
    setmetatile 0x1F, 0x08, 0x281, 0x0
    setmetatile 0x20, 0x07, 0x281, 0x0
    setmetatile 0x20, 0x08, 0x281, 0x0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm LOCALID_ROCK_TUNNEL_EXTRA_BOULDER_2
	setvar VAR_ROCK_TUNNEL_EXTRA_STRENGTH_2, 100
    releaseall
    end

EventScript_StrengthTile3::
    setmetatile 0x5, 0xB, 0x281, 0x0  @ verify correct metatile for Rock Tunnel floor
    setmetatile 0x5, 0xC, 0x281, 0x0
    setmetatile 0x6, 0xB, 0x281, 0x0
    setmetatile 0x6, 0xC, 0x281, 0x0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm LOCALID_ROCK_TUNNEL_EXTRA_BOULDER_3
	setvar VAR_ROCK_TUNNEL_EXTRA_STRENGTH_3, 100
    releaseall
    end


RockTunnelExtra_EventScript_Coats::
    lock
    faceplayer
	goto_if_set FLAG_DEFEATED_ROCK_TUNNEL_EXTRA_COATS, EventScript_Coats_Defeated
    msgbox gText_coats_askChallenge, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, 1, EventScript_Coats_Battle
    @ msgbox gText_coats_Reject
    release
    end

EventScript_Coats_Battle::
    setspeaker SP_NAME_UNKNOWN
    msgbox gText_coats_2
    @ special HealPlayerParty                 
	trainerbattle_no_intro TRAINER_ROCK_TUNNEL_COATS, coats_Text_Defeat  
    setflag FLAG_DEFEATED_ROCK_TUNNEL_EXTRA_COATS
    msgbox gText_coats_3
    giveitem ITEM_GOLURKITE      
	msgbox gText_coats_4
	waitbuttonpress                             
    release
    end

EventScript_Coats_Defeated::
	msgbox gText_coats_4
EventScript_Coats_Releasend:
	release
	end


gText_coats_askChallenge::
  .string "I hear there is a legendary Pokémon\n"
  .string "in this area. I'd like to hone\l"
  .string "my skills before encountering it.\p"
  .string "Would you like a battle? Just a heads\n"
  .string "up, I specialize in doubles.\p"

gText_coats_Reject::
  .string "Fine, I'll see you around, maybe?$"


coats_Text_Defeat::
	.string "Well then, it looks like I wasn't\n"
	.string "ready for you!$"

gText_coats_2::
	.string "Alrighty, I'll even put a Mega Stone\n"
	.string "on the line. As a trainer, you have\l"
	.string "to be ready for anything!$"

gText_coats_3::
	.string "A good trainer keeps to his word.\p"
	.string "Take this."

gText_coats_4::
	.string "Mega Golurk packs a mean punch. Use\n"
	.string "it well!$"
