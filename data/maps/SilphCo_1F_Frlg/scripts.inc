SilphCo_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SilphCo_1F_OnTransition
	.byte 0

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
	end

SilphCo_1F_EventScript_Receptionist::
	msgbox SilphCo_1F_Text_WelcomePresidentInBoardroom, MSGBOX_NPC
	end

SilphCo_1F_EventScript_FloorSign::
	msgbox SilphCo_1F_Text_FloorSign, MSGBOX_SIGN
	end

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
