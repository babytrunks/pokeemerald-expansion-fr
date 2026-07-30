FuchsiaCity_Gym_Frlg_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, FuchsiaCity_Gym_Frlg_CheckClearPathToKoga
    map_script MAP_SCRIPT_ON_FRAME_TABLE, FuchsiaCity_Gym_OnFrame
	.byte 0

FuchsiaCity_Gym_OnFrame:
    map_script_2 VAR_MAP_SCENE_PEWTER_CITY_GYM, 5, EventScript_FuschiaCityGym_GymGuyFeathers
	.2byte 0

EventScript_FuschiaCityGym_GymGuyFeathers::
	applymovement LOCALID_FUSCHIA_GYM_GUY, Movement_GymGuideFuschia_WalkUpToYou   
    waitmovement 0
    msgbox FuchsiaCity_Gym_Text_GymGuyAdvice, MSGBOX_AUTOCLOSE
    msgbox FuschiaCity_Gym_Text_ComplimentaryItems, MSGBOX_AUTOCLOSE
    giveitem ITEM_CARBOS 1
    closemessage
    applymovement LOCALID_FUSCHIA_GYM_GUY, Movement_GymGuideFuschia_WalkBack
    waitmovement 0
    setvar VAR_MAP_SCENE_PEWTER_CITY_GYM, 6
    end

Movement_GymGuideFuschia_WalkUpToYou:
    walk_down
    walk_left
    walk_left
    walk_left
    walk_left
    face_down
    step_end

Movement_GymGuideFuschia_WalkBack::
    walk_right
    walk_right
    walk_right
    walk_right
    walk_up
    face_down
    step_end

FuchsiaCity_Gym_EventScript_Koga::
	famechecker FAMECHECKER_KOGA, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_KOGA, FuchsiaCity_Gym_Text_KogaIntro, FuchsiaCity_Gym_Text_KogaDefeat, FuchsiaCity_Gym_EventScript_DefeatedKoga, NO_MUSIC
	msgbox FuchsiaCity_Gym_Text_KogaPostBattle
	release
	end

FuchsiaCity_Gym_EventScript_DefeatedKoga::
	famechecker FAMECHECKER_KOGA, 1
	clearflag FLAG_HIDE_FAME_CHECKER_KOGA_JOURNAL
	setflag FLAG_BADGE06_GET
    call_if_set FLAG_AUTOSAVE_ENABLED, Common_EventScript_AutoSave
	set_gym_trainers_frlg 5
	goto FuchsiaCity_Gym_EventScript_GiveTM06
	end

FuchsiaCity_Gym_EventScript_GiveTM06::
	callnative SetBuffer1ToLevelCap
	msgbox FuchsiaCity_Gym_Text_KogaExplainSoulBadge
	giveitem ITEM_GRENINJITE
	msgbox FuchsiaCity_Gym_Text_KogaExplainGreninjite
    giveitem ITEM_LIFE_ORB
    msgbox FuchsiaCity_Gym_Text_KogaPostBattle
    playse SE_DOOR
    setmetatile 6, 16, 0x281, FALSE
    setmetatile 7, 16, 0x281, FALSE
    setmetatile 8, 16, 0x281, FALSE
	special DrawWholeMapView
	waitse
    applymovement LOCALID_PLAYER, Common_Movement_FaceDown
    waitmovement 0
	release
	end


FuchsiaCity_Gym_Frlg_CheckClearPathToKoga::
    call_if_set FLAG_BADGE06_GET, FuchsiaCity_Gym_Frlg_ClearPathToKoga
    end

FuchsiaCity_Gym_Frlg_ClearPathToKoga:
    setmetatile 6, 16, 0x281, FALSE
    setmetatile 7, 16, 0x281, FALSE
    setmetatile 8, 16, 0x281, FALSE
    return

FuchsiaCity_Gym_EventScript_Phil::
	trainerbattle_single TRAINER_TAMER_PHIL, FuchsiaCity_Gym_Text_PhilIntro, FuchsiaCity_Gym_Text_PhilDefeat
	msgbox FuchsiaCity_Gym_Text_PhilPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Edgar::
	trainerbattle_single TRAINER_TAMER_EDGAR, FuchsiaCity_Gym_Text_EdgarIntro, FuchsiaCity_Gym_Text_EdgarDefeat
	msgbox FuchsiaCity_Gym_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_JUGGLER_KIRK, FuchsiaCity_Gym_Text_KirkIntro, FuchsiaCity_Gym_Text_KirkDefeat
	famechecker FAMECHECKER_KOGA, 2
	msgbox FuchsiaCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_JUGGLER_SHAWN, FuchsiaCity_Gym_Text_ShawnIntro, FuchsiaCity_Gym_Text_ShawnDefeat
	msgbox FuchsiaCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Kayden::
	trainerbattle_single TRAINER_JUGGLER_KAYDEN, FuchsiaCity_Gym_Text_KaydenIntro, FuchsiaCity_Gym_Text_KaydenDefeat
	msgbox FuchsiaCity_Gym_Text_KaydenPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_JUGGLER_NATE, FuchsiaCity_Gym_Text_NateIntro, FuchsiaCity_Gym_Text_NateDefeat
	msgbox FuchsiaCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE06_GET, FuchsiaCity_Gym_EventScript_GymGuyPostVictory
	msgbox FuchsiaCity_Gym_Text_GymGuyAdvice
	release
	end

FuchsiaCity_Gym_EventScript_GymGuyPostVictory::
	msgbox FuchsiaCity_Gym_Text_GymGuyPostVictory
	release
	end

FuchsiaCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FuchsiaCity_Gym_EventScript_GymStatuePostVictory
	msgbox FuchsiaCity_Gym_Text_GymStatue
	releaseall
	end

FuchsiaCity_Gym_EventScript_GymStatuePostVictory::
	msgbox FuchsiaCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

FuschiaCity_Gym_EventScript_Greninja::
    lock
	faceplayer
	waitse
	playmoncry SPECIES_GRENINJA, CRY_MODE_NORMAL
	msgbox FuschiaCity_Gym_Text_Greninja
	waitmoncry
	release
	end

FuschiaCity_Gym_Text_Greninja::
    .string "Jaa!!$"

FuchsiaCity_Gym_Text_KogaIntro::
    .string "Fwahahaha!\p"
    .string "A mere child like you dares to\n"
    .string "challenge me?\p"
    .string "The very idea makes me shiver\n"
    .string "with mirth!\p"
    .string "Very well, I shall show you true\n"
    .string "terror as a ninja master.\p"
    .string "Swiftness brings abrupt doom.\n"
    .string "Being outran can render foes\n"
    .string "helpless.\p"
    .string "Despair to the frightening horror of\n"
    .string "my speed demons!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

FuchsiaCity_Gym_Text_KogaDefeat::
    .string "Humph!\n"
    .string "You have proven your worth!\p"
    .string "Here!\n"
    .string "Take the Soul Badge!$"

FuchsiaCity_Gym_Text_KogaPostBattle::
    .string "The Life Orb allows you to deal more\n"
    .string "damage at the cost of some of the user's\l"
    .string "HP.\p"
    .string "Despite its drawback, it can often\n"
    .string "be the difference in killing the foe.$"

FuchsiaCity_Gym_Text_KogaExplainSoulBadge::
    .string "Now that you have the Soul Badge,\n"
    .string "you can now Surf outside of battle.\p"
    .string "It also increases your Level Cap\n"
    .string "to {STR_VAR_1}.\p"
    .string "Ah!\n"
    .string "Take this, too!$"

FuchsiaCity_Gym_Text_ReceivedTM06FromKoga::
    .string "{PLAYER} received TM06\n"
    .string "from Koga.$"

FuchsiaCity_Gym_Text_KogaExplainGreninjite::
    .string "That allows you to use Mega Greninja!\p"
    .string "Any true ninja master should use it.\p"
    .string "I don't have a TM to give, so perhaps\n"
    .string "I should compensate with this.$"

FuchsiaCity_Gym_Text_MakeSpaceForThis::
    .string "Make space for this, child!$"

FuchsiaCity_Gym_Text_KaydenIntro::
    .string "Strength isn't the key for Pokémon.\n"
    .string "Do you understand this?\p"
    .string "Pokémon is about strategy!\p"
    .string "I'll show you how strategy can\n"
    .string "beat brute strength.$"

FuchsiaCity_Gym_Text_KaydenDefeat::
    .string "What?\n"
    .string "Extraordinary!$"

FuchsiaCity_Gym_Text_KaydenPostBattle::
    .string "So, you mix brawn with brains?\n"
    .string "Good strategy!\p"
    .string "That's remarkable for a child\n"
    .string "Trainer.$"

FuchsiaCity_Gym_Text_KirkIntro::
    .string "I was a magician once upon a time.\p"
    .string "But I dreamt of becoming a ninja,\n"
    .string "so I joined this Gym.$"

FuchsiaCity_Gym_Text_KirkDefeat::
    .string "I'm done for!$"

FuchsiaCity_Gym_Text_KirkPostBattle::
    .string "Even though I've lost, I will keep\n"
    .string "training according to the teachings\l"
    .string "of Koga, my ninja master.$"

FuchsiaCity_Gym_Text_NateIntro::
    .string "Let's see you beat my special\n"
    .string "techniques!$"

FuchsiaCity_Gym_Text_NateDefeat::
    .string "You had me fooled!$"

FuchsiaCity_Gym_Text_NatePostBattle::
    .string "I like poison and sleep techniques,\n"
    .string "as they linger after battle!$"

FuchsiaCity_Gym_Text_PhilIntro::
    .string "Stop right there!\p"
    .string "The famed invisible walls of\n"
    .string "Fuchsia Gym have you frustrated?$"

FuchsiaCity_Gym_Text_PhilDefeat::
    .string "Whoa!\n"
    .string "You've got it!$"

FuchsiaCity_Gym_Text_PhilPostBattle::
    .string "You impressed me!\n"
    .string "Here's a hint!\p"
    .string "Look very closely for gaps in the\n"
    .string "invisible walls!$"

FuchsiaCity_Gym_Text_EdgarIntro::
    .string "I also study the way of the ninja\n"
    .string "with Master Koga!\p"
    .string "Ninja have a long history of using\n"
    .string "animals!$"

FuchsiaCity_Gym_Text_EdgarDefeat::
    .string "Awoo!$"

FuchsiaCity_Gym_Text_EdgarPostBattle::
    .string "I still have much to learn.$"

FuchsiaCity_Gym_Text_ShawnIntro::
    .string "Master Koga comes from a long line\n"
    .string "of ninjas.\p"
    .string "What did you descend from?$"

FuchsiaCity_Gym_Text_ShawnDefeat::
    .string "You're more skilled than I'd\n"
    .string "thought!$"

FuchsiaCity_Gym_Text_ShawnPostBattle::
    .string "Where there is light, there is\n"
    .string "shadow!\p"
    .string "Light and shadow!\n"
    .string "Which do you choose?$"

FuchsiaCity_Gym_Text_GymGuyAdvice::
    .string "Yo!\n"
    .string "Champ in the making!\p"
    .string "Koga specializes in speed.\p"
    .string "He's got some of the fastest\n"
    .string "Pokémon out there!\p"
    .string "Priority moves could be a big help.$"

FuschiaCity_Gym_Text_ComplimentaryItems:
    .string "Here, these complimentary items may\n"
    .string "help too.$"

FuchsiaCity_Gym_Text_GymGuyPostVictory::
    .string "It's amazing how ninja can terrify,\n"
    .string "even now!$"

FuchsiaCity_Gym_Text_GymStatue::
    .string "Fuchsia Pokémon Gym\n"
    .string "Leader: Koga\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}$"

FuchsiaCity_Gym_Text_GymStatuePlayerWon::
    .string "Fuchsia Pokémon Gym\n"
    .string "Leader: Koga\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}, {PLAYER}$"

