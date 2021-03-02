DewfordTown_Mart_MapScripts::
	.byte 0

DewfordTown_Mart_EventScript_1552B0::
	lock
	faceplayer
	message PetalburgCity_Mart_Text_1A0BE4
	waitmessage
	pokemart DewfordTown_Mart_Items1
	msgbox PetalburgCity_Mart_Text_1A0C02, 4
	release
	end

	.align 2
DewfordTown_Mart_Items1::
    .2byte ITEM_HEAL_BALL
	.2byte ITEM_WAVE_MAIL
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_NONE
	release
	end

DewfordTown_Mart_EventScript_RandomNPC::
    lock
    faceplayer
	call DewfordTown_EventScript_1A0102
	msgbox DewfordTown_Mart_Text, 4
    release
	end
