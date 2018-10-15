GnarledRidge_MapBorder::
	.incbin "data/layouts/GnarledRidge/border.bin"

GnarledRidge_MapBlockdata::
	.incbin "data/layouts/GnarledRidge/map.bin"

	.align 2
GnarledRidge_Layout::
	.4byte 0x28
	.4byte 0x30
	.4byte GnarledRidge_MapBorder
	.4byte GnarledRidge_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Fallarbor
