Route21_South_Frlg_MapScripts::
	.byte 0

@ Gated boss, opens up once every Route 21 trainer is beaten
Route21_South_EventScript_Elbein::
	lock
	faceplayer
	goto_if_set FLAG_GOT_STARAPTITE_FROM_ELBEIN, Route21_South_EventScript_ElbeinPostBattle
	goto_if_defeated TRAINER_ROUTE21_ELBEIN, Route21_South_EventScript_ElbeinReward
	goto_if_not_defeated TRAINER_FISHERMAN_RONALD, Route21_South_EventScript_ElbeinLocked
	goto_if_not_defeated TRAINER_FISHERMAN_WADE, Route21_South_EventScript_ElbeinLocked
	goto_if_not_defeated TRAINER_SWIMMER_MALE_SPENCER, Route21_South_EventScript_ElbeinLocked
	goto_if_not_defeated TRAINER_SIS_AND_BRO_LIL_IAN, Route21_South_EventScript_ElbeinLocked
	goto_if_not_defeated TRAINER_FISHERMAN_CLAUDE, Route21_South_EventScript_ElbeinLocked
	goto_if_not_defeated TRAINER_FISHERMAN_NOLAN, Route21_South_EventScript_ElbeinLocked
	goto_if_not_defeated TRAINER_SWIMMER_MALE_JACK, Route21_South_EventScript_ElbeinLocked
	goto_if_not_defeated TRAINER_SWIMMER_MALE_JEROME, Route21_South_EventScript_ElbeinLocked
	goto_if_not_defeated TRAINER_SWIMMER_MALE_ROLAND, Route21_South_EventScript_ElbeinLocked
	msgbox Route21_South_Text_ElbeinChallenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route21_South_EventScript_ElbeinDecline
	msgbox Route21_South_Text_ElbeinAccept
	closemessage
	trainerbattle_no_intro TRAINER_ROUTE21_ELBEIN, Route21_South_Text_ElbeinDefeat

@ Also the re-talk path if the Bag was full last time
Route21_South_EventScript_ElbeinReward::
	msgbox Route21_South_Text_ElbeinReward
	checkitemspace ITEM_STARAPTITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	giveitem ITEM_STARAPTITE
	setflag FLAG_GOT_STARAPTITE_FROM_ELBEIN
	goto Route21_South_EventScript_ElbeinPostBattle
	end

Route21_South_EventScript_ElbeinLocked::
	msgbox Route21_South_Text_ElbeinLocked
	release
	end

Route21_South_EventScript_ElbeinDecline::
	msgbox Route21_South_Text_ElbeinDecline
	release
	end

Route21_South_EventScript_ElbeinPostBattle::
	msgbox Route21_South_Text_ElbeinPostBattle
	release
	end

Route21_South_Text_ElbeinLocked::
	.string "I befriended an incredibly rare\n"
	.string "Pokémon in my home region.\p"
	.string "Think you have what it takes to\n"
	.string "beat it?\p"
	.string "Defeat all the trainers here and\n"
	.string "I'll show you its awesome power!$"

Route21_South_Text_ElbeinChallenge::
	.string "I see you've defeated all the\n"
	.string "trainers in this area.\p"
	.string "Are you sure you're ready to\n"
	.string "face me?$"

Route21_South_Text_ElbeinAccept::
	.string "I have a Mythical Pokémon on my\n"
	.string "side, there's no way I can lose!$"

Route21_South_Text_ElbeinDefeat::
	.string "I'm impressed.$"

Route21_South_Text_ElbeinReward::
	.string "It looks like I need to get back\n"
	.string "to my training.\p"
	.string "Here, take this.$"

Route21_South_Text_ElbeinPostBattle::
	.string "I once caught my partner sneaking\n"
	.string "glances at another trainer's Ditto.\p"
	.string "But I thought no Mythical Pokémon\n"
	.string "could breed.\p"
	.string "Odd, right?$"

Route21_South_Text_ElbeinDecline::
	.string "Then come back when you are.\n"
	.string "I'm not going anywhere.$"

Route21_South_Text_JackIntro::
	.string "I caught my Pokémon at sea.$"

Route21_South_Text_JackDefeat::
	.string "Diver!!\n"
	.string "Down!!$"

Route21_South_Text_JackPostBattle::
	.string "Where'd you catch your Pokémon?$"

Route21_South_Text_JeromeIntro::
	.string "Right now, I'm in a triathlon meet.$"

Route21_South_Text_JeromeDefeat::
	.string "Pant…\n"
	.string "Pant… Pant…$"

Route21_South_Text_JeromePostBattle::
	.string "I'm beat! But, I still have the\n"
	.string "bike race and marathon left!$"

Route21_South_Text_RolandIntro::
	.string "Ahh!\n"
	.string "Feel the sun and the wind!$"

Route21_South_Text_RolandDefeat::
	.string "Yow!\n"
	.string "I lost!$"

Route21_South_Text_RolandPostBattle::
	.string "I'm sunburnt to a crisp!$"

Route21_South_Text_ClaudeIntro::
	.string "Hey, don't scare away the fish!$"

Route21_South_Text_ClaudeDefeat::
	.string "Sorry! I'm just so frustrated from\n"
	.string "not catching anything.$"

Route21_South_Text_ClaudePostBattle::
	.string "Sheesh, I haven't caught a thing.\n"
	.string "Could this place actually be a\l"
	.string "giant pool or something?$"

Route21_South_Text_NolanIntro::
	.string "Keep me company till I get a hit.$"

Route21_South_Text_NolanDefeat::
	.string "That burned some time.$"

Route21_South_Text_NolanPostBattle::
	.string "Oh wait!\n"
	.string "I got a bite! Yeah!$"

Route21_North_Text_LilIntro::
	.string "Lil: Huh? A battle?\n"
	.string "Ian, can't you do it alone?$"

Route21_North_Text_LilDefeat::
	.string "Lil: Oh, see?\n"
	.string "We lost. Happy now?$"

Route21_North_Text_LilPostBattle::
	.string "Lil: I'm tired.\n"
	.string "Can't we go home already?$"

Route21_North_Text_LilNotEnoughMons::
	.string "Lil: Huh? A battle?\n"
	.string "I can't be bothered to do it alone.\l"
	.string "Bring two Pokémon, won't you?$"

Route21_North_Text_IanIntro::
	.string "Ian: My sis doesn't get enough\n"
	.string "exercise, so I made her come.$"

Route21_North_Text_IanDefeat::
	.string "Ian: Awww, Sis!\n"
	.string "Get it together!$"

Route21_North_Text_IanPostBattle::
	.string "Ian: Come on, Sis!\p"
	.string "You're not going to lose weight\n"
	.string "like this!$"

Route21_North_Text_IanNotEnoughMons::
	.string "Ian: We want a two-on-two battle.\n"
	.string "So can you bring two Pokémon?$"
