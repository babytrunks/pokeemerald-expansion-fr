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
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
	msgbox ViridianCity_House_Text_Speary
	waitmoncry
	release
	end

ViridianCity_House_EventScript_NicknameSign::
	msgbox ViridianCity_House_Text_SpearowNameSpeary, MSGBOX_SIGN
	end

ViridianCity_House_Text_NicknamingIsFun::
  .string "Kids nowadays are cracked!\p"
  .string "Back in my day, you'd be king of\n"
  .string "the playground if you had even\l"
  .string "a {COLOR GREEN}Nidorino{COLOR BLUE} at my son's age.\p"
  .string "My kid's running around with a\n"
  .string "{COLOR GREEN}Sheer Force Nidoking!\p"
  .string "{COLOR BLUE}Wahahah!$"

ViridianCity_House_Text_MyDaddyLovesMonsToo::
  .string "{COLOR GREEN}LeKing, {COLOR BLUE} sit!$"


ViridianCity_House_Text_Speary::
  .string "{COLOR GREEN}LeKing: {COLOR BLUE} Raaagh!$"

ViridianCity_House_Text_SpearowNameSpeary::
    .string "Nidoking\n"
    .string "Name: LeKing$"

