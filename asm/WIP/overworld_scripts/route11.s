.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s" 

.equ FLAG_ACTIVATE_POKEVIAL, 0x1047

.global EventScript_whitney_Start
EventScript_whitney_Start:
	lockall
	msgbox gText_whitney_1 0x6
	applymovement 0xF EventScript_whitney_Look
	waitmovement 0x0
	lockall
	msgbox gText_whitney_2 0x6
	lockall
	msgbox gText_whitney_3 0x5
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_whitney_Battle
	msgbox gText_whitney_4 0x6
	releaseall
	end

EekDontWannaFight:
	msgbox gText_whitney_DontWannaFight 0x6
	release
	end

EventScript_whitney_Battle:
	setflag 0x915
	setflag 0x90E
	msgbox gText_whitney_5 0x6
	special 0x0
	trainerbattle3 0x3 0x31 0x0 gText_whitney_Defeat
	msgbox gText_whitney_6 0x6
	clearflag 0x915
	giveitem ITEM_NORMAL_GEM 0x1 MSG_OBTAIN
	msgbox gText_whitney_7 MSG_NORMAL
	msgbox gText_whitney_7_2 MSG_NORMAL
	giveitem ITEM_EVIOLITE 0x1 MSG_OBTAIN
	msgbox gText_whitney_8 0x6
	fadescreen 0x1
	hidesprite 0xF
	sound 0x9
	checksound
	fadescreen 0x0
	setflag 0x933
	releaseall
	end


EventScript_whitney_Look:
.byte 0x4A
.byte 0xFE

.global EventScript_itemfinder_Start 
EventScript_itemfinder_Start:
	lockall
	faceplayer
	textcolor 0x0
	checkflag 0x938
	if 0x1 _goto EventScript_itemfinder_Done
	msgbox gText_itemfinder_3 0x6
	giveitem 0x105 0x1 MSG_OBTAIN
	msgbox gText_itemfinder_4 MSG_FACE 
	setflag 0x938
	release
	end

EventScript_itemfinder_Done:
	msgbox gText_itemfinder_4 MSG_FACE
	release
	end

.global EventScript_Guard_EVTraining
EventScript_Guard_EVTraining:
	lock
	faceplayer
	msgbox gText_Guard_Evtraining MSG_FACE
	release
	end
	
.global EventScript_Route11_FireStone
EventScript_Route11_FireStone:
  	hidesprite 0x800F
    giveitem ITEM_FIRE_STONE 0x1 MSG_FIND
    setflag 0x1039
    release
    end
	