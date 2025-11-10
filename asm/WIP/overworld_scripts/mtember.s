.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s" 

.global EventScript_MtEmber_MistyExplode
EventScript_MtEmber_MistyExplode:
    lock
    faceplayer 
    checkflag 0x2C3
	if 0x1 _goto EventScript_mistyexplode_Done
	msgbox gText_mistyexplode_3 0x5
	compare LASTRESULT 0x1
	if 0x1 _call EventScript_mistyexplode_Take
	msgbox gText_mistyexplode_6 0x6
	release
	end

EventScript_mistyexplode_Take:
	msgbox gText_mistyexplode_4 0x6
	giveitem ITEM_TM112 0x1 MSG_OBTAIN
	setflag 0x2C3
	msgbox gText_mistyexplode_5 0x6
	release
	end

EventScript_mistyexplode_Done:
	msgbox gText_mistyexplode_5 0x6
	release
	end

.global EventScript_MtEmber_Courtney
EventScript_MtEmber_Courtney:
    lock
    msgbox gText_mtember_ariana_1 MSG_NORMAL
    msgbox gText_mtember_ariana_22 MSG_KEEPOPEN
    pause 0x4
    closeonkeypress
    sound 0x15
    applymovement 0x15 FacePlayer
    waitmovement 0x0
    checksound
    msgbox gText_mtember_ariana_2 MSG_NORMAL
    special 0x0
    setflag 0x90E
    trainerbattle3 0x3 0x29 0x0 gText_MtEmber_arianaLoss
    msgbox gText_mtember_ariana_3 MSG_NORMAL
    applymovement 0x15 FaceUp
    waitmovement 0x0
    pause 0x3
    fadescreen 0x1
    hidesprite 0x15
    sound 0x9
    checksound
    fadescreen 0x0
    setflag 0x93E
    special 0x0 
    release
    end
    
FacePlayer:
    .byte face_player
    .byte exclaim
    .byte end_m

FaceUp:
    .byte look_up
    .byte end_m

.global EventScript_MtEmber_Maxie_Fight_Right
EventScript_MtEmber_Maxie_Fight_Right:
    lock
    setflag 0x926
    applymovement 0xFF WalkLeft
    waitmovement 0x0
    goto EventScript_MtEmber_Maxie_Fight
    end

.global EventScript_MtEmber_Maxie_Fight
EventScript_MtEmber_Maxie_Fight:
    lock
	call PutFollowPkmnInBallBattle
    applymovement PLAYER LookUp
    waitmovement 0x0
    msgbox gText_mtember_archer1 MSG_NORMAL
    applymovement 0x7 CourtneyInPlace @6 is maxie 7 is courtney
    waitmovement 0x0
    msgbox gText_mtember_archer2 MSG_NORMAL
    applymovement 0x6 FaceDown
    waitmovement 0x0
    msgbox gText_mtember_archer3 MSG_NORMAL
    applymovement 0x7 CourtneyInPlace
    waitmovement 0x0
    applymovement 0x6 FaceLeft
    waitmovement 0x0
    msgbox gText_mtember_archer4 MSG_NORMAL
    applymovement 0x6 FaceDown
    waitmovement 0x0
    msgbox gText_mtember_archer5 MSG_NORMAL
    special 0x0
    setflag 0x90E
    checkflag FLAG_HARDCORE_MODE
    if SET _call SetHarshSunlight
    @ setflag FLAG_SMALL_TRAINER_LEVELS
    trainerbattle3 0x3 0x2A 0x0 gText_MtEmber_MaxieLoss
    msgbox gText_mtember_archer6 MSG_NORMAL
    msgbox gText_mtember_archer7 MSG_NORMAL
    msgbox gText_mtember_archer8 MSG_NORMAL
    call GiveSpecialAero
    fanfare 0x13E
    msgbox gText_mtember_archer9 MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    msgbox gText_mtember_archer10 MSG_NORMAL
    fadescreen 0x1
    hidesprite 0x6 
    hidesprite 0x7
    sound 0x9
    checksound
    fadescreen 0x0
    setvar 0x510B 0x1
    setvar VAR_WEATHER 0x0
    call MakeFollowerVisibleNoFade
    release
    end

LookUp:
    .byte look_up
    .byte end_m

GiveSpecialAero:
    setvar 0x8000 MOVE_FIREFANG
    setvar 0x8001 MOVE_STONEEDGE
    setvar 0x8002 MOVE_HEADLONGRUSH @moves 
    setvar 0x8003 MOVE_BRAVEBIRD 
    setvar 0x8004 NATURE_JOLLY @nature 
    setvar 0x8005 0x0 
    setvar 0x8006 31
    setvar 0x8007 31
    setvar 0x8008 31
    setvar 0x8009 31
    setvar 0x800A 31
    setvar 0x800B 31
    givepokemon SPECIES_AERODACTYL 85 0x0 0x0 0x1 0x0

SetHarshSunlight:
	setvar VAR_WEATHER 0x5
	return

CourtneyInPlace:
    .byte walk_right_onspot
    .byte walk_right_onspot
    .byte end_m

FaceLeft:
    .byte look_left
    .byte end_m
FaceDown:
    .byte look_down
    .byte end_m

WalkDownUp:
    .byte walk_down
    .byte walk_up
    .byte end_m

JumpInPlace:
    .byte jump_onspot_left
    .byte end_m

QuestionMark:
    .byte say_question
    .byte end_m

ComeToYou:
    .byte walk_down
    .byte walk_right
    .byte face_player 
    .byte end_m

WalkLeft:
    .byte walk_left
    .byte look_up
    .byte end_m

EndThis:
    release 
    end

.global EventScript_MtEmber_Heatran
EventScript_MtEmber_Heatran:
    lock
    faceplayer
    cry SPECIES_HEATRAN 0x2
    preparemsg gText_MtEmber_Heatran1 
    waitmsg
    waitcry
    pause 0xA
    playsong 0x156 0x0
    waitkeypress
    wildbattle SPECIES_HEATRAN 0x5A 0x00
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x4
    if 0x1 _goto EndThis
    fadescreen 0x1
    hidesprite 0x800F
    setflag 0x2BD
    fadescreen 0x0
    release
    end

