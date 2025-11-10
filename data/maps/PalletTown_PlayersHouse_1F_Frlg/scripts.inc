.set JOHTO_STARTER, 2
.set HOENN_STARTER, 3
.set SINNOH_STARTER, 4
.set UNOVA_STARTER, 5
.set KALOS_STARTER, 6
.set ALOLA_STARTER, 7
.set GALAR_STARTER, 8
.set PALDEA_STARTER, 9

PalletTown_PlayersHouse_1F_Frlg_MapScripts::
    map_script MAP_SCRIPT_ON_FRAME_TABLE LevelScripts_PalletTownHome
	.byte 0

LevelScripts_PalletTownHome:
    map_script_2 VAR_PALLET_TOWN_MOM_ASK_STARTER, 0, LevelScript_PalletTownAskStarterRegion
	.2byte 0

PalletTown_PlayersHouse_1F_EventScript_Mom::
	lock
	faceplayer
    setspeaker SP_NAME_MOM
	goto_if_set FLAG_BEAT_RIVAL_IN_OAKS_LAB, PalletTown_PlayersHouse_1F_EventScript_MomHeal
	checkplayergender
	call_if_eq VAR_RESULT, MALE, PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouMale
	call_if_eq VAR_RESULT, FEMALE, PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouFemale
	closemessage
	applymovement LOCALID_MOM, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouMale::
	msgbox PalletTown_PlayersHouse_1F_Text_AllBoysLeaveOakLookingForYou
	return

PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouFemale::
	msgbox PalletTown_PlayersHouse_1F_Text_AllGirlsLeaveOakLookingForYou
	return

PalletTown_PlayersHouse_1F_EventScript_MomHeal::
	msgbox PalletTown_PlayersHouse_1F_Text_YouShouldTakeQuickRest
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox PalletTown_PlayersHouse_1F_Text_LookingGreatTakeCare
	release
	end

@ Displays special text if interacted with from side or back (which are normally inaccessible)
PalletTown_PlayersHouse_1F_EventScript_TV::
	lockall
	goto_if_eq VAR_FACING, DIR_NORTH, PalletTown_PlayersHouse_1F_EventScript_TVScreen
	msgbox PalletTown_PlayersHouse_1F_Text_OopsWrongSide
	releaseall
	end

PalletTown_PlayersHouse_1F_EventScript_TVScreen::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, PalletTown_PlayersHouse_1F_EventScript_TVScreenMale
	call_if_eq VAR_RESULT, FEMALE, PalletTown_PlayersHouse_1F_EventScript_TVScreenFemale
	releaseall
	end

PalletTown_PlayersHouse_1F_EventScript_TVScreenMale::
	msgbox PalletTown_PlayersHouse_1F_Text_MovieOnTVFourBoysOnRailroad
	return

PalletTown_PlayersHouse_1F_EventScript_TVScreenFemale::
	msgbox PalletTown_PlayersHouse_1F_Text_MovieOnTVGirlOnBrickRoad
	return


LevelScript_PalletTownAskStarterRegion:
    applymovement LOCALID_MOM, Common_Movement_FaceRight
    waitmovement 0
    goto AskStarters
    end

AskStarters:
    setspeaker SP_NAME_MOM
    msgbox PalletTown_PlayersHouse_1F_Text_Mom_ProfAsks 
    goto SetStarters

OhOkay:
    setspeaker SP_NAME_MOM
    msgbox gText_Pallet_OkTakeCare 
    goto AskStarterEnd
    end

endofstarterscript:
    goto AskStarterEnd
    end

AskStarterEnd:
    setvar VAR_PALLET_TOWN_MOM_ASK_STARTER 0x1
    applymovement LOCALID_MOM, Common_Movement_FaceLeft
    waitmovement 0
    release
    end

SetStarters:
	@ multichoice 20, 0, MULTI_REGIONS, TRUE
    msgbox gText_WhichRegion, MSGBOX_DEFAULT
    dynmultichoice 25, 0, TRUE, 6, 0, DYN_MULTICHOICE_CB_NONE, gText_Kanto, gText_Johto, gText_Hoenn, gText_Sinnoh, gText_Unova, gText_Kalos, gText_Alola, gText_Galar, gText_Paldea
	@ return
	switch VAR_RESULT
	case 0, KantoStarter
	case 1, JohtoStarter
	case 2, HoennStarter
	case 3, SinnohStarter
	case 4, UnovaStarter
	case 5, KalosStarter
	case 6, AlolanStarter
	case 7, GalarStarter
	case 8, PaldeaStarter
	end

KantoStarter:
    setspeaker SP_NAME_MOM
    msgbox gText_KantoStarter 
    goto endofstarterscript

JohtoStarter: 
    setspeaker SP_NAME_MOM
    setvar VAR_STARTER_GENERATION JOHTO_STARTER
    msgbox gText_JohtoStarter 
    goto endofstarterscript

HoennStarter:
    setspeaker SP_NAME_MOM
    setvar VAR_STARTER_GENERATION HOENN_STARTER
    msgbox gText_HoennStarter 
    goto endofstarterscript

SinnohStarter:
    setspeaker SP_NAME_MOM
    setvar VAR_STARTER_GENERATION SINNOH_STARTER
    msgbox gText_SinnohStarter 
    goto endofstarterscript

UnovaStarter:
    setspeaker SP_NAME_MOM
    setvar VAR_STARTER_GENERATION UNOVA_STARTER
    msgbox gText_UnovaStarter 
    goto endofstarterscript

KalosStarter:
    setspeaker SP_NAME_MOM
    setvar VAR_STARTER_GENERATION KALOS_STARTER
    msgbox gText_KalosStarter 
    goto endofstarterscript

AlolanStarter: 
    setspeaker SP_NAME_MOM
    setvar VAR_STARTER_GENERATION ALOLA_STARTER
    msgbox gText_AlolaStarter 
    goto endofstarterscript

GalarStarter:
    setspeaker SP_NAME_MOM
    setvar VAR_STARTER_GENERATION GALAR_STARTER
    msgbox gText_GalarStarter 
    goto endofstarterscript

PaldeaStarter:
    setspeaker SP_NAME_MOM
    setvar VAR_STARTER_GENERATION PALDEA_STARTER
    msgbox gText_PaldeaStarter 
    goto endofstarterscript

PalletTown_PlayersHouse_1F_Text_AllBoysLeaveOakLookingForYou::
    .string "…Right.\n"
    .string "All boys leave home someday.\l"
    .string "It said so on TV.\p"
    .string "Oh, yes. Prof. Oak, next door, was\n"
    .string "looking for you.$"

PalletTown_PlayersHouse_1F_Text_AllGirlsLeaveOakLookingForYou::
    .string "…Right.\n"
    .string "All girls dream of traveling.\l"
    .string "It said so on TV.\p"
    .string "Oh, yes. Prof. Oak, next door, was\n"
    .string "looking for you.$"

PalletTown_PlayersHouse_1F_Text_YouShouldTakeQuickRest::
    .string "{PLAYER}!\n"
    .string "You should take a quick rest.$"

PalletTown_PlayersHouse_1F_Text_LookingGreatTakeCare::
    .string "Oh, good! You and your\n"
    .string "Pokémon are looking great.\l"
    .string "Take care now!$"

PalletTown_PlayersHouse_1F_Text_MovieOnTVFourBoysOnRailroad::
    .string "There's a movie on TV.\n"
    .string "Four boys are walking on railroad\l"
    .string "tracks.\p"
    .string "…I better go, too.$"

PalletTown_PlayersHouse_1F_Text_MovieOnTVGirlOnBrickRoad::
    .string "There's a movie on TV.\n"
    .string "A girl with her hair in pigtails is\l"
    .string "walking up a brick road.\p"
    .string "…I better go, too.$"

PalletTown_PlayersHouse_1F_Text_OopsWrongSide::
    .string "Oops, wrong side…$"

PalletTown_PlayersHouse_1F_Text_Mom_ProfAsks::
    .string "Mom: Hey {PLAYER}!\p"
	.string "The Professor wanted to ask if you\n"
	.string "had a specific region in mind for\l"
	.string "your Starter Pokémon.$"


gText_KantoStarter::
    .string "Ooh okay! Kanto it is!\n"
    .string "I'll let him know.$"

gText_JohtoStarter::
	.string "Ooh okay! Johto it is!\n"
	.string "I'll let him know.$"

gText_HoennStarter::
	.string "Ooh okay! Hoenn it is!\n"
	.string "I'll let him know.$"

gText_SinnohStarter::
	.string "Ooh okay! Sinnoh it is!\n"
	.string "I'll let him know.$"

gText_UnovaStarter::
    .string "Ooh okay! Unova it is!\n"
	.string "I'll let him know.$"

gText_KalosStarter::
    .string "Ooh okay! Kalos it is!\n"
	.string "I'll let him know.$"

gText_AlolaStarter::
    .string "Ooh okay! Alola it is!\n"
	.string "I'll let him know.$"

gText_GalarStarter::
    .string "Ooh okay! Galar it is!\n"
	.string "I'll let him know.$"

gText_PaldeaStarter::
    .string "Ooh okay! Paldea it is!\n"
	.string "I'll let him know.$"

gText_Pallet_OkTakeCare::
    .string "Ah okay then!\n"
	.string "Take care sweetie!$"

gText_WhichRegion::
   .string "Which region would you have a\n"
   .string "preference for?$"

gText_Kanto::
    .string "Kanto$"

gText_Johto::
    .string "Johto$"

@ gText_Hoenn::
@    .string "Hoenn$"

gText_Sinnoh::
    .string "Sinnoh$"

gText_Unova::
    .string "Unova$"

gText_Kalos::
    .string "Kalos$"

gText_Alola::
    .string "Alola$"

gText_Galar::
    .string "Galar$"

gText_Paldea::
    .string "Paldea$"
