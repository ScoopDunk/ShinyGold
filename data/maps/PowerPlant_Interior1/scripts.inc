PowerPlant_Interior1_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, PowerPlant_Interior1_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, PowerPlant_Interior1_OnTransition
	.byte 0

PowerPlant_Interior1_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, PowerPlant_Interior1_EventScript_OnResume_1
	end

PowerPlant_Interior1_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_POWER_PLANT
	call_if_unset 0x2BF, PowerPlant_Interior1_EventScript_OnTransition_1
	call_if_unset 0x2D0, PowerPlant_Interior1_EventScript_OnTransition_2
	call_if_unset 0x2D1, PowerPlant_Interior1_EventScript_OnTransition_3
	end

PowerPlant_Interior1_EventScript_OnResume_1::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, 7, EventScript_Return
	removeobject VAR_LAST_TALKED
	return

PowerPlant_Interior1_EventScript_OnTransition_1::
	clearflag 0x05D
	return

PowerPlant_Interior1_EventScript_OnTransition_2::
	clearflag 0x085
	return

PowerPlant_Interior1_EventScript_OnTransition_3::
	clearflag 0x086
	return

PowerPlant_Interior1_EventScript_Policeman::
	call_if_set 0x1185, PowerPlant_Interior1_EventScript_Policeman_1
	msgbox PowerPlant_Interior1_Text_Policeman_1, MSGBOX_NPC
	end

PowerPlant_Interior1_EventScript_Policeman_1::
	msgbox PowerPlant_Interior1_Text_Policeman_2, MSGBOX_NPC
	end

PowerPlant_Interior1_EventScript_Scientist::
	call_if_set 0x1185, PowerPlant_Interior1_EventScript_Scientist_1
	msgbox PowerPlant_Interior1_Text_Scientist_1, MSGBOX_NPC
	end

PowerPlant_Interior1_EventScript_Scientist_1::
	msgbox PowerPlant_Interior1_Text_Scientist_2, MSGBOX_NPC
	end

PowerPlant_Interior1_EventScript_Scientist2::
	call_if_set 0x1185, PowerPlant_Interior1_EventScript_Scientist2_1
	msgbox PowerPlant_Interior1_Text_Scientist2_1, MSGBOX_NPC
	end

PowerPlant_Interior1_EventScript_Scientist2_1::
	msgbox PowerPlant_Interior1_Text_Scientist2_2, MSGBOX_NPC
	end

PowerPlant_Interior1_EventScript_Scientist3::
	call_if_set 0x1185, PowerPlant_Interior1_EventScript_Scientist3_1
	msgbox PowerPlant_Interior1_Text_Scientist3_1, MSGBOX_NPC
	end

PowerPlant_Interior1_EventScript_Scientist3_1::
	msgbox PowerPlant_Interior1_Text_Scientist3_2, MSGBOX_NPC
	end

PowerPlant_Interior1_EventScript_Policeman2::
	call_if_set 0x1185, PowerPlant_Interior1_EventScript_Policeman2_1
	msgbox PowerPlant_Interior1_Text_Policeman2_1, MSGBOX_NPC
	end

PowerPlant_Interior1_EventScript_Policeman2_1::
	msgbox PowerPlant_Interior1_Text_Policeman2_2, MSGBOX_NPC
	end

PowerPlant_Interior1_EventScript_BaldingMan::
	call_if_set 0x1185, PowerPlant_Interior1_EventScript_BaldingMan_1
	checkitem ITEM_SECRET_KEY
	call_if_eq VAR_RESULT, 1, PowerPlant_Interior1_EventScript_BaldingMan_2
	call_if_set 0x11C1, PowerPlant_Interior1_EventScript_BaldingMan_3
	setflag 0x11C1
	msgbox PowerPlant_Interior1_Text_BaldingMan_1, MSGBOX_NPC
	end

PowerPlant_Interior1_EventScript_BaldingMan_1::
	msgbox PowerPlant_Interior1_Text_BaldingMan_2, MSGBOX_NPC
	end

PowerPlant_Interior1_EventScript_BaldingMan_2::
	removeitem ITEM_SECRET_KEY
	msgbox PowerPlant_Interior1_Text_BaldingMan_3, MSGBOX_NPC
	giveitem ITEM_TM07
	msgbox PowerPlant_Interior1_Text_BaldingMan_4, MSGBOX_NPC
	setflag 0x1185
	setflag 0x11B9
	release
	end

PowerPlant_Interior1_EventScript_BaldingMan_3::
	msgbox PowerPlant_Interior1_Text_BaldingMan_5, MSGBOX_NPC
	end

PowerPlant_Interior1_EventScript_Trigger1::
	call_if_set 0x11BE, PowerPlant_Interior1_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, PowerPlant_Interior1_Movement_Trigger1_1
	delay 64
	call PowerPlant_Interior1_EventScript_Trigger1_2
	end

PowerPlant_Interior1_EventScript_Trigger1_1::
	release
	end

PowerPlant_Interior1_EventScript_Trigger1_2::
	msgbox PowerPlant_Interior1_Text_Trigger1_1, MSGBOX_AUTOCLOSE
	applymovement 1, PowerPlant_Interior1_Movement_Trigger1_2
	delay 16
	applymovement 1, PowerPlant_Interior1_Movement_Trigger1_3
	delay 64
	msgbox PowerPlant_Interior1_Text_Trigger1_2, MSGBOX_NPC
	msgbox PowerPlant_Interior1_Text_Trigger1_3, MSGBOX_NPC
	msgbox PowerPlant_Interior1_Text_Trigger1_4, MSGBOX_NPC
	applymovement 1, PowerPlant_Interior1_Movement_Trigger1_4
	delay 96
	setflag 0x11BE
	clearflag 0x11C0
	clearflag 0x272
	setflag 0x11BF
	release
	end

PowerPlant_Interior1_Movement_Trigger1_1::
	walk_up
	walk_right
	walk_right
	walk_right
	face_up
	step_end

PowerPlant_Interior1_Movement_Trigger1_2::
	face_down_fast
	step_end

PowerPlant_Interior1_Movement_Trigger1_3::
	emote_exclamation_mark
	step_end

PowerPlant_Interior1_Movement_Trigger1_4::
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	set_invisible
	walk_fast_down
	walk_fast_down
	step_end

PowerPlant_Interior1_EventScript_Trigger2::
	call_if_set 0x11BE, PowerPlant_Interior1_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, PowerPlant_Interior1_Movement_Trigger2
	delay 64
	call PowerPlant_Interior1_EventScript_Trigger1_2
	end

PowerPlant_Interior1_Movement_Trigger2::
	walk_up
	walk_right
	walk_right
	face_up
	step_end

PowerPlant_Interior1_EventScript_Trigger3::
	call_if_set 0x11BE, PowerPlant_Interior1_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, PowerPlant_Interior1_Movement_Trigger3
	delay 48
	call PowerPlant_Interior1_EventScript_Trigger1_2
	end

PowerPlant_Interior1_Movement_Trigger3::
	walk_up
	walk_right
	face_up
	step_end
