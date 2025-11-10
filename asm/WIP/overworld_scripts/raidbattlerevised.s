.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"

.equ SPECIAL_IS_RAID_BATTLE_AVAILABLE, 0x115
.equ SPECIAL_RAID_BATTLE_INTRO, 0x116
.equ SPECIAL_CREATE_RAID_MON, 0x117
.equ SPECIAL_START_RAID_BATTLE, 0x118 
.equ SPECIAL_SET_RAID_BATTLE_FLAG, 0x119
.equ SPECIAL_GIVE_RAID_BATTLE_REWARDS, 0x11C
.equ FLAG_TAG_BATTLE, 0x908
.equ FLAG_DYNAMAX_BATTLE, 0x918
.equ VAR_DAILY_EVENT, 0x504A @ Also 0x504B
.equ VAR_CERULEANCAVE, 0x504C @also 0x504D
.equ VAR_MTMOON, 0x504E @also 0x504F 
.equ VAR_ROUTE4, 0x507E @also 0x507F
.equ VAR_ROUTETHREE, 0x5080 @also 0x5081 
.equ VAR_ROUTE24, 0x5082 @0x506D also 0x506E
.equ VAR_ROUTE25, 0x5084 @also 0x5062
.equ VAR_ROUTE5, 0x5086 @also 0x5064
.equ VAR_ROUTE6, 0x5088 @also 0x5066 
.equ VAR_ROUTE11, 0x5098 @also 0x5099
.equ VAR_DIGLETSSCAVE, 0x5070 @also 0x5071
.equ VAR_ROUTE2, 0x5072 @also 0x5073
.equ VAR_ROUTE9, 0x5074 @also 0x5075
.equ VAR_ROUTE10, 0x5076 @also 0x5077
.equ VAR_ROCKTUNNEL, 0x5078 @also 0x5079
.equ VAR_ROUTE8, 0x507A @also 0x507B
.equ VAR_ROUTE7, 0x507C @also 0x507D
.equ VAR_POWERPLANT, 0x508A @also 0x508B 
.equ VAR_SEAFOAM, 0x508C @also 0x508D
.equ VAR_ROUTE12, 0x508E @also 0x508F 
.equ VAR_ROUTE13, 0x5090 @also 0x5091 
.equ VAR_ROUTE14, 0x5092 @also 0x5093 
.equ VAR_ROUTE15, 0x5094 @also 0x5095
.equ VAR_PKMNMANSION, 0x5096 @also 0x5097
.equ VAR_VIRIDIANFOREST, 0x5104 @also 0x5105
.equ ITEM_WISHING_PIECE, 0x281
.equ VAR_WISHING_PIECE_COUNT, 0x5137

.global EventScript_VictoryRoadRaid
EventScript_VictoryRoadRaid:
    @ setvar 0x8000 VAR_DAILY_EVENT
    @ setvar 0x8001 0x0
    @ special2 LASTRESULT 0xA0
    @ compare LASTRESULT 0x0 
    @ if equal _goto RaidScript_Cancel @If we proceed in script that means it's a new day 
    call RaidBattle 
    setvar 0x4000 0x0
    call RaidScript_GiveReward 
    goto RaidScript_End
    end 

RaidBattle: 
    @ setvar 0x8000 0x0  @Clear Raid Script flag 
    @ special 0x11A
    @ lock

    special SPECIAL_IS_RAID_BATTLE_AVAILABLE
    compare LASTRESULT 0x0 
    if equal _goto RaidScript_Cancel 
    msgbox gText_StartRaidBattle MSG_YESNO 
    compare LASTRESULT YES 
    if NO _goto RaidScript_EndClear 
    fadescreen FADEOUT_BLACK
    sound 0x9
    checksound
    special SPECIAL_RAID_BATTLE_INTRO
    waitstate
    compare LASTRESULT 0x0 
    if equal _goto RaidScript_EndClear
    msgbox gText_SelectThree MSG_NORMAL
    special 0x27
	special 0xF5
	waitstate
    compare LASTRESULT NO
	if equal _goto Cancel
	special 0x28
    setflag FLAG_TAG_BATTLE 
    setflag FLAG_DYNAMAX_BATTLE
    msgbox gText_RaidTeamUp MSG_NORMAL
    special SPECIAL_CREATE_RAID_MON 
    special SPECIAL_START_RAID_BATTLE
    waitstate 
    special SPECIAL_SET_RAID_BATTLE_FLAG 
    applymovement 0x800F LookDown
    waitmovement 0x0
    special2 LASTRESULT 0xB4
    compare LASTRESULT 0x4 @Ran 
    if equal _goto RaidScript_End2 
    compare LASTRESULT 0x5 @Teleported, lost battle
    if equal _goto RaidScript_End2
    @ special SPECIAL_SET_RAID_BATTLE_FLAG 
    @ goto RaidScript_GiveReward
    return 


LookLeft:
    .byte look_left
    .byte end_m  
LookDown:
    .byte look_down
    .byte end_m

Cancel:
    special 0x28
    clearflag FLAG_TAG_BATTLE 
    clearflag FLAG_DYNAMAX_BATTLE
    release
    end

RaidScript_GiveReward:
    special SPECIAL_GIVE_RAID_BATTLE_REWARDS 
    compare LASTRESULT 0x1
    if equal _goto RaidScript_End2
    callstd MSG_FIND 
    goto RaidScript_GiveReward 

RaidScript_End2:
    return 

RaidScript_End: 
    setvar 0x8000 VAR_DAILY_EVENT
    setvar 0x8001 0x0
    special 0xA1
    release 
    end 

RaidScript_Cancel:
    msgbox gText_StartRaidBattle2 MSG_NORMAL 
    checkitem ITEM_WISHING_PIECE 0x1
    compare 0x800D 0x1
    if greaterorequal _goto AskToThrowAWishingPiece
    release 
    end 

AskToThrowAWishingPiece:
    msgbox gText_RaidDen_AskWishingPiece MSG_YESNO
    compare LASTRESULT YES
    if equal _call RespawnRaidDen
    release
    end

RespawnRaidDen:
    setvar 0x8000 0x1
    special 0x11A
    addvar VAR_WISHING_PIECE_COUNT 0x1
    msgbox gText_RaidDen_ThrewWishingPiece MSG_NORMAL
    removeitem ITEM_WISHING_PIECE 0x1
    callasm DetermineRaidStars + 1 
    release
    end

RaidScript_EndClear:
    applymovement 0x800F LookDown
    waitmovement 0x0
    setvar 0x8000 0x0  @Clear Raid Script flag 
    clearflag FLAG_DYNAMAX_BATTLE @Prevent Dynamax lol
    special 0x11A
    release 
    end 

.global EventScript_MtMoonRaid
EventScript_MtMoonRaid:
    @ setvar 0x8000 VAR_MTMOON
    @ setvar 0x8001 0x0
    @ special2 LASTRESULT 0xA0
    @ compare LASTRESULT 0x0 
    @ if equal _goto RaidScript_Cancel @If we proceed in script that means it's a new day 
    call RaidBattle 
    setvar 0x4000 0x0
    call RaidScript_GiveReward 
    goto RaidScript_EndMtMoon
    end 

RaidScript_EndMtMoon: 
    setvar 0x8000 VAR_MTMOON
    setvar 0x8001 0x0
    special 0xA1
    release 
    end 

.global EventScript_Route4Raid
EventScript_Route4Raid:
    @ setvar 0x8000 VAR_ROUTE4
    @ setvar 0x8001 0x0
    @ special2 LASTRESULT 0xA0
    @ compare LASTRESULT 0x0 
    @ if equal _goto RaidScript_Cancel @If we proceed in script that means it's a new day 
    call RaidBattle 
    setvar 0x4000 0x0
    call RaidScript_GiveReward
    goto RaidScript_EndRoute4  
    end 

RaidScript_EndRoute4: 
    setvar 0x8000 VAR_ROUTE4
    setvar 0x8001 0x0
    special 0xA1
    release 
    end 

.global EventScript_Route3Raid 
EventScript_Route3Raid:
    @ setvar 0x8000 VAR_ROUTETHREE 
    @ setvar 0x8001 0x0
    @ special2 LASTRESULT 0xA0
    @ compare LASTRESULT 0x0 
    @ if equal _goto RaidScript_Cancel @If we proceed in script that means it's a new day 
    call RaidBattle 
    setvar 0x4000 0x0
    call RaidScript_GiveReward
    goto RaidScript_EndRoute3 
    end 

RaidScript_EndRoute3: @Here 
    setvar 0x8000 VAR_ROUTETHREE
    setvar 0x8001 0x0
    special 0xA1
    release 
    end 

.global EventScript_Route24Raid @Here 
EventScript_Route24Raid:
    @ setvar 0x8000 VAR_ROUTE24 @Here 
    @ setvar 0x8001 0x0
    @ special2 LASTRESULT 0xA0
    @ compare LASTRESULT 0x0 
    @ if equal _goto RaidScript_Cancel @If we proceed in script that means it's a new day 
    call RaidBattle 
    setvar 0x4000 0x0
    call RaidScript_GiveReward
    goto RaidScript_EndRoute24 @ Here
    end 

RaidScript_EndRoute24: @Here 
    setvar 0x8000 VAR_ROUTE24 @Here 
    setvar 0x8001 0x0
    special 0xA1
    release 
    end 

.global EventScript_Route25Raid @Here 
EventScript_Route25Raid:
    @ setvar 0x8000 VAR_ROUTE25 @Here 
    @ setvar 0x8001 0x0
    @ special2 LASTRESULT 0xA0
    @ compare LASTRESULT 0x0 
    @ if equal _goto RaidScript_Cancel @If we proceed in script that means it's a new day 
    call RaidBattle 
    setvar 0x4000 0x0
    call RaidScript_GiveReward
    goto RaidScript_EndRoute25 @ Here
    end 

RaidScript_EndRoute25: @Here 
    setvar 0x8000 VAR_ROUTE25 @Here 
    setvar 0x8001 0x0
    special 0xA1
    release 
    end 

.global EventScript_Route5Raid @Here 
EventScript_Route5Raid:
    @ setvar 0x8000 VAR_ROUTE5 @Here 
    @ setvar 0x8001 0x0
    @ special2 LASTRESULT 0xA0
    @ compare LASTRESULT 0x0 
    @ if equal _goto RaidScript_Cancel @If we proceed in script that means it's a new day 
    call RaidBattle 
    setvar 0x4000 0x0
    call RaidScript_GiveReward
    goto RaidScript_EndRoute5 @ Here
    end 

RaidScript_EndRoute5: @Here 
    setvar 0x8000 VAR_ROUTE5 @Here 
    setvar 0x8001 0x0
    special 0xA1
    release 
    end 

.global EventScript_Route6Raid @Here 
EventScript_Route6Raid:
    @ setvar 0x8000 VAR_ROUTE6 @Here 
    @ setvar 0x8001 0x0
    @ special2 LASTRESULT 0xA0
    @ compare LASTRESULT 0x0 
    @ if equal _goto RaidScript_Cancel @If we proceed in script that means it's a new day 
    call RaidBattle 
    setvar 0x4000 0x0
    call RaidScript_GiveReward
    goto RaidScript_EndRoute6 @ Here
    end 

RaidScript_EndRoute6: @Here 
    setvar 0x8000 VAR_ROUTE6 @Here 
    setvar 0x8001 0x0
    special 0xA1
    release 
    end 

.global EventScript_Route11Raid @Here 
EventScript_Route11Raid:
    @ setvar 0x8000 VAR_ROUTE11 @Here 
    @ setvar 0x8001 0x0
    @ special2 LASTRESULT 0xA0
    @ compare LASTRESULT 0x0 
    @ if equal _goto RaidScript_Cancel @If we proceed in script that means it's a new day 
    call RaidBattle 
    setvar 0x4000 0x0
    call RaidScript_GiveReward
    goto RaidScript_EndRoute11 @ Here
    end 

RaidScript_EndRoute11: @Here 
    setvar 0x8000 VAR_ROUTE11 @Here 
    setvar 0x8001 0x0
    special 0xA1
    release 
    end 

.global EventScript_DigletsCaveRaid @Here 
EventScript_DigletsCaveRaid:
    @ setvar 0x8000 VAR_DIGLETSSCAVE @Here 
    @ setvar 0x8001 0x0
    @ special2 LASTRESULT 0xA0
    @ compare LASTRESULT 0x0 
    @ if equal _goto RaidScript_Cancel @If we proceed in script that means it's a new day 
    call RaidBattle 
    setvar 0x4000 0x0
    call RaidScript_GiveReward
    goto RaidScript_EndDigletsCave @ Here
    end 

RaidScript_EndDigletsCave: @Here 
    setvar 0x8000 VAR_DIGLETSSCAVE @Here 
    setvar 0x8001 0x0
    special 0xA1
    release 
    end 

.global EventScript_Route2Raid @Here 
EventScript_Route2Raid:
    @ setvar 0x8000 VAR_ROUTE2 @Here 
    @ setvar 0x8001 0x0
    @ special2 LASTRESULT 0xA0
    @ compare LASTRESULT 0x0 
    @ if equal _goto RaidScript_Cancel @If we proceed in script that means it's a new day 
    @ setvar VAR_WISHING_PIECE_COUNT 0x0
    call RaidBattle 
    setvar 0x4000 0x0
    call RaidScript_GiveReward
    goto RaidScript_EndRoute2 @ Here
    end 

RaidScript_EndRoute2: @Here 
    setvar 0x8000 VAR_ROUTE2 @Here 
    setvar 0x8001 0x0
    special 0xA1
    release 
    end 

.global EventScript_Route9Raid @Here 
EventScript_Route9Raid:
    @ setvar 0x8000 VAR_ROUTE9 @Here 
    @ setvar 0x8001 0x0
    @ special2 LASTRESULT 0xA0
    @ compare LASTRESULT 0x0 
    @ if equal _goto RaidScript_Cancel @If we proceed in script that means it's a new day 
    call RaidBattle 
    setvar 0x4000 0x0
    call RaidScript_GiveReward
    goto RaidScript_EndRoute9 @ Here
    end 

RaidScript_EndRoute9: @Here 
    setvar 0x8000 VAR_ROUTE9 @Here 
    setvar 0x8001 0x0
    special 0xA1
    release 
    end 

.global EventScript_Route10Raid @Here 
EventScript_Route10Raid:
    @ setvar 0x8000 VAR_ROUTE10 @Here 
    @ setvar 0x8001 0x0
    @ special2 LASTRESULT 0xA0
    @ compare LASTRESULT 0x0 
    @ if equal _goto RaidScript_Cancel @If we proceed in script that means it's a new day 
    call RaidBattle 
    setvar 0x4000 0x0
    call RaidScript_GiveReward
    goto RaidScript_EndRoute10 @ Here
    end 

RaidScript_EndRoute10: @Here 
    setvar 0x8000 VAR_ROUTE10 @Here 
    setvar 0x8001 0x0
    special 0xA1
    release 
    end 


.global EventScript_RockTunnelRaid
EventScript_RockTunnelRaid:
    @ setvar 0x8000 VAR_ROCKTUNNEL
    @ setvar 0x8001 0x0
    @ special2 LASTRESULT 0xA0
    @ compare LASTRESULT 0x0 
    @ if equal _goto RaidScript_Cancel @If we proceed in script that means it's a new day 
    call RaidBattle 
    setvar 0x4000 0x0
    call RaidScript_GiveReward
    goto RaidScript_EndRockTunnel
    end 

RaidScript_EndRockTunnel: 
    setvar 0x8000 VAR_ROCKTUNNEL
    setvar 0x8001 0x0
    special 0xA1
    release 
    end 

.global EventScript_Route16Raid
EventScript_Route16Raid:
    @ setvar 0x8000 VAR_ROUTE7 @originally route 7 but route too small, too lazy to change 
    @ setvar 0x8001 0x0
    @ special2 LASTRESULT 0xA0
    @ compare LASTRESULT 0x0 
    @ if equal _goto RaidScript_Cancel @If we proceed in script that means it's a new day 
    call RaidBattle 
    setvar 0x4000 0x0
    call RaidScript_GiveReward
    goto RaidScript_EndRoute16
    end 

RaidScript_EndRoute16: 
    setvar 0x8000 VAR_ROUTE7
    setvar 0x8001 0x0
    special 0xA1
    release 
    end 

.global EventScript_Route8Raid
EventScript_Route8Raid:
    @ setvar 0x8000 VAR_ROUTE8
    @ setvar 0x8001 0x0
    @ special2 LASTRESULT 0xA0
    @ compare LASTRESULT 0x0 
    @ if equal _goto RaidScript_Cancel @If we proceed in script that means it's a new day 
    call RaidBattle 
    setvar 0x4000 0x0
    call RaidScript_GiveReward
    goto RaidScript_EndRoute8
    end 

RaidScript_EndRoute8: 
    setvar 0x8000 VAR_ROUTE8
    setvar 0x8001 0x0
    special 0xA1
    release 
    end 

.global EventScript_Route12Raid
EventScript_Route12Raid:
    @ setvar 0x8000 VAR_ROUTE12
    @ setvar 0x8001 0x0
    @ special2 LASTRESULT 0xA0
    @ compare LASTRESULT 0x0 
    @ if equal _goto RaidScript_Cancel @If we proceed in script that means it's a new day 
    call RaidBattle 
    setvar 0x4000 0x0
    call RaidScript_GiveReward
    goto RaidScript_EndRoute12
    end 

RaidScript_EndRoute12: 
    setvar 0x8000 VAR_ROUTE12
    setvar 0x8001 0x0
    special 0xA1
    release 
    end 

.global EventScript_Route13Raid
EventScript_Route13Raid:
    @ setvar 0x8000 VAR_ROUTE13
    @ setvar 0x8001 0x0
    @ special2 LASTRESULT 0xA0
    @ compare LASTRESULT 0x0 
    @ if equal _goto RaidScript_Cancel @If we proceed in script that means it's a new day 
    call RaidBattle 
    setvar 0x4000 0x0
    call RaidScript_GiveReward
    goto RaidScript_EndRoute13
    end 

RaidScript_EndRoute13: 
    setvar 0x8000 VAR_ROUTE13
    setvar 0x8001 0x0
    special 0xA1
    release 
    end 

.global EventScript_Route14Raid
EventScript_Route14Raid:
    @ setvar 0x8000 VAR_ROUTE14
    @ setvar 0x8001 0x0
    @ special2 LASTRESULT 0xA0
    @ compare LASTRESULT 0x0 
    @ if equal _goto RaidScript_Cancel @If we proceed in script that means it's a new day 
    call RaidBattle 
    setvar 0x4000 0x0
    call RaidScript_GiveReward
    goto RaidScript_EndRoute14
    end 

RaidScript_EndRoute14: 
    setvar 0x8000 VAR_ROUTE14
    setvar 0x8001 0x0
    special 0xA1
    release 
    end 

.global EventScript_PkmnMansionRaid
EventScript_PkmnMansionRaid:
    @ setvar 0x8000 VAR_PKMNMANSION
    @ setvar 0x8001 0x0
    @ special2 LASTRESULT 0xA0
    @ compare LASTRESULT 0x0 
    @ if equal _goto RaidScript_Cancel @If we proceed in script that means it's a new day 
    call RaidBattle 
    setvar 0x4000 0x0
    call RaidScript_GiveReward
    goto RaidScript_EndPkmnMansion
    end 

RaidScript_EndPkmnMansion: 
    setvar 0x8000 VAR_PKMNMANSION
    setvar 0x8001 0x0
    special 0xA1
    release 
    end 


.global EventScript_Route15Raid
EventScript_Route15Raid:
    @ setvar 0x8000 VAR_ROUTE15
    @ setvar 0x8001 0x0
    @ special2 LASTRESULT 0xA0
    @ compare LASTRESULT 0x0 
    @ if equal _goto RaidScript_Cancel @If we proceed in script that means it's a new day 
    call RaidBattle 
    setvar 0x4000 0x0
    call RaidScript_GiveReward
    goto RaidScript_EndRoute15
    end 

RaidScript_EndRoute15: 
    setvar 0x8000 VAR_ROUTE15
    setvar 0x8001 0x0
    special 0xA1
    release 
    end 


.global EventScript_PowerPlantRaid 
EventScript_PowerPlantRaid:
    @ setvar 0x8000 VAR_POWERPLANT
    @ setvar 0x8001 0x0
    @ special2 LASTRESULT 0xA0
    @ compare LASTRESULT 0x0 
    @ if equal _goto RaidScript_Cancel @If we proceed in script that means it's a new day 
    call RaidBattle 
    setvar 0x4000 0x0
    call RaidScript_GiveReward
    goto RaidScript_EndPowerPlant
    end 

RaidScript_EndPowerPlant:
    setvar 0x8000 VAR_POWERPLANT
    setvar 0x8001 0x0
    special 0xA1
    release 
    end 

.global EventScript_SeafoamIslandsRaid 
EventScript_SeafoamIslandsRaid:
    @ setvar 0x8000 VAR_SEAFOAM
    @ setvar 0x8001 0x0
    @ special2 LASTRESULT 0xA0
    @ compare LASTRESULT 0x0 
    @ if equal _goto RaidScript_Cancel @If we proceed in script that means it's a new day 
    call RaidBattle 
    setvar 0x4000 0x0
    call RaidScript_GiveReward
    goto RaidScript_EndSeafoam
    end 

RaidScript_EndSeafoam:
    setvar 0x8000 VAR_SEAFOAM
    setvar 0x8001 0x0
    special 0xA1
    release 
    end 

.global EventScript_ViridianForestRaid 
EventScript_ViridianForestRaid:
    @ setvar 0x8000 VAR_VIRIDIANFOREST
    @ setvar 0x8001 0x0
    @ special2 LASTRESULT 0xA0
    @ compare LASTRESULT 0x0 
    @ if equal _goto RaidScript_Cancel @If we proceed in script that means it's a new day 
    call RaidBattle 
    setvar 0x4000 0x0
    call RaidScript_GiveReward
    goto RaidScript_EndViridianForest
    end 

RaidScript_EndViridianForest:
    setvar 0x8000 VAR_VIRIDIANFOREST
    setvar 0x8001 0x0
    special 0xA1
    release 
    end 

.global EventScript_CeruleanCaveRaid
EventScript_CeruleanCaveRaid:
    @ setvar 0x8000 VAR_CERULEANCAVE
    @ setvar 0x8001 0x0
    @ special2 LASTRESULT 0xA0
    @ compare LASTRESULT 0x0 
    @ if equal _goto RaidScript_Cancel @If we proceed in script that means it's a new day 
    call RaidBattle 
    setvar 0x4000 0x0
    call RaidScript_GiveReward
    goto RaidScript_EndCerulean 
    end 

RaidScript_EndCerulean: 
    setvar 0x8000 VAR_CERULEANCAVE
    setvar 0x8001 0x0
    special 0xA1
    release 
    end 
