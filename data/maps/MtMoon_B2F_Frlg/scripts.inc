MtMoon_B2F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMoon_B2F_OnTransition
	.byte 0

MtMoon_B2F_OnTransition::
	call_if_unset FLAG_GOT_FOSSIL_FROM_MT_MOON, MtMoon_B2F_EventScript_ShowFossils
	end

MtMoon_B2F_EventScript_ShowFossils::
	clearflag FLAG_HIDE_DOME_FOSSIL
	clearflag FLAG_HIDE_HELIX_FOSSIL
	return

MtMoon_B2F_EventScript_MiguelTrigger::
	lockall
	applymovement LOCALID_MIGUEL, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call MtMoon_B2F_EventScript_BattleMiguel
	releaseall
	end

MtMoon_B2F_EventScript_Miguel::
	lock
	faceplayer
	goto_if_set FLAG_GOT_FOSSIL_FROM_MT_MOON, MtMoon_B2F_EventScript_MiguelFossilPicked
	goto_if_defeated TRAINER_SUPER_NERD_MIGUEL, MtMoon_B2F_EventScript_MiguelGoPickFossil
	call MtMoon_B2F_EventScript_BattleMiguel
	release
	end

MtMoon_B2F_EventScript_BattleMiguel::
	textcolor NPC_TEXT_COLOR_MALE
	message MtMoon_B2F_Text_MiguelIntro
	waitmessage
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, 0
	waitbuttonpress
	setvar VAR_LAST_TALKED, LOCALID_MIGUEL
	trainerbattle_no_intro TRAINER_SUPER_NERD_MIGUEL, MtMoon_B2F_Text_MiguelDefeat
	setvar VAR_MAP_SCENE_MT_MOON_B2F, 1
	msgbox MtMoon_B2F_Text_WellEachTakeAFossil
	return

MtMoon_B2F_EventScript_MiguelFossilPicked::
	msgbox MtMoon_B2F_Text_LabOnCinnabarRegeneratesFossils
	release
	end

MtMoon_B2F_EventScript_MiguelGoPickFossil::
	msgbox MtMoon_B2F_Text_WellEachTakeAFossil
	release
	end

MtMoon_B2F_EventScript_DomeFossil::
	lock
	faceplayer
	msgbox MtMoon_B2F_Text_YouWantDomeFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtMoon_B2F_EventScript_DontTakeFossil
	removeobject LOCALID_DOME_FOSSIL
	giveitem_msg MtMoon_B2F_Text_ObtainedDomeFossil, ITEM_DOME_FOSSIL, 1, MUS_RG_OBTAIN_KEY_ITEM
	closemessage
	delay 10
	applymovement LOCALID_MIGUEL, MtMoon_B2F_Movement_MiguelToHelixFossil
	waitmovement 0
	copyobjectxytoperm LOCALID_MIGUEL
	textcolor NPC_TEXT_COLOR_MALE
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message MtMoon_B2F_Text_ThenThisFossilIsMine
	waitmessage
	waitfanfare
	removeobject LOCALID_HELIX_FOSSIL
	setflag FLAG_GOT_DOME_FOSSIL
	setflag FLAG_GOT_FOSSIL_FROM_MT_MOON
	release
	end

MtMoon_B2F_Movement_MiguelToHelixFossil::
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

MtMoon_B2F_EventScript_HelixFossil::
	lock
	faceplayer
	msgbox MtMoon_B2F_Text_YouWantHelixFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtMoon_B2F_EventScript_DontTakeFossil
	removeobject LOCALID_HELIX_FOSSIL
	giveitem_msg MtMoon_B2F_Text_ObtainedHelixFossil, ITEM_HELIX_FOSSIL, 1, MUS_RG_OBTAIN_KEY_ITEM
	closemessage
	delay 10
	applymovement LOCALID_MIGUEL, MtMoon_B2F_Movement_MiguelToDomeFossil
	waitmovement 0
	copyobjectxytoperm LOCALID_MIGUEL
	textcolor NPC_TEXT_COLOR_MALE
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message MtMoon_B2F_Text_ThenThisFossilIsMine
	waitmessage
	waitfanfare
	removeobject LOCALID_DOME_FOSSIL
	setflag FLAG_GOT_HELIX_FOSSIL
	setflag FLAG_GOT_FOSSIL_FROM_MT_MOON
	release
	end

MtMoon_B2F_EventScript_DontTakeFossil::
	release
	end

MtMoon_B2F_Movement_MiguelToDomeFossil::
	walk_up
	walk_up
	walk_up
	step_end

MtMoon_B2F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT, MtMoon_B2F_Text_Grunt1Intro, MtMoon_B2F_Text_Grunt1Defeat
	msgbox MtMoon_B2F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_2, MtMoon_B2F_Text_Grunt2Intro, MtMoon_B2F_Text_Grunt2Defeat
	msgbox MtMoon_B2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_3, MtMoon_B2F_Text_Grunt3Intro, MtMoon_B2F_Text_Grunt3Defeat
	msgbox MtMoon_B2F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_4, MtMoon_B2F_Text_Grunt4Intro, MtMoon_B2F_Text_Grunt4Defeat
	msgbox MtMoon_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

EventScript_AdminMtMoonLeft_Start::
    setvar VAR_TEMP_2, 1
    goto EventScript_AdminMtMoonMain_Start


EventScript_AdminMtMoonRight_Start::
    setvar VAR_TEMP_2, 2
    goto EventScript_AdminMtMoonMain_Start

EventScript_AdminMtMoonMain_Start::
    lockall
    addobject LOCALID_MT_MOON_ARCHER
    addobject LOCALID_MT_MOON_MIGHTYENA
    applymovement LOCALID_PLAYER, MtMoon_Movement_AdminMtMoonLeft_Stop
    waitmovement 0
    msgbox adminmtmoonleft_Text_1
    waitmessage

    @ playse 0xB3                         @ original: sound 0xB3 @? (pick a proper SE_ constant later)
    applymovement LOCALID_PLAYER, MtMoon_Movement_AdminMtMoonLeft_Question
    waitmovement 0
    @ waitse                               @ original used checksound @?

    call_if_eq VAR_TEMP_2, 1, MtMoon_AdminMtMoon_ComeUpLeft
    call_if_eq VAR_TEMP_2, 2, MtMoon_AdminMtMoon_ComeUpRight

    msgbox adminmtmoonleft_Text_2
    waitmessage
    trainerbattle_no_intro TRAINER_MT_MOON_ARCHER, adminmtmoonleft_Text_Defeat

    fadescreen FADE_TO_BLACK

    removeobject LOCALID_MT_MOON_MIGHTYENA
    playse 0xF                          @ original: sound 0xF when partner disappears @?
    waitse

    fadescreen FADE_FROM_BLACK

    msgbox adminmtmoonleft_Text_4
    waitmessage

    call_if_eq VAR_TEMP_2, 1, MtMoon_AdminMtMoon_ComeDownLeft
    call_if_eq VAR_TEMP_2, 2, MtMoon_AdminMtMoon_ComeDownRight

    setvar VAR_MT_MOON_ARCHER, 1                    @ TODO: give this a proper VAR_ name in vars.h @?
    removeobject LOCALID_MT_MOON_ARCHER
    setflag FLAG_BEAT_MT_MOON_ARCHER
    playse SE_EXIT    
    waitse
    release
    end

MtMoon_AdminMtMoon_ComeUpLeft:
    applymovement LOCALID_MT_MOON_ARCHER, MtMoon_Movement_AdminMtMoonLeft_ComeUp
    applymovement LOCALID_MT_MOON_MIGHTYENA, MtMoon_Movement_AdminMtMoonLeft_ComeUp
    waitmovement 0
    applymovement LOCALID_PLAYER, MtMoon_Movement_AdminMtMoonLeft_Look
    waitmovement 0
    return

MtMoon_AdminMtMoon_ComeUpRight:
    applymovement LOCALID_MT_MOON_ARCHER, MtMoon_Movement_AdminMtMoonRight_ComeUp
    applymovement LOCALID_MT_MOON_MIGHTYENA, MtMoon_Movement_AdminMtMoonRight_ComeUp
    waitmovement 0
    applymovement LOCALID_PLAYER, MtMoon_Movement_AdminMtMoonLeft_Look
    waitmovement 0
    return

MtMoon_AdminMtMoon_ComeDownLeft:
    applymovement LOCALID_MT_MOON_ARCHER, MtMoon_Movement_AdminMtMoonLeft_ComeDown
    waitmovement 0
    return

MtMoon_AdminMtMoon_ComeDownRight:
    applymovement LOCALID_MT_MOON_ARCHER, MtMoon_Movement_AdminMtMoonRight_ComeDown
    waitmovement 0
    return

@ =========================
@ Movement scripts
@ =========================

MtMoon_Movement_AdminMtMoonLeft_ComeUp:
    walk_fast_left
    walk_fast_left
    walk_fast_left
    walk_fast_left
    walk_fast_left
    walk_fast_left
    walk_fast_left
    walk_fast_left
    walk_fast_left
    face_down
    step_end 

MtMoon_Movement_AdminMtMoonRight_ComeUp:
    walk_fast_left
    walk_fast_left
    walk_fast_left
    walk_fast_left
    walk_fast_left
    walk_fast_left
    walk_fast_left
    walk_fast_left
    face_down
    step_end 

MtMoon_Movement_AdminMtMoonLeft_ComeDown:
    walk_fast_right
    walk_fast_down
    walk_fast_down
    walk_fast_down
    walk_fast_down
    walk_fast_right
    step_end 

MtMoon_Movement_AdminMtMoonRight_ComeDown:
    walk_fast_left
    walk_fast_down
    walk_fast_down
    walk_fast_down
    walk_fast_down
    walk_fast_right
    walk_fast_right
    step_end 

MtMoon_Movement_AdminMtMoonLeft_Question:
    @ CFRU bytes: 0x63,0xFE
    @ In FR, 0x63 is a movement/step; name suggests a question-mark emotion.
    @ If you have a Common_Movement_QuestionMark, you could just use that instead.
    @ e.g.:
    @   Common_Movement_QuestionMark
    step_end @?

MtMoon_Movement_AdminMtMoonLeft_Look:
    @ CFRU bytes: 0x01,0xFE (Face Up)
    face_up
    step_end

MtMoon_Movement_AdminMtMoonLeft_Stop:
    @ CFRU bytes: 0x00,0xFE (Face Down)
    face_down
    step_end

MtMoon_B2F_Text_MiguelIntro::
    .string "Hey, stop!\p"
    .string "I found these fossils!\n"
    .string "They're both mine!$"

MtMoon_B2F_Text_MiguelDefeat::
    .string "Okay!\n"
    .string "I'll share!$"

MtMoon_B2F_Text_WellEachTakeAFossil::
    .string "We'll each take a fossil!\n"
    .string "No being greedy!$"

MtMoon_B2F_Text_ThenThisFossilIsMine::
    .string "All right.\n"
    .string "Then this fossil is mine!$"

MtMoon_B2F_Text_LabOnCinnabarRegeneratesFossils::
    .string "Far away, on CINNABAR ISLAND,\n"
    .string "there's a Pokémon LAB.\p"
    .string "They do research on regenerating\n"
    .string "fossils.$"

MtMoon_B2F_Text_Grunt1Intro::
    .string "We, TEAM ROCKET, shall find the\n"
    .string "fossils!\p"
    .string "Reviving Pokémon from them will\n"
    .string "earn us huge riches!$"

MtMoon_B2F_Text_Grunt1Defeat::
    .string "Urgh!\n"
    .string "Now I'm mad!$"

MtMoon_B2F_Text_Grunt1PostBattle::
    .string "You made me mad!\n"
    .string "TEAM ROCKET will blacklist you!$"

MtMoon_B2F_Text_Grunt2Intro::
    .string "We, TEAM ROCKET, are Pokémon\n"
    .string "gangsters!\l"
    .string "We strike fear with our strength!$"

MtMoon_B2F_Text_Grunt2Defeat::
    .string "I blew it!$"

MtMoon_B2F_Text_Grunt2PostBattle::
    .string "Darn it all!\n"
    .string "My associates won't stand for this!$"

MtMoon_B2F_Text_Grunt3Intro::
    .string "We're pulling a big job here!\n"
    .string "Get lost, kid!$"

MtMoon_B2F_Text_Grunt3Defeat::
    .string "So, you are good…$"

MtMoon_B2F_Text_Grunt3PostBattle::
    .string "If you find a fossil, give it to me\n"
    .string "and scram!$"

MtMoon_B2F_Text_Grunt4Intro::
    .string "Little kids shouldn't be messing\n"
    .string "around with grown-ups!\p"
    .string "It could be bad news!$"

MtMoon_B2F_Text_Grunt4Defeat::
    .string "I'm steamed!$"

MtMoon_B2F_Text_Grunt4PostBattle::
    .string "Pokémon lived here long before\n"
    .string "people came.$"

MtMoon_B2F_Text_YouWantDomeFossil::
    .string "Do you want the DOME FOSSIL?$"

MtMoon_B2F_Text_YouWantHelixFossil::
    .string "Do you want the HELIX FOSSIL?$"

MtMoon_B2F_Text_ObtainedHelixFossil::
    .string "Obtained the HELIX FOSSIL!$"

MtMoon_B2F_Text_ObtainedDomeFossil::
    .string "Obtained the DOME FOSSIL!$"

adminmtmoonleft_Text_1::
  .string "HEY YOU! Wait right there!$"


adminmtmoonleft_Text_2::
  .string "Are you the twerp messing with my\n"
  .string "grunts?\p"
  .string "…Little kid, you think you're brave,\n"
  .string "eh?\p"
  .string "I'll teach you a valuable lesson.$"


adminmtmoonleft_Text_Defeat::
  .string "What a shameful blunder…$"


adminmtmoonleft_Text_4::
  .string "Whatever, we've done everything we\n"
  .string "needed.\p"
  .string "I won't be as nice to you next\n"
  .string "time.\p"
  .string "…I'll be seeing you.$"
