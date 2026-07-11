SafariZone_North_RestHouse_Frlg_MapScripts::
	.byte 0

SafariZone_North_RestHouse_EventScript_Fisher::
	msgbox SafariZone_East_Text_PrizeInDeepestPartOfSafariZone, MSGBOX_NPC
	end

SafariZone_North_RestHouse_EventScript_Scientist::
	msgbox SafariZone_East_Text_KeepAnyItemFoundOnSafari, MSGBOX_NPC
	end

SafariZone_North_RestHouse_EventScript_BugCatcherQuiz::
	lock
	faceplayer
	goto_if_set FLAG_SAFARI_BUG_CATCHER_QUIZ, SafariZone_North_RestHouse_EventScript_BugCatcherQuizDone
	msgbox SafariZone_North_RestHouse_Text_BugCatcherIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SafariZone_North_RestHouse_EventScript_BugCatcherDecline
	@ Question 1 - hidden ability (answer: Spewpa, index 1)
	message SafariZone_North_RestHouse_Text_BugCatcherQuestion1
	waitmessage
	dynmultichoice 0, 0, TRUE, 4, 0, DYN_MULTICHOICE_CB_NONE, SafariZone_North_RestHouse_Text_ChoiceMetapod, SafariZone_North_RestHouse_Text_ChoiceSpewpa, SafariZone_North_RestHouse_Text_ChoiceCharjabug, SafariZone_North_RestHouse_Text_ChoiceCascoon
	goto_if_ne VAR_RESULT, 1, SafariZone_North_RestHouse_EventScript_BugCatcherWrong
	@ Question 2 - can't learn Tackle (answer: Kakuna, index 1)
	playse SE_SUCCESS
	delay 10
	playse SE_SUCCESS
	message SafariZone_North_RestHouse_Text_BugCatcherQuestion2
	waitmessage
	dynmultichoice 0, 0, TRUE, 4, 0, DYN_MULTICHOICE_CB_NONE, SafariZone_North_RestHouse_Text_ChoiceMetapod, SafariZone_North_RestHouse_Text_ChoiceKakuna, SafariZone_North_RestHouse_Text_ChoiceSilcoon, SafariZone_North_RestHouse_Text_ChoiceSpewpa
	goto_if_ne VAR_RESULT, 1, SafariZone_North_RestHouse_EventScript_BugCatcherWrong
	@ Question 3 - shiny cocoon with blue eyes (answer: Silcoon, index 0)
	playse SE_SUCCESS
	delay 10
	playse SE_SUCCESS
	message SafariZone_North_RestHouse_Text_BugCatcherQuestion3
	waitmessage
	dynmultichoice 0, 0, TRUE, 4, 0, DYN_MULTICHOICE_CB_NONE, SafariZone_North_RestHouse_Text_ChoiceSilcoon, SafariZone_North_RestHouse_Text_ChoiceCascoon, SafariZone_North_RestHouse_Text_ChoiceKakuna, SafariZone_North_RestHouse_Text_ChoiceSpewpa
	goto_if_ne VAR_RESULT, 0, SafariZone_North_RestHouse_EventScript_BugCatcherWrong
	closemessage
	playse SE_SUCCESS
	delay 10
	playse SE_SUCCESS
	msgbox SafariZone_North_RestHouse_Text_BugCatcherCorrect, MSGBOX_DEFAULT
	giveitem ITEM_SHED_SHELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_SAFARI_BUG_CATCHER_QUIZ
	msgbox SafariZone_North_RestHouse_Text_BugCatcherReward, MSGBOX_DEFAULT
	release
	end

SafariZone_North_RestHouse_EventScript_BugCatcherWrong::
	closemessage
	msgbox SafariZone_North_RestHouse_Text_BugCatcherIncorrect, MSGBOX_DEFAULT
	release
	end

SafariZone_North_RestHouse_EventScript_BugCatcherDecline::
	msgbox SafariZone_North_RestHouse_Text_BugCatcherMaybeLater, MSGBOX_DEFAULT
	release
	end

SafariZone_North_RestHouse_EventScript_BugCatcherQuizDone::
	msgbox SafariZone_North_RestHouse_Text_BugCatcherAlreadyDone, MSGBOX_DEFAULT
	release
	end

SafariZone_East_Text_KeepAnyItemFoundOnSafari::
    .string "You can keep any item you find in\n"
    .string "the Safari Zone.\p"
    .string "But, you'll run out of time if you\n"
    .string "try for all of them at once.$"

SafariZone_East_Text_PrizeInDeepestPartOfSafariZone::
    .string "Go to the deepest part of the\n"
    .string "Safari Zone. You will win a prize!$"

SafariZone_North_RestHouse_Text_BugCatcherIntro::
    .string "Bug Pokémon are the greatest, don't\n"
    .string "you think? So elegant! So diverse!\p"
    .string "I've got a little quiz on cocoon and\n"
    .string "Bug Pokémon. Three questions.\p"
    .string "Get them all right and I'll give you\n"
    .string "a rare reward! Want to try?$"

SafariZone_North_RestHouse_Text_BugCatcherQuestion1::
    .string "Question 1!\p"
    .string "Which of these Pokémon has a\n"
    .string "Hidden Ability?$"

SafariZone_North_RestHouse_Text_BugCatcherQuestion2::
    .string "Correct! Question 2!\p"
    .string "Which of these Pokémon is unable\n"
    .string "to learn Tackle?$"

SafariZone_North_RestHouse_Text_BugCatcherQuestion3::
    .string "Nicely done! Question 3!\p"
    .string "Which cocoon Pokémon has a Shiny\n"
    .string "form with blue eyes?$"

SafariZone_North_RestHouse_Text_BugCatcherCorrect::
    .string "Again, correct! Three for three!\p"
    .string "You really know your Bug Pokémon!\n"
    .string "Here, take this as your reward!$"

SafariZone_North_RestHouse_Text_BugCatcherReward::
    .string "A Shed Shell lets a Pokémon switch\n"
    .string "out no matter what. Handy, right?$"

SafariZone_North_RestHouse_Text_BugCatcherIncorrect::
    .string "Incorrect! Try again next time!$"

SafariZone_North_RestHouse_Text_BugCatcherMaybeLater::
    .string "No? Come back anytime you feel like\n"
    .string "testing your Bug knowledge!$"

SafariZone_North_RestHouse_Text_BugCatcherAlreadyDone::
    .string "You already aced my quiz! You're a\n"
    .string "true Bug Pokémon expert!$"

SafariZone_North_RestHouse_Text_ChoiceMetapod::
    .string "Metapod$"

SafariZone_North_RestHouse_Text_ChoiceSpewpa::
    .string "Spewpa$"

SafariZone_North_RestHouse_Text_ChoiceCharjabug::
    .string "Charjabug$"

SafariZone_North_RestHouse_Text_ChoiceCascoon::
    .string "Cascoon$"

SafariZone_North_RestHouse_Text_ChoiceKakuna::
    .string "Kakuna$"

SafariZone_North_RestHouse_Text_ChoiceSilcoon::
    .string "Silcoon$"

