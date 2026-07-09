#ifndef GUARD_SHOP_H
#define GUARD_SHOP_H

extern struct ItemSlot gMartPurchaseHistory[3];

// A single Game Corner prize: an item bought with Coins rather than money.
struct PrizeItem
{
    u16 itemId;
    u16 coinCost;
};

void CreatePokemartMenu(const u16 *itemsForSale);
void CreateDecorationShop1Menu(const u16 *itemsForSale);
void CreateDecorationShop2Menu(const u16 *itemsForSale);
void CreateOutfitShopMenu(const u16 *itemsForSale);
void CreateGameCornerPrizeMenu(const struct PrizeItem *prizes);
void CB2_ExitSellMenu(void);

#endif // GUARD_SHOP_H
