.equ HELIX_FOSSIL, 1
.equ DOME_FOSSIL,  2
.equ OLD_AMBER,    3

CinnabarIsland_PokemonLab_ExperimentRoom_Frlg_MapScripts::
	.byte 0

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_Garett::
	lock
	faceplayer
	setvar VAR_0x8008, INGAME_TRADE_SEEL
	call EventScript_GetInGameTradeSpeciesInfo
	goto_if_set FLAG_DID_SEELOR_TRADE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_AlreadyTraded
	msgbox Trade_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineTrade
	call EventScript_ChooseMonForInGameTrade
	goto_if_ge VAR_0x8004, PARTY_SIZE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineTrade
	call EventScript_GetInGameTradeSpecies
	goto_if_ne VAR_RESULT, VAR_0x8009, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NotRequestedMon
	call EventScript_DoInGameTrade
	msgbox Trade_Text_HeyThanks
	setflag FLAG_DID_SEELOR_TRADE
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineTrade::
	msgbox Trade_Text_AwwOhWell
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox Trade_Text_WhatThatsNoMon
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_AlreadyTraded::
	msgbox Trade_Text_IsntMyOldMonGreat
	release
	end


Text_MetronomeTeach::
    .string "Tch-tch-tch!\n"
    .string "I'll teach you a nifty move.\p"
    .string "Teach it to a Pokémon, and watch\n"
    .string "the fun unfold!\p"
    .string "It's a move called METRONOME.\n"
    .string "Does it strike your fancy?$"

Text_MetronomeDeclined::
    .string "I tell you, it's a lot of fun!$"

Text_MetronomeWhichMon::
    .string "Okay!\n"
    .string "Which Pokémon should I teach?$"

Text_MetronomeTaught::
    .string "Tch-tch-tch!\n"
    .string "That's the sound of a METRONOME.\p"
    .string "It tweaks your Pokémon's brain into\n"
    .string "using moves it doesn't even know.$"
