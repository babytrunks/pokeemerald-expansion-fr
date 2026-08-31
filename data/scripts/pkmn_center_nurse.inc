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
   call_if_set FLAG_AUTOSAVE_ENABLED, Common_EventScript_AutoSave
   release
   end

EventScript_PkmnCenterNurse_Aide::
	lock
	call_if_quest_complete QUEST_NATURE_CHANGER, PkmnCenterNurse_NatureChangeOption
	dynmultipush PkmnCenterNurse_Text_MoveTutor, 1
	call_if_set FLAG_NES_GAVE_INFINITE_CANDY, PkmnCenterNurse_LevelCapOptions
	msgbox PkmnCenterNurse_Text_WhatService
	dynmultipush PkmnCenterNurse_Text_GenderSwap, 4
	dynmultipush PkmnCenterNurse_Text_BallSwap, 5
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, NULL
	switch VAR_RESULT
	case MULTI_B_PRESSED, PkmnCenterNurse_Aide_End
	case 0, PkmnCenterNurse_EventScript_WantNatureChange
	case 1, PkmnCenterNurse_EventScript_WantMoveTutor
	case 2, PkmnCenterNurse_EventScript_PartyToLvlCap
	case 3, PkmnCenterNurse_EventScript_PkmnToLvlCap
	case 4, PkmnCenterNurse_EventScript_SwapGender
	case 5, PkmnCenterNurse_EventScript_SwapBall
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
	dynmultipush Debug_EventScript_ChangeNature_Text_Adamant, 3
	dynmultipush Debug_EventScript_ChangeNature_Text_Modest, 15
	dynmultipush Debug_EventScript_ChangeNature_Text_Timid, 10
	dynmultipush Debug_EventScript_ChangeNature_Text_Jolly, 13
	dynmultipush Debug_EventScript_ChangeNature_Text_Naive, 14
	dynmultipush Debug_EventScript_ChangeNature_Text_Hasty, 11
	dynmultipush Debug_EventScript_ChangeNature_Text_Bold, 5
	dynmultipush Debug_EventScript_ChangeNature_Text_Impish, 8
	dynmultipush Debug_EventScript_ChangeNature_Text_Calm, 20
	dynmultipush Debug_EventScript_ChangeNature_Text_Careful, 23
	dynmultipush Debug_EventScript_ChangeNature_Text_Lonely, 1
	dynmultipush Debug_EventScript_ChangeNature_Text_Naughty, 4
	dynmultipush Debug_EventScript_ChangeNature_Text_Mild, 16
	dynmultipush Debug_EventScript_ChangeNature_Text_Rash, 19
	dynmultipush Debug_EventScript_ChangeNature_Text_Brave, 2
	dynmultipush Debug_EventScript_ChangeNature_Text_Docile, 6
	dynmultipush Debug_EventScript_ChangeNature_Text_Relaxed, 7
	dynmultipush Debug_EventScript_ChangeNature_Text_Lax, 9
	dynmultipush Debug_EventScript_ChangeNature_Text_Serious, 12
	dynmultipush Debug_EventScript_ChangeNature_Text_Quiet, 17
	dynmultipush Debug_EventScript_ChangeNature_Text_Bashful, 18
	dynmultipush Debug_EventScript_ChangeNature_Text_Gentle, 21
	dynmultipush Debug_EventScript_ChangeNature_Text_Sassy, 22
	dynmultipush Debug_EventScript_ChangeNature_Text_Hardy, 0
	dynmultistack 0, 0, FALSE, 6, FALSE, 3, NULL
	switch VAR_RESULT
	case MULTI_B_PRESSED, PalletTown_ProfessorOaks_EventScript_End
	special SetHiddenNature
	msgbox PkmnCenterNurse_Text_PkmnNatureChangeDone
	releaseall
	end

PkmnCenterNurse_EventScript_WantMoveTutor:
	@ goto_if_unset FLAG_BADGE01_GET, PkmnCenterNurse_EventScript_StartingMoveTutors
	dynmultipush PkmnCenterNurse_Text_StartingTutors, 0
	call_if_set FLAG_BADGE01_GET, PkmnCenterNurse_SetBoulderBadgeTutor
	call_if_set FLAG_BADGE02_GET, PkmnCenterNurse_SetCascadeBadgeTutor
	call_if_set FLAG_BADGE03_GET, PkmnCenterNurse_SetThunderBadgeTutor
	call_if_set FLAG_BADGE04_GET, PkmnCenterNurse_SetRainbowBadgeTutor
	call_if_set FLAG_BADGE05_GET, PkmnCenterNurse_SetSoulBadgeTutor
	call_if_set FLAG_BADGE06_GET, PkmnCenterNurse_SetMarshBadgeTutor
	call_if_set FLAG_BADGE07_GET, PkmnCenterNurse_SetVolcanoBadgeTutor
	call_if_set FLAG_BADGE08_GET, PkmnCenterNurse_SetEarthBadgeTutor
	dynmultipush PkmnCenterNurse_Text_AllTutors, 9
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, NULL
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
	case 9, PkmnCenterNurse_EventScript_AllMoveTutors
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

@ Every badge tutor list pushes MOVE_ ids so the info panel can read the move
@ Starting tutors is also reached before any badge so B returns to the aide menu
PkmnCenterNurse_EventScript_StartingMoveTutors:
	call PkmnCenterNurse_AllTutors_Starting
	closemessage
	dynmultistack 0, 0, FALSE, 5, FALSE, 0, DYN_MULTICHOICE_CB_SHOW_MOVE_INFO
	goto_if_eq VAR_RESULT, MULTI_B_PRESSED, PkmnCenterNurse_EventScript_WantMoveTutor
	copyvar VAR_0x8005, VAR_RESULT
	goto PkmnCenterNurse_Tutor_TeachMove
	end

PkmnCenterNurse_EventScript_BoulderMoveTutors:
	call PkmnCenterNurse_AllTutors_Boulder
	goto PkmnCenterNurse_ShowTutorList

PkmnCenterNurse_EventScript_CascadeMoveTutors:
	call PkmnCenterNurse_AllTutors_Cascade
	goto PkmnCenterNurse_ShowTutorList

PkmnCenterNurse_EventScript_ThunderMoveTutors:
	call PkmnCenterNurse_AllTutors_Thunder
	goto PkmnCenterNurse_ShowTutorList

PkmnCenterNurse_EventScript_RainbowMoveTutors:
	call PkmnCenterNurse_AllTutors_Rainbow
	goto PkmnCenterNurse_ShowTutorList

PkmnCenterNurse_EventScript_SoulMoveTutors:
	call PkmnCenterNurse_AllTutors_Soul
	goto PkmnCenterNurse_ShowTutorList

PkmnCenterNurse_EventScript_MarshMoveTutors:
	call PkmnCenterNurse_AllTutors_Marsh
	goto PkmnCenterNurse_ShowTutorList

PkmnCenterNurse_EventScript_VolcanoMoveTutors:
	call PkmnCenterNurse_AllTutors_Volcano
	goto PkmnCenterNurse_ShowTutorList

PkmnCenterNurse_EventScript_EarthMoveTutors:
	goto EventScript_PkmnCenterNurse_Aide

@ shared tail for every tutor list, B goes back to the category menu
@ maxBeforeScroll stays at 5 or the list border overlaps the info window
PkmnCenterNurse_ShowTutorList:
	closemessage
	dynmultistack 0, 0, FALSE, 5, FALSE, 0, DYN_MULTICHOICE_CB_SHOW_MOVE_INFO
	goto_if_eq VAR_RESULT, MULTI_B_PRESSED, PkmnCenterNurse_EventScript_WantMoveTutor
	copyvar VAR_0x8005, VAR_RESULT
	goto PkmnCenterNurse_Tutor_TeachMove
	end


@ Master list of every tutor the player has unlocked so far
@ Earth Badge has no tutors yet so it is not pushed here
PkmnCenterNurse_EventScript_AllMoveTutors:
	call PkmnCenterNurse_AllTutors_Starting
	call_if_set FLAG_BADGE01_GET, PkmnCenterNurse_AllTutors_Boulder
	call_if_set FLAG_BADGE02_GET, PkmnCenterNurse_AllTutors_Cascade
	call_if_set FLAG_BADGE03_GET, PkmnCenterNurse_AllTutors_Thunder
	call_if_set FLAG_BADGE04_GET, PkmnCenterNurse_AllTutors_Rainbow
	call_if_set FLAG_BADGE05_GET, PkmnCenterNurse_AllTutors_Soul
	call_if_set FLAG_BADGE06_GET, PkmnCenterNurse_AllTutors_Marsh
	call_if_set FLAG_BADGE07_GET, PkmnCenterNurse_AllTutors_Volcano
	@ ids here are move constants so no switch is needed
	@ MULTI_B_PRESSED is 127 which is Waterfall so no tutor may use that move
	goto PkmnCenterNurse_ShowTutorList

PkmnCenterNurse_AllTutors_Starting:
	dynmultipush PkmnCenterNurse_Text_Swift, MOVE_SWIFT
	dynmultipush PkmnCenterNurse_Text_FalseSwipe, MOVE_FALSE_SWIPE
	dynmultipush PkmnCenterNurse_Text_MagicalLeaf, MOVE_MAGICAL_LEAF
	dynmultipush PkmnCenterNurse_Text_BugBite, MOVE_BUG_BITE
	dynmultipush PkmnCenterNurse_Text_AirCutter, MOVE_AIR_CUTTER
	return

PkmnCenterNurse_AllTutors_Boulder:
	call_if_quest_complete QUEST_FANG_TUTOR, PkmnCenterNurse_AllTutors_Fangs
	dynmultipush PkmnCenterNurse_Text_Round, MOVE_ROUND
	dynmultipush PkmnCenterNurse_Text_MudShot, MOVE_MUD_SHOT
	dynmultipush PkmnCenterNurse_Text_OminousWind, MOVE_OMINOUS_WIND
	dynmultipush PkmnCenterNurse_Text_AncientPower, MOVE_ANCIENT_POWER
	return

PkmnCenterNurse_AllTutors_Fangs:
	dynmultipush gText_FireFang, MOVE_FIRE_FANG
	dynmultipush gText_IceFang, MOVE_ICE_FANG
	dynmultipush gText_ThunderFang, MOVE_THUNDER_FANG
	return

PkmnCenterNurse_AllTutors_Cascade:
	call_if_quest_complete QUEST_FAN_CLUB_TUTOR, PkmnCenterNurse_AllTutors_FanClub
	call_if_set FLAG_TUTOR_SEISMIC_TOSS, PkmnCenterNurse_AllTutors_SeismicToss
	dynmultipush PkmnCenterNurse_Text_Hex, MOVE_HEX
	dynmultipush PkmnCenterNurse_Text_StompingTantrum, MOVE_STOMPING_TANTRUM
	return

PkmnCenterNurse_AllTutors_FanClub:
	dynmultipush PkmnCenterNurse_Text_FlameCharge, MOVE_FLAME_CHARGE
	dynmultipush PkmnCenterNurse_Text_Trailblaze, MOVE_TRAILBLAZE
	dynmultipush PkmnCenterNurse_Text_PowerUpPunch, MOVE_POWER_UP_PUNCH
	dynmultipush PkmnCenterNurse_Text_ChargeBeam, MOVE_CHARGE_BEAM
	dynmultipush PkmnCenterNurse_Text_WorkUp, MOVE_WORK_UP
	dynmultipush PkmnCenterNurse_Text_HoneClaws, MOVE_HONE_CLAWS
	return

PkmnCenterNurse_AllTutors_SeismicToss:
	dynmultipush PkmnCenterNurse_Text_SeismicToss, MOVE_SEISMIC_TOSS
	return

PkmnCenterNurse_AllTutors_Thunder:
	dynmultipush PkmnCenterNurse_Text_SignalBeam, MOVE_SIGNAL_BEAM
	dynmultipush PkmnCenterNurse_Text_TailSlap, MOVE_TAIL_SLAP
	dynmultipush PkmnCenterNurse_Text_RockBlast, MOVE_ROCK_BLAST
	dynmultipush PkmnCenterNurse_Text_IcicleSpear, MOVE_ICICLE_SPEAR
	call_if_set FLAG_TUTOR_COUNTER, PkmnCenterNurse_AllTutors_Counter
	return

PkmnCenterNurse_AllTutors_Counter:
	dynmultipush PkmnCenterNurse_Text_Counter, MOVE_COUNTER
	return

PkmnCenterNurse_AllTutors_Rainbow:
	dynmultipush PkmnCenterNurse_Text_BugBuzz, MOVE_BUG_BUZZ
	dynmultipush PkmnCenterNurse_Text_BodySlam, MOVE_BODY_SLAM
	dynmultipush PkmnCenterNurse_Text_PhantomForce, MOVE_PHANTOM_FORCE
	dynmultipush PkmnCenterNurse_Text_LeafBlade, MOVE_LEAF_BLADE
	dynmultipush PkmnCenterNurse_Text_PowerGem, MOVE_POWER_GEM
	dynmultipush PkmnCenterNurse_Text_FocusPunch, MOVE_FOCUS_PUNCH
	dynmultipush PkmnCenterNurse_Text_PsychicFangs, MOVE_PSYCHIC_FANGS
	return

PkmnCenterNurse_AllTutors_Soul:
	dynmultipush PkmnCenterNurse_Text_DrillRun, MOVE_DRILL_RUN
	dynmultipush PkmnCenterNurse_Text_BlazeKick, MOVE_BLAZE_KICK
	dynmultipush PkmnCenterNurse_Text_PainSplit, MOVE_PAIN_SPLIT
	dynmultipush PkmnCenterNurse_Text_AlluringVoice, MOVE_ALLURING_VOICE
	dynmultipush PkmnCenterNurse_Text_FoulPlay, MOVE_FOUL_PLAY
	return

PkmnCenterNurse_AllTutors_Marsh:
	dynmultipush PkmnCenterNurse_Text_MeteorBeam, MOVE_METEOR_BEAM
	dynmultipush PkmnCenterNurse_Text_Outrage, MOVE_OUTRAGE
	dynmultipush PkmnCenterNurse_Text_SolarBeam, MOVE_SOLAR_BEAM
	dynmultipush PkmnCenterNurse_Text_SolarBlade, MOVE_SOLAR_BLADE
	dynmultipush PkmnCenterNurse_Text_PowerWhip, MOVE_POWER_WHIP
	dynmultipush PkmnCenterNurse_Text_GrassyGlide, MOVE_GRASSY_GLIDE
	dynmultipush PkmnCenterNurse_Text_RisingVoltage, MOVE_RISING_VOLTAGE
	dynmultipush PkmnCenterNurse_Text_ExpandingForce, MOVE_EXPANDING_FORCE
	dynmultipush PkmnCenterNurse_Text_MistyExplosion, MOVE_MISTY_EXPLOSION
	return

PkmnCenterNurse_AllTutors_Volcano:
	dynmultipush PkmnCenterNurse_Text_FlareBlitz, MOVE_FLARE_BLITZ
	dynmultipush PkmnCenterNurse_Text_StoredPower, MOVE_STORED_POWER
	dynmultipush PkmnCenterNurse_Text_Tailwind, MOVE_TAILWIND
	dynmultipush PkmnCenterNurse_Text_Megahorn, MOVE_MEGAHORN
	return

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
	goto_if_eq VAR_RESULT, MON_GENDERLESS, PkmnCenterNurse_CantOperateOnGenderless
	goto_if_eq VAR_RESULT, 0xFD, PkmnCenterNurse_CantSwapFixedGender
	msgbox PkmnCenterNurse_Text_SwapGenderOfPkmn MSGBOX_YESNO
	switch VAR_RESULT
	case NO, EventScript_PkmnCenterNurse_Aide
	callnative SwapSelectedPokemonGender
	msgbox PkmnCenterNurse_Text_SwapGenderDone
	release
	end

PkmnCenterNurse_EventScript_SwapBall:
	msgbox PkmnCenterNurse_Text_DoYouWantToSwapBall MSGBOX_YESNO
	switch VAR_RESULT
	case NO, EventScript_PkmnCenterNurse_Aide
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, EventScript_PkmnCenterNurse_Aide
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, PkmnCenterNurse_CantOperateOnEgg
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	msgbox PkmnCenterNurse_Text_WhichBall
	callnative BuildBallSwapList
	dynmultistack 0, 0, FALSE, 6, FALSE, VAR_0x8006, DYN_MULTICHOICE_CB_SHOW_ITEM
	goto_if_eq VAR_RESULT, MULTI_B_PRESSED, EventScript_PkmnCenterNurse_Aide
	copyvar VAR_0x8005, VAR_RESULT
	callnative SetSelectedMonBall
	msgbox PkmnCenterNurse_Text_BallSwapDone
	release
	end

PkmnCenterNurse_CantOperateOnEgg::
	msgbox PkmnCenterNurse_Text_CantOperateOnEgg
	goto EventScript_PkmnCenterNurse_Aide
	end

PkmnCenterNurse_CantOperateOnGenderless::
	msgbox PkmnCenterNurse_Text_CantOperateOnGenderless
	goto EventScript_PkmnCenterNurse_Aide
	end

PkmnCenterNurse_CantSwapFixedGender::
	msgbox PkmnCenterNurse_Text_CantSwapFixedGender
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
	.string "What service would be of interest?$"

PkmnCenterNurse_Text_CantOperateOnEgg:
	.string "…I can't operate on an egg.$"

PkmnCenterNurse_Text_WhatNature:
	.string "What nature would you like for {STR_VAR_1}?$"

PkmnCenterNurse_Text_SetPartyToLevelCapDone: 
	.string "…Okay, your team has been set to the\n"
	.string "Level Cap of {STR_VAR_2}.$"

PkmnCenterNurse_Text_WhichPokemonDoYouWantLvlCap:
	.string "Select the {PKMN} whose level you'd like to\n"
	.string "raise to the Level Cap.$"

PkmnCenterNurse_Text_RaisePokemonToLvlCap:
	.string "Raise {STR_VAR_1} to\n"
	.string "the Level Cap?$"

PkmnCenterNurse_Text_SetPartyToLevelCap:
	.string "Shall I raise your party's levels to the\n"
	.string "Level Cap?$"

PkmnCenterNurse_Text_PkmnRaisedToCapDone:
	.string "{STR_VAR_1} has been raised to the\n"
	.string "Level Cap of {STR_VAR_2}.$"

PkmnCenterNurse_Text_InterestedInNatureChange:
	.string "Are you interested in swapping\n"
	.string "a Pokémon's nature?$"

PkmnCenterNurse_Text_PkmnNatureChangeDone:
	.string "…Okay, your {STR_VAR_1}'s Nature has\n"
	.string "been changed to {STR_VAR_2}.$"

PkmnCenterNurse_Text_DoYouWantToSwapGender:
	.string "Do you want to swap the Gender\n"
	.string "of one of your Pokémon?$"

PkmnCenterNurse_Text_CantOperateOnGenderless:
	.string "…That Pokémon doesn't have a gender.$"

PkmnCenterNurse_Text_CantSwapFixedGender:
	.string "…I can't change that Pokémon's gender.$"

PkmnCenterNurse_Text_SwapGenderDone:
	.string "…Okay, {STR_VAR_1}'s gender has\n"
	.string "been changed.$"

PkmnCenterNurse_Text_SwapGenderOfPkmn:
	.string "Swap the Gender of {STR_VAR_1}?$"

PkmnCenterNurse_Text_BallSwap:
	.string "Poké Ball Swap$"

PkmnCenterNurse_Text_DoYouWantToSwapBall:
	.string "Do you want to change the Ball a\n"
	.string "Pokémon is kept in?$"

PkmnCenterNurse_Text_WhichBall:
	.string "Which Ball would you like for\n"
	.string "{STR_VAR_1}?$"

PkmnCenterNurse_Text_BallSwapDone:
	.string "…Okay, {STR_VAR_1} is now\n"
	.string "kept in a {STR_VAR_2}.$"

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

PkmnCenterNurse_Text_Outrage:
	.string "Outrage$"

PkmnCenterNurse_Text_SolarBeam:
	.string "Solar Beam$"

PkmnCenterNurse_Text_SolarBlade:
	.string "Solar Blade$"

PkmnCenterNurse_Text_PowerWhip:
	.string "Power Whip$"

PkmnCenterNurse_Text_GrassyGlide:
	.string "Grassy Glide$"

PkmnCenterNurse_Text_RisingVoltage:
	.string "Rising Voltage$"

PkmnCenterNurse_Text_ExpandingForce:
	.string "Expanding Force$"

PkmnCenterNurse_Text_MistyExplosion:
	.string "Misty Explosion$"

PkmnCenterNurse_Text_FlareBlitz:
	.string "Flare Blitz$" 

PkmnCenterNurse_Text_StoredPower:
	.string "Stored Power$"

PkmnCenterNurse_Text_Tailwind:
	.string "Tailwind$"

PkmnCenterNurse_Text_Megahorn:
	.string "Megahorn$"

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
	.string "Petal Badge Tutors$"

PkmnCenterNurse_Text_AllTutors:
	.string "All Tutors$"
