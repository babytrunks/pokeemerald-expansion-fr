ViridianCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

ViridianCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_VIRIDIAN_CITY
	end

ViridianCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_VIRIDIAN_NURSE
	call Common_EventScript_PkmnCenterNurse
	release
	end

ViridianCity_PokemonCenter_1F_EventScript_Boy::
	msgbox ViridianCity_PokemonCenter_1F_Text_PokeCenterInEveryTown, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox ViridianCity_PokemonCenter_1F_Text_FeelFreeToUsePC, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox ViridianCity_PokemonCenter_1F_Text_PokeCentersHealMons, MSGBOX_NPC
	end

EventScript_GachaMachineViridian::
EventScript_Gacha::
	lockall
	callnative Buffer1GachaVouchers
	msgbox GatchaMachine_Text_WhichMachine
	dynmultichoice 25, 0, 0, 6, 0, DYN_MULTICHOICE_CB_NONE, GachaMachine_Text_Common, GachaMachine_Text_Uncommon, GachaMachine_Text_Pseudos, GachaMachine_Text_UltraRare
	switch VAR_RESULT
	case MULTI_B_PRESSED, EventScript_Gatcha_releasEnd
	case 0, EventScript_Gacha_Common
	case 1, EventScript_Gacha_Uncommon
	case 2, EventScript_Gacha_Rare
	case 3, EventScript_Gacha_UltraRare
	releaseall
	end

EventScript_Gacha_Common::
	checkitem ITEM_GACHA_VOUCHER
	goto_if_eq VAR_RESULT, FALSE, EventScript_NoGatchaVoucher
	setvar VAR_0x8004, 1 @This sets to common
	call EventScript_GachaCommon
	releaseall
	end

EventScript_Gacha_Uncommon::
	checkitem ITEM_GACHA_VOUCHER 2
	goto_if_eq VAR_RESULT, FALSE, EventScript_NoGatcha2Voucher
	setvar VAR_0x8004, 2 @This sets to uncommon
	call EventScript_GachaCommon
	releaseall
	end

EventScript_Gacha_Rare::
	checkitem ITEM_GACHA_VOUCHER 5
	goto_if_eq VAR_RESULT, FALSE, EventScript_NoGatcha5Voucher
	setvar VAR_0x8004, 3 @This sets to Rares
	call EventScript_GachaCommon
	releaseall
	end

EventScript_Gacha_UltraRare::
	checkitem ITEM_GACHA_VOUCHER 10
	goto_if_eq VAR_RESULT, FALSE, EventScript_NoGatcha10Voucher
	setvar VAR_0x8004, 4 @This sets to Ultra Rare
	call EventScript_GachaCommon
	releaseall
	end

EventScript_GachaCommon::
	setflag FLAG_3_PERFECT_IVS
	playbgm MUS_RG_CINNABAR, FALSE
	special StartGacha
	waitstate
	clearflag FLAG_3_PERFECT_IVS
	savebgm MUS_DUMMY
	fadedefaultbgm
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, EventScript_RecieveGachaMonParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, EventScript_RecieveGachaMonPC
EventScript_GachaEnd::
	return

EventScript_RecieveGachaMonParty::
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_GachaEnd
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto EventScript_GachaEnd

EventScript_RecieveGachaMonPC::
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_TransferGachaMonToPC
	call Common_EventScript_NameReceivedBoxMon
EventScript_TransferGachaMonToPC::
	call Common_EventScript_TransferredToPC
	goto EventScript_GachaEnd

EventScript_NoGatchaVoucher::
	msgbox GatchaMachine_Text_CantBuyWithNoVoucher, MSGBOX_DEFAULT
	goto EventScript_Gatcha_releasEnd

EventScript_NoGatcha2Voucher::
	msgbox GatchaMachine_Text_CantBuyWithNo2Voucher, MSGBOX_DEFAULT
	goto EventScript_Gatcha_releasEnd

EventScript_NoGatcha5Voucher::
	msgbox GatchaMachine_Text_CantBuyWithNo5Voucher, MSGBOX_DEFAULT
	goto EventScript_Gatcha_releasEnd

EventScript_NoGatcha10Voucher::
	msgbox GatchaMachine_Text_CantBuyWithNo10Voucher, MSGBOX_DEFAULT
	goto EventScript_Gatcha_releasEnd

EventScript_Gatcha_releasEnd:
	releaseall
	end

ViridianCity_PokemonCenter_1F_Text_FeelFreeToUsePC::
    .string "Please feel free to use that PC in\n"
    .string "the corner.\p"
    .string "The receptionist told me so.\n"
    .string "It's so kind of her!$"

ViridianCity_PokemonCenter_1F_Text_PokeCenterInEveryTown::
    .string "There's a Pokémon Center in every\n"
    .string "town ahead.\p"
    .string "They charge no money, so don't\n"
    .string "be shy about healing Pokémon.$"

ViridianCity_PokemonCenter_1F_Text_PokeCentersHealMons::
    .string "Pokémon Centers heal your tired,\n"
    .string "hurt, or fainted Pokémon.\p"
    .string "They make all Pokémon completely\n"
    .string "healthy.$"

GatchaMachine_Text_CantBuyWithNoVoucher::
	.string "You need a Gatcha Voucher to play.$"

GachaMachine_Text_Common::
	.string "Common$"

GachaMachine_Text_Uncommon::
	.string "Uncommon$"

GachaMachine_Text_Pseudos::
	.string "Rare$"

GachaMachine_Text_UltraRare::
	.string "Ultra Rare$"

GatchaMachine_Text_CantBuyWithNo2Voucher::
	.string "You need 2 Gatcha Vouchers to play.$"

GatchaMachine_Text_CantBuyWithNo5Voucher::
	.string "You need 5 Gatcha Vouchers to play.$"

GatchaMachine_Text_CantBuyWithNo10Voucher::
	.string "You need 10 Gatcha Vouchers to play.$"

GatchaMachine_Text_WhichMachine:
	.string "Which machine would you like to play?\n"
	.string "You have {STR_VAR_1} vouchers.$"
