Route135_MapBorder:: @ 82C371C
	.incbin "data/layouts/Route135/border.bin"

Route135_MapBlockdata:: @ 82C3724
	.incbin "data/layouts/Route135/map.bin"

	.align 2
Route135_Layout:: @ 82C5024
	.4byte 0x30
	.4byte 0x3C
	.4byte Route135_MapBorder
	.4byte Route135_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Mauville
