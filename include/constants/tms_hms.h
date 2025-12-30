#ifndef GUARD_CONSTANTS_TMS_HMS_H
#define GUARD_CONSTANTS_TMS_HMS_H

#define FOREACH_TM(F) \
    F(CLOSE_COMBAT) \
    F(DRAGON_CLAW) \
    F(WATER_PULSE) \
    F(CALM_MIND) \
    F(ROAR) \
    F(TOXIC) \
    F(HEAT_WAVE) \
    F(ZEN_HEADBUTT) \
    F(BULLET_SEED) \
    F(HIDDEN_POWER) \
    F(SUNNY_DAY) \
    F(TAUNT) \
    F(ICE_BEAM) \
    F(BLIZZARD) \
    F(HYPER_BEAM) \
    F(LIGHT_SCREEN) \
    F(PROTECT) \
    F(RAIN_DANCE) \
    F(GIGA_DRAIN) \
    F(HYPER_VOICE) \
    F(ICY_WIND) \
    F(SOLAR_BEAM) \
    F(IRON_HEAD) \
    F(THUNDERBOLT) \
    F(THUNDER) \
    F(EARTHQUAKE) \
    F(RETURN) \
    F(BULLDOZE) \
    F(PSYCHIC) \
    F(SHADOW_BALL) \
    F(BRICK_BREAK) \
    F(LOW_KICK) \
    F(REFLECT) \
    F(SHOCK_WAVE) \
    F(FLAMETHROWER) \
    F(SLUDGE_BOMB) \
    F(HIGH_HORSEPOWER) \
    F(FIRE_BLAST) \
    F(ROCK_TOMB) \
    F(AERIAL_ACE) \
    F(LIQUIDATION) \
    F(FACADE) \
    F(SECRET_POWER) \
    F(REST) \
    F(DRAINING_KISS) \
    F(SNARL) \
    F(STEEL_WING) \
    F(ELECTROWEB) \
    F(HURRICANE) \
    F(OVERHEAT) \
    F(WILD_CHARGE) \
    F(U_TURN) \
    F(VOLT_SWITCH) \
    F(FLIP_TURN) \
    F(FOCUS_BLAST) \
    F(DAZZLING_GLEAM) \
    F(LOW_SWEEP) \


#define FOREACH_HM(F) \
    F(CUT) \
    F(FLY) \
    F(SURF) \
    F(STRENGTH) \
    F(FLASH) \
    F(ROCK_SMASH) \
    F(WATERFALL) \
    F(DIVE)

#define FOREACH_TMHM(F) \
    FOREACH_TM(F) \
    FOREACH_HM(F)

#endif
