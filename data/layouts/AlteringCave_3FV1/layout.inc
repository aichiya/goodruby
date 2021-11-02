AlteringCave3FV1_MapBorder:: @ 82E7570
	.incbin "data/layouts/AlteringCave_3FV1/border.bin"

AlteringCave3FV1_MapBlockdata:: @ 82E7578
	.incbin "data/layouts/AlteringCave_3FV1/map.bin"

	.align 2
AlteringCave3FV1_Layout:: @ 82E76A0
	.4byte 0x20
	.4byte 0x18
	.4byte AlteringCave3FV1_MapBorder
	.4byte AlteringCave3FV1_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
