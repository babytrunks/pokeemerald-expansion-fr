.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s" 

.equ FLAG_HARDCORE_MODE, 0x1034
.equ VAR_WEATHER, 0x5118
.equ FLAG_BEAT_DUMBASS_KID_REMATCH, 0x1082
.global EventScript_DumbassKid
EventScript_DumbassKid:
    checkflag 0x98D
    if 0x1 _goto Done
    lock
    faceplayer
    msgbox gText_DumbassKid_1 MSG_YESNO
    compare LASTRESULT 0x0
    if notequal _goto Good 
    msgbox gText_DumbassKid_Battle MSG_YESNO
    compare LASTRESULT 0x0 
    if notequal _goto Good 
    sound 0xA
    applymovement 0x4 JumpUp
    waitmovement 0x0
    checksound
    msgbox gText_DumbassKid_Battle2 MSG_FACE 
    setflag 0x90E
    checkflag FLAG_HARDCORE_MODE
    if 0x1 _call SetWeather 
    trainerbattle3 0x3 0x19 0x0 gText_DumbassKidLoss
    setflag 0x98D
    msgbox gText_DumbassKid_PostLoss MSG_FACE 
    giveitem ITEM_TM26 0x1 MSG_OBTAIN
    msgbox gText_DumbassKid_EQInfo MSG_KEEPOPEN
    pause 0x5
    closeonkeypress
    release 
    end 
    
Done:
    checkflag 0x97A
    if 0x0 _goto CheckSwampertMega
    checkitem ITEM_Z_POWER_RING 0x1
    compare LASTRESULT 0x1
    if greaterorequal _goto DumbassKidRematch
    msgbox gText_DumbassKid_LastMsg_2 MSG_FACE 
    release
    end

DumbassKidRematch:
    checkflag FLAG_BEAT_DUMBASS_KID_REMATCH
    if 0x1 _goto DumbassKidRematchDone2
    lock
    faceplayer
    msgbox gText_DumbassKid_Rematch MSG_YESNO
    compare LASTRESULT NO
    if equal _goto releaseendscript
    msgbox gText_DumbassKid_GetHim MSG_NORMAL
    call SetWeather
    trainerbattle3 0x3 0x23 0x0 gText_DumbassKidLoss
    msgbox gText_DumbassKid_Rematch2 MSG_NORMAL
    givepokemon SPECIES_COSMOG 50 0x0 0x0 0x0 0x0
    fanfare 0x13E
    msgbox gText_DumbassKid_ReceiveCosmog MSG_KEEPOPEN
    waitfanfare
    pause 0x2
    setflag FLAG_BEAT_DUMBASS_KID_REMATCH 
DumbassKidRematchDone:
    msgbox gText_DumbassKid_Stronger MSG_NORMAL
    release
    end

DumbassKidRematchDone2:
    random 0x3
    compare 0x800D 0x0 
	if 0x1 _goto DumbassKidRematchDone
    compare 0x800D 0x1
    if 0x1 _goto DumbassKidRematchDone3
    msgbox gText_DumbassKid_Gren MSG_NORMAL
    release
    end

DumbassKidRematchDone3:
    msgbox gText_DumbassKid_SisterBully MSG_NORMAL
    release
    end

Done2:
    msgbox gText_DumbassKid_LastMsg MSG_FACE 
    release
    end

CheckSwampertMega:
    checkflag FLAG_FOLLOWER_IN_PROGRESS
	if 0x0 _goto Done2
	compare 0x5130 SPECIES_SWAMPERT
	if notequal _goto Done2
    faceplayer
    @ callasm FollowerApplyMovementJumpToUp + 1 
    @ waitmovement 0x0
    @ checksound
    sound 0xA
    pause 0x3
    sound 0x15
    applymovement 0x4 Exclaim
    waitmovement 0x0
    checksound
    msgbox gText_DumbassKid_YouGotSwamp MSG_KEEPOPEN
    cry SPECIES_SWAMPERT 0x0
    waitcry
    pause 0x2
    closeonkeypress
    sound 0xA
    applymovement 0x4 JumpUp
    waitmovement 0x0
    checksound
    msgbox gText_DumbassKid_ThatsPog MSG_NORMAL
    msgbox gText_DumbassKid_HaveThis MSG_NORMAL
    giveitem ITEM_SWAMPERTITE 0x1 MSG_OBTAIN
    setflag 0x97A
    release
    end




Exclaim:
    .byte exclaim
    .byte end_m

SetWeather:
    setvar VAR_WEATHER 0x2 
    return

Good:
    cry 0x11B 0x0
    msgbox gText_DumbassKid_Good MSG_KEEPOPEN
    waitcry
    closeonkeypress
    cry 0x11B 0x0
    msgbox gText_DumbassKid_Good MSG_KEEPOPEN
    waitcry
    closeonkeypress
    cry 0x11B 0x0
    msgbox gText_DumbassKid_Good MSG_KEEPOPEN
    waitcry
    closeonkeypress
    cry 0x11B 0x0
    msgbox gText_DumbassKid_Good MSG_KEEPOPEN
    waitcry
    closeonkeypress
    cry 0x11B 0x0
    msgbox gText_DumbassKid_Good MSG_KEEPOPEN
    waitcry
    closeonkeypress
    release 
    end

JumpUp:
    .byte 0x52
    .byte 0xFE

.global EventScript_PowerPlant_Jotard
EventScript_PowerPlant_Jotard:
	lock
	faceplayer 
    msgbox gText_Jotard_1 MSG_KEEPOPEN 
    closeonkeypress 
    msgbox gText_Jotard_2 MSG_YESNO 
	compare LASTRESULT NO 
    if equal _goto DontFight 
	msgbox gText_Jotard_3 MSG_NORMAL 
    goto JotardBattle
	release
	end

JotardBattle: 
	setflag 0x915
    setflag 0x90E 
	trainerbattle3 0x3 0x42 0x0 gText_Jotard_Defeat
	msgbox gText_Jotard_4 0x6
	giveitem ITEM_MACHAMPITE 0x1 MSG_OBTAIN
	giveitem ITEM_PRISON_BOTTLE 0x1 MSG_OBTAIN
	msgbox gText_Jotard_5 0x6 
	fadescreen 0x1
	hidesprite 0xA
	sound 0x9
	checksound
	fadescreen 0x0
	setflag 0x93D
	release
	end

DontFight:
    release 
    end 
