.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s" 

.equ FLAG_HARDCORE_MODE, 0x1034
.equ FLAG_MINIMAL_GRINDING_MODE, 0x1032

.equ VAR_BATTLE_AURAS, 0x5119
.equ AURA_DELTA_STREAM_STRING, 27
.equ VAR_WEATHER, 0x5118

.global EventScript_terrakion_OW
EventScript_terrakion_OW:
    lock
    faceplayer
    cry SPECIES_TERRAKION 0x2
    preparemsg gText_terrakion_12
    waitmsg
    waitcry
    pause 0xA
    playsong 0x156 0x0
    waitkeypress
    wildbattle SPECIES_TERRAKION 0x41 0x00
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x4
    if 0x1 _goto Moveback2
    fadescreen 0x1
    hidesprite 0x800F
    setflag 0x1012
    fadescreen 0x0
    release
    end

Moveback2:
    release 
    end

.global gMapScripts_RockTunnelZap
gMapScripts_RockTunnelZap:
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScripts_RockTunnelZap
    mapscript MAP_SCRIPT_ON_LOAD SetmaptileScript_RockTunnelPost
    .byte MAP_SCRIPT_TERMIN

LevelScripts_RockTunnelZap:
    levelscript 0x510C, 0, LevelScript_RockTunnelZap
    .hword MAP_SCRIPT_TERMIN

LevelScript_RockTunnelZap:
    lock
	msgbox gText_rocktunnelzap_1 MSG_KEEPOPEN
    pause 0x3
	closeonkeypress
    applymovement 0x4 FalknerLookDown
    waitmovement 0x0
    pause 0x3
    sound 0x15
    applymovement 0x4 FalknerSurprised
    waitmovement 0x0
    checksound
    msgbox gText_rocktunnelzap_2 MSG_KEEPOPEN
    pause 0x3
    msgbox gText_rocktunnelzap_2_2 MSG_NORMAL
    msgbox gText_rocktunnelzap_3 MSG_NORMAL
    special 0x0
    setflag 0x90E
    checkflag FLAG_HARDCORE_MODE
    if SET _call SetDeltaStream
    trainerbattle3 0x3 0x2B 0x0 gText_rocktunnelzap_Defeat
    msgbox gText_rocktunnelzap_4 MSG_NORMAL
    giveitem ITEM_FLYINIUM_Z 0x1 MSG_OBTAIN
    msgbox gText_rocktunnelzap_4_2 MSG_NORMAL
    giveitem ITEM_GRACIDEA 0x1 MSG_OBTAIN
    msgbox gText_rocktunnelzap_5 MSG_NORMAL
    fadescreen 0x1
    hidesprite 0x4
    sound 0x9
    checksound
    fadescreen 0x0
    setflag 0x1018
	setvar 0x510C 0x1
	end

SetDeltaStream:
    setvar VAR_WEATHER 0x8
    return
    
SetmaptileScript_RockTunnelPost:
    compare 0x5131 0x64
    if 0x1 _call SetFirstTiles
    compare 0x512B 0x64
    if 0x1 _call SetSecondTiles
    compare 0x512C 0x64
    if 0x1 _call SetThirdTiles
    end

SetFirstTiles:
    setmaptile 0x1B 0x1E 0x281 0x0
    setmaptile 0x1B 0x1F 0x281 0x0
    setmaptile 0x1C 0x1E 0x281 0x0
    setmaptile 0x1C 0x1F 0x281 0x0
    movesprite2 0x6 0x1 0x12 
    moveoffscreen 0x6
    return

SetSecondTiles:
    setmaptile 0x1F 0x07 0x281 0x0
    setmaptile 0x1F 0x08 0x281 0x0
    setmaptile 0x20 0x07 0x281 0x0
    setmaptile 0x20 0x08 0x281 0x0
    movesprite2 0x5 0x1D 0x13
    moveoffscreen 0x5
    return

SetThirdTiles:
    setmaptile 0x5 0xB 0x281 0x0
    setmaptile 0x5 0xC 0x281 0x0
    setmaptile 0x6 0xB 0x281 0x0
    setmaptile 0x6 0xC 0x281 0x0
    movesprite2 0x8 0x29 0x1
    return

FalknerSurprised:
    .byte exclaim
    .byte end_m

FalknerLookDown:
    .byte look_down
    .byte end_m

.global EventScript_Magearna_OW
EventScript_Magearna_OW:
    lock
    faceplayer
    cry SPECIES_MAGEARNA 0x2
    preparemsg gText_Magearna_Cry
    waitmsg
    waitcry
    pause 0xA
    playsong 0x156 0x0
    waitkeypress
    wildbattle SPECIES_MAGEARNA 0x5A 0x00
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x4
    if 0x1 _goto Moveback2
    fadescreen 0x1
    hidesprite 0x800F
    setflag 0x101A
    fadescreen 0x0
    release
    end

.global EventScript_Route10_PostHermanCare
EventScript_Route10_PostHermanCare:
	lockall
	textcolor 0x0
	checkflag 0x103F
	if 0x1 _call GiveHermanCarePackage
	setvar 0x5121 0x1
	release
	end

GiveHermanCarePackage:
	applymovement 0xFF EventScript_Stop
	waitmovement 0x0
    msgbox gText_CarePackageFind MSG_NORMAL
	giveitem ITEM_BIG_NUGGET 0xA MSG_OBTAIN
	giveitem ITEM_DIVE_BALL 0xA MSG_OBTAIN
	giveitem ITEM_DUSK_BALL 0xA MSG_OBTAIN
	giveitem ITEM_MOOMOO_MILK 0xA MSG_OBTAIN
    checkflag FLAG_HARDCORE_MODE
	if 0x0 _call GiveMisty
	return

GiveMisty:
	giveitem ITEM_MISTY_SEED 0xA MSG_OBTAIN
	return

EventScript_Stop:
	.byte lock_facing
	.byte 0xFE

.global EventScript_StrengthTile1
EventScript_StrengthTile1:
    setmaptile 0x1B 0x1E 0x281 0x0
    setmaptile 0x1B 0x1F 0x281 0x0
    setmaptile 0x1C 0x1E 0x281 0x0
    setmaptile 0x1C 0x1F 0x281 0x0
    sound 0x23
    special 0x8E
    checksound
    moveoffscreen 0x6
    setvar 0x5131 0x64
    releaseall
    end

.global EventScript_StrengthTile2
EventScript_StrengthTile2:
    setmaptile 0x1F 0x07 0x281 0x0
    setmaptile 0x1F 0x08 0x281 0x0
    setmaptile 0x20 0x07 0x281 0x0
    setmaptile 0x20 0x08 0x281 0x0
    sound 0x23
    special 0x8E
    checksound
    moveoffscreen 0x5
    setvar 0x512B 0x64
    releaseall
    end

.global EventScript_StrengthTile3
EventScript_StrengthTile3:
    setmaptile 0x5 0xB 0x281 0x0
    setmaptile 0x5 0xC 0x281 0x0
    setmaptile 0x6 0xB 0x281 0x0
    setmaptile 0x6 0xC 0x281 0x0
    sound 0x23
    special 0x8E
    checksound
    moveoffscreen 0x8
    setvar 0x512C 0x64
    releaseall
    end

