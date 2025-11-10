.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s" 

.global EventScript_aideverstone_Start
EventScript_aideverstone_Start:
	lock
	faceplayer
	textcolor 0x0
	checkflag 0x1005
	if 0x1 _goto EventScript_aideverstone_Done
	msgbox gText_aideverstone_Msg 0x6
	giveitem ITEM_EVERSTONE 0x1 MSG_OBTAIN
	faceplayer
	msgbox gText_aideverstone_1 0x6
	setflag 0x1005 
	release
	end

EventScript_aideverstone_Done:
	msgbox gText_aideverstone_1 MSG_FACE 
	release
	end

.global EventScript_Route10MapScripts
EventScript_Route10MapScripts:
    mapscript MAP_SCRIPT_ON_LOAD SetmaptileScript_Route10
	@ mapscript MAP_SCRIPT_ON_TRANSITION ClearVars_Route10
    .byte MAP_SCRIPT_TERMIN

SetmaptileScript_Route10:
	checkitem ITEM_Z_POWER_RING 0x1
	compare LASTRESULT 0x1
    if greaterorequal _call SetTiles
	end 

SetTiles:
	setmaptile 0x1 0x23 0xA9 0x0
	return 

ClearVars_Route10:
	setvar 0x5131 0x0
	setvar 0x512B 0x0
	setvar 0x512C 0x0
	end
