SSAqua_Interior6_MapScripts::
	.byte 0

SSAqua_Interior6_EventScript_RocketM::
	applymovement 5, SSAqua_Interior6_Movement_RocketM
	msgbox SSAqua_Interior6_Text_RocketM, MSGBOX_AUTOCLOSE
	end

SSAqua_Interior6_Movement_RocketM::
	face_left
	step_end
