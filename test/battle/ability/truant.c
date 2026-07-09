#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SLACK_OFF) == EFFECT_RESTORE_HP);
}

SINGLE_BATTLE_TEST("Truant Pokémon can use Slack Off during its loafing around turn")
{
    GIVEN {
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Moves(MOVE_TACKLE, MOVE_SLACK_OFF); MaxHP(200); HP(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_SLACK_OFF); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SLACK_OFF, player);
        HP_BAR(player);
        NOT MESSAGE("Slaking is loafing around!");
    }
}

SINGLE_BATTLE_TEST("Truant Pokémon still loafs around when using a move other than Slack Off")
{
    GIVEN {
        PLAYER(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Moves(MOVE_TACKLE, MOVE_SLACK_OFF); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        MESSAGE("Slaking is loafing around!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
    }
}
