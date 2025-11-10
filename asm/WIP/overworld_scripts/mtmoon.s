.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.global EventScript_MtMoon_MuscleBand
EventScript_MtMoon_MuscleBand:
    lock
    faceplayer 
    checkflag 0x997
    if 0x1 _goto Done
    msgbox gText_MtMoon_MuscleBand1 MSG_FACE 
    msgbox gText_MtMoon_MuscleBand2 MSG_FACE
    giveitem ITEM_MUSCLE_BAND 0x1 MSG_OBTAIN 
    setflag 0x997
    release
    end

Done:
    msgbox gText_MtMoon_MuscleBand1 MSG_FACE 
    release 
    end 

.global EventScript_adminmtmoonright
EventScript_adminmtmoonright:
    applymovement 0xFF PlayerMoveLeft
    waitmovement 0x0 
    goto EventScript_adminmtmoonleft_Start

PlayerMoveLeft:
	.byte walk_left 
	.byte end_m  

.global EventScript_adminmtmoonleft_Start
EventScript_adminmtmoonleft_Start:
	clearflag 0x200
    setflag 0x926
	showsprite 0x0D
    showsprite 0xF
	textcolor 0x00
	applymovement 0xFF EventScript_adminmtmoonleft_Stop
	waitmovement 0x0
    call PutFollowPkmnInBallBattle
	msgbox gText_adminmtmoonleft_1 0x6
	sound 0xB3
	applymovement 0xFF EventScript_adminmtmoonleft_Question
	waitmovement 0x0
	checksound
	applymovement 0x0D EventScript_adminmtmoonleft_Comeup
    applymovement 0xF EventScript_adminmtmoonleft_Comeup
	waitmovement 0x0
	applymovement 0xFF EventScript_adminmtmoonleft_Look
	waitmovement 0x0
	msgbox gText_adminmtmoonleft_2 0x6
	setflag 0x200
	trainerbattle3 0x3 0x2E 0x0 gText_adminmtmoonleft_Defeat
    fadescreen 0x1
	hidesprite 0xF
	sound 0xF
	checksound
    fadescreen 0x0
	msgbox gText_adminmtmoonleft_4 0x6
	applymovement 0x0d EventScript_adminmtmoonleft_Comedown
	waitmovement 0x0
	setvar 0x4014 0x1
	hidesprite 0x0D
	sound 0x9
	checksound
	setflag 0x201
    call MakeFollowerVisible
	release
	end

EventScript_adminmtmoonleft_Comeup:
.byte 0x1F
.byte 0x1F
.byte 0x1F
.byte 0x1F
.byte 0x1F
.byte 0x1F
.byte 0x1F
.byte 0x1F
.byte 0x0
.byte 0xFE

EventScript_adminmtmoonleft_Comedown:
.byte 0x13
.byte 0x10
.byte 0x10
.byte 0x10
.byte 0x10
.byte 0x13
.byte 0xFE


EventScript_adminmtmoonleft_Question:
.byte 0x63
.byte 0xFE

EventScript_adminmtmoonleft_Look:
.byte 0x1
.byte 0xFE

EventScript_adminmtmoonleft_Stop:
.byte 0x0
.byte 0xFE

.global EventScript_cobalion_OW
EventScript_cobalion_OW:
	lock
    faceplayer
    cry SPECIES_COBALION 0x2
    preparemsg gText_cobalion_12
    waitmsg
    waitcry
    pause 0xA
    playsong 0x156 0x0
    waitkeypress
    wildbattle SPECIES_COBALION 0x41 0x00
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x4
    if 0x1 _goto Moveback2
    fadescreen 0x1
    hidesprite 0x800F
    setflag 0x1013
    fadescreen 0x0
    release
    end

Moveback2:
    release 
    end

.global EventScript_MagikarpGuy
EventScript_MagikarpGuy:
    lock    
    faceplayer
    checkflag 0x98E
    if 0x1 _goto Done1 
    showmoney 0x0 0x0 0x0
    msgbox gText_MagikarpGuy_1 MSG_YESNO
    compare LASTRESULT NO
    if equal _goto Reject
    checkmoney 0x1F4 0x0
    compare LASTRESULT 0x1
    if 0x0 _goto NotEnoughMoney
    sound 0x58 
    msgbox gText_MagikarpGuy_Bought1 MSG_FACE
    removemoney 0x1F4 0x00
    updatemoney 0x00 0x00 0x00
    checksound
    givepokemon 0x81 0x5 0x0 0x0 0x0 0x0
    msgbox gText_MagikarpGuy_AfterBought2 MSG_FACE
    setflag 0x98E
    hidemoney 0x0 0x0 
    release 
    end

Done1:
    checkflag 0x98F
    if 0x1 _goto Done2 
    showmoney 0x0 0x0 0x0
    msgbox gText_MagikarpGuy_2 MSG_YESNO
    compare LASTRESULT NO
    if equal _goto Reject
    checkmoney 0x124F8 0x0
    compare LASTRESULT 0x1
    if 0x0 _goto NotEnoughMoney
    sound 0x58 
    removemoney 0x124F8 0x00
    updatemoney 0x00 0x00 0x00
    setflag 0x913
    givepokemon 0x81 0x5 0x0 0x0 0x0 0x0
    clearflag 0x913
    msgbox gText_MagikarpGuy_Bought2 MSG_KEEPOPEN
    checksound
    closeonkeypress 
    msgbox gText_MagikarpGuy_AfterBought2 MSG_FACE
    hidemoney 0x0 0x0 
    setflag 0x98F
    release 
    end

Done2:
    checkflag 0x990
    if 0x1 _goto Done3
    msgbox gText_MagikarpGuy_3 MSG_FACE 
    msgbox gText_MagikarpGuy_4 MSG_FACE 
    setflag 0x990
    release 
    end 

Done3: 
    msgbox gText_MagikarpGuy_4 MSG_FACE 
    release 
    end

Reject: 
    hidemoney 0x0 0x0 
    msgbox gText_MagikarpGuy_Reject MSG_FACE 
    release 
    end

NotEnoughMoney: 
    msgbox gText_MagikarpGuy_MoreMoney MSG_FACE 
    hidemoney 0x0 0x0 
    release 
    end 

