CeladonCity_DepartmentStore_2F_Frlg_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_2F_EventScript_UnusedNPC::
	msgbox CeladonCity_DepartmentStore_2F_Text_SuperRepelMorePowerfulRepel, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_2F_EventScript_Lass::
	msgbox CeladonCity_DepartmentStore_2F_Text_BuyReviveForLongOutings, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_2F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_2F_Text_FloorSign, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_2F_EventScript_ClerkItems::
lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_BADGE05_GET, CeladonCity_Mart_5BadgeStock
	goto_if_set FLAG_BADGE04_GET, CeladonCity_Mart_4BadgeStock
	goto_if_set FLAG_BADGE02_GET, CeladonCity_Mart_2BadgeStock
	pokemart CeladonCity_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

CeladonCity_Mart_5BadgeStock:
	pokemart CeladonCity_Mart_5BadgeItems
	msgbox gText_PleaseComeAgain
	release
	end

CeladonCity_Mart_4BadgeStock:
	pokemart CeladonCity_Mart_4BadgeItems
	msgbox gText_PleaseComeAgain
	release
	end

CeladonCity_Mart_2BadgeStock:
	pokemart CeladonCity_Mart_2BadgeItems
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_Mart_Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_BERRY_JUICE
	.2byte ITEM_SILK_SCARF
	.2byte ITEM_CHARCOAL
	.2byte ITEM_MIRACLE_SEED
	.2byte ITEM_MYSTIC_WATER
	.2byte ITEM_MAGNET
	.2byte ITEM_BLACK_BELT
	.2byte ITEM_TWISTED_SPOON
	.2byte ITEM_SOFT_SAND
	.2byte ITEM_POISON_BARB
	.2byte ITEM_SHARP_BEAK
	.2byte ITEM_SILVER_POWDER
	.2byte ITEM_SPELL_TAG
	.2byte ITEM_METAL_COAT
	.2byte ITEM_NEVER_MELT_ICE
	.2byte ITEM_DRAGON_FANG
	.2byte ITEM_FAIRY_FEATHER
	.2byte ITEM_NONE
	release
	end

	.align 2
CeladonCity_Mart_2BadgeItems::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_BERRY_JUICE
	.2byte ITEM_NONE
	release
	end

	.align 2
CeladonCity_Mart_4BadgeItems::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_BERRY_JUICE
	.2byte ITEM_NONE
	release
	end

	.align 2
CeladonCity_Mart_5BadgeItems::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_DUSK_BALL  
	.2byte ITEM_BERRY_JUICE
	.2byte ITEM_NONE
	release
	end

CeladonCity_DepartmentStore_2F_EventScript_ClerkTMs::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_2F_TMs
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_2F_TMs::
	.2byte ITEM_TM_ROAR
	.2byte ITEM_TM_LIGHT_SCREEN
	.2byte ITEM_TM_REFLECT 
	.2byte ITEM_TM_DRAGON_TAIL
	.2byte ITEM_TM_HYPER_VOICE
	.2byte ITEM_NONE
	release
	end

CeladonCity_DepartmentStore_2F_Text_SuperRepelMorePowerfulRepel::
    .string "Sometimes when I want to let off a little\n"
    .string "steam, I just spam Roar at Wild Rattatas.$"

CeladonCity_DepartmentStore_2F_Text_BuyReviveForLongOutings::
    .string "Pairing Reflect with Light Clay is\n"
    .string "is a decent tactic.$"

CeladonCity_DepartmentStore_2F_Text_FloorSign::
    .string "Top-Grade Items for Trainers!\p"
    .string "2F: Trainer's Market$"

CeladonCity_DepartmentStore_2F_Text_LanceComesToBuyCapes::
    .string "We have a customer, Lance, who\n"
    .string "occasionally comes.\p"
    .string "He always buys capes.\p"
    .string "I wonder… Did he learn that\n"
    .string "move from Piccolo?$"
