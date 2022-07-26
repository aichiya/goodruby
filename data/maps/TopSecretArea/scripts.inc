TopSecretArea_MapScripts::
	map_script 3, TopSecretArea_MapScript
	.byte 0

TopSecretArea_MapScript::
	goto_if_unset FLAG_BEAT_HACK_LORD, TopSecretArea_MapScriptEnd
	setobjectxyperm 2, 23, 17

TopSecretArea_MapScriptEnd::
	end

TopSecretArea_TorchicDoll::
	msgbox TopSecretArea_Text_TorchicDoll, 2
	end

TopSecretArea_Machoke::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOKE, 0
	msgbox TopSecretArea_Text_Machoke, 4
	waitmoncry
	release
	end

TopSecretArea_Computer1::
	msgbox TopSecretArea_Text_Computer1, 2
	end

TopSecretArea_Computer2::
	msgbox TopSecretArea_Text_Computer2, 2
	end

TopSecretArea_Computer3::
	msgbox TopSecretArea_Text_Computer3, 2
	end

TopSecretArea_Computer4::
	msgbox TopSecretArea_Text_Computer4, 2
	end

TopSecretArea_Computer5::
	msgbox TopSecretArea_Text_Computer5, 2
	end

TopSecretArea_Computer6::
	msgbox TopSecretArea_Text_Computer6, 2
	end

TopSecretArea_Plaque::
	msgbox TopSecretArea_Text_Plaque, 2
	end

TopSecretArea_HackLord::
    lock
    faceplayer
    goto_if_set FLAG_BEAT_HACK_LORD, TopSecretArea_HackLordRequestRefight
    goto_if_set FLAG_SYS_GAME_CLEAR, TopSecretArea_HackLordRequestFight
	msgbox TopSecretArea_Text_Hacker1, 2
    release
    end

TopSecretArea_HackLordRequestFight::
    msgbox TopSecretArea_Text_Hacker2, MSGBOX_YESNO
	compare RESULT, NO
	goto_if_eq TopSecretArea_HackLordFightDeclined
	msgbox TopSecretArea_Text_Hacker4, 4
	trainerbattle 3, TRAINER_DOESNT, 0, TopSecretArea_Text_Hacker5
	setflag FLAG_BEAT_HACK_LORD
	setobjectxyperm 2, 23, 17
    msgbox TopSecretArea_Text_Hacker6, 4
	closemessage
    release
    end

TopSecretArea_HackLordRequestRefight::
    msgbox TopSecretArea_Text_Hacker7, MSGBOX_YESNO
	compare RESULT, NO
	goto_if_eq TopSecretArea_HackLordFightDeclined
	msgbox TopSecretArea_Text_Hacker4, 4
	trainerbattle 3, TRAINER_DOESNT, 0, TopSecretArea_Text_Hacker5
    msgbox TopSecretArea_Text_Hacker6, 4
	closemessage
    release
    end
    
TopSecretArea_HackLordFightDeclined::
	msgbox TopSecretArea_Text_Hacker3, 2
    release
    end

TopSecretArea_MoulderTheBoulder::
    lock
    faceplayer
    goto_if_set FLAG_BEAT_HACK_LORD, TopSecretArea_MoulderTheBoulderDone
    goto_if_set FLAG_HIDE_MOSSDEEP_AQUA_GRUNT, TopSecretArea_MoulderTheBoulderStrength
	msgbox TopSecretArea_Text_Moulder, 2
    release
    end

TopSecretArea_MoulderTheBoulderStrength::
	msgbox TopSecretArea_Text_Moulder2, 2
    release
	end

TopSecretArea_MoulderTheBoulderDone::
	msgbox TopSecretArea_Text_Moulder3, 2
    release
	end

TopSecretArea_EternalNugget:: @ 81B1460
	giveitem_std ITEM_BIG_NUGGET, 1, 1
	end
