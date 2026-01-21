CeruleanCity_House1_Frlg_MapScripts::
	.byte 0

CeruleanCity_House1_EventScript_LuxuryBallGuy::
	lock
	faceplayer
    goto_if_set FLAG_CERULEAN_GAVE_LUXURY_BALL, CeruleanCity_House1_EventScript_LuxuryBallGuyDone
	msgbox CeruleanCity_House1_Text_LuxuryBallClassy
    giveitem ITEM_LUXURY_BALL
    setflag FLAG_CERULEAN_GAVE_LUXURY_BALL
CeruleanCity_House1_EventScript_LuxuryBallGuyDone:
    msgbox CeruleanCity_House1_Text_LuxuryBallBoostsIVs
    release
    end

CeruleanCity_House1_Text_LuxuryBallClassy::
    .string "Hello there traveler. I love when\n"
    .string "Pokémon have class.\p"
    .string "A little easy trick to make your\n"
    .string "Pokémon classier is catching them with\l"
    .string "a Luxury Ball.$"

CeruleanCity_House1_Text_LuxuryBallBoostsIVs::
    .string "The Luxury Ball is not only an\n"
    .string "excellent Ball to show high status.\p"
    .string "It'll automatically give 3 Perfect\n"
    .string "IVs to caught Pokémon.$"

