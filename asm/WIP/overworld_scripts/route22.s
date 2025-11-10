.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s" 

.equ FLAG_HARDCORE_MODE, 0x1034
.equ AURA_SWAMP_STRING, 21
.equ AURA_SEAOFFIRE_STRING, 22
.equ AURA_RAINBOW_STRING,  23
.equ VAR_BATTLE_AURAS, 0x5119 
.equ VAR_WEATHER, 0x5118
.equ AURA_MAGMA_STORM_STRING, 26
	@---------------
.global EventScript_garypree4top_GaryPreE4Top
EventScript_garypree4top_GaryPreE4Top:
	lockall
	setvar 0x4001 0x0
	goto EventScript_garypree4top_GaryPreE4Start

.global EventScript_garypree4top_GaryPreE4Middle
EventScript_garypree4top_GaryPreE4Middle:
    lockall
    setvar 0x4001 0x1
    movesprite2 0x1 0x19 0x5
    goto EventScript_garypree4top_GaryPreE4Start

.global EventScript_garypree4top_GaryPreE4Bottom
EventScript_garypree4top_GaryPreE4Bottom:
    lockall
    setvar 0x4001 0x2
    movesprite2 0x1 0x19 0x5
    goto EventScript_garypree4top_GaryPreE4Start

	@---------------
EventScript_garypree4top_GaryPreE4Start:
	textcolor 0x0
	playsong 0x13B 0x0
	showsprite 0x1
	compare 0x4001 0x0
	if 0x1 _call EventScript_garypree4top_Turnalil
	compare 0x4001 0x1
	if 0x1 _call EventScript_garypree4top_Turnalil
	compare 0x4001 0x2
	if 0x1 _call EventScript_garypree4top_Turnalil2
	msgbox gText_garypree4top_GaryMsg1 MSG_KEEPOPEN @"[rival]: What? [player]!\nWhat a s..."
	setvar LASTTALKED 0x1
	compare 0x4031 0x2
	if 0x1 _call EventScript_garypree4top_Battle1
	compare 0x4031 0x1
	if 0x1 _call EventScript_garypree4top_Battle2
	compare 0x4031 0x0
	if 0x1 _call EventScript_garypree4top_Battle3
	msgbox gText_garypree4top_GaryLossMsg MSG_KEEPOPEN @"That loosened me up.\nI@m ready fo..."
	closeonkeypress
	pause 0xA
	playsong 0x13C 0x0
	applymovement 0x1 EventScript_garypree4top_GaryLeave
	waitmovement 0x0
	fadedefault
	hidesprite 0x1
	setvar 0x4054 0x4
	releaseall
	end

	@---------------
EventScript_garypree4top_Turnalil:
	applymovement 0x1 EventScript_garypree4top_Stepright2
	waitmovement 0x0
	return

	@---------------
EventScript_garypree4top_Turnalil2:
	applymovement 0x1 EventScript_garypree4top_StepRight
	applymovement 0xFF EventScript_garypree4top_FaceUp
	waitmovement 0x0
	return

	@---------------
EventScript_garypree4top_Battle1:
    @Sqirtle
    checkflag FLAG_HARDCORE_MODE
    if 0x1 _call SetAuraSquirtle
	trainerbattle3 0x3 0x1B3 0x0 gText_garypree4top_MsgJustCareless
	return

	@---------------
EventScript_garypree4top_Battle2:
    checkflag FLAG_HARDCORE_MODE
    if 0x1 _call SetAuraBulbasaur
	trainerbattle3 0x3 0x1B4 0x0 gText_garypree4top_MsgJustCareless
	return

	@---------------
EventScript_garypree4top_Battle3:
    checkflag FLAG_HARDCORE_MODE
    if 0x1 _call SetAuraCharmander
	trainerbattle3 0x3 0x1B5 0x0 gText_garypree4top_MsgJustCareless
	return

	@-----------
	@ Movements
	@-----------

SetAuraSquirtle:
    setvar VAR_WEATHER 0x2
    setvar VAR_BATTLE_AURAS AURA_RAINBOW_STRING
    return

SetAuraBulbasaur:
    setvar VAR_BATTLE_AURAS AURA_SWAMP_STRING
    return
SetAuraCharmander:
    setvar VAR_BATTLE_AURAS AURA_MAGMA_STORM_STRING
    return

EventScript_garypree4top_GaryLeave:
.byte 0x12
.byte 0x12
.byte 0x12
.byte 0x12
.byte 0x12
.byte 0x12
.byte 0x12
.byte 0xFE

EventScript_garypree4top_Stepright2:
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0xFE

EventScript_garypree4top_StepRight:
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x2D
.byte 0xFE

EventScript_garypree4top_FaceUp:
.byte 0x1C
.byte 0x1C
.byte 0x1C
.byte 0x1C
.byte 0x1C
.byte 0x1C
.byte 0x1C
.byte 0x1B
.byte 0x2E
.byte 0xFE
