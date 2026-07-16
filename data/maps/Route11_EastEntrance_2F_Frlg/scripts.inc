.equ REQUIRED_CAUGHT_MONS, 30

Route11_EastEntrance_2F_Frlg_MapScripts::
	.byte 0

Route11_EastEntrance_2F_EventScript_LeftBinoculars::
	lockall
	goto_if_set FLAG_WOKE_UP_ROUTE_12_SNORLAX, Route11_EastEntrance_2F_EventScript_LeftBinocularsSnorlaxGone
	msgbox Route11_EastEntrance_2F_Text_BigMonAsleepOnRoad
	releaseall
	end

Route11_EastEntrance_2F_EventScript_LeftBinocularsSnorlaxGone::
	msgbox Route11_EastEntrance_2F_Text_WhatABreathtakingView
	releaseall
	end

Route11_EastEntrance_2F_EventScript_RightBinoculars::
	msgbox Route11_EastEntrance_2F_Text_RockTunnelGoodRouteToLavender, MSGBOX_SIGN
	end

Route11_EastEntrance_2F_EventScript_Turner::
	lock
	faceplayer
	setvar VAR_0x8008, INGAME_TRADE_FLOETTE_ETERNAL
	call EventScript_GetInGameTradeSpeciesInfo
	goto_if_set FLAG_DID_NINA_TRADE, Route11_EastEntrance_2F_EventScript_AlreadyTraded
	msgbox Trade_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route11_EastEntrance_2F_EventScript_DeclineTrade
	call EventScript_ChooseMonForInGameTrade
	goto_if_ge VAR_0x8004, PARTY_SIZE, Route11_EastEntrance_2F_EventScript_DeclineTrade
	call EventScript_GetInGameTradeSpecies
	goto_if_ne VAR_RESULT, VAR_0x8009, Route11_EastEntrance_2F_EventScript_NotRequestedMon
	call EventScript_DoInGameTrade
	msgbox Trade_Text_HeyThanks
	setflag FLAG_DID_NINA_TRADE
	release
	end

Route11_EastEntrance_2F_EventScript_DeclineTrade::
	msgbox Trade_Text_AwwOhWell
	release
	end

Route11_EastEntrance_2F_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox Trade_Text_WhatThatsNoMon
	release
	end

Route11_EastEntrance_2F_EventScript_AlreadyTraded::
	msgbox Trade_Text_IsntMyOldMonGreat
	release
	end

Route11_EastEntrance_2F_EventScript_Aide::
	lock
	faceplayer
	call Route11_EastEntrance_2F_EventScript_GetAideRequestInfo
	goto_if_set FLAG_GOT_ITEMFINDER, Route11_EastEntrance_2F_EventScript_AlreadyGotItemfinder
	msgbox Route11_EastEntrance_2F_Text_GiveItemfinderIfCaught30, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Aide_EventScript_DeclineCheckMons
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, GetFrlgPokedexCount
	buffernumberstring STR_VAR_3, VAR_0x8006
	call Route11_EastEntrance_2F_EventScript_GetAideRequestInfo
	goto_if_lt VAR_0x8006, REQUIRED_CAUGHT_MONS, Aide_EventScript_HaventCaughtEnough
	msgbox Route11_EastEntrance_2F_Text_GreatHereYouGo
	giveitem_msg Route11_EastEntrance_2F_Text_ReceivedItemfinderFromAide, ITEM_EVERSTONE
	setflag FLAG_GOT_ITEMFINDER
	msgbox Route11_EastEntrance_2F_Text_ExplainEverstone
	release
	end

Route11_EastEntrance_2F_EventScript_AlreadyGotItemfinder::
	msgbox Route11_EastEntrance_2F_Text_ExplainEverstone
	release
	end

Route11_EastEntrance_2F_EventScript_GetAideRequestInfo::
	buffernumberstring STR_VAR_1, REQUIRED_CAUGHT_MONS
	bufferitemname STR_VAR_2, ITEM_EVERSTONE
	return

Route11_EastEntrance_2F_Text_GiveItemfinderIfCaught30::
    .string "Oh… {PLAYER}!\n"
    .string "I've been looking for you!\p"
    .string "It's me, one of the ever-present\n"
    .string "Aides to Prof. Oak.\p"
    .string "If your Pokédex has complete data\n"
    .string "on twenty species, I'm supposed to\l"
    .string "give you a reward from Prof. Oak.\p"
    .string "He entrusted me with this\n"
    .string "Everstone.\p"
    .string "So, {PLAYER}, let me ask you.\p"
    .string "Have you gathered data on at least\n"
    .string "twenty kinds of Pokémon?$"

Route11_EastEntrance_2F_Text_GreatHereYouGo::
    .string "Great! You have caught or owned\n"
    .string "{STR_VAR_3} kinds of Pokémon!\p"
    .string "Congratulations!\n"
    .string "Here you go!$"

Route11_EastEntrance_2F_Text_ReceivedItemfinderFromAide::
    .string "{PLAYER} received the {STR_VAR_2}\n"
    .string "from the Aide.$"

Route11_EastEntrance_2F_Text_ExplainEverstone::
    .string "Making Pokémon evolve certainly\n"
    .string "can add to the Pokédex.\p"
    .string "However, at times, you may not\n"
    .string "want a certain Pokémon to evolve.\p"
    .string "In that case, give the Everstone\n"
    .string "to that Pokémon.\p"
    .string "It will prevent evolution according\n"
    .string "to the Professor.$"

Route11_EastEntrance_2F_Text_BigMonAsleepOnRoad::
    .string "Let's see what the binoculars have\n"
    .string "to show…\p"
    .string "A big Pokémon is asleep on a road!$"

Route11_EastEntrance_2F_Text_WhatABreathtakingView::
    .string "Let's see what the binoculars have\n"
    .string "to show…\p"
    .string "What a breathtaking view!$"

Route11_EastEntrance_2F_Text_RockTunnelGoodRouteToLavender::
    .string "Let's see what the binoculars have\n"
    .string "to show…\p"
    .string "To get to Lavender Town from\n"
    .string "Cerulean City…\p"
    .string "Rock Tunnel appears to be a good\n"
    .string "route to take.$"

