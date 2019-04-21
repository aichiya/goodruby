GraniteCave_Stairs_MapBorder::
	.incbin "data/layouts/GraniteCave_StairsRoom/border.bin"

GraniteCave_Stairs_MapBlockdata::
	.incbin "data/layouts/GraniteCave_StairsRoom/map.bin"

	.align 2
GraniteCave_Stairs_Layout::
	.4byte 0x20
	.4byte 0x1A
	.4byte GraniteCave_Stairs_MapBorder
	.4byte GraniteCave_Stairs_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
