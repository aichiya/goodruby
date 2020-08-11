#include "global.h"
#include "data2.h"
#include "battle_setup.h"
#include "battle.h"
#include "trainer.h"
#include "graphics.h"
#include "gba/types.h"
#include "constants/species.h"
#include "constants/moves.h"
#include "constants/items.h"
#include "constants/opponents.h"

const struct MonCoords gTrainerBackPicCoords[] = {
    {8, 4},
    {8, 4},
    {8, 4},
};

extern const u8 gTrainerBackPic_Brendan[];
extern const u8 gTrainerBackPic_May[];
extern const u8 gTrainerBackPic_Wally[];

const struct CompressedSpriteSheet gTrainerBackPicTable[] = {
    {gTrainerBackPic_Brendan, 0x2000, 0},
    {gTrainerBackPic_May, 0x2000, 1},
    {gTrainerBackPic_Wally, 0x2000, 2}
};

extern const u8 gTrainerPalette_Brendan[];
extern const u8 gTrainerPalette_May[];
extern const u8 gTrainerPalette_Wally[];

const struct CompressedSpritePalette gTrainerBackPicPaletteTable[] = {
    {gTrainerPalette_Brendan, 0},
    {gTrainerPalette_May, 1},
    {gTrainerPalette_Wally, 2}
};

// This determines how much higher above the usual position the enemy Pokémon
// is during battle. Species that float or fly have nonzero values.
const u8 gEnemyMonElevation[] = {
    [0] =  0,

    [SPECIES_BUTTERFREE] = 8,
    [SPECIES_BEEDRILL] = 8,
    [SPECIES_PIDGEOT] = 4,
    [SPECIES_FEAROW] = 6,
    [SPECIES_ZUBAT] = 8,
    [SPECIES_GOLBAT] = 8,
    [SPECIES_VENOMOTH] = 8,
    [SPECIES_GEODUDE] = 16,
    [SPECIES_MAGNEMITE] = 16,
    [SPECIES_MAGNETON] = 8,
    [SPECIES_GASTLY] = 4,
    [SPECIES_HAUNTER] = 4,
    [SPECIES_VOLTORB] = 10,
    [SPECIES_ELECTRODE] = 12,
    [SPECIES_KOFFING] = 8,
    [SPECIES_WEEZING] = 6,
    [SPECIES_AERODACTYL] = 7,
    [SPECIES_ARTICUNO] = 6,
    [SPECIES_ZAPDOS] = 8,
    [SPECIES_MOLTRES] = 5,
    [SPECIES_DRAGONITE] = 6,
    [SPECIES_MEW] = 8,
    [SPECIES_LEDIAN] = 8,
    [SPECIES_CROBAT] = 6,
    [SPECIES_HOPPIP] = 11,
    [SPECIES_SKIPLOOM] = 12,
    [SPECIES_JUMPLUFF] = 9,
    [SPECIES_YANMA] = 8,
    [SPECIES_MISDREAVUS] = 8,
    [SPECIES_UNOWN] = 8,
    [SPECIES_GLIGAR] = 6,
    [SPECIES_MANTINE] = 6,
    [SPECIES_LUGIA] = 6,
    [SPECIES_HO_OH] = 6,
    [SPECIES_CELEBI] = 15,

    [SPECIES_OLD_UNOWN_B] =  0,
    [SPECIES_OLD_UNOWN_C] =  0,
    [SPECIES_OLD_UNOWN_D] =  0,
    [SPECIES_OLD_UNOWN_E] =  0,
    [SPECIES_OLD_UNOWN_F] =  0,
    [SPECIES_OLD_UNOWN_G] =  0,
    [SPECIES_OLD_UNOWN_H] =  0,
    [SPECIES_OLD_UNOWN_I] =  0,
    [SPECIES_OLD_UNOWN_J] =  0,
    [SPECIES_OLD_UNOWN_K] =  0,
    [SPECIES_OLD_UNOWN_L] =  0,
    [SPECIES_OLD_UNOWN_M] =  0,
    [SPECIES_OLD_UNOWN_N] =  0,
    [SPECIES_OLD_UNOWN_O] =  0,
    [SPECIES_OLD_UNOWN_P] =  0,
    [SPECIES_OLD_UNOWN_Q] =  0,
    [SPECIES_OLD_UNOWN_R] =  0,
    [SPECIES_OLD_UNOWN_S] =  0,
    [SPECIES_OLD_UNOWN_T] =  0,
    [SPECIES_OLD_UNOWN_U] =  0,
    [SPECIES_OLD_UNOWN_V] =  0,
    [SPECIES_OLD_UNOWN_W] =  0,
    [SPECIES_OLD_UNOWN_X] =  0,
    [SPECIES_OLD_UNOWN_Y] =  0,
    [SPECIES_OLD_UNOWN_Z] =  0,
    [SPECIES_TREECKO] =  0,
    [SPECIES_GROVYLE] =  0,
    [SPECIES_SCEPTILE] =  0,
    [SPECIES_TORCHIC] =  0,
    [SPECIES_COMBUSKEN] =  0,
    [SPECIES_BLAZIKEN] =  0,
    [SPECIES_MUDKIP] =  0,
    [SPECIES_MARSHTOMP] =  0,
    [SPECIES_SWAMPERT] =  0,
    [SPECIES_POOCHYENA] =  0,
    [SPECIES_MIGHTYENA] =  0,
    [SPECIES_ZIGZAGOON] =  0,
    [SPECIES_LINOONE] =  0,
    [SPECIES_WURMPLE] =  0,
    [SPECIES_SILCOON] =  0,
    [SPECIES_BEAUTIFLY] =  8,
    [SPECIES_CASCOON] =  0,
    [SPECIES_DUSTOX] = 10,
    [SPECIES_LOTAD] =  0,
    [SPECIES_LOMBRE] =  0,
    [SPECIES_LUDICOLO] =  0,
    [SPECIES_SEEDOT] =  0,
    [SPECIES_NUZLEAF] =  0,
    [SPECIES_SHIFTRY] =  0,
    [SPECIES_NINCADA] =  0,
    [SPECIES_NINJASK] = 10,
    [SPECIES_SHEDINJA] =  8,
    [SPECIES_TAILLOW] =  0,
    [SPECIES_SWELLOW] =  0,
    [SPECIES_SHROOMISH] =  0,
    [SPECIES_BRELOOM] =  0,
    [SPECIES_SPINDA] =  0,
    [SPECIES_WINGULL] = 16,
    [SPECIES_PELIPPER] =  8,
    [SPECIES_SURSKIT] =  0,
    [SPECIES_MASQUERAIN] = 10,
    [SPECIES_WAILMER] =  0,
    [SPECIES_WAILORD] =  0,
    [SPECIES_SKITTY] =  0,
    [SPECIES_DELCATTY] =  0,
    [SPECIES_KECLEON] =  0,
    [SPECIES_BALTOY] =  4,
    [SPECIES_CLAYDOL] =  4,
    [SPECIES_NOSEPASS] =  0,
    [SPECIES_TORKOAL] =  0,
    [SPECIES_SABLEYE] =  0,
    [SPECIES_BARBOACH] =  0,
    [SPECIES_WHISCASH] =  0,
    [SPECIES_LUVDISC] =  0,
    [SPECIES_CORPHISH] =  0,
    [SPECIES_CRAWDAUNT] =  0,
    [SPECIES_FEEBAS] =  0,
    [SPECIES_MILOTIC] =  0,
    [SPECIES_CARVANHA] =  0,
    [SPECIES_SHARPEDO] =  0,
    [SPECIES_TRAPINCH] =  0,
    [SPECIES_VIBRAVA] =  0,
    [SPECIES_FLYGON] =  3,
    [SPECIES_MAKUHITA] =  0,
    [SPECIES_HARIYAMA] =  0,
    [SPECIES_ELECTRIKE] =  0,
    [SPECIES_MANECTRIC] =  0,
    [SPECIES_NUMEL] =  0,
    [SPECIES_CAMERUPT] =  0,
    [SPECIES_SPHEAL] =  0,
    [SPECIES_SEALEO] =  0,
    [SPECIES_WALREIN] =  0,
    [SPECIES_CACNEA] =  0,
    [SPECIES_CACTURNE] =  0,
    [SPECIES_SNORUNT] =  0,
    [SPECIES_GLALIE] = 12,
    [SPECIES_LUNATONE] = 13,
    [SPECIES_SOLROCK] =  4,
    [SPECIES_AZURILL] =  0,
    [SPECIES_SPOINK] =  0,
    [SPECIES_GRUMPIG] =  0,
    [SPECIES_PLUSLE] =  0,
    [SPECIES_MINUN] =  0,
    [SPECIES_MAWILE] =  0,
    [SPECIES_MEDITITE] =  0,
    [SPECIES_MEDICHAM] =  0,
    [SPECIES_SWABLU] = 12,
    [SPECIES_ALTARIA] =  8,
    [SPECIES_WYNAUT] =  0,
    [SPECIES_DUSKULL] =  4,
    [SPECIES_DUSCLOPS] =  0,
    [SPECIES_ROSELIA] =  0,
    [SPECIES_SLAKOTH] =  0,
    [SPECIES_VIGOROTH] =  0,
    [SPECIES_SLAKING] =  0,
    [SPECIES_GULPIN] =  0,
    [SPECIES_SWALOT] =  0,
    [SPECIES_TROPIUS] =  0,
    [SPECIES_WHISMUR] =  0,
    [SPECIES_LOUDRED] =  0,
    [SPECIES_EXPLOUD] =  0,
    [SPECIES_CLAMPERL] =  0,
    [SPECIES_HUNTAIL] =  0,
    [SPECIES_GOREBYSS] =  0,
    [SPECIES_ABSOL] =  0,
    [SPECIES_SHUPPET] = 12,
    [SPECIES_BANETTE] =  8,
    [SPECIES_SEVIPER] =  0,
    [SPECIES_ZANGOOSE] =  0,
    [SPECIES_RELICANTH] =  0,
    [SPECIES_ARON] =  0,
    [SPECIES_LAIRON] =  0,
    [SPECIES_AGGRON] =  0,
    [SPECIES_CASTFORM] = 16,
    [SPECIES_VOLBEAT] =  0,
    [SPECIES_ILLUMISE] =  0,
    [SPECIES_LILEEP] =  0,
    [SPECIES_CRADILY] =  0,
    [SPECIES_ANORITH] =  0,
    [SPECIES_ARMALDO] =  0,
    [SPECIES_RALTS] =  0,
    [SPECIES_KIRLIA] =  0,
    [SPECIES_GARDEVOIR] =  0,
    [SPECIES_BAGON] =  0,
    [SPECIES_SHELGON] =  0,
    [SPECIES_SALAMENCE] =  0,
    [SPECIES_BELDUM] =  8,
    [SPECIES_METANG] =  0,
    [SPECIES_METAGROSS] =  0,
    [SPECIES_REGIROCK] =  0,
    [SPECIES_REGICE] =  0,
    [SPECIES_REGISTEEL] =  0,
    [SPECIES_KYOGRE] =  0,
    [SPECIES_GROUDON] =  0,
    [SPECIES_RAYQUAZA] =  6,
    [SPECIES_LATIAS] =  6,
    [SPECIES_LATIOS] =  6,
    [SPECIES_JIRACHI] = 12,
    [SPECIES_DEOXYS] =  4,
    [SPECIES_CHIMECHO] = 12,
    
    [SPECIES_MISMAGIUS] = 8,
    [SPECIES_CHINGLING] = 4,
    [SPECIES_MANTYKE] = 12,
    [SPECIES_MAGNEZONE] = 3,
    [SPECIES_TOGEKISS] = 6,
    [SPECIES_YANMEGA] = 8,
    [SPECIES_GLISCOR] = 8,
    [SPECIES_PORYGONZ] = 4,
    [SPECIES_PROBOPASS] = 4,
    [SPECIES_DUSKNOIR] = 4,
    [SPECIES_FROSLASS] = 6,
};

#include "../data/trainer_parties.h"

#if ENGLISH
#include "../data/text/trainer_class_names_en.h"
#include "../data/trainers_en.h"
#include "../data/text/species_names_en.h"
#include "../data/text/move_names_en.h"
#elif GERMAN
#include "../data/text/trainer_class_names_de.h"
#include "../data/trainers_de.h"
#include "../data/text/species_names_de.h"
#include "../data/text/move_names_de.h"
#endif

const u32 gUnknown_81F9528 = 0x101;
