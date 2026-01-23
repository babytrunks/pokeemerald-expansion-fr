const struct TrainerMon gBattleFrontierMons[NUM_FRONTIER_MONS] =
{
    [FRONTIER_MON_BULBASAUR] = { 
        .species = SPECIES_BULBASAUR,
        .moves = {MOVE_TACKLE, MOVE_MAGICAL_LEAF, MOVE_SLEEP_POWDER, MOVE_NONE},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3,
    },
    [FRONTIER_MON_CHARMANDER] = { 
        .species = SPECIES_CHARMANDER,
        .moves = {MOVE_FIRE_SPIN, MOVE_METAL_CLAW, MOVE_SMOKESCREEN, MOVE_SCARY_FACE},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3,
    },
    [FRONTIER_MON_SQUIRTLE] = { 
        .species = SPECIES_SQUIRTLE,
        .moves = {MOVE_WATER_PULSE, MOVE_BITE, MOVE_RAPID_SPIN, MOVE_NONE},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3,
    },
    [FRONTIER_MON_CHIKORITA] = {
        .species = SPECIES_CHIKORITA,
        .moves = {MOVE_TACKLE, MOVE_ABSORB, MOVE_MUD_SLAP, MOVE_NONE},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3,
    },
    [FRONTIER_MON_CYNDAQUIL] = {
        .species = SPECIES_CYNDAQUIL,
        .moves = {MOVE_INCINERATE, MOVE_SWIFT, MOVE_QUICK_ATTACK, MOVE_SMOKESCREEN},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3,
    },
    [FRONTIER_MON_TOTODILE] = {
        .species = SPECIES_TOTODILE,
        .moves = {MOVE_AQUA_JET, MOVE_BITE, MOVE_SCARY_FACE, MOVE_NONE},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3,
    },

    [FRONTIER_MON_TURTWIG] = {
        .species = SPECIES_TURTWIG,
        .moves = {MOVE_MEGA_DRAIN, MOVE_TACKLE, MOVE_SAND_TOMB, MOVE_NONE},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3,
    },

    [FRONTIER_MON_TORCHIC] = {
        .species = SPECIES_TORCHIC,
        .moves = {MOVE_SCRATCH, MOVE_GROWL, MOVE_EMBER, MOVE_QUICK_ATTACK},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3,
    },

    [FRONTIER_MON_MUDKIP] = {
        .species = SPECIES_MUDKIP,
        .moves = {MOVE_TACKLE, MOVE_GROWL, MOVE_WATER_GUN, MOVE_ROCK_SMASH},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3,
    },

    [FRONTIER_MON_TREECKO] = {
        .species = SPECIES_TREECKO,
        .moves = {MOVE_POUND, MOVE_LEER, MOVE_QUICK_ATTACK, MOVE_MEGA_DRAIN},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3,
    },

    [FRONTIER_MON_CHIMCHAR] = {
        .species = SPECIES_CHIMCHAR,
        .moves = {MOVE_FLAME_WHEEL, MOVE_SCRATCH, MOVE_GROWL, MOVE_NONE},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3,
    },
    [FRONTIER_MON_PIPLUP] = {
        .species = SPECIES_PIPLUP,
        .moves = {MOVE_BRINE, MOVE_PLUCK, MOVE_GROWL, MOVE_NONE},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3,
    },
    [FRONTIER_MON_SNIVY] = {
        .species = SPECIES_SNIVY,
        .moves = {MOVE_MEGA_DRAIN, MOVE_GLARE, MOVE_LEECH_SEED, MOVE_SWIFT},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3,
    },

    [FRONTIER_MON_TEPIG] = {
        .species = SPECIES_TEPIG,
        .moves = {MOVE_FLAME_WHEEL, MOVE_TACKLE, MOVE_SUCKER_PUNCH, MOVE_ROCK_SMASH},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3,
    },
    [FRONTIER_MON_OSHAWOTT] = {
        .species = SPECIES_OSHAWOTT,
        .moves = {MOVE_WATER_GUN, MOVE_TACKLE, MOVE_TAIL_WHIP, MOVE_NONE},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3,
    },

    [FRONTIER_MON_CHESPIN] = {
        .species = SPECIES_CHESPIN,
        .moves = {MOVE_VINE_WHIP, MOVE_GROWL, MOVE_ROLLOUT, MOVE_BITE},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3,
    },

    [FRONTIER_MON_FENNEKIN] = {
        .ability = ABILITY_MAGIC_GUARD,
        .species = SPECIES_FENNEKIN,
        .moves = {MOVE_INCINERATE, MOVE_MUD_SLAP, MOVE_FOUL_PLAY, MOVE_NONE},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3,
    },
    [FRONTIER_MON_FROAKIE] = {
        .species = SPECIES_FROAKIE,
        .moves = {MOVE_LICK, MOVE_WATER_PULSE, MOVE_SMOKESCREEN, MOVE_NONE},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3,
    },

    [FRONTIER_MON_ROWLET] = {
        .ability = ABILITY_TINTED_LENS,
        .species = SPECIES_ROWLET,
        .moves = {MOVE_RAZOR_LEAF, MOVE_PLUCK, MOVE_SUCKER_PUNCH, MOVE_NONE},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3,
    },

    [FRONTIER_MON_LITTEN] = {
        .species = SPECIES_LITTEN,
        .moves = {MOVE_EMBER, MOVE_FURY_SWIPES, MOVE_GROWL, MOVE_NONE},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3,
    },
    [FRONTIER_MON_POPPLIO] = {
        .species = SPECIES_POPPLIO,
        .moves = {MOVE_WATER_GUN, MOVE_TACKLE, MOVE_GROWL, MOVE_NONE},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3,
    },

    [FRONTIER_MON_GROOKEY] = {
        .species = SPECIES_GROOKEY,
        .moves = {MOVE_BRANCH_POKE, MOVE_FALSE_SWIPE, MOVE_SCRATCH, MOVE_NONE},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3,
    },

    [FRONTIER_MON_SCORBUNNY] = {
        .species = SPECIES_SCORBUNNY,
        .moves = {MOVE_EMBER, MOVE_QUICK_ATTACK, MOVE_GROWL, MOVE_NONE},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3,
    },
    [FRONTIER_MON_SOBBLE] = {
        .species = SPECIES_SOBBLE,
        .moves = {MOVE_WATER_PULSE, MOVE_U_TURN, MOVE_GROWL, MOVE_NONE},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3,
    },

    [FRONTIER_MON_SPRIGATITO] = {
        .species = SPECIES_SPRIGATITO,
        .moves = {MOVE_LEAFAGE, MOVE_QUICK_ATTACK, MOVE_NONE, MOVE_NONE},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3,
    },

    [FRONTIER_MON_FUECOCO] = {
        .species = SPECIES_FUECOCO,
        .moves = {MOVE_EMBER, MOVE_TACKLE, MOVE_GROWL, MOVE_NONE},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3,
    },
    [FRONTIER_MON_QUAXLY] = {
        .species = SPECIES_QUAXLY,
        .moves = {MOVE_WATER_GUN, MOVE_DISARMING_VOICE, MOVE_GROWL, MOVE_NONE},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3,
    },

    [FRONTIER_MON_ODDISH] = {
        .species = SPECIES_ODDISH,
        .moves = {MOVE_ABSORB, MOVE_MEGA_DRAIN, MOVE_ACID, MOVE_SWEET_SCENT},
        .heldItem = ITEM_LEAF_STONE,
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_BELLSPROUT] = {
        .species = SPECIES_BELLSPROUT,
        .moves = {MOVE_VINE_WHIP, MOVE_ACID, MOVE_WRAP, MOVE_SLEEP_POWDER},
        .heldItem = ITEM_LEAF_STONE,
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_SNOVER] = {
        .species = SPECIES_SNOVER,
        .moves = {MOVE_LEER, MOVE_POWDER_SNOW, MOVE_LEAFAGE, MOVE_MIST},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_BUDEW] = {
        .species = SPECIES_BUDEW,
        .moves = {MOVE_MEGA_DRAIN, MOVE_STUN_SPORE, MOVE_WORRY_SEED, MOVE_NONE},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_VOLTORB_HISUIAN] = {
        .species = SPECIES_VOLTORB_HISUI,
        .moves = {MOVE_CHARGE, MOVE_TACKLE, MOVE_THUNDER_SHOCK, MOVE_EERIE_IMPULSE},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_CARNIVINE] = {
        .species = SPECIES_CARNIVINE,
        .moves = {MOVE_BIND, MOVE_GROWTH, MOVE_BITE, MOVE_VINE_WHIP},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_COTTONEE] = {
        .species = SPECIES_COTTONEE,
        .moves = {MOVE_HELPING_HAND, MOVE_ABSORB, MOVE_FAIRY_WIND, MOVE_STUN_SPORE},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_PETILIL] = {
        .species = SPECIES_PETILIL,
        .moves = {MOVE_ABSORB, MOVE_GROWTH, MOVE_HELPING_HAND, MOVE_STUN_SPORE},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_MARACTUS] = {
        .species = SPECIES_MARACTUS,
        .moves = {MOVE_SPIKY_SHIELD, MOVE_PECK, MOVE_ABSORB, MOVE_AFTER_YOU},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3,
    },

    [FRONTIER_MON_APPLIN] = {
        .species = SPECIES_APPLIN,
        .moves = {MOVE_ASTONISH, MOVE_WITHDRAW, MOVE_NONE, MOVE_NONE},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_FOONGUS] = {
        .species = SPECIES_FOONGUS,
        .moves = {MOVE_ABSORB, MOVE_ASTONISH, MOVE_STUN_SPORE, MOVE_MEGA_DRAIN},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_TROPIUS] = {
        .species = SPECIES_TROPIUS,
        .moves = {MOVE_GUST, MOVE_LEER, MOVE_RAZOR_LEAF, MOVE_SWEET_SCENT},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3,
    },

    [FRONTIER_MON_TOEDSCOOL] = {
        .species = SPECIES_TOEDSCOOL,
        .moves = {MOVE_WRAP, MOVE_MUD_SLAP, MOVE_ABSORB, MOVE_POISON_POWDER},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_EXEGGCUTE] = {
        .species = SPECIES_EXEGGCUTE,
        .moves = {MOVE_ABSORB, MOVE_HYPNOSIS, MOVE_CONFUSION, MOVE_BULLET_SEED},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_DHELMISE] = {
        .species = SPECIES_DHELMISE,
        .moves = {MOVE_ABSORB, MOVE_RAPID_SPIN, MOVE_ASTONISH, MOVE_WRAP},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_LILEEP] = {
        .species = SPECIES_LILEEP,
        .moves = {MOVE_BULLET_SEED, MOVE_WRAP, MOVE_ASTONISH, MOVE_ACID},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_CAPSAKID] = {
        .heldItem = ITEM_FIRE_STONE,
        .species = SPECIES_CAPSAKID,
        .moves = {MOVE_LEER, MOVE_LEAFAGE, MOVE_BITE, MOVE_NONE},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3,
    },

    [FRONTIER_MON_SCYTHER] = {
        .species = SPECIES_SCYTHER,
        .moves = {MOVE_LEER, MOVE_QUICK_ATTACK, MOVE_FURY_CUTTER, MOVE_FALSE_SWIPE},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_NYMBLE] = {
        .ability = ABILITY_TINTED_LENS,
        .species = SPECIES_NYMBLE,
        .moves = {MOVE_TACKLE, MOVE_LEER, MOVE_STRUGGLE_BUG, MOVE_ASTONISH},
        .nature = NATURE_DOCILE,
        .ball = BALL_PREMIER,
        .numPerfectIVs = 3
    },

    [FRONTIER_MON_PINSIR] = {
        .species = SPECIES_PINSIR,
        .moves = {MOVE_VISE_GRIP, MOVE_FOCUS_ENERGY, MOVE_BIND, MOVE_SEISMIC_TOSS},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_HERACROSS] = {
        .species = SPECIES_HERACROSS,
        .moves = {MOVE_TACKLE, MOVE_LEER, MOVE_FURY_ATTACK, MOVE_ENDURE},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_SHUCKLE] = {
        .species = SPECIES_SHUCKLE,
        .moves = {MOVE_WITHDRAW, MOVE_WRAP, MOVE_ROLLOUT, MOVE_STRUGGLE_BUG},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_ANORITH] = {
        .species = SPECIES_ANORITH,
        .moves = {MOVE_FURY_CUTTER, MOVE_AQUA_JET, MOVE_SMACK_DOWN, MOVE_BUG_BITE},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_SKORUPI] = {
        .species = SPECIES_SKORUPI,
        .moves = {MOVE_POISON_STING, MOVE_LEER, MOVE_POISON_FANG, MOVE_BITE},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_VENIPEDE] = {
        .species = SPECIES_VENIPEDE,
        .moves = {MOVE_POISON_STING, MOVE_ROLLOUT, MOVE_BUG_BITE, MOVE_POISON_TAIL},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_KARRABLAST] = {
        .species = SPECIES_KARRABLAST,
        .moves = {MOVE_PECK, MOVE_LEER, MOVE_FURY_CUTTER, MOVE_ENDURE},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_SHELMET] = {
        .species = SPECIES_SHELMET,
        .moves = {MOVE_ABSORB, MOVE_ACID, MOVE_STRUGGLE_BUG, MOVE_MEGA_DRAIN},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_DURANT] = {
        .species = SPECIES_DURANT,
        .moves = {MOVE_FURY_CUTTER, MOVE_SAND_ATTACK, MOVE_VISE_GRIP, MOVE_METAL_CLAW},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_LARVESTA] = {
        .species = SPECIES_LARVESTA,
        .moves = {MOVE_EMBER, MOVE_STRING_SHOT, MOVE_FLAME_WHEEL, MOVE_BUG_BITE},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_WIMPOD] = {
        .species = SPECIES_WIMPOD,
        .moves = {MOVE_STRUGGLE_BUG, MOVE_SAND_ATTACK, MOVE_DEFENSE_CURL},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_DEWPIDER] = {
        .species = SPECIES_DEWPIDER,
        .moves = {MOVE_WATER_GUN, MOVE_INFESTATION, MOVE_BUG_BITE, MOVE_BITE},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_FALINKS] = {
        .species = SPECIES_FALINKS,
        .moves = {MOVE_TACKLE, MOVE_PROTECT, MOVE_ROCK_SMASH, MOVE_FOCUS_ENERGY},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_DRATINI] = {
        .species = SPECIES_DRATINI,
        .moves = {MOVE_WRAP, MOVE_LEER, MOVE_TWISTER, MOVE_THUNDER_WAVE},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_LARVITAR] = {
        .species = SPECIES_LARVITAR,
        .moves = {MOVE_TACKLE, MOVE_LEER, MOVE_ROCK_THROW, MOVE_PAYBACK},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_BAGON] = {
        .species = SPECIES_BAGON,
        .moves = {MOVE_LEER, MOVE_EMBER, MOVE_BITE, MOVE_DRAGON_BREATH},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_BELDUM] = {
        .species = SPECIES_BELDUM,
        .moves = {MOVE_TACKLE},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_DEINO] = {
        .species = SPECIES_DEINO,
        .moves = {MOVE_TACKLE, MOVE_FOCUS_ENERGY, MOVE_DRAGON_BREATH, MOVE_BITE},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_GOOMY] = {
        .species = SPECIES_GOOMY,
        .moves = {MOVE_TACKLE, MOVE_ABSORB, MOVE_WATER_GUN, MOVE_DRAGON_BREATH},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_JANGMO_O] = {
        .species = SPECIES_JANGMO_O,
        .moves = {MOVE_TACKLE, MOVE_GROWL, MOVE_LEER, MOVE_DRAGON_BREATH},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_DREEPY] = {
        .species = SPECIES_DREEPY,
        .moves = {MOVE_BITE, MOVE_QUICK_ATTACK, MOVE_ASTONISH, MOVE_INFESTATION},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_FRIGIBAX] = {
        .species = SPECIES_FRIGIBAX,
        .moves = {MOVE_TACKLE, MOVE_LEER, MOVE_DRAGON_TAIL, MOVE_ICY_WIND},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_EEVEE] = { 
        .species = SPECIES_EEVEE,
        .moves = {MOVE_TACKLE, MOVE_ATTRACT, MOVE_FLAIL, MOVE_ENDURE},
        .heldItem = ITEM_WATER_STONE, //can be any of Fire/Water/Electric/Moon/Sun/Ice/Leaf stone
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},



    [FRONTIER_MON_OMANYTE] = {
        .species = SPECIES_OMANYTE,
        .moves = {MOVE_MUD_SHOT, MOVE_WATER_GUN, MOVE_ANCIENT_POWER, MOVE_TICKLE},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},

    [FRONTIER_MON_KABUTO] = {
        .species = SPECIES_KABUTO,
        .moves = {MOVE_MEGA_DRAIN, MOVE_ANCIENT_POWER, MOVE_SAND_ATTACK, MOVE_PROTECT},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},






    [FRONTIER_MON_SWINUB] = {
        .species = SPECIES_SWINUB,
        .moves = {MOVE_ICY_WIND, MOVE_DIG, MOVE_ROCK_TOMB, MOVE_ENDURE},
        .nature = NATURE_GENTLE,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_HOUNDOUR] = {
        .species = SPECIES_HOUNDOUR,
        .moves = {MOVE_LEER, MOVE_EMBER, MOVE_HOWL, MOVE_SMOG},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},

    
    [FRONTIER_MON_MURKROW] = {
        .species = SPECIES_MURKROW,
        .moves = {MOVE_PECK, MOVE_ASTONISH, MOVE_GUST, MOVE_HAZE},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},

    
    [FRONTIER_MON_SNEASEL] = {
        .species = SPECIES_SNEASEL,
        .moves = {MOVE_SCRATCH, MOVE_LEER, MOVE_TAUNT, MOVE_QUICK_ATTACK},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},

    
    [FRONTIER_MON_ABSOL] = {
        .species = SPECIES_ABSOL,
        .moves = {MOVE_QUICK_ATTACK, MOVE_LEER, MOVE_DOUBLE_TEAM, MOVE_KNOCK_OFF},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},

    
    [FRONTIER_MON_CARVANHA_1] = {
        .species = SPECIES_CARVANHA,
        .moves = {MOVE_AQUA_JET, MOVE_LEER, MOVE_POISON_FANG, MOVE_FOCUS_ENERGY},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},

    
    [FRONTIER_MON_SPIRITOMB] = {
        .species = SPECIES_SPIRITOMB,
        .moves = {MOVE_NIGHT_SHADE, MOVE_CONFUSE_RAY, MOVE_SHADOW_SNEAK, MOVE_SPITE},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},

    
    [FRONTIER_MON_SANDILE] = {
        .species = SPECIES_SANDILE,
        .moves = {MOVE_LEER, MOVE_POWER_TRIP, MOVE_SAND_ATTACK, MOVE_NONE},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},

    
    [FRONTIER_MON_PAWNIARD] = {
        .species = SPECIES_PAWNIARD,
        .moves = {MOVE_SCRATCH, MOVE_LEER, MOVE_FURY_CUTTER, MOVE_METAL_CLAW},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},

    
    [FRONTIER_MON_VULLABY] = {
        .species = SPECIES_VULLABY,
        .moves = {MOVE_GUST, MOVE_LEER, MOVE_FLATTER, MOVE_PLUCK},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},

    
    [FRONTIER_MON_IMPIDIMP] = {
        .species = SPECIES_IMPIDIMP,
        .moves = {MOVE_FAKE_OUT, MOVE_CONFIDE, MOVE_BITE, MOVE_FLATTER},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},

    
    [FRONTIER_MON_MORPEKO] = {
        .species = SPECIES_MORPEKO,
        .moves = {MOVE_TAIL_WHIP, MOVE_THUNDER_SHOCK, MOVE_LEER, MOVE_POWER_TRIP},
        .heldItem = ITEM_LIFE_ORB,
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},

    
    [FRONTIER_MON_SCRAGGY] = {
        .species = SPECIES_SCRAGGY,
        .moves = {MOVE_LEER, MOVE_LOW_KICK, MOVE_PAYBACK, MOVE_HEADBUTT},
        .heldItem = ITEM_LEFTOVERS,
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},

    
    [FRONTIER_MON_KUBFU] = {
        .species = SPECIES_KUBFU,
        .moves = {MOVE_LEER, MOVE_ROCK_SMASH, MOVE_ENDURE, MOVE_FOCUS_ENERGY},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},

    
    [FRONTIER_MON_LITTEN_1] = {
        .species = SPECIES_LITTEN,
        .moves = {MOVE_SCRATCH, MOVE_GROWL, MOVE_EMBER, MOVE_LICK},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},

    
    [FRONTIER_MON_SPRIGATITO_1] = {
        .species = SPECIES_SPRIGATITO,
        .moves = {MOVE_SCRATCH, MOVE_TAIL_WHIP, MOVE_LEAFAGE, MOVE_BITE},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},

    
    [FRONTIER_MON_FLOETTE_ETERNAL] = {
        .species = SPECIES_FLOETTE_ETERNAL,
        .moves = {MOVE_VINE_WHIP, MOVE_TACKLE, MOVE_FAIRY_WIND, MOVE_SAFEGUARD},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},

    
    [FRONTIER_MON_ZORUA] = {
        .species = SPECIES_ZORUA,
        .moves = {MOVE_SCRATCH, MOVE_LEER, MOVE_TORMENT, MOVE_HONE_CLAWS},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},

    
    [FRONTIER_MON_ZORUA_HISUI] = {
        .species = SPECIES_ZORUA_HISUI,
        .moves = {MOVE_SCRATCH, MOVE_LEER, MOVE_TORMENT, MOVE_HONE_CLAWS},
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},


    


    [FRONTIER_MON_DUSKULL] = {
        .species = SPECIES_DUSKULL,
        .moves = {MOVE_SKILL_SWAP, MOVE_NIGHT_SHADE, MOVE_DISABLE, MOVE_CONFUSE_RAY},
        .heldItem = ITEM_PERSIM_BERRY,
        .nature = NATURE_QUIRKY,
    .ball = BALL_PREMIER,},

    [FRONTIER_MON_ELECTRIKE] = {
        .species = SPECIES_ELECTRIKE,
        .moves = {MOVE_SPARK, MOVE_THUNDER_WAVE, MOVE_ROAR, MOVE_QUICK_ATTACK},
        .heldItem = ITEM_CHERI_BERRY,
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},

    [FRONTIER_MON_VULPIX] = {
        .species = SPECIES_VULPIX,
        .moves = {MOVE_WILL_O_WISP, MOVE_CONFUSE_RAY, MOVE_FIRE_SPIN, MOVE_QUICK_ATTACK},
        .heldItem = ITEM_RAWST_BERRY,
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},

    [FRONTIER_MON_PIKACHU] = {
        .species = SPECIES_PIKACHU,
        .moves = {MOVE_SHOCK_WAVE, MOVE_THUNDER_WAVE, MOVE_DOUBLE_TEAM, MOVE_QUICK_ATTACK},
        .nature = NATURE_DOCILE, 
    .ball = BALL_PREMIER,},

    [FRONTIER_MON_SANDSHREW] = {
        .species = SPECIES_SANDSHREW,
        .moves = {MOVE_DIG, MOVE_ROCK_TOMB, MOVE_SANDSTORM, MOVE_SAND_ATTACK},
        .heldItem = ITEM_SOFT_SAND,
        .nature = NATURE_DOCILE,
    .ball = BALL_PREMIER,},

    [FRONTIER_MON_POLIWAG] = {
        .species = SPECIES_POLIWAG,
        .moves = {MOVE_HYPNOSIS, MOVE_ICY_WIND, MOVE_WATER_GUN, MOVE_RAIN_DANCE},
        .heldItem = ITEM_MYSTIC_WATER,
        .nature = NATURE_RELAXED,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_GEODUDE] = {
        .species = SPECIES_GEODUDE,
        .moves = {MOVE_MAGNITUDE, MOVE_ROCK_BLAST, MOVE_STRENGTH, MOVE_PROTECT},
        .heldItem = ITEM_FOCUS_BAND,
        .nature = NATURE_BRAVE,
    .ball = BALL_PREMIER,},

    [FRONTIER_MON_SNUBBULL] = {
        .species = SPECIES_SNUBBULL,
        .moves = {MOVE_BITE, MOVE_CHARM, MOVE_SWAGGER, MOVE_SCARY_FACE},
        .heldItem = ITEM_SCOPE_LENS,
        .nature = NATURE_RELAXED,
    .ball = BALL_PREMIER,},

    [FRONTIER_MON_REMORAID] = {
        .species = SPECIES_REMORAID,
        .moves = {MOVE_BUBBLE_BEAM, MOVE_AURORA_BEAM, MOVE_PSYBEAM, MOVE_PROTECT},
        .heldItem = ITEM_PETAYA_BERRY,
        .nature = NATURE_QUIRKY,
    .ball = BALL_PREMIER,},


    [FRONTIER_MON_BALTOY] = {
        .species = SPECIES_BALTOY,
        .moves = {MOVE_PSYBEAM, MOVE_ANCIENT_POWER, MOVE_LIGHT_SCREEN, MOVE_MUD_SLAP},
        .heldItem = ITEM_PERSIM_BERRY,
        .nature = NATURE_NAUGHTY,
    .ball = BALL_PREMIER,},

    [FRONTIER_MON_SNORUNT] = {
        .species = SPECIES_SNORUNT,
        .moves = {MOVE_ICY_WIND, MOVE_HEADBUTT, MOVE_LEER, MOVE_BITE},
        .heldItem = ITEM_PERSIM_BERRY,
        .nature = NATURE_BRAVE,
    .ball = BALL_PREMIER,},

   
    [FRONTIER_MON_GULPIN] = {
        .species = SPECIES_GULPIN,
        .moves = {MOVE_TOXIC, MOVE_YAWN, MOVE_PAIN_SPLIT, MOVE_ATTRACT},
        .heldItem = ITEM_LAX_INCENSE,
        .nature = NATURE_SERIOUS,
    .ball = BALL_PREMIER,},

    [FRONTIER_MON_VENONAT] = {
        .species = SPECIES_VENONAT,
        .moves = {MOVE_PSYBEAM, MOVE_SUPERSONIC, MOVE_STUN_SPORE, MOVE_SKILL_SWAP},
        .nature = NATURE_RELAXED,
    .ball = BALL_PREMIER,},

   
   


   

};
