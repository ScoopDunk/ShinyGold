ViridianCity_Interior6_MapScripts::
	.byte 0

ViridianCity_Interior6_EventScript_Gentleman::
	msgbox ViridianCity_Interior6_Text_Gentleman, MSGBOX_NPC
	end

ViridianCity_Interior6_EventScript_CableClubReceptionist::
	msgbox ViridianCity_Interior6_Text_CableClubReceptionist, MSGBOX_NPC
	end

ViridianCity_Interior6_EventScript_CooltrainerM::
	msgbox ViridianCity_Interior6_Text_CooltrainerM, MSGBOX_NPC
	end

ViridianCity_Interior6_EventScript_CooltrainerF::
	msgbox ViridianCity_Interior6_Text_CooltrainerF, MSGBOX_NPC
	end

ViridianCity_Interior6_EventScript_Boy::
	msgbox ViridianCity_Interior6_Text_Boy, MSGBOX_NPC
	end

ViridianCity_Interior6_EventScript_Trigger1::
	lock
	applymovement LOCALID_PLAYER, ViridianCity_Interior6_Movement_Trigger1_1
	waitmovement 0
	msgbox ViridianCity_Interior6_Text_Trigger1_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 1, ViridianCity_Interior6_EventScript_Trigger1_1
	msgbox ViridianCity_Interior6_Text_Trigger1_2, MSGBOX_AUTOCLOSE
	applymovement LOCALID_PLAYER, ViridianCity_Interior6_Movement_Trigger1_2
	waitmovement 0
	release
	end

ViridianCity_Interior6_EventScript_Trigger1_1::
	msgbox ViridianCity_Interior6_Text_Trigger1_3, MSGBOX_AUTOCLOSE
	applymovement LOCALID_PLAYER, ViridianCity_Interior6_Movement_Trigger1_3
	waitmovement 0
	msgbox ViridianCity_Interior6_Text_Trigger1_4, MSGBOX_AUTOCLOSE
	releaseall
	special DaisyMassageServices
	trainerbattle_earlyrival TRAINER_PKMN_TRAINER_CAL, 0, ViridianCity_Interior6_Text_Trigger1Defeat, ViridianCity_Interior6_Text_Trigger1Victory
	applymovement LOCALID_PLAYER, ViridianCity_Interior6_Movement_Trigger1_4
	waitmovement 0
	release
	end

ViridianCity_Interior6_Movement_Trigger1_1::
	face_up
	step_end

ViridianCity_Interior6_Movement_Trigger1_2::
	walk_right
	face_left
	step_end

ViridianCity_Interior6_Movement_Trigger1_3::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	face_right
	step_end

ViridianCity_Interior6_Movement_Trigger1_4::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
