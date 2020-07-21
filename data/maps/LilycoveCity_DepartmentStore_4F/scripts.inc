LilycoveCity_DepartmentStore_4F_MapScripts:: @ 8159FFD
	.byte 0

LilycoveCity_DepartmentStore_4F_EventScript_159FFE:: @ 8159FFE
	msgbox LilycoveCity_DepartmentStore_4F_Text_18C39C, 2
	end

LilycoveCity_DepartmentStore_4F_EventScript_15A007:: @ 815A007
	msgbox LilycoveCity_DepartmentStore_4F_Text_18C41B, 2
	end

LilycoveCity_DepartmentStore_4F_EventScript_15A010:: @ 815A010
	msgbox LilycoveCity_DepartmentStore_4F_Text_18C481, 2
	end

LilycoveCity_DepartmentStore_4F_EventScript_15A019:: @ 815A019
	lock
	faceplayer
	message LilycoveCity_DepartmentStore_4F_Text_1A0BE4
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Items1
	msgbox LilycoveCity_DepartmentStore_4F_Text_1A0C02, 4
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Items1:: @ 815A030
    .2byte ITEM_TM85_MAGIC_GLEAM
    .2byte ITEM_TM53_ENERGY_BALL
    .2byte ITEM_TM89_U_TURN
	.2byte ITEM_TM35_FLAMETHROWER
	.2byte ITEM_TM24_THUNDERBOLT
	.2byte ITEM_TM13_ICE_BEAM
    .2byte ITEM_TM29_PSYCHIC
	.2byte ITEM_TM68_GIGA_IMPACT
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_4F_EventScript_15A03C:: @ 815A03C
	lock
	faceplayer
	message LilycoveCity_DepartmentStore_4F_Text_1A0BE4
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Items2
	msgbox LilycoveCity_DepartmentStore_4F_Text_1A0C02, 4
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Items2:: @ 815A054
    .2byte ITEM_TM83_NATURAL_GIFT
	.2byte ITEM_TM17_PROTECT
	.2byte ITEM_TM20_SAFEGUARD
	.2byte ITEM_TM33_REFLECT
	.2byte ITEM_TM16_LIGHT_SCREEN
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_4F_EventScript_Merchant3::
	lock
	faceplayer
	message LilycoveCity_DepartmentStore_4F_Text_1A0BE4
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Items3
	msgbox LilycoveCity_DepartmentStore_4F_Text_1A0C02, 4
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Items3::
    .2byte ITEM_FIRE_STONE
	.2byte ITEM_WATER_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_SUN_STONE
	.2byte ITEM_DAWN_STONE
	.2byte ITEM_DUSK_STONE
	.2byte ITEM_SHINY_STONE
	.2byte ITEM_ICE_STONE
    .2byte ITEM_NOBLE_STONE
	.2byte ITEM_NONE
	release
	end
