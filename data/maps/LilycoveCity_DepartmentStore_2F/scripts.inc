LilycoveCity_DepartmentStore_2F_MapScripts:: @ 8159F0E
	.byte 0

LilycoveCity_DepartmentStore_2F_EventScript_StairsOutOfOrder::
	msgbox LilycoveCity_DepartmentStore_2F_Text_StairsOutOfOrder, 2
	end

LilycoveCity_DepartmentStore_2F_EventScript_159F0F:: @ 8159F0F
	msgbox LilycoveCity_DepartmentStore_2F_Text_18C162, 2
	end

LilycoveCity_DepartmentStore_2F_EventScript_159F18:: @ 8159F18
	msgbox LilycoveCity_DepartmentStore_2F_Text_18C195, 2
	end

LilycoveCity_DepartmentStore_2F_EventScript_159F21:: @ 8159F21
	msgbox LilycoveCity_DepartmentStore_2F_Text_18C1D9, 2
	end

LilycoveCity_DepartmentStore_2F_EventScript_159F2A:: @ 8159F2A
	lock
	faceplayer
	message LilycoveCity_DepartmentStore_2F_Text_1A0BE4
	waitmessage
	pokemart LilycoveCity_DepartmentStore_2F_Items1
	msgbox LilycoveCity_DepartmentStore_2F_Text_1A0C02, 4
	release
	end

	.align 2
LilycoveCity_DepartmentStore_2F_Items1:: @ 8159F44
	.2byte ITEM_MOOMOO_MILK
	.2byte ITEM_LAVA_COOKIE
	.2byte ITEM_FLUFFY_TAIL
	.2byte ITEM_SHADOW_MAIL
	.2byte ITEM_MECH_MAIL
	.2byte ITEM_WAVE_MAIL
	.2byte ITEM_NONE
	release
	end
