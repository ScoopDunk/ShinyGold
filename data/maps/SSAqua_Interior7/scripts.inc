SSAqua_Interior7_MapScripts::
	.byte 0

SSAqua_Interior7_EventScript_RedNormal::
	call_if_set 0x1178, SSAqua_Interior7_EventScript_RedNormal_1
	setflag 0x1178
	setflag 0x116D
	clearflag 0x116C
	msgbox SSAqua_Interior7_Text_RedNormal_1, MSGBOX_AUTOCLOSE
	end

SSAqua_Interior7_EventScript_RedNormal_1::
	msgbox SSAqua_Interior7_Text_RedNormal_2, MSGBOX_AUTOCLOSE
	end
