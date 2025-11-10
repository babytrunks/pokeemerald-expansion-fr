.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.global MakeFollowerVisible
MakeFollowerVisible:
    clearflag 0x926
	special 0xE1
	compare LASTRESULT 0x1
    if equal _goto continuescr
    return

continuescr:
	callasm CheckIfPkmnOkToFollow + 1
	compare LASTRESULT YES
    if equal _goto UpdateFollowerMakeVisible
    return

UpdateFollowerMakeVisible:
    special 0xD3
    clearflag 0x1054
    fadescreen 0x1
    showsprite 0x14
    callasm UpdateFollowerPokemonGraphic
	sound 0xF
	checksound
	fadescreen 0x0
    callasm SetFollowerVisible2
    @ sound 0x1C
    @ callasm FollowerApplyMovementJumpInPlace
    @ checksound
    cry 0x5130 0x0
    waitcry
    return

.global MakeFollowerVisibleNoFade
MakeFollowerVisibleNoFade:
    clearflag 0x926
	special 0xE1
	compare LASTRESULT 0x1
    if equal _goto continuescr2
    return

continuescr2:
	callasm CheckIfPkmnOkToFollow + 1
	compare LASTRESULT YES
    if equal _goto UpdateFollowerMakeVisibleNoFade
    return

UpdateFollowerMakeVisibleNoFade:
    special 0xD3
    clearflag 0x1054
    showsprite 0x14
    @ callasm UpdateFollowerPokemonGraphic
	sound 0xF
	checksound
    callasm SetFollowerVisible2
    @ sound 0x1C
    @ callasm FollowerApplyMovementJumpInPlace
    @ checksound
    cry 0x5130 0x0
    waitcry
    return

.global PutFollowPkmnInBallBattle
PutFollowPkmnInBallBattle:
	special 0xE1
	compare LASTRESULT 0x1
    if equal _call PutPkmnAway
    return
.global SetFollowerToFollowScript
SetFollowerToFollowScript:
	special 0xE1
	compare LASTRESULT 0x1
    if equal _call SetFlag926
    return

SetFlag926:
    setflag 0x926
    return
PutPkmnAway:
    special 0xD3
    pause 0x5
    checksound
    pause 0x5
    fadescreen 0x1
	callasm SetFollowerInvisible + 1 
	sound 0xF
	checksound
    pause 0x2
	fadescreen 0x0
    setflag 0x926
    return
