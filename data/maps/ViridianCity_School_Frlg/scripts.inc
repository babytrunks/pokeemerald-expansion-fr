ViridianCity_School_Frlg_MapScripts::
	.byte 0

ViridianCity_School_EventScript_Lass::
	lock
	faceplayer
	msgbox ViridianCity_School_Text_TryingToMemorizeNotes
	closemessage
	applymovement LOCALID_SCHOOL_LASS, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

ViridianCity_School_EventScript_Woman::
	lock
	msgbox ViridianCity_School_Text_ReadBlackboardCarefully
	closemessage
	faceplayer
	msgbox ViridianCity_School_Text_YouDontSeemNew
	closemessage
	goto CheckIfBeatAllViridianForestTrainers
ViridianCity_School_EventScript_WomanEnd::
	applymovement LOCALID_SCHOOL_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CheckIfBeatAllViridianForestTrainers:
	goto_if_not_defeated TRAINER_LASS_ANNE, ViridianCity_School_EventScript_WomanEnd
	goto_if_not_defeated TRAINER_BUG_CATCHER_ANTHONY, ViridianCity_School_EventScript_WomanEnd
	goto_if_not_defeated TRAINER_BUG_CATCHER_SAMMY, ViridianCity_School_EventScript_WomanEnd
	goto_if_not_defeated TRAINER_BUG_CATCHER_DOUG, ViridianCity_School_EventScript_WomanEnd
	goto_if_not_defeated TRAINER_BUG_CATCHER_RICK, ViridianCity_School_EventScript_WomanEnd
	msgbox ViridianCity_School_Text_EntertainMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ViridianCity_School_EventScript_FightTeacher
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_WomanReject

ViridianCity_School_EventScript_FightTeacher::
	trainerbattle_single TRAINER_STARTER_TEACHER, ViridianCity_School_Text_GiveItAll, ViridianCity_School_Text_Defeated, ViridianCity_School_EventScript_GiveMon, NO_MUSIC
ViridianCity_School_EventScript_GiveMon::
	msgbox ViridianCity_School_Text_HaveYourPick
	setflag FLAG_RARE_POKEMON_SCREEN
	setflag FLAG_BEAT_VIRIDIAN_CITY_TEACHER
	setvar VAR_RARE_POKEMON_COUNTER 0
	factory_generaterentalmons
	factory_rentmons
	waitstate
	clearflag FLAG_RARE_POKEMON_SCREEN
ViridianCity_School_EventScript_BeatenTeacher::
	msgbox ViridianCity_School_Text_Study
	release
	end

ViridianCity_School_EventScript_WomanReject::
	msgbox ViridianCity_School_Text_WomanReject
	release
	end 

ViridianCity_School_EventScript_Notebook::
	lockall
	msgbox ViridianCity_School_Text_NotebookFirstPage
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
	msgbox ViridianCity_School_Text_NotebookSecondPage
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
	msgbox ViridianCity_School_Text_NotebookThirdPage
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
	msgbox ViridianCity_School_Text_NotebookFourthPage
	applymovement LOCALID_SCHOOL_LASS, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox ViridianCity_School_Text_HeyDontLookAtMyNotes
	releaseall
	end

ViridianCity_School_EventScript_StopReadingNotebook::
	releaseall
	end

ViridianCity_School_EventScript_Blackboard::
	lockall
	msgbox ViridianCity_School_Text_BlackboardListsStatusProblems
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ChooseBlackboardTopic::
	message ViridianCity_School_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 7, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, ViridianCity_School_EventScript_ReadSleep
	case 1, ViridianCity_School_EventScript_ReadPoison
	case 2, ViridianCity_School_EventScript_ReadParalysis
	case 3, ViridianCity_School_EventScript_ReadBurn
	case 4, ViridianCity_School_EventScript_ReadFreeze
	case 5, ViridianCity_School_EventScript_ExitBlackboard
	case 127, ViridianCity_School_EventScript_ExitBlackboard
	end

ViridianCity_School_EventScript_ReadSleep::
	msgbox ViridianCity_School_Text_ExplainSleep
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ReadBurn::
	msgbox ViridianCity_School_Text_ExplainBurn
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ReadPoison::
	msgbox ViridianCity_School_Text_ExplainPoison
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ReadFreeze::
	msgbox ViridianCity_School_Text_ExplainFreeze
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ReadParalysis::
	msgbox ViridianCity_School_Text_ExplainParalysis
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ExitBlackboard::
	releaseall
	end

ViridianCity_School_Text_TryingToMemorizeNotes::
    .string "Whew! I'm trying to memorize all my\n"
    .string "notes.$"

ViridianCity_School_Text_ReadBlackboardCarefully::
    .string "Okay!\p"
    .string "Be sure to read what's on the\n"
    .string "blackboard carefully!$"

ViridianCity_School_Text_YouDontSeemNew::
    .string "…You're from Pallet Town, aren't you?\p"
    .string "You have quite the potential.\p"
    .string "Tell you what - beat all the\n"
    .string "trainers in Viridian Forest\l"
    .string "and I'll reward you with something\l"
    .string "special.$"

ViridianCity_School_Text_EntertainMe::
    .string "…Oh nice, you actually beat all\n"
    .string "of them.\p"
    .string "Entertain me in a battle,\n"
    .string "and I'll let you choose a\l"
    .string "another starter Pokémon.\p"
    .string "Y'know, those rare Pokémon\n"
    .string "Oak has stashed away.\p"
    .string "You wanna give it a go?$"

ViridianCity_School_Text_GiveItAll::
    .string "Give it all you got!$"

ViridianCity_School_Text_WomanReject::
    .string "Aw… Being a teacher is a thankless\n"
    .string "job. Please reconsider it!$"

ViridianCity_School_Text_Defeated::
    .string "Entertained I was!$"

ViridianCity_School_Text_Study::
    .string "Study hard and further yourself!$"

ViridianCity_School_Text_HaveYourPick::
	.string "Well then, have your pick!$"

ViridianCity_School_Text_NotebookFirstPage::
    .string "Let's check out the notebook.\p"
    .string "First page…\p"
    .string "Poké Balls are used to catch\n"
    .string "Pokémon.\p"
    .string "Up to six Pokémon can be carried\n"
    .string "in your party.\p"
    .string "People who raise and battle\n"
    .string "with Pokémon are called TRAINERS.$"

ViridianCity_School_Text_NotebookSecondPage::
    .string "Second page…\p"
    .string "A healthy Pokémon may be hard to\n"
    .string "catch, so weaken it first.\p"
    .string "Poison, burn, or cause another\n"
    .string "status problem to weaken it.$"

ViridianCity_School_Text_NotebookThirdPage::
    .string "Third page…\p"
    .string "Pokémon TRAINERS seek others to\n"
    .string "engage in Pokémon battles.\p"
    .string "To TRAINERS, the taste of victory\n"
    .string "is sweet, indeed.\p"
    .string "Battles are constantly waged at\n"
    .string "Pokémon GYMS everywhere.$"

ViridianCity_School_Text_NotebookFourthPage::
    .string "Fourth page…\p"
    .string "The ultimate goal for all Pokémon\n"
    .string "TRAINERS is simple.\p"
    .string "It is to defeat the top eight\n"
    .string "Pokémon GYM LEADERS.\p"
    .string "Do so to earn the right to face…\p"
    .string "The ELITE FOUR of the Pokémon\n"
    .string "LEAGUE!$"

ViridianCity_School_Text_TurnThePage::
    .string "Turn the page?$"

ViridianCity_School_Text_HeyDontLookAtMyNotes::
    .string "GIRL: Hey!\n"
    .string "Don't look at my notes!$"

ViridianCity_School_Text_BlackboardListsStatusProblems::
    .string "The blackboard lists Pokémon\n"
    .string "STATUS problems during battles.$"

ViridianCity_School_Text_ReadWhichTopic::
    .string "Which topic do you want to read?$"

ViridianCity_School_Text_ExplainSleep::
    .string "A Pokémon can't attack if it's\n"
    .string "asleep.\p"
    .string "Pokémon will stay asleep even\n"
    .string "after battles.\p"
    .string "Use AWAKENING to awaken one\n"
    .string "from sleep.$"

ViridianCity_School_Text_ExplainBurn::
    .string "A burn reduces ATTACK power.\n"
    .string "It also causes ongoing HP loss.\p"
    .string "A burn remains after a battle.\n"
    .string "Use BURN HEAL to cure a burn.$"

ViridianCity_School_Text_ExplainPoison::
    .string "When poisoned, a Pokémon's health\n"
    .string "steadily drops.\p"
    .string "Poison lingers after battles.\n"
    .string "Use an ANTIDOTE to cure poison!$"

ViridianCity_School_Text_ExplainFreeze::
    .string "A frozen Pokémon becomes\n"
    .string "helplessly immobile.\p"
    .string "It stays frozen even after the\n"
    .string "battle ends.\p"
    .string "Use ICE HEAL to thaw out the\n"
    .string "suffering Pokémon.$"

ViridianCity_School_Text_ExplainParalysis::
    .string "Paralysis reduces SPEED and may\n"
    .string "prevent the Pokémon from moving.\p"
    .string "Paralysis remains after battles.\n"
    .string "Use PARLYZ HEAL for treatment.$"

