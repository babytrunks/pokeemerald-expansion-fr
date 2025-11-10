.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s" 

.equ FLAG_BEAT_TWO_ISLE_STARTERGUY, 0x1068

.global gMapScripts_TwoIslandJoyfulGC
gMapScripts_TwoIslandJoyfulGC:
    mapscript MAP_SCRIPT_ON_TRANSITION 0x81713E5
    mapscript MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE LevelScripts_TwoIslandJoyfulGC
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScripts2_TwoIslandJoyfulGC
    mapscript MAP_SCRIPT_ON_LOAD 0x81BB237
    .byte MAP_SCRIPT_TERMIN

LevelScripts_TwoIslandJoyfulGC:
    levelscript 0x4079, 2, 0x8171416
    .hword MAP_SCRIPT_TERMIN

LevelScripts2_TwoIslandJoyfulGC:
    levelscript 0x4079, 0, 0x817145F
    levelscript 0x4079, 2, LevelScripts_FoundLostelle
    .hword MAP_SCRIPT_TERMIN

LevelScripts_FoundLostelle:
    lockall
    msgbox TwoIsland_JoyfulGameCorner_Text_YouRescuedLostelle MSG_NORMAL
    msgbox TwoIsland_JoyfulGameCorner_Text_LostelleItsOkayDaddy MSG_KEEPOPEN
	closemessage
	applymovement 0x3 Movement_WalkInPlaceFastestDown
	waitmovement 0x0
	setvar 0x4079 3
    releaseall 
    end


Movement_WalkInPlaceFastestDown:
    .byte walk_down_onspot_fastest
    .byte end_m

.global EventScript_TwoIsland_SteelBeam
EventScript_TwoIsland_SteelBeam:
    lock
    faceplayer 
	msgbox gText_TwoIsland_SteelBeam1 MSG_YESNO
    compare LASTRESULT YES 
    if NO _goto Cancel
    setvar 0x8005 0x88
    special 0x18D
    waitstate
    compare LASTRESULT 0x0
    if 0x1 _goto Cancel
    msgbox gText_TwoIsland_SteelBeam2 MSG_FACE 
    release 
	end

Cancel:
    msgbox gText_TwoIsland_SteelBeam3 MSG_FACE 
    release 
    end 

.global EventScript_TwoIsland_Whitney
EventScript_TwoIsland_Whitney:
    lock
    checkflag 0x1020
    if 0x1 _goto WhitneyBeatEnd
    checkflag 0x101E
    if 0x1 _goto WhitneyAsk3
    msgbox gText_TwoIsland_Whitney1 MSG_NORMAL
    applymovement 0x1 FacePlayer
    waitmovement 0x0
    msgbox gText_TwoIsland_WhitneyDot MSG_KEEPOPEN
    setflag 0x101E 
    pause 0x3
    closeonkeypress
    msgbox gText_TwoIsland_Whitney2 MSG_YESNO
    goto WhitneyAsk

WhitneyAsk3:
    msgbox gText_TwoIsland_Whitney2_2 MSG_YESNO
WhitneyAsk:
    compare LASTRESULT YES
    if equal _goto YesDialogue 
    compare LASTRESULT NO
    if equal _goto NoDialogue 
    end

YesDialogue:
    msgbox gText_TwoIsland_WhitneyYes MSG_NORMAL
    special 0x0
    setflag 0x900 @Inverse Battle
    trainerbattle3 0x3 0x4C 0x0 gText_Whitney2_Defeat
    msgbox gText_TwoIslandWhitney9 MSG_NORMAL
    giveitem ITEM_NORMALIUM_Z 0x1 MSG_OBTAIN
    setflag 0x1020
    setvar 0x8000 MOVE_LIGHTOFRUIN
    setvar 0x8001 MOVE_SOFTBOILED
    setvar 0x8002 MOVE_FLAMETHROWER @moves 
    setvar 0x8003 MOVE_THUNDERWAVE 
    setvar 0x8004 NATURE_MODEST @nature 
    setvar 0x8005 0x0 
    setvar 0x8006 31
    setvar 0x8007 31
    setvar 0x8008 31
    setvar 0x8009 31
    setvar 0x800A 31
    setvar 0x800B 31
    givepokemon SPECIES_CLEFABLE 100 0x0 0x0 0x1 0x0   
    fanfare 0x13E
    msgbox gText_TwoIslandWhitney9_2 MSG_KEEPOPEN
    waitfanfare
    pause 0x3
    closeonkeypress
    
WhitneyBeatEnd:
    applymovement 0x1 LookLeft
    waitmovement 0x0
    msgbox gText_TwoIslandWhitney10 MSG_NORMAL
    release
    end

NoDialogue: 
    release
    end
FacePlayer:
    .byte face_player
    .byte end_m

LookLeft:
    .byte look_left
    .byte end_m

Surprised:
    .byte exclaim
    .byte end_m

.global EventScript_TwoIslandJail_NPC
EventScript_TwoIslandJail_NPC:
    lock
    faceplayer
    msgbox gText_TwoIslandJail_NPC_1 MSG_KEEPOPEN
    pause 0x3
    closeonkeypress 
    msgbox gText_TwoIslandJail_NPC_2 MSG_FACE
    release
    end

.global EventScript_TwoIslandJail_Sign
EventScript_TwoIslandJail_Sign:
    lock
    msgbox gText_TwoIslandJail_Sign MSG_SIGN
    release
    end

.global EventScript_TwoIslandPC_NPC
EventScript_TwoIslandPC_NPC:
    lock
    msgbox gText_TwoIslandPC_NPC_1 MSG_FACE
    applymovement 0x800F LookDown
    waitmovement 0x0
    release
    end

LookDown:
    .byte look_down
    .byte end_m

.global EventScript_TwoIslandGC_Owner
EventScript_TwoIslandGC_Owner:
    lock
    faceplayer
    msgbox gText_TwoIsland_GC_Owner1 MSG_NORMAL
    release
    end

.global EventScript_TwoIslandGC_StarterGuy
EventScript_TwoIslandGC_StarterGuy:
    lock
    faceplayer
    checkflag FLAG_BEAT_TWO_ISLE_STARTERGUY
    if SET _goto TeachMoveTutors
    msgbox gText_TwoIsland_GC_StarterGuy1 MSG_YESNO
    compare LASTRESULT NO
    if equal _goto Donege  
CheckIfTeamEligible:
    callasm CheckIfTeamStartersOnly + 1
    compare LASTRESULT 0x0
    if equal _goto NotEligibleGC
    msgbox gText_TwoIsland_GC_StarterGuyBeginBattle MSG_NORMAL
    trainerbattle3 0x3 0x2 0x0 gText_TwoIsland_GC_StarterGuyLoss
    setflag FLAG_BEAT_TWO_ISLE_STARTERGUY
    msgbox gText_TwoIsland_GC_StarterGuy2 MSG_KEEPOPEN
    pause 0x5
    closeonkeypress
    msgbox gText_TwoIsland_GC_StarterGuy3 MSG_NORMAL
    goto TeachMoveTutors

Donege:
    release
    end

NotEligibleGC:
    msgbox gText_TwoIsland_GC_StarterGuyNotEligible MSG_NORMAL
    release
    end

TeachMoveTutors:
    setvar 0x8006 0x0 @first item
	loadpointer 0x0 gText_FrenzyPlant
	special 0x25
	setvar 0x8006 0x1 @second item
	loadpointer 0x0 gText_HydroCannon
	special 0x25
    setvar 0x8006 0x2 @second item
	loadpointer 0x0 gText_BlastBurn
	special 0x25
    preparemsg gText_TwoIsland_GC_StarterGuy4
    waitmsg
    multichoice 0x0 0x0 0x21 0x0
    compare LASTRESULT 0x0
    if 0x1 _goto TeachFrenzyPlant
    compare LASTRESULT 0x1
    if 0x1 _goto TeachHydroCannon
    compare LASTRESULT 0x2
    if 0x1 _goto TeachBlastBurn
    goto Donege

TeachFrenzyPlant:
    setvar 0x8005 0x3D
    goto EndScript
    end 

TeachHydroCannon:
    setvar 0x8005 0x3F
    goto EndScript
    end 

TeachBlastBurn:
    setvar 0x8005 0x3E
    goto EndScript
    end 

EndScript:
    msgbox gText_Saffron_ManyTutors7 MSG_NORMAL 
    special 0x18D 
    waitstate 
    compare LASTRESULT 0x0 
    if 0x1 _goto TeachMoveTutors
    msgbox gText_TwoIsland_GC_StarterGuy5 MSG_NORMAL 
    release 
    end 

.global EventScript_twoislandgcguy_Start
EventScript_twoislandgcguy_Start:
	lock
	faceplayer
	checkflag 0x2A3
	if 0x1 _goto EventScript_twoislandgcguy_Starttwo
	msgbox gText_twoislandgcguy_Msgone MSG_KEEPOPEN 
	release
	end

EventScript_twoislandgcguy_Starttwo:
	checkflag 0x1074
	if 0x1 _goto EventScript_twoislandgcguy_Startthree
	msgbox gText_twoislandgcguy_GText_MsgTwo MSG_NORMAL
	release
	end

EventScript_twoislandgcguy_Startthree:
	msgbox gText_twoislandgcguy_GText_MsgThree MSG_NORMAL
	release
	end
