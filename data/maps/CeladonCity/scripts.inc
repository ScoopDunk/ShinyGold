CeladonCity_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonCity_OnFrame
	.byte 0

CeladonCity_OnFrame::
	map_script_2 0x7047, 0, CeladonCity_EventScript_FrameScene
	.2byte 0

CeladonCity_EventScript_FrameScene::
	setflag 0x1366
	setvar 0x7047, 1
	call NewBarkTown_EventScript_FrameScene_1
	end

CeladonCity_EventScript_FatMan::
	msgbox CeladonCity_Text_FatMan, MSGBOX_NPC
	end

CeladonCity_EventScript_Poliwrath::
	msgbox CeladonCity_Text_Poliwrath, MSGBOX_NPC
	waitse
	playmoncry SPECIES_POLIWRATH, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)

CeladonCity_EventScript_Woman2::
	msgbox CeladonCity_Text_Woman2, MSGBOX_NPC
	end

CeladonCity_EventScript_Lass::
	msgbox CeladonCity_Text_Lass, MSGBOX_NPC
	end

CeladonCity_EventScript_Beauty::
	msgbox CeladonCity_Text_Beauty, MSGBOX_NPC
	end

CeladonCity_EventScript_OldMan2::
	msgbox CeladonCity_Text_OldMan2, MSGBOX_NPC
	end

CeladonCity_EventScript_Man::
	msgbox CeladonCity_Text_Man, MSGBOX_NPC
	end

CeladonCity_EventScript_OldMan1::
	msgbox CeladonCity_Text_OldMan1, MSGBOX_NPC
	end

CeladonCity_EventScript_ItemPpUp::
	finditem ITEM_PP_UP
	end

CeladonCity_EventScript_Youngster::
	msgbox CeladonCity_Text_Youngster, MSGBOX_NPC
	end

CeladonCity_EventScript_Trigger1::
	call_if_set 0x11E4, CeladonCity_EventScript_Trigger1_1
	setflag 0x11E3
	release
	end

CeladonCity_EventScript_Trigger1_1::
	release
	end

CeladonCity_EventScript_Trigger5::
	call_if_set 0x11E4, CeladonCity_EventScript_Trigger5_1
	clearflag 0x11E3
	applymovement LOCALID_PLAYER, CeladonCity_Movement_Trigger5_1
	delay 64
	applymovement LOCALID_PLAYER, CeladonCity_Movement_Trigger5_2
	delay 1
	applymovement 1, CeladonCity_Movement_Trigger5_3
	delay 48
	msgbox CeladonCity_Text_Trigger5_1, MSGBOX_NPC
	delay 16
	msgbox CeladonCity_Text_Trigger5_2, MSGBOX_NPC
	setflag 0x11E3
	trainerbattle_earlyrival TRAINER_PKMN_TRAINER_ARD, 0, CeladonCity_Text_Trigger5Defeat, CeladonCity_Text_Trigger5Victory
	msgbox CeladonCity_Text_Trigger5_3, MSGBOX_NPC
	setflag 0x11E4
	applymovement 1, CeladonCity_Movement_Trigger5_4
	delay 208
	end

CeladonCity_EventScript_Trigger5_1::
	release
	end

CeladonCity_Movement_Trigger5_1::
	emote_exclamation_mark
	step_end

CeladonCity_Movement_Trigger5_2::
	walk_fast_down
	face_up
	step_end

CeladonCity_Movement_Trigger5_3::
	walk_down
	step_end

CeladonCity_Movement_Trigger5_4::
	walk_right
	walk_down
	jump_2_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	set_invisible
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

CeladonCity_EventScript_Sign1::
	msgbox CeladonCity_Text_Sign1, MSGBOX_AUTOCLOSE
	end

CeladonCity_EventScript_Sign2::
	msgbox CeladonCity_Text_Sign2, MSGBOX_AUTOCLOSE
	end

CeladonCity_EventScript_Sign3::
	msgbox CeladonCity_Text_Sign3, MSGBOX_AUTOCLOSE
	end

CeladonCity_EventScript_Sign4::
	msgbox CeladonCity_Text_Sign4, MSGBOX_AUTOCLOSE
	end

CeladonCity_EventScript_Sign5::
	msgbox CeladonCity_Text_Sign5, MSGBOX_AUTOCLOSE
	end
