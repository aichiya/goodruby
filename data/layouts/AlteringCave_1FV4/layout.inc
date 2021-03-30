AlteringCave1FV4_MapBorder:: @ 82E7570
	.incbin "data/layouts/AlteringCave1FV4/border.bin"

AlteringCave1FV4_MapBlockdata:: @ 82E7578
	.incbin "data/layouts/AlteringCave1FV4/map.bin"

	.align 2
AlteringCave1FV4_Layout:: @ 82E76A0
	.4byte 0x20
	.4byte 0x18
	.4byte AlteringCave1FV4_MapBorder
	.4byte AlteringCave1FV4_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
