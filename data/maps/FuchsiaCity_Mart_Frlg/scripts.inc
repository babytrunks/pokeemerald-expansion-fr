FuchsiaCity_Mart_Frlg_MapScripts::
	.byte 0

FuchsiaCity_Mart_EventScript_CooltrainerF::
	msgbox FuchsiaCity_Mart_Text_DidYouTryXSpeed, MSGBOX_NPC
	end

FuchsiaCity_Mart_EventScript_Gentleman::
	msgbox FuchsiaCity_Mart_Text_DontTheyHaveSafariZonePennants, MSGBOX_NPC
	end


FuchsiaCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_BADGE05_GET, FuchsiaCity_Mart_5BadgeStock
	goto_if_set FLAG_BADGE04_GET, FuchsiaCity_Mart_4BadgeStock
	goto_if_set FLAG_BADGE02_GET, FuchsiaCity_Mart_2BadgeStock
	pokemart FuchsiaCity_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

FuchsiaCity_Mart_5BadgeStock:
	pokemart FuchsiaCity_Mart_5BadgeItems
	msgbox gText_PleaseComeAgain
	release
	end

FuchsiaCity_Mart_4BadgeStock:
	pokemart FuchsiaCity_Mart_4BadgeItems
	msgbox gText_PleaseComeAgain
	release
	end

FuchsiaCity_Mart_2BadgeStock:
	pokemart FuchsiaCity_Mart_2BadgeItems
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
FuchsiaCity_Mart_Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_NONE
	release
	end

	.align 2
FuchsiaCity_Mart_2BadgeItems::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_NONE
	release
	end

	.align 2
FuchsiaCity_Mart_4BadgeItems::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_NONE
	release
	end

	.align 2
FuchsiaCity_Mart_5BadgeItems::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_DUSK_BALL
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_NONE
	release
	end

FuchsiaCity_Mart_Text_DontTheyHaveSafariZonePennants::
    .string "Don't they have any pennants\n"
    .string "promoting the Safari Zone?\p"
    .string "How about some paper lanterns?\n"
    .string "Aren't there even any calendars?$"

FuchsiaCity_Mart_Text_DidYouTryXSpeed::
    .string "Did you try X Speed?\n"
    .string "It speeds up a Pokémon in battle.$"

