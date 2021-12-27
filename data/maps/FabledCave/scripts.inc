FabledCave_MapScripts::
	map_script 5, FabledCave_MapScript
	.byte 0

FabledCave_MapScript:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FabledCave_EventScript_SnipSomething
	end

FabledCave_EventScript_SnipSomething:
    removeobject LAST_TALKED
    return

FabledCave_EventScript_Ho_oh::
	lock
	waitse
	playmoncry SPECIES_HO_OH, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_HO_OH, 70, ITEM_NONE
	setflag FLAG_HIDE_HO_OH
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special ScrSpecial_StartGroudonKyogreBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	release
	end
