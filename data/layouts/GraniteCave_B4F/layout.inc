GraniteCave_B4F_MapBorder::
	.incbin "data/layouts/GraniteCave_B4F/border.bin"

GraniteCave_B4F_MapBlockdata::
	.incbin "data/layouts/GraniteCave_B4F/map.bin"

	.align 2
GraniteCave_B4F_Layout::
	.4byte 0x20
	.4byte 0x20
	.4byte GraniteCave_B4F_MapBorder
	.4byte GraniteCave_B4F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
