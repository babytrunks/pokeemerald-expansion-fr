.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s" 

.equ FLAG_HARDCORE_MODE, 0x1034
.equ FLAG_MINIMAL_GRINDING_MODE, 0x1032

.global EventScript_Route8_AceTrainer
EventScript_Route8_AceTrainer:
    lock
    faceplayer
    checkflag 0x102C 
    if 0x1 _goto AlreadyDone
    msgbox gText_Route8_AceTrainer1 MSG_FACE
    checkitem ITEM_MEGA_RING 0x1
	compare 0x800D 0x1
	if 0x4 _goto Route8_AceTrainerFight
    msgbox gText_Route8_AceTrainerReject MSG_FACE
    release
    end

Route8_AceTrainerFight: 
    faceplayer
    msgbox gText_Route8_AceTrainer2 MSG_YESNO
    compare LASTRESULT NO 
    if equal _goto LaterThen 
    msgbox gText_Route8_AceTrainerPreBattle MSG_FACE
    setflag 0x90E
    special 0x0
    trainerbattle3 0x3 0x12 0x0 gText_Route8_AceTrainerLoss
    msgbox gText_Route8_AceTrainer3 MSG_FACE
    faceplayer
    giveitem ITEM_ROCKY_HELMET 0x1 MSG_OBTAIN
    msgbox gText_Route8_AceTrainer4 MSG_FACE
    giveitem ITEM_CENTISKITE 0x1 MSG_OBTAIN
    msgbox gText_Route8_AceTrainer5 MSG_FACE
    setflag 0x102C
    release
    end

Notready:
    msgbox gText_Route8_AceTrainerReject MSG_FACE
    release
    end

LaterThen:
    msgbox gText_Route8_AceTrainerLater MSG_FACE
    release
    end

AlreadyDone:
    msgbox gText_Route8_AceTrainer5 MSG_FACE
    release
    end

EventScript_Stop:
	.byte lock_facing
	.byte 0xFE

.global EventScript_Route9_PostaliciaCare
EventScript_Route9_PostaliciaCare:
	lockall
	textcolor 0x0
	checkflag 0x103F
	if 0x1 _call GiveAliciaCarePackage
	setvar 0x5120 0x1
	release
	end

GiveAliciaCarePackage:
	applymovement 0xFF EventScript_Stop
	waitmovement 0x0
    msgbox gText_CarePackageFind MSG_NORMAL
	giveitem ITEM_BABIRI_BERRY 0xA MSG_OBTAIN
	giveitem ITEM_BLACK_SLUDGE 0xA MSG_OBTAIN
	giveitem ITEM_EVERSTONE 0xA MSG_OBTAIN
	giveitem ITEM_FLAME_ORB 0xA MSG_OBTAIN
	giveitem ITEM_KASIB_BERRY 0xA MSG_OBTAIN
	giveitem ITEM_SMOKE_BALL 0xA MSG_OBTAIN
	giveitem ITEM_THICK_CLUB 0xA MSG_OBTAIN
    checkflag FLAG_HARDCORE_MODE
	if 0x0 _call GiveWeakness
	return

GiveWeakness:
	giveitem ITEM_WEAKNESS_POLICY 0xA MSG_OBTAIN
	return