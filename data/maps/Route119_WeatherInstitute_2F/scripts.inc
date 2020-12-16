Route119_WeatherInstitute_2F_MapScripts:: @ 8163CC2
	map_script 3, Route119_WeatherInstitute_2F_MapScript1_163CC8
	.byte 0

Route119_WeatherInstitute_2F_MapScript1_163CC8:: @ 8163CC8
	call Route119_WeatherInstitute_2F_EventScript_1A0196
	compare VAR_WEATHER_INSTITUTE_STATE, 0
	call_if_eq Route119_WeatherInstitute_2F_EventScript_163CE4
	compare VAR_WEATHER_INSTITUTE_STATE, 1
	call_if_eq Route119_WeatherInstitute_2F_EventScript_163CF0
	end

Route119_WeatherInstitute_2F_EventScript_163CE4:: @ 8163CE4
	setobjectxyperm 5, 1, 6
	setobjectmovementtype 5, 10
	return

Route119_WeatherInstitute_2F_EventScript_163CF0:: @ 8163CF0
	setobjectxyperm 5, 4, 6
	setobjectmovementtype 5, 10
	return

Route119_WeatherInstitute_2F_EventScript_163CFC:: @ 8163CFC
	trainerbattle 0, TRAINER_WEATHER_INSTITUTE_GRUNT_3, 0, Route119_WeatherInstitute_2F_Text_19EEAF, Route119_WeatherInstitute_2F_Text_19EF1B
	msgbox Route119_WeatherInstitute_2F_Text_19EF3E, 6
	end

Route119_WeatherInstitute_2F_EventScript_163D13:: @ 8163D13
	trainerbattle 0, TRAINER_WEATHER_INSTITUTE_GRUNT_4, 0, Route119_WeatherInstitute_2F_Text_19EFA3, Route119_WeatherInstitute_2F_Text_19EFDD
	msgbox Route119_WeatherInstitute_2F_Text_19EFE9, 6
	end

Route119_WeatherInstitute_2F_EventScript_163D2A:: @ 8163D2A
	trainerbattle 2, TRAINER_WEATHER_INSTITUTE_GRUNT_5, 0, Route119_WeatherInstitute_2F_Text_19F042, Route119_WeatherInstitute_2F_Text_19F0F4, Route119_WeatherInstitute_2F_EventScript_163D45
	msgbox Route119_WeatherInstitute_2F_Text_19F11B, 6
	end

Route119_WeatherInstitute_2F_EventScript_163D45:: @ 8163D45
	msgbox Route119_WeatherInstitute_2F_Text_19F11B, 4
	closemessage
	setvar VAR_WEATHER_INSTITUTE_STATE, 1
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_WORKERS_2F
	fadedefaultbgm
	fadescreen 1
	setflag FLAG_HIDE_EVIL_TEAM_WEATHER_INSTITUTE
	removeobject 1
	removeobject 2
	removeobject 3
	fadescreen 0
	applymovement 5, Route119_WeatherInstitute_2F_Movement_163DC8
	waitmovement 0
	moveobjectoffscreen 5
	goto Route119_WeatherInstitute_2F_EventScript_163D7A
	end

Route119_WeatherInstitute_2F_EventScript_163D7A:: @ 8163D7A
	msgbox Route119_WeatherInstitute_2F_Text_19F1CF, 4
    getpartysize
    copyvar VAR_SPECIAL_4, RESULT
    bufferspeciesname 0, SPECIES_CASTFORM
	givemon SPECIES_CASTFORM, 30, ITEM_MYSTIC_WATER, 0x0, 0x0, 0
    compare RESULT, 0
    goto_if_eq Route119_WeatherInstitute_2F_EventScript_GiveCastformParty
    compare RESULT, 1
    goto_if_eq Route119_WeatherInstitute_2F_EventScript_GiveCastformPC
    release
    end

Route119_WeatherInstitute_2F_EventScript_GiveCastformParty::
    call Route119_WeatherInstitute_2F_EventScript_CastformFanfare
    msgbox CommonText_NicknameRecievedPokemon, MSGBOX_YESNO
    compare RESULT, NO
    goto_if_eq Route119_WeatherInstitute_2F_EventScript_CastformEnd
    call Common_EventScript_NameRecievedPartyMon
    goto Route119_WeatherInstitute_2F_EventScript_CastformEnd

Route119_WeatherInstitute_2F_EventScript_GiveCastformPC::
    call Route119_WeatherInstitute_2F_EventScript_CastformFanfare
    msgbox CommonText_NicknameRecievedPokemon, MSGBOX_YESNO
    bufferspeciesname 1, SPECIES_CASTFORM
    compare RESULT, NO
    goto_if_eq Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
    call Common_EventScript_NameReceivedBoxMon
    goto Route119_WeatherInstitute_2F_EventScript_SendCastformToPC

Route119_WeatherInstitute_2F_EventScript_SendCastformToPC::
    call Common_EventScript_TransferredToPC
    goto Route119_WeatherInstitute_2F_EventScript_CastformEnd

Route119_WeatherInstitute_2F_EventScript_CastformFanfare::
	playfanfare MUS_FANFA4
	message Route119_WeatherInstitute_2F_Text_19F267
	waitfanfare
	waitmessage
	return

Route119_WeatherInstitute_2F_EventScript_CastformEnd::
    msgbox Route119_WeatherInstitute_2F_Text_19F27D, 4
	setflag FLAG_RECEIVED_CASTFORM
	release
	end

Route119_WeatherInstitute_2F_EventScript_163DB4:: @ 8163DB4
	msgbox Route119_WeatherInstitute_2F_Text_19F231, 4
	release
	end

Route119_WeatherInstitute_2F_EventScript_163DBE:: @ 8163DBE
	msgbox Route119_WeatherInstitute_2F_Text_19F2FE, 4
	release
	end

Route119_WeatherInstitute_2F_Movement_163DC8:: @ 8163DC8
	walk_right
	walk_right
	walk_right
	end_movement

Route119_WeatherInstitute_2F_EventScript_163DCC:: @ 8163DCC
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CASTFORM, Route119_WeatherInstitute_2F_EventScript_163DBE
	goto Route119_WeatherInstitute_2F_EventScript_163D7A
	end
