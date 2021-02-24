LavaridgeTown_Mart_MapScripts:: @ 81538CA
	.byte 0

LavaridgeTown_Mart_EventScript_1538CB:: @ 81538CB
	lock
	faceplayer
	message LavaridgeTown_Mart_Text_1A0BE4
	waitmessage
	pokemart LavaridgeTown_Mart_Items
	msgbox LavaridgeTown_Mart_Text_1A0C02, 4
	release
	end

	.align 2
LavaridgeTown_Mart_Items:: @ 81538E4
	.2byte ITEM_DUSK_BALL
	.2byte ITEM_BEAD_MAIL
	.2byte ITEM_X_SPECIAL
    .2byte ITEM_CHARCOAL
	.2byte ITEM_NONE

LavaridgeTown_Mart_EventScript_1538FA:: @ 81538FA
	msgbox LavaridgeTown_Mart_Text_176DA6, 2
	end

LavaridgeTown_Mart_EventScript_153903:: @ 8153903
	msgbox LavaridgeTown_Mart_Text_176E1A, 2
	end
