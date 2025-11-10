.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s" 

.equ FLAG_MINIMAL_GRINDING_MODE, 0x1032
.equ FLAG_HARDCORE_MODE, 0x1034

.global EventScript_bugsy_Start
EventScript_bugsy_Start:
	lock
	textcolor 0x00
	msgbox gText_bugsy_1 0x4
	applymovement 0xE EventScript_bugsy_Look
	waitmovement 0x0
	msgbox gText_bugsy_2 0x6
	msgbox gText_bugsy_3 0x5
	compare LASTRESULT 0x1
	if 0x1 _call EventScript_bugsy_Battle
	msgbox gText_bugsy_4 0x6
	release
	end

EventScript_bugsy_Battle:
	setflag 0x915
	setflag 0x90E
	msgbox gText_bugsy_5 0x6
	special 0x0
	goto CheckBadges
	@ goto Normalbugsy

Normalbugsy:
	trainerbattle3 0x3 0x2F 0x0 gText_bugsy_Defeat
	goto PostBugsy

PostBugsy:
	msgbox gText_bugsy_6 0x6
	giveitem ITEM_TM89 0x1 MSG_OBTAIN
	msgbox gText_bugsy_7 0x6
	giveitem 0x08 0x5 MSG_OBTAIN
	msgbox gText_bugsy_8 0x6
	fadescreen 0x1
	hidesprite 0xE
	sound 0x9
	checksound
	fadescreen 0x0
	setflag 0x931
	release
	end

CheckBadges:
	checkflag 0x822 @Beat Surge?
	if 0x0 _goto Normalbugsy
	trainerbattle3 0x3 0x8 0x0 gText_bugsy_Defeat
	goto PostBugsy

EventScript_bugsy_Look:
.byte 0x4A
.byte 0xFE

.global EventScript_flamecharge_Start
EventScript_flamecharge_Start:
	hidesprite 0x9
	giveitem ITEM_TM77 0x1 MSG_FIND
	setflag 0x937
	release
	end

.global EventScript_nuggetbridge_StartLeft
EventScript_nuggetbridge_StartLeft:
	applymovement 0xFF MoveRight 
	waitmovement 0x0 
	goto EventScript_nuggetbridge_Start 
	end 


.global EventScript_nuggetbridge_StartRight
EventScript_nuggetbridge_StartRight:
	applymovement 0xFF EventScript_nuggetbridge_Movement1
	waitmovement 0x0
	goto EventScript_nuggetbridge_Start
	end 

EventScript_nuggetbridge_Start:
	textcolor 0x0
	call EventScript_nuggetbridge_Move1 
	msgbox gText_nuggetbridge_1 MSG_KEEPOPEN 
	call EventScript_nuggetbridge_Secondstart
	releaseall
	end


EventScript_nuggetbridge_Move1:
	applymovement 0x1 EventScript_nuggetbridge_Movement2
	waitmovement 0x0
	return

MoveRight:
	.byte walk_right 
	.byte end_m 

EventScript_nuggetbridge_Secondstart:
	preparemsg gText_nuggetbridge_2 
	waitmsg
	playsong 0x11B 0x0
	waitkeypress
	setvar LASTTALKED 0x1
	trainerbattle3 0x3 0x164 0x0 gText_nuggetbridge_3
	msgbox gText_nuggetbridge_4 MSG_NORMAL 
	giveitem ITEM_BIG_NUGGET 0x1 MSG_OBTAIN
	msgbox gText_nuggetbridge_5 MSG_NORMAL
	checkflag 0x103F
	if 0x1 _call PickUpItems
	checkflag FLAG_MINIMAL_GRINDING_MODE
	if 0x0 _call PickUpVitamins 
	checkflag FLAG_HARDCORE_MODE
	if 0x0 _call PickUpThroatSpray
	setvar 0x406B 0x1
	return

PickUpItems:
	msgbox gText_nuggetbridge_6 MSG_NORMAL
	giveitem ITEM_LEEK 0xA MSG_OBTAIN
	giveitem ITEM_SILK_SCARF 0xA MSG_OBTAIN
	giveitem ITEM_WACAN_BERRY 0xA MSG_OBTAIN
	return

PickUpThroatSpray:
	giveitem ITEM_THROAT_SPRAY 0xA MSG_OBTAIN
	return

PickUpVitamins:
	giveitem ITEM_HEALTH_WING 0xA MSG_OBTAIN
	giveitem ITEM_HP_UP 0xA MSG_OBTAIN 
	return

EndOfRocketBridgeScript:
	setvar 0x406B 0x1
	releaseall
	end

EventScript_nuggetbridge_Movement1:
.byte 0x30
.byte 0xFE

EventScript_nuggetbridge_Movement2:
.byte 0x4A @0x12
.byte 0xFE

EventScript_nuggetbridge_Movement3:
.byte 0x2F
.byte 0xFE

EventScript_nuggetbridge_Move4:
.byte 0x10
.byte 0xFE

EventScript_nuggetbridge_Move5:
.byte 0x13
.byte 0x2F
.byte 0xFE

EventScript_nuggetbridge_Trainer:
	compare 0x406B 0x1
	if 0x1 _goto YouBeGood 
	lockall
	goto EventScript_nuggetbridge_Start 
	end 

YouBeGood: 
	lock 
	faceplayer 
	msgbox gText_nuggetbridge_5 MSG_NORMAL
	release 
	end 

.global EventScript_Route24_LeafStone
EventScript_Route24_LeafStone:
    hidesprite 0x800F
    giveitem ITEM_LEAF_STONE 0x1 MSG_FIND
    setflag 0x1038
    release
    end
