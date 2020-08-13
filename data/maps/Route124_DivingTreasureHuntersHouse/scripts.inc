Route124_DivingTreasureHuntersHouse_MapScripts:: @ 8163DFA
	map_script 3, Route124_DivingTreasureHuntersHouse_MapScript1_163E00
	.byte 0

Route124_DivingTreasureHuntersHouse_MapScript1_163E00:: @ 8163E00
	setflag FLAG_LANDMARK_HUNTERS_HOUSE
	end

Route124_DivingTreasureHuntersHouse_EventScript_163E04::
	lock
	faceplayer
	message Route124_DivingTreasureHuntersHouse_Text_Intro
	waitmessage
	pokemart Route124_DivingTreasureHuntersHouse_Items
	msgbox Route124_DivingTreasureHuntersHouse_Text_Outro, 4
	release
	end


	.align 2
Route124_DivingTreasureHuntersHouse_Items:
	.2byte ITEM_LUXURY_BALL
	.2byte ITEM_DUSK_BALL
	.2byte ITEM_QUICK_BALL
  	.2byte ITEM_NET_BALL
    .2byte ITEM_DIVE_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_AQUA_BALL
	.2byte ITEM_MAGMA_BALL
	.2byte ITEM_NONE
	release
	end

Route124_DivingTreasureHuntersHouse_EventScript_164335:: @ 8164335
	msgbox Route124_DivingTreasureHuntersHouse_Text_19F6C5, 3
	end
