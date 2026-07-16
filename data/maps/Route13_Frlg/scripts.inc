Route13_Frlg_MapScripts::
	.byte 0

Route13_EventScript_SheilaDouble::
    goto_if_defeated TRAINER_BEAUTY_SHEILA, Route13_EventScript_SheilaBeaten
    playbgm MUS_ENCOUNTER_FEMALE, FALSE
    applymovement LOCALID_ROUTE13_SHEILA, Route13_Corridor_Movement_GirlFacePlayer
    waitmovement 0
    setspeaker SP_NAME_SHEILA
    msgbox Route13_Text_SheilaIntro
    playbgm MUS_ENCOUNTER_FEMALE, FALSE
    applymovement LOCALID_ROUTE13_LOLA, Common_Movement_ExclamationMark
    waitmovement 0
    setspeaker SP_NAME_LOLA
    msgbox Route13_Text_LolaIntro
	trainerbattle_two_trainers TRAINER_BEAUTY_SHEILA, Route13_Text_SheilaDefeat, TRAINER_BEAUTY_LOLA, Route13_Text_LolaDefeat
	settrainerflag TRAINER_BEAUTY_SHEILA
    settrainerflag TRAINER_BEAUTY_LOLA
    setvar VAR_ROUTE13_DOUBLE_BATTLE, 0x1
    end

Route13_Corridor_Movement_GirlFacePlayer::
    emote_exclamation_mark
    face_player
    step_end

Route13_EventScript_SheilaBeaten::
    lock
    faceplayer
    msgbox Route13_Text_SheilaPostBattle 
    release
    end

Route13_EventScript_TrainerTips1::
	msgbox Route13_Text_LookToLeftOfThatPost, MSGBOX_SIGN
	end

Route13_EventScript_TrainerTips2::
	msgbox Route13_Text_SelectToSwitchItems, MSGBOX_SIGN
	end

Route13_EventScript_RouteSign::
	msgbox Route13_Text_RouteSign, MSGBOX_SIGN
	end

Route13_Text_SebastianIntro::
    .string "My bird Pokémon want to battle\n"
    .string "with you!$"

Route13_Text_SebastianDefeat::
    .string "My Charizard and Tropius combo\n"
    .string "lost?$"

Route13_Text_SebastianPostBattle::
    .string "My Pokémon look happy even though\n"
    .string "they lost.$"

Route13_Text_SusieIntro::
    .string "I'm told I'm good for a kid.$"

Route13_Text_SusieDefeat::
    .string "Ohh!\n"
    .string "I lost!$"

Route13_Text_SusiePostBattle::
    .string "I want to become a good Trainer.\n"
    .string "I'll train hard, just watch.$"

Route13_Text_ValerieIntro::
    .string "Wow!\n"
    .string "Your Badges are too cool!$"

Route13_Text_ValerieDefeat::
    .string "Not enough!$"

Route13_Text_ValeriePostBattle::
    .string "You got those Badges from Gym\n"
    .string "Leaders. I know!$"

Route13_Text_GwenIntro::
    .string "My cute Pokémon wish to make your\n"
    .string "acquaintance.$"

Route13_Text_GwenDefeat::
    .string "Good going!\n"
    .string "You totally won!$"

Route13_Text_GwenPostBattle::
    .string "You have to make Pokémon battle\n"
    .string "to toughen them up.$"

Route13_Text_AlmaIntro::
    .string "I found Carbos in a cave once\n"
    .string "while I was spelunking.$"

Route13_Text_AlmaDefeat::
    .string "Oh, too bad!\n"
    .string "I just messed up!$"

Route13_Text_AlmaPostBattle::
    .string "Carbos boosted the Speed of my\n"
    .string "Pokémon.$"

Route13_Text_PerryIntro::
    .string "I'm not going to lose.\n"
    .string "Not when the wind's blowing my way!$"

Route13_Text_PerryDefeat::
    .string "The wind turned!$"

Route13_Text_PerryPostBattle::
    .string "I'm beat.\n"
    .string "I guess I'll Fly home.$"

Route13_Text_LolaIntro::
    .string "Sure, I'll play with you, sweetie.$"

Route13_Text_LolaDefeat::
    .string "Oh!\n"
    .string "You little beast!$"

Route13_Text_LolaPostBattle::
    .string "I wonder which is stronger, male or\n"
    .string "female Pokémon?$"

Route13_Text_SheilaIntro::
    .string "Do you want to battle some\n"
    .string "Pokémon with me?$"

Route13_Text_SheilaDefeat::
    .string "It's over already?$"

Route13_Text_SheilaPostBattle::
    .string "I don't know anything about\n"
    .string "Pokémon actually.\p"
    .string "The ones I use… I picked them\n"
    .string "for their looks!$"

Route13_Text_JaredIntro::
    .string "What're you lookin' at?$"

Route13_Text_JaredDefeat::
    .string "Dang!\n"
    .string "Stripped gears!$"

Route13_Text_JaredPostBattle::
    .string "Get lost!$"

Route13_Text_RobertIntro::
    .string "I always go with bird Pokémon.\n"
    .string "I've dedicated myself to them.$"

Route13_Text_RobertDefeat::
    .string "Out of power!$"

Route13_Text_RobertPostBattle::
    .string "I wish I could fly like Pidgey and\n"
    .string "Pidgeotto…$"

Route13_Text_LookToLeftOfThatPost::
    .string "Trainer Tips\p"
    .string "Look, look!\n"
    .string "Look to the left of that post!$"

Route13_Text_SelectToSwitchItems::
    .string "Trainer Tips\p"
    .string "Use Select to switch items in the\n"
    .string "Items window.$"

Route13_Text_RouteSign::
    .string "Route 13\n"
    .string "North to Silence Bridge$"

