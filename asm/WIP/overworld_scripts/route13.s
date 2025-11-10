.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s" 

.global EventScript_Route13_Trainer4
EventScript_Route13_Trainer4:
	trainerbattle11 0xB 0x10C 0x10D 0x4 0x5 0x0 gText_Route13_Trainer4_EncounterText gText_Route13_Trainer5_EncounterText gText_Route13_Trainer4_DefeatText gText_Route13_Trainer5_DefeatText gText_Route13_Trainer4_AfterBattle gText_Route13_Trainer4_AfterBattle
	msgbox gText_Route13_Trainer4_AfterBattle 0x6
	end


.global EventScript_Route13_Trainer5
EventScript_Route13_Trainer5: 
	trainerbattle11 0xB 0x10C 0x10D 0x5 0x4 0x0 gText_Route13_Trainer4_EncounterText gText_Route13_Trainer5_EncounterText gText_Route13_Trainer4_DefeatText gText_Route13_Trainer5_DefeatText gText_Route13_Trainer5_AfterBattle gText_Route13_Trainer5_AfterBattle
	msgbox gText_Route13_Trainer5_AfterBattle 0x6
	end
    