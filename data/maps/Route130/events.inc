Route130_EventObjects:: @ 838523C
	object_event 1, EVENT_OBJ_GFX_SWIMMER_M, 0, 7, 26, 1, MOVEMENT_TYPE_WALK_SEQUENCE_UP_RIGHT_LEFT_DOWN, 3, 6, 1, 3, Route130_EventScript_152410, 0
	object_event 2, EVENT_OBJ_GFX_SWIMMER_F, 0, 68, 22, 1, MOVEMENT_TYPE_FACE_DOWN_AND_UP, 1, 1, 1, 3, Route130_EventScript_152427, 0
	object_event 3, EVENT_OBJ_GFX_BERRY_TREE, 0, 52, 9, 3, MOVEMENT_TYPE_BERRY_TREE_GROWTH, 0, 0, 0, 82, S_BerryTree, FLAG_TEMP_11
	object_event 4, EVENT_OBJ_GFX_CELEBI, 0, 38, 5, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, Route130_EventScript_Celebi, FLAG_HIDE_CELEBI

Route130_MapBGEvents:
    bg_event 38, 5, 0, BG_EVENT_PLAYER_FACING_ANY, Route130_EventScript_Shrine
    bg_event 39, 5, 0, BG_EVENT_PLAYER_FACING_ANY, Route130_EventScript_Shrine

Route130_MapEvents:: @ 8385284
	map_events Route130_EventObjects, 0x0, 0x0, Route130_MapBGEvents
