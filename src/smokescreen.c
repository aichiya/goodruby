#include "global.h"
#include "decompress.h"
#include "sprite.h"

extern u8 CreateInvisibleSpriteWithCallback(void (*)(struct Sprite *));

static void sub_8046388(struct Sprite *);

extern struct SpriteSheet gUnknown_081FAEA4;
extern struct SpritePalette gUnknown_081FAEAC;
extern const struct SpriteTemplate gSpriteTemplate_81FAF0C;

u8 sub_8046234(s16 x, s16 y, u8 a3)
{
    u8 mainSpriteId;
    u8 spriteId1, spriteId2, spriteId3, spriteId4;
    struct Sprite *mainSprite;

    if (GetSpriteTileStartByTag(gUnknown_081FAEA4.tag) == 0xFFFF)
    {
        LoadCompressedObjectPic(&gUnknown_081FAEA4);
        LoadCompressedObjectPalette(&gUnknown_081FAEAC);
    }

    mainSpriteId = CreateInvisibleSpriteWithCallback(sub_8046388);
    mainSprite = &gSprites[mainSpriteId];
    mainSprite->data1 = a3;

    spriteId1 = CreateSprite(&gSpriteTemplate_81FAF0C, x - 16, y - 16, 2);
    gSprites[spriteId1].data0 = mainSpriteId;
    mainSprite->data0++;
    AnimateSprite(&gSprites[spriteId1]);

    spriteId2 = CreateSprite(&gSpriteTemplate_81FAF0C, x, y - 16, 2);
    gSprites[spriteId2].data0 = mainSpriteId;
    mainSprite->data0++;
    StartSpriteAnim(&gSprites[spriteId2], 1);
    AnimateSprite(&gSprites[spriteId2]);

    spriteId3 = CreateSprite(&gSpriteTemplate_81FAF0C, x - 16, y, 2);
    gSprites[spriteId3].data0 = mainSpriteId;
    mainSprite->data0++;
    StartSpriteAnim(&gSprites[spriteId3], 2);
    AnimateSprite(&gSprites[spriteId3]);

    spriteId4 = CreateSprite(&gSpriteTemplate_81FAF0C, x, y, 2);
    gSprites[spriteId4].data0 = mainSpriteId;
    mainSprite->data0++;
    StartSpriteAnim(&gSprites[spriteId4], 3);
    AnimateSprite(&gSprites[spriteId4]);

    return mainSpriteId;
}

static void sub_8046388(struct Sprite *sprite)
{
    if (!sprite->data0)
    {
        FreeSpriteTilesByTag(gUnknown_081FAEA4.tag);
        FreeSpritePaletteByTag(gUnknown_081FAEAC.tag);
        if (!sprite->data1)
            DestroySprite(sprite);
        else
            sprite->callback = SpriteCallbackDummy;
    }
}

void sub_80463CC(struct Sprite *sprite)
{
    if (sprite->animEnded)
    {
        gSprites[sprite->data0].data0--;
        DestroySprite(sprite);
    }
}
