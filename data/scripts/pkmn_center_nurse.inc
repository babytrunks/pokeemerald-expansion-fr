Common_EventScript_PkmnCenterNurse::
	lock
	faceplayer
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, CountPlayerTrainerStars
	goto_if_eq VAR_RESULT, 4, EventScript_PkmnCenterNurse_GoldCard
	goto EventScript_PkmnCenterNurse_HealPkmn
	end

EventScript_PkmnCenterNurse_Goodbye::
	message gText_WeHopeToSeeYouAgain
	return

@ VAR_0x8004 is 1 when player has Gold Card; jumps are identical
EventScript_PkmnCenterNurse_HealPkmn::
	incrementgamestat GAME_STAT_USED_POKECENTER
	call_if_eq VAR_0x8004, 0, EventScript_PkmnCenterNurse_IllTakeYourPkmn
	call_if_eq VAR_0x8004, 1, EventScript_PkmnCenterNurse_IllTakeYourPkmn2
	waitmessage
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn
	checkitem ITEM_POKEVIAL
	goto_if_eq VAR_RESULT, FALSE, EventScript_PkmnCenterNurse_GiveVial
EndOfPkmnCenterNurse:
	goto_if_unset FLAG_POKERUS_EXPLAINED, EventScript_PkmnCenterNurse_CheckPokerus
	goto EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom
	end

EventScript_PkmnCenterNurse_GiveVial:
	msgbox gText_Nurse_YouDontHaveVial, MSGBOX_DEFAULT
	giveitem ITEM_POKEVIAL
	@ pokevial VIAL_UP,VIAL_SIZE,9
	@ pokevial VIAL_REFRESH
	setvar VAR_POKEVIAL_MAX_SIZE 15
	setvar VAR_POKEVIAL_CURRENT_DOSE 15
	msgbox gText_Nurse_YouDontHaveVial2, MSGBOX_DEFAULT
	goto EndOfPkmnCenterNurse

EventScript_PkmnCenterNurse_IllTakeYourPkmn::
	@ message gText_IllTakeYourPkmn
	return

EventScript_PkmnCenterNurse_IllTakeYourPkmn2::
	@ message gText_IllTakeYourPkmn2
	return

EventScript_PkmnCenterNurse_TakeAndHealPkmn::
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Turn @ Changed from Common_Movement_WalkInPlaceFasterLeft to force the follower to enter their Poké Ball
	waitmovement 0
	dofieldeffect FLDEFF_POKECENTER_HEAL
.if OW_UNION_DISABLE_CHECK == FALSE && OW_FLAG_MOVE_UNION_ROOM_CHECK != 0
	setflag OW_FLAG_MOVE_UNION_ROOM_CHECK
	call CableClub_OnResume
	clearflag OW_FLAG_MOVE_UNION_ROOM_CHECK
.endif
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	applymovement VAR_0x800B, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	return

EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom::
	specialvar VAR_RESULT, PlayerNotAtTrainerHillEntrance
	goto_if_eq VAR_RESULT, 0, EventScript_PkmnCenterNurse_ReturnPkmn
	specialvar VAR_RESULT, BufferUnionRoomPlayerName
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, EventScript_PkmnCenterNurse_ReturnPkmn
	goto_if_eq VAR_0x8008, 1, EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom
	end

@ VAR_0x8004 is 1 when player has Gold Card
EventScript_PkmnCenterNurse_ReturnPkmn::
	goto_if_eq VAR_0x8004, 1, EventScript_PkmnCenterNurse_ReturnPkmn2
	@ message gText_RestoredPkmnToFullHealth
	@ waitmessage
	@ applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
	@ waitmovement 0
	message gText_WeHopeToSeeYouAgain
	closemessage
	goto EventScript_PkmnCenterNurse_PlayerTurn
	return

EventScript_PkmnCenterNurse_ReturnPkmn2::
	@ message gText_ThankYouForWaiting
	@ waitmessage
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	@ message gText_WeHopeToSeeYouAgain2
	goto EventScript_PkmnCenterNurse_PlayerTurn
	return

EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom::
	goto_if_set FLAG_NURSE_UNION_ROOM_REMINDER, EventScript_PkmnCenterNurse_ReturnPkmn
	msgbox gText_RestoredPkmnToFullHealth, MSGBOX_DEFAULT
	setflag FLAG_NURSE_UNION_ROOM_REMINDER
	message CableClub_Text_PlayerIsWaiting
	waitmessage
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	message gText_WeHopeToSeeYouAgain
	return

EventScript_PkmnCenterNurse_CheckPokerus::
	specialvar VAR_RESULT, IsPokerusInParty
	goto_if_eq VAR_RESULT, TRUE, EventScript_PkmnCenterNurse_ExplainPokerus
	goto_if_eq VAR_RESULT, FALSE, EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom
	end

EventScript_PkmnCenterNurse_ExplainPokerus::
	message gText_PokerusExplanation
	setflag FLAG_POKERUS_EXPLAINED
	return

EventScript_PkmnCenterNurse_GoldCard::
	goto_if_set FLAG_NURSE_MENTIONS_GOLD_CARD, EventScript_PkmnCenterNurse_AskForUsual
	setflag FLAG_NURSE_MENTIONS_GOLD_CARD
	msgbox gText_WelcomeCutShort, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement VAR_0x800B, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x800B, Common_Movement_Delay48
	waitmovement 0
	msgbox gText_NoticesGoldCard, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_GoldCardHealPkmn
	message gText_WeHopeToSeeYouAgain2
	return

EventScript_PkmnCenterNurse_AskForUsual::
	msgbox gText_YouWantTheUsual, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_GoldCardHealPkmn
	message gText_WeHopeToSeeYouAgain2
	return

EventScript_PkmnCenterNurse_GoldCardHealPkmn::
	setvar VAR_0x8004, 1
	goto EventScript_PkmnCenterNurse_HealPkmn
	end

Movement_PkmnCenterNurse_Bow:
	nurse_joy_bow
	delay_4
	step_end

Movement_PkmnCenterNurse_Turn:
	walk_in_place_faster_left
	step_end

EventScript_PkmnCenterNurse_PlayerTurn::
   @ closemessage
   applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
   waitmovement 0
   release
   end

EventScript_PkmnCenterNurse_Aide::
	lock
	call_if_quest_complete QUEST_NATURE_CHANGER, PkmnCenterNurse_NatureChangeOption
	dynmultipush PkmnCenterNurse_Text_MoveTutor, 1
	call_if_set FLAG_NES_GAVE_INFINITE_CANDY, PkmnCenterNurse_LevelCapOptions
	msgbox PkmnCenterNurse_Text_WhatService
	@ dynmultipush PkmnCenterNurse_Text_GenderSwap, 4
	dynmultistack 0, 0, FALSE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case MULTI_B_PRESSED, PkmnCenterNurse_Aide_End
	case 0, PkmnCenterNurse_EventScript_WantNatureChange
	case 1, PkmnCenterNurse_EventScript_WantMoveTutor
	case 2, PkmnCenterNurse_EventScript_PartyToLvlCap
	case 3, PkmnCenterNurse_EventScript_PkmnToLvlCap
	case 4, PkmnCenterNurse_EventScript_SwapGender
	release
	end

PkmnCenterNurse_LevelCapOptions:
	dynmultipush PkmnCenterNurse_Text_PartyToLevelCap, 2
	dynmultipush PkmnCenterNurse_Text_PkmnToLevelCap, 3
	return

PkmnCenterNurse_NatureChangeOption:
	dynmultipush PkmnCenterNurse_Text_NatureChanger, 0
	return

PkmnCenterNurse_EventScript_WantNatureChange::
	msgbox PkmnCenterNurse_Text_InterestedInNatureChange MSGBOX_YESNO
	switch VAR_RESULT
	case NO, EventScript_PkmnCenterNurse_Aide
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, EventScript_PkmnCenterNurse_Aide
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, PkmnCenterNurse_CantOperateOnEgg
	bufferspeciesname STR_VAR_1, VAR_RESULT
	msgbox PkmnCenterNurse_Text_WhatNature
	dynmultipush Debug_EventScript_ChangeNature_Text_Hardy, 0
	dynmultipush Debug_EventScript_ChangeNature_Text_Lonely, 1
	dynmultipush Debug_EventScript_ChangeNature_Text_Brave, 2
	dynmultipush Debug_EventScript_ChangeNature_Text_Adamant, 3
	dynmultipush Debug_EventScript_ChangeNature_Text_Naughty, 4
	dynmultipush Debug_EventScript_ChangeNature_Text_Bold, 5
	dynmultipush Debug_EventScript_ChangeNature_Text_Docile, 6
	dynmultipush Debug_EventScript_ChangeNature_Text_Relaxed, 7
	dynmultipush Debug_EventScript_ChangeNature_Text_Impish, 8
	dynmultipush Debug_EventScript_ChangeNature_Text_Lax, 9
	dynmultipush Debug_EventScript_ChangeNature_Text_Timid, 10
	dynmultipush Debug_EventScript_ChangeNature_Text_Hasty, 11
	dynmultipush Debug_EventScript_ChangeNature_Text_Serious, 12
	dynmultipush Debug_EventScript_ChangeNature_Text_Jolly, 13
	dynmultipush Debug_EventScript_ChangeNature_Text_Naive, 14
	dynmultipush Debug_EventScript_ChangeNature_Text_Modest, 15
	dynmultipush Debug_EventScript_ChangeNature_Text_Mild, 16
	dynmultipush Debug_EventScript_ChangeNature_Text_Quiet, 17
	dynmultipush Debug_EventScript_ChangeNature_Text_Bashful, 18
	dynmultipush Debug_EventScript_ChangeNature_Text_Rash, 19
	dynmultipush Debug_EventScript_ChangeNature_Text_Calm, 20
	dynmultipush Debug_EventScript_ChangeNature_Text_Gentle, 21
	dynmultipush Debug_EventScript_ChangeNature_Text_Sassy, 22
	dynmultipush Debug_EventScript_ChangeNature_Text_Careful, 23
	dynmultipush Debug_EventScript_ChangeNature_Text_Quirky, 24
	dynmultistack 0, 0, FALSE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case MULTI_B_PRESSED, PalletTown_ProfessorOaks_EventScript_End
	special SetHiddenNature
	msgbox PkmnCenterNurse_Text_PkmnNatureChangeDone
	releaseall
	end

PkmnCenterNurse_EventScript_WantMoveTutor:
	goto_if_unset FLAG_BADGE01_GET, PkmnCenterNurse_EventScript_StartingMoveTutors
	dynmultipush PkmnCenterNurse_Text_StartingTutors, 0
	call_if_set FLAG_BADGE01_GET, PkmnCenterNurse_SetBoulderBadgeTutor
	call_if_set FLAG_BADGE02_GET, PkmnCenterNurse_SetCascadeBadgeTutor
	call_if_set FLAG_BADGE03_GET, PkmnCenterNurse_SetThunderBadgeTutor
	call_if_set FLAG_BADGE04_GET, PkmnCenterNurse_SetRainbowBadgeTutor
	call_if_set FLAG_BADGE05_GET, PkmnCenterNurse_SetSoulBadgeTutor
	call_if_set FLAG_BADGE06_GET, PkmnCenterNurse_SetMarshBadgeTutor
	call_if_set FLAG_BADGE07_GET, PkmnCenterNurse_SetVolcanoBadgeTutor
	call_if_set FLAG_BADGE08_GET, PkmnCenterNurse_SetEarthBadgeTutor
	dynmultistack 0, 0, FALSE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case MULTI_B_PRESSED, EventScript_PkmnCenterNurse_Aide
	case 0, PkmnCenterNurse_EventScript_StartingMoveTutors
	case 1, PkmnCenterNurse_EventScript_BoulderMoveTutors
	case 2, PkmnCenterNurse_EventScript_CascadeMoveTutors
	case 3, PkmnCenterNurse_EventScript_ThunderMoveTutors
	case 4, PkmnCenterNurse_EventScript_RainbowMoveTutors
	case 5, PkmnCenterNurse_EventScript_SoulMoveTutors
	case 6, PkmnCenterNurse_EventScript_MarshMoveTutors
	case 7, PkmnCenterNurse_EventScript_VolcanoMoveTutors
	case 8, PkmnCenterNurse_EventScript_EarthMoveTutors
	end 

PkmnCenterNurse_SetBoulderBadgeTutor:
	dynmultipush PkmnCenterNurse_Text_BoulderBadgeTutors, 1
	return

PkmnCenterNurse_SetCascadeBadgeTutor:
	dynmultipush PkmnCenterNurse_Text_CascadeBadgeTutors, 2
	return

PkmnCenterNurse_SetThunderBadgeTutor:
	dynmultipush PkmnCenterNurse_Text_ThunderBadgeTutors, 3
	return

PkmnCenterNurse_SetRainbowBadgeTutor:
	dynmultipush PkmnCenterNurse_Text_RainbowBadgeTutors, 4
	return

PkmnCenterNurse_SetSoulBadgeTutor:
	dynmultipush PkmnCenterNurse_Text_SoulBadgeTutors, 5
	return

PkmnCenterNurse_SetMarshBadgeTutor:
	dynmultipush PkmnCenterNurse_Text_MarshBadgeTutors, 6
	return

PkmnCenterNurse_SetVolcanoBadgeTutor:
	dynmultipush PkmnCenterNurse_Text_VolcanoBadgeTutors, 7
	return

PkmnCenterNurse_SetEarthBadgeTutor:
	dynmultipush PkmnCenterNurse_Text_EarthBadgeTutors, 8
	return

PkmnCenterNurse_EventScript_StartingMoveTutors:
	dynmultipush PkmnCenterNurse_Text_Swift, 0
	dynmultipush PkmnCenterNurse_Text_FalseSwipe, 1
	dynmultipush PkmnCenterNurse_Text_MagicalLeaf, 2
	dynmultipush PkmnCenterNurse_Text_BugBite, 3
	dynmultipush PkmnCenterNurse_Text_AirCutter, 4
	dynmultistack 0, 0, FALSE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case MULTI_B_PRESSED, EventScript_PkmnCenterNurse_Aide
	case 0, PkmnCenterNurse_Tutor_Swift
	case 1, PkmnCenterNurse_Tutor_FalseSwipe
	case 2, PkmnCenterNurse_Tutor_MagicalLeaf
	case 3, PkmnCenterNurse_Tutor_BugBite
	case 4, PkmnCenterNurse_Tutor_AirCutter
	end

PkmnCenterNurse_EventScript_BoulderMoveTutors:
	call_if_quest_complete QUEST_FANG_TUTOR, PkmnCenterNurse_EventScript_FangTutors
	dynmultipush PkmnCenterNurse_Text_Round, 3
	dynmultipush PkmnCenterNurse_Text_MudShot, 4
	dynmultipush PkmnCenterNurse_Text_OminousWind, 5
	dynmultipush PkmnCenterNurse_Text_AncientPower, 6
	dynmultipush PkmnCenterNurse_Text_VacuumWave, 7
	dynmultistack 0, 0, FALSE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case MULTI_B_PRESSED, EventScript_PkmnCenterNurse_Aide
	case 0, PkmnCenterNurse_Tutor_FireFang
	case 1, PkmnCenterNurse_Tutor_IceFang
	case 2, PkmnCenterNurse_Tutor_ThunderFang
	case 3, PkmnCenterNurse_Tutor_Round
	case 4, PkmnCenterNurse_Tutor_Mudshot
	case 5, PkmnCenterNurse_Tutor_OminousWind
	case 6, PkmnCenterNurse_Tutor_AncientPower
	case 7, PkmnCenterNurse_Tutor_VacuumWave
	goto PkmnCenterNurse_EventScript_WantMoveTutor
	
	end

PkmnCenterNurse_EventScript_FangTutors:
	dynmultipush gText_FireFang, 0
	dynmultipush gText_IceFang, 1
	dynmultipush gText_ThunderFang, 2
	return

PkmnCenterNurse_EventScript_CascadeMoveTutors:
	call_if_quest_complete QUEST_FAN_CLUB_TUTOR, PkmnCenterNurse_EventScript_VermFanClubTutors
	call_if_set FLAG_TUTOR_SEISMIC_TOSS, PkmnCenterNurse_EventScript_SeismicTossTutor
	dynmultipush PkmnCenterNurse_Text_Hex, 6
	dynmultipush PkmnCenterNurse_Text_StompingTantrum, 7
	dynmultistack 0, 0, FALSE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case MULTI_B_PRESSED, EventScript_PkmnCenterNurse_Aide
	case 0, PkmnCenterNurse_Tutor_FlameCharge
	case 1, PkmnCenterNurse_Tutor_Trailblaze
	case 2, PkmnCenterNurse_Tutor_PowerUpPunch
	case 3, PkmnCenterNurse_Tutor_ChargeBeam
	case 4, PkmnCenterNurse_Tutor_WorkUp
	case 5, PkmnCenterNurse_Tutor_HoneClaws
	case 6, PkmnCenterNurse_Tutor_Hex
	case 7, PkmnCenterNurse_Tutor_StompingTantrum
	case 8, PkmnCenterNurse_Tutor_SeismicToss
	goto PkmnCenterNurse_EventScript_WantMoveTutor
	end

PkmnCenterNurse_EventScript_VermFanClubTutors:
	dynmultipush PkmnCenterNurse_Text_FlameCharge, 0
	dynmultipush PkmnCenterNurse_Text_Trailblaze, 1
	dynmultipush PkmnCenterNurse_Text_PowerUpPunch, 2
	dynmultipush PkmnCenterNurse_Text_ChargeBeam, 3
	dynmultipush PkmnCenterNurse_Text_WorkUp, 4
	dynmultipush PkmnCenterNurse_Text_HoneClaws, 5
	return

PkmnCenterNurse_EventScript_SeismicTossTutor:
	dynmultipush PkmnCenterNurse_Text_SeismicToss, 8
	return

PkmnCenterNurse_Tutor_Swift:
	setvar VAR_0x8005, MOVE_SWIFT
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_FalseSwipe:
	setvar VAR_0x8005, MOVE_FALSE_SWIPE
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_MagicalLeaf:
	setvar VAR_0x8005, MOVE_MAGICAL_LEAF
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_BugBite:
	setvar VAR_0x8005, MOVE_BUG_BITE
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_AirCutter:
	setvar VAR_0x8005, MOVE_AIR_CUTTER
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_Round:
	setvar VAR_0x8005, MOVE_ROUND
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_Mudshot:
	setvar VAR_0x8005, MOVE_MUD_SHOT
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_OminousWind:
	setvar VAR_0x8005, MOVE_OMINOUS_WIND
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_AncientPower:
	setvar VAR_0x8005, MOVE_ANCIENT_POWER
	goto PkmnCenterNurse_Tutor_TeachMove
PkmnCenterNurse_Tutor_VacuumWave:
	setvar VAR_0x8005, MOVE_VACUUM_WAVE
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_FireFang:
	setvar VAR_0x8005, MOVE_FIRE_FANG
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_IceFang:
	setvar VAR_0x8005, MOVE_ICE_FANG
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_ThunderFang:
	setvar VAR_0x8005, MOVE_THUNDER_FANG
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_FlameCharge:
	setvar VAR_0x8005, MOVE_FLAME_CHARGE
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_Trailblaze:
	setvar VAR_0x8005, MOVE_TRAILBLAZE
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_PowerUpPunch:
	setvar VAR_0x8005, MOVE_POWER_UP_PUNCH
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_ChargeBeam:
	setvar VAR_0x8005, MOVE_CHARGE_BEAM
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_WorkUp:
	setvar VAR_0x8005, MOVE_WORK_UP
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_HoneClaws:
	setvar VAR_0x8005, MOVE_HONE_CLAWS
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_SeismicToss:
	setvar VAR_0x8005, MOVE_SEISMIC_TOSS
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_IcyWind:
	setvar VAR_0x8005, MOVE_ICY_WIND
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_StompingTantrum:
	setvar VAR_0x8005, MOVE_STOMPING_TANTRUM
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_AirSlash:
	setvar VAR_0x8005, MOVE_AIR_SLASH
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_MysticalFire:
	setvar VAR_0x8005, MOVE_MYSTICAL_FIRE
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_Hex:
	setvar VAR_0x8005, MOVE_HEX
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_SignalBeam:
	setvar VAR_0x8005, MOVE_SIGNAL_BEAM
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_TailSlap:
	setvar VAR_0x8005, MOVE_TAIL_SLAP
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_RockBlast:
	setvar VAR_0x8005, MOVE_ROCK_BLAST
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_IcicleSpear:
	setvar VAR_0x8005, MOVE_ICICLE_SPEAR
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_Counter:
	setvar VAR_0x8005, MOVE_COUNTER
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_BugBuzz:
	setvar VAR_0x8005, MOVE_BUG_BUZZ
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_BodySlam:
	setvar VAR_0x8005, MOVE_BODY_SLAM
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_PhantomForce:
	setvar VAR_0x8005, MOVE_PHANTOM_FORCE
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_LeafBlade:
	setvar VAR_0x8005, MOVE_LEAF_BLADE
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_PowerGem:
	setvar VAR_0x8005, MOVE_POWER_GEM
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_FocusPunch:
	setvar VAR_0x8005, MOVE_FOCUS_PUNCH
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_PsychicFangs:
	setvar VAR_0x8005, MOVE_PSYCHIC_FANGS
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_DrillRun:
	setvar VAR_0x8005, MOVE_DRILL_RUN
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_BlazeKick:
	setvar VAR_0x8005, MOVE_BLAZE_KICK
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_PainSplit:
	setvar VAR_0x8005, MOVE_PAIN_SPLIT
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_AlluringVoice:
	setvar VAR_0x8005, MOVE_ALLURING_VOICE
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_FoulPlay:
	setvar VAR_0x8005, MOVE_FOUL_PLAY
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_SwordsDance:
	setvar VAR_0x8005, MOVE_SWORDS_DANCE
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_NastyPlot:
	setvar VAR_0x8005, MOVE_NASTY_PLOT
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_BulkUp:
	setvar VAR_0x8005, MOVE_BULK_UP
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_CalmMind:
	setvar VAR_0x8005, MOVE_CALM_MIND
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_Tutor_MeteorBeam:
	setvar VAR_0x8005, MOVE_METEOR_BEAM
	goto PkmnCenterNurse_Tutor_TeachMove

PkmnCenterNurse_EventScript_ThunderMoveTutors:
	dynmultipush PkmnCenterNurse_Text_SignalBeam, 0
	dynmultipush PkmnCenterNurse_Text_TailSlap, 1
	dynmultipush PkmnCenterNurse_Text_RockBlast, 2
	dynmultipush PkmnCenterNurse_Text_IcicleSpear, 3
	call_if_set FLAG_TUTOR_COUNTER, PkmnCenterNurse_EventScript_CounterTutor
	dynmultistack 0, 0, FALSE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case MULTI_B_PRESSED, EventScript_PkmnCenterNurse_Aide
	case 0, PkmnCenterNurse_Tutor_SignalBeam
	case 1, PkmnCenterNurse_Tutor_TailSlap
	case 2, PkmnCenterNurse_Tutor_RockBlast
	case 3, PkmnCenterNurse_Tutor_IcicleSpear
	goto PkmnCenterNurse_EventScript_WantMoveTutor
	end

PkmnCenterNurse_EventScript_CounterTutor:
	dynmultipush PkmnCenterNurse_Text_Counter, 6
	return

PkmnCenterNurse_EventScript_RainbowMoveTutors:
	dynmultipush PkmnCenterNurse_Text_BugBuzz, 0
	dynmultipush PkmnCenterNurse_Text_BodySlam, 1
	dynmultipush PkmnCenterNurse_Text_PhantomForce, 2
	dynmultipush PkmnCenterNurse_Text_LeafBlade, 3
	dynmultipush PkmnCenterNurse_Text_PowerGem, 4
	dynmultipush PkmnCenterNurse_Text_FocusPunch, 5
	dynmultipush PkmnCenterNurse_Text_PsychicFangs, 6
	dynmultistack 0, 0, FALSE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case MULTI_B_PRESSED, EventScript_PkmnCenterNurse_Aide
	case 0, PkmnCenterNurse_Tutor_BugBuzz
	case 1, PkmnCenterNurse_Tutor_BodySlam
	case 2, PkmnCenterNurse_Tutor_PhantomForce
	case 3, PkmnCenterNurse_Tutor_LeafBlade
	case 4, PkmnCenterNurse_Tutor_PowerGem
	case 5, PkmnCenterNurse_Tutor_FocusPunch
	case 6, PkmnCenterNurse_Tutor_PsychicFangs
	goto PkmnCenterNurse_EventScript_WantMoveTutor

PkmnCenterNurse_EventScript_SoulMoveTutors:
	dynmultipush PkmnCenterNurse_Text_DrillRun, 0
	dynmultipush PkmnCenterNurse_Text_BlazeKick, 1
	dynmultipush PkmnCenterNurse_Text_PainSplit, 2
	dynmultipush PkmnCenterNurse_Text_AlluringVoice, 3
	dynmultipush PkmnCenterNurse_Text_FoulPlay, 4
	dynmultistack 0, 0, FALSE, 5, FALSE, 0, NULL
	switch VAR_RESULT
	case MULTI_B_PRESSED, EventScript_PkmnCenterNurse_Aide
	case 0, PkmnCenterNurse_Tutor_DrillRun
	case 1, PkmnCenterNurse_Tutor_BlazeKick
	case 2, PkmnCenterNurse_Tutor_PainSplit
	case 3, PkmnCenterNurse_Tutor_AlluringVoice
	case 4, PkmnCenterNurse_Tutor_FoulPlay
	goto PkmnCenterNurse_EventScript_WantMoveTutor

PkmnCenterNurse_EventScript_MarshMoveTutors:
	dynmultipush PkmnCenterNurse_Text_SwordsDance, 0
	dynmultipush PkmnCenterNurse_Text_NastyPlot, 1
	dynmultipush PkmnCenterNurse_Text_BulkUp, 2
	dynmultipush PkmnCenterNurse_Text_CalmMind, 3
	dynmultipush PkmnCenterNurse_Text_MeteorBeam, 4
	dynmultistack 0, 0, FALSE, 5, FALSE, 0, NULL
	switch VAR_RESULT
	case MULTI_B_PRESSED, EventScript_PkmnCenterNurse_Aide
	case 0, PkmnCenterNurse_Tutor_SwordsDance
	case 1, PkmnCenterNurse_Tutor_NastyPlot
	case 2, PkmnCenterNurse_Tutor_BulkUp
	case 3, PkmnCenterNurse_Tutor_CalmMind
	case 4, PkmnCenterNurse_Tutor_MeteorBeam
	goto PkmnCenterNurse_EventScript_WantMoveTutor

PkmnCenterNurse_EventScript_VolcanoMoveTutors:
	goto EventScript_PkmnCenterNurse_Aide

PkmnCenterNurse_EventScript_EarthMoveTutors:
	goto EventScript_PkmnCenterNurse_Aide

PkmnCenterNurse_Tutor_TeachMove:
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, PkmnCenterNurse_EventScript_WantMoveTutor
	release
	end


PkmnCenterNurse_EventScript_PartyToLvlCap:
	msgbox PkmnCenterNurse_Text_SetPartyToLevelCap MSGBOX_YESNO
	switch VAR_RESULT
	case NO, EventScript_PkmnCenterNurse_Aide
	callnative SetTeamToLevelCap
	msgbox PkmnCenterNurse_Text_SetPartyToLevelCapDone
	release
	end


PkmnCenterNurse_EventScript_PkmnToLvlCap:
	msgbox PkmnCenterNurse_Text_WhichPokemonDoYouWantLvlCap 
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, EventScript_PkmnCenterNurse_Aide
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, PkmnCenterNurse_CantOperateOnEgg
	bufferspeciesname STR_VAR_1, VAR_RESULT
	msgbox PkmnCenterNurse_Text_RaisePokemonToLvlCap MSGBOX_YESNO
	switch VAR_RESULT
	case NO, EventScript_PkmnCenterNurse_Aide
	callnative SetPkmnToLevelCap
	msgbox PkmnCenterNurse_Text_PkmnRaisedToCapDone
	release
	end

PkmnCenterNurse_EventScript_SwapGender:
	msgbox PkmnCenterNurse_Text_DoYouWantToSwapGender MSGBOX_YESNO
	switch VAR_RESULT
	case NO, EventScript_PkmnCenterNurse_Aide
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, EventScript_PkmnCenterNurse_Aide
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, PkmnCenterNurse_CantOperateOnEgg
	callnative GetSelectedPokemonGender
	goto_if_eq VAR_RESULT, 0xFE, PkmnCenterNurse_CantOperateOnGenderless
	msgbox PkmnCenterNurse_Text_SwapGenderOfPkmn MSGBOX_YESNO
	switch VAR_RESULT
	case NO, EventScript_PkmnCenterNurse_Aide
	callnative SwapSelectedPokemonGender
	release
	end

PkmnCenterNurse_CantOperateOnEgg::
	msgbox PkmnCenterNurse_Text_CantOperateOnEgg
	goto EventScript_PkmnCenterNurse_Aide
	end

PkmnCenterNurse_Aide_End:
	release
	end

PkmnCenterNurse_Text_MoveTutor:
	.string "Move Tutors$"

PkmnCenterNurse_Text_NatureChanger:
	.string "Nature Change$"

PkmnCenterNurse_Text_GenderSwap:
	.string "Gender Swap$"

PkmnCenterNurse_Text_PartyToLevelCap:
	.string "Party To Level Cap$"

PkmnCenterNurse_Text_PkmnToLevelCap:
	.string "{PKMN} To Level Cap$"

PkmnCenterNurse_Text_MysteryGift:
	.string "Mystery Gift$"

PkmnCenterNurse_Text_WhatService:
	.string "{COLOR RED}What service would be of interest?$"

PkmnCenterNurse_Text_CantOperateOnEgg:
	.string "{COLOR RED}…I can't operate on an egg.$"

PkmnCenterNurse_Text_WhatNature:
	.string "{COLOR RED}What nature would you like for {STR_VAR_1}?$"

PkmnCenterNurse_Text_SetPartyToLevelCapDone: 
	.string "{COLOR RED}…Okay, your team has been set to the\n"
	.string "Level Cap of {STR_VAR_2}.$"

PkmnCenterNurse_Text_WhichPokemonDoYouWantLvlCap:
	.string "{COLOR RED}Select the {PKMN} whose level you'd like to\n"
	.string "raise to the Level Cap.$"

PkmnCenterNurse_Text_RaisePokemonToLvlCap:
	.string "{COLOR RED}Raise {STR_VAR_1} to\n"
	.string "the Level Cap?$"

PkmnCenterNurse_Text_SetPartyToLevelCap:
	.string "{COLOR RED}Shall I raise your party's levels to the\n"
	.string "Level Cap?$"

PkmnCenterNurse_Text_PkmnRaisedToCapDone:
	.string "{COLOR RED}{STR_VAR_1} has been raised to the\n"
	.string "Level Cap of {STR_VAR_2}.$"

PkmnCenterNurse_Text_InterestedInNatureChange:
	.string "{COLOR RED}Are you interested in swapping\n"
	.string "a Pokémon's nature?$"

PkmnCenterNurse_Text_PkmnNatureChangeDone:
	.string "{COLOR RED}…Okay, your {STR_VAR_1}'s Nature has\n"
	.string "been changed to {STR_VAR_2}.$"

PkmnCenterNurse_Text_DoYouWantToSwapGender:
	.string "{COLOR RED}Do you want to swap the Gender\n"
	.string "of one of your Pokémon?$"

PkmnCenterNurse_CantOperateOnGenderless:
	.string "{COLOR RED}…That Pokémon doesn't have a gender.$"

PkmnCenterNurse_Text_SwapGenderOfPkmn:
	.string "{COLOR RED}Swap the Gender of {STR_VAR_1}?$"

PkmnCenterNurse_Text_Swift:
	.string "Swift$"

PkmnCenterNurse_Text_FalseSwipe:
	.string "False Swipe$"

PkmnCenterNurse_Text_MagicalLeaf:
	.string "Magical Leaf$"

PkmnCenterNurse_Text_BugBite:
	.string "Bug Bite$"

PkmnCenterNurse_Text_AirCutter:
	.string "Air Cutter$"

PkmnCenterNurse_Text_Round:
	.string "Round$"

PkmnCenterNurse_Text_MudShot:
	.string "Mud Shot$"

PkmnCenterNurse_Text_OminousWind:
	.string "Ominous Wind$"

PkmnCenterNurse_Text_VacuumWave:
	.string "Vacuum Wave$"

PkmnCenterNurse_Text_FlameCharge::
	.string "Flame Charge$"

PkmnCenterNurse_Text_Trailblaze::
	.string "Trailblaze$"

PkmnCenterNurse_Text_PowerUpPunch::
	.string "Power-Up Punch$"

PkmnCenterNurse_Text_ChargeBeam::
	.string "Charge Beam$"

PkmnCenterNurse_Text_WorkUp::
	.string "Work Up$"

PkmnCenterNurse_Text_HoneClaws::
	.string "Hone Claws$"

PkmnCenterNurse_Text_IcyWind:
	.string "Icy Wind$"

PkmnCenterNurse_Text_AncientPower:
	.string "Ancient Power$"

PkmnCenterNurse_Text_StompingTantrum:
	.string "Stomping Tantrum$"

PkmnCenterNurse_Text_AirSlash:
	.string "Air Slash$"

PkmnCenterNurse_Text_MysticalFire:
	.string "Mystical Fire$"

PkmnCenterNurse_Text_Hex:
	.string "Hex$"

PkmnCenterNurse_Text_SignalBeam:
	.string "Signal Beam$"

PkmnCenterNurse_Text_ScorchingSands:
	.string "Scorching Sands$"

PkmnCenterNurse_Text_TailSlap:
	.string "Tail Slap$"

PkmnCenterNurse_Text_RockBlast:
	.string "Rock Blast$"

PkmnCenterNurse_Text_IcicleSpear:
	.string "Icicle Spear$"

PkmnCenterNurse_Text_BugBuzz:
	.string "Bug Buzz$"

PkmnCenterNurse_Text_BodySlam:
	.string "Body Slam$"

PkmnCenterNurse_Text_PhantomForce:
	.string "Phantom Force$"

PkmnCenterNurse_Text_LeafBlade:
	.string "Leaf Blade$"

PkmnCenterNurse_Text_PowerGem:
	.string "Power Gem$"

PkmnCenterNurse_Text_FocusPunch:
	.string "Focus Punch$"

PkmnCenterNurse_Text_PsychicFangs:
	.string "Psychic Fangs$"

PkmnCenterNurse_Text_Counter:
	.string "Counter$"

PkmnCenterNurse_Text_DrillRun:
	.string "Drill Run$"

PkmnCenterNurse_Text_BlazeKick:
	.string "Blaze Kick$"

PkmnCenterNurse_Text_PainSplit:
	.string "Pain Split$"

PkmnCenterNurse_Text_AlluringVoice:
	.string "Alluring Voice$"

PkmnCenterNurse_Text_FoulPlay:
	.string "Foul Play$"

PkmnCenterNurse_Text_SwordsDance:
	.string "Swords Dance$"

PkmnCenterNurse_Text_NastyPlot:
	.string "Nasty Plot$"

PkmnCenterNurse_Text_BulkUp:
	.string "Bulk Up$"

PkmnCenterNurse_Text_CalmMind:
	.string "Calm Mind$"

PkmnCenterNurse_Text_MeteorBeam:
	.string "Meteor Beam$"

PkmnCenterNurse_Text_SeismicToss:
	.string "Seismic Toss$"

PkmnCenterNurse_Text_StartingTutors:
	.string "Starting Tutors$"

PkmnCenterNurse_Text_BoulderBadgeTutors:
	.string "Boulder Badge Tutors$"

PkmnCenterNurse_Text_CascadeBadgeTutors:
	.string "Cascade Badge Tutors$"

PkmnCenterNurse_Text_ThunderBadgeTutors:
	.string "Thunder Badge Tutors$"

PkmnCenterNurse_Text_RainbowBadgeTutors:
	.string "Rainbow Badge Tutors$"

PkmnCenterNurse_Text_SoulBadgeTutors:
	.string "Soul Badge Tutors$"

PkmnCenterNurse_Text_MarshBadgeTutors:
	.string "Marsh Badge Tutors$"

PkmnCenterNurse_Text_VolcanoBadgeTutors:
	.string "Volcano Badge Tutors$"

PkmnCenterNurse_Text_EarthBadgeTutors:
	.string "Earth Badge Tutors$"
