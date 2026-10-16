CeruleanCity_Gym_MapScripts::
	.byte 0

CeruleanCity_Gym_EventScript_SwimmerMParker::
	trainerbattle_single TRAINER_SWIMMER_M_PARKER, CeruleanCity_Gym_Text_SwimmerMParkerIntro, CeruleanCity_Gym_Text_SwimmerMParkerDefeat
	msgbox CeruleanCity_Gym_Text_SwimmerMParker, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_PicnickerDiana::
	trainerbattle_single TRAINER_PICNICKER_DIANA, CeruleanCity_Gym_Text_PicnickerDianaIntro, CeruleanCity_Gym_Text_PicnickerDianaDefeat
	msgbox CeruleanCity_Gym_Text_PicnickerDiana, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_LeaderMisty::
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	special UpdatePickStateFromSpecialVar8005
	call CeruleanCity_Gym_EventScript_LeaderMisty_1
	trainerbattle_single TRAINER_LEADER_MISTY, CeruleanCity_Gym_Text_LeaderMistyIntro, CeruleanCity_Gym_Text_LeaderMistyDefeat, CeruleanCity_Gym_EventScript_LeaderMistyContinue, NO_MUSIC
	msgbox CeruleanCity_Gym_Text_LeaderMisty, MSGBOX_NPC
	end

CeruleanCity_Gym_EventScript_LeaderMisty_1::
	setvar 0x7030, 0x128
	setvar 0x7033, 0x109
	release
	return

CeruleanCity_Gym_EventScript_LeaderMistyContinue::
	setflag 0x1180
	call LavenderTown_EventScript_Trigger6_3
	msgbox CeruleanCity_Gym_Text_LeaderMisty, MSGBOX_NPC
	end

CeruleanCity_Gym_EventScript_GymGuy::
	call_if_set 0x1180, CeruleanCity_Gym_EventScript_GymGuy_1
	msgbox CeruleanCity_Gym_Text_GymGuy_1, MSGBOX_NPC
	end

CeruleanCity_Gym_EventScript_GymGuy_1::
	msgbox CeruleanCity_Gym_Text_GymGuy_2, MSGBOX_NPC
	end

CeruleanCity_Gym_EventScript_SwimmerFBriana::
	trainerbattle_single TRAINER_SWIMMER_F_BRIANA, CeruleanCity_Gym_Text_SwimmerFBrianaIntro, CeruleanCity_Gym_Text_SwimmerFBrianaDefeat
	msgbox CeruleanCity_Gym_Text_SwimmerFBriana, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_SwimmerFDiana::
	trainerbattle_single TRAINER_SWIMMER_F_DIANA, CeruleanCity_Gym_Text_SwimmerFDianaIntro, CeruleanCity_Gym_Text_SwimmerFDianaDefeat
	msgbox CeruleanCity_Gym_Text_SwimmerFDiana, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_ItemSecretKey::
	finditem ITEM_SECRET_KEY
	end

CeruleanCity_Gym_EventScript_Trigger1::
	call_if_set 0x11C0, CeruleanCity_Gym_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, CeruleanCity_Gym_Movement_Trigger1_1
	delay 32
	call CeruleanCity_Gym_EventScript_Trigger1_2
	end

CeruleanCity_Gym_EventScript_Trigger1_1::
	release
	end

CeruleanCity_Gym_EventScript_Trigger1_2::
	applymovement 2, CeruleanCity_Gym_Movement_Trigger1_2
	delay 48
	applymovement 2, CeruleanCity_Gym_Movement_Trigger1_3
	delay 64
	applymovement 2, CeruleanCity_Gym_Movement_Trigger1_4
	delay 16
	playbgm MUS_SILPH, 51
	msgbox CeruleanCity_Gym_Text_Trigger1_1, MSGBOX_NPC
	applymovement 2, CeruleanCity_Gym_Movement_Trigger1_5
	delay 48
	applymovement 2, CeruleanCity_Gym_Movement_Trigger1_6
	delay 16
	msgbox CeruleanCity_Gym_Text_Trigger1_2, MSGBOX_NPC
	applymovement 2, CeruleanCity_Gym_Movement_Trigger1_7
	delay 16
	msgbox CeruleanCity_Gym_Text_Trigger1_3, MSGBOX_NPC
	applymovement 2, CeruleanCity_Gym_Movement_Trigger1_8
	delay 64
	playbgm MUS_GYM, 51
	setflag 0x11C0
	setflag 0x11B8
	clearflag 0x11B9
	setflag 0x11BB
	clearflag 0x11BC
	setvar VAR_GOLD_POWER_PLANT_SCENE, 2
	release
	end

CeruleanCity_Gym_Movement_Trigger1_1::
	walk_right
	walk_right
	walk_up
	step_end

CeruleanCity_Gym_Movement_Trigger1_2::
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

CeruleanCity_Gym_Movement_Trigger1_3::
	jump_special_up
	step_end

CeruleanCity_Gym_Movement_Trigger1_4::
	walk_down
	step_end

CeruleanCity_Gym_Movement_Trigger1_5::
	emote_exclamation_mark
	step_end

CeruleanCity_Gym_Movement_Trigger1_6::
	walk_slow_up
	face_down_fast
	step_end

CeruleanCity_Gym_Movement_Trigger1_7::
	walk_fast_down
	step_end

CeruleanCity_Gym_Movement_Trigger1_8::
	walk_fast_left
	walk_fast_down
	walk_fast_down
	set_invisible
	walk_fast_down
	walk_fast_down
	step_end

CeruleanCity_Gym_EventScript_Trigger2::
	call_if_set 0x11C0, CeruleanCity_Gym_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, CeruleanCity_Gym_Movement_Trigger2
	delay 16
	call CeruleanCity_Gym_EventScript_Trigger1_2
	end

CeruleanCity_Gym_Movement_Trigger2::
	walk_right
	face_up
	step_end

CeruleanCity_Gym_EventScript_Trigger3::
	call_if_set 0x11C0, CeruleanCity_Gym_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, CeruleanCity_Gym_Movement_Trigger3
	delay 16
	call CeruleanCity_Gym_EventScript_Trigger1_2
	end

CeruleanCity_Gym_Movement_Trigger3::
	walk_up
	step_end

@ Pure Gold/Silver: GYM statue as in G/S (WINNING TRAINERS: the player once the CASCADEBADGE is won);
@ while MISTY and her trainers are out, notes are left instead (pokegold CeruleanGym.asm)
CeruleanCity_Gym_EventScript_Sign1::
	goto_if_set 0x11C2, CeruleanCity_Gym_EventScript_Sign1_4
	goto CeruleanCity_Gym_EventScript_Statue

CeruleanCity_Gym_EventScript_Statue::
	goto_if_set 0x1180, CeruleanCity_Gym_EventScript_Sign1_2
	msgbox CeruleanCity_Gym_Text_Sign1_1, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_Sign1_2::
	msgbox CeruleanCity_Gym_Text_Sign1_3, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_Sign1_4::
	msgbox CeruleanCity_Gym_Text_Sign1_5, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_Sign2::
	goto_if_set 0x11C2, CeruleanCity_Gym_EventScript_Sign2_1
	goto CeruleanCity_Gym_EventScript_Statue

CeruleanCity_Gym_EventScript_Sign2_1::
	msgbox CeruleanCity_Gym_Text_Sign2, MSGBOX_AUTOCLOSE
	end
