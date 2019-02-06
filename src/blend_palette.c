#include "global.h"
#include "blend_palette.h"
#include "palette.h"

void BlendPalette(u16 palOffset, u16 numEntries, u8 coeff, u16 blendColor)
{
    u16 i;
    for (i = 0; i < numEntries; i++)
    {
        u16 index = i + palOffset;
        struct PlttData *data1 = (struct PlttData *)&gPlttBufferUnfaded[index];
        s8 r = data1->r;
        s8 g = data1->g;
        s8 b = data1->b;
        struct PlttData *data2 = (struct PlttData *)&blendColor;
        gPlttBufferFaded[index] = ((r + (((data2->r - r) * coeff) >> 4)) << 0)
                                | ((g + (((data2->g - g) * coeff) >> 4)) << 5)
                                | ((b + (((data2->b - b) * coeff) >> 4)) << 10);
    }
}

static void NudgePalette_(u16* src, u16* dest, u16 palOffset, u16 numEntries, u32 colorValue)
{
    u16 i;
    s8 dr = (colorValue & 0x0030) >> 4;
    s8 dg = (colorValue & 0x00C0) >> 6;
    s8 db = (colorValue & 0x0300) >> 8;
    s8 mr = (colorValue & 0x0C00) >> 10;
    s8 mg = (colorValue & 0x3000) >> 12;
    s8 mb = (colorValue & 0xC000) >> 14;
    
    for (i = 0; i < numEntries; i++)
    {
        u16 index = i + palOffset;
        struct PlttData *data = (struct PlttData *)&src[index];
        s8 r = data->r + dr - mr;
        s8 g = data->g + dg - mg;
        s8 b = data->b + db - mb;
        r = r > 31 ? r - 4 : r; 
        b = b > 31 ? b - 4 : b; 
        g = g > 31 ? g - 4 : g;
        r = r < 0 ? r + 4 : r;
        b = b < 0 ? b + 4 : b;
        g = g < 0 ? g + 4 : g;
        
        src[index] = (r << 0)
                    | (g << 5)
                    | (b << 10);
        dest[index] = (r << 0)
                    | (g << 5)
                    | (b << 10);
    }
}

void NudgePalette(u16 palOffset, u16 numEntries, u32 colorValue)
{
    NudgePalette_((u16*)gPlttBufferUnfaded, (u16*)gPlttBufferFaded, palOffset, numEntries, colorValue);
}

void NudgePaletteInPlace(u16* palette, u16 numEntries, u32 colorValue)
{
    NudgePalette_(palette, palette, 0, numEntries, colorValue);
}
