.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s" 

.equ FLAG_EXPERT_MODE, 0x93A
.equ FLAG_RANDOMIZER_MODE, 0x940
.equ FLAG_WONDER_TRADE_FIRST, 0x103E

.global EventScript_WonderTrade
EventScript_WonderTrade: 
    lock
    faceplayer
    checkflag 0x99E 
    if 0x1 _goto AlreadyDone 
    showmoney 0x0 0x0 0x0
    msgbox gText_RandomEgg MSG_YESNO 
    compare LASTRESULT NO 
    if equal _goto CancelEgg 
    checkmoney 0x1388 0x0
    compare LASTRESULT 0x1
    if 0x0 _goto NotEnoughMoney
    special2 LASTRESULT 0x83
    compare LASTRESULT 0x6
    if notequal _goto ReceiveEgg  @if we have a slot open 
    msgbox gText_RandomEggNoRoom MSG_FACE
    hidemoney 0x00 0x00 
    release 
    end 

ReceiveEgg:
    msgbox gText_WouldYouLikePaldean MSG_NORMAL
    setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_Wonder
	special 0x25
	setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_Paldean
	special 0x25
    preparemsg gText_WhichOne
    waitmsg
    multichoice 0x0 0x0 0x20 0x0
    compare LASTRESULT 0x0
    if 0x1 _goto WonderEgg1
    compare LASTRESULT 0x1
    if 0x1 _goto PaldeanEgg1
    goto CancelEgg
    end

WonderEgg1:
    msgbox gText_RandomEgg2 MSG_NORMAL
    fanfare 0x101
    msgbox gText_RandomEgg_ReceivedEgg MSG_KEEPOPEN
    waitfanfare
    waitkeypress
    checkflag FLAG_RANDOMIZER_MODE
    if 0x1 _goto ReceiveEggEnd
    checkflag FLAG_EXPERT_MODE
    if 0x1 _goto ReceiveEggEnd
    setflag FLAG_WONDER_TRADE_FIRST
    goto ReceiveEggEnd

PaldeanEgg1:
    msgbox gText_RandomEgg2 MSG_FACE
    fanfare 0x101
    waitfanfare
    msgbox gText_RandomEgg_ReceivedEgg MSG_FACE
    checkflag FLAG_RANDOMIZER_MODE
    if 0x1 _goto ReceiveEggEnd
    checkflag FLAG_EXPERT_MODE
    if 0x1 _goto ReceiveEggEnd
    setflag 0x104A
    goto ReceivePaldeanEggEnd1

ReceivePaldeanEggEnd1:
    giveegg SPECIES_MUDKIP
    clearflag 0x104A
    clearflag FLAG_WONDER_TRADE_FIRST
    setflag  0x99E
    msgbox gText_RandomEgg3 MSG_FACE
    sound 0x58 
    removemoney 0x1388 0x00
    updatemoney 0x35 0x00 0x00
    checksound
    msgbox gText_punchtutor_Wait MSG_FACE
    hidemoney 0x35 0x00 
    msgbox gText_RandomEgg6 MSG_FACE
    release
    end

ReceiveEggEnd: 
    giveegg SPECIES_MUDKIP
    clearflag FLAG_WONDER_TRADE_FIRST
    setflag 0x99E
    msgbox gText_RandomEgg3 MSG_NORMAL 
    sound 0x58 
    removemoney 0x1388 0x00
    updatemoney 0x00 0x00 0x00
    checksound
    msgbox gText_punchtutor_Wait MSG_NORMAL
    hidemoney 0x00 0x00 
    msgbox gText_RandomEgg5 MSG_NORMAL
    release
    end


AlreadyDone: 
    msgbox gText_RandomEgg4 MSG_FACE 
    release 
    end 

CancelEgg:
    hidemoney 0x00 0x00 
    release 
    end 

NotEnoughMoney: 
    msgbox gText_RandomEggNotEnough MSG_FACE
    hidemoney 0x00 0x00 
    release 
    end 

.global EventScript_WonderTrade2
EventScript_WonderTrade2: 
    lock
    faceplayer
    checkflag 0x97E 
    if 0x1 _goto AlreadyDone2
    showmoney 0x35 0x0 0x0
    msgbox gText_RandomEgg MSG_YESNO 
    compare LASTRESULT NO
    if equal _goto CancelEgg
    checkmoney 0x1388 0x0
    compare LASTRESULT 0x1
    if 0x0 _goto NotEnoughMoney
    special2 LASTRESULT 0x83
    compare LASTRESULT 0x6
    if notequal _goto ReceiveEgg2  @if we have a slot open 
    msgbox gText_RandomEggNoRoom MSG_FACE
    hidemoney 0x35 0x00 
    release 
    end 

ReceiveEgg2:
    msgbox gText_WouldYouLikePaldean MSG_NORMAL
    setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_Wonder
	special 0x25
	setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_Paldean
	special 0x25
    preparemsg gText_WhichOne
    waitmsg
    multichoice 0x0 0x0 0x20 0x0
    compare LASTRESULT 0x0
    if 0x1 _goto WonderEgg2
    compare LASTRESULT 0x1
    if 0x1 _goto PaldeanEgg2
    goto CancelEgg
    end

PaldeanEgg2:
    msgbox gText_RandomEgg2 MSG_FACE
    fanfare 0x101
    waitfanfare
    msgbox gText_RandomEgg_ReceivedEgg MSG_FACE
    checkflag FLAG_RANDOMIZER_MODE
    if 0x1 _goto ReceiveEggEnd2
    checkflag FLAG_EXPERT_MODE
    if 0x1 _goto ReceiveEggEnd2
    setflag 0x104A
    goto ReceivePaldeanEggEnd2


WonderEgg2:
    msgbox gText_RandomEgg2 MSG_FACE
    fanfare 0x101
    waitfanfare
    msgbox gText_RandomEgg_ReceivedEgg MSG_FACE
    checkflag FLAG_RANDOMIZER_MODE
    if 0x1 _goto ReceiveEggEnd2
    checkflag FLAG_EXPERT_MODE
    if 0x1 _goto ReceiveEggEnd2
    setflag 0x94F
    goto ReceiveEggEnd2

ReceiveEggEnd2:
    giveegg SPECIES_FLOETTE
    clearflag 0x94F
    setflag 0x97E
    msgbox gText_RandomEgg3 MSG_FACE
    sound 0x58 
    removemoney 0x1388 0x00
    updatemoney 0x35 0x00 0x00
    checksound
    msgbox gText_punchtutor_Wait MSG_FACE
    hidemoney 0x35 0x00 
    msgbox gText_RandomEgg5 MSG_FACE
    release
    end

ReceivePaldeanEggEnd2:
    giveegg SPECIES_FLOETTE
    clearflag 0x104A
    setflag 0x97E
    msgbox gText_RandomEgg3 MSG_FACE
    sound 0x58 
    removemoney 0x1388 0x00
    updatemoney 0x35 0x00 0x00
    checksound
    msgbox gText_punchtutor_Wait MSG_FACE
    hidemoney 0x35 0x00 
    msgbox gText_RandomEgg6 MSG_FACE
    release
    end

AlreadyDone2:
    msgbox gText_RandomEgg2_4 MSG_FACE 
    release 
    end 

.global EventScript_WonderTrade3
EventScript_WonderTrade3: 
    lock
    faceplayer
    checkflag 0x97F
    if 0x1 _goto AlreadyDone2
    showmoney 0x35 0x0 0x0
    msgbox gText_RandomEgg MSG_YESNO 
    compare LASTRESULT NO 
    if equal _goto CancelEgg 
    checkmoney 0x1388 0x0
    compare LASTRESULT 0x1
    if 0x0 _goto NotEnoughMoney
    special2 LASTRESULT 0x83
    compare LASTRESULT 0x6
    if notequal _goto ReceiveEgg3  @if we have a slot open 
    msgbox gText_RandomEggNoRoom MSG_FACE
    hidemoney 0x35 0x00 
    release 
    end 

ReceiveEgg3:
    msgbox gText_WouldYouLikePaldean MSG_NORMAL
    setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_Wonder
	special 0x25
	setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_Paldean
	special 0x25
    preparemsg gText_WhichOne
    waitmsg
    multichoice 0x0 0x0 0x20 0x0
    compare LASTRESULT 0x0
    if 0x1 _goto WonderEgg3
    compare LASTRESULT 0x1
    if 0x1 _goto PaldeanEgg3
    goto CancelEgg
    end

PaldeanEgg3:
    fanfare 0x101
    waitfanfare
    msgbox gText_RandomEgg_ReceivedEgg MSG_FACE
    checkflag FLAG_RANDOMIZER_MODE
    if 0x1 _goto ReceiveEggEnd3
    checkflag FLAG_EXPERT_MODE
    if 0x1 _goto ReceiveEggEnd3
    setflag 0x104A
    goto PaldeanEggEnd3

WonderEgg3:   
    fanfare 0x101
    waitfanfare
    msgbox gText_RandomEgg_ReceivedEgg MSG_FACE
    checkflag FLAG_RANDOMIZER_MODE
    if 0x1 _goto ReceiveEggEnd3
    checkflag FLAG_EXPERT_MODE
    if 0x1 _goto ReceiveEggEnd3
    setflag 0x94F
    goto ReceiveEggEnd3
    

ReceiveEggEnd3:
    giveegg SPECIES_GASTLY
    clearflag 0x94F
    setflag 0x97F
    msgbox gText_RandomEgg3 MSG_FACE 
    sound 0x58 
    removemoney 0x1388 0x00
    updatemoney 0x35 0x00 0x00
    checksound
    msgbox gText_punchtutor_Wait MSG_FACE
    hidemoney 0x35 0x00 
    msgbox gText_RandomEgg5 MSG_FACE
    release
    end

PaldeanEggEnd3:
    giveegg SPECIES_GASTLY
    clearflag 0x104A
    setflag 0x97F
    msgbox gText_RandomEgg3 MSG_FACE 
    sound 0x58 
    removemoney 0x1388 0x00
    updatemoney 0x35 0x00 0x00
    checksound
    msgbox gText_punchtutor_Wait MSG_FACE
    hidemoney 0x35 0x00 
    msgbox gText_RandomEgg6 MSG_FACE
    release
    end
    