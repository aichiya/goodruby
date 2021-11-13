GraniteCave_Underwater_MapScripts::
	map_script 6, GraniteCave_Underwater_MapScriptStart
	.byte 0

GraniteCave_Underwater_MapScriptStart::
	getplayerxy VAR_SPECIAL_4, VAR_SPECIAL_5
	compare VAR_SPECIAL_5, 10
	goto_if_ge GraniteCave_Underwater_MapScript_To4F
	goto GraniteCave_Underwater_MapScript_ToLugia

GraniteCave_Underwater_MapScript_To4F:: @ 815F0A6
	setdivewarp MAP_GRANITE_CAVE_B4F, 255, 15, 12
	end

GraniteCave_Underwater_MapScript_ToLugia:: @ 815F0AF
	setdivewarp MAP_GRANITE_CAVE_LUGIA_CHAMBER, 255, 15, 27
	end