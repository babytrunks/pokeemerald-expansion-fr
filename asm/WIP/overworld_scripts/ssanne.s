.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.global EventScript_secondbrendanmiddle_Start
EventScript_secondbrendanmiddle_Start:
	setvar 0x4016 0x1
	goto EventScript_secondbrendantop_Script
	end


.global EventScript_secondbrendanright_Start
EventScript_secondbrendanright_Start:
	setvar 0x4016 0x2
	goto EventScript_secondbrendantop_Script
	end

.global EventScript_secondbrendanleft_Start
EventScript_secondbrendanleft_Start:
	setvar 0x4016 0x0
	goto EventScript_secondbrendantop_Script
	end

EventScript_secondbrendantop_Script:
	applymovement 0xFF EventScript_secondbrendantop_Stop
	waitmovement 0x0
	call PutFollowPkmnInBallBattle
	clearflag 0x200
	applymovement PLAYER LookUp
	waitmovement 0x0
	showsprite 0x1
	sound 0x9
    checksound
	pause 0xA
    sound 0x15
	applymovement 0x1 EventScript_secondbrendantop_Lookaround
	waitmovement 0x0
    checksound 
	compare 0x4016 0x0
	if 0x1 _goto EventScript_secondbrendantop_Left
	compare 0x4016 0x1
	if 0x1 _goto EventScript_secondbrendantop_Middle
	compare 0x4016 0x2
	if 0x1 _goto EventScript_secondbrendantop_Right
	end

LookUp:
	.byte look_up
	.byte end_m

EventScript_secondbrendantop_Left:
	applymovement 0x1 EventScript_secondbrendantop_Comeupleft
	waitmovement 0x0
	call EventScript_secondbrendantop_Battle
	goto EventScript_secondbrendantop_Leftleave
	end

EventScript_secondbrendantop_Middle:
	applymovement 0x1 EventScript_secondbrendantop_Comeupmiddle
	waitmovement 0x0
	call EventScript_secondbrendantop_Battle
	goto EventScript_secondbrendantop_Middleleave
	end

EventScript_secondbrendantop_Right:
	applymovement 0x1 EventScript_secondbrendantop_Comeupright
	waitmovement 0x0
	call EventScript_secondbrendantop_Battle
	goto EventScript_secondbrendantop_Rightleave
	end

EventScript_secondbrendantop_Battle:
	msgbox gText_secondbrendantop_2 0x6
	setflag 0x200
	special 0x0
	setflag 0x90E
	trainerbattle3 0x3 0x32 0x0 gText_secondbrendantop_Defeat
	msgbox gText_secondbrendantop_4 0x6
	giveitem 0xC5 0x2 MSG_OBTAIN
    giveitem ITEM_SHINY_STONE 0x1 MSG_OBTAIN
	msgbox gText_secondbrendantop_6 0x6
	return

EventScript_secondbrendantop_Leftleave:
	applymovement 0x1 EventScript_secondbrendantop_Comedowntop
	waitmovement 0x0
    goto EndBrendanScript

EndBrendanScript:
	setvar 0x4015 0x1
	hidesprite 0x01
	call MakeFollowerVisible
	release
	end

EventScript_secondbrendantop_Middleleave:
	applymovement 0x1 EventScript_secondbrendantop_Comedowntop
	waitmovement 0x0
	goto EndBrendanScript
    end

EventScript_secondbrendantop_Rightleave:
	applymovement 0x1 EventScript_secondbrendantop_Comedownbottom
	waitmovement 0x0
	goto EndBrendanScript
    end

EventScript_secondbrendantop_Stop:
    .byte look_up
    .byte end_m

EventScript_secondbrendantop_Lookaround:
    .byte look_down
    .byte exclaim
    .byte end_m

EventScript_secondbrendantop_Comeupleft:
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte end_m

EventScript_secondbrendantop_Comeupmiddle:
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte look_down
    .byte end_m

EventScript_secondbrendantop_Comeupright:
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte walk_right
    .byte look_down
    .byte 0xFE

EventScript_secondbrendantop_Comedowntop:
.byte walk_right
.byte walk_down
.byte walk_down
.byte walk_down
.byte walk_down
.byte walk_down
.byte walk_down
.byte walk_down
.byte walk_down
.byte end_m

EventScript_secondbrendantop_Comedownbottom:
.byte walk_left
.byte walk_down
.byte walk_down
.byte walk_down
.byte walk_down
.byte walk_down
.byte walk_down
.byte walk_down
.byte walk_down
.byte end_m

.global EventScript_SsAnne_Trainer1
EventScript_SsAnne_Trainer1:
	trainerbattle11 0xB 0x87 0x86 0x3 0x4 0x0 gText_ssanne_sailor1PreBattle gText_ssanne_sailor2PreBattle gText_ssanne_sailor1Lose gText_ssanne_sailor2Lose gText_ssanne_sailor1cantbattle gText_ssanne_sailor1cantbattle
	msgbox gText_ssanne_sailor1postbattle 0x6
	end


.global EventScript_SsAnne_Trainer2
EventScript_SsAnne_Trainer2: 
	trainerbattle11 0xB 0x86 0x87 0x4 0x3 0x0 gText_ssanne_sailor2PreBattle gText_ssanne_sailor1PreBattle gText_ssanne_sailor2Lose gText_ssanne_sailor1Lose gText_ssanne_sailor1cantbattle gText_ssanne_sailor1cantbattle
	msgbox gText_ssanne_sailor2postbattle 0x6
	end


.global EventScript_SsAnne_Trainer3
EventScript_SsAnne_Trainer3:
	trainerbattle11 0xB 0x7E 0x1E2 0x3 0x4 0x0 gText_ssanne_PreBattle gText_ssanne_trainer2_prebattle gText_ssanne_trainer1_lose gText_ssanne_trainer2_lose gText_ssanne_sailor1cantbattle gText_ssanne_sailor1cantbattle
	msgbox gText_ssanne_trainer1_postbattle 0x6
	end


.global EventScript_SsAnne_Trainer4
EventScript_SsAnne_Trainer4: 
	trainerbattle11 0xB 0x1E2 0x7E 0x4 0x3 0x0 gText_ssanne_trainer2_prebattle gText_ssanne_PreBattle gText_ssanne_sailor2Lose gText_ssanne_sailor1Lose gText_ssanne_sailor1cantbattle gText_ssanne_sailor1cantbattle
	msgbox gText_ssanne_trainer2_postbattle 0x6
	end
	