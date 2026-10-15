SeaCavern_Interior1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SeaCavern_Interior1_OnTransition
	.byte 0

SeaCavern_Interior1_OnTransition::
	call EventScript_TryDarkenRuins
	end

SeaCavern_Interior1_EventScript_Trigger1::
	warp MAP_SEA_CAVERN_INTERIOR4, 1, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

SeaCavern_Interior1_EventScript_Trigger2::
	call_if_set 0x117A, SeaCavern_Interior1_EventScript_Trigger2_1
	applymovement LOCALID_PLAYER, SeaCavern_Interior1_Movement_Trigger2_1
	delay 16
	call SeaCavern_Interior1_EventScript_Trigger2_2
	end

SeaCavern_Interior1_EventScript_Trigger2_1::
	release
	end

SeaCavern_Interior1_EventScript_Trigger2_2::
	msgbox SeaCavern_Interior1_Text_Trigger2_1, MSGBOX_NPC
	applymovement 2, SeaCavern_Interior1_Movement_Trigger2_2
	delay 16
	applymovement 1, SeaCavern_Interior1_Movement_Trigger2_2
	delay 1
	msgbox SeaCavern_Interior1_Text_Trigger2_2, MSGBOX_NPC
	applymovement 1, SeaCavern_Interior1_Movement_Trigger2_3
	delay 16
	playbgm MUS_ENCOUNTER_BOY, 51
	msgbox SeaCavern_Interior1_Text_Trigger2_3, MSGBOX_NPC
	call SilphCo_Interior6_EventScript_Trigger1_1
	trainerbattle_earlyrival TRAINER_PKMN_TRAINER_JESS_AND_JAMIE, 0, SeaCavern_Interior1_Text_Trigger2Defeat, SeaCavern_Interior1_Text_Trigger2Victory
	setflag 0x117A
	call SlowpokeWell_Cave1_EventScript_RocketM_1
	msgbox SeaCavern_Interior1_Text_Trigger2_4, MSGBOX_NPC
	warp MAP_SEA_CAVERN_INTERIOR1, 2, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

SeaCavern_Interior1_Movement_Trigger2_1::
	walk_left
	step_end

SeaCavern_Interior1_Movement_Trigger2_2::
	face_right
	step_end

SeaCavern_Interior1_Movement_Trigger2_3::
	walk_down
	walk_right
	step_end

SeaCavern_Interior1_EventScript_Trigger3::
	call_if_set 0x117A, SeaCavern_Interior1_EventScript_Trigger2_1
	applymovement LOCALID_PLAYER, SeaCavern_Interior1_Movement_Trigger3
	delay 16
	call SeaCavern_Interior1_EventScript_Trigger2_2
	end

SeaCavern_Interior1_Movement_Trigger3::
	walk_left
	walk_left
	step_end

SeaCavern_Interior1_EventScript_Trigger4::
	call_if_set 0x117A, SeaCavern_Interior1_EventScript_Trigger2_1
	applymovement LOCALID_PLAYER, SeaCavern_Interior1_Movement_Trigger4
	delay 32
	call SeaCavern_Interior1_EventScript_Trigger2_2
	end

SeaCavern_Interior1_Movement_Trigger4::
	walk_left
	walk_left
	walk_left
	step_end
