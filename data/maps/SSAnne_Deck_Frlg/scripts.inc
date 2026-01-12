SSAnne_Deck_Frlg_MapScripts::
	.byte 0

SSAnne_Deck_EventScript_Youngster::
	msgbox SSAnne_Deck_Text_ShipDepartingSoon, MSGBOX_NPC
	end

SSAnne_Deck_EventScript_BaldingMan::
	msgbox SSAnne_Deck_Text_FeelSeasick, MSGBOX_NPC
	end

SSAnne_Deck_EventScript_Sailor::
	msgbox SSAnne_Deck_Text_ScrubbingDecksHardWork, MSGBOX_NPC
	end


SSAnne_Deck_Text_ShipDepartingSoon::
    .string "The party's over.\n"
    .string "The ship will be departing soon.$"

SSAnne_Deck_Text_ScrubbingDecksHardWork::
    .string "Whew!\n"
    .string "Scrubbing decks is hard work!$"

SSAnne_Deck_Text_FeelSeasick::
    .string "Urf… I feel ill…\p"
    .string "I got seasick, so I stepped out to\n"
    .string "get some air…$"
