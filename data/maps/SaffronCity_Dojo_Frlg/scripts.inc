SaffronCity_Dojo_Frlg_MapScripts::
	.byte 0

SaffronCity_Dojo_EventScript_TriggerMasterBattleLeft::
	lockall
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
	applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	releaseall
	end

SaffronCity_Dojo_EventScript_TriggerMasterBattleRight::
	lockall
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
	applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	releaseall
	end

SaffronCity_Dojo_EventScript_HitmonleeBall::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_AlreadyGotHitmon
	showmonpic SPECIES_TAUROS_PALDEA_BLAZE, 10, 3
	setvar VAR_TEMP_1, SPECIES_TAUROS_PALDEA_BLAZE
	applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox SaffronCity_Dojo_Text_YouWantHitmonlee, MSGBOX_YESNO
	call EventScript_RestorePrevTextColor
	goto_if_eq VAR_RESULT, YES, SaffronCity_Dojo_EventScript_GiveHitmon
	hidemonpic
	release
	end

SaffronCity_Dojo_EventScript_AlreadyGotHitmon::
	msgbox SaffronCity_Dojo_Text_BetterNotGetGreedy
	release
	end

SaffronCity_Dojo_EventScript_HitmonchanBall::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_AlreadyGotHitmon
	showmonpic SPECIES_TAUROS_PALDEA_AQUA, 10, 3
	setvar VAR_TEMP_1, SPECIES_TAUROS_PALDEA_AQUA
	applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox SaffronCity_Dojo_Text_YouWantHitmonchan, MSGBOX_YESNO
	call EventScript_RestorePrevTextColor
	goto_if_eq VAR_RESULT, YES, SaffronCity_Dojo_EventScript_GiveHitmon
	hidemonpic
	release
	end

SaffronCity_Dojo_EventScript_GiveHitmon::
	hidemonpic
	givemon VAR_TEMP_1, 25
	goto_if_eq VAR_RESULT, 0, SaffronCity_Dojo_EventScript_ReceivedHitmonParty
	goto_if_eq VAR_RESULT, 1, SaffronCity_Dojo_EventScript_ReceivedHitmonPC
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	release
	end

SaffronCity_Dojo_EventScript_ReceivedHitmonParty::
	removeobject VAR_LAST_TALKED
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster
	waitmessage
	waitfanfare
	setflag FLAG_GOT_HITMON_FROM_DOJO
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_EndGiveMon
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SaffronCity_Dojo_EventScript_EndGiveMon
	end

SaffronCity_Dojo_EventScript_ReceivedHitmonPC::
	removeobject VAR_LAST_TALKED
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster
	waitmessage
	waitfanfare
	setflag FLAG_GOT_HITMON_FROM_DOJO
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_TransferredHitmonToPC
	call Common_EventScript_NameReceivedBoxMon
	goto SaffronCity_Dojo_EventScript_TransferredHitmonToPC
	end

SaffronCity_Dojo_EventScript_TransferredHitmonToPC::
	call Common_EventScript_TransferredToPC
	goto SaffronCity_Dojo_EventScript_EndGiveMon
	end

SaffronCity_Dojo_EventScript_EndGiveMon::
	release
	end

SaffronCity_Dojo_EventScript_Statue::
	msgbox SaffronCity_Dojo_Text_FightingDojo, MSGBOX_SIGN
	end

SaffronCity_Dojo_EventScript_LeftScroll::
	msgbox SaffronCity_Dojo_Text_EnemiesOnEverySide, MSGBOX_SIGN
	end

SaffronCity_Dojo_EventScript_RightScroll::
	msgbox SaffronCity_Dojo_Text_GoesAroundComesAround, MSGBOX_SIGN
	end

SaffronCity_Dojo_EventScript_Hitoshi::
	trainerbattle_single TRAINER_BLACK_BELT_HITOSHI, SaffronCity_Dojo_Text_HitoshiIntro, SaffronCity_Dojo_Text_HitoshiDefeat
	msgbox SaffronCity_Dojo_Text_HitoshiPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Hideki::
	trainerbattle_single TRAINER_BLACK_BELT_HIDEKI, SaffronCity_Dojo_Text_HidekiIntro, SaffronCity_Dojo_Text_HidekiDefeat
	msgbox SaffronCity_Dojo_Text_HidekiPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Aaron::
	trainerbattle_single TRAINER_BLACK_BELT_AARON, SaffronCity_Dojo_Text_AaronIntro, SaffronCity_Dojo_Text_AaronDefeat
	msgbox SaffronCity_Dojo_Text_AaronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Mike::
	trainerbattle_single TRAINER_BLACK_BELT_MIKE, SaffronCity_Dojo_Text_MikeIntro, SaffronCity_Dojo_Text_MikeDefeat
	msgbox SaffronCity_Dojo_Text_MikePostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_MasterKoichi::
	trainerbattle_single TRAINER_BLACK_BELT_CHUCK, SaffronCity_Dojo_Text_ChuckIntro, SaffronCity_Dojo_Text_ChuckDefeat, SaffronCity_Dojo_EventScript_DefeatedMasterKoichi
	goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_MasterKoichiAlreadyGotHitmon
	msgbox SaffronCity_Dojo_Text_ChoosePrizedFightingMon, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_MasterKoichiAlreadyGotHitmon::
	msgbox SaffronCity_Dojo_Text_StayAndTrainWithUs
	release
	end

SaffronCity_Dojo_EventScript_DefeatedMasterKoichi::
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
	setflag FLAG_DEFEATED_CHUCK
    msgbox SaffronCity_Dojo_Text_ChoosePrizedFightingMon
    call_if_unset FLAG_UNLOCKED_STAT_EDITOR, EventScript_Whitney_StatEditExplain
    callnative SetBuffer1ToEvCap
	msgbox johtoLeader_Text_CurrentEvCap
	setflag FLAG_UNLOCKED_STAT_EDITOR
	msgbox SaffronCity_Dojo_Text_HaveTMDrainPunch
	giveitem ITEM_TM_DRAIN_PUNCH
	release
	end

SaffronCity_Dojo_Text_ChuckIntro::
    .string "{COLOR BLUE}Hello there little chump!\p"
    .string "I'm Chuck, and I've taken over\n"
    .string "as the Karate Master of this dojo!\p"
    .string "I can put you in a choke-hold in\n"
    .string "a matter of seconds if I wanted to!\p"
    .string "What?\p"
    .string "It has nothing to do with Pokémon?\p"
    .string "Haha! A challenger long ago once\n"
    .string "said the same thing!\p"
    .string "Come on, we shall do battle!$"

SaffronCity_Dojo_Text_ChuckDefeat::
    .string "Wha! I lost?!\n"
    .string "Incredible!$"

SaffronCity_Dojo_Text_ChoosePrizedFightingMon::
    .string "{COLOR BLUE}What a crushing defeat!\p"
    .string "It's back to 24-hour training for\n"
    .string "me!\p"
    .string "But, I'm impressed, challenger.\p"
    .string "Here, I can give your Pokémon some\n"
    .string "nifty enhancements!$"

SaffronCity_Dojo_Text_HaveTMDrainPunch::
	.string "{COLOR BLUE}And here, my favorite TM!\p"
	.string "What could be more crushing than defeating\n"
	.string "the foe and also gaining HP!$"

SaffronCity_Dojo_Text_StayAndTrainWithUs::
    .string "Grunt!\n"
    .string "Stay and train at karate with us!$"

SaffronCity_Dojo_Text_MikeIntro::
    .string "Hoargh!\n"
    .string "Take your shoes off!$"

SaffronCity_Dojo_Text_MikeDefeat::
    .string "I give up!$"

SaffronCity_Dojo_Text_MikePostBattle::
    .string "You wait 'til you see our MASTER!\n"
    .string "I'm a small fry compared to him!$"

SaffronCity_Dojo_Text_HidekiIntro::
    .string "I hear you're good!\n"
    .string "Show me!$"

SaffronCity_Dojo_Text_HidekiDefeat::
    .string "Judge!\n"
    .string "One point!$"

SaffronCity_Dojo_Text_HidekiPostBattle::
    .string "Our MASTER is a pro fighter.\n"
    .string "Be prepared to lose!$"

SaffronCity_Dojo_Text_AaronIntro::
    .string "Hiyah!\n"
    .string "I have no fear for anything tough!\p"
    .string "I shatter boulders for training\n"
    .string "every day!$"

SaffronCity_Dojo_Text_AaronDefeat::
    .string "Yow!\n"
    .string "Stubbed fingers!$"

SaffronCity_Dojo_Text_AaronPostBattle::
    .string "The only thing that frightens us is\n"
    .string "psychic power!$"

SaffronCity_Dojo_Text_HitoshiIntro::
    .string "Hwaah!\p"
    .string "You're trespassing in our\n"
    .string "FIGHTING DOJO!$"

SaffronCity_Dojo_Text_HitoshiDefeat::
    .string "Oof!\n"
    .string "I give up!$"

SaffronCity_Dojo_Text_HitoshiPostBattle::
    .string "The prime fighters across the land\n"
    .string "train here.$"

SaffronCity_Dojo_Text_YouWantHitmonlee::
    .string "You want the Tauros Blaze Breed?$"

SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster::
    .string "{PLAYER} received the {STR_VAR_1}\n"
    .string "from the KARATE MASTER.$"

SaffronCity_Dojo_Text_YouWantHitmonchan::
    .string "You want the Tauros Aqua Breed?$"

SaffronCity_Dojo_Text_BetterNotGetGreedy::
    .string "Better not get greedy…$"

SaffronCity_Dojo_Text_EnemiesOnEverySide::
    .string "Enemies on every side!$"

SaffronCity_Dojo_Text_GoesAroundComesAround::
    .string "What goes around comes around.$"

SaffronCity_Dojo_Text_FightingDojo::
    .string "FIGHTING DOJO$"

