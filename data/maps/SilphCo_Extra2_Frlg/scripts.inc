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

@ A full Bag leaves the flag clear so he hands the stone over on the next talk
SilphCo_Extra2_EventScript_MdeGiveMegaStone::
	giveitem ITEM_GARCHOMPITE
	setflag FLAG_GOT_GARCHOMPITE_FROM_MDE
	msgbox SilphCo_Extra2_Text_MdeFiredUp
	release
	end

SilphCo_Extra2_EventScript_MdeNoRoom::
	msgbox SilphCo_Extra2_Text_MdeNoRoom
	release
	end

SilphCo_Extra2_EventScript_MdeAfterBattle::
	goto_if_unset FLAG_GOT_GARCHOMPITE_FROM_MDE, SilphCo_Extra2_EventScript_MdeGiveMegaStone
	msgbox SilphCo_Extra2_Text_MdeAfterBattle
	release
	end
