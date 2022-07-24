TopSecretArea_MapBorder::
	.incbin "data/layouts/TopSecretArea/border.bin"

TopSecretArea_MapBlockdata::
	.incbin "data/layouts/TopSecretArea/map.bin"

	.align 2
TopSecretArea_Layout::
	.4byte 0x20
	.4byte 0x20
	.4byte TopSecretArea_MapBorder
	.4byte TopSecretArea_MapBlockdata
	.4byte gTileset_SecretBase
	.4byte gTileset_SecretBaseRedCave
