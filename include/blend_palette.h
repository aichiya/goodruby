#ifndef GUARD_BLEND_PALETTE_H
#define GUARD_BLEND_PALETTE_H

void CopyPalette(u16 palOffset, u16 destOffset, u16 numEntries);
void FullBlendPalette(u16 palOffset, u16 numEntries, u8 coeff, u16 blendColor);
void BlendPalette(u16 palOffset, u16 numEntries, u8 coeff, u16 blendColor);
void NudgePalette(u16 palOffset, u16 numEntries, u32 colorValue);
void NudgePaletteInPlace(u16* palette, u16 numEntries, u32 colorValue);

#endif // GUARD_BLEND_PALETTE_H
