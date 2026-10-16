Route15_MapScripts::
	.byte 0

Route15_EventScript_PsychicJun::
	trainerbattle_single TRAINER_PSYCHIC_JUN, Route15_Text_PsychicJunIntro, Route15_Text_PsychicJunDefeat
	msgbox Route15_Text_PsychicJun, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_SchoolboyKipp::
	trainerbattle_single TRAINER_SCHOOLBOY_KIPP, Route15_Text_SchoolboyKippIntro, Route15_Text_SchoolboyKippDefeat
	msgbox Route15_Text_SchoolboyKipp, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_SchoolboyTommy::
	trainerbattle_single TRAINER_SCHOOLBOY_TOMMY, Route15_Text_SchoolboyTommyIntro, Route15_Text_SchoolboyTommyDefeat
	msgbox Route15_Text_SchoolboyTommy, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_TeacherHillary::
	trainerbattle_single TRAINER_TEACHER_HILLARY, Route15_Text_TeacherHillaryIntro, Route15_Text_TeacherHillaryDefeat
	msgbox Route15_Text_TeacherHillary, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_TeacherColette::
	trainerbattle_single TRAINER_TEACHER_COLETTE, Route15_Text_TeacherColetteIntro, Route15_Text_TeacherColetteDefeat
	msgbox Route15_Text_TeacherColette, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_SchoolboyJohnny::
	trainerbattle_single TRAINER_SCHOOLBOY_JOHNNY, Route15_Text_SchoolboyJohnnyIntro, Route15_Text_SchoolboyJohnnyDefeat
	msgbox Route15_Text_SchoolboyJohnny, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_ItemPpUp::
	finditem ITEM_PP_UP
	end

Route15_EventScript_SchoolboyBilly::
	trainerbattle_single TRAINER_SCHOOLBOY_BILLY, Route15_Text_SchoolboyBillyIntro, Route15_Text_SchoolboyBillyDefeat
	msgbox Route15_Text_SchoolboyBilly, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Trigger1::
	call_if_set 0x11F5, Route15_EventScript_Trigger1_1
	call_if_unset 0x11F3, Route15_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, Route15_Movement_Trigger1_1
	delay 16
	call Route15_EventScript_Trigger4
	end

Route15_EventScript_Trigger1_1::
	release
	end

Route15_EventScript_Trigger4::
	call_if_set 0x11F5, Route15_EventScript_Trigger1_1
	call_if_unset 0x11F3, Route15_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, Route15_Movement_Trigger1_2
	applymovement 11, Route15_Movement_Trigger1_3
	delay 128
	delay 128
	delay 48
	call Route15_EventScript_Trigger1_2
	end

Route15_Movement_Trigger1_1::
	walk_fast_right
	walk_fast_right
	step_end

Route15_EventScript_Trigger1_2::
	msgbox Route15_Text_Trigger1_1, MSGBOX_NPC
	delay 16
	msgbox Route15_Text_Trigger1_2, MSGBOX_NPC
	applymovement 10, Route15_Movement_Trigger1_4
	applymovement 1, Route15_Movement_Trigger1_4
	delay 32
	msgbox Route15_Text_Trigger1_3, MSGBOX_NPC
	msgbox Route15_Text_Trigger1_4, MSGBOX_NPC
	msgbox Route15_Text_Trigger1_5, MSGBOX_NPC
	applymovement 10, Route15_Movement_Trigger1_5
	applymovement 1, Route15_Movement_Trigger1_5
	delay 16
	msgbox Route15_Text_Trigger1_6, MSGBOX_NPC
	msgbox Route15_Text_Trigger1_7, MSGBOX_NPC
	fadescreen FADE_TO_BLACK
	playbgm MUS_VS_GYM_LEADER, 51
	delay 48
	playse SE_M_FLAMETHROWER @ ShinyGold fix: was playbgm (the sound effect replaced the map music until the next map)
	msgbox Route15_Text_Trigger1_8, MSGBOX_NPC
	msgbox Route15_Text_Trigger1_9, MSGBOX_NPC
	msgbox Route15_Text_Trigger1_10, MSGBOX_NPC
	removeobject 1
	removeobject 10
	fadescreen FADE_FROM_BLACK
	delay 48
	playbgm MUS_ROUTE11, 51
	applymovement LOCALID_PLAYER, Route15_Movement_Trigger1_6
	applymovement 11, Route15_Movement_Trigger1_7
	delay 1
	msgbox Route15_Text_Trigger1_11, MSGBOX_NPC
	playfanfare SE_USE_ITEM
	msgbox Route15_Text_Trigger1_12
	waitfanfare
	msgbox Route15_Text_Trigger1_13, MSGBOX_NPC
	applymovement 11, Route15_Movement_Trigger1_8
	delay 224
	setflag 0x11F4
	setflag 0x11F5
	setflag FLAG_SYS_POKEMON_GET
	clearflag 0x856
	clearflag 0x11F2
	release
	end

Route15_Movement_Trigger1_2::
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	step_end

Route15_Movement_Trigger1_3::
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	step_end

Route15_Movement_Trigger1_4::
	face_down_fast
	emote_exclamation_mark
	step_end

Route15_Movement_Trigger1_5::
	emote_double_exclamation_mark
	step_end

Route15_Movement_Trigger1_6::
	face_right
	step_end

Route15_Movement_Trigger1_7::
	face_left
	step_end

Route15_Movement_Trigger1_8::
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	set_invisible
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route15_EventScript_Trigger2::
	call_if_set 0x11F5, Route15_EventScript_Trigger1_1
	call_if_unset 0x11F3, Route15_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, Route15_Movement_Trigger2
	delay 16
	call Route15_EventScript_Trigger4
	end

Route15_Movement_Trigger2::
	walk_fast_up
	walk_fast_right
	step_end

Route15_EventScript_Sign::
	msgbox Route15_Text_Sign, MSGBOX_AUTOCLOSE
	end
