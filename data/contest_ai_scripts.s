	.include "asm/macros.s"
	.include "asm/macros/contest_ai_script.s"
	.include "constants/constants.s"

	.section script_data, "aw", %progbits

	.align 2
gUnknown_081DC118:: @ 81DC118
	.4byte Unknown_081DC7FB
	.4byte Unknown_081DC348
	.4byte Unknown_081DC27F
	.4byte Unknown_081DC2AB
	.4byte Unknown_081DCA4C
	.4byte Unknown_081DC3C7
	.4byte Unknown_081DC7DE
	.4byte Unknown_081DCAF3
	.4byte Unknown_081DCAF3
	.4byte Unknown_081DCAF3
	.4byte Unknown_081DCAF3
	.4byte Unknown_081DCAF3
	.4byte Unknown_081DCAF3
	.4byte Unknown_081DCAF3
	.4byte Unknown_081DCAF3
	.4byte Unknown_081DCAF3
	.4byte Unknown_081DCAF3
	.4byte Unknown_081DCAF3
	.4byte Unknown_081DCAF3
	.4byte Unknown_081DCAF3
	.4byte Unknown_081DCAF3
	.4byte Unknown_081DCAF3
	.4byte Unknown_081DCAF3
	.4byte Unknown_081DCAF3
	.4byte Unknown_081DCAF3
	.4byte Unknown_081DCAF3
	.4byte Unknown_081DCAF3
	.4byte Unknown_081DCAF3
	.4byte Unknown_081DCAF3
	.4byte Unknown_081DCAF3
	.4byte Unknown_081DCAF3
	.4byte Unknown_081DCAF3

	@ unreferenced
	if_turn_not_eq 0x00 ContestUnreferenced_80
	if_effect_not_eq 0x26 ContestUnreferenced_80
	score 0x0A
ContestUnreferenced_80:
	call ContestUnreferenced_0D
	end
ContestUnreferenced_0D:
	if_user_order_more_than 0x01 ContestUnreferenced_end
	if_effect_type_not_eq 0x02 ContestUnreferenced_end
	if_effect_type_not_eq 0x03 ContestUnreferenced_end
	score 0x0A
ContestUnreferenced_end:
	end
	if_turn_eq 0x00 ContestUnreferenced_0F_1
	if_turn_eq 0x01 ContestUnreferenced_0F_2
	if_turn_eq 0x02 ContestUnreferenced_0F_3
	if_turn_eq 0x03 ContestUnreferenced_0F_4
	if_turn_eq 0x04 ContestUnreferenced_0F_5
	end
ContestUnreferenced_0F_1:
	if_user_order_not_eq 0x00 ContestUnreferenced_2B_1
	if_user_order_not_eq 0x01 ContestUnreferenced_2B_2
	if_user_order_not_eq 0x02 ContestUnreferenced_2B_1
	if_user_order_not_eq 0x03 ContestUnreferenced_2B_1
	end
ContestUnreferenced_2B_1:
	if_effect_type_eq 0x01 ContestUnreferenced_score
	end
ContestUnreferenced_2B_2:
	if_effect_type_eq 0x01 ContestUnreferenced_score
	end
	if_effect_type_eq 0x01 ContestUnreferenced_score
	end
ContestUnreferenced_0F_2:
	if_user_order_not_eq 0x00 ContestUnreferenced_2B_1
	if_user_order_not_eq 0x01 ContestUnreferenced_2B_1
	if_user_order_not_eq 0x02 ContestUnreferenced_2B_1
	if_user_order_not_eq 0x03 ContestUnreferenced_2B_1
	end
ContestUnreferenced_0F_3:
	if_user_order_not_eq 0x00 ContestUnreferenced_2B_1
	if_user_order_not_eq 0x01 ContestUnreferenced_2B_1
	if_user_order_not_eq 0x02 ContestUnreferenced_2B_1
	if_user_order_not_eq 0x03 ContestUnreferenced_2B_1
	end
ContestUnreferenced_0F_4:
	if_user_order_not_eq 0x00 ContestUnreferenced_2B_1
	if_user_order_not_eq 0x01 ContestUnreferenced_2B_1
	if_user_order_not_eq 0x02 ContestUnreferenced_2B_1
	if_user_order_not_eq 0x03 ContestUnreferenced_2B_1
	end
ContestUnreferenced_0F_5:
	if_user_order_not_eq 0x00 ContestUnreferenced_2B_1
	if_user_order_not_eq 0x01 ContestUnreferenced_2B_1
	if_user_order_not_eq 0x02 ContestUnreferenced_2B_1
	if_user_order_not_eq 0x03 ContestUnreferenced_2B_1
	end
ContestUnreferenced_score:
	score 0x0A
	end
	end
	if_most_appealing_move ContestUnreferenced_score2
	end
ContestUnreferenced_score2:
	score 0x0A
	end

Unknown_081DC27F:
	if_effect_eq 3, AI_end_081DC27F
	if_move_used_count_eq 1 AI_score1_081DC27F
	if_move_used_count_eq 2 AI_score2_081DC27F
	if_move_used_count_eq 3 AI_score3_081DC27F
	if_move_used_count_eq 4 AI_score4_081DC27F
	end
AI_score1_081DC27F:
	score 0xFB
	end
AI_score2_081DC27F:
	score 0xF1
	end
AI_score3_081DC27F:
	score 0xEC
	end
AI_score4_081DC27F:
	score 0xE7
	end
AI_end_081DC27F:
	end

Unknown_081DC2AB:
	if_move_excitement_less_than 0x00 AI_contest09_081DC2AB
	if_move_excitement_eq 0x00 AI_contest7D_4_081DC2AB
	if_move_excitement_eq 0x01 AI_contest3D_081DC2AB
	end
AI_contest09_081DC2AB:
	if_excitement_eq 0x04 AI_contest0F_1_081DC2AB
	if_excitement_eq 0x03 AI_contest0F_2_081DC2AB
	if_user_has_exciting_move AI_end_081DC2AB
	score 0x0F
	end
AI_contest0F_1_081DC2AB:
	if_user_order_not_eq 0x00 AI_contest7D_1_081DC2AB
	if_random 0x33 AI_end_081DC2AB
	score 0x14
	end
AI_contest7D_1_081DC2AB:
	if_random 0x7F AI_end_081DC2AB
	score 0xF6
	end
AI_contest0F_2_081DC2AB:
	if_user_order_not_eq 0x00 AI_contest7D_3_081DC2AB
	if_turn_eq 0x04 AI_score_081DC2AB
AI_contest7D_2_081DC2AB:
	if_random 0x33 AI_end_081DC2AB
	score 0x0A
	end
AI_score_081DC2AB:
	score 0x0F
	end
AI_contest7D_3_081DC2AB:
	if_random 0x7F AI_end_081DC2AB
	score 0x0A
	end
AI_contest7D_4_081DC2AB:
	if_random 0x7F AI_end_081DC2AB
	score 0x0A
	end
AI_contest3D_081DC2AB:
	if_move_used_count_more_than 0x00 AI_contest29_081DC2AB
	if_user_order_not_eq 0x00 AI_contest7D_5_081DC2AB
	if_excitement_not_eq 0x04 AI_contest7D_5_081DC2AB
	score 0x1E
	end
AI_contest7D_5_081DC2AB:
	if_random 0x64 AI_end_081DC2AB
	score 0x0A
	end
AI_contest29_081DC2AB:
	if_effect_not_eq 0x03 AI_end_081DC2AB
	if_user_order_not_eq 0x00 AI_contest7D_5_081DC2AB
	if_excitement_not_eq 0x04 AI_contest7D_5_081DC2AB
	score 0x1E
	end
AI_end_081DC2AB:
	end

Unknown_081DC348:
	if_would_finish_combo AI_score_081DC348
	call AI_contest3F_081DC348
	call AI_contest45_081DC348
	end
AI_contest3F_081DC348:
	if_move_used_count_not_eq 0x00 AI_end_081DC348
	if_not_combo_starter AI_end_081DC348
	if_user_order_eq 0x00 AI_contest04_1_081DC348
	if_user_order_eq 0x01 AI_contest04_2_081DC348
	if_user_order_eq 0x02 AI_contest04_3_081DC348
	if_user_order_eq 0x03 AI_contest04_4_081DC348
	end
AI_contest45_081DC348:
	if_not_combo_finisher AI_end_081DC348
	score 0xF6
	end
AI_score_081DC348:
	score 0x19
	end
AI_contest04_1_081DC348:
	if_turn_eq 0x04 AI_contest7D_081DC348
	if_random 0x96 AI_end_081DC348
	score 0x0A
	end
AI_contest04_2_081DC348:
	if_turn_eq 0x04 AI_contest7D_081DC348
	if_random 0x7D AI_end_081DC348
	score 0x0A
	end
AI_contest04_3_081DC348:
	if_turn_eq 0x04 AI_contest7D_081DC348
	if_random 0x32 AI_end_081DC348
	score 0x0A
	end
AI_contest04_4_081DC348:
	if_turn_eq 0x04 AI_contest7D_081DC348
	score 0x0A
	end
AI_contest7D_081DC348:
	if_random 0x7D AI_end_081DC348
	score 0xF1
	end
AI_end_081DC348:
	end

Unknown_081DC3C7:
	if_effect_eq 39, ContestEffect39
	if_effect_eq 40, ContestEffect40
	if_effect_eq 41, ContestEffect41
	if_effect_eq 3, ContestEffect3
	if_effect_eq 38, ContestEffect38
	if_effect_eq 47, ContestEffect47
	if_effect_eq 31, ContestEffect31
	if_effect_eq 32, ContestEffect32
	if_effect_eq 46, ContestEffect46
	if_effect_eq 27, ContestEffect27
	if_effect_eq 16, ContestEffect16or17
	if_effect_eq 17, ContestEffect16or17
	if_effect_eq 26, ContestEffect_FollowingMonsNervous
	if_effect_eq 18, ContestEffect18
	end

ContestEffect39:
	if_user_condition_eq 0x03 ContestEffect39_score1
	if_user_condition_eq 0x02 ContestEffect39_score2
	if_user_condition_eq 0x01 ContestEffect39_score3
	if_user_condition_eq 0x00 ContestEffect39_score4
	end
ContestEffect39_score1:
	score 0x14
	end
ContestEffect39_score2:
	if_random 0x7D ContestEffectEnd
	score 0x0F
	end
ContestEffect39_score3:
	if_random 0x7D ContestEffectEnd
	score 0x05
	end
ContestEffect39_score4:
	score 0xEC
	end

ContestEffect40:
	if_effect_in_user_moveset 0x1D ContestEffectEnd
	if_random 0x32 ContestEffectEnd
	score 0x14
	end

ContestEffect41:
	if_effect_in_user_moveset 0x1E ContestEffectEnd
	if_random 0x32 ContestEffectEnd
	score 0x14
	end

ContestEffect3:
	if_user_order_not_eq 0x03 ContestEffectEnd
	if_random 0x32 ContestEffectEnd
	score 0x0F
	end
	if_turn_eq 0x04 ContestEffect3_7D
	if_random 0xDC ContestEffect3_score
	score 0x0A
	end
ContestEffect3_7D:
	if_random 0x14 ContestEffectEnd
	score 0x0F
	end
ContestEffect3_score:
	score 0xEC
	end

ContestEffect38:
	if_effect_in_user_moveset 0x27 ContestEffect38_contest04
	if_user_condition_eq 0x03 ContestEffect38_score1
	if_random 0x32 ContestEffectEnd
	score 0x0F
	end
ContestEffect38_score1:
	score 0xF6
	end
ContestEffect38_contest04:
	if_turn_eq 0x04 ContestEffect38_score2
	if_turn_eq 0x00 ContestEffect38_random
	if_move_used_count_eq 1 ContestEffectEnd
	if_random 0x7D ContestEffectEnd
	score 0x0A
	end
ContestEffect38_random:
	if_random 0x64 ContestEffectEnd
	score 0x0A
	end
ContestEffect38_score2:
	score 0xF6
	end

ContestEffect47:
	if_move_used_count_eq 1 ContestEffectEnd
	if_user_order_eq 0x00 ContestEffect47_random
	if_user_order_eq 0x01 ContestEffect47_random
	if_turn_not_eq 0x04 ContestEffectEnd
	if_user_has_exciting_move ContestEffectEnd
	if_excitement_less_than 0x01 ContestEffectEnd
	score 0x0A
	end
ContestEffect47_random:
	if_random 0x7F ContestEffectEnd
	score 0x0A
	end

ContestEffect31:
	if_user_order_eq 0x01 ContestEffect31_score1
	if_user_order_eq 0x02 ContestEffect31_score2
	if_user_order_eq 0x03 ContestEffect31_score3
	end
ContestEffect31_score1:
	score 0x05
	end
ContestEffect31_score2:
	score 0x0F
	end
ContestEffect31_score3:
	score 0x14
	end

ContestEffect32:
	if_user_order_eq 0x00 ContestEffect32_score1
	if_user_order_eq 0x01 ContestEffect32_score2
	if_user_order_eq 0x02 ContestEffect32_score3
	if_user_order_eq 0x03 ContestEffect32_score5
	end
ContestEffect32_score1:
	score 0xF6
	end
ContestEffect32_score2:
	contest_55 0x00 ContestEffectEnd
	score 0x05
	end
ContestEffect32_score3:
	contest_55 0x00 ContestEffect32_score4
	score 0x05
	jump ContestEffect32_score4
	end
ContestEffect32_score4:
	contest_55 0x01 ContestEffectEnd
	score 0x05
	end
ContestEffect32_score5:
	contest_55 0x00 ContestEffect32_score6
	score 0x05
	jump ContestEffect32_score6
	end
ContestEffect32_score6:
	contest_55 0x01 ContestEffect32_score7
	score 0x05
	jump ContestEffect32_score7
	end
ContestEffect32_score7:
	contest_55 0x02 ContestEffectEnd
	score 0x05
	end

ContestEffect46:
	if_user_order_eq 0x00 ContestEffect46_05
	if_user_order_more_than 0x00 ContestEffect46_score4
	end
ContestEffect46_05:
	if_turn_not_eq 0x00 ContestEffect46_score1
	if_excitement_eq 0x04 ContestEffect46_score2
	if_excitement_eq 0x03 ContestEffect46_score3
	end
ContestEffect46_score1:
	if_random 0x7D ContestEffectEnd
	score 0xF1
	end
ContestEffect46_score2:
	if_random 0x7D ContestEffectEnd
	score 0x14
	end
ContestEffect46_score3:
	if_random 0x7D ContestEffectEnd
	score 0x0F
	end
ContestEffect46_score4:
	if_random 0xB2 ContestEffectEnd
	score 0x0A
	end

ContestEffect27:
	if_user_order_eq 0x00 ContestEffectEnd
	jump ContestEffect27_55_1
	end
ContestEffect27_55_1:
	contest_55 0x00 ContestEffect27_noscore
	if_condition_eq 0x00 0x00 ContestEffect27_noscore
	if_condition_eq 0x00 0x01 ContestEffect27_score1
	if_condition_eq 0x00 0x02 ContestEffect27_score2
	if_condition_eq 0x00 0x03 ContestEffect27_score3
	end
ContestEffect27_score1:
	if_random 0x7D ContestEffect27_55_2
	score 0x05
	if_user_order_more_than 0x01 ContestEffect27_55_2
	end
ContestEffect27_score2:
	if_random 0x7D ContestEffect27_55_2
	score 0x0A
	if_user_order_more_than 0x01 ContestEffect27_55_2
	end
ContestEffect27_score3:
	if_random 0x7D ContestEffect27_55_2
	score 0x0F
	if_user_order_more_than 0x01 ContestEffect27_55_2
	end
ContestEffect27_noscore:
	if_user_order_more_than 0x01 ContestEffect27_55_2
	end
ContestEffect27_55_2:
	contest_55 0x01 ContestEffect27_noscore2
	if_condition_eq 0x01 0x00 ContestEffect27_noscore2
	if_condition_eq 0x01 0x01 ContestEffect27_score4
	if_condition_eq 0x01 0x02 ContestEffect27_score5
	if_condition_eq 0x01 0x03 ContestEffect27_score6
	end
ContestEffect27_score4:
	if_random 0x7D ContestEffect27_55_3
	score 0x05
	if_user_order_more_than 0x02 ContestEffect27_55_3
	end
ContestEffect27_score5:
	if_random 0x7D ContestEffect27_55_3
	score 0x0A
	if_user_order_more_than 0x02 ContestEffect27_55_3
	end
ContestEffect27_score6:
	if_random 0x7D ContestEffect27_55_3
	score 0x0F
	if_user_order_more_than 0x02 ContestEffect27_55_3
	end
ContestEffect27_noscore2:
	if_user_order_more_than 0x02 ContestEffect27_55_3
	end
ContestEffect27_55_3:
	contest_55 0x02 ContestEffect27_end
	if_condition_eq 0x02 0x00 ContestEffect27_end
	if_condition_eq 0x02 0x01 ContestEffect27_score7
	if_condition_eq 0x02 0x02 ContestEffect27_score8
	if_condition_eq 0x02 0x03 ContestEffect27_score9
	end
ContestEffect27_score7:
	if_random 0x7D ContestEffectEnd
	score 0x05
	end
ContestEffect27_score8:
	if_random 0x7D ContestEffectEnd
	score 0x0A
	end
ContestEffect27_score9:
	if_random 0x7D ContestEffectEnd
	score 0x0F
	end
ContestEffect27_end:
	end

ContestEffect16or17:
	if_user_order_eq 0x00 ContestEffectEnd
	jump ContestEffect16or17_55
	end
ContestEffect16or17_55:
	contest_55 0x00 ContestEffect16or17_0E_1
	contest_51 0x00 0x01 ContestEffect16or17_0E_1
	if_random 0x7D ContestEffect16or17_0E_1
	score 0x02
	contest_58 0x00 ContestEffect16or17_0E_1
	score 0x08
	end
ContestEffect16or17_0E_1:
	if_user_order_eq 0x01 ContestEffectEnd
	contest_55 0x01 ContestEffect16or17_0E_2
	contest_51 0x01 0x01 ContestEffect16or17_0E_2
	if_random 0x7D ContestEffect16or17_0E_2
	score 0x02
	contest_58 0x01 ContestEffect16or17_0E_2
	score 0x08
	end
ContestEffect16or17_0E_2:
	if_user_order_eq 0x02 ContestEffectEnd
	contest_55 0x02 ContestEffectEnd
	contest_51 0x02 0x01 ContestEffectEnd
	if_random 0x7D ContestEffectEnd
	score 0x02
	contest_58 0x02 ContestEffectEnd
	score 0x08
	end

@ This routine checks the following mons using contest_51 and contest_55
@ in order to decide if moves that make the following mons nervous should
@ be encouraged.
ContestEffect_FollowingMonsNervous:
	if_user_order_eq 3, ContestEffectEnd
	jump ContestEffect_FollowingMonsNervous_CheckMon3
	end
ContestEffect_FollowingMonsNervous_CheckMon3:
	contest_55 0x03, ContestEffect_FollowingMonsNervous_CheckMon2
	contest_51 0x03, 0x00, ContestEffect_FollowingMonsNervous_CheckMon2
	score +5
	if_random 125, ContestEffect16or17_0E_1
	score +5
	end
ContestEffect_FollowingMonsNervous_CheckMon2:
	if_user_order_eq 2, ContestEffectEnd
	contest_55 0x02, ContestEffect_FollowingMonsNervous_CheckMon1
	contest_51 0x02, 0x00, ContestEffect_FollowingMonsNervous_CheckMon1
	score +5
	if_random 125, ContestEffect16or17_0E_2
	score +5
	end
ContestEffect_FollowingMonsNervous_CheckMon1:
	if_user_order_eq 1, ContestEffectEnd
	contest_55 0x01, ContestEffectEnd
	contest_51 0x01, 0x00 ContestEffectEnd
	score +5
	if_random 125, ContestEffectEnd
	score +5
	end

ContestEffect18:
	if_turn_eq 0x04 ContestEffect18_score1
	jump ContestEffect18_0E
	end
ContestEffect18_score1:
	score 0x05
	jump ContestEffect18_0E
	end
ContestEffect18_0E:
	if_user_order_eq 0x00 ContestEffect18_score2
	if_user_order_eq 0x01 ContestEffect18_random1
	if_user_order_eq 0x02 ContestEffect18_random2
	if_user_order_eq 0x03 ContestEffect18_random3
	end
ContestEffect18_score2:
	score 0xF1
	end
ContestEffect18_random1:
	if_random 0x7D ContestEffectEnd
	score 0xF6
	end
ContestEffect18_random2:
	if_random 0x7D ContestEffectEnd
	score 0x05
	end
ContestEffect18_random3:
	if_random 0x7D ContestEffectEnd
	score 0x0F
	end

ContestEffectEnd:
	end

Unknown_081DC7DE:
	if_contest_type_eq CONTEST_CUTE, AI_contest7D_081DC7DE
	if_contest_type_eq CONTEST_SMART, AI_contest7D_081DC7DE
	if_contest_type_eq CONTEST_TOUGH, AI_contest7D_081DC7DE
	end
AI_contest7D_081DC7DE:
	if_random 0x7D AI_end_081DC7DE
	score 0x0A
	end
AI_end_081DC7DE:
	end

Unknown_081DC7FB:
	if_effect_eq 8, ContestEffect2_8
	if_effect_eq 10, ContestEffect2_8
	if_effect_eq 12, ContestEffect2_8
	if_effect_eq 14, ContestEffect2_8
	if_effect_eq 32, ContestEffect2_8
	if_effect_eq 35, ContestEffect2_8
	if_effect_eq 36, ContestEffect2_8
	if_effect_eq 37, ContestEffect2_8
	if_effect_eq 9, ContestEffect2_9
	if_effect_eq 11, ContestEffect2_9
	if_effect_eq 13, ContestEffect2_9
	if_effect_eq 15, ContestEffect2_9
	if_effect_eq 17, ContestEffect2_9
	if_effect_eq 16, ContestEffect2_9
	if_effect_eq 18, ContestEffect2_9
	if_effect_eq 19, ContestEffect2_9
	if_effect_eq 45, ContestEffect2_9
	if_effect_eq 20, ContestEffect2_9
	if_effect_eq 21, ContestEffect2_9
	if_effect_eq 22, ContestEffect2_9
	if_effect_eq 23, ContestEffect2_9
	if_effect_eq 24, ContestEffect2_9
	if_effect_eq 28, ContestEffect2_9
	if_effect_eq 27, ContestEffect2_9
	if_effect_eq 31, ContestEffect2_9
	if_effect_eq 25, ContestEffect2_25
	if_effect_eq 26, ContestEffect2_26
	if_effect_eq 47, ContestEffect2_26
	if_effect_eq 38, ContestEffect2_38
	if_effect_eq 4, ContestEffect2_4
	if_effect_eq 5, ContestEffect2_4
	if_effect_eq 6, ContestEffect2_4
	if_effect_eq 2, ContestEffect2_2
	end

ContestEffect2_8:
	if_user_order_eq 0x00 ContestEffect2_8_score1
	if_user_order_eq 0x01 ContestEffect2_8_score2
	if_user_order_eq 0x02 ContestEffect2_8_score3
	if_user_order_eq 0x03 ContestEffect2_8_score4
	end
ContestEffect2_8_score1:
	score 0xF6
	end
ContestEffect2_8_score2:
	contest_54 0x00 ContestEffectEnd2
	score 0xF6
	end
ContestEffect2_8_score3:
	contest_54 0x01 ContestEffectEnd2
	score 0xF6
	end
ContestEffect2_8_score4:
	contest_54 0x02 ContestEffectEnd2
	score 0xF6
	end

ContestEffect2_9:
	if_user_order_eq 0x00 ContestEffect2_9_score1
	if_user_order_eq 0x01 ContestEffect2_9_score2
	if_user_order_eq 0x02 ContestEffect2_9_score3
	if_user_order_eq 0x03 ContestEffect2_9_score4
	end
ContestEffect2_9_score1:
	score 0xEC
	end
ContestEffect2_9_score2:
	contest_54 0x00 ContestEffectEnd2
	score 0xF1
	end
ContestEffect2_9_score3:
	contest_54 0x00 ContestEffectEnd2
	contest_54 0x01 ContestEffectEnd2
	score 0xF1
	end
ContestEffect2_9_score4:
	contest_54 0x00 ContestEffectEnd2
	contest_54 0x01 ContestEffectEnd2
	contest_54 0x02 ContestEffectEnd2
	score 0xF1
	end

ContestEffect2_25:
	if_user_order_eq 0x00 ContestEffect2_25_score1
	if_user_order_eq 0x01 ContestEffect2_25_score2
	if_user_order_eq 0x02 ContestEffect2_25_score3
	score 0xF6
	end
ContestEffect2_25_score1:
	contest_54 0x01 ContestEffectEnd2
	score 0xF6
	end
ContestEffect2_25_score2:
	contest_54 0x02 ContestEffectEnd2
	score 0xF6
	end
ContestEffect2_25_score3:
	contest_54 0x03 ContestEffectEnd2
	score 0xF6
	end

ContestEffect2_26:
	if_user_order_eq 0x00 ContestEffect2_26_score1
	if_user_order_eq 0x01 ContestEffect2_26_score2
	if_user_order_eq 0x02 ContestEffect2_26_score3
	score 0xF6
	end
ContestEffect2_26_score1:
	contest_54 0x01 ContestEffectEnd2
	contest_54 0x02 ContestEffectEnd2
	contest_54 0x03 ContestEffectEnd2
	score 0xF6
	end
ContestEffect2_26_score2:
	contest_54 0x02 ContestEffectEnd2
	contest_54 0x03 ContestEffectEnd2
	score 0xF6
	end
ContestEffect2_26_score3:
	contest_54 0x03 ContestEffectEnd2
	score 0xF6
	end

ContestEffect2_38:
	if_user_condition_less_than 0x03 ContestEffectEnd2
	score 0xEC
	end

ContestEffect2_4:
	if_user_order_eq 0x00 ContestEffect2_4_score1
	if_user_order_eq 0x01 ContestEffect2_4_score2
	if_user_order_eq 0x02 ContestEffect2_4_score3
	score 0xF6
	end
ContestEffect2_4_score1:
	contest_54 0x01 ContestEffectEnd2
	contest_54 0x02 ContestEffectEnd2
	contest_54 0x03 ContestEffectEnd2
	score 0xF6
	end
ContestEffect2_4_score2:
	contest_54 0x02 ContestEffectEnd2
	contest_54 0x03 ContestEffectEnd2
	score 0xF6
	end
ContestEffect2_4_score3:
	contest_54 0x03 ContestEffectEnd2
	score 0xF6
	end

ContestEffect2_2:
	if_turn_eq 0x00 ContestEffect2_2_score1
	if_turn_eq 0x01 ContestEffect2_2_score2
	if_turn_eq 0x02 ContestEffect2_2_score3
	if_turn_eq 0x03 ContestEffect2_2_score4
	if_turn_eq 0x04 ContestEffect2_2_score5
	end
ContestEffect2_2_score1:
	if_random 0x14 ContestEffectEnd2
	score 0xF1
	end
ContestEffect2_2_score2:
	if_random 0x28 ContestEffectEnd2
	score 0xF1
	end
ContestEffect2_2_score3:
	if_random 0x3C ContestEffectEnd2
	score 0xF1
	end
ContestEffect2_2_score4:
	if_random 0x50 ContestEffectEnd2
	score 0xF1
	end
ContestEffect2_2_score5:
	if_random 0x14 ContestEffectEnd2
	score 0x14
	end

ContestEffectEnd2:
	end

Unknown_081DCA4C:
	if_user_order_eq 0x00 AI_effectcheck1_081DCA4C
	if_user_order_eq 0x01 AI_effectcheck2_081DCA4C
	if_user_order_eq 0x02 AI_effectcheck3_081DCA4C
	if_user_order_eq 0x03 AI_effectcheck4_081DCA4C
	end
AI_effectcheck1_081DCA4C:
	if_effect_eq 0x1D AI_score1_081DCA4C
	if_effect_eq 0x21 AI_score2_081DCA4C
	if_effect_type_eq 0x01 AI_random1_081DCA4C
	end
AI_score1_081DCA4C:
	score 0x0F
	end
AI_score2_081DCA4C:
	score 0xF1
	end
AI_random1_081DCA4C:
	if_random 0x64 ContestEffectEnd2
	score 0x0A
	end
AI_effectcheck2_081DCA4C:
	if_effect_eq 0x21 AI_score3_081DCA4C
	if_effect_type_eq 0x01 AI_random2_081DCA4C
	end
AI_score3_081DCA4C:
	score 0xFB
	end
AI_random2_081DCA4C:
	if_random 0x7D ContestEffectEnd2
	score 0x0A
	end
AI_effectcheck3_081DCA4C:
	if_effect_eq 0x21 AI_score4_081DCA4C
	if_effect_eq 0x1F AI_score4_081DCA4C
	if_effect_eq 0x01 AI_score4_081DCA4C
	end
AI_score4_081DCA4C:
	score 0x05
	end
AI_effectcheck4_081DCA4C:
	if_effect_eq 0x21 AI_score5_081DCA4C
	if_effect_eq 0x1E AI_score5_081DCA4C
	if_effect_eq 0x1F AI_score5_081DCA4C
	if_effect_eq 0x01 AI_score5_081DCA4C
	if_effect_eq 0x12 AI_score7_081DCA4C
	if_effect_type_eq 0x01 AI_score6_081DCA4C
	if_effect_type_eq 0x03 AI_random3_081DCA4C
	end
AI_score5_081DCA4C:
	score 0x0F
	end
AI_score6_081DCA4C:
	score 0xF6
	end
AI_random3_081DCA4C:
	if_random 0x7D ContestEffectEnd2
	score 0x0A
	end
AI_score7_081DCA4C:
	score 0x05
	end

Unknown_081DCAF3:
	end
