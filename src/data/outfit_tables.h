#include "constants/global.h"
#include "constants/event_objects.h"

static const u16 sRegionMapPlayerIcon_BrendanGfx[] = INCBIN_U16("graphics/pokenav/region_map/brendan_icon.4bpp");

static const u16 sRegionMapPlayerIcon_RSBrendanGfx[] = INCBIN_U16("graphics/pokenav/region_map/rs_brendan_icon.4bpp");

static const u16 sRegionMapPlayerIcon_MayGfx[] = INCBIN_U16("graphics/pokenav/region_map/may_icon.4bpp");

static const u16 sRegionMapPlayerIcon_RSMayGfx[] = INCBIN_U16("graphics/pokenav/region_map/rs_may_icon.4bpp");

static const u16 sRegionMapPlayerIcon_RedPal[] = INCBIN_U16("graphics/pokenav/region_map/red_icon.gbapal");
static const u8 sRegionMapPlayerIcon_RedGfx[] = INCBIN_U8("graphics/pokenav/region_map/red_icon.4bpp");
static const u16 sRegionMapPlayerIcon_GreenPal[] = INCBIN_U16("graphics/pokenav/region_map/leaf_icon.gbapal");
static const u8 sRegionMapPlayerIcon_GreenGfx[] = INCBIN_U8("graphics/pokenav/region_map/leaf_icon.4bpp");

static const u16 sRegionMapPlayerIcon_AltRedPal[] = INCBIN_U16("graphics/object_events/palettes/rgby_red_icon.gbapal");
static const u8 sRegionMapPlayerIcon_AltRedGfx[] = INCBIN_U8("graphics/object_events/pics/people/rgby_red/rgby_red_icon.4bpp");

static const u16 sRegionMapPlayerIcon_GoldPal[] = INCBIN_U16("graphics/object_events/palettes/gold_icon.gbapal");
static const u8 sRegionMapPlayerIcon_GoldGfx[] = INCBIN_U8("graphics/object_events/pics/people/gold/gold_icon.4bpp");
static const u8 sRegionMapPlayerIcon_KrisGfx[] = INCBIN_U8("graphics/object_events/pics/people/kris/kris_icon.4bpp");
// static const u16 sRegionMapPlayerIcon_AltGreenPal[] = INCBIN_U16("graphics/pokenav/region_map/leaf_icon.gbapal");
// static const u8 sRegionMapPlayerIcon_AltGreenGfx[] = INCBIN_U8("graphics/object_events/pics/people/rgby_red/rgby_red_icon.4bpp");


//! TODO: Should the gfx here be seperated?

static const u8 sFrontierPassPlayerIcons_BrendanMay_Gfx[] = INCBIN_U8("graphics/frontier_pass/map_heads.4bpp");

static const u8 sFrontierPassPlayerIcons_RSBrendanMay_Gfx[] = INCBIN_U8("graphics/frontier_pass/rs_map_heads.4bpp");

#define REGION_MAP_GFX(m, f) { sRegionMapPlayerIcon_ ## m ## Gfx, sRegionMapPlayerIcon_ ## f ## Gfx }

// bandaids to avoid adding unnecessary merge conflicts
// remove these if you have them added/renamed yourself.
#define OBJ_EVENT_GFX_OUTFIT_RS_BRENDAN_NORMAL     OBJ_EVENT_GFX_LINK_RS_BRENDAN
#define OBJ_EVENT_GFX_OUTFIT_RS_BRENDAN_ACRO_BIKE  OBJ_EVENT_GFX_BRENDAN_ACRO_BIKE
#define OBJ_EVENT_GFX_OUTFIT_RS_BRENDAN_SURFING    OBJ_EVENT_GFX_BRENDAN_SURFING
#define OBJ_EVENT_GFX_OUTFIT_RS_BRENDAN_UNDERWATER OBJ_EVENT_GFX_BRENDAN_UNDERWATER
#define OBJ_EVENT_GFX_OUTFIT_RS_BRENDAN_FIELD_MOVE OBJ_EVENT_GFX_BRENDAN_FIELD_MOVE
#define OBJ_EVENT_GFX_OUTFIT_RS_BRENDAN_FISHING    OBJ_EVENT_GFX_BRENDAN_FISHING
#define OBJ_EVENT_GFX_OUTFIT_RS_BRENDAN_WATERING   OBJ_EVENT_GFX_BRENDAN_WATERING
#define OBJ_EVENT_GFX_OUTFIT_RS_BRENDAN_DECORATING OBJ_EVENT_GFX_BRENDAN_DECORATING
#define OBJ_EVENT_GFX_OUTFIT_RS_BRENDAN_FIELD_MOVE OBJ_EVENT_GFX_BRENDAN_FIELD_MOVE

#define OBJ_EVENT_GFX_OUTFIT_RS_MAY_NORMAL     OBJ_EVENT_GFX_LINK_RS_MAY
#define OBJ_EVENT_GFX_OUTFIT_RS_MAY_ACRO_BIKE  OBJ_EVENT_GFX_MAY_ACRO_BIKE
#define OBJ_EVENT_GFX_OUTFIT_RS_MAY_SURFING    OBJ_EVENT_GFX_MAY_SURFING
#define OBJ_EVENT_GFX_OUTFIT_RS_MAY_UNDERWATER OBJ_EVENT_GFX_MAY_UNDERWATER
#define OBJ_EVENT_GFX_OUTFIT_RS_MAY_FIELD_MOVE OBJ_EVENT_GFX_MAY_FIELD_MOVE
#define OBJ_EVENT_GFX_OUTFIT_RS_MAY_FISHING    OBJ_EVENT_GFX_MAY_FISHING
#define OBJ_EVENT_GFX_OUTFIT_RS_MAY_WATERING   OBJ_EVENT_GFX_MAY_WATERING
#define OBJ_EVENT_GFX_OUTFIT_RS_MAY_DECORATING OBJ_EVENT_GFX_MAY_DECORATING
#define OBJ_EVENT_GFX_OUTFIT_RS_MAY_FIELD_MOVE OBJ_EVENT_GFX_MAY_FIELD_MOVE

const struct Outfit gOutfits[OUTFIT_COUNT] =
{
    [OUTFIT_NONE] = {
        .isHidden = TRUE
    },
    [OUTFIT_USUAL_GREEN] = {
        //! DESC: if sets to TRUE, it will not be shown in the OUTFIT menu if it's locked.
        .isHidden = FALSE,

        //! DESC: prices for purchasing them.
        .prices = { 0, 0 },

        //! agbcc doesnt like COMPOUND_STRING on my end
        //! DESC: outfit's name

        .name = COMPOUND_STRING("Default"),
        .desc = COMPOUND_STRING("The usual, but basic Outfit."),

        .nameFemale = COMPOUND_STRING("Default"),
        .descFemale = COMPOUND_STRING("The usual, but basic Outfit."),


        //! DESC: trainer front & back pic index
        //! (see include/constants/trainers.h)
        .trainerPics = {
            [MALE] =   { TRAINER_PIC_RED, TRAINER_BACK_PIC_RED, },
            [FEMALE] = { TRAINER_PIC_LEAF, TRAINER_BACK_PIC_LEAF, },
        },

        //! DESC: overworld avatars, consisting of: walking, cycling,
        //! surfing, and underwater. (see include/constants/event_object.h)
        .avatarGfxIds = {
           [MALE] = {
               [PLAYER_AVATAR_STATE_NORMAL] =     OBJ_EVENT_GFX_RED_NORMAL,
               [PLAYER_AVATAR_STATE_BIKE] =       OBJ_EVENT_GFX_RED_BIKE,
               [PLAYER_AVATAR_STATE_SURFING] =    OBJ_EVENT_GFX_RED_SURF,
               [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_BRENDAN_UNDERWATER
           },
           [FEMALE] = {
               [PLAYER_AVATAR_STATE_NORMAL] =     OBJ_EVENT_GFX_GREEN_NORMAL,
               [PLAYER_AVATAR_STATE_BIKE] =       OBJ_EVENT_GFX_RIVAL_MAY_ACRO_BIKE,
               [PLAYER_AVATAR_STATE_SURFING] =    OBJ_EVENT_GFX_GREEN_SURF,
               [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_BRENDAN_UNDERWATER
           },
        },

        //! DESC: overworld anims, consisting of: field move, fishing,
        //! water, and decorating. (see include/constants/event_object.h)
        .animGfxIds = {
            [MALE] = {
                [PLAYER_AVATAR_GFX_FIELD_MOVE] = OBJ_EVENT_GFX_RED_FIELD_MOVE,
                [PLAYER_AVATAR_GFX_FISHING] =    OBJ_EVENT_GFX_RED_FISH,
                [PLAYER_AVATAR_GFX_WATERING] =   OBJ_EVENT_GFX_BRENDAN_WATERING,
                [PLAYER_AVATAR_GFX_DECORATING] = OBJ_EVENT_GFX_BRENDAN_DECORATING,
                [PLAYER_AVATAR_GFX_VSSEEKER] =   OBJ_EVENT_GFX_RED_FIELD_MOVE
            },
            [FEMALE] = {
                [PLAYER_AVATAR_GFX_FIELD_MOVE] = OBJ_EVENT_GFX_GREEN_FIELD_MOVE,
                [PLAYER_AVATAR_GFX_FISHING] =    OBJ_EVENT_GFX_GREEN_FISH,
                [PLAYER_AVATAR_GFX_WATERING] =   OBJ_EVENT_GFX_BRENDAN_WATERING,
                [PLAYER_AVATAR_GFX_DECORATING] = OBJ_EVENT_GFX_BRENDAN_DECORATING,
                [PLAYER_AVATAR_GFX_VSSEEKER] =   OBJ_EVENT_GFX_GREEN_FIELD_MOVE
            },
        },

        //! DESC: head icons gfx&pal for region map
        .iconsRM = { sRegionMapPlayerIcon_RedGfx, sRegionMapPlayerIcon_GreenGfx },

        //! DESC: head icons gfx&pal for frontier pass
        //! note that frontier pass needs to be in one sprite instead of two,
        //! unlike region map. (probably should split them tbh)
        .iconsFP = sFrontierPassPlayerIcons_BrendanMay_Gfx,
    },
    [OUTFIT_ALT_RED_GREEN] = {
        //! DESC: if sets to TRUE, it will not be shown in the OUTFIT menu if it's locked.
        .isHidden = FALSE,

        //! DESC: prices for purchasing them.
        .prices = { 0, 0 },

        //! agbcc doesnt like COMPOUND_STRING on my end
        //! DESC: outfit's name

        .name = COMPOUND_STRING("Alternate Red"),
        .desc = COMPOUND_STRING("An alternate outfit for Red."),

        .nameFemale = COMPOUND_STRING("Green"),
        .descFemale = COMPOUND_STRING("An outfit based on Green."),

        //! DESC: trainer front & back pic index
        //! (see include/constants/trainers.h)
        .trainerPics = {
            [MALE] =   { TRAINER_PIC_RGBY_RED, TRAINER_BACK_PIC_RGBY_RED, },
            [FEMALE] = { TRAINER_PIC_GREEN , TRAINER_BACK_PIC_GREEN , },
        },

        //! DESC: overworld avatars, consisting of: walking, cycling,
        //! surfing, and underwater. (see include/constants/event_object.h)
        .avatarGfxIds = {
           [MALE] = {
               [PLAYER_AVATAR_STATE_NORMAL] =     OBJ_EVENT_GFX_RGBY_RED_NORMAL,
               [PLAYER_AVATAR_STATE_BIKE] =       OBJ_EVENT_GFX_RGBY_RED_MACH_BIKE,
               [PLAYER_AVATAR_STATE_SURFING] =    OBJ_EVENT_GFX_RGBY_RED_SURFING,
               [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_RGBY_RED_SURFING
           },
           [FEMALE] = {
               [PLAYER_AVATAR_STATE_NORMAL] =     OBJ_EVENT_GFX_GREEN_ALT_NORMAL,
               [PLAYER_AVATAR_STATE_BIKE] =       OBJ_EVENT_GFX_GREEN_ALT_MACH_BIKE,
               [PLAYER_AVATAR_STATE_SURFING] =    OBJ_EVENT_GFX_GREEN_ALT_SURFING,
               [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_GREEN_ALT_SURFING
           },
        },

        //! DESC: overworld anims, consisting of: field move, fishing,
        //! water, and decorating. (see include/constants/event_object.h)
        .animGfxIds = {
            [MALE] = {
                [PLAYER_AVATAR_GFX_FIELD_MOVE] = OBJ_EVENT_GFX_RGBY_RED_FIELD_MOVE,
                [PLAYER_AVATAR_GFX_FISHING] =    OBJ_EVENT_GFX_RGBY_RED_FISHING,
                [PLAYER_AVATAR_GFX_WATERING] =   OBJ_EVENT_GFX_RGBY_RED_FIELD_MOVE,
                [PLAYER_AVATAR_GFX_DECORATING] = OBJ_EVENT_GFX_RGBY_RED_FIELD_MOVE,
                [PLAYER_AVATAR_GFX_VSSEEKER] =   OBJ_EVENT_GFX_RGBY_RED_FIELD_MOVE
            },
            [FEMALE] = {
                [PLAYER_AVATAR_GFX_FIELD_MOVE] = OBJ_EVENT_GFX_GREEN_ALT_FIELD_MOVE,
                [PLAYER_AVATAR_GFX_FISHING] =    OBJ_EVENT_GFX_GREEN_ALT_FISHING,
                [PLAYER_AVATAR_GFX_WATERING] =   OBJ_EVENT_GFX_GREEN_ALT_FIELD_MOVE,
                [PLAYER_AVATAR_GFX_DECORATING] = OBJ_EVENT_GFX_GREEN_ALT_FIELD_MOVE,
                [PLAYER_AVATAR_GFX_VSSEEKER] =   OBJ_EVENT_GFX_GREEN_ALT_FIELD_MOVE
            },
        },

        //! DESC: head icons gfx&pal for region map
        .iconsRM = { sRegionMapPlayerIcon_AltRedGfx, sRegionMapPlayerIcon_GreenGfx },

        //! DESC: head icons gfx&pal for frontier pass
        //! note that frontier pass needs to be in one sprite instead of two,
        //! unlike region map. (probably should split them tbh)
        .iconsFP = sFrontierPassPlayerIcons_BrendanMay_Gfx,
    },
    [OUTFIT_GOLD_KRIS] = {
        //! DESC: if sets to TRUE, it will not be shown in the OUTFIT menu if it's locked.
        .isHidden = FALSE,
        .prices = { 0, 0 },


        .name = COMPOUND_STRING("Gold"),
        .desc = COMPOUND_STRING("An outfit based on Gold from GSC."),
        .nameFemale = COMPOUND_STRING("Kris"),
        .descFemale = COMPOUND_STRING("An outfit based on Kris from GSC."),
        .trainerPics = {
            [MALE] =   { TRAINER_PIC_GOLD , TRAINER_BACK_PIC_GOLD , },
            [FEMALE] = { TRAINER_PIC_KRIS , TRAINER_BACK_PIC_KRIS , },
        },

        .avatarGfxIds = {
           [MALE] = {
               [PLAYER_AVATAR_STATE_NORMAL] =     OBJ_EVENT_GFX_GOLD_NORMAL,
               [PLAYER_AVATAR_STATE_BIKE] =       OBJ_EVENT_GFX_GOLD_MACH_BIKE,
               [PLAYER_AVATAR_STATE_SURFING] =    OBJ_EVENT_GFX_GOLD_SURFING,
               [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_GOLD_SURFING
           },
           [FEMALE] = {
               [PLAYER_AVATAR_STATE_NORMAL] =     OBJ_EVENT_GFX_KRIS_NORMAL,
               [PLAYER_AVATAR_STATE_BIKE] =       OBJ_EVENT_GFX_KRIS_MACH_BIKE,
               [PLAYER_AVATAR_STATE_SURFING] =    OBJ_EVENT_GFX_KRIS_SURFING,
               [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_KRIS_SURFING
           },
        },

        .animGfxIds = {
            [MALE] = {
                [PLAYER_AVATAR_GFX_FIELD_MOVE] = OBJ_EVENT_GFX_GOLD_FIELD_MOVE,
                [PLAYER_AVATAR_GFX_FISHING] =    OBJ_EVENT_GFX_GOLD_FISHING,
                [PLAYER_AVATAR_GFX_WATERING] =   OBJ_EVENT_GFX_GOLD_FIELD_MOVE,
                [PLAYER_AVATAR_GFX_DECORATING] = OBJ_EVENT_GFX_GOLD_FIELD_MOVE,
                [PLAYER_AVATAR_GFX_VSSEEKER] =   OBJ_EVENT_GFX_GOLD_FIELD_MOVE
            },
            [FEMALE] = {
                [PLAYER_AVATAR_GFX_FIELD_MOVE] = OBJ_EVENT_GFX_KRIS_FIELD_MOVE,
                [PLAYER_AVATAR_GFX_FISHING] =    OBJ_EVENT_GFX_KRIS_FISHING,
                [PLAYER_AVATAR_GFX_WATERING] =   OBJ_EVENT_GFX_KRIS_FIELD_MOVE,
                [PLAYER_AVATAR_GFX_DECORATING] = OBJ_EVENT_GFX_KRIS_FIELD_MOVE,
                [PLAYER_AVATAR_GFX_VSSEEKER] =   OBJ_EVENT_GFX_KRIS_FIELD_MOVE
            },
        },

        .iconsRM = { sRegionMapPlayerIcon_GoldGfx, sRegionMapPlayerIcon_KrisGfx },

        .iconsFP = sFrontierPassPlayerIcons_BrendanMay_Gfx,
    },
    [OUTFIT_LUCAS_DAWN] = {
        //! DESC: if sets to TRUE, it will not be shown in the OUTFIT menu if it's locked.
        .isHidden = FALSE,
        .prices = { 0, 0 },


        .name = COMPOUND_STRING("Lucas"),
        .desc = COMPOUND_STRING("An outfit based on Lucas from DPP."),
        .nameFemale = COMPOUND_STRING("Dawn"),
        .descFemale = COMPOUND_STRING("An outfit based on Dawn from DPP."),
        .trainerPics = {
            [MALE] =   { TRAINER_PIC_LUCAS , TRAINER_BACK_PIC_LUCAS , },
            [FEMALE] = { TRAINER_PIC_DAWN , TRAINER_BACK_PIC_DAWN , },
        },

        .avatarGfxIds = {
           [MALE] = {
               [PLAYER_AVATAR_STATE_NORMAL] =     OBJ_EVENT_GFX_LUCAS_NORMAL,
               [PLAYER_AVATAR_STATE_BIKE] =       OBJ_EVENT_GFX_LUCAS_MACH_BIKE,
               [PLAYER_AVATAR_STATE_SURFING] =    OBJ_EVENT_GFX_LUCAS_SURFING,
               [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_LUCAS_SURFING
           },
           [FEMALE] = {
               [PLAYER_AVATAR_STATE_NORMAL] =     OBJ_EVENT_GFX_DAWN_NORMAL,
               [PLAYER_AVATAR_STATE_BIKE] =       OBJ_EVENT_GFX_DAWN_MACH_BIKE,
               [PLAYER_AVATAR_STATE_SURFING] =    OBJ_EVENT_GFX_DAWN_SURFING,
               [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_DAWN_SURFING
           },
        },

        .animGfxIds = {
            [MALE] = {
                [PLAYER_AVATAR_GFX_FIELD_MOVE] = OBJ_EVENT_GFX_LUCAS_FISHING, //TODO
                [PLAYER_AVATAR_GFX_FISHING] =    OBJ_EVENT_GFX_LUCAS_FISHING, 
                [PLAYER_AVATAR_GFX_WATERING] =   OBJ_EVENT_GFX_LUCAS_FISHING,
                [PLAYER_AVATAR_GFX_DECORATING] = OBJ_EVENT_GFX_LUCAS_FISHING,
                [PLAYER_AVATAR_GFX_VSSEEKER] =   OBJ_EVENT_GFX_LUCAS_FISHING
            },
            [FEMALE] = {
                [PLAYER_AVATAR_GFX_FIELD_MOVE] = OBJ_EVENT_GFX_DAWN_FIELD_MOVE,
                [PLAYER_AVATAR_GFX_FISHING] =    OBJ_EVENT_GFX_DAWN_FISHING,
                [PLAYER_AVATAR_GFX_WATERING] =   OBJ_EVENT_GFX_DAWN_FIELD_MOVE,
                [PLAYER_AVATAR_GFX_DECORATING] = OBJ_EVENT_GFX_DAWN_FIELD_MOVE,
                [PLAYER_AVATAR_GFX_VSSEEKER] =   OBJ_EVENT_GFX_DAWN_FIELD_MOVE
            },
        },

        .iconsRM = { sRegionMapPlayerIcon_RedGfx, sRegionMapPlayerIcon_GreenGfx }, //TODO

        .iconsFP = sFrontierPassPlayerIcons_BrendanMay_Gfx,
    },
    [OUTFIT_ALAIN_LYRA] = {
        //! DESC: if sets to TRUE, it will not be shown in the OUTFIT menu if it's locked.
        .isHidden = FALSE,
        .prices = { 0, 0 },


        .name = COMPOUND_STRING("Alain"),
        .desc = COMPOUND_STRING("An outfit based on Alain from the XY Anime."),
        .nameFemale = COMPOUND_STRING("Lyra"),
        .descFemale = COMPOUND_STRING("An outfit based on Lyra from HGSS."),
        .trainerPics = {
            [MALE] =   { TRAINER_PIC_ALAIN , TRAINER_BACK_PIC_ALAIN , },
            [FEMALE] = { TRAINER_PIC_LYRA , TRAINER_BACK_PIC_LYRA , },
        },

        .avatarGfxIds = {
           [MALE] = {
               [PLAYER_AVATAR_STATE_NORMAL] =     OBJ_EVENT_GFX_ALAIN_NORMAL,
               [PLAYER_AVATAR_STATE_BIKE] =       OBJ_EVENT_GFX_ALAIN_MACH_BIKE,
               [PLAYER_AVATAR_STATE_SURFING] =    OBJ_EVENT_GFX_ALAIN_SURFING,
               [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_ALAIN_SURFING
           },
           [FEMALE] = {
               [PLAYER_AVATAR_STATE_NORMAL] =     OBJ_EVENT_GFX_LYRA_NORMAL,
               [PLAYER_AVATAR_STATE_BIKE] =       OBJ_EVENT_GFX_LYRA_MACH_BIKE,
               [PLAYER_AVATAR_STATE_SURFING] =    OBJ_EVENT_GFX_LYRA_SURFING,
               [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_LYRA_SURFING
           },
        },

        .animGfxIds = {
            [MALE] = {
                [PLAYER_AVATAR_GFX_FIELD_MOVE] = OBJ_EVENT_GFX_ALAIN_FIELD_MOVE, 
                [PLAYER_AVATAR_GFX_FISHING] =    OBJ_EVENT_GFX_ALAIN_FISHING, 
                [PLAYER_AVATAR_GFX_WATERING] =   OBJ_EVENT_GFX_ALAIN_FISHING,
                [PLAYER_AVATAR_GFX_DECORATING] = OBJ_EVENT_GFX_ALAIN_FISHING,
                [PLAYER_AVATAR_GFX_VSSEEKER] =   OBJ_EVENT_GFX_ALAIN_FISHING
            },
            [FEMALE] = {
                [PLAYER_AVATAR_GFX_FIELD_MOVE] = OBJ_EVENT_GFX_LYRA_FIELD_MOVE,
                [PLAYER_AVATAR_GFX_FISHING] =    OBJ_EVENT_GFX_LYRA_FISHING,
                [PLAYER_AVATAR_GFX_WATERING] =   OBJ_EVENT_GFX_LYRA_FIELD_MOVE,
                [PLAYER_AVATAR_GFX_DECORATING] = OBJ_EVENT_GFX_LYRA_FIELD_MOVE,
                [PLAYER_AVATAR_GFX_VSSEEKER] =   OBJ_EVENT_GFX_LYRA_FIELD_MOVE
            },
        },

        .iconsRM = { sRegionMapPlayerIcon_RedGfx, sRegionMapPlayerIcon_GreenGfx }, //TODO

        .iconsFP = sFrontierPassPlayerIcons_BrendanMay_Gfx,
    },
    [OUTFIT_PLACEHOLDER_1] = {
        .isHidden = TRUE
    },
    [OUTFIT_PLACEHOLDER_2] = {
        .isHidden = TRUE
    },
    [OUTFIT_PLACEHOLDER_3] = {
        .isHidden = TRUE
    },
    [OUTFIT_PLACEHOLDER_4] = {
        .isHidden = TRUE
    },
};
