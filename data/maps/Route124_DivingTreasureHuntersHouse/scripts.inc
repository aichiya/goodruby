Route124_DivingTreasureHuntersHouse_MapScripts:: @ 8163DFA
	map_script 3, Route124_DivingTreasureHuntersHouse_MapScript1_163E00
	.byte 0

Route124_DivingTreasureHuntersHouse_MapScript1_163E00:: @ 8163E00
	setflag FLAG_LANDMARK_HUNTERS_HOUSE
	end

Route124_DivingTreasureHuntersHouse_EventScript_163E04::
	lock
	faceplayer
    goto_if_set FLAG_MANIAC_EXAMINED_GS_BALL, Route124_DivingTreasureHuntersHouse_EventScript_IntroShoppingFamiliar
    checkitem ITEM_GS_BALL, 1
    compare RESULT, 0
    goto_if_eq Route124_DivingTreasureHuntersHouse_EventScript_IntroShopping
    msgbox Route124_DivingTreasureHuntersHouse_Text_SpotGSBall, MSGBOX_YESNO
    switch RESULT
    case 0, Route124_DivingTreasureHuntersHouse_EventScript_Decline
    goto Route124_DivingTreasureHuntersHouse_EventScript_ExamineBall

Route124_DivingTreasureHuntersHouse_EventScript_IntroShopping:
	message Route124_DivingTreasureHuntersHouse_Text_Intro
	waitmessage
	pokemart Route124_DivingTreasureHuntersHouse_Items
	msgbox Route124_DivingTreasureHuntersHouse_Text_Outro, 4
	release
	end

Route124_DivingTreasureHuntersHouse_EventScript_IntroShoppingFamiliar:
	message Route124_DivingTreasureHuntersHouse_Text_FamiliarIntro
	waitmessage
	pokemart Route124_DivingTreasureHuntersHouse_Items
	msgbox Route124_DivingTreasureHuntersHouse_Text_Outro, 4
	release
	end

Route124_DivingTreasureHuntersHouse_EventScript_Decline:
	message Route124_DivingTreasureHuntersHouse_Text_Decline
	waitmessage
	pokemart Route124_DivingTreasureHuntersHouse_Items
	msgbox Route124_DivingTreasureHuntersHouse_Text_Outro, 4
	release
	end

Route124_DivingTreasureHuntersHouse_EventScript_ExamineBall:
    msgbox Route124_DivingTreasureHuntersHouse_Text_Examine, 4
    closemessage
    fadescreen 0x1
    delay 0x40
    playse SE_W199
    delay 0x40
    playse SE_W011
    delay 0x20
    playse SE_W011
    delay 0x20
    playse SE_W011
    delay 0x15
    playse SE_W172
    delay 0x40
    playse SE_W011
    delay 0x40
    fadescreen 0x0
    delay 0x20
    msgbox Route124_DivingTreasureHuntersHouse_Text_Examine3, 4
    setflag FLAG_MANIAC_EXAMINED_GS_BALL
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
