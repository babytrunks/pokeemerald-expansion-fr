Route23_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route23_OnTransition
	.byte 0

Route23_OnTransition::
	call_if_unset FLAG_VICTORY_ROAD_PUZZLE_INIT, Route23_EventScript_InitVictoryRoadBoulders
	end

@ Seeds the Victory Road boulders once so puzzle progress can persist
Route23_EventScript_InitVictoryRoadBoulders::
	setflag FLAG_VICTORY_ROAD_PUZZLE_INIT
	clearflag FLAG_HIDE_VICTORY_ROAD_3F_BOULDER
	setflag FLAG_HIDE_VICTORY_ROAD_2F_BOULDER
	return

Route23_EventScript_CascadeBadgeGuard::
	lock
	faceplayer
	setvar VAR_TEMP_1, 2
	bufferstdstring STR_VAR_1, STDSTRING_CASCADE_BADGE
	goto Route23_EventScript_BadgeGuard
	end

Route23_EventScript_ThunderBadgeGuard::
	lock
	faceplayer
	setvar VAR_TEMP_1, 3
	bufferstdstring STR_VAR_1, STDSTRING_THUNDER_BADGE
	goto Route23_EventScript_BadgeGuard
	end

Route23_EventScript_RainbowBadgeGuard::
	lock
	faceplayer
	setvar VAR_TEMP_1, 4
	bufferstdstring STR_VAR_1, STDSTRING_RAINBOW_BADGE
	goto Route23_EventScript_BadgeGuard
	end

Route23_EventScript_SoulBadgeGuard::
	lock
	faceplayer
	setvar VAR_TEMP_1, 5
	bufferstdstring STR_VAR_1, STDSTRING_SOUL_BADGE
	goto Route23_EventScript_BadgeGuard
	end

Route23_EventScript_MarshBadgeGuard::
	lock
	faceplayer
	setvar VAR_TEMP_1, 6
	bufferstdstring STR_VAR_1, STDSTRING_MARSH_BADGE
	goto Route23_EventScript_BadgeGuard
	end

Route23_EventScript_VolcanoBadgeGuard::
	lock
	faceplayer
	setvar VAR_TEMP_1, 7
	bufferstdstring STR_VAR_1, STDSTRING_VOLCANO_BADGE
	goto Route23_EventScript_BadgeGuard
	end

Route23_EventScript_EarthBadgeGuard::
	lock
	faceplayer
	setvar VAR_TEMP_1, 8
	bufferstdstring STR_VAR_1, STDSTRING_EARTH_BADGE
	goto Route23_EventScript_BadgeGuard
	end

Route23_EventScript_CascadeBadgeGuardTrigger::
	lockall
	setvar VAR_TEMP_1, 2
	setvar VAR_0x8009, LOCALID_CASCADE_BADGE_GUARD
	bufferstdstring STR_VAR_1, STDSTRING_CASCADE_BADGE
	goto Route23_EventScript_BadgeGuardTrigger
	end

Route23_EventScript_ThunderBadgeGuardTrigger::
	lockall
	setvar VAR_TEMP_1, 3
	setvar VAR_0x8009, LOCALID_THUNDER_BADGE_GUARD
	bufferstdstring STR_VAR_1, STDSTRING_THUNDER_BADGE
	goto Route23_EventScript_BadgeGuardTrigger
	end

Route23_EventScript_RainbowBadgeGuardTrigger::
	lockall
	setvar VAR_TEMP_1, 4
	setvar VAR_0x8009, LOCALID_RAINBOW_BADGE_GUARD
	bufferstdstring STR_VAR_1, STDSTRING_RAINBOW_BADGE
	goto Route23_EventScript_BadgeGuardTrigger
	end

Route23_EventScript_SoulBadgeGuardTrigger::
	lockall
	setvar VAR_TEMP_1, 5
	setvar VAR_0x8009, LOCALID_SOUL_BADGE_GUARD
	bufferstdstring STR_VAR_1, STDSTRING_SOUL_BADGE
	goto Route23_EventScript_BadgeGuardTrigger
	end

Route23_EventScript_MarshBadgeGuardTrigger::
	lockall
	setvar VAR_TEMP_1, 6
	setvar VAR_0x8009, LOCALID_MARSH_BADGE_GUARD
	bufferstdstring STR_VAR_1, STDSTRING_MARSH_BADGE
	goto Route23_EventScript_BadgeGuardTrigger
	end

Route23_EventScript_VolcanoBadgeGuardTrigger::
	lockall
	setvar VAR_TEMP_1, 7
	setvar VAR_0x8009, LOCALID_VOLCANO_BADGE_GUARD
	bufferstdstring STR_VAR_1, STDSTRING_VOLCANO_BADGE
	goto Route23_EventScript_BadgeGuardTrigger
	end

Route23_EventScript_EarthBadgeGuardTrigger::
	lockall
	setvar VAR_TEMP_1, 8
	setvar VAR_0x8009, LOCALID_EARTH_BADGE_GUARD
	bufferstdstring STR_VAR_1, STDSTRING_EARTH_BADGE
	goto Route23_EventScript_BadgeGuardTrigger
	end

@ Brendan calls out from the south as the player reaches the Victory Road gate
Route23_EventScript_BrendanTrigger::
	lockall
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	waitse
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	setspeaker SP_NAME_BRENDAN
	msgbox gText_VRBrendanBattle_1
	closemessage
	addobject LOCALID_ROUTE_23_BRENDAN
	applymovement LOCALID_ROUTE_23_BRENDAN, Route23_Movement_BrendanApproach
	waitmovement 0
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	goto EventScript_FinalBrendan_Fight
	end

EventScript_FinalBrendan_Fight::
	setspeaker SP_NAME_BRENDAN
	msgbox gText_VRBrendanBattle_2
	@ He looks away while he vents
	applymovement LOCALID_ROUTE_23_BRENDAN, Common_Movement_FaceLeft
	waitmovement 0
	msgbox gText_VRBrendanBattle_3
	msgbox gText_VRBrendanBattle_4
	applymovement LOCALID_ROUTE_23_BRENDAN, Common_Movement_FaceUp
	waitmovement 0
	msgbox gText_VRBrendanBattle_5
	msgbox gText_VRBrendanBattle_6
	trainerbattle_no_intro TRAINER_ROUTE_23_BRENDAN, gText_VRBrendanLoss
	setspeaker SP_NAME_BRENDAN
	msgbox gText_VRBrendanBattle_7
	msgbox gText_VRBrendanBattle_8
	closemessage
	giveitem ITEM_OLD_SEA_MAP
	setspeaker SP_NAME_BRENDAN
	msgbox gText_VRBrendanBattle_9
	msgbox gText_VRBrendanBattle_10, MSGBOX_AUTOCLOSE
	fadedefaultbgm
	applymovement LOCALID_ROUTE_23_BRENDAN, Route23_Movement_BrendanLeave
	waitmovement 0
	removeobject LOCALID_ROUTE_23_BRENDAN
	setvar VAR_MAP_SCENE_ROUTE23_BRENDAN, 1
	releaseall
	end

@ Runs up the corridor from 5, 37 to stand below the player at 5, 30
Route23_Movement_BrendanApproach::
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	face_up
	step_end

Route23_Movement_BrendanLeave::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

gText_VRBrendanBattle_1::
	.string "Oi, wait up!$"

gText_VRBrendanBattle_2::
	.string "Hey, it's me again…\p"
	.string "Sorry I couldn't help you further\n"
	.string "in Cerulean Cave.\p"
	.string "I got destroyed by Archer and ran\n"
	.string "away in shame…$"

gText_VRBrendanBattle_3::
	.string "You know recently…\p"
	.string "I don't know, I know I'm not a\n"
	.string "bad Trainer by any means.\p"
	.string "I can snag Gym badges sure,\n"
	.string "but I've always wanted to be an\l"
	.string "incredible Trainer like my Dad.\p"
	.string "And I really thought that as long\n"
	.string "as I put in the effort and work,\l"
	.string "I could be one of the best.\p"
	.string "But, I could never put a dent\n"
	.string "in you.\p"
	.string "Even Trainers like Archer have\n"
	.string "shown me how far the gap between\l"
	.string "us has become.\p"
	.string "It's becoming clear to me that I'm\n"
	.string "just not very strong,\l"
	.string "let alone talented.$"

gText_VRBrendanBattle_4::
	.string "Is that what I'm missing?\p"
	.string "An innate trait that some are just\n"
	.string "gifted with?\p"
	.string "I just can't accept that…$"

gText_VRBrendanBattle_5::
	.string "Agh! I'm not sure what\n"
	.string "I'm trying to say.$"

gText_VRBrendanBattle_6::
	.string "I don't care.\n"
	.string "{PLAYER}!\p"
	.string "We're battling.\p"
	.string "I won't take no for an answer!$"

gText_VRBrendanLoss::
	.string "Not sure what I was\n"
	.string "expecting…$"

gText_VRBrendanBattle_7::
	.string "I… I don't know.\p"
	.string "I'm discouraged. I know I shouldn't\n"
	.string "have shot for the stars, but…$"

gText_VRBrendanBattle_8::
	.string "The bottom line is I have a lot\n"
	.string "to learn.\p"
	.string "Some things require my attention in\n"
	.string "Hoenn, so I'll be returning now.\p"
	.string "Maybe I'll come back sometime.\p"
	.string "Or you could come visit,\n"
	.string "if you'd like.\p"
	.string "I know, somehow, our paths will\n"
	.string "cross again.\p"
	.string "I still must thank you for always\n"
	.string "pushing me to my limit.\p"
	.string "Please, take this.$"

gText_VRBrendanBattle_9::
	.string "The Old Sea Map will take you to a\n"
	.string "distant island.\p"
	.string "A powerful foe awaits you there.$"

gText_VRBrendanBattle_10::
	.string "So long, friend.$"

Route23_EventScript_VictoryRoadGateSign::
	msgbox Route23_Text_VictoryRoadGateSign, MSGBOX_SIGN
	end

Route23_Text_VictoryRoadGateSign::
    .string "Victory Road Gate -\n"
    .string "Pokémon League$"

