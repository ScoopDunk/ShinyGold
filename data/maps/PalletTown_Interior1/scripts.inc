PalletTown_Interior1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_Interior1_OnTransition
	.byte 0

PalletTown_Interior1_OnTransition::
	call_if_lt 0x4058, 2, PalletTown_Interior1_EventScript_OnTransition_1
	call_if_ge 0x4058, 2, PalletTown_Interior1_EventScript_OnTransition_2
	end

PalletTown_Interior1_EventScript_OnTransition_1::
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm 1, 5, 4
	return

PalletTown_Interior1_EventScript_OnTransition_2::
	setvar VAR_TEMP_1, 1
	return

PalletTown_Interior1_EventScript_Daisy::
	lock
	faceplayer
	special QuestLog_CutRecording
	goto_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, PalletTown_Interior1_EventScript_Daisy_1
	msgbox PalletTown_Interior1_Text_Daisy_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 0, PalletTown_Interior1_EventScript_Daisy_2
	msgbox PalletTown_Interior1_Text_Daisy_2
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	goto_if_ge VAR_0x8004, 6, PalletTown_Interior1_EventScript_Daisy_2
	specialvar VAR_RESULT, GetPartyMonSpecies
	goto_if_eq VAR_RESULT, 0x19C, PalletTown_Interior1_EventScript_Daisy_3
	msgbox PalletTown_Interior1_Text_Daisy_3
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special DaisyMassageServices
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox PalletTown_Interior1_Text_Daisy_4
	release
	end

PalletTown_Interior1_EventScript_Daisy_1::
	msgbox PalletTown_Interior1_Text_Daisy_5
	specialvar VAR_RESULT, GetLeadMonFriendship
	switch VAR_RESULT
	case 0, PalletTown_Interior1_EventScript_Daisy_4
	case 1, PalletTown_Interior1_EventScript_Daisy_5
	case 2, PalletTown_Interior1_EventScript_Daisy_6
	case 3, PalletTown_Interior1_EventScript_Daisy_7
	case 4, PalletTown_Interior1_EventScript_Daisy_8
	case 5, PalletTown_Interior1_EventScript_Daisy_9
	case 6, PalletTown_Interior1_EventScript_Daisy_10
	end

PalletTown_Interior1_EventScript_Daisy_2::
	msgbox PalletTown_Interior1_Text_Daisy_6
	release
	end

PalletTown_Interior1_EventScript_Daisy_3::
	msgbox PalletTown_Interior1_Text_Daisy_7
	release
	end

PalletTown_Interior1_EventScript_Daisy_4::
	msgbox PalletTown_Interior1_Text_Daisy_8
	release
	end

PalletTown_Interior1_EventScript_Daisy_5::
	msgbox PalletTown_Interior1_Text_Daisy_9
	release
	end

PalletTown_Interior1_EventScript_Daisy_6::
	msgbox PalletTown_Interior1_Text_Daisy_10
	release
	end

PalletTown_Interior1_EventScript_Daisy_7::
	msgbox PalletTown_Interior1_Text_Daisy_11
	release
	end

PalletTown_Interior1_EventScript_Daisy_8::
	msgbox PalletTown_Interior1_Text_Daisy_12
	release
	end

PalletTown_Interior1_EventScript_Daisy_9::
	msgbox PalletTown_Interior1_Text_Daisy_13
	release
	end

PalletTown_Interior1_EventScript_Daisy_10::
	msgbox PalletTown_Interior1_Text_Daisy_14
	release
	end

PalletTown_Interior1_EventScript_TownMap::
	msgbox PalletTown_Interior1_Text_TownMap, MSGBOX_NPC
	end

PalletTown_Interior1_EventScript_Sign1::
	msgbox PalletTown_Interior1_Text_Sign1, MSGBOX_SIGN
	end

PalletTown_Interior1_EventScript_Sign3::
	msgbox PalletTown_Interior1_Text_Sign3, MSGBOX_SIGN
	end
