.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s" 

.equ VAR_GZAPDOS_DAILY, 0x5112 

.global EventScript_PowerPlant_Zapdos
EventScript_PowerPlant_Zapdos:
    lock
    faceplayer
    cry SPECIES_ZAPDOS 0x2
    preparemsg gText_PowerPlant_Zapdos1 
    waitmsg
    waitcry
    pause 0xA
    playsong 0x156 0x0
    waitkeypress
    wildbattle SPECIES_ZAPDOS 0x46 0x00
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x4
    if 0x1 _goto Moveback2
    fadescreen 0x1
    hidesprite 0x800F
    setflag 0x2BF
	setvar 0x8000 VAR_GZAPDOS_DAILY
    setvar 0x8001 0x0
    special 0xA1
    fadescreen 0x0
    release
    end

Moveback2:
    release 
    end

.global EventScript_PowerPlant_GalarZapdos
EventScript_PowerPlant_GalarZapdos:
    lock
    faceplayer
    cry SPECIES_ZAPDOS 0x2
    preparemsg gText_PowerPlant_Zapdos1 
    waitmsg
    waitcry
    pause 0xA
    playsong 0x156 0x0
    waitkeypress
    wildbattle SPECIES_ZAPDOS_G 0x46 0x00
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x4
    if 0x1 _goto Moveback2
    fadescreen 0x1
    hidesprite 0x800F
    setflag 0x1026
	setflag 0x1027
    fadescreen 0x0
    release
    end

.global gMapScripts_PowerPlant
gMapScripts_PowerPlant:
    mapscript MAP_SCRIPT_ON_TRANSITION HideGZapdosIfNotReady
    .byte MAP_SCRIPT_TERMIN

HideGZapdosIfNotReady:
	checkflag 0x2BF
	if 0x0 _goto HideGZapdos
	checkflag 0x1027
	if 0x1 _goto HideGZapdos
	setvar 0x8000 VAR_GZAPDOS_DAILY
    setvar 0x8001 0x0
    special2 LASTRESULT 0xA0
    compare LASTRESULT 0x0 
    if equal _goto HideGZapdos
	clearflag 0x1026
	showsprite 0xB
	end 

HideGZapdos:
	hidesprite 0xB
	setflag 0x1026
	end
