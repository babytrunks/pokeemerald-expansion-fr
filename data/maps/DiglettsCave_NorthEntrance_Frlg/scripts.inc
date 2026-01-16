DiglettsCave_NorthEntrance_Frlg_MapScripts::
	.byte 0

DiglettsCave_NorthEntrance_EventScript_Hiker::
	msgbox DiglettsCave_NorthEntrance_RockTunnelPitchBlack, MSGBOX_NPC
	end

DiglettsCave_NorthEntrance_EventScript_ItemHardStone::
    finditem ITEM_HARD_STONE
	end


DiglettsCave_NorthEntrance_RockTunnelPitchBlack::
    .string "I went inside Rock Tunnel, but it's\n"
    .string "pitch-black and scary in there.\p"
    .string "If I could use the HM Flash and\n"
    .string "and light it up…$"

