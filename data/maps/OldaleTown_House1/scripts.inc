OldaleTown_House1_MapScripts:: @ 8152EEB
	.byte 0

OldaleTown_House1_EventScript_Debug:: @ 8152EEC
	lock
	msgbox OldaleTown_House1_Text_chet, 2
    multichoice 12, 0, 73, 0
    switch RESULT
	case 0, OldaleTown_House1_EventScript_GiveAllMons
	case 1, OldaleTown_House1_EventScript_GiveNewMons
    goto OldaleTown_House1_EventScript_End
    
OldaleTown_House1_EventScript_GiveAllMons:
	setvar VAR_TEMP_1, 0x1
loop1start:
	givemon VAR_TEMP_1, 80, ITEM_NONE, 0x0, 0x0, 0
	addvar VAR_TEMP_1, 0x1
	compare VAR_TEMP_1, 252
	goto_if_lt loop1start
	setvar VAR_TEMP_1, 277
loop2start:
	givemon VAR_TEMP_1, 80, ITEM_NONE, 0x0, 0x0, 0
	addvar VAR_TEMP_1, 0x1
	compare VAR_TEMP_1, 441
	goto_if_lt loop2start
	release
	end

OldaleTown_House1_EventScript_GiveNewMons:
	setvar VAR_TEMP_1, SPECIES_BUDEW
loop3start:
    givemon VAR_TEMP_1, 80, ITEM_NONE, 0x0, 0x0, 0
    addvar VAR_TEMP_1, 0x1
    compare VAR_TEMP_1, NUM_SPECIES
    goto_if_lt loop3start
    release
    end

OldaleTown_House1_EventScript_End:
    release
    end

OldaleTown_House1_EventScript_Vanilla::
	msgbox OldaleTown_House1_Text_17476D, 2
	end
