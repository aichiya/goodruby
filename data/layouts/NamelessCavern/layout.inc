NamelessCavern_MapBorder::
	.incbin "data/layouts/NamelessCavern/border.bin"

NamelessCavern_MapBlockdata::
	.incbin "data/layouts/NamelessCavern/map.bin"

	.align 2
NamelessCavern_Layout::
	.4byte 0x20
	.4byte 0x20
	.4byte NamelessCavern_MapBorder
	.4byte NamelessCavern_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
