.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s" 

.equ VAR_TERRAIN, 0x5000
.equ FLAG_HARDCORE_MODE, 0x1034
.equ FLAG_MINIMAL_GRINDING_MODE, 0x1032
.equ VAR_BATTLE_AURAS, 0x5119
.equ AURA_GRASS_TINTEDLENS_STRING, 6
.equ FLAG_GOT_LUCARIONITE, 0x96A

.global EventScript_Celadon_CheckErika
EventScript_Celadon_CheckErika:
    checkflag 0x823
    if 0x1 _goto Finished 
    applymovement 0xFF LookUp
    waitmovement 0x0 
    msgbox gText_Celadon_ErikaCheck MSG_FACE 
    applymovement 0xFF GoRight 
    waitmovement 0x0 
    release 
    end 

Finished:
    release 
    end 

LookUp:
    .byte 0x1
    .byte 0xFE 

GoRight:
    .byte 0x13
    .byte 0xFE 

.global EventScript_Celadon_CheckErika2
EventScript_Celadon_CheckErika2:
    checkflag 0x823
    if 0x1 _goto Finished 
    applymovement 0xFF LookUp
    waitmovement 0x0 
    msgbox gText_Celadon_ErikaCheck MSG_FACE 
    applymovement 0xFF GoDown 
    waitmovement 0x0 
    release 
    end 

GoDown:
    .byte 0x10
    .byte 0xFE 

.global EventScript_Celadon_IronHead
EventScript_Celadon_IronHead:
    lock
    faceplayer 
	msgbox gText_Celadon_IronHead1 MSG_YESNO
    compare LASTRESULT YES 
    if NO _goto Cancel
    setvar 0x8005 0x19
    special 0x18D
    waitstate
    compare LASTRESULT 0x0
    if 0x1 _goto Cancel
    msgbox gText_Celadon_IronHead2 MSG_FACE 
    release 
	end

Cancel:
    release 
    end 

.global EventScript_playrough_Start
EventScript_playrough_Start:
	lock
	faceplayer
	textcolor 0x0
	checkflag 0x956
	if 0x1 _goto EventScript_playrough_Cost
	msgbox gText_playrough_1 0x5
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_playrough_Cancel
	msgbox gText_playrough_3 0x6
	setvar 0x8005 0x72
	call EventScript_playrough_Teach
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_playrough_Cancel
	setflag 0x956
	msgbox gText_playrough_4 0x6
	release
	end


EventScript_playrough_Teach:
	special 0x18D
	waitstate
	return

EventScript_playrough_Cost:
	showmoney 0x00 0x00 0x00
	msgbox gText_playrough_1 0x6
	msgbox gText_playrough_2 0x5
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_playrough_Cancelhide
	checkmoney 0x1388 0x00
	compare 0x800D 0x1
	if 0x0 _goto EventScript_playrough_Nomoney
	msgbox gText_playrough_3 0x6
	hidemoney 0x00 0x00
	setvar 0x8005 0x72
	call EventScript_playrough_Teach
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_playrough_Cancel
	showmoney 0x00 0x00 0x00
	msgbox gText_playrough_Wait 0x6
	removemoney 0x1388 0x00
	sound 0x58
	updatemoney 0x00 0x00 0x00
	msgbox gText_playrough_4 0x6
	checksound
	hidemoney 0x0 0x0
	release
	end


EventScript_playrough_Cancel:
	msgbox gText_playrough_No 0x6
	release
	end

EventScript_playrough_Cancelhide:
	hidemoney 0x00 0x00
	msgbox gText_playrough_No 0x6
	release
	end

EventScript_playrough_Nomoney:
	msgbox gText_playrough_Poor 0x6
	hidemoney 0x00 0x00
	release
	end

.global EventScript_coincasenugget_Start
EventScript_coincasenugget_Start:
	lock
	faceplayer
	textcolor 0x0
	checkflag 0x96B
	if 0x1 _goto EventScript_coincasenugget_Done
	msgbox gText_coincasenugget_3 0x6
	giveitem ITEM_BIG_NUGGET 0x1 MSG_OBTAIN
	setflag 0x96B
	msgbox gText_coincasenugget_4 0x6
	release
	end

EventScript_coincasenugget_Done:
	msgbox gText_coincasenugget_5 0x6
	release
	end

.global EventScript_ivseller_Start
EventScript_ivseller_Start:
	lock
	faceplayer
	textcolor 0x0
	@ checkflag 0x82C
	@ if equal _goto NowChampion
	@ checkitem ITEM_POWDER_JAR 0x1
	@ compare 0x800D 0x1
	@ if 0x4 _goto EventScript_IvSeller_bustEm
	checkflag FLAG_MINIMAL_GRINDING_MODE
	if 0x1 _goto IvSeller_mingrindingmode
	showmoney 0x0 0x00 0x00
	msgbox gText_ivseller_1 0x5
	compare LASTRESULT 0x0
	if 0x1 _call EventScript_ivseller_Cancel
	msgbox gText_ivseller_3 0x6 @who wants it?
	hidemoney 0x0 0x0
	goto PickPokemon

IvSeller_mingrindingmode:
	msgbox gText_ivseller_1_Hard 0x5
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_ivseller_Cancelnohide
	msgbox gText_ivseller_3 0x6 @who wants it?
	goto PickPokemon

PickPokemon:
	setvar 0x8003 0x0
	special 0x9F @choose from party
	waitstate
	compare 0x8004 0x6
	if 0x4 _goto EventScript_ivseller_Cancelnohide
	special2 LASTRESULT 0x147 @check if it@s an egg
	compare LASTRESULT 0x19C
	if 0x1 _goto EventScript_ivseller_Thatsegg
	showmoney 0x35 0x00
	special 0x7C @puts the selected mon in party into buffer
	goto ChooseStat
	end

ChooseStat:
	setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_EVSubtracter_HP
	special 0x25
	setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_EVSubtracter_Attack
	special 0x25
	setvar 0x8006 0x2 @third item
	loadpointer 0x0 gText_EVSubtracter_Defense
	special 0x25
	setvar 0x8006 0x3 @fourth item
	loadpointer 0x0 gText_EVSubtracter_SpA
	special 0x25
	setvar 0x8006 0x4 @fifth item
	loadpointer 0x0 gText_EVSubtracter_SpDef
	special 0x25
	setvar 0x8006 0x5 @sixth item
	loadpointer 0x0 gText_EVSubtracter_Speed
	special 0x25
	setvar 0x8006 0x6 @7th item
	loadpointer 0x0 gText_EVSubtracter_AllStats
	special 0x25
	preparemsg gText_IVPerfecterPreparemsg_1
	waitmsg
	multichoice 0x0 0x0 0x25 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto PerfectHP
	compare LASTRESULT 0x1
	if 0x1 _goto PerfectAtk
	compare LASTRESULT 0x2
	if 0x1 _goto PerfectDef
	compare LASTRESULT 0x3
	if 0x1 _goto PerfectSpA
	compare LASTRESULT 0x4
	if 0x1 _goto PerfectSpDef
	compare LASTRESULT 0x5
	if 0x1 _goto PerfectSpeed
	compare LASTRESULT 0x6
	if 0x1 _goto PerfectAll
	goto EventScript_ivseller_Cancel
	end

CheckMoney:
	checkmoney 0x11170 0x0
	compare 0x800D 0x1 
	if 0x0 _goto EventScript_ivseller_Poor
	return

PerfectHP:
	checkflag FLAG_MINIMAL_GRINDING_MODE
	if 0x1 _goto PerfectHpMin 
	call CheckMoney
	setvar 0x8005 0x0
	special2 LASTRESULT 0x8 
	buffernumber 0x1 LASTRESULT
	msgbox gText_ivseller_4_1 MSG_YESNO
	compare LASTRESULT NO 
	if equal _goto ChooseStat
	setvar 0x8005 0x0
	setvar 0x8006 0x1F @31
	special 0x10
	goto RemoveEnd

PerfectHpMin:
	setvar 0x8005 0x0
	special2 LASTRESULT 0x8 
	buffernumber 0x1 LASTRESULT
	msgbox gText_ivseller_4_1_min MSG_YESNO
	compare LASTRESULT NO 
	if equal _goto ChooseStat
	setvar 0x8005 0x0
	setvar 0x8006 0x1F @31
	special 0x10
	goto RemoveEndMin

PerfectAtk:
	checkflag FLAG_MINIMAL_GRINDING_MODE
	if 0x1 _goto PerfectAtkMin 
	call CheckMoney
	setvar 0x8005 0x1
	special2 LASTRESULT 0x8 
	buffernumber 0x1 LASTRESULT
	msgbox gText_ivseller_4_2 MSG_YESNO
	compare LASTRESULT NO 
	if equal _goto ChooseStat
	setvar 0x8005 0x1
	setvar 0x8006 0x1F @31
	special 0x10
	goto RemoveEnd

PerfectAtkMin:
	setvar 0x8005 0x1
	special2 LASTRESULT 0x8 
	buffernumber 0x1 LASTRESULT
	msgbox gText_ivseller_4_2_min MSG_YESNO
	compare LASTRESULT NO 
	if equal _goto ChooseStat
	setvar 0x8005 0x1
	setvar 0x8006 0x1F @31
	special 0x10
	goto RemoveEndMin

PerfectDef:
	checkflag FLAG_MINIMAL_GRINDING_MODE
	if 0x1 _goto PerfectDefMin
	call CheckMoney
	setvar 0x8005 0x2
	special2 LASTRESULT 0x8 
	buffernumber 0x1 LASTRESULT
	msgbox gText_ivseller_4_3 MSG_YESNO
	compare LASTRESULT NO 
	if equal _goto ChooseStat
	setvar 0x8005 0x2
	setvar 0x8006 0x1F @31
	special 0x10
	goto RemoveEnd

PerfectDefMin:
	setvar 0x8005 0x2
	special2 LASTRESULT 0x8 
	buffernumber 0x1 LASTRESULT
	msgbox gText_ivseller_4_3_min MSG_YESNO
	compare LASTRESULT NO 
	if equal _goto ChooseStat
	setvar 0x8005 0x2
	setvar 0x8006 0x1F @31
	special 0x10
	goto RemoveEndMin

PerfectSpA:
	checkflag FLAG_MINIMAL_GRINDING_MODE
	if 0x1 _goto PerfectSpaMin
	call CheckMoney
	setvar 0x8005 0x4
	special2 LASTRESULT 0x8 
	buffernumber 0x1 LASTRESULT
	msgbox gText_ivseller_4_4 MSG_YESNO
	compare LASTRESULT NO 
	if equal _goto ChooseStat
	setvar 0x8005 0x4
	setvar 0x8006 0x1F @31
	special 0x10
	goto RemoveEnd

PerfectSpaMin:
	setvar 0x8005 0x4
	special2 LASTRESULT 0x8 
	buffernumber 0x1 LASTRESULT
	msgbox gText_ivseller_4_4_min MSG_YESNO
	compare LASTRESULT NO 
	if equal _goto ChooseStat
	setvar 0x8005 0x4
	setvar 0x8006 0x1F @31
	special 0x10
	goto RemoveEndMin

PerfectSpDef:
	checkflag FLAG_MINIMAL_GRINDING_MODE
	if 0x1 _goto PerfectSpDefMin
	call CheckMoney
	setvar 0x8005 0x5
	special2 LASTRESULT 0x8 
	buffernumber 0x1 LASTRESULT
	msgbox gText_ivseller_4_5 MSG_YESNO
	compare LASTRESULT NO 
	if equal _goto ChooseStat
	setvar 0x8005 0x5
	setvar 0x8006 0x1F @31
	special 0x10
	goto RemoveEnd

PerfectSpDefMin:
	setvar 0x8005 0x5
	special2 LASTRESULT 0x8 
	buffernumber 0x1 LASTRESULT
	msgbox gText_ivseller_4_5_min MSG_YESNO
	compare LASTRESULT NO 
	if equal _goto ChooseStat
	setvar 0x8005 0x5
	setvar 0x8006 0x1F @31
	special 0x10
	goto RemoveEndMin

PerfectSpeed:
	checkflag FLAG_MINIMAL_GRINDING_MODE
	if 0x1 _goto PerfectSpeedMin
	call CheckMoney
	setvar 0x8005 0x3
	special2 LASTRESULT 0x8 
	buffernumber 0x1 LASTRESULT
	msgbox gText_ivseller_4_6 MSG_YESNO
	compare LASTRESULT NO 
	if equal _goto ChooseStat
	setvar 0x8005 0x3
	setvar 0x8006 0x1F @31
	special 0x10
	goto RemoveEnd

PerfectSpeedMin:
	setvar 0x8005 0x3
	special2 LASTRESULT 0x8 
	buffernumber 0x1 LASTRESULT
	msgbox gText_ivseller_4_6_min MSG_YESNO
	compare LASTRESULT NO 
	if equal _goto ChooseStat
	setvar 0x8005 0x3
	setvar 0x8006 0x1F @31
	special 0x10
	goto RemoveEndMin

RemoveEnd:
	removemoney 0x11170 0x00
	sound 0x58
	msgbox gText_ivseller_Wait 0x6
	updatemoney 0x35 0x00 0x00
	msgbox gText_ivseller_Done 0x6
	checksound
	hidemoney 0x35 0x0
	msgbox gText_ivseller_Grind 0x6
	release
	end

RemoveEndMin:
	msgbox gText_ivseller_Wait 0x6
	hidemoney 0x35 0x00
	msgbox gText_ivseller_Done 0x6
	msgbox gText_ivseller_Grind 0x6
	release
	end

PerfectAll: 
	checkflag FLAG_MINIMAL_GRINDING_MODE
	if 0x1 _goto PerfectAllMin
	checkmoney 0x55730 0x0
	compare 0x800D 0x1
	if 0x0 _goto EventScript_ivseller_Poor @means player doesnt ahve enuf money
	msgbox gText_ivseller_4 0x6
	msgbox gText_ivseller_5 0x5
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_ivseller_Cancel2
	removemoney 0x55730 0x00
	call EventScript_ivseller_Giveivs
	sound 0x58
	msgbox gText_ivseller_Wait 0x6
	updatemoney 0x35 0x00 0x00
	msgbox gText_ivseller_Done 0x6
	checksound
	hidemoney 0x35 0x0
	msgbox gText_ivseller_Grind 0x6
	release
	end

PerfectAllMin:
	msgbox gText_ivseller_4_min 0x6
	msgbox gText_ivseller_5 0x5
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_ivseller_Cancel2
	call EventScript_ivseller_Giveivs
	msgbox gText_ivseller_Wait 0x6
	hidemoney 0x35 0x00
	msgbox gText_ivseller_Done 0x6
	msgbox gText_ivseller_Grind 0x6
	release
	end

EventScript_ivseller_Cancel:
	hidemoney 0x0 0x0
    goto EventScript_ivseller_Cancelnohide
	end

EventScript_ivseller_Cancel2:
	hidemoney 0x35 0x0
	goto EventScript_ivseller_Cancelnohide
	end 

EventScript_ivseller_Cancelnohide:
	msgbox gText_ivseller_Op 0x6
	release
	end

EventScript_ivseller_Poor:
	hidemoney 0x0 0x0
	msgbox gText_ivseller_2 0x6
	msgbox gText_ivseller_Op 0x6
	release
	end

EventScript_ivseller_Thatsegg:
	msgbox gText_ivseller_Wtf 0x6
	release
	end


EventScript_ivseller_Giveivs:
	setvar 0x8005 0x0
	setvar 0x8006 0x1F @31
	special 0x10
	setvar 0x8005 0x1
	setvar 0x8006 0x1F @It might be redundant setting 8006 each time but idk how it works so i@ll do it anyway lol
	special 0x10
	setvar 0x8005 0x2
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x3
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x4
	setvar 0x8006 0x1F
	special 0x10
	setvar 0x8005 0x5
	setvar 0x8006 0x1F
	special 0x10
	return

.global EventScript_amuletcoin_Start
EventScript_amuletcoin_Start:
	textcolor 0x0
	checkflag 0x1010
	if 0x1 _goto EventScript_amuletcoin_Done
    lock 
    faceplayer 
	msgbox gText_amuletcoin_3 0x6
	msgbox gText_amuletcoin_4 0x6
	giveitem 0xBD 0x1 MSG_OBTAIN
	setflag 0x1010
	msgbox gText_amuletcoin_5 0x6
	release
	end

EventScript_amuletcoin_Done:
	msgbox gText_amuletcoin_5 MSG_FACE 
	release
	end

.global EventScript_coinstory_Start
EventScript_coinstory_Start:
	textcolor 0x0
	lock
	faceplayer
	msgbox gText_coinstory_6 0x6
	msgbox gText_coinstory_7 0x6
	msgbox gText_coinstory_8 0x6
	msgbox gText_coinstory_9 0x6
	msgbox gText_coinstory_10 0x6
	release
	end

EventScript_gamecornertms_End:
	release
	end
	


@damn this script was written when i was stupid af so it's veeerrry messy and i'm way too lazy to clean it up so rip 
.global EventScript_gamecornermons_Start
EventScript_gamecornermons_Start:
	lockall
	faceplayer
	msgbox gText_gamecornermons_1 0x5
	compare LASTRESULT 0x0
	if 0x1 _call EventScript_gamecornermons_Cancel
	showmoney 0x35 0x00 0x00
	goto FirstList 

FirstList: 
	setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_gamecornermons_Text1
	special 0x25
	setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_gamecornermons_Text2
	special 0x25
	setvar 0x8006 0x2 @3rd item
	loadpointer 0x0 gText_gamecornermons_Text3
	special 0x25
	setvar 0x8006 0x3 @4rd item
	loadpointer 0x0 gText_gamecornermons_Text4
	special 0x25
	setvar 0x8006 0x4 @5th item
	loadpointer 0x0 gText_gamecornermons_Text5
	special 0x25
	setvar 0x8006 0x5 @6th item
	loadpointer 0x0 gText_gamecornermons_Text6
	special 0x25
	setvar 0x8006 0x6 @7th item
	loadpointer 0x0 gText_gamecornermons_Text7
	special 0x25
	preparemsg gText_gamecornermons_Whichpkmn
	waitmsg
	multichoice 0x0 0x0 0x25 0x0 @0x24 is 7 options
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_gamecornermons_Dratini
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_gamecornermons_Larvitar
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_gamecornermons_Beldum
	compare LASTRESULT 0x3
	if 0x1 _goto EventScript_gamecornermons_Bagon
	compare LASTRESULT 0x4
	if 0x1 _goto EventScript_gamecornermons_Riolu
	compare LASTRESULT 0x5
	if 0x1 _goto EventScript_gamecornermons_Rotom
	compare LASTRESULT 0x6
	if 0x1 _goto EventScript_gamecornermons_ViewMore
	hidemoney 0x35 0x00
	release
	end

EventScript_gamecornermons_ViewMore:
	setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_gamecornermons2_Text1
	special 0x25
	setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_gamecornermons2_Text2
	special 0x25
	setvar 0x8006 0x2 @3rd item
	loadpointer 0x0 gText_gamecornermons2_Text3
	special 0x25
	setvar 0x8006 0x3 @4rd item
	loadpointer 0x0 gText_gamecornermons2_Text4
	special 0x25
	setvar 0x8006 0x4 @5th item
	loadpointer 0x0 gText_gamecornermons2_Text5
	special 0x25
	setvar 0x8006 0x5 @6th item
	loadpointer 0x0 gText_gamecornermons2_Text6
	special 0x25
	setvar 0x8006 0x6 @7th item
	loadpointer 0x0 gText_gamecornermons_Text7
	special 0x25
	preparemsg gText_gamecornermons2_Whichpkmn
	waitmsg
	multichoice 0x0 0x0 0x25 0x0 @0x24 is 7 options
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_gamecornermons2_Gible
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_gamecornermons2_Larvesta
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_gamecornermons2_Deino
	compare LASTRESULT 0x3
	if 0x1 _goto EventScript_gamecornermons2_Goomy
	compare LASTRESULT 0x4
	if 0x1 _goto EventScript_gamecornermons2_Jangmo
	compare LASTRESULT 0x5
	if 0x1 _goto EventScript_gamecornermons2_Dreepy
	compare LASTRESULT 0x6
	if 0x1 _goto EventScript_gamecornermons_ViewMore2
	goto FirstList 
	release
	end

EventScript_gamecornermons_ViewMore2:
	setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_gamecornermons3_Text1 @Honedge 
	special 0x25
	setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_gamecornermons3_Text2 @Toxel 
	special 0x25
	setvar 0x8006 0x2 @3rd item
	loadpointer 0x0 gText_gamecornermons3_Text4 @Exit 
	special 0x25
	multichoice 0x0 0x0 0x21 0x0 @0x22 is 3 options
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_gamecornermons2_Honedge
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_gamecornermons2_Toxel
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_gamecornermons_Cancelhide
	goto EventScript_gamecornermons_ViewMore
	release 
	end 

.global EventScript_gamecornermons_Start2
EventScript_gamecornermons_Start2:
	lockall
	faceplayer
	msgbox gText_gamecornermons_1 0x5
	compare LASTRESULT 0x0
	if 0x1 _call EventScript_gamecornermons_Cancel
	showmoney 0x35 0x00 0x00
	goto FirstList2 

FirstList2: 
	setvar 0x8000 0x2 
    setvar 0x8001 0x6 
    setvar 0x8004 0x0 
    preparemsg gText_gamecornermons_Whichpkmn
	waitmsg
    special 0x158
    waitstate 
    compare LASTRESULT 0x7F 
    if 0x1 _goto EventScript_gamecornermons_Cancelhide
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_gamecornermons_Dratini
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_gamecornermons_Larvitar
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_gamecornermons_Beldum
	compare LASTRESULT 0x3
	if 0x1 _goto EventScript_gamecornermons_Bagon
	compare LASTRESULT 0x4
	if 0x1 _goto EventScript_gamecornermons_Riolu
	compare LASTRESULT 0x5
	if 0x1 _goto EventScript_gamecornermons_Rotom
	compare LASTRESULT 0x6
	if 0x1 _goto EventScript_gamecornermons2_Gible 
    compare LASTRESULT 0x7
	if 0x1 _goto EventScript_gamecornermons2_Larvesta 
    compare LASTRESULT 0x8
    if 0x1 _goto EventScript_gamecornermons2_Deino
    compare LASTRESULT 0x9
    if 0x1 _goto EventScript_gamecornermons2_Goomy 
    compare LASTRESULT 0xA
    if 0x1 _goto EventScript_gamecornermons2_Jangmo
    compare LASTRESULT 0xB
	if 0x1 _goto EventScript_gamecornermons2_Dreepy
	compare LASTRESULT 0xC
	if 0x1 _goto EventScript_gamecornermons2_Honedge
	compare LASTRESULT 0xD
	if 0x1 _goto EventScript_gamecornermons2_Toxel
	compare LASTRESULT 0xE
	if 0x1 _goto EventScript_gamecornermons2_Frigibax
	hidemoney 0x35 0x00
	release
	end

EventScript_gamecornermons_Cancel:
    clearflag 0x90F 
    clearflag 0x913
	release
	end

EventScript_gamecornermons_Cancelhide:
	hidemoney 0x35 0x00
    goto EventScript_gamecornermons_Cancel

EventScript_gamecornermons_Shinyupgrade:
	msgbox gText_gamecornermons_Upgrade 0x5 @Ask for shiny upgrade
	compare LASTRESULT 0x1
	if 0x1 _call EventScript_gamecornermons_Doshiny
	return

EventScript_gamecornermons_Hiddenability:
	msgbox gText_gamecornermons_Haupgrade 0x5 @ask if they want hidden ability
	compare LASTRESULT 0x1
	if 0x1 _call EventScript_gamecornermons_Doha
	return

EventScript_gamecornermons_Doshiny:
	setflag 0x913
	return

EventScript_gamecornermons_Doha:
	setflag 0x90F
	return

EventScript_gamecornermons_Dratini:
	msgbox gText_gamecornermons_Text1 0x6
	msgbox gText_gamecornermons_Itllbe 0x6
	call EventScript_gamecornermons_Shinyupgrade
	call EventScript_gamecornermons_Hiddenability
	msgbox gText_gamecornermons_Text1 0x6
	msgbox gText_gamecornermons_Itllbe 0x6
	call EventScript_gamecornermons_Checkifcorrect
	call EventScript_gamecornermons_Checkpayment
	givepokemon 0x93 0x1E 0x0 0x0 0x0 0x0
	fanfare 0x13E
	msgbox gText_gamecornermons_Gotdratini 0x4
	goto EventScript_gamecornermons_Endofscript

EventScript_gamecornermons_Larvitar:
	msgbox gText_gamecornermons_Text2 0x6
	msgbox gText_gamecornermons_Itllbe 0x6
	call EventScript_gamecornermons_Shinyupgrade
	call EventScript_gamecornermons_Hiddenability
	msgbox gText_gamecornermons_Text2 0x6
	msgbox gText_gamecornermons_Itllbe 0x6
	call EventScript_gamecornermons_Checkifcorrect
	call EventScript_gamecornermons_Checkpayment
	givepokemon 0xF6 0x1E 0x0 0x0 0x0 0x0
	fanfare 0x13E
	msgbox gText_gamecornermons_Gotlarvitar 0x4
	goto EventScript_gamecornermons_Endofscript

EventScript_gamecornermons_Beldum:
	msgbox gText_gamecornermons_Text3 0x6
	msgbox gText_gamecornermons_Itllbe 0x6
	call EventScript_gamecornermons_Shinyupgrade
	call EventScript_gamecornermons_Hiddenability
	msgbox gText_gamecornermons_Text3 0x6
	msgbox gText_gamecornermons_Itllbe 0x6
	call EventScript_gamecornermons_Checkifcorrect
	call EventScript_gamecornermons_Checkpayment
	givepokemon 0x18E 0x1E 0x0 0x0 0x0 0x0
	fanfare 0x13E
	msgbox gText_gamecornermons_Gotbeldum 0x4
	goto EventScript_gamecornermons_Endofscript

EventScript_gamecornermons_Bagon:
	msgbox gText_gamecornermons_Text4 0x6
	msgbox gText_gamecornermons_Itllbe 0x6
	call EventScript_gamecornermons_Shinyupgrade
	call EventScript_gamecornermons_Hiddenability
	msgbox gText_gamecornermons_Text4 0x6
	msgbox gText_gamecornermons_Itllbe 0x6
	call EventScript_gamecornermons_Checkifcorrect
	call EventScript_gamecornermons_Checkpayment
	givepokemon 0x18B 0x1E 0x0 0x0 0x0 0x0
	fanfare 0x13E
	msgbox gText_gamecornermons_Gotbagon 0x4
	goto EventScript_gamecornermons_Endofscript

EventScript_gamecornermons_Riolu:
	msgbox gText_gamecornermons_Text5 0x6
	msgbox gText_gamecornermons_Itllbe 0x6
	call EventScript_gamecornermons_Shinyupgrade
	call EventScript_gamecornermons_Hiddenability
	msgbox gText_gamecornermons_Text5 0x6
	msgbox gText_gamecornermons_Itllbe 0x6
	call EventScript_gamecornermons_Checkifcorrect
	call EventScript_gamecornermons_Checkpayment
	givepokemon 0x1F4 0x1E 0x0 0x0 0x0 0x0
	fanfare 0x13E
	msgbox gText_gamecornermons_Gotriolu 0x4
	goto EventScript_gamecornermons_Endofscript

EventScript_gamecornermons_Rotom:
	msgbox gText_gamecornermons_Text6 0x6
	msgbox gText_gamecornermons_Itllberotom 0x6
	msgbox gText_gamecornermons_Isitok 0x5
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_gamecornermons_Cancelhide
	call EventScript_gamecornermons_Shinyupgrade @has no hidden ability
	msgbox gText_gamecornermons_Text6 0x6
	msgbox gText_gamecornermons_Itllberotom 0x6
	call EventScript_gamecornermons_Checkifcorrect
	call EventScript_gamecornermons_Checkpayment
	givepokemon 0x214 0x1E 0x0 0x0 0x0 0x0
	fanfare 0x13E
	msgbox gText_gamecornermons_Gotrotom 0x4
	goto EventScript_gamecornermons_Endofscript

EventScript_gamecornermons2_Gible:
	msgbox gText_gamecornermons2_Text1 0x6
	msgbox gText_gamecornermons_Itllbe 0x6
	call EventScript_gamecornermons_Shinyupgrade
	call EventScript_gamecornermons_Hiddenability
	msgbox gText_gamecornermons2_Text1 0x6
	msgbox gText_gamecornermons_Itllbe 0x6
	call EventScript_gamecornermons_Checkifcorrect
	call EventScript_gamecornermons_Checkpayment
	givepokemon 0x1F0 0x1E 0x0 0x0 0x0 0x0
	fanfare 0x13E
	msgbox gText_gamecornermons2_Gotgible 0x4
	goto EventScript_gamecornermons_Endofscript

EventScript_gamecornermons2_Larvesta:
	msgbox gText_gamecornermons2_Text2 0x6
	msgbox gText_gamecornermons_Itllbe 0x6
	call EventScript_gamecornermons_Shinyupgrade
	call EventScript_gamecornermons_Hiddenability
	msgbox gText_gamecornermons2_Text2 0x6
	msgbox gText_gamecornermons_Itllbe 0x6
	call EventScript_gamecornermons_Checkifcorrect
	call EventScript_gamecornermons_Checkpayment
	givepokemon 0x2B1 0x1E 0x0 0x0 0x0 0x0
	fanfare 0x13E
	msgbox gText_gamecornermons2_GotLarvesta 0x4
	goto EventScript_gamecornermons_Endofscript

EventScript_gamecornermons2_Deino:
	msgbox gText_gamecornermons2_Text3 0x6
	msgbox gText_gamecornermons_Itllbe 0x6
	call EventScript_gamecornermons_Shinyupgrade @has no hidden ability
	msgbox gText_gamecornermons2_Text3 0x6
	msgbox gText_gamecornermons_Itllbe 0x6
	call EventScript_gamecornermons_Checkifcorrect
	call EventScript_gamecornermons_Checkpayment
	givepokemon 0x2AE 0x1E 0x0 0x0 0x0 0x0
	fanfare 0x13E
	msgbox gText_gamecornermons2_GotDeino 0x4
	goto EventScript_gamecornermons_Endofscript

EventScript_gamecornermons2_Goomy:
	msgbox gText_gamecornermons2_Text4 0x6
	msgbox gText_gamecornermons_Itllbe 0x6
	call EventScript_gamecornermons_Shinyupgrade
	call EventScript_gamecornermons_Hiddenability
	msgbox gText_gamecornermons2_Text4 0x6
	msgbox gText_gamecornermons_Itllbe 0x6
	call EventScript_gamecornermons_Checkifcorrect
	call EventScript_gamecornermons_Checkpayment
	givepokemon 0x32C 0x1E 0x0 0x0 0x0 0x0
	fanfare 0x13E
	msgbox gText_gamecornermons2_GotGoomy 0x4
	goto EventScript_gamecornermons_Endofscript

EventScript_gamecornermons2_Jangmo:
	msgbox gText_gamecornermons2_Text5 0x6
	msgbox gText_gamecornermons_Itllbe 0x6
	call EventScript_gamecornermons_Shinyupgrade
	call EventScript_gamecornermons_Hiddenability
	msgbox gText_gamecornermons2_Text5 0x6
	msgbox gText_gamecornermons_Itllbe 0x6
	call EventScript_gamecornermons_Checkifcorrect
	call EventScript_gamecornermons_Checkpayment
	givepokemon 0x3E7 0x1E 0x0 0x0 0x0 0x0
	fanfare 0x13E
	msgbox gText_gamecornermons2_Gotjangmo 0x4
	goto EventScript_gamecornermons_Endofscript


EventScript_gamecornermons2_Dreepy:
	msgbox gText_gamecornermons2_Text6 0x6
	msgbox gText_gamecornermons_Itllbe 0x6
	call EventScript_gamecornermons_Shinyupgrade
	call EventScript_gamecornermons_Hiddenability
	msgbox gText_gamecornermons2_Text6 0x6
	msgbox gText_gamecornermons_Itllbe 0x6
	call EventScript_gamecornermons_Checkifcorrect
	call EventScript_gamecornermons_Checkpayment
	givepokemon SPECIES_DREEPY 0x1E 0x0 0x0 0x0 0x0
	fanfare 0x13E
	msgbox gText_gamecornermons2_GotDreepy 0x4
	goto EventScript_gamecornermons_Endofscript

EventScript_gamecornermons2_Honedge:
	msgbox gText_gamecornermons3_Text1 0x6
	msgbox gText_gamecornermons_Itllbe 0x6
	call EventScript_gamecornermons_Shinyupgrade
	msgbox gText_gamecornermons3_Text1 0x6
	msgbox gText_gamecornermons_Itllbe 0x6
	call EventScript_gamecornermons_Checkifcorrect
	call EventScript_gamecornermons_Checkpayment
	givepokemon SPECIES_HONEDGE 0x1E 0x0 0x0 0x0 0x0
	fanfare 0x13E
	msgbox gText_gamecornermons2_GotHonedge 0x4
	goto EventScript_gamecornermons_Endofscript

EventScript_gamecornermons2_Toxel:
	msgbox gText_gamecornermons3_Text2 0x6
	msgbox gText_gamecornermons_Itllbe 0x6
	call EventScript_gamecornermons_Shinyupgrade
	msgbox gText_gamecornermons3_Text2 0x6
	msgbox gText_gamecornermons_Itllbe 0x6
	call EventScript_gamecornermons_Checkifcorrect
	call EventScript_gamecornermons_Checkpayment
	givepokemon SPECIES_TOXEL 0x1E 0x0 0x0 0x0 0x0
	fanfare 0x13E
	msgbox gText_gamecornermons2_GotToxel 0x4
	goto EventScript_gamecornermons_Endofscript


EventScript_gamecornermons2_Frigibax:
	msgbox gText_gamecornermons3_Text3 0x6
	msgbox gText_gamecornermons_Itllbe 0x6
	call EventScript_gamecornermons_Shinyupgrade
	msgbox gText_gamecornermons3_Text3 0x6
	msgbox gText_gamecornermons_Itllbe 0x6
	call EventScript_gamecornermons_Checkifcorrect
	call EventScript_gamecornermons_Checkpayment
	givepokemon SPECIES_FRIGIBAX 0x1E 0x0 0x0 0x0 0x0
	fanfare 0x13E
	msgbox gText_gamecornermons2_GotFrigibax 0x4
	goto EventScript_gamecornermons_Endofscript

EventScript_gamecornermons_Hatext:
	msgbox gText_gamecornermons_Withha 0x6
	return

EventScript_gamecornermons_Shinyupgradetxt:
	msgbox gText_gamecornermons_Shinytxt 0x6
	return

EventScript_gamecornermons_Shinyrotomtxt:
	msgbox gText_gamecornermons_Rotomtxt 0x6
	return

EventScript_gamecornermons_Checkifcorrect:
	checkflag 0x90F
	if 0x1 _call EventScript_gamecornermons_Hatext
	checkflag 0x913
	if 0x1 _call EventScript_gamecornermons_Shinyupgradetxt
	msgbox gText_gamecornermons_Correct 0x5
	compare LASTRESULT 0x0
	if 0x1 _call EventScript_gamecornermons_Cancelhide
	return

EventScript_gamecornermons_Checkcorrectrotom:
	checkflag 0x913
	if 0x1 _call EventScript_gamecornermons_Shinyrotomtxt
	msgbox gText_gamecornermons_Correct 0x5
	compare LASTRESULT 0x0
	if 0x1 _call EventScript_gamecornermons_Cancelhide
	return

EventScript_gamecornermons_Endofscript:
	waitfanfare
	closeonkeypress
	@ msgbox gText_giveNickname MSG_YESNO 
	@ compare LASTRESULT YES 
	@ if equal _call givenickname 
	hidemoney 0x35 0x00
	clearflag 0x913
	clearflag 0x90F
	release
	end

EventScript_gamecornermons_Checkpayment:
	checkflag 0x913
	if 0x1 _call EventScript_gamecornermons_Checkshinypay
	checkmoney 0x186A0 0x00
	compare 0x800D 0x1
	if 0x0 _goto EventScript_gamecornermons_Nomoney
	msgbox gText_gamecornermons_Wait 0x6
	removemoney 0x186A0 0x00
	sound 0x58
	updatemoney 0x35 0x00 0x00
	msgbox gText_gamecornermons_4 0x6
	checksound
	return

EventScript_gamecornermons_Checkshinypay:
	checkmoney 0x30D40 0x00
	compare 0x800D 0x1
	if 0x0 _goto EventScript_gamecornermons_Nomoney
	msgbox gText_gamecornermons_Wait 0x6
	removemoney 0x186A0 0x00
	return

EventScript_gamecornermons_Nomoney:
    clearflag 0x90F 
    clearflag 0x913
	msgbox gText_gamecornermons_Poor 0x6
	hidemoney 0x35 0x00
	release
	end

.global EventScript_gardevoirite_Start
EventScript_gardevoirite_Start:
	lock
	faceplayer
	checkflag 0x98B
	if 0x1 _goto EventScript_gardevoirite_Done
	msgbox gText_gardevoirite_1 0x6
	giveitem ITEM_ALAKAZITE 0x1 MSG_OBTAIN @Gardevoirite
	setflag 0x98B
	release
	end

EventScript_gardevoirite_Done:
	msgbox gText_gardevoirite_2 0x6
	release
	end

.global EventScript_CeladonStones
EventScript_CeladonStones:
	special 0x187
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_gamecornertms_End
	lock
	faceplayer
	preparemsg gText_gamecornertms_Hello @"Hi, there!\nMay I help you?"
	waitmsg
	pokemart EventScript_stones_Values
	msgbox gText_gamecornertms_Comeagain MSG_KEEPOPEN @"Please come again!"
	release
	end

EventScript_stones_Values:
    .hword ITEM_FIRE_STONE
	.hword ITEM_THUNDER_STONE
	.hword ITEM_LEAF_STONE
	.hword ITEM_WATER_STONE
    .hword ITEM_SUN_STONE
    .hword ITEM_MOON_STONE
    .hword ITEM_PRISM_SCALE
    .hword ITEM_ICE_STONE
    .hword ITEM_LINK_CABLE
    .hword ITEM_DUSK_STONE
    .hword ITEM_DAWN_STONE
    .hword ITEM_SHINY_STONE
    .hword ITEM_KINGS_ROCK
    .hword ITEM_METAL_COAT 
	.hword ITEM_UPGRADE
    .hword 0x0

.global EventScript_CeladonTMs
EventScript_CeladonTMs:
	special 0x187
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_gamecornertms_End
	lock
	faceplayer
	preparemsg gText_gamecornertms_Hello @"Hi, there!\nMay I help you?"
	waitmsg
	pokemart EventScript_TMs_Values
	msgbox gText_gamecornertms_Comeagain MSG_KEEPOPEN @"Please come again!"
	release
	end

EventScript_TMs_Values:
    .hword ITEM_TM06
	.hword ITEM_TM15
    .hword ITEM_TM16
	.hword ITEM_TM17
    .hword ITEM_TM20
	.hword ITEM_TM33
	.hword 0x0

ReleaseEnd:
	release 
	end 

.global EventScript_CeladonBalls
EventScript_CeladonBalls:
	special 0x187
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_gamecornertms_End
	lock
	faceplayer
	preparemsg gText_gamecornertms_Hello @"Hi, there!\nMay I help you?"
	waitmsg
	pokemart EventScript_Balls_Values
	msgbox gText_gamecornertms_Comeagain MSG_KEEPOPEN @"Please come again!"
	release
	end

EventScript_Balls_Values:
    .hword ITEM_NET_BALL
	.hword ITEM_DIVE_BALL
	.hword ITEM_NEST_BALL
	.hword ITEM_REPEAT_BALL
    .hword ITEM_TIMER_BALL
    .hword ITEM_LUXURY_BALL
    .hword ITEM_QUICK_BALL
    .hword ITEM_DUSK_BALL
    .hword ITEM_LOVE_BALL
    .hword ITEM_FAST_BALL
    .hword ITEM_LEVEL_BALL
    .hword ITEM_HEAVY_BALL
    .hword ITEM_MOON_BALL 
    .hword 0x0

.global EventScript_erika_Start
EventScript_erika_Start:
	lock
	faceplayer
	checkflag 0x823
	if 0x1 _goto EventScript_erika_Defeated
	setflag 0x915
	special 0x0
	checkflag FLAG_HARDCORE_MODE
	if 0x1 _call SetTerrain
	trainerbattle1 0x1 0x1A1 0x0 gText_erika_EncounterText gText_erika_DefeatText EventScript_erika_WonPointer
	release
	end

SetTerrain:
	setvar VAR_TERRAIN 0x2
	return

EventScript_erika_Defeated:
	lock
	faceplayer
	checkitem ITEM_MEGA_RING 0x1
	compare 0x800D 0x1
	if 0x4 _goto EventScript_erika_Rematch
	msgbox gText_erika_TMInfomsg 0x6
	release
	end

EventScript_erika_WonPointer:
	msgbox gText_erika_Givetm 0x6
	giveitem 0x133 0x1 MSG_OBTAIN
	settrainerflag 0x84
	settrainerflag 0x85
	settrainerflag 0xA0
	settrainerflag 0x109
	settrainerflag 0x10A
	settrainerflag 0x10B
	settrainerflag 0x192
	setflag 0x823
	clearflag 0x915
	setvar 0x5128 0x1
	msgbox gText_erika_TMInfomsg 0x6
	release
	end

EventScript_erika_Rematch:
	lock
	faceplayer
	checkitem ITEM_MEDICINE 0x1 @check if player has medicine
	compare 0x800D 0x1
	if 0x4 _goto EventScript_erika_Thankyou
	checkflag 0x948
	if 0x1 _goto EventScript_erika_Farewell
	checkflag 0x947
	if 0x1 _goto EventScript_erika_BattleTwo
	checkflag 0x945
	if 0x1 _goto EventScript_erika_Lastmsg
	msgbox gText_erika_Helloagain 0x6
	msgbox gText_erika_Helloend 0x6
	setflag 0x945
	release
	end


EventScript_erika_Lastmsg:
	msgbox gText_erika_Helloend 0x6
	release
	end

EventScript_erika_Thankyou:
	msgbox gText_erika_Isit 0x5
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_erika_Cancel
	removeitem ITEM_MEDICINE 0x1
	msgbox gText_erika_Thankutext 0x6
	sound 0x1
	msgbox gText_erika_Nothing 0x6
	checksound
	setflag 0x947
	goto EventScript_erika_BattleTwo
	end 

EventScript_erika_BattleTwo:
	cry 0x2C 0x0
	waitcry
	msgbox gText_erika_Itworks MSG_YESNO 
	compare LASTRESULT NO
	if equal _goto EventScript_erika_Cancel
	msgbox gText_erika_StartBattle MSG_NORMAL 
	setflag 0x90E
	special 0x0
	setvar VAR_TERRAIN 0x2
	checkflag FLAG_HARDCORE_MODE
	if 0x1 _call SetRematchAura
	trainerbattle3 0x3 0x41 0x0 gText_Erika_DefeatText2
	msgbox gText_PostRematch MSG_NORMAL 
	giveitem ITEM_TM86 0x1 MSG_OBTAIN
	msgbox gText_erika_Info 0x6
	setflag 0x948 
	release
	end

SetRematchAura:
	setvar VAR_BATTLE_AURAS AURA_GRASS_TINTEDLENS_STRING
	return

EventScript_erika_Farewell:
	msgbox gText_erika_Info 0x6
	release
	end

EventScript_erika_Cancel:
	msgbox gText_erika_No 0x6
	release
	end

.global EventScript_checkerikasabrina_Start
EventScript_checkerikasabrina_Start:
	checkflag 0x823
	if 0x0 _goto EventScript_checkerikasabrina_Goback
	checkflag 0x825
	if 0x0 _goto EventScript_checkerikasabrina_Goback
	release
	end

EventScript_checkerikasabrina_Goback:
	textcolor 0x00
	applymovement 0xFF EventScript_checkerikasabrina_Stop
	waitmovement 0x0
	msgbox gText_checkerikasabrina_1 0x6
	applymovement 0xFF EventScript_checkerikasabrina_Playermoveback
	waitmovement 0x0
	release
	end

EventScript_checkerikasabrina_Stop:
.byte 0x5
.byte 0xFE


EventScript_checkerikasabrina_Playermoveback:
.byte 0x13
.byte 0xFE

.global EventScript_Celadon_Friskinfo
EventScript_Celadon_Friskinfo:
	lock 
	faceplayer 
	msgbox gText_Celadon_Frisk MSG_YESNO 
	compare LASTRESULT NO 
	if equal _goto ReleaseEnd 
	msgbox gText_Celadon_Frisk2 MSG_FACE 
	release 
	end 

.global EventScript_Celadon_FlappleTrainers1
EventScript_Celadon_FlappleTrainers1:
	lock
	checkflag 0x102E
	if 0x1 _goto FlappleTrainersEnd
	goto FlappleTrainersContinue
	end

FlappleTrainersContinue:
	applymovement 0x5 FaceDown
	waitmovement 0x0
	msgbox gText_CeladonFlappleTrainers_1 MSG_NORMAL
	applymovement 0x6 FaceUp 
	waitmovement 0x0
	msgbox gText_CeladonFlappleTrainers_1_1 MSG_NORMAL
	checkitem ITEM_MEGA_RING 0x1
	compare 0x800D 0x1
	if lessthan _goto Celadon_FlappleTrainersEnd
	sound 0x15
	applymovement 0x800F Exclaim
	waitmovement 0x0
	checksound
	applymovement 0x5 FaceYou
	applymovement 0x6 FaceYou
	waitmovement 0x0 
	msgbox gText_CeladonFlappleTrainers_3 MSG_YESNO
	compare LASTRESULT NO 
	if equal _goto Celadon_FlappleReject
	setflag 0x90E
	msgbox gText_CeladonFlappleTrainers_4 MSG_NORMAL
	special 0x0
	trainerbattle3 0x3 0x10 0x0 gText_flappletrainer1_loss
	msgbox gText_CeladonFlappleTrainers_5 MSG_NORMAL
	setflag 0x90E
	trainerbattle3 0x3 0x11 0x0 gText_flappletrainer2_loss
	msgbox gText_CeladonFlappleTrainers_6 MSG_NORMAL 
	giveitem ITEM_APPLITE 0x1 MSG_OBTAIN
	msgbox gText_CeladonFlappleTrainers_7 MSG_NORMAL
	msgbox gText_CeladonFlappleTrainers8 MSG_NORMAL
	giveitem ITEM_TM117 0x1 MSG_OBTAIN
	setflag 0x102E
	release
	end

.global EventScript_Celadon_FlappleTrainers2
EventScript_Celadon_FlappleTrainers2:
	lock
	checkflag 0x102E
	if 0x1 _goto FlappleTrainersEnd2
	goto FlappleTrainersContinue
	end

FlappleTrainersEnd:
	msgbox gText_CeladonFlappleTrainers_7 MSG_FACE
	release
	end 

FlappleTrainersEnd2:
	msgbox gText_CeladonFlappleTrainers_9 MSG_FACE
	release
	end

FaceYou:
	.byte face_player
	.byte end_m

FaceDown:
	.byte look_down
	.byte end_m

FaceUp:
	.byte look_up
	.byte end_m

FaceLeft:
	.byte look_left
	.byte end_m

Exclaim:
	.byte exclaim
	.byte end_m

Celadon_FlappleReject:
	msgbox gText_CeladonFlappleTrainers_Boring MSG_NORMAL
	goto Celadon_FlappleTrainersEnd

Celadon_FlappleTrainersEnd:
	applymovement 0x5 FaceLeft
	applymovement 0x6 FaceLeft 
	waitmovement 0x0
	release
	end

.global EventScript_ElectricSeedCarePackage
EventScript_ElectricSeedCarePackage:
	lockall
	textcolor 0x0
	checkflag 0x103F
	if 0x1 _call GiveElectricSeedCarePackage
	setvar 0x5122 0x1
	release
	end

GiveElectricSeedCarePackage:
	applymovement 0xFF EventScript_StopInPLace
	waitmovement 0x0
	giveitem ITEM_METAL_COAT 0xA MSG_OBTAIN
	checkflag FLAG_HARDCORE_MODE
	if 0x0 _call GiveElectric
	return

GiveElectric:
	msgbox gText_CarePackageFind MSG_NORMAL
	giveitem ITEM_ELECTRIC_SEED 0xA MSG_OBTAIN
	return

EventScript_StopInPLace:
	.byte lock_facing
	.byte 0xFE


.global EventScript_CeladonLucarioMan
EventScript_CeladonLucarioMan:
	lock
	faceplayer
	checkflag FLAG_GOT_LUCARIONITE
	if 0x0 _goto CheckLucarionite
	checkflag FLAG_GOT_LUCARIONITE
	if 0x1 _goto GiveLucarionitePostMsg
StartLucario:
	msgbox gText_Celadon_LucarioMan1 MSG_KEEPOPEN
	closeonkeypress
	applymovement 0x2 GoLookAtLucario
	waitmovement 0x0
	release
	end

CheckLucarionite:
	checkflag 0x824 @koga badge
	if 0x0 _goto StartLucario
	checkflag FLAG_FOLLOWER_IN_PROGRESS
	if 0x0 _goto StartLucario
	compare 0x5130 SPECIES_LUCARIO
	if notequal _goto StartLucario
	msgbox gText_Celadon_LucarioMan2 MSG_NORMAL
	setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_Physical_Lucario
	special 0x25
	setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_Special_Lucario
	special 0x25
    setvar 0x8006 0x2 @third item
    loadpointer 0x0 gText_gText_Mixed_Lucario
	special 0x25
    preparemsg gText_Celadon_LucarioMan2_1
    waitmsg
    multichoice 0x0 0x0 0x21 0x1
	compare LASTRESULT 0x0
	if equal _goto PickedPhysical
	compare LASTRESULT 0x1 
	if equal _goto PickedSpecial
	compare LASTRESULT 0x2
	if equal _goto PickedMixed
	end

PickedPhysical:
	msgbox gText_Lucario_PickedPhysical MSG_NORMAL
	goto SecondQuestionLucario

PickedSpecial:
	msgbox gText_Lucario_PickedSpecial MSG_NORMAL
	goto SecondQuestionLucario

PickedMixed:
	msgbox gText_Lucario_PickedMixed MSG_NORMAL
	goto SecondQuestionLucario

SecondQuestionLucario:
	msgbox gText_Lucario_Flaws MSG_NORMAL
	setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_PowerCreep
	special 0x25
	setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_4MSS
	special 0x25
    setvar 0x8006 0x2 @third item
    loadpointer 0x0 gText_SpeedTier
	special 0x25
    preparemsg gText_Lucario_Flaws2
    waitmsg
    multichoice 0x0 0x0 0x21 0x1
	compare LASTRESULT 0x0
	if equal _goto PickedPowerCreep
	compare LASTRESULT 0x1 
	if equal _goto Picked4MSS
	compare LASTRESULT 0x2
	if equal _goto PickedSpeedTier

PickedPowerCreep:
	msgbox gText_Lucario_PickedPowerCreep MSG_NORMAL
	goto ThirdQuestionLucario

Picked4MSS:
	msgbox gText_Lucario_4mss MSG_NORMAL
	goto ThirdQuestionLucario

PickedSpeedTier:
	msgbox gText_Lucario_SpeedTier MSG_NORMAL
	goto ThirdQuestionLucario

ThirdQuestionLucario:
	msgbox gText_Lucario_DoYouThink MSG_YESNO
	compare LASTRESULT YES
	if equal _goto GiveLucarionite
	compare LASTRESULT NO
	if equal _goto NeverMindLucario
	end

NeverMindLucario:
	msgbox gText_Lucario_NeverMind MSG_NORMAL
	release
	end

GiveLucarionite:
	msgbox gText_Lucario_Yeppers MSG_NORMAL
	giveitem ITEM_LUCARIONITE 0x1 MSG_OBTAIN
	setflag FLAG_GOT_LUCARIONITE 
GiveLucarionitePostMsg:
	msgbox gText_Lucario_amazingMega MSG_NORMAL
	release
	end

GoLookAtLucario:
	.byte look_left
	.byte end_m

.global EventScript_CeladonLucario
EventScript_CeladonLucario:
	lock
	faceplayer
	cry SPECIES_LUCARIO 0x0
	msgbox gText_Celadon_Lucario MSG_KEEPOPEN
	closeonkeypress
	pause 0x1
	waitcry
	applymovement 0x2 GoLookatFriend
	waitmovement 0x0
	release
	end

 GoLookatFriend:
	.byte look_right
	.byte end_m


.global EventScript_CeladonAzumarill
EventScript_CeladonAzumarill:
	lock
	faceplayer
	cry SPECIES_AZUMARILL 0x0
	msgbox gText_Celadon_Azumarill MSG_KEEPOPEN
	closeonkeypress
	pause 0x1
	waitcry
	release
	end

.global EventScript_CeladonEmpoleon
EventScript_CeladonEmpoleon:
	lock
	faceplayer
	cry SPECIES_EMPOLEON 0x0
	msgbox gText_Celadon_Empoleon MSG_KEEPOPEN
	closeonkeypress
	pause 0x1
	waitcry
	release
	end

.global EventScript_CeladonTogekiss
EventScript_CeladonTogekiss:
	lock
	faceplayer
	cry SPECIES_TOGEKISS 0x0
	msgbox gText_Celadon_Togekiss MSG_KEEPOPEN
	closeonkeypress
	pause 0x1
	waitcry
	release
	end

.global EventScript_SsAnneGarde
EventScript_SsAnneGarde:
	lock
	faceplayer
	cry SPECIES_GARDEVOIR 0x0
	msgbox gText_Vermillion_Gardevoir MSG_NORMAL
	pause 0x1
	waitcry
	release
	end

.global EventScript_SsAnne_GardeTrainer
EventScript_SsAnne_GardeTrainer:
	msgbox gText_Vermillion_GardevoirTrainer MSG_FACE
	release
	end

.global EventScript_SsAnne_ChesnTrainer
EventScript_SsAnne_ChesnTrainer:
	msgbox gText_Ssanne_ChesnTrainer MSG_FACE
	release
	end

.global EventScript_SsAnne_Chesnaught
EventScript_SsAnne_Chesnaught:
	lock
	faceplayer
	cry SPECIES_CHESNAUGHT 0x0
	msgbox gText_Ssanne_Chesnaught MSG_NORMAL
	pause 0x1
	waitcry
	release
	end

.global EventScript_SsAnne_MailGuy
EventScript_SsAnne_MailGuy:
	msgbox gText_Vermillion_MailGuy MSG_FACE
	release
	end

.global EventScript_VermilionCorv
EventScript_VermilionCorv:
	lock
	faceplayer
	cry SPECIES_CORVIKNIGHT 0x0
	msgbox gText_Vermillion_Corviknight MSG_NORMAL
	pause 0x1
	waitcry
	release
	end

.global EventScript_SsAnne_MailGuy2
EventScript_SsAnne_MailGuy2:
	msgbox gText_Vermillion_MailGuy2 MSG_FACE
	release
	end


.global EventScript_CeladonKangakshan
EventScript_CeladonKangakshan:
	lock
	faceplayer
	cry SPECIES_KANGASKHAN 0x0
	msgbox gText_Kangakshan MSG_KEEPOPEN
	closeonkeypress
	pause 0x1
	waitcry
	release
	end

