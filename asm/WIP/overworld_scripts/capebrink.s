.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ VAR_BATTLE_AURAS, 0x5119
.equ FLAG_MINIMAL_GRINDING_MODE, 0x1032
.equ FLAG_TAUGHT_DARKHOLE, 0x105A
.equ FLAG_BEAT_DARKHOLE_TUTOR, 0x1059

.global EventScript_CapeBrinkDarkHoleTutor
EventScript_CapeBrinkDarkHoleTutor:
    checkflag FLAG_BEAT_DARKHOLE_TUTOR
    if SET _goto AskTeachDarkHole
    msgbox gText_CapeBrink_DH0 MSG_YESNO
    compare LASTRESULT YES
    if equal _goto BattleDarkHole
    goto OkSuitYourself
    end

BattleDarkHole: 
    msgbox gText_CapeBrinkDH0_1 MSG_NORMAL
    trainerbattle3 0x3 0x93 0x0 gText_DHTutor_Defeat
    setflag FLAG_BEAT_DARKHOLE_TUTOR
    msgbox gText_CapeBrinkDH0_2 MSG_NORMAL

AskTeachDarkHole:
    checkflag FLAG_TAUGHT_DARKHOLE
    if SET _goto AlreadyDoneDarkHole
    msgbox gText_CapeBrink_DH1 MSG_YESNO
    compare LASTRESULT YES
    if equal _goto TeachDarkHole
    compare LASTRESULT NO
    if equal _goto OkSuitYourself
    end

TeachDarkHole:
    msgbox gText_CapeBrink_DH2 MSG_NORMAL
	setvar 0x8005 0x8 @change here
	call DarkHoleOpenParty
	compare LASTRESULT 0x0
	if 0x1 _goto OkSuitYourself
    setflag FLAG_TAUGHT_DARKHOLE
	msgbox gText_CapeBrink_DH3 MSG_NORMAL
    release
    end

DarkHoleOpenParty:
	special 0x18D
	waitstate
	return


OkSuitYourself:
    msgbox gText_CapeBrink_DHNoBattle MSG_NORMAL
    release
    end

AlreadyDoneDarkHole:
    msgbox gText_CapeBrink_DHDone MSG_NORMAL
    release
    end

