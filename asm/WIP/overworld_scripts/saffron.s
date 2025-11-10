.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ VAR_BATTLE_AURAS, 0x5119
.equ FIGHTING_SPIRIT, 0x1
.equ PERMA_TRICK_ROOM_STRING, 0x2
.equ VAR_TERRAIN, 0x5000
.equ PSYCHIC_TERRAIN, 0x4
.equ FLAG_HARDCORE_MODE, 0x1034
.equ FLAG_MINIMAL_GRINDING_MODE, 0x1032

.global EventScript_Saffron_Nerd
EventScript_Saffron_Nerd:
    lock
    faceplayer
    msgbox gText_Saffron_Nerd MSG_YESNO
    compare LASTRESULT 0
    if equal _goto NahImGood
    checkitem ITEM_BOTTLE_CAP 0x1
    compare 0x800D 0x1
    if lessthan _goto YouDontHave
    setvar 0x8003 0x0 
    special 0x9F 
    waitstate 
    compare 0x8004 0x6
    if greaterorequal _goto NahImGood
	callasm CheckChosenMonHiddenAbility + 1
	compare LASTRESULT 0x0 
    if equal _goto DontHaveHidden
	msgbox gText_AbilityCapsuleOfferChange MSG_YESNO 
	compare LASTRESULT NO 
	if equal _goto NahImGood
    callasm SetChosenMonHiddenAbility + 1
    msgbox gText_Saffron_NerdGiveItem MSG_FACE
    msgbox gText_Saffron_NerdAfter MSG_FACE
    removeitem ITEM_BOTTLE_CAP 0x1
    release
    end

NahImGood:
    release
    end

YouDontHave:
    msgbox gText_Saffron_NerdReject MSG_FACE
    release
    end

DontHaveHidden: 
    msgbox gText_SaffronNerd_NoHidden MSG_FACE 
    release 
    end 

.global EventScript_Saffron_Nerd2
EventScript_Saffron_Nerd2:
	special 0x187
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_Saffron_Nerd2End
	lock
	faceplayer
	preparemsg gText_gamecornertms_Hello @"Hi, there!\nMay I help you?"
	waitmsg
	pokemart EventScript_pill_Values
	msgbox gText_gamecornertms_Comeagain MSG_KEEPOPEN @"Please come again!"
	release
	end

EventScript_Saffron_Nerd2End:
	release
	end

.align 1
EventScript_pill_Values:
	.hword ITEM_ABILITY_CAPSULE
	.hword ITEM_CHERI_BERRY
	.hword ITEM_CHESTO_BERRY
	.hword ITEM_RAWST_BERRY
	.hword ITEM_ASPEAR_BERRY
	.hword ITEM_PERSIM_BERRY
	.hword ITEM_POWER_BRACER
	.hword ITEM_POWER_BELT
	.hword ITEM_POWER_LENS
	.hword ITEM_POWER_BAND
	.hword ITEM_POWER_ANKLET
	.hword ITEM_POWER_WEIGHT
	.hword ITEM_DESTINY_KNOT
	.hword ITEM_RED_NECTAR
	.hword ITEM_YELLOW_NECTAR
	.hword ITEM_PINK_NECTAR
	.hword ITEM_PURPLE_NECTAR
    .hword 0x0

.global EventScript_Saffron_Test
EventScript_Saffron_Test:
    lock
    faceplayer 
    giveitem 0x1AA 0x1 MSG_OBTAIN 
    release 
    end 

.global EventScript_SilphCo_TeamAlert
EventScript_SilphCo_TeamAlert:
    lock 
    applymovement 0xFF StopInPlace
    msgbox gText_SilphCo_TeamAlert1 MSG_NORMAL
    special 0x0 
    setvar 0x5060 0x1 
    release 
    end 

StopInPlace:
    .byte look_down
    .byte end_m

.global EventScript_Saffron_ManyTutors2
EventScript_Saffron_ManyTutors2:    
    lock
    faceplayer 
    msgbox gText_Saffron_ManyTutors1 MSG_YESNO 
    compare LASTRESULT YES 
    if 0x0 _goto RegCancel 
    showmoney 0x35 0x00 0x00
    goto FirstList2
    release 
    end 

FirstList2:
	setvar 0x8000 0x3
	setvar 0x8001 0x6
	setvar 0x8004 0x0 
	preparemsg gText_Saffron_ManyTutors6
    waitmsg
	special 0x158
	waitstate 
	compare LASTRESULT 0x0
	if 0x1 _goto HydroPump
	compare LASTRESULT 0x1
	if 0x1 _goto DrillRun
	compare LASTRESULT 0x2
	if 0x1 _goto BlazeKick
	compare LASTRESULT 0x3
	if 0x1 _goto PainSplit
	compare LASTRESULT 0x4
	if 0x1 _goto ZenButt
	compare LASTRESULT 0x5
	if 0x1 _goto WeatherBall
	compare LASTRESULT 0x6
	if 0x1 _goto AirSlash
    compare LASTRESULT 0x7
	if 0x1 _goto Hex
    compare LASTRESULT 0x8
    if 0x1 _goto MysticFire
    compare LASTRESULT 0x9
    if 0x1 _goto SeedBomb
    compare LASTRESULT 0xA
    if 0x1 _goto LeafBlade
    compare LASTRESULT 0xB
	if 0x1 _goto KnockOff
	compare LASTRESULT 0xC
	if 0x1 _goto PowerGem
	compare LASTRESULT 0xD
	if 0x1 _goto RockBlast
	compare LASTRESULT 0xE
	if 0x1 _goto PinMissile
	compare LASTRESULT 0xF
	if 0x1 _goto IcicleSpear 
	compare LASTRESULT 0x10
	if 0x1 _goto TailSlap 
	compare LASTRESULT 0x11
	if 0x1 _goto BodySlam
	compare LASTRESULT 0x12
	if 0x1 _goto FoulPlay
	compare LASTRESULT 0x13
	if 0x1 _goto IronDefense
	hidemoney 0x35 0x00 
    msgbox gText_Saffron_ManyTutors5 MSG_FACE 
    release 
    end 

HydroPump: 
    setvar 0x8005 0x7B
    goto EndScript
    end 

IronDefense:
	setvar 0x8005 0x14
	goto EndScript
	end

DrillRun: 
    setvar 0x8005 0x23
    goto EndScript
    end 

BlazeKick:
    setvar 0x8005 0x68
    goto EndScript
    end 

PainSplit:
    setvar 0x8005 0x1B
    goto EndScript
    end 

ZenButt:
    setvar 0x8005 0x1F
    goto EndScript 
    end 

WeatherBall:
    setvar 0x8005 0x65
    goto EndScript 
    end 

AirSlash:
    setvar 0x8005 0x66
    goto EndScript 
    end 

Hex: 
    setvar 0x8005 0x64
    goto EndScript 
    end 

MysticFire: 
    setvar 0x8005 0x70
    goto EndScript 
    end 

SeedBomb:
    setvar 0x8005 0x20
    goto EndScript 
    end 

LeafBlade:
    setvar 0x8005 0x6E
    goto EndScript 
    end 

KnockOff:
    setvar 0x8005 0x35
    goto EndScript 
    end 

PowerGem:
	setvar 0x8005 0x74
	goto EndScript
	end 

RockBlast:
	setvar 0x8005 0x57
	goto EndScript 
	end 

PinMissile:
	setvar 0x8005 0x54
	goto EndScript 
	end 

IcicleSpear:
	setvar 0x8005 0x55
	goto EndScript 
	end 

TailSlap: 
	setvar 0x8005 0x56
	goto EndScript 
	end 

BodySlam:
	setvar 0x8005 0x5B
	goto EndScript
	end 

FoulPlay:
	setvar 0x8005 0x29
	goto EndScript
	end 

EndScript:
    checkmoney 0x1D4C 0x0
    compare LASTRESULT 0x1
    if 0x0 _goto NotEnoughMoney
    msgbox gText_Saffron_ManyTutors7 MSG_NORMAL 
    hidemoney 0x35 0x00 
    special 0x18D 
    waitstate 
    compare LASTRESULT 0x0 
    if 0x1 _goto RegCancel
    showmoney 0x35 0x00
    msgbox gText_Saffron_ManyTutors4 MSG_NORMAL 
    sound 0x58
    removemoney 0x1D4C 0x00
    updatemoney 0x35 0x00 0x00
    checksound 
    hidemoney 0x35 0x00
    msgbox gText_Saffron_ManyTutors3 MSG_NORMAL 
    release 
    end 

NotEnoughMoney:
    msgbox gText_Saffron_ManyTutors2 MSG_NORMAL 
    hidemoney 0x35 0x00
    release 
    end 

CancelDis:
    hidemoney 0x35 0x00
    msgbox gText_Saffron_ManyTutors5 MSG_FACE 
    release 
    end 

RegCancel:
    msgbox gText_Saffron_ManyTutors5 MSG_FACE 
    release 
    end 

.global EventScript_liquidation_Start
EventScript_liquidation_Start:
	lock
	faceplayer
	textcolor 0x0
	checkflag 0x957
	if 0x1 _goto EventScript_liquidation_Cost
	msgbox gText_liquidation_1 0x5
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_liquidation_Cancel
	msgbox gText_liquidation_3 0x6
	setvar 0x8005 0x27
	call EventScript_liquidation_Teach
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_liquidation_Cancel
	setflag 0x957
	msgbox gText_liquidation_4 0x6
	release
	end


EventScript_liquidation_Teach:
	special 0x18D
	waitstate
	return

EventScript_liquidation_Cost:
	showmoney 0x00 0x00 0x00
	msgbox gText_liquidation_1 0x6
	msgbox gText_liquidation_2 0x5
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_liquidation_Cancelhide
	checkmoney 0x1D4C 0x00
	compare 0x800D 0x1
	if 0x0 _goto EventScript_liquidation_Nomoney
	msgbox gText_liquidation_3 0x6
	hidemoney 0x00 0x00
	setvar 0x8005 0x27
	call EventScript_liquidation_Teach
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_liquidation_Cancel
	showmoney 0x00 0x00 0x00
	msgbox gText_liquidation_Wait 0x6
	removemoney 0x1D4C 0x00
    updatemoney 0x00 0x00 0x00
	sound 0x58
	msgbox gText_liquidation_4 0x6
	hidemoney 0x00 0x00
	checksound
	release
	end

EventScript_liquidation_Cancel:
	msgbox gText_liquidation_No 0x6
	release
	end

EventScript_liquidation_Cancelhide:
	hidemoney 0x00 0x00
	msgbox gText_liquidation_No 0x6
	release
	end

EventScript_liquidation_Nomoney:
	msgbox gText_liquidation_Poor 0x6
	hidemoney 0x00 0x00
	release
	end

.global EventScript_EVSubtracter_Start
EventScript_EVSubtracter_Start:
	lock
	faceplayer
	textcolor 0x0
	msgbox gText_EVSubtracter_Msg 0x5
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_EVSubtracter_MinusEVs
	goto EventScript_EVSubtracter_Cancel
	end

EventScript_EVSubtracter_MinusEVs:
	setvar 0x8003 0x0 @From party
	special 0x9F @choose from party
	waitstate
	compare 0x8004 0x6
	if 0x4 _goto EventScript_EVSubtracter_Cancel
	special 0x7C @puts the selected mon in party into buffer
	goto EventScript_EVSubtracter_CheckEVs

EventScript_EVSubtracter_CheckEVs:
	setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_EVSubtracter_HP
	special 0x25
	setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_EVSubtracter_Attack
	special 0x25
	setvar 0x8006 0x2 @third item
	loadpointer 0x0 gText_EVSubtracter_Defense
	special 0x25
	setvar 0x8006 0x3 @fourth item
	loadpointer 0x0 gText_EVSubtracter_SpA
	special 0x25
	setvar 0x8006 0x4 @fifth item
	loadpointer 0x0 gText_EVSubtracter_SpDef
	special 0x25
	setvar 0x8006 0x5 @sixth item
	loadpointer 0x0 gText_EVSubtracter_Speed
	special 0x25
	setvar 0x8006 0x6 @7th item
	loadpointer 0x0 gText_EVSubtracter_AllStats
	special 0x25
	preparemsg gText_EVSubtracter_1
	waitmsg
	multichoice 0x0 0x0 0x25 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_EVSubtracter_ReduceHP
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_EVSubtracter_ReduceAttack
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_EVSubtracter_ReduceDef
	compare LASTRESULT 0x3
	if 0x1 _goto EventScript_EVSubtracter_ReduceSpA
	compare LASTRESULT 0x4
	if 0x1 _goto EventScript_EVSubtracter_ReduceSpD
	compare LASTRESULT 0x5
	if 0x1 _goto EventScript_EVSubtracter_ReduceSpeed
	compare LASTRESULT 0x6
	if 0x1 _goto EventScript_EVSubtracter_ReduceAllEVs
	goto EventScript_EVSubtracter_MinusEVs @means they pressed B, goto previous screen
	end

EventScript_EVSubtracter_Cancel:
	msgbox gText_EVSubtracter_2 0x6
	release
	end


EventScript_EVSubtracter_ReduceHP:
	setvar 0x8005 0x0
	msgbox gText_EVSubtracter_HP 0x6
	goto EventScript_EVSubtracter_Statmultichoice

EventScript_EVSubtracter_ReduceAttack:
	setvar 0x8005 0x1
	msgbox gText_EVSubtracter_Attack 0x6
	goto EventScript_EVSubtracter_Statmultichoice

EventScript_EVSubtracter_ReduceDef:
	setvar 0x8005 0x2
	msgbox gText_EVSubtracter_Defense 0x6
	goto EventScript_EVSubtracter_Statmultichoice

EventScript_EVSubtracter_ReduceSpA:
	setvar 0x8005 0x4
	msgbox gText_EVSubtracter_SpA 0x6
	goto EventScript_EVSubtracter_Statmultichoice

EventScript_EVSubtracter_ReduceSpD:
	setvar 0x8005 0x5
	msgbox gText_EVSubtracter_SpDef 0x6
	goto EventScript_EVSubtracter_Statmultichoice

EventScript_EVSubtracter_ReduceSpeed:
	setvar 0x8005 0x3
	msgbox gText_EVSubtracter_Speed 0x6
	goto EventScript_EVSubtracter_Statmultichoice

EventScript_EVSubtracter_ReduceAllEVs:
	msgbox gText_EVSubtracter_DoAll MSG_YESNO 
	compare LASTRESULT YES 
	if notequal _goto EventScript_EVSubtracter_CheckEVs
	setvar 0x8005 0x0
	setvar 0x8006 0x1FC
	special 0xF
	setvar 0x8005 0x1 
	setvar 0x8006 0x1FC
	special 0xF
	setvar 0x8005 0x2
	setvar 0x8006 0x1FC
	special 0xF
	setvar 0x8005 0x3 
	setvar 0x8006 0x1FC
	special 0xF
	setvar 0x8005 0x4 
	setvar 0x8006 0x1FC
	special 0xF
	setvar 0x8005 0x5 
	setvar 0x8006 0x1FC
	special 0xF
	msgbox gText_EVSubtracter_DoAllDone MSG_NORMAL 
	goto EventScript_EVSubtracter_Doanother
	end 


EventScript_EVSubtracter_Statmultichoice:
	call EventScript_EVSubtracter_Checkstat0
	setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_EVSubtracter_Ten
	special 0x25
	setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_EVSubtracter_Fifty
	special 0x25
	setvar 0x8006 0x2 @third item
	loadpointer 0x0 gText_EVSubtracter_Hundred
	special 0x25
    setvar 0x8006 0x3 
    loadpointer 0x0 gText_EVSubtracter_All
    special 0x25 
	preparemsg gText_EVSubtracter_Reduceby
	waitmsg
	multichoice 0x0 0x0 0x22 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_EVSubtracter_Reduce10
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_EVSubtracter_Reduce50
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_EVSubtracter_Reduce100
    compare LASTRESULT 0x3
	if 0x1 _goto EventScript_EVSubtracter_ReduceAll
	goto EventScript_EVSubtracter_CheckEVs @means they pressed B, go back to previous screen
	end

EventScript_EVSubtracter_Reduce10:
	setvar 0x8006 0x010A @subtracting 10
	special 0xF
	msgbox gText_EVSubtracter_By10 0x6
	goto EventScript_EVSubtracter_Doanother
	end

EventScript_EVSubtracter_Reduce50:
	setvar 0x8006 0x0132
	special 0xF
	msgbox gText_EVSubtracter_By50 0x6
	goto EventScript_EVSubtracter_Doanother
	end

EventScript_EVSubtracter_Reduce100:
	setvar 0x8006 0x164
	special 0xF
	msgbox gText_EVSubtracter_By100 0x6
	goto EventScript_EVSubtracter_Doanother
	end

EventScript_EVSubtracter_ReduceAll:
	setvar 0x8006 0x1FC
	special 0xF
	msgbox gText_EVSubtracter_ByAll 0x6
	goto EventScript_EVSubtracter_Doanother
	end

EventScript_EVSubtracter_Checkstat0:
	special2 LASTRESULT 0x7
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_EVSubtracter_Noeffect
	special2 LASTRESULT 0x7
	buffernumber 0x1 LASTRESULT
	msgbox gText_EVSubtracter_Currently 0x6
	return

EventScript_EVSubtracter_Noeffect:
	msgbox gText_EVSubtracter_None 0x6
	goto EventScript_EVSubtracter_CheckEVs
	end

EventScript_EVSubtracter_Doanother:
	msgbox gText_EVSubtracter_4 0x5
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_EVSubtracter_MinusEVs
	goto EventScript_EVSubtracter_Cancel
	end

.global EventScript_EvChecker_Start
EventScript_EvChecker_Start:
	lock
	faceplayer
	textcolor 0x0
	msgbox gText_EvChecker_Msg 0x5
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_EvChecker_CheckEVs
	goto EventScript_EvChecker_Cancel
	end

EventScript_EvChecker_CheckEVs:
	setvar 0x8003 0x0 @From party
	special 0x9F @choose from party
	waitstate
	compare 0x8004 0x6
	if 0x4 _goto EventScript_EvChecker_Cancel
	special 0x7C @puts the selected mon in party into buffer
	msgbox gText_EvChecker_1 0x6
	setvar 0x8005 0x0
	special2 LASTRESULT 0x7
	buffernumber 0x0 LASTRESULT @hp evs in buffer 1
	setvar 0x8005 0x1
	special2 LASTRESULT 0x7
	buffernumber 0x1 LASTRESULT @atk evs in buffer 2
	setvar 0x8005 0x2
	special2 LASTRESULT 0x7
	buffernumber 0x2 LASTRESULT @def evs in buffer 3
	msgbox gText_EvChecker_3 0x6
	setvar 0x8005 0x3
	special2 LASTRESULT 0x7
	buffernumber 0x2 LASTRESULT @speed evs in buffer 1
	setvar 0x8005 0x4
	special2 LASTRESULT 0x7
	buffernumber 0x0 LASTRESULT @spa evs in buffer 2
	setvar 0x8005 0x5
	special2 LASTRESULT 0x7
	buffernumber 0x1 LASTRESULT @spdef evs in buffer 3
    msgbox gText_EvChecker_5 0x6
	msgbox gText_EvChecker_4 0x5
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_EvChecker_CheckEVs
	goto EventScript_EvChecker_Cancel
	end

EventScript_EvChecker_Cancel:
	msgbox gText_EvChecker_2 0x6
	release
	end


.global EventScript_IvChecker_Start
EventScript_IvChecker_Start:
	lock
	faceplayer
	textcolor 0x0
	msgbox gText_IvChecker_Msg 0x5
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_EvChecker_CheckIVs
	goto EventScript_EvChecker_Cancel
	end

EventScript_EvChecker_CheckIVs:
	setvar 0x8003 0x0 @From party
	special 0x9F @choose from party
	waitstate
	compare 0x8004 0x6
	if 0x4 _goto EventScript_EvChecker_Cancel
	special 0x7C @puts the selected mon in party into buffer
	msgbox gText_EvChecker_1 0x6 @ This is good 
	setvar 0x8005 0x0
	special2 LASTRESULT 0x8
	buffernumber 0x0 LASTRESULT @hp evs in buffer 1
	setvar 0x8005 0x1
	special2 LASTRESULT 0x8
	buffernumber 0x1 LASTRESULT @atk evs in buffer 2
	setvar 0x8005 0x2
	special2 LASTRESULT 0x8
	buffernumber 0x2 LASTRESULT @def evs in buffer 3
	msgbox gText_IvChecker_3 0x6
	setvar 0x8005 0x3
	special2 LASTRESULT 0x8
	buffernumber 0x2 LASTRESULT @speed evs in buffer 1
	setvar 0x8005 0x4
	special2 LASTRESULT 0x8
	buffernumber 0x0 LASTRESULT @spa evs in buffer 2
	setvar 0x8005 0x5
	special2 LASTRESULT 0x8
	buffernumber 0x1 LASTRESULT @spdef evs in buffer 3
    msgbox gText_IvChecker_5 0x6
	msgbox gText_EvChecker_4 0x5 @ this is good 
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_EvChecker_CheckIVs
	goto EventScript_EvChecker_Cancel
	end

.global EventScript_chuck_Start
EventScript_chuck_Start:
	lock
	faceplayer
	checkflag 0x950
	if 0x1 _goto EventScript_chuck_Done
	msgbox gText_chuck_1 0x6
	goto EventScript_chuck_Battle
	end

EventScript_chuck_Battle:
	special 0x0
	setflag 0x915
	setflag 0x90E
	checkflag FLAG_HARDCORE_MODE 
	if 0x1 _call SetFightingSpirit
	trainerbattle3 0x3 0x13D 0x0 gText_chuck_Defeat
	msgbox gText_chuck_6 0x6
	giveitem ITEM_TM60 0x1 MSG_OBTAIN
	msgbox gText_chuck_8 0x6
	giveitem ITEM_EXPERT_BELT 0x1 MSG_OBTAIN
	msgbox gText_chuck_Take 0x6
	setflag 0x950
	setvar 0x4081 0x1 @stop the script tiles
	release
	end

SetFightingSpirit:
	setvar VAR_BATTLE_AURAS FIGHTING_SPIRIT
	return

EventScript_chuck_Done:
	lock
	faceplayer
	checkitem ITEM_MEGA_RING 0x1
	compare 0x800D 0x1
	if 0x4 _goto EventScript_chuck_Givemega
	msgbox gText_chuck_9 0x6
	release
	end

EventScript_chuck_Givemega:
	lock
	faceplayer
	checkflag 0x951
	if 0x1 _goto EventScript_chuck_Donedone
	checkflag FLAG_MINIMAL_GRINDING_MODE
	if 0x1 _goto ChuckGiveMega_MinGrindingMode
	msgbox gText_chuck_10 0x6
	bufferfirstpokemon 0x00
	msgbox gText_chuck_11 0x6
	setvar 0x8003 0x0 @From party
	setvar 0x8004 0x0 @1st Pokemon
	setvar 0x8005 0x1
	special2 LASTRESULT 0x7
	buffernumber 0x0 LASTRESULT @Buffer attack EVs to [buffer1]
	compare LASTRESULT 150
	if 0x4 _goto EventScript_chuck_MaxedHappiness
	msgbox gText_chuck_13 0x6
	release
	end

ChuckGiveMega_MinGrindingMode:
	msgbox gText_chuck_10_minGrinding 0x6
	bufferfirstpokemon 0x00
	msgbox gText_chuck_11 0x6
	setvar 0x8003 0x0 @From party
	setvar 0x8004 0x0 @1st Pokemon
	callasm CheckIfChuckApproves
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_chuck_MaxedHappiness
	msgbox gText_chuck_13 0x6
	release
	end

EventScript_chuck_MaxedHappiness:
	msgbox gText_chuck_12 0x6
	giveitem ITEM_GALLADITE 0x1 MSG_OBTAIN
	msgbox gText_chuck_14 0x6
	giveitem ITEM_FOCUS_SASH 0x1 MSG_OBTAIN
	setflag 0x951
	release
	end

EventScript_chuck_Donedone:
	lock
	faceplayer
	msgbox gText_chuck_9 0x6
	release
	end

.global EventScript_taurospfire_Start
EventScript_taurospfire_Start:
	lock
	faceplayer
	checkflag 0x952
	if 0x1 _goto EventScript_clobbopus_Greedy
	showpokepic SPECIES_TAUROS_P_FIRE 0x0A 0x03
	cry SPECIES_TAUROS_P_FIRE 0x0
	waitcry
	msgbox gText_taurospfire_Uwant 0x5
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_taurospfire_Take
	hidepokepic
	release
	end

EventScript_clobbopus_Greedy:
	msgbox gText_clobbopus_Msggreedy 0x6
	release
	end

EventScript_taurospfire_Take:
	hidepokepic
	givepokemon SPECIES_TAUROS_P_FIRE 0x23 0x0 0x0 0x0 0x0
	fanfare 0x13E
	msgbox gText_taurospfire_Received 0x4
	waitfanfare
	closeonkeypress
	hidesprite 0x7
	setflag 0x952
	setflag 0x954
	release
	end

.global EventScript_taurospwater_Start
EventScript_taurospwater_Start:
	lock
	faceplayer
	checkflag 0x952
	if 0x1 _goto EventScript_crabrawler_Greedy
	showpokepic SPECIES_TAUROS_P_WATER 0x0A 0x03
	cry SPECIES_TAUROS_P_WATER 0x0
	waitcry
	msgbox gText_taurospwater_Uwant 0x5
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_taurospwater_Take
	hidepokepic
	release
	end

EventScript_crabrawler_Greedy:
	msgbox gText_crabrawler_Msggreedy 0x6
	release
	end

EventScript_taurospwater_Take:
	hidepokepic
	givepokemon SPECIES_TAUROS_P_WATER 0x23 0x0 0x0 0x0 0x0
	fanfare 0x13E
	msgbox gText_taurospwater_Received 0x4
	waitfanfare
	closeonkeypress
	hidesprite 0x6
	setflag 0x952
	setflag 0x953
	release
	end

.global EventScript_sabrina_Start
EventScript_sabrina_Start:
	lock
	faceplayer
	checkflag 0x825
	if 0x1 _goto EventScript_sabrina_Defeated
	msgbox gText_sabrina_EncounterText MSG_YESNO
	compare LASTRESULT NO 
	if equal _goto CancelSabrina
	msgbox gText_sabrina_LetsBegin MSG_NORMAL 
	setflag 0x915
	@ setflag 0x913 @set shiny 
	special 0x0 
	callasm CheckViableMons + 1
	compare LASTRESULT YES
	if equal _call SetPlaceholderPartner
	checkflag FLAG_HARDCORE_MODE
	if 0x1 _call SetTerrainTR
	trainerbattle3 0x3 0x1A4 0x0 gText_sabrina_DefeatText 
	goto EventScript_sabrina_WonPointer
	release
	end

SetTerrainTR:
	setvar VAR_BATTLE_AURAS PERMA_TRICK_ROOM_STRING 
	return

SetPlaceholderPartner:
	setflag 0x908
	setvar 0x5011 0x1 
	setvar 0x5012 0x8
	return 

CancelSabrina:
	msgbox gText_sabrina_Whenever MSG_NORMAL 
	release 
	end 

.global EventScript_sabrina_Defeated
EventScript_sabrina_Defeated:
	lock
	faceplayer
	checkflag 0x958
	if 0x1 _goto EventScript_sabrina_Done
	checkflag FLAG_HARDCORE_MODE
	if 0x1 _goto HardModeCheckShiny 
	checkflag FLAG_MINIMAL_GRINDING_MODE
	if 0x1 _goto MinModeCheckShiny
	msgbox gText_sabrina_Perfectpokemon 0x6
	bufferfirstpokemon 0x00
	msgbox gText_sabrina_Thepokemon 0x6
	setvar 0x8003 0x0 @From party
	setvar 0x8004 0x0 @1st 
	setvar 0x8005 0x0 @hp iv
	call EventScript_sabrina_Checkiv
	setvar 0x8005 0x1 @atk iv
	call EventScript_sabrina_Checkiv
	setvar 0x8005 0x2 @def iv
	call EventScript_sabrina_Checkiv
	setvar 0x8005 0x3 @speed iv
	call EventScript_sabrina_Checkiv
	setvar 0x8005 0x4 @special attack iv
	call EventScript_sabrina_Checkiv
	setvar 0x8005 0x5 @sp def iv
	call EventScript_sabrina_Checkiv
	msgbox gText_sabrina_Perfect 0x6
	giveitem ITEM_GARDEVOIRITE 0x1 MSG_OBTAIN
	msgbox gText_sabrina_Charmmsg 0x6
	giveitem ITEM_SHINY_CHARM 0x1 MSG_OBTAIN
	setflag 0x958
	release
	end

HardModeCheckShiny:
	msgbox gText_sabrina_Shinypokemon 0x6
	bufferfirstpokemon 0x00
	msgbox gText_sabrina_Thepokemon 0x6
	setvar 0x8003 0x0 @From party
	setvar 0x8004 0x0 @1st 
	setvar 0x8005 0x0 @hp iv
	callasm CheckIfShiny + 1
	compare LASTRESULT 0x1
	if 0x1 _goto ThisIsShinyHard
	goto EventScript_sabrina_Nah
	end

MinModeCheckShiny:
	msgbox gText_sabrina_Shinypokemon 0x6
	bufferfirstpokemon 0x00
	msgbox gText_sabrina_Thepokemon 0x6
	setvar 0x8003 0x0 @From party
	setvar 0x8004 0x0 @1st 
	setvar 0x8005 0x0 @hp iv
	callasm CheckIfShiny + 1
	compare LASTRESULT 0x1
	if 0x1 _goto ThisIsShiny
	goto EventScript_sabrina_Nah
	end

ThisIsShiny:
	msgbox gText_sabrina_Shiny MSG_NORMAL
	giveitem ITEM_GARDEVOIRITE 0x1 MSG_OBTAIN
	msgbox gText_sabrina_Charmmsg 0x6
	giveitem ITEM_SHINY_CHARM 0x1 MSG_OBTAIN
	setflag 0x958
	release
	end

ThisIsShinyHard:
	msgbox gText_sabrina_Shiny MSG_NORMAL
	giveitem ITEM_CAMERUPTITE 0x1 MSG_OBTAIN
	msgbox gText_sabrina_Charmmsg 0x6
	giveitem ITEM_SHINY_CHARM 0x1 MSG_OBTAIN
	setflag 0x958
	release
	end

EventScript_sabrina_WonPointer:
	msgbox gText_sabrina_TMInfomsg 0x6
	checkflag FLAG_HARDCORE_MODE
	if 0x1 _goto EventScript_sabrina_HardModeWonPointer
	giveitem ITEM_TM116 0x1 MSG_OBTAIN
	settrainerflag 0x118
	settrainerflag 0x119
	settrainerflag 0x11A
	settrainerflag 0x11B
	settrainerflag 0x1CE
	settrainerflag 0x1CF
	settrainerflag 0x1D0
	setflag 0x825
	msgbox gText_sabrina_Givetm 0x6
	msgbox gText_sabrina_Helloagain 0x6
	msgbox gText_sabrina_Perfectpokemon 0x6
	release
	end

EventScript_sabrina_HardModeWonPointer:
	giveitem ITEM_TM104 0x1 MSG_OBTAIN
	settrainerflag 0x118
	settrainerflag 0x119
	settrainerflag 0x11A
	settrainerflag 0x11B
	settrainerflag 0x1CE
	settrainerflag 0x1CF
	settrainerflag 0x1D0
	setflag 0x825
	msgbox gText_sabrina_GivetmHard 0x6
	msgbox gText_sabrina_HelloagainHard 0x6
	msgbox gText_sabrina_Shinypokemon 0x6
	release
	end

EventScript_sabrina_Done:
	msgbox gText_sabrina_Donemsg 0x6
	release
	end

EventScript_sabrina_Nah:
	msgbox gText_sabrina_Notquite 0x6
	release
	end

EventScript_sabrina_Checkiv:
	special2 LASTRESULT 0x8
	buffernumber 0x0 LASTRESULT @Buffer iv val to [buffer1]
	compare LASTRESULT 0x1F
	if 0x0 _goto EventScript_sabrina_Nah
	return

.global EventScript_sabrina_SetTile
EventScript_sabrina_SetTile:
	special 0x113
	applymovement 0x7F PanCameraDown 
	waitmovement 0x0 
	sound 0x8
	setmaptile 0xA 0x14 0x293 0x0
	special 0x8E
	checksound 
	applymovement 0x7F PanCameraUp 
	waitmovement 0x0 
	special 0x114
	setvar 0x5102 0x1 
	release
	end 

PanCameraDown:
	.byte walk_down 
	.byte walk_down 
	.byte walk_down 
	.byte walk_down 
	.byte walk_left
	.byte walk_left
	.byte walk_left
	.byte walk_left
	.byte end_m 
	
PanCameraUp:
	.byte walk_right
	.byte walk_right
	.byte walk_right
	.byte walk_right
	.byte walk_up
	.byte walk_up
	.byte walk_up
	.byte walk_up
	.byte end_m

.global EventScript_megaring_Start
EventScript_megaring_Start:
	lockall
	textcolor 0x1
	clearflag 0x200
	showsprite 0x10
	msgbox gText_megaring_1 0x6
	call PutFollowPkmnInBallBattle
	sound 0xB3
	applymovement 0xFF EventScript_megaring_Question
	waitmovement 0x0
	checksound
	applymovement 0x10 EventScript_megaring_Come
	waitmovement 0x0
	applymovement 0xFF EventScript_megaring_Lookdown
	waitmovement 0x0
	msgbox gText_megaring_2 0x6
	giveitem ITEM_MEGA_RING 0x1 MSG_OBTAIN
	msgbox gText_megaring_3 0x6
	applymovement 0x10 EventScript_megaring_Comedown
	waitmovement 0x0
	hidesprite 0x10
	setflag 0x200
	setvar 0x5042 0x1
	call MakeFollowerVisible
	release
	end

EventScript_megaring_Question:
.byte 0x63
.byte 0xFE


EventScript_megaring_Come:
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x11
.byte 0xFE

EventScript_megaring_Comedown:
.byte 0x10
.byte 0x12
.byte 0x12
.byte 0x12
.byte 0x12
.byte 0x12
.byte 0x12
.byte 0x12
.byte 0x12
.byte 0xFE


EventScript_megaring_Lookdown:
.byte 0x0
.byte 0xFE

.global EventScript_stopchuck_Start
EventScript_stopchuck_Start:
	lockall
	textcolor 0x0
	msgbox gText_stopchuck_1 0x6
	setflag 0x926
	applymovement 0xFF EventScript_stopchuck_Movedown
	waitmovement 0x0
	clearflag 0x926
	releaseall
	end


EventScript_stopchuck_Movedown:
.byte 0x10
.byte 0xFE

.global gMapScripts_SaffronGym
gMapScripts_SaffronGym:
    mapscript MAP_SCRIPT_ON_LOAD SetmaptileScript_SaffronGym
    .byte MAP_SCRIPT_TERMIN

.global SetmaptileScript_SaffronGym
SetmaptileScript_SaffronGym:
	compare 0x5102 0x1 
	if greaterorequal _call SetTiles 
	end 

SetTiles:
	setmaptile 0xA 0x14 0x293 0x0
	return 

.global Saffron_HiddenPowerChanger
Saffron_HiddenPowerChanger:
	lock
	faceplayer
	msgbox gText_Saffron_HPChanger_1 MSG_YESNO
	compare LASTRESULT NO
	if equal _goto NahImGood
	goto Saffron_HPChanger_SelectPkmn

Saffron_HPChanger_SelectPkmn:
	setvar 0x8003 0x0 
    special 0x9F 
    waitstate 
    compare 0x8004 0x6
    if greaterorequal _goto NahImGood
	setvar 0x8005 0x0 @hp iv
	call EventScript_HP_Checkiv
	setvar 0x8005 0x1 @atk iv
	call EventScript_HP_Checkiv
	setvar 0x8005 0x2 @def iv
	call EventScript_HP_Checkiv
	setvar 0x8005 0x3 @speed iv
	call EventScript_HP_Checkiv
	setvar 0x8005 0x4 @special attack iv
	call EventScript_HP_Checkiv
	setvar 0x8005 0x5 @sp def iv
	call EventScript_HP_Checkiv
	copyvar 0x510D 0x8004
	setvar 0x8000 0xA
	setvar 0x8001 0x6
	setvar 0x8004 0x0 
	preparemsg gText_Saffron_HpChanger_Which
    waitmsg
	special 0x158
	waitstate 
	copyvar 0x8004 0x510D  
	compare LASTRESULT 0x0 
	if 0x1 _goto SetFighting
	compare LASTRESULT 0x1
	if 0x1 _goto SetUpFlying
	compare LASTRESULT 0x2
	if 0x1 _goto SetUpPoison
	compare LASTRESULT 0x3
	if 0x1 _goto SetUpGround
	compare LASTRESULT 0x4
	if 0x1 _goto SetUpRock
	compare LASTRESULT 0x5
	if 0x1 _goto SetUpBug
	compare LASTRESULT 0x6
	if 0x1 _goto SetUpGhost
	compare LASTRESULT 0x7
	if 0x1 _goto SetUpSteel
	compare LASTRESULT 0x8
	if 0x1 _goto SetUpFire
	compare LASTRESULT 0x9
	if 0x1 _goto SetUpWater
	compare LASTRESULT 0xA
	if 0x1 _goto SetUpGrass
	compare LASTRESULT 0xB
	if 0x1 _goto SetUpElectric
	compare LASTRESULT 0xC
	if 0x1 _goto SetUpPsychic
	compare LASTRESULT 0xD
	if 0x1 _goto SetUpIce
	compare LASTRESULT 0xE
	if 0x1 _goto SetUpDragon
	compare LASTRESULT 0xF
	if 0x1 _goto SetUpDark
	goto Saffron_HPChanger_SelectPkmn
	release
	end 

EventScript_HP_Checkiv:
	special2 LASTRESULT 0x8
	buffernumber 0x0 LASTRESULT @Buffer iv val to [buffer1]
	compare LASTRESULT 0x1E
	if lessthan _goto EventScript_HPChanger_Nah
	return

EventScript_HPChanger_Nah:
	msgbox gText_SaffronHPChanger_No MSG_NORMAL
	release
	end

SetFighting:
	setvar 0x5106 0x1F
	buffernumber 0x0 0x5106
	setvar 0x5106 0x1E
	buffernumber 0x1 0x5106
	buffernumber 0x2 0x5106
	buffernumber 0x5 0x5106
	buffernumber 0x6 0x5106
	buffernumber 0x7 0x5106
	msgbox gText_SettingIVs MSG_KEEPOPEN
	pause 0x3
	closeonkeypress
	msgbox gText_SettingIVs_2 MSG_YESNO
	compare LASTRESULT NO
	if equal _goto NahImGood
	setvar 0x8005 0x0 @HP 
	setvar 0x8006 0x1F @31
	special 0x10
	setvar 0x8005 0x1 @Atk 
	setvar 0x8006 0x1E @It might be redundant setting 8006 each time but idk how it works so i@ll do it anyway lol
	special 0x10
	setvar 0x8005 0x2 @Def
	setvar 0x8006 0x1E
	special 0x10
	setvar 0x8005 0x3 @Speed 
	setvar 0x8006 0x1E
	special 0x10
	setvar 0x8005 0x4 @SpAtk 
	setvar 0x8006 0x1E
	special 0x10
	setvar 0x8005 0x5 @SpDef 
	setvar 0x8006 0x1E
	special 0x10
	goto EndOfHPScript

SetUpFire:
	setvar 0x5106 0x1F @HP 
	buffernumber 0x0 0x5106
	setvar 0x5106 0x1E @Atk 
	buffernumber 0x1 0x5106
	setvar 0x5106 0x1F @Def 
	buffernumber 0x2 0x5106
	setvar 0x5106 0x1E @SpA 
	buffernumber 0x5 0x5106
	setvar 0x5106 0x1F @SpD 
	buffernumber 0x6 0x5106
	setvar 0x5106 0x1E @Speed 
	buffernumber 0x7 0x5106
	msgbox gText_SettingIVs MSG_KEEPOPEN
	pause 0x3
	closeonkeypress
	msgbox gText_SettingIVs_2 MSG_YESNO
	compare LASTRESULT NO
	if equal _goto NahImGood
	setvar 0x8005 0x0 @HP 
	setvar 0x8006 0x1F @31
	special 0x10
	setvar 0x8005 0x1 @Atk 
	setvar 0x8006 0x1E @It might be redundant setting 8006 each time but idk how it works so i@ll do it anyway lol
	special 0x10
	setvar 0x8005 0x2 @Def
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x3 @Speed 
	setvar 0x8006 0x1E
	special 0x10
	setvar 0x8005 0x4 @SpAtk 
	setvar 0x8006 0x1E
	special 0x10
	setvar 0x8005 0x5 @SpDef 
	setvar 0x8006 0x1F
	special 0x10
	goto EndOfHPScript

SetUpIce:
	setvar 0x5106 0x1F @HP 
	buffernumber 0x0 0x5106
	setvar 0x5106 0x1E @Atk 
	buffernumber 0x1 0x5106
	setvar 0x5106 0x1E @Def 
	buffernumber 0x2 0x5106
	setvar 0x5106 0x1F @SpA 
	buffernumber 0x5 0x5106
	setvar 0x5106 0x1F @SpD 
	buffernumber 0x6 0x5106
	setvar 0x5106 0x1F @Speed 
	buffernumber 0x7 0x5106
	msgbox gText_SettingIVs MSG_KEEPOPEN
	pause 0x3
	closeonkeypress
	msgbox gText_SettingIVs_2 MSG_YESNO
	compare LASTRESULT NO
	if equal _goto NahImGood
	setvar 0x8005 0x0 @HP 
	setvar 0x8006 0x1F @31
	special 0x10
	setvar 0x8005 0x1 @Atk 
	setvar 0x8006 0x1E @It might be redundant setting 8006 each time but idk how it works so i@ll do it anyway lol
	special 0x10
	setvar 0x8005 0x2 @Def
	setvar 0x8006 0x1E
	special 0x10
	setvar 0x8005 0x3 @Speed 
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x4 @SpAtk 
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x5 @SpDef 
	setvar 0x8006 0x1F
	special 0x10
	goto EndOfHPScript

SetUpGrass:
	setvar 0x5106 0x1F @HP 
	buffernumber 0x0 0x5106
	setvar 0x5106 0x1E @Atk 
	buffernumber 0x1 0x5106
	setvar 0x5106 0x1F @Def 
	buffernumber 0x2 0x5106
	setvar 0x5106 0x1E @SpA 
	buffernumber 0x5 0x5106
	setvar 0x5106 0x1F @SpD 
	buffernumber 0x6 0x5106
	setvar 0x5106 0x1F @Speed 
	buffernumber 0x7 0x5106
	msgbox gText_SettingIVs MSG_KEEPOPEN
	pause 0x3
	closeonkeypress
	msgbox gText_SettingIVs_2 MSG_YESNO
	compare LASTRESULT NO
	if equal _goto NahImGood
	setvar 0x8005 0x0 @HP 
	setvar 0x8006 0x1F @31
	special 0x10
	setvar 0x8005 0x1 @Atk 
	setvar 0x8006 0x1E
	special 0x10
	setvar 0x8005 0x2 @Def
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x3 @Speed 
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x4 @SpAtk 
	setvar 0x8006 0x1E
	special 0x10
	setvar 0x8005 0x5 @SpDef 
	setvar 0x8006 0x1F
	special 0x10
	goto EndOfHPScript

SetUpGround:
	setvar 0x5106 0x1F @HP 
	buffernumber 0x0 0x5106
	setvar 0x5106 0x1F @Atk 
	buffernumber 0x1 0x5106
	setvar 0x5106 0x1F @Def 
	buffernumber 0x2 0x5106
	setvar 0x5106 0x1E @SpA 
	buffernumber 0x5 0x5106
	setvar 0x5106 0x1E @SpD 
	buffernumber 0x6 0x5106
	setvar 0x5106 0x1F @Speed 
	buffernumber 0x7 0x5106
	msgbox gText_SettingIVs MSG_KEEPOPEN
	pause 0x3
	closeonkeypress
	msgbox gText_SettingIVs_2 MSG_YESNO
	compare LASTRESULT NO
	if equal _goto NahImGood
	setvar 0x8005 0x0 @HP 
	setvar 0x8006 0x1F @31
	special 0x10
	setvar 0x8005 0x1 @Atk 
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x2 @Def
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x3 @Speed 
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x4 @SpAtk 
	setvar 0x8006 0x1E
	special 0x10
	setvar 0x8005 0x5 @SpDef 
	setvar 0x8006 0x1E
	special 0x10
	goto EndOfHPScript

SetUpRock:
	setvar 0x5106 0x1F @HP 
	buffernumber 0x0 0x5106
	setvar 0x5106 0x1F @Atk 
	buffernumber 0x1 0x5106
	setvar 0x5106 0x1E @Def 
	buffernumber 0x2 0x5106
	setvar 0x5106 0x1F @SpA 
	buffernumber 0x5 0x5106
	setvar 0x5106 0x1E @SpD 
	buffernumber 0x6 0x5106
	setvar 0x5106 0x1E @Speed 
	buffernumber 0x7 0x5106
	msgbox gText_SettingIVs MSG_KEEPOPEN
	pause 0x3
	closeonkeypress
	msgbox gText_SettingIVs_2 MSG_YESNO
	compare LASTRESULT NO
	if equal _goto NahImGood
	setvar 0x8005 0x0 @HP 
	setvar 0x8006 0x1F @31
	special 0x10
	setvar 0x8005 0x1 @Atk 
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x2 @Def
	setvar 0x8006 0x1E
	special 0x10
	setvar 0x8005 0x3 @Speed 
	setvar 0x8006 0x1E
	special 0x10
	setvar 0x8005 0x4 @SpAtk 
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x5 @SpDef 
	setvar 0x8006 0x1E
	special 0x10
	goto EndOfHPScript

SetUpFlying:
	setvar 0x5106 0x1F @HP 
	buffernumber 0x0 0x5106
	setvar 0x5106 0x1F @Atk 
	buffernumber 0x1 0x5106
	setvar 0x5106 0x1F @Def 
	buffernumber 0x2 0x5106
	setvar 0x5106 0x1E @SpA 
	buffernumber 0x5 0x5106
	setvar 0x5106 0x1E @SpD 
	buffernumber 0x6 0x5106
	setvar 0x5106 0x1E @Speed 
	buffernumber 0x7 0x5106
	msgbox gText_SettingIVs MSG_KEEPOPEN
	pause 0x3
	closeonkeypress
	msgbox gText_SettingIVs_2 MSG_YESNO
	compare LASTRESULT NO
	if equal _goto NahImGood
	setvar 0x8005 0x0 @HP 
	setvar 0x8006 0x1F @31
	special 0x10
	setvar 0x8005 0x1 @Atk 
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x2 @Def
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x3 @Speed 
	setvar 0x8006 0x1E
	special 0x10
	setvar 0x8005 0x4 @SpAtk 
	setvar 0x8006 0x1E
	special 0x10
	setvar 0x8005 0x5 @SpDef 
	setvar 0x8006 0x1E
	special 0x10
	goto EndOfHPScript

SetUpBug:
	setvar 0x5106 0x1F @HP 
	buffernumber 0x0 0x5106
	setvar 0x5106 0x1F @Atk 
	buffernumber 0x1 0x5106
	setvar 0x5106 0x1F @Def 
	buffernumber 0x2 0x5106
	setvar 0x5106 0x1F @SpA 
	buffernumber 0x5 0x5106
	setvar 0x5106 0x1E @SpD 
	buffernumber 0x6 0x5106
	setvar 0x5106 0x1E @Speed 
	buffernumber 0x7 0x5106
	msgbox gText_SettingIVs MSG_KEEPOPEN
	pause 0x3
	closeonkeypress
	msgbox gText_SettingIVs_2 MSG_YESNO
	compare LASTRESULT NO
	if equal _goto NahImGood
	setvar 0x8005 0x0 @HP 
	setvar 0x8006 0x1F @31
	special 0x10
	setvar 0x8005 0x1 @Atk 
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x2 @Def
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x3 @Speed 
	setvar 0x8006 0x1E
	special 0x10
	setvar 0x8005 0x4 @SpAtk 
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x5 @SpDef 
	setvar 0x8006 0x1E
	special 0x10
	goto EndOfHPScript

SetUpPsychic:
	setvar 0x5106 0x1F @HP 
	buffernumber 0x0 0x5106
	setvar 0x5106 0x1E @Atk 
	buffernumber 0x1 0x5106
	setvar 0x5106 0x1F @Def 
	buffernumber 0x2 0x5106
	setvar 0x5106 0x1F @SpA 
	buffernumber 0x5 0x5106
	setvar 0x5106 0x1F @SpD 
	buffernumber 0x6 0x5106
	setvar 0x5106 0x1E @Speed 
	buffernumber 0x7 0x5106
	msgbox gText_SettingIVs MSG_KEEPOPEN
	pause 0x3
	closeonkeypress
	msgbox gText_SettingIVs_2 MSG_YESNO
	compare LASTRESULT NO
	if equal _goto NahImGood
	setvar 0x8005 0x0 @HP 
	setvar 0x8006 0x1E @31
	special 0x10
	setvar 0x8005 0x1 @Atk 
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x2 @Def
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x3 @Speed 
	setvar 0x8006 0x1E
	special 0x10
	setvar 0x8005 0x4 @SpAtk 
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x5 @SpDef 
	setvar 0x8006 0x1F
	special 0x10
	goto EndOfHPScript

SetUpGhost:
	setvar 0x5106 0x1F @HP 
	buffernumber 0x0 0x5106
	setvar 0x5106 0x1F @Atk 
	buffernumber 0x1 0x5106
	setvar 0x5106 0x1E @Def 
	buffernumber 0x2 0x5106
	setvar 0x5106 0x1F @SpA 
	buffernumber 0x5 0x5106
	setvar 0x5106 0x1E @SpD 
	buffernumber 0x6 0x5106
	setvar 0x5106 0x1F @Speed 
	buffernumber 0x7 0x5106
	msgbox gText_SettingIVs MSG_KEEPOPEN
	pause 0x3
	closeonkeypress
	msgbox gText_SettingIVs_2 MSG_YESNO
	compare LASTRESULT NO
	if equal _goto NahImGood
	setvar 0x8005 0x0 @HP 
	setvar 0x8006 0x1F @31
	special 0x10
	setvar 0x8005 0x1 @Atk 
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x2 @Def
	setvar 0x8006 0x1E
	special 0x10
	setvar 0x8005 0x3 @Speed 
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x4 @SpAtk 
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x5 @SpDef 
	setvar 0x8006 0x1E
	special 0x10
	goto EndOfHPScript

SetUpPoison:
	setvar 0x5106 0x1F @HP 
	buffernumber 0x0 0x5106
	setvar 0x5106 0x1F @Atk 
	buffernumber 0x1 0x5106
	setvar 0x5106 0x1E @Def 
	buffernumber 0x2 0x5106
	setvar 0x5106 0x1E @SpA 
	buffernumber 0x5 0x5106
	setvar 0x5106 0x1E @SpD 
	buffernumber 0x6 0x5106
	setvar 0x5106 0x1F @Speed 
	buffernumber 0x7 0x5106
	msgbox gText_SettingIVs MSG_KEEPOPEN
	pause 0x3
	closeonkeypress
	msgbox gText_SettingIVs_2 MSG_YESNO
	compare LASTRESULT NO
	if equal _goto NahImGood
	setvar 0x8005 0x0 @HP 
	setvar 0x8006 0x1F @31
	special 0x10
	setvar 0x8005 0x1 @Atk 
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x2 @Def
	setvar 0x8006 0x1E
	special 0x10
	setvar 0x8005 0x3 @Speed 
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x4 @SpAtk 
	setvar 0x8006 0x1E
	special 0x10
	setvar 0x8005 0x5 @SpDef 
	setvar 0x8006 0x1E
	special 0x10
	goto EndOfHPScript

SetUpElectric:
	setvar 0x5106 0x1F @HP 
	buffernumber 0x0 0x5106
	setvar 0x5106 0x1F @Atk 
	buffernumber 0x1 0x5106
	setvar 0x5106 0x1F @Def 
	buffernumber 0x2 0x5106
	setvar 0x5106 0x1E @SpA 
	buffernumber 0x5 0x5106
	setvar 0x5106 0x1F @SpD 
	buffernumber 0x6 0x5106
	setvar 0x5106 0x1F @Speed 
	buffernumber 0x7 0x5106
	msgbox gText_SettingIVs MSG_KEEPOPEN
	pause 0x3
	closeonkeypress
	msgbox gText_SettingIVs_2 MSG_YESNO
	compare LASTRESULT NO
	if equal _goto NahImGood
	setvar 0x8005 0x0 @HP 
	setvar 0x8006 0x1F @31
	special 0x10
	setvar 0x8005 0x1 @Atk 
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x2 @Def
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x3 @Speed 
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x4 @SpAtk 
	setvar 0x8006 0x1E
	special 0x10
	setvar 0x8005 0x5 @SpDef 
	setvar 0x8006 0x1F
	special 0x10
	goto EndOfHPScript

SetUpDark:
	setvar 0x5106 0x1F @HP 
	buffernumber 0x0 0x5106
	setvar 0x5106 0x1F @Atk 
	buffernumber 0x1 0x5106
	setvar 0x5106 0x1F @Def 
	buffernumber 0x2 0x5106
	setvar 0x5106 0x1F @SpA 
	buffernumber 0x5 0x5106
	setvar 0x5106 0x1F @SpD 
	buffernumber 0x6 0x5106
	setvar 0x5106 0x1F @Speed 
	buffernumber 0x7 0x5106
	msgbox gText_SettingIVs MSG_KEEPOPEN
	pause 0x3
	closeonkeypress
	msgbox gText_SettingIVs_2 MSG_YESNO
	compare LASTRESULT NO
	if equal _goto NahImGood
	setvar 0x8005 0x0 @HP 
	setvar 0x8006 0x1F @31
	special 0x10
	setvar 0x8005 0x1 @Atk 
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x2 @Def
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x3 @Speed 
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x4 @SpAtk 
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x5 @SpDef 
	setvar 0x8006 0x1F
	special 0x10
	goto EndOfHPScript

SetUpDragon:
	setvar 0x5106 0x1F @HP 
	buffernumber 0x0 0x5106
	setvar 0x5106 0x1E @Atk 
	buffernumber 0x1 0x5106
	setvar 0x5106 0x1F @Def 
	buffernumber 0x2 0x5106
	setvar 0x5106 0x1F @SpA 
	buffernumber 0x5 0x5106
	setvar 0x5106 0x1F @SpD 
	buffernumber 0x6 0x5106
	setvar 0x5106 0x1F @Speed 
	buffernumber 0x7 0x5106
	msgbox gText_SettingIVs MSG_KEEPOPEN
	pause 0x3
	closeonkeypress
	msgbox gText_SettingIVs_2 MSG_YESNO
	compare LASTRESULT NO
	if equal _goto NahImGood
	setvar 0x8005 0x0 @HP 
	setvar 0x8006 0x1F @31
	special 0x10
	setvar 0x8005 0x1 @Atk 
	setvar 0x8006 0x1E
	special 0x10
	setvar 0x8005 0x2 @Def
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x3 @Speed 
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x4 @SpAtk 
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x5 @SpDef 
	setvar 0x8006 0x1F
	special 0x10
	goto EndOfHPScript

SetUpWater:
	setvar 0x5106 0x1F @HP 
	buffernumber 0x0 0x5106
	setvar 0x5106 0x1E @Atk 
	buffernumber 0x1 0x5106
	setvar 0x5106 0x1E @Def 
	buffernumber 0x2 0x5106
	setvar 0x5106 0x1E @SpA 
	buffernumber 0x5 0x5106
	setvar 0x5106 0x1F @SpD 
	buffernumber 0x6 0x5106
	setvar 0x5106 0x1F @Speed 
	buffernumber 0x7 0x5106
	msgbox gText_SettingIVs MSG_KEEPOPEN
	pause 0x3
	closeonkeypress
	msgbox gText_SettingIVs_2 MSG_YESNO
	compare LASTRESULT NO
	if equal _goto NahImGood
	setvar 0x8005 0x0 @HP 
	setvar 0x8006 0x1F @31
	special 0x10
	setvar 0x8005 0x1 @Atk 
	setvar 0x8006 0x1E
	special 0x10
	setvar 0x8005 0x2 @Def
	setvar 0x8006 0x1E
	special 0x10
	setvar 0x8005 0x3 @Speed 
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x4 @SpAtk 
	setvar 0x8006 0x1E
	special 0x10
	setvar 0x8005 0x5 @SpDef 
	setvar 0x8006 0x1F
	special 0x10
	goto EndOfHPScript

SetUpSteel:
	setvar 0x5106 0x1F @HP 
	buffernumber 0x0 0x5106
	setvar 0x5106 0x1F @Atk 
	buffernumber 0x1 0x5106
	setvar 0x5106 0x1F @Def 
	buffernumber 0x2 0x5106
	setvar 0x5106 0x1F @SpA 
	buffernumber 0x5 0x5106
	setvar 0x5106 0x1E @SpD 
	buffernumber 0x6 0x5106
	setvar 0x5106 0x1F @Speed 
	buffernumber 0x7 0x5106
	msgbox gText_SettingIVs MSG_KEEPOPEN
	pause 0x3
	closeonkeypress
	msgbox gText_SettingIVs_2 MSG_YESNO
	compare LASTRESULT NO
	if equal _goto NahImGood
	setvar 0x8005 0x0 @HP 
	setvar 0x8006 0x1F @31
	special 0x10
	setvar 0x8005 0x1 @Atk 
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x2 @Def
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x3 @Speed 
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x4 @SpAtk 
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x5 @SpDef 
	setvar 0x8006 0x1E
	special 0x10
	goto EndOfHPScript

EndOfHPScript:
	msgbox gText_HPChanger_Done MSG_NORMAL
	release
	end

.global EventScript_Saffron_CakeMaker
EventScript_Saffron_CakeMaker:
	lock
	checkflag 0x102D
	if 0x1 _goto AlcremieEnd
	msgbox gText_SaffronCake1 MSG_NORMAL
	applymovement 0x800F FaceYou
	waitmovement 0x0
	msgbox gText_SaffronCake2 MSG_YESNO
	compare LASTRESULT YES
	if equal _goto TryCake
	goto CakeIllImprovise
	end

FaceYou:
	.byte face_player
	.byte end_m

FaceUp:
	.byte look_up
	.byte end_m

TryCake:
	checkitem ITEM_MOOMOO_MILK 0x2
    compare 0x800D 0x1
    if lessthan _goto YouDontHaveCake
	checkitem ITEM_RAWST_BERRY 0x1
	compare 0x800D 0x1
	if lessthan _goto YouDontHaveCake
	checkitem ITEM_ASPEAR_BERRY 0x1
	compare 0x800D 0x1
	if lessthan _goto YouDontHaveCake
	msgbox gText_SaffronCake3 MSG_NORMAL
	removeitem ITEM_MOOMOO_MILK 0x2
	removeitem ITEM_RAWST_BERRY 0x1
	removeitem ITEM_ASPEAR_BERRY 0x1
	giveitem ITEM_ALCREMITE 0x1 MSG_OBTAIN
	setflag 0x102D
	msgbox gText_SaffronCake4 MSG_NORMAL
	msgbox gText_SaffronCake5 MSG_NORMAL
	giveitem ITEM_METRONOME 0x1 MSG_OBTAIN
	release
	end

AlcremieEnd:
	msgbox gText_SaffronCake4 MSG_FACE
	release
	end

YouDontHaveCake:
	msgbox gText_SaffronCakeDontHave MSG_NORMAL
	goto CakeIllImprovise
	end

CakeIllImprovise:
	msgbox gText_SaffronCakeImprovise MSG_NORMAL
	applymovement 0x800F FaceUp
	waitmovement 0x0
	release
	end

.global EventScript_SaffronCorv
EventScript_SaffronCorv:
	lock
	faceplayer
	cry SPECIES_CORVIKNIGHT 0x0
	msgbox gText_Saffron_Corvknight MSG_KEEPOPEN
	closeonkeypress
	pause 0x3
	waitcry
	release
	end

.global EventScript_SaffronStaraptor
EventScript_SaffronStaraptor:
	lock
	faceplayer
	cry SPECIES_STARAPTOR 0x0
	msgbox gText_SaffronStaraptor MSG_KEEPOPEN
	pause 0x3
	waitcry
	closeonkeypress
	release
	end

.global EventScript_SaffronStaraptorTrainer
EventScript_SaffronStaraptorTrainer:
	msgbox gText_SaffronStaraptorTrainer MSG_FACE
	release
	end

.global EventScript_Saffron_Mudkip
EventScript_Saffron_Mudkip:
	cry SPECIES_MUDKIP 0x0
	msgbox gText_SaffronMudkip MSG_FACE
	waitcry
	release
	end

.global EventScript_Saffron_Marshtomp
EventScript_Saffron_Marshtomp:
	cry SPECIES_MARSHTOMP 0x0
	msgbox gText_SaffronMarshtomp MSG_FACE
	waitcry
	release
	end

.global EventScript_Saffron_Swampert
EventScript_Saffron_Swampert:
	cry SPECIES_SWAMPERT_MEGA 0x0
	msgbox gText_SaffronSwampert MSG_FACE
	waitcry
	release
	end

.global EventScript_Saffron_Mimikyu
EventScript_Saffron_Mimikyu:
	cry SPECIES_MIMIKYU 0x0
	msgbox gText_SaffronMimikyu MSG_FACE
	waitcry
	release
	end

.global EventScript_Saffron_Rillaboom
EventScript_Saffron_Rillaboom:
	cry SPECIES_RILLABOOM 0x0
	msgbox gText_SaffronRillaboom MSG_FACE
	waitcry
	release
	end

.equ FLAG_GAVE_HISUIAN_POTENT, 0x1081

.global EventScript_Machine_RotomChanger
EventScript_Machine_RotomChanger:
    checkflag FLAG_FOLLOWER_IN_PROGRESS
	if 0x0 _goto MysteriousMachine
	callasm IsFollowerRotom + 1
	compare LASTRESULT 0x2
	if notequal _goto MysteriousMachine
    msgbox gText_Celadon_RotomChanger MSG_KEEPOPEN
	pause 0x8
	closeonkeypress
	setvar 0x8003 0x0 @From party
	special 0x9F @choose from party
	waitstate
	compare 0x8004 0x6
	if 0x4 _goto NahImGood
	callasm CheckIfRotom
	compare LASTRESULT 0x0
	if equal _goto NotRotom
	setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_RotomNorm
	special 0x25
	setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_RotomWash
	special 0x25
    setvar 0x8006 0x2 @third item
    loadpointer 0x0 gText_RotomMow
    special 0x25
    setvar 0x8006 0x3
    loadpointer 0x0 gText_RotomFrost
    special 0x25
    setvar 0x8006 0x4
    loadpointer 0x0 gText_RotomHeat
    special 0x25
	setvar 0x8006 0x5
    loadpointer 0x0 gText_RotomFan
    special 0x25
    preparemsg gText_WhichRotomForm
    waitmsg
	multichoice 0x0 0x0 0x24 0x0
	compare LASTRESULT 0x0
	if equal _goto RotomNorm
	compare LASTRESULT 0x1
	if equal _goto RotomWash
	compare LASTRESULT 0x2
	if equal _goto RotomMow
	compare LASTRESULT 0x3
	if equal _goto RotomFrost
	compare LASTRESULT 0x4
	if equal _goto RotomHeat
	compare LASTRESULT 0x5
	if equal _goto RotomFan
	goto NahImGood

MysteriousMachine:
	msgbox gText_MysteriousMachine_Text MSG_NORMAL
	release
	end

RotomNorm:
	setvar VAR_TEMPORARY_VALUE_2 SPECIES_ROTOM
	call DoRotomFormChange
	goto EndOfRotomScript

RotomWash:
	setvar VAR_TEMPORARY_VALUE_2 SPECIES_ROTOM_WASH
	call DoRotomFormChange
	goto EndOfRotomScript

RotomMow:
	setvar VAR_TEMPORARY_VALUE_2 SPECIES_ROTOM_MOW
	call DoRotomFormChange
	goto EndOfRotomScript

RotomFrost:
	setvar VAR_TEMPORARY_VALUE_2 SPECIES_ROTOM_FROST
	call DoRotomFormChange
	goto EndOfRotomScript

RotomHeat:
	setvar VAR_TEMPORARY_VALUE_2 SPECIES_ROTOM_HEAT
	call DoRotomFormChange
	goto EndOfRotomScript

RotomFan:
	setvar VAR_TEMPORARY_VALUE_2 SPECIES_ROTOM_FAN
	call DoRotomFormChange
	goto EndOfRotomScript

DoRotomFormChange:
	callasm TryRotomFormChange
	compare LASTRESULT 0x1
	if equal _goto NotRotom
	compare LASTRESULT 0x2
	if equal _goto SameForm
	return

EndOfRotomScript: 
	sound 0x58
	msgbox gText_Giving_DotDotDot MSG_KEEPOPEN @[.]
	pause 0x4
	checksound
	cry SPECIES_ROTOM 0x0
	waitcry
	closeonkeypress
	checkflag FLAG_FOLLOWER_IN_PROGRESS
	if 0x1 _call UpdatePokemonFollowerThingRotom
	msgbox gText_Celadon_RotomChange_Down MSG_NORMAL
	release
	end

UpdatePokemonFollowerThingRotom: 
	copyvar VAR_TEMPORARY_VALUE 0x5130
	callasm UpdateFollowerPokemonGraphic + 1
	callasm CompareFollowerVars + 1
	compare LASTRESULT 0x1
	if equal _call SoundBall
	return

NotRotom:
	sound 0x16
	msgbox gText_Celadon_NotRotom MSG_KEEPOPEN
	checksound
	pause 0x4
	closeonkeypress
	release
	end

SameForm:
	msgbox gText_Celadon_SameForm MSG_NORMAL
	release
	end


