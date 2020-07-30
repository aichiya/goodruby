NewMauville_Inside_B3F_EventObjects::
    object_event 1, EVENT_OBJ_GFX_ITEM_BALL, 0, 1, 14, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0, 0
    object_event 2, EVENT_OBJ_GFX_ITEM_BALL, 0, 13, 20, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0, 0
    object_event 3, EVENT_OBJ_GFX_ITEM_BALL, 0, 24, 18, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0, 0
    object_event 4, EVENT_OBJ_GFX_ITEM_BALL, 0, 3, 14, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0, 0
    object_event 5, EVENT_OBJ_GFX_ITEM_BALL, 0, 6, 15, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0, 0
    object_event 6, EVENT_OBJ_GFX_ITEM_BALL, 0, 5, 17, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0, 0
    object_event 7, EVENT_OBJ_GFX_ITEM_BALL, 0, 9, 19, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0, 0
    object_event 8, EVENT_OBJ_GFX_ITEM_BALL, 0, 15, 17, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0, 0
    object_event 9, EVENT_OBJ_GFX_ITEM_BALL, 0, 19, 15, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0, 0
    object_event 10, EVENT_OBJ_GFX_ITEM_BALL, 0, 16, 11, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0, 0
    object_event 11, EVENT_OBJ_GFX_ITEM_BALL, 0, 9, 11, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, 0, 0
    object_event 12, EVENT_OBJ_GFX_GOLD_BALL, 0, 12, 13, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, NewMauville_Inside_B3F_EventScript_Item, FLAG_HIDE_MAUVILLEBF3_ITEM

NewMauville_Inside_B3F_MapWarps::
	warp_def 16, 13, 3, 1, MAP_NEW_MAUVILLE_INSIDE_B2F
	warp_def 10, 13, 3, 2, MAP_NEW_MAUVILLE_INSIDE_B2F

NewMauville_Inside_B3F_MapEvents::
	map_events NewMauville_Inside_B3F_EventObjects, NewMauville_Inside_B3F_MapWarps, 0x0, 0x0
