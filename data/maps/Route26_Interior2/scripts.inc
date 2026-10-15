Route26_Interior2_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

Route26_Interior2_EventScript_MgDeliveryman::
	msgbox Route26_Interior2_Text_MgDeliveryman, MSGBOX_NPC
	end

Route26_Interior2_EventScript_MgDeliveryman2::
	msgbox Route26_Interior2_Text_MgDeliveryman2, MSGBOX_NPC
	end

Route26_Interior2_EventScript_MgDeliveryman3::
	msgbox Route26_Interior2_Text_MgDeliveryman3, MSGBOX_NPC
	end

Route26_Interior2_EventScript_Trigger1::
	call_if_set 0x1158, Route26_Interior2_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, Route26_Interior2_Movement_Trigger1
	delay 1
	msgbox Route26_Interior2_Text_MgDeliveryman, MSGBOX_NPC
	setflag 0x1158
	release
	end

Route26_Interior2_EventScript_Trigger1_1::
	release
	end

Route26_Interior2_Movement_Trigger1::
	face_left
	step_end
