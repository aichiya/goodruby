FabledCave_MapBorder::
	.incbin "data/layouts/FabledCave/border.bin"

FabledCave_MapBlockdata::
	.incbin "data/layouts/FabledCave/map.bin"

	.align 2
FabledCave_Layout::
	.4byte 0x20
	.4byte 0x40
	.4byte FabledCave_MapBorder
	.4byte FabledCave_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
