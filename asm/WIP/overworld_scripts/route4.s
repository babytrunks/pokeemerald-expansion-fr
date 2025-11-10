.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s" 

.equ FLAG_MINIMAL_GRINDING_MODE, 0x1032
.equ FLAG_HARDCORE_MODE, 0x1034

.global EventScript_givepoweruppunch_Start
EventScript_givepoweruppunch_Start:
	textcolor 0x0
	lock 
	faceplayer 
	checkitem ITEM_TM101 0x1 
	compare 0x800D 0x1
	if greaterorequal _goto EventScript_givepoweruppunch_Done
	msgbox gText_givepoweruppunch_3 0x6
	msgbox gText_givepoweruppunch_4 0x5
	compare LASTRESULT 0x1
	if 0x1 _call EventScript_givepoweruppunch_Take
	msgbox gText_givepoweruppunch_6 0x6
	release
	end

EventScript_givepoweruppunch_Take:
	msgbox gText_givepoweruppunch_5 0x6
	giveitem ITEM_TM101 0x1 MSG_OBTAIN
	msgbox gText_givepoweruppunch_7 0x6
	release
	end

EventScript_givepoweruppunch_Done:
	msgbox gText_givepoweruppunch_7 0x6
	release
	end

.global EventScript_machobrace_Start
EventScript_machobrace_Start:
	lock
	faceplayer
	textcolor 0x0
	checkflag 0x203
	if 0x1 _goto EventScript_machobrace_Done
	msgbox gText_machobrace_3 0x6 
	checkflag FLAG_MINIMAL_GRINDING_MODE
	if 0x1 _goto GivePPUps
	giveitem ITEM_MACHO_BRACE 0x1 MSG_OBTAIN
	msgbox gText_machobrace_4 0x6
	setflag 0x203
	msgbox gText_machobrace_5 0x6
	release
	end

GivePPUps:
	giveitem ITEM_PP_UP 0x4 MSG_OBTAIN
	msgbox gText_machobrace_4_2 0x6
	setflag 0x203
	release
	end

EventScript_machobrace_Done:
	checkflag FLAG_MINIMAL_GRINDING_MODE
	if 0x1 _goto MachoBrace_DoneMinGrinding
	msgbox gText_machobrace_4 0x6
	release
	end

MachoBrace_DoneMinGrinding:
	msgbox gText_machobrace_4_2 0x6
	release
	end

.global EventScript_Route4_WaterStone
EventScript_Route4_WaterStone:
    hidesprite 0x800F
    giveitem ITEM_WATER_STONE 0x1 MSG_FIND
    setflag 0x1036
    release
    end

.global EventScript_Route4_SunStone
EventScript_Route4_SunStone:
    hidesprite 0x800F
    giveitem ITEM_SUN_STONE 0x1 MSG_FIND
    setflag 0x1037
    release
    end


.global gMapScripts_Route4
gMapScripts_Route4:
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScripts_Route4
    mapscript MAP_SCRIPT_ON_TRANSITION MapEntryScript_Route4
    .byte MAP_SCRIPT_TERMIN

LevelScripts_Route4:
    levelscript 0x5054, 1, EventScript_postgiovannilevelscript_Start
    .hword MAP_SCRIPT_TERMIN

MapEntryScript_Route4:
	release 
	end 

.global EventScript_postgiovannilevelscript_Start
EventScript_postgiovannilevelscript_Start:
	lockall
	msgbox gText_postgiovannilevelscript_1 0x6
	applymovement 0xA EventScript_postgiovannilevelscript_Lookleft @A is giovanni
	pause 0x10
	applymovement 0xA EventScript_postgiovannilevelscript_Lookright
	pause 0x10
	applymovement 0xC EventScript_postgiovannilevelscript_Lookright @C is Lance 
	pause 0x10
	applymovement 0xA EventScript_postgiovannilevelscript_Lookleft
	waitmovement 0x0
	sound 0x15
	applymovement 0xA EventScript_postgiovannilevelscript_Surprised
	applymovement 0xC EventScript_postgiovannilevelscript_Surprised
	checksound
	waitmovement 0x0
	applymovement 0xFF EventScript_postgiovannilevelscript_Lookright
	waitmovement 0x0
	applymovement 0xA EventScript_postgiovannilevelscript_Lookleft
	applymovement 0x9 EventScript_postgiovannilevelscript_Lookleft
	waitmovement 0x0
	msgbox gText_postgiovannilevelscript_Suchpower 0x6
	applymovement 0xA EventScript_postgiovannilevelscript_Lookright
	waitmovement 0x0
	msgbox gText_postgiovannilevelscript_3 0x6
	applymovement 0xA EventScript_postgiovannilevelscript_Walkleft
	applymovement 0xA EventScript_postgiovannilevelscript_Movealilleft
	waitmovement 0x0
	msgbox gText_postgiovannilevelscript_4 0x6
	applymovement 0xA EventScript_postgiovannilevelscript_Lookright
	waitmovement 0x0
	msgbox gText_postgiovannilevelscript_5 0x6
	msgbox gText_postgiovannilevelscript_6 0x6
	applymovement 0xA EventScript_postgiovannilevelscript_Lookleft
	waitmovement 0x0
	msgbox gText_postgiovannilevelscript_6_2 MSG_NORMAL 
	msgbox gText_postgiovannilevelscript_7 0x6
	applymovement 0xA EventScript_postgiovannilevelscript_Walkleft
	waitmovement 0x0 
	applymovement 0xA EventScript_postgiovannilevelscript_Lookdown
	waitmovement 0x0 
	applymovement 0xFF EventScript_postgiovannilevelscript_Lookup
	waitmovement 0x0 
	msgbox gText_postgiovannilevelscript_7_2 MSG_NORMAL 
	giveitem ITEM_MEWTWONITE_Y 0x1 MSG_OBTAIN
	applymovement 0xA EventScript_postgiovannilevelscript_Lookright
	applymovement 0xA EventScript_postgiovannilevelscript_Movealilright
	waitmovement 0x0
	msgbox gText_postgiovannilevelscript_8 0x6
	sound 0xA
	applymovement 0x9 EventScript_postgiovannilevelscript_Jump @A is Archer 8 is Ariana
	applymovement 0xB EventScript_postgiovannilevelscript_Jump
	checksound
	waitmovement 0x0
	msgbox gText_postgiovannilevelscript_9 0x6
	applymovement 0xA WalkRight 
	waitmovement 0x0 
	applymovement 0x9 EventScript_postgiovannilevelscript_Walkleft2
	waitmovement 0x0
	applymovement 0xB EventScript_postgiovannilevelscript_Walkleft2
	waitmovement 0x0
	applymovement 0xB EventScript_postgiovannilevelscript_Walkleft
	waitmovement 0x0
	applymovement 0xB EventScript_postgiovannilevelscript_Down1
	waitmovement 0x0
	msgbox gText_postgiovannilevelscript_10 0x6
	applymovement 0x9 EventScript_postgiovannilevelscript_Rightlookback
	waitmovement 0x0
	applymovement 0xB EventScript_postgiovannilevelscript_Uplookback
	waitmovement 0x0
	applymovement 0xA EventScript_postgiovannilevelscript_Walkleft
	waitmovement 0x0
	applymovement 0xA EventScript_postgiovannilevelscript_Lookdown
	waitmovement 0x0
	msgbox gText_postgiovannilevelscript_11 0x6
	msgbox gText_postgiovannilevelscript_12 0x6
	applymovement 0xA EventScript_postgiovannilevelscript_Leave
	applymovement 0x9 EventScript_postgiovannilevelscript_Leave
	applymovement 0xB EventScript_postgiovannilevelscript_Leave
	waitmovement 0x0
	hidesprite 0xA
	hidesprite 0x9
	hidesprite 0xB
	setflag 0x920
	setflag 0x976
	setflag 0x977
	applymovement 0xFF EventScript_postgiovannilevelscript_Lookleft
	waitmovement 0x0 
	msgbox gText_postgiovannilevelscript_13 MSG_NORMAL 
	msgbox gText_postgiovannilevelscript_14 MSG_NORMAL 
	giveitem ITEM_SALAMENCITE 0x1 MSG_OBTAIN 
	msgbox gText_postgiovannilevelscript_15 MSG_NORMAL 
	fadescreen 0x1 
	sound 0x97
	checksound 
	hidesprite 0xC
	setflag 0x200 
	fadescreen 0x0
	setvar 0x5054 0x2
	call MakeFollowerVisible
	end

EventScript_postgiovannilevelscript_Lookleft:
.byte 0x2
.byte 0xFE

WalkRight:
	.byte walk_right 
	.byte look_left 
	.byte end_m 
	
EventScript_postgiovannilevelscript_Lookright:
.byte 0x3
.byte 0xFE

EventScript_postgiovannilevelscript_Lookup:
.byte 0x1
.byte 0xFE 

EventScript_postgiovannilevelscript_Lookdown:
.byte 0x0
.byte 0xFE

EventScript_postgiovannilevelscript_Surprised:
.byte 0x62
.byte 0xFE

EventScript_postgiovannilevelscript_Walkleft:
.byte 0x12
.byte 0xFE

EventScript_postgiovannilevelscript_Movealilleft:
.byte 0x23
.byte 0xFE

EventScript_postgiovannilevelscript_Movealilright:
.byte 0x24
.byte 0xFE

EventScript_postgiovannilevelscript_Walkleft2:
.byte 0x12
.byte 0x12
.byte 0xFE

EventScript_postgiovannilevelscript_Rightlookback:
.byte 0x13
.byte 0x4A
.byte 0xFE

EventScript_postgiovannilevelscript_Uplookback:
.byte 0x11
.byte 0x4A
.byte 0xFE

EventScript_postgiovannilevelscript_Down1:
.byte 0x10
.byte 0xFE


EventScript_postgiovannilevelscript_Jump:
.byte 0x54
.byte 0xFE

EventScript_postgiovannilevelscript_Leave:
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0x13
.byte 0xFE

EventScript_Stop:
	.byte lock_facing
	.byte 0xFE

.global EventScript_Route3_PostSallyCareTile
EventScript_Route3_PostSallyCareTile:
	lockall
	textcolor 0x0
	checkflag 0x103F
	if 0x1 _call GiveSallyCarePackage
	setvar 0x511D 0x1
	release
	end

GiveSallyCarePackage:
	applymovement 0xFF EventScript_Stop
	waitmovement 0x0
	checkflag FLAG_MINIMAL_GRINDING_MODE
	if 0x0 _call GiveSeed
	checkflag FLAG_HARDCORE_MODE
	if 0x0 _call GiveThroat
	msgbox gText_CarePackageFind MSG_NORMAL
	giveitem ITEM_BERRY_JUICE 0xA MSG_OBTAIN
	giveitem ITEM_CHESTO_BERRY 0xA MSG_OBTAIN
	giveitem ITEM_ETHER 0xA MSG_OBTAIN
	giveitem ITEM_HEAL_BALL 0x32 MSG_OBTAIN
	giveitem ITEM_LEPPA_BERRY 0xA MSG_OBTAIN
	giveitem ITEM_LUCKY_EGG 0xA MSG_OBTAIN
	giveitem ITEM_PP_UP 0xA MSG_OBTAIN
	giveitem ITEM_SITRUS_BERRY 0xA MSG_OBTAIN
	giveitem ITEM_STARDUST 0xA MSG_OBTAIN
	giveitem ITEM_IRON_BALL 0xA MSG_OBTAIN
	return

GiveSeed:
	giveitem ITEM_MUSCLE_WING 0xA MSG_OBTAIN
	giveitem ITEM_PROTEIN 0xA MSG_OBTAIN
	giveitem ITEM_CARBOS 0xA MSG_OBTAIN
	giveitem ITEM_SWIFT_WING 0xA MSG_OBTAIN
	return

GiveThroat:
	giveitem ITEM_THROAT_SPRAY 0xA MSG_OBTAIN
	return

.global EventScript_Route4_PostArcher1Care
EventScript_Route4_PostArcher1Care:
	lockall
	textcolor 0x0
	checkflag 0x103F
	if 0x1 _call GiveArcher1CarePackage
	setvar 0x511E 0x1
	release
	end

GiveArcher1CarePackage:
	applymovement 0xFF EventScript_Stop
	waitmovement 0x0
	checkflag FLAG_MINIMAL_GRINDING_MODE
	if 0x0 _call GiveArcher1Seed
	msgbox gText_CarePackageFind MSG_NORMAL
	giveitem ITEM_IRON_BALL 0xA MSG_OBTAIN
	giveitem ITEM_STAR_PIECE 0xA MSG_OBTAIN
	giveitem ITEM_COLBUR_BERRY 0xA MSG_OBTAIN
	giveitem ITEM_WIDE_LENS 0xA MSG_OBTAIN
	checkflag FLAG_HARDCORE_MODE
	if 0x0 _call GiveNonHcCare
	return

GiveNonHcCare:
	giveitem ITEM_HEAT_ROCK 0xA MSG_OBTAIN
	return

GiveArcher1Seed:
	giveitem ITEM_CARBOS 0xA MSG_OBTAIN
	giveitem ITEM_SWIFT_WING 0xA MSG_OBTAIN
	giveitem ITEM_CALCIUM 0xA MSG_OBTAIN
	giveitem ITEM_GENIUS_WING 0xA MSG_OBTAIN
	return
