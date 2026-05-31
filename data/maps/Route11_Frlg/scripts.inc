Route11_Frlg_MapScripts::
	.byte 0


Route11_EventScript_Whitney::
    lockall
    setspeaker SP_NAME_WHITNEY
    msgbox gText_whitney_1
    applymovement LOCALID_WHITNEY, Movement_Whitney_Look
    waitmovement 0
    setspeaker SP_NAME_WHITNEY
    msgbox gText_whitney_2
	goto_if_not_defeated TRAINER_GAMER_DARIAN, Route11_EventScript_WhitneyNotReady
	goto_if_not_defeated TRAINER_YOUNGSTER_YASU, Route11_EventScript_WhitneyNotReady
	goto_if_not_defeated TRAINER_ENGINEER_BRAXTON, Route11_EventScript_WhitneyNotReady
	goto_if_not_defeated TRAINER_GAMER_JASPER, Route11_EventScript_WhitneyNotReady
	goto_if_not_defeated TRAINER_ENGINEER_BERNIE, Route11_EventScript_WhitneyNotReady
	goto_if_not_defeated TRAINER_YOUNGSTER_EDDIE, Route11_EventScript_WhitneyNotReady
	goto_if_not_defeated TRAINER_GAMER_HUGO, Route11_EventScript_WhitneyNotReady
    setspeaker SP_NAME_WHITNEY
    msgbox gText_whitney_3, MSGBOX_YESNO     @ player choice; sets VAR_RESULT
    goto_if_eq VAR_RESULT, 1, EventScript_Whitney_Battle
    setspeaker SP_NAME_WHITNEY
    msgbox gText_whitney_4
    release
    end

Route11_EventScript_Whitney_NotReady:
    setspeaker SP_NAME_WHITNEY
    msgbox gText_whitney_2_1
    return

Route11_EventScript_WhitneyNotReady:

EventScript_Whitney_Battle::
    setspeaker SP_NAME_WHITNEY
    msgbox gText_whitney_5
    @ special HealPlayerParty                  @ special 0x0
    trainerbattle_no_intro TRAINER_WHITNEY, whitney_Text_Defeat   @ 0x31
    setflag FLAG_DEFEATED_WHITNEY            @ 0x933
    setspeaker SP_NAME_WHITNEY
    msgbox gText_whitney_6
    call_if_unset FLAG_UNLOCKED_STAT_EDITOR, EventScript_Whitney_StatEditExplain
    call_if_unset FLAG_DISABLE_EVS, EventScript_Whitney_StatEditTellCap
    setspeaker SP_NAME_WHITNEY
    msgbox gText_whitney_7_2
    giveitem ITEM_EVIOLITE
    setspeaker SP_NAME_WHITNEY
    msgbox gText_whitney_8
    fadescreen FADE_TO_BLACK                 @ fadescreen 0x1
    playse SE_EXIT                            @ sound 0x9
    waitse                                   @ checksound
    removeobject LOCALID_WHITNEY             @ hidesprite 0x2
    removeobject LOCALID_ROUTE11_MILTANK
    fadescreen FADE_FROM_BLACK               @ fadescreen 0x0
    release
    end

EventScript_Whitney_StatEditExplain::
    call_if_unset FLAG_DISABLE_EVS, EventScript_Whitney_StatEditExplain2
    return

EventScript_Whitney_StatEditExplain2:
    msgbox whitney_Text_StatEditor_Explain
    return

EventScript_Whitney_StatEditTellCap:
    callnative SetBuffer1ToEvCap
    msgbox johtoLeader_Text_CurrentEvCap
    setflag FLAG_UNLOCKED_STAT_EDITOR
    return

Movement_Whitney_Look:
    face_player                              @ from bytes 0x4A, 0xFE
    step_end

Route11_EventScript_DiglettsCaveSign::
	msgbox Route11_Text_DiglettsCave, MSGBOX_SIGN
	end

Route11_EventScript_Miltank::	
    lock
	faceplayer
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_NORMAL
	msgbox Route11_Text_Miltank
	waitmoncry
	release
	end

Route11_Text_Miltank::
    .string "Miltank: Moo!$"

Route11_Text_HugoIntro::
    .string "Win, lose, or draw!$"

Route11_Text_HugoDefeat::
    .string "Atcha!\n"
    .string "Didn't go my way!$"

Route11_Text_HugoPostBattle::
    .string "Pokémon is life!\n"
    .string "And to live is to play games!$"

Route11_Text_JasperIntro::
    .string "Competition!\n"
    .string "I can't get enough!$"

Route11_Text_JasperDefeat::
    .string "I had a chance!$"

Route11_Text_JasperPostBattle::
    .string "You can't be a coward in the world\n"
    .string "of Pokémon!$"

Route11_Text_EddieIntro::
    .string "Let's go, but don't cheat!$"

Route11_Text_EddieDefeat::
    .string "Huh?\n"
    .string "That's not right!$"

Route11_Text_EddiePostBattle::
    .string "I did my best.\n"
    .string "I have no regrets.$"

Route11_Text_BraxtonIntro::
    .string "Careful!\n"
    .string "I'm laying down some cables!$"

Route11_Text_BraxtonDefeat::
    .string "That was electric!$"

Route11_Text_BraxtonPostBattle::
    .string "Spread the word to save energy!$"

Route11_Text_DillonIntro::
    .string "I just became a TRAINER.\n"
    .string "But, I think I can win.$"

Route11_Text_DillonDefeat::
    .string "My Pokémon couldn't win…\n"
    .string "Haven't they grown enough?$"

Route11_Text_DillonPostBattle::
    .string "What now?\n"
    .string "Leave me alone!$"

Route11_Text_DirkIntro::
    .string "Fwahaha!\n"
    .string "I have never lost!$"

Route11_Text_DirkDefeat::
    .string "My first loss!$"

Route11_Text_DirkPostBattle::
    .string "You were just lucky, that's all.$"

Route11_Text_DarianIntro::
    .string "I have never won before…$"

Route11_Text_DarianDefeat::
    .string "I saw this coming…$"

Route11_Text_DarianPostBattle::
    .string "I was unlucky, as always.$"

Route11_Text_YasuIntro::
    .string "I'm the best in my class.\n"
    .string "I train every morning.$"

Route11_Text_YasuDefeat::
    .string "Darn!\n"
    .string "My Pokémon need to be stronger!$"

Route11_Text_YasuPostBattle::
    .string "There's a fat Pokémon that comes\n"
    .string "down from the mountains.\p"
    .string "I bet it'd be strong if you can\n"
    .string "catch it.$"

Route11_Text_BernieIntro::
    .string "Watch out for live wires!$"

Route11_Text_BernieDefeat::
    .string "Whoa!\n"
    .string "You spark plug!$"

Route11_Text_BerniePostBattle::
    .string "Well, better get back to work.$"

Route11_Text_DaveIntro::
    .string "I raised my Pokémon carefully.\n"
    .string "They should be ready by now!$"

Route11_Text_DaveDefeat::
    .string "Bye-bye!\n"
    .string "Thank you, and good-bye!$"

Route11_Text_DavePostBattle::
    .string "Tch…\n"
    .string "I better go find stronger ones!$"

Route11_Text_DiglettsCave::
    .string "Diglett's Cave$"

gText_whitney_1::
  .string "{COLOR RED}Jeez, Meganium and Feraligatr got new\n"
  .string "Megas, but Miltank gets no love!\p"
  .string "Don't worry buddy, I'm sure your time\n"
  .string "to shine will come soon…$"


gText_whitney_2::
  .string "{COLOR RED}Oh… hello there.\n"
  .string "I see you're quite an experienced\l"
  .string "trainer.\p"
  .string "I'm a renowned Gym Leader from the\n"
  .string "Johto region, fearsome for my\l"
  .string "Miltank! Perhaps you've heard of me?$"

gText_whitney_2_1::
  .string "{COLOR RED}Though, if you want to face me,\n"
  .string "you'll have to beat all the trainers\l"
  .string "on this Route first.$"

gText_whitney_3::
  .string "{COLOR RED}If an intense battle is what you want,\n"
  .string "then that's what you're going to get!$"

gText_whitney_4::
  .string "{COLOR RED}Scared of Miltank, aren't ya?$"

gText_whitney_5::
  .string "{COLOR RED}I hope you don't let my cuteness lull\n"
  .string "you. You'll definitely regret it!$"

whitney_Text_Defeat::
  .string "Ah… woe is me…$"

gText_whitney_6::
  .string "{COLOR RED}In my younger days, Miltank was such\n"
  .string "a big threat. I gave trainers of all\l"
  .string "ages nightmares.\p"
  .string "Though, now with Mega Evolutions, I fear\n"
  .string "my Miltank isn't quite as threatening\l"
  .string "anymore. But, I'm determined to still\l"
  .string "make it work!\p"
  .string "Anyway, thanks for the battle.$"

whitney_Text_StatEditor_Explain::
  .string "I can raise your Effort Values cap\n"
  .string "so your team can grow even stronger.\p"
  .string "The Edit Stats option is now avail-\n"
  .string "able when viewing your Pokémon in\l"
  .string "the party menu.$"

johtoLeader_Text_CurrentEvCap::
  .string "Your current EV Cap is {STR_VAR_1}.$"

gText_whitney_7_2::
  .string "{COLOR RED} Have this as well.$"

gText_whitney_8::
  .string "{COLOR RED}Eviolite boosts the defenses of Poké-\n"
  .string "mon that can still evolve.\p"
  .string "It's great if you like using cute\n"
  .string "Pokémon!\p"
  .string "Anyway, I need to Bounce.\n"
  .string "Too many creeps on this Route.\p"
  .string "I hope we see each other soon.$"
