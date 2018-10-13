#include "global.h"
#include "battle_anim.h"
#include "rom_8077ABC.h"
#include "trig.h"
#include "util.h"
#include "decompress.h"
#include "palette.h"

asm(".equ REG_BLDCNT, 0x4000050\n"
	"\t.equ REG_BG1CNT, 0x400000A\n"
	"\t.equ REG_BG1HOFS, 0x4000014");

extern s16 gBattleAnimArgs[];
extern u8 gAnimBankAttacker;
extern u8 gAnimBankTarget;
extern u16 gBattle_BG1_X;
extern u16 gBattle_BG1_Y;

extern const u8 gUnknown_08E70968[];
extern const u8 gUnknown_08E70C38[];
extern const u8 gUnknown_08E70F0C[];
extern const u8 gBattleAnimBackgroundImage_Surf[];
extern const u8 gBattleAnimBackgroundPalette_Surf[];
extern const u8 gBattleAnimBackgroundImageMuddyWater_Pal[];
extern const u8 gBattleAnimBackgroundImageSludgeWave_Pal[];

extern const union AffineAnimCmd *const gSpriteAffineAnimTable_83DA318[];
extern const union AnimCmd *const gSpriteAnimTable_83D9BC8[];

void sub_80D37FC(struct Sprite *sprite);
void sub_80D3838(struct Sprite *sprite);
void sub_80D4044(struct Sprite *sprite);
void sub_80D452C(struct Sprite *sprite);
void sub_80D4BF0(struct Sprite *sprite);
void sub_80D4C64(struct Sprite *sprite);
static void sub_80D3874(struct Sprite *sprite);

extern void sub_80D3B60(u8 taskId);
extern void sub_80D3D68(u8 taskId);

const union AnimCmd gSpriteAnim_83D9300[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd gSpriteAnim_83D9308[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END,
};

const union AnimCmd *const gSpriteAnimTable_83D9310[] =
{
    gSpriteAnim_83D9300,
};

const union AnimCmd *const gSpriteAnimTable_83D9314[] =
{
    gSpriteAnim_83D9308,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_83D9318 =
{
    .tileTag = 10155,
    .paletteTag = 10155,
    .oam = &gOamData_837E04C,
    .anims = gSpriteAnimTable_83D9310,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80794A8,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_83D9330 =
{
    .tileTag = 10155,
    .paletteTag = 10155,
    .oam = &gOamData_837E10C,
    .anims = gSpriteAnimTable_83D9314,
    .images = NULL,
    .affineAnims = gSpriteAffineAnimTable_83DA318,
    .callback = sub_80D37FC,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_83D9348 =
{
    .tileTag = 10141,
    .paletteTag = 10141,
    .oam = &gOamData_837DF24,
    .anims = gSpriteAnimTable_83D9BC8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80D3838,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_83D9360 =
{
    .tileTag = 10155,
    .paletteTag = 10155,
    .oam = &gOamData_837DF24,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80D4044,
};

const struct SpriteTemplate gSpriteTemplate_83D9378 =
{
    .tileTag = 10268,
    .paletteTag = 10268,
    .oam = &gOamData_837DF24,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80D452C,
};

const union AnimCmd gSpriteAnim_83D9390[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END,
};

const union AnimCmd gSpriteAnim_83D9398[] =
{
    ANIMCMD_FRAME(9, 1),
    ANIMCMD_END,
};

const union AnimCmd gSpriteAnim_83D93A0[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END,
};

const union AnimCmd *const gSpriteAnimTable_83D93A8[] =
{
    gSpriteAnim_83D9390,
    gSpriteAnim_83D9398,
};

const union AnimCmd *const gSpriteAnimTable_83D93B0[] =
{
    gSpriteAnim_83D93A0,
};

const union AffineAnimCmd gSpriteAffineAnim_83D93B4[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0xFFF6, 0xFFF6, 0, 15),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gSpriteAffineAnim_83D93CC[] =
{
    AFFINEANIMCMD_FRAME(0xE0, 0xE0, 0, 0),
    AFFINEANIMCMD_FRAME(0xFFF8, 0xFFF8, 0, 15),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gSpriteAffineAnim_83D93E4[] =
{
    AFFINEANIMCMD_FRAME(0x150, 0x150, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 15),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gSpriteAffineAnimTable_83D93FC[] =
{
    gSpriteAffineAnim_83D93B4,
    gSpriteAffineAnim_83D93CC,
};

const union AffineAnimCmd *const gSpriteAffineAnimTable_83D9404[] =
{
    gSpriteAffineAnim_83D93E4,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_83D9408 =
{
    .tileTag = 10155,
    .paletteTag = 10155,
    .oam = &gOamData_837DF24,
    .anims = gSpriteAnimTable_83D93A8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80D4BF0,
};

const struct SpriteTemplate gSpriteTemplate_83D9420 =
{
    .tileTag = 10155,
    .paletteTag = 10155,
    .oam = &gOamData_837DF84,
    .anims = gSpriteAnimTable_83D93A8,
    .images = NULL,
    .affineAnims = gSpriteAffineAnimTable_83D93FC,
    .callback = sub_80D4C64,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_83D9438 =
{
    .tileTag = 10155,
    .paletteTag = 10155,
    .oam = &gOamData_837DF8C,
    .anims = gSpriteAnimTable_83D93B0,
    .images = NULL,
    .affineAnims = gSpriteAffineAnimTable_83D9404,
    .callback = sub_807A9BC,
};

void sub_80D37FC(struct Sprite *sprite)
{
    sub_8078764(sprite, TRUE);

    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[2] = sprite->pos1.x + gBattleAnimArgs[2];
    sprite->data[4] = sprite->pos1.y + gBattleAnimArgs[4];

    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData(sprite, DestroyAnimSprite);
}

void sub_80D3838(struct Sprite *sprite)
{
    if (gBattleAnimArgs[3] != 0)
    {
        sub_8078764(sprite, TRUE);
    }
    else
    {
        InitAnimSpritePos(sprite, 1);
    }

    sprite->data[7] = gBattleAnimArgs[2];
    sprite->callback = sub_80D3874;
}

static void sub_80D3874(struct Sprite *sprite)
{
    sprite->data[0] = (sprite->data[0] + 11) & 0xFF;
    sprite->pos2.x = Sin(sprite->data[0], 4);

    sprite->data[1] += 48;
    sprite->pos2.y = -(sprite->data[1] >> 8);

    if (--sprite->data[7] == -1)
    {
        DestroyAnimSprite(sprite);
    }
}

void sub_80D38BC(u8 taskId)
{
    struct UnknownStruct2 sp00;
    u8 taskId2;
    volatile u8 spC;

    REG_BLDCNT = BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG0 | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BD;
    REG_BLDALPHA = BLDALPHA_BLEND(0, 0x10);
    ((volatile struct BgCnt *)&REG_BG1CNT)->priority = 1;
    ((volatile struct BgCnt *)&REG_BG1CNT)->screenSize = 1;
    sub_8078914(&sp00);
    Dma3FillLarge32_(0, sp00.unk0, 0x2000);
    spC = 0;
    spC = 0;
    DmaFill32Defvars(3, 0, sp00.unk4, 0x1000);
    if (!IsContest())
    {
        ((volatile struct BgCnt *)&REG_BG1CNT)->charBaseBlock = 1;
        if (GetBattlerSide(gAnimBankAttacker) == 1)
            LZDecompressVram(gUnknown_08E70968, sp00.unk4);
        else
            LZDecompressVram(gUnknown_08E70C38, sp00.unk4);
    }
    else
    {
        LZDecompressVram(gUnknown_08E70F0C, sp00.unk4);
        sub_80763FC(sp00.unk8, sp00.unk4, 0, 1);
    }
    LZDecompressVram(gBattleAnimBackgroundImage_Surf, sp00.unk0);
    if (gBattleAnimArgs[0] == 0)
        LoadCompressedPalette(gBattleAnimBackgroundPalette_Surf, sp00.unk8 * 16, 32);
    else if (gBattleAnimArgs[0] == 1)
        LoadCompressedPalette(gBattleAnimBackgroundImageMuddyWater_Pal, sp00.unk8 * 16, 32);
	else
		LoadCompressedPalette(gBattleAnimBackgroundImageSludgeWave_Pal, sp00.unk8 * 16, 32);
    taskId2 = CreateTask(sub_80D3D68, gTasks[taskId].priority + 1);
    gTasks[taskId].data[15] = taskId2;
    gTasks[taskId2].data[0] = 0;
    gTasks[taskId2].data[1] = 0x1000;
    gTasks[taskId2].data[2] = 0x1000;
    if (IsContest())
    {
        gBattle_BG1_X = -0x50;
        gBattle_BG1_Y = -0x30;
        gTasks[taskId].data[0] = 2;
        gTasks[taskId].data[1] = 1;
        gTasks[taskId2].data[3] = 0;
    }
    else if (GetBattlerSide(gAnimBankAttacker) == 1)
    {
        gBattle_BG1_X = -0xe0;
        gBattle_BG1_Y = 0x100;
        gTasks[taskId].data[0] = 2;
        gTasks[taskId].data[1] = -1;
        gTasks[taskId2].data[3] = 1;
    }
    else
    {
        gBattle_BG1_X = 0;
        gBattle_BG1_Y = -0x30;
        gTasks[taskId].data[0] = -2;
        gTasks[taskId].data[1] = 1;
        gTasks[taskId2].data[3] = 0;
    }
    REG_BG1HOFS = gBattle_BG1_X;
    REG_BG1VOFS = gBattle_BG1_Y;
    if (gTasks[taskId2].data[3] == 0)
    {
        gTasks[taskId2].data[4] = 0x30;
        gTasks[taskId2].data[5] = 0x70;
    }
    else
    {
        gTasks[taskId2].data[4] = 0;
        gTasks[taskId2].data[5] = 0;
    }
	gTasks[taskId].data[0x6] = 1;
    gTasks[taskId].func = sub_80D3B60;
}