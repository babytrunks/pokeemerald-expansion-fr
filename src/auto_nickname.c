#include "global.h"
#include "auto_nickname.h"
#include "pokemon.h"
#include "random.h"
#include "constants/pokemon.h"

#include "data/auto_nicknames.h"

#define NUM_NICK_NEUTRAL ARRAY_COUNT(sAutoNicknamesNeutral)
#define NUM_NICK_MALE    ARRAY_COUNT(sAutoNicknamesMale)
#define NUM_NICK_FEMALE  ARRAY_COUNT(sAutoNicknamesFemale)

// females/males have an equal chance of pulling
// from their own list or the neutral list
//  genderless pull from all three.
static const u8 *GetRandomAutoNickname(u16 gender)
{
    if (gender == MON_FEMALE)
    {
        if (Random() & 1)
            return sAutoNicknamesFemale[Random() % NUM_NICK_FEMALE];
        return sAutoNicknamesNeutral[Random() % NUM_NICK_NEUTRAL];
    }
    else if (gender == MON_MALE)
    {
        if (Random() & 1)
            return sAutoNicknamesMale[Random() % NUM_NICK_MALE];
        return sAutoNicknamesNeutral[Random() % NUM_NICK_NEUTRAL];
    }
    else
    {
        switch (Random() % 3)
        {
        case 0:  return sAutoNicknamesFemale[Random() % NUM_NICK_FEMALE];
        case 1:  return sAutoNicknamesMale[Random() % NUM_NICK_MALE];
        default: return sAutoNicknamesNeutral[Random() % NUM_NICK_NEUTRAL];
        }
    }
}

void ApplyAutoNickname(struct Pokemon *mon)
{
    SetMonData(mon, MON_DATA_NICKNAME, GetRandomAutoNickname(GetMonGender(mon)));
}
