PetalburgCity_PokemonCenter_1F_EventScript_1B1B14:: @ 81B1B14
	lock
	faceplayer
	goto_if_set FLAG_SYS_CHAT_USED, PetalburgCity_PokemonCenter_1F_EventScript_1B1BDB
	msgbox PetalburgCity_PokemonCenter_1F_Text_1B1C97, 4
	goto PetalburgCity_PokemonCenter_1F_EventScript_1B1B2D
	end

PetalburgCity_PokemonCenter_1F_EventScript_1B1B2D:: @ 81B1B2D
	msgbox PetalburgCity_PokemonCenter_1F_Text_1B1D10, 4
	multichoice 17, 6, 20, 0
	switch RESULT
	case 0, PetalburgCity_PokemonCenter_1F_EventScript_1B1B7A
	case 1, PetalburgCity_PokemonCenter_1F_EventScript_1B1BD1
	case 2, PetalburgCity_PokemonCenter_1F_EventScript_1B1B6C
	case 127, PetalburgCity_PokemonCenter_1F_EventScript_1B1BD1
	end

PetalburgCity_PokemonCenter_1F_EventScript_1B1B6C:: @ 81B1B6C
	msgbox PetalburgCity_PokemonCenter_1F_Text_1B1D3A, 4
	goto PetalburgCity_PokemonCenter_1F_EventScript_1B1B2D
	end

PetalburgCity_PokemonCenter_1F_EventScript_1B1B7A:: @ 81B1B7A
	msgbox PetalburgCity_PokemonCenter_1F_Text_1B1F7B, 4
	closemessage
	setvar VAR_SPECIAL_4, 0
	call PetalburgCity_PokemonCenter_1F_EventScript_1A00F3
	lock
	faceplayer
	compare VAR_SPECIAL_4, 1
	call_if_eq PetalburgCity_PokemonCenter_1F_EventScript_1B1C77
	compare RESULT, 0
	goto_if_eq PetalburgCity_PokemonCenter_1F_EventScript_1B1BB1
	compare RESULT, 1
	goto_if_eq PetalburgCity_PokemonCenter_1F_EventScript_1B1BBB
	end

PetalburgCity_PokemonCenter_1F_EventScript_1B1BB1:: @ 81B1BB1
	msgbox PetalburgCity_PokemonCenter_1F_Text_1B1FF0, 4
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_1B1BBB:: @ 81B1BBB
	setvar VAR_SPECIAL_4, 0
	special sub_80EB7C4
	waitmessage
	delay 80
	msgbox PetalburgCity_PokemonCenter_1F_Text_1B2137, 4
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_1B1BD1:: @ 81B1BD1
	msgbox PetalburgCity_PokemonCenter_1F_Text_1B1FA3, 4
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_1B1BDB:: @ 81B1BDB
	msgbox PetalburgCity_PokemonCenter_1F_Text_1B202F, 4
	goto PetalburgCity_PokemonCenter_1F_EventScript_1B1BE9
	end

PetalburgCity_PokemonCenter_1F_EventScript_1B1BE9:: @ 81B1BE9
	msgbox PetalburgCity_PokemonCenter_1F_Text_1B2063, 4
	multichoice 17, 6, 20, 0
	switch RESULT
	case 0, PetalburgCity_PokemonCenter_1F_EventScript_1B1C36
	case 1, PetalburgCity_PokemonCenter_1F_EventScript_1B1C6D
	case 2, PetalburgCity_PokemonCenter_1F_EventScript_1B1C28
	case 127, PetalburgCity_PokemonCenter_1F_EventScript_1B1C6D
	end

PetalburgCity_PokemonCenter_1F_EventScript_1B1C28:: @ 81B1C28
	msgbox PetalburgCity_PokemonCenter_1F_Text_1B1D3A, 4
	goto PetalburgCity_PokemonCenter_1F_EventScript_1B1BE9
	end

PetalburgCity_PokemonCenter_1F_EventScript_1B1C36:: @ 81B1C36
	msgbox PetalburgCity_PokemonCenter_1F_Text_1B207F, 4
	closemessage
	setvar VAR_SPECIAL_4, 0
	call PetalburgCity_PokemonCenter_1F_EventScript_1A00F3
	lock
	faceplayer
	compare VAR_SPECIAL_4, 1
	call_if_eq PetalburgCity_PokemonCenter_1F_EventScript_1B1C77
	compare RESULT, 0
	goto_if_eq PetalburgCity_PokemonCenter_1F_EventScript_1B1BB1
	compare RESULT, 1
	goto_if_eq PetalburgCity_PokemonCenter_1F_EventScript_1B1BBB
	end

PetalburgCity_PokemonCenter_1F_EventScript_1B1C6D:: @ 81B1C6D
	msgbox PetalburgCity_PokemonCenter_1F_Text_1B20CE, 4
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_1B1C77:: @ 81B1C77 ; said the phrase
	goto_if_set FLAG_SAID_JIRACHI_PHRASE, PetalburgCity_PokemonCenter_1F_EventScript_Return
	setflag FLAG_SAID_JIRACHI_PHRASE
	call_if_unset FLAG_VISITED_MOSSDEEP_CITY, PetalburgCity_PokemonCenter_1F_EventScript_JirachiGuyEarly
	call_if_set FLAG_VISITED_MOSSDEEP_CITY, PetalburgCity_PokemonCenter_1F_EventScript_JirachiGuyNormal
	goto_if_unset FLAG_VISITED_MOSSDEEP_CITY, PetalburgCity_PokemonCenter_1F_EventScript_JirachiGuyEarlyGive
	goto_if_set FLAG_VISITED_MOSSDEEP_CITY, PetalburgCity_PokemonCenter_1F_EventScript_JirachiGuyNormalGive
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_Return::
    return

PetalburgCity_PokemonCenter_1F_EventScript_JirachiGuyEarly::
	msgbox PetalburgCity_PokemonCenter_1F_Text_JirachiGuyEarly, 3
	return

PetalburgCity_PokemonCenter_1F_EventScript_JirachiGuyNormal::
	msgbox PetalburgCity_PokemonCenter_1F_Text_JirachiGuyNormal, 3
	return

PetalburgCity_PokemonCenter_1F_EventScript_JirachiGuyEarlyGive::
	givemon SPECIES_JIRACHI, 10, ITEM_GANLON_BERRY, 0x0, 0x0, 0
    goto PetalburgCity_PokemonCenter_1F_EventScript_JirachiGuyGiveMerge

PetalburgCity_PokemonCenter_1F_EventScript_JirachiGuyNormalGive::
	getpartysize
    copyvar VAR_SPECIAL_4, RESULT
	givemon SPECIES_JIRACHI, 50, ITEM_SALAC_BERRY, 0x0, 0x0, 0
    goto PetalburgCity_PokemonCenter_1F_EventScript_JirachiGuyGiveMerge

PetalburgCity_PokemonCenter_1F_EventScript_JirachiGuyGiveMerge::
    compare RESULT, 0
    goto_if_eq PetalburgCity_PokemonCenter_1F_EventScript_JirachiGuyRecieveParty
    compare RESULT, 1
    goto_if_eq PetalburgCity_PokemonCenter_1F_EventScript_JirachiGuyRecievePC
    release
    end
@ TODO: complain about all boxes full

PetalburgCity_PokemonCenter_1F_EventScript_JirachiGuyRecieveParty::
    call PetalburgCity_PokemonCenter_1F_EventScript_JirachiGuyFanfare
	bufferspeciesname 0, SPECIES_JIRACHI
    msgbox CommonText_NicknameRecievedPokemon, MSGBOX_YESNO
    compare RESULT, NO
    goto_if_eq PetalburgCity_PokemonCenter_1F_EventScript_JirachiGuyEnd
    call Common_EventScript_NameRecievedPartyMon
    goto PetalburgCity_PokemonCenter_1F_EventScript_JirachiGuyEnd

PetalburgCity_PokemonCenter_1F_EventScript_JirachiGuyEnd::
    setflag FLAG_GOT_JIRACHI
    release
    end

PetalburgCity_PokemonCenter_1F_EventScript_JirachiGuyRecievePC::
    call PetalburgCity_PokemonCenter_1F_EventScript_JirachiGuyFanfare
	bufferspeciesname 0, SPECIES_JIRACHI
    msgbox CommonText_NicknameRecievedPokemon, MSGBOX_YESNO
    compare RESULT, NO
    goto_if_eq PetalburgCity_PokemonCenter_1F_EventScript_JirachiGuySendToPC
    call Common_EventScript_NameReceivedBoxMon
    goto PetalburgCity_PokemonCenter_1F_EventScript_JirachiGuySendToPC

PetalburgCity_PokemonCenter_1F_EventScript_JirachiGuySendToPC::
    call Common_EventScript_TransferredToPC
    setflag FLAG_GOT_JIRACHI
    release
    end

PetalburgCity_PokemonCenter_1F_EventScript_JirachiGuyFanfare::
	playfanfare MUS_FANFA5
	message PetalburgCity_PokemonCenter_1F_Text_RecievedJirachi
	waitfanfare
	waitmessage
	return
