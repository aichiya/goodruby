Route130_MapScripts:: @ 81523C2
	map_script 3, Route130_MapScript1_1523C8
    map_script 5, Route130_MapScript5
	.byte 0

Route130_MapScript1_1523C8:: @ 81523C8
	specialvar RESULT, CountLegendariesSeen
	compare RESULT, 7
	goto_if_ge Route130_EventScript_15240C
	setflag FLAG_TEMP_11
	setflag FLAG_TEMP_12
	setflag FLAG_TEMP_13
	setflag FLAG_TEMP_14
	setflag FLAG_TEMP_15
	setflag FLAG_TEMP_16
	setflag FLAG_TEMP_17
	setflag FLAG_TEMP_18
	setflag FLAG_TEMP_19
	setflag FLAG_TEMP_1A
	setflag FLAG_TEMP_1B
	setflag FLAG_TEMP_1C
	setflag FLAG_TEMP_1D
	setflag FLAG_TEMP_1E
	setflag FLAG_TEMP_1F
	setflag FLAG_TEMP_20
	setmaplayoutindex 264
	end

Route130_EventScript_15240C:: @ 815240C
	setmaplayoutindex 46
	end

Route130_MapScript5:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route130_EventScriptSnipSomething
    call_if_unset FLAG_GS_BALL_OPENED, Route130_EventScript_HideCelebi
	end

Route130_EventScriptSnipSomething:
	removeobject LAST_TALKED
    return

Route130_EventScript_HideCelebi:
    setflag FLAG_HIDE_CELEBI
    return

Route130_EventScript_152410:: @ 8152410
	trainerbattle 0, TRAINER_RODNEY, 0, Route130_Text_1C2401, Route130_Text_1C245D
	msgbox Route130_Text_1C2479, 6
	end

Route130_EventScript_152427:: @ 8152427
	trainerbattle 0, TRAINER_KATIE, 0, Route130_Text_1C24DC, Route130_Text_1C2525
	msgbox Route130_Text_1C256E, 6
	end

Route130_EventScript_Celebi::
	lock
	waitse
	playmoncry SPECIES_CELEBI, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_CELEBI, 50, ITEM_NONE
	setflag FLAG_HIDE_CELEBI
    setflag FLAG_FOUGHT_CELEBI
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special ScrSpecial_StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	release
	end

Route130_EventScript_Shrine::
    goto_if_set FLAG_GS_BALL_OPENED, Route130_EventScript_ShrineNormal
    goto_if_unset FLAG_MANIAC_EXAMINED_GS_BALL, Route130_EventScript_ShrineNormal
    checkitem ITEM_GS_BALL, 1
    compare RESULT, 0
    goto_if_eq Route130_EventScript_ShrineNormal
    msgbox Route130_Text_CelebiAppears, 4
    closemessage
    playse SE_BOWA2
    fadescreen 0x3
    waitse
	playmoncry SPECIES_CELEBI, 0
    waitmoncry
    setflag FLAG_GS_BALL_OPENED
    takeitem ITEM_GS_BALL, 1
    clearflag FLAG_HIDE_CELEBI
    addobject 4
    fadescreen 0x2
    delay 0x4
    release
    end
    

Route130_EventScript_ShrineNormal:
    msgbox Route130_Text_JustAShrine, 3
    end
