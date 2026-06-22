SilphCo_7F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_7F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SilphCo_7F_OnTransition
	
	.byte 0

SilphCo_7F_OnLoad::
	call_if_unset FLAG_SILPH_7F_DOOR_1, EventScript_Close7FDoor1
	call_if_unset FLAG_SILPH_7F_DOOR_2, EventScript_Close7FDoor2
	call_if_unset FLAG_SILPH_7F_DOOR_3, EventScript_Close7FDoor3
	call_if_set   FLAG_SILPH_7F_MOVED_ORANGE_CRATE, SilphCo_7F_EventScript_OrangeCrateMove
	end

SilphCo_7F_OnTransition::
	call_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_SetObjRocketsGone
	end

SilphCo_7F_EventScript_SetObjRocketsGone::
	setobjectmovementtype LOCALID_SILPH_CO_7F_WORKER_M2, MOVEMENT_TYPE_FACE_UP
	return

SilphCo_7F_EventScript_RivalTriggerTop::
	lockall
	setvar VAR_TEMP_1, 0
	goto SilphCo_7F_EventScript_RivalScene
	end

SilphCo_7F_EventScript_RivalTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 1
	goto SilphCo_7F_EventScript_RivalScene
	end

SilphCo_7F_EventScript_RivalScene::
	textcolor NPC_TEXT_COLOR_MALE
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	applymovement LOCALID_SILPH_CO_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_SILPH_CO_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox SilphCo_7F_Text_RivalWhatKeptYou
	call_if_eq VAR_TEMP_1, 0, SilphCo_7F_EventScript_RivalApproachTop
	call_if_eq VAR_TEMP_1, 1, SilphCo_7F_EventScript_RivalApproachBottom
	msgbox SilphCo_7F_Text_RivalIntro
	setvar VAR_LAST_TALKED, LOCALID_SILPH_CO_RIVAL
	call_if_eq VAR_STARTER_MON, 2, SilphCo_7F_EventScript_RivalSquirtle
	call_if_eq VAR_STARTER_MON, 1, SilphCo_7F_EventScript_RivalBulbasaur
	call_if_eq VAR_STARTER_MON, 0, SilphCo_7F_EventScript_RivalCharmander
	msgbox SilphCo_7F_Text_RivalPostBattle
	closemessage
	playbgm MUS_RG_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, SilphCo_7F_EventScript_RivalExitTop
	call_if_eq VAR_TEMP_1, 1, SilphCo_7F_EventScript_RivalExitBottom
	playse SE_WARP_IN
	fadedefaultbgm
	removeobject LOCALID_SILPH_CO_RIVAL
	waitse
	setvar VAR_MAP_SCENE_SILPH_CO_7F, 1
	releaseall
	end

SilphCo_7F_EventScript_RivalApproachTop::
	closemessage
	applymovement LOCALID_SILPH_CO_RIVAL, SilphCo_7F_Movement_RivalApproachTop
	waitmovement 0
	return

SilphCo_7F_EventScript_RivalApproachBottom::
	return

SilphCo_7F_EventScript_RivalSquirtle::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_SQUIRTLE, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalBulbasaur::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_BULBASAUR, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalCharmander::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_CHARMANDER, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalExitTop::
	applymovement LOCALID_SILPH_CO_RIVAL, SilphCo_7F_Movement_RivalExitTop
	waitmovement 0
	return

SilphCo_7F_EventScript_RivalExitBottom::
	applymovement LOCALID_SILPH_CO_RIVAL, SilphCo_7F_Movement_RivalExitBottom
	waitmovement 0
	return

SilphCo_7F_Movement_RivalApproachTop::
	walk_up
	step_end

SilphCo_7F_Movement_RivalExitTop::
	walk_right
	walk_right
	walk_right
	walk_up
	delay_16
	step_end

SilphCo_7F_Movement_RivalExitBottom::
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	delay_16
	step_end

SilphCo_7F_EventScript_LaprasGuy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_LAPRAS_FROM_SILPH, SilphCo_7F_EventScript_AlreadyGotLapras
	msgbox SilphCo_7F_Text_HaveMonForSavingUs
	setflag FLAG_RARE_POKEMON_SCREEN
	setflag FLAG_3_PERFECT_IVS 
	setflag FLAG_FORCE_SHINY
    setvar VAR_RARE_POKEMON_COUNTER, 4
    factory_generaterentalmons
	factory_rentmons
	waitstate
	clearflag FLAG_RARE_POKEMON_SCREEN
	clearflag FLAG_3_PERFECT_IVS
	clearflag FLAG_FORCE_SHINY
	goto SilphCo_7F_EventScript_EndReceiveLapras
	@ setvar VAR_TEMP_1, SPECIES_LAPRAS
	@ givemon SPECIES_LAPRAS, 25
	@ goto_if_eq VAR_RESULT, 0, SilphCo_7F_EventScript_ReceiveLaprasParty
	@ goto_if_eq VAR_RESULT, 1, SilphCo_7F_EventScript_ReceiveLaprasPC
	@ goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	release
	end

SilphCo_7F_EventScript_ReceiveLaprasParty::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message SilphCo_7F_Text_ObtainedLaprasFromEmployee
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_LAPRAS
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SilphCo_7F_EventScript_EndReceiveLapras
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SilphCo_7F_EventScript_EndReceiveLapras
	end

SilphCo_7F_EventScript_ReceiveLaprasPC::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message SilphCo_7F_Text_ObtainedLaprasFromEmployee
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_LAPRAS
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SilphCo_7F_EventScript_LaprasTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto SilphCo_7F_EventScript_LaprasTransferredToPC
	end

SilphCo_7F_EventScript_LaprasTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto SilphCo_7F_EventScript_EndReceiveLapras
	end

SilphCo_7F_EventScript_EndReceiveLapras::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox SilphCo_7F_Text_ExplainLapras
	setflag FLAG_GOT_LAPRAS_FROM_SILPH
	release
	end

SilphCo_7F_EventScript_AlreadyGotLapras::
	msgbox SilphCo_7F_Text_RocketBossWentToBoardroom
	release
	end

SilphCo_7F_EventScript_WorkerM1::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_WorkerM1RocketsGone
	msgbox SilphCo_7F_Text_RocketsAfterMasterBall
	release
	end

SilphCo_7F_EventScript_WorkerM1RocketsGone::
	msgbox SilphCo_7F_Text_CanceledMasterBallProject
	release
	end

SilphCo_7F_EventScript_WorkerM2::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_WorkerM2RocketsGone
	msgbox SilphCo_7F_Text_BadIfTeamRocketTookOver
	release
	end

SilphCo_7F_EventScript_WorkerM2RocketsGone::
	msgbox SilphCo_7F_Text_WowYouChasedOffTeamRocket
	release
	end

SilphCo_7F_EventScript_WorkerF::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_WorkerFRocketsGone
	msgbox SilphCo_7F_Text_ReallyDangerousHere
	release
	end

SilphCo_7F_EventScript_WorkerFRocketsGone::
	msgbox SilphCo_7F_Text_ThankYouSoMuch
	release
	end

SilphCo_7F_EventScript_FloorSign::
	msgbox SilphCo_7F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_7F_EventScript_Joshua::
	trainerbattle_single TRAINER_SCIENTIST_JOSHUA, SilphCo_7F_Text_JoshuaIntro, SilphCo_7F_Text_JoshuaDefeat
	msgbox SilphCo_7F_Text_JoshuaPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_33, SilphCo_7F_Text_Grunt1Intro, SilphCo_7F_Text_Grunt1Defeat
	msgbox SilphCo_7F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_34, SilphCo_7F_Text_Grunt2Intro, SilphCo_7F_Text_Grunt2Defeat
	msgbox SilphCo_7F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_35, SilphCo_7F_Text_Grunt3Intro, SilphCo_7F_Text_Grunt3Defeat
	msgbox SilphCo_7F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_OrangeCrate::
	goto_if_quest_active QUEST_RARE_EXTRACT, SilphCo_7F_EventScript_OrangeCratePush
	msgbox SilphCo_7F_Text_OrangeCrate, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_OrangeCratePush:
	goto_if_set FLAG_SILPH_7F_MOVED_ORANGE_CRATE, SilphCo_7F_EventScript_OrangeCrateEnd
	msgbox SilphCo_7F_Text_OrangeCratePush, MSGBOX_YESNO
	setflag FLAG_SILPH_7F_MOVED_ORANGE_CRATE
	fadescreen FADE_TO_BLACK
	playse SE_M_ROCK_THROW
	waitse
	call SilphCo_7F_EventScript_OrangeCrateMove
	special DrawWholeMapView
	fadescreen FADE_FROM_BLACK
	release
	end

SilphCo_7F_EventScript_OrangeCrateEnd::
	end

SilphCo_7F_EventScript_OrangeCrateMove::
	setmetatile 2, 17, 0x310, 1  
    setmetatile 3, 17, 0x311, 1
    setmetatile 2, 18, 0x318, 1
    setmetatile 3, 18, 0x319, 1
	setmetatile 4, 17, 0x334, 0
    setmetatile 5, 17, 0x334, 0
    setmetatile 4, 18, 0x334, 0
    setmetatile 5, 18, 0x334, 0
	special DrawWholeMapView
	return

SilphCo_7F_EventScript_RareExtract::
	setspeaker SP_NAME_UNKNOWN
	applymovement LOCALID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	msgbox SilphCo_7F_Text_BurglarEvent_SomeonesHere
	playse SE_M_METRONOME
	applymovement LOCALID_PLAYER, Common_Movement_QuestionMark
	waitse
	waitmovement
	addobject LOCALID_SILPHCO7_BURGLAR_2
	addobject LOCALID_SILPHCO7_BURGLAR_1
	applymovement LOCALID_SILPHCO7_BURGLAR_1, Movement_SilphCo7_Burglar1Approach
	applymovement LOCALID_SILPHCO7_BURGLAR_2, Movement_SilphCo7_Burglar2Approach
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	setspeaker SP_NAME_UNKNOWN
	msgbox SilphCo_7F_Text_BurglarEvent_HandItOver
	trainerbattle_no_intro TRAINER_BURGLAR_JESSE, SilphCo7F_Text_JesseDefeat
	setspeaker SP_NAME_UNKNOWN
	msgbox SilphCo7F_Text_JosephApproach
	@ applymovement LOCALID_SILPHCO7_BURGLAR_1, Movement_SilphCo7_Burglar1Backup
	@ waitmovement 0
	@ applymovement LOCALID_SILPHCO7_BURGLAR_2, Movement_SilphCo7_Burglar2Fight
	@ waitmovement 0
	trainerbattle_no_intro TRAINER_BURGLAR_JOSEPH, SilphCo7F_Text_JosephDefeat
	setspeaker SP_NAME_JESSE
	msgbox SilphCo7F_Text_JesseLeave
	setspeaker SP_NAME_JOSEPH
	msgbox SilphCo7F_Text_JosephLeave
	waitbuttonpress
	applymovement LOCALID_SILPHCO7_BURGLAR_1, Movement_SilphCo7_Burglar1Leave
	applymovement LOCALID_SILPHCO7_BURGLAR_2, Movement_SilphCo7_Burglar2Leave
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	setspeaker SP_NAME_UNKNOWN
	msgbox SilphCo7F_Text_PoliceManApproach
	addobject LOCALID_SILPHCO_7_POLICEMAN
	applymovement LOCALID_SILPHCO_7_POLICEMAN, Movement_SilphCo7_PoliceApproach
	waitmovement 0
	trainerbattle_no_intro TRAINER_SILPH_CO_POLICEMAN, SilphCo7F_Text_PolicemanDefeat
	msgbox SilphCo7F_Text_PoliceManIOweYou
	applymovement TRAINER_SILPH_CO_POLICEMAN, Movement_SilphCo7_Burglar1Leave
	waitmovement 0
	removeobject LOCALID_SILPHCO_7_POLICEMAN
	removeobject LOCALID_SILPHCO7_BURGLAR_1
	removeobject LOCALID_SILPHCO7_BURGLAR_2
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	finditem ITEM_RARE_EXTRACT
	end

Movement_SilphCo7_Burglar1Approach:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

Movement_SilphCo7_Burglar2Approach:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	face_up
	step_end

Movement_SilphCo7_Burglar1Leave::
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

Movement_SilphCo7_Burglar2Leave::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

Movement_SilphCo7_PoliceApproach:
	walk_faster_left
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_left
	step_end 

Movement_SilphCo7_Burglar1Backup::
	walk_right
	face_left
	step_end

Movement_SilphCo7_Burglar2Fight::
	walk_up
	face_left
	step_end

SilphCo_7F_Text_HaveMonForSavingUs::
    .string "Oh! Hi! You're not a Rocket!\n"
    .string "You came to save us?\l"
    .string "Why, thank you!\p"
    .string "I want you to have a rare Pokémon\n"
    .string "for saving us.$"

SilphCo_7F_Text_ObtainedLaprasFromEmployee::
    .string "{PLAYER} obtained a LAPRAS from\n"
    .string "the SILPH employee!$"

SilphCo_7F_Text_ExplainLapras::
    .string "I've got some rare Pokémon\n"
    .string "working here in Silph Co.\p"
    .string "They'll be much better off with you.$"

SilphCo_7F_Text_RocketBossWentToBoardroom::
    .string "Team Rocket's Boss went to the\n"
    .string "boardroom!\p"
    .string "Is our PRESIDENT okay?\n"
    .string "I'm worried.$"

SilphCo_7F_Text_RocketsAfterMasterBall::
    .string "Team Rocket was after the MASTER\n"
    .string "BALL, which catches any Pokémon.$"

SilphCo_7F_Text_CanceledMasterBallProject::
    .string "We canceled the MASTER BALL\n"
    .string "project because of Team Rocket.$"

SilphCo_7F_Text_BadIfTeamRocketTookOver::
    .string "It would be bad if Team Rocket\n"
    .string "took over SILPH or our Pokémon.$"

SilphCo_7F_Text_WowYouChasedOffTeamRocket::
    .string "Wow!\p"
    .string "You chased off Team Rocket all by\n"
    .string "yourself?$"

SilphCo_7F_Text_ReallyDangerousHere::
    .string "You!\n"
    .string "It's really dangerous here!\p"
    .string "You came to save me?\n"
    .string "You can't!$"

SilphCo_7F_Text_ThankYouSoMuch::
    .string "Thank you so much!$"

SilphCo_7F_Text_Grunt3Intro::
    .string "Uh-oh!\n"
    .string "I smell a little mouse!$"

SilphCo_7F_Text_Grunt3Defeat::
    .string "Lights out!$"

SilphCo_7F_Text_Grunt3PostBattle::
    .string "You won't find my Boss by just\n"
    .string "scurrying around!$"

SilphCo_7F_Text_JoshuaIntro::
    .string "Heheh!\p"
    .string "You mistook me for a Silph worker?$"

SilphCo_7F_Text_JoshuaDefeat::
    .string "I'm done!$"

SilphCo_7F_Text_JoshuaPostBattle::
    .string "Despite your age, you are a\n"
    .string "skilled TRAINER!$"

SilphCo_7F_Text_Grunt1Intro::
    .string "I am one of the four ROCKET\n"
    .string "BROTHERS!$"

SilphCo_7F_Text_Grunt1Defeat::
    .string "Aack!\n"
    .string "Brothers, I lost!$"

SilphCo_7F_Text_Grunt1PostBattle::
    .string "Doesn't matter.\n"
    .string "My brothers will repay the favor!$"

SilphCo_7F_Text_Grunt2Intro::
    .string "A child intruder?\n"
    .string "That must be you!$"

SilphCo_7F_Text_Grunt2Defeat::
    .string "Fine!\n"
    .string "I lost!$"

SilphCo_7F_Text_Grunt2PostBattle::
    .string "Go on home before my Boss gets\n"
    .string "ticked off!$"

SilphCo_7F_Text_RivalWhatKeptYou::
    .string "{RIVAL}: What kept you, {PLAYER}?$"

SilphCo_7F_Text_RivalIntro::
    .string "{RIVAL}: Hahaha! I thought you'd\n"
    .string "turn up if I waited here!\p"
    .string "I guess Team Rocket slowed you\n"
    .string "down! Not that I care!\p"
    .string "I saw you in Saffron, so I decided\n"
    .string "to see if you got better!$"

SilphCo_7F_Text_RivalDefeat::
    .string "Oh, man!\n"
    .string "So, you are ready for Boss\l"
    .string "Rocket!$"

SilphCo_7F_Text_RivalPostBattle::
    .string "Well, {PLAYER}!\n"
    .string "I'm moving on up and ahead!\p"
    .string "By checking my Pokédex, I'm\n"
    .string "starting to see what's strong and\l"
    .string "how they evolve!\p"
    .string "Am I a genius or what?\p"
    .string "I'm going to the Pokémon LEAGUE to\n"
    .string "boot out the ELITE FOUR.\p"
    .string "I'll become the world's most\n"
    .string "powerful TRAINER!\p"
    .string "{PLAYER}, well, good luck to you!\n"
    .string "Don't sweat it!\l"
    .string "Smell ya!$"

SilphCo_7F_Text_FloorSign::
    .string "Silph Co. Head Office\n"
    .string "7F$"

SilphCo_7F_Text_OrangeCrate::
	.string "It's a crate.\n"
	.string "The placement is a little suspicious…$"

SilphCo_7F_Text_OrangeCratePush::
	.string "…There's a button underneath.\n"
	.string "Press it?$"

SilphCo_7F_Text_BurglarEvent_SomeonesHere::
	.string "…Uh, looks like someone got\n"
	.string "here first.$"

SilphCo_7F_Text_BurglarEvent_HandItOver::
	.string "Hey, you're gonna have to\n"
	.string "hand that over.\p"
	.string ".{PAUSE 30}.{PAUSE 30}.No?\p"
	.string "Well, you're gonna regret this.$"

SilphCo7F_Text_JesseDefeat::
	.string "So not cool…$"

SilphCo7F_Text_JosephDefeat::
	.string "…What?!$"

SilphCo7F_Text_JosephApproach::
	.string "Alright, let me handle this.$"

SilphCo7F_Text_JesseLeave::
	.string "Looks like we can't score again.\n"
	.string "Nice going, Joe.$"

SilphCo7F_Text_JosephLeave::
	.string "Yeah, whatever bro. Just blame\n"
	.string "it on me. You're such a pussy.\p"
	.string "Let's just get outta here.$"

SilphCo7F_Text_PoliceManApproach::
	.string ".{PAUSE 30}.{PAUSE 30}.{PAUSE 30}What's this racket going on?!$"

SilphCo7F_Text_PolicemanDefeat::
	.string "Oh jeez.$"

SilphCo7F_Text_PoliceManIOweYou::
	.string "Wait a sec.{PAUSE 30}.{PAUSE 30}.{PAUSE 30}\p"
	.string "You're the trainer that took out\n"
	.string "the Rockets here, right?\p"
	.string "Sorry, didn't recognize ya.\p"
	.string "I guess I owe you one so I'll\n"
	.string "pretend I saw nothin'.$"
