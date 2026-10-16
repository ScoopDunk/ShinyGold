Route26_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route26_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route26_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, Route26_OnReturnToField
	.byte 0

Route26_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_BIRTH_ISLAND_EXTERIOR
	setvar VAR_OBJ_GFX_ID_0, 150
	setvar VAR_DEOXYS_INTERACTION_STEP_COUNTER, 0
	setvar VAR_DEOXYS_INTERACTION_NUM, 0
	call_if_set 0x2E4, Route26_EventScript_OnTransition_1
	call_if_unset 0x2E4, Route26_EventScript_OnTransition_2
	end

Route26_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, Route26_EventScript_OnResume_1
	end

Route26_OnReturnToField::
	special SetDeoxysTrianglePalette
	end

Route26_EventScript_OnTransition_1::
	setflag 0x099
	setflag 0x09A
	return

Route26_EventScript_OnTransition_2::
	goto_if_set 0x2F7, EventScript_Return
	clearflag 0x09A
	clearflag FLAG_SYS_DEOXYS_AWAKENED
	return

Route26_EventScript_OnResume_1::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, 7, EventScript_Return
	removeobject 2
	return

Route26_EventScript_Fisher::
	faceplayer
	lock
	call_if_set 0x1156, Route26_EventScript_Fisher_1
	msgbox Route26_Text_Fisher_1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route26_EventScript_Fisher_2
	msgbox Route26_Text_Fisher_2, MSGBOX_NPC
	end

Route26_EventScript_Fisher_1::
	msgbox Route26_Text_Fisher_3, MSGBOX_NPC
	end

Route26_EventScript_Fisher_2::
	msgbox Route26_Text_Fisher_4, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_FISHERMAN_RYO, 0, Route26_Text_FisherDefeat, Route26_Text_FisherVictory
	setflag 0x1156
	msgbox Route26_Text_Fisher_5, MSGBOX_NPC
	giveitem ITEM_PP_MAX
	msgbox Route26_Text_Fisher_3, MSGBOX_NPC
	end

Route26_EventScript_FishermanScott::
	trainerbattle_single TRAINER_FISHERMAN_SCOTT, Route26_Text_FishermanScottIntro, Route26_Text_FishermanScottDefeat
	msgbox Route26_Text_FishermanScott, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_PsychicRichard::
	trainerbattle_single TRAINER_PSYCHIC_RICHARD, Route26_Text_PsychicRichardIntro, Route26_Text_PsychicRichardDefeat
	msgbox Route26_Text_PsychicRichard, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_CooltrainerJoyce::
	trainerbattle_single TRAINER_COOLTRAINER_JOYCE, Route26_Text_CooltrainerJoyceIntro, Route26_Text_CooltrainerJoyceDefeat
	msgbox Route26_Text_CooltrainerJoyce, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Cooltrainer302::
	trainerbattle_single TRAINER_COOLTRAINER_GAVEN_3, Route26_Text_Cooltrainer302Intro, Route26_Text_Cooltrainer302Defeat
	call_if_set 0x1327, Route26_EventScript_Cooltrainer302_1
	setvar 0x700C, 39
	setvar 0x700D, 0
	call_if_set 0x1357, Route35_EventScript_Juggler228_2
	msgbox Route26_Text_Cooltrainer302, MSGBOX_NPC
	setflag 0x1357
	call Route35_EventScript_Juggler228_3
	end

Route26_EventScript_Cooltrainer302_1::
	clearflag 0x1327
	msgbox Route35_Text_Juggler228_2, MSGBOX_NPC
	call_if_set 0x030, Route26_EventScript_Cooltrainer302_2
	call_if_set 0x1177, Route26_EventScript_Cooltrainer302_3
	call_if_set 0x115F, Route26_EventScript_Cooltrainer302_4
	call_if_set FLAG_BADGE07_GET, Route26_EventScript_Cooltrainer302_5
	trainerbattle_earlyrival TRAINER_COOLTRAINER_GAVEN_3, 0, Route26_Text_Cooltrainer302Defeat, Route35_Text_Juggler228Victory
	release
	end

Route26_EventScript_Cooltrainer302_2::
	trainerbattle_earlyrival TRAINER_COOLTRAINER_GAVEN_2, 0, Route26_Text_Cooltrainer302Defeat, Route35_Text_Juggler228Victory
	release
	end

Route26_EventScript_Cooltrainer302_3::
	trainerbattle_earlyrival TRAINER_COOLTRAINER_GAVEN, 0, Route26_Text_Cooltrainer302Defeat, Route35_Text_Juggler228Victory
	release
	end

Route26_EventScript_Cooltrainer302_4::
	trainerbattle_earlyrival TRAINER_COOLTRAINER_GAVEN_5, 0, Route26_Text_Cooltrainer302Defeat, Route35_Text_Juggler228Victory
	release
	end

Route26_EventScript_Cooltrainer302_5::
	trainerbattle_earlyrival TRAINER_COOLTRAINER_GAVEN_4, 0, Route26_Text_Cooltrainer302Defeat, Route35_Text_Juggler228Victory
	release
	end

Route26_EventScript_CooltrainerJake::
	trainerbattle_single TRAINER_COOLTRAINER_JAKE, Route26_Text_CooltrainerJakeIntro, Route26_Text_CooltrainerJakeDefeat
	msgbox Route26_Text_CooltrainerJake, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_ItemMaxElixir::
	finditem ITEM_MAX_ELIXIR
	end

Route26_EventScript_Cooltrainer518::
	trainerbattle_single TRAINER_COOLTRAINER_BETH, Route26_Text_Cooltrainer518Intro, Route26_Text_Cooltrainer518Defeat
	call_if_set 0x1325, Route26_EventScript_Cooltrainer518_1
	setvar 0x700C, 37
	setvar 0x700D, 0
	call_if_set 0x1355, Route35_EventScript_Juggler228_2
	msgbox Route26_Text_Cooltrainer518, MSGBOX_NPC
	setflag 0x1355
	call Route35_EventScript_Juggler228_3
	end

Route26_EventScript_Cooltrainer518_1::
	clearflag 0x1325
	msgbox Route35_Text_Juggler228_2, MSGBOX_NPC
	call_if_set 0x1177, Route26_EventScript_Cooltrainer518_2
	call_if_set 0x115F, Route26_EventScript_Cooltrainer518_3
	trainerbattle_earlyrival TRAINER_COOLTRAINER_BETH, 0, Route26_Text_Cooltrainer518Defeat, Route35_Text_Juggler228Victory
	release
	end

Route26_EventScript_Cooltrainer518_2::
	trainerbattle_earlyrival TRAINER_COOLTRAINER_BETH_3, 0, Route26_Text_Cooltrainer518Defeat, Route35_Text_Juggler228Victory
	release
	end

Route26_EventScript_Cooltrainer518_3::
	trainerbattle_earlyrival TRAINER_COOLTRAINER_BETH_2, 0, Route26_Text_Cooltrainer518Defeat, Route35_Text_Juggler228Victory
	release
	end

Route26_EventScript_Trigger1::
	call_if_set 0x1155, Route26_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, Route26_Movement_Trigger1_1
	delay 32
	call Route26_EventScript_Trigger1_2
	end

Route26_EventScript_Trigger1_1::
	release
	end

Route26_EventScript_Trigger1_2::
	msgbox Route26_Text_Trigger1_1, MSGBOX_NPC
	applymovement 9, Route26_Movement_Trigger1_2
	delay 1
	msgbox Route26_Text_Trigger1_2, MSGBOX_NPC
	applymovement LOCALID_PLAYER, Route26_Movement_Trigger1_3
	delay 48
	applymovement 9, Route26_Movement_Trigger1_4
	delay 1
	msgbox Route26_Text_Trigger1_3, MSGBOX_NPC
	applymovement LOCALID_PLAYER, Route26_Movement_Trigger1_5
	delay 48
	msgbox Route26_Text_Trigger1_4, MSGBOX_NPC
	applymovement 10, Route26_Movement_Trigger1_6
	delay 16
	applymovement LOCALID_PLAYER, Route26_Movement_Trigger1_7
	delay 1
	applymovement 10, Route26_Movement_Trigger1_8
	delay 16
	msgbox Route26_Text_Trigger1_5, MSGBOX_AUTOCLOSE
	applymovement LOCALID_PLAYER, Route26_Movement_Trigger1_9
	delay 1
	playbgm MUS_ENCOUNTER_BOY, 51
	msgbox Route26_Text_Trigger1_6, MSGBOX_NPC
	msgbox Route26_Text_Trigger1_7, MSGBOX_NPC
	delay 32
	msgbox Route26_Text_Trigger1_8, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_PKMN_THIEF_190, 0, Route26_Text_Trigger1Defeat, Route26_Text_Trigger1Victory
	setflag 0x1155
	playbgm MUS_ENCOUNTER_BOY, 51
	msgbox Route26_Text_Trigger1_9, MSGBOX_NPC
	msgbox Route26_Text_Trigger1_10, MSGBOX_NPC
	applymovement 9, Route26_Movement_Trigger1_10
	applymovement 10, Route26_Movement_Trigger1_11
	delay 64
	msgbox Route26_Text_Trigger1_11, MSGBOX_AUTOCLOSE
	delay 32
	msgbox Route26_Text_Trigger1_12, MSGBOX_NPC
	applymovement 9, Route26_Movement_Trigger1_12
	applymovement 10, Route26_Movement_Trigger1_12
	delay 96
	applymovement LOCALID_PLAYER, Route26_Movement_Trigger1_13
	delay 32
	msgbox Route26_Text_Trigger1_13, MSGBOX_AUTOCLOSE
	playbgm MUS_HALL_OF_FAME, 51
	release
	end

Route26_Movement_Trigger1_1::
	walk_up
	walk_right
	walk_up
	step_end

Route26_Movement_Trigger1_2::
	face_down_fast
	step_end

Route26_Movement_Trigger1_3::
	walk_up
	walk_up
	face_right
	step_end

Route26_Movement_Trigger1_4::
	face_right
	step_end

Route26_Movement_Trigger1_5::
	face_left
	emote_question_mark
	step_end

Route26_Movement_Trigger1_6::
	walk_fast_left
	walk_fast_left
	step_end

Route26_Movement_Trigger1_7::
	emote_double_exclamation_mark
	face_right
	step_end

Route26_Movement_Trigger1_8::
	walk_fast_right
	walk_fast_right
	face_left
	step_end

Route26_Movement_Trigger1_9::
	face_left
	step_end

Route26_Movement_Trigger1_10::
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	face_up
	step_end

Route26_Movement_Trigger1_11::
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_down
	face_up
	step_end

Route26_Movement_Trigger1_12::
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	set_invisible
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Route26_Movement_Trigger1_13::
	walk_down
	step_end

Route26_EventScript_Trigger2::
	call_if_set 0x1155, Route26_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, Route26_Movement_Trigger2
	delay 32
	call Route26_EventScript_Trigger1_2
	end

Route26_Movement_Trigger2::
	walk_up
	walk_up
	step_end

Route26_EventScript_Sign1::
	msgbox Route26_Text_Sign1, MSGBOX_AUTOCLOSE
	end
