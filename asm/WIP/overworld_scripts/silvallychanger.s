.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"

.equ SPECIES_SILVALLY, 0x3DE
.equ SPECIES_SILVALLY_FIGHT, 0x418
.equ SPECIES_SILVALLY_FLYING, 0x419
.equ SPECIES_SILVALLY_POISON, 0x41A
.equ SPECIES_SILVALLY_GROUND, 0x41B
.equ SPECIES_SILVALLY_ROCK, 0x41C
.equ SPECIES_SILVALLY_BUG, 0x41D
.equ SPECIES_SILVALLY_GHOST, 0x41E
.equ SPECIES_SILVALLY_STEEL, 0x41F
.equ SPECIES_SILVALLY_FIRE, 0x420
.equ SPECIES_SILVALLY_WATER, 0x421
.equ SPECIES_SILVALLY_GRASS, 0x422
.equ SPECIES_SILVALLY_ELECTRIC, 0x423
.equ SPECIES_SILVALLY_PSYCHIC, 0x424
.equ SPECIES_SILVALLY_ICE, 0x425
.equ SPECIES_SILVALLY_DRAGON, 0x426
.equ SPECIES_SILVALLY_DARK, 0x427
.equ SPECIES_SILVALLY_FAIRY, 0x428

.global EventScript_SilvallyChanger
EventScript_SilvallyChanger:
    lock
    faceplayer
    msgbox gText_SilvallyChanger1 MSG_YESNO 
    compare LASTRESULT YES 
    if 0x0 _goto CancelThis 
	setvar 0x8003 0x0 
    special 0x9F 
    waitstate 
    compare 0x8004 0x6
    if greaterorequal _goto CancelThis 
    special2 LASTRESULT 0x18
    compare LASTRESULT SPECIES_SILVALLY 
    if YES _goto ThatsSilvally  
    compare LASTRESULT SPECIES_SILVALLY_FIGHT 
    if YES _goto ThatsSilvally 
    compare LASTRESULT SPECIES_SILVALLY_FLYING
    if YES _goto ThatsSilvally 
    compare LASTRESULT SPECIES_SILVALLY_GROUND
    if YES _goto ThatsSilvally 
    compare LASTRESULT SPECIES_SILVALLY_ROCK
    if YES _goto ThatsSilvally 
    compare LASTRESULT SPECIES_SILVALLY_ICE
    if YES _goto ThatsSilvally 
    compare LASTRESULT SPECIES_SILVALLY_BUG
    if YES _goto ThatsSilvally 
    compare LASTRESULT SPECIES_SILVALLY_GHOST
    if YES _goto ThatsSilvally 
    compare LASTRESULT SPECIES_SILVALLY_STEEL
    if YES _goto ThatsSilvally 
    compare LASTRESULT SPECIES_SILVALLY_FIRE
    if YES _goto ThatsSilvally 
    compare LASTRESULT SPECIES_SILVALLY_WATER
    if YES _goto ThatsSilvally 
    compare LASTRESULT SPECIES_SILVALLY_GRASS
    if YES _goto ThatsSilvally 
    compare LASTRESULT SPECIES_SILVALLY_ELECTRIC
    if YES _goto ThatsSilvally 
    compare LASTRESULT SPECIES_SILVALLY_PSYCHIC
    if YES _goto ThatsSilvally 
    compare LASTRESULT SPECIES_SILVALLY_DRAGON 
    if YES _goto ThatsSilvally 
    compare LASTRESULT SPECIES_SILVALLY_DARK
    if YES _goto ThatsSilvally 
    compare LASTRESULT SPECIES_SILVALLY_FAIRY
    if YES _goto ThatsSilvally 
    compare LASTRESULT SPECIES_SILVALLY_POISON
    if YES _goto ThatsSilvally 
    msgbox gText_NoSilvally MSG_NORMAL 
	release 
	end 

ThatsSilvally:
    msgbox gText_SilvallyChanger3 MSG_NORMAL 
    goto FirstList 
    end 

FirstList: 
	setvar 0x8006 0x0
    loadpointer 0x0 gText_Normal
    special 0x25 
    setvar 0x8006 0x1 
    loadpointer 0x0 gText_Fighting
    special 0x25 
    setvar 0x8006 0x2
    loadpointer 0x0 gText_Steel
    special 0x25
    setvar 0x8006 0x3
    loadpointer 0x0 gText_Fairy  
    special 0x25 
    setvar 0x8006 0x4 
    loadpointer 0x0 gText_Dragon
    special 0x25
    setvar 0x8006 0x5
    loadpointer 0x0 gText_Grass
    special 0x25
    setvar 0x8006 0x6
    loadpointer 0x0 gText_ViewMore 
    special 0x25 
    preparemsg gText_WhichForm
    waitmsg
    multichoice 0x0 0x0 0x25 0x0 
    compare LASTRESULT 0x0
    if 0x1 _goto Normal 
    compare LASTRESULT 0x1
    if 0x1 _goto Fighting 
    compare LASTRESULT 0x2
    if 0x1 _goto Steel 
    compare LASTRESULT 0x3 
    if 0x1 _goto Fairy 
    compare LASTRESULT 0x4
    if 0x1 _goto Dragon 
    compare LASTRESULT 0x5 
    if 0x1 _goto Grass
    compare LASTRESULT 0x6
    if 0x1 _goto SecondList
	goto CancelThis 
	end 


SecondList:
    setvar 0x8006 0x0
    loadpointer 0x0 gText_Flying
    special 0x25 
    setvar 0x8006 0x1 
    loadpointer 0x0 gText_Poison 
    special 0x25 
    setvar 0x8006 0x2
    loadpointer 0x0 gText_Ground 
    special 0x25
    setvar 0x8006 0x3
    loadpointer 0x0 gText_Rock 
    special 0x25 
    setvar 0x8006 0x4 
    loadpointer 0x0 gText_Bug 
    special 0x25
    setvar 0x8006 0x5
    loadpointer 0x0 gText_Ghost  
    special 0x25 
	setvar 0x8006 0x6
    loadpointer 0x0 gText_ViewMore 
    special 0x25 
    preparemsg gText_WhichForm
    waitmsg
    multichoice 0x0 0x0 0x25 0x0 
    compare LASTRESULT 0x0
    if 0x1 _goto Flying
    compare LASTRESULT 0x1
    if 0x1 _goto Poison 
    compare LASTRESULT 0x2
    if 0x1 _goto Ground 
    compare LASTRESULT 0x3 
    if 0x1 _goto Rock 
    compare LASTRESULT 0x4
    if 0x1 _goto Bug  
    compare LASTRESULT 0x5 
    if 0x1 _goto Ghost  
	compare LASTRESULT 0x6
	if 0x1 _goto ThirdList
    goto FirstList 
    end 
	
ThirdList:
	setvar 0x8006 0x0
    loadpointer 0x0 gText_Fire
    special 0x25 
    setvar 0x8006 0x1 
    loadpointer 0x0 gText_Water 
    special 0x25 
    setvar 0x8006 0x2
    loadpointer 0x0 gText_Ice 
    special 0x25
    setvar 0x8006 0x3
    loadpointer 0x0 gText_Psychic
    special 0x25 
    setvar 0x8006 0x4 
    loadpointer 0x0 gText_Electric
    special 0x25
    setvar 0x8006 0x5
    loadpointer 0x0 gText_Dark 
    special 0x25 
	setvar 0x8006 0x6
    loadpointer 0x0 gText_Exit 
    special 0x25 
    preparemsg gText_WhichForm
    waitmsg
    multichoice 0x0 0x0 0x25 0x0 
    compare LASTRESULT 0x0
    if 0x1 _goto Fire 
    compare LASTRESULT 0x1
    if 0x1 _goto Water  
    compare LASTRESULT 0x2
    if 0x1 _goto Ice  
    compare LASTRESULT 0x3 
    if 0x1 _goto Psychic  
    compare LASTRESULT 0x4
    if 0x1 _goto Electric 
    compare LASTRESULT 0x5 
    if 0x1 _goto Dark 
	compare LASTRESULT 0x6
	if 0x1 _goto CancelThis 
    goto SecondList 
    end 

Normal: 
    setvar 0x8005 SPECIES_SILVALLY 
    special 0x16
    goto EndThisScript 
    end 


Fighting:
	setvar 0x8005 SPECIES_SILVALLY_FIGHT
    special 0x16
    goto EndThisScript 
    end 

Flying:
	setvar 0x8005 SPECIES_SILVALLY_FLYING
    special 0x16
    goto EndThisScript 
    end 

Poison:
	setvar 0x8005 SPECIES_SILVALLY_POISON
    special 0x16
    goto EndThisScript 
    end 

Ground:
	setvar 0x8005 SPECIES_SILVALLY_GROUND
    special 0x16
    goto EndThisScript 
    end 

Rock:
	setvar 0x8005 SPECIES_SILVALLY_ROCK
    special 0x16
    goto EndThisScript 
    end 

Bug:
	setvar 0x8005 SPECIES_SILVALLY_BUG
    special 0x16
    goto EndThisScript 
    end 

Ghost:
	setvar 0x8005 SPECIES_SILVALLY_GHOST
    special 0x16
    goto EndThisScript 
    end 

Steel:
	setvar 0x8005 SPECIES_SILVALLY_STEEL
    special 0x16
    goto EndThisScript 
    end 

Fire:
	setvar 0x8005 SPECIES_SILVALLY_FIRE
    special 0x16
    goto EndThisScript 
    end 

Water:
	setvar 0x8005 SPECIES_SILVALLY_WATER
    special 0x16
    goto EndThisScript 
    end 

Grass:
	setvar 0x8005 SPECIES_SILVALLY_GRASS
    special 0x16
    goto EndThisScript 
    end 

Electric:
	setvar 0x8005 SPECIES_SILVALLY_ELECTRIC
    special 0x16
    goto EndThisScript 
    end 

Psychic:
	setvar 0x8005 SPECIES_SILVALLY_PSYCHIC
    special 0x16
    goto EndThisScript 
    end 

Ice:
	setvar 0x8005 SPECIES_SILVALLY_ICE
    special 0x16
    goto EndThisScript 
    end 

Dragon:
	setvar 0x8005 SPECIES_SILVALLY_DRAGON
    special 0x16
    goto EndThisScript 
    end 

Dark:
	setvar 0x8005 SPECIES_SILVALLY_DARK
    special 0x16
    goto EndThisScript 
    end 

Fairy:
	setvar 0x8005 SPECIES_SILVALLY_FAIRY 
    special 0x16
    goto EndThisScript 
    end 

CancelThis:
	release 
	end 

EndThisScript: 
	msgbox gText_SilvallyChanger2 MSG_NORMAL 
	release 
	end 

