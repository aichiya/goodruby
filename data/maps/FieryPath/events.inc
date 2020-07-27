FieryPath_EventObjects:: @ 838C718
	object_event 1, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 17, 15, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, S_PushableBoulder, FLAG_TEMP_12

FieryPath_MapWarps:: @ 838C7D8
	warp_def 26, 36, 3, 4, MAP_ROUTE112
	warp_def 26, 4, 3, 5, MAP_ROUTE112
	warp_def 11, 16, 3, 0, MAP_FIERY_PATH_B1F

FieryPath_MapEvents:: @ 838C7E8
	map_events FieryPath_EventObjects, FieryPath_MapWarps, 0x0, 0x0
