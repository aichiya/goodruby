GraniteCave_LugiaChamber_MapScripts::
	map_script 5, GraniteCave_LugiaChamber_MapScript
	.byte 0

GraniteCave_LugiaChamber_MapScript:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, GraniteCave_LugiaChamber_EventScript_SnipSomething
	setdivewarp MAP_GRANITE_CAVE_UNDERWATER, 255, 10, 5
	end

GraniteCave_LugiaChamber_EventScript_SnipSomething:
    removeobject LAST_TALKED
    return

GraniteCave_LugiaChamber_EventScript_Lugia::
	lock
	waitse
	playmoncry SPECIES_LUGIA, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_LUGIA, 70, ITEM_NONE
	setflag FLAG_HIDE_LUGIA
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special ScrSpecial_StartGroudonKyogreBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	release
	end