ShoalCave_LowTideIceRoom_MapScripts:: @ 815F300
	map_script 5, ShoalCave_LowTideIceRoom_MapScript
	.byte 0

ShoalCave_LowTideIceRoom_MapScript:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, ShoalCave_LowTideIceRoom_EventScript_SnipArticuno
	end

ShoalCave_LowTideIceRoom_EventScript_SnipArticuno:
    removeobject 3
    return

ShoalCave_LowTideIceRoom_EventScript_Articuno::
	lock
	waitse
	playmoncry SPECIES_ARTICUNO, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_ARTICUNO, 50, ITEM_NONE
	setflag FLAG_HIDE_ARTICUNO
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special ScrSpecial_StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	release
	end
