CinnabarIsland_PokemonLab_Entrance_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_PokemonLab_Entrance_OnTransition
	.byte 0

CinnabarIsland_PokemonLab_Entrance_OnTransition::
	call_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1, CinnabarIsland_PokemonLab_Entrance_EventScript_ReadyFossil
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_ReadyFossil::
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 2
	return

CinnabarIsland_PokemonLab_Entrance_EventScript_Scientist::
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_StudyMonsExtensively, MSGBOX_NPC
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_DrFujiPhoto::
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_PhotoOfLabFounderDrFuji, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_MeetingRoomSign::
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_MeetingRoomSign, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_RAndDRoomSign::
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_RAndDRoomSign, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_TestingRoomSign::
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_TestingRoomSign, MSGBOX_SIGN
	end


CinnabarIsland_PokemonLab_Entrance_EventScript_Morty::
    lockall
    faceplayer
    setspeaker SP_NAME_MORTY
    msgbox gText_morty_1
    setspeaker SP_NAME_MORTY
    msgbox gText_morty_askChallenge, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, 1, EventScript_Morty_Battle
    msgbox gText_morty_Reject
    release
    end

CinnabarIsland_PokemonLab_Entrance_EventScript_MortyNotReady::
    msgbox gText_Morty_NotReady 
    release
    end

EventScript_Morty_Battle::
    setspeaker SP_NAME_MORTY
    msgbox gText_morty_2
    @ special HealPlayerParty                  @ special 0x0
    trainerbattle_no_intro TRAINER_LEADER_MORTY, morty_Text_Defeat   @ 0x31
    setflag FLAG_DEFEATED_MORTY            @ 0x933
    setspeaker SP_NAME_MORTY
    call_if_unset FLAG_UNLOCKED_STAT_EDITOR, EventScript_Morty_StatEditExplain
    call_if_unset FLAG_DISABLE_EVS, EventScript_Morty_StatEditTellCap
    setspeaker SP_NAME_MORTY
    msgbox gText_morty_3
    giveitem ITEM_GENGARITE
    setspeaker SP_NAME_MORTY
    msgbox gText_morty_4
    fadescreen FADE_TO_BLACK                 @ fadescreen 0x1
    playse SE_EXIT                            @ sound 0x9
    waitse                                   @ checksound
    removeobject LOCALID_CINNABAR_MORTY             @ hidesprite 0x2
    removeobject LOCALID_CINNABAR_GENGAR
    fadescreen FADE_FROM_BLACK               @ fadescreen 0x0
    release
    end

EventScript_Morty_StatEditExplain::
    call_if_unset FLAG_DISABLE_EVS, EventScript_Morty_StatEditExplain2
    return

EventScript_Morty_StatEditExplain2:
    msgbox morty_Text_StatEditor_Explain
    return

EventScript_Morty_StatEditTellCap:
    callnative SetBuffer1ToEvCap
    msgbox johtoLeader_Text_CurrentEvCap
    setflag FLAG_UNLOCKED_STAT_EDITOR
    return


CinnabarIsland_PokemonLab_Entrance_EventScript_Gengar::	
    lock
	faceplayer
	waitse
	playmoncry SPECIES_FROSLASS, CRY_MODE_NORMAL
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_Gengar
	waitmoncry
	release
	end

CinnabarIsland_Gym_Text_PhotoOfBlaineAndFuji::
    .string "It's a photo of Blaine and\n"
    .string "Mr. Fuji.\p"
    .string "They're standing shoulder to\n"
    .string "shoulder with big grins.$"

CinnabarIsland_PokemonLab_Entrance_Text_StudyMonsExtensively::
    .string "We study Pokémon extensively\n"
    .string "every day.\p"
    .string "People often bring us rare Pokémon\n"
    .string "for examination.$"

CinnabarIsland_PokemonLab_Entrance_Text_PhotoOfLabFounderDrFuji::
    .string "A photo of the Lab's founder…\n"
    .string "Dr. Fuji?!$"

CinnabarIsland_PokemonLab_Entrance_Text_MeetingRoomSign::
    .string "Pokémon Lab\n"
    .string "Meeting Room$"

CinnabarIsland_PokemonLab_Entrance_Text_RAndDRoomSign::
    .string "Pokémon Lab\n"
    .string "R & D Room$"

CinnabarIsland_PokemonLab_Entrance_Text_TestingRoomSign::
    .string "Pokémon La\n"
    .string "Testing Room$"

gText_morty_1::
  .string "Hi, good of you to greet me.\p"
  .string "Kanto has seen quite a surge in\n"
  .string "appearances of Legendary Pokémon,\l"
  .string "so I've spent some time training here\l"
  .string "as of late.$"

gText_morty_askChallenge::
  .string "Perhaps you'd like to help me with\n"
  .string "my training?$"

gText_morty_2::
    .string "Help me reach a higher level!$"

gText_morty_Reject::
  .string "I see… Fine.$"

morty_Text_Defeat::
  .string "I have a lot more training to do.$"

gText_morty_3::
  .string "I see… Your journey has taken you\n"
  .string "to many different places.\p"
  .string "And you've witnessed much more\n"
  .string "than I.\p"
  .string "It seems many talented trainers I've\n"
  .string "met have gone through similar\l"
  .string "endeavors.\p"
  .string "Here, have this.$"

morty_Text_StatEditor_Explain::
  .string "I can raise your Effort Values cap\n"
  .string "so your team can grow even stronger.\p"
  .string "The Edit Stats option is now avail-\n"
  .string "able when viewing your Pokémon in\l"
  .string "the party menu.$"

gText_morty_4::
  .string "You may have something more than\n"
  .string "just strength.\p"
  .string "Take on the Pokémon League. That's\n"
  .string "a challenge more worthy of your time.\p"
  .string "I've stayed here for too long.\p"
  .string "Farewell.$"

gText_Morty_NotReady::
    .string "I'll only fight you once you've\n"
    .string "defeated all the trainers in Pokémon Mansion.$"

CinnabarIsland_PokemonLab_Entrance_Text_Gengar::
    .string "Garr!$"
