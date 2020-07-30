NewMauville_Inside_B2F_MapScripts::
	map_script 5, NewMauville_Inside_B2F_MapScript
	.byte 0

NewMauville_Inside_B2F_MapScript:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NewMauville_Inside_B2F_EventScript_SnipSomething
	end

NewMauville_Inside_B2F_EventScript_SnipSomething:
    removeobject LAST_TALKED
    return

NewMauville_Inside_B2F_Electrode1::
    setvar VAR_SPECIAL_5, FLAG_HIDE_ELECTRODE_MAUVILLEBF2_1
    goto NewMauville_Inside_B2F_EventScript_ElectrodeGeneral

NewMauville_Inside_B2F_Electrode2::
    setvar VAR_SPECIAL_5, FLAG_HIDE_ELECTRODE_MAUVILLEBF2_2
    goto NewMauville_Inside_B2F_EventScript_ElectrodeGeneral

NewMauville_Inside_B2F_Electrode3::
    setvar VAR_SPECIAL_5, FLAG_HIDE_ELECTRODE_MAUVILLEBF2_3
    goto NewMauville_Inside_B2F_EventScript_ElectrodeGeneral

NewMauville_Inside_B2F_Electrode4::
    setvar VAR_SPECIAL_5, FLAG_HIDE_ELECTRODE_MAUVILLEBF2_4
    goto NewMauville_Inside_B2F_EventScript_ElectrodeGeneral

NewMauville_Inside_B2F_Electrode5::
    setvar VAR_SPECIAL_5, FLAG_HIDE_ELECTRODE_MAUVILLEBF2_5
    goto NewMauville_Inside_B2F_EventScript_ElectrodeGeneral

NewMauville_Inside_B2F_Electrode6::
    setvar VAR_SPECIAL_5, FLAG_HIDE_ELECTRODE_MAUVILLEBF2_6
    goto NewMauville_Inside_B2F_EventScript_ElectrodeGeneral

NewMauville_Inside_B2F_Electrode7::
    setvar VAR_SPECIAL_5, FLAG_HIDE_ELECTRODE_MAUVILLEBF2_7
    goto NewMauville_Inside_B2F_EventScript_ElectrodeGeneral

NewMauville_Inside_B2F_Electrode8::
    setvar VAR_SPECIAL_5, FLAG_HIDE_ELECTRODE_MAUVILLEBF2_8
    goto NewMauville_Inside_B2F_EventScript_ElectrodeGeneral

NewMauville_Inside_B2F_Electrode9::
    setvar VAR_SPECIAL_5, FLAG_HIDE_ELECTRODE_MAUVILLEBF2_9
    goto NewMauville_Inside_B2F_EventScript_ElectrodeGeneral

NewMauville_Inside_B2F_Electrode10::
    setvar VAR_SPECIAL_5, FLAG_HIDE_ELECTRODE_MAUVILLEBF2_10
    goto NewMauville_Inside_B2F_EventScript_ElectrodeGeneral

NewMauville_Inside_B2F_Electrode11::
    setvar VAR_SPECIAL_5, FLAG_HIDE_ELECTRODE_MAUVILLEBF2_11
    goto NewMauville_Inside_B2F_EventScript_ElectrodeGeneral

NewMauville_Inside_B2F_Electrode12::
    setvar VAR_SPECIAL_5, FLAG_HIDE_ELECTRODE_MAUVILLEBF2_12
    goto NewMauville_Inside_B2F_EventScript_ElectrodeGeneral

NewMauville_Inside_B2F_EventScript_ElectrodeGeneral:
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 40, ITEM_NONE
	waitse
	playmoncry SPECIES_ELECTRODE, 2
	delay 40
	waitmoncry
	setflag VAR_SPECIAL_5
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	release
	end

NewMauville_Inside_B2F_Zapdos::
	lock
	waitse
	playmoncry SPECIES_ZAPDOS, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_ZAPDOS, 50, ITEM_NONE
	setflag FLAG_HIDE_ZAPDOS
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special ScrSpecial_StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	release
	end

