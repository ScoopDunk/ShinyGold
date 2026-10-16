CianwoodCity_Interior7_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

CianwoodCity_Interior7_EventScript_BlackBeltYoshi::
	trainerbattle_single TRAINER_BLACK_BELT_YOSHI, CianwoodCity_Interior7_Text_BlackBeltYoshiIntro, CianwoodCity_Interior7_Text_BlackBeltYoshiDefeat
	msgbox CianwoodCity_Interior7_Text_BlackBeltYoshi, MSGBOX_AUTOCLOSE
	end

CianwoodCity_Interior7_EventScript_BlackBeltLao::
	trainerbattle_single TRAINER_BLACK_BELT_LAO, CianwoodCity_Interior7_Text_BlackBeltLaoIntro, CianwoodCity_Interior7_Text_BlackBeltLaoDefeat
	msgbox CianwoodCity_Interior7_Text_BlackBeltLao, MSGBOX_AUTOCLOSE
	end

CianwoodCity_Interior7_EventScript_BlackBeltNob::
	trainerbattle_single TRAINER_BLACK_BELT_NOB, CianwoodCity_Interior7_Text_BlackBeltNobIntro, CianwoodCity_Interior7_Text_BlackBeltNobDefeat
	msgbox CianwoodCity_Interior7_Text_BlackBeltNob, MSGBOX_AUTOCLOSE
	end

CianwoodCity_Interior7_EventScript_BlackBeltLung::
	trainerbattle_single TRAINER_BLACK_BELT_LUNG, CianwoodCity_Interior7_Text_BlackBeltLungIntro, CianwoodCity_Interior7_Text_BlackBeltLungDefeat
	msgbox CianwoodCity_Interior7_Text_BlackBeltLung, MSGBOX_AUTOCLOSE
	end

CianwoodCity_Interior7_EventScript_CrushGirl::
	msgbox CianwoodCity_Interior7_Text_CrushGirl, MSGBOX_NPC
	end

CianwoodCity_Interior7_EventScript_BaldingMan::
	call_if_set FLAG_BADGE03_GET, CianwoodCity_Interior7_EventScript_BaldingMan_1
	msgbox CianwoodCity_Interior7_Text_BaldingMan_1, MSGBOX_NPC
	applymovement 9, CianwoodCity_Interior7_Movement_BaldingMan_1
	msgbox CianwoodCity_Interior7_Text_BaldingMan_2, MSGBOX_AUTOCLOSE
	applymovement 10, CianwoodCity_Interior7_Movement_BaldingMan_2
	delay 64
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	special UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_CHUCK_2, CianwoodCity_Interior7_Text_BaldingManIntro, CianwoodCity_Interior7_Text_BaldingManDefeat, CianwoodCity_Interior7_EventScript_BaldingManContinue, NO_MUSIC
	loadword 0, CianwoodCity_Interior7_Text_BaldingMan_3
	callstd 41
	compare_var_to_var 0x0F08, 0x5000
	.byte 0xD5 @ invalid opcode (script stops)

CianwoodCity_Interior7_EventScript_BaldingMan_1::
	msgbox CianwoodCity_Interior7_Text_BaldingMan_3, MSGBOX_NPC
	end

CianwoodCity_Interior7_EventScript_BaldingManContinue::
	@ ShinyGold: overlapping data duplicated from 0x0877D2F0
	setflag FLAG_BADGE03_GET
	msgbox CianwoodCity_Interior7_Text_BaldingMan_4, MSGBOX_NPC
	giveitem ITEM_TM01
	msgbox CianwoodCity_Interior7_Text_BaldingMan_5, MSGBOX_NPC
	end

CianwoodCity_Interior7_Movement_BaldingMan_1::
	face_right
	step_end

CianwoodCity_Interior7_Movement_BaldingMan_2::
	walk_fast_left
	jump_2_right
	set_invisible
	walk_up
	walk_up
	step_end

CianwoodCity_Interior7_EventScript_PushableBoulder4::
	msgbox CianwoodCity_Interior7_Text_PushableBoulder4, MSGBOX_AUTOCLOSE
	end

CianwoodCity_Interior7_EventScript_Trigger1::
	call_if_set 0x10CD, CianwoodCity_Interior7_EventScript_Trigger1_1
	call_if_set FLAG_BADGE03_GET, CianwoodCity_Interior7_EventScript_Trigger1_2
	release
	end

CianwoodCity_Interior7_EventScript_Trigger1_1::
	release
	end

CianwoodCity_Interior7_EventScript_Trigger1_2::
	setflag 0x10CD
	applymovement 8, CianwoodCity_Interior7_Movement_Trigger1_1
	delay 64
	msgbox CianwoodCity_Interior7_Text_Trigger1_1, MSGBOX_NPC
	msgbox CianwoodCity_Interior7_Text_Trigger1_2, MSGBOX_NPC
	applymovement 8, CianwoodCity_Interior7_Movement_Trigger1_2
	delay 96
	applymovement 8, CianwoodCity_Interior7_Movement_Trigger1_3
	delay 16
	msgbox CianwoodCity_Interior7_Text_Trigger1_3, MSGBOX_NPC
	applymovement 8, CianwoodCity_Interior7_Movement_Trigger1_4
	trywondercardscript
	.byte 0xDC @ invalid opcode (script stops)

CianwoodCity_Interior7_Movement_Trigger1_1::
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

CianwoodCity_Interior7_Movement_Trigger1_2::
	walk_down
	walk_down
	emote_exclamation_mark
	step_end

CianwoodCity_Interior7_Movement_Trigger1_3::
	face_up
	step_end

CianwoodCity_Interior7_Movement_Trigger1_4::
	walk_down
	walk_down
	walk_down
	set_invisible
	walk_down
	walk_down
	step_end

CianwoodCity_Interior7_EventScript_Trigger2::
	call_if_set 0x10CD, CianwoodCity_Interior7_EventScript_Trigger1_1
	call_if_set FLAG_BADGE03_GET, CianwoodCity_Interior7_EventScript_Trigger2_1
	release
	end

CianwoodCity_Interior7_EventScript_Trigger2_1::
	setflag 0x10CD
	applymovement 8, CianwoodCity_Interior7_Movement_Trigger2_1
	delay 48
	msgbox CianwoodCity_Interior7_Text_Trigger1_1, MSGBOX_NPC
	msgbox CianwoodCity_Interior7_Text_Trigger1_2, MSGBOX_NPC
	applymovement 8, CianwoodCity_Interior7_Movement_Trigger2_2
	delay 96
	applymovement 8, CianwoodCity_Interior7_Movement_Trigger1_3
	delay 16
	msgbox CianwoodCity_Interior7_Text_Trigger1_3, MSGBOX_NPC
	applymovement 8, CianwoodCity_Interior7_Movement_Trigger1_4
	delay 48
	end

CianwoodCity_Interior7_Movement_Trigger2_1::
	walk_left
	walk_left
	walk_up
	step_end

CianwoodCity_Interior7_Movement_Trigger2_2::
	walk_left
	walk_down
	walk_down
	emote_exclamation_mark
	step_end

CianwoodCity_Interior7_EventScript_Sign1::
	call_if_set FLAG_BADGE03_GET, CianwoodCity_Interior7_EventScript_Sign1_2
	msgbox CianwoodCity_Interior7_Text_Sign1_1, MSGBOX_NPC
	end

CianwoodCity_Interior7_EventScript_Sign1_2::
	msgbox CianwoodCity_Interior7_Text_Sign1_3, MSGBOX_NPC
	end
