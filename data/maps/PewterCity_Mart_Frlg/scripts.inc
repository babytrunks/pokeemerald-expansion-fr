PewterCity_Mart_Frlg_MapScripts::
	.byte 0

PewterCity_Mart_EventScript_Youngster::
	msgbox PewterCity_Mart_Text_BoughtWeirdFishFromShadyGuy, MSGBOX_NPC
	end

PewterCity_Mart_EventScript_Boy::
	msgbox PewterCity_Mart_Text_GoodThingsIfRaiseMonsDiligently, MSGBOX_NPC
	end

PewterCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_LUXURY_BALLS_IN_MARTS, PewterCity_Mart_LuxuryStock
	goto_if_set FLAG_BADGE05_GET, PewterCity_Mart_5BadgeStock
	goto_if_set FLAG_BADGE04_GET, PewterCity_Mart_4BadgeStock
	goto_if_set FLAG_BADGE02_GET, PewterCity_Mart_2BadgeStock
	pokemart PewterCity_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

PewterCity_Mart_LuxuryStock:
	pokemart PewterCity_Mart_LuxuryItems
	msgbox gText_PleaseComeAgain
	release
	end

PewterCity_Mart_5BadgeStock:
	pokemart PewterCity_Mart_5BadgeItems
	msgbox gText_PleaseComeAgain
	release
	end

PewterCity_Mart_4BadgeStock:
	pokemart PewterCity_Mart_4BadgeItems
	msgbox gText_PleaseComeAgain
	release
	end

PewterCity_Mart_2BadgeStock:
	pokemart PewterCity_Mart_2BadgeItems
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
PewterCity_Mart_Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_CHARCOAL
	.2byte ITEM_MIRACLE_SEED
	.2byte ITEM_MYSTIC_WATER
	.2byte ITEM_NONE
	release
	end

	.align 2
PewterCity_Mart_2BadgeItems::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_CHARCOAL
	.2byte ITEM_MIRACLE_SEED
	.2byte ITEM_MYSTIC_WATER
	.2byte ITEM_NONE
	release
	end

	.align 2
PewterCity_Mart_4BadgeItems::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_CHARCOAL
	.2byte ITEM_MIRACLE_SEED
	.2byte ITEM_MYSTIC_WATER
	.2byte ITEM_NONE
	release
	end

	.align 2
PewterCity_Mart_5BadgeItems::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_DUSK_BALL
	.2byte ITEM_CHARCOAL
	.2byte ITEM_MIRACLE_SEED
	.2byte ITEM_MYSTIC_WATER
	.2byte ITEM_NONE
	release
	end

	.align 2
PewterCity_Mart_LuxuryItems::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_DUSK_BALL
	.2byte ITEM_CHARCOAL
	.2byte ITEM_MIRACLE_SEED
	.2byte ITEM_MYSTIC_WATER
	.2byte ITEM_LUXURY_BALL
	.2byte ITEM_NONE
	release
	end

PewterCity_Mart_Text_BoughtWeirdFishFromShadyGuy::
    .string "A shady old guy sucked me into\n"
    .string "buying this weird fish Pokémon!\p"
    .string "It's totally weak and it cost ¥500!$"

PewterCity_Mart_Text_GoodThingsIfRaiseMonsDiligently::
    .string "Good things can happen if you raise\n"
    .string "Pokémon diligently.\p"
    .string "Even the weak ones can surprise\n"
    .string "you if you don't give up on them.$"

