ViridianCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_OnTransition
	.byte 0

ViridianCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VIRIDIAN_CITY
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 0, ViridianCity_EventScript_TryUnlockGym
	end

ViridianCity_EventScript_SetOldManNormal::
	@ setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_1
	return

ViridianCity_EventScript_SetOldManStandingByRoad::
	@ setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_1
	@ setobjectxyperm LOCALID_TUTORIAL_MAN, 21, 8
	@ setobjectmovementtype LOCALID_TUTORIAL_MAN, MOVEMENT_TYPE_LOOK_AROUND
	return

ViridianCity_EventScript_SetOldManBlockingRoad::
	@ setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_LYING_DOWN
	@ setobjectxyperm LOCALID_TUTORIAL_MAN, 21, 11
	@ setobjectmovementtype LOCALID_TUTORIAL_MAN, MOVEMENT_TYPE_FACE_DOWN
	return

ViridianCity_EventScript_TryUnlockGym::
	goto_if_unset FLAG_BADGE02_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE03_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE04_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE05_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE06_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE07_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_DEFEATED_GIOVANNI_CERULEAN_CAVE, Common_EventScript_NopReturn
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 1
	return

ViridianCity_EventScript_GymDoorLocked::
	lockall
	textcolor NPC_TEXT_COLOR_NEUTRAL
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	goto_if_unset FLAG_BADGE07_GET, ViridianCity_EventScript_GymDoorLockedNormal
	goto_if_unset FLAG_DEFEATED_GIOVANNI_CERULEAN_CAVE, ViridianCity_EventScript_GymDoorLockedGoToCC
	releaseall
	end

ViridianCity_EventScript_GymDoorLockedNormal:
	msgbox ViridianCity_Text_GymDoorsAreLocked
	closemessage
	applymovement LOCALID_PLAYER, ViridianCity_Movement_JumpDownLedge
	waitmovement 0
	releaseall
	end

ViridianCity_EventScript_GymDoorLockedGoToCC:
	msgbox ViridianCity_Text_GymDoorsAreLockedCC
	closemessage
	applymovement LOCALID_PLAYER, ViridianCity_Movement_JumpDownLedge
	waitmovement 0
	releaseall
	end
ViridianCity_Movement_JumpDownLedge::
	jump_2_down
	step_end

ViridianCity_EventScript_CitySign::
	msgbox ViridianCity_Text_CitySign, MSGBOX_SIGN
	end

ViridianCity_EventScript_TrainerTips1::
	msgbox ViridianCity_Text_CatchMonsForEasierBattles, MSGBOX_SIGN
	end

ViridianCity_EventScript_TrainerTips2::
	msgbox ViridianCity_Text_MovesLimitedByPP, MSGBOX_SIGN
	end

ViridianCity_EventScript_GymSign::
	msgbox ViridianCity_Text_GymSign, MSGBOX_SIGN
	end

ViridianCity_EventScript_GymDoor::
	msgbox ViridianCity_Text_GymDoorsAreLocked, MSGBOX_SIGN
	end

ViridianCity_EventScript_Boy::
	msgbox ViridianCity_Text_CanCarryMonsAnywhere, MSGBOX_NPC
	end

@ Other old man, not the tutorial old man
ViridianCity_EventScript_OldMan::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 1, ViridianCity_EventScript_OldManGymLeaderReturned
	msgbox ViridianCity_Text_GymClosedWonderWhoLeaderIs
	closemessage
	applymovement LOCALID_VIRIDIAN_OLD_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

ViridianCity_EventScript_OldManGymLeaderReturned::
	msgbox ViridianCity_Text_ViridiansGymLeaderReturned
	release
	end

ViridianCity_EventScript_TutorialOldMan::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE06_GET, ViridianCity_EventScript_OldManTired
	goto_if_quest_complete QUEST_MISSING_NUMBER, ViridianCity_EventScript_MissingNumberDone
	goto_if_quest_active QUEST_MISSING_NUMBER, ViridianCity_EventScript_MissingNumberCheck
	msgbox ViridianCity_Text_MissingNumberIntro
	setflag FLAG_SYS_QUEST_MENU_GET
	startquest QUEST_MISSING_NUMBER
	release
	end

ViridianCity_EventScript_OldManTired::
	msgbox ViridianCity_Text_UsedToHelpLads
	release
	end

ViridianCity_EventScript_MissingNumberCheck::
	checkitem ITEM_LOTTO_TICKET
	goto_if_eq VAR_RESULT, TRUE, ViridianCity_EventScript_MissingNumberReward
	msgbox ViridianCity_Text_MissingNumberReminder
	release
	end

ViridianCity_EventScript_MissingNumberReward::
	msgbox ViridianCity_Text_MissingNumberAwShucks
	msgbox ViridianCity_Text_MissingNumberTakeThis
	giveitem ITEM_CHOICE_BAND
	removeitem ITEM_LOTTO_TICKET, 1
	completequest QUEST_MISSING_NUMBER
	release
	end

ViridianCity_EventScript_MissingNumberDone::
	msgbox ViridianCity_Text_MissingNumberThanks
	release
	end

ViridianCity_EventScript_AskIfTeachyTVHelpful::
	msgbox ViridianCity_Text_HowsTeachyTVHelping, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_EventScript_TeachyTVNotHelpful
	msgbox ViridianCity_Text_MyGrandsonOnTheShow
	release
	end

ViridianCity_EventScript_TeachyTVNotHelpful::
	msgbox ViridianCity_Text_TooBusyForTeachyTV
	release
	end

ViridianCity_EventScript_TutorialCompleted::
	msgbox ViridianCity_Text_WeakenMonsFirstToCatch
	release
	end

ViridianCity_EventScript_TutorialStart::
	call ViridianCity_EventScript_DoTutorialBattle
	release
	end

ViridianCity_EventScript_TutorialNotReady::
	msgbox ViridianCity_Text_ThisIsPrivateProperty
	closemessage
	release
	end

ViridianCity_EventScript_Youngster::
	lock
	faceplayer
	goto_if_set FLAG_NES_GAVE_INFINITE_CANDY, ViridianCity_EventScript_Youngster_WillyWonka
	msgbox ViridianCity_Text_WantToKnowAboutCaterpillarMons, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ViridianCity_EventScript_YoungsterExplainCaterpillars
	goto_if_eq VAR_RESULT, NO, ViridianCity_EventScript_YoungsterDeclineExplanation
	end

ViridianCity_EventScript_Youngster_WillyWonka::
	msgbox ViridianCity_Text_ExplainWillyWonka
	release
	end

ViridianCity_EventScript_YoungsterExplainCaterpillars::
	msgbox ViridianCity_Text_ExplainCaterpieWeedle
	release
	end

ViridianCity_EventScript_YoungsterDeclineExplanation::
	msgbox ViridianCity_Text_OhOkayThen
	release
	end

ViridianCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_eq VAR_OAKS_LAB_AIDE_GIVE_BOX_LINK, 0, ViridianCity_EventScript_WomanRoadBlocked
	msgbox ViridianCity_Text_GoShoppingInPewterOccasionally
	release
	end

ViridianCity_EventScript_WomanRoadBlocked::
	msgbox ViridianCity_Text_GrandpaHasntHadCoffeeYet
	closemessage
	applymovement LOCALID_VIRIDIAN_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

ViridianCity_EventScript_DreamEaterTutor::
	goto EventScript_DreamEaterTutor
	end

ViridianCity_EventScript_RoadBlocked::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox ViridianCity_Text_ThisIsPrivateProperty
	closemessage
	applymovement LOCALID_PLAYER, ViridianCity_Movement_WalkDown
	waitmovement 0
	releaseall
	end

ViridianCity_Movement_WalkDown::
	walk_down
	step_end

ViridianCity_EventScript_TutorialTriggerLeft::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_TUTORIAL_MAN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call ViridianCity_EventScript_DoTutorialBattle
	release
	end

ViridianCity_EventScript_TutorialTriggerRight::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_TUTORIAL_MAN, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	call ViridianCity_EventScript_DoTutorialBattle
	release
	end

ViridianCity_EventScript_DoTutorialBattle::
	msgbox ViridianCity_Text_ShowYouHowToCatchMons
	closemessage
	@ special StartOldManTutorialBattle
	@ waitstate
	lock
	@ faceplayer
	msgbox ViridianCity_Text_ThatWasEducationalTakeThis
	setvar VAR_OAKS_LAB_AIDE_GIVE_BOX_LINK, 2
	giveitem ITEM_TEACHY_TV
	msgbox ViridianCity_Text_ThatThingsUseless
	return

ViridianCity_EventScript_TriggerBrendanCeruleanCaveLeft::
	goto_if_unset FLAG_BADGE07_GET, ViridianCity_EventScript_TriggerNothing
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	setspeaker SP_NAME_BRENDAN
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	msgbox ViridianCity_Text_BrendanToCerulean_Greet
	waitmessage
	waitbuttonpress
	addobject LOCALID_VIRIDIAN_BRENDAN
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitse
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_VIRIDIAN_BRENDAN, ViridianCity_Movement_BrendanApproachLeft
	waitmovement 0
	goto ViridianCity_EventScript_TriggerBrendanCeruleanCave

ViridianCity_EventScript_TriggerBrendanCeruleanCaveMiddle::
	goto_if_unset FLAG_BADGE07_GET, ViridianCity_EventScript_TriggerNothing
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	setspeaker SP_NAME_BRENDAN
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	msgbox ViridianCity_Text_BrendanToCerulean_Greet
	waitmessage
	waitbuttonpress
	addobject LOCALID_VIRIDIAN_BRENDAN
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitse
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_VIRIDIAN_BRENDAN, ViridianCity_Movement_BrendanApproachMiddle
	waitmovement 0
	goto ViridianCity_EventScript_TriggerBrendanCeruleanCave

ViridianCity_EventScript_TriggerBrendanCeruleanCaveRight::
	goto_if_unset FLAG_BADGE07_GET, ViridianCity_EventScript_TriggerNothing
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	setspeaker SP_NAME_BRENDAN
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	msgbox ViridianCity_Text_BrendanToCerulean_Greet
	waitmessage
	waitbuttonpress
	addobject LOCALID_VIRIDIAN_BRENDAN
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitse
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_VIRIDIAN_BRENDAN, ViridianCity_Movement_BrendanApproachRight
	waitmovement 0
	goto ViridianCity_EventScript_TriggerBrendanCeruleanCave

ViridianCity_EventScript_TriggerNothing:
	end

ViridianCity_EventScript_TriggerBrendanCeruleanCave:
	setspeaker SP_NAME_BRENDAN
	msgbox ViridianCity_Text_BrendanToCerulean_GladToFindYou
	setspeaker SP_NAME_BRENDAN
	msgbox ViridianCity_Text_BrendanToCeruleanNeedYourHelp
	fadescreen FADE_TO_BLACK
	playse SE_USE_ITEM
	waitse
	special HealPlayerParty
	fadescreen FADE_FROM_BLACK
	setflag FLAG_HIDE_CERULEAN_CAVE_GUARD
	setflag FLAG_HIDE_ROUTE_22_RIVAL
	setvar VAR_VIRIDIAN_TRIGGER_CERULEAN_CAVE 1
	setspeaker SP_NAME_BRENDAN
	msgbox ViridianCity_Text_BrendanToCerulean_LetsGo
	waitbuttonpress
	warp MAP_CERULEAN_CAVE_1F 33 20
	waitstate
	end


ViridianCity_Movement_BrendanApproachLeft:
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_down
	step_end

ViridianCity_Movement_BrendanApproachMiddle:
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_down
	step_end

ViridianCity_Movement_BrendanApproachRight:
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_down
	step_end 

ViridianCity_Text_CanCarryMonsAnywhere::
    .string "Those Poké Balls at your waist!\n"
    .string "You have Pokémon, don't you?\p"
    .string "It's great that you can carry and\n"
    .string "use Pokémon anytime, anywhere.$"

ViridianCity_Text_GymClosedWonderWhoLeaderIs::
    .string "This Pokémon Gym is always closed.\p"
    .string "I wonder who the Leader is?$"

ViridianCity_Text_ViridiansGymLeaderReturned::
    .string "Viridian Gym's Leader is here!$"

ViridianCity_Text_WantToKnowAboutCaterpillarMons::
    .string "You want to know about the two\n"
    .string "kinds of caterpillar Pokémon?$"

ViridianCity_Text_OhOkayThen::
    .string "Oh, okay then!$"

ViridianCity_Text_ExplainWillyWonka::
	.string "…Oh nice, you got the Infinite Candy.\n"
	.string "If you're curious on how such a\l"
	.string "thing even works…\p"
	.string "I heard Soupercell commissioned\n"
	.string "Willy Wonka himself quite a bit of\l"
	.string "money!$"

ViridianCity_Text_ExplainCaterpieWeedle::
    .string "Caterpie has no poison,\n"
    .string "but Weedle does.\p"
    .string "Watch that your Pokémon aren't\n"
    .string "stabbed by Weedle's Poison Sting.$"

ViridianCity_Text_GrandpaHasntHadCoffeeYet::
    .string "Oh, Grandpa!\n"
    .string "Don't be so mean!\p"
    .string "I'm so sorry.\n"
    .string "He hasn't had his coffee yet.$"

ViridianCity_Text_GoShoppingInPewterOccasionally::
    .string "I go shopping in Pewter City\n"
    .string "occasionally.\p"
    .string "I have to take the winding trail in\n"
    .string "Viridian Forest when I go.$"

ViridianCity_Text_ThisIsPrivateProperty::
    .string "I absolutely forbid you from\n"
    .string "going through here!\p"
    .string "This is private property!$"

ViridianCity_Text_ShowYouHowToCatchMons::
    .string "Well, now, I've had my coffee, and\n"
    .string "that's what I need to get going!\p"
    .string "Hm?\n"
    .string "What is that red box you have?\p"
    .string "Ah, so you're working on your\n"
    .string "Pokédex.\p"
    .string "Then let me give you a word of\n"
    .string "advice.\p"
    .string "Whenever you catch a Pokémon,\n"
    .string "the Pokédex automatically updates\l"
    .string "its data.$"

ViridianCity_Text_ThatWasEducationalTakeThis::
    .string "And here, take this, too.$"

ViridianCity_Text_ThatThingsUseless::
    .string "That thing's useless!$"

ViridianCity_Text_WeakenMonsFirstToCatch::
    .string "Well, now, I've had my coffee, and\n"
    .string "that's what I need to get going!\p"
    .string "But I made it too strong.\n"
    .string "It gave me a headache…\p"
    .string "Incidentally, are you filling your\n"
    .string "Pokédex?\p"
    .string "At first, focus on weakening the\n"
    .string "Pokémon before trying to catch it.$"

ViridianCity_Text_HowsTeachyTVHelping::
    .string "Well, now, I've had my coffee, and\n"
    .string "that's what I need to get going!\p"
    .string "But I made it too strong.\n"
    .string "It gave me a headache…\p"
    .string "Incidentally, how much dust is my\n"
    .string "old Teachy TV gathering?$"

ViridianCity_Text_MyGrandsonOnTheShow::
    .string "Wahaha!\n"
    .string "It's my grandson on the show!\p"
    .string "Since he's the one doing the\n"
    .string "teaching, you're bound to learn.$"

ViridianCity_Text_TooBusyForTeachyTV::
    .string "Hm… You're too busy to not even\n"
    .string "have the time for Teachy TV…\p"
    .string "Time is money, and neither should\n"
    .string "be ill spent…$"

ViridianCity_Text_CitySign::
    .string "Viridian City \n"
    .string "The Eternally Green Paradise$"

ViridianCity_Text_CatchMonsForEasierBattles::
    .string "Trainer Tips\p"
	.string "Consumable held items are automati-\n"
	.string "cally retrieved at the end of each\l"
	.string "battle!$"

ViridianCity_Text_MovesLimitedByPP::
    .string "Trainer Tips\p"
	.string "Natures can be a big difference maker!\n"
	.string "The stats colored in Red are in-\l"
	.string "creased by 10% while the stats co-\l"
	.string "lored in blue are decreased by 10%.$"

ViridianCity_Text_GymSign::
    .string "Viridian City Pokémon Gym$"

ViridianCity_Text_GymDoorsAreLocked::
    .string "Viridian Gym's doors are locked…$"

ViridianCity_Text_GymDoorsAreLockedCC::
    .string "Viridian Gym's doors are locked…\n"
	.string "Perhaps we should help Brendan out in\l"
	.string "Cerulean Cave?$"

ViridianCity_Text_BrendanToCerulean_Greet::
    .string "{PLAYER}!$"

ViridianCity_Text_BrendanToCerulean_GladToFindYou::
	.string "Oh my, I'm so glad to have found\n"
	.string "you.\p"
	.string "May told me she had just bumped into\n"
	.string "you here, so I hurried back over\l"
	.string "here hoping nto find you.$"

ViridianCity_Text_BrendanToCeruleanNeedYourHelp::
	.string "I've come looking for your help!\p"
	.string "You're really the only one I know\n"
	.string "capable of stopping this.\p"
	.string "Team Rocket has occupied Cerulean\n"
	.string "Cave!\p"
	.string "There's rumors that a powerful\n"
	.string "legendary rests there…\p"
	.string "Could that be what they're after?!\p"
	.string "It sounds like bad news.\p"
	.string "Anywho, we need to put an end to\n"
	.string "it!\p"
	.string "Oh, you'd like a heal? Sure thing…$"

ViridianCity_Text_BrendanToCerulean_LetsGo::
	.string "Okay, off we go.$"

ViridianCity_Text_UsedToHelpLads::
	.string "I used to help young lads like you\n"
	.string "learn how to catch Pokémon.\p"
	.string "Now you young ones act like complete\n"
	.string "know it alls.\p"
	.string "How disrespectful, you lot!$"

ViridianCity_Text_MissingNumberIntro::
	.string "Bah! You caught me in a foul mood.\p"
	.string "I've been grouchy for weeks now, ever\n"
	.string "since I lost my lotto ticket.\p"
	.string "I dropped it somewhere along the east\n"
	.string "side of Cinnabar Island, of all the\l"
	.string "far-flung places.\p"
	.string "I don't lose things often, even in my\n"
	.string "old age. Believe it or not.\p"
	.string "Almost felt like a glitch in the\n"
	.string "matrix…\p"
	.string "If a spry young thing like you could\n"
	.string "track it down, I'd make it worth your\l"
	.string "while. What do you say?$"

ViridianCity_Text_MissingNumberReminder::
	.string "Still no sign of my lotto ticket?\p"
	.string "Check the east side of Cinnabar\n"
	.string "Island. That's where I lost it.$"

ViridianCity_Text_MissingNumberAwShucks::
	.string "My lotto ticket! You actually found\n"
	.string "it!\p"
	.string "Let me just check the number and…\p"
	.string "…Aw, shucks. Doesn't match a single\n"
	.string "digit. What a load of hooey.$"

ViridianCity_Text_MissingNumberTakeThis::
	.string "Still, you went to all that trouble\n"
	.string "for a grouchy old coot like me.\p"
	.string "Here, take this. It belonged to a\n"
	.string "battler I trained back in the day.$"

ViridianCity_Text_MissingNumberThanks::
	.string "That Choice Band's a fine piece of\n"
	.string "gear. Put it to good use.\p"
	.string "And thanks again for humoring an old\n"
	.string "man, you hear?$"
