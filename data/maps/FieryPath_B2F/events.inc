FieryPath_B2F_EventObjects::
	object_event 1, EVENT_OBJ_GFX_GOLD_BALL, 0, 3, 29, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, FieryPath_EventScript_Item4, FLAG_ITEM_FIERY_PATH_4
	object_event 2, EVENT_OBJ_GFX_MOLTRES, 0, 24, 21, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, FieryPath_B2F_EventScript_Moltres, FLAG_HIDE_MOLTRES

FieryPath_B2F_MapWarps::
	warp_def 36, 23, 3, 1, MAP_FIERY_PATH_B1F
	warp_def 24, 9, 3, 2, MAP_FIERY_PATH_B1F
	warp_def 9, 6, 3, 3, MAP_FIERY_PATH_B1F
	warp_def 3, 22, 3, 4, MAP_FIERY_PATH_B1F
	warp_def 16, 33, 3, 5, MAP_FIERY_PATH_B1F

FieryPath_B2F_MapEvents::
	map_events FieryPath_B2F_EventObjects, FieryPath_B2F_MapWarps, 0x0, 0x0
