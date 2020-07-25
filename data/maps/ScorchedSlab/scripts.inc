ScorchedSlab_MapScripts:: @ 815F29D
	map_script 3, ScorchedSlab_MapScript1_15F2A3
	map_script 5, ScorchedSlab_MapScript2
	.byte 0

ScorchedSlab_MapScript1_15F2A3:: @ 815F2A3
	setflag FLAG_LANDMARK_SCORCHED_SLAB
	end

ScorchedSlab_MapScript2:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, ScorchedSlab_EventScriptSnipEntei
	end

ScorchedSlab_EventScriptSnipEntei:
    removeobject 9
    return

ScorchedSlab_EventScript_Entei::
	lock
	waitse
	playmoncry SPECIES_ENTEI, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_ENTEI, 50, ITEM_NONE
	setflag FLAG_HIDE_ENTEI
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special ScrSpecial_StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	release
	end
