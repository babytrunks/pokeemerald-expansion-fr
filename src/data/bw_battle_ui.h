// const data

// textbox
static const u32 sBWBattleUI_TextboxTiles[] = INCBIN_U32("graphics/battle_interface/bw/textbox.4bpp.smol");
static const u16 sBWBattleUI_TextboxPalette[] = INCBIN_U16("graphics/battle_interface/bw/textbox.gbapal");
static const u32 sBWBattleUI_TextboxTilemap[] = INCBIN_U32("graphics/battle_interface/bw/textbox.bin.smolTM");
// Raw copy for the move box's rect blit. CopyRectToBgTilemapBufferRect takes a
// plain pointer, so it reads this straight out of ROM instead of decompressing
// the 4 KB tilemap onto the heap every time the box is redrawn.
static const u16 sBWBattleUI_TextboxTilemapRaw[] = INCBIN_U16("graphics/battle_interface/bw/textbox.bin");

// inputbox->actionbox
static const u8 sBWBattleUI_ActionBox[] = INCBIN_U8("graphics/battle_interface/bw/actionbox.4bpp");
static const u8 *const sBWBattleUI_ActionBoxFields[][BUI_ACTION_BOX_ENTRY_COUNT] =
{
    // left-top -> right-bottom
    { // default
        COMPOUND_STRING("FIGHT!"),  COMPOUND_STRING("BAG"),
        COMPOUND_STRING("POKÉMON"), COMPOUND_STRING("RUN"),
    },
    { // safari
        COMPOUND_STRING("BALL!"),    COMPOUND_STRING("{POKEBLOCK}"),
        COMPOUND_STRING("GO NEAR"),  COMPOUND_STRING("RUN"),
    },
};

// inputbox->movebox
// Built as four 14x3 metatiles, one per panel, so each window can be filled
// with a single contiguous tile copy.
static const u8 sBWBattleUI_MoveBoxGraphics[] = INCBIN_U8("graphics/battle_interface/bw/movebox.4bpp");
static const u8 sBWBattleUI_MoveBoxGraphicsZ[] = INCBIN_U8("graphics/battle_interface/bw/movebox_z.4bpp");
static const u16 sBWBattleUI_MoveBoxPalette[] = INCBIN_U16("graphics/battle_interface/bw/movebox.gbapal");
static const u16 sBWBattleUI_MoveBoxTypePalettes[] = INCBIN_U16("graphics/battle_interface/bw/movebox_types.gbapal");

// inputbox->cursor
static const u32 sBWBattleUI_CursorGfx[] = INCBIN_U32("graphics/battle_interface/bw/cursor.4bpp.smol");
static const u16 sBWBattleUI_CursorPalette[] = INCBIN_U16("graphics/battle_interface/bw/cursor.gbapal");

// The cursor is a single sprite whose four corners are pulled apart far enough
// to frame whichever box it currently sits on.
static const struct Subsprite sBWBattleUI_ActionCursorSubsprite[] =
{
    {
        .x = 0,
        .y = 0,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SIZE(16x16),
        .tileOffset = 0,
    },
    {
        .x = BUI_ACTION_CURSOR_MAX_X,
        .y = 0,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SIZE(16x16),
        .tileOffset = 4,
    },
    {
        .x = 0,
        .y = BUI_ACTION_CURSOR_MAX_Y,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SIZE(16x16),
        .tileOffset = 8,
    },
    {
        .x = BUI_ACTION_CURSOR_MAX_X,
        .y = BUI_ACTION_CURSOR_MAX_Y,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SIZE(16x16),
        .tileOffset = 12,
    },
};

static const struct Subsprite sBWBattleUI_MoveCursorSubsprite[] =
{
    {
        .x = 0,
        .y = 0,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SIZE(16x16),
        .tileOffset = 0,
        .priority = 0
    },
    {
        .x = BUI_MOVE_CURSOR_MAX_X,
        .y = 0,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SIZE(16x16),
        .tileOffset = 4,
        .priority = 0
    },
    {
        .x = 0,
        .y = BUI_MOVE_CURSOR_MAX_Y,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SIZE(16x16),
        .tileOffset = 8,
        .priority = 0
    },
    {
        .x = BUI_MOVE_CURSOR_MAX_X,
        .y = BUI_MOVE_CURSOR_MAX_Y,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SIZE(16x16),
        .tileOffset = 12,
        .priority = 0
    },
};

static const struct Subsprite sBWBattleUI_ZMoveCursorSubsprite[] =
{
    {
        .x = 0,
        .y = 0,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SIZE(16x16),
        .tileOffset = 0,
        .priority = 0
    },
    {
        .x = BUI_Z_MOVE_CURSOR_MAX_X,
        .y = 0,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SIZE(16x16),
        .tileOffset = 4,
        .priority = 0
    },
    {
        .x = 0,
        .y = BUI_Z_MOVE_CURSOR_MAX_Y,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SIZE(16x16),
        .tileOffset = 8,
        .priority = 0
    },
    {
        .x = BUI_Z_MOVE_CURSOR_MAX_X,
        .y = BUI_Z_MOVE_CURSOR_MAX_Y,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SIZE(16x16),
        .tileOffset = 12,
        .priority = 0
    },
};

static const struct SubspriteTable sBWBattleUI_CursorSubspritesTable[] =
{
    { ARRAY_COUNT(sBWBattleUI_ActionCursorSubsprite), sBWBattleUI_ActionCursorSubsprite },
    { ARRAY_COUNT(sBWBattleUI_MoveCursorSubsprite),   sBWBattleUI_MoveCursorSubsprite },
    { ARRAY_COUNT(sBWBattleUI_ZMoveCursorSubsprite),  sBWBattleUI_ZMoveCursorSubsprite },
    { }
};

static const struct SpriteTemplate sBWBattleUI_CursorTemplate =
{
    .tileTag = TAG_CURSOR,
    .paletteTag = TAG_CURSOR,
    .oam = &(struct OamData){
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
    },
    .anims = (const union AnimCmd *const[]){
        [0] = (const union AnimCmd[]){
            ANIMCMD_FRAME( 0, 16),
            ANIMCMD_FRAME(16, 16),
            ANIMCMD_FRAME(32, 16),
            ANIMCMD_JUMP(0),
        },
    },
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_BattleUICursor,
};

static const union TextColor sBWBattleUI_TextColors[NUM_BUI_TXTCLRS] =
{
    [BUI_TXTCLR_MOVE_BOX] =
    {
        .foreground = 13,
        .shadow = 15,
    },
    [BUI_TXTCLR_ABOX_1] =
    {
        .foreground = 4,
        .accent = 2,
        .shadow = 9,
    },
    [BUI_TXTCLR_ABOX_2] =
    {
        .foreground = 14,
        .accent = 5,
        .shadow = 9,
    },
    [BUI_TXTCLR_ABOX_3] =
    {
        .foreground = 11,
        .accent = 10,
        .shadow = 9,
    },
    [BUI_TXTCLR_ABOX_4] =
    {
        .foreground = 12,
        .accent = 8,
        .shadow = 9,
    },
};
