Route25_Frlg_MapScripts::
	.byte 0

Route25_EventScript_SeaCottageSign::
	msgbox Route25_Text_SeaCottageSign, MSGBOX_SIGN
	end

Route25_EventScript_Man::
	msgbox Route25_Text_AreYouHereAlone, MSGBOX_NPC
	end

Route25_EventScript_Bugsy::
    lockall
    @ checkflag 0x10C2                          @ ??? some prior-save / tutorial flag
    @ call_if_eq VAR_RESULT, 0, SaveGame        @ if 0x0 _call SaveGame
    setspeaker SP_NAME_UNKNOWN
    msgbox gText_bugsy_1      @ 0x4
    applymovement LOCALID_BUGSY, Movement_Bugsy_Look
    waitmovement 0
    setspeaker SP_NAME_BUGSY
    msgbox gText_bugsy_2
    setspeaker SP_NAME_BUGSY
    msgbox gText_bugsy_3, MSGBOX_YESNO        @ 0x5 -> yes/no box; sets VAR_RESULT
    goto_if_eq VAR_RESULT, 1, EventScript_Bugsy_Battle
    setspeaker SP_NAME_BUGSY
    msgbox gText_bugsy_4, MSGBOX_DEFAULT
    release
    end


EventScript_Bugsy_Battle::        
    setspeaker SP_NAME_BUGSY      
    msgbox gText_bugsy_5, MSGBOX_DEFAULT
    special HealPlayerParty                               
    goto CheckBadges                          


NormalBugsy:
    trainerbattle_no_intro TRAINER_BUGSY, gText_bugsy_Defeat  
    goto PostBugsy


PostBugsy:
    setweather 0x0                           
    doweather
    setspeaker SP_NAME_BUGSY
    msgbox gText_bugsy_6, MSGBOX_DEFAULT
    setflag FLAG_RARE_POKEMON_SCREEN
	setflag FLAG_3_PERFECT_IVS 
    setvar VAR_RARE_POKEMON_COUNTER, 2
    factory_generaterentalmons
	factory_rentmons
	waitstate
	clearflag FLAG_RARE_POKEMON_SCREEN
	clearflag FLAG_3_PERFECT_IVS
    setspeaker SP_NAME_BUGSY
    msgbox gText_bugsy_6_1
    giveitem ITEM_TM_U_TURN
    msgbox gText_bugsy_7, MSGBOX_DEFAULT
    fadescreen FADE_TO_BLACK
    removeobject LOCALID_BUGSY                
    playse SE_PIN                                @ ??? map to proper SE_* constant
    waitse
    fadescreen FADE_FROM_BLACK
    setflag FLAG_DEFEATED_BUGSY                           
    setweather 0x3                            
    doweather

    release
    end


CheckBadges:
    goto_if_unset FLAG_BADGE03_GET, NormalBugsy
    trainerbattle_no_intro TRAINER_BUGSY_POST_SURGE, gText_bugsy_Defeat  
    goto PostBugsy

Movement_Bugsy_Look:
    face_player                       
    step_end

Route25_Text_JoeyIntro::
    .string "Local TRAINERS come here to\n"
    .string "practice.$"

Route25_Text_JoeyDefeat::
    .string "You're decent.$"

Route25_Text_JoeyPostBattle::
    .string "All Pokémon have weaknesses.\n"
    .string "Even the strongest ones.\p"
    .string "That's why it's best to raise\n"
    .string "Pokémon of different types.$"

Route25_Text_DanIntro::
    .string "Dad took me to a great party on\n"
    .string "the S.S. ANNE at VERMILION CITY.$"

Route25_Text_DanDefeat::
    .string "I'm not mad!$"

Route25_Text_DanPostBattle::
    .string "On the S.S. ANNE, I saw TRAINERS\n"
    .string "from around the world.$"

Route25_Text_FlintIntro::
    .string "I'm a cool guy.\n"
    .string "I've got a girlfriend!$"

Route25_Text_FlintDefeat::
    .string "Aww, darn…$"

Route25_Text_FlintPostBattle::
    .string "Oh, well.\n"
    .string "My girlfriend will cheer me up.$"

Route25_Text_KelseyIntro::
    .string "Hi!\n"
    .string "My boyfriend is cool!$"

Route25_Text_KelseyDefeat::
    .string "My conditioning isn't the best…$"

Route25_Text_KelseyPostBattle::
    .string "I wish my boyfriend was as good\n"
    .string "as you.$"

Route25_Text_ChadIntro::
    .string "I had this feeling…\n"
    .string "I knew I had to battle you!$"

Route25_Text_ChadDefeat::
    .string "I knew I'd lose, too!$"

Route25_Text_ChadPostBattle::
    .string "If your Pokémon gets confused,\n"
    .string "switch it out.\p"
    .string "That's a good tactic.$"

Route25_Text_HaleyIntro::
    .string "My friend has many cute Pokémon.\n"
    .string "I'm so jealous!$"

Route25_Text_HaleyDefeat::
    .string "I'm not so jealous!$"

Route25_Text_HaleyPostBattle::
    .string "You came from MT. MOON?\n"
    .string "May I have a CLEFAIRY?$"

Route25_Text_FranklinIntro::
    .string "I just got down from MT. MOON,\n"
    .string "but I've still got gas in the tank!$"

Route25_Text_FranklinDefeat::
    .string "You worked hard!$"

Route25_Text_FranklinPostBattle::
    .string "Drat!\n"
    .string "A ZUBAT bit me back in that cave.$"

Route25_Text_NobIntro::
    .string "I'm off to see a POKéMANIAC's\n"
    .string "collection at the cape.$"

Route25_Text_NobDefeat::
    .string "You done got me, and real good,\n"
    .string "too!$"

Route25_Text_NobPostBattle::
    .string "The POKéMANIAC sure lives up to\n"
    .string "his name.\p"
    .string "His collection includes many rare\n"
    .string "species of Pokémon.$"

Route25_Text_WayneIntro::
    .string "You're going to see BILL?\n"
    .string "First, we battle!$"

Route25_Text_WayneDefeat::
    .string "You're something.$"

Route25_Text_WaynePostBattle::
    .string "The trail below is a shortcut to\n"
    .string "CERULEAN CITY.$"

Route25_Text_SeaCottageSign::
    .string "SEA COTTAGE\n"
    .string "BILL lives here!$"

Route25_Text_MistyHighHopesAboutThisPlace::
    .string "This cape is a famous date spot.\p"
    .string "MISTY, the GYM LEADER, has high\n"
    .string "hopes about this place.$"

Route25_Text_AreYouHereAlone::
    .string "Hello, are you here alone?\p"
    .string "If you're out at CERULEAN's cape…\n"
    .string "Well, it should be as a couple.$"

gText_bugsy_1::
  .string "{COLOR BLUE}I better keep my ass in this rainy\n"
  .string "weather!!! or im FINISHED!!$"


gText_bugsy_2::
  .string "{COLOR BLUE}Oh, didn't see you there. I hope you\n"
  .string "can disregard what I just said…\p"
  .string "The name's Bugsy.\p"
  .string "…Oh? You've met my colleague\n"
  .string "Falkner too?\p"
  .string "Yeah, the Johto gym leaders decided\n"
  .string "to pay Kanto a visit, as there have\l"
  .string "been talks of a lot of new cutting-\l"
  .string "edge technology being researched here.$"


gText_bugsy_3::
  .string "{COLOR BLUE}Well, since you're here, I'm assuming\n"
  .string "you want a battle?$"


gText_bugsy_4::
  .string "{COLOR BLUE}Suit yourself. I'll be here in case\n"
  .string "you change your mind.$"


gText_bugsy_5::
  .string "{COLOR BLUE}Don't consider me weak just because I\n"
  .string "use Bug types, I'll show you how\l"
  .string "fearsome they can be!$"


gText_bugsy_Defeat::
  .string "Gah… It's just not cutting it!$"

gText_bugsy_6::
  .string "{COLOR BLUE}Frankly, I'm a bit disappointed in\n"
  .string "myself.\p"
  .string "I'm struggling to win even in the\n"
  .string "rain. It's hard to stay competitive\l"
  .string "specializing in Bug-types.\p"
  .string "Well, you can have a selection of\n"
  .string "a rare Bug-type. Maybe you'll go fur-\l"
  .string "ther with them than me.$"

gText_bugsy_6_1::
  .string "{COLOR BLUE}Here, have my favorite TM too.$"

gText_bugsy_7::
  .string "{COLOR BLUE}Anywho, it's nice meeting you, but I'll\n"
  .string "be taking my leave.$"
