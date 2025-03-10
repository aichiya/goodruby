#ifndef GUARD_EWRAM_H
#define GUARD_EWRAM_H

extern u8 gSharedMem[];
#define ewram_addr 0x02000000 // used in gSharedMem addr hacks

// Note: we have duplicate ewram labels because its clear some memory
// regions overlap others but have different definitions. Until some
// dupes can be determined to be the same, they will be deliberate
// seperated.
#define eDroughtPaletteData             (*(struct WeatherPaletteData *)gSharedMem)
#define gBattleStruct                   ((struct BattleStruct *)     (gSharedMem + 0x0))
#define ewram0_2                        (*(struct Struct2000000 *)(gSharedMem + 0x0))
#define namingScreenData                (*(struct NamingScreenData *)(gSharedMem + 0x0))
#define ewramBerryPic                   (gSharedMem + 0x0)
#define ewram0_4                        (*(struct Unk2000000 *)(gSharedMem + 0x0))
#define ewram0_5                        (*(struct UnkStruct *)(gSharedMem + 0x0))
#define eMatsudaDebugVar                (gSharedMem[0x0])
#define eBrendanSprite                  (gSharedMem + 0x0)
#define ewram0_6                        (u32)(&gSharedMem[0])
#define ewram0_7                        (&gSharedMem[0])
#define eSaveSection                    (struct SaveSector *)(gSharedMem + 0x0)
#define ewram0arr                       ((u8 (*)[32])gSharedMem)
#define eVoidSharedArr                  (void *)(ewram_addr + 0x0)
#define eVoidSharedArr2                 (u32)(ewram_addr) // ew(ram)
#define eSlotMachine                    ((struct SlotMachineEwramStruct *)(gSharedMem + 0x0))
#define ewram0_9(i)                     (u8 *)(ewram_addr + (i * 0x20))
#define ewram0_10                       (*(struct UnknownPokenav0*)(gSharedMem + 0))
#define ewram0_11                       (*(struct UnknownPokenav0_1*)(gSharedMem + 0))
#define ePokemonStorageSystem           (*(struct PokemonStorageSystemData *)(gSharedMem + 0))
#define ewram4                          (*(struct UnknownStruct8 *)(gSharedMem + 0x4))
#define ewram520                        ((struct UnknownStruct7 *)(gSharedMem + 0x00520))
#define ewram520_2                      (u8 *)(ewram_addr + 0x520)
#define eMaySprite                      (gSharedMem + 0x800)
#define ewram888                        (gSharedMem + 0x888)
#define ewramBlankMapName               (gSharedMem + 0xA48)
#define ewramA6E                        (gSharedMem[0xA6E])
#define ewram01000                      (*(struct Unk2001000 *)(gSharedMem + 0x1000))
#define ewramBerryPicTemp               (gSharedMem + 0x1000)
#define EWRAM_1000                      (*(struct Struct2001000 *)(gSharedMem + 0x1000))
#define ewram4000                       (gSharedMem + 0x4000)
#define gUnknown_02007000               (*(ewramStruct_02007000 *)(gSharedMem + 0x7000))
#define ARRAY_2007800                   ((struct EasyChatPair *)(gSharedMem + 0x7800))
#define ARRAY_2007900                   ((struct EasyChatPair *)(gSharedMem + 0x7900))
#define ewram_2008000                   (*(struct PlayerRecords *)(gSharedMem + 0x08000))
#define ewram8000                       (&gSharedMem[0x8000])
#define ePokedexPalAddr1                (void *)(gSharedMem + 0x8000)
#define ewram8800                       (&gSharedMem[0x8800])
#define ewram9000                       (&gSharedMem[0x9000])
#define ewram9000_hack                  (void *)(ewram_addr + 0x9000) // TODO: Fix this.
#define ewram9800                       (&gSharedMem[0x9800])
#define ewramA000                       (&gSharedMem[0xA000])
#define ewramA800                       (&gSharedMem[0xA800])
#define ewramB000                       (&gSharedMem[0xB000])
#define ewramB800                       (&gSharedMem[0xB800])
#define TRANSITION_STRUCT               (*(struct TransitionData *)   (gSharedMem + 0xC000))
#define ewramC000                       (&gSharedMem[0xC000])
#define ePokedexPalAddr2                (void *)(gSharedMem + 0xC000)
#define ewramC03C                       (&gSharedMem[0xC03C])
#define ewramC800                       (&gSharedMem[0xC800])
#define ewramD000                       (&gSharedMem[0xD000])
#define ewramD800                       (&gSharedMem[0xD800])
#define ewramE000                       (&gSharedMem[0xE000])
#define ewramE800                       (&gSharedMem[0xE800])
#define ewramF000                       (&gSharedMem[0xF000])
#define ewramF800                       (&gSharedMem[0xF800])
#define ewram_2010000                   (*(struct TradeEwramStruct *)(gSharedMem + 0x10000))
#define ewram10000                      (&gSharedMem[0x10000])
#define eSlotMachineGfxBuffer                    (void *)(gSharedMem + 0x10000) // slot machine
#define ePokedexPalAddr3                (void *)(gSharedMem + 0x10000)
#define ewram10800                      (&gSharedMem[0x10800])
#define ewram11000                      (&gSharedMem[0x11000])
#define ewram11800                      (&gSharedMem[0x11800])
#define ewram12000                      (&gSharedMem[0x12000])
#define ewram12800                      (&gSharedMem[0x12800])
#define ewram13000                      (&gSharedMem[0x13000])
#define eSlotMachineReelTimeGfxBuffer                      (&gSharedMem[0x13200])
#define ewram13800                      (&gSharedMem[0x13800])
#define EWRAM_14000                     ((u8 *)(gSharedMem + 0x14000))
#define ewram14000                      (&gSharedMem[0x14000])
#define ePokedexPalAddr4                (void *)(gSharedMem + 0x14000)
#define ewram14000arr(i, data)          (gSharedMem[0x14000 + i + data])
#define ewram14004arr(i, data)          (gSharedMem[0x14004 + i + data])
#define ewram14008arr(i, data)          (gSharedMem[0x14008 + data + i])
#define ewram14800                      (&gSharedMem[0x14800])
#define EWRAM_14800                     ((u16 *)(gSharedMem + 0x14800))
#define sEvoInfo                        ((*(struct EvoInfo*)(gSharedMem + 0x14800)))
#define EWRAM_15000                     ((u8 *)(gSharedMem + 0x15000))
#define ewram15000                      (&gSharedMem[0x15000])
#define ewram15000arr(i, data)          (gSharedMem[0x15000 + data + i])
#define ewram15800                      (&gSharedMem[0x15800])
#define ewram15DDE                      (gSharedMem[0x15DDE])
#define ewram15DDF                      (gSharedMem[0x15DDF])
#define ewram15DE0                      ((*(struct ContestEntry*)(gSharedMem + 0x15DE0)))
#define ewram15E00                      ((*(struct Unk2015E00*)(gSharedMem + 0x15E00)))
#define ewram16000                      (gSharedMem[0x16000])
#define ewram16000_2                    (&gSharedMem[0x16000])
#define ewram16001                      (gSharedMem[0x16001])
#define ewram16002                      (gSharedMem[0x16002])
#define ewram16003                      (gSharedMem[0x16003])
#define ewram16004arr(i, battler)       (gSharedMem[0x16004 + i + battler * 2])
#define ewram1600C                      (gSharedMem[0x1600C])
#define ewram1600E                      (gSharedMem[0x1600E])
#define ewram16010arr(battler)          (gSharedMem[0x16010 + battler])
#define ewram1601B                      (gSharedMem[0x1601B])
#define eDynamicMoveType                (gSharedMem[0x1601C])
#define eFocusPunchBattler              (gSharedMem[0x1601D])
#define eDmgMultiplier                  (gSharedMem[0x1601F])
#define ewram16020                      ((u8 *)(gSharedMem + 0x16020))
#define ewram16020arr(i)                (gSharedMem[0x16020 + i])
#define ewram16054                      (gSharedMem[0x16054])
#define ewram16056                      (gSharedMem[0x16056])
#define ewram16058                      (gSharedMem[0x16058])
#define ewram16059                      (gSharedMem[0x16059])
#define ewram16060(battler)             (gSharedMem[0x16060 + battler])
#define BATTLE_PARTY_ID(battler)        (gSharedMem[0x16064 + battler])
#define ewram16064                      (&gSharedMem[0x16064])
#define ewram16064arr(battler)          (gSharedMem[0x16064 + battler])
#define ewram16068arr(i)                (gSharedMem[0x16068 + i])
#define UNK_201606C_ARRAY               (gSharedMem + 0x1606C) // lazy define but whatever.
#define ewram1606Carr(i, a)             (gSharedMem[0x1606C + i + a * 3])
#define ewram16078                      (gSharedMem[0x16078])
#define ewram16084                      (gSharedMem[0x16084])
#define ewram16086                      (gSharedMem[0x16086])
#define ewram16087                      (gSharedMem[0x16087])
#define ewram16088_2                    (*(u8 *)(gSharedMem + 0x16088))
#define ewram16089                      (gSharedMem[0x16089])
#define ewram16089_2                    (*(u8 *)(gSharedMem + 0x16089))

// src/battle/anim/battle_intro.c
#define ewram1608A                      gSharedMem[0x1608A]
#define ewram1608B                      gSharedMem[0x1608B]

#define ewram1608Carr(battler)          (gSharedMem[0x1608C + battler])
#define EWRAM_1609D                     (gSharedMem[0x1609D])
#define ewram160A1                      (gSharedMem[0x160A1])
#define ewram160A4                      (gSharedMem[0x160A4])
#define ewram160A5                      (gSharedMem[0x160A5])
#define ewram160A6                      (gSharedMem[0x160A6])
#define ewram160A8                      (gSharedMem[0x160A8])
#define ewram160A9                      (gSharedMem[0x160A9])
#define ewram160AA                      (gSharedMem[0x160AA])
#define ewram160AB                      (gSharedMem[0x160AB])
#define ewram160AC                      ((u8 *)(gSharedMem + 0x160AC))
#define ewram160ACarr(i)                (gSharedMem[0x160AC + i])
#define ewram160ACarr2(i, battler)      (gSharedMem[0x160AC + i + battler * 2])
#define ewram160BC                      ((u16 *)(gSharedMem + 0x160BC))  // hp
#define ewram160BCarr(battler)          (gSharedMem[0x160BC + battler * 2])
#define ewram160C0                      (gSharedMem[0x160C0])
#define ewram160C2_Flags                ((u16 *)(gSharedMem + 0x160C2))
#define ewram160C4_Callback             ((MainCallback *)(gSharedMem + 0x160C4))
#define ewram160C8                      (gSharedMem[0x160C8])
#define ewram160C8arr(battler)          (gSharedMem[0x160C8 + (battler / 2)])
#define ewram160C9                      (gSharedMem[0x160C9])
#define ewram160CB                      (gSharedMem[0x160CB])
#define ewram160CC                      ((u8 *)(gSharedMem + 0x160CC))
#define ewram160CCarr(i)                (gSharedMem[0x160CC + i])
#define USED_HELD_ITEM(battler)         ((((u16*)(&gSharedMem[0x160CC + battler * 2]))))
#define USED_HELD_ITEMS(battler)        (*(u16 *)&gSharedMem[0x160CC + 2 * (battler)])
#define ewram160D4(battler)             (gSharedMem[0x160D4 + (battler / 2) * 2])
#define ewram160D8(battler)             (gSharedMem[0x160D8 + (battler / 2)])
#define ewram160DA(battler)             (gSharedMem[0x160DA + (battler / 2)])
#define ewram160DD                      (gSharedMem[0x160DD])
#define ewram160E0(i)                   (gSharedMem[0x160E0 + i])
#define ewram160E6                      (gSharedMem[0x160E6])
#define ewram160E7                      (gSharedMem[0x160E7])
#define CHOICED_MOVE(battler)           (((u16*)(&gSharedMem[0x160E8 + battler * 2])))
#define ewram160E8                      ((u8 *)(gSharedMem + 0x160E8))
#define ewram160E8arr(i)                (gSharedMem[0x160E8 + i])
#define ewram160E8arr2(i, battler)      (gSharedMem[0x160E8 + i + battler * 2])
#define ewram160F0                      ((u8 *)(gSharedMem + 0x160F0))
#define ewram160F0arr(i)                (gSharedMem[0x160F0 + i])
#define ewram160F8                      (gSharedMem[0x160F8])
#define ewram160F9                      (gSharedMem[0x160F9])
#define eStatHp                         (gSharedMem[0x160FA])
#define ewram160FB                      (gSharedMem[0x160FB])
#define ewram16100                      ((u8 *)(gSharedMem + 0x16100))
#define ewram16100arr(i)                (gSharedMem[0x16100 + i])
#define ewram16100arr2(i, battler)      (gSharedMem[0x16100 + i + battler * 4])
#define ewram16108                      ((u8 *)(gSharedMem + 0x16108))
#define ewram16108arr(i)                (gSharedMem[0x16108 + i])
#define ewram16110                      (gSharedMem[0x16110])
#define ewram16111                      (gSharedMem[0x16111])
#define eMultihitMoveEffect             (gSharedMem[0x16112])
#define ewram16113                      (gSharedMem[0x16113])
#define ewram16400                      (gSharedMem + 0x16400)
#define AI_THINKING_STRUCT              ((struct AI_ThinkingStruct *)(gSharedMem + 0x16800))
#define AI_BATTLE_HISTORY               ((struct BattleHistory *) (gSharedMem + 0x16A00))
#define AI_STACK                        ((struct AI_Stack *)         (gSharedMem + 0x16C00))
#define AI_ARRAY_160CC(i)               (gSharedMem[0x160CC + i * 2])
#define ewram16800                      (&gSharedMem[0x16800])
#define ewram17000                      (&gSharedMem[0x17000])
#define eMoveTutorMenu                  (struct MoveTutorMenu *)(gSharedMem + 0x17000)
#define eSecretBaseRecord               ((struct SecretBaseRecord *)(gSharedMem + 0x17000))
#define eCableCar1                      ((struct CableCarEwramStruct1 *)(gSharedMem + 0x17000))
#define ewram17002                      (&gSharedMem[0x17002])
#define eFlashFireArr                   (*(struct Struct2017100 *)(gSharedMem + 0x17100))
#define B_BATTLESCRIPTS_STACK           ((struct scriptsStack *)     (gSharedMem + 0x17110))
#define ewram17130                      (gSharedMem[0x17130])
#define B_FUNCTION_STACK                ((struct funcStack *)        (gSharedMem + 0x17140))
#define ewram17160                      (gSharedMem[0x17160])
#define ewram17800                      ((struct Struct2017800 *)    (gSharedMem + 0x17800))
#define ewram17800_2                    (&gSharedMem[0x17800])
#define EWRAM_17800                     ((struct UnknownStruct1 *)(gSharedMem + 0x17800))
#define eTransformStatuses              ((struct TransformStatus *)(gSharedMem + 0x17800))
#define ewram17810                      ((struct Struct2017810 *)    (gSharedMem + 0x17810))
#define EWRAM_17810                     ((struct UnknownStruct3 *)(gSharedMem + 0x17810))
#define ewram17840                      (*(struct Struct2017840 *)   (gSharedMem + 0x17840))
#define ewram17850                      ((struct UnknownStruct5 *)(gSharedMem + 0x17850))
#define ewram17E00                      ((u16 *)(gSharedMem + 0x17E00))
#define ewram_2018000                   (*(struct PlayerRecords *)(gSharedMem + 0x18000))
#define EWRAM_18000                     ((u16 *)(gSharedMem + 0x18000))
#define ewram18000                      ((u16 *)(gSharedMem + 0x18000))
#define ewram18000_2                    (&gSharedMem[0x18000])
#define ewram18000_3                    *(struct Pokemon **)(gSharedMem + 0x18000)
#define eBerryBlenderData               (struct BerryBlenderData*)(&gSharedMem[0x18000])
#define eEggHatchData                   (struct EggHatchData*)(&gSharedMem[0x18000])
#define ePokedexView1                   (struct PokedexView *)(gSharedMem + 0x18000)
#define UNK_2018000_STRUCT              (*(struct UnknownStruct2018000 *)(gSharedMem + 0x18000))
#define pssData                         (*(struct PokemonSummaryScreenStruct *)(gSharedMem + 0x18000))
#define ewram18300                      ((u16 *)(gSharedMem + 0x18300))
#define ewram18800                      (&gSharedMem[0x18800])
#define ePokedexView2                   (struct PokedexView *)(gSharedMem + 0x18800)
#define ewram189a0                      ((u16 *)(gSharedMem + 0x189A0))
#define ewram18a20                      ((u16 *)(gSharedMem + 0x18A20))
#define ewram18a32                      ((u16 *)(gSharedMem + 0x18A32))
#define ewram18a80                      ((u16 *)(gSharedMem + 0x18a80))
#define ewram19000                      (&gSharedMem[0x19000])
#define eCableCar2                      ((struct CableCarEwramStruct2 *)(gSharedMem + 0x19000))
#define ePokedexView3                   (struct PokedexView *)(gSharedMem + 0x19000)
#define eRoulette                       ((struct Roulette *)(gSharedMem + 0x19000))
#define shared192D0                     (*(struct UnknownContestStruct7 *)(gSharedMem + 0x192D0))
#define eContestAI                      ((struct ContestAIInfo *)(gSharedMem + 0x192E4))
#define EWRAM_19348                     ((u16 *)(gSharedMem + 0x19348))
#define eWRAM_19348Struct               ((struct EWRAM_19348_Struct *)(gSharedMem + 0x19348))
#define ewram19800                      (&gSharedMem[0x19800])
#define ePokedexView4                   (struct PokedexView *)(gSharedMem + 0x19800)
#define ewram1A000                      (&gSharedMem[0x1A000])
#define ewram1A800                      (&gSharedMem[0x1A800])
#define ewram1B000                      (*(struct Unk201B000 *)(gSharedMem + 0x1B000))
#define ewram1B000_alt                  (*(struct Struct201B000 *)(gSharedMem + 0x1B000))
#define EWRAM_1B000                     ewram1B000_alt // FIXME
#define EWRAM_1B000_2                   (*(struct Struct201B000 *)(gSharedMem + 0x1B000))
#define ewram1B000_2                    (&gSharedMem[0x1B000])
#define ewram1B800                      (&gSharedMem[0x1B800])
#define EWRAM_1C000                     (*(struct Struct201C000 *)(gSharedMem + 0x1C000))
#define ewram1C000                      (*(struct Unk201C000 *)(gSharedMem + 0x1C000))
#define ewram1c000                      (*(struct Unk201C000 *)(gSharedMem + 0x1C000)) // FIXME, names too similar
#define eHallOfFameMons1                (struct HallofFameMons*)(&gSharedMem[0x1C000])
#define eHOFPCScreenEffect              (*(struct PCScreenEffectStruct *)(gSharedMem + 0x1c000))
#define ewram1D000                      ((struct Pokemon *)(gSharedMem + 0x1D000))
#define ewram1D000_2                    ((u16 *)(gSharedMem + 0x1D000))
#define ewram1D400                      ((u16 *)(gSharedMem + 0x1D400))
#define ewramSavedItemsPocket           ((struct ItemSlot *)(gSharedMem + 0x1E000))  // saved items pocket (for Wally battle)
#define ewram1E000(i)                   (gSharedMem[0x1E000 + i])
#define eHallOfFameMons2                (struct HallofFameMons*)(&gSharedMem[0x1E000])
#define eHallOfFame                     (struct HallOfFame *)(gSharedMem + 0x1E000)
#define HALL_OF_FAME_SHEET_0            ((u8 *)(gSharedMem + 0x1E000))
#define ewram1E000_2                    (const u8 *)(gSharedMem + 0x1E000)
#define eContestLinkSendBuffer          gSharedMem + 0x1E000
#define HALL_OF_FAME_SHEET_1            ((u8 *)(gSharedMem + 0x1E800))
#define ewram_1f000                     (*(struct DecoPCPointers *)(gSharedMem + 0x1f000))
#define ewramSavedPokeballsPocket       ((struct ItemSlot *)(gSharedMem + 0x1F000))  // saved Pokeballs pocket (for Wally battle)
#define HALL_OF_FAME_SHEET_2            ((u8 *)(gSharedMem + 0x1F000))
#define EWRAM_1F800                     ((u16 *)(gSharedMem + 0x1F800))
#define ewram_1F800_2                   (const u16 *)(gSharedMem + 0x1F800)
#define ewram1FE00                      (*(struct Unk201FE00 *)(gSharedMem + 0x1FE00))
#define eMailboxInfo                    (*(struct MailboxStruct *)(gSharedMem + 0x1FE00))
#define eCutGrassSpriteArray            (gSharedMem + 0x1FFF0) // 8 sprite IDs
#define eAIItemsUsed                    (gSharedMem[0x1FFF0])
#define ePCItemsUsed                    (gSharedMem[0x1FFF1])
#define ewram1FFFC                      (gSharedMem[0x1FFFC])
#define ewram1FFFD                      (gSharedMem[0x1FFFD])
#define gHelperState                    (gSharedMem[0x1FFFE])
#define ewram1FFFE                      (gSharedMem[0x1FFFE])
#define gReshowState                    (gSharedMem[0x1FFFF])
#define ewramBagSetupStep               (gSharedMem[0x1FFFF])
#define ewram1FFFF                      (gSharedMem[0x1FFFF])

#endif
