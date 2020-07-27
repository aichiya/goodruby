FieryPath_B1F_MapBorder::
	.incbin "data/layouts/FieryPath_B1F/border.bin"

FieryPath_B1F_MapBlockdata::
	.incbin "data/layouts/FieryPath_B1F/map.bin"

	.align 2
FieryPath_B1F_Layout::
	.4byte 0x2A
	.4byte 0x2A
	.4byte FieryPath_B1F_MapBorder
	.4byte FieryPath_B1F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Lavaridge
