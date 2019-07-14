#ifndef GUARD_DATA_ENCOUNTERS_H
#define GUARD_DATA_ENCOUNTERS_H

const struct WildPokemon PetalburgCity_WaterMons [] =
{
    {20, 30, SPECIES_MARILL},
    {10, 20, SPECIES_MARILL},
    {30, 35, SPECIES_MARILL},
    {5, 10, SPECIES_MARILL},
    {5, 10, SPECIES_MARILL},
};
const struct WildPokemonInfo PetalburgCity_WaterMonsInfo = {1, PetalburgCity_WaterMons};

const struct WildPokemon MeteorFalls_1F_1R_LandMons [] =
{
    {19, 22, SPECIES_ZUBAT},
    {19, 22, SPECIES_ZUBAT},
    {19, 22, SPECIES_ARON},
    {19, 22, SPECIES_ARON},
    {19, 22, SPECIES_SOLROCK},
    {19, 22, SPECIES_LUNATONE},
    {19, 22, SPECIES_CLEFAIRY},
    {19, 22, SPECIES_CLEFAIRY},
    {19, 22, SPECIES_CLEFAIRY},
    {19, 22, SPECIES_MISDREAVUS},
    {19, 22, SPECIES_CLEFAIRY},
    {19, 22, SPECIES_MISDREAVUS},
};
const struct WildPokemonInfo MeteorFalls_1F_1R_LandMonsInfo = {10, MeteorFalls_1F_1R_LandMons};

const struct WildPokemon MeteorFalls_1F_2R_LandMons [] =
{
    {33, 33, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
#ifdef SAPPHIRE
    {35, 35, SPECIES_LUNATONE},
    {33, 33, SPECIES_LUNATONE},
    {37, 37, SPECIES_LUNATONE},
#else
    {35, 35, SPECIES_SOLROCK},
    {33, 33, SPECIES_SOLROCK},
    {37, 37, SPECIES_SOLROCK},
#endif
    {35, 35, SPECIES_GOLBAT},
#ifdef SAPPHIRE
    {39, 39, SPECIES_LUNATONE},
#else
    {39, 39, SPECIES_SOLROCK},
#endif
    {38, 38, SPECIES_GOLBAT},
    {40, 40, SPECIES_GOLBAT},
    {38, 38, SPECIES_GOLBAT},
    {40, 40, SPECIES_GOLBAT},
};
const struct WildPokemonInfo MeteorFalls_1F_2R_LandMonsInfo = {10, MeteorFalls_1F_2R_LandMons};

const struct WildPokemon MeteorFalls_B1F_1R_LandMons [] =
{
    {33, 33, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
#ifdef SAPPHIRE
    {35, 35, SPECIES_LUNATONE},
    {33, 33, SPECIES_LUNATONE},
    {37, 37, SPECIES_LUNATONE},
#else
    {35, 35, SPECIES_SOLROCK},
    {33, 33, SPECIES_SOLROCK},
    {37, 37, SPECIES_SOLROCK},
#endif
    {35, 35, SPECIES_GOLBAT},
#ifdef SAPPHIRE
    {39, 39, SPECIES_LUNATONE},
#else
    {39, 39, SPECIES_SOLROCK},
#endif
    {38, 38, SPECIES_GOLBAT},
    {40, 40, SPECIES_GOLBAT},
    {38, 38, SPECIES_GOLBAT},
    {40, 40, SPECIES_GOLBAT},
};
const struct WildPokemonInfo MeteorFalls_B1F_1R_LandMonsInfo = {10, MeteorFalls_B1F_1R_LandMons};

const struct WildPokemon MeteorFalls_B1F_2R_LandMons [] =
{
    {33, 33, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {30, 30, SPECIES_BAGON},
#ifdef SAPPHIRE
    {35, 35, SPECIES_LUNATONE},
#else
    {35, 35, SPECIES_SOLROCK},
#endif
    {35, 35, SPECIES_BAGON},
#ifdef SAPPHIRE
    {37, 37, SPECIES_LUNATONE},
#else
    {37, 37, SPECIES_SOLROCK},
#endif
    {25, 25, SPECIES_BAGON},
#ifdef SAPPHIRE
    {39, 39, SPECIES_LUNATONE},
#else
    {39, 39, SPECIES_SOLROCK},
#endif
    {38, 38, SPECIES_GOLBAT},
    {40, 40, SPECIES_GOLBAT},
    {38, 38, SPECIES_GOLBAT},
    {40, 40, SPECIES_GOLBAT},
};
const struct WildPokemonInfo MeteorFalls_B1F_2R_LandMonsInfo = {10, MeteorFalls_B1F_2R_LandMons};

const struct WildPokemon RusturfTunnel_LandMons [] =
{
    {9, 10, SPECIES_WHISMUR},
    {9, 10, SPECIES_WHISMUR},
    {9, 10, SPECIES_WHISMUR},
    {9, 10, SPECIES_WHISMUR},
    {9, 10, SPECIES_CHINGLING},
    {9, 10, SPECIES_DROWZEE},
    {9, 10, SPECIES_CHINGLING},
    {9, 10, SPECIES_DROWZEE},
    {9, 10, SPECIES_DUNSPARCE},
    {9, 10, SPECIES_DROWZEE},
    {9, 10, SPECIES_DUNSPARCE},
    {9, 10, SPECIES_DROWZEE},
};
const struct WildPokemonInfo RusturfTunnel_LandMonsInfo = {10, RusturfTunnel_LandMons};

const struct WildPokemon GraniteCave_1F_LandMons [] =
{
    {11, 13, SPECIES_ZUBAT},
    {11, 13, SPECIES_GEODUDE},
    {11, 13, SPECIES_EKANS},
    {11, 13, SPECIES_MAKUHITA},
    {11, 13, SPECIES_ABRA},
    {11, 13, SPECIES_KRABBY},
    {11, 13, SPECIES_ZUBAT},
    {11, 13, SPECIES_GEODUDE},
    {11, 13, SPECIES_MAKUHITA},
    {11, 13, SPECIES_EKANS},
    {11, 13, SPECIES_MAKUHITA},
    {11, 13, SPECIES_EKANS},
};
const struct WildPokemonInfo GraniteCave_1F_LandMonsInfo = {10, GraniteCave_1F_LandMons};

const struct WildPokemon GraniteCave_B1F_LandMons [] =
{
    {11, 13, SPECIES_ZUBAT},
    {11, 13, SPECIES_ARON},
    {11, 13, SPECIES_EKANS},
    {11, 13, SPECIES_MAKUHITA},
    {11, 13, SPECIES_ABRA},
    {11, 13, SPECIES_ONIX},
    {11, 13, SPECIES_ZUBAT},
    {11, 13, SPECIES_GEODUDE},
    {11, 13, SPECIES_SABLEYE},
    {11, 13, SPECIES_MAWILE},
    {11, 13, SPECIES_SABLEYE},
    {11, 13, SPECIES_MAWILE},
};
const struct WildPokemonInfo GraniteCave_B1F_LandMonsInfo = {10, GraniteCave_B1F_LandMons};

const struct WildPokemon GraniteCave_B2F_LandMons [] =
{
    {11, 13, SPECIES_ZUBAT},
    {11, 13, SPECIES_ARON},
    {11, 13, SPECIES_EKANS},
    {11, 13, SPECIES_SABLEYE},
    {11, 13, SPECIES_ABRA},
    {11, 13, SPECIES_ONIX},
    {11, 13, SPECIES_ZUBAT},
    {11, 13, SPECIES_GEODUDE},
    {11, 13, SPECIES_MAWILE},
    {11, 13, SPECIES_MAWILE},
    {11, 13, SPECIES_MAWILE},
    {11, 13, SPECIES_MAWILE},
};
const struct WildPokemonInfo GraniteCave_B2F_LandMonsInfo = {10, GraniteCave_B2F_LandMons};

const struct WildPokemon GraniteCave_B2F_RockSmashMons [] =
{
    {15, 20, SPECIES_NOSEPASS},
    {15, 20, SPECIES_NOSEPASS},
    {15, 20, SPECIES_NOSEPASS},
    {15, 20, SPECIES_NOSEPASS},
    {15, 20, SPECIES_NOSEPASS},
};
const struct WildPokemonInfo GraniteCave_B2F_RockSmashMonsInfo = {90, GraniteCave_B2F_RockSmashMons};

const struct WildPokemon GraniteCave_B4F_LandMons [] =
{
    {15, 17, SPECIES_ZUBAT},
    {15, 17, SPECIES_NOSEPASS},
    {15, 17, SPECIES_KRABBY},
    {15, 17, SPECIES_SEEL},
    {15, 17, SPECIES_SABLEYE},
    {15, 17, SPECIES_MAWILE},
    {15, 17, SPECIES_ZUBAT},
    {15, 17, SPECIES_NOSEPASS},
    {15, 17, SPECIES_ONIX},
    {15, 17, SPECIES_ONIX},
    {15, 17, SPECIES_ONIX},
    {15, 17, SPECIES_ONIX},
};
const struct WildPokemonInfo GraniteCave_B4F_LandMonsInfo = {10, GraniteCave_B4F_LandMons};

const struct WildPokemon GraniteCave_B4F_RockSmashMons [] =
{
    {15, 20, SPECIES_SHUCKLE},
    {15, 20, SPECIES_NOSEPASS},
    {15, 20, SPECIES_NOSEPASS},
    {15, 20, SPECIES_NOSEPASS},
    {15, 20, SPECIES_NOSEPASS},
};
const struct WildPokemonInfo GraniteCave_B4F_RockSmashMonsInfo = {90, GraniteCave_B4F_RockSmashMons};

const struct WildPokemon GraniteCave_StevensRoom_LandMons [] =
{
    {11, 13, SPECIES_ZUBAT},
    {11, 13, SPECIES_ARON},
    {11, 13, SPECIES_EKANS},
    {11, 13, SPECIES_MAKUHITA},
    {11, 13, SPECIES_ABRA},
    {11, 13, SPECIES_ARON},
    {11, 13, SPECIES_ZUBAT},
    {11, 13, SPECIES_ARON},
    {11, 13, SPECIES_MAKUHITA},
    {11, 13, SPECIES_EKANS},
    {11, 13, SPECIES_MAKUHITA},
    {11, 13, SPECIES_EKANS},
};
const struct WildPokemonInfo GraniteCave_StevensRoom_LandMonsInfo = {10, GraniteCave_StevensRoom_LandMons};

const struct WildPokemon PetalburgWoods_LandMons [] =
{
    {6, 8, SPECIES_HOOTHOOT},
    {6, 8, SPECIES_BELLSPROUT},
    {6, 8, SPECIES_SHROOMISH},
    {6, 8, SPECIES_PARAS},
    {6, 7, SPECIES_CATERPIE},
    {6, 7, SPECIES_WEEDLE},
    {6, 8, SPECIES_SPINARAK},
    {6, 8, SPECIES_ZIGZAGOON},
    {6, 8, SPECIES_SLAKOTH},
    {6, 8, SPECIES_TAILLOW},
    {6, 8, SPECIES_SLAKOTH},
    {6, 8, SPECIES_TAILLOW},
};
const struct WildPokemonInfo PetalburgWoods_LandMonsInfo = {20, PetalburgWoods_LandMons};

const struct WildPokemon PetalburgWoods_AltLandMons [] =
{
    {10, 11, SPECIES_HOOTHOOT},
    {10, 11, SPECIES_BELLSPROUT},
    {10, 11, SPECIES_SHROOMISH},
    {10, 11, SPECIES_PARAS},
    {10, 11, SPECIES_PINECO},
    {10, 11, SPECIES_PINECO},
    {10, 11, SPECIES_SPINARAK},
    {10, 11, SPECIES_ZIGZAGOON},
    {10, 11, SPECIES_SLAKOTH},
    {10, 11, SPECIES_TAILLOW},
    {10, 11, SPECIES_SLAKOTH},
    {10, 11, SPECIES_TAILLOW},
};
const struct WildPokemonInfo PetalburgWoods_AltLandMonsInfo = {20, PetalburgWoods_AltLandMons};

const struct WildPokemon JaggedPass_LandMons [] =
{
    {20, 23, SPECIES_NUMEL},
    {20, 23, SPECIES_MACHOP},
    {20, 23, SPECIES_MANKEY},
    {20, 23, SPECIES_SPOINK},
    {20, 23, SPECIES_PINECO},
    {20, 23, SPECIES_SLUGMA},
    {20, 23, SPECIES_PONYTA},
    {20, 23, SPECIES_PONYTA},
    {20, 23, SPECIES_MANKEY},
    {20, 23, SPECIES_SUDOWOODO},
    {20, 23, SPECIES_MANKEY},
    {20, 23, SPECIES_SUDOWOODO},
};
const struct WildPokemonInfo JaggedPass_LandMonsInfo = {20, JaggedPass_LandMons};

const struct WildPokemon FieryPath_LandMons [] =
{
    {17, 19, SPECIES_KOFFING},
    {17, 19, SPECIES_GRIMER},
    {17, 19, SPECIES_NUMEL},
    {17, 19, SPECIES_NUMEL},
    {17, 19, SPECIES_SLUGMA},
    {17, 19, SPECIES_TORKOAL},
    {17, 19, SPECIES_MAGBY},
    {17, 19, SPECIES_MAGBY},
    {17, 19, SPECIES_MACHOP},
    {17, 19, SPECIES_DIGLETT},
    {17, 19, SPECIES_MACHOP},
    {17, 19, SPECIES_DIGLETT},
};
const struct WildPokemonInfo FieryPath_LandMonsInfo = {10, FieryPath_LandMons};

const struct WildPokemon MtPyre_1F_LandMons [] =
{
    {27, 28, SPECIES_SHUPPET},
    {27, 28, SPECIES_DUSKULL},
    {25, 26, SPECIES_SHUPPET},
    {25, 26, SPECIES_DUSKULL},
    {24, 29, SPECIES_SHUPPET},
    {24, 29, SPECIES_DUSKULL},
    {22, 23, SPECIES_SHUPPET},
    {22, 23, SPECIES_DUSKULL},
    {24, 29, SPECIES_SHUPPET},
    {24, 29, SPECIES_DUSKULL},
    {24, 29, SPECIES_SHUPPET},
    {24, 29, SPECIES_DUSKULL},
};
const struct WildPokemonInfo MtPyre_1F_LandMonsInfo = {10, MtPyre_1F_LandMons};

const struct WildPokemon MtPyre_2F_LandMons [] =
{
    {27, 28, SPECIES_SHUPPET},
    {27, 28, SPECIES_DUSKULL},
    {25, 26, SPECIES_SHUPPET},
    {25, 26, SPECIES_DUSKULL},
    {24, 29, SPECIES_SHUPPET},
    {24, 29, SPECIES_DUSKULL},
    {22, 23, SPECIES_SHUPPET},
    {22, 23, SPECIES_DUSKULL},
    {24, 29, SPECIES_SHUPPET},
    {24, 29, SPECIES_DUSKULL},
    {24, 29, SPECIES_SHUPPET},
    {24, 29, SPECIES_DUSKULL},
};
const struct WildPokemonInfo MtPyre_2F_LandMonsInfo = {10, MtPyre_2F_LandMons};

const struct WildPokemon MtPyre_3F_LandMons [] =
{
    {27, 28, SPECIES_SHUPPET},
    {27, 28, SPECIES_DUSKULL},
    {25, 26, SPECIES_SHUPPET},
    {25, 26, SPECIES_DUSKULL},
    {24, 29, SPECIES_SHUPPET},
    {24, 29, SPECIES_DUSKULL},
    {22, 23, SPECIES_SHUPPET},
    {22, 23, SPECIES_DUSKULL},
    {24, 29, SPECIES_SHUPPET},
    {24, 29, SPECIES_DUSKULL},
    {24, 29, SPECIES_SHUPPET},
    {24, 29, SPECIES_DUSKULL},
};
const struct WildPokemonInfo MtPyre_3F_LandMonsInfo = {10, MtPyre_3F_LandMons};

const struct WildPokemon MtPyre_4F_LandMons [] =
{
    {27, 28, SPECIES_SHUPPET},
    {27, 28, SPECIES_DUSKULL},
    {25, 26, SPECIES_SHUPPET},
    {25, 26, SPECIES_DUSKULL},
    {24, 29, SPECIES_SHUPPET},
    {24, 29, SPECIES_DUSKULL},
    {22, 23, SPECIES_SHUPPET},
    {22, 23, SPECIES_DUSKULL},
    {24, 29, SPECIES_SHUPPET},
    {24, 29, SPECIES_DUSKULL},
    {24, 29, SPECIES_SHUPPET},
    {24, 29, SPECIES_DUSKULL},
};
const struct WildPokemonInfo MtPyre_4F_LandMonsInfo = {10, MtPyre_4F_LandMons};

const struct WildPokemon MtPyre_5F_LandMons [] =
{
    {27, 28, SPECIES_SHUPPET},
    {27, 28, SPECIES_DUSKULL},
    {25, 26, SPECIES_SHUPPET},
    {25, 26, SPECIES_DUSKULL},
    {24, 29, SPECIES_SHUPPET},
    {24, 29, SPECIES_DUSKULL},
    {22, 23, SPECIES_SHUPPET},
    {22, 23, SPECIES_DUSKULL},
    {24, 29, SPECIES_SHUPPET},
    {24, 29, SPECIES_DUSKULL},
    {24, 29, SPECIES_SHUPPET},
    {24, 29, SPECIES_DUSKULL},
};
const struct WildPokemonInfo MtPyre_5F_LandMonsInfo = {10, MtPyre_5F_LandMons};

const struct WildPokemon MtPyre_6F_LandMons [] =
{
    {27, 28, SPECIES_SHUPPET},
    {27, 28, SPECIES_DUSKULL},
    {25, 26, SPECIES_SHUPPET},
    {25, 26, SPECIES_DUSKULL},
    {24, 29, SPECIES_SHUPPET},
    {24, 29, SPECIES_DUSKULL},
    {22, 23, SPECIES_SHUPPET},
    {22, 23, SPECIES_DUSKULL},
    {24, 29, SPECIES_SHUPPET},
    {24, 29, SPECIES_DUSKULL},
    {24, 29, SPECIES_SHUPPET},
    {24, 29, SPECIES_DUSKULL},
};
const struct WildPokemonInfo MtPyre_6F_LandMonsInfo = {10, MtPyre_6F_LandMons};

const struct WildPokemon MtPyre_Exterior_LandMons [] =
{
#ifdef SAPPHIRE
    {27, 27, SPECIES_SHUPPET},
#else
    {27, 27, SPECIES_DUSKULL},
#endif
    {27, 27, SPECIES_MEDITITE},
#ifdef SAPPHIRE
    {28, 28, SPECIES_SHUPPET},
#else
    {28, 28, SPECIES_DUSKULL},
#endif
    {29, 29, SPECIES_MEDITITE},
#ifdef SAPPHIRE
    {29, 29, SPECIES_SHUPPET},
#else
    {29, 29, SPECIES_DUSKULL},
#endif
    {27, 27, SPECIES_VULPIX},
    {29, 29, SPECIES_VULPIX},
    {25, 25, SPECIES_VULPIX},
    {27, 27, SPECIES_WINGULL},
    {27, 27, SPECIES_WINGULL},
    {26, 26, SPECIES_WINGULL},
    {28, 28, SPECIES_WINGULL},
};
const struct WildPokemonInfo MtPyre_Exterior_LandMonsInfo = {10, MtPyre_Exterior_LandMons};

const struct WildPokemon MtPyre_Summit_LandMons [] =
{
#ifdef SAPPHIRE
    {28, 28, SPECIES_SHUPPET},
    {29, 29, SPECIES_SHUPPET},
    {27, 27, SPECIES_SHUPPET},
    {26, 26, SPECIES_SHUPPET},
    {30, 30, SPECIES_SHUPPET},
    {25, 25, SPECIES_SHUPPET},
    {24, 24, SPECIES_SHUPPET},
    {28, 28, SPECIES_DUSKULL},
    {26, 26, SPECIES_DUSKULL},
    {30, 30, SPECIES_DUSKULL},
#else
    {28, 28, SPECIES_DUSKULL},
    {29, 29, SPECIES_DUSKULL},
    {27, 27, SPECIES_DUSKULL},
    {26, 26, SPECIES_DUSKULL},
    {30, 30, SPECIES_DUSKULL},
    {25, 25, SPECIES_DUSKULL},
    {24, 24, SPECIES_DUSKULL},
    {28, 28, SPECIES_SHUPPET},
    {26, 26, SPECIES_SHUPPET},
    {30, 30, SPECIES_SHUPPET},
#endif
    {28, 28, SPECIES_CHIMECHO},
    {28, 28, SPECIES_CHIMECHO},
};
const struct WildPokemonInfo MtPyre_Summit_LandMonsInfo = {10, MtPyre_Summit_LandMons};

const struct WildPokemon SeafloorCavern_Room1_LandMons [] =
{
    {30, 30, SPECIES_ZUBAT},
    {31, 31, SPECIES_ZUBAT},
    {32, 32, SPECIES_ZUBAT},
    {33, 33, SPECIES_ZUBAT},
    {28, 28, SPECIES_ZUBAT},
    {29, 29, SPECIES_ZUBAT},
    {34, 34, SPECIES_ZUBAT},
    {35, 35, SPECIES_ZUBAT},
    {34, 34, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
    {36, 36, SPECIES_GOLBAT},
};
const struct WildPokemonInfo SeafloorCavern_Room1_LandMonsInfo = {4, SeafloorCavern_Room1_LandMons};

const struct WildPokemon SeafloorCavern_Room2_LandMons [] =
{
    {30, 30, SPECIES_ZUBAT},
    {31, 31, SPECIES_ZUBAT},
    {32, 32, SPECIES_ZUBAT},
    {33, 33, SPECIES_ZUBAT},
    {28, 28, SPECIES_ZUBAT},
    {29, 29, SPECIES_ZUBAT},
    {34, 34, SPECIES_ZUBAT},
    {35, 35, SPECIES_ZUBAT},
    {34, 34, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
    {36, 36, SPECIES_GOLBAT},
};
const struct WildPokemonInfo SeafloorCavern_Room2_LandMonsInfo = {4, SeafloorCavern_Room2_LandMons};

const struct WildPokemon SeafloorCavern_Room3_LandMons [] =
{
    {30, 30, SPECIES_ZUBAT},
    {31, 31, SPECIES_ZUBAT},
    {32, 32, SPECIES_ZUBAT},
    {33, 33, SPECIES_ZUBAT},
    {28, 28, SPECIES_ZUBAT},
    {29, 29, SPECIES_ZUBAT},
    {34, 34, SPECIES_ZUBAT},
    {35, 35, SPECIES_ZUBAT},
    {34, 34, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
    {36, 36, SPECIES_GOLBAT},
};
const struct WildPokemonInfo SeafloorCavern_Room3_LandMonsInfo = {4, SeafloorCavern_Room3_LandMons};

const struct WildPokemon SeafloorCavern_Room4_LandMons [] =
{
    {30, 30, SPECIES_ZUBAT},
    {31, 31, SPECIES_ZUBAT},
    {32, 32, SPECIES_ZUBAT},
    {33, 33, SPECIES_ZUBAT},
    {28, 28, SPECIES_ZUBAT},
    {29, 29, SPECIES_ZUBAT},
    {34, 34, SPECIES_ZUBAT},
    {35, 35, SPECIES_ZUBAT},
    {34, 34, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
    {36, 36, SPECIES_GOLBAT},
};
const struct WildPokemonInfo SeafloorCavern_Room4_LandMonsInfo = {4, SeafloorCavern_Room4_LandMons};

const struct WildPokemon SeafloorCavern_Room5_LandMons [] =
{
    {30, 30, SPECIES_ZUBAT},
    {31, 31, SPECIES_ZUBAT},
    {32, 32, SPECIES_ZUBAT},
    {33, 33, SPECIES_ZUBAT},
    {28, 28, SPECIES_ZUBAT},
    {29, 29, SPECIES_ZUBAT},
    {34, 34, SPECIES_ZUBAT},
    {35, 35, SPECIES_ZUBAT},
    {34, 34, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
    {36, 36, SPECIES_GOLBAT},
};
const struct WildPokemonInfo SeafloorCavern_Room5_LandMonsInfo = {4, SeafloorCavern_Room5_LandMons};

const struct WildPokemon SeafloorCavern_Room6_LandMons [] =
{
    {30, 30, SPECIES_ZUBAT},
    {31, 31, SPECIES_ZUBAT},
    {32, 32, SPECIES_ZUBAT},
    {33, 33, SPECIES_ZUBAT},
    {28, 28, SPECIES_ZUBAT},
    {29, 29, SPECIES_ZUBAT},
    {34, 34, SPECIES_ZUBAT},
    {35, 35, SPECIES_ZUBAT},
    {34, 34, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
    {36, 36, SPECIES_GOLBAT},
};
const struct WildPokemonInfo SeafloorCavern_Room6_LandMonsInfo = {4, SeafloorCavern_Room6_LandMons};

const struct WildPokemon SeafloorCavern_Room7_LandMons [] =
{
    {30, 30, SPECIES_ZUBAT},
    {31, 31, SPECIES_ZUBAT},
    {32, 32, SPECIES_ZUBAT},
    {33, 33, SPECIES_ZUBAT},
    {28, 28, SPECIES_ZUBAT},
    {29, 29, SPECIES_ZUBAT},
    {34, 34, SPECIES_ZUBAT},
    {35, 35, SPECIES_ZUBAT},
    {34, 34, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
    {36, 36, SPECIES_GOLBAT},
};
const struct WildPokemonInfo SeafloorCavern_Room7_LandMonsInfo = {4, SeafloorCavern_Room7_LandMons};

const struct WildPokemon SeafloorCavern_Room8_LandMons [] =
{
    {30, 30, SPECIES_ZUBAT},
    {31, 31, SPECIES_ZUBAT},
    {32, 32, SPECIES_ZUBAT},
    {33, 33, SPECIES_ZUBAT},
    {28, 28, SPECIES_ZUBAT},
    {29, 29, SPECIES_ZUBAT},
    {34, 34, SPECIES_ZUBAT},
    {35, 35, SPECIES_ZUBAT},
    {34, 34, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
    {36, 36, SPECIES_GOLBAT},
};
const struct WildPokemonInfo SeafloorCavern_Room8_LandMonsInfo = {4, SeafloorCavern_Room8_LandMons};

const struct WildPokemon CaveOfOrigin_Entrance_LandMons [] =
{
    {30, 30, SPECIES_ZUBAT},
    {31, 31, SPECIES_ZUBAT},
    {32, 32, SPECIES_ZUBAT},
    {33, 33, SPECIES_ZUBAT},
    {28, 28, SPECIES_ZUBAT},
    {29, 29, SPECIES_ZUBAT},
    {34, 34, SPECIES_ZUBAT},
    {35, 35, SPECIES_ZUBAT},
    {34, 34, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
    {36, 36, SPECIES_GOLBAT},
};
const struct WildPokemonInfo CaveOfOrigin_Entrance_LandMonsInfo = {4, CaveOfOrigin_Entrance_LandMons};

const struct WildPokemon CaveOfOrigin_1F_LandMons [] =
{
    {30, 30, SPECIES_ZUBAT},
    {31, 31, SPECIES_ZUBAT},
    {32, 32, SPECIES_ZUBAT},
#ifdef SAPPHIRE
    {30, 30, SPECIES_SABLEYE},
    {32, 32, SPECIES_SABLEYE},
    {34, 34, SPECIES_SABLEYE},
#else
    {30, 30, SPECIES_MAWILE},
    {32, 32, SPECIES_MAWILE},
    {34, 34, SPECIES_MAWILE},
#endif
    {33, 33, SPECIES_ZUBAT},
    {34, 34, SPECIES_ZUBAT},
    {34, 34, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
    {36, 36, SPECIES_GOLBAT},
};
const struct WildPokemonInfo CaveOfOrigin_1F_LandMonsInfo = {4, CaveOfOrigin_1F_LandMons};

const struct WildPokemon CaveOfOrigin_B1F_LandMons [] =
{
    {30, 30, SPECIES_ZUBAT},
    {31, 31, SPECIES_ZUBAT},
    {32, 32, SPECIES_ZUBAT},
#ifdef SAPPHIRE
    {30, 30, SPECIES_SABLEYE},
    {32, 32, SPECIES_SABLEYE},
    {34, 34, SPECIES_SABLEYE},
#else
    {30, 30, SPECIES_MAWILE},
    {32, 32, SPECIES_MAWILE},
    {34, 34, SPECIES_MAWILE},
#endif
    {33, 33, SPECIES_ZUBAT},
    {34, 34, SPECIES_ZUBAT},
    {34, 34, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
    {36, 36, SPECIES_GOLBAT},
};
const struct WildPokemonInfo CaveOfOrigin_B1F_LandMonsInfo = {4, CaveOfOrigin_B1F_LandMons};

const struct WildPokemon CaveOfOrigin_B2F_LandMons [] =
{
    {30, 30, SPECIES_ZUBAT},
    {31, 31, SPECIES_ZUBAT},
    {32, 32, SPECIES_ZUBAT},
#ifdef SAPPHIRE
    {30, 30, SPECIES_SABLEYE},
    {32, 32, SPECIES_SABLEYE},
    {34, 34, SPECIES_SABLEYE},
#else
    {30, 30, SPECIES_MAWILE},
    {32, 32, SPECIES_MAWILE},
    {34, 34, SPECIES_MAWILE},
#endif
    {33, 33, SPECIES_ZUBAT},
    {34, 34, SPECIES_ZUBAT},
    {34, 34, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
    {36, 36, SPECIES_GOLBAT},
};
const struct WildPokemonInfo CaveOfOrigin_B2F_LandMonsInfo = {4, CaveOfOrigin_B2F_LandMons};

const struct WildPokemon CaveOfOrigin_B3F_LandMons [] =
{
    {30, 30, SPECIES_ZUBAT},
    {31, 31, SPECIES_ZUBAT},
    {32, 32, SPECIES_ZUBAT},
#ifdef SAPPHIRE
    {30, 30, SPECIES_SABLEYE},
    {32, 32, SPECIES_SABLEYE},
    {34, 34, SPECIES_SABLEYE},
#else
    {30, 30, SPECIES_MAWILE},
    {32, 32, SPECIES_MAWILE},
    {34, 34, SPECIES_MAWILE},
#endif
    {33, 33, SPECIES_ZUBAT},
    {34, 34, SPECIES_ZUBAT},
    {34, 34, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
    {36, 36, SPECIES_GOLBAT},
};
const struct WildPokemonInfo CaveOfOrigin_B3F_LandMonsInfo = {4, CaveOfOrigin_B3F_LandMons};

const struct WildPokemon VictoryRoad_1F_LandMons [] =
{
    {40, 40, SPECIES_GOLBAT},
    {40, 40, SPECIES_HARIYAMA},
    {40, 40, SPECIES_LAIRON},
    {40, 40, SPECIES_LOUDRED},
    {36, 36, SPECIES_ZUBAT},
    {36, 36, SPECIES_MAKUHITA},
    {38, 38, SPECIES_GOLBAT},
    {38, 38, SPECIES_HARIYAMA},
    {36, 36, SPECIES_ARON},
    {36, 36, SPECIES_WHISMUR},
    {36, 36, SPECIES_ARON},
    {36, 36, SPECIES_WHISMUR},
};
const struct WildPokemonInfo VictoryRoad_1F_LandMonsInfo = {10, VictoryRoad_1F_LandMons};

const struct WildPokemon VictoryRoad_B1F_LandMons [] =
{
    {40, 40, SPECIES_GOLBAT},
    {40, 40, SPECIES_HARIYAMA},
    {40, 40, SPECIES_LAIRON},
    {40, 40, SPECIES_MEDICHAM},
    {38, 38, SPECIES_GOLBAT},
    {38, 38, SPECIES_HARIYAMA},
    {42, 42, SPECIES_GOLBAT},
    {42, 42, SPECIES_HARIYAMA},
    {42, 42, SPECIES_LAIRON},
    {38, 38, SPECIES_MEDITITE},
    {42, 42, SPECIES_LAIRON},
    {38, 38, SPECIES_MEDITITE},
};
const struct WildPokemonInfo VictoryRoad_B1F_LandMonsInfo = {10, VictoryRoad_B1F_LandMons};

const struct WildPokemon VictoryRoad_B1F_RockSmashMons [] =
{
    {30, 40, SPECIES_GRAVELER},
    {30, 40, SPECIES_GEODUDE},
    {35, 40, SPECIES_GRAVELER},
    {35, 40, SPECIES_GRAVELER},
    {35, 40, SPECIES_GRAVELER},
};
const struct WildPokemonInfo VictoryRoad_B1F_RockSmashMonsInfo = {20, VictoryRoad_B1F_RockSmashMons};

const struct WildPokemon VictoryRoad_B2F_LandMons [] =
{
    {40, 40, SPECIES_GOLBAT},
#ifdef SAPPHIRE
    {40, 40, SPECIES_SABLEYE},
#else
    {40, 40, SPECIES_MAWILE},
#endif
    {40, 40, SPECIES_LAIRON},
    {40, 40, SPECIES_MEDICHAM},
    {42, 42, SPECIES_GOLBAT},
#ifdef SAPPHIRE
    {42, 42, SPECIES_SABLEYE},
#else
    {42, 42, SPECIES_MAWILE},
#endif
    {44, 44, SPECIES_GOLBAT},
#ifdef SAPPHIRE
    {44, 44, SPECIES_SABLEYE},
#else
    {44, 44, SPECIES_MAWILE},
#endif
    {42, 42, SPECIES_LAIRON},
    {42, 42, SPECIES_MEDICHAM},
    {44, 44, SPECIES_LAIRON},
    {44, 44, SPECIES_MEDICHAM},
};
const struct WildPokemonInfo VictoryRoad_B2F_LandMonsInfo = {10, VictoryRoad_B2F_LandMons};

const struct WildPokemon ShoalCave_LowTideEntranceRoom_LandMons [] =
{
    {26, 26, SPECIES_ZUBAT},
    {26, 26, SPECIES_SPHEAL},
    {28, 28, SPECIES_ZUBAT},
    {28, 28, SPECIES_SPHEAL},
    {30, 30, SPECIES_ZUBAT},
    {30, 30, SPECIES_SPHEAL},
    {32, 32, SPECIES_ZUBAT},
    {32, 32, SPECIES_SPHEAL},
    {32, 32, SPECIES_GOLBAT},
    {32, 32, SPECIES_SPHEAL},
    {32, 32, SPECIES_GOLBAT},
    {32, 32, SPECIES_SPHEAL},
};
const struct WildPokemonInfo ShoalCave_LowTideEntranceRoom_LandMonsInfo = {10, ShoalCave_LowTideEntranceRoom_LandMons};

const struct WildPokemon ShoalCave_LowTideInnerRoom_LandMons [] =
{
    {26, 26, SPECIES_ZUBAT},
    {26, 26, SPECIES_SPHEAL},
    {28, 28, SPECIES_ZUBAT},
    {28, 28, SPECIES_SPHEAL},
    {30, 30, SPECIES_ZUBAT},
    {30, 30, SPECIES_SPHEAL},
    {32, 32, SPECIES_ZUBAT},
    {32, 32, SPECIES_SPHEAL},
    {32, 32, SPECIES_GOLBAT},
    {32, 32, SPECIES_SPHEAL},
    {32, 32, SPECIES_GOLBAT},
    {32, 32, SPECIES_SPHEAL},
};
const struct WildPokemonInfo ShoalCave_LowTideInnerRoom_LandMonsInfo = {10, ShoalCave_LowTideInnerRoom_LandMons};

const struct WildPokemon ShoalCave_LowTideStairsRoom_LandMons [] =
{
    {26, 26, SPECIES_ZUBAT},
    {26, 26, SPECIES_SPHEAL},
    {28, 28, SPECIES_ZUBAT},
    {28, 28, SPECIES_SPHEAL},
    {30, 30, SPECIES_ZUBAT},
    {30, 30, SPECIES_SPHEAL},
    {32, 32, SPECIES_ZUBAT},
    {32, 32, SPECIES_SPHEAL},
    {32, 32, SPECIES_GOLBAT},
    {32, 32, SPECIES_SPHEAL},
    {32, 32, SPECIES_GOLBAT},
    {32, 32, SPECIES_SPHEAL},
};
const struct WildPokemonInfo ShoalCave_LowTideStairsRoom_LandMonsInfo = {10, ShoalCave_LowTideStairsRoom_LandMons};

const struct WildPokemon ShoalCave_LowTideLowerRoom_LandMons [] =
{
    {26, 26, SPECIES_ZUBAT},
    {26, 26, SPECIES_SPHEAL},
    {28, 28, SPECIES_ZUBAT},
    {28, 28, SPECIES_SPHEAL},
    {30, 30, SPECIES_ZUBAT},
    {30, 30, SPECIES_SPHEAL},
    {32, 32, SPECIES_ZUBAT},
    {32, 32, SPECIES_SPHEAL},
    {32, 32, SPECIES_GOLBAT},
    {32, 32, SPECIES_SPHEAL},
    {32, 32, SPECIES_GOLBAT},
    {32, 32, SPECIES_SPHEAL},
};
const struct WildPokemonInfo ShoalCave_LowTideLowerRoom_LandMonsInfo = {10, ShoalCave_LowTideLowerRoom_LandMons};

const struct WildPokemon ShoalCave_LowTideIceRoom_LandMons [] =
{
    {26, 26, SPECIES_ZUBAT},
    {26, 26, SPECIES_SPHEAL},
    {28, 28, SPECIES_ZUBAT},
    {28, 28, SPECIES_SPHEAL},
    {30, 30, SPECIES_ZUBAT},
    {30, 30, SPECIES_SPHEAL},
    {26, 26, SPECIES_SNORUNT},
    {32, 32, SPECIES_SPHEAL},
    {30, 30, SPECIES_GOLBAT},
    {28, 28, SPECIES_SNORUNT},
    {32, 32, SPECIES_GOLBAT},
    {30, 30, SPECIES_SNORUNT},
};
const struct WildPokemonInfo ShoalCave_LowTideIceRoom_LandMonsInfo = {10, ShoalCave_LowTideIceRoom_LandMons};

const struct WildPokemon NewMauville_Entrance_LandMons [] =
{
    {16, 19, SPECIES_VOLTORB},
    {16, 19, SPECIES_MAGNEMITE},
    {16, 19, SPECIES_VOLTORB},
    {16, 19, SPECIES_MAGNEMITE},
    {16, 19, SPECIES_SHUPPET},
    {16, 19, SPECIES_SHUPPET},
    {16, 19, SPECIES_VOLTORB},
    {16, 19, SPECIES_MAGNEMITE},
    {16, 19, SPECIES_ELEKID},
    {16, 19, SPECIES_ELEKID},
    {16, 19, SPECIES_ELEKID},
    {16, 19, SPECIES_ELEKID},
};
const struct WildPokemonInfo NewMauville_Entrance_LandMonsInfo = {10, NewMauville_Entrance_LandMons};

const struct WildPokemon NewMauville_Inside_LandMons [] =
{
    {24, 24, SPECIES_VOLTORB},
    {24, 24, SPECIES_MAGNEMITE},
    {25, 25, SPECIES_VOLTORB},
    {25, 25, SPECIES_MAGNEMITE},
    {23, 23, SPECIES_VOLTORB},
    {23, 23, SPECIES_MAGNEMITE},
    {26, 26, SPECIES_VOLTORB},
    {26, 26, SPECIES_MAGNEMITE},
    {22, 22, SPECIES_VOLTORB},
    {22, 22, SPECIES_MAGNEMITE},
    {26, 26, SPECIES_ELECTRODE},
    {26, 26, SPECIES_MAGNETON},
};
const struct WildPokemonInfo NewMauville_Inside_LandMonsInfo = {10, NewMauville_Inside_LandMons};

const struct WildPokemon SkyPillar_1F_LandMons [] =
{
#ifdef SAPPHIRE
    {48, 48, SPECIES_SABLEYE},
#else
    {48, 48, SPECIES_MAWILE},
#endif
    {48, 48, SPECIES_GOLBAT},
    {50, 50, SPECIES_GOLBAT},
#ifdef SAPPHIRE
    {50, 50, SPECIES_SABLEYE},
#else
    {50, 50, SPECIES_MAWILE},
#endif
    {48, 48, SPECIES_CLAYDOL},
#ifdef SAPPHIRE
    {48, 48, SPECIES_BANETTE},
    {50, 50, SPECIES_BANETTE},
#else
    {48, 48, SPECIES_DUSCLOPS},
    {50, 50, SPECIES_DUSCLOPS},
#endif
    {49, 49, SPECIES_CLAYDOL},
    {47, 47, SPECIES_CLAYDOL},
    {50, 50, SPECIES_CLAYDOL},
    {47, 47, SPECIES_CLAYDOL},
    {50, 50, SPECIES_CLAYDOL},
};
const struct WildPokemonInfo SkyPillar_1F_LandMonsInfo = {10, SkyPillar_1F_LandMons};

const struct WildPokemon SkyPillar_3F_LandMons [] =
{
#ifdef SAPPHIRE
    {51, 51, SPECIES_SABLEYE},
#else
    {51, 51, SPECIES_MAWILE},
#endif
    {51, 51, SPECIES_GOLBAT},
    {53, 53, SPECIES_GOLBAT},
#ifdef SAPPHIRE
    {53, 53, SPECIES_SABLEYE},
#else
    {53, 53, SPECIES_MAWILE},
#endif
    {51, 51, SPECIES_CLAYDOL},
#ifdef SAPPHIRE
    {51, 51, SPECIES_BANETTE},
    {53, 53, SPECIES_BANETTE},
#else
    {51, 51, SPECIES_DUSCLOPS},
    {53, 53, SPECIES_DUSCLOPS},
#endif
    {52, 52, SPECIES_CLAYDOL},
    {50, 50, SPECIES_CLAYDOL},
    {53, 53, SPECIES_CLAYDOL},
    {50, 50, SPECIES_CLAYDOL},
    {53, 53, SPECIES_CLAYDOL},
};
const struct WildPokemonInfo SkyPillar_3F_LandMonsInfo = {10, SkyPillar_3F_LandMons};

const struct WildPokemon SkyPillar_5F_LandMons [] =
{
#ifdef SAPPHIRE
    {54, 54, SPECIES_SABLEYE},
#else
    {54, 54, SPECIES_MAWILE},
#endif
    {54, 54, SPECIES_GOLBAT},
    {56, 56, SPECIES_GOLBAT},
#ifdef SAPPHIRE
    {56, 56, SPECIES_SABLEYE},
#else
    {56, 56, SPECIES_MAWILE},
#endif
    {54, 54, SPECIES_CLAYDOL},
#ifdef SAPPHIRE
    {54, 54, SPECIES_BANETTE},
    {56, 56, SPECIES_BANETTE},
#else
    {54, 54, SPECIES_DUSCLOPS},
    {56, 56, SPECIES_DUSCLOPS},
#endif
    {55, 55, SPECIES_CLAYDOL},
    {56, 56, SPECIES_CLAYDOL},
    {57, 57, SPECIES_ALTARIA},
    {54, 54, SPECIES_ALTARIA},
    {60, 60, SPECIES_ALTARIA},
};
const struct WildPokemonInfo SkyPillar_5F_LandMonsInfo = {10, SkyPillar_5F_LandMons};

const struct WildPokemon Route101_LandMons [] =
{
    {2, 3, SPECIES_ZIGZAGOON},
    {2, 3, SPECIES_WURMPLE},
    {2, 3, SPECIES_ZIGZAGOON},
    {2, 3, SPECIES_WURMPLE},
    {2, 3, SPECIES_LEDYBA},
    {2, 3, SPECIES_LEDYBA},
    {2, 3, SPECIES_LEDYBA},
    {2, 3, SPECIES_LEDYBA},
    {2, 3, SPECIES_POOCHYENA},
    {2, 3, SPECIES_POOCHYENA},
    {2, 3, SPECIES_POOCHYENA},
    {2, 3, SPECIES_POOCHYENA},
};
const struct WildPokemonInfo Route101_LandMonsInfo = {20, Route101_LandMons};

const struct WildPokemon Route102_LandMons [] =
{
    {3, 5, SPECIES_ZIGZAGOON},
    {3, 5, SPECIES_POOCHYENA},
    {3, 5, SPECIES_WURMPLE},
    {3, 5, SPECIES_WURMPLE},
    {3, 5, SPECIES_LOTAD},
    {3, 5, SPECIES_SEEDOT},
    {3, 5, SPECIES_PSYDUCK},
    {3, 5, SPECIES_PSYDUCK},
    {3, 5, SPECIES_TAILLOW},
    {3, 5, SPECIES_RALTS},
    {3, 5, SPECIES_SURSKIT},
    {3, 5, SPECIES_SURSKIT},
};
const struct WildPokemonInfo Route102_LandMonsInfo = {20, Route102_LandMons};

const struct WildPokemon Route103_LandMons [] =
{
    {2, 4, SPECIES_ZIGZAGOON},
    {2, 4, SPECIES_POOCHYENA},
    {2, 4, SPECIES_ZIGZAGOON},
    {2, 4, SPECIES_POOCHYENA},
    {2, 4, SPECIES_LEDYBA},
    {2, 4, SPECIES_LEDYBA},
    {2, 4, SPECIES_HOPPIP},
    {2, 4, SPECIES_HOPPIP},
    {2, 4, SPECIES_WINGULL},
    {2, 4, SPECIES_WINGULL},
    {2, 4, SPECIES_WINGULL},
    {2, 4, SPECIES_WINGULL},
};
const struct WildPokemonInfo Route103_LandMonsInfo = {20, Route103_LandMons};

const struct WildPokemon Route103_AltLandMons [] =
{
    {14, 16, SPECIES_RATTATA},
    {14, 16, SPECIES_MAREEP},
    {14, 16, SPECIES_ZIGZAGOON},
    {14, 16, SPECIES_WINGULL},
    {14, 16, SPECIES_LEDYBA},
    {14, 16, SPECIES_HOPPIP},
    {14, 16, SPECIES_ZIGZAGOON},
    {14, 16, SPECIES_WINGULL},
    {14, 16, SPECIES_LEDYBA},
    {14, 16, SPECIES_ABRA},
    {14, 16, SPECIES_LEDYBA},
    {14, 16, SPECIES_ABRA},
};
const struct WildPokemonInfo Route103_AltLandMonsInfo = {20, Route103_AltLandMons};

const struct WildPokemon Route104_LandMons [] =
{
    {4, 6, SPECIES_ZIGZAGOON},
    {4, 6, SPECIES_POOCHYENA},
    {4, 6, SPECIES_WURMPLE},
    {4, 6, SPECIES_WURMPLE},
    {4, 6, SPECIES_HOPPIP},
    {4, 6, SPECIES_TAILLOW},
    {4, 6, SPECIES_BELLSPROUT},
    {4, 6, SPECIES_AZURILL},
    {4, 6, SPECIES_WINGULL},
    {4, 6, SPECIES_WINGULL},
    {4, 6, SPECIES_WINGULL},
    {4, 6, SPECIES_WINGULL},
};
const struct WildPokemonInfo Route104_LandMonsInfo = {20, Route104_LandMons};

const struct WildPokemon Route104_AltLandMons [] =
{
    {7, 9, SPECIES_ZIGZAGOON},
    {7, 9, SPECIES_BELLSPROUT},
    {7, 9, SPECIES_LEDYBA},
    {7, 9, SPECIES_TAILLOW},
    {7, 9, SPECIES_LOTAD},
    {7, 9, SPECIES_SHROOMISH},
    {7, 9, SPECIES_ZIGZAGOON},
    {7, 9, SPECIES_LEDYBA},
    {7, 9, SPECIES_SHROOMISH},
    {7, 9, SPECIES_SKITTY},
    {7, 9, SPECIES_SHROOMISH},
    {7, 9, SPECIES_SKITTY},
};
const struct WildPokemonInfo Route104_AltLandMonsInfo = {20, Route104_AltLandMons};

const struct WildPokemon Route107_LandMons [] =
{
    {10, 12, SPECIES_PIDGEY},
    {10, 12, SPECIES_WINGULL},
    {10, 12, SPECIES_EKANS},
    {10, 12, SPECIES_SLOWPOKE},
    {10, 12, SPECIES_KRABBY},
    {10, 12, SPECIES_MAKUHITA},
    {10, 12, SPECIES_PIDGEY},
    {10, 12, SPECIES_EKANS},
    {10, 12, SPECIES_HOPPIP},
    {10, 12, SPECIES_HOPPIP},
    {10, 12, SPECIES_HOPPIP},
    {10, 12, SPECIES_HOPPIP},
};
const struct WildPokemonInfo Route107_LandMonsInfo = {20, Route107_LandMons};

const struct WildPokemon Route110_AltLandMons [] =
{
    {12, 15, SPECIES_WINGULL},
    {12, 15, SPECIES_ELECTRIKE},
    {12, 15, SPECIES_GULPIN},
    {12, 15, SPECIES_ODDISH},
    {12, 15, SPECIES_PLUSLE},
    {12, 15, SPECIES_MINUN},
    {12, 15, SPECIES_GULPIN},
    {12, 15, SPECIES_ODDISH},
    {12, 15, SPECIES_RATTATA},
    {12, 15, SPECIES_RATTATA},
    {12, 15, SPECIES_RATTATA},
    {12, 15, SPECIES_RATTATA},
};
const struct WildPokemonInfo Route110_AltLandMonsInfo = {20, Route110_AltLandMons};

const struct WildPokemon Route110_LandMons [] =
{
    {14, 16, SPECIES_RATTATA},
    {14, 16, SPECIES_ELECTRIKE},
    {14, 16, SPECIES_GULPIN},
    {14, 16, SPECIES_ODDISH},
    {14, 16, SPECIES_PLUSLE},
    {14, 16, SPECIES_MINUN},
    {14, 16, SPECIES_GULPIN},
    {14, 16, SPECIES_ODDISH},
    {14, 16, SPECIES_WINGULL},
    {14, 16, SPECIES_WINGULL},
    {14, 16, SPECIES_WINGULL},
    {14, 16, SPECIES_WINGULL},
};
const struct WildPokemonInfo Route110_LandMonsInfo = {20, Route110_LandMons};

const struct WildPokemon Route111_LandMons [] =
{
    {22, 25, SPECIES_SANDSHREW},
    {22, 25, SPECIES_TRAPINCH},
    {22, 25, SPECIES_CACNEA},
    {22, 25, SPECIES_BALTOY},
    {22, 25, SPECIES_DIGLETT},
    {22, 25, SPECIES_GLIGAR},
    {22, 25, SPECIES_CACNEA},
    {22, 25, SPECIES_LARVITAR},
    {22, 25, SPECIES_SANDSHREW},
    {22, 25, SPECIES_TRAPINCH},
    {22, 25, SPECIES_SANDSHREW},
    {22, 25, SPECIES_TRAPINCH},
};
const struct WildPokemonInfo Route111_LandMonsInfo = {10, Route111_LandMons};

const struct WildPokemon Route111_RockSmashMons [] =
{
    {10, 15, SPECIES_GEODUDE},
    {5, 10, SPECIES_GEODUDE},
    {15, 20, SPECIES_GEODUDE},
    {15, 20, SPECIES_GEODUDE},
    {15, 20, SPECIES_GEODUDE},
};
const struct WildPokemonInfo Route111_RockSmashMonsInfo = {20, Route111_RockSmashMons};

const struct WildPokemon Route111_AltLandMons [] =
{
    {15, 18, SPECIES_RATTATA},
    {15, 18, SPECIES_CACNEA},
    {15, 18, SPECIES_MACHOP},
    {15, 18, SPECIES_SANDSHREW},
    {15, 18, SPECIES_SLUGMA},
    {15, 18, SPECIES_ODDISH},
    {15, 18, SPECIES_RATTATA},
    {15, 18, SPECIES_CACNEA},
    {15, 18, SPECIES_MACHOP},
    {15, 18, SPECIES_SANDSHREW},
    {15, 18, SPECIES_MACHOP},
    {15, 18, SPECIES_SANDSHREW},
};
const struct WildPokemonInfo Route111_AltLandMonsInfo = {10, Route111_AltLandMons};

const struct WildPokemon Route112_LandMons [] =
{
    {16, 19, SPECIES_MACHOP},
    {16, 19, SPECIES_NUMEL},
    {16, 19, SPECIES_MACHOP},
    {16, 19, SPECIES_NUMEL},
    {16, 19, SPECIES_SLUGMA},
    {16, 19, SPECIES_PONYTA},
    {16, 19, SPECIES_SLUGMA},
    {16, 19, SPECIES_PONYTA},
    {16, 19, SPECIES_TYROGUE},
    {16, 19, SPECIES_TYROGUE},
    {16, 19, SPECIES_TYROGUE},
    {16, 19, SPECIES_TYROGUE},
};
const struct WildPokemonInfo Route112_LandMonsInfo = {20, Route112_LandMons};

const struct WildPokemon Route113_LandMons [] =
{
    {18, 20, SPECIES_SPINDA},
    {18, 20, SPECIES_SPINDA},
    {18, 20, SPECIES_SPINDA},
    {18, 20, SPECIES_SLUGMA},
    {18, 20, SPECIES_SANDSHREW},
    {18, 20, SPECIES_VENONAT},
    {18, 20, SPECIES_SLUGMA},
    {18, 20, SPECIES_SANDSHREW},
    {18, 20, SPECIES_VENONAT},
    {18, 20, SPECIES_SKARMORY},
    {18, 20, SPECIES_VENONAT},
    {18, 20, SPECIES_SKARMORY},
};
const struct WildPokemonInfo Route113_LandMonsInfo = {20, Route113_LandMons};

const struct WildPokemon Route114_LandMons [] =
{
    {19, 21, SPECIES_LOMBRE},
    {19, 21, SPECIES_NUZLEAF},
    {19, 21, SPECIES_SWABLU},
    {19, 21, SPECIES_SUNKERN},
    {19, 21, SPECIES_ZANGOOSE},
    {19, 21, SPECIES_SEVIPER},
    {19, 21, SPECIES_SWABLU},
    {19, 21, SPECIES_SUNKERN},
    {19, 21, SPECIES_FURRET},
    {19, 21, SPECIES_MISDREAVUS},
    {19, 21, SPECIES_FURRET},
    {19, 21, SPECIES_MISDREAVUS},
};
const struct WildPokemonInfo Route114_LandMonsInfo = {20, Route114_LandMons};

const struct WildPokemon Route114_RockSmashMons [] =
{
    {10, 15, SPECIES_GEODUDE},
    {5, 10, SPECIES_GEODUDE},
    {15, 20, SPECIES_GEODUDE},
    {15, 20, SPECIES_GEODUDE},
    {15, 20, SPECIES_GEODUDE},
};
const struct WildPokemonInfo Route114_RockSmashMonsInfo = {20, Route114_RockSmashMons};

const struct WildPokemon Route115_LandMons [] =
{
    {24, 28, SPECIES_SWABLU},
    {24, 28, SPECIES_WINGULL},
    {24, 28, SPECIES_SWABLU},
    {24, 28, SPECIES_WINGULL},
    {24, 28, SPECIES_JIGGLYPUFF},
    {24, 28, SPECIES_CLEFAIRY},
    {24, 28, SPECIES_SEVIPER},
    {24, 28, SPECIES_ZANGOOSE},
    {24, 28, SPECIES_JIGGLYPUFF},
    {24, 28, SPECIES_FARFETCHD},
    {24, 28, SPECIES_JIGGLYPUFF},
    {24, 28, SPECIES_FARFETCHD},
};
const struct WildPokemonInfo Route115_LandMonsInfo = {20, Route115_LandMons};

const struct WildPokemon Route116_LandMons [] =
{
    {7, 10, SPECIES_SENTRET},
    {7, 10, SPECIES_TAILLOW},
    {7, 10, SPECIES_WHISMUR},
    {7, 10, SPECIES_NINCADA},
    {7, 10, SPECIES_MANKEY},
    {7, 10, SPECIES_ABRA},
    {7, 10, SPECIES_WHISMUR},
    {7, 10, SPECIES_NINCADA},
    {7, 10, SPECIES_SENTRET},
    {7, 10, SPECIES_SKITTY},
    {7, 10, SPECIES_SENTRET},
    {7, 10, SPECIES_SKITTY},
};
const struct WildPokemonInfo Route116_LandMonsInfo = {20, Route116_LandMons};

const struct WildPokemon Route117_LandMons [] =
{
    {15, 17, SPECIES_RATTATA},
    {15, 17, SPECIES_ODDISH},
    {15, 17, SPECIES_MAREEP},
    {15, 17, SPECIES_MAREEP},
    {15, 17, SPECIES_VOLBEAT},
    {15, 17, SPECIES_ILLUMISE},
    {15, 17, SPECIES_ROSELIA},
    {15, 17, SPECIES_ROSELIA},
    {15, 17, SPECIES_MARILL},
    {15, 17, SPECIES_MIME_JR},
    {15, 17, SPECIES_MARILL},
    {15, 17, SPECIES_MIME_JR},
};
const struct WildPokemonInfo Route117_LandMonsInfo = {20, Route117_LandMons};

const struct WildPokemon Route118_LandMons [] =
{
    {24, 24, SPECIES_ZIGZAGOON},
    {24, 24, SPECIES_ELECTRIKE},
    {26, 26, SPECIES_ZIGZAGOON},
    {26, 26, SPECIES_ELECTRIKE},
    {26, 26, SPECIES_LINOONE},
    {26, 26, SPECIES_MANECTRIC},
    {25, 25, SPECIES_WINGULL},
    {25, 25, SPECIES_WINGULL},
    {26, 26, SPECIES_WINGULL},
    {26, 26, SPECIES_WINGULL},
    {27, 27, SPECIES_WINGULL},
    {25, 25, SPECIES_KECLEON},
};
const struct WildPokemonInfo Route118_LandMonsInfo = {20, Route118_LandMons};

const struct WildPokemon Route119_LandMons [] =
{
    {25, 25, SPECIES_ZIGZAGOON},
    {25, 25, SPECIES_LINOONE},
    {27, 27, SPECIES_ZIGZAGOON},
    {25, 25, SPECIES_ODDISH},
    {27, 27, SPECIES_LINOONE},
    {26, 26, SPECIES_ODDISH},
    {27, 27, SPECIES_ODDISH},
    {24, 24, SPECIES_ODDISH},
    {25, 25, SPECIES_TROPIUS},
    {26, 26, SPECIES_TROPIUS},
    {27, 27, SPECIES_TROPIUS},
    {25, 25, SPECIES_KECLEON},
};
const struct WildPokemonInfo Route119_LandMonsInfo = {15, Route119_LandMons};

const struct WildPokemon Route120_LandMons [] =
{
    {25, 25, SPECIES_ZIGZAGOON},
    {25, 25, SPECIES_LINOONE},
    {27, 27, SPECIES_LINOONE},
    {25, 25, SPECIES_ODDISH},
    {25, 25, SPECIES_MARILL},
    {26, 26, SPECIES_ODDISH},
    {27, 27, SPECIES_ODDISH},
    {27, 27, SPECIES_MARILL},
    {25, 25, SPECIES_ABSOL},
    {27, 27, SPECIES_ABSOL},
    {25, 25, SPECIES_KECLEON},
    {25, 25, SPECIES_SURSKIT},
};
const struct WildPokemonInfo Route120_LandMonsInfo = {20, Route120_LandMons};

const struct WildPokemon Route121_LandMons [] =
{
    {26, 26, SPECIES_ZIGZAGOON},
#ifdef SAPPHIRE
    {26, 26, SPECIES_SHUPPET},
#else
    {26, 26, SPECIES_DUSKULL},
#endif
    {26, 26, SPECIES_LINOONE},
#ifdef SAPPHIRE
    {28, 28, SPECIES_SHUPPET},
#else
    {28, 28, SPECIES_DUSKULL},
#endif
    {28, 28, SPECIES_LINOONE},
    {26, 26, SPECIES_ODDISH},
    {28, 28, SPECIES_ODDISH},
    {28, 28, SPECIES_GLOOM},
    {26, 26, SPECIES_WINGULL},
    {27, 27, SPECIES_WINGULL},
    {28, 28, SPECIES_WINGULL},
    {25, 25, SPECIES_KECLEON},
};
const struct WildPokemonInfo Route121_LandMonsInfo = {20, Route121_LandMons};

const struct WildPokemon Route123_LandMons [] =
{
    {26, 26, SPECIES_ZIGZAGOON},
#ifdef SAPPHIRE
    {26, 26, SPECIES_SHUPPET},
#else
    {26, 26, SPECIES_DUSKULL},
#endif
    {26, 26, SPECIES_LINOONE},
#ifdef SAPPHIRE
    {28, 28, SPECIES_SHUPPET},
#else
    {28, 28, SPECIES_DUSKULL},
#endif
    {28, 28, SPECIES_LINOONE},
    {26, 26, SPECIES_ODDISH},
    {28, 28, SPECIES_ODDISH},
    {28, 28, SPECIES_GLOOM},
    {26, 26, SPECIES_WINGULL},
    {27, 27, SPECIES_WINGULL},
    {28, 28, SPECIES_WINGULL},
    {25, 25, SPECIES_KECLEON},
};
const struct WildPokemonInfo Route123_LandMonsInfo = {20, Route123_LandMons};

const struct WildPokemon Route130_LandMons [] =
{
    {30, 30, SPECIES_WYNAUT},
    {35, 35, SPECIES_WYNAUT},
    {25, 25, SPECIES_WYNAUT},
    {40, 40, SPECIES_WYNAUT},
    {20, 20, SPECIES_WYNAUT},
    {45, 45, SPECIES_WYNAUT},
    {15, 15, SPECIES_WYNAUT},
    {50, 50, SPECIES_WYNAUT},
    {10, 10, SPECIES_WYNAUT},
    {5, 5, SPECIES_WYNAUT},
    {10, 10, SPECIES_WYNAUT},
    {5, 5, SPECIES_WYNAUT},
};
const struct WildPokemonInfo Route130_LandMonsInfo = {20, Route130_LandMons};

const struct WildPokemon SafariZone_Northwest_LandMons [] =
{
    {27, 27, SPECIES_RHYHORN},
    {27, 27, SPECIES_ODDISH},
    {29, 29, SPECIES_RHYHORN},
    {29, 29, SPECIES_ODDISH},
    {27, 27, SPECIES_DODUO},
    {29, 29, SPECIES_GLOOM},
    {31, 31, SPECIES_GLOOM},
    {29, 29, SPECIES_DODUO},
    {29, 29, SPECIES_DODRIO},
    {27, 27, SPECIES_PINSIR},
    {31, 31, SPECIES_DODRIO},
    {29, 29, SPECIES_PINSIR},
};
const struct WildPokemonInfo SafariZone_Northwest_LandMonsInfo = {25, SafariZone_Northwest_LandMons};

const struct WildPokemon SafariZone_Northeast_LandMons [] =
{
    {27, 27, SPECIES_PHANPY},
    {27, 27, SPECIES_ODDISH},
    {29, 29, SPECIES_PHANPY},
    {29, 29, SPECIES_ODDISH},
    {27, 27, SPECIES_NATU},
    {29, 29, SPECIES_GLOOM},
    {31, 31, SPECIES_GLOOM},
    {29, 29, SPECIES_NATU},
    {29, 29, SPECIES_XATU},
    {27, 27, SPECIES_HERACROSS},
    {31, 31, SPECIES_XATU},
    {29, 29, SPECIES_HERACROSS},
};
const struct WildPokemonInfo SafariZone_Northeast_LandMonsInfo = {25, SafariZone_Northeast_LandMons};

const struct WildPokemon SafariZone_Northeast_RockSmashMons [] =
{
    {10, 15, SPECIES_GEODUDE},
    {5, 10, SPECIES_GEODUDE},
    {15, 20, SPECIES_GEODUDE},
    {20, 25, SPECIES_GEODUDE},
    {25, 30, SPECIES_GEODUDE},
};
const struct WildPokemonInfo SafariZone_Northeast_RockSmashMonsInfo = {25, SafariZone_Northeast_RockSmashMons};

const struct WildPokemon SafariZone_Southwest_LandMons [] =
{
    {25, 25, SPECIES_ODDISH},
    {27, 27, SPECIES_ODDISH},
    {25, 25, SPECIES_GIRAFARIG},
    {27, 27, SPECIES_GIRAFARIG},
    {25, 25, SPECIES_NATU},
    {25, 27, SPECIES_DODUO},
    {25, 25, SPECIES_GLOOM},
    {27, 27, SPECIES_WOBBUFFET},
    {25, 25, SPECIES_PIKACHU},
    {27, 27, SPECIES_WOBBUFFET},
    {27, 27, SPECIES_PIKACHU},
    {29, 29, SPECIES_WOBBUFFET},
};
const struct WildPokemonInfo SafariZone_Southwest_LandMonsInfo = {25, SafariZone_Southwest_LandMons};

const struct WildPokemon SafariZone_Southeast_LandMons [] =
{
    {25, 25, SPECIES_ODDISH},
    {27, 27, SPECIES_ODDISH},
    {25, 25, SPECIES_GIRAFARIG},
    {27, 27, SPECIES_GIRAFARIG},
    {25, 25, SPECIES_NATU},
    {25, 25, SPECIES_DODUO},
    {25, 25, SPECIES_GLOOM},
    {27, 27, SPECIES_WOBBUFFET},
    {25, 25, SPECIES_PIKACHU},
    {27, 27, SPECIES_WOBBUFFET},
    {27, 27, SPECIES_PIKACHU},
    {29, 29, SPECIES_WOBBUFFET},
};
const struct WildPokemonInfo SafariZone_Southeast_LandMonsInfo = {25, SafariZone_Southeast_LandMons};

const struct WildPokemon Underwater1_WaterMons [] =
{
    {20, 30, SPECIES_CLAMPERL},
    {20, 30, SPECIES_CHINCHOU},
    {30, 35, SPECIES_CLAMPERL},
    {30, 35, SPECIES_RELICANTH},
    {30, 35, SPECIES_RELICANTH},
};
const struct WildPokemonInfo Underwater1_WaterMonsInfo = {4, Underwater1_WaterMons};

const struct WildPokemon Underwater2_WaterMons [] =
{
    {20, 30, SPECIES_CLAMPERL},
    {20, 30, SPECIES_CHINCHOU},
    {30, 35, SPECIES_CLAMPERL},
    {30, 35, SPECIES_RELICANTH},
    {30, 35, SPECIES_RELICANTH},
};
const struct WildPokemonInfo Underwater2_WaterMonsInfo = {4, Underwater2_WaterMons};

const struct WildPokemon GnarledRidge_LandMons [] =
{
    {10, 11, SPECIES_SPEAROW},
    {10, 11, SPECIES_SENTRET},
    {10, 11, SPECIES_MANKEY},
    {10, 11, SPECIES_NINCADA},
    {10, 11, SPECIES_CUBONE},
    {10, 11, SPECIES_TEDDIURSA},
    {10, 11, SPECIES_MANKEY},
    {10, 11, SPECIES_SLUGMA},
    {10, 11, SPECIES_NIDORAN_M},
    {10, 11, SPECIES_NIDORAN_F},
    {10, 11, SPECIES_NIDORAN_M},
    {10, 11, SPECIES_NIDORAN_F},
};
const struct WildPokemonInfo GnarledRidge_LandMonsInfo = {20, GnarledRidge_LandMons};


const struct WildPokemonHeader gWildMonHeaders[] =
{
    {
        .mapGroup = MAP_GROUP(PETALBURG_CITY),
        .mapNum = MAP_NUM(PETALBURG_CITY),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL, //&PetalburgCity_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &PetalburgLakeRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SLATEPORT_CITY),
        .mapNum = MAP_NUM(SLATEPORT_CITY),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL, //&SlateportCity_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &PacifidlogSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(LILYCOVE_CITY),
        .mapNum = MAP_NUM(LILYCOVE_CITY),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL, //&LilycoveCity_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &LilycoveSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(MOSSDEEP_CITY),
        .mapNum = MAP_NUM(MOSSDEEP_CITY),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL, //&MossdeepCity_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &LilycoveSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SOOTOPOLIS_CITY),
        .mapNum = MAP_NUM(SOOTOPOLIS_CITY),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL, //&SootopolisCity_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &SootopolisCity_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(EVER_GRANDE_CITY),
        .mapNum = MAP_NUM(EVER_GRANDE_CITY),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL, //&EverGrandeCity_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &LilycoveSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(METEOR_FALLS_1F_1R),
        .mapNum = MAP_NUM(METEOR_FALLS_1F_1R),
        .landMonsInfo = &MeteorFalls_1F_1R_LandMonsInfo,
        .waterMonsInfo = NULL, //&MeteorFalls_1F_1R_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &MeteorFallsInterior_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(METEOR_FALLS_1F_2R),
        .mapNum = MAP_NUM(METEOR_FALLS_1F_2R),
        .landMonsInfo = &MeteorFalls_1F_2R_LandMonsInfo,
        .waterMonsInfo = NULL, //&MeteorFalls_1F_2R_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &MeteorFallsInterior_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(METEOR_FALLS_B1F_1R),
        .mapNum = MAP_NUM(METEOR_FALLS_B1F_1R),
        .landMonsInfo = &MeteorFalls_B1F_1R_LandMonsInfo,
        .waterMonsInfo = NULL, //&MeteorFalls_B1F_1R_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &MeteorFallsInterior_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(METEOR_FALLS_B1F_2R),
        .mapNum = MAP_NUM(METEOR_FALLS_B1F_2R),
        .landMonsInfo = &MeteorFalls_B1F_2R_LandMonsInfo,
        .waterMonsInfo = NULL, //&MeteorFalls_B1F_2R_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &MeteorFallsInterior_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(RUSTURF_TUNNEL),
        .mapNum = MAP_NUM(RUSTURF_TUNNEL),
        .landMonsInfo = &RusturfTunnel_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(GRANITE_CAVE_1F),
        .mapNum = MAP_NUM(GRANITE_CAVE_1F),
        .landMonsInfo = &GraniteCave_1F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(GRANITE_CAVE_B1F),
        .mapNum = MAP_NUM(GRANITE_CAVE_B1F),
        .landMonsInfo = &GraniteCave_B1F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(GRANITE_CAVE_B2F),
        .mapNum = MAP_NUM(GRANITE_CAVE_B2F),
        .landMonsInfo = &GraniteCave_B2F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = &GraniteCave_B2F_RockSmashMonsInfo,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(GRANITE_CAVE_B3F),
        .mapNum = MAP_NUM(GRANITE_CAVE_B3F),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = &GraniteCave_B4F_RockSmashMonsInfo,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(GRANITE_CAVE_B4F),
        .mapNum = MAP_NUM(GRANITE_CAVE_B4F),
        .landMonsInfo = &GraniteCave_B4F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = &GraniteCave_B4F_RockSmashMonsInfo,
        .fishingMonsInfo = &GraniteCaveInterior_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(GRANITE_CAVE_STAIRS),
        .mapNum = MAP_NUM(GRANITE_CAVE_STAIRS),
        .landMonsInfo = &GraniteCave_B4F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = &GraniteCave_B4F_RockSmashMonsInfo,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(GRANITE_CAVE_STEVENS_ROOM),
        .mapNum = MAP_NUM(GRANITE_CAVE_STEVENS_ROOM),
        .landMonsInfo = &GraniteCave_StevensRoom_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(PETALBURG_WOODS),
        .mapNum = MAP_NUM(PETALBURG_WOODS),
        .landMonsInfo = &PetalburgWoods_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
        .altXLow = 29,
        .altYLow = 3,
        .altXHigh = 46,
        .altYHigh = 31,
        .altLandMonsInfo = &PetalburgWoods_AltLandMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(JAGGED_PASS),
        .mapNum = MAP_NUM(JAGGED_PASS),
        .landMonsInfo = &JaggedPass_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIERY_PATH),
        .mapNum = MAP_NUM(FIERY_PATH),
        .landMonsInfo = &FieryPath_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_1F),
        .mapNum = MAP_NUM(MT_PYRE_1F),
        .landMonsInfo = &MtPyre_1F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_2F),
        .mapNum = MAP_NUM(MT_PYRE_2F),
        .landMonsInfo = &MtPyre_2F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_3F),
        .mapNum = MAP_NUM(MT_PYRE_3F),
        .landMonsInfo = &MtPyre_3F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_4F),
        .mapNum = MAP_NUM(MT_PYRE_4F),
        .landMonsInfo = &MtPyre_4F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_5F),
        .mapNum = MAP_NUM(MT_PYRE_5F),
        .landMonsInfo = &MtPyre_5F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_6F),
        .mapNum = MAP_NUM(MT_PYRE_6F),
        .landMonsInfo = &MtPyre_6F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_EXTERIOR),
        .mapNum = MAP_NUM(MT_PYRE_EXTERIOR),
        .landMonsInfo = &MtPyre_Exterior_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_SUMMIT),
        .mapNum = MAP_NUM(MT_PYRE_SUMMIT),
        .landMonsInfo = &MtPyre_Summit_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ENTRANCE),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ENTRANCE),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL, //&SeafloorCavern_Entrance_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &LilycoveSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM1),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM1),
        .landMonsInfo = &SeafloorCavern_Room1_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM2),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM2),
        .landMonsInfo = &SeafloorCavern_Room2_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM3),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM3),
        .landMonsInfo = &SeafloorCavern_Room3_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM4),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM4),
        .landMonsInfo = &SeafloorCavern_Room4_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM5),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM5),
        .landMonsInfo = &SeafloorCavern_Room5_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM6),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM6),
        .landMonsInfo = &SeafloorCavern_Room6_LandMonsInfo,
        .waterMonsInfo = NULL, //&SeafloorCavern_Room6_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &SeafloorCavern_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM7),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM7),
        .landMonsInfo = &SeafloorCavern_Room7_LandMonsInfo,
        .waterMonsInfo = NULL, //&SeafloorCavern_Room7_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &SeafloorCavern_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM8),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM8),
        .landMonsInfo = &SeafloorCavern_Room8_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_ENTRANCE),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_ENTRANCE),
        .landMonsInfo = &CaveOfOrigin_Entrance_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_1F),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_1F),
        .landMonsInfo = &CaveOfOrigin_1F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_B1F),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_B1F),
        .landMonsInfo = &CaveOfOrigin_B1F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_B2F),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_B2F),
        .landMonsInfo = &CaveOfOrigin_B2F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_B3F),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_B3F),
        .landMonsInfo = &CaveOfOrigin_B3F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(VICTORY_ROAD_1F),
        .mapNum = MAP_NUM(VICTORY_ROAD_1F),
        .landMonsInfo = &VictoryRoad_1F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(VICTORY_ROAD_B1F),
        .mapNum = MAP_NUM(VICTORY_ROAD_B1F),
        .landMonsInfo = &VictoryRoad_B1F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = &VictoryRoad_B1F_RockSmashMonsInfo,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(VICTORY_ROAD_B2F),
        .mapNum = MAP_NUM(VICTORY_ROAD_B2F),
        .landMonsInfo = &VictoryRoad_B2F_LandMonsInfo,
        .waterMonsInfo = NULL, //&VictoryRoad_B2F_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &MeteorFallsInterior_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM),
        .landMonsInfo = &ShoalCave_LowTideEntranceRoom_LandMonsInfo,
        .waterMonsInfo = NULL, //&ShoalCave_LowTideEntranceRoom_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &LilycoveSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_INNER_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_INNER_ROOM),
        .landMonsInfo = &ShoalCave_LowTideInnerRoom_LandMonsInfo,
        .waterMonsInfo = NULL, //&ShoalCave_LowTideInnerRoom_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &LilycoveSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_STAIRS_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_STAIRS_ROOM),
        .landMonsInfo = &ShoalCave_LowTideStairsRoom_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_LOWER_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_LOWER_ROOM),
        .landMonsInfo = &ShoalCave_LowTideLowerRoom_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_ICE_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_ICE_ROOM),
        .landMonsInfo = &ShoalCave_LowTideIceRoom_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(NEW_MAUVILLE_ENTRANCE),
        .mapNum = MAP_NUM(NEW_MAUVILLE_ENTRANCE),
        .landMonsInfo = &NewMauville_Entrance_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(NEW_MAUVILLE_INSIDE),
        .mapNum = MAP_NUM(NEW_MAUVILLE_INSIDE),
        .landMonsInfo = &NewMauville_Inside_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ABANDONED_SHIP_ROOMS_B1F),
        .mapNum = MAP_NUM(ABANDONED_SHIP_ROOMS_B1F),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL, //&AbandonedShip_Rooms_B1F_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &DewfordSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS),
        .mapNum = MAP_NUM(ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL, //&AbandonedShip_HiddenFloorCorridors_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &DewfordSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SKY_PILLAR_1F),
        .mapNum = MAP_NUM(SKY_PILLAR_1F),
        .landMonsInfo = &SkyPillar_1F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SKY_PILLAR_3F),
        .mapNum = MAP_NUM(SKY_PILLAR_3F),
        .landMonsInfo = &SkyPillar_3F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SKY_PILLAR_5F),
        .mapNum = MAP_NUM(SKY_PILLAR_5F),
        .landMonsInfo = &SkyPillar_5F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE101),
        .mapNum = MAP_NUM(ROUTE101),
        .landMonsInfo = &Route101_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE102),
        .mapNum = MAP_NUM(ROUTE102),
        .landMonsInfo = &Route102_LandMonsInfo,
        .waterMonsInfo = NULL, //&Route102_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &PetalburgLakeRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE103),
        .mapNum = MAP_NUM(ROUTE103),
        .landMonsInfo = &Route103_LandMonsInfo,
        .waterMonsInfo = NULL, //&Route103_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &DewfordSeaRegion_FishingMonsInfo,
        .altXLow = 61,
        .altYLow = 4,
        .altXHigh = 66,
        .altYHigh = 8,
        .altLandMonsInfo = &Route103_AltLandMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE104),
        .mapNum = MAP_NUM(ROUTE104),
        .landMonsInfo = &Route104_LandMonsInfo,
        .waterMonsInfo = NULL, //&Route104_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &SootopolisCity_FishingMonsInfo,
        .altXLow = 1,
        .altYLow = 3,
        .altXHigh = 10,
        .altYHigh = 13,
        .altLandMonsInfo = &Route104_AltLandMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE105),
        .mapNum = MAP_NUM(ROUTE105),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL, //&Route105_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &DewfordSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE106),
        .mapNum = MAP_NUM(ROUTE106),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL, //&Route106_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &DewfordSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE107),
        .mapNum = MAP_NUM(ROUTE107),
        .landMonsInfo = &Route107_LandMonsInfo,
        .waterMonsInfo = NULL, //&Route107_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &DewfordSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE108),
        .mapNum = MAP_NUM(ROUTE108),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL, //&Route108_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &DewfordSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE109),
        .mapNum = MAP_NUM(ROUTE109),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL, //&Route109_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &DewfordSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE110),
        .mapNum = MAP_NUM(ROUTE110),
        .landMonsInfo = &Route110_LandMonsInfo,
        .waterMonsInfo = NULL, //&Route110_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &PacifidlogSeaRegion_FishingMonsInfo,
        .altXLow = 8,
        .altYLow = 92,
        .altXHigh = 15,
        .altYHigh = 98,
        .altLandMonsInfo = &Route110_AltLandMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE111),
        .mapNum = MAP_NUM(ROUTE111),
        .landMonsInfo = &Route111_LandMonsInfo,
        .waterMonsInfo = NULL, //&Route111_WaterMonsInfo,
        .rockSmashMonsInfo = &Route111_RockSmashMonsInfo,
        .fishingMonsInfo = &MauvilleLakeRegion_FishingMonsInfo,
        .altXLow = 22,
        .altYLow = 112,
        .altXHigh = 28,
        .altYHigh = 118,
        .altLandMonsInfo = &Route111_AltLandMonsInfo
    },
    {
        .mapGroup = MAP_GROUP(ROUTE112),
        .mapNum = MAP_NUM(ROUTE112),
        .landMonsInfo = &Route112_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE113),
        .mapNum = MAP_NUM(ROUTE113),
        .landMonsInfo = &Route113_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE114),
        .mapNum = MAP_NUM(ROUTE114),
        .landMonsInfo = &Route114_LandMonsInfo,
        .waterMonsInfo = NULL, //&Route114_WaterMonsInfo,
        .rockSmashMonsInfo = &Route114_RockSmashMonsInfo,
        .fishingMonsInfo = &FallarborFortreeLakeRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE115),
        .mapNum = MAP_NUM(ROUTE115),
        .landMonsInfo = &Route115_LandMonsInfo,
        .waterMonsInfo = NULL, //&Route115_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &RustboroSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE116),
        .mapNum = MAP_NUM(ROUTE116),
        .landMonsInfo = &Route116_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE117),
        .mapNum = MAP_NUM(ROUTE117),
        .landMonsInfo = &Route117_LandMonsInfo,
        .waterMonsInfo = NULL, //&Route117_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &MauvilleLakeRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE118),
        .mapNum = MAP_NUM(ROUTE118),
        .landMonsInfo = &Route118_LandMonsInfo,
        .waterMonsInfo = NULL, //&Route118_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &JungleRiverRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE119),
        .mapNum = MAP_NUM(ROUTE119),
        .landMonsInfo = &Route119_LandMonsInfo,
        .waterMonsInfo = NULL, //&Route119_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &JungleRiverRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE120),
        .mapNum = MAP_NUM(ROUTE120),
        .landMonsInfo = &Route120_LandMonsInfo,
        .waterMonsInfo = NULL, //&Route120_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &FallarborFortreeLakeRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE121),
        .mapNum = MAP_NUM(ROUTE121),
        .landMonsInfo = &Route121_LandMonsInfo,
        .waterMonsInfo = NULL, //&Route121_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &LilycoveSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE122),
        .mapNum = MAP_NUM(ROUTE122),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL, //&Route122_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &LilycoveSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE123),
        .mapNum = MAP_NUM(ROUTE123),
        .landMonsInfo = &Route123_LandMonsInfo,
        .waterMonsInfo = NULL, //&Route123_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &LilycoveSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE124),
        .mapNum = MAP_NUM(ROUTE124),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL, //&Route124_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &LilycoveSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE125),
        .mapNum = MAP_NUM(ROUTE125),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL, //&Route125_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &LilycoveSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE126),
        .mapNum = MAP_NUM(ROUTE126),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL, //&Route126_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &LilycoveSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE127),
        .mapNum = MAP_NUM(ROUTE127),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL, //&Route127_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &LilycoveSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE128),
        .mapNum = MAP_NUM(ROUTE128),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL, //&Route128_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &LilycoveSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE129),
        .mapNum = MAP_NUM(ROUTE129),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL, //&Route129_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &LilycoveSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE130),
        .mapNum = MAP_NUM(ROUTE130),
        .landMonsInfo = &Route130_LandMonsInfo,
        .waterMonsInfo = NULL, //&Route130_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &PacifidlogSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE131),
        .mapNum = MAP_NUM(ROUTE131),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL, //&Route131_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &PacifidlogSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE132),
        .mapNum = MAP_NUM(ROUTE132),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL, //&Route132_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &PacifidlogSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE133),
        .mapNum = MAP_NUM(ROUTE133),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL, //&Route133_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &PacifidlogSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE134),
        .mapNum = MAP_NUM(ROUTE134),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL, //&Route134_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &PacifidlogSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_NORTHWEST),
        .mapNum = MAP_NUM(SAFARI_ZONE_NORTHWEST),
        .landMonsInfo = &SafariZone_Northwest_LandMonsInfo,
        .waterMonsInfo = NULL, //&SafariZone_Northwest_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &SafariZone_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_NORTHEAST),
        .mapNum = MAP_NUM(SAFARI_ZONE_NORTHEAST),
        .landMonsInfo = &SafariZone_Northeast_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = &SafariZone_Northeast_RockSmashMonsInfo,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_SOUTHWEST),
        .mapNum = MAP_NUM(SAFARI_ZONE_SOUTHWEST),
        .landMonsInfo = &SafariZone_Southwest_LandMonsInfo,
        .waterMonsInfo = NULL, //&SafariZone_Southwest_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &SafariZone_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_SOUTHEAST),
        .mapNum = MAP_NUM(SAFARI_ZONE_SOUTHEAST),
        .landMonsInfo = &SafariZone_Southeast_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(DEWFORD_TOWN),
        .mapNum = MAP_NUM(DEWFORD_TOWN),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL, //&DewfordTown_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &DewfordSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(PACIFIDLOG_TOWN),
        .mapNum = MAP_NUM(PACIFIDLOG_TOWN),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL, //&PacifidlogTown_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &PacifidlogSeaRegion_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(UNDERWATER1),
        .mapNum = MAP_NUM(UNDERWATER1),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL, //&Underwater1_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(UNDERWATER2),
        .mapNum = MAP_NUM(UNDERWATER2),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL, //&Underwater2_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(GNARLED_RIDGE),
        .mapNum = MAP_NUM(GNARLED_RIDGE),
        .landMonsInfo = &GnarledRidge_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(UNDEFINED),
        .mapNum = MAP_NUM(UNDEFINED),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
};

#endif //GUARD_DATA_ENCOUNTERS_H