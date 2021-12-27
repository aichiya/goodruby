Route136_MapBorder::
	.incbin "data/layouts/Route136/border.bin"

Route136_MapBlockdata::
	.incbin "data/layouts/Route136/map.bin"

	.align 2
Route136_Layout::
	.4byte 0x28
	.4byte 0x30
	.4byte Route136_MapBorder
	.4byte Route136_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Pacifidlog
