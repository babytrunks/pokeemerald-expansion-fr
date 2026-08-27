PalletTown_PlayersHouse_2F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_PlayersHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PalletTown_PlayersHouse_2F_OnWarp
	.byte 0

PalletTown_PlayersHouse_2F_OnTransition::
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 0, PalletTown_PlayersHouse_2F_EventScript_SetRespawn
	end

PalletTown_PlayersHouse_2F_EventScript_SetRespawn::
	setrespawn HEAL_LOCATION_PALLET_TOWN
	return

PalletTown_PlayersHouse_2F_OnWarp::
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 0, PalletTown_PlayersHouse_2F_FirstWarpIn
	.2byte 0

PalletTown_PlayersHouse_2F_FirstWarpIn::
	turnobject LOCALID_PLAYER, DIR_NORTH
	setvar VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 1
	end

PalletTown_PlayersHouse_2F_EventScript_NES::
	msgbox PalletTown_Text_AskCode, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PalletTown_EventScript_NESAskCode
	goto_if_eq VAR_RESULT, NO, PalletTown_EventScript_NESDone

PalletTown_EventScript_NESDone:
	release
	end

PalletTown_EventScript_NESAskCode::
	special EnterCode
	waitstate
	special GetCodeFeedback
	goto_if_eq VAR_RESULT, 0, NESCodeFailed
	goto_if_eq VAR_RESULT, 1, NESGiveInfCandy
	goto_if_eq VAR_RESULT, 2, NESActivateDexAll
	goto_if_eq VAR_RESULT, 3, NESActivateEZCatch

NESCodeFailed::
	msgbox PalletTown_Text_NESInvalidCode
	release
	end

NESGiveInfCandy::
	goto_if_set FLAG_NES_GAVE_INFINITE_CANDY, PalletTown_EventScript_NES_AlreadyGaveCode
	msgbox PalletTown_Text_NESInfCandyCode
	giveitem ITEM_INFINITE_CANDY
	setflag FLAG_NES_GAVE_INFINITE_CANDY
	release
	end

NESActivateDexAll::
	goto_if_set FLAG_NES_ACTIVATE_DEX_ALL, PalletTown_EventScript_NES_AlreadyGaveCode
	msgbox PalletTown_Text_NESDexAllActivate
	setflag FLAG_NES_ACTIVATE_DEX_ALL
	release
	end


NESActivateEZCatch::
	goto_if_set FLAG_NES_EZCATCH, PalletTown_EventScript_NES_AlreadyGaveCode
	msgbox PalletTown_Text_NESEZCatchActivate
	setflag FLAG_NES_EZCATCH
	release
	end

PalletTown_EventScript_NES_AlreadyGaveCode::
	msgbox PalletTown_Text_NES_AlreadyGave
	release
	end

PalletTown_PlayersHouse_2F_EventScript_Sign::
	msgbox PalletTown_PlayersHouse_2F_Text_PressLRForHelp, MSGBOX_SIGN
	end

PalletTown_PlayersHouse_2F_EventScript_CheatBook::
	lockall
	msgbox PalletTown_PlayersHouse_2F_Text_CheatBookAskRead, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PalletTown_PlayersHouse_2F_EventScript_CheatBookRead
	goto PalletTown_PlayersHouse_2F_EventScript_CheatBookDone

PalletTown_PlayersHouse_2F_EventScript_CheatBookRead::
	msgbox PalletTown_PlayersHouse_2F_Text_CheatBookContents, MSGBOX_DEFAULT
	goto PalletTown_PlayersHouse_2F_EventScript_CheatBookDone

PalletTown_PlayersHouse_2F_EventScript_CheatBookDone::
	closemessage
	releaseall
	end

PalletTown_Text_AskCode::
	.string "Would you like to input a code?$"

PalletTown_Text_NES_AlreadyGave::
	.string "…You already input that code.$"

PalletTown_Text_NESInvalidCode::
	.string "Invalid code.$"

PalletTown_Text_NESDexAllActivate::
	.string "…DexAll code activated.$"

PalletTown_Text_NESInfCandyCode::
	.string "…Infinite Candy code received.$"

PalletTown_Text_NESEZCatchActivate::
	.string "…EZCatch activated.\nAll Pokéballs now catch without fail.$"

PalletTown_PlayersHouse_2F_Text_PlayedWithNES::
    .string "{PLAYER} played with the NES.\p"
    .string "…Okay!\n"
    .string "It's time to go!$"

PalletTown_PlayersHouse_2F_Text_PressLRForHelp::
    .string "It's a posted notice…\p"
    .string "Check out the Options Menu in the\n"
    .string "{START_BUTTON} Menu!\p"
	.string "Don't forget to pres$"

PalletTown_PlayersHouse_2F_Text_CheatBookAskRead::
	.string "A worn paperback sits on the shelf…\p"
	.string "Title: Cheat Codes For Dummies…\p"
	.string "Read it?$"

PalletTown_PlayersHouse_2F_Text_CheatBookContents::
	.string "Chapter 1: So You Bought An NES\p"
	.string "Punch a secret word into the NES\n"
	.string "and the world plays along!\p"
	.string "Spelling counts, dummy.\p"
	.string "Chapter 2: The Sweet Tooth\p"
	.string "“Woyaopp” buys candy that never, EVER\n"
	.string "runs out.\p"
	.string "Chapter 3: The Know-It-All\p"
	.string "“DexAll” is said to fill a Pokédex\n"
	.string "with things you have yet to meet.\p"
	.string "Makes DexNav hunting a breeze.\p"
	.string "Chapter 4: The Lazy Catch\p"
	.string "“EZCatch” makes every Ball stick.\n"
	.string "No wiggling. No heartbreak.\p"
	.string "The last page is torn out…\p"
	.string "Something's scribbled in the margin:\n"
	.string "“Hide from Mom! And Soup!!!”$"

