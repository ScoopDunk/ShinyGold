SSAqua_Interior3_MapScripts::
	.byte 0

SSAqua_Interior3_EventScript_Sailor::
	call_if_set 0x1177, SSAqua_Interior3_EventScript_Sailor_1
	call_if_set 0x1167, SSAqua_Interior3_EventScript_Sailor_2
	clearflag 0x1169
	msgbox SSAqua_Interior3_Text_Sailor_1, MSGBOX_NPC
	end

SSAqua_Interior3_EventScript_Sailor_1::
	msgbox SSAqua_Interior3_Text_Sailor_2, MSGBOX_NPC
	end

SSAqua_Interior3_EventScript_Sailor_2::
	msgbox SSAqua_Interior3_Text_Sailor_3, MSGBOX_NPC
	end

SSAqua_Interior3_EventScript_JugglerFritz::
	trainerbattle_single TRAINER_JUGGLER_FRITZ, SSAqua_Interior3_Text_JugglerFritzIntro, SSAqua_Interior3_Text_JugglerFritzDefeat
	msgbox SSAqua_Interior3_Text_JugglerFritz, MSGBOX_AUTOCLOSE
	end

SSAqua_Interior3_EventScript_SailorJeff::
	trainerbattle_single TRAINER_SAILOR_JEFF, SSAqua_Interior3_Text_SailorJeffIntro, SSAqua_Interior3_Text_SailorJeffDefeat
	msgbox SSAqua_Interior3_Text_SailorJeff, MSGBOX_AUTOCLOSE
	end

SSAqua_Interior3_EventScript_PicnickerDebra::
	trainerbattle_single TRAINER_PICNICKER_DEBRA, SSAqua_Interior3_Text_PicnickerDebraIntro, SSAqua_Interior3_Text_PicnickerDebraDefeat
	msgbox SSAqua_Interior3_Text_PicnickerDebra, MSGBOX_AUTOCLOSE
	end

SSAqua_Interior3_EventScript_FishermanJonah::
	trainerbattle_single TRAINER_FISHERMAN_JONAH, SSAqua_Interior3_Text_FishermanJonahIntro, SSAqua_Interior3_Text_FishermanJonahDefeat
	call_if_set 0x11A6, SSAqua_Interior3_EventScript_FishermanJonah_1
	msgbox SSAqua_Interior3_Text_FishermanJonah, MSGBOX_AUTOCLOSE
	end

SSAqua_Interior3_EventScript_FishermanJonah_1::
	msgbox SSAqua_Interior3_Text_FishermanJonahIntro, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_FISHERMAN_JONAH, 0, SSAqua_Interior3_Text_FishermanJonahDefeat, SSAqua_Interior3_Text_FishermanJonahVictory
	clearflag 0x11A6
	end

SSAqua_Interior3_EventScript_RocketF::
	applymovement 6, SSAqua_Interior3_Movement_RocketF
	msgbox SSAqua_Interior3_Text_RocketF, MSGBOX_AUTOCLOSE
	end

SSAqua_Interior3_Movement_RocketF::
	face_down_fast
	step_end

SSAqua_Interior3_EventScript_SailorKenneth::
	trainerbattle_single TRAINER_SAILOR_KENNETH, SSAqua_Interior3_Text_SailorKennethIntro, SSAqua_Interior3_Text_SailorKennethDefeat
	call_if_set 0x119C, SSAqua_Interior3_EventScript_SailorKenneth_1
	msgbox SSAqua_Interior3_Text_SailorKenneth, MSGBOX_AUTOCLOSE
	end

SSAqua_Interior3_EventScript_SailorKenneth_1::
	msgbox SSAqua_Interior3_Text_SailorKennethIntro, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_SAILOR_KENNETH, 0, SSAqua_Interior3_Text_SailorKennethDefeat, SSAqua_Interior3_Text_FishermanJonahVictory
	clearflag 0x119C
	end

SSAqua_Interior3_EventScript_TeacherShirley::
	trainerbattle_single TRAINER_TEACHER_SHIRLEY, SSAqua_Interior3_Text_TeacherShirleyIntro, SSAqua_Interior3_Text_TeacherShirleyDefeat
	call_if_set 0x119D, SSAqua_Interior3_EventScript_TeacherShirley_1
	msgbox SSAqua_Interior3_Text_TeacherShirley, MSGBOX_AUTOCLOSE
	end

SSAqua_Interior3_EventScript_TeacherShirley_1::
	msgbox SSAqua_Interior3_Text_TeacherShirleyIntro, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_TEACHER_SHIRLEY, 0, SSAqua_Interior3_Text_TeacherShirleyDefeat, SSAqua_Interior3_Text_FishermanJonahVictory
	clearflag 0x119D
	end

SSAqua_Interior3_EventScript_SchoolboyNate::
	trainerbattle_single TRAINER_SCHOOLBOY_NATE, SSAqua_Interior3_Text_SchoolboyNateIntro, SSAqua_Interior3_Text_SchoolboyNateDefeat
	call_if_set 0x119E, SSAqua_Interior3_EventScript_SchoolboyNate_1
	msgbox SSAqua_Interior3_Text_SchoolboyNate, MSGBOX_AUTOCLOSE
	end

SSAqua_Interior3_EventScript_SchoolboyNate_1::
	msgbox SSAqua_Interior3_Text_SchoolboyNateIntro, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_SCHOOLBOY_NATE, 0, SSAqua_Interior3_Text_SchoolboyNateDefeat, SSAqua_Interior3_Text_FishermanJonahVictory
	clearflag 0x119E
	end

SSAqua_Interior3_EventScript_SchoolboyRicky::
	trainerbattle_single TRAINER_SCHOOLBOY_RICKY, SSAqua_Interior3_Text_SchoolboyRickyIntro, SSAqua_Interior3_Text_SchoolboyRickyDefeat
	call_if_set 0x119F, SSAqua_Interior3_EventScript_SchoolboyRicky_1
	msgbox SSAqua_Interior3_Text_SchoolboyRicky, MSGBOX_AUTOCLOSE
	end

SSAqua_Interior3_EventScript_SchoolboyRicky_1::
	msgbox SSAqua_Interior3_Text_SchoolboyRickyIntro, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_SCHOOLBOY_RICKY, 0, SSAqua_Interior3_Text_SchoolboyRickyDefeat, SSAqua_Interior3_Text_FishermanJonahVictory
	clearflag 0x119F
	end

SSAqua_Interior3_EventScript_BlackBeltWai::
	trainerbattle_single TRAINER_BLACK_BELT_WAI, SSAqua_Interior3_Text_BlackBeltWaiIntro, SSAqua_Interior3_Text_BlackBeltWaiDefeat
	call_if_set 0x11A8, SSAqua_Interior3_EventScript_BlackBeltWai_1
	msgbox SSAqua_Interior3_Text_BlackBeltWai, MSGBOX_AUTOCLOSE
	end

SSAqua_Interior3_EventScript_BlackBeltWai_1::
	msgbox SSAqua_Interior3_Text_BlackBeltWaiIntro, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_BLACK_BELT_WAI, 0, SSAqua_Interior3_Text_BlackBeltWaiDefeat, SSAqua_Interior3_Text_FishermanJonahVictory
	clearflag 0x11A8
	end

SSAqua_Interior3_EventScript_SailorGarrett::
	trainerbattle_single TRAINER_SAILOR_GARRETT, SSAqua_Interior3_Text_SailorGarrettIntro, SSAqua_Interior3_Text_SailorGarrettDefeat
	call_if_set 0x11A7, SSAqua_Interior3_EventScript_SailorGarrett_1
	msgbox SSAqua_Interior3_Text_SailorGarrett, MSGBOX_AUTOCLOSE
	end

SSAqua_Interior3_EventScript_SailorGarrett_1::
	msgbox SSAqua_Interior3_Text_SailorGarrettIntro, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_SAILOR_GARRETT, 0, SSAqua_Interior3_Text_SailorGarrettDefeat, SSAqua_Interior3_Text_FishermanJonahVictory
	clearflag 0x11A7
	end

SSAqua_Interior3_EventScript_Trigger1::
	lockall
	setvar VAR_TEMP_1, 0
	goto SSAqua_Interior3_EventScript_Trigger1_1

SSAqua_Interior3_EventScript_Trigger1_1::
	textcolor NPC_TEXT_COLOR_MALE
	playse SE_EXIT
	delay 5
	playbgm MUS_ENCOUNTER_RIVAL, 0
	addobject 1
	delay 10
	applymovement 1, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 20
	call_if_eq VAR_TEMP_1, 0, SSAqua_Interior3_EventScript_Trigger1_2
	call_if_eq VAR_TEMP_1, 1, SSAqua_Interior3_EventScript_Trigger1_3
	call_if_eq VAR_TEMP_1, 2, SSAqua_Interior3_EventScript_Trigger1_4
	msgbox SSAqua_Interior3_Text_Trigger1_1
	setvar VAR_LAST_TALKED, 1
	call_if_eq VAR_STARTER_MON, 2, SSAqua_Interior3_EventScript_Trigger1_5
	call_if_eq VAR_STARTER_MON, 1, SSAqua_Interior3_EventScript_Trigger1_6
	call_if_eq VAR_STARTER_MON, 0, SSAqua_Interior3_EventScript_Trigger1_7
	msgbox SSAqua_Interior3_Text_Trigger1_2
	closemessage
	delay 10
	playbgm MUS_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, SSAqua_Interior3_EventScript_Trigger1_8
	call_if_eq VAR_TEMP_1, 1, SSAqua_Interior3_EventScript_Trigger1_9
	call_if_eq VAR_TEMP_1, 2, SSAqua_Interior3_EventScript_Trigger1_10
	fadedefaultbgm
	removeobject 1
	setvar 0x405B, 1
	releaseall
	end

SSAqua_Interior3_EventScript_Trigger1_2::
	applymovement 1, SSAqua_Interior3_Movement_Trigger1_1
	waitmovement 0
	return

SSAqua_Interior3_EventScript_Trigger1_3::
	applymovement 1, SSAqua_Interior3_Movement_Trigger1_2
	applymovement LOCALID_PLAYER, SSAqua_Interior3_Movement_Trigger1_3
	waitmovement 0
	return

SSAqua_Interior3_EventScript_Trigger1_4::
	applymovement LOCALID_PLAYER, SSAqua_Interior3_Movement_Trigger1_4
	applymovement 1, SSAqua_Interior3_Movement_Trigger1_5
	waitmovement 0
	return

SSAqua_Interior3_EventScript_Trigger1_5::
	trainerbattle_no_intro TRAINER_SCHOOLBOY_KIPP, SSAqua_Interior3_Text_Trigger1Defeat
	return

SSAqua_Interior3_EventScript_Trigger1_6::
	trainerbattle_no_intro TRAINER_CHAMPION_427, SSAqua_Interior3_Text_Trigger1Defeat
	return

SSAqua_Interior3_EventScript_Trigger1_7::
	trainerbattle_no_intro TRAINER_CHAMPION_428, SSAqua_Interior3_Text_Trigger1Defeat
	return

SSAqua_Interior3_EventScript_Trigger1_8::
	applymovement 1, SSAqua_Interior3_Movement_Trigger1_6
	waitmovement 0
	return

SSAqua_Interior3_EventScript_Trigger1_9::
	applymovement 1, SSAqua_Interior3_Movement_Trigger1_7
	waitmovement 0
	return

SSAqua_Interior3_EventScript_Trigger1_10::
	applymovement 1, SSAqua_Interior3_Movement_Trigger1_8
	waitmovement 0
	return

SSAqua_Interior3_Movement_Trigger1_1::
	walk_down
	walk_down
	walk_down
	step_end

SSAqua_Interior3_Movement_Trigger1_2::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

SSAqua_Interior3_Movement_Trigger1_3::
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SSAqua_Interior3_Movement_Trigger1_4::
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SSAqua_Interior3_Movement_Trigger1_5::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	delay_4
	step_end

SSAqua_Interior3_Movement_Trigger1_6::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SSAqua_Interior3_Movement_Trigger1_7::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SSAqua_Interior3_Movement_Trigger1_8::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SSAqua_Interior3_EventScript_Trigger2::
	lockall
	setvar VAR_TEMP_1, 1
	goto SSAqua_Interior3_EventScript_Trigger1_1

SSAqua_Interior3_EventScript_Trigger3::
	lockall
	setvar VAR_TEMP_1, 2
	goto SSAqua_Interior3_EventScript_Trigger1_1

SSAqua_Interior3_EventScript_Trigger4::
	call_if_set 0x1167, SSAqua_Interior3_EventScript_Trigger4_1
	call_if_set 0x1168, SSAqua_Interior3_EventScript_Trigger4_2
	release
	end

SSAqua_Interior3_EventScript_Trigger4_1::
	release
	end

SSAqua_Interior3_EventScript_Trigger4_2::
	clearflag 0x1168
	applymovement 1, SSAqua_Interior3_Movement_Trigger4
	delay 32
	release
	end

SSAqua_Interior3_Movement_Trigger4::
	walk_left
	face_down_fast
	step_end

SSAqua_Interior3_EventScript_Trigger5::
	call_if_set 0x1167, SSAqua_Interior3_EventScript_Trigger5_1
	call_if_unset 0x1168, SSAqua_Interior3_EventScript_Trigger5_2
	release
	end

SSAqua_Interior3_EventScript_Trigger5_1::
	release
	end

SSAqua_Interior3_EventScript_Trigger5_2::
	setflag 0x1168
	applymovement 1, SSAqua_Interior3_Movement_Trigger5
	delay 32
	release
	end

SSAqua_Interior3_Movement_Trigger5::
	walk_right
	face_down_fast
	step_end
