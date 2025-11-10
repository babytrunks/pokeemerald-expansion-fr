.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s" 

.equ FLAG_DOUBLE_WILD_BATTLE, 0x910
.equ FLAG_DISABLE_BAG, 0x915
.equ FLAG_TAG_BATTLE, 0x908
.equ VAR_PARTNER_BACKSPRITE, 0x5012
.equ VAR_PARTNER, 0x5011
.equ VAR_TOTEM, 0x5002
.equ VAR_BATTLE_AURAS, 0x5119
.equ AURA_STATUSMIST_STRING, 25 
.equ VAR_TERRAIN, 0x5000
.equ FLAG_HARDCORE_MODE, 0x1034
.equ FLAG_MINIMAL_GRINDING_MODE, 0x1032

.global EventScript_rockslide_Start
EventScript_rockslide_Start:
	lock
	faceplayer
	textcolor 0x0
	checkflag 0x1006
	if 0x1 _goto EventScript_rockslide_Done
	msgbox gText_rockslide_3 0x6
	msgbox gText_rockslide_4 0x5
	compare LASTRESULT 0x1
	if 0x1 _call EventScript_rockslide_Take
	msgbox gText_rockslide_6 0x6
	release
	end

EventScript_rockslide_Take:
	msgbox gText_rockslide_5 0x6
	giveitem ITEM_TM80 0x1 MSG_OBTAIN
	setflag 0x1006
	msgbox gText_rockslide_7 0x6
	release
	end

EventScript_rockslide_Done:
	msgbox gText_rockslide_7 0x6
	release
	end

.global EventScript_morty_Start
EventScript_morty_Start:
	lock
	faceplayer
	checkflag 0x1003
	if 0x1 _goto EventScript_morty_Done
	msgbox gText_morty_1 0x6
	msgbox gText_morty_3 0x5
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_morty_Battle
	msgbox gText_morty_4 0x6
	release
	end

EventScript_morty_Battle:
	setflag 0x915
	setflag 0x90E
	msgbox gText_morty_5 0x6
	special 0x0
    setflag 0x90E
	trainerbattle3 0x3 0x34 0x0 gText_morty_Defeat
	msgbox gText_morty_6 0x6
	giveitem 0x13E 0x1 MSG_OBTAIN
	msgbox gText_morty_8 0x6
	giveitem ITEM_SHED_SHELL 0x1 MSG_OBTAIN
	giveitem 0xB8 0x1 MSG_OBTAIN
	msgbox gText_morty_9 0x6
	setflag 0x1003
	release
	end

EventScript_morty_Done:
	lock
	faceplayer
	checkitem ITEM_MEGA_RING 0x1
	compare 0x800D 0x1
	if 0x4 _goto EventScript_morty_Givemega
	msgbox gText_morty_9 0x6
	release
	end


EventScript_morty_Givemega:
	lock
	faceplayer
	checkflag 0x1004
	if 0x1 _goto EventScript_morty_Donedone
	msgbox gText_morty_10 0x6
	bufferfirstpokemon 0x00
	msgbox gText_morty_11 0x6
	setvar 0x8003 0x0 @From party
	setvar 0x8004 0x0 @1
	special2 LASTRESULT 0xD
	buffernumber 0x0 LASTRESULT @Buffer happiness to [buffer1]
	compare LASTRESULT 255
	if 0x1 _goto EventScript_morty_MaxedHappiness
	msgbox gText_morty_13 0x6
	release
	end

EventScript_morty_MaxedHappiness:
	msgbox gText_morty_12 0x6
	giveitem ITEM_GENGARITE 0x1 MSG_OBTAIN
	setflag 0x1004
	release
	end

EventScript_morty_Donedone:
	lock
	faceplayer
	goto EventScript_mortyEndDone

EventScript_mortyEndDone:
	msgbox gText_morty_9 0x6
	release
	end




EventScript_morty_rematchreject:
	msgbox gText_morty_4 0x6
	release
	end

.global EventScript_amarowak_Start
EventScript_amarowak_Start:
	lockall
	textcolor 0x2
	msgbox gText_amarowak_Begone MSG_KEEPOPEN @"Be gone[.]\nIntruders[.]"
	checkitem 0x167 0x1
	compare 0x800D 0x1
	if 0x0 _goto EventScript_amarowak_Moveup
	setflag 0x90B
	setflag 0x90C
	checkflag FLAG_HARDCORE_MODE
	if 0x1 _call SetTerrain
	setvar 0x8000 MOVE_BONEMERANG @sets moveset to bonemerang, shadow bone, flare blitz thunderpunch
	setvar 0x8001 MOVE_SHADOWBONE
	setvar 0x8002 MOVE_FIREPUNCH
	setvar 0x8003 MOVE_THUNDERPUNCH
	setvar VAR_TOTEM 0xFFFF @raises all stats by 1
	setflag FLAG_DISABLE_BAG
	setflag FLAG_DONT_RANDOMIZE
	setwildbattle SPECIES_MAROWAK_A 0x3A ITEM_THICK_CLUB
	dowildbattle
	special2 LASTRESULT 0xB4
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_amarowak_Thespirit
	applymovement 0xFF EventScript_amarowak_Move
	waitmovement 0x0
	releaseall
	end

SetTerrain: 
	setvar VAR_BATTLE_AURAS AURA_STATUSMIST_STRING @misty terrain
	return

EventScript_amarowak_Moveup:
	applymovement 0xFF EventScript_amarowak_Move
	waitmovement 0x0
	releaseall
	end

EventScript_amarowak_Thespirit:
	clearflag 0x915
	preparemsg gText_amarowak_Ghostwas @"The ghost was the restless spirit\..."
	waitmsg
	checksound
	cry 0x69 0x0
	waitkeypress
	waitcry
	msgbox gText_amarowak_Calmdown MSG_KEEPOPEN @"The mother@s spirit was calmed.\pI..."
	giveitem ITEM_THICK_CLUB 0x1 MSG_OBTAIN
	setvar 0x4059 0x1
	releaseall
	end

EventScript_amarowak_Move:
.byte 0x11
.byte 0xFE


.global EventScript_AudinoSlayer
EventScript_AudinoSlayer:
	lock
	faceplayer
	showmoney 0x0 0x0 0x0
	checkflag FLAG_MINIMAL_GRINDING_MODE
	if 0x1 _goto MinGrindingSlayer
	msgbox gText_AudinoSlayer_1 MSG_YESNO
	compare LASTRESULT NO
	if equal _goto AudinoReject
	goto ChooseStat

MinGrindingSlayer:
	msgbox gText_AudinoSlayer_1_Hard MSG_YESNO
	compare LASTRESULT NO
	if equal _goto AudinoReject
	goto AudinoService
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
	setvar 0x8006 0x6 @sixth item
	loadpointer 0x0 gText_AudinoSlayer_EXP
	special 0x25
	preparemsg gText_AudinoSlayer_Choose
	waitmsg
	multichoice 0x0 0x0 0x25 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto HPService
	compare LASTRESULT 0x1
	if 0x1 _goto AtkService
	compare LASTRESULT 0x2
	if 0x1 _goto DefService
	compare LASTRESULT 0x3
	if 0x1 _goto SpAtkService
	compare LASTRESULT 0x4
	if 0x1 _goto SpDefService
	compare LASTRESULT 0x5
	if 0x1 _goto SpeedService
	compare LASTRESULT 0x6
	if 0x1 _goto AudinoService
	goto AudinoReject


AudinoService:
	showmoney 0x0 0x0 0x0
	checkmoney 0x2710 0x0
    compare LASTRESULT 0x1
    if 0x0 _goto NotEnoughMoneyAudino
	sound 0x58 
	removemoney 0x2710 0x00
    updatemoney 0x00 0x00 0x00
    msgbox gText_AudniSlayer_Wait MSG_KEEPOPEN
	checksound
	closeonkeypress
	msgbox gText_AudinoSlayer_2 MSG_NORMAL
	hidemoney 0x0 0x0
	setflag 0x90E
	trainerbattle3 0x3 0x1B 0x0 gText_AudinoSlayer_Defeat
	special 0x0
	msgbox gText_AudinoSlayer_5 MSG_NORMAL
	release
	end

EVServiceStuff:
	showmoney 0x0 0x0 0x0
	checkmoney 0x7D0 0x0
    compare LASTRESULT 0x1
	if 0x0 _goto NotEnoughMoneyEVs
	sound 0x58 
	removemoney 0x7D0 0x00
    updatemoney 0x00 0x00 0x00
    msgbox gText_AudniSlayer_Wait MSG_KEEPOPEN
	checksound
	closeonkeypress
	msgbox gText_AudinoSlayer_2 MSG_NORMAL
	hidemoney 0x0 0x0 
	return

AtkService:
	call EVServiceStuff
	trainerbattle3 0x3 0xA 0x0 gText_AudinoSlayer_Defeat
	special 0x0
	msgbox gText_AudinoSlayer_5 MSG_NORMAL
	release
	end

DefService:
	call EVServiceStuff
	trainerbattle3 0x3 0xB 0x0 gText_AudinoSlayer_Defeat
	special 0x0
	msgbox gText_AudinoSlayer_5 MSG_NORMAL
	release
	end

SpAtkService:
	call EVServiceStuff
	trainerbattle3 0x3 0xC 0x0 gText_AudinoSlayer_Defeat
	special 0x0
	msgbox gText_AudinoSlayer_5 MSG_NORMAL
	release
	end

SpDefService:
	call EVServiceStuff
	trainerbattle3 0x3 0xD 0x0 gText_AudinoSlayer_Defeat
	special 0x0
	msgbox gText_AudinoSlayer_5 MSG_NORMAL
	release
	end

SpeedService:
	call EVServiceStuff
	trainerbattle3 0x3 0x9 0x0 gText_AudinoSlayer_Defeat
	special 0x0
	msgbox gText_AudinoSlayer_5 MSG_NORMAL
	release
	end

HPService:
	call EVServiceStuff
	trainerbattle3 0x3 0x1B 0x0 gText_AudinoSlayer_Defeat
	special 0x0
	msgbox gText_AudinoSlayer_5 MSG_NORMAL
	release
	end

AudinoReject:
	msgbox gText_AudinoSlayer_3 MSG_NORMAL
	hidemoney 0x0 0x0 
	release
	end

NotEnoughMoneyAudino:
	msgbox gText_AudinoSlayer_4 MSG_NORMAL
	hidemoney 0x0 0x0 
	release
	end

NotEnoughMoneyEVs:
	msgbox gText_AudinoSlayer_EV_4 MSG_NORMAL
	hidemoney 0x0 0x0 
	release
	end

.global EventScript_LavenderFurret
EventScript_LavenderFurret:
	lock
	faceplayer
	cry SPECIES_FURRET 0x0
	msgbox gText_Lavender_Furret MSG_NORMAL
	pause 0x3
	waitcry
	release
	end


.global EventScript_LavenderGengar
EventScript_LavenderGengar:
	lock
	faceplayer
	cry SPECIES_GENGAR 0x0
	msgbox gText_Lavender_Gengar MSG_NORMAL
	pause 0x3
	waitcry
	release
	end
	