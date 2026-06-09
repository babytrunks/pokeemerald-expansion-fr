.set SPOKE_TO_WOMAN_LAST,   FLAG_TEMP_2
.set SPOKE_TO_FAT_MAN_LAST, FLAG_TEMP_3

.equ HELIX_FOSSIL,     1
.equ DOME_FOSSIL,      2
.equ OLD_AMBER,        3
.equ ROOT_FOSSIL,      4
.equ CLAW_FOSSIL,      5
.equ ARMOR_FOSSIL,     6
.equ SKULL_FOSSIL,     7
.equ COVER_FOSSIL,     8
.equ PLUME_FOSSIL,     9
.equ JAW_FOSSIL,       10
.equ SAIL_FOSSIL,      11
.equ FOSSILIZED_BIRD_DRAKE,  12
.equ FOSSILIZED_FISH_DRAKE,  13
.equ FOSSILIZED_BIRD_DINO, 14
.equ FOSSILIZED_FISH_DINO,  15

VermilionCity_PokemonFanClub_Frlg_MapScripts::
	.byte 0

VermilionCity_PokemonFanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BIKE_VOUCHER, VermilionCity_PokemonFanClub_EventScript_AlreadyHeardStory
	msgbox VermilionCity_PokemonFanClub_Text_DidYouComeToHearAboutMyMons, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VermilionCity_PokemonFanClub_EventScript_ChairmanStory
	msgbox VermilionCity_PokemonFanClub_Text_ComeBackToHearStory
	release
	end

VermilionCity_PokemonFanClub_EventScript_AlreadyHeardStory::
	msgbox VermilionCity_PokemonFanClub_Text_DidntComeToSeeAboutMonsAgain
	release
	end

VermilionCity_PokemonFanClub_EventScript_ChairmanStory::
	msgbox VermilionCity_PokemonFanClub_Text_ChairmansStory
	checkitemspace ITEM_BIKE_VOUCHER
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_PokemonFanClub_EventScript_NoRoomForBikeVoucher
	setflag FLAG_GOT_BIKE_VOUCHER
	giveitem_msg VermilionCity_PokemonFanClub_Text_ReceivedBikeVoucherFromChairman, ITEM_BIKE_VOUCHER, 1, MUS_RG_OBTAIN_KEY_ITEM
	msgbox VermilionCity_PokemonFanClub_Text_ExplainBikeVoucher
	release
	end

VermilionCity_PokemonFanClub_EventScript_NoRoomForBikeVoucher::
	msgbox VermilionCity_PokemonFanClub_Text_MakeRoomForThis
	release
	end

VermilionCity_PokemonFanClub_EventScript_WorkerF::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, VermilionCity_PokemonFanClub_EventScript_WorkerFGameClear
	msgbox VermilionCity_PokemonFanClub_Text_ChairmanVeryVocalAboutPokemon
	release
	end

VermilionCity_PokemonFanClub_EventScript_WorkerFGameClear::
	famechecker FAMECHECKER_DAISY, 1
	msgbox VermilionCity_PokemonFanClub_Text_ChairmanReallyAdoresHisMons
	release
	end

VermilionCity_PokemonFanClub_EventScript_Woman::
	lock
	faceplayer
	goto_if_set SPOKE_TO_FAT_MAN_LAST, VermilionCity_PokemonFanClub_EventScript_WomanSpokeToFatMan
	msgbox VermilionCity_PokemonFanClub_Text_AdoreMySeel
	closemessage
	applymovement LOCALID_POKEMON_FAN_CLUB_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag SPOKE_TO_WOMAN_LAST
	release
	end

VermilionCity_PokemonFanClub_EventScript_WomanSpokeToFatMan::
	msgbox VermilionCity_PokemonFanClub_Text_SeelFarMoreAttractive
	closemessage
	applymovement LOCALID_POKEMON_FAN_CLUB_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	clearflag SPOKE_TO_FAT_MAN_LAST
	release
	end

VermilionCity_PokemonFanClub_EventScript_FatMan::
	lock
	faceplayer
	goto_if_set SPOKE_TO_WOMAN_LAST, VermilionCity_PokemonFanClub_EventScript_FatManSpokeToWoman
	msgbox VermilionCity_PokemonFanClub_Text_AdmirePikachusTail
	closemessage
	applymovement LOCALID_POKEMON_FAN_CLUB_FAT_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag SPOKE_TO_FAT_MAN_LAST
	release
	end

VermilionCity_PokemonFanClub_EventScript_FatManSpokeToWoman::
	msgbox VermilionCity_PokemonFanClub_Text_PikachuTwiceAsCute
	closemessage
	applymovement LOCALID_POKEMON_FAN_CLUB_FAT_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	clearflag SPOKE_TO_WOMAN_LAST
	release
	end

VermilionCity_PokemonFanClub_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox VermilionCity_PokemonFanClub_Text_Pikachu
	waitmoncry
	release
	end

VermilionCity_PokemonFanClub_EventScript_Seel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SEEL, CRY_MODE_NORMAL
	msgbox VermilionCity_PokemonFanClub_Text_Seel
	waitmoncry
	release
	end

VermilionCity_PokemonFanClub_EventScript_RulesSign1::
	msgbox VermilionCity_PokemonFanClub_Text_ListenPolitelyToOtherTrainers, MSGBOX_SIGN
	end

VermilionCity_PokemonFanClub_EventScript_RulesSign2::
	msgbox VermilionCity_PokemonFanClub_Text_SomeoneBragsBragBack, MSGBOX_SIGN
	end


VermilionCity_PokemonFanClub_EventScript_TamerTutor::
	lock
	faceplayer
    goto_if_quest_complete QUEST_FAN_CLUB_TUTOR, VermilionCity_PokemonFanClub_EventScript_TeachBoostingMoves	
	goto_if_quest_active QUEST_FAN_CLUB_TUTOR, VermilionCity_PokemonFanClub_EventScript_CheckBoy
	msgbox VermilionCity_FanClubTutor_Text_LookingForOffensiveMon
    setflag FLAG_SYS_QUEST_MENU_GET
 	questmenu QUEST_MENU_SET_ACTIVE QUEST_FAN_CLUB_TUTOR
    openquestmenu
    startquest QUEST_FAN_CLUB_TUTOR
	release
	end

VermilionCity_PokemonFanClub_EventScript_CheckBoy:
	msgbox VermilionCity_FanClubTutor_Text_BringMeAGoodBoy
	callnative CheckFollowerPokemonIsPerfectOffenses
	goto_if_eq VAR_RESULT, NO, VermilionCity_PokemonFanClub_EventScript_ThatsNotPerfOffenses
	setvar 0x8004, 0
	special BufferMonNickname
	msgbox VermilionCity_FanClubTutor_Text_HesHim
	completequest QUEST_FAN_CLUB_TUTOR
    waitmessage
    release
    end
	
VermilionCity_PokemonFanClub_EventScript_ThatsNotPerfOffenses: 
	msgbox VermilionCity_FanClubTutor_Text_ThatsNotPerfOffenses
	release
	end

VermilionCity_PokemonFanClub_EventScript_TeachBoostingMoves:
	msgbox VermilionCity_FanClubTutor_Text_DoYouWantBoostingTutor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_PokemonFanClub_EventScript_NoInterestInBoostingMoves
	msgbox VermilionCity_FanClubTutor_Text_WhatchaThinking
	dynmultichoice 25, 0, 0, 6, 0, DYN_MULTICHOICE_CB_NONE, PkmnCenterNurse_Text_FlameCharge, PkmnCenterNurse_Text_Trailblaze, PkmnCenterNurse_Text_PowerUpPunch, PkmnCenterNurse_Text_ChargeBeam, PkmnCenterNurse_Text_WorkUp, PkmnCenterNurse_Text_HoneClaws
	switch VAR_RESULT
	case MULTI_B_PRESSED, VermilionCity_PokemonFanClub_EventScript_NoInterestInBoostingMoves
	case 0, VermilionCity_PokemonFanClub_EventScript_TeachFlameCharge
	case 1, VermilionCity_PokemonFanClub_EventScript_TeachTrailblaze
	case 2, VermilionCity_PokemonFanClub_EventScript_TeachPowerUpPunch
	case 3, VermilionCity_PokemonFanClub_EventScript_TeachChargeBeam
	case 4, VermilionCity_PokemonFanClub_EventScript_TeachWorkUp
	case 5, VermilionCity_PokemonFanClub_EventScript_TeachHoneClaws
	end

VermilionCity_PokemonFanClub_EventScript_NoInterestInBoostingMoves::
	@ msgbox VermilionCity_FanClubTutor_Text_HopeToSeeYouAgain
	release
	end

VermilionCity_PokemonFanClub_EventScript_TeachFlameCharge:
	setvar VAR_0x8005, MOVE_FLAME_CHARGE
	goto VermilionCity_PokemonFanClub_EventScript_FinishBoostingMoves

VermilionCity_PokemonFanClub_EventScript_TeachTrailblaze:
	setvar VAR_0x8005, MOVE_TRAILBLAZE
	goto VermilionCity_PokemonFanClub_EventScript_FinishBoostingMoves

VermilionCity_PokemonFanClub_EventScript_TeachPowerUpPunch:
	setvar VAR_0x8005, MOVE_POWER_UP_PUNCH
	goto VermilionCity_PokemonFanClub_EventScript_FinishBoostingMoves

VermilionCity_PokemonFanClub_EventScript_TeachChargeBeam:
	setvar VAR_0x8005, MOVE_CHARGE_BEAM
	goto VermilionCity_PokemonFanClub_EventScript_FinishBoostingMoves

VermilionCity_PokemonFanClub_EventScript_TeachWorkUp:
	setvar VAR_0x8005, MOVE_WORK_UP
	goto VermilionCity_PokemonFanClub_EventScript_FinishBoostingMoves

VermilionCity_PokemonFanClub_EventScript_TeachHoneClaws:
	setvar VAR_0x8005, MOVE_HONE_CLAWS
	goto VermilionCity_PokemonFanClub_EventScript_FinishBoostingMoves

VermilionCity_PokemonFanClub_EventScript_FinishBoostingMoves:
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_PokemonFanClub_EventScript_NoInterestInBoostingMoves
	msgbox VermilionCity_FanClubTutor_Text_TaughtBoostingMoves
	release
	end

VermilionCity_FanClub_EventScript_FossilScientist::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 2, VermilionCity_FanClub_EventScript_GiveRevivedMon
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1, VermilionCity_FanClub_EventScript_FossilStillReviving
	call VermilionCity_FanClub_EventScript_CheckIfAnyFossils
	msgbox VermilionCity_FanClub_Text_HaveYouAFossilForMe
	goto_if_eq VAR_SCRIPT_TEMP, NO, VermilionCity_FanClub_EventScript_DontShowFossil
	checkitem ITEM_HELIX_FOSSIL
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_FossilScientist_AddHelixFossilToList
	checkitem ITEM_DOME_FOSSIL
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_FossilScientist_AddDomeFossilToList
	checkitem ITEM_OLD_AMBER
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_FossilScientist_AddOldAmberToList
	checkitem ITEM_ROOT_FOSSIL
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_FossilScientist_AddRootFossilToList
	checkitem ITEM_CLAW_FOSSIL
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_FossilScientist_AddClawFossilToList
	checkitem ITEM_ARMOR_FOSSIL
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_FossilScientist_AddArmorFossilToList
	checkitem ITEM_SKULL_FOSSIL
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_FossilScientist_AddSkullFossilToList
	checkitem ITEM_COVER_FOSSIL
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_FossilScientist_AddCoverFossilToList
	checkitem ITEM_PLUME_FOSSIL
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_FossilScientist_AddPlumeFossilToList
	checkitem ITEM_JAW_FOSSIL
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_FossilScientist_AddJawFossilToList
	checkitem ITEM_SAIL_FOSSIL
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_FossilScientist_AddSailFossilToList
	checkitem ITEM_FOSSILIZED_DRAKE
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_FossilScientist_AddFossilizedDrakeToList
	checkitem ITEM_FOSSILIZED_DINO
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_FossilScientist_AddFossilizedDinoToList
	dynmultistack 2, 0, FALSE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, VermilionCity_FanClub_EventScript_ShowHelixFossil
	case 1, VermilionCity_FanClub_EventScript_ShowDomeFossil
	case 2, VermilionCity_FanClub_EventScript_ShowOldAmber
	case 3, VermilionCity_FanClub_EventScript_ShowRootFossil
	case 4, VermilionCity_FanClub_EventScript_ShowClawFossil
	case 5, VermilionCity_FanClub_EventScript_ShowArmorFossil
	case 6, VermilionCity_FanClub_EventScript_ShowSkullFossil
	case 7, VermilionCity_FanClub_EventScript_ShowCoverFossil
	case 8, VermilionCity_FanClub_EventScript_ShowPlumeFossil
	case 9, VermilionCity_FanClub_EventScript_ShowJawFossil
	case 10, VermilionCity_FanClub_EventScript_ShowSailFossil
	case 11, VermilionCity_FanClub_EventScript_ShowFossilizedDrakeFossil
	case 12, VermilionCity_FanClub_EventScript_ShowFossilizedDinoFossil
	case 127, VermilionCity_FanClub_EventScript_DontShowFossil
	end

VermilionCity_FanClub_EventScript_FossilScientist_AddHelixFossilToList:
	dynmultipush VermilionCity_FanClub_Text_HelixFossil, 0
	return

VermilionCity_FanClub_EventScript_FossilScientist_AddDomeFossilToList:
	dynmultipush VermilionCity_FanClub_Text_DomeFossil, 1
	return

VermilionCity_FanClub_EventScript_FossilScientist_AddOldAmberToList:
	dynmultipush VermilionCity_FanClub_Text_OldAmber, 2
	return

VermilionCity_FanClub_EventScript_FossilScientist_AddRootFossilToList:
	dynmultipush VermilionCity_FanClub_Text_RootFossil, 3
	return

VermilionCity_FanClub_EventScript_FossilScientist_AddClawFossilToList:
	dynmultipush VermilionCity_FanClub_Text_ClawFossil, 4
	return

VermilionCity_FanClub_EventScript_FossilScientist_AddArmorFossilToList:
	dynmultipush VermilionCity_FanClub_Text_ArmorFossil, 5
	return

VermilionCity_FanClub_EventScript_FossilScientist_AddSkullFossilToList:
	dynmultipush VermilionCity_FanClub_Text_SkullFossil, 6
	return

VermilionCity_FanClub_EventScript_FossilScientist_AddCoverFossilToList:
	dynmultipush VermilionCity_FanClub_Text_CoverFossil, 7
	return

VermilionCity_FanClub_EventScript_FossilScientist_AddPlumeFossilToList:
	dynmultipush VermilionCity_FanClub_Text_PlumeFossil, 8
	return

VermilionCity_FanClub_EventScript_FossilScientist_AddJawFossilToList:
	dynmultipush VermilionCity_FanClub_Text_JawFossil, 9
	return

VermilionCity_FanClub_EventScript_FossilScientist_AddSailFossilToList:
	dynmultipush VermilionCity_FanClub_Text_SailFossil, 10
	return

VermilionCity_FanClub_EventScript_FossilScientist_AddFossilizedDrakeToList:
	setvar VAR_SCRIPT_TEMP FALSE
	checkitem ITEM_FOSSILIZED_BIRD
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_SetVarTempTrue
	checkitem ITEM_FOSSILIZED_FISH
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_SetVarTempTrue
	call_if_eq VAR_SCRIPT_TEMP, TRUE, VermilionCity_FanClub_EventScript_FossilScientist_SetFossilizedDrakeToList
	return

VermilionCity_FanClub_EventScript_FossilScientist_SetFossilizedDrakeToList:
	dynmultipush VermilionCity_FanClub_Text_FossilizedDrake, 11
	return

VermilionCity_FanClub_EventScript_FossilScientist_AddFossilizedDinoToList:
	setvar VAR_SCRIPT_TEMP FALSE
	checkitem ITEM_FOSSILIZED_BIRD
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_SetVarTempTrue
	checkitem ITEM_FOSSILIZED_FISH
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_SetVarTempTrue
	call_if_eq VAR_SCRIPT_TEMP, TRUE, VermilionCity_FanClub_EventScript_FossilScientist_SetFossilizedDinoToList
	return

VermilionCity_FanClub_EventScript_FossilScientist_SetFossilizedDinoToList:
	dynmultipush VermilionCity_FanClub_Text_FossilizedDino, 12
	return

VermilionCity_FanClub_EventScript_SetVarTempTrue::
	setvar VAR_SCRIPT_TEMP, TRUE
	return

VermilionCity_FanClub_EventScript_DontShowFossil::
	msgbox VermilionCity_FanClub_Text_NoIsTooBad
	release
	end


VermilionCity_FanClub_EventScript_CheckIfAnyFossils:
	setvar VAR_SCRIPT_TEMP, FALSE
	checkitem ITEM_HELIX_FOSSIL
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_SetVarTempTrue
	checkitem ITEM_DOME_FOSSIL
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_SetVarTempTrue
	checkitem ITEM_OLD_AMBER
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_SetVarTempTrue
	checkitem ITEM_ROOT_FOSSIL
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_SetVarTempTrue
	checkitem ITEM_CLAW_FOSSIL
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_SetVarTempTrue
	checkitem ITEM_ARMOR_FOSSIL
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_SetVarTempTrue
	checkitem ITEM_SKULL_FOSSIL
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_SetVarTempTrue
	checkitem ITEM_COVER_FOSSIL
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_SetVarTempTrue
	checkitem ITEM_PLUME_FOSSIL
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_SetVarTempTrue
	checkitem ITEM_JAW_FOSSIL
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_SetVarTempTrue
	checkitem ITEM_SAIL_FOSSIL
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_SetVarTempTrue
	checkitem ITEM_FOSSILIZED_DRAKE
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_SetVarTempTrue
	checkitem ITEM_FOSSILIZED_DINO
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_SetVarTempTrue
	return

VermilionCity_FanClub_EventScript_ShowHelixFossil::
	bufferspeciesname STR_VAR_1, SPECIES_OMANYTE
	bufferitemname STR_VAR_2, ITEM_HELIX_FOSSIL
	msgbox VermilionCity_FanClub_Text_ThatFossilIsOfMonMakeItLiveAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_FanClub_EventScript_DeclineReviveFossil
	msgbox VermilionCity_FanClub_Text_HandedFossilToWeirdDoctor
	textcolor NPC_TEXT_COLOR_MALE
	removeitem ITEM_HELIX_FOSSIL
	msgbox VermilionCity_FanClub_Text_TakesTimeGoForWalk
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, HELIX_FOSSIL
	release
	end

VermilionCity_FanClub_EventScript_ShowDomeFossil::
	bufferspeciesname STR_VAR_1, SPECIES_KABUTO
	bufferitemname STR_VAR_2, ITEM_DOME_FOSSIL
	msgbox VermilionCity_FanClub_Text_ThatFossilIsOfMonMakeItLiveAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_FanClub_EventScript_DeclineReviveFossil
	msgbox VermilionCity_FanClub_Text_HandedFossilToWeirdDoctor
	textcolor NPC_TEXT_COLOR_MALE
	removeitem ITEM_DOME_FOSSIL
	msgbox VermilionCity_FanClub_Text_TakesTimeGoForWalk
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, DOME_FOSSIL
	release
	end

VermilionCity_FanClub_EventScript_ShowOldAmber::
	bufferspeciesname STR_VAR_1, SPECIES_AERODACTYL
	bufferitemname STR_VAR_2, ITEM_OLD_AMBER
	msgbox VermilionCity_FanClub_Text_ThatFossilIsOfMonMakeItLiveAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_FanClub_EventScript_DeclineReviveFossil
	msgbox VermilionCity_FanClub_Text_HandedFossilToWeirdDoctor
	textcolor NPC_TEXT_COLOR_MALE
	removeitem ITEM_OLD_AMBER
	msgbox VermilionCity_FanClub_Text_TakesTimeGoForWalk
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, OLD_AMBER
	release
	end

VermilionCity_FanClub_EventScript_ShowRootFossil::
	bufferspeciesname STR_VAR_1, SPECIES_LILEEP
	bufferitemname STR_VAR_2, ITEM_ROOT_FOSSIL
	msgbox VermilionCity_FanClub_Text_ThatFossilIsOfMonMakeItLiveAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_FanClub_EventScript_DeclineReviveFossil
	msgbox VermilionCity_FanClub_Text_HandedFossilToWeirdDoctor
	textcolor NPC_TEXT_COLOR_MALE
	removeitem ITEM_ROOT_FOSSIL
	msgbox VermilionCity_FanClub_Text_TakesTimeGoForWalk
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, ROOT_FOSSIL
	release
	end

VermilionCity_FanClub_EventScript_ShowClawFossil::
	bufferspeciesname STR_VAR_1, SPECIES_ANORITH
	bufferitemname STR_VAR_2, ITEM_CLAW_FOSSIL
	msgbox VermilionCity_FanClub_Text_ThatFossilIsOfMonMakeItLiveAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_FanClub_EventScript_DeclineReviveFossil
	msgbox VermilionCity_FanClub_Text_HandedFossilToWeirdDoctor
	textcolor NPC_TEXT_COLOR_MALE
	removeitem ITEM_CLAW_FOSSIL
	msgbox VermilionCity_FanClub_Text_TakesTimeGoForWalk
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, CLAW_FOSSIL
	release
	end

VermilionCity_FanClub_EventScript_ShowArmorFossil::
	bufferspeciesname STR_VAR_1, SPECIES_SHIELDON
	bufferitemname STR_VAR_2, ITEM_ARMOR_FOSSIL
	msgbox VermilionCity_FanClub_Text_ThatFossilIsOfMonMakeItLiveAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_FanClub_EventScript_DeclineReviveFossil
	msgbox VermilionCity_FanClub_Text_HandedFossilToWeirdDoctor
	textcolor NPC_TEXT_COLOR_MALE
	removeitem ITEM_ARMOR_FOSSIL
	msgbox VermilionCity_FanClub_Text_TakesTimeGoForWalk
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, ARMOR_FOSSIL
	release
	end

VermilionCity_FanClub_EventScript_ShowSkullFossil::
	bufferspeciesname STR_VAR_1, SPECIES_CRANIDOS
	bufferitemname STR_VAR_2, ITEM_SKULL_FOSSIL
	msgbox VermilionCity_FanClub_Text_ThatFossilIsOfMonMakeItLiveAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_FanClub_EventScript_DeclineReviveFossil
	msgbox VermilionCity_FanClub_Text_HandedFossilToWeirdDoctor
	textcolor NPC_TEXT_COLOR_MALE
	removeitem ITEM_SKULL_FOSSIL
	msgbox VermilionCity_FanClub_Text_TakesTimeGoForWalk
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, SKULL_FOSSIL
	release
	end

VermilionCity_FanClub_EventScript_ShowCoverFossil::
	bufferspeciesname STR_VAR_1, SPECIES_TIRTOUGA
	bufferitemname STR_VAR_2, ITEM_COVER_FOSSIL
	msgbox VermilionCity_FanClub_Text_ThatFossilIsOfMonMakeItLiveAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_FanClub_EventScript_DeclineReviveFossil
	msgbox VermilionCity_FanClub_Text_HandedFossilToWeirdDoctor
	textcolor NPC_TEXT_COLOR_MALE
	removeitem ITEM_COVER_FOSSIL
	msgbox VermilionCity_FanClub_Text_TakesTimeGoForWalk
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, COVER_FOSSIL
	release
	end

VermilionCity_FanClub_EventScript_ShowPlumeFossil::
	bufferspeciesname STR_VAR_1, SPECIES_ARCHEN
	bufferitemname STR_VAR_2, ITEM_PLUME_FOSSIL
	msgbox VermilionCity_FanClub_Text_ThatFossilIsOfMonMakeItLiveAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_FanClub_EventScript_DeclineReviveFossil
	msgbox VermilionCity_FanClub_Text_HandedFossilToWeirdDoctor
	textcolor NPC_TEXT_COLOR_MALE
	removeitem ITEM_PLUME_FOSSIL
	msgbox VermilionCity_FanClub_Text_TakesTimeGoForWalk
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, PLUME_FOSSIL
	release
	end

VermilionCity_FanClub_EventScript_ShowJawFossil::
	bufferspeciesname STR_VAR_1, SPECIES_TYRUNT
	bufferitemname STR_VAR_2, ITEM_JAW_FOSSIL
	msgbox VermilionCity_FanClub_Text_ThatFossilIsOfMonMakeItLiveAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_FanClub_EventScript_DeclineReviveFossil
	msgbox VermilionCity_FanClub_Text_HandedFossilToWeirdDoctor
	textcolor NPC_TEXT_COLOR_MALE
	removeitem ITEM_JAW_FOSSIL
	msgbox VermilionCity_FanClub_Text_TakesTimeGoForWalk
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, JAW_FOSSIL
	release
	end

VermilionCity_FanClub_EventScript_ShowSailFossil::
	bufferspeciesname STR_VAR_1, SPECIES_AMAURA
	bufferitemname STR_VAR_2, ITEM_SAIL_FOSSIL
	msgbox VermilionCity_FanClub_Text_ThatFossilIsOfMonMakeItLiveAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_FanClub_EventScript_DeclineReviveFossil
	msgbox VermilionCity_FanClub_Text_HandedFossilToWeirdDoctor
	textcolor NPC_TEXT_COLOR_MALE
	removeitem ITEM_SAIL_FOSSIL
	msgbox VermilionCity_FanClub_Text_TakesTimeGoForWalk
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, SAIL_FOSSIL
	release
	end


VermilionCity_FanClub_EventScript_ShowFossilizedDrakeFossil::
	msgbox VermilionCity_FanClub_Text_ThatFossilMergesWithAnother 
	checkitem ITEM_FOSSILIZED_BIRD
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_AddFossilizedBirdText
	checkitem ITEM_FOSSILIZED_FISH
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_AddFossilizedFishText
	dynmultistack 10, 0, FALSE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, VermilionCity_FanClub_EventScript_ShowDracozolt
	case 1, VermilionCity_FanClub_EventScript_ShowDracovish
	case 127, VermilionCity_FanClub_EventScript_FossilScientist
	release
	end

VermilionCity_FanClub_EventScript_ShowDracozolt:
	bufferspeciesname STR_VAR_1, SPECIES_DRACOZOLT
	msgbox VermilionCity_FanClub_Text_ThatFossilIsOfMonMakeItLiveAgainVer2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_FanClub_EventScript_DeclineReviveFossil
	msgbox VermilionCity_FanClub_Text_HandedFossilToWeirdDoctor
	textcolor NPC_TEXT_COLOR_MALE
	removeitem ITEM_FOSSILIZED_BIRD
	removeitem ITEM_FOSSILIZED_DRAKE
	msgbox VermilionCity_FanClub_Text_TakesTimeGoForWalk
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, FOSSILIZED_BIRD_DRAKE
	release
	end

VermilionCity_FanClub_EventScript_ShowDracovish:
	bufferspeciesname STR_VAR_1, SPECIES_DRACOVISH
	msgbox VermilionCity_FanClub_Text_ThatFossilIsOfMonMakeItLiveAgainVer2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_FanClub_EventScript_DeclineReviveFossil
	msgbox VermilionCity_FanClub_Text_HandedFossilToWeirdDoctor
	textcolor NPC_TEXT_COLOR_MALE
	removeitem ITEM_FOSSILIZED_FISH
	removeitem ITEM_FOSSILIZED_DRAKE
	msgbox VermilionCity_FanClub_Text_TakesTimeGoForWalk
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, FOSSILIZED_FISH_DRAKE
	release
	end

VermilionCity_FanClub_EventScript_ShowArctovish:
	bufferspeciesname STR_VAR_1, SPECIES_ARCTOVISH
	msgbox VermilionCity_FanClub_Text_ThatFossilIsOfMonMakeItLiveAgainVer2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_FanClub_EventScript_DeclineReviveFossil
	msgbox VermilionCity_FanClub_Text_HandedFossilToWeirdDoctor
	textcolor NPC_TEXT_COLOR_MALE
	removeitem ITEM_FOSSILIZED_FISH
	removeitem ITEM_FOSSILIZED_DINO
	msgbox VermilionCity_FanClub_Text_TakesTimeGoForWalk
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, FOSSILIZED_FISH_DINO
	release
	end

VermilionCity_FanClub_EventScript_ShowArctozolt:
	bufferspeciesname STR_VAR_1, SPECIES_ARCTOVISH
	msgbox VermilionCity_FanClub_Text_ThatFossilIsOfMonMakeItLiveAgainVer2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_FanClub_EventScript_DeclineReviveFossil
	msgbox VermilionCity_FanClub_Text_HandedFossilToWeirdDoctor
	textcolor NPC_TEXT_COLOR_MALE
	removeitem ITEM_FOSSILIZED_BIRD
	removeitem ITEM_FOSSILIZED_DINO
	msgbox VermilionCity_FanClub_Text_TakesTimeGoForWalk
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, FOSSILIZED_BIRD_DINO
	release
	end



VermilionCity_FanClub_EventScript_AddFossilizedBirdText:
	dynmultipush VermilionCity_FanClub_Text_FossilizedBird, 0
	return

VermilionCity_FanClub_EventScript_AddFossilizedFishText:
	dynmultipush VermilionCity_FanClub_Text_FossilizedFish, 1
	return

VermilionCity_FanClub_EventScript_ShowFossilizedDinoFossil::
	msgbox VermilionCity_FanClub_Text_ThatFossilMergesWithAnother 
	checkitem ITEM_FOSSILIZED_BIRD
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_AddFossilizedBirdText
	checkitem ITEM_FOSSILIZED_FISH
	call_if_eq VAR_RESULT, TRUE, VermilionCity_FanClub_EventScript_AddFossilizedFishText
	dynmultistack 10, 0, FALSE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, VermilionCity_FanClub_EventScript_ShowArctozolt
	case 1, VermilionCity_FanClub_EventScript_ShowArctovish
	case 127, VermilionCity_FanClub_EventScript_FossilScientist
	release
	end

VermilionCity_FanClub_EventScript_DeclineReviveFossil::
	msgbox VermilionCity_FanClub_Text_YouComeAgain
	release
	end

VermilionCity_FanClub_EventScript_FossilStillReviving::
	msgbox VermilionCity_FanClub_Text_TakesTimeGoForWalk
	release
	end

VermilionCity_FanClub_EventScript_GiveRevivedMon::
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, HELIX_FOSSIL, VermilionCity_FanClub_EventScript_GiveOmanyte
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, DOME_FOSSIL, VermilionCity_FanClub_EventScript_GiveKabuto
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, OLD_AMBER, VermilionCity_FanClub_EventScript_GiveAerodactyl
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, ROOT_FOSSIL, VermilionCity_FanClub_EventScript_GiveLileep
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, CLAW_FOSSIL, VermilionCity_FanClub_EventScript_GiveAnorith
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, ARMOR_FOSSIL, VermilionCity_FanClub_EventScript_GiveShieldon
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, SKULL_FOSSIL, VermilionCity_FanClub_EventScript_GiveCranidos
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, COVER_FOSSIL, VermilionCity_FanClub_EventScript_GiveTirtouga
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, PLUME_FOSSIL, VermilionCity_FanClub_EventScript_GiveArchen
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, JAW_FOSSIL, VermilionCity_FanClub_EventScript_GiveTyrunt
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, SAIL_FOSSIL, VermilionCity_FanClub_EventScript_GiveAmaura
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, FOSSILIZED_BIRD_DRAKE, VermilionCity_FanClub_EventScript_GiveDracozolt
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, FOSSILIZED_FISH_DRAKE, VermilionCity_FanClub_EventScript_GiveDracovish
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, FOSSILIZED_BIRD_DINO, VermilionCity_FanClub_EventScript_GiveArctozolt
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, FOSSILIZED_FISH_DINO, VermilionCity_FanClub_EventScript_GiveArctovish
	end

VermilionCity_FanClub_EventScript_GiveOmanyte::
	setvar VAR_TEMP_1, SPECIES_OMANYTE
	bufferspeciesname STR_VAR_1, SPECIES_OMANYTE
	msgbox VermilionCity_FanClub_Text_FossilMonBackToLife
	givemon SPECIES_OMANYTE, 5
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	goto_if_eq VAR_RESULT, 0, VermilionCity_FanClub_EventScript_NicknameMonParty
	goto_if_eq VAR_RESULT, 1, VermilionCity_FanClub_EventScript_NicknameMonPC
	end

VermilionCity_FanClub_EventScript_GiveKabuto::
	setvar VAR_TEMP_1, SPECIES_KABUTO
	bufferspeciesname STR_VAR_1, SPECIES_KABUTO
	msgbox VermilionCity_FanClub_Text_FossilMonBackToLife
	givemon SPECIES_KABUTO, 5
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	goto_if_eq VAR_RESULT, 0, VermilionCity_FanClub_EventScript_NicknameMonParty
	goto_if_eq VAR_RESULT, 1, VermilionCity_FanClub_EventScript_NicknameMonPC
	end

VermilionCity_FanClub_EventScript_GiveAerodactyl::
	setvar VAR_TEMP_1, SPECIES_AERODACTYL
	bufferspeciesname STR_VAR_1, SPECIES_AERODACTYL
	msgbox VermilionCity_FanClub_Text_FossilMonBackToLife
	givemon SPECIES_AERODACTYL, 5
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	goto_if_eq VAR_RESULT, 0, VermilionCity_FanClub_EventScript_NicknameMonParty
	goto_if_eq VAR_RESULT, 1, VermilionCity_FanClub_EventScript_NicknameMonPC
	end

VermilionCity_FanClub_EventScript_GiveLileep::
	setvar VAR_TEMP_1, SPECIES_LILEEP
	bufferspeciesname STR_VAR_1, SPECIES_LILEEP
	msgbox VermilionCity_FanClub_Text_FossilMonBackToLife
	givemon SPECIES_LILEEP, 5
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	goto_if_eq VAR_RESULT, 0, VermilionCity_FanClub_EventScript_NicknameMonParty
	goto_if_eq VAR_RESULT, 1, VermilionCity_FanClub_EventScript_NicknameMonPC
	end

VermilionCity_FanClub_EventScript_GiveAnorith::
	setvar VAR_TEMP_1, SPECIES_ANORITH
	bufferspeciesname STR_VAR_1, SPECIES_ANORITH
	msgbox VermilionCity_FanClub_Text_FossilMonBackToLife
	givemon SPECIES_ANORITH, 5
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	goto_if_eq VAR_RESULT, 0, VermilionCity_FanClub_EventScript_NicknameMonParty
	goto_if_eq VAR_RESULT, 1, VermilionCity_FanClub_EventScript_NicknameMonPC
	end

VermilionCity_FanClub_EventScript_GiveShieldon::
	setvar VAR_TEMP_1, SPECIES_SHIELDON
	bufferspeciesname STR_VAR_1, SPECIES_SHIELDON
	msgbox VermilionCity_FanClub_Text_FossilMonBackToLife
	givemon SPECIES_SHIELDON, 5
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	goto_if_eq VAR_RESULT, 0, VermilionCity_FanClub_EventScript_NicknameMonParty
	goto_if_eq VAR_RESULT, 1, VermilionCity_FanClub_EventScript_NicknameMonPC
	end

VermilionCity_FanClub_EventScript_GiveCranidos::
	setvar VAR_TEMP_1, SPECIES_CRANIDOS
	bufferspeciesname STR_VAR_1, SPECIES_CRANIDOS
	msgbox VermilionCity_FanClub_Text_FossilMonBackToLife
	givemon SPECIES_CRANIDOS, 5
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	goto_if_eq VAR_RESULT, 0, VermilionCity_FanClub_EventScript_NicknameMonParty
	goto_if_eq VAR_RESULT, 1, VermilionCity_FanClub_EventScript_NicknameMonPC
	end

VermilionCity_FanClub_EventScript_GiveTirtouga::
	setvar VAR_TEMP_1, SPECIES_TIRTOUGA
	bufferspeciesname STR_VAR_1, SPECIES_TIRTOUGA
	msgbox VermilionCity_FanClub_Text_FossilMonBackToLife
	givemon SPECIES_TIRTOUGA, 5
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	goto_if_eq VAR_RESULT, 0, VermilionCity_FanClub_EventScript_NicknameMonParty
	goto_if_eq VAR_RESULT, 1, VermilionCity_FanClub_EventScript_NicknameMonPC
	end

VermilionCity_FanClub_EventScript_GiveArchen::
	setvar VAR_TEMP_1, SPECIES_ARCHEN
	bufferspeciesname STR_VAR_1, SPECIES_ARCHEN
	msgbox VermilionCity_FanClub_Text_FossilMonBackToLife
	givemon SPECIES_ARCHEN, 5
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	goto_if_eq VAR_RESULT, 0, VermilionCity_FanClub_EventScript_NicknameMonParty
	goto_if_eq VAR_RESULT, 1, VermilionCity_FanClub_EventScript_NicknameMonPC
	end

VermilionCity_FanClub_EventScript_GiveTyrunt::
	setvar VAR_TEMP_1, SPECIES_TYRUNT
	bufferspeciesname STR_VAR_1, SPECIES_TYRUNT
	msgbox VermilionCity_FanClub_Text_FossilMonBackToLife
	givemon SPECIES_TYRUNT, 5
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	goto_if_eq VAR_RESULT, 0, VermilionCity_FanClub_EventScript_NicknameMonParty
	goto_if_eq VAR_RESULT, 1, VermilionCity_FanClub_EventScript_NicknameMonPC
	end

VermilionCity_FanClub_EventScript_GiveAmaura::
	setvar VAR_TEMP_1, SPECIES_AMAURA
	bufferspeciesname STR_VAR_1, SPECIES_AMAURA
	msgbox VermilionCity_FanClub_Text_FossilMonBackToLife
	givemon SPECIES_AMAURA, 5
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	goto_if_eq VAR_RESULT, 0, VermilionCity_FanClub_EventScript_NicknameMonParty
	goto_if_eq VAR_RESULT, 1, VermilionCity_FanClub_EventScript_NicknameMonPC
	end

VermilionCity_FanClub_EventScript_GiveDracozolt::
	setvar VAR_TEMP_1, SPECIES_DRACOZOLT
	bufferspeciesname STR_VAR_1, SPECIES_DRACOZOLT
	msgbox VermilionCity_FanClub_Text_FossilMonBackToLife
	givemon SPECIES_DRACOZOLT, 5
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	goto_if_eq VAR_RESULT, 0, VermilionCity_FanClub_EventScript_NicknameMonParty
	goto_if_eq VAR_RESULT, 1, VermilionCity_FanClub_EventScript_NicknameMonPC
	end

VermilionCity_FanClub_EventScript_GiveDracovish::
	setvar VAR_TEMP_1, SPECIES_DRACOVISH
	bufferspeciesname STR_VAR_1, SPECIES_DRACOVISH
	msgbox VermilionCity_FanClub_Text_FossilMonBackToLife
	givemon SPECIES_DRACOVISH, 5
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	goto_if_eq VAR_RESULT, 0, VermilionCity_FanClub_EventScript_NicknameMonParty
	goto_if_eq VAR_RESULT, 1, VermilionCity_FanClub_EventScript_NicknameMonPC
	end

VermilionCity_FanClub_EventScript_GiveArctozolt::
	setvar VAR_TEMP_1, SPECIES_ARCTOZOLT
	bufferspeciesname STR_VAR_1, SPECIES_ARCTOZOLT
	msgbox VermilionCity_FanClub_Text_FossilMonBackToLife
	givemon SPECIES_ARCTOZOLT, 5
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	goto_if_eq VAR_RESULT, 0, VermilionCity_FanClub_EventScript_NicknameMonParty
	goto_if_eq VAR_RESULT, 1, VermilionCity_FanClub_EventScript_NicknameMonPC
	end

VermilionCity_FanClub_EventScript_GiveArctovish::
	setvar VAR_TEMP_1, SPECIES_ARCTOVISH
	bufferspeciesname STR_VAR_1, SPECIES_ARCTOVISH
	msgbox VermilionCity_FanClub_Text_FossilMonBackToLife
	givemon SPECIES_ARCTOVISH, 5
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	goto_if_eq VAR_RESULT, 0, VermilionCity_FanClub_EventScript_NicknameMonParty
	goto_if_eq VAR_RESULT, 1, VermilionCity_FanClub_EventScript_NicknameMonPC
	end

VermilionCity_FanClub_EventScript_NicknameMonParty::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message VermilionCity_FanClub_Text_ReceivedMonFromDoctor
	waitmessage
	waitfanfare
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 0
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_FanClub_EventScript_EndGiveMon
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto VermilionCity_FanClub_EventScript_EndGiveMon
	end

VermilionCity_FanClub_EventScript_NicknameMonPC::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message VermilionCity_FanClub_Text_ReceivedMonFromDoctor
	waitmessage
	waitfanfare
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 0
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_FanClub_EventScript_MonSentToPC
	call Common_EventScript_NameReceivedBoxMon
	goto VermilionCity_FanClub_EventScript_MonSentToPC
	end

VermilionCity_FanClub_EventScript_MonSentToPC::
	call Common_EventScript_TransferredToPC
	goto VermilionCity_FanClub_EventScript_EndGiveMon
	end

VermilionCity_FanClub_EventScript_EndGiveMon::
	release
	end

VermilionCity_PokemonFanClub_Text_AdmirePikachusTail::
    .string "Won't you admire my Pikachu's\n"
    .string "adorable tail?$"

VermilionCity_PokemonFanClub_Text_PikachuTwiceAsCute::
    .string "Humph!\p"
    .string "My Pikachu is twice as cute as\n"
    .string "that one!$"

VermilionCity_PokemonFanClub_Text_AdoreMySeel::
    .string "I just adore my SEEL!\n"
    .string "It's so lovable!\p"
    .string "It squeals, “Kyuuuh,” when I\n"
    .string "hug it!$"

VermilionCity_PokemonFanClub_Text_SeelFarMoreAttractive::
    .string "Oh, dear!\p"
    .string "My SEEL is far more attractive.\n"
    .string "By double, I would say.$"

VermilionCity_PokemonFanClub_Text_Pikachu::
    .string "PIKACHU: Chu! Pikachu!$"

VermilionCity_PokemonFanClub_Text_Seel::
    .string "SEEL: Kyuoo!$"

VermilionCity_PokemonFanClub_Text_DidYouComeToHearAboutMyMons::
    .string "I chair the Pokémon Fan Club!\p"
    .string "I raise more than a hundred\n"
    .string "Pokémon!\p"
    .string "I'm very fussy when it comes to\n"
    .string "Pokémon! I surely am!\p"
    .string "So…\p"
    .string "Did you come visit to hear about\n"
    .string "my Pokémon?$"

VermilionCity_PokemonFanClub_Text_ChairmansStory::
    .string "Good!\n"
    .string "Then listen up!\p"
    .string "My favorite RAPIDASH…\p"
    .string "It's…cute…lovely…smart… \n"
    .string "plus…amazing…you think so?…\l"
    .string "oh yes…it's…stunning…\l"
    .string "kindly…love it!\p"
    .string "Hug it…when…sleeping…warm\n"
    .string "and cuddly…spectacular…\l"
    .string "ravishing…\l"
    .string "…Oops! Look at the time!\l"
    .string "I kept you too long!\p"
    .string "Thanks for hearing me out!\n"
    .string "I want you to have this!$"

VermilionCity_PokemonFanClub_Text_ReceivedBikeVoucherFromChairman::
    .string "{PLAYER} received a BIKE VOUCHER\n"
    .string "from the CHAIRMAN.$"

VermilionCity_PokemonFanClub_Text_ExplainBikeVoucher::
    .string "Take that BIKE VOUCHER to the\n"
    .string "BIKE SHOP in Cerulean City.\p"
    .string "Exchange that for a BICYCLE\n"
    .string "free of charge!\p"
    .string "Don't worry, my favorite FEAROW\n"
    .string "will FLY me anywhere I need to go.\p"
    .string "So, I have no need for a BICYCLE.\p"
    .string "I hope you like cycling!$"

VermilionCity_PokemonFanClub_Text_ComeBackToHearStory::
    .string "Oh. Come back when you want to\n"
    .string "hear my story!$"

VermilionCity_PokemonFanClub_Text_DidntComeToSeeAboutMonsAgain::
    .string "Hello, {PLAYER}!\p"
    .string "Did you come see me about my\n"
    .string "Pokémon again?\p"
    .string "No?\n"
    .string "Too bad!$"

VermilionCity_PokemonFanClub_Text_MakeRoomForThis::
    .string "Make room for this!$"

VermilionCity_PokemonFanClub_Text_ChairmanVeryVocalAboutPokemon::
    .string "Our CHAIRMAN is very vocal about\n"
    .string "Pokémon.$"

VermilionCity_PokemonFanClub_Text_ListenPolitelyToOtherTrainers::
    .string "Let's all listen politely to other\n"
    .string "TRAINERS!$"

VermilionCity_PokemonFanClub_Text_SomeoneBragsBragBack::
    .string "If someone brags, brag right back!$"

VermilionCity_PokemonFanClub_Text_ChairmanReallyAdoresHisMons::
    .string "Our CHAIRMAN really does adore his\n"
    .string "Pokémon.\p"
    .string "But the person who is most liked by\n"
    .string "Pokémon is DAISY, I think.$"

VermilionCity_FanClubTutor_Text_LookingForOffensiveMon:
	.string "{COLOR BLUE}Ooh, you look like a good trainer!\n"
	.string "Tell you what - I love when Pokémon\l"
	.string "hit hard and fast!\p"
	.string "{PAUSE 200}.{PAUSE 200}.{PAUSE 200}.Uhh yeah, pause.\p"
	.string "What I mean is, I'd like to see a\n"
	.string "Pokémon you've perfected in its\l"
	.string "speed and offenses.\p"
	.string "Show me that and I can teach you some\n"
	.string "cool moves.$"

VermilionCity_FanClubTutor_Text_BringMeAGoodBoy:
	.string "I'd like to see a Pokémon you've\n"
	.string "perfected in its speed and offenses.\p"
	.string "Show me that and I can teach you some\n"
	.string "cool moves.$"

VermilionCity_FanClubTutor_Text_ThatsNotPerfOffenses:
	.string "Hmm… that's not quite it.$"

VermilionCity_FanClubTutor_Text_DoYouWantBoostingTutor:
	.string "Hey buddy! You want to learn some\n"
	.string "boosting moves?$"

VermilionCity_FanClubTutor_Text_HesHim:
	.string "Oh yup.{PAUSE 200}.{PAUSE 200}.{PAUSE 200}\n"
	.string "That {STR_VAR_1}, yo that {STR_VAR_1}\l"
	.string "kinda nice.\p"
	.string "Alright, as agreed I can teach you\n"
	.string "some boosting moves now. The Nurse's\l"
	.string "Aide should be able to teach you them\l"
	.string "as well.$"

VermilionCity_FanClubTutor_Text_WhatchaThinking:
	.string "Whatcha thinking?$"

VermilionCity_FanClubTutor_Text_TaughtBoostingMoves:
	.string "Faster and stronger!\n"
	.string "I hope you dig it!$"

VermilionCity_FanClub_Text_HaveYouAFossilForMe::
    .string "Hiya!\p"
    .string "I am important doctor.\n"
    .string "Yes, very much so, indeed.\p"
    .string "Here, I study rare Pokémon fossils.\n"
    .string "All the time, I study.\p"
    .string "You!\n"
    .string "Have you a fossil for me?$"

VermilionCity_FanClub_Text_NoIsTooBad::
    .string "No!\n"
    .string "Is too bad!$"

VermilionCity_FanClub_Text_FossilMonBackToLife::
    .string "You late.\n"
    .string "Where were you?\p"
    .string "Your fossil is back to life!\n"
    .string "It was {STR_VAR_1} like I think!$"

VermilionCity_FanClub_Text_ReceivedMonFromDoctor::
    .string "{PLAYER} received the {STR_VAR_1}\n"
    .string "from the doctor.$"

VermilionCity_FanClub_Text_ThatFossilIsOfMonMakeItLiveAgain::
    .string "Oh!\n"
    .string "That is {STR_VAR_2}, it is!\p"
    .string "It is fossil of {STR_VAR_1},\n"
    .string "a Pokémon that is already extinct!\p"
    .string "My Resurrection Machine will make\n"
    .string "that Pokémon live again!$"

VermilionCity_FanClub_Text_ThatFossilIsOfMonMakeItLiveAgainVer2::
    .string "Oh!\n"
    .string "It is fossil of {STR_VAR_1},\l"
    .string "a Pokémon that is already extinct!\p"
    .string "My Resurrection Machine will make\n"
    .string "that Pokémon live again!$"

VermilionCity_FanClub_Text_ThatFossilMergesWithAnother::
	.string "Oh! That Fossil merges with another.\n"
	.string "Which one you merge with?$"

@ TODO: Resolve text dump error below?
VermilionCity_FanClub_Text_HandedFossilToWeirdDoctor::
    .string "So!\n"
    .string "You hurry and give me that!\p"
    .string "{FONT_NORMAL}{PLAYER} handed over the\n"
    .string "{STR_VAR_2} to the weird doctor.$"

VermilionCity_FanClub_Text_TakesTimeGoForWalk::
    .string "I take a little time!\n"
    .string "You go for walk a little while!$"


VermilionCity_FanClub_Text_HelixFossil::
	.string "Helix Fossil$"

VermilionCity_FanClub_Text_DomeFossil::
	.string "Dome Fossil$"

VermilionCity_FanClub_Text_OldAmber::
	.string "Old Amber$"

VermilionCity_FanClub_Text_RootFossil::
	.string "Root Fossil$"

VermilionCity_FanClub_Text_ClawFossil::
	.string "Claw Fossil$"

VermilionCity_FanClub_Text_ArmorFossil::
	.string "Armor Fossil$"

VermilionCity_FanClub_Text_SkullFossil::
	.string "Skull Fossil$"

VermilionCity_FanClub_Text_CoverFossil::
	.string "Cover Fossil$"

VermilionCity_FanClub_Text_PlumeFossil::
	.string "Plume Fossil$"

VermilionCity_FanClub_Text_JawFossil::
	.string "Jaw Fossil$"

VermilionCity_FanClub_Text_SailFossil::
	.string "Sail Fossil$"

VermilionCity_FanClub_Text_FossilizedBird::
	.string "Fossilized Bird$"

VermilionCity_FanClub_Text_FossilizedFish::
	.string "Fossilized Fish$"

VermilionCity_FanClub_Text_FossilizedDrake::
	.string "Fossilized Drake$"

VermilionCity_FanClub_Text_FossilizedDino::
	.string "Fossilized Dino$"

VermilionCity_FanClub_Text_YouComeAgain::
    .string "Aiyah!\n"
    .string "You come again!$"
