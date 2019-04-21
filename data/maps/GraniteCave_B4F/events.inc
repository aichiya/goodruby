GraniteCave_B4F_EventObjects::
	object_event 1, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 16, 29, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, S_BreakableRock, FLAG_TEMP_11
	object_event 2, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 12, 28, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, S_BreakableRock, FLAG_TEMP_12
	object_event 3, EVENT_OBJ_GFX_BREAKABLE_ROCK, 0, 27, 26, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, S_BreakableRock, FLAG_TEMP_13
	object_event 4, EVENT_OBJ_GFX_ITEM_BALL, 0, 7, 7, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, GraniteCave_B3F_EventScript_Calcium, FLAG_ITEM_GRANITE_CAVE_B3F_3

GraniteCave_B4F_MapWarps::
	warp_def 15, 28, 3, 1, MAP_GRANITE_CAVE_B3F
	warp_def 15, 3, 3, 0, MAP_GRANITE_CAVE_STAIRS

GraniteCave_B4F_MapBGEvents::
	bg_event 4, 3, 0, BG_EVENT_PLAYER_FACING_ANY, GraniteCave_B4F_EventScript_BrailleWallDay
	bg_event 5, 3, 0, BG_EVENT_PLAYER_FACING_ANY, GraniteCave_B4F_EventScript_BrailleWallDay
	bg_event 6, 3, 0, BG_EVENT_PLAYER_FACING_ANY, GraniteCave_B4F_EventScript_BrailleWallDay
	bg_event 24, 3, 0, BG_EVENT_PLAYER_FACING_ANY, GraniteCave_B4F_EventScript_BrailleWallNight
	bg_event 25, 3, 0, BG_EVENT_PLAYER_FACING_ANY, GraniteCave_B4F_EventScript_BrailleWallNight
	bg_event 26, 3, 0, BG_EVENT_PLAYER_FACING_ANY, GraniteCave_B4F_EventScript_BrailleWallNight
	bg_event 14, 20, 0, BG_EVENT_PLAYER_FACING_ANY, GraniteCave_B4F_EventScript_BrailleWallMorning
	bg_event 15, 20, 0, BG_EVENT_PLAYER_FACING_ANY, GraniteCave_B4F_EventScript_BrailleWallMorning
	bg_event 16, 20, 0, BG_EVENT_PLAYER_FACING_ANY, GraniteCave_B4F_EventScript_BrailleWallMorning

GraniteCave_B4F_MapEvents::
	map_events GraniteCave_B4F_EventObjects, GraniteCave_B4F_MapWarps, 0x0, GraniteCave_B4F_MapBGEvents
