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
	checkitem ITEM_TM_ICE_BEAM 
	call_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_PrizeRoom_EventScript_TMIceBeamSetText
	call_if_eq VAR_RESULT, TRUE, CeladonCity_GameCorner_PrizeRoom_EventScript_TMIceBeamSold
	checkitem ITEM_TM_FLASH_CANNON
	call_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_PrizeRoom_EventScript_TMFlashCannonSetText
	call_if_eq VAR_RESULT, TRUE, CeladonCity_GameCorner_PrizeRoom_EventScript_TMFlashCannonSold
	checkitem ITEM_TM_THUNDERBOLT
	call_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_PrizeRoom_EventScript_TMThunderboltSetText
	call_if_eq VAR_RESULT, TRUE, CeladonCity_GameCorner_PrizeRoom_EventScript_TMThunderboltSold
	checkitem ITEM_TM_FLAMETHROWER
	call_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_PrizeRoom_EventScript_TMFlamethrowerSetText
	call_if_eq VAR_RESULT, TRUE, CeladonCity_GameCorner_PrizeRoom_EventScript_TMFlamethrowerSold
	checkitem ITEM_TM_DARK_PULSE
	call_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_PrizeRoom_EventScript_TMDarkPulseSetText
	call_if_eq VAR_RESULT, TRUE, CeladonCity_GameCorner_PrizeRoom_EventScript_TMDarkPulseSold
	dynmultistack 13, 0, FALSE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, CeladonCity_GameCorner_PrizeRoom_EventScript_TM13
	case 1, CeladonCity_GameCorner_PrizeRoom_EventScript_TMFlashCannon
	case 2, CeladonCity_GameCorner_PrizeRoom_EventScript_TM24
	case 3, CeladonCity_GameCorner_PrizeRoom_EventScript_TM35
	case 4, CeladonCity_GameCorner_PrizeRoom_EventScript_TM30
	case 5, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	case 127, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_TMIceBeamSetText:
	dynmultipush CeladonCity_GameCorner_PrizeRoom_Text_TMIceBeam, 0
	return

CeladonCity_GameCorner_PrizeRoom_EventScript_TMIceBeamSold:
	dynmultipush CeladonCity_GameCorner_PrizeRoom_Text_TMIceBeamSold, 0
	return

CeladonCity_GameCorner_PrizeRoom_EventScript_TMFlashCannonSetText:
	dynmultipush CeladonCity_GameCorner_PrizeRoom_Text_TMFlashCannon, 1
	return

CeladonCity_GameCorner_PrizeRoom_EventScript_TMFlashCannonSold:
	dynmultipush CeladonCity_GameCorner_PrizeRoom_Text_TMFlashCannonSold, 1
	return

CeladonCity_GameCorner_PrizeRoom_EventScript_TMThunderboltSetText:
	dynmultipush CeladonCity_GameCorner_PrizeRoom_Text_TMThunderbolt, 2
	return

CeladonCity_GameCorner_PrizeRoom_EventScript_TMThunderboltSold:
	dynmultipush CeladonCity_GameCorner_PrizeRoom_Text_TMThunderboltSold, 2
	return

CeladonCity_GameCorner_PrizeRoom_EventScript_TMFlamethrowerSetText:
	dynmultipush CeladonCity_GameCorner_PrizeRoom_Text_TMFlamethrower, 3
	return

CeladonCity_GameCorner_PrizeRoom_EventScript_TMFlamethrowerSold:
	dynmultipush CeladonCity_GameCorner_PrizeRoom_Text_TMFlamethrowerSold, 3
	return

CeladonCity_GameCorner_PrizeRoom_EventScript_TMDarkPulseSetText:
	dynmultipush CeladonCity_GameCorner_PrizeRoom_Text_TMDarkPulse, 4
	return

CeladonCity_GameCorner_PrizeRoom_EventScript_TMDarkPulseSold:
	dynmultipush CeladonCity_GameCorner_PrizeRoom_Text_TMDarkPulseSold, 4
	return

CeladonCity_GameCorner_PrizeRoom_EventScript_TM13::
	checkitem ITEM_TM_ICE_BEAM
	call_if_eq VAR_RESULT, TRUE, CeladonCity_GameCorner_PrizeRoom_EventScript_AlreadySold
	setvar VAR_TEMP_1, ITEM_TM_ICE_BEAM
	setvar VAR_TEMP_2, 4000
	buffermovename STR_VAR_2, MOVE_ICE_BEAM
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_AlreadySold::
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_AlreadySold
	release
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_TMFlashCannon::
	checkitem ITEM_TM_FLASH_CANNON
	call_if_eq VAR_RESULT, TRUE, CeladonCity_GameCorner_PrizeRoom_EventScript_AlreadySold
	setvar VAR_TEMP_1, ITEM_TM_FLASH_CANNON
	setvar VAR_TEMP_2, 3500
	buffermovename STR_VAR_2, MOVE_FLASH_CANNON
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_TM24::
	checkitem ITEM_TM_THUNDERBOLT
	call_if_eq VAR_RESULT, TRUE, CeladonCity_GameCorner_PrizeRoom_EventScript_AlreadySold
	setvar VAR_TEMP_1, ITEM_TM_THUNDERBOLT
	setvar VAR_TEMP_2, 4000
	buffermovename STR_VAR_2, MOVE_THUNDERBOLT
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_TM30::
	checkitem ITEM_TM_DARK_PULSE
	call_if_eq VAR_RESULT, TRUE, CeladonCity_GameCorner_PrizeRoom_EventScript_AlreadySold
	setvar VAR_TEMP_1, ITEM_TM_DARK_PULSE
	setvar VAR_TEMP_2, 4000
	buffermovename STR_VAR_2, MOVE_DARK_PULSE
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeTM
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_TM35::
	checkitem ITEM_TM_FLAMETHROWER
	call_if_eq VAR_RESULT, TRUE, CeladonCity_GameCorner_PrizeRoom_EventScript_AlreadySold
	setvar VAR_TEMP_1, ITEM_TM_FLAMETHROWER
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
	call CeladonCity_GameCorner_SetCorrespondingMegaItemFlag
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	end

CeladonCity_GameCorner_SetCorrespondingMegaItemFlag:
	call_if_eq VAR_TEMP_1, ITEM_VENUSAURITE, CeladonCity_GameCorner_SetVenusauriteFlag
	call_if_eq VAR_TEMP_1, ITEM_BLASTOISINITE, CeladonCity_GameCorner_SetBlastoisiniteFlag
	call_if_eq VAR_TEMP_1, ITEM_CHARIZARDITE_X, CeladonCity_GameCorner_SetCharizarditeXFlag
	call_if_eq VAR_TEMP_1, ITEM_PIDGEOTITE, CeladonCity_GameCorner_SetPidgeotiteFlag
	call_if_eq VAR_TEMP_1, ITEM_HERACRONITE, CeladonCity_GameCorner_SetHeracroniteFlag
	call_if_eq VAR_TEMP_1, ITEM_ABSOLITE, CeladonCity_GameCorner_SetAbsoliteFlag
	return

CeladonCity_GameCorner_SetVenusauriteFlag:
	setflag FLAG_CELADON_BOUGHT_VENUSAURITE
	return

CeladonCity_GameCorner_SetBlastoisiniteFlag:
	setflag FLAG_CELADON_BOUGHT_BLASTOISINITE
	return

CeladonCity_GameCorner_SetCharizarditeXFlag:
	setflag FLAG_CELADON_BOUGHT_CHARIZARDITE_X
	return

CeladonCity_GameCorner_SetPidgeotiteFlag:
	setflag FLAG_CELADON_BOUGHT_PIDGEOTITE
	return

CeladonCity_GameCorner_SetHeracroniteFlag:
	setflag FLAG_CELADON_BOUGHT_HERACRONITE
	return

CeladonCity_GameCorner_SetAbsoliteFlag:
	setflag FLAG_CELADON_BOUGHT_ABSOLITE
	return

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
	call_if_unset FLAG_CELADON_BOUGHT_VENUSAURITE, CeladonCity_GameCorner_PrizeRoom_EventScript_VenusauriteSetText
	call_if_set FLAG_CELADON_BOUGHT_VENUSAURITE, CeladonCity_GameCorner_PrizeRoom_EventScript_VenusauriteSoldSetText
	call_if_unset FLAG_CELADON_BOUGHT_BLASTOISINITE, CeladonCity_GameCorner_PrizeRoom_EventScript_BlastoisiniteSetText
	call_if_set FLAG_CELADON_BOUGHT_BLASTOISINITE, CeladonCity_GameCorner_PrizeRoom_EventScript_BlastoisiniteSetTextSold
	call_if_unset FLAG_CELADON_BOUGHT_CHARIZARDITE_X, CeladonCity_GameCorner_PrizeRoom_EventScript_CharizarditeXSetText
	call_if_set FLAG_CELADON_BOUGHT_CHARIZARDITE_X, CeladonCity_GameCorner_PrizeRoom_EventScript_CharizarditeXSetTextSold
	call_if_unset FLAG_CELADON_BOUGHT_PIDGEOTITE, CeladonCity_GameCorner_PrizeRoom_EventScript_PidgeotiteSetText
	call_if_set FLAG_CELADON_BOUGHT_PIDGEOTITE, CeladonCity_GameCorner_PrizeRoom_EventScript_PidgeotiteSetTextSold
	call_if_unset FLAG_CELADON_BOUGHT_HERACRONITE, CeladonCity_GameCorner_PrizeRoom_EventScript_HeracroniteSetText
	call_if_set FLAG_CELADON_BOUGHT_HERACRONITE, CeladonCity_GameCorner_PrizeRoom_EventScript_HeracroniteSetTextSold
	call_if_unset FLAG_CELADON_BOUGHT_ABSOLITE, CeladonCity_GameCorner_PrizeRoom_EventScript_AbsoliteSetText
	call_if_set FLAG_CELADON_BOUGHT_ABSOLITE, CeladonCity_GameCorner_PrizeRoom_EventScript_AbsoliteSetTextSold
	dynmultistack 10, 0, FALSE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, CeladonCity_GameCorner_PrizeRoom_EventScript_Venusaurite
	case 1, CeladonCity_GameCorner_PrizeRoom_EventScript_Blastoisinite
	case 2, CeladonCity_GameCorner_PrizeRoom_EventScript_CharizarditeX
	case 3, CeladonCity_GameCorner_PrizeRoom_EventScript_Pidgeotite
	case 4, CeladonCity_GameCorner_PrizeRoom_EventScript_Heracronite
	case 5, CeladonCity_GameCorner_PrizeRoom_EventScript_Absolite
	case 6, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	case 127, CeladonCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_VenusauriteSetText:
	dynmultipush CeladonCity_GameCorner_PrizeRoom_Text_Venusaurite, 0
	return

CeladonCity_GameCorner_PrizeRoom_EventScript_VenusauriteSoldSetText:
	dynmultipush CeladonCity_GameCorner_PrizeRoom_Text_VenusauriteSold, 0
	return

CeladonCity_GameCorner_PrizeRoom_EventScript_BlastoisiniteSetText:
	dynmultipush CeladonCity_GameCorner_PrizeRoom_Text_Blastoisinite, 1
	return

CeladonCity_GameCorner_PrizeRoom_EventScript_BlastoisiniteSetTextSold:
	dynmultipush CeladonCity_GameCorner_PrizeRoom_Text_BlastoisiniteSold, 1
	return

CeladonCity_GameCorner_PrizeRoom_EventScript_CharizarditeXSetText:
	dynmultipush CeladonCity_GameCorner_PrizeRoom_Text_CharizarditeX, 2
	return

CeladonCity_GameCorner_PrizeRoom_EventScript_CharizarditeXSetTextSold:
	dynmultipush CeladonCity_GameCorner_PrizeRoom_Text_CharizarditeXSold, 2
	return

CeladonCity_GameCorner_PrizeRoom_EventScript_PidgeotiteSetText:
	dynmultipush CeladonCity_GameCorner_PrizeRoom_Text_Pidgeotite, 3
	return

CeladonCity_GameCorner_PrizeRoom_EventScript_PidgeotiteSetTextSold:
	dynmultipush CeladonCity_GameCorner_PrizeRoom_Text_PidgeotiteSold, 3
	return

CeladonCity_GameCorner_PrizeRoom_EventScript_HeracroniteSetText:
	dynmultipush CeladonCity_GameCorner_PrizeRoom_Text_Heracronite, 4
	return

CeladonCity_GameCorner_PrizeRoom_EventScript_HeracroniteSetTextSold:
	dynmultipush CeladonCity_GameCorner_PrizeRoom_Text_HeracroniteSold, 4
	return

CeladonCity_GameCorner_PrizeRoom_EventScript_AbsoliteSetText:
	dynmultipush CeladonCity_GameCorner_PrizeRoom_Text_Absolite, 5
	return

CeladonCity_GameCorner_PrizeRoom_EventScript_AbsoliteSetTextSold:
	dynmultipush CeladonCity_GameCorner_PrizeRoom_Text_AbsoliteSold, 5
	return

CeladonCity_GameCorner_PrizeRoom_EventScript_Venusaurite::
	goto_if_set FLAG_CELADON_BOUGHT_VENUSAURITE, CeladonCity_GameCorner_PrizeRoom_EventScript_AlreadySold
	setvar VAR_TEMP_1, ITEM_VENUSAURITE
	setvar VAR_TEMP_2, 3000
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeItem
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_Blastoisinite::
	goto_if_set FLAG_CELADON_BOUGHT_BLASTOISINITE, CeladonCity_GameCorner_PrizeRoom_EventScript_AlreadySold
	setvar VAR_TEMP_1, ITEM_BLASTOISINITE
	setvar VAR_TEMP_2, 3000
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeItem
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_CharizarditeX::
	goto_if_set FLAG_CELADON_BOUGHT_CHARIZARDITE_X, CeladonCity_GameCorner_PrizeRoom_EventScript_AlreadySold
	setvar VAR_TEMP_1, ITEM_CHARIZARDITE_X
	setvar VAR_TEMP_2, 3000
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeItem
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_Pidgeotite::
	goto_if_set FLAG_CELADON_BOUGHT_PIDGEOTITE, CeladonCity_GameCorner_PrizeRoom_EventScript_AlreadySold
	setvar VAR_TEMP_1, ITEM_PIDGEOTITE
	setvar VAR_TEMP_2, 3000
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeItem
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_Heracronite::
	goto_if_set FLAG_CELADON_BOUGHT_HERACRONITE, CeladonCity_GameCorner_PrizeRoom_EventScript_AlreadySold
	setvar VAR_TEMP_1, ITEM_HERACRONITE
	setvar VAR_TEMP_2, 3000
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeItem
	end

CeladonCity_GameCorner_PrizeRoom_EventScript_Absolite::
	goto_if_set FLAG_CELADON_BOUGHT_ABSOLITE, CeladonCity_GameCorner_PrizeRoom_EventScript_AlreadySold
	setvar VAR_TEMP_1, ITEM_ABSOLITE
	setvar VAR_TEMP_2, 3000
	goto CeladonCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeItem
	end

CeladonCity_GameCorner_EventScript_NoRedCoin::
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_DontHaveRedCoin
	hidecoinsbox 2, 2
	release
	end

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

CeladonCity_GameCorner_PrizeRoom_Text_WhichPrize::
    .string "Which prize would you like?$"

CeladonCity_GameCorner_PrizeRoom_Text_YouWantPrize::
    .string "So, you want the {STR_VAR_1}?$"

CeladonCity_GameCorner_PrizeRoom_Text_TMIceBeam::
	.string "{FONT_SMALL_NARROW}TM Ice Beam{CLEAR_TO 0x4A}{FONT_SMALL_NARROWER}4000 Coins$"

CeladonCity_GameCorner_PrizeRoom_Text_TMIceBeamSold::
	.string "{FONT_SMALL_NARROW}TM Ice Beam{CLEAR_TO 0x4A}{FONT_SMALL_NARROWER}{COLOR RED}SOLD$"

CeladonCity_GameCorner_PrizeRoom_Text_TMFlashCannon::
	.string "{FONT_SMALL_NARROW}TM Flash Cannon{CLEAR_TO 0x4A}{FONT_SMALL_NARROWER}3500 Coins$"

CeladonCity_GameCorner_PrizeRoom_Text_TMFlashCannonSold::
	.string "{FONT_SMALL_NARROW}TM Flash Cannon{CLEAR_TO 0x4A}{FONT_SMALL_NARROWER}{COLOR RED}SOLD$"

CeladonCity_GameCorner_PrizeRoom_Text_TMThunderbolt::
	.string "{FONT_SMALL_NARROW}TM Thunderbolt{CLEAR_TO 0x4A}{FONT_SMALL_NARROWER}4000 Coins$"

CeladonCity_GameCorner_PrizeRoom_Text_TMThunderboltSold::
	.string "{FONT_SMALL_NARROW}TM Thunderbolt{CLEAR_TO 0x4A}{FONT_SMALL_NARROWER}{COLOR RED}SOLD$"

CeladonCity_GameCorner_PrizeRoom_Text_TMFlamethrower::
	.string "{FONT_SMALL_NARROW}TM Flamethrower{CLEAR_TO 0x4A}{FONT_SMALL_NARROWER}4000 Coins$"

CeladonCity_GameCorner_PrizeRoom_Text_TMFlamethrowerSold::
	.string "{FONT_SMALL_NARROW}TM Flamethrower{CLEAR_TO 0x4A}{FONT_SMALL_NARROWER}{COLOR RED}SOLD$"

CeladonCity_GameCorner_PrizeRoom_Text_TMDarkPulse::
	.string "{FONT_SMALL_NARROW}TM Dark Pulse{CLEAR_TO 0x4A}{FONT_SMALL_NARROWER}4000 Coins$"

CeladonCity_GameCorner_PrizeRoom_Text_TMDarkPulseSold::
	.string "{FONT_SMALL_NARROW}TM Dark Pulse{CLEAR_TO 0x4A}{FONT_SMALL_NARROWER}{COLOR RED}SOLD$"

CeladonCity_GameCorner_PrizeRoom_Text_Venusaurite::
	.string "Venusaurite{CLEAR_TO 0x4A}{FONT_SMALL_NARROWER}3000 Coins$"

CeladonCity_GameCorner_PrizeRoom_Text_VenusauriteSold::
	.string "Venusaurite{CLEAR_TO 0x4A}{FONT_SMALL_NARROWER}{COLOR RED}SOLD$"

CeladonCity_GameCorner_PrizeRoom_Text_Blastoisinite::
	.string "Blastoisinite{CLEAR_TO 0x4A}{FONT_SMALL_NARROWER}3000 Coins$"

CeladonCity_GameCorner_PrizeRoom_Text_BlastoisiniteSold::
	.string "Blastoisinite{CLEAR_TO 0x4A}{FONT_SMALL_NARROWER}{COLOR RED}SOLD$"

CeladonCity_GameCorner_PrizeRoom_Text_CharizarditeX::
	.string "Charizardite X{CLEAR_TO 0x4A}{FONT_SMALL_NARROWER}3000 Coins$"

CeladonCity_GameCorner_PrizeRoom_Text_CharizarditeXSold::
	.string "Charizardite X{CLEAR_TO 0x4A}{FONT_SMALL_NARROWER}{COLOR RED}SOLD$"

CeladonCity_GameCorner_PrizeRoom_Text_Pidgeotite::
	.string "Pidgeotite{CLEAR_TO 0x4A}{FONT_SMALL_NARROWER}3000 Coins$"

CeladonCity_GameCorner_PrizeRoom_Text_PidgeotiteSold::
	.string "Pidgeotite{CLEAR_TO 0x4A}{FONT_SMALL_NARROWER}{COLOR RED}SOLD$"

CeladonCity_GameCorner_PrizeRoom_Text_Heracronite::
	.string "Heracronite{CLEAR_TO 0x4A}{FONT_SMALL_NARROWER}3000 Coins$"

CeladonCity_GameCorner_PrizeRoom_Text_HeracroniteSold::
	.string "Heracronite{CLEAR_TO 0x4A}{FONT_SMALL_NARROWER}{COLOR RED}SOLD$"

CeladonCity_GameCorner_PrizeRoom_Text_Absolite::
	.string "Absolite{CLEAR_TO 0x4A}{FONT_SMALL_NARROWER}3000 Coins$"

CeladonCity_GameCorner_PrizeRoom_Text_AbsoliteSold::
	.string "Absolite{CLEAR_TO 0x4A}{FONT_SMALL_NARROWER}{COLOR RED}SOLD$"

CeladonCity_GameCorner_PrizeRoom_Text_YouWantTM::
    .string "Okay, a TM of {STR_VAR_2}\n"
    .string "is what you want?$"

CeladonCity_GameCorner_PrizeRoom_Text_NeedMoreCoins::
    .string "Sorry, you'll need more Coins\n"
    .string "than that.$"

CeladonCity_GameCorner_PrizeRoom_Text_AlreadySold::
	.string "…You already have that item.$"
