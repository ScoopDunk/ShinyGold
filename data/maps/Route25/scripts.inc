Route25_MapScripts::
	.byte 0

Route25_EventScript_SchoolboyDudley::
	trainerbattle_single TRAINER_SCHOOLBOY_DUDLEY, Route25_Text_SchoolboyDudleyIntro, Route25_Text_SchoolboyDudleyDefeat
	msgbox Route25_Text_SchoolboyDudley, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_CooltrainerM::
	msgbox Route25_Text_CooltrainerM_1, MSGBOX_AUTOCLOSE
	msgbox Route25_Text_CooltrainerM_2, MSGBOX_AUTOCLOSE
	applymovement 14, Route25_Movement_CooltrainerM_1
	delay 1
	msgbox Route25_Text_CooltrainerM_3, MSGBOX_AUTOCLOSE
	applymovement 2, Route25_Movement_CooltrainerM_2
	delay 16
	msgbox Route25_Text_CooltrainerM_4, MSGBOX_AUTOCLOSE
	msgbox Route25_Text_CooltrainerM_5, MSGBOX_AUTOCLOSE
	applymovement 2, Route25_Movement_CooltrainerM_1
	delay 1
	msgbox Route25_Text_CooltrainerM_6, MSGBOX_NPC
	msgbox Route25_Text_CooltrainerM_7, MSGBOX_NPC
	msgbox Route25_Text_CooltrainerM_8, MSGBOX_NPC
	msgbox Route25_Text_CooltrainerM_9, MSGBOX_NPC
	msgbox Route25_Text_CooltrainerM_10, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_COOL_COUPLE_DANTE_AND_RINA_2, 0, Route25_Text_CooltrainerMDefeat, Route25_Text_CooltrainerMVictory
	setflag 0x11BD
	msgbox Route25_Text_CooltrainerM_11, MSGBOX_NPC
	applymovement 14, Route25_Movement_CooltrainerM_3
	delay 16
	msgbox Route25_Text_CooltrainerM_12, MSGBOX_AUTOCLOSE
	msgbox Route25_Text_CooltrainerM_13, MSGBOX_AUTOCLOSE
	call_if_eq VAR_FACING, 4, Route25_EventScript_CooltrainerM_1
	applymovement 2, Route25_Movement_CooltrainerM_4
	delay 64
	msgbox Route25_Text_CooltrainerM_14, MSGBOX_AUTOCLOSE
	applymovement 14, Route25_Movement_CooltrainerM_4
	delay 112
	applymovement 2, Route25_Movement_CooltrainerM_5
	delay 1
	applymovement 14, Route25_Movement_CooltrainerM_5
	delay 128
	end

Route25_EventScript_CooltrainerM_1::
	applymovement 2, Route25_Movement_CooltrainerM_6
	delay 64
	msgbox Route25_Text_CooltrainerM_14, MSGBOX_AUTOCLOSE
	applymovement 14, Route25_Movement_CooltrainerM_6
	delay 128
	applymovement 2, Route25_Movement_CooltrainerM_7
	delay 1
	applymovement 14, Route25_Movement_CooltrainerM_7
	delay 128
	end

Route25_Movement_CooltrainerM_1::
	face_player
	step_end

Route25_Movement_CooltrainerM_2::
	face_right
	step_end

Route25_Movement_CooltrainerM_3::
	face_left
	step_end

Route25_Movement_CooltrainerM_4::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route25_Movement_CooltrainerM_5::
	walk_left
	walk_left
	walk_left
	set_invisible
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route25_Movement_CooltrainerM_6::
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route25_Movement_CooltrainerM_7::
	walk_left
	walk_left
	walk_left
	set_invisible
	walk_fast_up
	walk_fast_up
	step_end

Route25_EventScript_LassEllen::
	trainerbattle_single TRAINER_LASS_ELLEN, Route25_Text_LassEllenIntro, Route25_Text_LassEllenDefeat
	msgbox Route25_Text_SchoolboyDudley, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_SuperNerdPat::
	trainerbattle_single TRAINER_SUPER_NERD_PAT, Route25_Text_SuperNerdPatIntro, Route25_Text_SuperNerdPatDefeat
	msgbox Route25_Text_SuperNerdPat, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_SchoolboyJoe::
	trainerbattle_single TRAINER_SCHOOLBOY_JOE, Route25_Text_SchoolboyJoeIntro, Route25_Text_SchoolboyJoeDefeat
	msgbox Route25_Text_SchoolboyDudley, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_LassLaura::
	trainerbattle_single TRAINER_LASS_LAURA, Route25_Text_LassLauraIntro, Route25_Text_LassLauraDefeat
	msgbox Route25_Text_SchoolboyDudley, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_CamperLloyd::
	trainerbattle_single TRAINER_CAMPER_LLOYD, Route25_Text_CamperLloydIntro, Route25_Text_CamperLloydDefeat
	msgbox Route25_Text_SchoolboyDudley, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_LassShannon::
	trainerbattle_single TRAINER_LASS_SHANNON, Route25_Text_LassShannonIntro, Route25_Text_LassShannonDefeat
	msgbox Route25_Text_SchoolboyDudley, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_CooltrainerM2::
	call_if_set 0x11BA, Route25_EventScript_CooltrainerM2_1
	setflag 0x11BA
	msgbox Route25_Text_CooltrainerM2_1, MSGBOX_NPC
	giveitem ITEM_NUGGET
	msgbox Route25_Text_CooltrainerM2_2, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_COOLTRAINER_KEVIN, 0, Route25_Text_CooltrainerM2Defeat, Route25_Text_CooltrainerM2Victory
	msgbox Route25_Text_CooltrainerM2_3, MSGBOX_NPC
	end

Route25_EventScript_CooltrainerM2_1::
	msgbox Route25_Text_CooltrainerM2_3, MSGBOX_NPC
	end

Route25_EventScript_ItemProtein::
	finditem ITEM_PROTEIN
	end

Route25_EventScript_Man::
	msgbox Route25_Text_Man, MSGBOX_NPC
	end

Route25_EventScript_ItemPotion::
	finditem ITEM_POTION
	end

Route25_EventScript_Trigger1::
	call_if_set 0x11BB, Route25_EventScript_Trigger1_1
	setflag 0x11BC
	release
	end

Route25_EventScript_Trigger1_1::
	release
	end

Route25_EventScript_Trigger2::
	call_if_set 0x11C3, Route25_EventScript_Trigger2_1
	call_if_set 0x11BC, Route25_EventScript_Trigger2_1
	applymovement 12, Route25_Movement_Trigger2_1
	delay 96
	applymovement 13, Route25_Movement_Trigger2_2
	delay 64
	applymovement 12, Route25_Movement_Trigger2_3
	delay 1
	applymovement 13, Route25_Movement_Trigger2_4
	delay 160
	playbgm MUS_ENCOUNTER_GIRL, 51
	applymovement 12, Route25_Movement_Trigger2_5
	delay 112
	msgbox Route25_Text_Trigger2, MSGBOX_NPC
	applymovement 12, Route25_Movement_Trigger2_6
	delay 224
	playbgm MUS_ROUTE24, 51
	setflag 0x11BC
	setflag 0x11C3
	clearflag 0x11C2
	release
	end

Route25_EventScript_Trigger2_1::
	release
	end

Route25_Movement_Trigger2_1::
	emote_smile
	step_end

Route25_Movement_Trigger2_2::
	emote_exclamation_mark
	step_end

Route25_Movement_Trigger2_3::
	face_down_fast
	step_end

Route25_Movement_Trigger2_4::
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	set_invisible
	walk_fast_down
	walk_fast_down
	step_end

Route25_Movement_Trigger2_5::
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route25_Movement_Trigger2_6::
	walk_up
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
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route25_EventScript_Trigger3::
	call_if_set 0x11C3, Route25_EventScript_Trigger2_1
	call_if_set 0x11BC, Route25_EventScript_Trigger2_1
	applymovement 12, Route25_Movement_Trigger2_1
	delay 96
	applymovement 13, Route25_Movement_Trigger2_2
	delay 64
	applymovement 12, Route25_Movement_Trigger2_3
	delay 1
	applymovement 13, Route25_Movement_Trigger2_4
	delay 160
	playbgm MUS_ENCOUNTER_GIRL, 51
	applymovement 12, Route25_Movement_Trigger3_1
	delay 112
	msgbox Route25_Text_Trigger2, MSGBOX_NPC
	applymovement 12, Route25_Movement_Trigger3_2
	delay 224
	playbgm MUS_ROUTE24, 51
	setflag 0x11BC
	setflag 0x11C3
	clearflag 0x11C2
	release
	end

Route25_Movement_Trigger3_1::
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route25_Movement_Trigger3_2::
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
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route25_EventScript_Sign::
	msgbox Route25_Text_Sign, MSGBOX_AUTOCLOSE
	end
