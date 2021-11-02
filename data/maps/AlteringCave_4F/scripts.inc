AlteringCave4F_MapScripts::
	map_script 5, AlteringCave4F_MapScript
	.byte 0

AlteringCave4F_MapScript::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AlteringCave4F_EventScript_SnipSomething
	end

AlteringCave4F_EventScript_SnipSomething:
    removeobject LAST_TALKED
    return

AlteringCave4F_EventScript_Mewtwo::
	lock
	waitse
	playmoncry SPECIES_MEWTWO, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_MEWTWO, 70, ITEM_BRIGHT_POWDER
	setflag FLAG_HIDE_MEWTWO
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special ScrSpecial_StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	release
	end

