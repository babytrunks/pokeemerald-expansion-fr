.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s" 

.global EventScript_FinalCreator_Fight
EventScript_FinalCreator_Fight:
    clearflag 0x200 
    applymovement 0xFF FaceUp
    waitmovement 0x0
    call SetFollowerToFollowScript
    opendoor 0xB 0x6
    waitdooranim
    showsprite 0x3
    applymovement 0xFF Down1
    waitmovement 0x0
    applymovement 0xFF GoDownBackUp
    waitmovement 0x0
    applymovement 0x3 Down1 
    waitmovement 0x0 
    closedoor 0xB 0x6
    waitdooranim
    textcolor 0x0
    msgbox gText_FinalCreatorBattle_1 MSG_FACE  
    setflag 0x200 
    trainerbattle3 0x3 0x18 0x0 gText_FinalCreatorBattle_Loss
    applymovement 0x3 JumpUp
    waitmovement 0x0
    msgbox gText_FinalCreatorBattle_2 MSG_FACE 
    giveitem ITEM_METAGROSSITE 0x1 MSG_OBTAIN
    msgbox gText_FinalCreatorBattle_3 MSG_FACE
    applymovement 0x3 CreatorLeave
    waitmovement 0x0 
    applymovement 0xFF FaceRight 
    waitmovement 0x0 
    applymovement 0x3 Down1 
    waitmovement 0x0 
    applymovement 0xFF FaceDown 
    waitmovement 0x0
    applymovement 0x3 CreatorLeave2 
    waitmovement 0x0
    hidesprite 0x3
    setvar 0x5058 0x1
    setflag 0x995
    release
    end 

FaceUp: 
    .byte 0x1
    .byte 0xFE 

GoDownBackUp:
    .byte walk_down
    .byte walk_up
    .byte look_up
    .byte end_m

FaceRight:
    .byte 0x7
    .byte 0xFE

FaceDown:
    .byte 0x0
    .byte 0xFE 

Down1:
    .byte 0x10
    .byte 0xFE 

CreatorLeave:
    .byte 0x13
    .byte 0x10
    .byte 0xFE 

CreatorLeave2:
    .byte 0x10
    .byte 0x10
    .byte 0x10
    .byte 0x10
    .byte 0x10
    .byte 0xFE

JumpUp:
    .byte 0x52
    .byte 0xFE

