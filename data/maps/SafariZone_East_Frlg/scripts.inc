SafariZone_East_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SafariZone_East_OnTransition
	.byte 0

@ The rogue Mega Lucario only appears while the Mega Mayhem quest is active
@ (winning flips the quest to its reward state, clearing the active bit).
SafariZone_East_OnTransition::
	setflag FLAG_HIDE_SAFARI_ZONE_EAST_LUCARIO_Z
	goto_if_quest_active QUEST_MEGA_MAYHEM, SafariZone_East_EventScript_ShowLucarioZ
	end

SafariZone_East_EventScript_ShowLucarioZ::
	clearflag FLAG_HIDE_SAFARI_ZONE_EAST_LUCARIO_Z
	end

SafariZone_East_EventScript_RestHouseSign::
	msgbox SafariZone_East_Text_RestHouse, MSGBOX_SIGN
	end

SafariZone_East_EventScript_TrainerTips::
	msgbox SafariZone_East_Text_TimeDeclinesOnlyWhileYouWalk, MSGBOX_SIGN
	end

SafariZone_East_EventScript_AreaSign::
	msgbox SafariZone_East_Text_AreaSign, MSGBOX_SIGN
	end

@ lucario only active when respective quest is active (Cinnabar Labs)
SafariZone_East_EventScript_LucarioZ::
	lock
	faceplayer
	msgbox SafariZone_East_Text_LucarioRoar, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_LUCARIO_MEGA_Z, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_DONT_RANDOMIZE
	setflag FLAG_CANT_RUN
	setflag FLAG_CANT_CATCH
	setwildbattle SPECIES_LUCARIO_MEGA_Z, 65, ITEM_NONE, SPECIES_IRON_JUGULIS, 65, ITEM_NONE
	createmon 1, 0, SPECIES_LUCARIO_MEGA_Z, 65, ITEM_NONE, 0, NATURE_TIMID, 1, MON_FEMALE, 0, 0, 0, 252 , 252, 0, 31, 31, 31, 31, 31, 31, MOVE_AURA_SPHERE, MOVE_FLASH_CANNON, MOVE_DARK_PULSE, MOVE_VACUUM_WAVE, TRUE, FALSE, 0, 0  
	createmon 1, 1, SPECIES_IRON_JUGULIS, 65, ITEM_BOOSTER_ENERGY, 0, NATURE_TIMID, 1, MON_MALE, 0, 0, 0, 252 , 252, 0, 31, 31, 31, 31, 31, 31, MOVE_AEROBLAST, MOVE_DARK_PULSE, MOVE_EARTH_POWER, MOVE_KNOCK_OFF, TRUE, FALSE, 0, 0  	
	setwildonevstwo
	dowildbattle
	clearflag FLAG_DONT_RANDOMIZE
	clearflag FLAG_CANT_RUN
	clearflag FLAG_CANT_CATCH
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SafariZone_East_EventScript_LucarioZDefeated
	releaseall
	end

SafariZone_East_EventScript_LucarioZDefeated::
    fadescreenswapbuffers FADE_TO_BLACK
    removeobject LOCALID_SAFARI_ZONE_EAST_LUCARIO_Z
    fadescreenswapbuffers FADE_FROM_BLACK
	questmenu QUEST_MENU_SET_REWARD, QUEST_MEGA_MAYHEM
	msgbox SafariZone_East_Text_LucarioCalmed
	closemessage
	setflag FLAG_HIDE_SAFARI_ZONE_EAST_LUCARIO_Z
	releaseall
	end

SafariZone_East_Text_RestHouse::
    .string "Rest House$"

SafariZone_East_Text_TimeDeclinesOnlyWhileYouWalk::
    .string "Trainer Tips\p"
    .string "The remaining time declines only\n"
    .string "while you walk.$"

SafariZone_East_Text_AreaSign::
    .string "Area 1\n"
    .string "West: Center Area$"

SafariZone_East_Text_LucarioRoar::
    .string "The Lucario's eyes flash!\p"
    .string "Waves of strange energy pour off its\n"
    .string "body… and it Mega Evolves before your\l"
    .string "very eyes!\p"
    .string "A second Pokémon answers its call!$"

SafariZone_East_Text_LucarioCalmed::
    .string "The rogue Mega ran away…$"
