SealedChamber_InnerRoom_EventObjects::
	object_event 1, EVENT_OBJ_GFX_MEW, 0, 10, 12, 3, MOVEMENT_TYPE_FACE_DOWN, 0, 0, 0, 0, SealedChamber_InnerRoom_EventScript_Mew, FLAG_HIDE_MEW

SealedChamber_InnerRoom_MapWarps:: @ 838E900
	warp_def 10, 19, 3, 0, MAP_SEALED_CHAMBER_OUTER_ROOM

SealedChamber_InnerRoom_MapEvents:: @ 838E974
	map_events SealedChamber_InnerRoom_EventObjects, SealedChamber_InnerRoom_MapWarps, 0x0, 0x0
