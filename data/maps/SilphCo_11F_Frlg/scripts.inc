SilphCo_11F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_11F_OnLoad
	.byte 0

SilphCo_11F_OnLoad::
	call_if_unset FLAG_SILPH_11F_DOOR, EventScript_Close11FDoor
	end

SilphCo_11F_EventScript_President::
	lock
	faceplayer
	goto_if_set FLAG_GOT_MASTER_BALL_FROM_SILPH, SilphCo_11F_EventScript_GhostQuest
	setspeaker SP_NAME_PRESIDENT
	checkplayergender
	call_if_eq VAR_RESULT, MALE, SilphCo_11F_EventScript_PresidentThanksMale
	call_if_eq VAR_RESULT, FEMALE, SilphCo_11F_EventScript_PresidentThanksFemale
	checkitemspace ITEM_MASTER_BALL
	goto_if_eq VAR_RESULT, FALSE, SilphCo_11F_EventScript_NoRoomForMasterBall
	giveitem_msg SilphCo_11F_Text_ObtainedMasterBallFromPresident, ITEM_MASTER_BALL, 1, MUS_RG_OBTAIN_KEY_ITEM
	setspeaker SP_NAME_PRESIDENT
	msgbox SilphCo_11F_Text_ThatsOurSecretPrototype
	setflag FLAG_GOT_MASTER_BALL_FROM_SILPH
	goto_if_set FLAG_DEFEATED_SABRINA, SilphCo_11F_EventScript_GhostQuest
	release
	end

@ Ghost in the Machine quest, offered once Sabrina is beaten
SilphCo_11F_EventScript_GhostQuest::
	setspeaker SP_NAME_PRESIDENT
	goto_if_quest_complete QUEST_GHOST_IN_THE_MACHINE, SilphCo_11F_EventScript_PresidentAfterQuest
	goto_if_eq VAR_SILPH_CO_GHOST_QUEST, 4, SilphCo_11F_EventScript_PresidentReward
	goto_if_quest_active QUEST_GHOST_IN_THE_MACHINE, SilphCo_11F_EventScript_PresidentReminder
	goto_if_unset FLAG_DEFEATED_SABRINA, SilphCo_11F_EventScript_AlreadyGotMasterBall
	msgbox SilphCo_11F_Text_PresidentGhostPlea
	msgbox SilphCo_11F_Text_PresidentGhostAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SilphCo_11F_EventScript_PresidentDeclined
	setflag FLAG_SYS_QUEST_MENU_GET
	setvar VAR_SILPH_CO_GHOST_QUEST, 1
	startquest QUEST_GHOST_IN_THE_MACHINE
	setspeaker SP_NAME_PRESIDENT
	msgbox SilphCo_11F_Text_PresidentGoToLavender
	release
	end

@ Quest is not started so he asks again next time
SilphCo_11F_EventScript_PresidentDeclined::
	msgbox SilphCo_11F_Text_PresidentDeclined
	release
	end

SilphCo_11F_EventScript_PresidentReminder::
	goto_if_ge VAR_SILPH_CO_GHOST_QUEST, 2, SilphCo_11F_EventScript_PresidentReminderTeleporter
	msgbox SilphCo_11F_Text_PresidentReminder
	release
	end

SilphCo_11F_EventScript_PresidentReminderTeleporter::
	msgbox SilphCo_11F_Text_PresidentReminderTeleporter
	release
	end

@ Var stays at 4 until the balls actually fit so a full bag can be recovered from
SilphCo_11F_EventScript_PresidentReward::
	msgbox SilphCo_11F_Text_PresidentThankYou
	giveitem ITEM_LUXURY_BALL, 3
	setspeaker SP_NAME_PRESIDENT
	msgbox SilphCo_11F_Text_PresidentLuxuryBallDeal
	setflag FLAG_LUXURY_BALLS_IN_MARTS
	setvar VAR_SILPH_CO_GHOST_QUEST, 5
	completequest QUEST_GHOST_IN_THE_MACHINE
	release
	end

SilphCo_11F_EventScript_PresidentAfterQuest::
	msgbox SilphCo_11F_Text_PresidentAfterQuest
	release
	end

SilphCo_11F_EventScript_PresidentThanksMale::
	msgbox SilphCo_11F_Text_ThanksForSavingMeDearBoy
	return

SilphCo_11F_EventScript_PresidentThanksFemale::
	msgbox SilphCo_11F_Text_ThanksForSavingMeDearGirl
	return

SilphCo_11F_EventScript_NoRoomForMasterBall::
	msgbox SilphCo_11F_Text_YouHaveNoRoomForThis
	release
	end

SilphCo_11F_EventScript_AlreadyGotMasterBall::
	msgbox SilphCo_11F_Text_ThatsOurSecretPrototype
	release
	end

SilphCo_11F_EventScript_Secretary::
	setspeaker SP_NAME_SECRETARY
	msgbox SilphCo_11F_Text_ThanksForRescuingUs, MSGBOX_NPC
	end

SilphCo_11F_EventScript_GiovanniTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto SilphCo_11F_EventScript_BattleGiovanni
	end

SilphCo_11F_EventScript_GiovanniTriggerRight::
	lockall
	setvar VAR_TEMP_1, 1
	goto SilphCo_11F_EventScript_BattleGiovanni
	end

SilphCo_11F_EventScript_BattleGiovanni::
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_SILPH_CO_GIOVANNI, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 25
	setspeaker SP_NAME_GIOVANNI
	msgbox SilphCo_11F_Text_GiovanniIntro
	closemessage
	call_if_eq VAR_TEMP_1, 0, SilphCo_11F_EventScript_GiovanniApproachLeft
	call_if_eq VAR_TEMP_1, 1, SilphCo_11F_EventScript_GiovanniApproachRight
	setvar VAR_LAST_TALKED, LOCALID_SILPH_CO_GIOVANNI
	trainerbattle_no_intro TRAINER_BOSS_GIOVANNI_2, SilphCo_11F_Text_GiovanniDefeat
	setspeaker SP_NAME_GIOVANNI
	msgbox SilphCo_11F_Text_GiovanniPostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_SILPH_CO_GIOVANNI
	removeobject LOCALID_SILPH_CO_11F_GRUNT1
	fadescreen FADE_FROM_BLACK
	setvar VAR_MAP_SCENE_SILPH_CO_11F, 1
	setflag FLAG_HIDE_SAFFRON_ROCKETS
	clearflag FLAG_HIDE_SAFFRON_CIVILIANS
	releaseall
	end

SilphCo_11F_EventScript_GiovanniApproachLeft::
	applymovement LOCALID_SILPH_CO_GIOVANNI, SilphCo_11F_Movement_GiovanniApproachLeft
	applymovement LOCALID_PLAYER, SilphCo_11F_Movement_PlayerFaceGiovanni
	waitmovement 0
	return

SilphCo_11F_EventScript_GiovanniApproachRight::
	applymovement LOCALID_SILPH_CO_GIOVANNI, SilphCo_11F_Movement_GiovanniApproachRight
	waitmovement 0
	return

SilphCo_11F_Movement_GiovanniApproachLeft::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

SilphCo_11F_Movement_GiovanniApproachRight::
	walk_down
	walk_down
	walk_down
	step_end

SilphCo_11F_Movement_PlayerFaceGiovanni::
	delay_16
	delay_16
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_right
	step_end

@ Unused
SilphCo_11F_EventScript_Monitor::
	msgbox SilphCo_11F_Text_MonitorHasMonsOnIt, MSGBOX_SIGN
	end

SilphCo_11F_EventScript_FloorSign::
	msgbox SilphCo_11F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_11F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_40, SilphCo_11F_Text_Grunt1Intro, SilphCo_11F_Text_Grunt1Defeat
	msgbox SilphCo_11F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

@ Trigger: player stepped on left tile
SilphCo_11F_EventScript_ArcherArianaTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto SilphCo_11F_EventScript_ArcherArianaScene
	end

@ Trigger: player stepped on right tile
SilphCo_11F_EventScript_ArcherArianaTriggerRight::
	lockall
	setvar VAR_TEMP_1, 1
	goto SilphCo_11F_EventScript_ArcherArianaScene
	end

SilphCo_11F_EventScript_ArcherArianaScene::
	addobject LOCALID_SILPHCO_ARCHER
	addobject LOCALID_SILPHCO_ARIANA
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_SILPHCO_ARCHER, SilphCo_11F_Movement_ArcherArianaWalkUp
	applymovement LOCALID_SILPHCO_ARIANA, SilphCo_11F_Movement_ArcherArianaWalkUp
	waitmovement 0
	applymovement LOCALID_PLAYER, SilphCo_11F_Movement_PlayerStepUp
	waitmovement 0
	setspeaker SP_NAME_ARIANA
	msgbox SilphCo_11F_Text_ArcherArianaIntro1
	@ applymovement LOCALID_SILPHCO_ARCHER, Common_Movement_FaceLeft
	@ waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	setspeaker SP_NAME_ARCHER
	msgbox SilphCo_11F_Text_ArcherArianaIntro2
	setspeaker SP_NAME_ARIANA
	msgbox SilphCo_11F_Text_ArcherArianaIntro3
	setspeaker SP_NAME_ARCHER
	msgbox SilphCo_11F_Text_ArcherArianaIntro3_1
	setspeaker SP_NAME_ARIANA
	msgbox SilphCo_11F_Text_ArcherArianaIntro3_2
	@ playse SE_BALL_THROW
	applymovement LOCALID_SILPHCO_ARCHER, Common_Movement_FaceRight
	waitmovement 0
	@ waitse
	@ textcolor NPC_TEXT_COLOR_MALE
	setspeaker SP_NAME_ARCHER
	msgbox SilphCo_11F_Text_ArcherArianaIntro4
	applymovement LOCALID_SILPHCO_ARCHER, Common_Movement_FaceUp
	waitmovement 0
	setspeaker SP_NAME_ARIANA
	msgbox SilphCo_11F_Text_ArcherArianaIntro5
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	setspeaker SP_NAME_UNKNOWN 
	msgbox SilphCo_11F_Text_BrendanAppears
	addobject LOCALID_SILPHCO_BRENDAN
	@ playse SE_BIKE_BELL
	applymovement LOCALID_PLAYER, SilphCo_11F_Movement_QuestionMark
	applymovement LOCALID_SILPHCO_ARCHER, SilphCo_11F_Movement_QuestionMark
	waitmovement 0
	@ waitse
	@ Brendan approaches based on player tile position
	call_if_eq VAR_TEMP_1, 0, SilphCo_11F_EventScript_BrendanComeMiddle
	call_if_eq VAR_TEMP_1, 1, SilphCo_11F_EventScript_BrendanComeRight
	@ Brendan faces player and introduces himself
	@ textcolor NPC_TEXT_COLOR_MALE
	setspeaker SP_NAME_BRENDAN
	msgbox SilphCo_11F_Text_BrendanIntro1
	applymovement LOCALID_SILPHCO_BRENDAN, SilphCo_11F_Movement_FaceRight
	waitmovement 0
	call_if_eq VAR_TEMP_1, 0, SilphCo_11F_EventScript_PlayerFaceRight
	call_if_eq VAR_TEMP_1, 1, SilphCo_11F_EventScript_PlayerFaceLeft
	setspeaker SP_NAME_BRENDAN
	msgbox SilphCo_11F_Text_BrendanIntro2
	@ Player faces down, Brendan faces down to signal battle start
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_SILPHCO_BRENDAN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	@ textcolor NPC_TEXT_COLOR_FEMALE
	msgbox SilphCo_11F_Text_ArcherArianaPreBattle
SilphCo_11F_EventScript_ArcherArianaChooseTeam:
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_eq VAR_RESULT, 0, SilphCo_11F_EventScript_ArcherArianaChooseTeam
	@ Tag battle: Player/Brendan vs Archer/Ariana
	multi_2_vs_2 TRAINER_SILPH_CO_ARCHER, SilphCo_11F_Text_ArcherDefeat, TRAINER_SILPH_CO_ARIANA, SilphCo_11F_Text_ArianaDefeat, PARTNER_SILPH_BRENDAN
	@ Post-battle
	switch VAR_RESULT
	case 1, SilphCo_11F_EventScript_DefeatedArcherArianaScene
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	waitstate

SilphCo_11F_EventScript_DefeatedArcherArianaScene::
	setspeaker SP_NAME_ARCHER
	msgbox SilphCo_11F_Text_PostBattle1
	setspeaker SP_NAME_ARIANA
	msgbox SilphCo_11F_Text_PostBattle1_2
	@ applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	@ waitmovement 0
	setspeaker SP_NAME_ARIANA
	msgbox SilphCo_11F_Text_PostBattle2
	@ applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	@ waitmovement 0
	setspeaker SP_NAME_ARCHER
	msgbox SilphCo_11F_Text_PostBattle3
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_SILPHCO_ARCHER
	removeobject LOCALID_SILPHCO_ARIANA
	@ playse SE_BALL_THROW
	@ waitse
	fadescreen FADE_FROM_BLACK
	call_if_eq VAR_TEMP_1, 0, SilphCo_11F_EventScript_PlayerFaceRight
	call_if_eq VAR_TEMP_1, 1, SilphCo_11F_EventScript_PlayerFaceLeft
	@ Brendan's farewell — he's now hidden, so player faces where he was
	@ textcolor NPC_TEXT_COLOR_MALE
	setspeaker SP_NAME_BRENDAN
	msgbox SilphCo_11F_Text_BrendanFarewell1
	@ playse SE_CONTEST_HALL_ENTER
	setspeaker SP_NAME_BRENDAN
	@ waitse

	textcolor NPC_TEXT_COLOR_MALE
	msgbox SilphCo_11F_Text_BrendanFarewell3
	giveitem ITEM_HM_ROCK_SMASH
	setspeaker SP_NAME_BRENDAN
	msgbox SilphCo_11F_Text_BrendanFarewell4
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_SILPHCO_BRENDAN
	fadescreen FADE_FROM_BLACK
	@ msgbox SilphCo_11F_Text_LevelCapIncreased, MSGBOX_SIGN
	setvar VAR_MAP_SCENE_SILPH_CO_11F_ARCHER, 1
	special HealPlayerParty
	releaseall
	end

SilphCo_11F_EventScript_BrendanComeMiddle::
	applymovement LOCALID_SILPHCO_BRENDAN, SilphCo_11F_Movement_BrendanApproach
	waitmovement 0
	return

SilphCo_11F_EventScript_BrendanComeRight::
	applymovement LOCALID_SILPHCO_BRENDAN, SilphCo_11F_Movement_BrendanApproachRight
	waitmovement 0
	return

SilphCo_11F_EventScript_PlayerFaceRight::
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_SILPHCO_BRENDAN, Common_Movement_FaceLeft
	waitmovement 0
	return

SilphCo_11F_EventScript_PlayerFaceLeft::
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_SILPHCO_BRENDAN, Common_Movement_FaceRight
	waitmovement 0
	return

@ ============================================================
@ Movement Scripts
@ ============================================================

SilphCo_11F_Movement_ArcherArianaWalkUp::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SilphCo_11F_Movement_PlayerStepUp::
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

SilphCo_11F_Movement_FaceLeft::
	face_left
	step_end

SilphCo_11F_Movement_FaceRight::
	face_right
	step_end

SilphCo_11F_Movement_FaceUp::
	face_up
	step_end

SilphCo_11F_Movement_FaceDown::
	face_down
	step_end

SilphCo_11F_Movement_QuestionMark::
	emote_question_mark
	step_end

SilphCo_11F_Movement_BrendanApproach::
	@ Brendan walks down from his starting position to meet the player
	@ (adjust walk count to match map layout)
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	emote_exclamation_mark
	face_down
	step_end

SilphCo_11F_Movement_BrendanApproachRight::
	face_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SilphCo_11F_Movement_BrendanExit::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SilphCo_11F_Text_ArcherArianaIntro1::
	.string "Looks like we found our intruder.$"

SilphCo_11F_Text_ArcherArianaIntro2::
	.string "Wait a sec…\p"
	.string "This is the punk I ran into at\n"
	.string "Mt. Moon!$"

SilphCo_11F_Text_ArcherArianaIntro3::
	.string "Wow, you lost to this loser?$"

SilphCo_11F_Text_ArcherArianaIntro3_1::
	.string "Quiet, I'm sure my Mightyena gave\n"
	.string "this punk a scare.$"

SilphCo_11F_Text_ArcherArianaIntro3_2::
	.string "Your Mightyena doesn't even have\n"
	.string "Intimidate.$"

SilphCo_11F_Text_ArcherArianaIntro4::
	.string "Would you SHUT UP, Ari?!\p"
	.string "We've got things to deal with here.$"

SilphCo_11F_Text_ArcherArianaIntro5::
	.string "Geez, someone's grumpy…\p"
	.string "Sorry, kid. Looks like your fun\n"
	.string "ends here.$"

SilphCo_11F_Text_BrendanAppears::
	.string "Wait a moment!$"

SilphCo_11F_Text_BrendanIntro1::
	.string "Don't you think two\n"
	.string "against one is a little unfair?$"

SilphCo_11F_Text_BrendanIntro2::
	.string "Heh, sorry I'm late to\n"
	.string "the party, {PLAYER}.\p"
	.string "Let me give you a hand!$"

SilphCo_11F_Text_ArcherArianaPreBattle::
	.string "Who the hell…?\p"
	.string "The more the merrier I guess.\p"
	.string "Whatever, neither of you will be\n"
	.string "reaching the Boss.$"

SilphCo_11F_Text_ArcherDefeat::
	.string "Again?!\n"
	.string "This is infuriating!$"

SilphCo_11F_Text_ArianaDefeat::
	.string "We lost?! To these idiots?$"


SilphCo_11F_Text_PostBattle1::
	.string "Damn it…\p"
	.string "I hate this…$"

SilphCo_11F_Text_PostBattle1_2::
	.string "Boss won't be happy about this.$"

SilphCo_11F_Text_PostBattle2::
	.string "Of course he won't.\n"
	.string "We ought to scram.$"

SilphCo_11F_Text_PostBattle3::
	.string "Pray you don't meet us again,\n"
	.string "{PLAYER}.$"

SilphCo_11F_Text_BrendanFarewell1::
	.string "Whew…\p"
	.string "To be honest, I was quite scared!\p"
	.string "But I knew they stood no chance\n"
	.string "with you on my side.\p"
	.string "You're simply incredible!$"

SilphCo_11F_Text_BrendanFarewell3::
	.string "I'd love to help you further, but\n"
	.string "I have something urgent to attend\n"
	.string "to back in Hoenn.\p"
	.string "I think you have this mostly handled\n"
	.string "anyway.\p"
	.string "Before I part, take this.$"

SilphCo_11F_Text_ObtainedTM68::
	.string "Again, I apologize for\n"
	.string "needing to leave so abruptly…\p"
	.string "Please, take another parting gift.$"

SilphCo_11F_Text_BrendanFarewell4::
	.string "Good luck, friend.$"

SilphCo_11F_Text_ThanksForSavingMeDearBoy::
    .string "Oh, dear boy!\n"
    .string "Thank you for saving Silph.\p"
    .string "I will never forget you saved us in\n"
    .string "our moment of peril.\p"
    .string "I have to thank you in some way.\p"
    .string "Because I am rich, I can give you\n"
    .string "anything.\p"
    .string "Here, maybe this will do.$"

SilphCo_11F_Text_ThanksForSavingMeDearGirl::
    .string "Oh, dear girl!\n"
    .string "Thank you for saving Silph.\p"
    .string "I will never forget you saved us in\n"
    .string "our moment of peril.\p"
    .string "I have to thank you in some way.\p"
    .string "Because I am rich, I can give you\n"
    .string "anything.\p"
    .string "Here, maybe this will do.$"

SilphCo_11F_Text_ObtainedMasterBallFromPresident::
    .string "{PLAYER} obtained a Master Ball\n"
    .string "from the President!$"

SilphCo_11F_Text_ThatsOurSecretPrototype::
    .string "You can't buy that\n"
    .string "anywhere.\p"
    .string "It's our secret prototype Master\n"
    .string "Ball.\p"
    .string "It will catch any Pokémon without\n"
    .string "fail!\p"
    .string "You should be quiet about using it,\n"
    .string "though.$"

SilphCo_11F_Text_YouHaveNoRoomForThis::
    .string "You have no room for this.$"

SilphCo_11F_Text_PresidentGhostPlea::
    .string "Oh, {PLAYER}! Thank Arceus you're\n"
    .string "here. Please, hear an old man out!\p"
    .string "Ever since you drove those Rockets\n"
    .string "out, Silph has been bleeding money.\p"
    .string "Slowly at first… then all at once.\n"
    .string "Faster than I could brace for.\p"
    .string "I've searched this building floor by\n"
    .string "floor and found nothing. Nothing!\p"
    .string "I'm starting to think it's a ghost,\n"
    .string "or something of its kind.$"

SilphCo_11F_Text_PresidentGhostAsk::
    .string "Help this old man get his company's\n"
    .string "glory back.\p"
    .string "There's someone in Lavender Town\n"
    .string "who handles this sort of thing…\p"
    .string "Will you go and speak with them?$"

SilphCo_11F_Text_PresidentDeclined::
    .string "Oh no…\p"
    .string "My company. My company…$"

SilphCo_11F_Text_PresidentGoToLavender::
    .string "Bless you, {PLAYER}.\p"
    .string "Lavender Town. Ask after the young\n"
    .string "woman who studies the departed.$"

SilphCo_11F_Text_PresidentReminder::
    .string "Lavender Town, {PLAYER}.\p"
    .string "They know ghosts there better than\n"
    .string "anyone alive.$"

SilphCo_11F_Text_PresidentReminderTeleporter::
    .string "A teleporter? On my own ground\n"
    .string "floor? In all these years…\p"
    .string "Whatever is down there, {PLAYER},\n"
    .string "I'm counting on you.$"

SilphCo_11F_Text_PresidentThankYou::
    .string "A rival? All of this, over a rival?\p"
    .string "Ha! And here I was losing sleep over\n"
    .string "phantoms.\p"
    .string "You've given an old man his nerve\n"
    .string "back. Let me give you something too.$"

SilphCo_11F_Text_PresidentLuxuryBallDeal::
    .string "Some of our finest.\p"
    .string "And I'll see to it that every Poké\n"
    .string "Mart in Kanto carries them now.\p"
    .string "Silph keeps its promises.\n"
    .string "Unlike some people.$"

SilphCo_11F_Text_PresidentMakeRoom::
    .string "…Ah. Your Bag is rather full.\p"
    .string "Make some room and come back.\n"
    .string "They'll be waiting right here.$"

SilphCo_11F_Text_PresidentAfterQuest::
    .string "Business is picking up again, and I\n"
    .string "have you to thank for it.\p"
    .string "Let that young upstart contend all\n"
    .string "he likes. Silph is ready for him.$"

SilphCo_11F_Text_ThanksForRescuingUs::
    .string "Thank you for rescuing\n"
    .string "all of us.\p"
    .string "We, from the President down,\n"
    .string "are indebted to you.$"

SilphCo_11F_Text_GiovanniIntro::
    .string "Ah, {PLAYER}!\n"
    .string "So we meet again!\p"
    .string "The President and I are discussing\n"
    .string "a vital business proposition.\p"
    .string "Keep your nose out of grown-up\n"
    .string "matters…\p"
    .string "Or, experience a world of pain!$"

SilphCo_11F_Text_GiovanniDefeat::
    .string "Arrgh!!\n"
    .string "I lost again!?$"

SilphCo_11F_Text_GiovanniPostBattle::
    .string "Blast it all!\n"
    .string "You ruined our plans for Silph!\p"
    .string "But, Team Rocket will never fall!\p"
    .string "{PLAYER}! Never forget that all\n"
    .string "Pokémon exist for Team Rocket!\p"
    .string "I must go, but I shall return!$"

SilphCo_11F_Text_Grunt1Intro::
    .string "Halt! Do you have an appointment\n"
    .string "with my Boss?$"

SilphCo_11F_Text_Grunt1Defeat::
    .string "Gaah!\n"
    .string "Demolished!$"

SilphCo_11F_Text_Grunt1PostBattle::
    .string "Watch your step…\n"
    .string "My Boss likes his Pokémon tough!$"

SilphCo_11F_Text_MonitorHasMonsOnIt::
    .string "The monitor has Pokémon on it!$"

SilphCo_11F_Text_FloorSign::
    .string "Silph Co. Head Office\n"
    .string "11F$"
