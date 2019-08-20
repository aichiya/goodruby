LavaridgeTown_HerbShop_MapScripts:: @ 8153628
	.byte 0

LavaridgeTown_HerbShop_EventScript_153629:: @ 8153629
	lock
	faceplayer
	message LavaridgeTown_HerbShop_Text_17615C
	waitmessage
	pokemart LavaridgeTown_HerbShop_Items
	msgbox LavaridgeTown_HerbShop_Text_1A0C02, 4
	release
	end

	.align 2
LavaridgeTown_HerbShop_Items:: @ 8153640
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_REVIVAL_HERB
	.2byte ITEM_NONE
	release
	end

LavaridgeTown_HerbShop_EventScript_15364C:: @ 815364C
	msgbox LavaridgeTown_HerbShop_Text_1762A3, 2
	end

LavaridgeTown_HerbShop_EventScript_153655:: @ 8153655
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CHARCOAL, LavaridgeTown_HerbShop_EventScript_153684
	msgbox LavaridgeTown_HerbShop_Text_1761A2, 4
	giveitem_std ITEM_CHARCOAL
	compare RESULT, 0
	goto_if_eq LavaridgeTown_HerbShop_EventScript_1A029B
	setflag FLAG_RECEIVED_CHARCOAL
	release
	end

LavaridgeTown_HerbShop_EventScript_153684:: @ 8153684
	msgbox LavaridgeTown_HerbShop_Text_176209, 4
	release
	end

LavaridgeTown_HerbShop_EventScript_Psychiatrist::
	lock
	faceplayer
	msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_Intro, 4
	waitmessage
	showmoneybox 0, 0
    nop
    msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_ShowPrice, MSGBOX_YESNO
	hidemoneybox 0, 0
	compare RESULT, NO
	goto_if_eq LavaridgeTown_HerbShop_EventScript_PsychiatristBye
    
	checkmoney 10000, 0
    compare RESULT, 0
    goto_if_eq LavaridgeTown_HerbShop_EventScript_PsychiatristNeedMoney
    
    msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_WhichMon, 4
	special SelectMonForNPCTrade
	waitstate
    compare VAR_SPECIAL_4, 255
	goto_if_eq LavaridgeTown_HerbShop_EventScript_PsychiatristBye
    
	specialvar RESULT, ScriptGetPartyMonSpecies
	compare RESULT, SPECIES_EGG
	goto_if_eq LavaridgeTown_HerbShop_EventScript_PsychiatristEgg

LavaridgeTown_HerbShop_EventScript_PsychiatristFirstPick:
    msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_WhichStrength, 4
    multichoice 0, 0, 83, 0
    switch RESULT
    case 0, LavaridgeTown_HerbShop_EventScript_AttackUp
    case 1, LavaridgeTown_HerbShop_EventScript_DefenseUp
    case 2, LavaridgeTown_HerbShop_EventScript_SpAtkUp
    case 3, LavaridgeTown_HerbShop_EventScript_SpDefUp
    case 4, LavaridgeTown_HerbShop_EventScript_SpeedUp
    case 5, LavaridgeTown_HerbShop_EventScript_Balance
    goto LavaridgeTown_HerbShop_EventScript_PsychiatristBye

LavaridgeTown_HerbShop_EventScript_AttackUp:
    msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_WhichWeakness, 4
    multichoice 0, 0, 84, 0
    switch RESULT
    case 0, LavaridgeTown_HerbShop_EventScript_Lonely
    case 1, LavaridgeTown_HerbShop_EventScript_Adamant
    case 2, LavaridgeTown_HerbShop_EventScript_Naughty
    case 3, LavaridgeTown_HerbShop_EventScript_Brave
    goto LavaridgeTown_HerbShop_EventScript_PsychiatristFirstPick

LavaridgeTown_HerbShop_EventScript_DefenseUp:
    msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_WhichWeakness, 4
    multichoice 0, 0, 85, 0
    switch RESULT
    case 0, LavaridgeTown_HerbShop_EventScript_Bold
    case 1, LavaridgeTown_HerbShop_EventScript_Impish
    case 2, LavaridgeTown_HerbShop_EventScript_Lax
    case 3, LavaridgeTown_HerbShop_EventScript_Relaxed
    goto LavaridgeTown_HerbShop_EventScript_PsychiatristFirstPick

LavaridgeTown_HerbShop_EventScript_SpAtkUp:
    msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_WhichWeakness, 4
    multichoice 0, 0, 86, 0
    switch RESULT
    case 0, LavaridgeTown_HerbShop_EventScript_Modest
    case 1, LavaridgeTown_HerbShop_EventScript_Mild
    case 2, LavaridgeTown_HerbShop_EventScript_Rash
    case 3, LavaridgeTown_HerbShop_EventScript_Quiet
    goto LavaridgeTown_HerbShop_EventScript_PsychiatristFirstPick

LavaridgeTown_HerbShop_EventScript_SpDefUp:
    msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_WhichWeakness, 4
    multichoice 0, 0, 87, 0
    switch RESULT
    case 0, LavaridgeTown_HerbShop_EventScript_Calm
    case 1, LavaridgeTown_HerbShop_EventScript_Gentle
    case 2, LavaridgeTown_HerbShop_EventScript_Careful
    case 3, LavaridgeTown_HerbShop_EventScript_Sassy
    goto LavaridgeTown_HerbShop_EventScript_PsychiatristFirstPick

LavaridgeTown_HerbShop_EventScript_SpeedUp:
    msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_WhichWeakness, 4
    multichoice 0, 0, 88, 0
    switch RESULT
    case 0, LavaridgeTown_HerbShop_EventScript_Timid
    case 1, LavaridgeTown_HerbShop_EventScript_Hasty
    case 2, LavaridgeTown_HerbShop_EventScript_Jolly
    case 3, LavaridgeTown_HerbShop_EventScript_Naive
    goto LavaridgeTown_HerbShop_EventScript_PsychiatristFirstPick

LavaridgeTown_HerbShop_EventScript_Balance:
    setvar VAR_SPECIAL_1, 6
	msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_Balance, MSGBOX_YESNO
    goto LavaridgeTown_HerbShop_EventScript_Operation

LavaridgeTown_HerbShop_EventScript_Lonely:
    setvar VAR_SPECIAL_1, 1
	msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_Lonely, MSGBOX_YESNO
    goto LavaridgeTown_HerbShop_EventScript_Operation

LavaridgeTown_HerbShop_EventScript_Brave:
    setvar VAR_SPECIAL_1, 2
	msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_Brave, MSGBOX_YESNO
    goto LavaridgeTown_HerbShop_EventScript_Operation

LavaridgeTown_HerbShop_EventScript_Adamant:
    setvar VAR_SPECIAL_1, 3
	msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_Adamant, MSGBOX_YESNO
    goto LavaridgeTown_HerbShop_EventScript_Operation

LavaridgeTown_HerbShop_EventScript_Naughty:
    setvar VAR_SPECIAL_1, 4
	msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_Naughty, MSGBOX_YESNO
    goto LavaridgeTown_HerbShop_EventScript_Operation

LavaridgeTown_HerbShop_EventScript_Bold:
    setvar VAR_SPECIAL_1, 5
	msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_Bold, MSGBOX_YESNO
    goto LavaridgeTown_HerbShop_EventScript_Operation

LavaridgeTown_HerbShop_EventScript_Relaxed:
    setvar VAR_SPECIAL_1, 7
	msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_Relaxed, MSGBOX_YESNO
    goto LavaridgeTown_HerbShop_EventScript_Operation

LavaridgeTown_HerbShop_EventScript_Impish:
    setvar VAR_SPECIAL_1, 8
	msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_Impish, MSGBOX_YESNO
    goto LavaridgeTown_HerbShop_EventScript_Operation

LavaridgeTown_HerbShop_EventScript_Lax:
    setvar VAR_SPECIAL_1, 9
	msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_Lax, MSGBOX_YESNO
    goto LavaridgeTown_HerbShop_EventScript_Operation

LavaridgeTown_HerbShop_EventScript_Timid:
    setvar VAR_SPECIAL_1, 10
	msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_Timid, MSGBOX_YESNO
    goto LavaridgeTown_HerbShop_EventScript_Operation

LavaridgeTown_HerbShop_EventScript_Hasty:
    setvar VAR_SPECIAL_1, 11
	msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_Hasty, MSGBOX_YESNO
    goto LavaridgeTown_HerbShop_EventScript_Operation

LavaridgeTown_HerbShop_EventScript_Jolly:
    setvar VAR_SPECIAL_1, 13
	msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_Jolly, MSGBOX_YESNO
    goto LavaridgeTown_HerbShop_EventScript_Operation

LavaridgeTown_HerbShop_EventScript_Naive:
    setvar VAR_SPECIAL_1, 14
	msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_Naive, MSGBOX_YESNO
    goto LavaridgeTown_HerbShop_EventScript_Operation

LavaridgeTown_HerbShop_EventScript_Modest:
    setvar VAR_SPECIAL_1, 15
	msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_Modest, MSGBOX_YESNO
    goto LavaridgeTown_HerbShop_EventScript_Operation

LavaridgeTown_HerbShop_EventScript_Mild:
    setvar VAR_SPECIAL_1, 16
	msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_Mild, MSGBOX_YESNO
    goto LavaridgeTown_HerbShop_EventScript_Operation

LavaridgeTown_HerbShop_EventScript_Quiet:
    setvar VAR_SPECIAL_1, 17
	msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_Quiet, MSGBOX_YESNO
    goto LavaridgeTown_HerbShop_EventScript_Operation

LavaridgeTown_HerbShop_EventScript_Rash:
    setvar VAR_SPECIAL_1, 19
	msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_Rash, MSGBOX_YESNO
    goto LavaridgeTown_HerbShop_EventScript_Operation

LavaridgeTown_HerbShop_EventScript_Calm:
    setvar VAR_SPECIAL_1, 20
	msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_Calm, MSGBOX_YESNO
    goto LavaridgeTown_HerbShop_EventScript_Operation

LavaridgeTown_HerbShop_EventScript_Gentle:
    setvar VAR_SPECIAL_1, 21
	msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_Gentle, MSGBOX_YESNO
    goto LavaridgeTown_HerbShop_EventScript_Operation

LavaridgeTown_HerbShop_EventScript_Sassy:
    setvar VAR_SPECIAL_1, 22
	msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_Sassy, MSGBOX_YESNO
    goto LavaridgeTown_HerbShop_EventScript_Operation

LavaridgeTown_HerbShop_EventScript_Careful:
    setvar VAR_SPECIAL_1, 23
	msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_Careful, MSGBOX_YESNO
    goto LavaridgeTown_HerbShop_EventScript_Operation


LavaridgeTown_HerbShop_EventScript_Operation:
	compare RESULT, NO
	goto_if_eq LavaridgeTown_HerbShop_EventScript_PsychiatristFirstPick
    special SetNatureOverride
    switch RESULT
    case 0, LavaridgeTown_HerbShop_EventScript_Redundant
    case 1, LavaridgeTown_HerbShop_EventScript_CollectPay
    
LavaridgeTown_HerbShop_EventScript_CollectPay:
    msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_Done, 4
	waitmessage
	showmoneybox 0, 0
    nop
    msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_Done2, 4
	takemoney 10000, 0
	updatemoneybox 0, 0
	nop
	playse SE_REGI
    msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_Bye, 4
	hidemoneybox 0, 0
    release
	end
    
LavaridgeTown_HerbShop_EventScript_Redundant:
    msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_Redundant, 4
    release
	end

LavaridgeTown_HerbShop_EventScript_PsychiatristEgg:
    msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_Egg, 4
    release
	end

LavaridgeTown_HerbShop_EventScript_PsychiatristNeedMoney:
    msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_NeedMoney, 4
    release
	end

LavaridgeTown_HerbShop_EventScript_PsychiatristBye:
    msgbox LavaridgeTown_HerbShop_Text_Psychiatrist_Bye, 4
    release
	end
