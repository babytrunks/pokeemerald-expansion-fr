Route1_EventScript_ItemLuckyEgg::
	finditem ITEM_LUCKY_EGG
	end

Route22_EventScript_ItemQuickClaw::
	finditem ITEM_QUICK_CLAW
	end

Route2_EventScript_ItemTMRest::
	finditem ITEM_TM_REST
	end

Route2_EventScript_ItemGachaVoucher::
	finditem ITEM_GACHA_VOUCHER
	end

Route3_EventScript_ItemWideLens::
	finditem ITEM_WIDE_LENS
	end

ViridianForest_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY
	end

ViridianForest_EventScript_ItemWiseGlasses::
	finditem ITEM_WISE_GLASSES
	end

ViridianForest_EventScript_ItemDuskBall::
	finditem ITEM_DUSK_BALL
	end

MtMoon_1F_EventScript_ItemShellBell::
	finditem ITEM_SHELL_BELL
	end

MtMoon_1F_EventScript_ItemTM09::
	finditem ITEM_TM09
	end

MtMoon_B2F_EventScript_ItemBerryJuice::
	giveitem ITEM_BERRY_JUICE
	removeobject VAR_LAST_TALKED
	end

MtMoon_1F_EventScript_ItemKalosFossil::
	randomSeeded 2
	switch VAR_RESULT
	case 0, MtMoon_B2F_EventScript_JawFossil
	case 1, MtMoon_B2F_EventScript_SailFossil
	end

MtMoon_B2F_EventScript_JawFossil:
	finditem ITEM_JAW_FOSSIL
	end

MtMoon_B2F_EventScript_SailFossil:
	finditem ITEM_SAIL_FOSSIL
	end

MtMoon_1F_EventScript_ItemEscapeRope::
	finditem ITEM_ESCAPE_ROPE
	end

MtMoon_1F_EventScript_ItemMoonStone::
	finditem ITEM_MOON_STONE
	end

MtMoon_B2F_EventScript_ItemHoennFossil::
	randomSeeded 2
	switch VAR_RESULT
	case 0, MtMoon_B2F_EventScript_ClawFossil
	case 1, MtMoon_B2F_EventScript_RootFossil
	end

MtMoon_B2F_EventScript_ClawFossil:
	finditem ITEM_CLAW_FOSSIL
	end

MtMoon_B2F_EventScript_RootFossil:
	finditem ITEM_ROOT_FOSSIL
	end

MtMoon_B2F_EventScript_ItemTMHiddenPower:: @ unused
	finditem ITEM_TM_HIDDEN_POWER
	end

Route24_EventScript_ItemSwiftFeather::
	finditem ITEM_SWIFT_FEATHER
	end

MtMoon_B2F_EventScript_ItemTM46::
	finditem ITEM_TM46
	end

Route4_EventScript_ItemTM_ShockWave::
	finditem ITEM_TM_SHOCK_WAVE
	end

Route24_EventScript_ItemTM45::
	finditem ITEM_TM45
	end

Route24_EventScript_ItemTMWaterPulse::
	finditem ITEM_TM_WATER_PULSE
	end

Route25_EventScript_ItemTM43::
	finditem ITEM_TM43
	end

Route24_EventScript_ItemMuscleFeather::
	finditem ITEM_MUSCLE_FEATHER
	end


Route6_EventScript_ItemTMVenoshock::
	finditem ITEM_TM_VENOSHOCK
	end

SSAnne_1F_Room2_EventScript_ItemTM31::
	finditem ITEM_TM31
	end

SSAnne_2F_Room2_EventScript_ItemDiveBall::
	finditem ITEM_DIVE_BALL
	end

SSAnne_2F_Room4_EventScript_ItemSwiftFeather::
	finditem ITEM_SWIFT_FEATHER
	end

SSAnne_B1F_Room2_EventScript_ItemHealthFeather::
	finditem ITEM_HEALTH_FEATHER
	end

SSAnne_B1F_Room3_EventScript_ItemLuxuryBall::
	finditem ITEM_LUXURY_BALL
	end

SSAnne_B1F_Room5_EventScript_ItemWaterStone::
	finditem ITEM_WATER_STONE
	end

SSAnne_Kitchen_EventScript_ItemGreatBall::
	finditem ITEM_GREAT_BALL
	end

Route9_EventScript_ItemTMThunderPunch::
	finditem ITEM_TM_THUNDER_PUNCH
	end

RocketHideout_B1F_EventScript_ItemLuxuryBall::
	finditem ITEM_LUXURY_BALL
	end

RocketHideout_B1F_EventScript_ItemZinc::
	finditem ITEM_ZINC
	end

RocketHideout_B2F_EventScript_ItemSwiftFeather::
	finditem ITEM_SWIFT_FEATHER
	end

RocketHideout_B2F_EventScript_ItemGachaVoucher::
	finditem ITEM_GACHA_VOUCHER
	end

RocketHideout_B2F_EventScript_ItemTM12::
	finditem ITEM_TM12
	end

RocketHideout_B2F_EventScript_ItemSafetyGoggles::
	finditem ITEM_SAFETY_GOGGLES
	end

RocketHideout_B3F_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY
	end

RocketHideout_B3F_EventScript_ItemTMFutureSight::
	finditem ITEM_TM_FUTURE_SIGHT 
	end

RocketHideout_B4F_EventScript_ItemTMSludgeBomb::
	finditem ITEM_TM_SLUDGE_BOMB
	end

RocketHideout_B4F_EventScript_ItemHPUp::
	finditem ITEM_HP_UP
	end

RocketHideout_B4F_EventScript_ItemCalcium::
	finditem ITEM_CALCIUM
	end

PokemonTower_3F_EventScript_ItemReaperCloth::
	finditem ITEM_REAPER_CLOTH
	end

PokemonTower_4F_EventScript_ItemMetronome::
	finditem ITEM_METRONOME
	end

PokemonTower_4F_EventScript_ItemSwiftFeather::
	finditem ITEM_SWIFT_FEATHER
	end

PokemonTower_4F_EventScript_ItemWhiteHerb::
	finditem ITEM_WHITE_HERB
	end

PokemonTower_5F_EventScript_ItemIron::
	finditem ITEM_IRON
	end

PokemonTower_6F_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY
	end

PokemonTower_6F_EventScript_ItemSablenite::
	finditem ITEM_SABLENITE
	end

Route12_EventScript_ItemTMHurricane::
	finditem ITEM_TM_HURRICANE
	end

Route12_EventScript_ItemIron::
	finditem ITEM_ABOMASITE
	end

Route15_EventScript_ItemTMHydroPump::
	finditem ITEM_TM_HYDRO_PUMP
	end

SafariZone_Center_EventScript_ItemNugget::
	finditem ITEM_NUGGET
	end

SafariZone_East_EventScript_ItemMaxPotion::
	finditem ITEM_MAX_POTION
	end

SafariZone_East_EventScript_ItemFullRestore::
	finditem ITEM_FULL_RESTORE
	end

SafariZone_East_EventScript_ItemTM11::
	finditem ITEM_TM11
	end

SafariZone_East_EventScript_ItemLeafStone::
	finditem ITEM_LEAF_STONE
	end

SafariZone_North_EventScript_ItemProtein::
	finditem ITEM_PROTEIN
	end

SafariZone_North_EventScript_ItemTM47::
	finditem ITEM_TM47
	end

SafariZone_West_EventScript_ItemTM32::
	finditem ITEM_TM32
	end

SafariZone_West_EventScript_ItemGoldTeeth::
	finditem ITEM_GOLD_TEETH
	end

SafariZone_West_EventScript_ItemMaxPotion::
	finditem ITEM_MAX_POTION
	end

SafariZone_West_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE
	end

SilphCo_3F_EventScript_ItemLoadedDice::
	finditem ITEM_LOADED_DICE
	end

SilphCo_4F_EventScript_ItemTMDragonClaw::
	finditem ITEM_TM_DRAGON_CLAW
	end

SilphCo_4F_EventScript_ItemManectite::
	finditem ITEM_MANECTITE
	end

SilphCo_4F_EventScript_ItemCovertCloak::
	finditem ITEM_COVERT_CLOAK
	end

SilphCo_5F_EventScript_ItemProtein::
	finditem ITEM_PROTEIN
	end

SilphCo_5F_EventScript_ItemTMBodyPress::
	finditem ITEM_TM_BODY_PRESS
	end

SilphCo_5F_EventScript_ItemCardKey::
	removeobject VAR_LAST_TALKED
	giveitem ITEM_CARD_KEY 
	setflag FLAG_HIDE_SILPH_CO_5F_CARD_KEY
	release
	end

SilphCo_6F_EventScript_ItemUpgrade::
	finditem ITEM_UPGRADE
	end

SilphCo_6F_EventScript_ItemGlalitite::
	finditem ITEM_GLALITITE
	end

SilphCo_7F_EventScript_ItemCalcium::
	finditem ITEM_CALCIUM
	end

SilphCo_7F_EventScript_ItemTM08::
	finditem ITEM_TM_FUTURE_SIGHT
	end

SilphCo_10F_EventScript_ItemCarbos::
	finditem ITEM_CARBOS
	end

SilphCo_10F_EventScript_ItemDreamPatch::
	finditem ITEM_DREAM_PATCH
	end

SilphCo_10F_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY
	end

PowerPlant_EventScript_ItemMaxPotion::
	finditem ITEM_MAX_POTION
	end

PowerPlant_EventScript_ItemTM17::
	finditem ITEM_TM17
	end

PowerPlant_EventScript_ItemTM25::
	finditem ITEM_TM25
	end

PowerPlant_EventScript_ItemThunderStone::
	finditem ITEM_THUNDER_STONE
	end

PowerPlant_EventScript_ItemElixir::
	finditem ITEM_ELIXIR
	end

PokemonMansion_1F_EventScript_ItemCarbos::
	finditem ITEM_CARBOS
	end

PokemonMansion_1F_EventScript_ItemEscapeRope::
	finditem ITEM_ESCAPE_ROPE
	end

PokemonMansion_2F_EventScript_ItemCalcium::
	finditem ITEM_CALCIUM
	end

PokemonMansion_3F_EventScript_ItemMaxPotion::
	finditem ITEM_MAX_POTION
	end

PokemonMansion_3F_EventScript_ItemIron::
	finditem ITEM_IRON
	end

PokemonMansion_B1F_EventScript_ItemTM14::
	finditem ITEM_TM14
	end

PokemonMansion_B1F_EventScript_ItemFullRestore::
	finditem ITEM_FULL_RESTORE
	end

PokemonMansion_B1F_EventScript_ItemTM22::
	finditem ITEM_TM22
	end

PokemonMansion_B1F_EventScript_ItemSecretKey::
	finditem ITEM_SECRET_KEY
	end

VictoryRoad_1F_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY
	end

VictoryRoad_1F_EventScript_ItemTM02::
	finditem ITEM_TM02
	end

VictoryRoad_2F_EventScript_ItemGuardSpec::
	finditem ITEM_GUARD_SPEC
	end

VictoryRoad_2F_EventScript_ItemTM07::
	finditem ITEM_TM07
	end

VictoryRoad_2F_EventScript_ItemFullHeal::
	finditem ITEM_FULL_HEAL
	end

VictoryRoad_2F_EventScript_ItemTM37::
	finditem ITEM_TM37
	end

VictoryRoad_3F_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE
	end

VictoryRoad_3F_EventScript_ItemTM50::
	finditem ITEM_TM50
	end

CeruleanCave_1F_EventScript_ItemMaxElixir::
	finditem ITEM_MAX_ELIXIR
	end

CeruleanCave_1F_EventScript_ItemNugget::
	finditem ITEM_NUGGET
	end

CeruleanCave_1F_EventScript_ItemFullRestore::
	finditem ITEM_FULL_RESTORE
	end

CeruleanCave_2F_EventScript_ItemFullRestore::
	finditem ITEM_FULL_RESTORE
	end

CeruleanCave_2F_EventScript_ItemPPUp::
	finditem ITEM_PP_UP
	end

CeruleanCave_2F_EventScript_ItemUltraBall::
	finditem ITEM_ULTRA_BALL
	end

CeruleanCave_B1F_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE
	end

CeruleanCave_B1F_EventScript_ItemUltraBall::
	finditem ITEM_ULTRA_BALL
	end

FuchsiaCity_WardensHouse_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY
	end

TwoIsland_EventScript_ItemRevive::
	finditem ITEM_REVIVE
	end

ThreeIsland_EventScript_ItemZinc::
	finditem ITEM_ZINC
	end

ViridianForest_EventScript_ItemResistFeather::
	finditem ITEM_RESIST_FEATHER
	end

MtMoon_B2F_EventScript_ItemSinnohFossil::
	randomSeeded 2
	switch VAR_RESULT
	case 0, MtMoon_B2F_EventScript_SkullFossil
	case 1, MtMoon_B2F_EventScript_ArmorFossil
	end

MtMoon_B2F_EventScript_SkullFossil:
	finditem ITEM_SKULL_FOSSIL
	end

MtMoon_B2F_EventScript_ArmorFossil:
	finditem ITEM_ARMOR_FOSSIL
	end

MtMoon_B2F_EventScript_ItemCleverFeather::
	finditem ITEM_CLEVER_FEATHER
	end

Route11_EventScript_ItemThunderStone::
	finditem ITEM_THUNDER_STONE
	end

Route10_EventScript_ItemTMFirePunch::
	finditem ITEM_TM_FIRE_PUNCH
	end

Route10_EventScript_ItemTMIcyWind::
	finditem ITEM_TM_ICY_WIND
	end

Route9_EventScript_ItemShinyStone::
	finditem ITEM_LEAF_STONE
	end

Route8_EventScript_ItemTMDualWingbeat::
	finditem ITEM_TM_DUAL_WINGBEAT
	end

Route8_EventScript_ItemLaxMint::
	finditem ITEM_LAX_MINT
	end

RockTunnel_1F_EventScript_ItemFossilizedBird::
	finditem ITEM_FOSSILIZED_BIRD
	end

RockTunnel_1F_EventScript_ItemRedCard::
	finditem ITEM_RED_CARD
	end

RockTunnel_1F_EventScript_ItemTMZenHeadbutt::
	finditem ITEM_TM_ZEN_HEADBUTT
	end

RockTunnel_1F_EventScript_ItemEverstone::
	finditem ITEM_EVERSTONE
	end

RockTunnel_B1F_EventScript_ItemSinnohFossil::
	randomSeeded 2
	switch VAR_RESULT
	case 0, MtMoon_B2F_EventScript_ArmorFossil
	case 1, MtMoon_B2F_EventScript_SkullFossil
	end

RockTunnel_B1F_EventScript_ItemFossilisedFish::
	finditem ITEM_FOSSILIZED_FISH
	end

RockTunnel_B1F_EventScript_ItemFossilizedDino::
	finditem ITEM_FOSSILIZED_DINO
	end


SilphCo_8F_EventScript_ItemIronBall::
	finditem ITEM_IRON_BALL
	end

SilphCo_11F_EventScript_ItemZinc::
	finditem ITEM_ZINC
	end

PokemonMansion_1F_EventScript_ItemProtein::
	finditem ITEM_PROTEIN
	end

PokemonMansion_2F_EventScript_ItemZinc::
	finditem ITEM_ZINC
	end

PokemonMansion_2F_EventScript_ItemHPUp::
	finditem ITEM_HP_UP
	end

ViridianCity_EventScript_ItemAbilityCapsule::
	finditem ITEM_ABILITY_CAPSULE
	end

Route11_EventScript_ItemDreamBall::
	finditem ITEM_DREAM_BALL
	end

Route11_EventScript_ItemMuscleFeather::
	finditem ITEM_MUSCLE_FEATHER
	end

RockTunnel_B1F_EventScript_ItemTMRockSlide::
	finditem ITEM_TM_ROCK_SLIDE
	end

PokemonTower_5F_EventScript_ItemTMWillOWisp::
	finditem ITEM_TM_WILL_O_WISP
	end

CeladonCity_EventScript_ItemDreamPatch::
	finditem ITEM_DREAM_PATCH
	end

CeladonCity_EventScript_ItemScovillainite::
	finditem ITEM_SCOVILLAINITE
	end

RocketHideout_B3F_EventScript_ItemAmuletCoin::
	finditem ITEM_RED_CARD
	end

SafariZone_North_EventScript_ItemQuickClaw::
	finditem ITEM_QUICK_CLAW
	end

SeafoamIslands_1F_EventScript_ItemIceHeal::
	finditem ITEM_ICE_HEAL
	end

SeafoamIslands_B1F_EventScript_ItemWaterStone::
	finditem ITEM_WATER_STONE
	end

SeafoamIslands_B1F_EventScript_ItemRevive::
	finditem ITEM_REVIVE
	end

SeafoamIslands_B2F_EventScript_ItemBigPearl::
	finditem ITEM_BIG_PEARL
	end

SeafoamIslands_B4F_EventScript_ItemUltraBall::
	finditem ITEM_ULTRA_BALL
	end

FourIsland_EventScript_ItemStarPiece::
	finditem ITEM_STAR_PIECE
	end

FourIsland_EventScript_ItemStardust::
	finditem ITEM_STARDUST
	end

OneIsland_KindleRoad_EventScript_ItemEther::
	finditem ITEM_ETHER
	end

OneIsland_KindleRoad_EventScript_ItemMaxRepel::
	finditem ITEM_BIG_NUGGET
	end

OneIsland_KindleRoad_EventScript_ItemCarbos::
	finditem ITEM_CARBOS
	end

FiveIsland_Meadow_EventScript_ItemMaxPotion::
	finditem ITEM_MAX_POTION
	end

FiveIsland_Meadow_EventScript_ItemPPUp::
	finditem ITEM_PP_UP
	end

FiveIsland_MemorialPillar_EventScript_ItemMetalCoat::
	finditem ITEM_METAL_COAT
	end

SixIsland_OutcastIsland_EventScript_ItemPPUp::
	finditem ITEM_PP_UP
	end

SixIsland_WaterPath_EventScript_ItemElixir::
	finditem ITEM_ELIXIR
	end

SixIsland_WaterPath_EventScript_ItemDragonScale::
	finditem ITEM_DRAGON_SCALE
	end

SixIsland_RuinValley_EventScript_ItemFullRestore::
	finditem ITEM_FULL_RESTORE
	end

SixIsland_RuinValley_EventScript_ItemHPUp::
	finditem ITEM_HP_UP
	end

SixIsland_RuinValley_EventScript_ItemSunStone::
	finditem ITEM_SUN_STONE
	end

SevenIsland_SevaultCanyon_EventScript_ItemKingsRock::
	finditem ITEM_KINGS_ROCK
	end

SevenIsland_SevaultCanyon_EventScript_ItemMaxElixir::
	finditem ITEM_MAX_ELIXIR
	end

SevenIsland_SevaultCanyon_EventScript_ItemNugget::
	finditem ITEM_NUGGET
	end

ThreeIsland_BerryForest_EventScript_ItemMaxEther::
	finditem ITEM_MAX_ETHER
	end

ThreeIsland_BerryForest_EventScript_ItemFullHeal::
	finditem ITEM_FULL_HEAL
	end

ThreeIsland_BerryForest_EventScript_ItemMaxElixir::
	finditem ITEM_MAX_ELIXIR
	end

MtEmber_Exterior_EventScript_ItemUltraBall::
	finditem ITEM_ULTRA_BALL
	end

MtEmber_Exterior_EventScript_ItemFireStone::
	finditem ITEM_FIRE_STONE
	end

MtEmber_Exterior_EventScript_ItemDireHit::
	finditem ITEM_DIRE_HIT
	end

FourIsland_IcefallCave_1F_EventScript_ItemUltraBall::
	finditem ITEM_ULTRA_BALL
	end

FourIsland_IcefallCave_1F_EventScript_ItemHM07::
	finditem ITEM_HM07
	end

FourIsland_IcefallCave_B1F_EventScript_ItemFullRestore::
	finditem ITEM_FULL_RESTORE
	end

FourIsland_IcefallCave_B1F_EventScript_ItemNeverMeltIce::
	finditem ITEM_NEVER_MELT_ICE
	end

FiveIsland_RocketWarehouse_EventScript_ItemBigPearl::
	finditem ITEM_BIG_PEARL
	end

FiveIsland_RocketWarehouse_EventScript_ItemTM36::
	finditem ITEM_TM36
	end

FiveIsland_RocketWarehouse_EventScript_ItemPearl::
	finditem ITEM_PEARL
	end

FiveIsland_RocketWarehouse_EventScript_ItemUpGrade::
	finditem ITEM_UP_GRADE
	end

FiveIsland_LostCave_Room10_EventScript_ItemSilkScarf::
	finditem ITEM_SILK_SCARF
	end

FiveIsland_LostCave_Room11_EventScript_ItemLaxIncense::
	finditem ITEM_LAX_INCENSE
	end

FiveIsland_LostCave_Room12_EventScript_ItemSeaIncense::
	finditem ITEM_SEA_INCENSE
	end

FiveIsland_LostCave_Room13_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE
	end

FiveIsland_LostCave_Room14_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY
	end

SevenIsland_SevaultCanyon_House_EventScript_ItemLuckyPunch::
	finditem ITEM_LUCKY_PUNCH
	end

SilphCo_4F_EventScript_ItemTM41::
	finditem ITEM_TM_SCALD
	end
