Route19_Frlg_MapScripts::
	.byte 0


Route19_EventScript_PlainInsane::
    lockall
    faceplayer
    msgbox gText_plaininsane_1
    goto_if_not_defeated TRAINER_SWIMMER_MALE_REECE, Route19_EventScript_PlainInsaneNotReady
	goto_if_not_defeated TRAINER_SWIMMER_MALE_RICHARD, Route19_EventScript_PlainInsaneNotReady
	goto_if_not_defeated TRAINER_SWIMMER_MALE_TONY, Route19_EventScript_PlainInsaneNotReady
	goto_if_not_defeated TRAINER_SWIMMER_MALE_DOUGLAS, Route19_EventScript_PlainInsaneNotReady
	goto_if_not_defeated TRAINER_SIS_AND_BRO_LIA_LUC, Route19_EventScript_PlainInsaneNotReady
	goto_if_not_defeated TRAINER_SWIMMER_MALE_MATTHEW, Route19_EventScript_PlainInsaneNotReady
	goto_if_not_defeated TRAINER_SWIMMER_MALE_AXLE, Route19_EventScript_PlainInsaneNotReady
	goto_if_not_defeated TRAINER_SWIMMER_FEMALE_CONNIE, Route19_EventScript_PlainInsaneNotReady
	goto_if_not_defeated TRAINER_SWIMMER_FEMALE_ALICE, Route19_EventScript_PlainInsaneNotReady
    msgbox gText_plaininsane_askChallenge, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, 1, EventScript_PlainInsane_Battle
    msgbox gText_plaininsane_Reject
    releaseall
    end

Route19_EventScript_PlainInsaneNotReady::
    msgbox gText_PlainInsane_NotReady 
    releaseall
    end

EventScript_PlainInsane_Battle::
    msgbox gText_plaininsane_2
    trainerbattle_no_intro TRAINER_PLAININSANE, plaininsane_Text_Defeat  
    setflag FLAG_DEFEATED_PLAININSANE          
    msgbox gText_plaininsane_3
    giveitem ITEM_STARMINITE
    giveitem ITEM_ASSAULT_VEST
    msgbox gText_plaininsane_4
    fadescreenswapbuffers FADE_TO_BLACK                
    playse SE_EXIT                            
    waitse                                  
    removeobject LOCALID_ROUTE19_PLAINSANE             
    fadescreenswapbuffers FADE_FROM_BLACK              
    releaseall
    end

Route19_EventScript_RouteSign::
	msgbox Route19_Text_RouteSign, MSGBOX_SIGN
	end

Route19_Text_RichardIntro::
    .string "I have to exercise and warm up\n"
    .string "before going out for a swim.$"

Route19_Text_RichardDefeat::
    .string "All warmed up!$"

Route19_Text_RichardPostBattle::
    .string "Thanks, kid!\n"
    .string "I'm ready for a swim.$"

Route19_Text_ReeceIntro::
    .string "Wait! Slow down!\n"
    .string "You'll have a heart attack!$"

Route19_Text_ReeceDefeat::
    .string "Ooh!\n"
    .string "That's chilly!$"

Route19_Text_ReecePostBattle::
    .string "Watch out for TENTACOOL.\n"
    .string "They sting so painfully.$"

Route19_Text_MatthewIntro::
    .string "I love swimming!\n"
    .string "What about you?$"

Route19_Text_MatthewDefeat::
    .string "Belly flop!$"

Route19_Text_MatthewPostBattle::
    .string "I can beat even marine Pokémon\n"
    .string "at swimming.$"

Route19_Text_DouglasIntro::
    .string "What's beyond the horizon?$"

Route19_Text_DouglasDefeat::
    .string "Glub!$"

Route19_Text_DouglasPostBattle::
    .string "I see a couple of islands over\n"
    .string "yonder!$"

Route19_Text_DavidIntro::
    .string "I tried diving for Pokémon, but it\n"
    .string "was a no-go.$"

Route19_Text_DavidDefeat::
    .string "Help!$"

Route19_Text_DavidPostBattle::
    .string "I guess you have to fish for sea\n"
    .string "Pokémon.$"

Route19_Text_TonyIntro::
    .string "I look at the sea to forget all\n"
    .string "the bad things that happened.$"

Route19_Text_TonyDefeat::
    .string "Ooh!\n"
    .string "Traumatic!$"

Route19_Text_TonyPostBattle::
    .string "I'm looking at the sea to forget\n"
    .string "the bad thing that happened!$"

Route19_Text_AnyaIntro::
    .string "Oh, I just love your ride!\n"
    .string "Can I have it if I win?$"

Route19_Text_AnyaDefeat::
    .string "Oh! I lost!$"

Route19_Text_AnyaPostBattle::
    .string "It's still a long way to go to\n"
    .string "Seafoam Islands…\p"
    .string "I want to go back to FUCHSIA…$"

Route19_Text_AliceIntro::
    .string "Swimming's great!\n"
    .string "Sunburns aren't!$"

Route19_Text_AliceDefeat::
    .string "Shocker!$"

Route19_Text_AlicePostBattle::
    .string "My boyfriend wanted to swim to\n"
    .string "Seafoam Islands.$"

Route19_Text_AxleIntro::
    .string "Ahoy, there!\n"
    .string "These waters are treacherous!$"

Route19_Text_AxleDefeat::
    .string "Ooh!\n"
    .string "Dangerous!$"

Route19_Text_AxlePostBattle::
    .string "M-my legs! They cramped up!\n"
    .string "Glub, glub…$"

Route19_Text_ConnieIntro::
    .string "I swam here with my friends…\n"
    .string "I'm tired…$"

Route19_Text_ConnieDefeat::
    .string "I'm exhausted…$"

Route19_Text_ConniePostBattle::
    .string "If I were to ride a Pokémon on\n"
    .string "the sea, I'd like a LAPRAS.\p"
    .string "LAPRAS is so big, I bet it\n"
    .string "would keep me dry on water.$"

Route19_Text_RouteSign::
    .string "SEA ROUTE 19\n"
    .string "Fuchsia City - SEAFOAM ISLANDS$"

Route19_Text_LiaIntro::
    .string "I'm looking after my brother.\n"
    .string "He just became a TRAINER.$"

Route19_Text_LiaDefeat::
    .string "That's no way to treat my\n"
    .string "little brother!$"

Route19_Text_LiaPostBattle::
    .string "Do you have a younger\n"
    .string "brother?\p"
    .string "I hope you're teaching him all\n"
    .string "sorts of things.$"

Route19_Text_LiaNotEnoughMons::
    .string "I want to battle together\n"
    .string "with my little brother.\p"
    .string "Don't you have two Pokémon?$"

Route19_Text_LucIntro::
    .string "My big sis taught me how\n"
    .string "to swim and train Pokémon.$"

Route19_Text_LucDefeat::
    .string "Oh, wow!\n"
    .string "Someone tougher than my big sis!$"

Route19_Text_LucPostBattle::
    .string "My big sis is strong and nice.\n"
    .string "I think she's awesome!$"

Route19_Text_LucNotEnoughMons::
    .string "I don't want to if I can't\n"
    .string "battle you with my big sis.\p"
    .string "Don't you have two Pokémon?$"


gText_plaininsane_1::
  .string "Hello there.$"


gText_plaininsane_askChallenge::
  .string "Are you ready for a surprise?$"

gText_plaininsane_2::
    .string "Surprise!\n"
    .string "I'll show you how to battle with\l"
    .string "an all out ASSAULT!$"

gText_plaininsane_Reject::
  .string "Ah, well…$"

plaininsane_Text_Defeat::
  .string "Hmm, that checks out.$"

gText_plaininsane_3::
  .string "Well done! I knew you looked\n"
  .string "like a MEGA STAR! Take these!$"

gText_plaininsane_4::
  .string "Make sure to use those gifts you\n"
  .string "earned! You'll need them in the\l"
  .string "Elite 4!\p"
  .string "Anyway, I'll be off to try and\n"
  .string "surprise more trainers!$"

gText_PlainInsane_NotReady::
    .string "Defeat the trainers in this area and\n"
    .string "I'll give you surprise!$"
