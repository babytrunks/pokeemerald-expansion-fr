.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ VAR_LEVEL, 0x1E
.equ VAR_DAILY_EVENT, 0x505A
.equ FLAG_HARDCORE_MODE, 0x1034
.equ FLAG_MINIMAL_GRINDING_MODE, 0x1032
.equ VAR_BATTLE_AURAS, 0x5119
.equ AURA_MAGMA_STORM_STRING, 26
.equ AURA_FIREPROOF_STRING, 9
.equ VAR_WEATHER, 0x5118

.global EventScript_CinnabarMay_Boss
EventScript_CinnabarMay_Boss:
    clearflag 0x200
    sound 0x9
    showsprite 0x05
    checksound
    applymovement 0xFF CinnabarMayStop
    waitmovement 0x0
	call SetFollowerToFollowScript
    textcolor 0x01
    msgbox gText_CinnabarMay1 MSG_NORMAL
    applymovement 0xFF MoveDown
    waitmovement 0x0
    applymovement 0x05 MayDown
    waitmovement 0x0
    msgbox gText_CinnabarMay2 MSG_NORMAL
    sound 0x15
    applymovement 0x05 Exclamation
    waitmovement 0x0 
    checksound
    msgbox gText_CinnabarMay3 MSG_NORMAL
    msgbox gText_CinnabarMay4 MSG_NORMAL
    setflag 0x200 
    setflag 0x915
	checkflag FLAG_HARDCORE_MODE
	if 0x1 _call SetAura
	setflag 0x926
    trainerbattle3 0x3 0x3D 0x0 gText_CinnabarMayDefeat 
    msgbox gText_CinnabarMay5 MSG_NORMAL
    giveitem ITEM_BLAZIKENITE 0x1 MSG_OBTAIN
    msgbox gText_CinnabarMay7 MSG_NORMAL
    applymovement 0x05 ComeDown
    waitmovement 0x0 
    setvar 0x5047 0x1
    hidesprite 0x05
    setflag 0x200
    setflag 0x998
	checkflag 0x103F
	if 0x1 _call GiveMayCarePackage
    release
    end

GiveMayCarePackage:
	giveitem ITEM_CLEANSE_TAG 0xA MSG_OBTAIN
	giveitem ITEM_SHELL_BELL 0xA MSG_OBTAIN
	return

SetAura:
	setvar VAR_BATTLE_AURAS AURA_MAGMA_STORM_STRING
	return

CinnabarMayStop:
    .byte 0x1
    .byte 0xFE

Exclamation:
    .byte 0x62
    .byte 0xFE 

MoveDown:
    .byte 0x10
	.byte walk_down
	.byte walk_up
    .byte 0x1
    .byte 0xFE

MayDown:
    .byte 0x10
    .byte 0xFE

ComeDown:
    .byte 0x13
    .byte 0x13
    .byte 0x13
    .byte 0x13
    .byte 0x13
    .byte 0x13
    .byte 0x13
    .byte 0x13
    .byte 0xFE    


.global EventScript_Cinnabar_WeatherRock
EventScript_Cinnabar_WeatherRock:
	special 0x187
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_dada_Snippet1
	checkflag 0x827
	if 0x1 _goto Mart2 
	lock
	faceplayer
	preparemsg gText_dada_MartGreetingMsg
	waitmsg
	pokemartdecor EventScript_dada_MartItemsList
	msgbox gText_dada_MartLeavingMsg 0x6
	release
	end

Mart2:
	lock
	faceplayer
	preparemsg gText_dada_MartGreetingMsg
	waitmsg
	pokemartdecor EventScript_dada_MartItems2List
	msgbox gText_dada_MartLeavingMsg 0x6
	release
	end

EventScript_dada_Snippet1:
	release
	end

.align 1
EventScript_dada_MartItemsList:
    .hword ITEM_DREAM_BALL 
    .hword ITEM_WHITE_HERB
	.hword ITEM_LUM_BERRY 
    .hword 0x0

.align 1
EventScript_dada_MartItems2List:
    .hword ITEM_DREAM_BALL 
    .hword ITEM_WHITE_HERB
	.hword ITEM_LUM_BERRY 
	.hword ITEM_BEAST_BALL
    .hword 0x0

.global EventScript_Cinnabar_Latis
EventScript_Cinnabar_Latis:
    checkflag 0x962
    if 0x0 _goto Start 
    checkflag 0x94B
    if 0x0 _goto Start 
    msgbox gText_CinnabarLatis5 MSG_FACE 
    release 
    end 

Start:
    lockall 
    faceplayer
    msgbox gText_CinnabarLatis1 MSG_FACE 
    setvar 0x8003 0x0
    special 0x9F
    waitstate
    compare 0x8004 0x6
    if 0x4 _goto CancelLati 
    special2 LASTRESULT 0x18 
    compare LASTRESULT 0x197 
    if 0x1 _goto Latias 
    compare LASTRESULT 0x198
    if 0x1 _goto Latios 
    msgbox gText_CinnabarLatis2 MSG_FACE 
    msgbox gText_CinnabarLatis3 MSG_FACE 
    release 
    end 

Latias: 
    checkflag 0x962
    if 0x1 _goto AlreadyGave
    call ExclamationStuff
    bufferpokemon 0x0 0x197
    msgbox gText_CinnabarLatis6 MSG_FACE 
    giveitem ITEM_SOUL_DEW 0x1 MSG_OBTAIN 
    giveitem ITEM_LATIASITE 0x1 MSG_OBTAIN 
    setflag 0x962 
    release 
    end 

Latios: 
    checkflag 0x94B 
    if 0x1 _goto AlreadyGave 
    call ExclamationStuff
    bufferpokemon 0x0 0x198
    msgbox gText_CinnabarLatis6 MSG_FACE 
    giveitem ITEM_SOUL_DEW 0x1 MSG_OBTAIN 
    giveitem ITEM_LATIOSITE 0x1 MSG_OBTAIN 
    setflag 0x94B
    release 
    end 

ExclamationStuff:
    msgbox gText_CinnabarLatis2 MSG_FACE 
    applymovement 0x800F ExclamationMark
    sound 0x15 
    checksound 
    waitmovement 0x0 
    return 

CancelLati:
    release 
    end 

AlreadyGave:
    msgbox gText_CinnabarLatis4 MSG_FACE 
    release 
    end 

ExclamationMark:
    .byte 0x62
    .byte 0xFE 


.global EventScript_blaine_Start
EventScript_blaine_Start:
	lock
	faceplayer
	checkflag 0x826
	if 0x1 _goto EventScript_blaine_Defeated
	setflag 0x915
	special 0x0
	checkflag FLAG_HARDCORE_MODE
	if 0x1 _call SetWeather
    trainerbattle1 0x1 0x1A3 0x0 gText_blaine_EncounterText gText_blaine_DefeatText EventScript_blaine_WonPointer
	release
	end

SetWeather:
	setvar VAR_WEATHER 0x5
	return

EventScript_blaine_Defeated:
	lock
	faceplayer
	checkflag 0x96F
	if 0x1 _goto EventScript_blaine_Done
	checkflag FLAG_MINIMAL_GRINDING_MODE
	if 0x1 _goto Blaine_defeated_Hardcore
	msgbox gText_blaine_Perfectpokemon 0x6
	bufferfirstpokemon 0x00
	msgbox gText_blaine_Thepokemon 0x6
	setvar 0x8003 0x0 @From party
	setvar 0x8004 0x0 @1st Pok�mon
	setvar 0x8005 0x4 @check speed EVs
	special2 LASTRESULT 0x7
	buffernumber 0x0 LASTRESULT @Buffer spa EVs to [buffer1]
	compare LASTRESULT 150
	if 0x4 _goto EventScript_blaine_Veryfast
	msgbox gText_blaine_Notquite 0x6
	release
	end

Blaine_defeated_Hardcore:
	msgbox gText_blaine_Perfectpokemon2 0x6
	bufferfirstpokemon 0x00
	msgbox gText_blaine_Thepokemon 0x6
	setvar 0x8003 0x0 @From party
	setvar 0x8004 0x0 @1st Pok�mon
	callasm CheckIfBlaineApproves
	compare LASTRESULT 0x1
	if equal _goto EventScript_blaine_Veryfast2
	msgbox gText_blaine_Notquite 0x6
	release
	end

EventScript_blaine_WonPointer:
	msgbox gText_blaine_TMInfomsg 0x6
	giveitem 0x146 0x1 MSG_OBTAIN @fire blast
	settrainerflag 0xB1
	settrainerflag 0xB2
	settrainerflag 0xB3
	settrainerflag 0xB4
	settrainerflag 0xD5
	settrainerflag 0xD6
	settrainerflag 0xD7
	setflag 0x826
	clearflag 0x915
	msgbox gText_blaine_Givetm 0x6
	checkflag 0x103F
	if 0x1 _call BlaineGiveCarePackage
	checkflag FLAG_HARDCORE_MODE
	if 0x1 _goto blaine_WonPointer_hardcoreend
	msgbox gText_blaine_Helloagain 0x6
	msgbox gText_blaine_Perfectpokemon 0x6
	release
	end

BlaineGiveCarePackage: 
	giveitem ITEM_LIFE_ORB 0xA MSG_OBTAIN
	giveitem ITEM_POWER_HERB 0xA MSG_OBTAIN
	return

blaine_WonPointer_hardcoreend:
	msgbox gText_blaine_Helloagain2 0x6
	msgbox gText_blaine_Perfectpokemon2 0x6
	release
	end

EventScript_blaine_Done:
	msgbox gText_blaine_Donemsg 0x6
	release
	end

EventScript_blaine_Veryfast:
	msgbox gText_blaine_Perfect 0x6
	giveitem ITEM_CHARIZARDITE_Y 0x1 MSG_OBTAIN 
	msgbox gText_blaine_Charmmsg 0x6
	giveitem ITEM_CHOICE_SPECS 0x1 MSG_OBTAIN 
	setflag 0x96F
	release
	end

EventScript_blaine_Veryfast2:
	checkflag FLAG_HARDCORE_MODE
	if 0x0 _goto EventScript_blaine_Veryfast
	msgbox gText_blaine_Perfect 0x6
	giveitem ITEM_CHARIZARDITE_X 0x1 MSG_OBTAIN 
	msgbox gText_blaine_Charmmsg 0x6
	giveitem ITEM_CHOICE_SPECS 0x1 MSG_OBTAIN 
	setflag 0x96F
	release
	end

.global EventScript_jasmine_Start
EventScript_jasmine_Start:
	lock
	faceplayer
	checkflag 0x96D
	if 0x1 _goto EventScript_jasmine_Done
	textcolor 0x1
	msgbox gText_jasmine_1 0x6
	msgbox gText_jasmine_2 0x6
	msgbox gText_jasmine_3 0x5
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_jasmine_Battle
	release 
	end

EventScript_jasmine_Battle:
	msgbox gText_jasmine_4 0x6
	setflag 0x915
	setflag 0x90E
	special 0x0
	checkflag FLAG_HARDCORE_MODE
	if 0x1 _call SetAuraJasmine
	random 0x3
	compare 0x800D 0x0
	if 0x1 _goto EventScript_jasmine_Option1
	compare 0x800D 0x1
	if 0x1 _goto EventScript_jasmine_Option2
	compare 0x800D 0x2
	if 0x1 _goto EventScript_jasmine_Option3
	end

SetAuraJasmine:
	setvar VAR_BATTLE_AURAS AURA_FIREPROOF_STRING
	return

EventScript_jasmine_Option1:
	trainerbattle3 0x3 0x3E 0x0 gText_jasmine_Defeat
	goto EventScript_jasmine_Endbattle

EventScript_jasmine_Option2:
	trainerbattle3 0x3 0x3F 0x0 gText_jasmine_Defeat
	goto EventScript_jasmine_Endbattle

EventScript_jasmine_Option3:
	trainerbattle3 0x3 0x40 0x0 gText_jasmine_Defeat
	goto EventScript_jasmine_Endbattle

EventScript_jasmine_Endbattle:
	msgbox gText_jasmine_6 0x6
	giveitem ITEM_AGGRONITE 0x1 MSG_OBTAIN
	msgbox gText_jasmine_7 0x6
	giveitem ITEM_CHOICE_BAND 0x1 MSG_OBTAIN
	msgbox gText_jasmine_Take 0x6
	setflag 0x96D
	release
	end


EventScript_jasmine_Done:
	checkflag 0x96E
	if 0x1 _goto EventScript_jasmine_Donedone
	checkflag FLAG_MINIMAL_GRINDING_MODE
	if 0x1 _goto Jasmine_Done_hardcore 
	msgbox gText_jasmine_Take 0x6
	bufferfirstpokemon 0x00
	msgbox gText_jasmine_Firstmon 0x6
	setvar 0x8003 0x0 @From party
	setvar 0x8004 0x0 @1st Pokemon
	setvar 0x8005 0x2
	special2 LASTRESULT 0x7
	buffernumber 0x0 LASTRESULT @Buffer def EVs to [buffer1]
	compare LASTRESULT 150
	if 0x4 _goto EventScript_jasmine_HighDef
	msgbox gText_jasmine_8 0x6
	release
	end

Jasmine_Done_hardcore:
	msgbox gText_jasmine_Take 0x6
	bufferfirstpokemon 0x00
	msgbox gText_jasmine_Firstmon 0x6
	setvar 0x8003 0x0 @From party
	setvar 0x8004 0x0 @1st Pokemon
	callasm CheckIfJasmineApproves
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_jasmine_HighDef
	msgbox gText_jasmine_8 0x6
	release
	end

EventScript_jasmine_HighDef:
	msgbox gText_jasmine_9 0x6
	giveitem ITEM_ASSAULT_VEST 0x1 MSG_OBTAIN
    giveitem ITEM_STEELIXITE 0x1 MSG_OBTAIN 
	setflag 0x96E
	release
	end

EventScript_jasmine_Donedone:
	@ checkitem ITEM_TRI_PASS 0x1
	@ compare 0x800D 0x1
	@ if 0x4 _goto EventScript_jasmine_RematchAgain
	msgbox gText_jasmine_10 0x6
	release
	end

DoneMsg2:
	lock
    faceplayer 
	msgbox gText_TwoIsland_SteelBeam1 MSG_YESNO
    compare LASTRESULT YES 
    if NO _goto CancelSteel
    setvar 0x8005 0x88
    special 0x18D
    waitstate
    compare LASTRESULT 0x0
    if 0x1 _goto CancelSteel
    msgbox gText_TwoIsland_SteelBeam2 MSG_FACE 
    release 
	end

CancelSteel:
    msgbox gText_TwoIsland_SteelBeam3 MSG_FACE 
    release 
    end 
	
EventScript_jasmine_RematchAgain:
	checkflag 0x1021
	if 0x1 _goto DoneMsg2
	msgbox gText_jasminere_1 MSG_YESNO
	compare LASTRESULT YES
	if equal _goto jasmine_RematchStart
	release
	end

jasmine_RematchStart:
	trainerbattle3 0x3 0x1D 0x0 gText_jasmine_Defeat
	msgbox gText_jasminere_2 MSG_NORMAL
	giveitem ITEM_STEELIUM_Z 0x1 MSG_OBTAIN
	msgbox gText_jasminere_3 MSG_NORMAL
	setflag 0x1021
	release
	end

.global EventScript_metatutor_Start2
EventScript_metatutor_Start2:
	lock
	faceplayer
	msgbox gText_metatutor_1 0x5
	compare LASTRESULT 0x0
	if 0x1 _call EventScript_metatutor_Cancel
	showmoney 0x35 0x00 0x00
	goto FirstList2

FirstList2: 
	setvar 0x8000 0x4
	setvar 0x8001 0x6 
	setvar 0x8004 0x0 
	preparemsg gText_metatutor_Msg
	waitmsg
	special 0x158
	waitstate 
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_metatutor_Firstoption
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_metatutor_Secondoption
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_metatutor_Thirdoption
	compare LASTRESULT 0x3
	if 0x1 _goto EventScript_metatutor_Fourthoption
	compare LASTRESULT 0x4
	if 0x1 _goto EventScript_metatutor_Fifthoption
	compare LASTRESULT 0x5
	if 0x1 _goto EventScript_metatutor_Sixthoption
	compare LASTRESULT 0x6
	if 0x1 _goto EventScript_metatutor_PhantomForce
	compare LASTRESULT 0x7
	if 0x1 _goto EventScript_metatutor_FlareBlitz
	compare LASTRESULT 0x8
	if 0x1 _goto EventScript_metatutor_StoredPower
	compare LASTRESULT 0x9
	if 0x1 _goto EventScript_metatutor_GunkShot
	compare LASTRESULT 0xA 
	if 0x1 _goto EventScript_metatutor_Tailwind
	compare LASTRESULT 0xB
	if 0x1 _goto EventScript_metatutor_Megahorn
	hidemoney 0x35 0x00
	release
	end


EventScript_metatutor_Teach:
	special 0x18D
	waitstate
	lock
	faceplayer
	return

EventScript_metatutor_Cancel:
	release
	end

EventScript_metatutor_CancelHide:
	hidemoney 0x35 0x00
	goto EventScript_metatutor_Cancel

EventScript_metatutor_Checkpayment:
	checkmoney 0x2710 0x00
	compare 0x800D 0x1
	if 0x0 _goto EventScript_metatutor_Nomoney
	return

EventScript_metatutor_Firstoption:
	setvar 0x8005 0x67
	call EventScript_metatutor_Checkpayment
	goto EventScript_metatutor_Endofscript

EventScript_metatutor_PhantomForce:
	setvar 0x8005 0x71
	call EventScript_metatutor_Checkpayment
	goto EventScript_metatutor_Endofscript

EventScript_metatutor_FlareBlitz:
	setvar 0x8005 0x79
	call EventScript_metatutor_Checkpayment
	goto EventScript_metatutor_Endofscript

EventScript_metatutor_StoredPower:
	setvar 0x8005 0x61
	call EventScript_metatutor_Checkpayment
	goto EventScript_metatutor_Endofscript

EventScript_metatutor_GunkShot:
	setvar 0x8005 0x30
	call EventScript_metatutor_Checkpayment
	goto EventScript_metatutor_Endofscript

EventScript_metatutor_Tailwind:
	setvar 0x8005 0x1C
	call EventScript_metatutor_Checkpayment
	goto EventScript_metatutor_Endofscript

EventScript_metatutor_Megahorn:
	setvar 0x8005 0x7D
	call EventScript_metatutor_Checkpayment
	goto EventScript_metatutor_Endofscript

EventScript_metatutor_Secondoption:
	setvar 0x8005 0x32
	call EventScript_metatutor_Checkpayment
	goto EventScript_metatutor_Endofscript

EventScript_metatutor_Thirdoption:
	setvar 0x8005 0x7A
	call EventScript_metatutor_Checkpayment
	goto EventScript_metatutor_Endofscript

EventScript_metatutor_Fourthoption:
	setvar 0x8005 0x7E
	call EventScript_metatutor_Checkpayment
	goto EventScript_metatutor_Endofscript

EventScript_metatutor_Fifthoption:
	setvar 0x8005 0x6D
	call EventScript_metatutor_Checkpayment
	goto EventScript_metatutor_Endofscript

EventScript_metatutor_Sixthoption:
	setvar 0x8005 0x69
	call EventScript_metatutor_Checkpayment
	goto EventScript_metatutor_Endofscript

EventScript_metatutor_Nomoney:
	msgbox gText_metatutor_Poor 0x6
	hidemoney 0x35 0x00
	release
	end

EventScript_metatutor_Endofscript:
	hidemoney 0x35 0x00
	msgbox gText_metatutor_3 0x6
	call EventScript_metatutor_Teach
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_metatutor_Cancel
	showmoney 0x35 0x00 0x00
	msgbox gText_metatutor_Wait 0x6
	removemoney 0x2710 0x00
	sound 0x58
	updatemoney 0x35 0x00 0x00
	lock
	faceplayer
	msgbox gText_metatutor_4 0x6
	checksound
	hidemoney 0x35 0x00
	release
	end
	
.global EventScript_therianforms_Start
EventScript_therianforms_Start:
	lock
	faceplayer
	checkflag 0x827
	if 0x0 _goto EventScript_therianforms_Default
	checkflag 0x109C
	if 0x0 _goto EventScript_therianformsStart
	checkflag 0x949
	if 0x0 _goto EventScript_therianformsStart
	goto EventScript_therianforms_Done

EventScript_therianformsStart:
	msgbox gText_therianforms_2 0x6
	msgbox gText_therianforms_3 0x6
	goto EventScript_therianforms_Reg
	release
	end

EventScript_therianforms_Reg:
	setvar 0x8003 0x0 @From party
	special 0x9F @choose from party
	waitstate
	compare 0x8004 0x6
	if 0x4 _goto EventScript_therianforms_Cancel
	special 0x7C @puts the selected mon in party into buffer
	msgbox gText_therianforms_4 0x6
	special2 LASTRESULT 0x18
	compare LASTRESULT 0x2BA
	if 0x1 _goto EventScript_therianforms_Landorus
	special2 LASTRESULT 0x18
	compare LASTRESULT 0x2B7
	if 0x1 _goto EventScript_therianforms_Landorus
	special2 LASTRESULT 0x18
	compare LASTRESULT 0x2B6
	if 0x1 _goto EventScript_therianforms_Landorus
	special2 LASTRESULT 0x18
	compare LASTRESULT 0x2F4
	if 0x1 _goto EventScript_therianforms_Landorus
	special2 LASTRESULT 0x18
	compare LASTRESULT 0x2F3
	if 0x1 _goto EventScript_therianforms_Landorus
	special2 LASTRESULT 0x18
	compare LASTRESULT 0x2F2
	if 0x1 _goto EventScript_therianforms_Landorus
	special2 LASTRESULT 0x18
	compare LASTRESULT SPECIES_ENAMORUS
	if 0x1 _goto EventScript_therianforms_Landorus
	special2 LASTRESULT 0x18
	compare LASTRESULT SPECIES_ENAMORUS_THERIAN
	if 0x1 _goto EventScript_therianforms_Landorus
	special2 LASTRESULT 0x18
	compare LASTRESULT SPECIES_KYUREM
	if 0x1 _goto EventScript_DNASplicers
	special2 LASTRESULT 0x18
	compare LASTRESULT SPECIES_ZEKROM
	if 0x1 _goto EventScript_DNASplicers
	special2 LASTRESULT 0x18
	compare LASTRESULT SPECIES_RESHIRAM
	if 0x1 _goto EventScript_DNASplicers
	msgbox gText_therianforms_5 0x6
	release
	end

EventScript_therianforms_Landorus:
	checkflag 0x949 
	if 0x1 _goto EventScript_therianforms_AlreadyDid
	msgbox gText_therianforms_7 0x6
	giveitem ITEM_REVEAL_GLASS 0x1 MSG_OBTAIN 
	setflag 0x949 
	release
	end

EventScript_DNASplicers:
	checkflag 0x109B
	if 0x1 _goto EventScript_therianforms_AlreadyDid
	msgbox gText_therianforms_7 0x6
	giveitem ITEM_DNA_SPLICERS 0x1 MSG_OBTAIN
	setflag 0x109B
	release
	end


EventScript_therianforms_Default:
	msgbox gText_therianforms_2 0x6
	release
	end

EventScript_therianforms_AlreadyDid:
	msgbox gText_therianforms_2_1 0x6
	release
	end

EventScript_therianforms_Done:
	msgbox gText_therianforms_8 MSG_FACE 
	release 
	end 

EventScript_therianforms_Cancel:
	release
	end

.global EventScript_Cinnabar_AceTrainer1
EventScript_Cinnabar_AceTrainer1:
	checkflag 0x269
	if 0x1 _goto End1
	checkflag FLAG_HARDCORE_MODE
	if 0x1 _call SetWeather
	trainerbattle2 0x2 0xB3 0x0 gText_CinnabarGym_AceTrainer1_1 gText_CinnabarGym_AceTrainer1_2 EndAceTrainer1
	setvar 0x8004 0x8
	setvar 0x8005 0x2
	special 0x173
End1:
	msgbox gText_CinnabarGym_AceTrainer1_3 MSG_NORMAL 
	end


EndAceTrainer1:
	checkflag 0x269
	if 0x0 _call CallAnotherScript1
	release
	end


CallAnotherScript1:
	call SoundSetTiles
	return


SoundSetTiles:
	sound 0x26
	checksound
	call SetTiles1
	special 0x8E
	setflag 0x269
	return


SetTiles1:
	setmaptile 0xB 0x15 0x2D1 0x1
	setmaptile 0xB 0x16 0x289 0x0
	setmaptile 0xB 0x17 0x281 0x0
	return

.global EventScript_Cinnabar_AceTrainer2
EventScript_Cinnabar_AceTrainer2:
	checkflag 0x26A
	if 0x1 _goto End2
	checkflag FLAG_HARDCORE_MODE
	if 0x1 _call SetWeather
	trainerbattle2 0x2 0xD7 0x0 gText_CinnabarGym_AceTrainer2_1 gText_CinnabarGym_AceTrainer2_2 EndAceTrainer2
End2:
	msgbox gText_CinnabarGym_AceTrainer2_3 MSG_NORMAL 
	end


EndAceTrainer2:
	checkflag 0x26A
	if 0x0 _call CallAnotherScript2
	release
	end


CallAnotherScript2:
	call SetTilesStuff2
	return


SetTilesStuff2:
	sound 0x26
	checksound
	call SetTiles2
	special 0x8E
	setflag 0x26A
	return


SetTiles2:
	setmaptile 0x5 0x10 0x2C7 0x0
	setmaptile 0x6 0x10 0x2C6 0x0
	setmaptile 0x5 0x11 0x2CF 0x0
	setmaptile 0x6 0x11 0x2CE 0x0
	setmaptile 0x5 0x12 0x289 0x0
	setmaptile 0x6 0x12 0x281 0x0
	setmaptile 0x7 0x12 0x282 0x0
	return

.global EventScript_Cinnabar_AceTrainer3
EventScript_Cinnabar_AceTrainer3:
	checkflag 0x26B
	if 0x1 _goto End3
	checkflag FLAG_HARDCORE_MODE
	if 0x1 _call SetWeather
	trainerbattle2 0x2 0xB4 0x0 gText_CinnabarGym_AceTrainer3_1 gText_CinnabarGym_AceTrainer3_2 EndAceTrainer3
End3:	
	msgbox gText_CinnabarGym_AceTrainer3_3 MSG_NORMAL
	end

EndAceTrainer3:
	checkflag 0x26B
	if 0x0 _call CallScript3
	release
	end

CallScript3:
	call CallSetTiles3
	return

CallSetTiles3:
	sound 0x26
	checksound
	call SetTiles3
	special 0x8E
	setflag 0x26B
	return

SetTiles3:
	setmaptile 0x5 0x8 0x2C7 0x0
	setmaptile 0x6 0x8 0x2C6 0x0
	setmaptile 0x5 0x9 0x2CF 0x0
	setmaptile 0x6 0x9 0x2CE 0x0
	setmaptile 0x5 0xA 0x289 0x0
	setmaptile 0x6 0xA 0x281 0x0
	setmaptile 0x7 0xA 0x282 0x0
	return


