VerdanturfTown_Mart_MapScripts:: @ 8153EBB
	.byte 0

VerdanturfTown_Mart_EventScript_153EBC:: @ 8153EBC
	lock
	faceplayer
	message VerdanturfTown_Mart_Text_1A0BE4
	waitmessage
	pokemart VerdanturfTown_Mart_Items
	msgbox VerdanturfTown_Mart_Text_1A0C02, 4
	release
	end

	.align 2
VerdanturfTown_Mart_Items:: @ 8153ED4
	.2byte ITEM_NEST_BALL
	.2byte ITEM_FLUFFY_TAIL
	.2byte ITEM_GLITTER_MAIL
	.2byte ITEM_X_DEFEND
	.2byte ITEM_NONE
	release
	end

VerdanturfTown_Mart_EventScript_153EEE:: @ 8153EEE
	msgbox VerdanturfTown_Mart_Text_1781C9, 2
	end

VerdanturfTown_Mart_EventScript_153EF7:: @ 8153EF7
	msgbox VerdanturfTown_Mart_Text_178240, 2
	end

VerdanturfTown_Mart_EventScript_153F00:: @ 8153F00
	msgbox VerdanturfTown_Mart_Text_1782C0, 2
	end
