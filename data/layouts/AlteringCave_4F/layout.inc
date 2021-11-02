AlteringCave4F_MapBorder::
	.incbin "data/layouts/AlteringCave_4F/border.bin"

AlteringCave4F_MapBlockdata::
	.incbin "data/layouts/AlteringCave_4F/map.bin"

	.align 2
AlteringCave4F_Layout::
	.4byte 0x20
	.4byte 0x18
	.4byte AlteringCave4F_MapBorder
	.4byte AlteringCave4F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
