VictoryRoad_Cave2_MapScripts::
	@ ShinyGold: 1 entry with invalid type(s) 0x6C dropped (inert: the engine skips them)
	.byte 0

VictoryRoad_Cave2_EventScript_ItemTm26::
	finditem ITEM_TM26
	end

VictoryRoad_Cave2_EventScript_ItemFullRestore::
	finditem ITEM_FULL_RESTORE
	end

VictoryRoad_Cave2_EventScript_Trigger1::
	call_if_set FLAG_BADGE08_GET, VictoryRoad_Cave2_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, VictoryRoad_Cave2_Movement_Trigger1
	delay 48
	end

VictoryRoad_Cave2_EventScript_Trigger1_1::
	checkpartymove MOVE_WHIRLPOOL
	call_if_eq VAR_RESULT, 6, VictoryRoad_Cave2_EventScript_Trigger1_2
	setfieldeffectargument 0, VAR_RESULT
	msgbox VictoryRoad_Cave2_Text_Trigger1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 0, VictoryRoad_Cave2_EventScript_Trigger1_2
	closemessage
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	release
	end

VictoryRoad_Cave2_EventScript_Trigger1_2::
	releaseall
	applymovement LOCALID_PLAYER, VictoryRoad_Cave2_Movement_Trigger1
	delay 48
	end

VictoryRoad_Cave2_Movement_Trigger1::
	walk_fast_up
	face_left
	face_down_fast
	face_right
	face_up
	face_left
	face_down_fast
	face_right
	face_up
	face_left
	face_down_fast
	face_right
	face_up
	step_end

VictoryRoad_Cave2_EventScript_Trigger3::
	call_if_set FLAG_BADGE08_GET, VictoryRoad_Cave2_EventScript_Trigger3_1
	applymovement LOCALID_PLAYER, VictoryRoad_Cave2_Movement_Trigger3
	delay 48
	end

VictoryRoad_Cave2_EventScript_Trigger3_1::
	checkpartymove MOVE_WHIRLPOOL
	call_if_eq VAR_RESULT, 6, VictoryRoad_Cave2_EventScript_Trigger3_2
	setfieldeffectargument 0, VAR_RESULT
	msgbox VictoryRoad_Cave2_Text_Trigger1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 0, VictoryRoad_Cave2_EventScript_Trigger3_2
	closemessage
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	release
	end

VictoryRoad_Cave2_EventScript_Trigger3_2::
	releaseall
	applymovement LOCALID_PLAYER, VictoryRoad_Cave2_Movement_Trigger3
	delay 48
	end

VictoryRoad_Cave2_Movement_Trigger3::
	walk_fast_down
	face_left
	face_down_fast
	face_right
	face_up
	face_left
	face_down_fast
	face_right
	face_up
	face_left
	face_down_fast
	face_right
	face_up
	step_end
