ViridianCity_House_Frlg_MapScripts::
	.byte 0

ViridianCity_House_EventScript_BaldingMan::
	msgbox ViridianCity_House_Text_NicknamingIsFun, MSGBOX_NPC
	end

ViridianCity_House_EventScript_LittleGirl::
	msgbox ViridianCity_House_Text_MyDaddyLovesMonsToo, MSGBOX_NPC
	end

ViridianCity_House_EventScript_Speary::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_NIDOKING, CRY_MODE_NORMAL
	msgbox ViridianCity_House_Text_Speary
	waitmoncry
	release
	end

ViridianCity_House_EventScript_NicknameSign::
	msgbox ViridianCity_House_Text_SpearowNameSpeary, MSGBOX_SIGN
	end

ViridianCity_House_Text_NicknamingIsFun::
  .string "{COLOR BLUE}Kids nowadays are cracked!\p"
  .string "Back in my day, you'd be king of\n"
  .string "the playground if you had even\l"
  .string "a Nidorino at my kid's age.\p"
  .string "My kid's running around with a\n"
  .string "Sheer Force Nidoking!\p"
  .string "Wahahah!$"

ViridianCity_House_Text_MyDaddyLovesMonsToo::
  .string "{COLOR RED}LeKing, sit!$"


ViridianCity_House_Text_Speary::
  .string "LeKing: Raaagh!$"

ViridianCity_House_Text_SpearowNameSpeary::
    .string "Nidoking\n"
    .string "Name: LeKing$"

