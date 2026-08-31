SilphCo_Extra2_Frlg_MapScripts::
	.byte 0

@ Ghost in the Machine quest, the rival executive behind the haunting
SilphCo_Extra2_EventScript_Mde::
	lock
	faceplayer
	goto_if_ge VAR_SILPH_CO_GHOST_QUEST, 4, SilphCo_Extra2_EventScript_MdeAfterBattle
	msgbox SilphCo_Extra2_Text_MdeIntro
	msgbox SilphCo_Extra2_Text_MdeTheDeal, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SilphCo_Extra2_EventScript_MdeDeclined
	msgbox SilphCo_Extra2_Text_MdeAccepted
	closemessage
	trainerbattle_no_intro TRAINER_SILPH_CO_MDE, SilphCo_Extra2_Text_MdeDefeat
	setvar VAR_SILPH_CO_GHOST_QUEST, 4
	msgbox SilphCo_Extra2_Text_MdeDealIsADeal
	goto SilphCo_Extra2_EventScript_MdeGiveMegaStone
	end

@ Var stays at 3 so he can be challenged again
SilphCo_Extra2_EventScript_MdeDeclined::
	msgbox SilphCo_Extra2_Text_MdeDeclined
	release
	end

SilphCo_Extra2_EventScript_MdeGiveMegaStone::
	giveitem ITEM_GARCHOMPITE
	setflag FLAG_GOT_GARCHOMPITE_FROM_MDE
	msgbox SilphCo_Extra2_Text_MdeFiredUp
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_SILPH_CO_EXTRA_MDE
	removeobject LOCALID_SILPH_CO_EXTRA_WORKER_1
	removeobject LOCALID_SILPH_CO_EXTRA_WORKER_2
	removeobject LOCALID_SILPH_CO_EXTRA_WORKER_3
	removeobject LOCALID_SILPH_CO_EXTRA_WORKER_4
	fadescreen FADE_FROM_BLACK
	release
	end

SilphCo_Extra2_EventScript_MdeAfterBattle::
	goto_if_unset FLAG_GOT_GARCHOMPITE_FROM_MDE, SilphCo_Extra2_EventScript_MdeGiveMegaStone
	msgbox SilphCo_Extra2_Text_MdeAfterBattle
	release
	end

SilphCo_Extra2_EventScript_Worker1::
	msgbox SilphCo_Extra2_Text_Worker1, MSGBOX_NPC
	end

SilphCo_Extra2_EventScript_Scientist1::
	msgbox SilphCo_Extra2_Text_Scientist1, MSGBOX_NPC
	end

SilphCo_Extra2_EventScript_Scientist2::
	msgbox SilphCo_Extra2_Text_Scientist2, MSGBOX_NPC
	end

SilphCo_Extra2_EventScript_Worker2::
	msgbox SilphCo_Extra2_Text_Worker2, MSGBOX_NPC
	end

SilphCo_Extra2_Text_Worker1::
    .string "Shoo. I've got work to do.$"

SilphCo_Extra2_Text_Scientist1::
    .string "Busy. Can't you tell?$"

SilphCo_Extra2_Text_Scientist2::
    .string "Don't you have better things to do?\p"
    .string "Because I sure do.$"

SilphCo_Extra2_Text_Worker2::
    .string "The boss wants all of this done\n"
    .string "before his next call.\p"
    .string "So no, I can't chat.$"

SilphCo_Extra2_Text_MdeIntro::
    .string "Hey. New face.\p"
    .string "You here for a meeting, or for a\n"
    .string "job application?\p"
    .string "The old man? He knows exactly how\n"
    .string "this business goes.\p"
    .string "He had the whole Kanto market\n"
    .string "locked up for decades.\p"
    .string "It wouldn't kill him to share a bit.\p"
    .string "Or to step up his game now that\n"
    .string "there's finally a contender.$"

SilphCo_Extra2_Text_MdeTheDeal::
    .string "Look, I've got places to be and\n"
    .string "calls to make.\p"
    .string "But I'm somewhat in the mood for it.\p"
    .string "Beat me in a battle and I'll leave\n"
    .string "the old man alone. Plus something\l"
    .string "worth your time.$"

SilphCo_Extra2_Text_MdeDeclined::
    .string "Sure.\p"
    .string "Now shoo. I have an important call\n"
    .string "to make.$"

SilphCo_Extra2_Text_MdeAccepted::
    .string "Okay. Don't disappoint me.\p"
    .string "Bring me some inspiration for my\n"
    .string "next ideas.$"

SilphCo_Extra2_Text_MdeDefeat::
    .string "What a shame you won't join my\n"
    .string "company.\p"
    .string "You got guts, and you got skill.$"

SilphCo_Extra2_Text_MdeDealIsADeal::
    .string "Welp. A deal is a deal.\p"
    .string "I'll leave the old man alone.\p"
    .string "And since I happen to have two of\n"
    .string "these little guys…\p"
    .string "Why not let one ride along with you?\n"
    .string "It'll most likely help.$"

SilphCo_Extra2_Text_MdeFiredUp::
    .string "Anyway. You got me fired up with\n"
    .string "ideas for my next projects.\p"
    .string "So I have to take my leave.\n"
    .string "Bye!$"

SilphCo_Extra2_Text_MdeAfterBattle::
    .string "Still here? I'm on a call.\p"
    .string "Tell the old man the market's his\n"
    .string "for now. I've got bigger projects.$"

