NewMauville_Inside_B3F_MapBorder::
	.incbin "data/layouts/NewMauville_Inside_B3F/border.bin"

NewMauville_Inside_B3F_MapBlockdata::
	.incbin "data/layouts/NewMauville_Inside_B3F/map.bin"

	.align 2
NewMauville_Inside_B3F_Layout::
	.4byte 0x19
	.4byte 0x19
	.4byte NewMauville_Inside_B3F_MapBorder
	.4byte NewMauville_Inside_B3F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
