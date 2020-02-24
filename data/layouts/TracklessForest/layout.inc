TracklessForest_MapBorder::
	.incbin "data/layouts/TracklessForest/border.bin"

TracklessForest_MapBlockdata::
	.incbin "data/layouts/TracklessForest/map.bin"

	.align 2
TracklessForest_Layout:: @ 82F6CE0
	.4byte 0x30
	.4byte 0x30
	.4byte TracklessForest_MapBorder
	.4byte TracklessForest_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Rustboro
