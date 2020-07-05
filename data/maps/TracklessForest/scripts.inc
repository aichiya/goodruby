TracklessForest_MapScripts::
	map_script 5, TracklessForest_MapScript
    .byte 0

TracklessForest_MapScript:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, TracklessForest_EventScriptSnipSudowoodo
	end

TracklessForest_EventScriptSnipSudowoodo:
    removeobject 1
    return

TracklessForest_EventScript_Sudowoodo::
	lock
	faceplayer
	applymovement 1, TracklessForest_Movement_SudowoodoShake
	waitmovement 0
    checkitem ITEM_WAILMER_PAIL, 1
	compare RESULT, 0
    goto_if_eq TracklessForest_EventScript_LeaveSudowoodo
    msgbox TracklessForest_Text_WeirdTree, MSGBOX_YESNO
	compare RESULT, NO
	goto_if_eq TracklessForest_EventScript_LeaveSudowoodo

TracklessForest_EventScript_WaterSudowoodo:
    message TracklessForest_Text_WaterTree
    waitmessage
	special DoWateringBerryTreeAnim
	waitstate
	setweather WEATHER_SANDSTORM
	doweather
	applymovement 1, TracklessForest_Movement_SudowoodoShake
	waitmovement 0
    
    checkitem ITEM_GO_GOGGLES, 1
    compare RESULT, 0
    goto_if_eq TracklessForest_EventScript_NoGoggles
    
	msgbox TracklessForest_Text_SudowoodoAttacked, 4
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, 2
	delay 40
	waitmoncry
	setflag FLAG_HIDE_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 30, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_HIDE_SUDOWOODO
	setweather WEATHER_SUNNY
	doweather
	release
	end

TracklessForest_EventScript_LeaveSudowoodo:
    release
    end

TracklessForest_EventScript_NoGoggles:
    msgbox TracklessForest_Text_SudowoodoSandstorm, 4
    applymovement 255, TracklessForest_Movement_WalkAway 
	setweather WEATHER_SUNNY
	doweather
    waitmovement 0
    release
    end

TracklessForest_EventScript_Benjamin::
	trainerbattle 0, TRAINER_BENJAMIN, 0, TracklessForest_Text_BenjaminSpot, TracklessForest_Text_BenjaminDefeat
	msgbox TracklessForest_Text_BenjaminFollowup, 6
	end

TracklessForest_EventScript_Leah::
	trainerbattle 0, TRAINER_LEAH, 0, TracklessForest_Text_LeahSpot, TracklessForest_Text_LeahDefeat
	msgbox TracklessForest_Text_LeahFollowup, 6
	end

TracklessForest_EventScript_Harrison::
	trainerbattle 0, TRAINER_HARRISON, 0, TracklessForest_Text_HarrisonSpot, TracklessForest_Text_HarrisonDefeat
	msgbox TracklessForest_Text_HarrisonFollowup, 6
	end

TracklessForest_Movement_SudowoodoShake:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	end_movement

TracklessForest_Movement_WalkAway:
    walk_down
    walk_down
    end_movement
