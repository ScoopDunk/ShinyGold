SaffronCity_Interior3_MapScripts::
	.byte 0

SaffronCity_Interior3_EventScript_Doduo::
	msgbox SaffronCity_Interior3_Text_Doduo, MSGBOX_AUTOCLOSE
	waitse
	playmoncry SPECIES_DODRIO, 0x200
	.byte 0xFF @ invalid opcode (script stops)

SaffronCity_Interior3_EventScript_Pikachu::
	msgbox SaffronCity_Interior3_Text_Pikachu, MSGBOX_AUTOCLOSE
	end

SaffronCity_Interior3_EventScript_Lass::
	call_if_set 0x11CF, SaffronCity_Interior3_EventScript_Lass_1
	call_if_set 0x1189, SaffronCity_Interior3_EventScript_Lass_2
	call_if_set 0x1185, SaffronCity_Interior3_EventScript_Lass_3
	applymovement 4, SaffronCity_Interior3_Movement_Lass_1
	delay 16
	setobjectxy 4, 15, 6
	checkplayergender
	call_if_eq VAR_RESULT, 1, SaffronCity_Interior3_EventScript_Lass_4
	call SaffronCity_Interior3_EventScript_Lass_5

SaffronCity_Interior3_EventScript_Lass_10::
	lock
	faceplayer
	msgbox SaffronCity_Interior3_Text_Lass_1, MSGBOX_NPC
	applymovement 6, SaffronCity_Interior3_Movement_Lass_1
	delay 1
	applymovement 7, SaffronCity_Interior3_Movement_Lass_1
	delay 16
	setobjectxy 6, 15, 6
	setobjectxy 7, 15, 6
	setobjectxy 4, 9, 6
	msgbox SaffronCity_Interior3_Text_Lass_2, MSGBOX_NPC
	end

SaffronCity_Interior3_EventScript_Lass_1::
	applymovement 4, SaffronCity_Interior3_Movement_Lass_1
	delay 16
	setobjectxy 4, 15, 6
	checkplayergender
	call_if_eq VAR_RESULT, 1, SaffronCity_Interior3_EventScript_Lass_6
	call SaffronCity_Interior3_EventScript_Lass_7
	end

SaffronCity_Interior3_EventScript_Lass_2::
	msgbox SaffronCity_Interior3_Text_Lass_3, MSGBOX_NPC
	giveitem ITEM_EON_TICKET
	removeitem ITEM_METEORITE
	setflag 0x11CF
	clearflag 0x1188
	setflag 0x1187
	msgbox SaffronCity_Interior3_Text_Lass_4, MSGBOX_NPC
	end

SaffronCity_Interior3_EventScript_Lass_3::
	applymovement 4, SaffronCity_Interior3_Movement_Lass_1
	delay 16
	setobjectxy 4, 15, 6
	checkplayergender
	call_if_eq VAR_RESULT, 1, SaffronCity_Interior3_EventScript_Lass_8
	call SaffronCity_Interior3_EventScript_Lass_9
	end

SaffronCity_Interior3_EventScript_Lass_4::
	setobjectxy 7, 9, 6
	applymovement 7, SaffronCity_Interior3_Movement_Lass_2
	call SaffronCity_Interior3_EventScript_Lass_10
	end

SaffronCity_Interior3_EventScript_Lass_5::
	setobjectxy 6, 9, 6
	applymovement 6, SaffronCity_Interior3_Movement_Lass_2
	call SaffronCity_Interior3_EventScript_Lass_10
	end

SaffronCity_Interior3_EventScript_Lass_6::
	setobjectxy 7, 9, 6
	applymovement 7, SaffronCity_Interior3_Movement_Lass_2
	call SaffronCity_Interior3_EventScript_Lass_11
	end

SaffronCity_Interior3_EventScript_Lass_7::
	setobjectxy 6, 9, 6
	applymovement 6, SaffronCity_Interior3_Movement_Lass_2
	call SaffronCity_Interior3_EventScript_Lass_11
	end

SaffronCity_Interior3_EventScript_Lass_8::
	setobjectxy 7, 9, 6
	applymovement 7, SaffronCity_Interior3_Movement_Lass_2
	call SaffronCity_Interior3_EventScript_Lass_12
	end

SaffronCity_Interior3_EventScript_Lass_9::
	setobjectxy 6, 9, 6
	applymovement 6, SaffronCity_Interior3_Movement_Lass_2
	call SaffronCity_Interior3_EventScript_Lass_12
	end

SaffronCity_Interior3_Movement_Lass_1::
	face_up
	face_left
	face_down_fast
	face_right
	face_up
	face_left
	face_down_fast
	face_right
	step_end

SaffronCity_Interior3_EventScript_Lass_11::
	lock
	faceplayer
	msgbox SaffronCity_Interior3_Text_Lass_5, MSGBOX_NPC
	applymovement 6, SaffronCity_Interior3_Movement_Lass_1
	delay 1
	applymovement 7, SaffronCity_Interior3_Movement_Lass_1
	delay 16
	setobjectxy 6, 15, 6
	setobjectxy 7, 15, 6
	setobjectxy 4, 9, 6
	msgbox SaffronCity_Interior3_Text_Lass_6, MSGBOX_NPC
	end

SaffronCity_Interior3_EventScript_Lass_12::
	lock
	faceplayer
	msgbox SaffronCity_Interior3_Text_Lass_7, MSGBOX_NPC
	applymovement 6, SaffronCity_Interior3_Movement_Lass_1
	delay 1
	applymovement 7, SaffronCity_Interior3_Movement_Lass_1
	delay 16
	setobjectxy 6, 15, 6
	setobjectxy 7, 15, 6
	setobjectxy 4, 9, 6
	msgbox SaffronCity_Interior3_Text_Lass_8, MSGBOX_NPC
	setflag 0x11CE
	release
	end

SaffronCity_Interior3_Movement_Lass_2::
	face_player
	step_end

SaffronCity_Interior3_EventScript_Sign1::
	msgbox SaffronCity_Interior3_Text_Sign1, MSGBOX_SIGN
	end

SaffronCity_Interior3_EventScript_Sign2::
	msgbox SaffronCity_Interior3_Text_Sign2, MSGBOX_SIGN
	end
