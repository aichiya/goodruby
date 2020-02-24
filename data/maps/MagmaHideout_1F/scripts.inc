MagmaHideout_1F_MapScripts:: @ 815F2A7
	.byte 0

MagmaHideout_1F_EventScript_MagmaGrunt1::
	trainerbattle 2, TRAINER_HIDEOUT_1F_GRUNT, 0, MagmaHideout_1F_Text_MagmaGruntSee, MagmaHideout_1F_Text_MagmaGruntFight, MagmaHideout_1F_EventScript_MagmaGrunt1Post
	msgbox MagmaHideout_1F_Text_MagmaGruntPost, 6
	end

MagmaHideout_1F_EventScript_MagmaGrunt1Post::
	msgbox MagmaHideout_1F_Text_MagmaGruntPost, 4
	release
	end

MagmaHideout_1F_EventScript_AquaGrunt1::
	trainerbattle 2, TRAINER_HIDEOUT_1F_GRUNT, 0, MagmaHideout_1F_Text_AquaGruntSee, MagmaHideout_1F_Text_AquaGruntFight, MagmaHideout_1F_EventScript_AquaGrunt1Post
	msgbox AquaHideout_1F_Text_196E3D, 6
	end

MagmaHideout_1F_EventScript_AquaGrunt1Post::
	msgbox MagmaHideout_1F_Text_AquaGruntPost, 4
	release
	end