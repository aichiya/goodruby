RustboroCity_DevonCorp_2F_MapScripts:: @ 81574CA
	map_script 3, RustboroCity_DevonCorp_2F_MapScript1_1574D0
	.byte 0

RustboroCity_DevonCorp_2F_MapScript1_1574D0:: @ 81574D0
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
	call_if_eq RustboroCity_DevonCorp_2F_EventScript_1574DC
	end

RustboroCity_DevonCorp_2F_EventScript_1574DC:: @ 81574DC
	setvar VAR_FOSSIL_RESURRECTION_STATE, 2
	return

RustboroCity_DevonCorp_2F_EventScript_1574E2:: @ 81574E2
	lock
	faceplayer
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
	call_if_eq RustboroCity_DevonCorp_2F_EventScript_1574DC
	msgbox RustboroCity_DevonCorp_2F_Text_182B81, 4
	release
	end

RustboroCity_DevonCorp_2F_EventScript_1574F9:: @ 81574F9
	lock
	faceplayer
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
	call_if_eq RustboroCity_DevonCorp_2F_EventScript_1574DC
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, RustboroCity_DevonCorp_2F_EventScript_157519
	msgbox RustboroCity_DevonCorp_2F_Text_182BD8, 4
	release
	end

RustboroCity_DevonCorp_2F_EventScript_157519:: @ 8157519
	msgbox RustboroCity_DevonCorp_2F_Text_182C25, 4
	release
	end

RustboroCity_DevonCorp_2F_EventScript_157523:: @ 8157523
	lock
	faceplayer
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
	call_if_eq RustboroCity_DevonCorp_2F_EventScript_1574DC
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_DevonCorp_2F_EventScript_157543
	msgbox RustboroCity_DevonCorp_2F_Text_182D2A, 4
	release
	end

RustboroCity_DevonCorp_2F_EventScript_157543:: @ 8157543
	msgbox RustboroCity_DevonCorp_2F_Text_182D7E, 4
	release
	end

RustboroCity_DevonCorp_2F_EventScript_15754D:: @ 815754D
	lock
	faceplayer
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
	call_if_eq RustboroCity_DevonCorp_2F_EventScript_1574DC
	msgbox RustboroCity_DevonCorp_2F_Text_182E6B, 4
	release
	end

RustboroCity_DevonCorp_2F_EventScript_157564:: @ 8157564
	lock
	faceplayer
	compare VAR_FOSSIL_RESURRECTION_STATE, 2
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_15764A
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_157640
	msgbox RustboroCity_DevonCorp_2F_Text_182ED5, 4
    checkitem ITEM_ROOT_FOSSIL, 1
    compare RESULT, 1
    goto_if_eq RustboroCity_DevonCorp_2F_ChooseFossilHaveRoot
    checkitem ITEM_CLAW_FOSSIL, 1
    compare RESULT, 1
    goto_if_eq RustboroCity_DevonCorp_2F_ChooseFossilHaveClaw
    checkitem ITEM_DOME_FOSSIL, 1
    compare RESULT, 1
    goto_if_eq RustboroCity_DevonCorp_2F_ChooseFossilHaveDome
    checkitem ITEM_HELIX_FOSSIL, 1
    compare RESULT, 1
    goto_if_eq RustboroCity_DevonCorp_2F_ChooseFossilHaveHelix
	release
	end

RustboroCity_DevonCorp_2F_ChooseFossilHaveRoot:
    checkitem ITEM_CLAW_FOSSIL, 1
    compare RESULT, 1
    goto_if_eq RustboroCity_DevonCorp_2F_PickRootClaw
    checkitem ITEM_DOME_FOSSIL, 1
    compare RESULT, 1
    goto_if_eq RustboroCity_DevonCorp_2F_PickRootDome
    checkitem ITEM_HELIX_FOSSIL, 1
    compare RESULT, 1
    goto_if_eq RustboroCity_DevonCorp_2F_PickRootHelix
    goto RustboroCity_DevonCorp_2F_PickJustRoot

RustboroCity_DevonCorp_2F_ChooseFossilHaveClaw:
    checkitem ITEM_DOME_FOSSIL, 1
    compare RESULT, 1
    goto_if_eq RustboroCity_DevonCorp_2F_PickClawDome
    checkitem ITEM_HELIX_FOSSIL, 1
    compare RESULT, 1
    goto_if_eq RustboroCity_DevonCorp_2F_PickClawHelix
    goto RustboroCity_DevonCorp_2F_PickJustClaw

RustboroCity_DevonCorp_2F_ChooseFossilHaveDome:
    checkitem ITEM_HELIX_FOSSIL, 1
    compare RESULT, 1
    goto_if_eq RustboroCity_DevonCorp_2F_PickDomeHelix
    goto RustboroCity_DevonCorp_2F_PickJustDome

RustboroCity_DevonCorp_2F_ChooseFossilHaveHelix:
    goto RustboroCity_DevonCorp_2F_PickJustHelix

RustboroCity_DevonCorp_2F_PickRootClaw:
	closemessage
	playse SE_PIN
	applymovement 5, RustboroCity_DevonCorp_2F_Movement_1A0833
	waitmovement 0
	applymovement 5, RustboroCity_DevonCorp_2F_Movement_1A0835
	waitmovement 0
	message RustboroCity_DevonCorp_2F_Text_182F35
    waitmessage
    multichoice 0, 0, 76, 0
	switch RESULT
    case 0, RustboroCity_DevonCorp_2F_EventScript_HandOverRoot
    case 1, RustboroCity_DevonCorp_2F_EventScript_HandOverClaw
	goto RustboroCity_DevonCorp_2F_EventScript_157636

RustboroCity_DevonCorp_2F_PickRootDome:
	closemessage
	playse SE_PIN
	applymovement 5, RustboroCity_DevonCorp_2F_Movement_1A0833
	waitmovement 0
	applymovement 5, RustboroCity_DevonCorp_2F_Movement_1A0835
	waitmovement 0
	message RustboroCity_DevonCorp_2F_Text_182F35
    waitmessage
    multichoice 0, 0, 77, 0
	switch RESULT
    case 0, RustboroCity_DevonCorp_2F_EventScript_HandOverRoot
    case 1, RustboroCity_DevonCorp_2F_EventScript_HandOverDome
	goto RustboroCity_DevonCorp_2F_EventScript_157636

RustboroCity_DevonCorp_2F_PickRootHelix:
	closemessage
	playse SE_PIN
	applymovement 5, RustboroCity_DevonCorp_2F_Movement_1A0833
	waitmovement 0
	applymovement 5, RustboroCity_DevonCorp_2F_Movement_1A0835
	waitmovement 0
	message RustboroCity_DevonCorp_2F_Text_182F35
    waitmessage
    multichoice 0, 0, 78, 0
	switch RESULT
    case 0, RustboroCity_DevonCorp_2F_EventScript_HandOverRoot
    case 1, RustboroCity_DevonCorp_2F_EventScript_HandOverHelix
	goto RustboroCity_DevonCorp_2F_EventScript_157636

RustboroCity_DevonCorp_2F_PickClawDome:
	closemessage
	playse SE_PIN
	applymovement 5, RustboroCity_DevonCorp_2F_Movement_1A0833
	waitmovement 0
	applymovement 5, RustboroCity_DevonCorp_2F_Movement_1A0835
	waitmovement 0
	message RustboroCity_DevonCorp_2F_Text_182F35
    waitmessage
    multichoice 0, 0, 79, 0
	switch RESULT
    case 0, RustboroCity_DevonCorp_2F_EventScript_HandOverClaw
    case 1, RustboroCity_DevonCorp_2F_EventScript_HandOverDome
	goto RustboroCity_DevonCorp_2F_EventScript_157636

RustboroCity_DevonCorp_2F_PickClawHelix:
	closemessage
	playse SE_PIN
	applymovement 5, RustboroCity_DevonCorp_2F_Movement_1A0833
	waitmovement 0
	applymovement 5, RustboroCity_DevonCorp_2F_Movement_1A0835
	waitmovement 0
	message RustboroCity_DevonCorp_2F_Text_182F35
    waitmessage
    multichoice 0, 0, 80, 0
	switch RESULT
    case 0, RustboroCity_DevonCorp_2F_EventScript_HandOverClaw
    case 1, RustboroCity_DevonCorp_2F_EventScript_HandOverHelix
	goto RustboroCity_DevonCorp_2F_EventScript_157636

RustboroCity_DevonCorp_2F_PickDomeHelix:
	closemessage
	playse SE_PIN
	applymovement 5, RustboroCity_DevonCorp_2F_Movement_1A0833
	waitmovement 0
	applymovement 5, RustboroCity_DevonCorp_2F_Movement_1A0835
	waitmovement 0
	message RustboroCity_DevonCorp_2F_Text_182F35
    waitmessage
    multichoice 0, 0, 81, 0
	switch RESULT
    case 0, RustboroCity_DevonCorp_2F_EventScript_HandOverDome
    case 1, RustboroCity_DevonCorp_2F_EventScript_HandOverHelix
	goto RustboroCity_DevonCorp_2F_EventScript_157636

RustboroCity_DevonCorp_2F_PickJustRoot:
	closemessage
	playse SE_PIN
	applymovement 5, RustboroCity_DevonCorp_2F_Movement_1A0833
	waitmovement 0
	applymovement 5, RustboroCity_DevonCorp_2F_Movement_1A0835
	waitmovement 0
	msgbox RustboroCity_DevonCorp_2F_Text_182F35, MSGBOX_YESNO
	compare RESULT, NO
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_157636
    goto RustboroCity_DevonCorp_2F_EventScript_HandOverRoot

RustboroCity_DevonCorp_2F_PickJustClaw:
	closemessage
	playse SE_PIN
	applymovement 5, RustboroCity_DevonCorp_2F_Movement_1A0833
	waitmovement 0
	applymovement 5, RustboroCity_DevonCorp_2F_Movement_1A0835
	waitmovement 0
	msgbox RustboroCity_DevonCorp_2F_Text_182F35, MSGBOX_YESNO
	compare RESULT, NO
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_157636
    goto RustboroCity_DevonCorp_2F_EventScript_HandOverClaw

RustboroCity_DevonCorp_2F_PickJustDome:
	closemessage
	playse SE_PIN
	applymovement 5, RustboroCity_DevonCorp_2F_Movement_1A0833
	waitmovement 0
	applymovement 5, RustboroCity_DevonCorp_2F_Movement_1A0835
	waitmovement 0
	msgbox RustboroCity_DevonCorp_2F_Text_182F35, MSGBOX_YESNO
	compare RESULT, NO
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_157636
    goto RustboroCity_DevonCorp_2F_EventScript_HandOverDome

RustboroCity_DevonCorp_2F_PickJustHelix:
	closemessage
	playse SE_PIN
	applymovement 5, RustboroCity_DevonCorp_2F_Movement_1A0833
	waitmovement 0
	applymovement 5, RustboroCity_DevonCorp_2F_Movement_1A0835
	waitmovement 0
	msgbox RustboroCity_DevonCorp_2F_Text_182F35, MSGBOX_YESNO
	compare RESULT, NO
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_157636
    goto RustboroCity_DevonCorp_2F_EventScript_HandOverHelix

RustboroCity_DevonCorp_2F_EventScript_HandOverRoot:: @ 81575A6
	bufferitemname 0, ITEM_ROOT_FOSSIL
	msgbox RustboroCity_DevonCorp_2F_Text_183023, 4
	takeitem ITEM_ROOT_FOSSIL, 1
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 1
	release
	end

RustboroCity_DevonCorp_2F_EventScript_HandOverClaw:: @ 81575EE
	bufferitemname 0, ITEM_CLAW_FOSSIL
	msgbox RustboroCity_DevonCorp_2F_Text_183023, 4
	takeitem ITEM_CLAW_FOSSIL, 1
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 2
	release
	end

RustboroCity_DevonCorp_2F_EventScript_HandOverDome:: @ 81575EE
	bufferitemname 0, ITEM_DOME_FOSSIL
	msgbox RustboroCity_DevonCorp_2F_Text_183023, 4
	takeitem ITEM_DOME_FOSSIL, 1
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 3
	release
	end

RustboroCity_DevonCorp_2F_EventScript_HandOverHelix:: @ 81575EE
	bufferitemname 0, ITEM_HELIX_FOSSIL
	msgbox RustboroCity_DevonCorp_2F_Text_183023, 4
	takeitem ITEM_HELIX_FOSSIL, 1
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 4
	release
	end

RustboroCity_DevonCorp_2F_EventScript_157636:: @ 8157636
	msgbox RustboroCity_DevonCorp_2F_Text_182FD7, 4
	release
	end

RustboroCity_DevonCorp_2F_EventScript_157640:: @ 8157640
	msgbox RustboroCity_DevonCorp_2F_Text_183072, 4
	release
	end

RustboroCity_DevonCorp_2F_EventScript_15764A:: @ 815764A
    switch VAR_WHICH_FOSSIL_REVIVED
    case 1, RustboroCity_DevonCorp_2F_EventScript_GiveLileep
	case 2, RustboroCity_DevonCorp_2F_EventScript_GiveAnorith
    case 3, RustboroCity_DevonCorp_2F_EventScript_GiveKabuto
    case 4, RustboroCity_DevonCorp_2F_EventScript_GiveOmanyte
	end

RustboroCity_DevonCorp_2F_EventScript_GiveLileep:: @ 8157661
	bufferspeciesname 1, SPECIES_LILEEP
	msgbox RustboroCity_DevonCorp_2F_Text_183124, 4
	getpartysize
	compare RESULT, 6
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_157707
	copyvar VAR_SPECIAL_4, RESULT
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_FOSSIL_MON
	playfanfare MUS_FANFA4
	message RustboroCity_DevonCorp_2F_Text_18319E
	waitfanfare
	waitmessage
	givemon SPECIES_LILEEP, 24, ITEM_NONE, 0x0, 0x0, 0
	msgbox RustboroCity_DevonCorp_2F_Text_1A1102, MSGBOX_YESNO
	compare RESULT, YES
	call_if_eq RustboroCity_DevonCorp_2F_EventScript_1A0678
	release
	end

RustboroCity_DevonCorp_2F_EventScript_GiveAnorith:: @ 81576B4
	bufferspeciesname 1, SPECIES_ANORITH
	msgbox RustboroCity_DevonCorp_2F_Text_183124, 4
	getpartysize
	compare RESULT, 6
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_157707
	copyvar VAR_SPECIAL_4, RESULT
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_FOSSIL_MON
	playfanfare MUS_FANFA4
	message RustboroCity_DevonCorp_2F_Text_18319E
	waitfanfare
	waitmessage
	givemon SPECIES_ANORITH, 24, ITEM_NONE, 0x0, 0x0, 0
	msgbox RustboroCity_DevonCorp_2F_Text_1A1102, MSGBOX_YESNO
	compare RESULT, YES
	call_if_eq RustboroCity_DevonCorp_2F_EventScript_1A0678
	release
	end

RustboroCity_DevonCorp_2F_EventScript_GiveKabuto::
	bufferspeciesname 1, SPECIES_KABUTO
	msgbox RustboroCity_DevonCorp_2F_Text_183124, 4
	getpartysize
	compare RESULT, 6
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_157707
	copyvar VAR_SPECIAL_4, RESULT
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_FOSSIL_MON
	playfanfare MUS_FANFA4
	message RustboroCity_DevonCorp_2F_Text_18319E
	waitfanfare
	waitmessage
	givemon SPECIES_KABUTO, 24, ITEM_NONE, 0x0, 0x0, 0
	msgbox RustboroCity_DevonCorp_2F_Text_1A1102, MSGBOX_YESNO
	compare RESULT, YES
	call_if_eq RustboroCity_DevonCorp_2F_EventScript_1A0678
	release
	end

RustboroCity_DevonCorp_2F_EventScript_GiveOmanyte::
	bufferspeciesname 1, SPECIES_OMANYTE
	msgbox RustboroCity_DevonCorp_2F_Text_183124, 4
	getpartysize
	compare RESULT, 6
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_157707
	copyvar VAR_SPECIAL_4, RESULT
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_FOSSIL_MON
	playfanfare MUS_FANFA4
	message RustboroCity_DevonCorp_2F_Text_18319E
	waitfanfare
	waitmessage
	givemon SPECIES_OMANYTE, 24, ITEM_NONE, 0x0, 0x0, 0
	msgbox RustboroCity_DevonCorp_2F_Text_1A1102, MSGBOX_YESNO
	compare RESULT, YES
	call_if_eq RustboroCity_DevonCorp_2F_EventScript_1A0678
	release
	end

RustboroCity_DevonCorp_2F_EventScript_157707:: @ 8157707
	msgbox RustboroCity_DevonCorp_2F_Text_1831C8, 4
	release
	end
