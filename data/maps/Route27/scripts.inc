Route27_MapScripts::
	.byte 0

Route27_EventScript_FatMan::
	call_if_set 0x1153, Route27_EventScript_FatMan_1
	setflag 0x1153
	applymovement 1, Route27_Movement_FatMan
	delay 64
	msgbox Route27_Text_FatMan_1, MSGBOX_NPC
	end

Route27_EventScript_FatMan_1::
	msgbox Route27_Text_FatMan_2, MSGBOX_NPC
	end

Route27_Movement_FatMan::
	emote_exclamation_mark
	step_end

Route27_EventScript_CooltrainerMegan::
	trainerbattle_single TRAINER_COOLTRAINER_MEGAN, Route27_Text_CooltrainerMeganIntro, Route27_Text_CooltrainerMeganDefeat
	msgbox Route27_Text_CooltrainerMegan, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_CooltrainerBlake::
	trainerbattle_single TRAINER_COOLTRAINER_BLAKE, Route27_Text_CooltrainerBlakeIntro, Route27_Text_CooltrainerBlakeDefeat
	msgbox Route27_Text_CooltrainerBlake, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY
	end

Route27_EventScript_PsychicGilbert::
	trainerbattle_single TRAINER_PSYCHIC_GILBERT, Route27_Text_PsychicGilbertIntro, Route27_Text_PsychicGilbertDefeat
	msgbox Route27_Text_PsychicGilbert, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_BirdKeeper549::
	trainerbattle_single TRAINER_BIRD_KEEPER_JOSE_3, Route27_Text_BirdKeeper549Intro, Route27_Text_BirdKeeper549Defeat
	call_if_set 0x1326, Route27_EventScript_BirdKeeper549_1
	setvar 0x700C, 38
	setvar 0x700D, 0
	call_if_set 0x1356, Route35_EventScript_Juggler228_2
	msgbox Route27_Text_BirdKeeper549, MSGBOX_NPC
	setflag 0x1356
	call Route35_EventScript_Juggler228_3
	end

Route27_EventScript_BirdKeeper549_1::
	clearflag 0x1326
	msgbox Route35_Text_Juggler228_2, MSGBOX_NPC
	call_if_set 0x030, Route27_EventScript_BirdKeeper549_2
	call_if_set 0x1177, Route27_EventScript_BirdKeeper549_3
	call_if_set 0x115F, Route27_EventScript_BirdKeeper549_4
	trainerbattle_earlyrival TRAINER_BIRD_KEEPER_JOSE_3, 0, Route27_Text_BirdKeeper549Defeat, Route35_Text_Juggler228Victory
	release
	end

Route27_EventScript_BirdKeeper549_2::
	trainerbattle_earlyrival TRAINER_BIRD_KEEPER_JOSE_2, 0, Route27_Text_BirdKeeper549Defeat, Route35_Text_Juggler228Victory
	release
	end

Route27_EventScript_BirdKeeper549_3::
	trainerbattle_earlyrival TRAINER_BIRD_KEEPER_JOSE, 0, Route27_Text_BirdKeeper549Defeat, Route35_Text_Juggler228Victory
	release
	end

Route27_EventScript_BirdKeeper549_4::
	trainerbattle_earlyrival TRAINER_BIRD_KEEPER_JOSE_4, 0, Route27_Text_BirdKeeper549Defeat, Route35_Text_Juggler228Victory
	release
	end

Route27_EventScript_ItemTm22::
	finditem ITEM_TM22
	end

Route27_EventScript_CooltrainerBrian::
	trainerbattle_single TRAINER_COOLTRAINER_BRIAN, Route27_Text_CooltrainerBrianIntro, Route27_Text_CooltrainerBrianDefeat
	msgbox Route27_Text_CooltrainerBrian, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Cooltrainer222::
	trainerbattle_single TRAINER_COOLTRAINER_REENA_4, Route27_Text_Cooltrainer222Intro, Route27_Text_Cooltrainer222Defeat
	call_if_set 0x1328, Route27_EventScript_Cooltrainer222_1
	setvar 0x700C, 40
	setvar 0x700D, 0
	call_if_set 0x1358, Route35_EventScript_Juggler228_2
	msgbox Route27_Text_Cooltrainer222, MSGBOX_NPC
	setflag 0x1358
	call Route35_EventScript_Juggler228_3
	end

Route27_EventScript_Cooltrainer222_1::
	clearflag 0x1328
	msgbox Route35_Text_Juggler228_2, MSGBOX_NPC
	call_if_set 0x030, Route27_EventScript_Cooltrainer222_2
	call_if_set 0x1177, Route27_EventScript_Cooltrainer222_3
	call_if_set 0x115F, Route27_EventScript_Cooltrainer222_4
	call_if_set FLAG_BADGE07_GET, Route27_EventScript_Cooltrainer222_5
	trainerbattle_earlyrival TRAINER_COOLTRAINER_REENA_4, 0, Route27_Text_Cooltrainer222Defeat, Route35_Text_Juggler228Victory
	release
	end

Route27_EventScript_Cooltrainer222_2::
	trainerbattle_earlyrival TRAINER_COOLTRAINER_REENA_3, 0, Route27_Text_Cooltrainer222Defeat, Route35_Text_Juggler228Victory
	release
	end

Route27_EventScript_Cooltrainer222_3::
	trainerbattle_earlyrival TRAINER_COOLTRAINER_REENA_2, 0, Route27_Text_Cooltrainer222Defeat, Route35_Text_Juggler228Victory
	release
	end

Route27_EventScript_Cooltrainer222_4::
	trainerbattle_earlyrival TRAINER_COOLTRAINER_REENA, 0, Route27_Text_Cooltrainer222Defeat, Route35_Text_Juggler228Victory
	release
	end

Route27_EventScript_Cooltrainer222_5::
	trainerbattle_earlyrival TRAINER_COOLTRAINER_REENA_5, 0, Route27_Text_Cooltrainer222Defeat, Route35_Text_Juggler228Victory
	release
	end

Route27_EventScript_Trigger1::
	call_if_set 0x1153, Route27_EventScript_Trigger1_1
	setflag 0x1153
	applymovement 1, Route27_Movement_Trigger1
	delay 64
	msgbox Route27_Text_FatMan_1, MSGBOX_NPC
	end

Route27_EventScript_Trigger1_1::
	release
	end

Route27_Movement_Trigger1::
	face_up
	emote_exclamation_mark
	step_end

Route27_EventScript_Trigger4::
	call_if_set 0x1153, Route27_EventScript_Trigger4_1
	setflag 0x1153
	applymovement 1, Route27_Movement_Trigger4_1
	delay 48
	applymovement 1, Route27_Movement_Trigger4_2
	delay 16
	msgbox Route27_Text_FatMan_1, MSGBOX_NPC
	end

Route27_EventScript_Trigger4_1::
	release
	end

Route27_Movement_Trigger4_1::
	face_left
	emote_exclamation_mark
	step_end

Route27_Movement_Trigger4_2::
	walk_down
	face_left
	step_end

Route27_EventScript_Trigger5::
	call_if_set 0x1153, Route27_EventScript_Trigger4_1
	setflag 0x1153
	applymovement 1, Route27_Movement_Trigger4_1
	delay 48
	applymovement 1, Route27_Movement_Trigger5
	delay 32
	msgbox Route27_Text_FatMan_1, MSGBOX_NPC
	end

Route27_Movement_Trigger5::
	walk_down
	walk_down
	face_left
	step_end

Route27_EventScript_Sign::
	msgbox Route27_Text_Sign, MSGBOX_AUTOCLOSE
	end
