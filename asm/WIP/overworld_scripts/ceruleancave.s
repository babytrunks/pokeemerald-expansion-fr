.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ FLAG_TAG_BATTLE, 0x908
.equ VAR_PARTNER_BACKSPRITE, 0x5012 
.equ VAR_PARTNER, 0x5011 
.equ VAR_KUBFU_DAILY, 0x5110 

.equ SPECIES_KUBFU, 0x49F
.equ ITEM_BLACK_BELT, 207
.equ FLAG_HARDCORE_MODE, 0x1034
.equ VAR_TERRAIN, 0x5000
.equ VAR_BATTLE_AURAS, 0x5119
.equ VAR_BATTLE_TAILWIND_STRING, 5
.equ FIGHTING_SPIRIT, 0x1

.global gMapScripts_CeruleanCave
gMapScripts_CeruleanCave:
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScripts_CeruleanCave
    mapscript MAP_SCRIPT_ON_TRANSITION MapEntryScript_CeruleanCave
    .byte MAP_SCRIPT_TERMIN

LevelScripts_CeruleanCave:
    levelscript 0x5049, 0, LevelScript_CeruleanCave
    .hword MAP_SCRIPT_TERMIN

LevelScript_CeruleanCave:
	lock
	msgbox gText_ceruleancavelevelscript_1 0x4
	closeonkeypress
	msgbox gText_ceruleancavelevelscript_2 0x6
	sound 0x15
	applymovement 0xFF EventScript_ceruleancavelevelscript_Look
	applymovement 0xA EventScript_ceruleancavelevelscript_Look
    waitmovement 0x0 
	checksound
	applymovement 0xB EventScript_ceruleancavelevelscript_Comedown @B is ariana, A is brendan
	waitmovement 0x0
	sound 0xA
	applymovement 0xA EventScript_ceruleancavelevelscript_Jump
	waitmovement 0x0
	checksound
	msgbox gText_ceruleancavelevelscript_3 0x6
	applymovement 0xB EventScript_ceruleancavelevelscript_Movealil
	waitmovement 0x0
	msgbox gText_ceruleancavelevelscript_4 0x6
	applymovement 0xA EventScript_ceruleancavelevelscript_Lookatu
	waitmovement 0x0
	msgbox gText_ceruleancavelevelscript_5 0x6
	applymovement 0xA EventScript_ceruleancavelevelscript_Lookback
	waitmovement 0x0
	msgbox gText_ceruleancavelevelscript_6 0x6
	clearflag 0x977
    showsprite 0xC
    hidesprite 0xB
	setflag 0x980
	setvar 0x5049 0x1
	callasm SetFollowerVisible2
	end

EventScript_ceruleancavelevelscript_Look:
.byte 0x62
.byte 0xFE

EventScript_ceruleancavelevelscript_Look2:
.byte 0x1
.byte 0xFE

EventScript_ceruleancavelevelscript_Comedown:
.byte 0x10
.byte 0x10
.byte 0x10
.byte 0x10
.byte 0x10
.byte 0xFE

EventScript_ceruleancavelevelscript_Jump:
.byte 0x53
.byte 0xFE

EventScript_ceruleancavelevelscript_Movealil:
.byte 0x21
.byte 0x21
.byte 0xFE

EventScript_ceruleancavelevelscript_Lookatu:
.byte 0x4A
.byte 0xFE

EventScript_ceruleancavelevelscript_Lookback:
.byte 0x1
.byte 0xFE

MapEntryScript_CeruleanCave:
    release 
    end 

.global EventScript_brendanceruleancave_Start
EventScript_brendanceruleancave_Start:
	lock
	textcolor 0x0
	msgbox gText_brendanceruleancave_1 0x6
	cry 0x117 0x0
	waitcry
	applymovement 0x800F EventScript_brendanceruleancave_Look
	waitmovement 0x0
	msgbox gText_brendanceruleancave_2 0x6
	applymovement 0x800F EventScript_brendanceruleancave_Lookback
	waitmovement 0x0
	release
	end

EventScript_brendanceruleancave_Look:
.byte 0x4A
.byte 0xFE

EventScript_brendanceruleancave_Lookback:
.byte 0x1
.byte 0xFE

.global EventScript_arianaceruelancave_Start
EventScript_arianaceruelancave_Start:
	lock
	textcolor 0x1
	msgbox gText_arianaceruelancave_1 0x6
	cry 0x163 0x0
	waitcry
	applymovement 0x800F EventScript_arianaceruelancave_Look
	waitmovement 0x0
	msgbox gText_arianaceruelancave_2 0x6
	applymovement 0x800F EventScript_arianaceruelancave_Lookback
	waitmovement 0x0
	release
	end

EventScript_arianaceruelancave_Look:
.byte 0x4A
.byte 0xFE

EventScript_arianaceruelancave_Lookback:
.byte 0x0
.byte 0xFE

.global EventScript_ceruleangrunt1_Start
EventScript_ceruleangrunt1_Start:
	trainerbattle0 0x0 0x046 0x0 gText_ceruleangrunt1_EncounterText gText_ceruleangrunt1_DefeatText
	msgbox gText_ceruleangrunt1_AfterBattle 0x6
	end

.global EventScript_ceruleangrunt2_Start
EventScript_ceruleangrunt2_Start:
	trainerbattle0 0x0 0x047 0x0 gText_ceruleangrunt2_EncounterText gText_ceruleangrunt2_DefeatText
	msgbox gText_ceruleangrunt2_AfterBattle 0x6
	end

.global EventScript_ceruleangrunt3_Start
EventScript_ceruleangrunt3_Start:
	trainerbattle0 0x0 0x048 0x0 gText_ceruleangrunt3_EncounterText gText_ceruleangrunt3_DefeatText
	msgbox gText_ceruleangrunt3_AfterBattle 0x6
	end

.global EventScript_ceruleangrunt4_Start
EventScript_ceruleangrunt4_Start:
	trainerbattle0 0x0 0x049 0x0 gText_ceruleangrunt4_EncounterText gText_ceruleangrunt4_DefeatText
	msgbox gText_ceruleangrunt4_AfterBattle 0x6
	end

.global EventScript_ceruleanarcherarianaright_Start
EventScript_ceruleanarcherarianaright_Start:
	applymovement 0xFF EventScript_ceruleanarcherarianaright_Moveleft
	waitmovement 0x0
	goto EventScript_ceruleanarcherariana_Start
	end


EventScript_ceruleanarcherarianaright_Moveleft:
.byte 0x12
.byte 0xFE

.global EventScript_ceruleanarcherariana_Start
EventScript_ceruleanarcherariana_Start:
	lockall
	sound 0x8
	clearflag 0x200
	applymovement 0xFF EventScript_ceruleanarcherariana_Stop
	waitmovement 0x0
	call PutFollowPkmnInBallBattle
	showsprite 0xF @D is archer, E is Ariana
	checksound
	applymovement 0xF EventScript_ceruleanarcherariana_Downright
	waitmovement 0x0
	applymovement 0xFF EventScript_ceruleanarcherariana_Lookup
	waitmovement 0x0
	msgbox gText_ceruleanarcherariana_1 0x6
	sound 0x8
	clearflag 0x980
	showsprite 0x10
	checksound
	applymovement 0x10 EventScript_ceruleanarcherariana_Down
	waitmovement 0x0
	msgbox gText_ceruleanarcherariana_2 0x6
	applymovement 0xF EventScript_ceruleanarcherariana_Movealil
	waitmovement 0x0
	msgbox gText_ceruleanarcherariana_3 0x6
	applymovement 0xF EventScript_ceruleanarcherariana_Archerlook
	applymovement 0x10 EventScript_ceruleanarcherariana_Arianalook
	waitmovement 0x0
	msgbox gText_ceruleanarcherariana_4 0x6
	applymovement 0xF EventScript_ceruleanarcherariana_Stop
	applymovement 0x10 EventScript_ceruleanarcherariana_Stop
	msgbox gText_ceruleanarcherariana_5 0x6
	applymovement 0xF EventScript_ceruleanarcherariana_Movealil
	waitmovement 0x0
	msgbox gText_ceruleanarcherariana_6 0x4
	closeonkeypress
	msgbox gText_ceruleanarcherariana_7 0x6
	applymovement 0x10 EventScript_ceruleanarcherariana_Movealil
	waitmovement 0x0
	msgbox gText_ceruleanarcherariana_8 0x6
	applymovement 0x10 EventScript_ceruleanarcherariana_Movealil
	waitmovement 0x0
	applymovement 0xF EventScript_ceruleanarcherariana_Down @modify this depending on var
	waitmovement 0x0
	applymovement 0xF EventScript_ceruleanarcherariana_Archerlook @this one too
	waitmovement 0x0
	applymovement 0xFF EventScript_ceruleanarcherariana_Arianalook
	msgbox gText_ceruleanarcherariana_10 0x6
	setflag 0x200
	setflag 0x980
	setflag 0x915
	special 0x0 
	trainerbattle3 0x3 0x43 0x0 gText_ceruleanarcherariana_Archerloss
	setflag 0x915
	applymovement 0x10 EventScript_ceruleanarcherariana_Movealil @this one as well
	waitmovement 0x0
	applymovement 0xFF EventScript_ceruleanarcherariana_Lookup
	waitmovement 0x0
	msgbox gText_ceruleanarcherariana_11 0x6
	trainerbattle3 0x3 0x44 0x0 gText_ceruleanarcherariana_Arianaloss
	applymovement 0xFF EventScript_ceruleanarcherariana_Arianalook
	waitmovement 0x0
	msgbox gText_ceruleanarcherariana_12 0x6
	applymovement 0x10 EventScript_ceruleanarcherariana_Movealil
	waitmovement 0x0
	applymovement 0xFF EventScript_ceruleanarcherariana_Lookup
	waitmovement 0x0
	msgbox gText_ceruleanarcherariana_13 0x6
	giveitem ITEM_MAWILITE 0x1 MSG_OBTAIN
	applymovement 0xFF EventScript_ceruleanarcherariana_Arianalook
	waitmovement 0x0
	msgbox gText_ceruleanarcherariana_14 0x6
	giveitem ITEM_HOUNDOOMINITE 0x1 MSG_OBTAIN
	msgbox gText_ceruleanarcherariana_15 0x6
	applymovement 0xF EventScript_ceruleanarcherariana_Down2left2
	waitmovement 0x0
	sound 0x8
	setflag 0x200
	hidesprite 0xF
	checksound
	applymovement 0xFF EventScript_ceruleanarcherariana_Lookup
	waitmovement 0x0
	msgbox gText_ceruleanarcherariana_16 0x6
	applymovement 0x10 EventScript_ceruleanarcherariana_Right1
	waitmovement 0x0
	applymovement 0x10 EventScript_ceruleanarcherariana_Down2left2
	waitmovement 0x0
	applymovement 0xFF EventScript_ceruleanarcherariana_Stop
	waitmovement 0x0
	sound 0x8
	setflag 0x977
	setflag 0x981
	hidesprite 0x10
	checksound
	setvar 0x5051 0x1
	call MakeFollowerVisible
	release
	end

EventScript_ceruleanarcherariana_Downright:
.byte 0x10
.byte 0x13
.byte 0x0
.byte 0xFE

EventScript_ceruleanarcherariana_Down:
.byte 0x10
.byte 0xFE

EventScript_ceruleanarcherariana_Stop:
.byte 0x0
.byte 0xFE

EventScript_ceruleanarcherariana_Lookup:
.byte 0x1
.byte 0xFE

EventScript_ceruleanarcherariana_Movealil:
.byte 0x21
.byte 0xFE

EventScript_ceruleanarcherariana_Archerlook:
.byte 0x2
.byte 0xFE

EventScript_ceruleanarcherariana_Arianalook:
.byte 0x3
.byte 0xFE

EventScript_ceruleanarcherariana_Down2left2:
.byte 0x10
.byte 0x12
.byte 0x12
.byte 0xFE

EventScript_ceruleanarcherariana_Right1:
.byte 0x13
.byte 0x10
.byte 0xFE

.global EventScript_healstoptheboss_Start
EventScript_healstoptheboss_Start:
	lock
	faceplayer
	special 0x0
	fadescreen 0x1
	sound 0x1
	checksound
	fadescreen 0x0
	msgbox gText_healstoptheboss_1 0x6
	release
	end

.global EventScript_ceruleangiovanni_Left 
EventScript_ceruleangiovanni_Left:
	applymovement 0xFF WalkLeft 
	waitmovement 0x0 
    goto EventScript_ceruleangiovanni_Start
	end 

.global EventScript_ceruleangiovanni_Start
EventScript_ceruleangiovanni_Start:
	lockall
	fadeoutbgm 0x3
	applymovement 0xFF EventScript_ceruleangiovanni_Lookup
	waitmovement 0x0
	call PutFollowPkmnInBallBattle
	applymovement PLAYER LookUp
	waitmovement 0x0
	applymovement 0xF EventScript_ceruleangiovanni_Lookdown @F is giovanni
	waitmovement 0x0
	msgbox gText_ceruleangiovanni_1 0x6
	applymovement 0xF EventScript_ceruleangiovanni_Lookup
	waitmovement 0x0
	msgbox gText_ceruleangiovanni_2 0x6
	applymovement 0xF EventScript_ceruleangiovanni_Goup
	waitmovement 0x0
	playsong 0x156 0x0
	msgbox gText_ceruleangiovanni_3 0x6
	cry 0x96 0x2
	msgbox gText_ceruleangiovanni_4 0x6
	waitcry
	sound 0x36
	msgbox gText_ceruleangiovanni_5 0x6
	hidesprite 0x3 @mewtwo
	setflag 0x81
	clearflag 0x200
	showsprite 0x10 @pokeball
	checksound
	sound 0x31
	checksound
	msgbox gText_ceruleangiovanni_6 0x6
	sound 0x31
	checksound
	sound 0x10
	checksound
	fadeoutbgm 0x3
	msgbox gText_ceruleangiovanni_7 0x6
	applymovement 0xF EventScript_ceruleangiovanni_Lookdown
	msgbox gText_ceruleangiovanni_8 0x6
	msgbox gText_ceruleangiovanni_8_2 MSG_KEEPOPEN
	closeonkeypress 
	setflag 0x200 @pokeball and lance 
	sound 0xB3
	applymovement 0xFF Confused  
	applymovement 0xF Confused 
	waitmovement 0x0 
	checksound 
	fadescreen 0x1 
	sound 0x97
	checksound 
	showsprite 0x13
	fadescreen 0x0
	fadeinbgm 0x2 
	@ applymovement 0x13 Lance_Comeup 
	@ waitmovement 0x0 
	sound 0x15
	applymovement 0xF Exclamation 
	waitmovement 0x0 
	checksound 
	msgbox gText_ceruleangiovanni_8_3 MSG_NORMAL 
	msgbox gText_ceruleangiovanni_8_4 MSG_NORMAL
	applymovement 0x13 EventScript_ceruleangiovanni_Lookleft
	applymovement 0xFF EventScript_ceruleangiovanni_Lookright
	waitmovement 0x0 
	msgbox gText_ceruleangiovanni_8_5 MSG_NORMAL
	applymovement 0x13 EventScript_ceruleangiovanni_Lookup
	applymovement 0xFF EventScript_ceruleangiovanni_Lookup
	waitmovement 0x0 
	msgbox gText_ceruleangiovanni_8_6 MSG_NORMAL
	goto StartSelectPokemon
	end

LookUp:
	.byte look_up
	.byte end_m

StartSelectPokemon:
	special 0x27
	special 0xF5
	waitstate
    compare LASTRESULT NO
	if equal _goto StartSelectPokemon
	special 0x28
	setflag FLAG_TAG_BATTLE 
	checkflag FLAG_HARDCORE_MODE
	if 0x1 _call SetTerrain
	setvar VAR_PARTNER 0x27 @Lance partner 
	setvar VAR_PARTNER_BACKSPRITE 0x6 @Lance Backsprite 
	clearflag 0x81 @mewtwo
	special 0x0
	setflag 0x915 @disable bag
	setflag FLAG_TRANSFORM_BATTLE
	trainerbattle3 0x3 0x45 0x0 gText_ceruleangiovanni_Defeated
	fadeoutbgm 0x1
	msgbox gText_ceruleangiovanni_9 0x4
	closeonkeypress
	msgbox gText_ceruleangiovanni_Awaydialogue 0x6
	applymovement 0xF EventScript_ceruleangiovanni_Lookleft
	waitmovement 0x0
	msgbox gText_ceruleangiovanni_10 0x6
	applymovement 0xF EventScript_ceruleangiovanni_Lookright
	waitmovement 0x0
	msgbox gText_ceruleangiovanni_11 0x6
	clearflag 0x980
	clearflag 0x981
	showsprite 0x11
	showsprite 0x12
	applymovement 0x11 EventScript_ceruleangiovanni_Comeup @ariana
	applymovement 0x12 EventScript_ceruleangiovanni_Comeup @archer
	waitmovement 0x0
	msgbox gText_ceruleangiovanni_12 0x6
	sound 0x15
	applymovement 0xF EventScript_ceruleangiovanni_Surprised
	checksound
	waitmovement 0x0
	applymovement 0x13 EventScript_ceruleangiovanni_Lookdown
	waitmovement 0x0 
	applymovement 0xF EventScript_ceruleangiovanni_Lookdown
	msgbox gText_ceruleangiovanni_13 0x6
	applymovement 0x12 EventScript_ceruleangiovanni_Movealil
	waitmovement 0x0
	msgbox gText_ceruleangiovanni_14 0x6
	applymovement 0x11 EventScript_ceruleangiovanni_Movealil
	waitmovement 0x0
	msgbox gText_ceruleangiovanni_15 0x6
	msgbox gText_ceruleangiovanni_16 0x6
	msgbox gText_ceruleangiovanni_17 0x6
	sound 0xA
	applymovement 0x12 EventScript_ceruleangiovanni_Jumpup @jump
	checksound
	waitmovement 0x0
	msgbox gText_ceruleangiovanni_18 0x6
	applymovement 0x11 EventScript_ceruleangiovanni_Movealil
	waitmovement 0x0
	msgbox gText_ceruleangiovanni_19 0x6
	msgbox gText_ceruleangiovanni_20 0x6
	applymovement 0xF EventScript_ceruleangiovanni_Lookup
	waitmovement 0x0
	msgbox gText_ceruleangiovanni_21 0x6
	setvar 0x5053 0x1
	setvar 0x5054 0x1
	applymovement 0xF EventScript_ceruleangiovanni_Lookdown
	waitmovement 0x0
	msgbox gText_ceruleangiovanni_22 0x6
	fadeinbgm 0x1
	sound 0x35
	hidesprite 0x10 @hidepokeball, mewtwo reappear
	showsprite 0x3
	checksound
	applymovement 0xF EventScript_ceruleangiovanni_Lookup
	applymovement 0x13 EventScript_ceruleangiovanni_Lookup
	waitmovement 0x0
	sound 0x15
	applymovement 0xF EventScript_ceruleangiovanni_Surprised2
	applymovement 0xFF EventScript_ceruleangiovanni_Surprised2
	applymovement 0x11 EventScript_ceruleangiovanni_Surprised2
	applymovement 0x12 EventScript_ceruleangiovanni_Surprised2
	applymovement 0x13 EventScript_ceruleangiovanni_Surprised2
	checksound
	waitmovement 0x0
	setflag 0x980
	setflag 0x981
	setflag 0x982 @defeated giovanni
	clearflag 0x920 @this for the level script about to ensue
	clearflag 0x976 @same as above
	clearflag 0x977 @same as above
	msgbox gText_ceruleangiovanni_23 0x6
	cry 0x96 0x2
	msgbox gText_ceruleangiovanni_24 0x6
	waitcry
	setvar 0x8004 0x8
	setvar 0x8005 0x8
	setvar 0x8006 0x8
	setvar 0x8007 0x8
	special 0x136
	clearflag 0x200 
	pause 0x50
	warp 0x3 0x16 0x3 0x0 0x0
	end

SetTerrain:
	setvar VAR_TERRAIN 0x4
	return

EventScript_ceruleangiovanni_Lookup:
.byte 0x1
.byte 0xFE

EventScript_ceruleangiovanni_Lookdown:
.byte 0x0
.byte 0xFE

WalkLeft:
	.byte walk_left
	.byte look_up 
	.byte end_m 

EventScript_ceruleangiovanni_Goup:
.byte 0x11
.byte 0xFE

EventScript_ceruleangiovanni_Lookleft:
.byte 0x2
.byte 0xFE

EventScript_ceruleangiovanni_Lookright:
.byte 0x3
.byte 0xFE

EventScript_ceruleangiovanni_Comeup:
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0xFE

Confused: 
	.byte say_question
	.byte end_m 

Exclamation:
	.byte exclaim 
	.byte end_m 

Lance_Comeup:
	.byte walk_up 
	.byte walk_up 
	.byte walk_up 
	.byte walk_up 
	.byte walk_up 
	.byte walk_up
	.byte end_m  


EventScript_ceruleangiovanni_Surprised:
.byte 0x62
.byte 0xFE

EventScript_ceruleangiovanni_Surprised2:
.byte 0x65
.byte 0xFE

EventScript_ceruleangiovanni_Movealil:
.byte 0x22
.byte 0xFE

EventScript_ceruleangiovanni_Jumpup:
.byte 0x53
.byte 0xFE

.global EventScript_CeruleanCaveKubfuMapScript
EventScript_CeruleanCaveKubfuMapScript:
    mapscript MAP_SCRIPT_ON_TRANSITION HideKubfuIfNotReady
    .byte MAP_SCRIPT_TERMIN

HideKubfuIfNotReady:
	checkflag 0x982
	if 0x0 _goto HideKubfuTrainer
	clearflag 0x1025
	showsprite 0x12
	end 

HideKubfuTrainer:
	hidesprite 0x12
	setflag 0x1025
	end 

.global EventScript_e4check_Start
EventScript_e4check_Start:
	checkflag 0x82C @dont trigger if we havent got e4 yet badge yet
	if 0x1 _goto EventScript_e4check_Done
	applymovement 0xFF EventScript_e4check_Stop
	waitmovement 0x0
	cry 0x96 0x0 
	msgbox gText_e4check_1 0x6
	waitcry
	applymovement 0xFF EventScript_e4check_Goback
	waitmovement 0x0
	release
	end

EventScript_e4check_Done:
	release
	end

EventScript_e4check_Stop:
	.byte 0x1
	.byte 0xFE

EventScript_e4check_Goback:
	.byte 0x10
	.byte 0xFE


.global EventScript_KubfuMaster
EventScript_KubfuMaster:
	lock
	faceplayer
	checkflag 0x1023
	if equal _goto RepeatBattle
	msgbox gText_KubfuMaster_1 MSG_FACE
	msgbox gText_KubfuMaster_2 MSG_YESNO
	compare LASTRESULT NO
	if equal _goto RejectKubfu
	msgbox gText_KubfuMaster_PreFight MSG_NORMAL
	call KubfuBattle
	checkflag FLAG_HARDCORE_MODE
	if 0x1 _call KubfuAura1
	trainerbattle3 0x3 0x14 0x0 gText_KubfuMaster_FightLoss
	msgbox gText_KubfuMaster_4 MSG_NORMAL
	givepokemon SPECIES_KUBFU 0x1E ITEM_LIECHI_BERRY 0x0 0x0 0x0
	call KubfuBattleEnd
	goto EndKubfuFirst
	end 

KubfuBattle:
	setflag 0x915
	setflag 0x90E
	return 

KubfuAura1:
	setvar VAR_BATTLE_AURAS VAR_BATTLE_TAILWIND_STRING
	return

KubfuAura2:
	setvar VAR_BATTLE_AURAS FIGHTING_SPIRIT
	return

KubfuBattleEnd:
	fanfare 0x13E
	msgbox gText_ReceivedKubfu MSG_KEEPOPEN
	waitfanfare
	closeonkeypress
	setvar 0x8000 VAR_KUBFU_DAILY
    setvar 0x8001 0x0
    special 0xA1
	return

EndKubfuFirst:
	setflag 0x1023
	msgbox gText_KubfuMaster_GoodLuck MSG_NORMAL
	msgbox gText_KubfuMaster_DoneForToday MSG_NORMAL
	goto EndKubfu
	end 
	
RepeatBattle:
	setvar 0x8000 VAR_KUBFU_DAILY
    setvar 0x8001 0x0
    special2 LASTRESULT 0xA0
    compare LASTRESULT 0x0 
    if equal _goto AlreadyDid
	checkflag 0x1024
	if 0x1 _goto RepeatBattle2
	msgbox gText_KubfuMaster_DownAgain MSG_YESNO
	compare LASTRESULT NO
	if equal _goto RejectKubfu
	msgbox gText_KubfuMaster_PreFight MSG_NORMAL
	call KubfuBattle
	checkflag FLAG_HARDCORE_MODE
	if 0x1 _call KubfuAura2
	trainerbattle3 0x3 0x13 0x0 gText_KubfuMaster_FightLoss
	msgbox gText_KubfuMaster_5 MSG_NORMAL
	givepokemon SPECIES_KUBFU 0x1E ITEM_SALAC_BERRY 0x0 0x0 0x0
	call KubfuBattleEnd
	goto EndKubfuSecond
	end

RepeatBattle2: 
	msgbox gText_KubfuMaster_DownAgain2 MSG_YESNO
	compare LASTRESULT NO
	if equal _goto RejectKubfu
	msgbox gText_KubfuMaster_PreFight MSG_NORMAL
	call KubfuBattle
	random 0x2
	compare 0x800D 0x0 
	if 0x1 _goto Battle1
	compare 0x800D 0x1
	if 0x1 _goto Battle2
	end

Battle1:
	trainerbattle3 0x3 0x13 0x0 gText_KubfuMaster_FightLoss
	goto EndKubfuSecond
	end

Battle2:
	trainerbattle3 0x3 0x14 0x0 gText_KubfuMaster_FightLoss
	goto EndKubfuSecond
	end
	
GiveNuggets:
	giveitem ITEM_BIG_NUGGET 0x5 MSG_OBTAIN
	setvar 0x8000 VAR_KUBFU_DAILY
    setvar 0x8001 0x0
    special 0xA1
	return

EndKubfuSecond:
	msgbox gText_KubfuMaster_5_2 MSG_NORMAL
	call GiveNuggets
	setflag 0x1024
	msgbox gText_KubfuMaster_DoneForToday MSG_NORMAL
	goto EndKubfu
	end 

RejectKubfu:
	msgbox gText_KubfuMaster_3 MSG_NORMAL
	goto EndKubfu
	end

EndKubfu:
	applymovement 0x12 FaceUp
	waitmovement 0x0
	release
	end

AlreadyDid:
	msgbox gText_KubfuMaster_DoneForToday MSG_FACE
	goto EndKubfu
	end

FaceUp:
	.byte look_up 
	.byte end_m
