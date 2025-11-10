.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s" 

@ RUN LEFT AND RIGHT
@ RUNS TO THE RIGHT SIX GRIDS TO THE RIGHT
.equ FLAG_HIDEPKMNTOWER_NPC, 0x105B
.equ VAR_LVL_PKMNTOWER_POSTGAME_F1, 0x5133 
.equ FLAG_BEAT_ACE_TRAINER_1, 0x1069
.equ FLAG_BEAT_ACE_TRAINER_2, 0x106A
.equ FLAG_BEAT_ACE_TRAINER_3, 0x106B
.equ FLAG_BEAT_MORTY_REMATCH, 0x101D
.equ VAR_PKMNTOWER_MORTY_SCRIPT, 0x5138
.equ FLAG_DONE_MARSHADOW, 0x106C

.global gMapScripts_PokemonTowerPostGamePath
gMapScripts_PokemonTowerPostGamePath:
    mapscript MAP_SCRIPT_ON_LOAD PokemonTowerShowPostGamePath
    .byte MAP_SCRIPT_TERMIN

PokemonTowerShowPostGamePath:
	checkitem ITEM_Z_POWER_RING 0x1
	compare LASTRESULT 0x1
    if greaterorequal _call ShowPkmnTowerPostGame
	checkitem ITEM_Z_POWER_RING 0x1
	compare LASTRESULT 0x0
    if 0x1 _call HidePkmnTowerPostGame
    end

ShowPkmnTowerPostGame:
    setmaptile 0x5 0x9 0x282 0x0
    setmaptile 0x6 0x9 0x282 0x0
    setmaptile 0x7 0x9 0x282 0x0
    setmaptile 0x8 0x9 0x282 0x0
    setmaptile 0x5 0xA 0x282 0x0
    setmaptile 0x6 0xA 0x282 0x0
    setmaptile 0x7 0xA 0x282 0x0
    setmaptile 0x8 0xA 0x282 0x0
    setmaptile 0x5 0xB 0x282 0x0
    setmaptile 0x6 0xB 0x282 0x0
    setmaptile 0x7 0xB 0x282 0x0
    setmaptile 0x8 0xB 0x282 0x0
    special 0x8E
    checkflag FLAG_BEAT_MORTY_REMATCH
    if 0x0 _call ClearSprite
    return

ClearSprite:
    clearflag FLAG_HIDEPKMNTOWER_NPC
    showsprite 0x5
    return

HidePkmnTowerPostGame:
    setflag FLAG_HIDEPKMNTOWER_NPC
    hidesprite 0x5
    return

.global EventScript_PkmnTower_OldGateKeeper
EventScript_PkmnTower_OldGateKeeper:
    msgbox gText_PkmnTower_Gatekeeper MSG_YESNO
    compare LASTRESULT YES
    if equal _goto LeadToPkmnTowerPostGame
    msgbox gText_PkmnTower_GateKeeperReject MSG_NORMAL
    release
    end

LeadToPkmnTowerPostGame:
    clearflag FLAG_BEAT_ACE_TRAINER_1
    clearflag FLAG_BEAT_ACE_TRAINER_2
    clearflag FLAG_BEAT_ACE_TRAINER_3
    setvar VAR_LVL_PKMNTOWER_POSTGAME_F1 0x0
    msgbox gText_PkmnTower_Gatekeeper2 MSG_NORMAL
    applymovement 0x5 FaceLeft
    waitmovement 0x0
    sound 0x9
    hidesprite 0x5
    setflag FLAG_HIDEPKMNTOWER_NPC
	checksound
    clearflag 0x200
    applymovement 0xFF GoLeft 
    waitmovement 0x0
    warp 0x1 0x7D 0x1 0x0 0x0
    end

GoLeft:
    .byte walk_left
    .byte end_m

FaceLeft:
    .byte look_left
    .byte end_m

.global EventScript_GengarCaughtYou1F
EventScript_GengarCaughtYou1F:
    cry SPECIES_GENGAR 0x0
    msgbox gText_PkmnTower_Gengar MSG_NORMAL
    warp 0x1 0x7D 0x0 0x0 0x0 
    end


.global gMapScripts_PokemonTowerPostGameFloor1
gMapScripts_PokemonTowerPostGameFloor1:
    mapscript MAP_SCRIPT_ON_FRAME_TABLE LevelScripts_PokemonTowerOldManLeads
    mapscript MAP_SCRIPT_ON_LOAD PokemonTowerPutBlock
    .byte MAP_SCRIPT_TERMIN

LevelScripts_PokemonTowerOldManLeads:
    levelscript VAR_LVL_PKMNTOWER_POSTGAME_F1, 0, LevelScript_PokemonTowerOldManLeads
    .hword MAP_SCRIPT_TERMIN

PokemonTowerPutBlock:
    checkflag FLAG_BEAT_MORTY_REMATCH
    if 0x1 _goto DoNothing 
    compare VAR_LVL_PKMNTOWER_POSTGAME_F1 0x0
    if equal _goto DoNothing 
    goto SetBlocks
    end

DoNothing:
    end

SetBlocks:
    setmaptile 0x3 0xA 0x291 0x1
    special 0x8E
    end


LevelScript_PokemonTowerOldManLeads:
    lock
    clearflag 0x200
    showsprite 0x5
    applymovement PLAYER WalkRight
    waitmovement 0x0
    applymovement 0x5 FaceLeft
    waitmovement 0x0
    sound 0x26
    setmaptile 0x3 0xA 0x291 0x1
    special 0x8E
    checksound
    msgbox gText_PkmnTower_GateKeeperRules MSG_NORMAL
    clearflag FLAG_HIDEPKMNTOWER_NPC
    setvar VAR_LVL_PKMNTOWER_POSTGAME_F1 0x1
    setflag FLAG_DISABLE_START_MENU_BAG
    setflag 0x200
    release
    end
    
WalkRight:
    .byte walk_right
    .byte end_m

.global EventScript_PokemonTower_AceTrainer1
EventScript_PokemonTower_AceTrainer1:
    lock
    faceplayer
    msgbox gText_PkmnTower_AceTrainer1_1 MSG_YESNO
    compare LASTRESULT NO
    if equal _goto releaseend
    msgbox gText_PkmnTower_AceTrainer1_2 MSG_NORMAL
    special 0x0
    setflag FLAG_DISABLE_BAG
    trainerbattle3 0x3 0x7C 0x0 gText_PkmnTower_AceTrainer1_3
ChooseHealMons:
    msgbox gText_PkmnTower_AceTrainer1_4 MSG_YESNO
    compare LASTRESULT NO
    if equal _goto HowBraveOfYou
	setvar 0x8003 0x0 @From party
	special 0x9F @choose from party
	waitstate
	compare 0x8004 0x6
	if 0x4 _goto ChooseHealMons
    special 0x7C
    msgbox gText_PkmnTower_AceTrainer1_4_2 MSG_NORMAL
    callasm HealMonInPartySlot 
ChooseHealMons2:
    msgbox gText_PkmnTower_AceTrainer1_4_3 MSG_YESNO
    compare LASTRESULT NO
    if equal _goto HowBraveOfYou
    setvar 0x8003 0x0 @From party
	special 0x9F @choose from party
	waitstate
	compare 0x8004 0x6
	if 0x4 _goto ChooseHealMons2
    special 0x7C
    msgbox gText_PkmnTower_AceTrainer1_4_2 MSG_NORMAL
    callasm HealMonInPartySlot
    goto EndOfAceTrainer1
    end

releaseend:
    release
    end

HowBraveOfYou:
    msgbox gText_PkmnTower_AceTrainer1_5 MSG_NORMAL
    goto EndOfAceTrainer1

EndOfAceTrainer1:
    applymovement 0x4 LookUp
    waitmovement 0x0
    sound 0x26
    call SetBlocks1
    checksound
    msgbox gText_PkmnTower_AceTrainer1_6 MSG_NORMAL
    fadescreen 0x1
    setflag FLAG_BEAT_ACE_TRAINER_1
    hidesprite 0x4
    sound 0x9
    checksound
    fadescreen 0x0
    release
    end
SetBlocks1:
    setmaptile 0xA 0x13 0x282 0x0
    setmaptile 0xB 0x13 0x282 0x0
    setmaptile 0xC 0x13 0x282 0x0
    setmaptile 0xD 0x13 0x282 0x0
    special 0x8E
    return

LookUp:
    .byte look_up
    .byte end_m

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 
.global EventScript_PokemonTower_AceTrainer2
EventScript_PokemonTower_AceTrainer2:
    lock
    faceplayer
    msgbox gText_PkmnTower_AceTrainer2_1 MSG_YESNO
    compare LASTRESULT NO
    if equal _goto releaseend
    msgbox gText_PkmnTower_AceTrainer2_2 MSG_NORMAL
    @ setflag FLAG_SMALL_TRAINER_LEVELS
    setflag FLAG_DISABLE_BAG
    trainerbattle3 0x3 0x52 0x0 gText_PkmnTower_AceTrainer2_3
ChooseHealMonsAce2:
    msgbox gText_PkmnTower_AceTrainer2_4 MSG_YESNO
    compare LASTRESULT NO
    if equal _goto HowBraveOfYou2
	setvar 0x8003 0x0 @From party
	special 0x9F @choose from party
	waitstate
	compare 0x8004 0x6
	if 0x4 _goto ChooseHealMonsAce2
    special 0x7C
    msgbox gText_PkmnTower_AceTrainer2_4_2 MSG_NORMAL
    callasm HealMonInPartySlot 
ChooseHealMonsAce2_2:
    msgbox gText_PkmnTower_AceTrainer2_4_3 MSG_YESNO
    compare LASTRESULT NO
    if equal _goto HowBraveOfYou2
    setvar 0x8003 0x0 @From party
	special 0x9F @choose from party
	waitstate
	compare 0x8004 0x6
	if 0x4 _goto ChooseHealMonsAce2_2
    special 0x7C
    msgbox gText_PkmnTower_AceTrainer2_4_2 MSG_NORMAL
    callasm HealMonInPartySlot
    goto EndOfAceTrainer2
    end

HowBraveOfYou2:
    msgbox gText_PkmnTower_AceTrainer2_5 MSG_NORMAL
    goto EndOfAceTrainer2

EndOfAceTrainer2:
    applymovement 0x3 LookUp
    waitmovement 0x0
    sound 0x26
    call SetBlocks2
    checksound
    msgbox gText_PkmnTower_AceTrainer2_6 MSG_NORMAL
    fadescreen 0x1
    setflag FLAG_BEAT_ACE_TRAINER_2
    hidesprite 0x3
    sound 0x9
    checksound
    fadescreen 0x0
    release
    end

SetBlocks2:
    setmaptile 0xA 0xE 0x282 0x0
    setmaptile 0xB 0xE 0x282 0x0
    setmaptile 0xC 0xE 0x282 0x0
    setmaptile 0xD 0xE 0x282 0x0
    special 0x8E
    return

@@@@@@@@@@@@@@@@@@@@@
.global EventScript_PokemonTower_AceTrainer3
EventScript_PokemonTower_AceTrainer3:
    lock
    faceplayer
    msgbox gText_PkmnTower_AceTrainer3_1 MSG_YESNO
    compare LASTRESULT NO
    if equal _goto releaseend
    msgbox gText_PkmnTower_AceTrainer3_2 MSG_NORMAL
    @ setflag FLAG_SMALL_TRAINER_LEVELS
    setflag FLAG_DISABLE_BAG
    trainerbattle3 0x3 0x71 0x0 gText_PkmnTower_AceTrainer2_3
ChooseHealMonsAce3:
    msgbox gText_PkmnTower_AceTrainer3_4 MSG_YESNO
    compare LASTRESULT NO
    if equal _goto HowBraveOfYou3
	setvar 0x8003 0x0 @From party
	special 0x9F @choose from party
	waitstate
	compare 0x8004 0x6
	if 0x4 _goto ChooseHealMonsAce3
    special 0x7C
    msgbox gText_PkmnTower_AceTrainer1_4_2 MSG_NORMAL
    callasm HealMonInPartySlot 
ChooseHealMonsAce3_2:
    msgbox gText_PkmnTower_AceTrainer2_4_3 MSG_YESNO
    compare LASTRESULT NO
    if equal _goto HowBraveOfYou3
    setvar 0x8003 0x0 @From party
	special 0x9F @choose from party
	waitstate
	compare 0x8004 0x6
	if 0x4 _goto ChooseHealMonsAce3_2
    special 0x7C
    msgbox gText_PkmnTower_AceTrainer1_4_2 MSG_NORMAL
    callasm HealMonInPartySlot
    goto EndOfAceTrainer3
    end


HowBraveOfYou3:
    msgbox gText_PkmnTower_AceTrainer3_5 MSG_NORMAL
    goto EndOfAceTrainer3

EndOfAceTrainer3:
    applymovement 0x2 LookUp
    waitmovement 0x0
    sound 0x26
    call SetBlocks3
    checksound
    msgbox gText_PkmnTower_AceTrainer3_6 MSG_NORMAL
    fadescreen 0x1
    setflag FLAG_BEAT_ACE_TRAINER_3
    hidesprite 0x2
    sound 0x9
    checksound
    fadescreen 0x0
    release
    end

SetBlocks3:
    setmaptile 0xA 0x9 0x282 0x0
    setmaptile 0xB 0x9 0x282 0x0
    setmaptile 0xC 0x9 0x282 0x0
    setmaptile 0xD 0x9 0x282 0x0
    special 0x8E
    return

.global EventScript_PokemonTower_OldManWarp
EventScript_PokemonTower_OldManWarp:
    lock
    faceplayer
    msgbox gText_PkmnTower_GateKeeperLeave MSG_YESNO
    compare LASTRESULT YES
    if equal _goto WarpPlayer
    release
    end

WarpPlayer:
    clearflag FLAG_DISABLE_START_MENU_BAG
    warp 0x1 0x5E 0x2 0x0 0x0
    release
    end

.global gMapScripts_PokemonTowerPostGameFloor2
gMapScripts_PokemonTowerPostGameFloor2:
    mapscript MAP_SCRIPT_ON_LOAD PokemonTowerPutBlock2
    .byte MAP_SCRIPT_TERMIN

PokemonTowerPutBlock2:
    checkflag FLAG_BEAT_ACE_TRAINER_1
    if 0x1 _call SetBlocks1 
    checkflag FLAG_BEAT_ACE_TRAINER_2
    if 0x1 _call SetBlocks2
    checkflag FLAG_BEAT_ACE_TRAINER_3
    if 0x1 _call SetBlocks3
    end

.global EventScript_PokemonTower_MortyTile
EventScript_PokemonTower_MortyTile:
    lock
    applymovement 0x1 LookDown
    waitmovement 0x0
    msgbox gText_PkmnTower_Morty_1 MSG_NORMAL
    applymovement 0x1 LookUp
    waitmovement 0x0
    msgbox gText_PkmnTower_Morty_2 MSG_NORMAL
    applymovement 0x1 LookDown
    waitmovement 0x0
    msgbox gText_PkmnTower_Morty_3 MSG_NORMAL
    @ setflag FLAG_SMALL_TRAINER_LEVELS
    trainerbattle3 0x3 0x1C 0x0 gText_PkmnTower_MortyLoss
    setflag FLAG_BEAT_MORTY_REMATCH
    msgbox gText_PkmnTower_Morty_4 MSG_NORMAL
    giveitem ITEM_GHOSTIUM_Z 0x1 MSG_OBTAIN
    msgbox gText_PkmnTower_Morty_5 MSG_NORMAL
    fadescreen 0x1
    hidesprite 0x1
    sound 0x9
    checksound
    setvar VAR_PKMNTOWER_MORTY_SCRIPT 0x1
    setflag FLAG_HIDEPKMNTOWER_NPC
    clearflag FLAG_DISABLE_START_MENU_BAG
    fadescreen 0x0
    release
    end

LookDown:
    .byte look_down
    .byte end_m


.global EventScript_PokemonTower_Marshadow
EventScript_PokemonTower_Marshadow:
	lock
    faceplayer
    cry SPECIES_MARSHADOW 0x2
    waitcry
    pause 0x2
    wildbattle SPECIES_MARSHADOW 100 0x00
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x4
    if 0x1 _goto Moveback2
    fadescreen 0x1
    hidesprite 0x800F
    setflag FLAG_DONE_MARSHADOW
    fadescreen 0x0
    msgboxsign
    msgbox gText_KyogrePrimalOrb MSG_KEEPOPEN
    closeonkeypress
    giveitem ITEM_MARSHADIUM_Z 0x1 MSG_FIND 
    release
    end

Moveback2:
    release 
    end
