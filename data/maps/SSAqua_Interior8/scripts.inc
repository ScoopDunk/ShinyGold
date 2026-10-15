SSAqua_Interior8_MapScripts::
	.byte 0

SSAqua_Interior8_EventScript_Captain::
	call_if_set 0x117D, SSAqua_Interior8_EventScript_Captain_1
	msgbox SSAqua_Interior8_Text_Captain_1, MSGBOX_NPC
	end

SSAqua_Interior8_EventScript_Captain_1::
	msgbox SSAqua_Interior8_Text_Captain_2, MSGBOX_NPC
	end

SSAqua_Interior8_EventScript_Woman1::
	applymovement 2, SSAqua_Interior8_Movement_Woman1
	msgbox SSAqua_Interior8_Text_Woman1_1, MSGBOX_AUTOCLOSE
	msgbox SSAqua_Interior8_Text_Woman1_2, MSGBOX_NPC
	setflag 0x1170
	clearflag 0x1171
	warp MAP_SS_AQUA_INTERIOR8, 1, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

SSAqua_Interior8_Movement_Woman1::
	face_left
	step_end
