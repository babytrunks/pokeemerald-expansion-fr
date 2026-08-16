SaffronCity_Mart_Frlg_MapScripts::
	.byte 0

SaffronCity_Mart_EventScript_Lass::
	msgbox SaffronCity_Mart_Text_TryToBendSpoon, MSGBOX_NPC
	end

SaffronCity_Mart_EventScript_Youngster::
	msgbox SaffronCity_Mart_Text_MaxRepelMoreEffectiveThanSuper, MSGBOX_NPC
	end

SaffronCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_BADGE05_GET, SaffronCity_Mart_5BadgeStock
	goto_if_set FLAG_BADGE04_GET, SaffronCity_Mart_4BadgeStock
	goto_if_set FLAG_BADGE02_GET, SaffronCity_Mart_2BadgeStock
	pokemart SaffronCity_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end


SaffronCity_Mart_5BadgeStock:
	pokemart SaffronCity_Mart_5BadgeItems
	msgbox gText_PleaseComeAgain
	release
	end

SaffronCity_Mart_4BadgeStock:
	pokemart SaffronCity_Mart_4BadgeItems
	msgbox gText_PleaseComeAgain
	release
	end

SaffronCity_Mart_2BadgeStock:
	pokemart SaffronCity_Mart_2BadgeItems
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
SaffronCity_Mart_Items::
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	pokemartlistend


	.align 2
SaffronCity_Mart_2BadgeItems::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_BLACK_BELT
	.2byte ITEM_TWISTED_SPOON
	pokemartlistend

	.align 2
SaffronCity_Mart_4BadgeItems::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_BLACK_BELT
	.2byte ITEM_TWISTED_SPOON
	pokemartlistend

	.align 2
SaffronCity_Mart_5BadgeItems::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_DUSK_BALL
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_BLACK_BELT
	.2byte ITEM_TWISTED_SPOON
	pokemartlistend

SaffronCity_Mart_Text_MaxRepelMoreEffectiveThanSuper::
    .string "I'd prefer getting my Fighting-types\n"
    .string "a White Belt rather than just handing\l"
    .string "them a Black Belt.\p"
    .string "But I can't find them in stock anywhere!$"

SaffronCity_Mart_Text_TryToBendSpoon::
    .string "Do not try and bend the Twisted\n"
    .string "Spoon. Instead, only try to\l$"
    .string "realize the truth.$"
