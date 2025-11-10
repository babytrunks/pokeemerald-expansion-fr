.include "../xse_commands.s"
.include "../xse_defines.s"

.global EventScript_TrainerTipsPewter
EventScript_TrainerTipsPewter:
	msgbox gText_Pewter_TrainerTips1 MSG_SIGN
	release
	end

.global EventScript_TrainerTipsViridian1
EventScript_TrainerTipsViridian1:
	msgbox gText_Viridian_TrainerTips1 MSG_SIGN
	release
	end

.global EventScript_TrainerTipsViridian2
EventScript_TrainerTipsViridian2:
	msgbox gText_Viridian_TrainerTips2 MSG_SIGN
	release
	end

.global EventScript_TrainerTipsViridianForest1
EventScript_TrainerTipsViridianForest1:
	msgbox gText_ViridianForest_TrainerTips1 MSG_SIGN
	release
	end

.global EventScript_TrainerTipsViridianForest2
EventScript_TrainerTipsViridianForest2:
	msgbox gText_ViridianForest_TrainerTips2 MSG_SIGN
	release
	end

.global EventScript_TrainerTipsViridianForest3
EventScript_TrainerTipsViridianForest3:
	msgbox gText_ViridianForest_TrainerTips3 MSG_SIGN
	release
	end

.global EventScript_TrainerTipsViridianForest4
EventScript_TrainerTipsViridianForest4:
	msgbox gText_ViridianForest_TrainerTips4 MSG_SIGN
	release
	end

.global EventScript_TrainerTipsCerulean1
EventScript_TrainerTipsCerulean1:
	msgbox gText_Cerulean_TrainerTips1 MSG_SIGN
	release
	end

.global EventScript_TrainerTipsCeladon1
EventScript_TrainerTipsCeladon1:
	msgbox gText_Celadon_TrainerTips1 MSG_SIGN
	release
	end

.global EventScript_TrainerTipsCeladon2
EventScript_TrainerTipsCeladon2:
	msgbox gText_Celadon_TrainerTips2 MSG_SIGN
	release
	end

.global EventScript_TrainerTipsSaffron1
EventScript_TrainerTipsSaffron1:
	msgbox gText_Saffron_TrainerTips1 MSG_SIGN
	release
	end

.global EventScript_TrainerTipsSaffron2
EventScript_TrainerTipsSaffron2:
	msgbox gText_Saffron_TrainerTips2 MSG_SIGN
	release
	end

.global EventScript_TrainerTipsRoute13_1
EventScript_TrainerTipsRoute13_1:
	msgbox gText_Route13_TrainerTips1 MSG_SIGN
	release
	end

.global EventScript_TrainerTipsPallet
EventScript_TrainerTipsPallet:
	msgbox gText_pallettown_trainertips MSG_KEEPOPEN 
	setvar 0x4070 0x1
	releaseall
	end

.global EventScript_TrainerTipsTile
EventScript_TrainerTipsTile:
	lockall
	applymovement 0x1 0x81A75EB
	applymovement PLAYER 0x81A75E7
	waitmovement 0x0
	call TrainerTipsStuff
	releaseall
	end


#org EventScript_Pallet_TipsGirl
EventScript_Pallet_TipsGirl:
	lock
	compare 0x4070 0x2
	if 0x1 _goto 0x81657ED
	compare 0x4070 0x1
	if 0x1 _goto 0x8165815
	compare 0x4002 0x1
	if 0x1 _goto TrainerTipsGirl1
	checkflag 0x2
	if 0x1 _goto 0x8165801
	msgbox 0x81B1C8B MSG_KEEPOPEN 
	applymovement 0x1 0x81A75E1
	waitmovement 0x0
	sound 0x15
	applymovement 0x1 0x81A75DB
	waitmovement 0x0
	applymovement 0x1 0x81A75DD
	waitmovement 0x0
	msgbox 0x81B1C9F MSG_KEEPOPEN 
	closeonkeypress
	compare PLAYERFACING 0x4
	if 0x1 _call 0x81657D7
	compare PLAYERFACING 0x4
	if 0x5 _call 0x81657E2
	moveoffscreen 0x1
	setflag 0x2
	release
	end

TrainerTipsGirl1:
	applymovement 0x1 0x81A75E1
	waitmovement 0x0
	call TrainerTipsStuff
	release
	end

TrainerTipsStuff:
	textcolor 0x1
	msgbox 0x81B1D0B MSG_KEEPOPEN 
	closeonkeypress
	pause 0x14
	textcolor 0x3
	setflag 0x83E
	setvar 0x4070 0x1
	setvar 0x4002 0x0
	special 0x170
	special 0x171
	signmsg
	msgbox gText_pallettown_trainertips MSG_KEEPOPEN 
	pause 0x14
	normalmsg
	return
