Route8_Frlg_MapScripts::
	.byte 0

Route8_EventScript_UndergroundPathSign::
	msgbox Route8_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route8_EventScript_Cole::
	lock
	faceplayer
	goto_if_defeated TRAINER_ACE_TRAINER_COLE, Route8_EventScript_ColePostBattle
	checkitem ITEM_MEGA_RING
	goto_if_eq VAR_RESULT, FALSE, Route8_EventScript_ColeNoMegaRing
    msgbox Route8_Text_ColeIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route8_EventScript_ColeDecline
	msgbox Route8_Text_ColeBattleAccept
	trainerbattle_no_intro TRAINER_ACE_TRAINER_COLE, Route8_Text_ColeDefeat
	msgbox Route8_Text_ColeReward
	giveitem ITEM_ROCKY_HELMET
	giveitem ITEM_CENTISKITE
	msgbox Route8_Text_ColePostBattle
	release
	end

Route8_EventScript_ColePostBattle::
	msgbox Route8_Text_ColePostBattle
	release
	end


Route8_EventScript_ColeNoMegaRing::
	msgbox Route8_Text_ColeNoMegaRing
	release
	end

Route8_EventScript_ColeDecline::
	msgbox Route8_Text_ColeDecline
	release
	end


Route8_Text_ColeIntro::
    .string "That ring on your hand…\n"
    .string "So you've earned a Mega Ring.\p"
    .string "Then you're ready.\p"
    .string "Shall we do battle?$"

Route8_Text_ColeBattleAccept::
    .string "Let's begin!$"

Route8_Text_ColeDefeat::
    .string "Ha! Perhaps my thorns weren't\n"
    .string "sharp enough.$"

Route8_Text_ColeReward::
    .string "You and your Pokémon are the real\n"
    .string "deal. Take these.$"

Route8_Text_ColePostBattle::
    .string "Mega Centiskorch is the only Pokémon\n"
    .string "immune to Rock.\p"
    .string "Quite dandy, don't you think?\p"
    .string "The Rocky Helmet punishes foes for\n"
    .string "attacking you.\p"
    .string "Sometimes chip damage makes all the\n"
    .string "difference!$"
    
Route8_Text_ColeNoMegaRing::
    .string "A real Trainer carries a Mega Ring.\p"
    .string "Come back when you've got one, and\n"
    .string "I'll give you a battle.$"

Route8_Text_ColeDecline::
    .string "Tsk, fine.$"

Route8_Text_AidanIntro::
    .string "You look good at Pokémon, but how\n"
    .string "is your chemistry grade?$"

Route8_Text_AidanDefeat::
    .string "Ow!\n"
    .string "Meltdown!$"

Route8_Text_AidanPostBattle::
    .string "I am better at school than this!$"

Route8_Text_StanIntro::
    .string "All right!\n"
    .string "Let's play a game!$"

Route8_Text_StanDefeat::
    .string "Drat!\n"
    .string "Came up short!$"

Route8_Text_StanPostBattle::
    .string "Things didn't work today.$"

Route8_Text_GlennIntro::
    .string "You should be informed.\n"
    .string "You need strategy to win at this!$"

Route8_Text_GlennDefeat::
    .string "It's not logical!$"

Route8_Text_GlennPostBattle::
    .string "Go with Cradily first…and…\n"
    .string "…and…then…$"

Route8_Text_PaigeIntro::
    .string "I like fairies, so I collect them!$"

Route8_Text_PaigeDefeat::
    .string "Why?\n"
    .string "Why??$"

Route8_Text_PaigePostBattle::
    .string "When Pokémon grow up, they get\n"
    .string "ugly! They shouldn't evolve.\p"
    .string "And don't get me started on\n"
    .string "Megas!$"

Route8_Text_LeslieIntro::
    .string "School is fun, but so are Pokémon.$"

Route8_Text_LeslieDefeat::
    .string "You made it clear to me that\n"
    .string "I should stick with school.$"

Route8_Text_LesliePostBattle::
    .string "I was planning on getting some\n"
    .string "fresh air for a change, but…\p"
    .string "We're stuck here because of the\n"
    .string "gates at Saffron.$"

Route8_Text_AndreaIntro::
    .string "Ambipom is so so cute!$"

Route8_Text_AndreaDefeat::
    .string "Yeeeeowch!$"

Route8_Text_AndreaPostBattle::
    .string "I think Mismagius is quite classy\n"
    .string "too!$"

Route8_Text_MeganIntro::
    .string "We must look silly standing here\n"
    .string "like this.$"

Route8_Text_MeganDefeat::
    .string "Look what you did to my poor, cute\n"
    .string "Pokémon!$"

Route8_Text_MeganPostBattle::
    .string "Saffron's gatekeeper won't let us\n"
    .string "go through.\p"
    .string "I know he's doing his job, but I\n"
    .string "think he's mean.$"

Route8_Text_RichIntro::
    .string "I'm a rambling, gaming dude!$"

Route8_Text_RichDefeat::
    .string "Missed the big chance!$"

Route8_Text_RichPostBattle::
    .string "Playing games and Pokémon are like\n"
    .string "eating peanuts! I just can't stop!$"

Route8_Text_JuliaIntro::
    .string "What's a cute, round, and fluffy\n"
    .string "Pokémon?$"

Route8_Text_JuliaDefeat::
    .string "Stop!\p"
    .string "Don't be so mean to my Probopass!$"

Route8_Text_JuliaPostBattle::
    .string "Nosepass evolves when it's near\n"
    .string "a special magnetic field.$"

Route8_Text_UndergroundPathSign::
    .string "Underground Path\n"
    .string "Celadon City - Lavender Town$"

Route8_Text_EliIntro::
    .string "Twin power is fantastic.\n"
    .string "Did you know?$"

Route8_Text_EliDefeat::
    .string "But…\n"
    .string "We used our twin power…$"

Route8_Text_EliPostBattle::
    .string "I caught my Pokémon with\n"
    .string "Anne!$"

Route8_Text_EliNotEnoughMons::
    .string "We can't battle if you don't\n"
    .string "have two Pokémon.$"

Route8_Text_AnneIntro::
    .string "We'll shock you with our twin\n"
    .string "power!$"

Route8_Text_AnneDefeat::
    .string "Our twin power…$"

Route8_Text_AnnePostBattle::
    .string "I'm raising Pokémon with\n"
    .string "Eli.$"

Route8_Text_AnneNotEnoughMons::
    .string "Hi, hi! Let's battle!\n"
    .string "But bring two Pokémon.$"

Route8_Text_RicardoIntro::
    .string "My bike's acting up, man.$"

Route8_Text_RicardoDefeat::
    .string "Aww, man.\n"
    .string "I'm not into this.$"

Route8_Text_RicardoPostBattle::
    .string "I got grass caught up in my\n"
    .string "spokes, man.$"

Route8_Text_JarenIntro::
    .string "Clear the way, or I'll run you\n"
    .string "down!$"

Route8_Text_JarenDefeat::
    .string "You for real, kid?$"

Route8_Text_JarenPostBattle::
    .string "Don't think you're all special and\n"
    .string "all just because of this.$"
