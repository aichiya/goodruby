TopSecretArea_EventObjects::
	object_event 1, EVENT_OBJ_GFX_ITEM_BALL, 0, 24, 16, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, TopSecretArea_EternalNugget, 0
	object_event 2, EVENT_OBJ_GFX_PUSHABLE_BOULDER, 0, 24, 17, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, TopSecretArea_MoulderTheBoulder, 0
    object_event 3, EVENT_OBJ_GFX_TORCHIC_DOLL, 0, 3, 3, 3, MOVEMENT_TYPE_LOOK_AROUND, 0, 0, 0, 0, TopSecretArea_TorchicDoll, 0
    object_event 4, EVENT_OBJ_GFX_MACHOKE_CARRYING_BOX, 0, 4, 18, 3, MOVEMENT_TYPE_WALK_RIGHT_AND_LEFT, 3, 0, 0, 0, TopSecretArea_Machoke, 0
	object_event 5, EVENT_OBJ_GFX_MANIAC, 0, 22, 3, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, TopSecretArea_HackLord, 0

TopSecretArea_MapWarps::
	warp_def 15, 30, 0, 3, MAP_LILYCOVE_CITY_COVE_LILY_MOTEL_1F

TopSecretArea_MapBGEvents::
	bg_event 3, 17, 0, BG_EVENT_PLAYER_FACING_ANY, TopSecretArea_Computer1
	bg_event 4, 17, 0, BG_EVENT_PLAYER_FACING_ANY, TopSecretArea_Computer2
	bg_event 5, 17, 0, BG_EVENT_PLAYER_FACING_ANY, TopSecretArea_Computer3
	bg_event 6, 17, 0, BG_EVENT_PLAYER_FACING_ANY, TopSecretArea_Computer4
	bg_event 7, 17, 0, BG_EVENT_PLAYER_FACING_ANY, TopSecretArea_Computer5
	bg_event 8, 17, 0, BG_EVENT_PLAYER_FACING_ANY, TopSecretArea_Computer6
	bg_event 13, 26, 0, BG_EVENT_PLAYER_FACING_ANY, TopSecretArea_Plaque
	bg_event 17, 26, 0, BG_EVENT_PLAYER_FACING_ANY, TopSecretArea_Plaque
    
TopSecretArea_MapEvents::
	map_events TopSecretArea_EventObjects, TopSecretArea_MapWarps, 0x0, TopSecretArea_MapBGEvents
