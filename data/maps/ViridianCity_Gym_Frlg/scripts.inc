ViridianCity_Gym_Frlg_MapScripts::
	.byte 0

ViridianCity_Gym_EventScript_Clair::
	trainerbattle_single TRAINER_LEADER_CLAIR, Text_claire_EncounterText, ViridianCity_Gym_Text_ClairDefeat, ViridianCity_Gym_EventScript_DefeatedClair, NO_MUSIC
	msgbox ViridianCity_Gym_Text_ExplainItems
	closemessage
	release
	end

ViridianCity_Gym_EventScript_DefeatedClair::
	setflag FLAG_HIDE_MISC_KANTO_ROCKETS
	setflag FLAG_DEFEATED_LEADER_GIOVANNI
	setflag FLAG_BADGE08_GET
	setvar VAR_MAP_SCENE_ROUTE22, 3
	set_gym_trainers_frlg 8
	goto ViridianCity_Gym_EventScript_GiveTM90
	end

ViridianCity_Gym_EventScript_GiveTM90::
    callnative SetBuffer1ToLevelCap
	msgbox ViridianCity_Gym_Text_ExplainRisingBadgeTakeThis
    giveitem ITEM_DRAGONINITE
    giveitem ITEM_TM_DRACO_METEOR
	msgbox ViridianCity_Gym_Text_ExplainItems
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
	goto_if_set FLAG_DEFEATED_LEADER_GIOVANNI, ViridianCity_Gym_EventScript_GymGuyPostVictory
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

ViridianCity_Gym_Text_GiovanniIntro::
    .string "Fwahahaha!\n"
    .string "Welcome to my hideout!\p"
    .string "It shall be so until I can restore\n"
    .string "Team Rocket to its former glory.\p"
    .string "But, you have found me again.\n"
    .string "So be it.\l"
    .string "This time, I'm not holding back!\p"
    .string "Once more, you shall face\n"
    .string "Giovanni, the greatest Trainer!{PLAY_BGM}{MUS_RG_ENCOUNTER_ROCKET}$"

ViridianCity_Gym_Text_GiovanniDefeat::
    .string "Ha!\n"
    .string "That was a truly intense fight.\l"
    .string "You have won!\p"
    .string "As proof, here is the EarthBadge!\n"
    .string "{PAUSE_MUSIC}{PLAY_BGM}{MUS_OBTAIN_BADGE}{PAUSE 0xFE}{PAUSE 0xFE}{PAUSE 0xFE}{RESUME_MUSIC}$"

ViridianCity_Gym_Text_ExplainRisingBadgeTakeThis::
    .string "The Rising Badge raises your Level\n"
    .string "Cap to {STR_VAR_1}.\p"
    .string "With it, you can challenge the\n"
    .string "Pokémon League.\p"
    .string "Also, take these.\p"
    .string "Consider it gifts for your Pokémon\n"
    .string "League challenge.$"


ViridianCity_Gym_Text_ExplainItems::
    .string "TM90 contains Draco Meteor.\p"
    .string "It is a powerful attack that rains\n"
    .string "comets on the foe.\p"
    .string "However, it lowers Special Attack,\n"
    .string "so be wary when using it.\p"
    .string "Mega Dragonite obtains No Guard\n"
    .string "when its base form has Inner Focus.\p"
    .string "It allows it to use inaccurate moves\n"
    .string "like Hurricane without fear.$"

ViridianCity_Gym_Text_YouDoNotHaveSpace::
    .string "You do not have space for this!$"

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
    .string "Do you know the identity of our\n"
    .string "Gym Leader?$"

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
    .string "But now, our Leader is back!$"

ViridianCity_Gym_Text_SamuelDefeat::
    .string "I was beaten?$"

ViridianCity_Gym_Text_SamuelPostBattle::
    .string "You can go on to the Pokémon\n"
    .string "League only by defeating our Gym\l"
    .string "Leader!$"

ViridianCity_Gym_Text_GymGuyAdvice::
    .string "Yo!\n"
    .string "Champ in the making!\p"
    .string "Even I don't know the Viridian\n"
    .string "Leader's identity.\p"
    .string "But one thing's certain.\n"
    .string "This will be the toughest of all\l"
    .string "the Gym Leaders.\p"
    .string "Also, I heard that the Trainers\n"
    .string "here like Ground-type Pokémon.$"

ViridianCity_Gym_Text_GymGuyPostVictory::
    .string "Blow me away! Giovanni was the\n"
    .string "Gym Leader of Viridian?$"

ViridianCity_Gym_Text_GymStatue::
    .string "Viridian Pokémon Gym\n"
    .string "Leader: ?\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}$"

ViridianCity_Gym_Text_GymStatuePlayerWon::
    .string "Viridian Pokémon Gym\n"
    .string "Leader: Giovanni\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}, {PLAYER}$"

Text_claire_EncounterText::
    .string "Ah, a challenger finally arrives.\p"
    .string "Although I'm a newly appointed\n"
    .string "Gym Leader in the Kanto region,\l"
    .string "I was once a leader in Johto.\p"
    .string "So, this is nothing new to me.\p"
    .string "Lance may be considered the world's\n"
    .string "number one dragon master,\l"
    .string "but I'm a close second!\p"
    .string "I will use my full power against\n"
    .string "any opponent!$"

ViridianCity_Gym_Text_ClairDefeat::
    .string "Alright. I recognize your power.\n"
    .string "The badge is yours.$"
