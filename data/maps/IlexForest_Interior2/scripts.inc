IlexForest_Interior2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IlexForest_Interior2_OnTransition
	.byte 0

@ Pure Gold: this is the ROUTE 34 gate to ILEX FOREST. While the forest is restless (GS Ball event, from KURT's
@ discovery to the shrine) the teacher (object 2) stands at the exit to the forest instead (object 4, local id 5, as
@ object 1 has local id 4), and once KURT gave the GS BALL back the lass (object 1) is in the forest
@ (pokecrystal Route34IlexForestGate, EVENT_ROUTE_34_ILEX_FOREST_GATE_LASS).
IlexForest_Interior2_OnTransition::
	clearflag FLAG_GOLD_HIDE_ILEX_GATE_LASS
	clearflag FLAG_GOLD_HIDE_ILEX_GATE_TEACHER
	setflag FLAG_GOLD_HIDE_ILEX_GATE_TEACHER_DOOR
	goto_if_eq VAR_GOLD_GS_BALL, GS_BALL_KURT_OUTSIDE, IlexForest_Interior2_EventScript_ForestIsRestless
	goto_if_eq VAR_GOLD_GS_BALL, GS_BALL_RETURNED, IlexForest_Interior2_EventScript_LassInForest
	end

IlexForest_Interior2_EventScript_LassInForest::
	setflag FLAG_GOLD_HIDE_ILEX_GATE_LASS
IlexForest_Interior2_EventScript_ForestIsRestless::
	setflag FLAG_GOLD_HIDE_ILEX_GATE_TEACHER
	clearflag FLAG_GOLD_HIDE_ILEX_GATE_TEACHER_DOOR
	end

IlexForest_Interior2_EventScript_TeacherAtExit::
	msgbox IlexForest_Interior2_Text_ForestIsRestless, MSGBOX_NPC
	end

@ pokecrystal Route34IlexForestGateCelebiEvent
IlexForest_Interior2_EventScript_TeacherBlocksExit::
	lockall
	playse SE_PIN
	applymovement 5, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 5, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox IlexForest_Interior2_Text_ForestIsRestless
	closemessage
	applymovement LOCALID_PLAYER, IlexForest_Interior2_Movement_PlayerStepsBack
	waitmovement 0
	applymovement 5, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	releaseall
	end

IlexForest_Interior2_Movement_PlayerStepsBack::
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

IlexForest_Interior2_EventScript_Woman2::
	msgbox IlexForest_Interior2_Text_Woman2, MSGBOX_NPC
	end

IlexForest_Interior2_EventScript_Picnicker::
	call_if_set 0x1077, IlexForest_Interior2_EventScript_Picnicker_1
	msgbox IlexForest_Interior2_Text_Picnicker_1, MSGBOX_NPC
	giveitem ITEM_TM12
	msgbox IlexForest_Interior2_Text_Picnicker_2, MSGBOX_NPC
	setflag 0x1077
	end

IlexForest_Interior2_EventScript_Picnicker_1::
	msgbox IlexForest_Interior2_Text_Picnicker_2, MSGBOX_NPC
	end

IlexForest_Interior2_EventScript_Clefairy::
	msgbox IlexForest_Interior2_Text_Clefairy, MSGBOX_NPC
	waitse
	playmoncry SPECIES_CLEFAIRY, 0x201
	.byte 0xFF @ invalid opcode (script stops)
