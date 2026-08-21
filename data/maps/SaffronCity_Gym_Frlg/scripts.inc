SaffronCity_Gym_Frlg_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, SaffronCityGym_SetmaptileScript
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SaffronCity_Gym_OnFrame
	.byte 0

SaffronCity_Gym_OnFrame::
    map_script_2 VAR_MAP_SCENE_PEWTER_CITY_GYM, 4, EventScript_SaffronCityGym_GymGuyFeathers
	.2byte 0

EventScript_SaffronCityGym_GymGuyFeathers:
	applymovement LOCALID_SAFFROM_GYM_GUY, Movement_GymGuideSaffron_WalkUpToYou   
    waitmovement 0
    msgbox SaffronCity_Gym_Text_GymGuyAdvice, MSGBOX_AUTOCLOSE
    msgbox Common_Gym_Text_ComplimentaryItems, MSGBOX_AUTOCLOSE
    giveitem ITEM_HEALTH_FEATHER 2
	giveitem ITEM_MUSCLE_FEATHER 2
	giveitem ITEM_RESIST_FEATHER 2
    giveitem ITEM_GENIUS_FEATHER 2
    giveitem ITEM_CLEVER_FEATHER 2
    giveitem ITEM_SWIFT_FEATHER 2
    closemessage
    applymovement LOCALID_SAFFROM_GYM_GUY, Movement_GymGuideSaffron_WalkBack
    waitmovement 0
    setvar VAR_MAP_SCENE_PEWTER_CITY_GYM, 5
    end

Movement_GymGuideSaffron_WalkUpToYou::
    walk_left
    walk_down
	walk_down
    step_end

Movement_GymGuideSaffron_WalkBack::
    walk_up
    walk_up
    walk_right
	face_down
    step_end

SaffronCity_Gym_EventScript_Sabrina::
	famechecker FAMECHECKER_SABRINA, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_SABRINA, SaffronCity_Gym_Text_SabrinaIntro, SaffronCity_Gym_Text_SabrinaDefeat, SaffronCity_Gym_EventScript_DefeatedSabrina, NO_MUSIC
	msgbox SaffronCity_Gym_Text_ExplainTM04
	release
	end

SaffronCity_Gym_EventScript_SabrinaSetTile::
    lock
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SaffronCity_Gym_Movement_PanCameraDown
	waitmovement 0
	playse SE_DOOR
	setmetatile 0xA, 0x14, 0x293, FALSE
	special DrawWholeMapView
	waitse
	applymovement LOCALID_CAMERA, SaffronCity_Gym_Movement_PanCameraUp
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_SAFFRON_GYM_WARP_TILE, 1
	release
	end

SaffronCity_Gym_Movement_PanCameraDown::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SaffronCity_Gym_Movement_PanCameraUp::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SaffronCityGym_SetmaptileScript::
	compare VAR_SAFFRON_GYM_WARP_TILE 0x1 
	call_if_eq SaffronCityGym_SetTiles 
	end 

SaffronCityGym_SetTiles:
	setmetatile 0xA, 0x14, 0x293, FALSE
	return 

SaffronCity_Gym_EventScript_DefeatedSabrina::
	famechecker FAMECHECKER_SABRINA, 2
	famechecker FAMECHECKER_SABRINA, 3
	clearflag FLAG_HIDE_SAFFRON_CITY_POKECENTER_SABRINA_JOURNALS
	setflag FLAG_DEFEATED_SABRINA
	setflag FLAG_BADGE05_GET
	set_gym_trainers_frlg 6
	goto SaffronCity_Gym_EventScript_GiveTM04
	end

SaffronCity_Gym_EventScript_GiveTM04::
	callnative SetBuffer1ToLevelCap
	msgbox SaffronCity_Gym_Text_ExplainMarshBadgeTakeThis
	giveitem ITEM_TM_TRICK_ROOM
	msgbox SaffronCity_Gym_Text_SabrinaPostBattle
	giveitem ITEM_CHIMECHITE
    applymovement LOCALID_PLAYER, Common_Movement_FaceDown
    waitmovement 0
    call_if_set FLAG_AUTOSAVE_ENABLED, Common_EventScript_AutoSave
	release
	end

SaffronCity_Gym_EventScript_Johan::
	trainerbattle_single TRAINER_PSYCHIC_JOHAN, SaffronCity_Gym_Text_JohanIntro, SaffronCity_Gym_Text_JohanDefeat
	msgbox SaffronCity_Gym_Text_JohanPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Tyron::
	trainerbattle_single TRAINER_PSYCHIC_TYRON, SaffronCity_Gym_Text_TyronIntro, SaffronCity_Gym_Text_TyronDefeat
	famechecker FAMECHECKER_SABRINA, 5
	msgbox SaffronCity_Gym_Text_TyronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Cameron::
	trainerbattle_single TRAINER_PSYCHIC_CAMERON, SaffronCity_Gym_Text_CameronIntro, SaffronCity_Gym_Text_CameronDefeat
	msgbox SaffronCity_Gym_Text_CameronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PSYCHIC_PRESTON, SaffronCity_Gym_Text_PrestonIntro, SaffronCity_Gym_Text_PrestonDefeat
	msgbox SaffronCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Amanda::
	trainerbattle_single TRAINER_CHANNELER_AMANDA, SaffronCity_Gym_Text_AmandaIntro, SaffronCity_Gym_Text_AmandaDefeat
	msgbox SaffronCity_Gym_Text_AmandaPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Stacy::
	trainerbattle_single TRAINER_CHANNELER_STACY, SaffronCity_Gym_Text_StacyIntro, SaffronCity_Gym_Text_StacyDefeat
	msgbox SaffronCity_Gym_Text_StacyPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Tasha::
	trainerbattle_single TRAINER_CHANNELER_TASHA, SaffronCity_Gym_Text_TashaIntro, SaffronCity_Gym_Text_TashaDefeat
	msgbox SaffronCity_Gym_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SABRINA, SaffronCity_Gym_EventScript_GymGuyPostVictory
	msgbox SaffronCity_Gym_Text_GymGuyAdvice
	release
	end

SaffronCity_Gym_EventScript_GymGuyPostVictory::
	msgbox SaffronCity_Gym_Text_GymGuyPostVictory
	release
	end

SaffronCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE05_GET, SaffronCity_Gym_EventScript_GymStatuePostVictory
	msgbox SaffronCity_Gym_Text_GymStatue
	releaseall
	end

SaffronCity_Gym_EventScript_GymStatuePostVictory::
	msgbox SaffronCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

SaffronCity_Gym_Text_SabrinaIntro::
    .string "I had a vision of your arrival.\p"
    .string "I have had psychic powers since\n"
    .string "I was a child.\p"
    .string "It started when a spoon I\n"
    .string "carelessly tossed, bent.\p"
    .string "I dislike battling, but if you wish,\n"
    .string "I will show you my powers!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

SaffronCity_Gym_Text_SabrinaDefeat::
    .string "This loss shocks me!\n"
    .string "But, a loss is a loss.\p"
    .string "I admit, I didn't work hard enough\n"
    .string "to win.\p"
    .string "Your victory has earned you the\n"
    .string "Marsh Badge.$"

SaffronCity_Gym_Text_SabrinaPostBattle::
    .string "TM71 is Trick Room.\p"
    .string "It flips dimensions to allow\n"
    .string "slower Pokémon to move first.\p"
	.string "It's particularly strong in Doubles.\p"
	.string "A decent Trick Room setter would be\n"
	.string "Mega Chimecho.$"

SaffronCity_Gym_Text_ExplainMarshBadgeTakeThis::
    .string "The Marsh Badge raises the Level Cap to\n"
    .string "{STR_VAR_1}.\p"
	.string "It also allows you to use HM Rock Smash\n"
	.string "outside of battle.\p"
    .string "Wait, please take this TM with you.$"

SaffronCity_Gym_Text_ReceivedTM71FromSabrina::
    .string "{PLAYER} received TM71 from\n"
    .string "Sabrina.$"

SaffronCity_Gym_Text_ExplainTM04::
    .string "TM71 is Trick Room.\p"
    .string "It flips dimensions to allow\n"
    .string "slower Pokémon to move first.\p"
	.string "It's particularly strong in Doubles.$"

SaffronCity_Gym_Text_BagFullOfOtherItems::
    .string "Your Bag is full of other items.$"

SaffronCity_Gym_Text_AmandaIntro::
    .string "Sabrina is far younger than I,\n"
    .string "but she has earned my respect.$"

SaffronCity_Gym_Text_AmandaDefeat::
    .string "Not good enough!$"

SaffronCity_Gym_Text_AmandaPostBattle::
    .string "In a battle of equals, the one\n"
    .string "with the stronger will wins.\p"
    .string "If you wish to beat Sabrina, focus\n"
    .string "and will yourself to victory.$"

SaffronCity_Gym_Text_JohanIntro::
    .string "Does our unseen power scare you?$"

SaffronCity_Gym_Text_JohanDefeat::
    .string "I never foresaw this!$"

SaffronCity_Gym_Text_JohanPostBattle::
    .string "Psychic Pokémon fear only ghosts\n"
    .string "and bugs!$"

SaffronCity_Gym_Text_StacyIntro::
    .string "Pokémon take on the appearance of\n"
    .string "their Trainers.\p"
    .string "Your Pokémon must be tough, then!$"

SaffronCity_Gym_Text_StacyDefeat::
    .string "I knew it!$"

SaffronCity_Gym_Text_StacyPostBattle::
    .string "I have much to learn still…\p"
    .string "I must master Psychic and teach it\n"
    .string "to my Pokémon…$"

SaffronCity_Gym_Text_TyronIntro::
    .string "You understand, don't you?\p"
    .string "That power alone isn't enough to\n"
    .string "win in the world of Pokémon?$"

SaffronCity_Gym_Text_TyronDefeat::
    .string "I don't believe this!$"

SaffronCity_Gym_Text_TyronPostBattle::
    .string "Sabrina just wiped out the Karate\n"
    .string "Master next door.$"

SaffronCity_Gym_Text_TashaIntro::
    .string "You and I, our Pokémon shall\n"
    .string "battle!$"

SaffronCity_Gym_Text_TashaDefeat::
    .string "I lost after all!$"

SaffronCity_Gym_Text_TashaPostBattle::
    .string "I knew that this was going to take\n"
    .string "place.$"

SaffronCity_Gym_Text_CameronIntro::
    .string "Sabrina is young, but she's also\n"
    .string "our highly skilled Leader.\p"
    .string "You won't reach her easily!$"

SaffronCity_Gym_Text_CameronDefeat::
    .string "Ow!\n"
    .string "Down and out!$"

SaffronCity_Gym_Text_CameronPostBattle::
    .string "There used to be two Pokémon Gyms\n"
    .string "in Saffron.\p"
    .string "The Fighting Dojo next door lost\n"
    .string "its Gym status, though.\p"
    .string "We simply creamed them when we\n"
    .string "decided to have just one Gym.$"

SaffronCity_Gym_Text_PrestonIntro::
    .string "Saffron Pokémon Gym is famous for\n"
    .string "training psychics.\p"
    .string "You want to see Sabrina, don't\n"
    .string "you? I can tell!$"

SaffronCity_Gym_Text_PrestonDefeat::
    .string "Arrrgh!$"

SaffronCity_Gym_Text_PrestonPostBattle::
    .string "That's right! I used telepathy to\n"
    .string "read your mind!$"

SaffronCity_Gym_Text_GymGuyAdvice::
    .string "Yo!\n"
    .string "Champ in the making!\p"
    .string "Sabrina specializes in the double\n"
    .string "battle, rather than a specific type.\p"
    .string "Switch up your strategies for doubles!\p"
    .string "Double targetting a threat can\n"
    .string "be a good strategy.$"

SaffronCity_Gym_Text_GymGuyPostVictory::
    .string "Psychic power, huh?\p"
    .string "If I had that, I'd make a bundle\n"
    .string "at the slots!$"

SaffronCity_Gym_Text_GymStatue::
    .string "Saffron Pokémon Gym\n"
    .string "Leader: Sabrina\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}$"

SaffronCity_Gym_Text_GymStatuePlayerWon::
    .string "Saffron Pokémon Gym\n"
    .string "Leader: Sabrina\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}, {PLAYER}$"

