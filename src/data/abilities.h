const struct AbilityInfo gAbilitiesInfo[ABILITIES_COUNT] =
{
    [ABILITY_NONE] =
        {
            .name = _("-------"),
            .description = COMPOUND_STRING("No special ability."),
            .aiRating = 0,
            .cantBeSwapped = TRUE,
            .cantBeTraced = TRUE,
        },

        [ABILITY_STENCH] =
        {
            .name = _("Stench"),
            .description = COMPOUND_STRING("When the user deals damage, there is a 10% chance that targets will flinch."),
            .aiRating = 1,
        },

        [ABILITY_DRIZZLE] =
        {
            .name = _("Drizzle"),
            .description = COMPOUND_STRING("Summons rain for 5 turns when the user enters a battle."),
            .aiRating = 9,
        },

        [ABILITY_SPEED_BOOST] =
        {
            .name = _("Speed Boost"),
            .description = COMPOUND_STRING("Boosts Speed by 1 stage at the end of each turn."),
            .aiRating = 9,
        },

        [ABILITY_BATTLE_ARMOR] =
        {
            .name = _("Battle Armor"),
            .description = COMPOUND_STRING("The user is protected from critical hits."),
            .aiRating = 2,
            .breakable = TRUE,
        },

        [ABILITY_STURDY] =
        {
            .name = _("Sturdy"),
            .description = COMPOUND_STRING("If the user is at full HP and takes a hit that would KO it, it will survive with 1 HP."),
            .aiRating = 6,
            .breakable = TRUE,
        },

        [ABILITY_DAMP] =
        {
            .name = _("Damp"),
            .description = COMPOUND_STRING("Prevents the use of explosive, self-destructing moves."),
            .aiRating = 2,
            .breakable = TRUE,
        },

        [ABILITY_LIMBER] =
        {
            .name = _("Limber"),
            .description = COMPOUND_STRING("The user cannot be paralyzed."),
            .aiRating = 3,
            .breakable = TRUE,
        },

        [ABILITY_SAND_VEIL] =
        {
            .name = _("Sand Veil"),
            .description = COMPOUND_STRING("Boosts the user's evasiveness by 25% in a sandstorm."),
            .aiRating = 3,
            .breakable = TRUE,
        },

        [ABILITY_STATIC] =
        {
            .name = _("Static"),
            .description = COMPOUND_STRING("30% chance to paralyze opponents that make direct contact with the user."),
            .aiRating = 4,
        },

        [ABILITY_VOLT_ABSORB] =
        {
            .name = _("Volt Absorb"),
            .description = COMPOUND_STRING("The user restores up to 25% of its max HP when hit with Electric-type moves."),
            .aiRating = 7,
            .breakable = TRUE,
        },

        [ABILITY_WATER_ABSORB] =
        {
            .name = _("Water Absorb"),
            .description = COMPOUND_STRING("The user restores up to 25% of its max HP when hit with Water-type moves."),
            .aiRating = 7,
            .breakable = TRUE,
        },

        [ABILITY_OBLIVIOUS] =
        {
            .name = _("Oblivious"),
            .description = COMPOUND_STRING("The user cannot be infatuated, intimidated, or be taunted."),
            .aiRating = 2,
            .breakable = TRUE,
        },

        [ABILITY_CLOUD_NINE] =
        {
            .name = _("Cloud Nine"),
            .description = COMPOUND_STRING("Weather effects are negated while the user is on the field."),
            .aiRating = 5,
        },

        [ABILITY_COMPOUND_EYES] =
        {
            .name = _("Compound Eyes"),
            .description = COMPOUND_STRING("Increases the base accuracy of the user's moves by 30%"),
            .aiRating = 7,
        },

        [ABILITY_INSOMNIA] =
        {
            .name = _("Insomnia"),
            .description = COMPOUND_STRING("The user cannot fall asleep."),
            .aiRating = 4,
            .breakable = TRUE,
        },

        [ABILITY_COLOR_CHANGE] =
        {
            .name = _("Color Change"),
            .description = COMPOUND_STRING("The user's type becomes the type of the move used on it."),
            .aiRating = 2,
        },

        [ABILITY_IMMUNITY] =
        {
            .name = _("Immunity"),
            .description = COMPOUND_STRING("The user cannot be poisoned."),
            .aiRating = 4,
            .breakable = TRUE,
        },

        [ABILITY_FLASH_FIRE] =
        {
            .name = _("Flash Fire"),
            .description = COMPOUND_STRING("If hit by a Fire-type move, user takes no damage and boosts its Fire-type moves by 50%"),
            .aiRating = 6,
            .breakable = TRUE,
        },

        [ABILITY_SHIELD_DUST] =
        {
            .name = _("Shield Dust"),
            .description = COMPOUND_STRING("Protects the user from entry hazards and the additional effects of moves."),
            .aiRating = 5,
            .breakable = TRUE,
        },

        [ABILITY_OWN_TEMPO] =
        {
            .name = _("Own Tempo"),
            .description = COMPOUND_STRING("The user cannot be confused or intimidated."),
            .aiRating = 3,
            .breakable = TRUE,
        },

        [ABILITY_SUCTION_CUPS] =
        {
            .name = _("Suction Cups"),
            .description = COMPOUND_STRING("Ignores moves and held items of other Pokémon that would force it to switch out."),
            .aiRating = 2,
            .breakable = TRUE,
        },

        [ABILITY_INTIMIDATE] =
        {
            .name = _("Intimidate"),
            .description = COMPOUND_STRING("When the user enters a battle, it lowers the Attack of opponents by 1 stage."),
            .aiRating = 8,
        },

        [ABILITY_SHADOW_TAG] =
        {
            .name = _("Shadow Tag"),
            .description = COMPOUND_STRING("Prevents non-Ghost Type opponents from escaping or switching out."),
            .aiRating = 10,
        },

        [ABILITY_ROUGH_SKIN] =
        {
            .name = _("Rough Skin"),
            .description = COMPOUND_STRING("When hit by a contact move, attacker takes damage equal to 1/8 of its max HP."),
            .aiRating = 6,
        },

        [ABILITY_WONDER_GUARD] =
        {
            .name = _("Wonder Guard"),
            .description = COMPOUND_STRING("Shedinja can only be hit by super effective moves."),
            .aiRating = 10,
            .cantBeCopied = TRUE,
            .cantBeSwapped = TRUE,
            .breakable = TRUE,
        },

        [ABILITY_LEVITATE] =
        {
            .name = _("Levitate"),
            .description = COMPOUND_STRING("The user is immune to Ground-type and effects that apply to grounded Pokémon."),
            .aiRating = 7,
            .breakable = TRUE,
        },

        [ABILITY_EFFECT_SPORE] =
        {
            .name = _("Effect Spore"),
            .description = COMPOUND_STRING("30% chance an attacker that makes contact is poisoned, paralyzed, or put to sleep."),
            .aiRating = 4,
        },

        [ABILITY_SYNCHRONIZE] =
        {
            .name = _("Synchronize"),
            .description = COMPOUND_STRING("The opponent receives the same status condition it gives to the user."),
            .aiRating = 4,
        },

        [ABILITY_CLEAR_BODY] =
        {
            .name = _("Clear Body"),
            .description = COMPOUND_STRING("Prevents stat reduction unless self-inflicted."),
            .aiRating = 4,
            .breakable = TRUE,
        },

        [ABILITY_NATURAL_CURE] =
        {
            .name = _("Natural Cure"),
            .description = COMPOUND_STRING("Heals the user of status conditions when it switches out of battle."),
            .aiRating = 7,
        },

        [ABILITY_LIGHTNING_ROD] =
        {
            .name = _("Lightning Rod"),
            .description = COMPOUND_STRING("The user draws in all Electric-type moves, raising its Sp. Atk by 1 stage."),
            .aiRating = 7,
            .breakable = TRUE,
        },

        [ABILITY_SERENE_GRACE] =
        {
            .name = _("Serene Grace"),
            .description = COMPOUND_STRING("Doubles the chance of the user's moves triggering their additional effects."),
            .aiRating = 8,
        },

        [ABILITY_SWIFT_SWIM] =
        {
            .name = _("Swift Swim"),
            .description = COMPOUND_STRING("Doubles the Speed of the user in rain."),
            .aiRating = 6,
        },

        [ABILITY_CHLOROPHYLL] =
        {
            .name = _("Chlorophyll"),
            .description = COMPOUND_STRING("Doubles the Speed of the user in harsh sunlight."),
            .aiRating = 6,
        },

        [ABILITY_ILLUMINATE] =
        {
            .name = _("Illuminate"),
            .description = COMPOUND_STRING("Increases the base accuracy of the user's moves by 20%"),
            .aiRating = 0,
            .breakable = TRUE,
        },

        [ABILITY_TRACE] =
        {
            .name = _("Trace"),
            .description = COMPOUND_STRING("Upon entry, user changes its Ability to match that of the opponent."),
            .aiRating = 6,
            .cantBeCopied = TRUE,
            .cantBeTraced = TRUE,
        },

        [ABILITY_HUGE_POWER] =
        {
            .name = _("Huge Power"),
            .description = COMPOUND_STRING("Doubles the user's Attack stat."),
            .aiRating = 10,
        },

        [ABILITY_POISON_POINT] =
        {
            .name = _("Poison Point"),
            .description = COMPOUND_STRING("30% chance to poison attackers that make direct contact with the user."),
            .aiRating = 4,
        },

        [ABILITY_INNER_FOCUS] =
        {
            .name = _("Inner Focus"),
            .description = COMPOUND_STRING("The user cannot be flinched or intimidated."),
            .aiRating = 2,
            .breakable = TRUE,
        },

        [ABILITY_MAGMA_ARMOR] =
        {
            .name = _("Magma Armor"),
            .description = COMPOUND_STRING("The user cannot be frozen."),
            .aiRating = 1,
            .breakable = TRUE,
        },

        [ABILITY_WATER_VEIL] =
        {
            .name = _("Water Veil"),
            .description = COMPOUND_STRING("The user cannot get burned."),
            .aiRating = 4,
            .breakable = TRUE,
        },

        [ABILITY_MAGNET_PULL] =
        {
            .name = _("Magnet Pull"),
            .description = COMPOUND_STRING("Prevents Steel-Type opponents from escaping or switching out."),
            .aiRating = 9,
        },

        [ABILITY_SOUNDPROOF] =
        {
            .name = _("Soundproof"),
            .description = COMPOUND_STRING("The user is unaffected by Sound-based moves."),
            .aiRating = 4,
            .breakable = TRUE,
        },

        [ABILITY_RAIN_DISH] =
        {
            .name = _("Rain Dish"),
            .description = COMPOUND_STRING("The user recovers 6.25% HP during rain at the end of each turn."),
            .aiRating = 3,
        },

        [ABILITY_SAND_STREAM] =
        {
            .name = _("Sand Stream"),
            .description = COMPOUND_STRING("Summons a sandstorm for 5 turns when the user enters a battle."),
            .aiRating = 9,
        },

        [ABILITY_PRESSURE] =
        {
            .name = _("Pressure"),
            .description = COMPOUND_STRING("Causes opponents to expend 1 more PP when using moves against the user."),
            .aiRating = 5,
        },

        [ABILITY_THICK_FAT] =
        {
            .name = _("Thick Fat"),
            .description = COMPOUND_STRING("Damage received from Fire-type and Ice-type moves is halved."),
            .aiRating = 7,
            .breakable = TRUE,
        },

        [ABILITY_EARLY_BIRD] =
        {
            .name = _("Early Bird"),
            .description = COMPOUND_STRING("User wakes up twice as fast."),
            .aiRating = 4,
        },

        [ABILITY_FLAME_BODY] =
        {
            .name = _("Flame Body"),
            .description = COMPOUND_STRING("30% chance to burn opponents that make direct contact with the user."),
            .aiRating = 4,
        },

        [ABILITY_RUN_AWAY] =
        {
            .name = _("Run Away"),
            .description = COMPOUND_STRING("Enables a sure getaway from wild Pokémon."),
            .aiRating = 0,
        },

        [ABILITY_KEEN_EYE] =
        {
            .name = _("Keen Eye"),
            .description = COMPOUND_STRING("Prevents the loss of accuracy."),
            .aiRating = 1,
            .breakable = TRUE,
        },

        [ABILITY_HYPER_CUTTER] =
        {
            .name = _("Hyper Cutter"),
            .description = COMPOUND_STRING("The user's Attack stat cannot be lowered by other Pokémon."),
            .aiRating = 3,
            .breakable = TRUE,
        },

        [ABILITY_PICKUP] =
        {
            .name = _("Pickup"),
            .description = COMPOUND_STRING("10% chance of finding an item at the end of each battle."),
            .aiRating = 1,
        },

        [ABILITY_TRUANT] =
        {
            .name = _("Truant"),
            .description = COMPOUND_STRING("Can't use moves on consecutive turns, except Slack Off."),
            .aiRating = 4,
            .cantBeOverwritten = TRUE,
        },

        [ABILITY_HUSTLE] =
        {
            .name = _("Hustle"),
            .description = COMPOUND_STRING("Increases the user's Attack by 50%, but lowers Accuracy by 20%"),
            .aiRating = 7,
        },

        [ABILITY_CUTE_CHARM] =
        {
            .name = _("Cute Charm"),
            .description = COMPOUND_STRING("30% chance to Infatuate opponents that come into direct contact with the user."),
            .aiRating = 2,
        },

        [ABILITY_PLUS] =
        {
            .name = _("Plus"),
            .description = COMPOUND_STRING("Boosts the user's Sp. Atk stat by 50% if an ally with the Plus or Minus is also in battle."),
            .aiRating = 0,
        },

        [ABILITY_MINUS] =
        {
            .name = _("Minus"),
            .description = COMPOUND_STRING("Boosts the user's Sp. Atk stat by 50% if an ally with the Plus or Minus is also in battle."),
            .aiRating = 0,
        },

        [ABILITY_FORECAST] = //fru todo
        {
            .name = _("Forecast"),
            .description = COMPOUND_STRING("Castform transforms with the weather to change its type to Water, Fire, or Ice."),
            .aiRating = 6,
            .cantBeCopied = TRUE,
            .cantBeTraced = TRUE,
        },

        [ABILITY_STICKY_HOLD] =
        {
            .name = _("Sticky Hold"),
            .description = COMPOUND_STRING("The user's held item cannot be taken or removed by other Pokémon."),
            .aiRating = 3,
            .breakable = TRUE,
        },

        [ABILITY_SHED_SKIN] =
        {
            .name = _("Shed Skin"),
            .description = COMPOUND_STRING("The user has a 33% chance of healing from status conditions at the end of each turn."),
            .aiRating = 7,
        },

        [ABILITY_GUTS] =
        {
            .name = _("Guts"),
            .description = COMPOUND_STRING("Increases the user's Attack by 50% if it has a status condition."),
            .aiRating = 6,
        },

        [ABILITY_MARVEL_SCALE] =
        {
            .name = _("Marvel Scale"),
            .description = COMPOUND_STRING("Increases the user's Defense by 50% if it has a status condition."),
            .aiRating = 5,
            .breakable = TRUE,
        },

        [ABILITY_LIQUID_OOZE] =
        {
            .name = _("Liquid Ooze"),
            .description = COMPOUND_STRING("Opponents who use draining moves on the user lose HP instead of recovering."),
            .aiRating = 3,
        },

        [ABILITY_OVERGROW] =
        {
            .name = _("Overgrow"),
            .description = COMPOUND_STRING("Boosts the power of Grass-type moves by 50% when the user's HP is 1/3 or less."),
            .aiRating = 5,
        },

        [ABILITY_BLAZE] =
        {
            .name = _("Blaze"),
            .description = COMPOUND_STRING("Boosts the power of Fire-type moves by 50% when the user's HP is 1/3 or less."),
            .aiRating = 5,
        },

        [ABILITY_TORRENT] =
        {
            .name = _("Torrent"),
            .description = COMPOUND_STRING("Boosts the power of Water-type moves by 50% when the user's HP is 1/3 or less."),
            .aiRating = 5,
        },

        [ABILITY_SWARM] =
        {
            .name = _("Swarm"),
            .description = COMPOUND_STRING("Boosts the power of Bug-type moves by 50% when the user's HP is 1/3 or less."),
            .aiRating = 5,
        },

        [ABILITY_ROCK_HEAD] =
        {
            .name = _("Rock Head"),
            .description = COMPOUND_STRING("The user takes no recoil damage."),
            .aiRating = 5,
        },

        [ABILITY_DROUGHT] =
        {
            .name = _("Drought"),
            .description = COMPOUND_STRING("Summons harsh sunlight for 5 turns when the user enters a battle."),
            .aiRating = 9,
        },

        [ABILITY_ARENA_TRAP] =
        {
            .name = _("Arena Trap"),
            .description = COMPOUND_STRING("Prevents grounded Pokémon from fleeing from battle, except Ghosts."),
            .aiRating = 9,
        },

        [ABILITY_VITAL_SPIRIT] =
        {
            .name = _("Vital Spirit"),
            .description = COMPOUND_STRING("The user cannot fall asleep."),
            .aiRating = 4,
            .breakable = TRUE,
        },

        [ABILITY_WHITE_SMOKE] =
        {
            .name = _("White Smoke"),
            .description = COMPOUND_STRING("Prevents stat reduction unless self-inflicted."),
            .aiRating = 4,
            .breakable = TRUE,
        },

        [ABILITY_PURE_POWER] =
        {
            .name = _("Pure Power"),
            .description = COMPOUND_STRING("Doubles the user's Attack stat."),
            .aiRating = 10,
        },

        [ABILITY_SHELL_ARMOR] =
        {
            .name = _("Shell Armor"),
            .description = COMPOUND_STRING("The user is protected from critical hits."),
            .aiRating = 2,
            .breakable = TRUE,
        },

        [ABILITY_AIR_LOCK] =
        {
            .name = _("Air Lock"),
            .description = COMPOUND_STRING("Weather effects are negated while the user is on the field."),
            .aiRating = 5,
        },

        [ABILITY_TANGLED_FEET] =
        {
            .name = _("Tangled Feet"),
            .description = COMPOUND_STRING("Doubles the Pokémon's evasiveness if it is confused."),
            .aiRating = 2,
            .breakable = TRUE,
        },

        [ABILITY_MOTOR_DRIVE] =
        {
            .name = _("Motor Drive"),
            .description = COMPOUND_STRING("If hit by an Electric-type move, user takes no damage and raises its Speed by 1 stage."),
            .aiRating = 6,
            .breakable = TRUE,
        },

        [ABILITY_RIVALRY] = 
        {
            .name = _("Rivalry"),
            .description = COMPOUND_STRING("Boosts the power of the user's moves by 25% against targets of the same gender."),
            .aiRating = 1,
        },

        [ABILITY_STEADFAST] =
        {
            .name = _("Steadfast"),
            .description = COMPOUND_STRING("Increases the user's Speed by 1 stage each time it flinches."),
            .aiRating = 2,
        },

        [ABILITY_SNOW_CLOAK] =
        {
            .name = _("Snow Cloak"),
            .description = COMPOUND_STRING("Boosts the user's evasiveness by 25% in snow."),
            .aiRating = 3,
            .breakable = TRUE,
        },

        [ABILITY_GLUTTONY] =
        {
            .name = _("Gluttony"),
            .description = COMPOUND_STRING("Berries will be eaten at 50% health if they normally would at 25%"),
            .aiRating = 3,
        },

        [ABILITY_ANGER_POINT] =
        {
            .name = _("Anger Point"),
            .description = COMPOUND_STRING("User's Attack stat is maxed out if struck by a critical hit."),
            .aiRating = 4,
        },

        [ABILITY_UNBURDEN] =
        {
            .name = _("Unburden"),
            .description = COMPOUND_STRING("Doubles the user's Speed once it consumes its held item."),
            .aiRating = 7,
        },

        [ABILITY_HEATPROOF] =
        {
            .name = _("Heatproof"),
            .description = COMPOUND_STRING("Damage received from Fire-type moves and Burn Status is halved."),
            .aiRating = 5,
            .breakable = TRUE,
        },

        [ABILITY_SIMPLE] =
        {
            .name = _("Simple"),
            .description = COMPOUND_STRING("Doubles the number of stages that the user's stat is increased or decreased."),
            .aiRating = 8,
            .breakable = TRUE,
        },

        [ABILITY_DRY_SKIN] =
        {
            .name = _("Dry Skin"),
            .description = COMPOUND_STRING("Heals from Water attacks and rain. Hurt by Fire attacks and harsh sunlight."),
            .aiRating = 6,
            .breakable = TRUE,
        },

        [ABILITY_DOWNLOAD] =
        {
            .name = _("Download"),
            .description = COMPOUND_STRING("Raises the user's Atk or Sp. Atk by 1 stage depending on the foe's defensive stats."),
            .aiRating = 7,
        },

        [ABILITY_IRON_FIST] =
        {
            .name = _("Iron Fist"),
            .description = COMPOUND_STRING("Boosts the damage done by punching moves by 30%"),
            .aiRating = 6,
        },

        [ABILITY_POISON_HEAL] =
        {
            .name = _("Poison Heal"),
            .description = COMPOUND_STRING("Heals 12.5% of its max HP while poisoned at the end of each turn."),
            .aiRating = 8,
        },

        [ABILITY_ADAPTABILITY] =
        {
            .name = _("Adaptability"),
            .description = COMPOUND_STRING("Increases the user's STAB multiplier from 1.5x to 2.0x."),
            .aiRating = 8,
        },

        [ABILITY_SKILL_LINK] =
        {
            .name = _("Skill Link"),
            .description = COMPOUND_STRING("Moves that hit 2-5 times will always strike 5 times."),
            .aiRating = 7,
        },

        [ABILITY_HYDRATION] =
        {
            .name = _("Hydration"),
            .description = COMPOUND_STRING("Cures the user's status conditions at the end of every turn in rain."),
            .aiRating = 4,
        },

        [ABILITY_SOLAR_POWER] =
        {
            .name = _("Solar Power"),
            .description = COMPOUND_STRING("Boosts the user's Special Attack by 50% during harsh sunlight."),
            .aiRating = 3,
        },

        [ABILITY_QUICK_FEET] =
        {
            .name = _("Quick Feet"),
            .description = COMPOUND_STRING("Doubles the user's Speed if it is affected by a status condition."),
            .aiRating = 5,
        },

        [ABILITY_NORMALIZE] =
        {
            .name = _("Normalize"),
            .description = COMPOUND_STRING("All the user's moves become Normal type, and their power is boosted by 20%"),
            .aiRating = -1,
        },

        [ABILITY_SNIPER] =
        {
            .name = _("Sniper"),
            .description = COMPOUND_STRING("Critical hits deal 2.25x damage instead of 1.5x."),
            .aiRating = 3,
        },

        [ABILITY_MAGIC_GUARD] =
        {
            .name = _("Magic Guard"),
            .description = COMPOUND_STRING("This Pokémon can't be damaged by Status, Recoil and Hazards."),
            .aiRating = 9,
        },

        [ABILITY_NO_GUARD] =
        {
            .name = _("No Guard"),
            .description = COMPOUND_STRING("The accuracy of moves used both by and against the user becomes 100%"),
            .aiRating = 8,
        },

        [ABILITY_STALL] =
        {
            .name = _("Stall"),
            .description = COMPOUND_STRING("User always moves last in its priority bracket."),
            .aiRating = -1,
        },

        [ABILITY_TECHNICIAN] =
        {
            .name = _("Technician"),
            .description = COMPOUND_STRING("Boosts the power of the user's moves by 50% if their power is 60 or less."),
            .aiRating = 8,
        },

        [ABILITY_LEAF_GUARD] =
        {
            .name = _("Leaf Guard"),
            .description = COMPOUND_STRING("The user is immune to status conditions in harsh sunlight."),
            .aiRating = 2,
            .breakable = TRUE,
        },

        [ABILITY_KLUTZ] =
        {
            .name = _("Klutz"),
            .description = COMPOUND_STRING("The user cannot use or benefit from held items."),
            .aiRating = -1,
        },

        [ABILITY_MOLD_BREAKER] =
        {
            .name = _("Mold Breaker"),
            .description = COMPOUND_STRING("The user's moves are unaffected by the Ability of the target."),
            .aiRating = 7,
        },

        [ABILITY_SUPER_LUCK] =
        {
            .name = _("Super Luck"),
            .description = COMPOUND_STRING("The user has a 1-stage Critical-Hit Ratio Boost."),
            .aiRating = 3,
        },

        [ABILITY_AFTERMATH] =
        {
            .name = _("Aftermath"),
            .description = COMPOUND_STRING("If the user faints by a contact move, the attacker loses 25% of its max HP."),
            .aiRating = 5,
        },

        [ABILITY_ANTICIPATION] =
        {
            .name = _("Anticipation"),
            .description = COMPOUND_STRING("On entry, shudders if an enemy has a super effective attack."),
            .aiRating = 2,
        },

        [ABILITY_FOREWARN] =
        {
            .name = _("Forewarn"),
            .description = COMPOUND_STRING("On entry, identifies the enemy's highest-power move."),
            .aiRating = 2,
        },

        [ABILITY_UNAWARE] =
        {
            .name = _("Unaware"),
            .description = COMPOUND_STRING("The user ignores the opponent's stat changes when attacking or receiving attacks."),
            .aiRating = 6,
            .breakable = TRUE,
        },

        [ABILITY_TINTED_LENS] =
        {
            .name = _("Tinted Lens"),
            .description = COMPOUND_STRING("Doubles the damage of the user's not very effective moves."),
            .aiRating = 7,
        },

        [ABILITY_FILTER] =
        {
            .name = _("Filter"),
            .description = COMPOUND_STRING("Reduces the damage taken from super effective moves by 25%"),
            .aiRating = 6,
            .breakable = TRUE,
        },

        [ABILITY_SLOW_START] =
        {
            .name = _("Slow Start"),
            .description = COMPOUND_STRING("Upon entry, Attack and Speed are halved for 5 turns. Resets timer if switched out."),
            .aiRating = -2,
        },

        [ABILITY_SCRAPPY] =
        {
            .name = _("Scrappy"),
            .description = COMPOUND_STRING("Can hit Ghost-types with Normal/Fighting moves. Unaffected by Intimidate."),
            .aiRating = 6,
        },

        [ABILITY_STORM_DRAIN] =
        {
            .name = _("Storm Drain"),
            .description = COMPOUND_STRING("The user draws in all Water-type moves, raising its Sp. Atk by 1 stage."),
            .aiRating = 7,
            .breakable = TRUE,
        },

        [ABILITY_ICE_BODY] =
        {
            .name = _("Ice Body"),
            .description = COMPOUND_STRING("The user recovers 6.25% HP during snow at the end of each turn."),
            .aiRating = 3,
        },

        [ABILITY_SOLID_ROCK] =
        {
            .name = _("Solid Rock"),
            .description = COMPOUND_STRING("Reduces the damage taken from super effective moves by 25%"),
            .aiRating = 6,
            .breakable = TRUE,
        },

        [ABILITY_SNOW_WARNING] =
        {
            .name = _("Snow Warning"),
            .description = COMPOUND_STRING("Summons snow for 5 turns when the user enters a battle."),
            .aiRating = 8,
        },

        [ABILITY_HONEY_GATHER] =
        {
            .name = _("Honey Gather"),
            .description = COMPOUND_STRING("May gather Honey."),
            .aiRating = 0,
        },

        [ABILITY_FRISK] =
        {
            .name = _("Frisk"),
            .description = COMPOUND_STRING("Identifies the opponents' held item on entry."),
            .aiRating = 3,
        },

        [ABILITY_RECKLESS] =
        {
            .name = _("Reckless"),
            .description = COMPOUND_STRING("Boosts the power of moves that have recoil or crash damage by 20%"),
            .aiRating = 6,
        },

        [ABILITY_MULTITYPE] =
        {
            .name = _("Multitype"),
            .description = COMPOUND_STRING("The user changes its type to match the Plate or Z-Crystal it holds."),
            .aiRating = 8,
            .cantBeCopied = TRUE,
            .cantBeSwapped = TRUE,
            .cantBeTraced = TRUE,
            .cantBeSuppressed = TRUE,
            .cantBeOverwritten = TRUE,
        },

        [ABILITY_FLOWER_GIFT] =
        {
            .name = _("Flower Gift"),
            .description = COMPOUND_STRING("In harsh sunlight, user changes forme to Sunshine. Attack/Speed is boosted by 50%"),
            .aiRating = 4,
            .cantBeCopied = TRUE,
            .cantBeTraced = TRUE,
            .breakable = TRUE,
        },

        [ABILITY_BAD_DREAMS] =
        {
            .name = _("Bad Dreams"),
            .description = COMPOUND_STRING("Bypasses Sleep Clause. Damages sleeping foes for 1/8 of their max HP each turn."),
            .aiRating = 4,
        },

        [ABILITY_PICKPOCKET] =
        {
            .name = _("Pickpocket"),
            .description = COMPOUND_STRING("If the user without item is hit by a contact move, it will steal the attacker's held item."),
            .aiRating = 3,
        },

        [ABILITY_SHEER_FORCE] =
        {
            .name = _("Sheer Force"),
            .description = COMPOUND_STRING("Moves with additional effects get a boost in damage of 30%, but lose those effects."),
            .aiRating = 8,
        },

        [ABILITY_CONTRARY] =
        {
            .name = _("Contrary"),
            .description = COMPOUND_STRING("Inverts all changes to the stat stages of the user."),
            .aiRating = 8,
            .breakable = TRUE,
        },

        [ABILITY_UNNERVE] =
        {
            .name = _("Unnerve"),
            .description = COMPOUND_STRING("Foes can't eat Berries."),
            .aiRating = 3,
        },

        [ABILITY_DEFIANT] =
        {
            .name = _("Defiant"),
            .description = COMPOUND_STRING("Raises the user's Attack by 2 stages when its stats are lowered."),
            .aiRating = 5,
        },

        [ABILITY_DEFEATIST] =
        {
            .name = _("Defeatist"),
            .description = COMPOUND_STRING("Halves the user's Attack and Sp. Atk when its HP is 1/3 or less."),
            .aiRating = -1,
        },

        [ABILITY_CURSED_BODY] =
        {
            .name = _("Cursed Body"),
            .description = COMPOUND_STRING("30% chance to disable the opponent's move that damages the user for 4 turns."),
            .aiRating = 4,
        },

        [ABILITY_HEALER] =
        {
            .name = _("Healer"),
            .description = COMPOUND_STRING("50% chance of user curing the status conditions of its allies at the end of each turn."),
            .aiRating = 0,
        },

        [ABILITY_FRIEND_GUARD] =
        {
            .name = _("Friend Guard"),
            .description = COMPOUND_STRING("Reduces the damage allies take by 25%"),
            .aiRating = 0,
            .breakable = TRUE,
        },

        [ABILITY_WEAK_ARMOR] =
        {
            .name = _("Weak Armor"),
            .description = COMPOUND_STRING("When the user takes a hit from a physical move, Defense -1 stage, Speed +2 stages."),
            .aiRating = 2,
        },

        [ABILITY_HEAVY_METAL] =
        {
            .name = _("Heavy Metal"),
            .description = COMPOUND_STRING("Doubles weight."),
            .aiRating = -1,
            .breakable = TRUE,
        },

        [ABILITY_LIGHT_METAL] =
        {
            .name = _("Light Metal"),
            .description = COMPOUND_STRING("Halves weight."),
            .aiRating = 2,
            .breakable = TRUE,
        },

        [ABILITY_MULTISCALE] =
        {
            .name = _("Multiscale"),
            .description = COMPOUND_STRING("Halves the damage the user takes while its HP is full."),
            .aiRating = 8,
            .breakable = TRUE,
        },

        [ABILITY_TOXIC_BOOST] =
        {
            .name = _("Toxic Boost"),
            .description = COMPOUND_STRING("Boosts Attack by 50% when poisoned. Takes no damage from poison."),
            .aiRating = 6,
        },

        [ABILITY_FLARE_BOOST] =
        {
            .name = _("Flare Boost"),
            .description = COMPOUND_STRING("Boosts Sp. Atk by 50% when burned. Takes no damage from burns."),
            .aiRating = 5,
        },

        [ABILITY_HARVEST] =
        {
            .name = _("Harvest"),
            .description = COMPOUND_STRING("50% chance of recycling an used Berry at the end of every turn. 100% in harsh sunlight."),
            .aiRating = 5,
        },

        [ABILITY_TELEPATHY] =
        {
            .name = _("Telepathy"),
            .description = COMPOUND_STRING("The user dodges attacks from its allies."),
            .aiRating = 0,
            .breakable = TRUE,
        },

        [ABILITY_MOODY] =
        {
            .name = _("Moody"),
            .description = COMPOUND_STRING("Every turn, raises a random stat by 2 stages, but lowers another random stat by 1 stage."),
            .aiRating = 10,
        },

        [ABILITY_OVERCOAT] =
        {
            .name = _("Overcoat"),
            .description = COMPOUND_STRING("Protects user from weather and powder effects."),
            .aiRating = 5,
            .breakable = TRUE,
        },

        [ABILITY_POISON_TOUCH] =
        {
            .name = _("Poison Touch"),
            .description = COMPOUND_STRING("30% chance to poison opponents that the user attacks and makes direct contact with."),
            .aiRating = 4,
        },

        [ABILITY_REGENERATOR] =
        {
            .name = _("Regenerator"),
            .description = COMPOUND_STRING("The user restores up to 1/3 of its max HP when switched out of battle."),
            .aiRating = 8,
        },

        [ABILITY_BIG_PECKS] =
        {
            .name = _("Big Pecks"),
            .description = COMPOUND_STRING("Protects the user from Defense lowering effects."),
            .aiRating = 1,
            .breakable = TRUE,
        },

        [ABILITY_SAND_RUSH] =
        {
            .name = _("Sand Rush"),
            .description = COMPOUND_STRING("Doubles the Speed of the user in sandstorm."),
            .aiRating = 6,
        },

        [ABILITY_WONDER_SKIN] =
        {
            .name = _("Wonder Skin"),
            .description = COMPOUND_STRING("The Accuracy of Status moves targeting the user becomes 50%"),
            .aiRating = 4,
            .breakable = TRUE,
        },

        [ABILITY_ANALYTIC] =
        {
            .name = _("Analytic"),
            .description = COMPOUND_STRING("Boosts the power of the user's moves by 30% when the user is the last to move that turn."),
            .aiRating = 5,
        },

        [ABILITY_ILLUSION] =
        {
            .name = _("Illusion"),
            .description = COMPOUND_STRING("Disguises as the your team's last member. 30% damage boost while the Illusion is up."),
            .aiRating = 8,
            .cantBeCopied = TRUE,
            .cantBeSwapped = TRUE,
            .cantBeTraced = TRUE,
        },

        [ABILITY_IMPOSTER] =
        {
            .name = _("Imposter"),
            .description = COMPOUND_STRING("Transforms into the foe. Copies ability. moves and stats, except HP."),
            .aiRating = 9,
            .cantBeCopied = TRUE,
            .cantBeTraced = TRUE,
        },

        [ABILITY_INFILTRATOR] =
        {
            .name = _("Infiltrator"),
            .description = COMPOUND_STRING("Ignores the effects of Reflect, Light Screen, Aurora Veil, Safeguard and Substitute."),
            .aiRating = 6,
        },

        [ABILITY_MUMMY] =
        {
            .name = _("Mummy"),
            .description = COMPOUND_STRING("When the user is hit by a contact move, the attacker's Ability becomes Mummy."),
            .aiRating = 5,
        },

        [ABILITY_MOXIE] =
        {
            .name = _("Moxie"),
            .description = COMPOUND_STRING("The user's Attack is raised by 1 stage whenever it knocks out a Pokémon."),
            .aiRating = 7,
        },

        [ABILITY_JUSTIFIED] =
        {
            .name = _("Justified"),
            .description = COMPOUND_STRING("When the user is hit by a Dark-type move, its Attack is raised by 1 stage."),
            .aiRating = 4,
        },

        [ABILITY_RATTLED] =
        {
            .name = _("Rattled"),
            .description = COMPOUND_STRING("Raises Speed by 1 stage when hit by a Dark, Ghost, or Bug-type attack."),
            .aiRating = 3,
        },

        [ABILITY_MAGIC_BOUNCE] =
        {
            .name = _("Magic Bounce"),
            .description = COMPOUND_STRING("The user reflects status moves and hazards back at the opponent."),
            .aiRating = 9,
            .breakable = TRUE,
        },

        [ABILITY_SAP_SIPPER] =
        {
            .name = _("Sap Sipper"),
            .description = COMPOUND_STRING("Raises Attack by 1 stage if hit by a Grass-type move, immune to Grass-type moves."),
            .aiRating = 7,
            .breakable = TRUE,
        },

        [ABILITY_PRANKSTER] =
        {
            .name = _("Prankster"),
            .description = COMPOUND_STRING("Gives +1 priority to status moves."),
            .aiRating = 17,
        },

        [ABILITY_SAND_FORCE] =
        {
            .name = _("Sand Force"),
            .description = COMPOUND_STRING("Boosts Rock, Ground, and Steel-type moves by 30% in sandstorm."),
            .aiRating = 4,
        },

        [ABILITY_IRON_BARBS] =
        {
            .name = _("Iron Barbs"),
            .description = COMPOUND_STRING("When hit by a contact move, attacker takes damage equal to 1/8 of its max HP."),
            .aiRating = 6,
        },

        [ABILITY_ZEN_MODE] = 
        {
            .name = _("Zen Mode"),
            .description = COMPOUND_STRING("Transforms into Zen Mode upon entry."),
            .aiRating = -1,
            .cantBeCopied = TRUE,
            .cantBeSwapped = TRUE,
            .cantBeTraced = TRUE,
            .cantBeSuppressed = B_UPDATED_ABILITY_DATA >= GEN_7,
        },

        [ABILITY_VICTORY_STAR] =
        {
            .name = _("Victory Star"),
            .description = COMPOUND_STRING("Boosts the Accuracy of the user and its allies by 10%"),
            .aiRating = 6,
        },

        [ABILITY_TURBOBLAZE] =
        {
            .name = _("Turboblaze"),
            .description = COMPOUND_STRING("The user's moves are unaffected by the Ability of the target."),
            .aiRating = 7,
        },

        [ABILITY_TERAVOLT] =
        {
            .name = _("Teravolt"),
            .description = COMPOUND_STRING("The user's moves are unaffected by the Ability of the target."),
            .aiRating = 7,
        },

        [ABILITY_AROMA_VEIL] =
        {
            .name = _("Aroma Veil"),
            .description = COMPOUND_STRING("Protects the user and its allies from effects that prevent the use of moves."),
            .aiRating = 3,
            .breakable = TRUE,
        },

        [ABILITY_FLOWER_VEIL] =
        {
            .name = _("Flower Veil"),
            .description = COMPOUND_STRING("Ally Grass-types cannot be afflicted by status, or have their stats lowered by opponents."),
            .aiRating = 0,
        },

        [ABILITY_CHEEK_POUCH] =
        {
            .name = _("Cheek Pouch"),
            .description = COMPOUND_STRING("User recovers 1/3 of its max HP when it eats a Berry, in addition to the Berry's effect."),
            .aiRating = 4,
        },

        [ABILITY_PROTEAN] = 
        {
            .name = _("Protean"),
            .description = COMPOUND_STRING("User changes type to match the type of its latest used move."),
            .aiRating = 8,
        },

        [ABILITY_FUR_COAT] =
        {
            .name = _("Fur Coat"),
            .description = COMPOUND_STRING("Halves damage taken from physical moves."),
            .aiRating = 7,
            .breakable = TRUE,
        },

        [ABILITY_MAGICIAN] =
        {
            .name = _("Magician"),
            .description = COMPOUND_STRING("If the user without item is hit by a contact move, it will steal the attacker's held item."),
            .aiRating = 3,
        },

        [ABILITY_BULLETPROOF] =
        {
            .name = _("Bulletproof"),
            .description = COMPOUND_STRING("The user is immune to ball and bomb moves."),
            .aiRating = 7,
        },

        [ABILITY_COMPETITIVE] =
        {
            .name = _("Competitive"),
            .description = COMPOUND_STRING("Raises the user's Sp. Atk by 2 stages when its stats are lowered."),
            .aiRating = 5,
        },

        [ABILITY_STRONG_JAW] =
        {
            .name = _("Strong Jaw"),
            .description = COMPOUND_STRING("Boosts the damage done by biting moves by 50%"),
            .aiRating = 6,
        },

        [ABILITY_REFRIGERATE] =
        {
            .name = _("Refrigerate"),
            .description = COMPOUND_STRING("The user's Normal-type moves become Ice-type and their power is boosted by 20%"),
            .aiRating = 8,
        },

        [ABILITY_SWEET_VEIL] =
        {
            .name = _("Sweet Veil"),
            .description = COMPOUND_STRING("User and allies cannot fall asleep."),
            .aiRating = 4,
            .breakable = TRUE,
        },

        [ABILITY_STANCE_CHANGE] =
        {
            .name = _("Stance Change"),
            .description = COMPOUND_STRING("King's Shield changes user to Shield Form. Attacking changes user to Blade Form."),
            .aiRating = 10,
            .cantBeCopied = TRUE,
            .cantBeSwapped = TRUE,
            .cantBeTraced = TRUE,
            .cantBeSuppressed = TRUE,
            .cantBeOverwritten = TRUE,
        },

        [ABILITY_GALE_WINGS] =
        {
            .name = _("Gale Wings"),
            .description = COMPOUND_STRING("Flying-Type moves get +1 Priority while the user is at full HP."),
            .aiRating = 6,
        },

        [ABILITY_MEGA_LAUNCHER] =
        {
            .name = _("Mega Launcher"),
            .description = COMPOUND_STRING("Boosts aura and pulse moves by 50%"),
            .aiRating = 7,
        },

        [ABILITY_GRASS_PELT] =
        {
            .name = _("Grass Pelt"),
            .description = COMPOUND_STRING("Boost the user's Defense by 50% on Grassy Terrain."),
            .aiRating = 2,
            .breakable = TRUE,
        },

        [ABILITY_SYMBIOSIS] =
        {
            .name = _("Symbiosis"),
            .description = COMPOUND_STRING("Passes held item to an ally which loses theirs."),
            .aiRating = 0,
        },

        [ABILITY_TOUGH_CLAWS] =
        {
            .name = _("Tough Claws"),
            .description = COMPOUND_STRING("Boosts the damage of moves that make physical contact by 30%"),
            .aiRating = 7,
        },

        [ABILITY_PIXILATE] =
        {
            .name = _("Pixilate"),
            .description = COMPOUND_STRING("The user's Normal-type moves become Fairy-type and their power is boosted by 20%"),
            .aiRating = 8,
        },

        [ABILITY_GOOEY] =
        {
            .name = _("Gooey"),
            .description = COMPOUND_STRING("When the user is hit by a contact move, the attacker's Speed is lowered by 1 stage."),
            .aiRating = 5,
        },

        [ABILITY_AERILATE] =
        {
            .name = _("Aerilate"),
            .description = COMPOUND_STRING("The user's Normal-type moves become Flying-type and their power is boosted by 20%"),
            .aiRating = 8,
        },

        [ABILITY_PARENTAL_BOND] =
        {
            .name = _("Parental Bond"),
            .description = COMPOUND_STRING("Moves hit a second time for 25% damage."),
            .aiRating = 10,
        },

        [ABILITY_DARK_AURA] =
        {
            .name = _("Dark Aura"),
            .description = COMPOUND_STRING("Boosts the power of the Dark-type moves of all Pokémon on the field by 33%"),
            .aiRating = 6,
        },

        [ABILITY_FAIRY_AURA] =
        {
            .name = _("Fairy Aura"),
            .description = COMPOUND_STRING("Boosts the power of the Fairy-type moves of all Pokémon on the field by 33%"),
            .aiRating = 6,
        },

        [ABILITY_AURA_BREAK] =
        {
            .name = _("Aura Break"),
            .description = COMPOUND_STRING("The effects of Aura Abilities are reversed to lower the power of affected moves."),
            .aiRating = 3,
        },

        [ABILITY_PRIMORDIAL_SEA] =
        {
            .name = _("Primordial Sea"),
            .description = COMPOUND_STRING("Summons heavy rain on entry, lasting until user leaves the field."),
            .aiRating = 10,
        },

        [ABILITY_DESOLATE_LAND] =
        {
            .name = _("Desolate Land"),
            .description = COMPOUND_STRING("Summons intense sunlight on entry, lasting until user leaves the field."),
            .aiRating = 10,
        },

        [ABILITY_DELTA_STREAM] =
        {
            .name = _("Delta Stream"),
            .description = COMPOUND_STRING("Summons strong winds on entry, lasting until user leaves the field. No Flying weaknesses."),
            .aiRating = 10,
        },

        [ABILITY_STAMINA] =
        {
            .name = _("Stamina"),
            .description = COMPOUND_STRING("When the user takes a hit, its Defense is raised by 1 stage."),
            .aiRating = 6,
        },

        [ABILITY_WIMP_OUT] =
        {
            .name = _("Wimp Out"),
            .description = COMPOUND_STRING("Switches out when its HP is half or less, but after it has executed this turn's move."),
            .aiRating = 3,
        },

        [ABILITY_EMERGENCY_EXIT] =
        {
            .name = _("Emergency Exit"),
            .description = COMPOUND_STRING("Switches out when its HP is half or less, but after it has executed this turn's move."),
            .aiRating = 3,
        },

        [ABILITY_WATER_COMPACTION] =
        {
            .name = _("Water Compaction"),
            .description = COMPOUND_STRING("Raises the Defense of the user when it is hit by a Water-type move by 2 stages."),
            .aiRating = 4,
        },

        [ABILITY_MERCILESS] =
        {
            .name = _("Merciless"),
            .description = COMPOUND_STRING("All attacks against poisoned foes become critical hits."),
            .aiRating = 4,
        },

        [ABILITY_SHIELDS_DOWN] =
        {
            .name = _("Shields Down"),
            .description = COMPOUND_STRING("Changes Minior's forms. Above half HP, Meteor Form, below half HP, Core Form."),
            .aiRating = 6,
            .cantBeCopied = TRUE,
            .cantBeSwapped = TRUE,
            .cantBeTraced = TRUE,
            .cantBeSuppressed = TRUE,
            .cantBeOverwritten = TRUE,
        },

        [ABILITY_STAKEOUT] =
        {
            .name = _("Stakeout"),
            .description = COMPOUND_STRING("Doubles the damage dealt to a target that has just switched into battle."),
            .aiRating = 6,
        },

        [ABILITY_WATER_BUBBLE] =
        {
            .name = _("Water Bubble"),
            .description = COMPOUND_STRING("Halves Fire-type damage taken, and doubles Water-type damage inflicted."),
            .aiRating = 8,
        },

        [ABILITY_STEELWORKER] =
        {
            .name = _("Steelworker"),
            .description = COMPOUND_STRING("Boosts Steel-type moves by 50%"),
            .aiRating = 6,
        },

        [ABILITY_BERSERK] =
        {
            .name = _("Berserk"),
            .description = COMPOUND_STRING("Raises the user's Sp. Atk by 1 stage when a hit causes its HP to drop to half or less."),
            .aiRating = 5,
        },

        [ABILITY_SLUSH_RUSH] =
        {
            .name = _("Slush Rush"),
            .description = COMPOUND_STRING("Doubles the Speed of the user in snow."),
            .aiRating = 5,
        },

        [ABILITY_LONG_REACH] =
        {
            .name = _("Long Reach"),
            .description = COMPOUND_STRING("None of the moves used by this Pokémon are considered contact moves."),
            .aiRating = 3,
        },

        [ABILITY_LIQUID_VOICE] =
        {
            .name = _("Liquid Voice"),
            .description = COMPOUND_STRING("The user's sound-based moves become Water-type."),
            .aiRating = 5,
        },

        [ABILITY_TRIAGE] =
        {
            .name = _("Triage"),
            .description = COMPOUND_STRING("Gives +3 Priority to damaging and status moves that heal used by this Pokémon."),
            .aiRating = 7,
        },

        [ABILITY_GALVANIZE] =
        {
            .name = _("Galvanize"),
            .description = COMPOUND_STRING("The user's Normal-type moves become Electric-type and their power is boosted by 20%"),
            .aiRating = 8,
        },

        [ABILITY_SURGE_SURFER] =
        {
            .name = _("Surge Surfer"),
            .description = COMPOUND_STRING("Doubles the Speed of the user in Electric Terrain."),
            .aiRating = 4,
        },

        [ABILITY_SCHOOLING] =
        {
            .name = _("Schooling"),
            .description = COMPOUND_STRING("Forms a school if health is at least 25% and level is 20 or more."),
            .aiRating = 6,
            .cantBeCopied = TRUE,
            .cantBeSwapped = TRUE,
            .cantBeTraced = TRUE,
            .cantBeSuppressed = TRUE,
            .cantBeOverwritten = TRUE,
        },

        [ABILITY_DISGUISE] =
        {
            .name = _("Disguise"),
            .description = COMPOUND_STRING("When hit, user loses 1/8 of its max HP instead, then changes into Busted Form."),
            .aiRating = 8,
            .breakable = TRUE,
            .cantBeCopied = TRUE,
            .cantBeSwapped = TRUE,
            .cantBeTraced = TRUE,
            .cantBeSuppressed = TRUE,
            .cantBeOverwritten = TRUE,
            .failsOnImposter = TRUE,
        },

        [ABILITY_BATTLE_BOND] =
        {
            .name = _("Battle Bond"),
            .description = COMPOUND_STRING("Changes to Ash Greninja Form after KOing an opponent."),
            .aiRating = 6,
            .cantBeCopied = TRUE,
            .cantBeSwapped = TRUE,
            .cantBeTraced = TRUE,
            .cantBeSuppressed = TRUE,
            .cantBeOverwritten = TRUE,
        },

        [ABILITY_POWER_CONSTRUCT] =
        {
            .name = _("Power Construct"),
            .description = COMPOUND_STRING("Changes to Complete Forme when the user's HP drops to half or less."),
            .aiRating = 10,
            .cantBeCopied = TRUE,
            .cantBeSwapped = TRUE,
            .cantBeTraced = TRUE,
            .cantBeSuppressed = TRUE,
            .cantBeOverwritten = TRUE,
        },

        [ABILITY_CORROSION] =
        {
            .name = _("Corrosion"),
            .description = COMPOUND_STRING("User can hit and inflict Poison Status on Steel-types with its Poison-type moves."),
            .aiRating = 5,
        },

        [ABILITY_COMATOSE] =
        {
            .name = _("Comatose"),
            .description = COMPOUND_STRING("User is considered to be asleep, can attack and can't be statused. Works with Facade."),
            .aiRating = 6,
            .cantBeCopied = TRUE,
            .cantBeSwapped = TRUE,
            .cantBeTraced = TRUE,
            .cantBeSuppressed = TRUE,
            .cantBeOverwritten = TRUE,
        },

        [ABILITY_QUEENLY_MAJESTY] =
        {
            .name = _("Queenly Majesty"),
            .description = COMPOUND_STRING("Opponents are unable to use priority moves against the user or its allies."),
            .aiRating = 6,
            .breakable = TRUE,
        },

        [ABILITY_INNARDS_OUT] =
        {
            .name = _("Innards Out"),
            .description = COMPOUND_STRING("When fainted by an attack, user deals the same amount of damage to the attacker."),
            .aiRating = 5,
        },

        [ABILITY_DANCER] =
        {
            .name = _("Dancer"),
            .description = COMPOUND_STRING("User performs Dance moves used by another Pokémon on the field immediately after."),
            .aiRating = 5,
        },

        [ABILITY_BATTERY] =
        {
            .name = _("Battery"),
            .description = COMPOUND_STRING("Boosts the Sp. Atk of allies by 30%"),
            .aiRating = 0,
        },

        [ABILITY_FLUFFY] =
        {
            .name = _("Fluffy"),
            .description = COMPOUND_STRING("Halves damage taken from contact moves, doubles damage taken from Fire-type moves."),
            .aiRating = 5,
            .breakable = TRUE,
        },

        [ABILITY_DAZZLING] =
        {
            .name = _("Dazzling"),
            .description = COMPOUND_STRING("Opponents are unable to use priority moves against the user or its allies."),
            .aiRating = 5,
            .breakable = TRUE,
        },

        [ABILITY_SOUL_HEART] =
        {
            .name = _("Soul-Heart"),
            .description = COMPOUND_STRING("Raises the user's Sp. Atk stat every time another Pokémon faints."),
            .aiRating = 7,
        },

        [ABILITY_TANGLING_HAIR] =
        {
            .name = _("Tangling Hair"),
            .description = COMPOUND_STRING("When the user is hit by a contact move, the attacker's Speed stat is lowered by 1 stage."),
            .aiRating = 5,
        },

        [ABILITY_RECEIVER] =
        {
            .name = _("Receiver"),
            .description = COMPOUND_STRING("If an ally faints, gain their Ability."),
            .aiRating = 0,
            .cantBeCopied = TRUE,
            .cantBeTraced = TRUE,
        },

        [ABILITY_POWER_OF_ALCHEMY] =
        {
            .name = _("Power Of Alchemy"),
            .description = COMPOUND_STRING("If an ally faints, gain their Ability."),
            .aiRating = 0,
            .cantBeCopied = TRUE,
            .cantBeTraced = TRUE,
        },

        [ABILITY_BEAST_BOOST] =
        {
            .name = _("Beast Boost"),
            .description = COMPOUND_STRING("Boosts the user's highest stat every time it knocks out a target."),
            .aiRating = 7,
        },

        [ABILITY_EELEVATE] =
        {
            .name = _("Eelevate"),
            .description = COMPOUND_STRING("Makes the user ungrounded. KOs raises the user's best stat by 1 stage."),
            .aiRating = 9,
            .breakable = TRUE,
        },

        [ABILITY_RKS_SYSTEM] =
        {
            .name = _("RKS System"),
            .description = COMPOUND_STRING("Changes Silvally's type to match the memory disc it holds."),
            .aiRating = 8,
            .cantBeCopied = TRUE,
            .cantBeSwapped = TRUE,
            .cantBeTraced = TRUE,
            .cantBeSuppressed = TRUE,
            .cantBeOverwritten = TRUE,
        },

        [ABILITY_ELECTRIC_SURGE] =
        {
            .name = _("Electric Surge"),
            .description = COMPOUND_STRING("The user activates Electric Terrain for 5 turns when it enters a battle."),
            .aiRating = 8,
        },

        [ABILITY_PSYCHIC_SURGE] =
        {
            .name = _("Psychic Surge"),
            .description = COMPOUND_STRING("The user activates Psychic Terrain for 5 turns when it enters a battle."),
            .aiRating = 8,
        },

        [ABILITY_MISTY_SURGE] =
        {
            .name = _("Misty Surge"),
            .description = COMPOUND_STRING("The user activates Misty Terrain for 5 turns when it enters a battle."),
            .aiRating = 8,
        },

        [ABILITY_GRASSY_SURGE] =
        {
            .name = _("Grassy Surge"),
            .description = COMPOUND_STRING("The user activates Grassy Terrain for 5 turns when it enters a battle."),
            .aiRating = 8,
        },

        [ABILITY_FULL_METAL_BODY] =
        {
            .name = _("Full Metal Body"),
            .description = COMPOUND_STRING("Prevents stat reduction unless self-inflicted."),
            .aiRating = 4,
        },

        [ABILITY_SHADOW_SHIELD] =
        {
            .name = _("Shadow Shield"),
            .description = COMPOUND_STRING("Halves the damage the user takes while its HP is full."),
            .aiRating = 8,
        },

        [ABILITY_PRISM_ARMOR] =
        {
            .name = _("Prism Armor"),
            .description = COMPOUND_STRING("Reduces the damage taken from super effective moves by 25%"),
            .aiRating = 6,
        },

        [ABILITY_NEUROFORCE] =
        {
            .name = _("Neuroforce"),
            .description = COMPOUND_STRING("User deals 25% more damage with super effective moves."),
            .aiRating = 6,
        },

        [ABILITY_INTREPID_SWORD] =
        {
            .name = _("Intrepid Sword"),
            .description = COMPOUND_STRING("Raises the user's Attack by 1 stage when it enters the battle."),
            .aiRating = 3,
        },

        [ABILITY_DAUNTLESS_SHIELD] =
        {
            .name = _("Dauntless Shield"),
            .description = COMPOUND_STRING("Raises the user's Defense by 1 stage when it enters the battle."),
            .aiRating = 3,
        },

        [ABILITY_LIBERO] =
        {
            .name = _("Libero"),
            .description = COMPOUND_STRING("User changes type to match the type of its latest used move."),
        },

        [ABILITY_BALL_FETCH] =
        {
            .name = _("Ball Fetch"),
            .description = COMPOUND_STRING("If user is not holding an item, recovers the first failed Pokeball of the battle."),
            .aiRating = 10,
        },

        [ABILITY_COTTON_DOWN] =
        {
            .name = _("Cotton Down"),
            .description = COMPOUND_STRING("When hit by an attack, reduces Speed of all other Pokémon on the field."),
            .aiRating = 3,
        },

        [ABILITY_PROPELLER_TAIL] =
        {
            .name = _("Propeller Tail"),
            .description = COMPOUND_STRING("The user ignores the effects of Abilities and moves that redirect moves."),
            .aiRating = 2,
        },

        [ABILITY_MIRROR_ARMOR] =
        {
            .name = _("Mirror Armor"),
            .description = COMPOUND_STRING("User reflects stat decreases."),
            .aiRating = 6,
            .breakable = TRUE,
        },

        [ABILITY_GULP_MISSILE] =
        {
            .name = _("Gulp Missile"),
            .description = COMPOUND_STRING("Fills mouth with prey after using Surf or Dive, then spits it out after being hit."),
            .aiRating = 3,
            .cantBeCopied = TRUE,
            .cantBeSuppressed = TRUE,
            .cantBeOverwritten = TRUE,
            .failsOnImposter = TRUE,
        },

        [ABILITY_STALWART] =
        {
            .name = _("Stalwart"),
            .description = COMPOUND_STRING("The user ignores the effects of Abilities and moves that redirect moves."),
            .aiRating = 2,
        },

        [ABILITY_STEAM_ENGINE] =
        {
            .name = _("Steam Engine"),
            .description = COMPOUND_STRING("When the user is hit by a Water or Fire-type move, its Speed is raised by 6 stages."),
            .aiRating = 3,
        },

        [ABILITY_PUNK_ROCK] =
        {
            .name = _("Punk Rock"),
            .description = COMPOUND_STRING("Sound move damage inflicted +30% and received -50%"),
            .aiRating = 2,
            .breakable = TRUE,
        },

        [ABILITY_SAND_SPIT] =
        {
            .name = _("Sand Spit"),
            .description = COMPOUND_STRING("User summons a sandstorm for 5 turns when it takes a hit."),
            .aiRating = 5,
        },

        [ABILITY_ICE_SCALES] =
        {
            .name = _("Ice Scales"),
            .description = COMPOUND_STRING("Halves damage taken from special moves."),
            .aiRating = 7,
            .breakable = TRUE,
        },

        [ABILITY_RIPEN] =
        {
            .name = _("Ripen"),
            .description = COMPOUND_STRING("Doubles the effect of Berries."),
            .aiRating = 4,
        },

        [ABILITY_ICE_FACE] =
        {
            .name = _("Ice Face"),
            .description = COMPOUND_STRING("The Ice Face can take a physical hit as a substitute. Face renewed with Snow."),
            .aiRating = 4,
            .cantBeCopied = TRUE,
            .cantBeSwapped = TRUE,
            .cantBeTraced = TRUE,
            .cantBeSuppressed = TRUE,
            .cantBeOverwritten = TRUE,
            .breakable = TRUE,
            .failsOnImposter = TRUE,
        },

        [ABILITY_POWER_SPOT] =
        {
            .name = _("Power Spot"),
            .description = COMPOUND_STRING("Boosts moves used by allies by 30%"),
            .aiRating = 2,
        },

        [ABILITY_MIMICRY] =
        {
            .name = _("Mimicry"),
            .description = COMPOUND_STRING("Type changes to match active Terrain."),
            .aiRating = 2,
        },

        [ABILITY_SCREEN_CLEANER] =
        {
            .name = _("Screen Cleaner"),
            .description = COMPOUND_STRING("Removes Reflect, Light Screen and Aurora Veil from the field on entry."),
            .aiRating = 3,
        },

        [ABILITY_STEELY_SPIRIT] =
        {
            .name = _("Steely Spirit"),
            .description = COMPOUND_STRING("Damage of Steel-type moves performed by the user or its allies is boosted by 50%"),
            .aiRating = 2,
        },

        [ABILITY_PERISH_BODY] =
        {
            .name = _("Perish Body"),
            .description = COMPOUND_STRING("If user is hit by a contact move, both user and attacker faint in 3 turns."),
            .aiRating = -1,
        },

        [ABILITY_WANDERING_SPIRIT] =
        {
            .name = _("Wandering Spirit"),
            .description = COMPOUND_STRING("When the user is hit by a contact move, it swaps Abilities with the attacker."),
            .aiRating = 2,
        },

        [ABILITY_GORILLA_TACTICS] =
        {
            .name = _("Gorilla Tactics"),
            .description = COMPOUND_STRING("Boosts the user's Attack by 50%, but locks it into using only one move."),
            .aiRating = 4,
        },

        [ABILITY_NEUTRALIZING_GAS] =
        {
            .name = _("Neutralizing Gas"),
            .description = COMPOUND_STRING("Nullifies active Abilities. Other abilities cannot be activated."),
            .aiRating = 5,
            .cantBeCopied = TRUE,
            .cantBeSwapped = TRUE,
            .cantBeTraced = TRUE,
            .failsOnImposter = TRUE,
        },

        [ABILITY_PASTEL_VEIL] =
        {
            .name = _("Pastel Veil"),
            .description = COMPOUND_STRING("User and allies cannot be poisoned."),
            .aiRating = 4,
            .breakable = TRUE,
        },

        [ABILITY_HUNGER_SWITCH] =
        {
            .name = _("Hunger Switch"),
            .description = COMPOUND_STRING("Changes form at the end of each turn."),
            .aiRating = 2,
            .cantBeCopied = TRUE,
            .cantBeSwapped = TRUE,
            .cantBeTraced = TRUE,
            .failsOnImposter = TRUE,
        },

        [ABILITY_QUICK_DRAW] =
        {
            .name = _("Quick Draw"),
            .description = COMPOUND_STRING("User has a 30% chance to move first in its priority bracket."),
            .aiRating = 4,
        },

        [ABILITY_UNSEEN_FIST] =
        {
            .name = _("Unseen Fist"),
            .description = COMPOUND_STRING("Contact moves can hit through protection moves."),
            .aiRating = 6,
        },

        [ABILITY_CURIOUS_MEDICINE] =
        {
            .name = _("Curious Medicine"),
            .description = COMPOUND_STRING("When the user enters a battle, it removes all stat changes from its allies."),
            .aiRating = 3,
        },

        [ABILITY_TRANSISTOR] =
        {
            .name = _("Transistor"),
            .description = COMPOUND_STRING("Boosts the power of Electric-type moves by 30%"),
            .aiRating = 6,
        },

        [ABILITY_DRAGONS_MAW] =
        {
            .name = _("Dragon's Maw"),
            .description = COMPOUND_STRING("Boosts the power of Dragon-type moves by 50%"),
            .aiRating = 6,
        },

        [ABILITY_CHILLING_NEIGH] =
        {
            .name = _("Chilling Neigh"),
            .description = COMPOUND_STRING("The user's Attack is raised by 1 stage whenever it knocks out a Pokémon."),
            .aiRating = 7,
        },

        [ABILITY_GRIM_NEIGH] =
        {
            .name = _("Grim Neigh"),
            .description = COMPOUND_STRING("The user's Sp. Atk is raised by 1 stage whenever it knocks out a Pokémon."),
            .aiRating = 7,
        },

        [ABILITY_AS_ONE_ICE_RIDER] =
        {
            .name = _("As One"),
            .description = COMPOUND_STRING("Opponents can't eat their Berries. Fainting a foe raises Attack by 1 stage."),
            .aiRating = 10,
            .cantBeCopied = TRUE,
            .cantBeSwapped = TRUE,
            .cantBeTraced = TRUE,
            .cantBeSuppressed = TRUE,
            .cantBeOverwritten = TRUE,
        },

        [ABILITY_AS_ONE_SHADOW_RIDER] =
        {
            .name = _("As One"),
            .description = COMPOUND_STRING("Opponents can't eat their Berries. Fainting a foe raises Sp. Atk by 1 stage."),
            .aiRating = 10,
            .cantBeCopied = TRUE,
            .cantBeSwapped = TRUE,
            .cantBeTraced = TRUE,
            .cantBeSuppressed = TRUE,
            .cantBeOverwritten = TRUE,
        },

        [ABILITY_LINGERING_AROMA] =
        {
            .name = _("Lingering Aroma"),
            .description = COMPOUND_STRING("When the user is hit by a contact move, the attacker's Ability becomes Lingering Aroma."),
            .aiRating = 5,
        },

        [ABILITY_SEED_SOWER] =
        {
            .name = _("Seed Sower"),
            .description = COMPOUND_STRING("Summons Grassy Terrain when hit by an attack. Lasts five turns"),
            .aiRating = 5,
        },

        [ABILITY_THERMAL_EXCHANGE] =
        {
            .name = _("Thermal Exchange"),
            .description = COMPOUND_STRING("User cannot be burned. Raises Attack by 1 stage when hit by a Fire-type move."),
            .aiRating = 4,
            .breakable = TRUE,
        },

        [ABILITY_ANGER_SHELL] =
        {
            .name = _("Anger Shell"),
            .description = COMPOUND_STRING("If hit to below half HP,  Atk, Sp. Atk and Spe +1 stage, Def and Sp. Def -1 stage."),
            .aiRating = 3,
        },

        [ABILITY_PURIFYING_SALT] =
        {
            .name = _("Purifying Salt"),
            .description = COMPOUND_STRING("This Pokémon can't be statused. Takes halved damage from Ghost-type moves."),
            .aiRating = 6,
            .breakable = TRUE,
        },

        [ABILITY_WELL_BAKED_BODY] =
        {
            .name = _("Well-Baked Body"),
            .description = COMPOUND_STRING("When hit by a Fire move, user takes no damage and raises its Defense by 2 stages."),
            .aiRating = 5,
            .breakable = TRUE,
        },

        [ABILITY_WIND_RIDER] =
        {
            .name = _("Wind Rider"),
            .description = COMPOUND_STRING("When hit by a Wind move, user takes no damage and raises its Attack by 1 stage."),
            .aiRating = 4,
            .breakable = TRUE,
        },

        [ABILITY_GUARD_DOG] =
        {
            .name = _("Guard Dog"),
            .description = COMPOUND_STRING("Cannot be forced to switch out. Raises Attack by 1 stage if Intimidated."),
            .aiRating = 5,
            .breakable = TRUE,
        },

        [ABILITY_ROCKY_PAYLOAD] =
        {
            .name = _("Rocky Payload"),
            .description = COMPOUND_STRING("Boosts Rock-type moves by 50%"),
            .aiRating = 6,
        },

        [ABILITY_WIND_POWER] =
        {
            .name = _("Wind Power"),
            .description = COMPOUND_STRING("Wind-based moves grant the Charged effect to the user."),
            .aiRating = 4,
        },

        [ABILITY_ZERO_TO_HERO] =
        {
            .name = _("Zero to Hero"),
            .description = COMPOUND_STRING("When switched out, Palafin transforms into Hero Form for the rest of the battle."),
            .aiRating = 10,
            .cantBeCopied = TRUE,
            .cantBeSwapped = TRUE,
            .cantBeTraced = TRUE,
            .cantBeSuppressed = TRUE,
            .cantBeOverwritten = TRUE,
            .failsOnImposter = TRUE,
        },

        [ABILITY_COMMANDER] =
        {
            .name = _("Commander"),
            .description = COMPOUND_STRING("If ally is Dondozo, leaps inside its mouth and raises its stats by 2 stages."),
            .aiRating = 10,
            .cantBeCopied = TRUE,
            .cantBeSwapped = TRUE,
            .cantBeTraced = TRUE,
            .cantBeSuppressed = TRUE,
            .cantBeOverwritten = TRUE,
        },

        [ABILITY_ELECTROMORPHOSIS] =
        {
            .name = _("Electromorphosis"),
            .description = COMPOUND_STRING("When the user is hit by a move, it gains the Charged effect."),
            .aiRating = 5,
        },

        [ABILITY_PROTOSYNTHESIS] =
        {
            .name = _("Protosynthesis"),
            .description = COMPOUND_STRING("Raises highest stat if harsh sunlight is active or Booster Energy is consumed."),
            .aiRating = 7,
            .cantBeCopied = TRUE,
            .cantBeSwapped = TRUE,
            .cantBeTraced = TRUE,
            .failsOnImposter = TRUE,
        },

        [ABILITY_QUARK_DRIVE] =
        {
            .name = _("Quark Drive"),
            .description = COMPOUND_STRING("Raises highest stat if Electric Terrain is active or Booster Energy is consumed."),
            .aiRating = 7,
            .cantBeCopied = TRUE,
            .cantBeSwapped = TRUE,
            .cantBeTraced = TRUE,
            .failsOnImposter = TRUE,
        },

        [ABILITY_GOOD_AS_GOLD] =
        {
            .name = _("Good as Gold"),
            .description = COMPOUND_STRING("Unaffected by status moves which target this Pokémon."),
            .aiRating = 8,
            .breakable = TRUE,
        },

        [ABILITY_VESSEL_OF_RUIN] =
        {
            .name = _("Vessel of Ruin"),
            .description = COMPOUND_STRING("Reduces the Sp. Atk of all other Pokémon on the field by 25%"),
            .aiRating = 5,
            .breakable = TRUE,
        },

        [ABILITY_SWORD_OF_RUIN] =
        {
            .name = _("Sword of Ruin"),
            .description = COMPOUND_STRING("Reduces the Defense of all other Pokémon on the field by 25%"),
            .aiRating = 5,
            .breakable = TRUE,
        },

        [ABILITY_TABLETS_OF_RUIN] =
        {
            .name = _("Tablets of Ruin"),
            .description = COMPOUND_STRING("Reduces the Attack of all other Pokémon on the field by 25%"),
            .aiRating = 5,
            .breakable = TRUE,
        },

        [ABILITY_BEADS_OF_RUIN] =
        {
            .name = _("Beads of Ruin"),
            .description = COMPOUND_STRING("Reduces the Sp. Def of all other Pokémon on the field by 25%"),
            .aiRating = 5,
            .breakable = TRUE,
        },

        [ABILITY_ORICHALCUM_PULSE] =
        {
            .name = _("Orichalcum Pulse"),
            .description = COMPOUND_STRING("Summons harsh sunlight for 5 turns upon entry, boosting the user's Atk by 33%"),
            .aiRating = 8,
        },

        [ABILITY_HADRON_ENGINE] =
        {
            .name = _("Hadron Engine"),
            .description = COMPOUND_STRING("Summons Electric Terrain for 5 turns upon entry, boosting the user's Sp. Atk by 33%"),
            .aiRating = 8,
        },

        [ABILITY_OPPORTUNIST] =
        {
            .name = _("Opportunist"),
            .description = COMPOUND_STRING("Copies ally's stat changes on entry."),
            .aiRating = 5,
        },

        [ABILITY_CUD_CHEW] =
        {
            .name = _("Cud Chew"),
            .description = COMPOUND_STRING("If a berry is consumed, its effects are granted again at the end of the next turn."),
            .aiRating = 4,
        },

        [ABILITY_SHARPNESS] =
        {
            .name = _("Sharpness"),
            .description = COMPOUND_STRING("Boosts the damage done by slicing moves by 50%"),
            .aiRating = 7,
        },

        [ABILITY_SUPREME_OVERLORD] =
        {
            .name = _("Supreme Overlord"),
            .description = COMPOUND_STRING("Move power is boosted by 10% for every fainted Pokémon in the party."),
            .aiRating = 6,
        },

        [ABILITY_COSTAR] =
        {
            .name = _("Costar"),
            .description = COMPOUND_STRING("Copies ally's stat changes on entry."),
            .aiRating = 5,
        },

        [ABILITY_TOXIC_DEBRIS] =
        {
            .name = _("Toxic Debris"),
            .description = COMPOUND_STRING("Sets Toxic Spikes if hit by an opponent's physical move."),
            .aiRating = 4,
        },

        [ABILITY_ARMOR_TAIL] =
        {
            .name = _("Armor Tail"),
            .description = COMPOUND_STRING("Opponents are unable to use priority moves against the user or its allies."),
            .aiRating = 5,
            .breakable = TRUE,
        },

        [ABILITY_EARTH_EATER] =
        {
            .name = _("Earth Eater"),
            .description = COMPOUND_STRING("The user restores up to 25% of its max HP when hit with Ground-type moves."),
            .aiRating = 7,
            .breakable = TRUE,
        },

        [ABILITY_MYCELIUM_MIGHT] =
        {
            .name = _("Mycelium Might"),
            .description = COMPOUND_STRING("User's Status moves ignore certain Abilities, but moves last in its priority bracket."),
            .aiRating = 2,
        },

        [ABILITY_HOSPITALITY] =
        {
            .name = _("Hospitality"),
            .description = COMPOUND_STRING("When the user enters a battle, it restores 1/4 of its ally's max HP."),
            .aiRating = 5,
        },

        [ABILITY_MINDS_EYE] =
        {
            .name = _("Mind's Eye"),
            .description = COMPOUND_STRING("Ignores Accuracy loss or foe's Evasiveness, hits Ghost-types with Normal and Fighting."),
            .aiRating = 8,
            .breakable = TRUE,
        },

        [ABILITY_EMBODY_ASPECT_TEAL_MASK] =
        {
            .name = _("Embody Aspect"),
            .description = COMPOUND_STRING("Raises Speed by 1 stage on entry, once only."),
            .aiRating = 6,
            .cantBeCopied = TRUE,
            .cantBeSwapped = TRUE,
            .cantBeTraced = TRUE,
            .failsOnImposter = TRUE,
        },

        [ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK] =
        {
            .name = _("Embody Aspect"),
            .description = COMPOUND_STRING("Raises Attack by 1 stage on entry, once only."),
            .aiRating = 6,
            .cantBeCopied = TRUE,
            .cantBeSwapped = TRUE,
            .cantBeTraced = TRUE,
            .failsOnImposter = TRUE,
        },

        [ABILITY_EMBODY_ASPECT_WELLSPRING_MASK] =
        {
            .name = _("Embody Aspect"),
            .description = COMPOUND_STRING("Raises Sp. Def by 1 stage on entry, once only."),
            .aiRating = 6,
            .cantBeCopied = TRUE,
            .cantBeSwapped = TRUE,
            .cantBeTraced = TRUE,
            .failsOnImposter = TRUE,
        },

        [ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK] =
        {
            .name = _("Embody Aspect"),
            .description = COMPOUND_STRING("Raises Defense by 1 stage on entry, once only."),
            .aiRating = 6,
            .cantBeCopied = TRUE,
            .cantBeSwapped = TRUE,
            .cantBeTraced = TRUE,
            .failsOnImposter = TRUE,
        },

        [ABILITY_TOXIC_CHAIN] =
        {
            .name = _("Toxic Chain"),
            .description = COMPOUND_STRING("Each hit gains a 30% chance to badly poison the target."),
            .aiRating = 8,
        },

        [ABILITY_SUPERSWEET_SYRUP] =
        {
            .name = _("Supersweet Syrup"),
            .description = COMPOUND_STRING("Once per battle, lower opponents' Evasiveness by 1 stage upon entry."),
            .aiRating = 5,
        },

        [ABILITY_TERA_SHIFT] =
        {
            .name = _("Tera Shift"),
            .description = COMPOUND_STRING("Enters Terastal Form upon entry."),
            .aiRating = 10,
            .cantBeCopied = TRUE,
            .cantBeSwapped = TRUE,
            .cantBeTraced = TRUE,
            .cantBeSuppressed = TRUE,
            .cantBeOverwritten = TRUE,
            .failsOnImposter = TRUE,
        },

        [ABILITY_TERA_SHELL] =
        {
            .name = _("Tera Shell"),
            .description = COMPOUND_STRING("While at full HP, all received hits become not very effective."),
            .aiRating = 10,
            .cantBeCopied = TRUE,
            .cantBeSwapped = TRUE,
            .cantBeTraced = TRUE,
            .breakable = TRUE,
        },

        [ABILITY_TERAFORM_ZERO] =
        {
            .name = _("Teraform Zero"),
            .description = COMPOUND_STRING("Neutralizes weather and terrain."),
            .aiRating = 10,
            .cantBeCopied = TRUE,
            .cantBeSwapped = TRUE,
            .cantBeTraced = TRUE,
        },

        [ABILITY_POISON_PUPPETEER] =
        {
            .name = _("Poison Puppeteer"),
            .description = COMPOUND_STRING("When the user Poisons or Badly Poisons a foe, it will additionally be confused."),
            .aiRating = 8,
            .cantBeCopied = TRUE,
            .cantBeSwapped = TRUE,
            .cantBeTraced = TRUE,
        },
    

    [ABILITY_STRIKER] =
    {
        .name = _("Striker"),
        .description = COMPOUND_STRING("Boosts the damage done by kicking moves by 30%"),
        .aiRating = 6,

    },
    [ABILITY_BULL_RUSH] =
    {
        .name = _("Bull Rush"),
        .description = COMPOUND_STRING("Boosts the user's Speed by 50% and power by 20% on first turn."),
        .aiRating = 6,

    },
    [ABILITY_QUILL_RUSH] =
    {
        .name = _("Quill Rush"),
        .description = COMPOUND_STRING("Boosts the user's Speed by 50% and power by 20% on first turn."),
        .aiRating = 6,
    },
    [ABILITY_BLUBBER_DEFENSE] =
    {
        .name = _("Blubber Defense"),
        .description = COMPOUND_STRING("Halves the damage the user takes while its HP is full."),
        .aiRating = 6,
        .breakable = TRUE,
    },
    [ABILITY_FROZEN_MIST] =
    {
        .name = _("Frozen Mist"),
        .description = COMPOUND_STRING("Protects user from entry hazards and the secondary effects of moves."),
        .aiRating = 6,
        .breakable = TRUE,
    },
    [ABILITY_BLAZING_SOUL] = 
    {        
        .name = _("Blazing Soul"),
        .description = COMPOUND_STRING("Fire-Type moves get +1 Priority while the user is at full HP."),
        .aiRating = 6,
    },
    [ABILITY_SELF_SUFFICIENT] = 
    {        
        .name = _("Self Sufficient"),
        .description = COMPOUND_STRING("Heals 1/8 of the user's Max HP at end of each turn."),
        .aiRating = 6,
    },
    [ABILITY_FELINE_PROWESS] = 
    {        
        .name = _("Feline Prowess"),
        .description = COMPOUND_STRING("Doubles the user's Sp. Atk stat."),
        .aiRating = 10,
    }, 
    [ABILITY_BAD_COMPANY] =
    {
        .name = _("Bad Company"),
        .description = COMPOUND_STRING("Prevents recoil and the user's own attacking moves from lowering its stats."),
        .aiRating = 10,
    },
    [ABILITY_PRIMAL_ARMOR] = 
    {        
        .name = _("Primal Armor"),
            .description = COMPOUND_STRING("Damage taken by the user from super effective attacks is halved."),
        .aiRating = 10,
    },
    [ABILITY_MOUNTAINEER] =
    {
        .name = _("Mountaineer"),
        .description = COMPOUND_STRING("Immune to Rock-type moves and Stealth Rocks."),
        .aiRating = 10,
        .breakable = TRUE,
    },
    [ABILITY_PHOENIX_DOWN] = //todo
    {        
        .name = _("Phoenix Down"),
        .description = COMPOUND_STRING("Revives to half health on first faint once per battle."),
        .aiRating = 10,
    },
    [ABILITY_SAGE_POWER] = 
    {        
        .name = _("Sage Power"),
        .description = COMPOUND_STRING("Boosts the user's Sp. Atk by 50%, but locks it into using only one move."),
        .aiRating = 10,
    },
    [ABILITY_BONE_ZONE] = //todo
    {        
        .name = _("Bone Zone"),
        .description = COMPOUND_STRING("Bone moves bypass resists and immunities."),
        .aiRating = 8,
    },
    [ABILITY_FATAL_PRECISION] = //todo
    {        
        .name = _("Fatal Precision"),
        .description = COMPOUND_STRING("âSuper effective moves can't miss & are boosted by 20%"),
        .aiRating = 10,
    },
    [ABILITY_CASH_SPLASH] =
    {
        .name = _("Cash Splash"),
        .description = COMPOUND_STRING("Halves Fire-type damage taken, and doubles Water-type damage inflicted."),
        .aiRating = 6,
        .breakable = TRUE,
    },
    [ABILITY_MEGA_SOL] =
    {
        .name = _("Mega Sol"),
        .description = COMPOUND_STRING("Sun-boosted moves work without sunlight."),
        .aiRating = 7,
    },
    [ABILITY_DRAGONIZE] =
    {
        .name = _("Dragonize"),
        .description = COMPOUND_STRING("The user's Normal-type moves become Dragon-type and their power is boosted by 20%"),
        .aiRating = 8,
    },
    [ABILITY_ORAORAORAORA] =
    {
        .name = _("ORAORAORAORA!"),
        .description = COMPOUND_STRING("Punching moves hit a second time for 50% damage."),
        .aiRating = 8,
    },
    [ABILITY_FIRE_MANE] =
    {
        .name = _("Fire Mane"),
        .description = COMPOUND_STRING("Boosts the power of Fire-type moves by 50%"),
        .aiRating = 8,
    },
    [ABILITY_CORROSIVE_GUTS] =
    {
        .name = _("Corrosive Guts"),
        .description = COMPOUND_STRING("Poison hits Steel. Hurts foe when defeated."),
        .aiRating = 6,
    },
    [ABILITY_LAST_KISS] =
    {
        .name = _("Last Kiss"),
        .description = COMPOUND_STRING("Once per battle, fully heals its replacement upon fainting. May revive an ally"),
        .aiRating = 8,
    },
};
