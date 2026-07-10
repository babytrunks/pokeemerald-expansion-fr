SlateportCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SlateportCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

SlateportCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_SLATEPORT_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SlateportCity_PokemonCenter_1F_EventScript_Sailor::
	msgbox SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_EventScript_Woman::
	msgbox SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_EventScript_NurseJoke::
	msgbox SlateportCity_PokemonCenter_1F_Text_IsNoMoreMore, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_EventScript_NOOOOOOOOOOOOO::
	msgbox SlateportCity_PokemonCenter_1F_Text_NOOOOOOOOO, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon:
	.string "Want a tip for battling?\p"
	.string "I'd say it's raising different kinds\n"
	.string "of Pokémon in a balanced manner.\p"
	.string "It's no good to make just one\n"
	.string "Pokémon strong.\p"
	.string "If it has a type disadvantage,\n"
	.string "it might not stand a chance.$"

SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend:
	.string "Hey dude calm down$"

SlateportCity_PokemonCenter_1F_Text_IsNoMoreMore::
	.string "Your Bagon is no more more$"

SlateportCity_PokemonCenter_1F_Text_NOOOOOOOOO::
	.string "NOOOOOOOOOOO\n"
	.string "NOOOOOOOOOOOOOOOOO$"
