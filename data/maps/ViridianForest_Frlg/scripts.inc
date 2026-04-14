ViridianForest_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianForest_OnTransition
	.byte 0

ViridianForest_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VIRIDIAN_FOREST
	end

ViridianForest_EventScript_Youngster::
	msgbox ViridianForest_Text_FriendsItchingToBattle, MSGBOX_NPC
	end

ViridianForest_EventScript_Boy::
	msgbox ViridianForest_Text_RanOutOfPokeBalls, MSGBOX_NPC
	end

ViridianForest_EventScript_TrainerTips1::
	msgbox ViridianForest_Text_AvoidGrassyAreasWhenWeak, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips2::
	msgbox ViridianForest_Text_UseAntidoteForPoison, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips3::
	msgbox ViridianForest_Text_ContactOakViaPCToRatePokedex, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips4::
	msgbox ViridianForest_Text_CantCatchOwnedMons, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips5::
	msgbox ViridianForest_Text_WeakenMonsBeforeCapture, MSGBOX_SIGN
	end

ViridianForest_EventScript_ExitSign::
	msgbox ViridianForest_Text_LeavingViridianForest, MSGBOX_SIGN
	end

ViridianForest_EventScript_Rick::
	trainerbattle_single TRAINER_BUG_CATCHER_RICK, ViridianForest_Text_RickIntro, ViridianForest_Text_RickDefeat
	msgbox ViridianForest_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Doug::
	trainerbattle_single TRAINER_BUG_CATCHER_DOUG, ViridianForest_Text_DougIntro, ViridianForest_Text_DougDefeat
	msgbox ViridianForest_Text_DougPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Sammy::
	trainerbattle_single TRAINER_BUG_CATCHER_SAMMY, ViridianForest_Text_SammyIntro, ViridianForest_Text_SammyDefeat
	msgbox ViridianForest_Text_SammyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Anthony::
	trainerbattle_single TRAINER_BUG_CATCHER_ANTHONY, ViridianForest_Text_AnthonyIntro, ViridianForest_Text_AnthonyDefeat
	msgbox ViridianForest_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_BrendanOneTriggerLeft::
	lockall
	setvar VAR_TEMP_2, 1
    goto ViridianForest_EventScript_BrendanOne_Battle
    end

ViridianForest_EventScript_BrendanOneTriggerMiddle::
	lockall
	setvar VAR_TEMP_2, 2
    goto ViridianForest_EventScript_BrendanOne_Battle
    end

ViridianForest_EventScript_BrendanOneTriggerRight::
	lockall
	setvar VAR_TEMP_2, 3
    goto ViridianForest_EventScript_BrendanOne_Battle
    end

ViridianForest_EventScript_BrendanOne_Battle::
    lockall
    addobject LOCALID_VIRIDIAN_FOREST_BRENDAN 
    addobject LOCALID_VIRIDIAN_FOREST_TREECKO 
    applymovement LOCALID_VIRIDIAN_FOREST_BRENDAN, EventScript_BrendanLookingAround
    applymovement LOCALID_VIRIDIAN_FOREST_TREECKO, EventScript_TreeckoLookingAround
    waitmovement 0 
    setspeaker SP_NAME_BRENDAN
    msgbox ViridianForest_Text_BrendanLooking
    waitmessage
    playse SE_PIN 
    playbgm MUS_ENCOUNTER_BRENDAN, FALSE
    applymovement LOCALID_VIRIDIAN_FOREST_BRENDAN, Common_Movement_ExclamationMark
    applymovement LOCALID_VIRIDIAN_FOREST_BRENDAN, Common_Movement_Delay32
    waitmovement 0
    call_if_eq VAR_TEMP_2, 1, ViridianForest_EventScript_BrendanApproachLeftTile
    call_if_eq VAR_TEMP_2, 2, ViridianForest_EventScript_BrendanApproachMiddleTile
    call_if_eq VAR_TEMP_2, 3, ViridianForest_EventScript_BrendanApproachRightTile
    setspeaker SP_NAME_BRENDAN
    msgbox ViridianForest_Text_BrendanOhHello 
    trainerbattle_no_intro TRAINER_BRENDAN_1, ViridianForest_Text_Brendan1Defeat
    @ fadescreen FADE_TO_BLACK                          @ fadescreen 0x1
    applymovement LOCALID_VIRIDIAN_FOREST_TREECKO, EventScript_TreeckoEnterPokeball
    waitmovement 0
    @ removeobject LOCALID_VIRIDIAN_FOREST_TREECKO     
    @ playse 0xF                                        @ sound 0xF
    @ waitse
    @ fadescreen FADE_FROM_BLACK  
    setspeaker SP_NAME_BRENDAN
    msgbox ViridianForest_Text_PostDefeat
    giveitem ITEM_EXP_SHARE
    setflag FLAG_EXP_SHARE
    setspeaker SP_NAME_BRENDAN
    msgbox ViridianForest_Text_BrendanTeacher
    call_if_eq VAR_TEMP_2, 1, ViridianForest_EventScript_BrendanLeaveLeftTile
    call_if_eq VAR_TEMP_2, 2, ViridianForest_EventScript_BrendanLeaveLeftTile
    call_if_eq VAR_TEMP_2, 3, ViridianForest_EventScript_BrendanLeaveRightTile
    waitmovement 0
	removeobject LOCALID_VIRIDIAN_FOREST_BRENDAN
    setvar VAR_VIRIDIAN_FOREST_BRENDAN_BATTLE, 1 
    release
    end

EventScript_TreeckoEnterPokeball:
    enter_pokeball
    step_end

ViridianForest_EventScript_BrendanApproachLeftTile::
    applymovement LOCALID_VIRIDIAN_FOREST_BRENDAN, EventScript_Brendan_MoveApproachLeftTile
    applymovement LOCALID_VIRIDIAN_FOREST_TREECKO, EventScript_Treecko_MoveApproachLeftTile
    waitmovement 0
    return

ViridianForest_EventScript_BrendanApproachMiddleTile::
    applymovement LOCALID_VIRIDIAN_FOREST_BRENDAN, EventScript_Brendan_MoveApproachMiddleTile
    applymovement LOCALID_VIRIDIAN_FOREST_TREECKO, EventScript_Treecko_MoveApproachMiddleTile
    waitmovement 0
    return

ViridianForest_EventScript_BrendanApproachRightTile::
    applymovement LOCALID_VIRIDIAN_FOREST_BRENDAN, EventScript_Brendan_MoveApproachRightTile
    applymovement LOCALID_VIRIDIAN_FOREST_TREECKO, EventScript_Treecko_MoveApproachRightTile
    waitmovement 0
    return

ViridianForest_EventScript_BrendanLeaveLeftTile::
    applymovement LOCALID_VIRIDIAN_FOREST_BRENDAN, EventScript_Brendan_MoveLeaveLeftTile
    @ applymovement LOCALID_VIRIDIAN_FOREST_TREECKO, EventScript_Treecko_MoveLeaveLeftTile
    return

ViridianForest_EventScript_BrendanLeaveRightTile::
    applymovement LOCALID_VIRIDIAN_FOREST_BRENDAN, EventScript_Brendan_MoveLeaveRightTile
    @ applymovement LOCALID_VIRIDIAN_FOREST_TREECKO, EventScript_Treecko_MoveLeaveRightTile
    return

EventScript_BrendanLookingAround::
    walk_down
    walk_down
    walk_right
    walk_left
    walk_left
    walk_right
    step_end

EventScript_TreeckoLookingAround::
    walk_down
    walk_down
    walk_down
    walk_right
    walk_left
    walk_left
    step_end

EventScript_Brendan_MoveApproachLeftTile::
    walk_down
    walk_down
    walk_down
    walk_left
    face_down
    step_end

EventScript_Brendan_MoveApproachMiddleTile::
    walk_down
    walk_down
    walk_down
    step_end

EventScript_Brendan_MoveApproachRightTile::
    walk_down
    walk_down
    walk_down
    walk_right
    face_down
    step_end

EventScript_Treecko_MoveApproachLeftTile::
    walk_right
    walk_down
    walk_down
    walk_down
    step_end

EventScript_Treecko_MoveApproachMiddleTile::
    walk_right
    walk_down
    walk_down
    step_end

EventScript_Treecko_MoveApproachRightTile::
    walk_right
    walk_down
    walk_down
    walk_down
    step_end

EventScript_Brendan_MoveLeaveLeftTile::
    walk_right
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end

EventScript_Brendan_MoveLeaveRightTile::
    walk_left
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end

EventScript_Treecko_MoveLeaveLeftTile::
    walk_left
    walk_right
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end

EventScript_Treecko_MoveLeaveRightTile::
    walk_right
    walk_left
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end

EventScript_Viridian_LassRepelGirl::
    lockall
    faceplayer
    playbgm MUS_RG_ENCOUNTER_GIRL, 0
    setspeaker SP_NAME_ANNE
    msgbox LassRepelEncounter_Text
    @ setflag FLAG_DONT_RANDOMIZE

    @ trainerbattle3 0x3 0x04 0x0 gText_LassRepelDefeat
    @ Guessing this is a simple no-intro trainer battle.
    trainerbattle_no_intro TRAINER_LASS_ANNE, LassRepelDefeat_Text   @ ??? 0x04
    setspeaker SP_NAME_ANNE
    msgbox Viridian_Text_LassRepel1   
    setspeaker SP_NAME_ANNE
    msgbox Viridian_Text_LassRepel1_2   
    giveitem ITEM_INFINITE_REPEL
    setspeaker SP_NAME_ANNE
    msgbox Viridian_Text_LassRepel3  
    @ fadescreen FADE_TO_BLACK                          @ fadescreen 0x1
    applymovement LOCALID_VIRIDIAN_LASS_REPEL_GIRL, Movement_Viridian_LassRepelLeave
    waitmovement 0
    removeobject LOCALID_VIRIDIAN_LASS_REPEL_GIRL      @ ??? 0x16; use proper local id
    setflag FLAG_INF_REPEL_GIRL
    @ playse SE_EXIT                                        @ sound 0xF
    @ waitse                                            @ checksound
    @ fadescreen FADE_FROM_BLACK                        @ fadescreen 0x0
    release
    end

Movement_Viridian_LassRepelLeave:
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end

ViridianForest_Text_FriendsItchingToBattle::
    .string "I came here with some friends to\n"
    .string "catch us some BUG Pokémon!\p"
    .string "They're all itching to get into\n"
    .string "some Pokémon battles!$"

ViridianForest_Text_RickIntro::
    .string "Hey! You have Pokémon!\n"
    .string "Come on!\l"
    .string "Let's battle 'em!$"

ViridianForest_Text_RickDefeat::
    .string "No!\nCATERPIE can't hack it!$"

ViridianForest_Text_RickPostBattle::
    .string "Ssh! You'll scare the bugs away.\n"
    .string "Another time, okay?$"

ViridianForest_Text_DougIntro::
    .string "Yo!\n"
    .string "You can't jam out if you're a\l"
    .string "Pokémon TRAINER!$"

ViridianForest_Text_DougDefeat::
    .string "Huh?\n"
    .string "I ran out of Pokémon!$"

ViridianForest_Text_DougPostBattle::
    .string "That totally stinks! I'm going to\n"
    .string "catch some stronger ones!$"

ViridianForest_Text_SammyIntro::
    .string "Hey, wait up!\n"
    .string "What's the hurry? Why the rush?$"

ViridianForest_Text_SammyDefeat::
    .string "I give!\n"
    .string "You're good at this!$"

ViridianForest_Text_SammyPostBattle::
    .string "Sometimes, you can find stuff on\n"
    .string "the ground.\p"
    .string "I'm looking for the stuff I\n"
    .string "dropped. Can you help me?$"

ViridianForest_Text_AnthonyIntro::
    .string "I might be little, but I won't like\n"
    .string "it if you go easy on me!$"

ViridianForest_Text_AnthonyDefeat::
    .string "Oh, boo.\n"
    .string "Nothing went right.$"

ViridianForest_Text_AnthonyPostBattle::
    .string "I lost some of my allowance…$"

ViridianForest_Text_RanOutOfPokeBalls::
    .string "I was throwing Poké Balls to\n"
    .string "catch Pokémon, and I ran out.\p"
    .string "That's why you can never have too\n"
    .string "many Poké Balls.$"

ViridianForest_Text_AvoidGrassyAreasWhenWeak::
    .string "Trainer Tips\p"
    .string "If your Pokémon are weak and you\n"
    .string "want to avoid battles, stay away\l"
    .string "from grassy areas!$"

ViridianForest_Text_Brendan1Defeat::
    .string "So it goes…$"

ViridianForest_Text_UseAntidoteForPoison::
    .string "For poison, use ANTIDOTE!\n"
    .string "Get it at Pokémon MARTS!$"

ViridianForest_Text_ContactOakViaPCToRatePokedex::
    .string "Trainer Tips\p"
    .string "Contact Prof. Oak via a PC to\n"
    .string "get your Pokédex evaluated!$"

ViridianForest_Text_CantCatchOwnedMons::
    .string "Trainer Tips\p"
    .string "You can't catch a Pokémon that\n"
    .string "belongs to someone else.\p"
    .string "Throw Poké Balls only at wild\n"
    .string "Pokémon to catch them!$"

ViridianForest_Text_WeakenMonsBeforeCapture::
    .string "Trainer Tips\p"
    .string "Weaken Pokémon before attempting\n"
    .string "capture!\p"
    .string "When healthy, they may escape!$"

ViridianForest_Text_LeavingViridianForest::
    .string "Leaving Viridian Forest\n"
    .string "Pewter City Ahead$"

ViridianForest_Text_BrendanLooking::
  .string "{COLOR BLUE}Hm… I wonder if there are Surskit\n"
  .string "somewhere here…{PAUSE 15}$"

  
ViridianForest_Text_BrendanOhHello::
  .string "{COLOR BLUE}Oh hello!\p"
  .string "I'm just trying to catch some Poké-\n"
  .string "mon before I challenge Brock.\p"
  .string "…Oh? You're looking to challenge him\n"
  .string "as well?\p"
  .string "Why don't we have a battle then?$"

ViridianForest_Text_PostDefeat::
  .string "{COLOR BLUE}I haven't had a loss like that in\n"
  .string "a while! But, that was rather fun.\p"
  .string "…{PLAYER}, {COLOR BLUE}huh…\p"
  .string "Here, I have an extra of these,\n"
  .string "they'll surely help you.$"

ViridianForest_Text_BrendanTeacher::
  .string "{COLOR BLUE}Anyway, I'm heading to Viridian to\n"
  .string "check out the trainer school.\p"
  .string "I heard the teacher has some rare\n"
  .string "Pokémon.\p"
  .string "You should check it out if you\n"
  .string "haven't already!\p"
  .string "Well, until we meet again,\n"
  .string "{PLAYER}!$"

LassRepelEncounter_Text::
  .string "{COLOR RED}Eek, I hate bugs!$"


LassRepelDefeat_Text::
  .string "Picked a fight with the wrong trainer…$"


Viridian_Text_LassRepel1::
  .string "{COLOR RED}Sorry for being rude!\n"
  .string "I'm on edge…\p"
  .string "Using the new Infinite Repel{COLOR RED}\n"
  .string "I got from my father, I'm able to avoid\l"
  .string "these pesky insects…\p"
  .string "But I'm still a bit startled.$"

Viridian_Text_LassRepel1_2::
  .string "{COLOR RED}…Ah, perhaps you could put it to use\n"
  .string "too!$\p"

Viridian_Text_LassRepel3::
  .string "{COLOR RED}Well, no more bugs for both of\n"
  .string "us! Toodles!$"
