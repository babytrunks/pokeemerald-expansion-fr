VermilionCity_Mart_Frlg_MapScripts::
	.byte 0

VermilionCity_Mart_EventScript_CooltrainerF::
	msgbox VermilionCity_Mart_Text_MonsGoodOrBadDependingOnTrainer, MSGBOX_NPC
	end

VermilionCity_Mart_EventScript_BaldingMan::
	msgbox VermilionCity_Mart_Text_TeamRocketAreWickedPeople, MSGBOX_NPC
	end

VermilionCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_LUXURY_BALLS_IN_MARTS, VermilionCity_Mart_LuxuryStock
	goto_if_set FLAG_BADGE05_GET, VermilionCity_Mart_5BadgeStock
	goto_if_set FLAG_BADGE04_GET, VermilionCity_Mart_4BadgeStock
	goto_if_set FLAG_BADGE02_GET, VermilionCity_Mart_2BadgeStock
	pokemart VermilionCity_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

VermilionCity_Mart_LuxuryStock:
	pokemart VermilionCity_Mart_LuxuryItems
	msgbox gText_PleaseComeAgain
	release
	end

VermilionCity_Mart_5BadgeStock:
	pokemart VermilionCity_Mart_5BadgeItems
	msgbox gText_PleaseComeAgain
	release
	end

VermilionCity_Mart_4BadgeStock:
	pokemart VermilionCity_Mart_4BadgeItems
	msgbox gText_PleaseComeAgain
	release
	end

VermilionCity_Mart_2BadgeStock:
	pokemart VermilionCity_Mart_2BadgeItems
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
VermilionCity_Mart_Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_HARD_STONE
	.2byte ITEM_SOFT_SAND
	.2byte ITEM_NONE
	release
	end

	.align 2
VermilionCity_Mart_2BadgeItems::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_HARD_STONE
	.2byte ITEM_SOFT_SAND
	.2byte ITEM_NONE
	release
	end

	.align 2
VermilionCity_Mart_4BadgeItems::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_HARD_STONE
	.2byte ITEM_SOFT_SAND
	.2byte ITEM_NONE
	release
	end

	.align 2
VermilionCity_Mart_5BadgeItems::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_DUSK_BALL  
	.2byte ITEM_HARD_STONE
	.2byte ITEM_SOFT_SAND
	.2byte ITEM_NONE
	release
	end

	.align 2
VermilionCity_Mart_LuxuryItems::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_DUSK_BALL  
	.2byte ITEM_HARD_STONE
	.2byte ITEM_SOFT_SAND
	.2byte ITEM_LUXURY_BALL
	.2byte ITEM_NONE
	release
	end

VermilionCity_Mart_Text_TeamRocketAreWickedPeople::
    .string "There are wicked people who will\n"
    .string "use Pokémon for criminal acts.\p"
    .string "Team Rocket traffics in rare\n"
    .string "Pokémon, for example.\p"
    .string "They also abandon Pokémon that\n"
    .string "they consider unpopular or useless.\p"
    .string "That's the sort of horrid people\n"
    .string "they are, Team Rocket.$"

VermilionCity_Mart_Text_MonsGoodOrBadDependingOnTrainer::
    .string "I think Pokémon can be good or\n"
    .string "bad. It depends on the Trainer.$"

