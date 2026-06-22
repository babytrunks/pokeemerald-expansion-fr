PokemonMansion_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonMansion_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonMansion_1F_OnTransition
	.byte 0

PokemonMansion_1F_OnLoad::
	call_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_PressSwitch_1F
	end

PokemonMansion_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_POKEMON_MANSION_1F
	end

PokemonMansion_1F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 0
	call PokemonMansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

PokemonMansion_1F_EventScript_Ted::
	trainerbattle_single TRAINER_SCIENTIST_TED, PokemonMansion_1F_Text_TedIntro, PokemonMansion_1F_Text_TedDefeat
	msgbox PokemonMansion_1F_Text_TedPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_1F_EventScript_Johnson::
	trainerbattle_single TRAINER_YOUNGSTER_JOHNSON, PokemonMansion_1F_Text_JohnsonIntro, PokemonMansion_1F_Text_JohnsonDefeat
	msgbox PokemonMansion_1F_Text_JohnsonPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_1F_EventScript_Thomas::
	lock
	faceplayer
	goto_if_defeated TRAINER_COOLTRAINER_THOMAS, PokemonMansion_1F_EventScript_ThomasReward
	goto_if_not_defeated TRAINER_SCIENTIST_TED, PokemonMansion_1F_EventScript_ThomasNotReady
	goto_if_not_defeated TRAINER_YOUNGSTER_JOHNSON, PokemonMansion_1F_EventScript_ThomasNotReady
	goto_if_not_defeated TRAINER_BURGLAR_ARNIE, PokemonMansion_1F_EventScript_ThomasNotReady
	goto_if_not_defeated TRAINER_BURGLAR_SIMON, PokemonMansion_1F_EventScript_ThomasNotReady
	goto_if_not_defeated TRAINER_SCIENTIST_BRAYDON, PokemonMansion_1F_EventScript_ThomasNotReady
	goto_if_not_defeated TRAINER_BURGLAR_LEWIS, PokemonMansion_1F_EventScript_ThomasNotReady
	goto_if_not_defeated TRAINER_SCIENTIST_IVAN, PokemonMansion_1F_EventScript_ThomasNotReady
	msgbox PokemonMansion_1F_Text_ThomasIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PokemonMansion_1F_EventScript_ThomasDecline
	msgbox PokemonMansion_1F_Text_ThomasAccept
	trainerbattle_no_intro TRAINER_COOLTRAINER_THOMAS, PokemonMansion_1F_Text_ThomasDefeat
PokemonMansion_1F_EventScript_ThomasReward::
	msgbox PokemonMansion_1F_Text_ThomasReward
	giveitem ITEM_GOLISOPITE
	msgbox PokemonMansion_1F_Text_ThomasPostBattle
	closemessage
	setflag FLAG_HIDE_MANSION_THOMAS
	removeobject LOCALID_POKEMON_MANSION_1F_THOMAS
	release
	end

PokemonMansion_1F_EventScript_ThomasBagFull::
	msgbox gText_TooBadBagIsFull
	release
	end

PokemonMansion_1F_EventScript_ThomasNotReady::
	msgbox PokemonMansion_1F_Text_ThomasNotReady
	release
	end

PokemonMansion_1F_EventScript_ThomasDecline::
	msgbox PokemonMansion_1F_Text_ThomasNo
	release
	end

PokemonMansion_1F_Text_TedIntro::
    .string "Who are you?\n"
    .string "There shouldn't be anyone here.$"

PokemonMansion_1F_Text_TedDefeat::
    .string "Ouch!$"

PokemonMansion_1F_Text_TedPostBattle::
    .string "A key? I don't know what you're\n"
    .string "talking about.$"

PokemonMansion_1F_Text_JohnsonIntro::
    .string "W-w-waah! You startled me!\n"
    .string "I thought you were a ghost.$"

PokemonMansion_1F_Text_JohnsonDefeat::
    .string "Tch!\n"
    .string "I can't get any wins.$"

PokemonMansion_1F_Text_JohnsonPostBattle::
    .string "I was exploring here by myself,\n"
    .string "but I feel spooked.\p"
    .string "I ought to go soon.$"

PokemonMansion_1F_Text_ThomasIntro::
    .string "Hm? Oh yes.\n"
    .string "I've had my eye on you. Cleared\l"
    .string "out every trainer here.\p"
    .string "Fine. A battle, and make it\n"
    .string "snappy.\p"
    .string "Well? Yes or no? Don't waste\n"
    .string "my time.$"

PokemonMansion_1F_Text_ThomasAccept::
    .string "Good! Let's get this over with.\n"
    .string "I have a power nap scheduled at\l"
	.string "three.$"

PokemonMansion_1F_Text_ThomasDefeat::
    .string "Wha?! That was not what I\n"
    .string "had planned!$"

PokemonMansion_1F_Text_ThomasReward::
    .string "Fine, fine. You got me.\n"
    .string "Here, consider it a signing\l"
    .string "bonus.\p"
	.string "Maybe it'll get you to leave\n"
	.string "me alone.$"

PokemonMansion_1F_Text_ThomasPostBattle::
    .string "Now if you'll excuse me, I have\n"
    .string "a very important nap to take.$"

PokemonMansion_1F_Text_ThomasNotReady::
    .string "Mm? You want my time?\p"
    .string "Sorry. I don't take meetings\n"
    .string "with amateurs.\p"
    .string "Clear out every trainer in this\n"
    .string "mansion first. Then we'll talk.$"

PokemonMansion_1F_Text_ThomasNo::
    .string "No? Fine. You saved me the trouble.$"
