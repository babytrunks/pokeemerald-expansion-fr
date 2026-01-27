#ifndef GUARD_UTIL_H
#define GUARD_UTIL_H

#include "sprite.h"

extern const u8 gMiscBlank_Gfx[]; // unused in Emerald

u8 CreateInvisibleSpriteWithCallback(void (*callback)(struct Sprite *));
void StoreWordInTwoHalfwords(u16 *h, u32 w);
void LoadWordFromTwoHalfwords(u16 *h, u32 *w);
int CountTrailingZeroBits(u32 value);
u16 CalcCRC16(const u8 *data, s32 length);
u16 CalcCRC16WithTable(const u8 *data, u32 length);
u32 CalcByteArraySum(const u8 *data, u32 length);
void BlendPalette(u16 palOffset, u16 numEntries, u8 coeff, u32 blendColor);
void DoBgAffineSet(struct BgAffineDstData *dest, u32 texX, u32 texY, s16 scrX, s16 scrY, s16 sx, s16 sy, u16 alpha);
void CopySpriteTiles(u8 shape, u8 size, u8 *tiles, u16 *tilemap, u8 *output);

#define MURMURHASH2A_R 24
#define MURMURHASH2A_MULTIPLIER 0x5bd1e995
#define MURMURHASH2A_SEED 2166136261U

#define murmurhash2a_init(h) { h = MURMURHASH2A_SEED; }
    
#define murmurhash2a_update(h,word)                \
{                                                  \
    u32 mmh2ak = (word) * MURMURHASH2A_MULTIPLIER; \
    mmh2ak ^= mmh2ak >> MURMURHASH2A_R;            \
    mmh2ak *= MURMURHASH2A_MULTIPLIER;             \
    h *= MURMURHASH2A_MULTIPLIER;                  \
    h ^= mmh2ak;                                   \
} while (0)

#define murmurhash2a_final(h)                      \
{                                                  \
    h ^= h >> 13;                                  \
    h *= MURMURHASH2A_MULTIPLIER;                  \
    h ^= h >> 15;                                  \
}

u32 MathMax(u32 num1, u32 num2);
u32 MathMin(u32 num1, u32 num2);
#endif // GUARD_UTIL_H
