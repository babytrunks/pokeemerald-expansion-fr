.equ REQUIRED_SEEN_MONS, 10

Route2_EastBuilding_Frlg_MapScripts::
	.byte 0

Route2_EastBuilding_EventScript_Aide::
	lock
	faceplayer
	call Route2_EastBuilding_EventScript_GetAideRequestInfo
	goto_if_set FLAG_GOT_HM05, Route2_EastBuilding_EventScript_AlreadyGotHM05
	msgbox Route2_EastBuilding_Text_GiveHM05IfSeen10Mons, MSGBOX_YESNO
	giveitem_msg Route2_EastBuilding_Text_ReceivedHM05FromAide, ITEM_HM05
	setflag FLAG_GOT_HM05
	msgbox Route2_EastBuilding_Text_ExplainHM05
	release
	end

Route2_EastBuilding_EventScript_AlreadyGotHM05::
	msgbox Route2_EastBuilding_Text_ExplainHM05
	release
	end

Route2_EastBuilding_EventScript_GetAideRequestInfo::
	buffernumberstring STR_VAR_1, REQUIRED_SEEN_MONS
	bufferitemname STR_VAR_2, ITEM_HM05
	return

Route2_EastBuilding_EventScript_Rocker::
	msgbox Route2_EastBuilding_Text_CanGetThroughRockTunnel, MSGBOX_NPC
	end

Route2_EastBuilding_Text_GiveHM05IfSeen10Mons::
    .string "Hi! Remember me?\n"
    .string "I'm one of Prof. Oak's Aides.\p"
    .string "If your Pokédex has complete data\n"
    .string "on ten species, I'm supposed to\l"
    .string "give you a reward.\p"
    .string "Prof. Oak entrusted me with{PAUSE 200}.{PAUSE 200}.{PAUSE 200}.\p"
    .string "Eh, you know what?\p"
    .string "You can just have it, {PLAYER}.$"

Route2_EastBuilding_Text_GreatHereYouGo::
    .string "Great! You have caught or owned\n"
    .string "{STR_VAR_3} kinds of Pokémon!\p"
    .string "Congratulations!\n"
    .string "Here you go!$"

Route2_EastBuilding_Text_ReceivedHM05FromAide::
    .string "{PLAYER} received HM05\n"
    .string "from the burnt out Aide.$"

Route2_EastBuilding_Text_ExplainHM05::
    .string "Uh, yeah. That HM helps you get\n"
    .string "through dark places.\p"
    .string "I sure could use something like\n"
    .string "that right now.$"

Route2_EastBuilding_Text_CanGetThroughRockTunnel::
    .string "Once you get the HM Flash, you\n"
    .string "can get through Rock Tunnel.$"

