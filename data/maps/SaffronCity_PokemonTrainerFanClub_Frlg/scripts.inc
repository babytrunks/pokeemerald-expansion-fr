SaffronCity_PokemonTrainerFanClub_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SaffronCity_PokemonTrainerFanClub_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_PokemonTrainerFanClub_OnTransition
	.byte 0

SaffronCity_PokemonTrainerFanClub_OnFrame::
	map_script_2 VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 1, SaffronCity_PokemonTrainerFanClub_EventScript_MeetFirstFans
	.2byte 0

SaffronCity_PokemonTrainerFanClub_EventScript_MeetFirstFans::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	applymovement LOCALID_TRAINER_FAN_CLUB_BATTLE_GIRL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_TRAINER_FAN_CLUB_BATTLE_GIRL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_TRAINER_FAN_CLUB_BATTLE_GIRL, Common_Movement_Delay48
	waitmovement 0
	msgbox SaffronCity_PokemonTrainerFanClub_Text_HuhYou
	closemessage
	applymovement LOCALID_TRAINER_FAN_CLUB_BATTLE_GIRL, SaffronCity_PokemonTrainerFanClub_Movement_FanApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SaffronCity_PokemonTrainerFanClub_Text_YourePlayerWereYourFansNow
	setvar VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 2
	releaseall
	end

SaffronCity_PokemonTrainerFanClub_Movement_FanApproachPlayer::
	delay_16
	delay_8
	walk_down
	delay_16
	walk_down
	delay_8
	walk_left
	step_end

SaffronCity_PokemonTrainerFanClub_OnTransition::
	goto_if_eq VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 1, SaffronCity_PokemonTrainerFanClub_EventScript_SetMemberPosForFirstMeeting
	goto_if_eq VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 2, SaffronCity_PokemonTrainerFanClub_EventScript_UpdateFanMemberPositions
	end

SaffronCity_PokemonTrainerFanClub_EventScript_UpdateFanMemberPositions::
	special Script_TryLoseFansFromPlayTime
	setvar VAR_0x8004, FANCLUB_MEMBER1
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember1ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER2
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER3
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember3ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER4
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER5
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER6
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember6ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER7
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER8
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable
	end

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember1ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_BATTLE_GIRL, 5, 2
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_BATTLE_GIRL, MOVEMENT_TYPE_FACE_UP
	return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_YOUNGSTER, 7, 4
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_YOUNGSTER, MOVEMENT_TYPE_FACE_LEFT
	return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember3ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_GENTLEMAN, 2, 2
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_GENTLEMAN, MOVEMENT_TYPE_FACE_UP
	return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_LITTLE_GIRL, 3, 4
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_LITTLE_GIRL, MOVEMENT_TYPE_FACE_RIGHT
	return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_ROCKER, 4, 6
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_ROCKER, MOVEMENT_TYPE_FACE_UP
	return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember6ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_WOMAN, 10, 3
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_WOMAN, MOVEMENT_TYPE_FACE_UP
	return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_BEAUTY, 7, 5
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_BEAUTY, MOVEMENT_TYPE_FACE_LEFT
	return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_BLACK_BELT, 9, 6
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_BLACK_BELT, MOVEMENT_TYPE_FACE_LEFT
	return

SaffronCity_PokemonTrainerFanClub_EventScript_SetMemberPosForFirstMeeting::
	call SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable
	call SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable
	call SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember6ToFarTable
	call SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable
	call SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirl::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special Script_BufferFanClubTrainerName
	goto_if_eq VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 0, SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlPlayerNotChampion
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_WasYourFanNotAnymore
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_AlwaysCheerForYou
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_IllAlwaysBelieveInYou
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_EveryonesYourFanButICantBe
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlPlayerNotChampion::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_TrainersCoolWhenBattling
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirl::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER4
	special Script_BufferFanClubTrainerName
	goto_if_eq VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 0, SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayerNotChampion
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_WantToBeLikeSabrina
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_WantToBeLikeYouOneDay
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_EveryoneButMeStoppedBeingYourFan
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_WontStopBeingSabrinasFan
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayerNotChampion::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_CanIBecomeCoolTrainerOneDay
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_Youngster::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER2
	special Script_BufferFanClubTrainerName
	goto_if_eq VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 0, SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterPlayerNotChampion
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_BrocksMyHero
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_CanYouAutographShorts
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_CountingOnYou
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_BrocksFanToBitterEnd
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterPlayerNotChampion::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_BrocksLastWordOnCool
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_Gentleman::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER3
	special Script_BufferFanClubTrainerName
	goto_if_eq VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 0, SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanPlayerNotChampion
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_HmmAndYouAre
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_HadPleasureOfWatchingYouBattle
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_NeverSeenTrainerOfYourMagnificence
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_YouveStillAWaysToGo
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanPlayerNotChampion::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_YoullBeTalkedAboutIfYouKeepWinning
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_Woman::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER6
	special Script_BufferFanClubTrainerName
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_WomanPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_WomanOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_TrainerHasBeenOnFire
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_WomanPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_WomanOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_AdoreWayYouBattle
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_WomanOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_ImYourNumberOneFan
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_WomanOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_EveryoneTalksAboutYou
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_Rocker::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER5
	special Script_BufferFanClubTrainerName
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_RockerPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_RockerOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_LoveWayTrainerTalks
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_RockerPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_RockerOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_TheWayYouBattleIsCool
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_RockerOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_ImOnlyOneLeftOfYourFans
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_RockerOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_ImLoneTrainerFan
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_Beauty::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER7
	special Script_BufferFanClubTrainerName
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_BeautyPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_BeautyOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_WhyCantOthersSeeMastersDignity
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BeautyPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_BeautyOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_YouReallyAreAmazing
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BeautyOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_ImYourOnlyFan
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BeautyOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_BelieveInMasterWithAllMyHeart
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BlackBelt::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER8
	special Script_BufferFanClubTrainerName
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_BlackBeltPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_BlackBeltOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_OnlyMasterHasMyRespect
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BlackBeltPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_BlackBeltOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_YourBattleStyleIsEducational
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BlackBeltOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_WontStopBeingYourFan
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BlackBeltOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_NeverBeFanOfAnyoneButMaster
	release
	end

@ Meloetta's Blues quest, win a battle using four different sound moves
SaffronCity_PokemonTrainerFanClub_EventScript_Pom::
	lock
	faceplayer
	goto_if_quest_complete QUEST_ARIA_OF_SORROW, SaffronCity_PokemonTrainerFanClub_EventScript_PomAfterQuest
	@ Reward state means the battle was won but the gift could not be handed over
	goto_if_quest_reward QUEST_ARIA_OF_SORROW, SaffronCity_PokemonTrainerFanClub_EventScript_PomGiveMeloetta
	goto_if_quest_active QUEST_ARIA_OF_SORROW, SaffronCity_PokemonTrainerFanClub_EventScript_PomAskRematch
	msgbox SaffronCity_PokemonTrainerFanClub_Text_MeloettaIsDepressed, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_PokemonTrainerFanClub_EventScript_PomDeclined
	setflag FLAG_SYS_QUEST_MENU_GET
	startquest QUEST_ARIA_OF_SORROW
	goto SaffronCity_PokemonTrainerFanClub_EventScript_PomBattle
	end

SaffronCity_PokemonTrainerFanClub_EventScript_PomDeclined::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_PomDeclined
	setflag FLAG_SYS_QUEST_MENU_GET
	startquest QUEST_ARIA_OF_SORROW
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_PomAskRematch::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_PomAskRematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_PokemonTrainerFanClub_EventScript_PomDeclined
	goto SaffronCity_PokemonTrainerFanClub_EventScript_PomBattle
	end

@ earlyrival is the only mode that returns here when the player loses
SaffronCity_PokemonTrainerFanClub_EventScript_PomBattle::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_PomLetTheMusicPlay
	closemessage
	@ The hall makes every Sound move hit, for both sides
	setflag FLAG_SOUND_MOVES_NEVER_MISS
	trainerbattle_earlyrival TRAINER_SAFFRON_POM, RIVAL_BATTLE_HEAL_AFTER, SaffronCity_PokemonTrainerFanClub_Text_PomDefeat, SaffronCity_PokemonTrainerFanClub_Text_PomVictory
	goto SaffronCity_PokemonTrainerFanClub_EventScript_PomJudgeBattle
	end

SaffronCity_PokemonTrainerFanClub_EventScript_PomJudgeBattle::
	clearflag FLAG_SOUND_MOVES_NEVER_MISS
	@ earlyrival sets VAR_RESULT to TRUE when the player lost
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_PomQuestFailed
	specialvar VAR_RESULT, GetPlayerSoundMovesUsed
	goto_if_lt VAR_RESULT, MELOETTAS_BLUES_SOUND_MOVES, SaffronCity_PokemonTrainerFanClub_EventScript_PomQuestFailed
	@ Set reward first so a full party or PC can be recovered from
	questmenu QUEST_MENU_SET_REWARD, QUEST_ARIA_OF_SORROW
	goto SaffronCity_PokemonTrainerFanClub_EventScript_PomGiveMeloetta
	end

SaffronCity_PokemonTrainerFanClub_EventScript_PomQuestFailed::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_PomQuestFailed
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_PomGiveMeloetta::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_MeloettaLooksCheerful
	closemessage
	playmoncry SPECIES_MELOETTA, CRY_MODE_NORMAL
	waitmoncry
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MELOETTA
	setflag FLAG_DONT_RANDOMIZE
	givemon SPECIES_MELOETTA, 50
	clearflag FLAG_DONT_RANDOMIZE
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, SaffronCity_PokemonTrainerFanClub_EventScript_MeloettaToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, SaffronCity_PokemonTrainerFanClub_EventScript_MeloettaToPC
	goto SaffronCity_PokemonTrainerFanClub_EventScript_MeloettaNoRoom
	end

SaffronCity_PokemonTrainerFanClub_EventScript_MeloettaToParty::
	playfanfare MUS_LEVEL_UP
	message SaffronCity_PokemonTrainerFanClub_Text_MeloettaJoined
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_MELOETTA
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_PokemonTrainerFanClub_EventScript_FinishMeloettaGift
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SaffronCity_PokemonTrainerFanClub_EventScript_FinishMeloettaGift
	end

SaffronCity_PokemonTrainerFanClub_EventScript_MeloettaToPC::
	playfanfare MUS_LEVEL_UP
	message SaffronCity_PokemonTrainerFanClub_Text_MeloettaJoined
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_MELOETTA
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_PokemonTrainerFanClub_EventScript_MeloettaTransferToPC
	call Common_EventScript_NameReceivedBoxMon
	goto SaffronCity_PokemonTrainerFanClub_EventScript_MeloettaTransferToPC
	end

SaffronCity_PokemonTrainerFanClub_EventScript_MeloettaTransferToPC::
	call Common_EventScript_TransferredToPC
	goto SaffronCity_PokemonTrainerFanClub_EventScript_FinishMeloettaGift
	end

SaffronCity_PokemonTrainerFanClub_EventScript_FinishMeloettaGift::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_PomThankYou
	completequest QUEST_ARIA_OF_SORROW
	release
	end

@ Quest stays in reward state so Pom hands Meloetta over without another battle
SaffronCity_PokemonTrainerFanClub_EventScript_MeloettaNoRoom::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_MeloettaNoRoom
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_PomAfterQuest::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_PomAfterQuest
	release
	end

SaffronCity_PokemonTrainerFanClub_Text_HuhYou::
    .string "Huh?\n"
    .string "You…$"

SaffronCity_PokemonTrainerFanClub_Text_YourePlayerWereYourFansNow::
    .string "Are you maybe…\n"
    .string "… …\p"
    .string "You are!\n"
    .string "You are {PLAYER}!\p"
    .string "We were just talking about you!\p"
    .string "We were talking about how an\n"
    .string "incredibly good Trainer appeared.\p"
    .string "And that someone is you!\n"
    .string "You're so cool!\p"
    .string "So, we decided that we'll become\n"
    .string "your Fan Club!\p"
    .string "We all hope you'll keep battling\n"
    .string "and show us how cool you are.\p"
    .string "That way, maybe other people will\n"
    .string "become fans just like me.$"

SaffronCity_PokemonTrainerFanClub_Text_AlwaysCheerForYou::
    .string "I'll always be cheering for you!\p"
    .string "Go, {PLAYER}, go!$"

SaffronCity_PokemonTrainerFanClub_Text_IllAlwaysBelieveInYou::
    .string "I'll always believe in you,\n"
    .string "{PLAYER}.\p"
    .string "Please show the others what you're\n"
    .string "like when you battle seriously.$"

SaffronCity_PokemonTrainerFanClub_Text_WasYourFanNotAnymore::
    .string "I'm sorry.\n"
    .string "I was your fan before.\p"
    .string "But now, you seem to have lost\n"
    .string "the drive you had before.\p"
    .string "Lately, I think {STR_VAR_1} has been\n"
    .string "a lot cooler.$"

SaffronCity_PokemonTrainerFanClub_Text_EveryonesYourFanButICantBe::
    .string "Oh!\n"
    .string "{PLAYER}!\p"
    .string "Everyone's been all excited about\n"
    .string "you recently.\p"
    .string "I can understand why.\n"
    .string "I know that you're strong.\p"
    .string "But, do you know what?\p"
    .string "Once I became {STR_VAR_1}'s fan,\n"
    .string "I can't just stop being a fan.$"

SaffronCity_PokemonTrainerFanClub_Text_TrainersCoolWhenBattling::
    .string "I think Trainers are so cool when\n"
    .string "they're battling.\p"
    .string "Don't you think so, too?$"

SaffronCity_PokemonTrainerFanClub_Text_CanYouAutographShorts::
    .string "Oh! It's {PLAYER}!\n"
    .string "Too cool!\p"
    .string "Oh!\n"
    .string "Oh, yeah!\p"
    .string "Can you autograph something?\n"
    .string "How about my shorts?$"

SaffronCity_PokemonTrainerFanClub_Text_CountingOnYou::
    .string "However hot it's been…\p"
    .string "And however cold it may get…\p"
    .string "I've always believed in, and worn,\n"
    .string "shorts!\p"
    .string "I'm counting on you to keep\n"
    .string "winning!\p"
    .string "I believe in you just as much as\n"
    .string "I believe in shorts!$"

SaffronCity_PokemonTrainerFanClub_Text_BrocksMyHero::
    .string "Brock's my hero!\n"
    .string "He's a man among men!\p"
    .string "Heheh, I got my mom to do\n"
    .string "something for me.\p"
    .string "I got her to embroider “Brock”\n"
    .string "on my shorts!$"

SaffronCity_PokemonTrainerFanClub_Text_BrocksFanToBitterEnd::
    .string "…  …\p"
    .string "…  …\n"
    .string "I'm Brock's fan!\p"
    .string "Even if I were his only fan,\n"
    .string "I swear it on my rock-hard will,\l"
    .string "and on my shorts!\p"
    .string "I'll be his fan to the bitter end!$"

SaffronCity_PokemonTrainerFanClub_Text_BrocksLastWordOnCool::
    .string "Brock's the last word on cool,\n"
    .string "end of story!\p"
    .string "Now there's a guy who I want to\n"
    .string "be like!$"

SaffronCity_PokemonTrainerFanClub_Text_HadPleasureOfWatchingYouBattle::
    .string "{PLAYER}, I've had the pleasure of\n"
    .string "watching you battle.\p"
    .string "It brings back sweet memories of\n"
    .string "my own long-lost youth.\p"
    .string "May you continue to find success.\n"
    .string "You have a fan in me!$"

SaffronCity_PokemonTrainerFanClub_Text_NeverSeenTrainerOfYourMagnificence::
    .string "I have journeyed far and wide\n"
    .string "across the lands.\p"
    .string "But never have I seen a Trainer\n"
    .string "of your magnificence.\p"
    .string "Take courage in your abilities\n"
    .string "and keep battling on!\p"
    .string "Make that a promise to me,\n"
    .string "my young idol!$"

SaffronCity_PokemonTrainerFanClub_Text_HmmAndYouAre::
    .string "Hmm…\n"
    .string "And you are?\p"
    .string "Were you hoping to sign up for\n"
    .string "a membership in our Fan Club?$"

SaffronCity_PokemonTrainerFanClub_Text_YouveStillAWaysToGo::
    .string "Ah, so you are the much-\n"
    .string "talked-about {PLAYER}.\p"
    .string "You certainly do have the look of\n"
    .string "a winner.\p"
    .string "But for me to accept you as\n"
    .string "a true Pokémon great…\p"
    .string "… …\p"
    .string "You've still a ways to go!$"

SaffronCity_PokemonTrainerFanClub_Text_YoullBeTalkedAboutIfYouKeepWinning::
    .string "All of us gathered here are fans\n"
    .string "of Pokémon Trainers.\p"
    .string "The way they look in battle…\n"
    .string "They are the picture of coolness.\p"
    .string "Perhaps you will be talked about\n"
    .string "here, too, if you keep winning.$"

SaffronCity_PokemonTrainerFanClub_Text_WantToBeLikeYouOneDay::
    .string "It's {PLAYER}!\n"
    .string "It's {PLAYER}!\p"
    .string "I want to be like {PLAYER} one day!$"

SaffronCity_PokemonTrainerFanClub_Text_EveryoneButMeStoppedBeingYourFan::
    .string "Everyone stopped being {PLAYER}'s\n"
    .string "fan…\p"
    .string "But that means I can have {PLAYER}\n"
    .string "all to myself!\p"
    .string "Yay! Go for it!\n"
    .string "My one and only {PLAYER}!$"

SaffronCity_PokemonTrainerFanClub_Text_WantToBeLikeSabrina::
    .string "Do you know what?\n"
    .string "I want to be like Sabrina!\p"
    .string "I want to be a psychic girl just\n"
    .string "like her!$"

SaffronCity_PokemonTrainerFanClub_Text_WontStopBeingSabrinasFan::
    .string "Even if I'm the only one, I won't\n"
    .string "stop being Sabrina's fan.\p"
    .string "My dream is to be like Sabrina,\n"
    .string "cute, but cool.\p"
    .string "I want to be a psychic girl just\n"
    .string "like her!$"

SaffronCity_PokemonTrainerFanClub_Text_CanIBecomeCoolTrainerOneDay::
    .string "I wonder if I can become a cool\n"
    .string "Trainer one day?$"

SaffronCity_PokemonTrainerFanClub_Text_TheWayYouBattleIsCool::
    .string "Oh, man, oh, man!\n"
    .string "Cool! Too cool!\p"
    .string "…Huh?\n"
    .string "No, not you.\p"
    .string "Just the way you battle.\n"
    .string "That's cool.$"

SaffronCity_PokemonTrainerFanClub_Text_ImOnlyOneLeftOfYourFans::
    .string "Yo, {PLAYER}!\p"
    .string "Looks like I'm the only one left\n"
    .string "out of your fans.\p"
    .string "But, you know, I like being an only\n"
    .string "fan… It's less stressful.\p"
    .string "Keep up and at it!$"

SaffronCity_PokemonTrainerFanClub_Text_LoveWayTrainerTalks::
    .string "{STR_VAR_1}'s cool, huh?\n"
    .string "I love the way he talks.\p"
    .string "I'd really relish a chance to meet\n"
    .string "him in person once.$"

SaffronCity_PokemonTrainerFanClub_Text_ImLoneTrainerFan::
    .string "Huh, can you believe it?\n"
    .string "Everyone turned into your fans.\p"
    .string "So after all we've been through,\n"
    .string "I'm the lone {STR_VAR_1} fan?\p"
    .string "Eh, being the one and only\n"
    .string "{STR_VAR_1} fan's my style, anyway.$"

SaffronCity_PokemonTrainerFanClub_Text_AdoreWayYouBattle::
    .string "Oh, my goodness!\n"
    .string "Is it really you, {PLAYER}?\p"
    .string "I have to tell you, I adore the\n"
    .string "way you battle.\p"
    .string "I hope you'll keep at it.\n"
    .string "I'll be your number one fan!$"

SaffronCity_PokemonTrainerFanClub_Text_ImYourNumberOneFan::
    .string "Oh, my goodness!\n"
    .string "If it isn't {PLAYER}!\p"
    .string "It's so disappointing… I realized\n"
    .string "I'm your number-one-and-only fan!\p"
    .string "Well, it can't be helped!\n"
    .string "Let me cheer you on, at least!\p"
    .string "Hurray, hurray, {PLAYER}!$"

SaffronCity_PokemonTrainerFanClub_Text_TrainerHasBeenOnFire::
    .string "Recently, {STR_VAR_1} has been on\n"
    .string "fire.\p"
    .string "The way he battles… It's just \n"
    .string "the way that I like it!$"

SaffronCity_PokemonTrainerFanClub_Text_EveryoneTalksAboutYou::
    .string "Oh, hello!\n"
    .string "If it isn't {PLAYER}!\p"
    .string "Lately, all everyone talks about\n"
    .string "is you.\p"
    .string "I'm feeling lonesome because I\n"
    .string "prefer {STR_VAR_1}.$"

SaffronCity_PokemonTrainerFanClub_Text_YouReallyAreAmazing::
    .string "Amazing!\n"
    .string "{PLAYER}, you really are amazing!\p"
    .string "Instead of just watching, maybe\n"
    .string "I should become a Trainer, too.$"

SaffronCity_PokemonTrainerFanClub_Text_ImYourOnlyFan::
    .string "I'm your only fan…\n"
    .string "Sigh… This is lonely…\p"
    .string "Can't you try harder and make the\n"
    .string "others take notice of you?$"

SaffronCity_PokemonTrainerFanClub_Text_WhyCantOthersSeeMastersDignity::
    .string "Master {STR_VAR_1} is so dignified…\n"
    .string "He is so my type.\p"
    .string "Why can't the others see the\n"
    .string "dignity he simply oozes?$"

SaffronCity_PokemonTrainerFanClub_Text_BelieveInMasterWithAllMyHeart::
    .string "I believe in Master {STR_VAR_1}\n"
    .string "with all my heart.\p"
    .string "Even if I am the only one to\n"
    .string "believe in him.\p"
    .string "I won't ever feel lonesome, though.\p"
    .string "Not if I keep thinking about Master\n"
    .string "{STR_VAR_1}.$"

SaffronCity_PokemonTrainerFanClub_Text_YourBattleStyleIsEducational::
    .string "Hiyah!\p"
    .string "Your battling style is most\n"
    .string "educational.\p"
    .string "I hope that you will keep plugging\n"
    .string "away at success, hiyah!$"

SaffronCity_PokemonTrainerFanClub_Text_WontStopBeingYourFan::
    .string "Instead of just watching others\n"
    .string "battle, battle yourself!\p"
    .string "…My Dojo's Master chewed me out\n"
    .string "like that…\p"
    .string "But I won't let that stop me from\n"
    .string "being your fan!\p"
    .string "I can't stop being your fan!$"

SaffronCity_PokemonTrainerFanClub_Text_OnlyMasterHasMyRespect::
    .string "Hiyah! There is but one Trainer\n"
    .string "who has my respect.\p"
    .string "And that is none other than my\n"
    .string "Master at the Fighting Dojo.\p"
    .string "You should become a fan of my\n"
    .string "Master like me! Hiyah!$"

SaffronCity_PokemonTrainerFanClub_Text_NeverBeFanOfAnyoneButMaster::
    .string "Hiyah! I respect my Master at the\n"
    .string "Fighting Dojo.\p"
    .string "I will never become a fan of\n"
    .string "anyone other than my Master!\p"
    .string "I will even sneak out of the Dojo\n"
    .string "to spread word of his greatness.\p"
    .string "Hiyah!$"

SaffronCity_PokemonTrainerFanClub_Text_MeloettaIsDepressed::
    .string "Greetings, my name is Azalee,\n"
    .string "pleased to make your acquaintance.\p"
    .string "I came to Kanto in the company of\n"
    .string "my dearest friend, Meloetta, in\l"
    .string "search of new musical experiences.\p"
    .string "Alas, Meloetta has been feeling\n"
    .string "terribly distressed for some time\l"
    .string "now, noticing the dire state of\l"
    .string "music in our modern era.\p"
    .string "It won't even sing anymore!\p"
    .string "If it's not too impertinent to ask,\n"
    .string "could you do me a favor?\p"
    .string "Let us have a musical battle.\n"
    .string "Defeat me using four different\l"
    .string "Sound moves in the process.\p"
    .string "Do take heed, though.\n"
    .string "This hall is consecrated to music.\p"
    .string "Within these walls no Sound move\n"
    .string "can ever falter, be it mine or\l"
    .string "yours. Even Sing never misses.\p"
    .string "That might rekindle Meloetta's\n"
    .string "spirit!\p"
    .string "Are you ready to partake in this\n"
    .string "concerto?$"

SaffronCity_PokemonTrainerFanClub_Text_PomDeclined::
    .string "Understandable.\p"
    .string "We'll be here waiting to perform\n"
    .string "should you change your mind.$"

SaffronCity_PokemonTrainerFanClub_Text_PomAskRematch::
    .string "I'm glad to see you again.\p"
    .string "Meloetta still isn't singing.\p"
    .string "Remember, you must use four\n"
    .string "different Sound moves, and you\l"
    .string "have to win!\p"
    .string "And recall that no Sound move\n"
    .string "misses in this hall, mine least\l"
    .string "of all.\p"
    .string "Shall we try again?$"

SaffronCity_PokemonTrainerFanClub_Text_PomLetTheMusicPlay::
    .string "Marvellous!\p"
    .string "And now, if you please, maestro…\n"
    .string "One… two… three!$"

SaffronCity_PokemonTrainerFanClub_Text_PomDefeat::
    .string "A most exquisite performance. I\n"
    .string "expected nothing less from you!$"

SaffronCity_PokemonTrainerFanClub_Text_PomVictory::
    .string "It is natural to have ups and\n"
    .string "downs. Do not lose confidence.$"

SaffronCity_PokemonTrainerFanClub_Text_PomQuestFailed::
    .string "Sigh…\p"
    .string "It pains me to say this, but\n"
    .string "Meloetta's heart is not yet healed.\p"
    .string "You must use four different Sound\n"
    .string "moves and emerge victorious.\p"
    .string "Please come to me again when you'd\n"
    .string "like to have an encore.$"

SaffronCity_PokemonTrainerFanClub_Text_MeloettaLooksCheerful::
    .string "Ah, Meloetta, my soul rejoices to\n"
    .string "see you this blissful.\p"
    .string "{PLAYER}, we have succeeded!\p"
    .string "And while it saddens me, I know I\n"
    .string "must ask you to take Meloetta\l"
    .string "with you.$"

SaffronCity_PokemonTrainerFanClub_Text_MeloettaJoined::
    .string "Azalee gave you a Meloetta!$"

SaffronCity_PokemonTrainerFanClub_Text_PomThankYou::
    .string "I'm sure Meloetta will be able to\n"
    .string "discover a new side to music if it\l"
    .string "goes on an adventure by your side.\p"
    .string "Kindly take good care of it.\p"
    .string "One day, you'll come back to me,\n"
    .string "will you not, my dear friend?\p"
    .string "Thus, we part ways.\n"
    .string "Godspeed, {PLAYER}.$"

SaffronCity_PokemonTrainerFanClub_Text_MeloettaNoRoom::
    .string "Oh dear, you've no room for it.\p"
    .string "I shall hold on to Meloetta.\n"
    .string "Return once you've made space.$"

SaffronCity_PokemonTrainerFanClub_Text_PomAfterQuest::
    .string "From time to time, I communicate\n"
    .string "with Meloetta through psychic\l"
    .string "waves.\p"
    .string "Knowing that it's singing happily\n"
    .string "again is all I ever wanted.\p"
    .string "You have my perennial gratitude.$"

