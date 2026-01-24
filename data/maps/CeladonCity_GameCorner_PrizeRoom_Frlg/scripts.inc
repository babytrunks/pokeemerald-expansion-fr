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
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_PrizeClerkTMs::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_COIN_CASE, CeladonCity_GameCorner_PrizeRoom_EventScript_NeedCoinCase
	showcoinsbox 2, 2
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_WeExchangeCoinsForPrizes
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ChoosePrizeTM
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_ChoosePrizeTM::
	message CeladonCity_GameCorner_PrizeRoom_Text_WhichPrize
	waitmessage
	multichoice 11, 0, MULTI_GAME_CORNER_TMPRIZES, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_GameCorner_PrizeRoom_EventScript_TM13
	case 1, CeladonCity_GameCorner_PrizeRoom_EventScript_TM23
	case 2, CeladonCity_GameCorner_PrizeRoom_EventScript_TM24
	case 3, CeladonCity_GameCorner_PrizeRoom_EventScript_TM30
	case 4, CeladonCity_GameCorner_PrizeRoom_EventScript_TM35
	case 5, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	case 127, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_TM13::
	setvar VAR_TEMP_1, ITEM_TM13
	setvar VAR_TEMP_2, 4000
	buffermovename STR_VAR_2, MOVE_ICE_BEAM
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_TM23::
	setvar VAR_TEMP_1, ITEM_TM23
	setvar VAR_TEMP_2, 3500
	buffermovename STR_VAR_2, MOVE_IRON_TAIL
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_TM24::
	setvar VAR_TEMP_1, ITEM_TM24
	setvar VAR_TEMP_2, 4000
	buffermovename STR_VAR_2, MOVE_THUNDERBOLT
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_TM30::
	setvar VAR_TEMP_1, ITEM_TM30
	setvar VAR_TEMP_2, 4500
	buffermovename STR_VAR_2, MOVE_SHADOW_BALL
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_TM35::
	setvar VAR_TEMP_1, ITEM_TM35
	setvar VAR_TEMP_2, 4000
	buffermovename STR_VAR_2, MOVE_FLAMETHROWER
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM::
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_YouWantTM, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_TryGivePrize
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeItem::
	bufferitemname STR_VAR_1, VAR_TEMP_1
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_YouWantPrize, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_TryGivePrize
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_TryGivePrize::
	bufferitemname STR_VAR_1, VAR_TEMP_1
	checkcoins VAR_RESULT
	goto_if_lt VAR_RESULT, VAR_TEMP_2, CeladonCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoins
	checkitemspace VAR_TEMP_1
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_PrizeRoom_EventScript_BagFull
	removecoins VAR_TEMP_2
	updatecoinsbox 0, 5
	giveitem VAR_TEMP_1
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_BagFull::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox gText_TooBadBagIsFull
	hidecoinsbox 2, 2
	release
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_PrizeClerkItems::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_COIN_CASE, CeladonCity_GameCorner_PrizeRoom_EventScript_NeedCoinCase
	showcoinsbox 2, 2
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_WeExchangeCoinsForPrizes
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ChoosePrizeItem
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_ChoosePrizeItem::
	message CeladonCity_GameCorner_PrizeRoom_Text_WhichPrize
	waitmessage
	multichoice 10, 0, MULTI_GAME_CORNER_BATTLE_ITEM_PRIZES, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_GameCorner_PrizeRoom_EventScript_SmokeBall
	case 1, CeladonCity_GameCorner_PrizeRoom_EventScript_MiracleSeed
	case 2, CeladonCity_GameCorner_PrizeRoom_EventScript_Charcoal
	case 3, CeladonCity_GameCorner_PrizeRoom_EventScript_MysticWater
	case 4, CeladonCity_GameCorner_PrizeRoom_EventScript_YellowFlute
	case 5, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	case 127, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_SmokeBall::
	setvar VAR_TEMP_1, ITEM_SMOKE_BALL
	setvar VAR_TEMP_2, 800
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeItem
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_MiracleSeed::
	setvar VAR_TEMP_1, ITEM_MIRACLE_SEED
	setvar VAR_TEMP_2, 1000
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeItem
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_Charcoal::
	setvar VAR_TEMP_1, ITEM_CHARCOAL
	setvar VAR_TEMP_2, 1000
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeItem
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_MysticWater::
	setvar VAR_TEMP_1, ITEM_MYSTIC_WATER
	setvar VAR_TEMP_2, 1000
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeItem
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_YellowFlute::
	setvar VAR_TEMP_1, ITEM_YELLOW_FLUTE
	setvar VAR_TEMP_2, 1600
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeItem
	end

CeladonCity_GameCorner_EventScript_NoRedCoin::
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_DontHaveRedCoin
	hidecoinsbox 2, 2
	release
	end

CeladonCity_GameCorner_PrizeRoom_Text_FancyThatPorygon::
    .string "I sure do fancy that PORYGON!\n"
    .string "But, it's hard to win at slots!$"

CeladonCity_GameCorner_PrizeRoom_Text_RakedItInToday::
    .string "Gahaha! I raked it in today!\n"
    .string "If only every day were like this…$"

CeladonCity_GameCorner_PrizeRoom_Text_CoinCaseRequired::
    .string "A COIN CASE is required…$"

CeladonCity_GameCorner_PrizeRoom_Text_WeExchangeCoinsForPrizes::
    .string "We exchange your COINS for prizes.$"

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

CeladonCity_GameCorner_PrizeRoom_Text_WhichPrize::
    .string "Which prize would you like?$"

CeladonCity_GameCorner_PrizeRoom_Text_HereYouGo::
    .string "はい どうぞ$"

CeladonCity_GameCorner_PrizeRoom_Text_YouWantPrize::
    .string "So, you want the {STR_VAR_1}?$"

CeladonCity_GameCorner_PrizeRoom_Text_TM13::
	.string "TM13: Ice Beam$"

CeladonCity_GameCorner_PrizeRoom_Text_YouWantTM::
    .string "Okay, a TM of {STR_VAR_2}\n"
    .string "is what you want?$"

CeladonCity_GameCorner_PrizeRoom_Text_NeedMoreCoins::
    .string "Sorry, you'll need more COINS\n"
    .string "than that.$"

CeladonCity_GameCorner_PrizeRoom_Text_OopsNotEnoughRoom::
    .string "おきゃくさん もう もてないよ$"

CeladonCity_GameCorner_PrizeRoom_Text_OhFineThen::
    .string "あっ そう$"

