.equ MAGIKARP_PRICE, 500

Route4_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

Route4_PokemonCenter_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ROUTE4_POKEMON_CENTER_1F
	setrespawn HEAL_LOCATION_ROUTE4
	end

Route4_PokemonCenter_1F_EventScript_Boy::
	msgbox Route4_PokemonCenter_1F_Text_CanHaveSixMonsWithYou, MSGBOX_NPC
	end

Route4_PokemonCenter_1F_EventScript_Gentleman::
	lock
	msgbox Route4_PokemonCenter_1F_Text_TeamRocketAttacksCerulean
	release
	end

Route4_PokemonCenter_1F_EventScript_MagikarpSalesman::
	lock
	faceplayer
	goto_if_set FLAG_BOUGHT_JOHTO_EGG, Route4_PokemonCenter_1F_EventScript_AlreadyBoughtMagikarp
	showmoneybox 0, 0
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route4_PokemonCenter_1F_EventScript_AskBuyMagikarpMale
	goto_if_eq VAR_RESULT, FEMALE, Route4_PokemonCenter_1F_EventScript_AskBuyMagikarpFemale
	end

Route4_PokemonCenter_1F_EventScript_AskBuyMagikarpMale::
	msgbox Route4_PokemonCenter_1F_Text_LaddieBuyMagikarpForJust500, MSGBOX_YESNO
	goto Route4_PokemonCenter_1F_EventScript_TryBuyMagikarp
	end

Route4_PokemonCenter_1F_EventScript_AskBuyMagikarpFemale::
	msgbox Route4_PokemonCenter_1F_Text_SweetieBuyMagikarpForJust500, MSGBOX_YESNO
	goto Route4_PokemonCenter_1F_EventScript_TryBuyMagikarp
	end

Route4_PokemonCenter_1F_EventScript_TryBuyMagikarp::
	goto_if_eq VAR_RESULT, NO, Route4_PokemonCenter_1F_EventScript_DeclineMagikarp
	checkmoney MAGIKARP_PRICE
	goto_if_eq VAR_RESULT, FALSE, Route4_PokemonCenter_1F_EventScript_NotEnoughMoney
	textcolor NPC_TEXT_COLOR_NEUTRAL
	setvar VAR_TEMP_1, SPECIES_MAGIKARP
	givemon SPECIES_MAGIKARP, 5
	goto_if_eq VAR_RESULT, 0, Route4_PokemonCenter_1F_EventScript_BuyMagikarpParty
	goto_if_eq VAR_RESULT, 1, Route4_PokemonCenter_1F_EventScript_BuyMagikarpPC
	goto_if_eq VAR_RESULT, 2, Route4_PokemonCenter_1F_EventScript_NoRoomForMagikarp
	end

Route4_PokemonCenter_1F_EventScript_BuyMagikarpParty::
	call Route4_PokemonCenter_1F_EventScript_PayForMagikarp
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route4_PokemonCenter_1F_EventScript_EndPurchaseMagikarp
	call Common_EventScript_GetGiftMonPartySlot
	fadescreen FADE_TO_BLACK
	hidemoneybox
	special ChangePokemonNickname
	waitstate
	goto Route4_PokemonCenter_1F_EventScript_BoughtMagikarp
	end

Route4_PokemonCenter_1F_EventScript_BuyMagikarpPC::
	call Route4_PokemonCenter_1F_EventScript_PayForMagikarp
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route4_PokemonCenter_1F_EventScript_TransferMagikarpCloseMoneyBox
	fadescreen FADE_TO_BLACK
	hidemoneybox
	special ChangeBoxPokemonNickname
	waitstate
	lock
	faceplayer
	goto Route4_PokemonCenter_1F_EventScript_TransferMagikarp
	end

Route4_PokemonCenter_1F_EventScript_TransferMagikarpCloseMoneyBox::
	call Common_EventScript_TransferredToPC
	goto Route4_PokemonCenter_1F_EventScript_EndPurchaseMagikarp
	end

Route4_PokemonCenter_1F_EventScript_TransferMagikarp::
	call Common_EventScript_TransferredToPC
	goto Route4_PokemonCenter_1F_EventScript_BoughtMagikarp
	end

Route4_PokemonCenter_1F_EventScript_EndPurchaseMagikarp::
	hidemoneybox
	goto Route4_PokemonCenter_1F_EventScript_BoughtMagikarp
	end

Route4_PokemonCenter_1F_EventScript_BoughtMagikarp::
	setflag FLAG_BOUGHT_JOHTO_EGG
	release
	end

Route4_PokemonCenter_1F_EventScript_PayForMagikarp::
	removemoney MAGIKARP_PRICE
	updatemoneybox
	playfanfare MUS_LEVEL_UP
	message Route4_PokemonCenter_1F_Text_PaidOutrageouslyForMagikarp
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_MAGIKARP
	return

Route4_PokemonCenter_1F_EventScript_DeclineMagikarp::
	msgbox Route4_PokemonCenter_1F_Text_OnlyDoingThisAsFavorToYou
	hidemoneybox
	release
	end

Route4_PokemonCenter_1F_EventScript_NotEnoughMoney::
	msgbox Route4_PokemonCenter_1F_Text_YoullNeedMoreMoney
	hidemoneybox
	release
	end

Route4_PokemonCenter_1F_EventScript_AlreadyBoughtMagikarp::
	msgbox Route4_PokemonCenter_1F_Text_IDontGiveRefunds
	release
	end

Route4_PokemonCenter_1F_EventScript_NoRoomForMagikarp::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox Route4_PokemonCenter_1F_Text_NoRoomForMorePokemon
	hidemoneybox
	release
	end

Route4_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call Common_EventScript_PkmnCenterNurse
	release
	end

Route4_PokemonCenter_1F_EventScript_Youngster::
	msgbox Route4_PokemonCenter_1F_Text_ShouldStoreMonsUsingPC, MSGBOX_NPC
	end

Route4_PokemonCenter_1F_EventScript_Newspaper::
	lock
	msgbox Route4_PokemonCenter_1F_Text_ItsANewspaper
	release
	end


Route4_PokemonCenter_1F_EventScript_EggSalesman::
	lock
	faceplayer
	goto_if_set FLAG_BOUGHT_JOHTO_EGG, Route4_PokemonCenter_1F_EventScript_AlreadyBoughtJohtoEgg
	showmoneybox 0, 0
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route4_PokemonCenter_1F_EventScript_AskBuyEggMale
	goto_if_eq VAR_RESULT, FEMALE, Route4_PokemonCenter_1F_EventScript_AskBuyEggFemale
	end

Route4_PokemonCenter_1F_EventScript_AskBuyEggMale::
	msgbox Route4_PokemonCenter_1F_Text_SportBuyJohtoEgg, MSGBOX_YESNO
	goto Route4_PokemonCenter_1F_EventScript_TryBuyJohtoEgg
	end

Route4_PokemonCenter_1F_EventScript_AskBuyEggFemale::
	msgbox Route4_PokemonCenter_1F_Text_SweetieBuyJohtoEgg, MSGBOX_YESNO
	goto Route4_PokemonCenter_1F_EventScript_TryBuyJohtoEgg
	end

Route4_PokemonCenter_1F_EventScript_TryBuyJohtoEgg::
	goto_if_eq VAR_RESULT, NO, Route4_PokemonCenter_1F_EventScript_DeclineJohtoEgg
	checkmoney MAGIKARP_PRICE
	goto_if_eq VAR_RESULT, FALSE, Route4_PokemonCenter_1F_EventScript_NotEnoughMoneyJohtoEgg
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, Route4_PokemonCenter_1F_EventScript_NoRoomForJohtoEgg
	randomelement SPECIES_CLEFFA, SPECIES_IGGLYBUFF, SPECIES_TOGEPI, SPECIES_TYROGUE, SPECIES_SMOOCHUM, SPECIES_ELEKID, SPECIES_MAGBY, SPECIES_AZURILL, SPECIES_WYNAUT, SPECIES_RIOLU, SPECIES_TOXEL, SPECIES_MANTYKE, SPECIES_MUNCHLAX, SPECIES_HAPPINY, SPECIES_MIME_JR, SPECIES_BONSLY, SPECIES_CHINGLING, SPECIES_BUDEW, SPECIES_MAGIKARP
	copyvar VAR_TEMP_1, VAR_RESULT
	setflag FLAG_FORCE_SHINY
	setflag FLAG_3_PERFECT_IVS
	giveegg VAR_TEMP_1
	clearflag FLAG_FORCE_SHINY
	clearflag FLAG_3_PERFECT_IVS
	call Route4_PokemonCenter_1F_EventScript_PayForJohtoEgg
	hidemoneybox
	setflag FLAG_BOUGHT_JOHTO_EGG
	release
	end

Route4_PokemonCenter_1F_EventScript_PayForJohtoEgg::
	removemoney MAGIKARP_PRICE
	updatemoneybox
	playfanfare MUS_LEVEL_UP
	message Route4_PokemonCenter_1F_Text_PaidForJohtoEgg
	waitmessage
	waitfanfare
	return

Route4_PokemonCenter_1F_EventScript_DeclineJohtoEgg::
	msgbox Route4_PokemonCenter_1F_Text_DeclineJohtoEgg
	hidemoneybox
	release
	end

Route4_PokemonCenter_1F_EventScript_NotEnoughMoneyJohtoEgg::
	msgbox Route4_PokemonCenter_1F_Text_NotEnoughMoneyJohtoEgg
	hidemoneybox
	release
	end

Route4_PokemonCenter_1F_EventScript_NoRoomForJohtoEgg::
	msgbox Route4_PokemonCenter_1F_Text_NoRoomForJohtoEgg
	hidemoneybox
	release
	end

Route4_PokemonCenter_1F_EventScript_AlreadyBoughtJohtoEgg::
	msgbox Route4_PokemonCenter_1F_Text_AlreadyBoughtJohtoEgg
	release
	end

Route4_PokemonCenter_1F_Text_CanHaveSixMonsWithYou::
    .string "Okay, set six Poké Balls in my\n"
    .string "belt…\p"
    .string "Yeah, that'll do it. At most, you\n"
    .string "can have six Pokémon with you.$"

Route4_PokemonCenter_1F_Text_TeamRocketAttacksCerulean::
    .string "Team Rocket attacks Cerulean\n"
    .string "citizens…\p"
    .string "Not a day goes by without Team\n"
    .string "Rocket being in the news.$"

Route4_PokemonCenter_1F_Text_LaddieBuyMagikarpForJust500::
    .string "Man: Hello there, laddie!\n"
    .string "Have I got a deal just for you!\p"
    .string "I'll let you have a secret Pokémon\n"
    .string "- a Magikarp - for just ¥500!\p"
    .string "So, you'll buy it, am I right?$"

Route4_PokemonCenter_1F_Text_SweetieBuyMagikarpForJust500::
    .string "Man: Hello there, sweetie pie!\n"
    .string "Have I got a deal just for you!\p"
    .string "I'll let you have a secret Pokémon\n"
    .string "- a Magikarp - for just ¥500!\p"
    .string "So, you'll buy it, am I right?$"

Route4_PokemonCenter_1F_Text_PaidOutrageouslyForMagikarp::
    .string "{PLAYER} paid an outrageous ¥500\n"
    .string "and bought the Magikarp…$"

Route4_PokemonCenter_1F_Text_OnlyDoingThisAsFavorToYou::
    .string "No? You say no? I'm only doing this\n"
    .string "as a favor to you!$"

Route4_PokemonCenter_1F_Text_NoRoomForMorePokemon::
    .string "There's no more room for any more\n"
    .string "Pokémon, it looks like.$"

Route4_PokemonCenter_1F_Text_YoullNeedMoreMoney::
    .string "You'll need more money than that!$"

Route4_PokemonCenter_1F_Text_IDontGiveRefunds::
    .string "Man: Well, I don't give refunds.\n"
    .string "You knew what you were getting!$"

Route4_PokemonCenter_1F_Text_ShouldStoreMonsUsingPC::
    .string "Sometimes, you'll have too many\n"
    .string "Pokémon with you to add any more.\p"
    .string "In that case, you should just\n"
    .string "store some using any PC.$"

Route4_PokemonCenter_1F_Text_ItsANewspaper::
    .string "It's a newspaper.$"

Route4_PokemonCenter_1F_Text_SportBuyJohtoEgg::
    .string "Hey there, sport!\n"
    .string "You've got the look of a real\l"
    .string "Pokémon Trainer!\p"
    .string "I just got back from Johto!\p"
    .string "The Day-Care Couple there\n"
    .string "gave me a genuine Egg!\p"
    .string "No idea what's inside - could\n"
    .string "be anything! Real rare stuff!\p"
    .string "I'd never sell this to just\n"
    .string "anyone, but I like you, kid!\l"
    .string "Just ¥500! So, you'll buy it?$"

Route4_PokemonCenter_1F_Text_SweetieBuyJohtoEgg::
    .string "Well, hello, sweetie!\n"
    .string "You've got the look of a real\l"
    .string "Pokémon Trainer!\p"
    .string "I just got back from Johto!\p"
    .string "The Day-Care Couple there\n"
    .string "gave me a genuine Egg!\p"
    .string "No idea what's inside - could\n"
    .string "be anything! Real rare stuff!\p"
    .string "I'd never sell this to just\n"
    .string "anyone, but I like you, hon!\p"
    .string "Just ¥500! So, you'll buy it?$"

Route4_PokemonCenter_1F_Text_PaidForJohtoEgg::
    .string "{PLAYER} paid ¥500 for\n"
    .string "a mysterious Egg…$"

Route4_PokemonCenter_1F_Text_DeclineJohtoEgg::
    .string "No?! Fine!\n"
    .string "Your loss, not mine!\p"
    .string "Don't come cryin' to me when\n"
    .string "you see what could've hatched!$"

Route4_PokemonCenter_1F_Text_NotEnoughMoneyJohtoEgg::
    .string "You don't even have ¥500!\n"
	.string "That's nothin'!\p"
    .string "Come back when you're not\n"
    .string "broke!$"

Route4_PokemonCenter_1F_Text_NoRoomForJohtoEgg::
    .string "Hmph! No room in your party?\n"
    .string "Come back when you've got\n"
    .string "some space!$"

Route4_PokemonCenter_1F_Text_AlreadyBoughtJohtoEgg::
    .string "What?!\n"
    .string "I only had the one Egg!\p"
    .string "I'm not runnin' a hatchery here,\n"
    .string "you know!$"

