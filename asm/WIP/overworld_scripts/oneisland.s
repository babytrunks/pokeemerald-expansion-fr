.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s" 

.equ FLAG_HIDE_TRAINER_RED, 0x105F
.equ VAR_RANDOM_BATTLER_HIGH_SCORE, 0x5134
.equ VAR_RANDOM_BATTLER_CURRENT_STREAK, 0x5135
.equ FLAG_FOUGHT_RANDOM_BATTLER_ONCE, 0x1061
.equ FLAG_SET_RED_APPEAR, 0x1062
.equ FLAG_BEAT_TRAINER_RED, 0x1063
.equ FLAG_NORMAL_TRAINER_BATTLE, 0x1065
.equ FLAG_HARDCORE_TRAINER_BATTLE, 0x1066
.equ VAR_RANDOM_BATTLER_HARDCORE_HIGH_SCORE, 0x5136
.equ FLAG_ACTIVATED_ENAMORUS, 0x106D 
.equ FLAG_WON_COSMOG, 0x107E
.equ VAR_BATTLE_POINTS, 0x513F
.equ FLAG_BOUGHT_N_LUNARIZER, 0x107F

.global gMapScripts_OneIsland
gMapScripts_OneIsland:
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScripts_OneIslandJotard
    .byte MAP_SCRIPT_TERMIN

LevelScripts_OneIslandJotard:
    levelscript 0x5107, 0, LevelScript_OneIslandJotard
    .hword MAP_SCRIPT_TERMIN

LevelScript_OneIslandJotard:
    lock
    playsong 0x13B
    applymovement 0x5 JotardWalkToU
    waitmovement 0x0
    msgbox gText_OneIslandJotard_1 MSG_KEEPOPEN
    pause 0x4
    closeonkeypress
    msgbox gText_OneIslandJotard_2 MSG_KEEPOPEN
    pause 0x3
    closeonkeypress
    msgbox gText_OneIslandJotard_3 MSG_NORMAL
    msgbox gText_OneIslandJotard_4 MSG_NORMAL
    setflag 0x90E
    trainerbattle3 0x3 0x28 0x0 gText_OneIslandJotard_Defeated
    msgbox gText_OneIslandJotard_5 MSG_NORMAL
    giveitem ITEM_Z_POWER_RING 0x1 MSG_OBTAIN
    msgbox gText_OneIslandJotard_6 MSG_NORMAL
    giveitem ITEM_FIGHTINIUM_Z 0x1 MSG_OBTAIN
    msgbox gText_OneIslandJotard_7 MSG_NORMAL
    playsong 0x13B
    setflag 0x926
    applymovement 0xFF WalkLeft
    waitmovement 0x0
    applymovement 0x5 JotardLeave
    waitmovement 0x0
    sound 0x9
    hidesprite 0x5
    checksound
    setflag 0x1017
    setworldmapflag 0x89B
    setvar 0x5107 0x1
    fadedefault
    clearflag 0x926
    msgboxsign
    msgbox gText_OneIslandJotard_8 MSG_NORMAL
    normalmsg
    release
    end

JotardWalkToU:
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte end_m

WalkLeft:
    .byte walk_left
    .byte look_right
    .byte end_m

JotardLeave:
    .byte walk_down
    .byte end_m


.global EventScript_waterfallhm_Start
EventScript_waterfallhm_Start:
	lock
	faceplayer
	checkflag 0x2EF
	if 0x1 _goto EventScript_waterfallhm_Done
	msgbox gText_waterfallhm_Handinhand MSG_KEEPOPEN @"Hot springs go hand-in-hand with\n..."
	giveitem ITEM_HM07 0x1 MSG_OBTAIN
	setflag 0x2EF
	msgbox gText_waterfallhm_Shatterstxt MSG_KEEPOPEN @"That shatters boulders as if they\..."
	release
	end

EventScript_waterfallhm_Done:
	msgbox gText_waterfallhm_Shatterstxt MSG_KEEPOPEN @"That shatters boulders as if they\..."
	release
	end

.global EventScript_TreasureBeach_Red
EventScript_TreasureBeach_Red:
    lock
    faceplayer
    msgbox gText_TreasureBeach_Red1 MSG_NORMAL
    trainerbattle3 0x3 0x3 0x0 gText_TreasureBeach_Red1
    msgbox gText_TreasureBeach_Red1 MSG_KEEPOPEN
    pause 0x5
    closeonkeypress
    msgboxsign
    msgbox gText_TreasureBeach_Red2 MSG_NORMAL
    giveitem ITEM_MEWTWONITE_X 0x1 MSG_OBTAIN
    call GiveSpecialPika
    checkflag FLAG_MINIMAL_GRINDING_MODE
    if 0x1 _call MinGrindingTrainerRedMsg
    checkflag FLAG_MINIMAL_GRINDING_MODE
    if 0x0 _call NormalTrainerRedMsg
    pause 0x4
    closeonkeypress
    fanfare 0x13E
    msgbox gText_TreasureBeach_Red4 MSG_KEEPOPEN
    waitfanfare
    pause 0x2
    closeonkeypress
    normalmsg
    msgbox gText_TreasureBeach_Red5 MSG_KEEPOPEN
    pause 0x2
    closeonkeypress
    fadescreen 0x1
	hidesprite 0x2
    setflag FLAG_HIDE_TRAINER_RED
    setflag FLAG_BEAT_TRAINER_RED
	sound 0x9
	checksound
	fadescreen 0x0
    release
    end

MinGrindingTrainerRedMsg:
    msgbox gText_TreasureBeach_Red3_2 MSG_KEEPOPEN
    return

NormalTrainerRedMsg:
    msgbox gText_TreasureBeach_Red3 MSG_KEEPOPEN
    return


GiveSpecialPika:
    setvar 0x8000 MOVE_AURAWHEEL
    setvar 0x8001 MOVE_CLOSECOMBAT
    setvar 0x8002 MOVE_FAKEOUT 
    setvar 0x8003 MOVE_KNOCKOFF 
    setvar 0x8004 NATURE_JOLLY 
    setvar 0x8005 0x1
    setvar 0x8006 31
    setvar 0x8007 31
    setvar 0x8008 31
    setvar 0x8009 31
    setvar 0x800A 31
    setvar 0x800B 31
    setflag FLAG_GIVE_POKEMON_HACK_MAX_EVS
    givepokemon SPECIES_PIKACHU_LIBRE 85 ITEM_LIGHT_BALL 0x0 0x1 0x0
    return

.global EventScript_OneIsland_RandomBattler
EventScript_OneIsland_RandomBattler:
    checkflag FLAG_FOUGHT_RANDOM_BATTLER_ONCE
    if NOT_SET _call SetVarToZero  
    buffernumber 0x0 VAR_RANDOM_BATTLER_HIGH_SCORE
    msgbox gText_OneIsland_RandomBattler1 MSG_NORMAL

ShowBattleSimOptions:
    setvar VAR_RANDOM_BATTLER_CURRENT_STREAK 0x0
    setvar 0x8004 0x0
    setvar 0x8000 0xD
    setvar 0x8001 0x6
    preparemsg gText_OneIsland_RandomBattler1_1
    waitmsg
    special 0x158
    waitstate 
    compare LASTRESULT 0x0
    if 0x1 _goto FightNormal
    compare LASTRESULT 0x1
    if 0x1 _goto FightHardcore
    compare LASTRESULT 0x2
    if 0x1 _goto ExchangeItems
    compare LASTRESULT 0x3
    if 0x1 _goto DisplayInfo
    goto releaseendscript
    end

.global releaseendscript
releaseendscript:
    release
    end

ExchangeItems:
    buffernumber 0x0 VAR_BATTLE_POINTS
    setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_MasterBall
	special 0x25
    setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_TapuniumZ
	special 0x25
    setvar 0x8006 0x2 @third item
	loadpointer 0x0 gText_SnorliumZ
	special 0x25
    setvar 0x8006 0x3 @4th item
	loadpointer 0x0 gText_PikaniumZ
	special 0x25
    setvar 0x8006 0x4 @5th item
	loadpointer 0x0 gText_PikashuniumZ
	special 0x25
    setvar 0x8006 0x5 @6th item
	loadpointer 0x0 gText_MoreBPStuff
	special 0x25
    preparemsg gText_WhichBPItemYouWant
    waitmsg
    multichoice 0x0 0x0 0x24 0x0
    compare LASTRESULT 0x0
    if 0x1 _goto BuyMasterBall
    compare LASTRESULT 0x1
    if 0x1 _goto BuyTapuniumZ
    compare LASTRESULT 0x2
    if 0x1 _goto BuySnorliumZ
	compare LASTRESULT 0x3
	if 0x1 _goto BuyPikaniumZ
    compare LASTRESULT 0x4
    if 0x1 _goto BuyPikashuniumZ
    compare LASTRESULT 0x5
    if 0x1 _goto ExchangeItemsListTwo
    goto ShowBattleSimOptions


ExchangeItemsListTwo:
    buffernumber 0x0 VAR_BATTLE_POINTS
    setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_AloRachiumZ
	special 0x25
    setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_InciniumZ
	special 0x25
    setvar 0x8006 0x2 @third item
	loadpointer 0x0 gText_DecidiumZ
	special 0x25
    setvar 0x8006 0x3 @4th item
	loadpointer 0x0 gText_PrimariumZ
	special 0x25
    setvar 0x8006 0x4 @5th item
	loadpointer 0x0 gText_LycaniumZ
	special 0x25
    setvar 0x8006 0x5 @6th item
	loadpointer 0x0 gText_MoreBPStuff
	special 0x25
    preparemsg gText_WhichBPItemYouWant
    waitmsg
    multichoice 0x0 0x0 0x24 0x0
    compare LASTRESULT 0x0
    if 0x1 _goto BuyAloRaichiumZ
    compare LASTRESULT 0x1
    if 0x1 _goto BuyInciniumZ
    compare LASTRESULT 0x2
    if 0x1 _goto BuyDecidiumZ
	compare LASTRESULT 0x3
	if 0x1 _goto BuyPrimariumZ
    compare LASTRESULT 0x4
    if 0x1 _goto BuyLycaniumZ
    compare LASTRESULT 0x5
    if 0x1 _goto ExchangeItemsListThree
    goto ExchangeItems

ExchangeItemsListThree:
    buffernumber 0x0 VAR_BATTLE_POINTS
    setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_FlyingGem
	special 0x25
    @ setvar 0x8006 0x1 @second item
	@ loadpointer 0x0 gText_Diancite
	@ special 0x25
    setvar 0x8006 0x1 @third item
	loadpointer 0x0 gText_KommoniumZ
	special 0x25
    setvar 0x8006 0x2 @4th item
    checkflag FLAG_BOUGHT_N_LUNARIZER
    if 0x1 _call BoughtNLunarizer
    checkflag FLAG_BOUGHT_N_LUNARIZER
    if 0x0 _call NLunarizerIn
    setvar 0x8006 0x3 @4th item
	loadpointer 0x0 gText_MoreBPStuff
	special 0x25
    preparemsg gText_WhichBPItemYouWant
    waitmsg
    multichoice 0x0 0x0 0x22 0x0
    compare LASTRESULT 0x0
    if 0x1 _goto BuyFlyingGem
    compare LASTRESULT 0x1
    if 0x1 _goto BuyKommoniumZ
	compare LASTRESULT 0x2
	if 0x1 _goto BuyNLunarizer
    compare LASTRESULT 0x3
    if 0x1 _goto ExchangeItemsListFour
    goto ShowBattleSimOptions

BoughtNLunarizer:
	loadpointer 0x0 gText_NLunarizerSold
	special 0x25
    return

NLunarizerIn:
	loadpointer 0x0 gText_NLunarizer
	special 0x25
    return
ExchangeItemsListFour:
    buffernumber 0x0 VAR_BATTLE_POINTS
    setvar 0x8006 0x0 @first item
    loadpointer 0x0 gText_Zygarde10Per
    special 0x25
    setvar 0x8006 0x1
    checkflag FLAG_WON_COSMOG
    if 0x1 _call CosmogSoldOut
    checkflag FLAG_WON_COSMOG
    if 0x0 _call CosmogStillIn
    setvar 0x8006 0x2 @third item
	loadpointer 0x0 gText_UltraNecroziumZ
	special 0x25
    setvar 0x8006 0x3 @second item
	loadpointer 0x0 gText_BpExit
	special 0x25
    preparemsg gText_WhichBPItemYouWant
    waitmsg
    multichoice 0x0 0x0 0x22 0x0
    compare LASTRESULT 0x0
    if 0x1 _goto BuyBoosterEnergy
    compare LASTRESULT 0x1
    if 0x1 _goto BuyCosmog
    compare LASTRESULT 0x2
    if 0x1 _goto BuyUltraNecroziumZ
    compare LASTRESULT 0x3
    if 0x1 _goto ShowBattleSimOptions
    goto ExchangeItemsListThree

CosmogSoldOut:
	loadpointer 0x0 gText_CosmogSoldOut
	special 0x25
    return

CosmogStillIn:
	loadpointer 0x0 gText_CosmogBP
	special 0x25
    return

BuyMasterBall:
    compare VAR_BATTLE_POINTS 0x3
    if lessthan _goto CantBuy
    bufferitem 0x0 ITEM_MASTER_BALL
    buffernumber 0x1 VAR_BATTLE_POINTS
    msgbox gText_WouldYoulike3BP MSG_YESNO
    compare LASTRESULT NO
    if equal _goto ExchangeItems
    subvar VAR_BATTLE_POINTS 0x3
    buffernumber 0x1 VAR_BATTLE_POINTS
    sound 0x58
    msgbox gText_TransactionDotDotDot MSG_KEEPOPEN
    pause 0x1
    closeonkeypress
    checksound
    msgbox gText_TransactionCompleted MSG_NORMAL
    giveitem ITEM_MASTER_BALL 0x1 MSG_OBTAIN
    goto ExchangeItems

BuyTapuniumZ:
    compare VAR_BATTLE_POINTS 0x3
    if lessthan _goto CantBuy
    bufferitem 0x0 ITEM_TAPUNIUM_Z
    buffernumber 0x1 VAR_BATTLE_POINTS
    msgbox gText_WouldYoulike3BP MSG_YESNO
    compare LASTRESULT NO
    if equal _goto ExchangeItems
    subvar VAR_BATTLE_POINTS 0x3
    buffernumber 0x1 VAR_BATTLE_POINTS
    sound 0x58
    msgbox gText_TransactionDotDotDot MSG_KEEPOPEN
    pause 0x1
    closeonkeypress
    checksound
    msgbox gText_TransactionCompleted MSG_NORMAL
    giveitem ITEM_TAPUNIUM_Z 0x1 MSG_OBTAIN
    goto ExchangeItems

BuySnorliumZ:
    compare VAR_BATTLE_POINTS 0x3
    if lessthan _goto CantBuy
    bufferitem 0x0 ITEM_SNORLIUM_Z
    buffernumber 0x1 VAR_BATTLE_POINTS
    msgbox gText_WouldYoulike3BP MSG_YESNO
    compare LASTRESULT NO
    if equal _goto ExchangeItems
    subvar VAR_BATTLE_POINTS 0x3
    buffernumber 0x1 VAR_BATTLE_POINTS
    sound 0x58
    msgbox gText_TransactionDotDotDot MSG_KEEPOPEN
    pause 0x1
    closeonkeypress
    checksound
    msgbox gText_TransactionCompleted MSG_NORMAL
    giveitem ITEM_SNORLIUM_Z 0x1 MSG_OBTAIN
    goto ExchangeItems

BuyPikaniumZ:
    compare VAR_BATTLE_POINTS 0x3
    if lessthan _goto CantBuy
    bufferitem 0x0 ITEM_PIKANIUM_Z
    buffernumber 0x1 VAR_BATTLE_POINTS
    msgbox gText_WouldYoulike3BP MSG_YESNO
    compare LASTRESULT NO
    if equal _goto ExchangeItems
    subvar VAR_BATTLE_POINTS 0x3
    buffernumber 0x1 VAR_BATTLE_POINTS
        sound 0x58
    msgbox gText_TransactionDotDotDot MSG_KEEPOPEN
    pause 0x1
    closeonkeypress
    checksound
    msgbox gText_TransactionCompleted MSG_NORMAL
    giveitem ITEM_PIKANIUM_Z 0x1 MSG_OBTAIN
    goto ExchangeItems

BuyPikashuniumZ:
    compare VAR_BATTLE_POINTS 0x3
    if lessthan _goto CantBuy
    bufferitem 0x0 ITEM_PIKASHUNIUM_Z
    buffernumber 0x1 VAR_BATTLE_POINTS
    msgbox gText_WouldYoulike3BP MSG_YESNO
    compare LASTRESULT NO
    if equal _goto ExchangeItems
    subvar VAR_BATTLE_POINTS 0x3
    buffernumber 0x1 VAR_BATTLE_POINTS
        sound 0x58
    msgbox gText_TransactionDotDotDot MSG_KEEPOPEN
    pause 0x1
    closeonkeypress
    checksound
    msgbox gText_TransactionCompleted MSG_NORMAL
    giveitem ITEM_PIKASHUNIUM_Z 0x1 MSG_OBTAIN
    goto ExchangeItems

BuyAloRaichiumZ:
    compare VAR_BATTLE_POINTS 0x5
    if lessthan _goto CantBuy
    bufferitem 0x0 ITEM_ALORAICHIUM_Z
    buffernumber 0x1 VAR_BATTLE_POINTS
    msgbox gText_WouldYoulike5BP MSG_YESNO
    compare LASTRESULT NO
    if equal _goto ExchangeItems
    subvar VAR_BATTLE_POINTS 0x5
    buffernumber 0x1 VAR_BATTLE_POINTS
        sound 0x58
    msgbox gText_TransactionDotDotDot MSG_KEEPOPEN
    pause 0x1
    closeonkeypress
    checksound
    msgbox gText_TransactionCompleted MSG_NORMAL
    giveitem ITEM_ALORAICHIUM_Z 0x1 MSG_OBTAIN
    goto ExchangeItems

BuyInciniumZ:
    compare VAR_BATTLE_POINTS 0x5
    if lessthan _goto CantBuy
    bufferitem 0x0 ITEM_INCINIUM_Z
    buffernumber 0x1 VAR_BATTLE_POINTS
    msgbox gText_WouldYoulike5BP MSG_YESNO
    compare LASTRESULT NO
    if equal _goto ExchangeItems
    subvar VAR_BATTLE_POINTS 0x5
    buffernumber 0x1 VAR_BATTLE_POINTS
        sound 0x58
    msgbox gText_TransactionDotDotDot MSG_KEEPOPEN
    pause 0x1
    closeonkeypress
    checksound
    msgbox gText_TransactionCompleted MSG_NORMAL
    giveitem ITEM_INCINIUM_Z 0x1 MSG_OBTAIN
    goto ExchangeItems

BuyDecidiumZ:
    compare VAR_BATTLE_POINTS 0x5
    if lessthan _goto CantBuy
    bufferitem 0x0 ITEM_DECIDIUM_Z
    buffernumber 0x1 VAR_BATTLE_POINTS
    msgbox gText_WouldYoulike5BP MSG_YESNO
    compare LASTRESULT NO
    if equal _goto ExchangeItems
    subvar VAR_BATTLE_POINTS 0x5
    buffernumber 0x1 VAR_BATTLE_POINTS
        sound 0x58
    msgbox gText_TransactionDotDotDot MSG_KEEPOPEN
    pause 0x1
    closeonkeypress
    checksound
    msgbox gText_TransactionCompleted MSG_NORMAL
    giveitem ITEM_DECIDIUM_Z 0x1 MSG_OBTAIN
    goto ExchangeItems

BuyPrimariumZ:
    compare VAR_BATTLE_POINTS 0x5
    if lessthan _goto CantBuy
    bufferitem 0x0 ITEM_PRIMARIUM_Z
    buffernumber 0x1 VAR_BATTLE_POINTS
    msgbox gText_WouldYoulike5BP MSG_YESNO
    compare LASTRESULT NO
    if equal _goto ExchangeItems
    subvar VAR_BATTLE_POINTS 0x5
    buffernumber 0x1 VAR_BATTLE_POINTS
        sound 0x58
    msgbox gText_TransactionDotDotDot MSG_KEEPOPEN
    pause 0x1
    closeonkeypress
    checksound
    msgbox gText_TransactionCompleted MSG_NORMAL
    giveitem ITEM_PRIMARIUM_Z 0x1 MSG_OBTAIN
    goto ExchangeItems

BuyLycaniumZ:
    compare VAR_BATTLE_POINTS 0x5
    if lessthan _goto CantBuy
    bufferitem 0x0 ITEM_LYCANIUM_Z
    buffernumber 0x1 VAR_BATTLE_POINTS
    msgbox gText_WouldYoulike5BP MSG_YESNO
    compare LASTRESULT NO
    if equal _goto ExchangeItems
    subvar VAR_BATTLE_POINTS 0x5
    buffernumber 0x1 VAR_BATTLE_POINTS
        sound 0x58
    msgbox gText_TransactionDotDotDot MSG_KEEPOPEN
    pause 0x1
    closeonkeypress
    checksound
    msgbox gText_TransactionCompleted MSG_NORMAL
    giveitem ITEM_LYCANIUM_Z 0x1 MSG_OBTAIN
    goto ExchangeItems

BuyFlyingGem:
    compare VAR_BATTLE_POINTS 15
    if lessthan _goto CantBuy
    bufferitem 0x0 ITEM_FLYING_GEM
    buffernumber 0x1 VAR_BATTLE_POINTS
    msgbox gText_WouldYoulike15BP MSG_YESNO
    compare LASTRESULT NO
    if equal _goto ExchangeItems
    subvar VAR_BATTLE_POINTS 15
    buffernumber 0x1 VAR_BATTLE_POINTS
        sound 0x58
    msgbox gText_TransactionDotDotDot MSG_KEEPOPEN
    pause 0x1
    closeonkeypress
    checksound
    msgbox gText_TransactionCompleted MSG_NORMAL
    giveitem ITEM_FLYING_GEM 0x1 MSG_OBTAIN
    goto ExchangeItems

BuyDiancite:
    compare VAR_BATTLE_POINTS 20
    if lessthan _goto CantBuy
    bufferitem 0x0 ITEM_DIANCITE
    buffernumber 0x1 VAR_BATTLE_POINTS
    msgbox gText_WouldYoulike20BP MSG_YESNO
    compare LASTRESULT NO
    if equal _goto ExchangeItems
    subvar VAR_BATTLE_POINTS 20
    buffernumber 0x1 VAR_BATTLE_POINTS
    sound 0x58
    msgbox gText_TransactionDotDotDot MSG_KEEPOPEN
    pause 0x1
    closeonkeypress
    checksound
    msgbox gText_TransactionCompleted MSG_NORMAL
    giveitem ITEM_DIANCITE 0x1 MSG_OBTAIN
    goto ExchangeItems

BuyKommoniumZ:
    compare VAR_BATTLE_POINTS 25
    if lessthan _goto CantBuy
    bufferitem 0x0 ITEM_KOMMONIUM_Z
    buffernumber 0x1 VAR_BATTLE_POINTS
    msgbox gText_WouldYoulike25BP MSG_YESNO
    compare LASTRESULT NO
    if equal _goto ExchangeItems
    subvar VAR_BATTLE_POINTS 25
    buffernumber 0x1 VAR_BATTLE_POINTS
        sound 0x58
    msgbox gText_TransactionDotDotDot MSG_KEEPOPEN
    pause 0x1
    closeonkeypress
    checksound
    msgbox gText_TransactionCompleted MSG_NORMAL
    giveitem ITEM_KOMMONIUM_Z 0x1 MSG_OBTAIN
    goto ExchangeItems

BuyNLunarizer:
    checkflag FLAG_BOUGHT_N_LUNARIZER
    if 0x1 _goto BoughtLunarizerAlready
    compare VAR_BATTLE_POINTS 25
    if lessthan _goto CantBuy
    bufferitem 0x0 ITEM_N_LUNARIZER
    buffernumber 0x1 VAR_BATTLE_POINTS
    msgbox gText_WouldYoulike25BP MSG_YESNO
    compare LASTRESULT NO
    if equal _goto ExchangeItems
    subvar VAR_BATTLE_POINTS 25
    buffernumber 0x1 VAR_BATTLE_POINTS
        sound 0x58
    msgbox gText_TransactionDotDotDot MSG_KEEPOPEN
    pause 0x1
    closeonkeypress
    checksound
    msgbox gText_TransactionCompleted MSG_NORMAL
    giveitem ITEM_N_LUNARIZER 0x1 MSG_OBTAIN
    setflag FLAG_BOUGHT_N_LUNARIZER
    goto ExchangeItems

BuyNSolarizer:
    compare VAR_BATTLE_POINTS 25
    if lessthan _goto CantBuy
    bufferitem 0x0 ITEM_N_SOLARIZER
    buffernumber 0x1 VAR_BATTLE_POINTS
    msgbox gText_WouldYoulike25BP MSG_YESNO
    compare LASTRESULT NO
    if equal _goto ExchangeItems
    subvar VAR_BATTLE_POINTS 25
    buffernumber 0x1 VAR_BATTLE_POINTS
        sound 0x58
    msgbox gText_TransactionDotDotDot MSG_KEEPOPEN
    pause 0x1
    closeonkeypress
    checksound
    msgbox gText_TransactionCompleted MSG_NORMAL
    giveitem ITEM_N_SOLARIZER 0x1 MSG_OBTAIN
    goto ExchangeItems

BuyCosmog:
    checkflag FLAG_WON_COSMOG
    if 0x1 _goto BoughtCosmogAlready
    compare VAR_BATTLE_POINTS 50
    if lessthan _goto CantBuy
    bufferpokemon 0x0 SPECIES_COSMOG
    buffernumber 0x1 VAR_BATTLE_POINTS
    msgbox gText_WouldYoulike50BP MSG_YESNO
    compare LASTRESULT NO
    if equal _goto ExchangeItems
    subvar VAR_BATTLE_POINTS 50
    buffernumber 0x1 VAR_BATTLE_POINTS
        sound 0x58
    msgbox gText_TransactionDotDotDot MSG_KEEPOPEN
    pause 0x1
    closeonkeypress
    checksound
    msgbox gText_TransactionCompleted MSG_NORMAL
    bufferpokemon 0x0 SPECIES_COSMOG
    fanfare 0x13E
    msgbox gText_OneIsland_PkmnReceived MSG_KEEPOPEN
    waitfanfare
    pause 0x2
    givepokemon SPECIES_COSMOG 50 0x0 0x0 0x0 0x0
    setflag FLAG_WON_COSMOG
    goto ExchangeItems

BuyBoosterEnergy:
    compare VAR_BATTLE_POINTS 15
    if lessthan _goto CantBuy
    bufferitem 0x0 ITEM_BOOSTER_ENERGY
    buffernumber 0x1 VAR_BATTLE_POINTS
    msgbox gText_WouldYoulike15BP MSG_YESNO
    compare LASTRESULT NO
    if equal _goto ExchangeItems
    subvar VAR_BATTLE_POINTS 15
    buffernumber 0x1 VAR_BATTLE_POINTS
    sound 0x58
    msgbox gText_TransactionDotDotDot MSG_KEEPOPEN
    pause 0x1
    closeonkeypress
    checksound
    msgbox gText_TransactionCompleted MSG_NORMAL
    bufferitem 0x0 ITEM_BOOSTER_ENERGY
    giveitem ITEM_BOOSTER_ENERGY 0x1 MSG_OBTAIN
    goto ExchangeItems

BoughtCosmogAlready:
    msgbox gText_AlreadyBoughtCosmog MSG_NORMAL
    goto ExchangeItems

BoughtLunarizerAlready:
    msgbox gText_AlreadyBoughtLunarizer MSG_NORMAL
    goto ExchangeItems

BuyUltraNecroziumZ:
    compare VAR_BATTLE_POINTS 50
    if lessthan _goto CantBuy
    bufferitem 0x0 ITEM_ULTRANECROZIUM_Z
    buffernumber 0x1 VAR_BATTLE_POINTS
    msgbox gText_WouldYoulike50BP MSG_YESNO
    compare LASTRESULT NO
    if equal _goto ExchangeItems
    subvar VAR_BATTLE_POINTS 50
    buffernumber 0x1 VAR_BATTLE_POINTS
        sound 0x58
    msgbox gText_TransactionDotDotDot MSG_KEEPOPEN
    pause 0x1
    closeonkeypress
    checksound
    msgbox gText_TransactionCompleted MSG_NORMAL
    giveitem ITEM_ULTRANECROZIUM_Z 0x1 MSG_OBTAIN
    goto ExchangeItems


CantBuy:
    msgbox gText_NotEnoughBP MSG_NORMAL
    goto ExchangeItems

FightHardcore:
    buffernumber 0x0 VAR_RANDOM_BATTLER_HARDCORE_HIGH_SCORE
    msgbox gText_OneIsland_HCTrainerHiScore MSG_YESNO
    compare LASTRESULT NO
    if equal _goto releaseendscript
    setflag FLAG_FOUGHT_RANDOM_BATTLER_ONCE
    setflag FLAG_HARDCORE_TRAINER_BATTLE
    goto FightRandomBattlerTwo

DisplayInfo:
    msgbox gText_BattleSim_Info MSG_NORMAL
    goto ShowBattleSimOptions

FightNormal:
    buffernumber 0x0 VAR_RANDOM_BATTLER_HIGH_SCORE
    msgbox gText_OneIsland_NormalTrainerHiScore MSG_YESNO
    compare LASTRESULT NO
    if equal _goto releaseendscript
    setflag FLAG_FOUGHT_RANDOM_BATTLER_ONCE
    setflag FLAG_NORMAL_TRAINER_BATTLE
    @ setflag FLAG_SMALL_TRAINER_LEVELS

FightRandomBattlerTwo: 
    callasm SetRandomTrainer 
    callasm VarSetTerrainInHardcoreMode
    msgbox gText_OneIsland_BattleStart MSG_NORMAL
    setflag FLAG_SCALE_TRAINER_LEVELS
    @ setflag FLAG_SMALL_TRAINER_LEVELS
    trainerbattle9 0x9 LASTRESULT 0x0 gText_RandomBattlerWon gText_RandomBattlerLost
    compare LASTRESULT 0x1
    if equal _goto EndTheStreak
    compare LASTRESULT 0x0
    if equal _goto YouWinRandomBattler
    end

YouWinRandomBattler:
    addvar VAR_RANDOM_BATTLER_CURRENT_STREAK 0x1
    buffernumber 0x0 VAR_RANDOM_BATTLER_CURRENT_STREAK
    msgbox gText_WouldYouLikeToContinue MSG_YESNO
    compare LASTRESULT YES
    if equal _goto AskForHeal
    compare LASTRESULT NO
    if equal _goto EndTheStreak

AskForHeal:
    compare VAR_RANDOM_BATTLER_CURRENT_STREAK 0xA
    if greaterorequal _goto FightRandomBattlerTwo
    msgbox gText_WouldYouLikeToHeal MSG_YESNO
    compare LASTRESULT YES
    if equal _call HealTeam
    goto FightRandomBattlerTwo

HealTeam:
    msgbox gText_HealTeam MSG_KEEPOPEN
    special 0x0
    sound 0x1
	checksound
    pause 0x2
    closeonkeypress
    msgbox gText_TeamHasBeenHealed MSG_NORMAL
    goto FightRandomBattlerTwo

SetVarToZero:
    setvar VAR_RANDOM_BATTLER_HIGH_SCORE 0x0
    setvar VAR_RANDOM_BATTLER_HARDCORE_HIGH_SCORE 0x0
    setvar VAR_BATTLE_POINTS 0x0
    return

EndTheStreak:
    callasm CompareHighScoreVariables +1
    compare LASTRESULT 0x1
    if equal _goto NewHighScore
    buffernumber 0x0 VAR_RANDOM_BATTLER_CURRENT_STREAK
    checkflag FLAG_HARDCORE_TRAINER_BATTLE
    if 0x1 _call BufferHardcoreHighScore
    checkflag FLAG_NORMAL_TRAINER_BATTLE
    if 0x1 _call BufferNormalHighScore
    msgbox gText_RandomBattlerEnd MSG_NORMAL
    call CheckIfShouldGiveEnamorus
    callasm AddBattlePoints + 1
    buffernumber 0x1 VAR_BATTLE_POINTS
    msgbox gText_AddBattlePoints MSG_NORMAL
    clearflag FLAG_NORMAL_TRAINER_BATTLE
    clearflag FLAG_HARDCORE_TRAINER_BATTLE
    release
    end
BufferHardcoreHighScore:
    buffernumber 0x1 VAR_RANDOM_BATTLER_HARDCORE_HIGH_SCORE
    return

BufferNormalHighScore:
    buffernumber 0x1 VAR_RANDOM_BATTLER_HIGH_SCORE
    return

NewHighScore:
    checkflag FLAG_HARDCORE_TRAINER_BATTLE
    if 0x1 _call HardcoreTrainerScoreUpdate
    checkflag FLAG_NORMAL_TRAINER_BATTLE
    if 0x1 _call NormalTrainerScoreUpdate
    clearflag FLAG_HARDCORE_TRAINER_BATTLE
    clearflag FLAG_NORMAL_TRAINER_BATTLE
    release
    end

NormalTrainerScoreUpdate:
    copyvar VAR_RANDOM_BATTLER_HIGH_SCORE VAR_RANDOM_BATTLER_CURRENT_STREAK
    buffernumber 0x0 VAR_RANDOM_BATTLER_HIGH_SCORE
    msgbox gText_RandomBattler_NewHighScore MSG_NORMAL
    checkflag FLAG_SET_RED_APPEAR
    if 0x0 _call CheckIfRedCanAppear
    call CheckIfShouldGiveEnamorus
    callasm AddBattlePoints + 1
    buffernumber 0x1 VAR_BATTLE_POINTS
    msgbox gText_AddBattlePoints MSG_NORMAL
    compare VAR_RANDOM_BATTLER_CURRENT_STREAK 0xA
    if greaterthan _call AddBonusForTenStreak
    return

HardcoreTrainerScoreUpdate:
    copyvar VAR_RANDOM_BATTLER_HARDCORE_HIGH_SCORE VAR_RANDOM_BATTLER_CURRENT_STREAK
    buffernumber 0x0 VAR_RANDOM_BATTLER_HARDCORE_HIGH_SCORE
    msgbox gText_RandomBattler_NewHighScore MSG_NORMAL
    checkflag FLAG_SET_RED_APPEAR
    if 0x0 _call CheckIfRedCanAppearHardcore
    call CheckIfShouldGiveEnamorus
    callasm AddBattlePoints + 1
    buffernumber 0x1 VAR_BATTLE_POINTS
    msgbox gText_AddBattlePoints MSG_NORMAL
    compare VAR_RANDOM_BATTLER_CURRENT_STREAK 0xA
    if greaterthan _call AddBonusForTenStreak
    return

AddBonusForTenStreak:
    callasm AddBonusPoints + 1
    buffernumber 0x0 VAR_BATTLE_POINTS
    sound 0x58
    msgbox gText_BonusBattlePoints10Streak MSG_NORMAL
    checksound
    return

CheckIfRedCanAppear:
    compare VAR_RANDOM_BATTLER_HIGH_SCORE 0x4
    if greaterorequal _call RedIsHere
    return 

CheckIfRedCanAppearHardcore:
    compare VAR_RANDOM_BATTLER_HARDCORE_HIGH_SCORE 0x4
    if greaterorequal _call RedIsHere
    return 
    
RedIsHere:
    msgbox gText_RandomBattler_RedIsHere MSG_NORMAL
    callasm AddBonusPoints + 1
    sound 0x58
    msgbox gText_ReceivedBonusPoints MSG_NORMAL
    checksound
    setflag FLAG_SET_RED_APPEAR
    return

CheckIfShouldGiveMasterBall:
    callasm CheckIfCurrentScoreIsEven + 1
    compare LASTRESULT 0x1
    if greaterorequal _call GiveMasterBall
    return
CheckIfShouldGiveEnamorus:
    checkflag FLAG_ACTIVATED_ENAMORUS
    if 0x0 _call CheckEnamorusConditions
    return

CheckIfShouldGiveCosmog:
    checkflag FLAG_WON_COSMOG
    if 0x0 _call CheckCosmogConditions
    return

CheckCosmogConditions:
    callasm CheckIfCurrentScoreShouldGiveCosmog + 1
    compare LASTRESULT 0x1
    if equal _call GiveCosmog
    return

GiveCosmog:
    @ msgbox gText_OneIsland_CosmogPrize MSG_NORMAL
    @ fanfare 0x13E
    @ msgbox gText_OneIsland_PkmnReceived MSG_KEEPOPEN
    @ waitfanfare
    @ pause 0x2
    @ givepokemon SPECIES_COSMOG 50 0x0 0x0 0x0 0x0
    @ setflag FLAG_WON_COSMOG
    return

CheckEnamorusConditions:
    callasm CheckIfCurrentScoreShouldGiveEnamorus + 1
    compare LASTRESULT 0x1
    if equal _call SetEnamorus
    return

SetEnamorus:
    callasm CheckIfSpaceForRoamer + 1
    compare LASTRESULT 0x1
    if equal _call SetRoamingEnamorus
    return

SetRoamingEnamorus:
	setvar 0x8000 SPECIES_ENAMORUS 
	setvar 0x8001 100
	setvar 0x8002 0x1 @Can roam on land
	setvar 0x8003 0x1 @Can roam on water
	special 0x129 @Create roaming Pokemon
    msgbox gText_OneIsland_EnamorusRoaming MSG_NORMAL
    sound 0x58
    msgbox gText_ReceivedBonusPoints MSG_NORMAL
    checksound
    callasm AddBonusPoints + 1
    setflag FLAG_ACTIVATED_ENAMORUS
    return

GiveMasterBall:
    buffernumber 0x0 VAR_RANDOM_BATTLER_CURRENT_STREAK
    msgbox gText_BattleSim_MasterBall MSG_NORMAL
    giveitem ITEM_MASTER_BALL LASTRESULT MSG_OBTAIN
    giveitem ITEM_WISHING_PIECE LASTRESULT MSG_OBTAIN
    return


.global EventScript_TreasureBeach_MapScripts
EventScript_TreasureBeach_MapScripts:
    mapscript MAP_SCRIPT_ON_TRANSITION HideRedIfNotReady
    .byte MAP_SCRIPT_TERMIN

HideRedIfNotReady:
    checkflag FLAG_SET_RED_APPEAR
    if 0x0 _call HideRed
    checkflag FLAG_SET_RED_APPEAR
    if 0x1 _call CheckIfShouldRedAppear
    end

HideRed:
    hidesprite 0x2
    setflag FLAG_HIDE_TRAINER_RED
    return

CheckIfShouldRedAppear:
    checkflag FLAG_BEAT_TRAINER_RED
    if 0x0 _call MakeRedAppear
    return


MakeRedAppear:
    clearflag FLAG_HIDE_TRAINER_RED
    showsprite 0x2
    return 

.global EventScript_OneIsland_HisuianFormNPC
EventScript_OneIsland_HisuianFormNPC:
    msgbox gText_OneIsland_HisuainForms MSG_FACE
    release
    end
