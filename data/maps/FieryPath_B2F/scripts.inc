FieryPath_B2F_MapScripts::
	map_script 5, FieryPath_B2F_MapScript
    .byte 0

FieryPath_B2F_MapScript:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FieryPath_B2F_EventScript_SnipMoltres
	end

FieryPath_B2F_EventScript_SnipMoltres:
    removeobject 2
    return

FieryPath_B2F_EventScript_Moltres::
	lock
	waitse
	playmoncry SPECIES_MOLTRES, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_MOLTRES, 50, ITEM_NONE
	setflag FLAG_HIDE_MOLTRES
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special ScrSpecial_StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	release
	end
