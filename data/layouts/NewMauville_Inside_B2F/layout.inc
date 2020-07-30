NewMauville_Inside_B2F_MapBorder::
	.incbin "data/layouts/NewMauville_Inside_B2F/border.bin"

NewMauville_Inside_B2F_MapBlockdata::
	.incbin "data/layouts/NewMauville_Inside_B2F/map.bin"

	.align 2
NewMauville_Inside_B2F_Layout::
	.4byte 0x28
	.4byte 0x28
	.4byte NewMauville_Inside_B2F_MapBorder
	.4byte NewMauville_Inside_B2F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
