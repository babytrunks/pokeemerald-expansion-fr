.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s" 

.equ FLAG_RENTAL_BATTLE, 0x104B

.global EventScript_gamecornertms_test
EventScript_gamecornertms_test:
	special 0x187
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_gamecornertms_End
	lock
	faceplayer
	preparemsg gText_gamecornertms_Hello @"Hi, there!\nMay I help you?"
	waitmsg
	pokemart EventScript_gamecornertms_Values
	msgbox gText_gamecornertms_Comeagain MSG_KEEPOPEN @"Please come again!"
	release
	end

EventScript_gamecornertms_End:
	release
	end
	
.align 1
EventScript_gamecornertms_Values:
	.hword ITEM_TM06
	.hword ITEM_TM13
	.hword ITEM_TM16 
	.hword ITEM_TM17
	.hword ITEM_TM20 
	.hword ITEM_TM24
	.hword ITEM_TM33 
    .hword ITEM_TM35
	.hword ITEM_TM53 
	.hword ITEM_TM56
	.hword ITEM_TM64
	.hword ITEM_TM65 
	.hword ITEM_TM74 
	.hword ITEM_TM75 
	.hword ITEM_TM79  
	.hword ITEM_TM82 
	.hword ITEM_TM83 
    .hword ITEM_TM84 
    .hword ITEM_TM91 
	.hword ITEM_TM93 
	.hword ITEM_TM102 
	.hword ITEM_TM110 
    .hword 0x0


.global gMapScripts_CeladonCity
gMapScripts_CeladonCity:
	mapscript MAP_SCRIPT_ON_TRANSITION HideSprite_CeladonSeviianEgg
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScripts_CeladonPokemonCenter
    .byte MAP_SCRIPT_TERMIN

SetHealingPlaceCeladon:
	sethealingplace 0x7
	end


HideSprite_CeladonSeviianEgg:
	sethealingplace 0x7
	compare 0x5128 0x1
	if 0x1 _goto End
	compare 0x5128 0x2
	if 0x1 _goto End
	checkflag 0x823
	if 0x1 _goto SetVarIfNewGame
	hidesprite 0x6
	setflag 0x1043
	release
	end
	
SetVarIfNewGame:
	checkflag 0x1043
	if 0x0 _call SetVarSevii
	release
	end

SetVarSevii:
	setvar 0x5128 0x1
	return

End:
	release
	end

LevelScripts_CeladonPokemonCenter:
    levelscript 0x5128, 1, LevelScript_CeladonCitySeviianEgg
    .hword MAP_SCRIPT_TERMIN

LevelScript_CeladonCitySeviianEgg:
	setvar 0x5128 0x2
	clearflag 0x1043
	showsprite 0x6
	applymovement 0x6 LookLeft
	waitmovement 0x0
	pause 0x5
	sound 0x15
	applymovement 0x6 Exclaim
	waitmovement 0x0
	checksound
	msgbox gText_CeladonSeviiEgg_1 MSG_KEEPOPEN
	closeonkeypress
	applymovement 0x6 WalkToYou
	waitmovement 0x0 
	applymovement 0xFF FaceRight
	waitmovement 0x0
	msgbox gText_CeladonSeviiEgg_2 MSG_NORMAL
	special2 LASTRESULT 0x83
    compare LASTRESULT 0x6
    if notequal _goto ReceiveEgg  @if we have a slot open 
	msgbox gText_CeladonSeviiEgg_3 MSG_NORMAL
	applymovement 0x6 WalkBack
	waitmovement 0x0
	release
	end

FaceRight:
	.byte look_right
	.byte end_m

ReceiveEgg:
	callasm GiveSeviianEgg
	msgbox gText_Celadon_ReceivedEgg MSG_KEEPOPEN
	fanfare 0x13E
	waitfanfare
	closeonkeypress
	msgbox gText_CeladonSeviiEgg_4 MSG_NORMAL
	applymovement 0xFF MakeRoom
	applymovement 0x6 Leave
	waitmovement 0x0
	sound 0x9
	checksound
	hidesprite 0x6
	setflag 0x1043
	release
	end

LookLeft:
	.byte look_left
	.byte end_m

Exclaim: 
	.byte exclaim
	.byte end_m

WalkToYou:
	.byte walk_left
	.byte walk_left
	.byte walk_left
	.byte end_m

WalkBack:
	.byte walk_right
	.byte walk_right
	.byte walk_right
	.byte look_up
	.byte end_m

Leave:
	.byte walk_left
	.byte look_down
	.byte end_m

MakeRoom:
	.byte walk_up
	.byte look_down
	.byte end_m

.global EventScript_CeladonCitySeviianEgg
EventScript_CeladonCitySeviianEgg:
	lock
	faceplayer
	msgbox gText_CeladonSeviiEgg_5 MSG_NORMAL
	special2 LASTRESULT 0x83
    compare LASTRESULT 0x6
    if notequal _goto ReceiveEgg2  @if we have a slot open 
	msgbox gText_CeladonSeviiEgg_6 MSG_NORMAL
	applymovement 0x6 LookUp
	waitmovement 0x0
	release
	end

ReceiveEgg2:
	msgbox gText_CeladonSeviiEgg_7 MSG_NORMAL
	callasm GiveSeviianEgg
	msgbox gText_Celadon_ReceivedEgg MSG_KEEPOPEN
	fanfare 0x13E
	waitfanfare
	closeonkeypress
	msgbox gText_CeladonSeviiEgg_4 MSG_NORMAL
	fadescreen 0x1
	hidesprite 0x6
	sound 0x9
	checksound
	fadescreen 0x0
	setflag 0x1043
	release
	end

LookUp:
	.byte look_up
	.byte end_m

.global EventScript_Celadon_Gambler
EventScript_Celadon_Gambler:
	lock
	faceplayer
	msgbox gText_Celadon_Gambler1 MSG_NORMAL
	msgbox gText_Celadon_Gambler2 MSG_YESNO
	compare LASTRESULT NO
	if equal _goto GamblerReject1
	showmoney 0x35 0x00 0x00
	setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_Celadon_10000
	special 0x25
	setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_Celadon_25000
	special 0x25
    setvar 0x8006 0x2 @third item
    loadpointer 0x0 gText_Celadon_50000
    special 0x25
	preparemsg gText_BetHowMuch
    waitmsg
    multichoice 0x0 0x0 0x21 0x0
    compare LASTRESULT 0x0
	if 0x1 _goto Bet10000
	compare LASTRESULT 0x1 
	if 0x1 _goto Bet25000
	compare LASTRESULT 0x2
	if 0x1 _goto Bet50000
	goto GamblerReject

Bet10000:
	checkmoney 0x2710 0x00
	compare 0x800D 0x1
	if 0x0 _goto EventScript_Gambler_NotEnoughMoney
	msgbox gText_playrough_Wait MSG_NORMAL
	removemoney 0x2710 0x00
	sound 0x58
	updatemoney 0x35 0x00 0x00
	msgbox gText_Celadon_Gambler_LetsGo 0x6
	checksound
	hidemoney 0x35 0x0
	setvar 0x5127 0x1
	special 0x27 @Backup
    special 0x28 @Need to have original team when saving game
	setflag FLAG_RENTAL_BATTLE
	callasm GiveRentalTeam
	trainerbattle9 0x9 0xE 0x0 gText_CeladonWinbattle gText_CeladonLoseBattle
	compare LASTRESULT 0x1
	if equal _goto YouLose
	compare LASTRESULT 0x0
	if equal _goto YouWin20000
	release
	end
	release
	end

Bet25000:
	checkmoney 0xC350 0x00
	compare 0x800D 0x1
	if 0x0 _goto EventScript_Gambler_NotEnoughMoney
	msgbox gText_playrough_Wait MSG_NORMAL
	removemoney 0xC350 0x00
	sound 0x58
	updatemoney 0x35 0x00 0x00
	msgbox gText_Celadon_Gambler_LetsGo 0x6
	checksound
	hidemoney 0x35 0x0
	setvar 0x5127 0x1
	special 0x27 @Backup
    special 0x28 @Need to have original team when saving game
	setflag FLAG_RENTAL_BATTLE
	callasm GiveRentalTeam
	setvar 0x8000 0xFEFE
	trainerbattle9 0x9 0xE 0x0 gText_CeladonWinbattle gText_CeladonLoseBattle
	compare LASTRESULT 0x1
	if equal _goto YouLose
	compare LASTRESULT 0x0
	if equal _goto YouWin25000
	release
	end

Bet50000:
	checkmoney 0x186A0 0x00
	compare 0x800D 0x1
	if 0x0 _goto EventScript_Gambler_NotEnoughMoney
	msgbox gText_playrough_Wait MSG_NORMAL
	removemoney 0x186A0 0x00
	sound 0x58
	updatemoney 0x35 0x00 0x00
	msgbox gText_Celadon_Gambler_LetsGo 0x6
	checksound
	hidemoney 0x35 0x0
	setvar 0x5127 0x1
	special 0x27 @Backup
    special 0x28 @Need to have original team when saving game
	setflag FLAG_RENTAL_BATTLE
	callasm GiveRentalTeam
	setvar 0x8000 0xFEFE
	trainerbattle9 0x9 0xE 0x0 gText_CeladonWinbattle gText_CeladonLoseBattle
	compare LASTRESULT 0x1
	if equal _goto YouLose
	compare LASTRESULT 0x0
	if equal _goto YouWin50000
	release
	end

EventScript_Gambler_NotEnoughMoney:
	hidemoney 0x35 0x0
	msgbox gText_Gamble_NotEnough MSG_NORMAL
	release
	end

GamblerReject:
	hidemoney 0x35 0x0
	msgbox gText_Celadon_GamblerNo MSG_NORMAL
	release
	end

GamblerReject1:
	msgbox gText_Celadon_GamblerNo MSG_NORMAL
	release
	end

YouLose:
	special 0x28
	msgbox gText_Celadon_YouLost MSG_NORMAL
	release
	end

YouWin50000:
	special 0x28
	showmoney 0x35 0x0
	addmoney 0x30D40
	goto EndOfBet

EndOfBet:
	msgbox gText_Celadon_YouWin MSG_NORMAL
	sound 0x58
	updatemoney 0x35 0x00 0x00
	msgbox gText_Celadon_Here 0x6
	checksound
	msgbox gText_ImAlwaysHere MSG_NORMAL
	hidemoney 0x35 0x0
	release
	end

YouWin25000:
	special 0x28
	showmoney 0x35 0x0
	addmoney 0x186A0
	goto EndOfBet

YouWin20000:
	special 0x28
	showmoney 0x35 0x0
	addmoney 0x4E20
	goto EndOfBet


.global EventScript_giovanni1_Start
EventScript_giovanni1_Start:
	lock
	faceplayer
	setvar 0x8004 0xF
	setvar 0x8005 0x0
	special 0x173
	preparemsg gText_giovanni1_Giovannitxt1 @"So! I must say, I am impressed you..."
	waitmsg
	playsong 0x11B 0x0
	waitkeypress
	special 0x0
	trainerbattle3 0x3 0x15C 0x0 gText_giovanni1_Giovanniloss
	msgbox gText_giovanni1_Giovannitxt2 0x6 @"I see that you raise Pok�mon with\..."
	fadescreen 0x1
	closeonkeypress
	hidesprite 0x1
	hidesprite 0xA
	showsprite 0x2
	clearflag 0x37
	setflag 0x5F
	setvar 0x8004 0xF
	setvar 0x8005 0x2
	special 0x174
	fadescreen 0x0
	release
	end
