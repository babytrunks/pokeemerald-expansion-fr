.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s" 

@ rescripted dragon tamer dialogue
.global EventScript_Route18_Trainer2
EventScript_Route18_Trainer2:
	trainerbattle0 0x0 0x134 0x0 gText_Route18Trainer2_EncounterText gText_Route18Trainer2_DefeatText
	msgbox gText_Route18Trainer2_AfterBattle 0x6
	end
