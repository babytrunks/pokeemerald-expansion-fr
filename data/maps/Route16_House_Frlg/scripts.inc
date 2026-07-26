Route16_House_Frlg_MapScripts::
	.byte 0

Route16_House_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HM02, Route16_House_EventScript_AlreadyGotHM02
	msgbox Route16_House_Text_FoundMySecretRetreat
	checkitemspace ITEM_HM02
	goto_if_eq VAR_RESULT, FALSE, Route16_House_EventScript_NoRoomForHM02
	giveitem_msg Route16_House_Text_ReceivedHM02FromGirl, ITEM_HM02
	msgbox Route16_House_Text_ExplainHM02
	setflag FLAG_GOT_HM02
	release
	end

Route16_House_EventScript_NoRoomForHM02::
	msgbox Route16_House_Text_DontHaveAnyRoomForThis
	release
	end

Route16_House_EventScript_AlreadyGotHM02::
	msgbox Route16_House_Text_ExplainHM02
	release
	end

Route16_House_EventScript_Fearow::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_FEAROW, CRY_MODE_NORMAL
	msgbox Route16_House_Text_Fearow
	waitmoncry
	release
	end


Route16_EventScript_Silva::
    lock
    faceplayer
	goto_if_set FLAG_DEFEATED_ROUTE_16_SILVA, EventScript_Silva_Defeated
	msgbox gText_silva_askChallenge
	goto_if_not_defeated TRAINER_CUE_BALL_KOJI, EventScript_Silva_Releasend
	goto_if_not_defeated TRAINER_BIKER_LAO, EventScript_Silva_Releasend
	goto_if_not_defeated TRAINER_CUE_BALL_LUKE, EventScript_Silva_Releasend
	goto_if_not_defeated TRAINER_BIKER_HIDEO, EventScript_Silva_Releasend
	goto_if_not_defeated TRAINER_BIKER_RUBEN, EventScript_Silva_Releasend
	goto_if_not_defeated TRAINER_BIKER_VIRGIL, EventScript_Silva_Releasend
	goto_if_not_defeated TRAINER_BIKER_BILLY, EventScript_Silva_Releasend
	goto_if_not_defeated TRAINER_BIKER_NIKOLAS, EventScript_Silva_Releasend
	goto_if_not_defeated TRAINER_CUE_BALL_JAMAL, EventScript_Silva_Releasend
	goto_if_not_defeated TRAINER_CUE_BALL_ZEEK, EventScript_Silva_Releasend
	goto_if_not_defeated TRAINER_CUE_BALL_COREY, EventScript_Silva_Releasend
	goto_if_not_defeated TRAINER_BIKER_JAXON, EventScript_Silva_Releasend
	goto_if_not_defeated TRAINER_BIKER_WILLIAM, EventScript_Silva_Releasend
    msgbox gText_silva_askChallenge2, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, 1, EventScript_Silva_Battle
    @ msgbox gText_silva_Reject
    release
    end

EventScript_Silva_Battle::
    setspeaker SP_NAME_UNKNOWN
    msgbox gText_silva_2
    @ special HealPlayerParty                 
	trainerbattle_no_intro TRAINER_ROUTE16_SILVA, silva_Text_Defeat  
    setflag FLAG_DEFEATED_ROUTE_16_SILVA
    msgbox gText_silva_3
    giveitem ITEM_CHANDELURITE                                   
    release
    end

EventScript_Silva_Defeated::
	msgbox gText_silva_4
EventScript_Silva_Releasend:
	release
	end

gText_silva_askChallenge::
  .string "These cyclists here thought they\n"
  .string "were better than me since I had\l"
  .string "to walk to get to Fuschia.\p"
  .string "Defeat them to make me feel\n"
  .string "better, yeah?$"

gText_silva_askChallenge2::
  .string "Ah, I see you've beat all the cyclists.\p"
  .string "I'll give you a hot reward if you\n"
  .string "beat me in battle!$"

gText_silva_Reject::
  .string "Heh, my aura frightens you, doesn't it?$"

 
silva_Text_Defeat::
	.string "Hm, I thought Shadow Tag would give\n"
	.string "a free win.$"

gText_silva_2::
	.string "Okay, let's do this!$"

gText_silva_3::
	.string "Well then, you've earned this.\p"
	.string "It makes the already awesome\n"
	.string "Chandelure even more powerful.$"

gText_silva_4::
	.string "Mega Chandelure is a straight up\n"
	.string "nuke. You ought to give it a\l"
	.string "shot.$"

Route16_House_Text_FoundMySecretRetreat::
    .string "Oh, dear.\n"
    .string "You've found my secret retreat.\p"
    .string "Please don't tell anyone I'm here.\n"
    .string "I'll make it up to you with this!$"


Route16_House_Text_ReceivedHM02FromGirl::
    .string "{PLAYER} received HM02\n"
    .string "from the girl.$"

Route16_House_Text_ExplainHM02::
    .string "HM02 is Fly.\n"
    .string "It's a wonderfully convenient move.\p"
    .string "Please, put it to good use.$"

Route16_House_Text_DontHaveAnyRoomForThis::
    .string "You don't have any room for this.$"

Route16_House_Text_Fearow::
    .string "Kyueen!$"

