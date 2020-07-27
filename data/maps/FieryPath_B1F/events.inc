FieryPath_B1F_EventObjects::
	object_event 1, EVENT_OBJ_GFX_ITEM_BALL, 0, 23, 35, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, FieryPath_EventScript_Item1, FLAG_ITEM_FIERY_PATH_1
	object_event 2, EVENT_OBJ_GFX_ITEM_BALL, 0, 12, 24, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, FieryPath_EventScript_Item2, FLAG_ITEM_FIERY_PATH_2
	object_event 3, EVENT_OBJ_GFX_ITEM_BALL, 0, 9, 16, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, FieryPath_EventScript_Item3, FLAG_ITEM_FIERY_PATH_3
	object_event 4, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 24, 24, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, S_PushableBoulder, FLAG_TEMP_11

FieryPath_B1F_MapWarps::
	warp_def 34, 32, 3, 2, MAP_FIERY_PATH
	warp_def 36, 23, 3, 0, MAP_FIERY_PATH_B2F
	warp_def 24, 9, 3, 1, MAP_FIERY_PATH_B2F
	warp_def 9, 6, 3, 2, MAP_FIERY_PATH_B2F
	warp_def 3, 22, 3, 3, MAP_FIERY_PATH_B2F
	warp_def 16, 33, 3, 4, MAP_FIERY_PATH_B2F

FieryPath_B1F_MapEvents::
	map_events FieryPath_B1F_EventObjects, FieryPath_B1F_MapWarps, 0x0, 0x0
