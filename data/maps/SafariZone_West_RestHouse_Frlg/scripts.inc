SafariZone_West_RestHouse_Frlg_MapScripts::
	.byte 0

SafariZone_West_RestHouse_EventScript_Man::
	msgbox SafariZone_West_Text_BaitMakesMonStickAround, MSGBOX_NPC
	end

SafariZone_West_RestHouse_EventScript_CooltrainerF::
	msgbox SafariZone_West_Text_HikedLotsDidntSeeMonIWanted, MSGBOX_NPC
	end

SafariZone_West_RestHouse_EventScript_Anabel::
	lockall
	faceplayer
	goto_if_defeated TRAINER_SAFARI_ZONE_ANABEL, SafariZone_West_RestHouse_EventScript_AnabelDone
	setspeaker SP_NAME_UNKNOWN
	msgbox SafariZone_West_RestHouse_Text_AnabelIntro1
	setspeaker SP_NAME_ANABEL
	msgbox SafariZone_West_RestHouse_Text_AnabelIntro2
	setspeaker SP_NAME_ANABEL
	msgbox SafariZone_West_RestHouse_Text_AnabelTicket
	setspeaker SP_NAME_ANABEL
	msgbox SafariZone_West_RestHouse_Text_AnabelAskChallenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_West_RestHouse_EventScript_AnabelBattle
	setspeaker SP_NAME_ANABEL
	msgbox SafariZone_West_RestHouse_Text_AnabelDecline
	release
	end

SafariZone_West_RestHouse_EventScript_AnabelBattle::
	setspeaker SP_NAME_ANABEL
	msgbox SafariZone_West_RestHouse_Text_AnabelPreBattle
	special HealPlayerParty
	trainerbattle_no_intro TRAINER_SAFARI_ZONE_ANABEL, SafariZone_West_RestHouse_Text_AnabelDefeat
	setspeaker SP_NAME_ANABEL
	msgbox SafariZone_West_RestHouse_Text_AnabelPostBattle
	setspeaker SP_NAME_ANABEL
	msgbox SafariZone_West_RestHouse_Text_AnabelBlueOrRed
	dynmultichoice 25, 0, TRUE, 2, 0, DYN_MULTICHOICE_CB_NONE, SafariZone_West_RestHouse_Text_Blue, SafariZone_West_RestHouse_Text_Red
	switch VAR_RESULT
	case 1, SafariZone_West_RestHouse_EventScript_AnabelChoseRed
	goto SafariZone_West_RestHouse_EventScript_AnabelGiveTicket

SafariZone_West_RestHouse_EventScript_AnabelChoseRed::
	setvar VAR_LATIOS_CHOSEN, 1
	goto SafariZone_West_RestHouse_EventScript_AnabelGiveTicket

SafariZone_West_RestHouse_EventScript_AnabelGiveTicket::
	setspeaker SP_NAME_ANABEL
	msgbox SafariZone_West_RestHouse_Text_AnabelHandOver
	giveitem ITEM_EON_TICKET
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
	setspeaker SP_NAME_ANABEL
	msgbox SafariZone_West_RestHouse_Text_AnabelFarewell
	release
	end

SafariZone_West_RestHouse_EventScript_AnabelDone::
	setspeaker SP_NAME_ANABEL
	msgbox SafariZone_West_RestHouse_Text_AnabelPostEvent
	release
	end

SafariZone_West_Text_KogaPatrolsSafariEverySoOften::
    .string "The Safari Zone's huge, wouldn't\n"
    .string "you say?\p"
    .string "Fuchsia's Gym Leader, Koga, \n"
    .string "patrols the grounds every so often.\p"
    .string "Thanks to him, we can play here\n"
    .string "knowing that we're safe.$"

SafariZone_West_Text_BaitMakesMonStickAround::
    .string "Using Bait will make Pokémon more\n"
    .string "likely to stick around if they get\l"
    .string "busy eating.$"

SafariZone_West_Text_HikedLotsDidntSeeMonIWanted::
    .string "I hiked a lot, but I didn't see any\n"
    .string "Pokémon I wanted.$"

SafariZone_West_RestHouse_Text_AnabelIntro1::
    .string "…You noticed me.\p"
    .string "Most people do not.$"

SafariZone_West_RestHouse_Text_AnabelIntro2::
    .string "Greetings.\p"
    .string "My name is Anabel. I am with the\n"
    .string "International Police.\p"
    .string "The Safari Zone draws all manner of\n"
    .string "people. Not all of them come here to\l"
    .string "watch Pokémon.\p"
    .string "Someone must see that these grounds\n"
    .string "stay safe. That is my role here.$"

SafariZone_West_RestHouse_Text_AnabelTicket::
    .string "…I have carried something with me for\n"
    .string "some months now.\p"
    .string "A ticket. A rather valuable one.\p"
    .string "It would be a shame to let it gather\n"
    .string "dust in my pocket…\p"
    .string "So I have been waiting for a trainer\n"
    .string "worthy of it.$"

SafariZone_West_RestHouse_Text_AnabelAskChallenge::
    .string "Let me see your talent in its\n"
    .string "entirety…\p"
    .string "Will you show me?$"

SafariZone_West_RestHouse_Text_AnabelDecline::
    .string "…I see.\p"
    .string "I will be waiting. Until the next\n"
    .string "time we meet…$"

SafariZone_West_RestHouse_Text_AnabelPreBattle::
    .string "Then let us begin, shall we?$"

SafariZone_West_RestHouse_Text_AnabelDefeat::
    .string "Fufufu, nicely done…$"

SafariZone_West_RestHouse_Text_AnabelPostBattle::
    .string "Your talent shall be recognized.\p"
    .string "I have never had a Pokémon battle so\n"
    .string "enjoyable before…\p"
    .string "The ticket is yours. But first,\n"
    .string "humor me.$"

SafariZone_West_RestHouse_Text_AnabelBlueOrRed::
    .string "Tell me… which fancies you more?\p"
    .string "Blue, or red?$"

SafariZone_West_RestHouse_Text_Blue::
    .string "Blue$"

SafariZone_West_RestHouse_Text_Red::
    .string "Red$"

SafariZone_West_RestHouse_Text_AnabelHandOver::
    .string "…I see. That suits you.\p"
    .string "Then take this.$"

SafariZone_West_RestHouse_Text_AnabelFarewell::
    .string "It will carry you to a small island\n"
    .string "far to the south.\p"
    .string "What waits for you there… I will let\n"
    .string "you discover that for yourself.$"

SafariZone_West_RestHouse_Text_AnabelPostEvent::
    .string "The southern island is waiting for\n"
    .string "you…\p"
    .string "Do not keep it waiting too long.\n"
    .string "Fufufu…$"
