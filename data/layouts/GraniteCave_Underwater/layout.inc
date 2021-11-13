GraniteCave_Underwater_MapBorder:: @ 82F2F18
	.incbin "data/layouts/GraniteCave_Underwater/border.bin"

GraniteCave_Underwater_MapBlockdata:: @ 82F2F20
	.incbin "data/layouts/GraniteCave_Underwater/map.bin"

	.align 2
GraniteCave_Underwater_Layout:: @ 82F6120
	.4byte 0x50
	.4byte 0x50
	.4byte GraniteCave_Underwater_MapBorder
	.4byte GraniteCave_Underwater_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Underwater
