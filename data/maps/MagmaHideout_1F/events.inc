MagmaHideout_1F_EventObjects:: @ 838E9BC
	object_event 1, EVENT_OBJ_GFX_VAR_1, 0, 13, 19, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, MagmaHideout_1F_EventScript_15D7CE, FLAG_HIDE_GRUNT_1_BLOCKING_HIDEOUT
	object_event 2, EVENT_OBJ_GFX_VAR_1, 0, 14, 19, 3, MOVEMENT_TYPE_FACE_DOWN, 1, 1, 0, 0, MagmaHideout_1F_EventScript_15D7ED, FLAG_HIDE_GRUNT_2_BLOCKING_HIDEOUT
	object_event 3, EVENT_OBJ_GFX_MAGMA_MEMBER_M, 0, 21, 3, 3, MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT, 7, 6, 1, 3, MagmaHideout_1F_EventScript_MagmaGrunt1, 0
    object_event 4, EVENT_OBJ_GFX_AQUA_MEMBER_M, 0, 13, 9, 3, MOVEMENT_TYPE_WALK_SEQUENCE_UP_LEFT_DOWN_RIGHT, 7, 6, 1, 3, MagmaHideout_1F_EventScript_AquaGrunt1, 0

MagmaHideout_1F_MapWarps:: @ 838EA04
	warp_def 13, 27, 1, 14, MAP_LILYCOVE_CITY
	warp_def 13, 1, 3, 0, MAP_MAGMA_HIDEOUT_B1F

MagmaHideout_1F_MapEvents:: @ 838EA14
	map_events MagmaHideout_1F_EventObjects, MagmaHideout_1F_MapWarps, 0x0, 0x0
