GraniteCave_B3F_MapBorder::
	.incbin "data/layouts/GraniteCave_B3F/border.bin"

GraniteCave_B3F_MapBlockdata::
	.incbin "data/layouts/GraniteCave_B3F/map.bin"

	.align 2
GraniteCave_B3F_Layout::
	.4byte 0x20
	.4byte 0x20
	.4byte GraniteCave_B3F_MapBorder
	.4byte GraniteCave_B3F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
