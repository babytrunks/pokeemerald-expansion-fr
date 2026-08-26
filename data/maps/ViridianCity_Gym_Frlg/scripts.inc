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

ViridianCity_Gym_EventScript_Daphne::
	trainerbattle_single TRAINER_AROMA_LADY_DAPHNE, ViridianCity_Gym_Text_DaphneIntro, ViridianCity_Gym_Text_DaphneDefeat
	msgbox ViridianCity_Gym_Text_DaphnePostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Vera::
	trainerbattle_single TRAINER_PAINTER_VERA, ViridianCity_Gym_Text_VeraIntro, ViridianCity_Gym_Text_VeraDefeat
	msgbox ViridianCity_Gym_Text_VeraPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Kiyo::
	trainerbattle_single TRAINER_BLACK_BELT_KIYO, ViridianCity_Gym_Text_KiyoIntro, ViridianCity_Gym_Text_KiyoDefeat
	msgbox ViridianCity_Gym_Text_KiyoPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Sienna::
	trainerbattle_single TRAINER_PAINTER_SIENNA, ViridianCity_Gym_Text_SiennaIntro, ViridianCity_Gym_Text_SiennaDefeat
	msgbox ViridianCity_Gym_Text_SiennaPostBattle, MSGBOX_AUTOCLOSE
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

ViridianCity_Gym_Text_VeraIntro::
    .string "I paint whatever I'm feeling!\n"
    .string "Right now I'm feeling victory!$"

ViridianCity_Gym_Text_VeraDefeat::
    .string "My palette!$"

ViridianCity_Gym_Text_VeraPostBattle::
    .string "Mina's hand never shakes.\n"
    .string "Mine still does.$"

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

ViridianCity_Gym_Text_SiennaIntro::
    .string "I sketch everyone who walks in\n"
    .string "through that door.\p"
    .string "Hold still. This won't take long!$"

ViridianCity_Gym_Text_SiennaDefeat::
    .string "Ah! Smudged it!$"

ViridianCity_Gym_Text_SiennaPostBattle::
    .string "You move too quickly.\n"
    .string "I couldn't get a single line down!$"

ViridianCity_Gym_Text_DaphneIntro::
    .string "Can you smell the flowers?\p"
    .string "Then you're already standing\n"
    .string "much too close to me!$"

ViridianCity_Gym_Text_DaphneDefeat::
    .string "Oh, dear.\n"
    .string "Wilted…$"

ViridianCity_Gym_Text_DaphnePostBattle::
    .string "Go on up.\p"
    .string "The Leader has been waiting to\n"
    .string "sketch you.$"

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
