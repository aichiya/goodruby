AlteringCave3FV3_EventObjects::
	object_event 1, EVENT_OBJ_GFX_GOLD_BALL, 0, 7, 19, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, AlteringCave_3F_EventScript_TM67, FLAG_ITEM_ALTERING_CAVE_F3_1
	object_event 2, EVENT_OBJ_GFX_ITEM_BALL, 0, 27, 13, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, AlteringCave_3F_EventScript_RareCandy, FLAG_ITEM_ALTERING_CAVE_F3_2

AlteringCave3FV3_MapWarps::
	warp_def 21, 18, 0, 1, MAP_ALTERING_CAVE_2FV4
	warp_def 17, 13, 0, 0, MAP_ALTERING_CAVE_4F
    
AlteringCave3FV3_MapBGEvents::

AlteringCave3FV3_MapEvents::
	map_events AlteringCave3FV3_EventObjects, AlteringCave3FV3_MapWarps, 0x0, AlteringCave3FV3_MapBGEvents
