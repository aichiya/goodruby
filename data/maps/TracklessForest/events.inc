TracklessForest_EventObjects::
    object_event 1, EVENT_OBJ_GFX_SUDOWOODO, 0, 7, 37, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, TracklessForest_EventScript_Sudowoodo, FLAG_HIDE_SUDOWOODO
	object_event 2, EVENT_OBJ_GFX_MAN_6, 0, 11, 14, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 1, 3, TracklessForest_EventScript_Benjamin, 0
	object_event 3, EVENT_OBJ_GFX_HEX_MANIAC, 0, 42, 12, 3, MOVEMENT_TYPE_FACE_DOWN_LEFT_AND_RIGHT, 0, 0, 1, 4, TracklessForest_EventScript_Leah, 0
	object_event 4, EVENT_OBJ_GFX_MANIAC, 0, 29, 39, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 1, 4, TracklessForest_EventScript_Harrison, 0
	object_event 5, EVENT_OBJ_GFX_GOLD_BALL, 0, 36, 16, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, TracklessForest_EventScript_Item1, FLAG_ITEM_TRACKLESS_FOREST_1
	object_event 6, EVENT_OBJ_GFX_ITEM_BALL, 0, 22, 27, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, TracklessForest_EventScript_Item2, FLAG_ITEM_TRACKLESS_FOREST_2
	object_event 7, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 25, 24, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, S_PushableBoulder, FLAG_TEMP_11
	object_event 8, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 26, 23, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, S_PushableBoulder, FLAG_TEMP_12
	object_event 9, EVENT_OBJ_GFX_RAIKOU, 0, 24, 14, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, TracklessForest_EventScript_Raikou, FLAG_HIDE_RAIKOU

TracklessForest_MapWarps::
	warp_def 6, 42, 0, 6, MAP_PETALBURG_WOODS
	warp_def 7, 42, 0, 7, MAP_PETALBURG_WOODS

TracklessForest_MapCoordEvents::

TracklessForest_MapBGEvents::

TracklessForest_MapEvents:: @ 838C31C
	map_events TracklessForest_EventObjects, TracklessForest_MapWarps, 0, 0
