#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_ENDEAVOR) == EFFECT_ENDEAVOR);
}

SINGLE_BATTLE_TEST("Endeavor causes the target's HP to equal the user's current HP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ENDEAVOR); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENDEAVOR, player);
    } THEN {
        EXPECT_EQ(player->hp, opponent->hp);
    }
}
SINGLE_BATTLE_TEST("Endeavor fails on Ghost-type Pokémon")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_GASTLY);
    } WHEN {
        TURN { MOVE(player, MOVE_ENDEAVOR); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENDEAVOR, player);
        MESSAGE("It doesn't affect the opposing Gastly…");
        NONE_OF { HP_BAR(opponent); }
    }
}

SINGLE_BATTLE_TEST("Endeavor does not bank damage for Shell Bell when it fails on a Ghost-type")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_SHELL_BELL].holdEffect == HOLD_EFFECT_SHELL_BELL);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Item(ITEM_SHELL_BELL); }
        OPPONENT(SPECIES_GASTLY);
    } WHEN {
        TURN { MOVE(player, MOVE_ENDEAVOR); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENDEAVOR, player);
        MESSAGE("It doesn't affect the opposing Gastly…");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            HP_BAR(player);
        }
    } THEN {
        EXPECT_EQ(player->hp, 1);
    }
}

SINGLE_BATTLE_TEST("Endeavor does not bank damage for Shell Bell when it misses")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_SHELL_BELL].holdEffect == HOLD_EFFECT_SHELL_BELL);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Item(ITEM_SHELL_BELL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ENDEAVOR, hit: FALSE); }
    } SCENE {
        MESSAGE("Wobbuffet's attack missed!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            HP_BAR(player);
        }
    } THEN {
        EXPECT_EQ(player->hp, 1);
    }
}

TO_DO_BATTLE_TEST("Endeavor does not change HP if the target has less HP than the user, but still plays the animation")
