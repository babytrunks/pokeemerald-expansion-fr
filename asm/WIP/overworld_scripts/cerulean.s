.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ VAR_DAILY_EVENT2, 0x505C
.equ FLAG_HARDCORE_MODE, 0x1034
.equ VAR_WEATHER, 0x5118
.equ FLAG_MINIMAL_GRINDING_MODE, 0x1032
.equ FLAG_DEFEATED_MISTY_POSTGAME, 0x107B

.global EventScript_Cerulean_Haircut
EventScript_Cerulean_Haircut:
    setvar 0x8000 VAR_DAILY_EVENT2
    setvar 0x8001 0x0
    special2 LASTRESULT 0xA0
    compare LASTRESULT 0x0 
    if equal _goto AlreadyDid
    lock
    faceplayer 
    showmoney 0x0 0x0 0x0
    msgbox gText_Cerulean_Haircut1 MSG_YESNO
    compare LASTRESULT YES 
    if NO _goto Cancel 
    checkmoney 0x1F4 0x0
    compare LASTRESULT 0x1
    if 0x0 _goto NotEnoughMoney
    msgbox gText_Cerulean_Haircut2 MSG_FACE
    setvar 0x8003 0x0
    special 0x9F
    waitstate
    compare 0x8004 0x6
    if 0x4 _goto Cancel
    setvar 0x8000 VAR_DAILY_EVENT2
    setvar 0x8001 0x0
    special 0xA1
    showmoney 0x0 0x0 0x0
    setvar 0x8005 0x1E @add 30 to happiness 
    special 0x13 @change happiness 
    special 0x7C @buffer nickname 
    msgbox gText_Cerulean_Haircut3 MSG_KEEPOPEN
    closeonkeypress
    fadescreen 0x1
    sound 0x1
    checksound 
    fadescreen 0x0 
    msgbox gText_Cerulean_Haircut5 MSG_KEEPOPEN
    sound 0x58 
    removemoney 0x1F4 0x00
    updatemoney 0x00 0x00 0x00
    checksound
    closeonkeypress 
    msgbox gText_Cerulean_Haircut6 MSG_FACE 
    hidemoney 0x0 0x0 
    release 
    end 

Cancel:
    hidemoney 0x0 0x0 
    release 
    end 

AlreadyDid:
    msgbox gText_Cerulean_Haircut4 MSG_FACE
    release 
    end 

NotEnoughMoney:
    hidemoney 0x0 0x0 
    msgbox gText_Cerulean_Haircut7 MSG_FACE 
    release 
    end 

.global EventScript_Cerulean_HappinessCheck
EventScript_Cerulean_HappinessCheck:
    msgbox gText_Cerulean_Happiness1 MSG_FACE 
    setvar 0x8003 0x0
    special 0x9F
    waitstate
    compare 0x8004 0x6
    if 0x4 _goto CancelHappy 
    special2 LASTRESULT 0xD
    special 0x7C @buffer nickname 
    buffernumber 0x1 LASTRESULT @Buffer happiness to [buffer2]
    msgbox gText_Cerulean_Happiness2 MSG_FACE 
    release 
    end 

CancelHappy:
    release 
    end 


.global EventScript_misty_Start
EventScript_misty_Start:
	lock
	faceplayer
	checkflag 0x821
	if 0x1 _goto EventScript_misty_Defeated
	setflag 0x915
	special 0x0
	trainerbattle1 0x1 0x19F 0x0 gText_misty_EncounterText gText_misty_DefeatText EventScript_misty_WonPointer
	release
	end

EventScript_misty_Defeated:
	lock
	faceplayer
	checkitem ITEM_MEGA_RING 0x1
	compare 0x800D 0x1
	if 0x4 _goto EventScript_misty_Rematch
	msgbox gText_misty_TMInfomsg 0x6
	release
	end

EventScript_misty_WonPointer:
	msgbox gText_misty_Givetm 0x6
	giveitem 0x123 0x1 MSG_OBTAIN
	settrainerflag 0xEA
	settrainerflag 0x96
	setflag 0x821
	clearflag 0x915
	msgbox gText_misty_TMInfomsg 0x6
	release
	end

EventScript_misty_Rematch:
	checkflag 0x932
	if 0x1 _goto EventScript_misty_DefeatedRematch
	lock
	faceplayer
	msgbox gText_misty_Helloagain 0x5
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_misty_Cancel
	setflag 0x915
	setflag 0x90E
	special 0x0
	trainerbattle1 0x1 0x30 0x0 gText_misty_Battle gText_misty_Seconddefeat EventScript_misty_Rematchwon
	release
	end

EventScript_misty_Cancel:
	msgbox gText_misty_Comeback 0x6
	release
	end

EventScript_misty_Rematchwon:
	clearflag 0x915
	msgbox gText_misty_Won2text 0x6
	setflag 0x90F
	giveitem ITEM_GYARADOSITE 0x1 MSG_OBTAIN
	givepokemon SPECIES_FINIZEN 0x5 0x0 0x0 0x0 0x0
	clearflag 0x90F
	fanfare 0x13E
	msgbox gText_misty_Finizen 0x4
	waitfanfare
	closeonkeypress
	setflag 0x932
	msgbox gText_misty_Info 0x6
	release
	end

EventScript_misty_DefeatedRematch:
	checkitem ITEM_Z_POWER_RING 0x1
	compare LASTRESULT 0x1
	if greaterorequal _goto MistyPostGameRematch
	msgbox gText_misty_Info 0x6
	release
	end

MistyPostGameRematch:
	checkflag FLAG_DEFEATED_MISTY_POSTGAME
	if SET _goto MistyPostGameRematchDone
	msgbox gText_misty_PostGame1 MSG_YESNO
	compare LASTRESULT NO
	if equal _goto EventScript_misty_Cancel
	msgbox gText_misty_PostGame2 MSG_NORMAL
	@ setflag FLAG_SMALL_TRAINER_LEVELS
	trainerbattle3 0x3 0x20 0x0 gText_misty_ThirdDefeat
	msgbox gText_misty_PostGame3 MSG_NORMAL
	giveitem ITEM_WATERIUM_Z 0x1 MSG_OBTAIN
	msgbox gText_misty_PostGame4 MSG_NORMAL
	setvar 0x8000 MOVE_SHELLSMASH
    setvar 0x8001 MOVE_JAWLOCK
    setvar 0x8002 MOVE_AQUAFANG @moves 
    setvar 0x8003 MOVE_CRUNCH 
    setvar 0x8004 NATURE_JOLLY @nature 
    setvar 0x8005 0x0 
    setvar 0x8006 31
    setvar 0x8007 31
    setvar 0x8008 31
    setvar 0x8009 31
    setvar 0x800A 31
    setvar 0x800B 31
    givepokemon SPECIES_DREDNAW 100 0x0 0x0 0x1 0x0   
    fanfare 0x13E
    msgbox gText_Misty_Drednaw MSG_KEEPOPEN
    waitfanfare
    pause 0x3
    closeonkeypress
	setflag FLAG_DEFEATED_MISTY_POSTGAME
	release
	end

MistyPostGameRematchDone:
	msgbox gText_Misty_RematchDoneDone MSG_NORMAL
	release
	end

.global EventScript_newdaycare_Start
EventScript_newdaycare_Start:
	special 0x187
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_newdaycare_End
	special 0x188
	lock
	faceplayer
	special 0xB5
	special2 LASTRESULT 0xB6
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_newdaycare_Theeggshit
	checkflag 0x266
	if 0x1 _goto EventScript_newdaycare_Theeggshit
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_newdaycare_Singlemon
	compare LASTRESULT 0x3
	if 0x1 _goto EventScript_newdaycare_Telldoingfine
	msgbox gText_newdaycare_Intro MSG_KEEPOPEN @"I@m the DAY-CARE MAN.\pI help take..."
	release
	end


EventScript_newdaycare_End:
	release
	end

EventScript_newdaycare_Theeggshit:
	msgbox gText_newdaycare_Ahitsyou MSG_YESNO @"Ah, it@s you!\pWe were raising you..."
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_newdaycare_Getegg @0x8167DD1
	msgbox gText_newdaycare_Ireallywill MSG_YESNO @"I really will keep it.\nYou do wan..."
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_newdaycare_Getegg
	msgbox gText_newdaycare_Illkeepit MSG_KEEPOPEN @"Well then, I@ll keep it.\nThanks!"
	clearflag 0x266
	special 0xB7
	release
	end

	@---------------
EventScript_newdaycare_Singlemon:
	special 0xB5
	msgbox gText_newdaycare_Singlemonmsg MSG_KEEPOPEN @"Ah, it@s you! Good to see you.\nYo..."
	release
	end

	@---------------
EventScript_newdaycare_Telldoingfine:
	special 0xB5
	msgbox gText_newdaycare_Twodoingfine MSG_KEEPOPEN @"Ah, it@s you! Your [buffer1] and\n..."
	special 0xB9
	special 0x8D
	waitmsg
	waitkeypress
	release
	end

	@---------------
EventScript_newdaycare_Getegg:
	special2 LASTRESULT 0x83
	compare LASTRESULT 0x6
	if 0x5 _goto EventScript_newdaycare_Receiveegg
	msgbox gText_newdaycare_Noroom MSG_KEEPOPEN @"You have no room for it[.]\nCome b..."
	release
	end

	@---------------
EventScript_newdaycare_Receiveegg:
	textcolor 0x3
	preparemsg gText_newdaycare_Receiveeggmsg @"[player] received the EGG from\nth..."
	call EventScript_newdaycare_Copyvar
	fanfare 0x101
	waitfanfare
	waitkeypress
	msgbox gText_newdaycare_Takegoodcare MSG_KEEPOPEN @"Take good care of it."
	special 0xB8
	clearflag 0x266
	release
	end

	@---------------
EventScript_newdaycare_Copyvar:
	copyvar 0x8012 0x8013
	return

.global EventScript_NewThiefInfo
EventScript_NewThiefInfo:
	msgbox gText_Cerulean_NewThiefInfo MSG_FACE 
	release 
	end 

.global EventScript_RedShardInfo
EventScript_RedShardInfo:
	msgbox gText_Cerulean_RedShardInfo MSG_FACE 
	release 
	end 

.global EventScript_redogaryrival_Startmiddletile
EventScript_redogaryrival_Startmiddletile:
	lockall
	setvar 0x4001 0x1
	movesprite2 0x8 0x17 0x0
	goto EventScript_redogaryrival_Rivalbattle

.global EventScript_redogaryrival_Startlefttile
EventScript_redogaryrival_Startlefttile:
	lockall
	setvar 0x4001 0x0
	goto EventScript_redogaryrival_Rivalbattle

.global EventScript_redogaryrival_StartRightTile
EventScript_redogaryrival_StartRightTile:
	lockall
	setvar 0x4001 0x2
	movesprite2 0x8 0x18 0x0
	goto EventScript_redogaryrival_Rivalbattle

LookUp:
	.byte look_up
	.byte end_m
	
EventScript_redogaryrival_Rivalbattle:
	call PutFollowPkmnInBallBattle
	applymovement PLAYER LookUp
	waitmovement 0x0
	textcolor 0x0
	setvar 0x4054 0x2
	playsong 0x13B 0x0
	showsprite 0x8
	applymovement 0x8 EventScript_redogaryrival_Comedown
	waitmovement 0x0
	msgbox gText_redogaryrival_Startmsg MSG_KEEPOPEN @"[rival]: Yo! [player]!\pYou@re sti..."
	setvar LASTTALKED 0x8
	compare 0x4031 0x2
	if 0x1 _call EventScript_redogaryrival_Trainerbattle1
	compare 0x4031 0x1
	if 0x1 _call EventScript_redogaryrival_Trainerbattle2
	compare 0x4031 0x0
	if 0x1 _call EventScript_redogaryrival_Trianerbattle3
	setvar 0x8004 0xD
	setvar 0x8005 0x0
	special 0x173
	msgbox gText_redogaryrival_Billmsg MSG_KEEPOPEN @"[rival]: Hey, guess what?\pI went ..."
	closeonkeypress
	playsong 0x13C 0x0
	compare 0x4001 0x0
	if 0x1 _call EventScript_redogaryrival_Leftmovement
	compare 0x4001 0x1
	if 0x1 _call EventScript_redogaryrival_Leftmovement
	compare 0x4001 0x2
	if 0x1 _call EventScript_redogaryrival_Rightmovement
	msgbox gText_redogaryrival_Apresent MSG_KEEPOPEN @"Oh, yeah, right.\pI feel sorry for..."
	setvar 0x4052 0x1
	setflag 0x29B
	giveitem 0x16B 0x1 MSG_OBTAIN
	msgbox gText_redogaryrival_Chattygossip MSG_KEEPOPEN @"A chatty gossip like you[.]\nThat ..."
	closeonkeypress
	applymovement 0x8 EventScript_redogaryrival_Garyleave
	waitmovement 0x0
	fadedefault
	hidesprite 0x8
	call MakeFollowerVisible
	releaseall
	end

EventScript_redogaryrival_Trainerbattle1:
	trainerbattle3 0x3 0x14C 0x0 gText_redogaryrival_Uwonalready
	return

EventScript_redogaryrival_Trainerbattle2:
	trainerbattle3 0x3 0x14D 0x0 gText_redogaryrival_Uwonalready
	return

EventScript_redogaryrival_Trianerbattle3:
	trainerbattle3 0x3 0x14E 0x0 gText_redogaryrival_Uwonalready
	return

EventScript_redogaryrival_Leftmovement:
	applymovement 0xFF EventScript_redogaryrival_Moveplayer1
	applymovement 0x8 EventScript_redogaryrival_Movegary1
	waitmovement 0x0
	return

EventScript_redogaryrival_Rightmovement:
	applymovement 0xFF EventScript_redogaryrival_Moveplayer2
	applymovement 0x8 EventScript_redogaryrival_Movegary2
	waitmovement 0x0
	return

EventScript_redogaryrival_Comedown:
.byte 0x10
.byte 0x10
.byte 0x10
.byte 0x10
.byte 0x10
.byte 0xFE

EventScript_redogaryrival_Garyleave:
.byte 0x10
.byte 0x10
.byte 0x10
.byte 0x10
.byte 0x10
.byte 0x10
.byte 0x10
.byte 0xFE

EventScript_redogaryrival_Moveplayer1:
.byte 0x1C
.byte 0x1B
.byte 0x30
.byte 0x1C
.byte 0x2D
.byte 0xFE

EventScript_redogaryrival_Movegary1:
.byte 0x13
.byte 0x10
.byte 0x10
.byte 0x10
.byte 0x10
.byte 0x10
.byte 0x10
.byte 0x10
.byte 0x1C
.byte 0x1C
.byte 0x12
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0xFE

EventScript_redogaryrival_Moveplayer2:
.byte 0x1C
.byte 0x1B
.byte 0x2F
.byte 0x1C
.byte 0x2D
.byte 0xFE

EventScript_redogaryrival_Movegary2:
.byte 0x12
.byte 0x10
.byte 0x10
.byte 0x10
.byte 0x10
.byte 0x10
.byte 0x10
.byte 0x10
.byte 0x1C
.byte 0x1C
.byte 0x13
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0x11
.byte 0xFE


	@---------------
.global EventScript_trdigredo_StartTop
EventScript_trdigredo_StartTop:
	lockall
	setvar 0x4001 0x0
	applymovement 0x2 EventScript_trdigredo_FaceUp
	waitmovement 0x0
	applymovement 0xFF EventScript_trdigredo_FaceDown
	waitmovement 0x0
	goto EventScript_trdigredo_Start2

	@---------------
.global EventScript_trdigredo_Start2
EventScript_trdigredo_Start2:
	lock
	faceplayer
	textcolor 0x0
	msgbox gText_trdigredo_TRMessage1 MSG_KEEPOPEN @"Hey! Stay out!\nIt@s not your yard..."
	setvar LASTTALKED 0x2
	special 0x0
	trainerbattle3 0x3 0x163 0x0 gText_trdigredo_PostTRBattle
	setvar 0x407D 0x1
	goto EventScript_trdigredo_Start3

	@---------------
EventScript_trdigredo_Start3:
	msgbox gText_trdigredo_OkIgiveback MSG_KEEPOPEN @"[.]Okay.\nI@ll return the TM I sto..."
	giveitem ITEM_TM28 0x1 MSG_OBTAIN
	msgbox gText_trdigredo_ILeave MSG_KEEPOPEN @"I better get moving!\nBye!"
	closeonkeypress
	fadescreen 0x1
	hidesprite 0x2
	fadescreen 0x0
	checkflag 0x103F
	if 0x1 _call TRDigCarePackage
	setflag 0x23F
	release
	end

EventScript_trdigredo_FaceUp:
.byte 0x2E
.byte 0xFE

EventScript_trdigredo_FaceDown:
.byte 0x2D
.byte 0xFE

.global EventScript_trdigredo_StartBottom
EventScript_trdigredo_StartBottom:
	lockall
	setvar 0x4001 0x1
	applymovement 0x2 EventScript_trdigredo_FaceDown
	waitmovement 0x0
	applymovement 0xFF EventScript_trdigredo_FaceUp
	waitmovement 0x0
	goto EventScript_trdigredo_Start2

TRDigCarePackage:
	msgbox gText_CarePackageFind MSG_NORMAL
	giveitem ITEM_ABILITY_CAPSULE 0x99 MSG_OBTAIN
	giveitem ITEM_ABILITY_CAPSULE 0x99 MSG_OBTAIN
	giveitem ITEM_BIG_PEARL 0xA MSG_OBTAIN
	giveitem ITEM_CHARCOAL 0xA MSG_OBTAIN
	giveitem ITEM_HABAN_BERRY 0xA MSG_OBTAIN
	giveitem ITEM_PEARL 0xA MSG_OBTAIN
	giveitem ITEM_ULTRA_BALL 0xA MSG_OBTAIN
	checkflag FLAG_MINIMAL_GRINDING_MODE
	if 0x0 _call TRGiveVitamins
	checkflag FLAG_HARDCORE_MODE
	if 0x0 _call GiveAirBalloon
	return

TRGiveVitamins:
	giveitem ITEM_CLEVER_WING 0x32 MSG_OBTAIN
	giveitem ITEM_RESIST_WING 0x32 MSG_OBTAIN
	giveitem ITEM_ZINC 0xA MSG_OBTAIN
	giveitem ITEM_IRON 0xA MSG_OBTAIN
	return

GiveAirBalloon:
	giveitem ITEM_AIR_BALLOON 0xA MSG_OBTAIN
	giveitem ITEM_TERRAIN_EXTENDER 0xA MSG_OBTAIN
	return

.global EventScript_ceruleantms_Start
EventScript_ceruleantms_Start:
	lock
	faceplayer
	preparemsg gText_gamecornertms_Hello @"Hi, there!\nMay I help you?"
	waitmsg
	pokemart EventScript_Cerulean_Values
	msgbox gText_ceruleantms_Comeagain MSG_NORMAL
	release
	end

EventScript_Ceruleantms_End:
	release
	end

.align 1
EventScript_Cerulean_Values:
	.hword ITEM_TM21
	.hword ITEM_TM87
	.hword ITEM_TM88
	.hword ITEM_TM108
	.hword ITEM_TM111
    .hword 0x0


.global gMapScripts_CeruleanCityGym
gMapScripts_CeruleanCityGym:
    mapscript MAP_SCRIPT_ON_TRANSITION SetVar_CeruleanCityGym
	.byte MAP_SCRIPT_TERMIN

.equ FLAG_BADGE04_GET, 0x823
SetVar_CeruleanCityGym:
	checkflag FLAG_BADGE04_GET 
	if 0x1 _call SetWeatherDo
	end


SetWeatherDo:
	setweather 0x3
	doweather
	pause 0x5
	end