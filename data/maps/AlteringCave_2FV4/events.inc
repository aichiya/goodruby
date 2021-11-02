AlteringCave2FV4_EventObjects::
	object_event 1, EVENT_OBJ_GFX_ITEM_BALL, 0, 27, 5, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, AlteringCave_2F_EventScript_Spoon, FLAG_ITEM_ALTERING_CAVE_F2_1
	object_event 2, EVENT_OBJ_GFX_ITEM_BALL, 0, 13, 10, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, AlteringCave_2F_EventScript_TM84, FLAG_ITEM_ALTERING_CAVE_F2_2
	object_event 3, EVENT_OBJ_GFX_ITEM_BALL, 0, 22, 19, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, AlteringCave_2F_EventScript_RareCandy, FLAG_ITEM_ALTERING_CAVE_F2_3

AlteringCave2FV4_MapWarps::
	warp_def 6, 4, 0, 1, MAP_ALTERING_CAVE_1FV4
	warp_def 21, 17, 0, 0, MAP_ALTERING_CAVE_3FV1

AlteringCave2FV4_MapBGEvents::

AlteringCave2FV4_MapEvents::
	map_events AlteringCave2FV4_EventObjects, AlteringCave2FV4_MapWarps, 0x0, AlteringCave2FV4_MapBGEvents
