Route20_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route20_OnTransition
	.byte 0

Route20_OnTransition::
	call_if_unset FLAG_STOPPED_SEAFOAM_B3F_CURRENT, Route20_EventScript_ResetSeafoamBouldersForB3F
	call_if_unset FLAG_STOPPED_SEAFOAM_B4F_CURRENT, Route20_EventScript_ResetSeafoamBouldersForB4F
	end

Route20_EventScript_ResetSeafoamBouldersForB3F::
	clearflag FLAG_HIDE_SEAFOAM_1F_BOULDER_1
	clearflag FLAG_HIDE_SEAFOAM_1F_BOULDER_2
	setflag FLAG_HIDE_SEAFOAM_B1F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B1F_BOULDER_2
	setflag FLAG_HIDE_SEAFOAM_B2F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B2F_BOULDER_2
	setflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_2
	return

Route20_EventScript_ResetSeafoamBouldersForB4F::
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_3
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_4
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_5
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_6
	setflag FLAG_HIDE_SEAFOAM_B4F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B4F_BOULDER_2
	return


Route20_EventScript_Pryce::
    lockall
    faceplayer
    setspeaker SP_NAME_PRYCE
    msgbox gText_pryce_1
	goto_if_not_defeated TRAINER_SWIMMER_FEMALE_MELISSA, Route20_EventScript_PryceNotReady
	goto_if_not_defeated TRAINER_PICNICKER_MISSY, Route20_EventScript_PryceNotReady
	goto_if_not_defeated TRAINER_SWIMMER_MALE_DEAN, Route20_EventScript_PryceNotReady
	goto_if_not_defeated TRAINER_SWIMMER_FEMALE_NORA, Route20_EventScript_PryceNotReady
	goto_if_not_defeated TRAINER_BIRD_KEEPER_ROGER, Route20_EventScript_PryceNotReady
	goto_if_not_defeated TRAINER_SWIMMER_MALE_BARRY, Route20_EventScript_PryceNotReady
	goto_if_not_defeated TRAINER_SWIMMER_FEMALE_SHIRLEY, Route20_EventScript_PryceNotReady
    setspeaker SP_NAME_PRYCE
    msgbox gText_pryce_askChallenge, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, 1, EventScript_Pryce_Battle
    msgbox gText_pryce_Reject
    release
    end

Route20_EventScript_PryceNotReady::
    msgbox gText_Pryce_NotReady 
    release
    end

EventScript_Pryce_Battle::
    setspeaker SP_NAME_PRYCE
    msgbox gText_pryce_2
    @ special HealPlayerParty                  @ special 0x0
    trainerbattle_no_intro TRAINER_LEADER_PRYCE, pryce_Text_Defeat   @ 0x31
    setflag FLAG_DEFEATED_PRYCE            @ 0x933
    setspeaker SP_NAME_PRYCE
    call_if_unset FLAG_UNLOCKED_STAT_EDITOR, EventScript_Pryce_StatEditExplain
    call_if_unset FLAG_DISABLE_EVS, EventScript_Pryce_StatEditTellCap
    setspeaker SP_NAME_PRYCE
    msgbox gText_pryce_3
    giveitem ITEM_FROSLASSITE
    setspeaker SP_NAME_PRYCE
    msgbox gText_pryce_4
    fadescreen FADE_TO_BLACK                 @ fadescreen 0x1
    playse SE_EXIT                            @ sound 0x9
    waitse                                   @ checksound
    removeobject LOCALID_ROUTE20_PRYCE             @ hidesprite 0x2
    removeobject LOCALID_ROUTE20_FROSLASS
    fadescreen FADE_FROM_BLACK               @ fadescreen 0x0
    release
    end

EventScript_Pryce_StatEditExplain::
    call_if_unset FLAG_DISABLE_EVS, EventScript_Pryce_StatEditExplain2
    return

EventScript_Pryce_StatEditExplain2:
    msgbox pryce_Text_StatEditor_Explain
    return

EventScript_Pryce_StatEditTellCap:
    callnative SetBuffer1ToEvCap
    msgbox johtoLeader_Text_CurrentEvCap
    setflag FLAG_UNLOCKED_STAT_EDITOR
    return


Route20_EventScript_Froslass::	
    lock
	faceplayer
	waitse
	playmoncry SPECIES_FROSLASS, CRY_MODE_NORMAL
	msgbox Route20_Text_Froslass
	waitmoncry
	release
	end

Route20_EventScript_SeafoamIslandsSign::
	msgbox Route20_Text_SeafoamIslands, MSGBOX_SIGN
	end

Route20_Text_Froslass:
    .string "Fros!$"

Route20_Text_BarryIntro::
    .string "The water is shallow here.\n"
    .string "There are many people swimming.$"

Route20_Text_BarryDefeat::
    .string "Splash!$"

Route20_Text_BarryPostBattle::
    .string "I wish I could ride my Pokémon.\n"
    .string "I bet you're not tired.$"

Route20_Text_ShirleyIntro::
    .string "SEAFOAM is a quiet getaway.\n"
    .string "I'm vacationing here.$"

Route20_Text_ShirleyDefeat::
    .string "Quit it!$"

Route20_Text_ShirleyPostBattle::
    .string "There's a huge cavern underneath\n"
    .string "this island.$"

Route20_Text_TiffanyIntro::
    .string "I love floating with the fishes\n"
    .string "here among the waves.$"

Route20_Text_TiffanyDefeat::
    .string "Yowch!$"

Route20_Text_TiffanyPostBattle::
    .string "Want to float with me?$"

Route20_Text_IreneIntro::
    .string "Are you on vacation, too?$"

Route20_Text_IreneDefeat::
    .string "No mercy at all!$"

Route20_Text_IrenePostBattle::
    .string "SEAFOAM used to be a single island\n"
    .string "in the distant past.$"

Route20_Text_DeanIntro::
    .string "Check out my buff physique!$"

Route20_Text_DeanDefeat::
    .string "Wimpy!$"

Route20_Text_DeanPostBattle::
    .string "I should've been buffing up my\n"
    .string "Pokémon, not me!$"

Route20_Text_DarrinIntro::
    .string "Why are you riding a Pokémon?\n"
    .string "Can't you swim?$"

Route20_Text_DarrinDefeat::
    .string "Ouch!\n"
    .string "Torpedoed!$"

Route20_Text_DarrinPostBattle::
    .string "Riding a Pokémon sure looks fun!$"

Route20_Text_RogerIntro::
    .string "I rode my bird Pokémon here.$"

Route20_Text_RogerDefeat::
    .string "Oh, no!\n"
    .string "Now what am I to do?$"

Route20_Text_RogerPostBattle::
    .string "My birds are exhausted.\n"
    .string "They can't FLY me back!$"

Route20_Text_NoraIntro::
    .string "My boyfriend gave me big pearls.$"

Route20_Text_NoraDefeat::
    .string "Oh, no!\n"
    .string "My pearls were in them!$"

Route20_Text_NoraPostBattle::
    .string "Will my pearls grow bigger inside\n"
    .string "CLOYSTER?$"

Route20_Text_MissyIntro::
    .string "I swam here from Cinnabar Island.\n"
    .string "It wasn't easy, I tell you.$"

Route20_Text_MissyDefeat::
    .string "I'm so disappointed!$"

Route20_Text_MissyPostBattle::
    .string "Pokémon have taken over an\n"
    .string "abandoned mansion on CINNABAR.\p"
    .string "They call it the Pokémon MANSION\n"
    .string "now.$"

Route20_Text_MelissaIntro::
    .string "CINNABAR, in the west, has a LAB\n"
    .string "for Pokémon.\p"
    .string "My daddy works there.$"

Route20_Text_MelissaDefeat::
    .string "Wait!\n"
    .string "You're supposed to wait!$"

Route20_Text_MelissaPostBattle::
    .string "CINNABAR is a volcanic island.\p"
    .string "I heard it rose out of the sea\n"
    .string "when a volcano erupted.$"

Route20_Text_SeafoamIslands::
    .string "SEAFOAM ISLANDS$"

Route20_Text_MistyTrainsHere::
    .string "Strong TRAINERS and WATER Pokémon\n"
    .string "are common sights in these parts.\p"
    .string "They say that MISTY of the\n"
    .string "CERULEAN GYM trains here.$"

gText_pryce_1::
  .string "Ah, hello.\p"
  .string "The Seafoam Islands is a very nostalgic\n"
  .string "spot for me…\p"
  .string "I've spent time training at this spot since\n"
  .string "before you were born.$"

gText_pryce_askChallenge::
  .string "I have a lifetime worth of experience behind\n"
  .string "me, is this a challenge you wish to seek?$"
gText_pryce_2::
    .string "{COLOR RED}I, the winter trainer, shall demonstrate\n"
    .string "my power!$"

gText_pryce_Reject::
  .string "Fine, then. I do not face cowards.$"

pryce_Text_Defeat::
  .string "Ah, well fought.\n"
  .string "It appears a strong will can overcome even\n"
  .string "my extended experience.$"

gText_pryce_3::
  .string "Here, you are worthy of this.$"

pryce_Text_StatEditor_Explain::
  .string "I can raise your Effort Values cap\n"
  .string "so your team can grow even stronger.\p"
  .string "The Edit Stats option is now avail-\n"
  .string "able when viewing your Pokémon in\l"
  .string "the party menu.$"

gText_pryce_4::
  .string "There's always new things to be learned.\n"
  .string "Megas Froslass is a relatively new discovery,\l"
  .string "making it a very formidable Pokémon.\p"
  .string "It is common knowledge that Articuno\n"
  .string "reigns in Seafoam Islands, but I've\l"
  .string "heard of rumors of other Mythical\l"
  .string "Pokémon making their stay here.\p"
  .string "Do what you will with that info.\n"
  .string "I'll be going away now.\p"
  .string "So long, challenger.$"

gText_Pryce_NotReady::
    .string "I'll only fight you once you've\n"
    .string "defeated all the trainers in this Route.$"
