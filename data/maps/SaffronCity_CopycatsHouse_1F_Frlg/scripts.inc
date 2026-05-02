SaffronCity_CopycatsHouse_1F_Frlg_MapScripts::
	.byte 0

SaffronCity_CopycatsHouse_1F_EventScript_CopycatsMom::
	msgbox SaffronCity_CopycatsHouse_1F_Text_DaughterIsSelfCentered, MSGBOX_NPC
	end

SaffronCity_CopycatsHouse_1F_EventScript_CopycatsDad::
	msgbox SaffronCity_CopycatsHouse_1F_Text_DaughterLikesToMimicPeople, MSGBOX_NPC
	end

SaffronCity_CopycatsHouse_1F_EventScript_Chansey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	msgbox SaffronCity_CopycatsHouse_1F_Text_Chansey
	waitmoncry
	release
	end

EventScript_DumbassKid::
    goto_if_set FLAG_SAFFRON_BEAT_DUMBASS_KID, EventScript_DumbassKid_Done  @ TODO: map 0x98D to its FLAG define
    lock
    faceplayer
    msgbox gText_DumbassKid_1, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, EventScript_DumbassKid_Good
    msgbox gText_DumbassKid_Battle, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, EventScript_DumbassKid_Good
    playse SE_LEDGE  @ TODO: map CFRU sound 0xA to correct SE constant
    applymovement 4, EventMovement_DumbassKid_JumpUp
    waitmovement 0
    waitse
    msgbox gText_DumbassKid_Battle2, MSGBOX_NPC
    trainerbattle_no_intro TRAINER_DUMBASS_KID, gText_DumbassKidLoss 
    setflag FLAG_SAFFRON_BEAT_DUMBASS_KID  @ TODO: map 0x98D to its FLAG define
    msgbox gText_DumbassKid_PostLoss, MSGBOX_NPC
    giveitem ITEM_SWAMPERTITE  @ TODO: verify item constant name in this project
    msgbox gText_DumbassKid_megaswampyinfo, MSGBOX_DEFAULT
    release
    end

EventScript_DumbassKid_Good:
    msgbox gText_DumbassKid_Good, MSGBOX_NPC
    release
    end

EventScript_DumbassKid_Done:
    lock
    faceplayer
    @ goto_if_unset FLAG_UNKNOWN_97A, EventScript_CheckSwampertMega  @ TODO: map 0x97A to its FLAG define; CheckSwampertMega defined elsewhere
    msgbox gText_DumbassKid_LastMsg_2, MSGBOX_NPC  @ TODO: define this text (not present in source)
    release
    end

EventMovement_DumbassKid_JumpUp:
    jump_in_place_up  
    step_end

gText_DumbassKid_1:
    .string "i Herd U Liek Mudkipz$"

gText_DumbassKid_Good:
    .string "Mud! Kip!$"

gText_DumbassKid_Battle:
    .string "no??? NO???????\p"
    .string "I HERD U LIEK MUDKIPZ????$"

gText_DumbassKid_Battle2:
    .string "YOU.\p"
    .string "YOU WILL PAY!!!!!!!!!$"

gText_DumbassKidLoss:
    .string "mud... kip...$\p"

gText_DumbassKid_LastMsg_2:
	.string "i heckin luv mudkipz$"

gText_DumbassKid_megaswampyinfo:
    .string "you know only thing cooler than swampy?\p"
    .string "MEGA SWAMPY!!!!!!$"

gText_DumbassKid_PostLoss:
    .string "Well.\p"
    .string "Mudkips are still cool.\p"
    .string "I will share sum love XD$"

gText_DumbassKid_GetMudkip:
    .string "{COLOR WHITE}You received a Mudkip{COLOR WHITE}!$"

gText_DumbassKid_LastMsg:
    .string "THIS GAME WON'T LET ME OVERLEVEL\n"
    .string "WHAT THE FRIIIIIIIIIIICK!$"

SaffronCity_CopycatsHouse_1F_Text_DaughterIsSelfCentered::
    .string "My daughter is so self-centered.\n"
    .string "She has but a few friends.$"

SaffronCity_CopycatsHouse_1F_Text_DaughterLikesToMimicPeople::
    .string "My daughter likes to mimic people.\n"
    .string "It's rather vexing.\p"
    .string "Her mimicry has earned her the\n"
    .string "nickname Copycat around here.$"

SaffronCity_CopycatsHouse_1F_Text_Chansey::
    .string "CHANSEY: Chaan! Sii!$"

