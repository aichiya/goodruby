AlteringCave1FV3_MapBorder:: @ 82E7570
	.incbin "data/layouts/AlteringCave_1FV3/border.bin"

AlteringCave1FV3_MapBlockdata:: @ 82E7578
	.incbin "data/layouts/AlteringCave_1FV3/map.bin"

	.align 2
AlteringCave1FV3_Layout:: @ 82E76A0
	.4byte 0x20
	.4byte 0x18
	.4byte AlteringCave1FV3_MapBorder
	.4byte AlteringCave1FV3_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
