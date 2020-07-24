MagmaHideout_B1F_MapScripts:: @ 815F2A8
	map_script 5, MagmaHideout_B1F_MapScript1_15F2AE
	.byte 0

MagmaHideout_B1F_MapScript1_15F2AE:: @ 815F2AE
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MagmaHideout_B1F_EventScript_15F2B8
	end

MagmaHideout_B1F_EventScript_15F2B8:: @ 815F2B8
	removeobject LAST_TALKED
	return

MagmaHideout_B1F_EventScript_GruntOne::
	trainerbattle 2, TRAINER_GRUNT_29, 0, AquaHideout_B1F_Text_196E6F, AquaHideout_B1F_Text_196EB6, MagmaHideout_B1F_EventScript_GruntOneFollowUp
	msgbox AquaHideout_B1F_Text_196ECC, 6
	end
MagmaHideout_B1F_EventScript_GruntOneFollowUp:
	msgbox AquaHideout_B1F_Text_196ECC, 4
	release
	end

MagmaHideout_B1F_EventScript_AquaGruntOne::
	trainerbattle 2, TRAINER_GRUNT_16, 0, MagmaHideout_B1F_Text_AquaGruntOneSpot, MagmaHideout_B1F_Text_AquaGruntOneDefeat, MagmaHideout_B1F_EventScript_AquaGruntOneFollowUp
	msgbox MagmaHideout_B1F_Text_AquaGruntOneLater, 6
	end
MagmaHideout_B1F_EventScript_AquaGruntOneFollowUp:
	msgbox MagmaHideout_B1F_Text_AquaGruntOneLater, 4
	release
	end

MagmaHideout_B1F_EventScript_AquaGruntTwo::
	trainerbattle 2, TRAINER_GRUNT_26, 0, MagmaHideout_B1F_Text_AquaGruntTwoSpot, MagmaHideout_B1F_Text_AquaGruntTwoDefeat, MagmaHideout_B1F_EventScript_AquaGruntTwoFollowUp
	msgbox MagmaHideout_B1F_Text_AquaGruntTwoLater, 6
	end
MagmaHideout_B1F_EventScript_AquaGruntTwoFollowUp:
	msgbox MagmaHideout_B1F_Text_AquaGruntTwoLater, 4
	release
	end

MagmaHideout_B1F_EventScript_Shelly::
    trainerbattle 1, TRAINER_SHELLY_1, 0, MagmaHideout_B1F_Text_ShellyIntro, MagmaHideout_B1F_Text_ShellyDefeat, MagmaHideout_B1F_EventScript_ShellyTwo

MagmaHideout_B1F_EventScript_ShellyTwo:
    msgbox MagmaHideout_B1F_Text_ShellyLater, 4
	giveitem_std ITEM_HM04_STRENGTH
	msgbox MagmaHideout_B1F_Text_ShellyLaterTwo, 4
	closemessage
	compare FACING, 3
	call_if_eq MagmaHideout_B1F_EventScript_ShellyLeaveDownRight
	compare FACING, 4
	call_if_eq MagmaHideout_B1F_EventScript_ShellyLeaveRight
	compare FACING, 2
	call_if_eq MagmaHideout_B1F_EventScript_ShellyLeaveRight
	removeobject LAST_TALKED
    setflag FLAG_HIDE_MAGMA_HIDEOUT_AQUA_GRUNTS
	release
	end

MagmaHideout_B1F_EventScript_ShellyLeaveRight:
	applymovement LAST_TALKED, MagmaHideout_B1F_Movement_ShellyRight
	waitmovement 0
    playse SE_TK_WARPIN
	return

MagmaHideout_B1F_EventScript_ShellyLeaveDownRight:
	applymovement LAST_TALKED, MagmaHideout_B1F_Movement_ShellyDownRight
	waitmovement 0
    playse SE_TK_WARPIN
	return

MagmaHideout_B1F_Movement_ShellyRight:
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
	end_movement
    
MagmaHideout_B1F_Movement_ShellyDownRight:
    walk_down
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_up
	end_movement