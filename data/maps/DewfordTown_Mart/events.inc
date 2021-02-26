DewfordTown_Mart_EventObjects::
	object_event 1, EVENT_OBJ_GFX_MART_EMPLOYEE, 0, 1, 3, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, Common_EventScript_StandardMart, 0
	object_event 2, EVENT_OBJ_GFX_MAN_2, 0, 9, 4, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, DewfordTown_Mart_EventScript_RandomNPC, 0
	object_event 3, EVENT_OBJ_GFX_MART_EMPLOYEE, 0, 1, 2, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, DewfordTown_Mart_EventScript_1552B0, 0

DewfordTown_Mart_MapWarps::
	warp_def 3, 7, 0, 5, MAP_DEWFORD_TOWN
	warp_def 4, 7, 0, 5, MAP_DEWFORD_TOWN

DewfordTown_Mart_MapEvents::
	map_events DewfordTown_Mart_EventObjects, DewfordTown_Mart_MapWarps, 0x0, 0x0
