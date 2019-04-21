GraniteCave_B4F_MapScripts::
	.byte 0

GraniteCave_B4F_EventScript_BrailleWallMorning::
	lockall
	braillemessage GraniteCave_B4F_BrailleMorning
	waitbuttonpress
	erasebox 0, 0, 29, 19
	releaseall
	end

GraniteCave_B4F_EventScript_BrailleWallDay::
	lockall
	braillemessage GraniteCave_B4F_BrailleDay
	waitbuttonpress
	erasebox 0, 0, 29, 19
	releaseall
	end

GraniteCave_B4F_EventScript_BrailleWallNight::
	lockall
	braillemessage GraniteCave_B4F_BrailleNight
	waitbuttonpress
	erasebox 0, 0, 29, 19
	releaseall
	end
