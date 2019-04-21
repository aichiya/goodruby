GraniteCave_B3F_MapScripts::
	map_script 2, GraniteCave_B1F_MapScript2_1C6BB5
	map_script 3, GraniteCave_B1F_MapScript1_1C6BBF
	map_script 5, GraniteCave_B3F_MapScript1_SetHoles
	map_script 1, GraniteCave_B3F_MapScript1_RepairCliff
	.byte 0

GraniteCave_B3F_MapScript1_SetHoles:: @ 815CBED
	setstepcallback 7
	setholewarp MAP_GRANITE_CAVE_B4F, 255, 0, 0
	end

GraniteCave_B3F_MapScript1_RepairCliff:
	call_if_set FLAG_TEMP_F, GraniteCave_B3F_MapScript1_DoRepairCliff
	end

GraniteCave_B3F_MapScript1_DoRepairCliff:
	setmetatile 17, 13, 513, 0
	setmetatile 18, 13, 513, 0
	setmetatile 19, 13, 513, 0
	return

GraniteCave_B3F_EventScript_BrailleWall::
	lockall
	braillemessage GraniteCave_B3F_Braille
	waitbuttonpress
	erasebox 0, 0, 29, 19
	releaseall
	end
