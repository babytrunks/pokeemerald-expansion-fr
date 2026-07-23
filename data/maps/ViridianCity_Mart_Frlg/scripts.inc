ViridianCity_Mart_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ViridianCity_Mart_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ViridianCity_Mart_OnFrame
	.byte 0

ViridianCity_Mart_OnLoad::
	goto_if_unset FLAG_SYS_POKEDEX_GET, ViridianCity_Mart_EventScript_HideQuestionnaire
	end

ViridianCity_Mart_EventScript_HideQuestionnaire::
	setmetatile 1, 3, METATILE_Mart_CounterMid_Top, 1
	setmetatile 1, 4, METATILE_Mart_CounterMid_Bottom, 1
	end

ViridianCity_Mart_OnFrame::
	.2byte 0


ViridianCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_BADGE05_GET, ViridianCity_Mart_5BadgeStock
	goto_if_set FLAG_BADGE04_GET, ViridianCity_Mart_4BadgeStock
	goto_if_set FLAG_BADGE02_GET, ViridianCity_Mart_2BadgeStock
	pokemart ViridianCity_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

ViridianCity_Mart_5BadgeStock:
	pokemart ViridianCity_Mart_5BadgeItems
	msgbox gText_PleaseComeAgain
	release
	end

ViridianCity_Mart_4BadgeStock:
	pokemart ViridianCity_Mart_4BadgeItems
	msgbox gText_PleaseComeAgain
	release
	end

ViridianCity_Mart_2BadgeStock:
	pokemart ViridianCity_Mart_2BadgeItems
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
ViridianCity_Mart_Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_POMEG_BERRY
	.2byte ITEM_SILK_SCARF
	.2byte ITEM_NONE
	release
	end

	.align 2
ViridianCity_Mart_2BadgeItems::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_POMEG_BERRY
	.2byte ITEM_SILK_SCARF
	.2byte ITEM_NONE
	release
	end

	.align 2
ViridianCity_Mart_4BadgeItems::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_POMEG_BERRY
	.2byte ITEM_SILK_SCARF
	.2byte ITEM_NONE
	release
	end

	.align 2
ViridianCity_Mart_5BadgeItems::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_DUSK_BALL
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_POMEG_BERRY
	.2byte ITEM_SILK_SCARF
	.2byte ITEM_NONE
	release
	end

ViridianCity_Mart_EventScript_Woman::
	msgbox ViridianCity_Mart_Text_ShopDoesGoodBusinessInAntidotes, MSGBOX_NPC
	end

ViridianCity_Mart_EventScript_Youngster::
	msgbox ViridianCity_Mart_Text_GotToBuySomePotions, MSGBOX_NPC
	end

ViridianCity_Mart_Text_ShopDoesGoodBusinessInAntidotes::
    .string "This shop does good business in\n"
    .string "Pomeg Berries, I've heard.$"

ViridianCity_Mart_Text_GotToBuySomePotions::
    .string "I've got to restock on Balls.\p"
    .string "You never know when you will encounter\n"
    .string "a Shiny.$"

