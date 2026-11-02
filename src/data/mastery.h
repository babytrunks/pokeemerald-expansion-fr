// Mastery table, indexed by the MASTERY_ constants
// Titles print on the pop up plate which is only about 80px wide, keep them short
// Descriptions must fit MASTERY_MAX_DESCRIPTION_LENGTH once wrapped
const struct Mastery gMasteries[MASTERY_COUNT] =
{
    [MASTERY_NONE] = { 0 },

    [MASTERY_WILD_GROWTH] =
    {
        .title       = COMPOUND_STRING("Wild Growth"),
        .description = COMPOUND_STRING("Land 5 moves boosted by Overgrow."),
        .event       = MASTERY_EVENT_ABILITY_BOOSTED_MOVE,
        .param       = ABILITY_OVERGROW,
        .targetCount = 5,
        .reward      = ITEM_MIRACLE_SEED,
    },

    [MASTERY_LINGERING_EMBER] =
    {
        .title       = COMPOUND_STRING("Lingering Ember"),
        .description = COMPOUND_STRING("Land 5 moves boosted by Blaze."),
        .event       = MASTERY_EVENT_ABILITY_BOOSTED_MOVE,
        .param       = ABILITY_BLAZE,
        .targetCount = 5,
        .reward      = ITEM_CHARCOAL,
    },

    [MASTERY_RISING_TIDE] =
    {
        .title       = COMPOUND_STRING("Rising Tide"),
        .description = COMPOUND_STRING("Land 5 moves boosted by Torrent."),
        .event       = MASTERY_EVENT_ABILITY_BOOSTED_MOVE,
        .param       = ABILITY_TORRENT,
        .targetCount = 5,
        .reward      = ITEM_MYSTIC_WATER,
    },

    [MASTERY_TRICKSTER] =
    {
        .title       = COMPOUND_STRING("Greed is Good"),
        .description = COMPOUND_STRING("Use Pay Day five times in one battle."),
        .event       = MASTERY_EVENT_MOVE_USED,
        .param       = MOVE_PAY_DAY,
        .targetCount = 5,
        .reward      = ITEM_AMULET_COIN,
        .perBattle   = TRUE,
    },

    [MASTERY_TREMOR_SENSE] =
    {
        .title       = COMPOUND_STRING("Gambler"),
        .description = COMPOUND_STRING("Hit with Magnitude 10 five times."),
        .event       = MASTERY_EVENT_MAGNITUDE_LEVEL,
        .param       = 10,
        .targetCount = 5,
        .reward      = ITEM_GACHA_VOUCHER,
    },
};
