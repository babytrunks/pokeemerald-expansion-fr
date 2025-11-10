.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ VAR_LVL_VIRIDIANFOLLOWER, 0x513B
.equ VAR_LVL_BERRYFOREST_1, 0x5139
.equ FLAG_GIVE_EJECT_BUTTON, 0x1075
.equ FLAG_GIVE_SAFETY_GOGGLES, 0x1076
.equ FLAG_GIVE_PROTECTIVE_PADS, 0x1077
.equ FLAG_GIVE_RED_CARD, 0x1078

.global TestFollower2
TestFollower2:
	lock
	faceplayer
	
AskForFollowStuff:
	checkflag 0x1055
	if 0x1 _goto StopFollowingAsk
	callasm CheckIfPkmnOkToFollow + 1
	compare LASTRESULT YES
	if equal _goto AskIfWantToComeOut
	compare LASTRESULT NO 
	if equal _goto NoEligiblePkmn
	end

AskIfWantToComeOut:
	msgbox gText_Viridian_FollowerPkmn1 MSG_YESNO
	compare LASTRESULT YES
	if equal _goto BringOutPkmn
	compare LASTRESULT NO 
	if equal _goto AnotherTime

BringOutPkmn:
	fadescreen 0x1
	sound 0xF
	showsprite 0x14
	clearflag 0x1054
	setflag 0x1055
	@ setflag 0x926
    setvar 0x8000 0x14
    setvar 0x8001 0x1E
    special 0xD1 
	checksound
	fadescreen 0x0
    release
    end

StopFollowingAsk:
	msgbox gText_Viridian_FollowerPkmnDisble MSG_YESNO
	compare LASTRESULT YES
	if equal _goto StopFollowing
	release
	end

StopFollowing:
	clearflag 0x1055
	fadescreen 0x1
	sound 0xF
	special 0xD2
	checksound
	fadescreen 0x0
	release
	end

AnotherTime:
	msgbox gText_Viridian_FollowerPkmn2 MSG_NORMAL
	release
	end

NoEligiblePkmn:
	msgbox gText_Viridian_FollowerPkmn3 MSG_NORMAL
	release
	end

.global EventScript_FollowMePkmn
EventScript_FollowMePkmn:
	lock
	faceplayer
	call CheckIfCanTriggerMewEvent
	bufferpokemon 0x0 0x5130 
    callasm BufferNicknameFollowPkmn
	callasm CheckForFollowerSpecialConditions
	compare LASTRESULT 0x1
	if equal _goto UnhappySurfer
	compare LASTRESULT 0x2
	if equal _goto FollowerAmpedUp
	compare LASTRESULT 0x3
	if equal _goto FollowerComfyRockTunnel
	compare LASTRESULT 0x4
	if equal _goto FollowerErikaGym
	compare LASTRESULT 0x5
	if equal _goto FollowerChucksDojo
	callasm DetermineHappinessFollowPkmn
	@ compare LASTRESULT 0x6
	@ if equal _goto TransformDitto
	compare LASTRESULT 0x1
	if equal _goto VeryHappy
	compare LASTRESULT 0x2
	if equal _goto LooksPleased
	compare LASTRESULT 0x3
	if equal _goto LooksCute
	goto LooksMean
	end

UnhappySurfer:
	cry 0x5130 0x5
    waitcry
    pause 0x3
	msgbox gText_Follower_UnhappySurfer MSG_NORMAL
	release
	end

CheckIfCanTriggerMewEvent:
	checkflag 0x2A3 @Lostelle Event
	if 0x1 _call CheckIfCanTriggerMewEvent2
	return

CheckIfCanTriggerMewEvent2:
	callasm CheckIfCanDoMewEvent
	compare LASTRESULT 0x1
	if equal _goto TriggerMewEvent
	return

TriggerMewEvent:
	msgbox gText_Follower_Mewtwo_Ask MSG_YESNO
	compare LASTRESULT YES
	if equal _goto WarpToMew
	compare LASTRESULT NO
	if equal _goto MewtwoFine
	end

WarpToMew:
	setvar VAR_LVL_BERRYFOREST_1 0x2
	clearflag 0x201
	warp 0x1 109 0x3 0x0 0x0
	waitstate
	release
	end

@ TransformDitto:
	
MewtwoFine:
	msgbox gText_Follower_Mewtwo_Reject MSG_NORMAL
	release
	end


VeryHappy:
	cry 0x5130 0x0
    waitcry
    pause 0x3
	random 0x64
	compare 0x800D 0x0 
	if 0x1 _goto GiveNugget
	compare 0x800D 0x1
	if 0x1 _goto GiveBigNugget
	msgbox gText_FollowMePkmn1 MSG_NORMAL
	sound 0x15
	callasm FollowerApplyMovementHappy
	checksound
	release
	end

FollowerAmpedUp:
	cry 0x5130 0x0
    waitcry
    pause 0x3
	random 0x64
	compare 0x800D 0x0 
	if 0x1 _goto GiveNugget
	compare 0x800D 0x1
	if 0x1 _goto GiveBigNugget
	msgbox gText_FollowMePkmnAmpedUp MSG_NORMAL
	sound 0x15
	callasm FollowerApplyMovementHappy
	checksound
	checkflag FLAG_GIVE_EJECT_BUTTON
	if 0x0 _goto GiveEjectButton
	release
	end

FollowerComfyRockTunnel:
	cry 0x5130 0x0
    waitcry
    pause 0x3
	random 0x64
	compare 0x800D 0x0 
	if 0x1 _goto GiveNugget
	compare 0x800D 0x1
	if 0x1 _goto GiveBigNugget
	msgbox gText_FollowMePkmnComfyRockTunnel MSG_NORMAL
	sound 0x15
	callasm FollowerApplyMovementHappy
	checksound
	checkflag FLAG_GIVE_SAFETY_GOGGLES
	if 0x0 _goto GiveSafetyGoggles
	release
	end

FollowerErikaGym:
	cry 0x5130 0x0
    waitcry
    pause 0x3
	random 0x64
	compare 0x800D 0x0 
	if 0x1 _goto GiveNugget
	compare 0x800D 0x1
	if 0x1 _goto GiveBigNugget
	msgbox gText_FollowMePkmnComfyRockTunnel MSG_NORMAL
	sound 0x15
	callasm FollowerApplyMovementHappy
	checksound
	checkflag FLAG_GIVE_RED_CARD
	if 0x0 _goto GiveRedCard
	release
	end

FollowerChucksDojo:
	cry 0x5130 0x0
    waitcry
    pause 0x3
	random 0x64
	compare 0x800D 0x0 
	if 0x1 _goto GiveNugget
	compare 0x800D 0x1
	if 0x1 _goto GiveBigNugget
	msgbox gText_FollowMePkmnComfyRockTunnel MSG_NORMAL
	sound 0x15
	callasm FollowerApplyMovementHappy
	checksound
	checkflag FLAG_GIVE_PROTECTIVE_PADS
	if 0x0 _goto GiveProtectivePads
	release
	end

GiveEjectButton:
	setflag FLAG_GIVE_EJECT_BUTTON
	msgbox gText_FollowerPokemon_EjectButton MSG_NORMAL
	giveitem ITEM_EJECT_BUTTON 0x1 MSG_OBTAIN
	release
	end

GiveSafetyGoggles:
	setflag FLAG_GIVE_SAFETY_GOGGLES
	msgbox gText_FollowerPokemon_EjectButton MSG_NORMAL
	giveitem ITEM_SAFETY_GOGGLES 0x1 MSG_OBTAIN
	release
	end

GiveRedCard:
	setflag FLAG_GIVE_RED_CARD
	msgbox gText_FollowerPokemon_EjectButton MSG_NORMAL
	giveitem ITEM_RED_CARD 0x1 MSG_OBTAIN
	release
	end

GiveProtectivePads:
	setflag FLAG_GIVE_PROTECTIVE_PADS
	msgbox gText_FollowerPokemon_EjectButton MSG_NORMAL
	giveitem ITEM_PROTECTIVE_PADS 0x1 MSG_OBTAIN
	release
	end

LooksPleased:
	cry 0x5130 0x0
    waitcry
    pause 0x3
	msgbox gText_FollowMePkmn3 MSG_NORMAL
	checkitem ITEM_ORAN_BERRY 0x1 
	compare LASTRESULT 0x1
	if greaterorequal _goto AskGiveOranBerry
	release
	end

LooksCute:
	cry 0x5130 0x0
    waitcry
    pause 0x3
	msgbox gText_FollowMePkmn4 MSG_NORMAL
	checkitem ITEM_ORAN_BERRY 0x1 
	compare LASTRESULT 0x1
	if greaterorequal _goto AskGiveOranBerry
	release
	end

LooksMean:
	cry 0x5130 0x5
    waitcry
    pause 0x3
	msgbox gText_FollowMePkmn5 MSG_NORMAL
	checkitem ITEM_ORAN_BERRY 0x1 
	compare LASTRESULT 0x1
	if greaterorequal _goto AskGiveOranBerry
	release
	end

AskGiveOranBerry:
	msgbox gText_FollowMePkmn_OranBerry MSG_YESNO
	compare LASTRESULT YES
	if equal _goto GiveFollowOranBerry
	release
	end

GiveFollowOranBerry:
	removeitem ITEM_ORAN_BERRY 0x1
	msgbox gText_FollowMePkmn_AteBerry MSG_KEEPOPEN
	pause 0x3
	callasm PlaySEChomp
	pause 0x5
	checksound
	callasm GiveHappyToFollowerMon + 1
	msgbox gText_FollowMePkmn_AteBerry2 MSG_NORMAL
	sound 0x15
	callasm FollowerApplyMovementHappy
	checksound
	release
	end

Happy:
	.byte say_smile
	.byte end_m

BeginningOfFindItem:
    sound 0x1C
    callasm FollowerApplyMovementJumpInPlace
    checksound
    pause 0x8
    sound 0xB5
    applymovement PLAYER QuestionMark
    waitmovement 0x0
    checksound
    pause 0x10
    msgbox gText_PkmnFoundSomething MSG_KEEPOPEN
    pause 0x30
    closeonkeypress
    sound 0x15
    applymovement PLAYER Exclaimation
    waitmovement 0x0
    checksound
	msgbox gText_FollowMePkmn2 MSG_KEEPOPEN
    pause 0x3
    closeonkeypress
    return

GiveNugget:
    call BeginningOfFindItem
	giveitem ITEM_WISHING_PIECE 0x1 MSG_OBTAIN
	release
	end

QuestionMark:
    .byte say_question
    .byte end_m
    
GiveBigNugget:
    call BeginningOfFindItem
	giveitem ITEM_BIG_NUGGET 0x1 MSG_OBTAIN
	release
	end

Exclaimation:
    .byte exclaim
    .byte end_m

.global gMapScripts_ViridanCityPC
gMapScripts_ViridanCityPC:
	mapscript MAP_SCRIPT_ON_TRANSITION HideFollowerPokemon
	mapscript MAP_SCRIPT_ON_RESUME 0x81BC05C
	mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScripts_ViridianCityFollowerNPC
	.byte MAP_SCRIPT_TERMIN

HideFollowerPokemon:
	sethealingplace 0x2
	special 0xE1
	compare LASTRESULT 0x0
	if equal _goto HideBcNoFollower
	release
	end

HideBcNoFollower:
	hidesprite 0x14
	setflag 0x1054
	release
	end

LevelScripts_ViridianCityFollowerNPC:
	levelscript VAR_LVL_VIRIDIANFOLLOWER, 0, LevelScript_ViridianCityFollowerNPC
	.hword MAP_SCRIPT_TERMIN

LevelScript_ViridianCityFollowerNPC:
	sound 0x15 
	applymovement 0x6 Exclaim
	waitmovement 0x0
	checksound
	applymovement 0x6 WalkToYou
	waitmovement 0x0
	setvar VAR_LVL_VIRIDIANFOLLOWER 0x1
	checkflag 0x820 @beat brock 
	if 0x0 _goto YouareNewTrainer
	checkflag 0x820
	if 0x1 _goto YouareExperiencedTrainer
	end

YouareNewTrainer:
	msgbox gText_ViridianCity_FollowerNew1 MSG_NORMAL
	call AskForFollowStuff

YouareExperiencedTrainer:
	msgbox gText_ViridianCity_FollowerNew1_1 MSG_NORMAL
	call AskForFollowStuff

Exclaim:
	.byte exclaim
	.byte end_m

WalkToYou:
	.byte walk_down
	.byte walk_down
	.byte walk_left
	.byte walk_left
	.byte end_m
