.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s" 

@Notes
@edited:
@Removed warps for Lavender Tower Event
@Removed time in seafoam islands (used to be 6)

.global EventScript_Route16_PsychicGirl

EventScript_Route16_PsychicGirl:
    checkitem ITEM_HM02 0x1 
    compare 0x800D 0x1
    if lessthan _goto GiveFly
    checkitem ITEM_TRI_PASS 0x1
    compare 0x800D 0x1
    if equal _goto WorthyChallenger
    lock
    faceplayer
    msgbox gText_Route16_PsychicGirlSense MSG_KEEPOPEN
    pause 0x5
    closeonkeypress
    checkflag 0x931 
    if 0x0 _goto FightBugsy
    checkflag 0x933 
    if 0x0 _goto FightWhitney
    checkflag 0x1003
    if 0x0 _goto FightMorty
    checkflag 0x950
    if 0x0 _goto FightChuck
    checkflag 0x96C
    if 0x0 _goto FightPryce
    checkflag 0x96D
    if 0x0 _goto FightJasmine
    checkflag 0x959
    if 0x0 _goto FightBrockRe
    checkflag 0x932
    if 0x0 _goto FightMistyRe
    checkflag 0x934
    if 0x0 _goto FightSurgeRe
    checkflag 0x98D
    if 0x0 _goto FightKid
    checkflag 0x945
    if 0x0 _goto FightErikaRe
    checkflag 0x93D
    if 0x0 _goto FightJotard
    checkflag 0x1004
    if 0x0 _goto GetMortyMega
    checkflag 0x82C
    if 0x0 _goto FightLeague
    msgbox gText_Route16_PsychicGirlReady MSG_FACE @if we got here that means we are ready for postgame!
    giveitem ITEM_TRI_PASS 0x1 MSG_OBTAIN
    lock
    faceplayer
    setvar 0x4076 0x1 @allows you to go to Seviis
    setvar 0x4071 0x4
    setflag 0x846
    copyvar 0x8012 0x8013
    goto WorthyChallenger
    @ goto NoMore
    end 

FightBugsy:
    msgbox gText_Route16_PsychicGirlRoute25 MSG_NORMAL
    release
    end 

FightWhitney:
    msgbox gText_Route16_PsychicGirlRoute11 MSG_NORMAL
    release
    end 

FightMorty:
    msgbox gText_Route16_PsychicGirlLavender MSG_NORMAL
    release
    end 

FightChuck:
    msgbox gText_Route16_PsychicGirlDojo MSG_NORMAL
    release
    end 

FightPryce:
    msgbox gText_Route16_PsychicGirlSeafoam MSG_NORMAL
    release
    end 

FightJasmine:
    msgbox gText_Route16_PsychicGirlCinnabar MSG_NORMAL
    release
    end 

FightBrockRe:
    msgbox gText_Route16_PsychicGirlPewter MSG_NORMAL
    release
    end 

FightMistyRe:
    msgbox gText_Route16_PsychicGirlCerulean MSG_NORMAL
    release
    end 

FightSurgeRe:
    msgbox gText_Route16_PsychicGirlVermilion MSG_NORMAL
    release
    end 

FightKid:
    msgbox gText_Route16_PsychicGirlSaffron MSG_NORMAL
    release 
    end

FightErikaRe:
    msgbox gText_Route16_PsychicGirlCeladon MSG_NORMAL
    release 
    end

FightJotard:
    msgbox gText_Route16_PsychicGirlJotard MSG_NORMAL
    release 
    end

FightLeague:
    msgbox gText_Route16_PsychicGirlChampion MSG_NORMAL
    release 
    end

WorthyChallenger:
    msgbox gText_Route16_PsychicGirlWorthy MSG_FACE
    release
    end

NoMore:
    msgbox gText_Route16_PsychicGirlNoMore MSG_FACE
    release
    end

GiveFly:
    msgbox gText_Route16_PsychicGirlFly MSG_FACE
    giveitem ITEM_HM02 0x1 MSG_OBTAIN 
    msgbox gText_Route16_PsychicGirlStrong MSG_NORMAL 
    release 
    end

GetMortyMega:
    msgbox gText_Route16_PsychicGetMortyMega MSG_FACE
    release
    end
.global EventScript_Route16_Absol
EventScript_Route16_Absol:
    cry SPECIES_ABSOL 0x2
    msgbox gText_Route16_Absol1 MSG_FACE
    waitcry
    release
    end
