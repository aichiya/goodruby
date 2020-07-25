ScorchedSlab_EventObjects:: @ 838E988
	object_event 1, EVENT_OBJ_GFX_GOLD_BALL, 0, 3, 10, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, ScorchedSlab_EventScript_1B18FF, FLAG_ITEM_SCORCHED_SLAB_1
	object_event 2, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 6, 10, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, S_PushableBoulder, FLAG_TEMP_11
	object_event 3, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 7, 9, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, S_PushableBoulder, FLAG_TEMP_12
	object_event 4, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 8, 10, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, S_PushableBoulder, FLAG_TEMP_13
	object_event 5, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 5, 10, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, S_BreakableRock, FLAG_TEMP_14
	object_event 6, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 6, 9, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, S_BreakableRock, FLAG_TEMP_15
	object_event 7, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 8, 9, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, S_BreakableRock, FLAG_TEMP_16
	object_event 8, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 9, 10, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, S_BreakableRock, FLAG_TEMP_17
	object_event 9, EVENT_OBJ_GFX_ENTEI, 0, 7, 4, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, ScorchedSlab_EventScript_Entei, FLAG_HIDE_ENTEI

ScorchedSlab_MapWarps:: @ 838E9A0
	warp_def 7, 16, 1, 1, MAP_ROUTE120

ScorchedSlab_MapEvents:: @ 838E9A8
	map_events ScorchedSlab_EventObjects, ScorchedSlab_MapWarps, 0x0, 0x0
