SSAnne_B1F_Room5_Frlg_MapScripts::
	.byte 0

SSAnne_B1F_Room5_EventScript_Boy::
	msgbox SSAnne_B1F_Room5_Text_MachokeHasStrengthToMoveRocks, MSGBOX_NPC
	end

SSAnne_B1F_Room5_EventScript_Machoke::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_GURDURR, CRY_MODE_NORMAL
	msgbox SSAnne_B1F_Room5_Text_Machoke
	waitmoncry
	release
	end

SSAnne_B1F_Room5_Text_MachokeHasStrengthToMoveRocks::
    .string "My buddy Gurdurr is super strong!\p"
    .string "He has enough Strength to move\n"
    .string "big rocks!\p"
	.string "Imagine what he could do with\n"
	.string "a Link Cable!$"

SSAnne_B1F_Room5_Text_Machoke::
    .string "Gurdurr: Gwoh! Goggoh!$"

