MtChimney_EventScript_1B2C95:: @ 81B2C95
	lock
	faceplayer
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_1B2CB9
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_1B2CC2
	closemessage
	applymovement 1, MtChimney_Movement_1A083D
	waitmovement 0
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end

MtChimney_EventScript_1B2CB9:: @ 81B2CB9
	msgbox MtChimney_Text_1B350B, 4
	return

MtChimney_EventScript_1B2CC2:: @ 81B2CC2
	msgbox MtChimney_Text_1B3598, 4
	return

MtChimney_EventScript_GruntA::
    lockall
	playbgm MUS_AQA_0, FALSE
	msgbox MtChimney_Text_GruntAFirst, 4
	trainerbattle 3, TRAINER_GRUNT_9 0, MtChimney_Text_GruntALost
    setvar VAR_SPECIAL_3 1
    applymovement 30, MtChimney_Movement_GruntBApproach
    waitmovement 0
    applymovement 255, MtChimney_Movement_FaceSouth
	playbgm MUS_AQA_0, FALSE
    msgbox MtChimney_Text_GruntBSecond, 4
	trainerbattle 3, TRAINER_GRUNT_15 0, MtChimney_Text_GruntBLost
    applymovement 29, MtChimney_Movement_FaceEast
    applymovement 30, MtChimney_Movement_FaceEast
    waitmovement 0
    msgbox MtChimney_Text_GruntsPanic, 4
    closemessage
    applymovement 29, MtChimney_Movement_GruntStepsBackA
    applymovement 30, MtChimney_Movement_FaceNorth
    applymovement 2, MtChimney_Movement_ArchiePathA
    applymovement 255, MtChimney_Movement_FaceEast
    waitmovement 0
    goto MtChimney_EventScript_ArchieStuff

MtChimney_EventScript_GruntB::
    lockall
	playbgm MUS_AQA_0, FALSE
	msgbox MtChimney_Text_GruntBFirst, 4
	trainerbattle 3, TRAINER_GRUNT_15 0, MtChimney_Text_GruntBLost
    setvar VAR_SPECIAL_3 2
    applymovement 29, MtChimney_Movement_GruntAApproach
    waitmovement 0
    applymovement 255, MtChimney_Movement_FaceNorth
	playbgm MUS_AQA_0, FALSE
    msgbox MtChimney_Text_GruntASecond, 4
	trainerbattle 3, TRAINER_GRUNT_9 0, MtChimney_Text_GruntALost
    applymovement 29, MtChimney_Movement_FaceEast
    applymovement 30, MtChimney_Movement_FaceEast
    waitmovement 0
    msgbox MtChimney_Text_GruntsPanic, 4
    closemessage
    applymovement 29, MtChimney_Movement_GruntStepsBackB
    applymovement 30, MtChimney_Movement_FaceWest
    applymovement 2, MtChimney_Movement_ArchiePathB
    waitmovement 2
    goto MtChimney_EventScript_ArchieStuff

MtChimney_Movement_GruntBApproach:
    walk_left
    face_up
    end_movement

MtChimney_Movement_GruntAApproach:
    walk_left
    face_down
    end_movement

MtChimney_Movement_FaceNorth:
    face_up
    end_movement

MtChimney_Movement_FaceSouth:
    face_down
    end_movement

MtChimney_Movement_FaceEast:
    face_right
    end_movement

MtChimney_Movement_FaceWest:
    face_left
    end_movement

MtChimney_Movement_GruntStepsBackA:
    walk_down
    face_up
    end_movement

MtChimney_Movement_GruntStepsBackB:
    walk_left
    face_down
    end_movement

MtChimney_Movement_ArchiePathA:
    walk_left
    end_movement

MtChimney_Movement_ArchiePathB:
    walk_left
    walk_left
    face_down
    end_movement

MtChimney_EventScript_ArchieStuff:: @ 81B2CCB
	msgbox MtChimney_Text_1B2ED9, 4
	trainerbattle 3, TRAINER_ARCHIE_3, 0, MtChimney_Text_1B3099
	msgbox MtChimney_Text_1B30C2, 4
	closemessage
	delay 30
	fadescreen 1
	removeobject 2
	removeobject 3
	removeobject 22
    removeobject 29
	removeobject 30
	setflag FLAG_HIDE_EVIL_TEAM_MT_CHIMNEY
	fadescreen 0
	setobjectxyperm 1, 10, 12
	addobject 1

	compare VAR_SPECIAL_3, 1
	call_if_eq MtChimney_EventScript_1B2D88
	compare VAR_SPECIAL_3, 2
	call_if_eq MtChimney_EventScript_1B2D7D

	applymovement 255, MtChimney_Movement_1A083F
	waitmovement 0
	msgbox MtChimney_Text_1B3608, 4
	closemessage

	compare VAR_SPECIAL_3, 1
	call_if_eq MtChimney_EventScript_1B2D9E
	compare VAR_SPECIAL_3, 2
	call_if_eq MtChimney_EventScript_1B2D93

	removeobject 1
    setflag FLAG_HIDE_OTEHR_TEAM_MT_CHIMNEY
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_HIDE_PROF_COSMO_FALLARBOR
	setflag FLAG_HIDE_PROF_COSMO_METEOR_FALLS
	releaseall
	end

MtChimney_EventScript_1B2D7D:: @ 81B2D7D
	applymovement 1, MtChimney_Movement_15D025
	waitmovement 0
	return

MtChimney_EventScript_1B2D88:: @ 81B2D88
	applymovement 1, MtChimney_Movement_15D036
	waitmovement 0
	return

MtChimney_EventScript_1B2D93:: @ 81B2D93
	applymovement 1, MtChimney_Movement_15D02D
	waitmovement 0
	return

MtChimney_EventScript_1B2D9E:: @ 81B2D9E
	applymovement 1, MtChimney_Movement_15D03E
	waitmovement 0
	return
