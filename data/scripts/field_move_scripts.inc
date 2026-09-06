@ Interact with cuttable tree
EventScript_CutTree::
	lockall
	goto_if_unset FLAG_BADGE02_GET, EventScript_CheckTreeCantCut
	checkitem ITEM_HM_CUT, 1
	goto_if_eq VAR_RESULT, FALSE, EventScript_CheckTreeCantCut
	@ setfieldeffectargument 0, VAR_RESULT
	goto EventScript_CutTreeDown
	@ bufferpartymonnick STR_VAR_1, VAR_RESULT
	@ buffermovename STR_VAR_2, MOVE_CUT
	@ msgbox Text_WantToCut, MSGBOX_YESNO
	@ goto_if_eq VAR_RESULT, NO, EventScript_CancelCut
	@ msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	@ closemessage
EventScript_CutTreeCommon:
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
EventScript_CutTreeDown:: @ fallthrough
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	playse SE_M_CUT
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
	waitmovement 0
	removeobject VAR_LAST_TALKED
	releaseall
	end

@ Use cut from party menu
EventScript_UseCut::
	lockall
	goto EventScript_CutTreeCommon

Movement_CutTreeDown:
	cut_tree
	step_end

EventScript_CheckTreeCantCut::
	msgbox Text_CantCut, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelCut::
	closemessage
	releaseall
	end

Text_WantToCut:
	.string "This tree looks like it can be\n"
	.string "Cut down!\p"
	.string "Would you like to CUT it?$"

Text_MonUsedFieldMove:
	.string "{STR_VAR_1} used {STR_VAR_2}!$"

Text_CantCut:
	.string "This tree looks like it can be\n"
	.string "Cut down!$"

@ Use rock smash from party menu
EventScript_UseRockSmash::
	lockall
	goto EventScript_RockSmashCommon

@ Interact with smashable rock
EventScript_RockSmash::
	lockall
	goto_if_unset FLAG_BADGE05_GET, EventScript_CantSmashRock
	checkitem ITEM_HM_ROCK_SMASH
	goto_if_eq VAR_RESULT, FALSE, EventScript_CantSmashRock
	@ setfieldeffectargument 0, VAR_RESULT
	@ bufferpartymonnick STR_VAR_1, VAR_RESULT
	@ buffermovename STR_VAR_2, MOVE_ROCK_SMASH
	@ msgbox Text_WantToSmash, MSGBOX_YESNO
	@ goto_if_eq VAR_RESULT, NO, EventScript_CancelSmash
	@ msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	@ closemessage
EventScript_RockSmashCommon:
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
EventScript_SmashRock:: @ fallthrough
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement VAR_LAST_TALKED, Movement_SmashRock
	waitmovement 0
	removeobject VAR_LAST_TALKED
	specialvar VAR_RESULT, TryUpdateRusturfTunnelState
	goto_if_eq VAR_RESULT, TRUE, EventScript_EndSmash
	special RockSmashWildEncounter
	goto_if_eq VAR_RESULT, FALSE, EventScript_EndSmash
	waitstate
	releaseall
	end

EventScript_EndSmash::
	releaseall
	end

Movement_SmashRock:
	rock_smash_break
	step_end

EventScript_CantSmashRock::
	msgbox Text_CantSmash, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelSmash::
	closemessage
	releaseall
	end

Text_WantToSmash:
	.string "This rock appears to be breakable.\n"
	.string "Would you like to use ROCK SMASH?$"

Text_CantSmash:
	.string "It's a rugged rock, but a Pokémon\n"
	.string "may be able to smash it.$"

EventScript_StrengthBoulder::
	lockall
	checkitem ITEM_HM_STRENGTH 
	goto_if_eq VAR_RESULT, TRUE, EventScript_CheckActivatedBoulder
	goto EventScript_CantStrength
	@ goto_if_set FLAG_SYS_USE_STRENGTH, EventScript_CheckActivatedBoulder
	@ checkfieldmove FIELD_MOVE_STRENGTH, TRUE
	@ goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantStrength
	@ setfieldeffectargument 0, VAR_RESULT
	@ msgbox Text_WantToStrength, MSGBOX_YESNO
	@ goto_if_eq VAR_RESULT, NO, EventScript_CancelStrength
	@ closemessage
	@ dofieldeffect FLDEFF_USE_STRENGTH
	@ waitstate
	@ goto EventScript_ActivateStrength
	end

EventScript_UseStrength::
	lockall
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end

EventScript_ActivateStrength::
	setflag FLAG_SYS_USE_STRENGTH
	msgbox Text_MonUsedStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CantStrength::
	msgbox Text_CantStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CheckActivatedBoulder::
	msgbox Text_StrengthActivated, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelStrength::
	closemessage
	releaseall
	end

Text_WantToStrength:
	.string "It's a big boulder, but a Pokémon\n"
	.string "may be able to push it aside.\p"
	.string "Would you like to use STRENGTH?$"

Text_MonUsedStrength:
	.string "{STR_VAR_1} used STRENGTH!\p"
	.string "{STR_VAR_1}'s STRENGTH made it\n"
	.string "possible to move boulders around!$"

Text_CantStrength:
	.string "It's a big boulder, but a Pokémon\n"
	.string "may be able to push it aside.$"

Text_StrengthActivated:
	.string "Strength made it possible to move\n"
	.string "boulders around.$"

EventScript_UseWaterfall::
	lockall
	checkfieldmove FIELD_MOVE_WATERFALL
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantWaterfall
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToWaterfall, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndWaterfall
	msgbox Text_MonUsedWaterfall, MSGBOX_DEFAULT
	hidefollowernpc
	dofieldeffect FLDEFF_USE_WATERFALL
	callnative FollowerNPC_WarpSetEnd
	goto EventScript_EndWaterfall

EventScript_CannotUseWaterfall::
	lockall

EventScript_CantWaterfall::
	msgbox Text_CantWaterfall, MSGBOX_DEFAULT

EventScript_EndWaterfall::
	releaseall
	end

Text_CantWaterfall:
	.string "A wall of water is crashing down with\n"
	.string "a mighty roar.$"

Text_WantToWaterfall:
	.string "It's a large waterfall.\n"
	.string "Would you like to use WATERFALL?$"

Text_MonUsedWaterfall:
	.string "{STR_VAR_1} used WATERFALL.$"

EventScript_UseDive::
	lockall
	checkfieldmove FIELD_MOVE_DIVE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantDive
	copyvar 0x8004 VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_WantToDive, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndDive
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	hidefollowernpc
	setfieldeffectargument 0, VAR_0x8004
	setfieldeffectargument 1, 1
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndDive
	end

EventScript_CantDive::
	msgbox Text_CantDive, MSGBOX_DEFAULT
	releaseall
	end

EventScript_EndDive::
	releaseall
	end

EventScript_UseDiveUnderwater::
	lockall
	checkfieldmove FIELD_MOVE_DIVE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSurface
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_WantToSurface, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_NoSurface
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	hidefollowernpc
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndSurface
	end

EventScript_CantSurface::
	lockall
	msgbox Text_CantSurface, MSGBOX_DEFAULT
	goto EventScript_EndSurface
	end

EventScript_EndSurface::
	callnative SetFollowerNPCSurfSpriteAfterDive
EventScript_NoSurface::
	releaseall
	end

EventScript_DigCommon:
	dofieldeffect FLDEFF_USE_DIG
	waitstate
EventScript_DigSealedChamber:: @ fallthrough
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	callnative DoBrailleDigEffect
	releaseall
	end

@ Use Dig from party menu
EventScript_UseDig::
	lockall
	goto EventScript_DigCommon


EventScript_CutGrassCommon:
	dofieldeffect FLDEFF_USE_CUT_ON_GRASS
	waitstate

@ Use Cut grass from party menu
EventScript_UseCutGrass::
	lockall
	goto EventScript_CutGrassCommon

Text_CantDive:
	.string "The sea is deep here. A Pokémon\n"
	.string "may be able to go underwater.$"

Text_WantToDive:
	.string "The sea is deep here.\n"
	.string "Would you like to use DIVE?$"

Text_MonUsedDive:
	.string "{STR_VAR_1} used DIVE.$"

Text_CantSurface:
	.string "Light is filtering down from above.\n"
	.string "A Pokémon may be able to surface.$"

Text_WantToSurface:
	.string "Light is filtering down from above.\n"
	.string "Would you like to use DIVE?$"

EventScript_FailSweetScent::
	msgbox Text_FailSweetScent, MSGBOX_SIGN
	end

Text_FailSweetScent:
	.string "Looks like there's nothing here…$"

EventScript_UseDefog::
	lockall
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_DEFOG
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	waitmovement 0
	setfieldeffectargument 0, VAR_RESULT
	dofieldeffect FLDEFF_DEFOG
	waitstate
	releaseall
	end

EventScript_UseRockClimb::
	lockall
	checkfieldmove FIELD_MOVE_ROCK_CLIMB
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantRockClimb
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToRockClimb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndRockClimb
	msgbox Text_MonUsedRockClimb, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_ROCK_CLIMB
	waitstate
	goto EventScript_EndRockClimb
	end

EventScript_CantRockClimb::
	msgbox Text_CantRockClimb, MSGBOX_DEFAULT

EventScript_EndRockClimb::
	releaseall
	end

Text_WantToRockClimb:
    .string "The cliff is steep.\n"
    .string "Would you like to use Rock Climb?$"

Text_MonUsedRockClimb:
    .string "{STR_VAR_1} used Rock Climb!$"

Text_CantRockClimb:
    .string "The cliff is steep.\n"
    .string "A Pokémon may be able to climb it.$"
