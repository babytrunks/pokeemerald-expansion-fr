Route4_Frlg_MapScripts::
    @ map_script MAP_SCRIPT_ON_TRANSITION, Route4_Frlg_OnTransition
    map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route4_Frlg_OnWarp
    map_script MAP_SCRIPT_ON_FRAME_TABLE, Route4_OnFrame
	.byte 0

Route4_Frlg_OnWarp::
    map_script_2 VAR_TRIGGER_CERULEAN_CAVE_GIOVANNI, 1, Route4_ShowSprites_PostCeruleanCaveScript
    .2byte 0

Route4_OnFrame::
    map_script_2 VAR_TRIGGER_CERULEAN_CAVE_GIOVANNI, 1, Route4_EventScript_PostCeruleanCaveScript 
	.2byte 0

Route4_ShowSprites_PostCeruleanCaveScript::
    addobject LOCALID_ROUTE4_GIOVANNI
    addobject LOCALID_ROUTE4_LANCE
    end

Route4_EventScript_PostCeruleanCaveScript::
    applymovement LOCALID_ROUTE4_LANCE, Common_Movement_FaceRight
    waitmovement 0
    applymovement LOCALID_PLAYER, Common_Movement_FaceRight
    waitmovement 0
    applymovement LOCALID_ROUTE4_GIOVANNI, Common_Movement_FaceLeft
    waitmovement 0
    setspeaker SP_NAME_GIOVANNI
    msgbox gText_ceruleangiovanni_Awaydialogue
    giveitem ITEM_MEWTWONITE_Y
    setspeaker SP_NAME_GIOVANNI
    msgbox gText_ceruleangiovanni_Farewell
    applymovement LOCALID_ROUTE4_GIOVANNI, Route4_Movement_GiovanniLeaveRight
    waitmovement 0
    removeobject LOCALID_ROUTE4_GIOVANNI
    applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
    waitmovement 0
    setspeaker SP_NAME_LANCE
    msgbox gText_Route4_Lance_BeatenEvil
    giveitem ITEM_SALAMENCITE
    setspeaker SP_NAME_LANCE
    msgbox gText_Route4_Lance_InDueTime, MSGBOX_AUTOCLOSE
    fadescreenswapbuffers FADE_TO_BLACK
    playse SE_M_FLY
    removeobject LOCALID_ROUTE4_LANCE
    fadescreenswapbuffers FADE_FROM_BLACK
    setvar VAR_TRIGGER_CERULEAN_CAVE_GIOVANNI, 2
    callnative ScriptUpdateFollowingMon
    end

Route4_Movement_GiovanniLeaveRight:
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    step_end

Route4_EventScript_Woman::
	msgbox Route4_Text_TrippedOverGeodude, MSGBOX_NPC
	end

Route4_EventScript_MtMoonSign::
	msgbox Route4_Text_MtMoonEntrance, MSGBOX_SIGN
	end

Route4_EventScript_RouteSign::
	msgbox Route4_Text_RouteSign, MSGBOX_SIGN
	end

Route4_Text_TrippedOverGeodude::
    .string "Ouch! I tripped over a rocky\n"
    .string "Pokémon, GEODUDE!$"

Route4_Text_CrissyIntro::
    .string "I came to Mt. Moon in search of\n"
    .string "mushroom Pokémon.$"

Route4_Text_CrissyDefeat::
    .string "After all I did to catch them!$"

Route4_Text_CrissyPostBattle::
    .string "There might not be any more\n"
    .string "mushrooms here.\p"
    .string "I think I got them all.$"

Route4_Text_MtMoonEntrance::
    .string "Mt. Moon\n"
    .string "Tunnel Entrance$"

Route4_Text_RouteSign::
    .string "Route 4\n"
    .string "Mt. Moon - Cerulean City$"

Text_BlackBeltGuy_BitFeisty::
    .string "Sorry, my partner can be a bit feisty.\p"
    .string "But, if you're serious about training,\n"
    .string "take this.$"

Text_BlackBeltTaught::
    .string "That'll give your Pokémon with punch\n"
    .string "moves a better fighting chance!$"

Text_LowKickTeach::
    .string "A kick of brutal ferocity!\p"
    .string "Packed with destructive power!\p"
    .string "When you get right down to it,\n"
    .string "Low Kick is the ultimate attack!\l"
    .string "Don't you agree?$"

Text_LowKickDeclined::
    .string "You'll come crawling back when you\n"
    .string "realize the value of Low Kick.$"

Text_LowKickHereYouGo::
    .string "I like your spirit!\n"
    .string "Take the TM!$"

Text_LowKickTaught::
    .string "Now, we are soul mates in the way\n"
    .string "of kicking!$"

Route4_Text_PeopleLikeAndRespectBrock::
    .string "Oh, wow, that's the Boulder Badge!\n"
    .string "You got it from Brock, didn't you?\p"
    .string "Brock is cool. He's not just tough.\n"
    .string "People like and respect him.\p"
    .string "I want to become a Gym Leader\n"
    .string "like him.$"


gText_ceruleangiovanni_Awaydialogue::
	.string "Impressive… He forced us out of\n"
	.string "his domain, despite being caught.\p"
	.string "Alas, my plans for world domination\n"
    .string "are but a dream.\p"
    .string "Having lost in this fashion, \n"
    .string "I can't face my followers.\l"
    .string "I have betrayed their trust.\p"
    .string "As of today, Team Rocket is\n"
    .string "finished forever!\p"
    .string "As for myself, I shall dedicate\n"
    .string "my life to training again.\p"
    .string "Here, this is better off my hands.$"

gText_ceruleangiovanni_Farewell::
    .string "Farewell!$"

gText_Route4_Lance_BeatenEvil::
    .string "We may have beaten evil today,\n"
    .string "but it's only a matter of time\l"
    .string "until something new takes its place.\p"
    .string "But, today we should marvel in our\n"
    .string "victory. {PLAYER}, have this.\l"
    .string "You fought well.$"

gText_Route4_Lance_InDueTime::
    .string "In due time, I expect you to\n"
    .string "challenge me in the league.\p"
    .string "But first, you'll have to defeat\n"
    .string "my cousin, who's recently been put\l"
    .string "in charge of the Viridian City gym.\p"
    .string "Best of luck!$"

