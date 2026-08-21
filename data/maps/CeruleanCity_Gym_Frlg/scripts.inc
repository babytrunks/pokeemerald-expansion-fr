CeruleanCity_Gym_Frlg_MapScripts::
    map_script MAP_SCRIPT_ON_FRAME_TABLE, CeruleanCity_Gym_OnFrame
	.byte 0

CeruleanCity_Gym_OnFrame:
    map_script_2 VAR_MAP_SCENE_PEWTER_CITY_GYM, 2, EventScript_CeruleanCityGym_GymGuyFeathers
	.2byte 0

CeruleanCity_Gym_EventScript_Misty::
    setspeaker SP_NAME_MISTY
	famechecker FAMECHECKER_MISTY, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_MISTY, CeruleanCity_Gym_Text_MistyIntro, CeruleanCity_Gym_Text_MistyDefeat, CeruleanCity_Gym_EventScript_MistyDefeated, NO_MUSIC
    goto_if_unset FLAG_BADGE02_GET, CeruleanCity_Gym_EventScript_GiveTM54
    setspeaker SP_NAME_MISTY
	msgbox CeruleanCity_Gym_Text_ExplainTM54
	release
	end

CeruleanCity_Gym_EventScript_MistyDefeated::
	famechecker FAMECHECKER_MISTY, 1
	setflag FLAG_BADGE02_GET
	setrespawn HEAL_LOCATION_CERULEAN_CITY
	set_gym_trainers_frlg 2
	goto CeruleanCity_Gym_EventScript_GiveTM54
	end

CeruleanCity_Gym_EventScript_GiveTM54::
    callnative SetBuffer1ToLevelCap
    setspeaker SP_NAME_MISTY
	msgbox CeruleanCity_Gym_Text_ExplainCascadeBadge
	giveitem ITEM_TM_FLIP_TURN
    setspeaker SP_NAME_MISTY
	msgbox CeruleanCity_Gym_Text_ExplainTM54
    applymovement LOCALID_PLAYER, Common_Movement_FaceDown
    waitmovement 0
    call_if_set FLAG_AUTOSAVE_ENABLED, Common_EventScript_AutoSave
	release
	end

CeruleanCity_Gym_EventScript_Diana::
	trainerbattle_single TRAINER_PICNICKER_DIANA, CeruleanCity_Gym_Text_DianaIntro, CeruleanCity_Gym_Text_DianaDefeat
	msgbox CeruleanCity_Gym_Text_DianaPostBattle, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_Luis::
	trainerbattle_single TRAINER_SWIMMER_MALE_LUIS, CeruleanCity_Gym_Text_LuisIntro, CeruleanCity_Gym_Text_LuisDefeat
	famechecker FAMECHECKER_MISTY, 2
	msgbox CeruleanCity_Gym_Text_LuisPostBattle, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE02_GET, CeruleanCity_Gym_EventScript_GymGuyPostVictory
	msgbox CeruleanCity_Gym_Text_GymGuyAdvice
	release
	end

CeruleanCity_Gym_EventScript_GymGuyPostVictory::
	msgbox CeruleanCity_Gym_Text_WeMakePrettyGoodTeam
	release
	end

CeruleanCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, CeruleanCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeruleanCity_Gym_Text_GymStatue
	releaseall
	end

CeruleanCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeruleanCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeruleanCity_Gym_EventScript_Starmie::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_STARMIE, CRY_MODE_NORMAL
	msgbox CeruleanCity_Gym_Text_Starmie
	waitmoncry
	release
	end

EventScript_CeruleanCityGym_GymGuyFeathers::
    applymovement LOCALID_CERULEAN_GYM_GUY, Movement_GymGuideCerulean_WalkUpToYou   
    waitmovement 0
    msgbox CeruleanCity_Gym_Text_GymGuyAdvice, MSGBOX_AUTOCLOSE
    msgbox Common_Gym_Text_ComplimentaryItems, MSGBOX_AUTOCLOSE
    giveitem ITEM_GENIUS_FEATHER 2
    giveitem ITEM_CLEVER_FEATHER 2
    closemessage
    applymovement LOCALID_CERULEAN_GYM_GUY, Movement_GymGuideCerulean_WalkBack
    waitmovement 0
    setvar VAR_MAP_SCENE_PEWTER_CITY_GYM, 3
    end

Movement_GymGuideCerulean_WalkUpToYou::
    walk_right
    walk_down
    step_end

Movement_GymGuideCerulean_WalkBack::
    walk_up
    walk_left
    face_down
    step_end

CeruleanCity_Gym_Text_Starmie::
    .string "Star Star!$"

CeruleanCity_Gym_Text_MistyIntro::
    .string "Hi, you're a new face!\p"
    .string "Only those Trainers who have a\n"
    .string "policy about Pokémon can turn pro.\p"
    .string "What is your approach when you\n"
    .string "catch and train Pokémon?\p"
    .string "My policy is an all-out offensive\n"
    .string "with Water-type Pokémon!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

CeruleanCity_Gym_Text_ExplainTM54::
    .string "TM54 teaches Flip Turn.\p"
    .string "Use it on an aquatic Pokémon!$"

CeruleanCity_Gym_Text_ExplainCascadeBadge::
    .string "The Cascade Badge allows you to\n"
    .string "use Cut outside of battle.\p"
    .string "You can Cut down small trees to\n"
    .string "open new pathways if you have the\l"
    .string "HM.\p"
    .string "Not only that, it raises your Level Cap\n"
    .string "to {STR_VAR_1}.\p"
    .string "You can also have my favorite TM.$"

CeruleanCity_Gym_Text_ReceivedTM54FromMisty::
    .string "{PLAYER} received TM54\n"
    .string "from Misty.$"

CeruleanCity_Gym_Text_BetterMakeRoomForThis::
    .string "You better make room for this!$"

CeruleanCity_Gym_Text_MistyDefeat::
    .string "Wow!\n"
    .string "You're too much!\p"
    .string "All right!\p"
    .string "You can have the CascadeBadge to\n"
    .string "show you beat me.$"

CeruleanCity_Gym_Text_DianaIntro::
    .string "What? You?\n"
    .string "I'm more than good enough for you!\p"
    .string "Misty won't have to be bothered.$"

CeruleanCity_Gym_Text_DianaDefeat::
    .string "You overwhelmed me!$"

CeruleanCity_Gym_Text_DianaPostBattle::
    .string "You have to face other Trainers\n"
    .string "to see how good you really are.$"

CeruleanCity_Gym_Text_LuisIntro::
    .string "Splash!\p"
    .string "I'm first up!\n"
    .string "Let's do it!$"

CeruleanCity_Gym_Text_LuisDefeat::
    .string "That can't be!$"

CeruleanCity_Gym_Text_LuisPostBattle::
    .string "Misty is a Trainer who's going to\n"
    .string "keep improving.\p"
    .string "She won't lose to someone like you!$"

CeruleanCity_Gym_Text_GymGuyAdvice::
    .string "Yo!\n"
    .string "Champ in the making!\p"
    .string "Let me give you some advice!\p"
    .string "The Leader, Misty, is a pro who\n"
    .string "uses Water-type Pokémon.\p"
    .string "You can drain all their water with\n"
    .string "Grass-type Pokémon.\p"
    .string "Or, you might use Electric-type\n"
    .string "Pokémon and zap them!$"

CeruleanCity_Gym_Text_WeMakePrettyGoodTeam::
    .string "You beat Misty!\n"
    .string "See, what'd I tell ya?\p"
    .string "You and me, kid, we make a pretty\n"
    .string "darn-good team!$"

CeruleanCity_Gym_Text_GymStatue::
    .string "Cerulean Pokémon Gym\n"
    .string "Leader: Misty\p"
    .string "Winning Trainer:\n"
    .string "{RIVAL}$"

CeruleanCity_Gym_Text_GymStatuePlayerWon::
    .string "Cerulean Pokémon Gym\n"
    .string "Leader: Misty\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}, {PLAYER}$"

Common_Gym_Text_ComplimentaryItems::
    .string "Here, take these items on the house\n"
    .string "for being brave enough to Tackle\l"
    .string "this gym.$"
