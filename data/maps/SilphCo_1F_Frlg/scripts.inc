SilphCo_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SilphCo_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SilphCo_1F_OnFrame
	.byte 0

SilphCo_1F_OnLoad::
	call_if_ge VAR_SILPH_CO_GHOST_QUEST, 3, SilphCo_1F_EventScript_PlaceTeleporter
	end

@ The pad is plain floor in the layout until the specialist uncovers it
SilphCo_1F_EventScript_PlaceTeleporter::
	setmetatile 35, 20, 0x390, 0
	return

SilphCo_1F_OnFrame::
	map_script_2 VAR_SILPH_CO_GHOST_QUEST, 2, SilphCo_1F_EventScript_GhostGirlScene
	.2byte 0

SilphCo_1F_EventScript_PoliceMan::
SilphCo_1F_OnTrigger_PoliceMan::
	lock
	goto_if_eq VAR_SILPH_CO_POLICEMAN_GAVE_MEGA_RING, 1, SilphCo_1F_EventScript_PoliceMan_GaveRing
	playse SE_PIN
	applymovement LOCALID_SILPHCO_POLICEMAN, SilphCo1F_Movement_PoliceMan
	waitmovement 
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement
	waitse
	msgbox SilphCo_1F_Text_OhThankHeavens
	giveitem ITEM_MEGA_RING
	setvar VAR_SILPH_CO_POLICEMAN_GAVE_MEGA_RING 1
	release
	end

SilphCo1F_Movement_PoliceMan::
	emote_exclamation_mark
	face_player
	step_end

EventScript_SilphCo_Growlithe::
	lock
	faceplayer
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
	msgbox SilphCo_1F_Text_Growlithe
	release
	end

SilphCo_1F_EventScript_PoliceMan_GaveRing:
	lock
	faceplayer
	msgbox SilphCo_1F_Text_DontGetPaid
	release
	end

SilphCo_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SILPH_CO_1F
	@ Flags start clear so she has to be hidden every load but her one scene
	call_if_ne VAR_SILPH_CO_GHOST_QUEST, 2, SilphCo_1F_EventScript_HideGhostGirl
	call_if_eq VAR_SILPH_CO_GHOST_QUEST, 2, SilphCo_1F_EventScript_ShowGhostGirl
	end

SilphCo_1F_EventScript_HideGhostGirl::
	setflag FLAG_HIDE_SILPH_CO_GHOST_SPECIAL
	return

SilphCo_1F_EventScript_ShowGhostGirl::
	clearflag FLAG_HIDE_SILPH_CO_GHOST_SPECIAL
	return

SilphCo_1F_EventScript_GhostGirlScene::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SilphCo_1F_Text_GhostGirlFoundTeleporter
	closemessage
	playse SE_PIN
	applymovement LOCALID_SILPH_CO_GHOST_SPECIAL, Common_Movement_ExclamationMark
	waitmovement 0
	waitse
	applymovement LOCALID_SILPH_CO_GHOST_SPECIAL, Common_Movement_FaceRight
	waitmovement 0
	playse SE_M_TELEPORT
	setmetatile 35, 20, 0x390, 0
	special DrawWholeMapView
	waitse
	applymovement LOCALID_SILPH_CO_GHOST_SPECIAL, Common_Movement_FaceLeft
	waitmovement 0
	msgbox SilphCo_1F_Text_GhostGirlDealWithItYourself
	closemessage
	setvar VAR_SILPH_CO_GHOST_QUEST, 3
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_SILPH_CO_GHOST_SPECIAL
	removeobject LOCALID_SILPH_CO_GHOST_SPECIAL
	fadescreen FADE_TO_BLACK
	releaseall
	end

@ Only reachable by talking to her before the scene finishes
SilphCo_1F_EventScript_GhostGirl::
	lock
	faceplayer
	msgbox SilphCo_1F_Text_GhostGirlDealWithItYourself
	release
	end

SilphCo_1F_EventScript_Receptionist::
	msgbox SilphCo_1F_Text_WelcomePresidentInBoardroom, MSGBOX_NPC
	end

SilphCo_1F_EventScript_FloorSign::
	msgbox SilphCo_1F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_1F_Text_GhostGirlFoundTeleporter::
    .string "Uh…\p"
    .string "I detected something was wrong on\n"
    .string "this floor.\p"
    .string "But I wasn't expecting a hidden\n"
    .string "teleporter…$"

SilphCo_1F_Text_GhostGirlDealWithItYourself::
    .string "Someone strong looms in there.\p"
    .string "I have done my job, so I'll go back\n"
    .string "to Lavender.\p"
    .string "Deal with it yourself.$"

SilphCo_1F_Text_WelcomePresidentInBoardroom::
    .string "Welcome.\p"
    .string "The President is in the boardroom\n"
    .string "on 11F.$"

SilphCo_1F_Text_FloorSign::
    .string "Silph Co. Head Office\n"
    .string "1F$"

SilphCo_1F_Text_DontGetPaid::
	.string "Hey, don't look at me to fix this.\n"
	.string "I'm just a regular policeman, not the\l"
	.string "main character.$"

SilphCo_1F_Text_OhThankHeavens::
	.string "Oh thank Arceus, you got quite\n"
	.string "a few Gym Badges. There's a ruckus\l"
	.string "going on upstairs with Team Rocket.\p"
	.string "Me and my level 20 Growlithe can't\n"
	.string "handle this, but maybe you could.\p"
	.string "One of their scientists dropped this,\n"
	.string "maybe you could put it to use.$"

SilphCo_1F_Text_Growlithe::
	.string "Ruff ruff!$"
