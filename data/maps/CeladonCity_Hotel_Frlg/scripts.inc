CeladonCity_Hotel_Frlg_MapScripts::
	.byte 0

CeladonCity_Hotel_EventScript_Receptionist::
	msgbox CeladonCity_Hotel_Text_ThisHotelIsForPeople, MSGBOX_NPC
	end

CeladonCity_Hotel_EventScript_Beauty::
	msgbox CeladonCity_Hotel_Text_OnVacationWithBrotherAndBoyfriend, MSGBOX_NPC
	end

CeladonCity_Hotel_EventScript_BeautyBoyfriend::
	msgbox CeladonCity_Hotel_Text_WhyDidSheBringBrother, MSGBOX_NPC
	end

CeladonCity_Hotel_EventScript_BeautyBrother::
	msgbox CeladonCity_Hotel_Text_SisBroughtMeOnVacation, MSGBOX_NPC
	end

CeladonCity_Hotel_EventScript_Jasmine::    @ rename map prefix if needed
    lockall
    faceplayer
    goto_if_set FLAG_DEFEATED_JASMINE, EventScript_Jasmine_Done   @ 0x96D
    msgbox jasmine_Text_1
    msgbox jasmine_Text_2
    msgbox jasmine_Text_3, MSGBOX_YESNO      @ was 0x5, compares LASTRESULT
    goto_if_eq VAR_RESULT, 1, EventScript_Jasmine_Battle
    release
    end


EventScript_Jasmine_Battle::
    msgbox jasmine_Text_4
    special HealPlayerParty                   @ was special 0x0
    trainerbattle_no_intro TRAINER_LEADER_JASMINE, jasmine_Text_Defeat   @ 0x3E
    setflag FLAG_DEFEATED_JASMINE    
    msgbox jasmine_Text_6
    call_if_unset FLAG_UNLOCKED_STAT_EDITOR, EventScript_Whitney_StatEditExplain
    setflag FLAG_UNLOCKED_STAT_EDITOR
    callnative SetBuffer1ToEvCap
	  msgbox johtoLeader_Text_CurrentEvCap
    msgbox jasmine_Text_7
    giveitem ITEM_TM_IRON_HEAD
    @ msgbox jasmine_Text_Take
    release
    end


EventScript_Jasmine_Done::
    msgbox jasmine_Text_10
    release
    end

CeladonCity_Hotel_EventScript_Steelix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_STEELIX_MEGA, CRY_MODE_NORMAL
	msgbox CeladonCity_Hotel_Text_Steelix
	waitmoncry
	release
	end

CeladonCity_Hotel_Text_Steelix::
    .string "Steelix: Oooooaar!$"

CeladonCity_Hotel_Text_ThisHotelIsForPeople::
    .string "Pokémon?\n"
    .string "No, this is a hotel for people.\p"
    .string "We're full up, unfortunately.$"

CeladonCity_Hotel_Text_OnVacationWithBrotherAndBoyfriend::
    .string "I'm on vacation with my brother and\n"
    .string "boyfriend.\p"
    .string "Celadon is such a pretty city!$"

CeladonCity_Hotel_Text_WhyDidSheBringBrother::
    .string "Why?\n"
    .string "Why did she bring her brother?$"

CeladonCity_Hotel_Text_SisBroughtMeOnVacation::
    .string "Yippee! I'm on vacation!\n"
    .string "My sis brought me along! Awesome!$"


jasmine_Text_1::
  .string "{COLOR RED}Hmm… Mega Aggron or Mega Steelix…$"


jasmine_Text_2::
  .string "{COLOR RED}Ah, hello.\p"
  .string "I've only recently acquainted myself\n"
  .string "with Mega Evolution, so I'm still\l"
  .string "figuring things out.$"


jasmine_Text_3::
  .string "{COLOR RED}Um, I'd like to practice, if you don't\n"
  .string "mind…$"


jasmine_Text_4::
  .string "{COLOR RED}Although I'm shy…\n"
  .string "Please don't take me lightly.$"


jasmine_Text_Defeat::
  .string "Well done…$"


jasmine_Text_6::
  .string "{COLOR RED}You have both skill and fortitude.\p"
  .string "Um… I think you'd like this.$"


jasmine_Text_7::
  .string "{COLOR RED}This TM is pretty essential for Steel-\n"
  .string "types. But it also can come in handy\l"
  .string "as coverage to deal with pesky fairies…$"


jasmine_Text_Take::
  .string "{COLOR RED}I do have more to give, but…\p"
  .string "You'll have to show me a Pokémon\n"
  .string "forged in Defense.$"


jasmine_Text_8::
  .string "{COLOR RED}I think it could use more\n"
  .string "protection.\p"
  .string "No… I don't mean that kind…$"


jasmine_Text_Firstmon::
  .string "{COLOR RED}Your {STR_VAR_1}…$"


jasmine_Text_9::
  .string "{COLOR RED}Yes, this Pokémon is quite a\n"
  .string "worthy shield.\p"
  .string "As promised, here you go.$"


jasmine_Text_10::
  .string "{COLOR RED}Steel Pokémon are essential to a\n"
  .string "balanced team. They do well against the\l"
  .string "mighty Dragon-type and the annoying\l"
  .string "Fairy-type.$"
