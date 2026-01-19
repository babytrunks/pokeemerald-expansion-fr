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
    goto_if_quest_complete QUEST_LIGHT_BALL, PewterCity_Museum_2F_EventScript_LittleGirlPikablu
	msgbox PewterCity_Museum_1F_Text_AskedDaddyToCatchPikachu, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_LittleGirlPikablu::
	msgbox PewterCity_Museum_1F_Text_AskedDaddyToCatchPikablu, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_BaldingMan::
    @ lock
    goto_if_quest_complete QUEST_LIGHT_BALL, PewterCity_Museum_2F_EventScript_WhatIsPikablu
    goto_if_quest_active QUEST_LIGHT_BALL, PewterCity_Museum_2F_EventScript_FindPikachu
	msgbox PewterCity_Museum_1F_Text_PikachuSoonIPromise
    applymovement LOCALID_PEWTER_BALDING_MAN, Common_Movement_ExclamationMark
    playse SE_PIN
    waitmovement 0
    waitse
    faceplayer
    setflag FLAG_SYS_QUEST_MENU_GET
	msgbox PewterCity_Museum_1F_Text_HeyYouLookLike
    closemessage
    questmenu QUEST_MENU_SET_ACTIVE QUEST_LIGHT_BALL
    openquestmenu
    startquest QUEST_LIGHT_BALL
	end

PewterCity_Museum_2F_EventScript_FindPikachu::
    @ lock
    faceplayer
    callnative GetFollowerPokemon
    goto_if_eq VAR_RESULT, SPECIES_PIKACHU, PewterCity_Museum_2F_EventScript_LightBallCompleteQuest
	msgbox PewterCity_Museum_1F_Text_HeyYouLookLike
    closemessage
    release
    end

PewterCity_Museum_2F_EventScript_WhatIsPikablu::
    msgbox PewterCity_Museum_1F_Text_WhatIsPikablu
    release
    end

PewterCity_Museum_2F_EventScript_LightBallCompleteQuest::
    playse SE_PIN
    applymovement LOCALID_PEWTER_LITTLE_GIRL_PIKACHU, PewterMuseum_Movement_GirlFacePlayer
    waitmovement 0
    waitse
 	msgbox PewterCity_Museum_1F_Text_HeyItsPikachu
    waitmessage
    applymovement LOCALID_PEWTER_BALDING_MAN, Common_Movement_WalkInPlaceLeft
    waitmovement 0
    msgbox PewterCity_Museum_1F_Text_ThatsOkaySilly
    applymovement LOCALID_PEWTER_BALDING_MAN,  Common_Movement_FacePlayer
    waitmovement 0
    msgbox PewterCity_Museum_1F_Text_KnewThisWouldHappen
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
    .string "Well, how about SEISMIC TOSS?\n"
    .string "Should I teach that to a Pokémon?$"

Text_SeismicTossDeclined::
    .string "Is that so?\n"
    .string "I'm sure you'll be back for it.$"

Text_SeismicTossWhichMon::
    .string "Which Pokémon wants to learn\n"
    .string "SEISMIC TOSS?$"

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

PewterCity_Museum_1F_Text_AskedDaddyToCatchPikachu::
    .string "{COLOR RED}I want a Pikachu!\n"
    .string "It's so cute!\p"
    .string "I asked my daddy to catch me one!$"

PewterCity_Museum_1F_Text_AskedDaddyToCatchPikablu::
    .string "{COLOR RED}Daddy, I want a Pikablu now!\n"
    .string "It's so cute!$"

PewterCity_Museum_1F_Text_PikachuSoonIPromise::
    .string "{COLOR BLUE}Yeah, a Pikachu soon, I promise!$"

PewterCity_Museum_1F_Text_HeyYouLookLike::
    .string "{COLOR BLUE}Hey, you look like a trainer!\p"
    .string "Can you get a Pikachu to show\n"
    .string "my daughter? Pretty please?$"

PewterCity_Museum_1F_Text_WhatIsPikablu::
    .string "{COLOR BLUE}Yeah, a Pikablu soon, I-\n"
    .string "…what in the world is a Pikablu?$"

PewterCity_Museum_1F_Text_HeyItsPikachu::
    .string "{COLOR RED}Hey… it's a Pikachu!\n"
    .string "Sooooo cute!\p"
    .string "Hmm…\p"
    .string "Hmmmm…\p"
    .string "Hm…\p"
    .string "…Now that I've seen it, I don't\n"
    .string "think I want one anymore…$"

PewterCity_Museum_1F_Text_ThatsOkaySilly::
    .string "{COLOR BLUE}Okay silly…$"

PewterCity_Museum_1F_Text_KnewThisWouldHappen::
    .string "{COLOR BLUE}I sort of knew this would happen.\p"
    .string "Kids can be like this. The joy of\n"
    .string "parenting! Anyway, thanks for that.\p"
    .string "This was going to go to her Pikachu,\n" 
    .string "but you can have it instead.$"

PewterCity_Museum_1F_Text_SpaceShuttle::
    .string "Space Shuttle$"

PewterCity_Museum_1F_Text_MeteoriteThatFellOnMtMoon::
    .string "A meteorite that fell on MT. MOON.\n"
    .string "It is thought to be a MOON STONE.$"


falkner_Text_1::
  .string "{COLOR BLUE}Hmm… There doesn't seem to be\n"
  .string "any information on Mega Stones…$"


falkner_Text_2::
  .string "{COLOR BLUE}Oh, hello! I'm Falkner, a Gym\n"
  .string "Leader from Johto.\p"
  .string "I'm traveling in Kanto looking for\n"
  .string "information on Mega Evolution,\l"
  .string "but have found nothing so far.$"


falkner_Text_3::
  .string "{COLOR BLUE}…A battle is what you're looking\n"
  .string "for?\p"
  .string "I guess I could spare the time.\p"
  .string "I'll demonstrate the power of the\n"
  .string "elegant bird Pokémon!$"


falkner_Text_Defeat::
  .string "Mmm… I have much to learn even\n"
  .string "before attaining the Mega Stones…$"


falkner_Text_4::
  .string "{COLOR BLUE}Thank you for a wonderful battle.\n"
  .string "I hope we meet again.\p"
  .string "I don't have a badge to give\n"
  .string "unfortunately, but you can have this.$"


falkner_Text_6::
  .string "Until next time.$"
