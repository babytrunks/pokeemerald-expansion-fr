PewterCity_Museum_2F_Frlg_MapScripts::
	.byte 0

PewterCity_Museum_2F_EventScript_Man::
	msgbox PewterCity_Museum_1F_Text_WhatsSpecialAboutMoonStone, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_OldMan::
	msgbox PewterCity_Museum_1F_Text_BoughtColorTVForMoonLanding, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_Scientist::
	msgbox PewterCity_Museum_1F_Text_RunningSpaceExhibitThisMonth, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_LittleGirl::
    goto_if_quest_complete QUEST_LIGHT_BALL, PewterCity_Museum_2F_EventScript_LittleGirlPichuSaved
	msgbox PewterCity_Museum_1F_Text_PoorLittlePichu, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_LittleGirlPichuSaved::
	msgbox PewterCity_Museum_1F_Text_PichuFoundAFriend, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_BaldingMan::
    @ lock
    goto_if_quest_complete QUEST_LIGHT_BALL, PewterCity_Museum_2F_EventScript_DaughterSmilesAgain
    goto_if_quest_active QUEST_LIGHT_BALL, PewterCity_Museum_2F_EventScript_CheckPichuRescued
	msgbox PewterCity_Museum_1F_Text_ThereThereSweetie
    applymovement LOCALID_PEWTER_BALDING_MAN, Common_Movement_ExclamationMark
    playse SE_PIN
    waitmovement 0
    waitse
    faceplayer
    setflag FLAG_SYS_QUEST_MENU_GET
	msgbox PewterCity_Museum_1F_Text_TeachThoseBulliesALesson
    closemessage
    questmenu QUEST_MENU_SET_ACTIVE QUEST_LIGHT_BALL
    openquestmenu
    startquest QUEST_LIGHT_BALL
	end

PewterCity_Museum_2F_EventScript_CheckPichuRescued::
    @ lock
    faceplayer
    goto_if_unset FLAG_RESCUED_SPIKY_PICHU, PewterCity_Museum_2F_EventScript_BulliesStillOutThere
    callnative GetFollowerPokemon
    goto_if_eq VAR_RESULT, SPECIES_PICHU, PewterCity_Museum_2F_EventScript_LightBallCompleteQuest
	msgbox PewterCity_Museum_1F_Text_BringThePichuAlong
    closemessage
    release
    end

PewterCity_Museum_2F_EventScript_BulliesStillOutThere::
	msgbox PewterCity_Museum_1F_Text_BulliesStillOutThere
    closemessage
    release
    end

PewterCity_Museum_2F_EventScript_DaughterSmilesAgain::
    msgbox PewterCity_Museum_1F_Text_DaughterSmilesAgain
    release
    end

PewterCity_Museum_2F_EventScript_LightBallCompleteQuest::
    playse SE_PIN
    applymovement LOCALID_PEWTER_LITTLE_GIRL_PIKACHU, PewterMuseum_Movement_GirlFacePlayer
    waitmovement 0
    waitse
 	msgbox PewterCity_Museum_1F_Text_ItsTheLittlePichu
    waitmessage
    applymovement LOCALID_PEWTER_BALDING_MAN, Common_Movement_WalkInPlaceLeft
    waitmovement 0
    msgbox PewterCity_Museum_1F_Text_HerSmileIsBack
    applymovement LOCALID_PEWTER_BALDING_MAN,  Common_Movement_FacePlayer
    waitmovement 0
    msgbox PewterCity_Museum_1F_Text_SpikyEaredPichu
    giveitem ITEM_LIGHT_BALL
    completequest QUEST_LIGHT_BALL
    waitmessage
    release
    end

PewterMuseum_Movement_GirlFacePlayer:
    face_player
    emote_exclamation_mark
    step_end

PewterCity_Museum_2F_EventScript_SpaceShuttle::
	msgbox PewterCity_Museum_1F_Text_SpaceShuttle, MSGBOX_SIGN
	end

PewterCity_Museum_2F_EventScript_MoonStone::
	msgbox PewterCity_Museum_1F_Text_MeteoriteThatFellOnMtMoon, MSGBOX_SIGN
	end

EventScript_falkner_Start::
    lockall                 @ CFRU used 'lock'; using lockall + faceplayer here
    setspeaker SP_NAME_FALKNER
    msgbox falkner_Text_1   @ 0x6 -> normal msgbox
    playse SE_PIN              @ sound 0x15  @ ??? replace with proper SE_* constant
    applymovement LOCALID_FALKNER, Common_Movement_ExclamationMark   @ 0x6 -> Falkner’s local id
    waitmovement 0
    waitse                  @ checksound
    applymovement LOCALID_FALKNER, Common_Movement_FacePlayer
    applymovement LOCALID_PEWTER_MUSEUM_PIDGEOTTO, Common_Movement_FacePlayer
    waitmovement 0
    setspeaker SP_NAME_FALKNER
    msgbox falkner_Text_2
    setspeaker SP_NAME_FALKNER
    msgbox falkner_Text_3
    @ trainerbattle3 0x3 0x2D 0x0 gText_falkner_Defeat
    @ Guess: simple no-intro trainer battle with mugshot handled via VARs above.
    trainerbattle_no_intro TRAINER_FALKNER, falkner_Text_Defeat   @ ??? 0x2D trainer id
    setspeaker SP_NAME_FALKNER
    msgbox falkner_Text_4
    giveitem ITEM_TM_AERIAL_ACE     
    setspeaker SP_NAME_FALKNER 
    msgbox falkner_Text_6
    closemessage
    fadescreen FADE_TO_BLACK    @ fadescreen 0x1
    removeobject LOCALID_FALKNER @ hidesprite 0x6  @ ??? confirm correct LOCALID
    removeobject LOCALID_PEWTER_MUSEUM_PIDGEOTTO
    playse SE_EXIT                  @ sound 0x9  @ ??? replace with proper SE_* constant
    waitse                      @ checksound
    fadescreen FADE_FROM_BLACK  @ fadescreen 0x0
    setflag FLAG_BEAT_PEWTER_FALKNER           @ ??? Likely “beaten Falkner / badge” story flag
    setvar VAR_MAP_SCENE_PEWTER_CITY_GYM, 1
    release
    end

EventScript_PewterCity_Museum_Pidgeotto::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEOTTO, CRY_MODE_NORMAL
	msgbox PewterCity_Museum_Text_Pidgeotto
	waitmoncry
	release
	end

PewterCity_Museum_Text_Pidgeotto::
    .string "Pidgeotto: Pi, pi!$"

Text_SeismicTossTeach::
    .string "The secrets of space…\n"
    .string "The mysteries of earth…\p"
    .string "There are so many things about\n"
    .string "which we know so little.\p"
    .string "But that should spur us to study\n"
    .string "harder, not toss in the towel.\p"
    .string "The only thing you should toss…\p"
    .string "Well, how about Seismic Toss?\n"
    .string "Should I teach that to a Pokémon?$"

Text_SeismicTossDeclined::
    .string "Is that so?\n"
    .string "I'm sure you'll be back for it.$"

Text_SeismicTossWhichMon::
    .string "Which Pokémon wants to learn\n"
    .string "Seismic Toss?$"

Text_SeismicTossTaught::
    .string "I hope you won't toss in the towel.\n"
    .string "Keep it up.$"

PewterCity_Museum_1F_Text_WhatsSpecialAboutMoonStone::
    .string "Moon Stone is busted!\p"
    .string "Early game Nidoking or Clefable?\n"
    .string "Can't go wrong!$"

PewterCity_Museum_1F_Text_BoughtColorTVForMoonLanding::
    .string "July 20, 1969!\p"
    .string "Humankind first set foot on the\n"
    .string "moon that day.\p"
    .string "I bought a color TV just so I\n"
    .string "could watch that news.\p"
    .string "Now you got conspiracy nuts\n"
    .string "saying it was all fake.\p"
    .string "What a sad world.$"

PewterCity_Museum_1F_Text_RunningSpaceExhibitThisMonth::
    .string "This month, we're running a space\n"
    .string "exhibit.$"

PewterCity_Museum_1F_Text_PoorLittlePichu::
    .string "Waaah… The poor little Pichu…\p"
    .string "Those two big meanies just kept\n"
    .string "picking on it…$"

PewterCity_Museum_1F_Text_PichuFoundAFriend::
    .string "You saved the little Pichu!\p"
    .string "Its spiky ear makes it extra\n"
    .string "cute! Take good care of it!$"

PewterCity_Museum_1F_Text_ThereThereSweetie::
    .string "There, there, sweetie.\n"
    .string "I'm sure that Pichu is fine…$"

PewterCity_Museum_1F_Text_TeachThoseBulliesALesson::
    .string "Oh! You look like a Trainer!\p"
    .string "My daughter and I were strolling\n"
    .string "through Viridian Forest when we\l"
    .string "saw something awful…\p"
    .string "In the western part, two Pichu\n"
    .string "were ganging up on a little one!\p"
    .string "She hasn't stopped crying about\n"
    .string "it since.\p"
    .string "Could you go teach those bullies\n"
    .string "a lesson?\p"
    .string "Please, for my little girl's\n"
    .string "peace of mind…$"

PewterCity_Museum_1F_Text_BulliesStillOutThere::
    .string "Those two bullies were in the\n"
    .string "western part of Viridian Forest.\p"
    .string "Please, put my daughter's mind\n"
    .string "at ease…$"

PewterCity_Museum_1F_Text_BringThePichuAlong::
    .string "You drove those bullies off?\n"
    .string "Thank you!\p"
    .string "And the little one that was being\n"
    .string "picked on… is it doing okay?\p"
    .string "I'd love for my daughter to see\n"
    .string "it safe with her own eyes.\p"
    .string "Could you bring it along with\n"
    .string "you?$"

PewterCity_Museum_1F_Text_ItsTheLittlePichu::
    .string "Ah! It's the little Pichu!\n"
    .string "It's safe!\p"
    .string "And it looks sooooo happy\n"
    .string "with you!$"

PewterCity_Museum_1F_Text_HerSmileIsBack::
    .string "Well, what do you know…\n"
    .string "Her smile is finally back.$"

PewterCity_Museum_1F_Text_SpikyEaredPichu::
    .string "Hm? Look at that…\p"
    .string "That ear of its is all spiky!\n"
    .string "I've never seen one like it.\p"
    .string "Maybe that's why the others\n"
    .string "picked on it…\p"
    .string "Well, it couldn't have found a\n"
    .string "better Trainer.\p"
    .string "Here, take this as thanks.$"

PewterCity_Museum_1F_Text_DaughterSmilesAgain::
    .string "Thanks to you, my daughter can't\n"
    .string "stop smiling.\p"
    .string "Take good care of that spiky-\n"
    .string "eared Pichu!$"

PewterCity_Museum_1F_Text_SpaceShuttle::
    .string "Space Shuttle$"

PewterCity_Museum_1F_Text_MeteoriteThatFellOnMtMoon::
    .string "A meteorite that fell on Mt. Moon.\n"
    .string "It is thought to be a Moon Stone.$"


falkner_Text_1::
  .string "Hmm… There doesn't seem to be\n"
  .string "any information on Mega Stones…$"


falkner_Text_2::
  .string "Oh, hello! I'm Falkner, a Gym\n"
  .string "Leader from Johto.\p"
  .string "I'm traveling in Kanto looking for\n"
  .string "information on Mega Evolution,\l"
  .string "but have found nothing so far.$"


falkner_Text_3::
  .string "…A battle is what you're looking\n"
  .string "for?\p"
  .string "I guess I could spare the time.\p"
  .string "I'll demonstrate the power of the\n"
  .string "elegant bird Pokémon!$"


falkner_Text_Defeat::
  .string "Mmm… I have much to learn even\n"
  .string "before attaining the Mega Stones…$"


falkner_Text_4::
  .string "Thank you for a wonderful battle.\n"
  .string "I hope we meet again.\p"
  .string "I don't have a badge to give\n"
  .string "unfortunately, but you can have this.$"


falkner_Text_6::
  .string "Until next time.$"
