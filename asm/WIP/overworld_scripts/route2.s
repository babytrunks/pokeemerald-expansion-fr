.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s" 

.global EventScript_giveflash_Start
EventScript_giveflash_Start:
	lock
	faceplayer
	textcolor 0x0
	checkflag 0x935
	if 0x1 _goto EventScript_giveflash_Done
	msgbox gText_giveflash_Msg 0x6
	giveitem 0x157 0x1 MSG_OBTAIN
	faceplayer
	msgbox gText_giveflash_2 0x6
	setflag 0x935
	release
	end

EventScript_giveflash_Done:
	msgbox gText_giveflash_1 0x6
	release
	end
