.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s" 

@0x106E is now free

.equ FLAG_COMPLETED_BERRY_FOREST, 0x2A3 
.equ VAR_LVL_BERRYFOREST_1, 0x5139
.equ VAR_BERRY_FOREST_OBSTACLE, 0x513A
.equ FLAG_BEAT_BERRY_ACE_TRAINER_1, 0x106F
.equ FLAG_BEAT_BERRY_ACE_TRAINER_2, 0x1070
.equ FLAG_BEAT_BERRY_ACE_TRAINER_3, 0x1071
.equ FLAG_BEAT_BERRY_ACE_TRAINER_4, 0x1072
.equ FLAG_DISABLE_BAG, 0x915
.equ VAR_TOTEM, 0x5002
.equ FLAG_COMPLETED_MEW_EVENT, 0x1074
.equ FLAG_NO_RUNNING, 0x903

.global EventScript_ThreeIsland_Kid
EventScript_ThreeIsland_Kid:
    msgbox gText_ThreeIsland_WingullBoy MSG_FACE
    release
    end

.global EventScript_Wingull
EventScript_Wingull:
    cry SPECIES_WINGULL 0x0
    msgbox gText_ThreeIsland_Wingull MSG_FACE
    waitcry
    release
    end

.global EventScript_ThreeIsland_Gem
EventScript_ThreeIsland_Gem:
    hidesprite 0x800F 
    giveitem ITEM_GRASS_GEM 0x1 MSG_OBTAIN 
    setflag 0x1BB
    release
    end

.global EventScript_threeislandguy1
EventScript_threeislandguy1:
	lock
	checkflag FLAG_COMPLETED_BERRY_FOREST
	if 0x1 _goto EventScript_threeislandguy_2
	compare 0x407B 0x4
	if 0x1 _goto EventScript_threeislandguy_2_2
	setvar 0x4001 0x0
	call EventScript_threeislandguy_3
	release
	end

EventScript_threeislandguy_2:
	applymovement 0x1 EventScript_threeislandguy_Movement1
	waitmovement 0x0
	msgbox gText_threeislandguy_Impressive MSG_KEEPOPEN @"You@ve got seriously impressive\nP..."
	release
	end

EventScript_threeislandguy_2_2:
	checkflag 0x2FC
	if 0x1 _goto ImpressivePokemon
	applymovement 0x1 EventScript_threeislandguy_Movement1
	waitmovement 0x0
	msgbox gText_threeislandguy_Thanks MSG_KEEPOPEN @"Thank you! Those goons were\nnothi..."
	giveitem ITEM_STEELIUM_Z 0x1 MSG_OBTAIN
	setflag 0x2FC

ImpressivePokemon:
	msgbox 0x81827F1 MSG_FACE @"You@ve got seriously impressive\nP..."
	release
	end

	@---------------
EventScript_threeislandguy_3:
	compare 0x4001 0x1
	if 0x1 _call EventScript_threeislandguy_167947
	compare 0x4001 0x2
	if 0x1 _call EventScript_threeislandguy_167947
	applymovement 0x1 EventScript_threeislandguy_0X167A1B
	waitmovement 0x0
	msgbox gText_threeislandguy_Noneed MSG_KEEPOPEN @"We don@t need you people bringing\..."
	compare 0x4001 0x0
	if 0x1 _call EventScript_threeislandguy_167952
	compare 0x4001 0x1
	if 0x1 _call EventScript_threeislandguy_167952
	compare 0x4001 0x2
	if 0x1 _call EventScript_threeislandguy_0X16795D
	applymovement 0x5 EventScript_threeislandguy_0X167A19
	waitmovement 0x0
	msgbox gText_threeislandguy_Gocry MSG_KEEPOPEN @"Hey, go cry somewhere else.\nOur b..."
	compare 0x4001 0x0
	if 0x1 _call EventScript_threeislandguy_MvPlayer167931
	compare 0x4001 0x1
	if 0x1 _call EventScript_threeislandguy_MvPlayer167931
	compare 0x4001 0x2
	if 0x1 _call EventScript_threeislandguy_0X167973
	applymovement 0x2 EventScript_threeislandguy_0X167A1B
	waitmovement 0x0
	msgbox gText_threeislandguy_GetOut MSG_KEEPOPEN @"W-what!? Not on your life!\nGet of..."
	compare 0x4001 0x0
	if 0x1 _call EventScript_threeislandguy_167952
	compare 0x4001 0x1
	if 0x1 _call EventScript_threeislandguy_167952
	compare 0x4001 0x2
	if 0x1 _call EventScript_threeislandguy_0X16795D
	applymovement 0x4 EventScript_threeislandguy_0X167A19
	waitmovement 0x0
	msgbox gText_threeislandguy_WhoGonnaMakeMe MSG_KEEPOPEN @"Who@s gonna make me?"
	return

	@---------------
EventScript_threeislandguy_167947:
	applymovement PLAYER EventScript_threeislandguy_MvPlayer1A75E7
	waitmovement 0x0
	return

	@---------------
EventScript_threeislandguy_167952:
	applymovement PLAYER EventScript_threeislandguy_0X1A75EB
	waitmovement 0x0
	return

	@---------------
EventScript_threeislandguy_0X16795D:
	getplayerpos 0x8004 0x8005
	compare 0x8004 0x9
	if 0x4 _goto EventScript_threeislandguy_MvPlayer167931
	goto 0x8167952

	@---------------
EventScript_threeislandguy_MvPlayer167931:
	applymovement PLAYER EventScript_threeislandguy_MvPlayer1A75E9
	waitmovement 0x0
	return

	@---------------
EventScript_threeislandguy_0X167973:
	getplayerpos 0x8004 0x8005
	compare 0x8004 0x9
	if 0x4 _goto EventScript_threeislandguy_167947
	goto EventScript_threeislandguy_MvPlayer167931


EventScript_threeislandguy_Movement1:
.byte 0x4A
.byte 0xFE

EventScript_threeislandguy_0X167A1B:
.byte 0x28
.byte 0xFE

EventScript_threeislandguy_0X167A19:
.byte 0x27
.byte 0xFE

EventScript_threeislandguy_MvPlayer1A75E7:
.byte 0x2F
.byte 0xFE

EventScript_threeislandguy_0X1A75EB:
.byte 0x30
.byte 0xFE

EventScript_threeislandguy_MvPlayer1A75E9:
.byte 0x2E
.byte 0xFE

.global EventScript_threeisland_GatekeeperTile
EventScript_threeisland_GatekeeperTile:
	call GateKeeperMainScript
	applymovement PLAYER WalkBack
	waitmovement 0x0
	release
	end

GateKeeperMainScript:
	lock
	applymovement 0x8 FacePlayer
	waitmovement 0x0
	msgbox gText_ThreeIsland_Gatekeeper1 MSG_YESNO
	compare LASTRESULT YES
	if equal _goto WarpToBerry
	return

FacePlayer:
	.byte face_player
	.byte end_m

.global EventScript_threeisland_Gatekeeper
EventScript_threeisland_Gatekeeper:
	call GateKeeperMainScript
	release
	end

WarpToBerry:
	clearflag FLAG_BEAT_BERRY_ACE_TRAINER_1
	clearflag FLAG_BEAT_BERRY_ACE_TRAINER_2
	clearflag FLAG_BEAT_BERRY_ACE_TRAINER_3
	clearflag FLAG_BEAT_BERRY_ACE_TRAINER_4
	setvar VAR_LVL_BERRYFOREST_1 0x0
	warp 0x1 109 0x0 0x0 0x0
	release
	end

WalkBack:
	.byte walk_down
	.byte end_m

.global gMapScripts_BerryForest
gMapScripts_BerryForest:
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScripts_BerryForestOldManLeads
    mapscript MAP_SCRIPT_ON_LOAD BerryForestPutBlocks
    .byte MAP_SCRIPT_TERMIN

LevelScripts_BerryForestOldManLeads:
	levelscript VAR_LVL_BERRYFOREST_1, 0, LevelScript_BerryForestOldManLeads
	levelscript VAR_LVL_BERRYFOREST_1, 2, LevelScript_BerryForestOldManMew
	.hword MAP_SCRIPT_TERMIN

LevelScript_BerryForestOldManMew:
	applymovement PLAYER FaceUp
	waitmovement 0x0
	cry SPECIES_MEW 0x0
	msgbox gText_BerryForest_DotDotdot MSG_KEEPOPEN
	pause 0x3
	waitcry
	closeonkeypress
	sound 0x15
	applymovement 0xA Exclaim
	waitmovement 0x0
	checksound
	msgbox gText_BerryForest_GatekeeperMew MSG_KEEPOPEN
	pause 0x5
	closeonkeypress
	applymovement 0xA WalkInPlace
	waitmovement 0x0
	msgbox gText_BerryForest_GatekeeperMew_1 MSG_NORMAL
	cry SPECIES_MEWTWO 0x0
	msgbox gText_BerryForest_DotDotdot MSG_KEEPOPEN
	pause 0x5
	waitcry
	closeonkeypress
	applymovement 0xB WalkUpInPlace
	waitmovement 0x0
	msgbox gText_BerryForest_GatekeeperMewtwo MSG_NORMAL
	applymovement 0xA WalkInPlace
	waitmovement 0x0
	msgbox gText_BerryForest_GatekeeperMew_2 MSG_NORMAL
	applymovement 0xA LookAtMew
	applymovement 0x8 LookAtGatekeeper 
	waitmovement 0x0 
	cry SPECIES_MEW 0x0
	msgbox gText_BerryForest_GateKeeperMewCry MSG_KEEPOPEN
	waitcry
	pause 0x5
	closeonkeypress
	applymovement 0xA LookDown
	applymovement 0x8 LookDown
	waitmovement 0x0
	msgbox gText_BerryForest_GatekeeperMew_3 MSG_NORMAL
	setflag 0x201
	setvar VAR_LVL_BERRYFOREST_1 0x1
	@ setflag FLAG_SMALL_TRAINER_LEVELS
	setflag FLAG_DISABLE_BAG
	special 0x0
	trainerbattle3 0x3 0xB0 0x0 gText_BerryForest_Gatekeeper_Loss
	msgbox gText_BerryForest_GatekeeperMew_4 MSG_NORMAL
	applymovement 0xA LookAtMew
	waitmovement 0x0
	msgbox gText_BerryForest_GatekeeperMew_5 MSG_NORMAL
	applymovement 0x8 LookAtGatekeeper
	waitmovement 0x0
	cry SPECIES_MEW 0x0
	msgbox gText_BerryForest_GateKeeperMewCry MSG_KEEPOPEN
	pause 0x3
	waitcry
	closeonkeypress
	msgbox gText_BerryForest_GatekeeperMew_6 MSG_NORMAL
	applymovement 0x8 WalkDown
	applymovement 0xA LookDown
	waitmovement 0x0
	hidesprite 0x8
	fanfare 0x13E
	msgbox gText_BerryForest_GatekeeperMew_7 MSG_KEEPOPEN
	waitfanfare
	closeonkeypress
	givepokemon SPECIES_MEW 100 0x0 0x0 0x0 0x0
	msgbox gText_BerryForest_GatekeeperMew_7_2 MSG_NORMAL
	giveitem ITEM_MEWNIUM_Z 0x1 MSG_OBTAIN
	msgbox gText_BerryForest_GatekeeperMew_8 MSG_NORMAL
	fadescreen 0x1
	hidesprite 0xA
	sound 0x9
	checksound
	fadescreen 0x0
	cry SPECIES_MEWTWO 0x0
	applymovement PLAYER LookDown
	waitmovement 0x0
	waitcry
	msgbox gText_BerryForest_MewtwoPost MSG_NORMAL
	fadescreen 0x1
	hidesprite 0xB
	sound 0xF
	checksound
	fadescreen 0x0
	setflag FLAG_COMPLETED_MEW_EVENT
	setvar VAR_LVL_BERRYFOREST_1 0x3
	release
	end

FaceUp:
	.byte look_up
	.byte end_m

WalkInPlace:
	.byte walk_down_onspot
	.byte walk_down_onspot
	.byte end_m

WalkUpInPlace:
	.byte walk_up_onspot
	.byte walk_up_onspot
	.byte end_m

WalkDown:
	.byte walk_down_very_slow
	.byte end_m

LookDown:
	.byte look_down
	.byte end_m

Exclaim:
	.byte look_down
	.byte exclaim
	.byte end_m

LookAtGatekeeper:
	.byte look_right
	.byte end_m

LookAtMew:
	.byte look_left
	.byte end_m

BerryForestPutBlocks:
	checkflag FLAG_COMPLETED_BERRY_FOREST
	if 0x0 _call SetFirstBlocks
	checkflag FLAG_BEAT_BERRY_ACE_TRAINER_1
	if SET _call UnSetBlocksTwo
	checkflag FLAG_BEAT_BERRY_ACE_TRAINER_2
	if SET _call UnSetBlocksThree
	checkflag FLAG_BEAT_BERRY_ACE_TRAINER_3
	if SET _call UnSetBlocksFour
	checkflag FLAG_BEAT_BERRY_ACE_TRAINER_4
	if SET _call UnSetBlocksFive
	end

SetFirstBlocks:
	compare VAR_LVL_BERRYFOREST_1 0x0
	if notequal _call SetTheFirstBlocks
	return

SetTheFirstBlocks:
	setmaptile 0x2A 0x28 0x5 0x1
	setmaptile 0x2B 0x28 0x5 0x1
	setmaptile 0x2C 0x28 0x5 0x1 
	setmaptile 0x2A 0x27 0x5 0x1
	setmaptile 0x2B 0x27 0x5 0x1
	setmaptile 0x2C 0x27 0x5 0x1
	special 0x8E
	return

UnSetBlocksTwo:
	setmaptile 0x12 0x27 0x1 0x0
	setmaptile 0x13 0x27 0x1 0x0
	setmaptile 0x14 0x27 0x1 0x0
	setmaptile 0x12 0x28 0x1 0x0
	setmaptile 0x13 0x28 0x1 0x0
	setmaptile 0x14 0x28 0x1 0x0
	special 0x8E
	return

UnSetBlocksThree:
	setmaptile 0x27 0x1D 0x1 0x0
	setmaptile 0x28 0x1D 0x1 0x0
	setmaptile 0x29 0x1D 0x1 0x0
	setmaptile 0x27 0x1E 0x1 0x0
	setmaptile 0x28 0x1E 0x1 0x0
	setmaptile 0x29 0x1E 0x1 0x0
	special 0x8E
	return

UnSetBlocksFour:
	setmaptile 0xC 0x7 0x1 0x0
	setmaptile 0xD 0x7 0x1 0x0
	setmaptile 0xE 0x7 0x1 0x0
	setmaptile 0xC 0x8 0x1 0x0
	setmaptile 0xD 0x8 0x1 0x0
	setmaptile 0xE 0x8 0x1 0x0
	special 0x8E
	return

UnSetBlocksFive:
	setmaptile 0x3 0x18 0x1 0x0
	setmaptile 0x4 0x18 0x1 0x0
	setmaptile 0x5 0x18 0x1 0x0
	setmaptile 0x3 0x19 0x1 0x0
	setmaptile 0x4 0x19 0x1 0x0
	setmaptile 0x5 0x19 0x1 0x0
	special 0x8E
	return

LevelScript_BerryForestOldManLeads:
	applymovement PLAYER WalkUpThree
	waitmovement 0x0
	sound 0x26
	call SetTheFirstBlocks
	checksound
	msgbox gText_BerryForest_GateKeeperRules MSG_NORMAL
	setvar VAR_LVL_BERRYFOREST_1 1
	setflag FLAG_DISABLE_START_MENU_BAG
	release
	end

WalkUpThree:
	.byte walk_up
	.byte walk_up
	.byte walk_up
	.byte end_m

.global EventScript_BerryForest_Gatekeeper
EventScript_BerryForest_Gatekeeper:
	lock
	faceplayer
	msgbox gText_BerryForest_GateKeeperEscort MSG_YESNO
	compare LASTRESULT YES
	if equal _goto WarpOutOfBerryForest
	release
	end

WarpOutOfBerryForest:
	setvar VAR_LVL_BERRYFOREST_1 0x0
	clearflag FLAG_DISABLE_START_MENU_BAG
	warp 0x3 48 0x2 0x0 0x0
	release
	end

.global EventScript_BerryForest_AceTrainer1
EventScript_BerryForest_AceTrainer1:
    lock
    faceplayer
    msgbox gText_BerryForest_AceTrainer1_1 MSG_YESNO
    compare LASTRESULT NO
    if equal _goto releaseend
    msgbox gText_BerryForest_AceTrainer1_2 MSG_NORMAL
    special 0x0
	@ setflag FLAG_SMALL_TRAINER_LEVELS
	setflag FLAG_DISABLE_BAG
    trainerbattle3 0x3 0x58 0x0 gText_BerryForest_AceTrainer1_3
ChooseHealMons:
    msgbox gText_BerryForest_AceTrainer1_4 MSG_YESNO
    compare LASTRESULT NO
    if equal _goto HowBraveOfYou
	setvar 0x8003 0x0 @From party
	special 0x9F @choose from party
	waitstate
	compare 0x8004 0x6
	if 0x4 _goto ChooseHealMons
    special 0x7C
    msgbox gText_BerryForest_AceTrainer1_4_2 MSG_NORMAL
    callasm HealMonInPartySlot 
ChooseHealMons2:
    msgbox gText_BerryForest_AceTrainer1_4_3 MSG_YESNO
    compare LASTRESULT NO
    if equal _goto HowBraveOfYou
    setvar 0x8003 0x0 @From party
	special 0x9F @choose from party
	waitstate
	compare 0x8004 0x6
	if 0x4 _goto ChooseHealMons2
    special 0x7C
    msgbox gText_BerryForest_AceTrainer1_4_2 MSG_NORMAL
    callasm HealMonInPartySlot
    goto EndOfAceTrainer1
    end

releaseend:
    release
    end

HowBraveOfYou:
    msgbox gText_BerryForest_AceTrainer1_5 MSG_NORMAL
    goto EndOfAceTrainer1

EndOfAceTrainer1:
    sound 0x26
    call UnSetBlocksTwo
    checksound
    msgbox gText_BerryForest_AceTrainer1_6 MSG_NORMAL
    fadescreen 0x1
    setflag FLAG_BEAT_BERRY_ACE_TRAINER_1
    hidesprite 0x800F
    sound 0x9
    checksound
    fadescreen 0x0
    release
    end

.global EventScript_BerryForest_AceTrainer2
EventScript_BerryForest_AceTrainer2:
    lock
    faceplayer
    msgbox gText_BerryForest_AceTrainer2_1 MSG_YESNO
    compare LASTRESULT NO
    if equal _goto releaseend
    msgbox gText_BerryForest_AceTrainer2_2 MSG_NORMAL
	@ setflag FLAG_SMALL_TRAINER_LEVELS
	setflag FLAG_DISABLE_BAG
    trainerbattle3 0x3 0xAE 0x0 gText_BerryForest_AceTrainer2_3
ChooseHealMons2_1:
    msgbox gText_BerryForest_AceTrainer2_4 MSG_YESNO
    compare LASTRESULT NO
    if equal _goto HowBraveOfYou2
	setvar 0x8003 0x0 @From party
	special 0x9F @choose from party
	waitstate
	compare 0x8004 0x6
	if 0x4 _goto ChooseHealMons2_1
    special 0x7C
    msgbox gText_BerryForest_AceTrainer2_4_2 MSG_NORMAL
    callasm HealMonInPartySlot 
ChooseHealMons2_2:
    msgbox gText_BerryForest_AceTrainer2_4_3 MSG_YESNO
    compare LASTRESULT NO
    if equal _goto HowBraveOfYou2
    setvar 0x8003 0x0 @From party
	special 0x9F @choose from party
	waitstate
	compare 0x8004 0x6
	if 0x4 _goto ChooseHealMons2_2
    special 0x7C
    msgbox gText_BerryForest_AceTrainer2_4_2 MSG_NORMAL
    callasm HealMonInPartySlot
    goto EndOfAceTrainer2
    end


HowBraveOfYou2:
    msgbox gText_BerryForest_AceTrainer2_5 MSG_NORMAL
    goto EndOfAceTrainer2

EndOfAceTrainer2:
    sound 0x26
    call UnSetBlocksThree
    checksound
    msgbox gText_BerryForest_AceTrainer2_6 MSG_NORMAL
    fadescreen 0x1
    setflag FLAG_BEAT_BERRY_ACE_TRAINER_2
    hidesprite 0x800F
    sound 0x9
    checksound
    fadescreen 0x0
    release
    end

.global EventScript_BerryForest_AceTrainer3
EventScript_BerryForest_AceTrainer3:
    lock
    faceplayer
    msgbox gText_BerryForest_AceTrainer3_1 MSG_YESNO
    compare LASTRESULT NO
    if equal _goto releaseend
    msgbox gText_BerryForest_AceTrainer3_2 MSG_NORMAL
	@ setflag FLAG_SMALL_TRAINER_LEVELS
	setflag FLAG_DISABLE_BAG
    trainerbattle3 0x3 0x55 0x0 gText_BerryForest_AceTrainer3_3
ChooseHealMons3_1:
    msgbox gText_BerryForest_AceTrainer3_4 MSG_YESNO
    compare LASTRESULT NO
    if equal _goto HowBraveOfYou3
	setvar 0x8003 0x0 @From party
	special 0x9F @choose from party
	waitstate
	compare 0x8004 0x6
	if 0x4 _goto ChooseHealMons3_1
    special 0x7C
    msgbox gText_BerryForest_AceTrainer3_4_2 MSG_NORMAL
    callasm HealMonInPartySlot 
ChooseHealMons3_2:
    msgbox gText_BerryForest_AceTrainer3_4_3 MSG_YESNO
    compare LASTRESULT NO
    if equal _goto HowBraveOfYou3
    setvar 0x8003 0x0 @From party
	special 0x9F @choose from party
	waitstate
	compare 0x8004 0x6
	if 0x4 _goto ChooseHealMons3_2
    special 0x7C
    msgbox gText_BerryForest_AceTrainer3_4_2 MSG_NORMAL
    callasm HealMonInPartySlot
    goto EndOfAceTrainer3
    end

HowBraveOfYou3:
    msgbox gText_BerryForest_AceTrainer3_5 MSG_NORMAL
    goto EndOfAceTrainer3

EndOfAceTrainer3:
    sound 0x26
    call UnSetBlocksFour
    checksound
    msgbox gText_BerryForest_AceTrainer3_6 MSG_NORMAL
    fadescreen 0x1
    setflag FLAG_BEAT_BERRY_ACE_TRAINER_3
    hidesprite 0x800F
    sound 0x9
    checksound
    fadescreen 0x0
    release
    end

.global EventScript_BerryForest_AceTrainer4
EventScript_BerryForest_AceTrainer4:
    lock
    faceplayer
    msgbox gText_BerryForest_AceTrainer4_1 MSG_YESNO
    compare LASTRESULT NO
    if equal _goto releaseend
    msgbox gText_BerryForest_AceTrainer4_2 MSG_NORMAL
	@ setflag FLAG_SMALL_TRAINER_LEVELS
	setflag FLAG_DISABLE_BAG
    trainerbattle3 0x3 0xAF 0x0 gText_BerryForest_AceTrainer4_3
ChooseHealMons4_1:
    msgbox gText_BerryForest_AceTrainer4_4 MSG_NORMAL
	goto EndOfAceTrainer4
    end

EndOfAceTrainer4:
    sound 0x26
    call UnSetBlocksFive
    checksound
    msgbox gText_BerryForest_AceTrainer4_6 MSG_NORMAL
    fadescreen 0x1
    setflag FLAG_BEAT_BERRY_ACE_TRAINER_4
    hidesprite 0x800F
    sound 0x9
    checksound
    fadescreen 0x0
    release
    end
.global EventScript_ThreeIslandLostelle_Start
EventScript_ThreeIslandLostelle_Start:
	lock
	faceplayer
	msgbox gText_ThreeIslandLostelle_LostelleOne MSG_KEEPOPEN @"Lostelle: Whimper[.] Sniff[.]\nOh!..."
	sound 0x15
	applymovement 0x1 EventScript_ThreeIslandLostelle_Exclaimmark
	waitmovement 0x0
	applymovement 0x1 EventScript_ThreeIslandLostelle_LostelleMove2
	waitmovement 0x0
	msgbox gText_ThreeIslandLostelle_LostelleTwo MSG_KEEPOPEN @"Oh! Here it comes again!\nNo! Go a..."
	special 0x187
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_ThreeIslandLostelle_ReleaseEnd
	checksound
	setflag FLAG_DISABLE_BAG
	setvar VAR_TOTEM 0xFFFF @raises all stats by 1
	fadescreen 0x1
	showsprite 0x3
	clearflag 0x200
	pause 0x5
	cry SPECIES_MEW 0x2
	waitcry
	fadescreen 0x0
	setflag 0x200
	pause 0x5
	setflag FLAG_NO_RUNNING
	wildbattle SPECIES_MEW 100 0x0
	fadescreen 0x1
	hidesprite 0x3
	pause 0x5
	cry SPECIES_MEW 0x2
	waitcry
	fadescreen 0x0
	msgboxsign
	msgbox gText_BerryForest_MewGotAway MSG_KEEPOPEN
	pause 0x5
	closeonkeypress
	special 0x188
	normalmsg
	applymovement 0x1 EventScript_ThreeIslandLostelle_FacePlayer
	waitmovement 0x0
	msgbox gText_ThreeIslandLostelle_LostelleThree MSG_KEEPOPEN @"Ohh! That was so scary!\nThank you..."
	giveitem ITEM_PSYCHIUM_Z 0x1 MSG_OBTAIN
	special 0x94
	msgbox gText_ThreeIslandLostelle_LostelleFour MSG_KEEPOPEN @"What@s your name?\pLostelle@s scar..."
	closeonkeypress
	setflag FLAG_COMPLETED_BERRY_FOREST
	setflag 0x7A
	setvar 0x4079 0x2
	clearflag 0x75
	clearflag FLAG_DISABLE_START_MENU_BAG
	setvar VAR_LVL_BERRYFOREST_1 0x1
	warp 0x21 0x0 0xFF 0x6 0x6
	waitstate
	release
	end

EventScript_ThreeIslandLostelle_ReleaseEnd:
	release
	end

EventScript_ThreeIslandLostelle_Exclaimmark:
.byte 0x62
.byte 0xFE

EventScript_ThreeIslandLostelle_LostelleMove2:
.byte 0x2F
.byte 0x1C
.byte 0x30
.byte 0x1B
.byte 0x2F
.byte 0xFE

EventScript_ThreeIslandLostelle_FacePlayer:
.byte 0x4A
.byte 0xFE

.global EventScript_ThreeIslandPort_CaveGuy
EventScript_ThreeIslandPort_CaveGuy:
	lock
	faceplayer
	checkflag 0x2E2
	if 0x1 _goto CaveGuyDonege
	msgbox gText_ThreeIsland_CaveGuy1 MSG_KEEPOPEN 
	giveitem ITEM_GROUNDIUM_Z 0x1 MSG_OBTAIN
	setflag 0x2E2
	goto CaveGuyDonege
	end

CaveGuyDonege:
	msgbox gText_ThreeIsland_CaveGuyDonege MSG_KEEPOPEN 
	release
	end


.global EventScript_BerryForest_TM95
EventScript_BerryForest_TM95:
	hidesprite 0x800F
	giveitem ITEM_TM95 0x1 MSG_OBTAIN
	setflag 0x1EC
	release
	end

.global EventScript_BerryForest_GroundGem
EventScript_BerryForest_GroundGem:
	hidesprite 0x800F
	giveitem ITEM_GROUND_GEM 0x1 MSG_OBTAIN
	setflag 0x1EB
	release
	end


