GnarledRidge_MapScripts::
	.byte 0

GnarledRidge_EventScript_Trainer1::
	trainerbattle 0, TRAINER_JIMMY, 0, GnarledRidge_Text_Trainer1Meet, GnarledRidge_Text_Trainer1Beat
	msgbox GnarledRidge_Text_Trainer1Chat, 6
	end

GnarledRidge_EventScript_Trainer2::
	trainerbattle 0, TRAINER_OLIVER, 0, GnarledRidge_Text_Trainer2Meet, GnarledRidge_Text_Trainer2Beat
	msgbox GnarledRidge_Text_Trainer2Chat, 6
	end

GnarledRidge_EventScript_Trainer3::
	trainerbattle 0, TRAINER_BRADY, 0, GnarledRidge_Text_Trainer3Meet, GnarledRidge_Text_Trainer3Beat
	msgbox GnarledRidge_Text_Trainer3Chat, 6
	end

