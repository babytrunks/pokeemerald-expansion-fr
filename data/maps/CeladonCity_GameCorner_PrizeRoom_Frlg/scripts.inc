CeladonCity_GameCorner_PrizeRoom_Frlg_MapScripts::
	.byte 0

@ Body Press, Scorching Sands, X-Scissor, Dragon Pulse, Seed Bombs
CeladonCity_GameCorner_PrizeRoom_EventScript_BaldingMan::
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_FancyThatPorygon, MSGBOX_NPC
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_OldMan::
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_RakedItInToday, MSGBOX_NPC
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_PrizeClerkMons::
	lock
	faceplayer
	showcoinsbox 2, 2
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_WeExchangeCoinsForRarePokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	checkitem ITEM_RED_COIN 1
	goto_if_eq VAR_RESULT, 0, CeladonCity_GameCorner_EventScript_NoRedCoin
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_Use5000CoinsForShiny, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, EventScript_Check5000CoinsForShiny
	hidecoinsbox 2, 2
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ChoosePrizeMon
	end

EventScript_Check5000CoinsForShiny::
	checkcoins 5000
	goto_if_lt VAR_RESULT, VAR_TEMP_2, CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoins
	removecoins 5000
	updatecoinsbox 2, 2
	playfanfare MUS_LEVEL_UP
	waitfanfare
EventScript_ToggleShiny::
	setflag FLAG_FORCE_SHINY
	return

CeladonCity_GameCorner_PrizeRoom_EventScript_ChoosePrizeMon::
	setflag FLAG_RARE_POKEMON_SCREEN
 	setvar VAR_RARE_POKEMON_COUNTER, 4
	setflag FLAG_3_PERFECT_IVS
    factory_generaterentalmons
	factory_rentmons
	waitstate
	clearflag FLAG_RARE_POKEMON_SCREEN
	clearflag FLAG_3_PERFECT_IVS
	clearflag FLAG_FORCE_SHINY
	release
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange::
	hidecoinsbox 2, 2
	release
	end


CeladonCity_GameCorner_PrizeRoom_EventScript_NeedCoinCase::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_CoinCaseRequired
	release
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoins::
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_NeedMoreCoins
	waitbuttonpress
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	end

@ The TM and Mega Stone clerks open the standard buy menu (item list on the
@ right, Coin balance top-left, item name/icon/description on the left) paid for
@ with Coins. Owned prizes show as "Sold Out". See CreateGameCornerPrizeMenu.
CeladonCity_GameCorner_PrizeRoom_EventScript_PrizeClerkTMs::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_COIN_CASE, CeladonCity_GameCorner_PrizeRoom_EventScript_NeedCoinCase
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_WeExchangeCoinsForPrizes
	prizemart CeladonCity_GameCorner_PrizeRoom_TMPrizes
	release
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_PrizeClerkItems::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_COIN_CASE, CeladonCity_GameCorner_PrizeRoom_EventScript_NeedCoinCase
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_WeExchangeCoinsForPrizes
	prizemart CeladonCity_GameCorner_PrizeRoom_MegaStonePrizes
	release
	end

CeladonCity_GameCorner_EventScript_NoRedCoin::
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_DontHaveRedCoin
	hidecoinsbox 2, 2
	release
	end

	.align 2
CeladonCity_GameCorner_PrizeRoom_TMPrizes:
	prize_item ITEM_TM_ICE_BEAM,     1500
	prize_item ITEM_TM_FLASH_CANNON, 1500
	prize_item ITEM_TM_THUNDERBOLT,  1500
	prize_item ITEM_TM_FLAMETHROWER, 1500
	prize_item ITEM_TM_DARK_PULSE,   1500
	prizelistend

	.align 2
CeladonCity_GameCorner_PrizeRoom_MegaStonePrizes:
	prize_item ITEM_VENUSAURITE,    1500
	prize_item ITEM_BLASTOISINITE,  1500
	prize_item ITEM_CHARIZARDITE_X, 1500
	prize_item ITEM_PIDGEOTITE,     1500
	prize_item ITEM_HERACRONITE,    1500
	prize_item ITEM_ABSOLITE,       1500
	prizelistend

CeladonCity_GameCorner_PrizeRoom_Text_FancyThatPorygon::
    .string "You used to be able to buy those\n"
    .string "rare Pokémon with coins!\p"
	.string "But the Pokémon League got sick of\n"
	.string "degenerate gamblers hoarding rare\l"
	.string "Pokémon and scalping them.\p"
	.string "Now, they're a bit more gatekept.\p"
	.string "If you know the right people you can\n"
	.string "easily get a Red Coin, though.$"

CeladonCity_GameCorner_PrizeRoom_Text_RakedItInToday::
    .string "Gahaha! I raked it in today!\n"
    .string "If only every day were like this…$"

CeladonCity_GameCorner_PrizeRoom_Text_CoinCaseRequired::
    .string "A Coin Case is required…$"

CeladonCity_GameCorner_PrizeRoom_Text_WeExchangeCoinsForPrizes::
    .string "We exchange your Coins for prizes.$"

CeladonCity_GameCorner_PrizeRoom_Text_WeExchangeCoinsForRarePokemon::
    .string "We exchange Red Coins for rare\n"
	.string "Pokémon. You can upgrade the rare\l"
	.string "Pokémon to shiny with Coins.\p"
	.string "Interested?$"

CeladonCity_GameCorner_PrizeRoom_Text_Use5000CoinsForShiny::
	.string "Would you like to use 5000 Coins\n"
	.string "to upgrade the rare Pokémon to Shiny?$"

CeladonCity_GameCorner_PrizeRoom_Text_DontHaveRedCoin::
	.string "…You don't have a Red Coin.$"

CeladonCity_GameCorner_PrizeRoom_Text_NeedMoreCoins::
    .string "Sorry, you'll need more Coins\n"
    .string "than that.$"
