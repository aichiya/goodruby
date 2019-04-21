GraniteCave_B3F_EventObjects::
	object_event 1, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 7, 4, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, S_BreakableRock, FLAG_TEMP_11
	object_event 2, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 9, 8, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, S_BreakableRock, FLAG_TEMP_12
	object_event 3, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 4, 24, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, S_BreakableRock, FLAG_TEMP_13
	object_event 4, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 18, 26, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, S_BreakableRock, FLAG_TEMP_14
	object_event 5, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 16, 20, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, S_BreakableRock, FLAG_TEMP_15
	object_event 6, EVENT_OBJ_GFX_ITEM_BALL, 0, 18, 11, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, GraniteCave_B3F_EventScript_HardStone, FLAG_ITEM_GRANITE_CAVE_B3F_1

GraniteCave_B3F_MapWarps::
	warp_def 7, 25, 3, 5, MAP_GRANITE_CAVE_B2F
	warp_def 15, 28, 3, 0, MAP_GRANITE_CAVE_B4F
	warp_def 26, 3, 3, 1, MAP_GRANITE_CAVE_STAIRS

GraniteCave_B3F_MapBGEvents::
	bg_event 10, 16, 0, BG_EVENT_PLAYER_FACING_ANY, GraniteCave_B3F_EventScript_BrailleWall
	bg_event 11, 16, 0, BG_EVENT_PLAYER_FACING_ANY, GraniteCave_B3F_EventScript_BrailleWall
	bg_event 12, 16, 0, BG_EVENT_PLAYER_FACING_ANY, GraniteCave_B3F_EventScript_BrailleWall

GraniteCave_B3F_MapEvents::
	map_events GraniteCave_B3F_EventObjects, GraniteCave_B3F_MapWarps, 0x0, GraniteCave_B3F_MapBGEvents
