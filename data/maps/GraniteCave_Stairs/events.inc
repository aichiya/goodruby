GraniteCave_Stairs_EventObjects::
	object_event 1, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 16, 29, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, S_BreakableRock, FLAG_TEMP_11
	object_event 2, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 12, 28, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, S_BreakableRock, FLAG_TEMP_12
	object_event 3, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 27, 26, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, S_BreakableRock, FLAG_TEMP_13
	object_event 4, EVENT_OBJ_GFX_ITEM_BALL, 0, 10, 18, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, GraniteCave_B3F_EventScript_TM40, FLAG_ITEM_GRANITE_CAVE_B3F_2

GraniteCave_Stairs_MapWarps::
	warp_def 5, 17, 3, 1, MAP_GRANITE_CAVE_B4F
	warp_def 16, 19, 3, 2, MAP_GRANITE_CAVE_B3F

GraniteCave_Stairs_MapEvents::
	map_events GraniteCave_Stairs_EventObjects, GraniteCave_Stairs_MapWarps, 0x0, 0x0
