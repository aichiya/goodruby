GraniteCave_LugiaChamber_MapBorder::
	.incbin "data/layouts/GraniteCave_LugiaChamber/border.bin"

GraniteCave_LugiaChamber_MapBlockdata::
	.incbin "data/layouts/GraniteCave_LugiaChamber/map.bin"

	.align 2
GraniteCave_LugiaChamber_Layout::
	.4byte 0x20
	.4byte 0x20
	.4byte GraniteCave_LugiaChamber_MapBorder
	.4byte GraniteCave_LugiaChamber_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
