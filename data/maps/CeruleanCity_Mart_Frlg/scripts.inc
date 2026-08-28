CeruleanCity_Mart_Frlg_MapScripts::
	.byte 0

CeruleanCity_Mart_EventScript_Youngster::
	msgbox CeruleanCity_Mart_Text_RepelWorksOnWeakMons, MSGBOX_NPC
	end

CeruleanCity_Mart_EventScript_Woman::
	msgbox CeruleanCity_Mart_Text_DoYouKnowAboutRareCandy, MSGBOX_NPC
	end

CeruleanCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_LUXURY_BALLS_IN_MARTS, CeruleanCity_Mart_LuxuryStock
	goto_if_set FLAG_BADGE05_GET, CeruleanCity_Mart_5BadgeStock
	goto_if_set FLAG_BADGE04_GET, CeruleanCity_Mart_4BadgeStock
	goto_if_set FLAG_BADGE02_GET, CeruleanCity_Mart_2BadgeStock
	pokemart CeruleanCity_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

CeruleanCity_Mart_LuxuryStock:
	pokemart CeruleanCity_Mart_LuxuryItems
	msgbox gText_PleaseComeAgain
	release
	end

CeruleanCity_Mart_5BadgeStock:
	pokemart CeruleanCity_Mart_5BadgeItems
	msgbox gText_PleaseComeAgain
	release
	end

CeruleanCity_Mart_4BadgeStock:
	pokemart CeruleanCity_Mart_4BadgeItems
	msgbox gText_PleaseComeAgain
	release
	end

CeruleanCity_Mart_2BadgeStock:
	pokemart CeruleanCity_Mart_2BadgeItems
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
CeruleanCity_Mart_Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_MAGNET
	.2byte ITEM_SHARP_BEAK
	.2byte ITEM_POISON_BARB
	.2byte ITEM_NONE
	release
	end

	.align 2
CeruleanCity_Mart_2BadgeItems::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_MAGNET
	.2byte ITEM_SHARP_BEAK
	.2byte ITEM_POISON_BARB
	.2byte ITEM_NONE
	release
	end

	.align 2
CeruleanCity_Mart_4BadgeItems::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_MAGNET
	.2byte ITEM_SHARP_BEAK
	.2byte ITEM_POISON_BARB
	.2byte ITEM_NONE
	release
	end

	.align 2
CeruleanCity_Mart_5BadgeItems::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_DUSK_BALL  
	.2byte ITEM_MAGNET
	.2byte ITEM_SHARP_BEAK
	.2byte ITEM_POISON_BARB
	.2byte ITEM_NONE
	release
	end

	.align 2
CeruleanCity_Mart_LuxuryItems::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_DUSK_BALL  
	.2byte ITEM_MAGNET
	.2byte ITEM_SHARP_BEAK
	.2byte ITEM_POISON_BARB
	.2byte ITEM_LUXURY_BALL
	.2byte ITEM_NONE
	release
	end

CeruleanCity_Mart_Text_RepelWorksOnWeakMons::
    .string "Repel not only keeps bugs away,\n"
    .string "it also works on weak Pokémon.\p"
    .string "Put your strongest Pokémon at the\n"
    .string "left of the Pokémon List.\p"
    .string "If your first Pokémon is strong,\n"
    .string "Repel's effect is boosted.$"

CeruleanCity_Mart_Text_DoYouKnowAboutRareCandy::
    .string "Do you know about Rare Candy?\n"
    .string "They don't sell it in shops.\p"
    .string "It can level up Pokémon past\n"
    .string "the Level Cap.$"

