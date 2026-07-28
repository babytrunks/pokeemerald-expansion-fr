#define RandomWeighted(tag, ...) MK(__VA_ARGS__)
#define RandomChance(tag, successes, total) (RandomWeighted(tag, total - successes, successes))
#define B_PARALYSIS_IMMOBILITY_DENOM 8
RandomChance(RNG_PARALYSIS, (B_PARALYSIS_IMMOBILITY_DENOM - 1), B_PARALYSIS_IMMOBILITY_DENOM)
RandomChance(RNG_SLEEP_TURNS, 1, 3)
