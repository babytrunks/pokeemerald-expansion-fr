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
	giveitem ITEM_DRAGALGITE
	msgbox PokemonMansion_1F_Text_ThomasPostBattle
	closemessage
	setflag FLAG_HIDE_MANSION_THOMAS
	removeobject LOCALID_POKEMON_MANSION_1F_THOMAS
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
    .string "I see you found me, trainer.\p"
    .string "Me and my Pokémon are here on\n"
    .string "Cinnabar Island to relax after\l"
    .string "many weeks out on the high seas.\p"
    .string "It could be fun to see how the\n"
    .string "mainland trainers fare in battle!$"

PokemonMansion_1F_Text_ThomasAccept::
    .string "That's the spirit, matey!\p"
    .string "Let's see if you can weather a\n"
    .string "storm!$"

PokemonMansion_1F_Text_ThomasDefeat::
    .string "Well done matey!\n"
    .string "You really washed me there!$"

PokemonMansion_1F_Text_ThomasReward::
    .string "Take this item, it is precious\n"
    .string "to my partner Dragalge.$"

PokemonMansion_1F_Text_ThomasPostBattle::
    .string "It was mighty fun battling you,\n"
    .string "youngster.\p"
    .string "I hope we can meet again\n"
    .string "sometime, out on the high seas!$"

PokemonMansion_1F_Text_ThomasNotReady::
    .string "Ahoy there, youngster!\p"
    .string "I only battle sailors who have\n"
    .string "earned their sea legs.\p"
    .string "Best every trainer in this\n"
    .string "mansion first, then we'll talk!$"

PokemonMansion_1F_Text_ThomasNo::
    .string "No? Then rest up, matey.\n"
    .string "I'll be here a while yet.$"
