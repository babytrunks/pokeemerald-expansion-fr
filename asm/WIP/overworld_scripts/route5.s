.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s" 


.global gMapScripts_Route5
gMapScripts_Route5:
    mapscript MAP_SCRIPT_ON_TRANSITION MapEntryScript_Route5
    .byte MAP_SCRIPT_TERMIN

MapEntryScript_Route5:
    checkflag 0x266
    if 0x1 _call MoveShit
    end 

MoveShit: 
    movesprite2 0x2 0x1B 0x1A 
    return 

.global EventScript_Route5_PostJeffCare
EventScript_Route5_PostJeffCare:
	lockall
	textcolor 0x0
	checkflag 0x103F
	if 0x1 _call GiveJeffCarePackage
	setvar 0x511F 0x1
	release
	end

GiveJeffCarePackage:
	applymovement 0xFF EventScript_Stop
	waitmovement 0x0
	msgbox gText_CarePackageFind MSG_NORMAL
	giveitem ITEM_GREAT_BALL 0xA MSG_OBTAIN
	giveitem ITEM_PRISM_SCALE 0xA MSG_OBTAIN
	giveitem ITEM_ROSELI_BERRY 0xA MSG_OBTAIN
	giveitem ITEM_SHUCA_BERRY 0xA MSG_OBTAIN
	giveitem ITEM_YELLOW_SHARD 0xA MSG_OBTAIN
	return

EventScript_Stop:
    .byte lock_facing
    .byte end_m

.global EventScript_daycarewoman_Daycarestart
EventScript_daycarewoman_Daycarestart:
	special 0x187
	compare LASTRESULT 0x2
	if 0x1 _goto 0x81A7AE0
	lock
	faceplayer
	special2 LASTRESULT 0xB6
	compare LASTRESULT 0x1
	if 0x1 _goto 0x8171A2E
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_daycarewoman_Changedstart
	compare LASTRESULT 0x3
	if 0x1 _goto EventScript_daycarewoman_Changedstart2
	msgbox 0x81BF7E4 MSG_YESNO @"I@m the Day-Care Lady.\pWe can rai..."
	compare LASTRESULT 0x1
	if 0x1 _goto 0x8171993
	msgbox 0x81BF916 MSG_KEEPOPEN @"Oh, fine, then.\nCome again."
	release
	end

	@---------------
EventScript_daycarewoman_Changedstart:
	msgbox 0x81BF988 MSG_KEEPOPEN @"Ah, it@s you!\nGood to see you.\pY..."
	setvar 0x8004 0x0
	msgbox 0x81BF89F MSG_YESNO @"We can raise two of your Pokémon.\..."
	compare LASTRESULT 0x1
	if 0x1 _goto 0x8171993
	msgbox 0x81BFAE8 MSG_YESNO @"Will you take your Pokémon back?"
	compare LASTRESULT 0x1
	if 0x1 _goto 0x8171A90
	goto 0x81719F7

	@---------------
EventScript_daycarewoman_Changedstart2:
	msgbox 0x81BF988 MSG_KEEPOPEN @"Ah, it@s you!\nGood to see you.\pY..."
	msgbox 0x81BFAE8 MSG_YESNO @"Will you take your Pokémon back?"
	compare LASTRESULT 0x1
	if 0x1 _goto 0x8171A90
	msgbox 0x81BF976 MSG_KEEPOPEN @"Fine.\nCome again."
	release
	end

.global EventScript_daycareEevee_Start
EventScript_daycareEevee_Start:
	lock
	faceplayer
	checkflag 0x104C @Flag to check if already received eevee
	if 0x1 _goto AlreadyReceivedEevee
	msgbox gText_Daycare_Eevee1 MSG_YESNO
	compare LASTRESULT NO
	if equal _goto DontFightEevee 
	msgbox gText_Daycare_Eevee2 MSG_NORMAL
	setflag FLAG_RENTAL_BATTLE
	setvar 0x5127 0x0
	special 0x27 @Backup
    special 0x28 @Need to have original team when saving game
	callasm GiveRentalTeam
	setvar 0x8000 0xFEFE
	trainerbattle9 0x9 0x5 0x0 gText_DaycareWinBattle gText_DaycareLoseBattle
	compare LASTRESULT 0x1
	if equal _goto NoPrize
	compare LASTRESULT 0x0
	if equal _goto TakeEevee
	release
	end

AlreadyReceivedEevee:
	msgbox gText_Daycare_Eevee4 MSG_NORMAL
	release
	end

DontFightEevee:
	msgbox gText_Daycare_EeveeDontFight MSG_NORMAL
	release
	end


TakeEevee:
	special 0x28
	setflag 0x104C
	givepokemon SPECIES_EEVEE 0x5 0x0 0x0 0x0 0x0
	msgbox gText_Daycare_Eevee3 MSG_NORMAL
	fanfare 0x13E
	msgbox gText_Daycare_ReceivedEevee MSG_KEEPOPEN
	waitfanfare
	closeonkeypress
	msgbox gText_Daycare_Eevee4 MSG_NORMAL
	release
	end

NoPrize:
	special 0x28
	msgbox gText_Daycare_Eevee2_Lose MSG_NORMAL
	release
	end
