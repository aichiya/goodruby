LilycoveCity_DepartmentStore_5F_MapScripts:: @ 815A060
	.byte 0

LilycoveCity_DepartmentStore_5F_EventScript_15A061:: @ 815A061
	lock
	faceplayer
	message LilycoveCity_DepartmentStore_5F_Text_1A0BE4
	waitmessage
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Items1
	msgbox LilycoveCity_DepartmentStore_5F_Text_1A0C02, 4
	release
	end

	.align 2
LilycoveCity_DepartmentStore_5F_Items1:: @ 815A078
	.2byte DECOR_PICHU_DOLL
	.2byte DECOR_PIKACHU_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_JIGGLYPUFF_DOLL
	.2byte DECOR_DUSKULL_DOLL 
	.2byte DECOR_WYNAUT_DOLL
	.2byte DECOR_BALTOY_DOLL
	.2byte DECOR_KECLEON_DOLL
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	.2byte DECOR_SWABLU_DOLL
	.2byte DECOR_GULPIN_DOLL
    .2byte DECOR_LOTAD_DOLL
    .2byte DECOR_SEEDOT_DOLL
	.2byte DECOR_NONE
	release
	end

LilycoveCity_DepartmentStore_5F_EventScript_15A094:: @ 815A094
	lock
	faceplayer
	message LilycoveCity_DepartmentStore_5F_Text_1A0BE4
	waitmessage
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Items2
	msgbox LilycoveCity_DepartmentStore_5F_Text_1A0C02, 4
	release
	end

	.align 2
LilycoveCity_DepartmentStore_5F_Items2:: @ 815A0AC
	.2byte DECOR_PIKA_CUSHION
	.2byte DECOR_ROUND_CUSHION
	.2byte DECOR_ZIGZAG_CUSHION
	.2byte DECOR_SPIN_CUSHION
	.2byte DECOR_DIAMOND_CUSHION
	.2byte DECOR_BALL_CUSHION
	.2byte DECOR_GRASS_CUSHION
	.2byte DECOR_FIRE_CUSHION
	.2byte DECOR_WATER_CUSHION
	.2byte DECOR_NONE
	release
	end

LilycoveCity_DepartmentStore_5F_EventScript_15A0C2:: @ 815A0C2
	lock
	faceplayer
	message LilycoveCity_DepartmentStore_5F_Text_1A0BE4
	waitmessage
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Items3
	msgbox LilycoveCity_DepartmentStore_5F_Text_1A0C02, 4
	release
	end

	.align 2
LilycoveCity_DepartmentStore_5F_Items3:: @ 815A0DC
	.2byte DECOR_BALL_POSTER
	.2byte DECOR_GREEN_POSTER
	.2byte DECOR_RED_POSTER
	.2byte DECOR_BLUE_POSTER
	.2byte DECOR_CUTE_POSTER
	.2byte DECOR_PIKA_POSTER
	.2byte DECOR_LONG_POSTER
	.2byte DECOR_SEA_POSTER
	.2byte DECOR_SKY_POSTER
	.2byte DECOR_NONE
	release
	end

LilycoveCity_DepartmentStore_5F_EventScript_15A0F2:: @ 815A0F2
	lock
	faceplayer
	message LilycoveCity_DepartmentStore_5F_Text_1A0BE4
	waitmessage
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Items4
	msgbox LilycoveCity_DepartmentStore_5F_Text_1A0C02, 4
	release
	end

	.align 2
LilycoveCity_DepartmentStore_5F_Items4:: @ 815A10C
	.2byte DECOR_SURF_MAT
	.2byte DECOR_THUNDER_MAT
	.2byte DECOR_FIRE_BLAST_MAT
	.2byte DECOR_POWDER_SNOW_MAT
	.2byte DECOR_ATTRACT_MAT
	.2byte DECOR_FISSURE_MAT
	.2byte DECOR_SPIKES_MAT
	.2byte DECOR_GLITTER_MAT
	.2byte DECOR_JUMP_MAT
	.2byte DECOR_SPIN_MAT
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_5F_EventScript_15A124:: @ 815A124
	msgbox LilycoveCity_DepartmentStore_5F_Text_18C4F9, 2
	end

LilycoveCity_DepartmentStore_5F_EventScript_15A12D:: @ 815A12D
	msgbox LilycoveCity_DepartmentStore_5F_Text_18C59F, 2
	end

LilycoveCity_DepartmentStore_5F_EventScript_15A136:: @ 815A136
	msgbox LilycoveCity_DepartmentStore_5F_Text_18C556, 2
	end
