SSAnne_B1F_Room5_Frlg_MapScripts::
	.byte 0

SSAnne_B1F_Room5_EventScript_Boy::
	msgbox SSAnne_B1F_Room5_Text_MachokeHasStrengthToMoveRocks, MSGBOX_NPC
	end

SSAnne_B1F_Room5_EventScript_Machoke::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWHIRL, CRY_MODE_NORMAL
	msgbox SSAnne_B1F_Room5_Text_Machoke
	waitmoncry
	release
	end

SSAnne_B1F_Room5_Text_MachokeHasStrengthToMoveRocks::
    .string "My buddy Poliwhirl is super strong!\p"
    .string "He has enough Strength to move\n"
    .string "big rocks!\p"
	.string "Imagine what he could do when\n"
	.string "he's evolved!$"

SSAnne_B1F_Room5_Text_Machoke::
    .string "Poliwhirl: Poli!$"

