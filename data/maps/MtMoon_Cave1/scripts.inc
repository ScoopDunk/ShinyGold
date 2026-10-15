MtMoon_Cave1_MapScripts::
	.byte 0

MtMoon_Cave1_EventScript_Trigger1::
	lock
	call_if_set 0x084, MtMoon_Cave1_EventScript_Trigger1_1
	playbgm MUS_DUMMY, 51
	applymovement LOCALID_PLAYER, MtMoon_Cave1_Movement_Trigger1_1
	waitmovement 0
	applymovement 1, MtMoon_Cave1_Movement_Trigger1_2
	waitmovement 0
	playbgm MUS_ENCOUNTER_RIVAL, 51
	msgbox MtMoon_Cave1_Text_Trigger1_1, MSGBOX_NPC
	call_if_eq VAR_STARTER_MON, 0, MtMoon_Cave1_EventScript_Trigger1_2
	call_if_eq VAR_STARTER_MON, 1, MtMoon_Cave1_EventScript_Trigger1_3
	call_if_eq VAR_STARTER_MON, 2, MtMoon_Cave1_EventScript_Trigger1_4
	msgbox MtMoon_Cave1_Text_Trigger1_2, MSGBOX_NPC
	applymovement 1, MtMoon_Cave1_Movement_Trigger1_3
	waitmovement 0
	setflag 0x084
	clearflag 0x090
	removeobject 1
	release
	end

MtMoon_Cave1_EventScript_Trigger1_1::
	release
	end

MtMoon_Cave1_EventScript_Trigger1_2::
	trainerbattle_earlyrival TRAINER_RIVAL_TERRY_15, 0, MtMoon_Cave1_Text_Trigger1Defeat, MtMoon_Cave1_Text_Trigger1Victory
	return

MtMoon_Cave1_EventScript_Trigger1_3::
	trainerbattle_earlyrival TRAINER_RIVAL_TERRY_17, 0, MtMoon_Cave1_Text_Trigger1Defeat, MtMoon_Cave1_Text_Trigger1Victory
	return

MtMoon_Cave1_EventScript_Trigger1_4::
	trainerbattle_earlyrival TRAINER_RIVAL_TERRY_16, 0, MtMoon_Cave1_Text_Trigger1Defeat, MtMoon_Cave1_Text_Trigger1Victory
	return

MtMoon_Cave1_Movement_Trigger1_1::
	emote_exclamation_mark
	walk_down
	face_right
	step_end

MtMoon_Cave1_Movement_Trigger1_2::
	walk_left
	walk_left
	step_end

MtMoon_Cave1_Movement_Trigger1_3::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtMoon_Cave1_EventScript_Trigger2::
	lock
	call_if_set 0x084, MtMoon_Cave1_EventScript_Trigger1_1
	playbgm MUS_DUMMY, 51
	applymovement LOCALID_PLAYER, MtMoon_Cave1_Movement_Trigger2
	waitmovement 0
	applymovement 1, MtMoon_Cave1_Movement_Trigger1_2
	waitmovement 0
	playbgm MUS_ENCOUNTER_RIVAL, 51
	msgbox MtMoon_Cave1_Text_Trigger1_1, MSGBOX_NPC
	call_if_eq VAR_STARTER_MON, 0, MtMoon_Cave1_EventScript_Trigger1_2
	call_if_eq VAR_STARTER_MON, 1, MtMoon_Cave1_EventScript_Trigger1_3
	call_if_eq VAR_STARTER_MON, 2, MtMoon_Cave1_EventScript_Trigger1_4
	msgbox MtMoon_Cave1_Text_Trigger1_2, MSGBOX_NPC
	applymovement 1, MtMoon_Cave1_Movement_Trigger1_3
	waitmovement 0
	setflag 0x084
	clearflag 0x090
	removeobject 1
	release
	end

MtMoon_Cave1_Movement_Trigger2::
	emote_exclamation_mark
	face_right
	step_end

MtMoon_Cave1_EventScript_Sign::
	msgbox MtMoon_Cave1_Text_Sign, MSGBOX_SIGN
	end
