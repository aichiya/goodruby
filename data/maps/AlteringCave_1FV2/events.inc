AlteringCave1FV2_EventObjects::
	object_event 1, EVENT_OBJ_GFX_ITEM_BALL, 0, 1, 13, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, AlteringCave_1F_EventScript_HeartScale, FLAG_ITEM_ALTERING_CAVE_F1_1
	object_event 2, EVENT_OBJ_GFX_ITEM_BALL, 0, 28, 10, 3, MOVEMENT_TYPE_LOOK_AROUND, 1, 1, 0, 0, AlteringCave_1F_EventScript_Nugget, FLAG_ITEM_ALTERING_CAVE_F1_2

AlteringCave1FV2_MapWarps::
	warp_def 18, 22, 0, 0, MAP_ROUTE103

AlteringCave1FV2_MapBGEvents::

AlteringCave1FV2_MapEvents::
	map_events AlteringCave1FV2_EventObjects, AlteringCave1FV2_MapWarps, 0x0, AlteringCave1FV2_MapBGEvents
