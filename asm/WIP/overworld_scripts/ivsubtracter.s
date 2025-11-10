.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.global EventScript_IVSubtracter_Start
EventScript_IVSubtracter_Start:
	lock
	faceplayer
	textcolor 0x0
	msgbox gText_IVSubtracter_Msg 0x5
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_IVSubtracter_MinusEVs
	goto EventScript_IVSubtracter_Cancel
	end

EventScript_IVSubtracter_MinusEVs:
	setvar 0x8003 0x0 @From party
	special 0x9F @choose from party
	waitstate
	compare 0x8004 0x6
	if 0x4 _goto EventScript_IVSubtracter_Cancel
	special 0x7C @puts the selected mon in party into buffer
	goto EventScript_IVSubtracter_CheckEVs

EventScript_IVSubtracter_CheckEVs:
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
	preparemsg gText_IVSubtracter_1
	waitmsg
	multichoice 0x0 0x0 0x24 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_IVSubtracter_ReduceHP
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_IVSubtracter_ReduceAttack
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_IVSubtracter_ReduceDef
	compare LASTRESULT 0x3
	if 0x1 _goto EventScript_IVSubtracter_ReduceSpA
	compare LASTRESULT 0x4
	if 0x1 _goto EventScript_IVSubtracter_ReduceSpD
	compare LASTRESULT 0x5
	if 0x1 _goto EventScript_IVSubtracter_ReduceSpeed
	goto EventScript_IVSubtracter_MinusEVs @means they pressed B, goto previous screen
	end

EventScript_IVSubtracter_Cancel:
	msgbox gText_EVSubtracter_2 0x6
	release
	end


EventScript_IVSubtracter_ReduceHP:
	setvar 0x8005 0x0
	msgbox gText_IVSubtracter_HP 0x5
	goto EventScript_IVSubtracter_EndofScript 

EventScript_IVSubtracter_ReduceAttack:
	setvar 0x8005 0x1
	msgbox gText_IVSubtracter_Attack 0x5
	goto EventScript_IVSubtracter_EndofScript 

EventScript_IVSubtracter_ReduceDef:
	setvar 0x8005 0x2
	msgbox gText_IVSubtracter_Defense 0x5
	goto EventScript_IVSubtracter_EndofScript 

EventScript_IVSubtracter_ReduceSpA:
	setvar 0x8005 0x4
	msgbox gText_IVSubtracter_SpA 0x5
	goto EventScript_IVSubtracter_EndofScript 

EventScript_IVSubtracter_ReduceSpD:
	setvar 0x8005 0x5
	msgbox gText_IVSubtracter_SpDef 0x5
	goto EventScript_IVSubtracter_EndofScript 

EventScript_IVSubtracter_ReduceSpeed:
	setvar 0x8005 0x3
	msgbox gText_IVSubtracter_Speed 0x5
	goto EventScript_IVSubtracter_EndofScript 

EventScript_IVSubtracter_EndofScript:
    compare LASTRESULT NO
    if equal _goto EventScript_IVSubtracter_Cancel
    setvar 0x8006 0x0 
    special 0x10 
    msgbox gText_IVSetterDone MSG_NORMAL 
    release 
    end 

.global EventScript_PokeBallSwitcher
EventScript_PokeBallSwitcher:
	lock 
	faceplayer 
	msgbox gText_SetBalls1 MSG_YESNO 
	compare LASTRESULT NO 
	if equal _goto EventScript_PokeBallSwitcher_Cancel
	setvar 0x8003 0x0 @From party
	special 0x9F @choose from party
	waitstate
	compare 0x8004 0x6
	if 0x4 _goto EventScript_PokeBallSwitcher_Cancel
	goto PokeBallList11 
	end 

PokeBallList11: 
    setvar 0x8000 0x9
    setvar 0x8001 0x6
	copyvar 0x5106 0x8004
    setvar 0x8004 0x0 
    preparemsg gText_PokeBall_Which
	waitmsg
    special 0x158
    waitstate 
	copyvar 0x8004 0x5106
	compare LASTRESULT 0x0
	if 0x1 _goto MasterBall
	compare LASTRESULT 0x1
	if 0x1 _goto UltraBall
	compare LASTRESULT 0x2
	if 0x1 _goto GreatBall
	compare LASTRESULT 0x3
	if 0x1 _goto PokeBall
	compare LASTRESULT 0x4
	if 0x1 _goto SafariBall
	compare LASTRESULT 0x5
	if 0x1 _goto NetBall
	compare LASTRESULT 0x6
	if 0x1 _goto DiveBall
	compare LASTRESULT 0x7
	if 0x1 _goto NestBall
	compare LASTRESULT 0x8
	if 0x1 _goto RepeatBall
	compare LASTRESULT 0x9
	if 0x1 _goto TimerBall
	compare LASTRESULT 0xA
	if 0x1 _goto LuxuryBall
	compare LASTRESULT 0xB
	if 0x1 _goto PremierBall
	compare LASTRESULT 0xC
	if 0x1 _goto DuskBall
	compare LASTRESULT 0xD
	if 0x1 _goto HealBall
	compare LASTRESULT 0xE
	if 0x1 _goto QuickBall
	compare LASTRESULT 0xF
	if 0x1 _goto CherishBall
	compare LASTRESULT 0x10
	if 0x1 _goto ParkBall
	compare LASTRESULT 0x11
	if 0x1 _goto FastBall
	compare LASTRESULT 0x12
	if 0x1 _goto LevelBall
	compare LASTRESULT 0x13
	if 0x1 _goto LureBall
	compare LASTRESULT 0x14
	if 0x1 _goto HeavyBall
	compare LASTRESULT 0x15
	if 0x1 _goto LoveBall
	compare LASTRESULT 0x16
	if 0x1 _goto FriendBall
	compare LASTRESULT 0x17
	if 0x1 _goto MoonBall
	compare LASTRESULT 0x18
	if 0x1 _goto BeastBall
	compare LASTRESULT 0x19
	if 0x1 _goto DreamBall
	compare LASTRESULT 0x1A
	if 0x1 _goto HisuianBall
	goto EventScript_PokeBallSwitcher_Cancel @means they pressed B, goto previous screen
	end 

MasterBall:
	setvar 0x8005 0x0
	goto EndOfPokeBall 

UltraBall:
	setvar 0x8005 0x1
	goto EndOfPokeBall 

GreatBall:
	setvar 0x8005 0x2
	goto EndOfPokeBall

PokeBall:
	setvar 0x8005 0x3
	goto EndOfPokeBall

SafariBall:
	setvar 0x8005 0x4
	goto EndOfPokeBall

NetBall:
	setvar 0x8005 0x5
	goto EndOfPokeBall

DiveBall:
	setvar 0x8005 0x6
	goto EndOfPokeBall

NestBall:
	setvar 0x8005 0x7
	goto EndOfPokeBall

RepeatBall:
	setvar 0x8005 0x8
	goto EndOfPokeBall

TimerBall:
	setvar 0x8005 0x9
	goto EndOfPokeBall

LuxuryBall:
	setvar 0x8005 0xA
	goto EndOfPokeBall

PremierBall:
	setvar 0x8005 0xB
	goto EndOfPokeBall

DuskBall:
	setvar 0x8005 0xC
	goto EndOfPokeBall

HealBall:
	setvar 0x8005 0xD
	goto EndOfPokeBall

QuickBall:
	setvar 0x8005 0xE
	goto EndOfPokeBall

CherishBall:
	setvar 0x8005 0xF
	goto EndOfPokeBall

ParkBall:
	setvar 0x8005 0x10
	goto EndOfPokeBall

FastBall:
	setvar 0x8005 0x11
	goto EndOfPokeBall

LevelBall:
	setvar 0x8005 0x12
	goto EndOfPokeBall

LureBall:
	setvar 0x8005 0x13
	goto EndOfPokeBall

HeavyBall:
	setvar 0x8005 0x14
	goto EndOfPokeBall

LoveBall:
	setvar 0x8005 0x15
	goto EndOfPokeBall

FriendBall:
	setvar 0x8005 0x16
	goto EndOfPokeBall

MoonBall:
	setvar 0x8005 0x17
	goto EndOfPokeBall

BeastBall:
	setvar 0x8005 0x19
	goto EndOfPokeBall

DreamBall:
	setvar 0x8005 0x1A
	goto EndOfPokeBall

HisuianBall:
	setvar 0x8005 0x18
	goto EndOfPokeBall
	
EndOfPokeBall:
	special 0x14 
	msgbox gText_POkeBall_Done MSG_NORMAL 
	release 
	end 

EventScript_PokeBallSwitcher_Cancel:
	release 
	end 
