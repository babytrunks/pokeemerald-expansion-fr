.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s" 

.global EventScript_snorlaxencounter_Start
.global EventScript_snorlaxencounter_Start2
.equ LEVEL_SCRIPT_SHARPEDO, 0x513C

.global EventScript_checkerikasabrina2_Start
EventScript_checkerikasabrina2_Start:
	checkflag 0x823
	if 0x0 _goto EventScript_checkerikasabrina2_Goback
	checkflag 0x825
	if 0x0 _goto EventScript_checkerikasabrina2_Goback
	release
	end

EventScript_checkerikasabrina2_Goback:
	textcolor 0x02
	setflag 0x926
	applymovement 0xFF EventScript_checkerikasabrina2_Stop
	waitmovement 0x0
	msgbox gText_checkerikasabrina_1 0x6
	applymovement 0xFF EventScript_checkerikasabrina2_Playermoveback
	waitmovement 0x0
	clearflag 0x926
	release
	end

EventScript_checkerikasabrina2_Stop:
.byte 0x4
.byte 0xFE

EventScript_checkerikasabrina2_Playermoveback:
.byte 0x11
.byte 0xFE

.global gMapScripts_SharpedoHouse
gMapScripts_SharpedoHouse:
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScripts_SharpedoHouse
	mapscript MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE ValidateValuesSharpedo 
    .byte MAP_SCRIPT_TERMIN

LevelScripts_SharpedoHouse:
	levelscript LEVEL_SCRIPT_SHARPEDO, 1, SharpedoHouseContinue
	.hword MAP_SCRIPT_TERMIN

ValidateValuesSharpedo:
	levelscript LEVEL_SCRIPT_SHARPEDO, 1, FaceUpAfterWarp
	.hword MAP_SCRIPT_TERMIN

.global EventScript_sharpedonite_Start
EventScript_sharpedonite_Start:
	lock
	faceplayer
	checkflag 0x98C
	if 0x1 _goto EventScript_sharpedonite_Default
	msgbox gText_sharpedonite_1 0x6
	goto EventScript_sharpedonite_Reg
	release
	end

EventScript_sharpedonite_Reg:
	checkflag FLAG_FOLLOWER_IN_PROGRESS
	if 0x0 _goto EndThis
	compare 0x5130 SPECIES_SHARPEDO
	if notequal _goto EndThis
	setvar LEVEL_SCRIPT_SHARPEDO 0x1
	warpmuted 23 0x2 0x2 0x0 0x0 
	waitstate
	release
	end

SharpedoHouseContinue:
	applymovement PLAYER LookUp
	waitmovement 0x0
	fadescreen 0x1
	clearflag 0x200
	special 0xD3
	callasm SetFollowerInvisible + 1 
	showsprite 0x4
	applymovement PLAYER LookUp
	waitmovement 0x0
	fadescreen 0x0
	pause 0x2
	sound 0x1C
	applymovement 0x4 JumpInPlaceToRight
	waitmovement 0x0
	checksound
	applymovement 0x1 LookLeft
	waitmovement 0x0
	cry SPECIES_SHARPEDO 0x0
	waitcry
	sound 0x15
	applymovement 0x1 EventScript_sharpedonite_Exclamation
	waitmovement 0x0 
	checksound
	msgbox gText_sharpedonite_6 MSG_KEEPOPEN
	pause 0x3
	closeonkeypress
	fadescreen 0x1
	callasm PlaySEMegaEvo + 1
	checksound
	fadescreen 0x0
	hidesprite 0x4
	showsprite 0x3
	sound 0x1C
	applymovement 0x3 JumpInPlaceToRight
	waitmovement 0x0
	checksound
	cry SPECIES_SHARPEDO_MEGA 0x0
	waitcry
	applymovement 0x1 FacePlayer
	waitmovement 0x0 
	msgbox gText_sharpedonite_7 MSG_NORMAL
	giveitem ITEM_SHARPEDONITE 0x1 MSG_OBTAIN
	fadescreen 0x1
	hidesprite 0x3
	setflag 0x200
	special 0xD3
    clearflag 0x1054
    showsprite 0x14
	sound 0xF
	checksound
    callasm SetFollowerVisible2
    fadescreen 0x0
	setflag 0x98C
	setvar LEVEL_SCRIPT_SHARPEDO 0x2
	release
	end

JumpInPlaceToRight:
	.byte jump_onspot_right
	.byte end_m

LookUp:
	.byte look_up
	.byte end_m

EndThis:
	release
	end

FacePlayer:
	.byte face_player
	.byte end_m

LookLeft:
	.byte look_left
	.byte end_m

FaceUpAfterWarp:
	spriteface PLAYER UP
	end

EventScript_sharpedonite_Reg2:
	setvar 0x8003 0x0 @From party
	special 0x9F @choose from party
	waitstate
	compare 0x8004 0x6
	if 0x4 _goto EventScript_sharpedonite_Cancel
	special 0x7C @puts the selected mon in party into buffer
	msgbox gText_sharpedonite_4 0x6
	special2 LASTRESULT 0x18
	compare LASTRESULT 0x14B
	if 0x1 _goto EventScript_sharpedonite_Sharpedo
	msgbox gText_sharpedonite_2 0x6
	release
	end

EventScript_sharpedonite_Sharpedo:
	msgbox gText_sharpedonite_5 0x6
	sound 0x15
	applymovement 0x1 EventScript_sharpedonite_Exclamation
	checksound
	msgbox gText_sharpedonite_6 0x6
	giveitem ITEM_SHARPEDONITE 0x1 MSG_OBTAIN
	setflag 0x98C
	release
	end

EventScript_sharpedonite_Default:
	msgbox gText_sharpedonite_3 0x6
	release
	end

EventScript_sharpedonite_Cancel:
	release
	end

EventScript_sharpedonite_Exclamation:
.byte 0x62
.byte 0xFE

EventScript_snorlaxencounter_Start:
	lock
	checkflag 0x23D
	if 0x0 _goto EventScript_snorlaxencounter_Depslumber
	special 0x187
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_snorlaxencounter_End
	special 0x188
	msgbox gText_snorlaxencounter_Pokeflute MSG_YESNO @"Want to use the Pok� Flute?"
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_snorlaxencounter_End
	call EventScript_snorlaxencounter_Playflute
	setwildbattle 0x8F 0x2D ITEM_LEFTOVERS
	checksound
	cry 0x8F 0x2
	pause 0x28
	waitcry
	setflag 0x54
	setflag 0x807
	setflag 0x253
	dowildbattle
	clearflag 0x807
	special2 LASTRESULT 0xB4
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_snorlaxencounter_Hugeyawn
	compare LASTRESULT 0x4
	if 0x1 _goto EventScript_snorlaxencounter_Hugeyawn
	compare LASTRESULT 0x5
	if 0x1 _goto EventScript_snorlaxencounter_Hugeyawn
	release
	end

EventScript_snorlaxencounter_Start2:
	lock
	checkflag 0x23D
	if 0x0 _goto EventScript_snorlaxencounter_Depslumber
	special 0x187
	compare LASTRESULT 0x2
	if 0x1 _goto EventScript_snorlaxencounter_End
	special 0x188
	msgbox gText_snorlaxencounter_Pokeflute MSG_YESNO @"Want to use the Pok� Flute?"
	compare LASTRESULT 0x0
	if 0x1 _goto EventScript_snorlaxencounter_End
	call EventScript_snorlaxencounter_Playflute2
	setwildbattle 0x8F 0x2D ITEM_LEFTOVERS
	checksound
	cry 0x8F 0x2
	pause 0x28
	waitcry
	setflag 0x80
	setflag 0x807
	setflag 0x253
	dowildbattle
	clearflag 0x807
	special2 LASTRESULT 0xB4
	compare LASTRESULT 0x1
	if 0x1 _goto EventScript_snorlaxencounter_Hugeyawn
	compare LASTRESULT 0x4
	if 0x1 _goto EventScript_snorlaxencounter_Hugeyawn
	compare LASTRESULT 0x5
	if 0x1 _goto EventScript_snorlaxencounter_Hugeyawn
	release
	end


	@---------------
EventScript_snorlaxencounter_Depslumber:
	msgbox gText_snorlaxencounter_ComfySlumber MSG_KEEPOPEN
	release
	end

	@---------------
EventScript_snorlaxencounter_End:
	release
	end

	@---------------
EventScript_snorlaxencounter_Playflute:
	preparemsg gText_snorlaxencounter_playflute
	waitmsg
	fanfare 0x152
	waitfanfare
	closeonkeypress
	pause 0x2
	applymovement LASTTALKED Jump
	waitmovement 0x0 
	msgbox gText_snorlaxencounter_Wokeup MSG_KEEPOPEN @"Snorlax woke up!\pIt attacked in a..."
	return

EventScript_snorlaxencounter_Playflute2:
	preparemsg gText_snorlaxencounter_playflute
	waitmsg
	fanfare 0x152
	waitfanfare
	closeonkeypress
	pause 0x2
	applymovement LASTTALKED Jump2
	waitmovement 0x0 
	@ checksound 
	msgbox gText_snorlaxencounter_Wokeup MSG_KEEPOPEN @"Snorlax woke up!\pIt attacked in a..."
	return

Jump:
	.byte face_player
	.byte jump_onspot_up
	.byte end_m 

Jump2: 
	.byte face_player
	.byte jump_onspot_right
	.byte end_m 

EventScript_snorlaxencounter_Hugeyawn:
	msgbox gText_snorlaxencounter_CalmedDown MSG_KEEPOPEN @"Snorlax calmed down.\nIt gave a hu..."
	release
	end

@ ace trainer previously was fisherman
.global EventScript_Route12_Trainer1
EventScript_Route12_Trainer1:
	trainerbattle0 0x0 0xE9 0x0 gText_Route12Trainer1_EncounterText gText_Route12Trainer1_DefeatText
	msgbox gText_Route12Trainer1_AfterBattle 0x6
	end
