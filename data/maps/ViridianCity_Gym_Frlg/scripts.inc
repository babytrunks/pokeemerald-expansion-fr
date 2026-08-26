ViridianCity_Gym_Frlg_MapScripts::
	.byte 0

ViridianCity_Gym_EventScript_Mina::
	trainerbattle_single TRAINER_LEADER_MINA, ViridianCity_Gym_Text_MinaIntro, ViridianCity_Gym_Text_MinaDefeat, ViridianCity_Gym_EventScript_DefeatedMina, NO_MUSIC
	msgbox ViridianCity_Gym_Text_MinaPostBattle
	closemessage
	release
	end

ViridianCity_Gym_EventScript_DefeatedMina::
	setflag FLAG_HIDE_MISC_KANTO_ROCKETS
	setflag FLAG_BADGE08_GET
	setvar VAR_MAP_SCENE_ROUTE22, 3
	set_gym_trainers_frlg 8
	goto ViridianCity_Gym_EventScript_GiveTM56
	end

ViridianCity_Gym_EventScript_GiveTM56::
    callnative SetBuffer1ToLevelCap
	msgbox ViridianCity_Gym_Text_ExplainPetalBadgeTakeThis
    giveitem ITEM_TM_DAZZLING_GLEAM
	msgbox ViridianCity_Gym_Text_ExplainDazzlingGleam
    giveitem ITEM_FLOETTITE
	msgbox ViridianCity_Gym_Text_ExplainFloettite
    applymovement LOCALID_PLAYER, Common_Movement_FaceDown
    waitmovement 0
	call_if_set FLAG_AUTOSAVE_ENABLED, Common_EventScript_AutoSave
	release
	end

ViridianCity_Gym_EventScript_Jason::
	trainerbattle_single TRAINER_TAMER_JASON, ViridianCity_Gym_Text_JasonIntro, ViridianCity_Gym_Text_JasonDefeat
	msgbox ViridianCity_Gym_Text_JasonPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Cole::
	trainerbattle_single TRAINER_TAMER_COLE, ViridianCity_Gym_Text_ColeIntro, ViridianCity_Gym_Text_ColeDefeat
	msgbox ViridianCity_Gym_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Atsushi::
	trainerbattle_single TRAINER_BLACK_BELT_ATSUSHI, ViridianCity_Gym_Text_AtsushiIntro, ViridianCity_Gym_Text_AtsushiDefeat
	msgbox ViridianCity_Gym_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Kiyo::
	trainerbattle_single TRAINER_BLACK_BELT_KIYO, ViridianCity_Gym_Text_KiyoIntro, ViridianCity_Gym_Text_KiyoDefeat
	msgbox ViridianCity_Gym_Text_KiyoPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Takashi::
	trainerbattle_single TRAINER_BLACK_BELT_TAKASHI, ViridianCity_Gym_Text_TakashiIntro, ViridianCity_Gym_Text_TakashiDefeat
	msgbox ViridianCity_Gym_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Samuel::
	trainerbattle_single TRAINER_COOLTRAINER_SAMUEL, ViridianCity_Gym_Text_SamuelIntro, ViridianCity_Gym_Text_SamuelDefeat
	msgbox ViridianCity_Gym_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Yuji::
	trainerbattle_single TRAINER_COOLTRAINER_YUJI, ViridianCity_Gym_Text_YujiIntro, ViridianCity_Gym_Text_YujiDefeat
	msgbox ViridianCity_Gym_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Warren::
	trainerbattle_single TRAINER_COOLTRAINER_WARREN, ViridianCity_Gym_Text_WarrenIntro, ViridianCity_Gym_Text_WarrenDefeat
	msgbox ViridianCity_Gym_Text_WarrenPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE08_GET, ViridianCity_Gym_EventScript_GymGuyPostVictory
	msgbox ViridianCity_Gym_Text_GymGuyAdvice
	release
	end

ViridianCity_Gym_EventScript_GymGuyPostVictory::
	famechecker FAMECHECKER_GIOVANNI, 4
	msgbox ViridianCity_Gym_Text_GymGuyPostVictory
	release
	end

ViridianCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, ViridianCity_Gym_EventScript_GymStatuePostVictory
	msgbox ViridianCity_Gym_Text_GymStatue
	releaseall
	end

ViridianCity_Gym_EventScript_GymStatuePostVictory::
	msgbox ViridianCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

ViridianCity_Gym_Text_ExplainPetalBadgeTakeThis::
    .string "Oh! Wonderful!\p"
    .string "You and your Pokémon, battling\n"
    .string "side by side…\p"
    .string "Now that's a great composition.\n"
    .string "I'd love to draw the two of you.\p"
    .string "Here. The Petal Badge is yours.\p"
    .string "It raises your Level Cap to\n"
    .string "{STR_VAR_1}, and it lets you challenge\l"
    .string "the Pokémon League.\p"
    .string "Take these, too.$"

ViridianCity_Gym_Text_ExplainDazzlingGleam::
    .string "TM56 is Dazzling Gleam.\p"
    .string "It floods the whole field with light\n"
    .string "and hits everything across from you.$"

ViridianCity_Gym_Text_ExplainFloettite::
    .string "And that one is the Floettite.\p"
    .string "Give it to a Floette holding the\n"
    .string "Eternal Flower and it'll Mega Evolve.\p"
    .string "Mega Floette gets Fairy Aura, so\n"
    .string "every Fairy-type move on the field\l"
    .string "hits harder.\p"
    .string "Both sides. So be careful.$"

ViridianCity_Gym_Text_YujiIntro::
    .string "Heh!\n"
    .string "You must be running out of steam\l"
    .string "by now!$"

ViridianCity_Gym_Text_YujiDefeat::
    .string "I ran out of gas!$"

ViridianCity_Gym_Text_YujiPostBattle::
    .string "You'll need power to keep up with\n"
    .string "our Gym Leader.$"

ViridianCity_Gym_Text_AtsushiIntro::
    .string "Rrrroar!\n"
    .string "I'm working myself into a rage!$"

ViridianCity_Gym_Text_AtsushiDefeat::
    .string "Wargh!$"

ViridianCity_Gym_Text_AtsushiPostBattle::
    .string "I'm still not worthy!$"

ViridianCity_Gym_Text_JasonIntro::
    .string "Pokémon and I, we make wonderful\n"
    .string "music together!$"

ViridianCity_Gym_Text_JasonDefeat::
    .string "You are in perfect harmony!$"

ViridianCity_Gym_Text_JasonPostBattle::
    .string "Our Leader paints, you know.\p"
    .string "Don't let that fool you.$"

ViridianCity_Gym_Text_KiyoIntro::
    .string "Karate is the ultimate form of\n"
    .string "martial arts!$"

ViridianCity_Gym_Text_KiyoDefeat::
    .string "Aiyah!$"

ViridianCity_Gym_Text_KiyoPostBattle::
    .string "If my Pokémon were as good at\n"
    .string "karate as I…$"

ViridianCity_Gym_Text_WarrenIntro::
    .string "The truly talented win with style.$"

ViridianCity_Gym_Text_WarrenDefeat::
    .string "I lost my grip!$"

ViridianCity_Gym_Text_WarrenPostBattle::
    .string "The Leader will scold me for\n"
    .string "losing this way…$"

ViridianCity_Gym_Text_TakashiIntro::
    .string "I'm the Karate King!\n"
    .string "Your fate rests with me!$"

ViridianCity_Gym_Text_TakashiDefeat::
    .string "Ayah!$"

ViridianCity_Gym_Text_TakashiPostBattle::
    .string "The Pokémon League?\n"
    .string "You? Don't get cocky!$"

ViridianCity_Gym_Text_ColeIntro::
    .string "Your Pokémon will cower at the\n"
    .string "crack of my whip!$"

ViridianCity_Gym_Text_ColeDefeat::
    .string "Yowch!\n"
    .string "Whiplash!$"

ViridianCity_Gym_Text_ColePostBattle::
    .string "Wait!\n"
    .string "I was just careless!$"

ViridianCity_Gym_Text_SamuelIntro::
    .string "Viridian Gym was closed for a\n"
    .string "long time.\p"
    .string "Now the League's given us a Trial\n"
    .string "Captain all the way from Alola!$"

ViridianCity_Gym_Text_SamuelDefeat::
    .string "I was beaten?$"

ViridianCity_Gym_Text_SamuelPostBattle::
    .string "You can go on to the Pokémon\n"
    .string "League only by defeating our Gym\l"
    .string "Leader!$"

ViridianCity_Gym_Text_GymGuyAdvice::
    .string "Yo!\n"
    .string "Champ in the making!\p"
    .string "This Gym sat empty for years, and\n"
    .string "then the League up and handed it\l"
    .string "to a painter from Alola.\p"
    .string "Don't let that fool you.\n"
    .string "She's the toughest of the eight.\p"
    .string "Word is she uses nothing but\n"
    .string "Fairy-type Pokémon.\p"
    .string "Steel and Poison, kid!$"

ViridianCity_Gym_Text_GymGuyPostVictory::
    .string "You beat her?!\p"
    .string "And she only took the job because\n"
    .string "she missed her boat!$"

ViridianCity_Gym_Text_GymStatue::
    .string "Viridian Pokémon Gym\n"
    .string "Leader: Mina\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}$"

ViridianCity_Gym_Text_GymStatuePlayerWon::
    .string "Viridian Pokémon Gym\n"
    .string "Leader: Mina\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}, {PLAYER}$"

ViridianCity_Gym_Text_MinaIntro::
    .string "Alola, alola!\p"
    .string "Oh! You're the challenger?\n"
    .string "Sorry. I kinda lost track of time.\p"
    .string "See, I was down at Vermilion Port\n"
    .string "sketching the ocean view, and I got\l"
    .string "so caught up in it that I guess I\l"
    .string "missed my ship back to Alola.\p"
    .string "Aww… Well, shoot.\p"
    .string "But then the League came around\n"
    .string "asking if anybody could fill in for\l"
    .string "their eighth Gym Leader.\p"
    .string "Happy accident, I guess!\p"
    .string "So how about it, Kantonian Trainer?\p"
    .string "Heh heh heh… Then here I go!\p"
    .string "You're going to learn how great\n"
    .string "Fairy-type Pokémon can be!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

ViridianCity_Gym_Text_MinaDefeat::
    .string "Whoa!\n"
    .string "I'm shocked at your strength!$"

ViridianCity_Gym_Text_MinaPostBattle::
    .string "I can't go back to Alola until I\n"
    .string "beat you. Heh. Just kidding.\p"
    .string "Go on. The League's waiting.\n"
    .string "I'll be here, sketching.$"
