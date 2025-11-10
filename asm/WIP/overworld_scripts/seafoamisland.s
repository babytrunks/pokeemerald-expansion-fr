.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s" 

.equ VAR_GARTICUNO_DAILY, 0x5114

.global EventScript_SeafoamIslands_Articuno
EventScript_SeafoamIslands_Articuno:
    lock
    faceplayer
    cry SPECIES_ARTICUNO 0x2
    preparemsg gText_SeafoamIslands_Articuno_1 
    waitmsg
    waitcry
    pause 0xA
    playsong 0x156 0x0
    waitkeypress
    wildbattle SPECIES_ARTICUNO 0x46 0x00
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x4
    if 0x1 _goto Moveback2
    fadescreen 0x1
    hidesprite 0x800F
    setflag 0x2BE
	setvar 0x8000 VAR_GARTICUNO_DAILY
    setvar 0x8001 0x0
    special 0xA1
    fadescreen 0x0
    release
    end

Moveback2:
    release 
    end

.global EventScript_SeafoamIslands_GalarArticuno
EventScript_SeafoamIslands_GalarArticuno:
    lock
    faceplayer
    cry SPECIES_ARTICUNO 0x2
    preparemsg gText_PowerPlant_Zapdos1 
    waitmsg
    waitcry
    pause 0xA
    playsong 0x156 0x0
    waitkeypress
    wildbattle SPECIES_ARTICUNO_G 0x46 0x00
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x4
    if 0x1 _goto Moveback2
    fadescreen 0x1
    hidesprite 0x800F
    setflag 0x1028
	setflag 0x1029
    fadescreen 0x0
    release
    end

.global gMapScripts_SeafoamIslands
gMapScripts_SeafoamIslands:
    mapscript MAP_SCRIPT_ON_TRANSITION HideGArticunoIfNotReady
    mapscript MAP_SCRIPT_ON_RESUME HideSpriteShit
    mapscript MAP_SCRIPT_ON_LOAD SetTileSeafoam4
    mapscript MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE ValidateValuesSeafoam4
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScripts_Seafoam4
    .byte MAP_SCRIPT_TERMIN

LevelScripts_Seafoam4:
    levelscript 0x4063, 1, LevelScript_Seafoam4
    .hword MAP_SCRIPT_TERMIN

ValidateValuesSeafoam4:
    levelscript 0x4063, 0x1, ValidateValuesScriptSeafoam4
    .hword MAP_SCRIPT_TERMIN

LevelScript_Seafoam4: 
    lockall
    applymovement PLAYER MovePlayerSeafoam4
    waitmovement 0x0
    setvar 0x4063 0x0
    releaseall
    end

MovePlayerSeafoam4:
    .byte run_up
    .byte run_up
    .byte run_up
    .byte end_m

LevelScript_SeafoamFailedRace:
    setvar 0x512D 0x0
    setvar 0x500B 0x0
    clearflag FLAG_SYS_BAG_HIDE
    clearflag 0x1050
    special2 LASTRESULT 0x49
    msgboxsign
    msgbox gText_OhNoFailedRace MSG_NORMAL
    msgbox gText_ReturnToTryAgain MSG_YESNO
    compare LASTRESULT YES
    if equal _goto WarpToSandshrew
    release
    end

WarpToSandshrew:
    warp 0x1 0x55 0x2 0x0 0x0
    end

HideGArticunoIfNotReady:
    checkflag 0x2BE
    if 0x0 _call 0x81630AD
    checkflag 0x2D3
    if 0x0 _call 0x8163082
    checkflag 0x2D3
    if 0x1 _call 0x81630A9
	checkflag 0x2BE
	if 0x0 _goto HideGArticuno
	checkflag 0x1029
	if 0x1 _goto HideGArticuno
	setvar 0x8000 VAR_GARTICUNO_DAILY
    setvar 0x8001 0x0
    special2 LASTRESULT 0xA0
    compare LASTRESULT 0x0 
    if equal _goto HideGArticuno
	clearflag 0x1028
	showsprite 0x5
	end 

SetTileSeafoam4:
    setvar 0x4002 0x0
    checkflag 0x4C
    if 0x0 _call 0x8163169
    checkflag 0x4D
    if 0x0 _call 0x8163169
    compare 0x4002 0x2
    if 0x1 _goto 0x81630D4
    end

ValidateValuesScriptSeafoam4:
    spriteface 0xFF 0x2
    special 0x161
    end

HideGArticuno:
    hidesprite 0x5
    setflag 0x1028
    end

HideSpriteShit:
    checkflag 0x807
    if 0x1 _call 0x8163052
    end


.global EventScript_Keldeo_OW
EventScript_Keldeo_OW:
	lock
    faceplayer
    cry SPECIES_KELDEO 0x2
    preparemsg gText_keldeo_12
    waitmsg
    waitcry
    pause 0xA
    playsong 0x156 0x0
    waitkeypress
    wildbattle SPECIES_KELDEO 0x46 0x00
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x4
    if 0x1 _goto Moveback2
    fadescreen 0x1
    hidesprite 0x800F
    setflag 0x1014
    fadescreen 0x0
    release
    end

.global gMapScripts_SeafoamIslandsCurrent
gMapScripts_SeafoamIslandsCurrent:
    mapscript MAP_SCRIPT_ON_TRANSITION SeafoamIslandRandomshit
    mapscript MAP_SCRIPT_ON_FRAME_TABLE SeafoamIslandCurrentStuff
    .byte MAP_SCRIPT_TERMIN

SeafoamIslandRandomshit:
    checkflag 0x2D2
    if 0x0 _call RandomshitSeafoam1
    checkflag 0x2D2
    if 0x1 _call 0x8162F94
    end

SeafoamIslandCurrentStuff:
    levelscript 0x512D, 1, LevelScript_SeafoamFailedRace
    levelscript 0x4001, 1, SeafoamIslandCurrentStuffScript
    .hword MAP_SCRIPT_TERMIN

SeafoamIslandCurrentStuffScript:
    lockall
    setvar 0x4002 0x0
    @ checkflag 0x46
    @ if 0x0 call 0x8162FF0
    checkflag 0x47
    if 0x0 _call 0x8162FF0
    compare 0x4002 0x1
    if 0x1 _goto 0x816300C
    getplayerpos 0x8008 0x8009
    compare 0x8008 0x18
    if 0x0 _call 0x8162FF6
    compare 0x8008 0x18
    if 0x4 _call 0x8163001
    setvar 0x4063 0x1
    warp 0x1 0x57 0xFF 0x1B 0x15
    waitstate
    releaseall
    end

RandomshitSeafoam1:
    setvar 0x4002 0x0
    @ checkflag 0x46
    @ if 0x0 _call 0x8162FF0
    checkflag 0x47
    if 0x0 _call 0x8162FF0
    compare 0x4002 0x1
    if 0x1 _call 0x8162F90
    return


.global EventScript_ASandshrewRaceStart
EventScript_ASandshrewRaceStart:
    lock
    faceplayer
    cry SPECIES_SANDSHREW_A 0x0
    msgbox gText_Seafoam_ASandhrew_1 MSG_KEEPOPEN
    waitcry
    closeonkeypress
    msgboxsign
    msgbox gText_Seafoam_ASandshrew_2 MSG_YESNO
    compare LASTRESULT YES
    if equal _goto WarpIntoRace
    release
    end

WarpIntoRace:
    applymovement 0x4 LookDown
    waitmovement 0x0
    sound 0x9
    hidesprite 0x4
    checksound
    @ special2 PLAYERFACING SPECIAL_GET_PLAYER_FACING
    compare PLAYERFACING RIGHT
    if 0x1 _call WarpFromLeft
    compare PLAYERFACING DOWN
    if 0x1 _call WarpFromUp
    compare PLAYERFACING LEFT
    if 0x1 _call WarpFromRight
    goto WarpFromRight
    release
    end
    
WarpFromRight:
    applymovement PLAYER WarpRightDown 
    waitmovement 0x0
    goto WarpASandshrew

WarpASandshrew:
    clearflag 0x1050
    warp 0x1 0x7C 0x0 0x0 0x0
    end

WarpFromUp:
    applymovement PLAYER WalkDown
    waitmovement 0x0
    goto WarpASandshrew

WarpFromLeft:
    applymovement PLAYER WarpLeftMove
    waitmovement 0x0
    goto WarpASandshrew

WarpRightDown:
    .byte walk_left
    .byte look_down
    .byte end_m

WarpLeftMove:
    .byte walk_right
    .byte look_down
    .byte end_m

WalkDown:
    .byte walk_down
    .byte end_m

LookDown:
    .byte look_down 
    .byte end_m


.global gMapScripts_SeafoamIslandsASandshrew
gMapScripts_SeafoamIslandsASandshrew:
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScripts_SeafoamIslands_ASandshrew
    mapscript MAP_SCRIPT_ON_LOAD ShowKyogrePathMap
    .byte MAP_SCRIPT_TERMIN

.global gMapScripts_SeafoamIslandsHideKyogrePath
gMapScripts_SeafoamIslandsHideKyogrePath:
    mapscript MAP_SCRIPT_ON_LOAD SeafoamIslandHideSandshrewshit
    .byte MAP_SCRIPT_TERMIN

SeafoamIslandHideSandshrewshit:
	checkitem ITEM_Z_POWER_RING 0x1
	compare LASTRESULT 0x1
    if greaterorequal _call ShowKyogrePath
	checkitem ITEM_Z_POWER_RING 0x1
	compare LASTRESULT 0x0
    if 0x1 _call HideKyogrePath
    end

filler:
    checkflag 0x82C
    if 0x1 _call ShowKyogrePath
    checkflag 0x82C
    if 0x0 _call HideKyogrePath
    end


ShowKyogrePath:
	checkitem ITEM_BICYCLE 0x1
	compare LASTRESULT 0x1
    if lessthan _goto HideKyogrePathEnd
    setmaptile 0x21 0x14 0x287 0x0
    setmaptile 0x20 0x15 0x2C8 0x1
    setmaptile 0x21 0x15 0x2C9 0x1
    setmaptile 0x22 0x15 0x2CA 0x1
    special 0x8E
    compare 0x512D 0x2
    if equal _goto DoNothing
    clearflag 0x1050 
    showsprite 0x4
    return

DoNothing:
    end 

HideKyogrePath:
    setflag 0x1050
    hidesprite 0x4
    return

HideKyogrePathEnd:
    setflag 0x1050
    hidesprite 0x4
    end

LevelScripts_SeafoamIslands_ASandshrew:
    levelscript 0x512D, 0, LevelScript_SeafoamIslands_ASandshrew
    .hword MAP_SCRIPT_TERMIN

LevelScript_SeafoamIslands_ASandshrew:
    sound 0x26
    setmaptile 0x9 0x0 0x299 0x1
    setmaptile 0x9 0x1 0x299 0x1
    special 0x8E
    checksound
    setvar 0x500B 0x1
    applymovement PLAYER WalkDown
    waitmovement 0x0
    applymovement 0x3 GoToSpot
    waitmovement 0x0
    applymovement 0x3 Jump2Right
    sound 0x1C
    checksound
    waitmovement 0x0
    special 0x157 @activate bicycle
    sound 0xB
    checksound
    msgboxsign
    msgbox gText_SeafoamIslands_Race_1 MSG_KEEPOPEN
    pause 0x5
    closeonkeypress
    msgbox gText_SeafoamIslands_Race_2 MSG_KEEPOPEN
    closeonkeypress
    special 0x46 @activate timer
    setflag FLAG_SYS_BAG_HIDE
    setvar 0x512D 0x1
    release
    goto SandshrewMovement

SandshrewMovement:
    applymovement 0x3 GoRace
    @ moveoffscreen 0x3
    end

GoToSpot:
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte walk_right
    .byte end_m

Jump2Right:
    .byte jump_2_right
    .byte look_down
    .byte end_m

GoRace:
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down_slow
    .byte walk_down
    .byte walk_down
    .byte walk_down
    .byte walk_down_slow
    .byte walk_down
    .byte walk_down
    .byte walk_down_slow
    .byte walk_left
    .byte walk_down
    .byte walk_down
    .byte walk_right 
    .byte walk_down
    .byte walk_down
    .byte walk_right
    .byte walk_right_onspot
    .byte walk_right_onspot
    .byte walk_right_onspot
    .byte walk_right_onspot
    .byte walk_right_onspot
    .byte walk_right_onspot
    .byte walk_right_onspot
    .byte end_m

.global EventScript_SeafoamIslands_FinishlineCheck
EventScript_SeafoamIslands_FinishlineCheck:
    setvar 0x500B 0x0
    setvar 0x8010 6 
    special2 LASTRESULT 0x4D
    compare LASTRESULT 0x1
    if 0x1 _goto TooSlow
    msgboxsign
    msgbox gText_Seafoam_YouWin MSG_KEEPOPEN
    setvar 0x512E 0x1
    setvar 0x512D 0x2
    clearflag FLAG_SYS_BAG_HIDE
    special2 LASTRESULT 0x49
    pause 0x5
    closeonkeypress
    fadescreen 0x1
    setflag 0x1050 
    hidesprite 0x3
    clearflag 0x200
    showsprite 0x2
    fadescreen 0x0
    applymovement 0x2 LookDown
    waitmovement 0x0
    applymovement PLAYER LookUp
    waitmovement 0x0
    cry SPECIES_SANDSHREW_A 0x0
    applymovement 0x2 Smile
    waitmovement 0x0
    waitcry
    applymovement 0x2 WalkRight
    waitmovement 0x0
    call GivePathToKyogre
    setmaptile 0x21 0x14 0x287 0x0
    setmaptile 0x20 0x15 0x2C8 0x1
    sound 0x7C
    special 0x8E
    checksound
    applymovement 0x2 WalkBack
    waitmovement 0x0
    sound 0x1C
    applymovement 0x2 JumpInPlace
    waitmovement 0x0
    checksound
    msgboxsign
    msgbox gText_Seafoam_ASandshrew_3 MSG_NORMAL
    fadescreen 0x1
    setflag 0x200
    hidesprite 0x2
    sound 0x9
	checksound
    fadescreen 0x0 
    release
    end

GivePathToKyogre:
    setmaptile 0x13 0x14 0x2F5 0x0
    setmaptile 0x13 0x15 0x305 0x0
    return 

LookUp:
    .byte look_up
    .byte end_m

Smile:
    .byte say_smile
    .byte end_m

WalkRight:
    .byte walk_right
    .byte end_m

WalkBack:
    .byte walk_left
    .byte end_m

JumpInPlace:
    .byte jump_onspot_down
    .byte end_m

TooSlow:
    msgbox gText_Seafoam_YouLose MSG_NORMAL
    special 0x46
    setvar 0x512D 0x0
    setvar 0x500B 0x0
    clearflag FLAG_SYS_BAG_HIDE
    special2 LASTRESULT 0x49
    clearflag 0x1050
    fadescreen 0x1
    warp 0x1 0x55 0x2 0x0 0x0
    pause 0x2
    fadescreen 0x0 
    release
    end

.global EventScript_CheckTimerAndStopRace
EventScript_CheckTimerAndStopRace:
    goto TooSlow
    release
    end

.global EventScript_SeafoamIslands_Kyogre
EventScript_SeafoamIslands_Kyogre:
	lock
    faceplayer
    cry SPECIES_KYOGRE 0x2
    waitcry
    pause 0x2
    wildbattle SPECIES_KYOGRE 100 0x00
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x4
    if 0x1 _goto Moveback2
    fadescreen 0x1
    hidesprite 0x800F
    setflag 0x1051
    fadescreen 0x0
    msgboxsign
    msgbox gText_KyogrePrimalOrb MSG_KEEPOPEN
    closeonkeypress
    giveitem ITEM_BLUE_ORB 0x1 MSG_FIND 
    release
    end

.global EventScript_SeafoamIslands_FrostbreathTM
EventScript_SeafoamIslands_FrostbreathTM:
    hidesprite 0x800F
    giveitem ITEM_TM97 0x1 MSG_FIND
    setflag 0x1052
    release
    end

.global EventScript_SeafoamIslands_Shrew
EventScript_SeafoamIslands_Shrew:
    faceplayer
    cry SPECIES_SANDSHREW_A 0x2
    release
    end

ShowKyogrePathMap:
    compare 0x512D 0x2
    if equal _call GivePathToKyogre
    release
    end

.global EventScript_SeafoamIsland_PryceRematchTile
EventScript_SeafoamIsland_PryceRematchTile:
    lock
    applymovement PLAYER LookRight
    applymovement 0x5 LookLeft
    waitmovement 0x0
    msgbox gText_Seafoam_Pryce1 MSG_YESNO
    compare LASTRESULT NO
    if equal _goto AnotherTime2
    goto SeafoamPryce

LookRight:
    .byte look_right
    .byte end_m

LookLeft:
    .byte look_left
    .byte end_m

.global EventScript_SeafoamIsland_PryceRematch
EventScript_SeafoamIsland_PryceRematch:
    lock
    faceplayer
    msgbox gText_Seafoam_Pryce1 MSG_YESNO
    compare LASTRESULT NO
    if equal _goto AnotherTime
    goto SeafoamPryce

SeafoamPryce:
    checkflag FLAG_HARDCORE_MODE
    if SET _call SetTrickRoom
    msgboxsign
    sound 0xBF
    msgbox gText_Seafoam_MonsAreFrozen MSG_KEEPOPEN
    checksound
    pause 0x5
    closeonkeypress
    setvar 0x8004 0x0
    setvar 0x8005 0x20
    setvar 0x8006 0x1
    special 0x64
    setvar 0x8004 0x1
    setvar 0x8005 0x20
    setvar 0x8006 0x1
    special 0x64
    setvar 0x8004 0x2
    setvar 0x8005 0x20
    setvar 0x8006 0x1
    special 0x64
    setflag FLAG_TRANSFORM_BATTLE
    @ setflag FLAG_SMALL_TRAINER_LEVELS
    trainerbattle3 0x3 0x4F 0x0 gText_pryce_Defeat
    normalmsg
    msgbox gText_Seafoam_Pryce3 MSG_NORMAL
    giveitem ITEM_ICIUM_Z 0x1 MSG_OBTAIN    
    msgbox gText_Seafoam_Pryce4 MSG_NORMAL
    fadescreen 0x1
    hidesprite 0x5
    sound 0x9
	checksound
    setflag 0x1053
    setvar 0x512F 0x1
    fadescreen 0x0
    release
    end

AnotherTime:
    msgbox gText_Seafoam_Pryce2 MSG_NORMAL
    release
    end

AnotherTime2:
    msgbox gText_Seafoam_Pryce2 MSG_NORMAL
    applymovement PLAYER GoUp
    waitmovement 0x0
    release
    end

GoUp:
    .byte walk_up
    .byte end_m

SetTrickRoom:  
	setvar VAR_BATTLE_AURAS PERMA_TRICK_ROOM_STRING 
    return

.global TestFollower
TestFollower:
    setvar 0x8000 LASTTALKED
    setvar 0x8001 0x1E
    special 0xD1 
    release
    end
