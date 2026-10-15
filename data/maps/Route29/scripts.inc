Route29_MapScripts::
	@ ShinyGold: overlapping data duplicated from 0x0816876B
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route29_OnFrame
	.byte 0

Route29_OnFrame::
	map_script_2 0x7010, 0, Route29_EventScript_FrameScene
	.2byte 0

Route29_EventScript_FrameScene::
	setvar 0x7010, 1
	call Route29_EventScript_FrameScene_1
	call Route35_EventScript_FrameScene_2
	end

Route29_EventScript_FrameScene_1::
	setvar 0x7011, 0
	setvar 0x7012, 0
	setvar 0x7013, 0
	setvar 0x7014, 0
	setvar 0x7015, 0
	setvar 0x7016, 0
	setvar 0x7017, 0
	setvar 0x7018, 0
	setvar 0x7019, 0
	setvar 0x701A, 0
	setvar 0x701B, 0
	setvar 0x701C, 0
	setvar 0x701D, 0
	setvar 0x701E, 0
	setvar 0x701F, 0
	setvar 0x7020, 0
	setvar 0x7021, 0
	setvar 0x7022, 0
	setvar 0x7023, 0
	setvar 0x7024, 0
	setvar 0x7025, 0
	setvar 0x7026, 0
	setvar 0x7027, 0
	setvar 0x7028, 0
	return

Route29_EventScript_Trigger1::
	goto_if_set 0x1007, Unused_G2_M68_EventScript_Trigger1_1
	textcolor NPC_TEXT_COLOR_MALE
	msgbox Unused_G2_M68_Text_Trigger1_1, MSGBOX_NPC
	applymovement 2, Route29_Movement_Trigger1_1
	delay 144
	call Route44_EventScript_PkmnTrainerCarlos3_1
	trainerbattle_earlyrival TRAINER_PKMN_TRAINER_194, 0, Unused_G2_M68_Text_Trigger1Defeat, Unused_G2_M68_Text_Trigger1Defeat
	setflag 0x1007
	delay 32
	call Route44_EventScript_PkmnTrainerCarlos3_2
	msgbox Unused_G2_M68_Text_Trigger1_2, MSGBOX_NPC
	applymovement LOCALID_PLAYER, Route29_Movement_Trigger1_2
	applymovement 2, Unused_G2_M68_Movement_Trigger1_3
	delay 224
	release
	end

Route29_Movement_Trigger1_1::
	walk_fast_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route29_Movement_Trigger1_2::
	walk_down
	face_up
	step_end

Route29_EventScript_Trigger2::
	goto_if_set 0x1007, Unused_G2_M68_EventScript_Trigger1_1
	textcolor NPC_TEXT_COLOR_MALE
	msgbox Unused_G2_M68_Text_Trigger1_1, MSGBOX_NPC
	applymovement 2, Unused_G2_M68_Movement_Trigger1_1
	delay 144
	call Route44_EventScript_PkmnTrainerCarlos3_1
	trainerbattle_earlyrival TRAINER_PKMN_TRAINER_194, 0, Unused_G2_M68_Text_Trigger1Defeat, Unused_G2_M68_Text_Trigger1Defeat
	setflag 0x1007
	delay 32
	call Route44_EventScript_PkmnTrainerCarlos3_2
	msgbox Unused_G2_M68_Text_Trigger1_2, MSGBOX_NPC
	applymovement LOCALID_PLAYER, Unused_G2_M68_Movement_Trigger1_2
	applymovement 2, Unused_G2_M68_Movement_Trigger1_3
	delay 224
	release
	end

@ ShinyGold: moved from data/maps/Unused_G2_M68/scripts.inc (map removed)
Unused_G2_M68_EventScript_Woman2::
	msgbox Unused_G2_M68_Text_Woman2, MSGBOX_NPC
	end

@ ShinyGold: moved from data/maps/Unused_G2_M68/scripts.inc (map removed)
Unused_G2_M68_EventScript_Lance::
	showcoinsbox 188, 136
	gotostd STD_OBTAIN_ITEM

@ ShinyGold: moved from data/maps/Unused_G2_M68/scripts.inc (map removed)
Unused_G2_M68_EventScript_Man::
	msgbox Unused_G2_M68_Text_Man, MSGBOX_NPC
	end

@ ShinyGold: moved from data/maps/Unused_G2_M68/scripts.inc (map removed)
Unused_G2_M68_EventScript_FatMan::
	msgbox Unused_G2_M68_Text_FatMan, MSGBOX_NPC
	end

@ ShinyGold: moved from data/maps/Unused_G2_M68/scripts.inc (map removed)
Unused_G2_M68_EventScript_Boy::
	msgbox Unused_G2_M68_Text_Boy, MSGBOX_NPC
	end

@ ShinyGold: moved from data/maps/Unused_G2_M68/scripts.inc (map removed)
Unused_G2_M68_EventScript_WorkerM::
	msgbox Unused_G2_M68_Text_WorkerM, MSGBOX_NPC
	end

@ ShinyGold: moved from data/maps/Unused_G2_M68/scripts.inc (map removed)
Unused_G2_M68_EventScript_ItemPotion::
	finditem ITEM_POTION
	end

@ ShinyGold: moved from data/maps/Unused_G2_M68/scripts.inc (map removed)
Unused_G2_M68_EventScript_Trigger1_1::
	release
	end

@ ShinyGold: moved from data/maps/Unused_G2_M68/scripts.inc (map removed)
Unused_G2_M68_Movement_Trigger1_1::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ ShinyGold: moved from data/maps/Unused_G2_M68/scripts.inc (map removed)
Unused_G2_M68_Movement_Trigger1_2::
	walk_up
	face_down_fast
	step_end

@ ShinyGold: moved from data/maps/Unused_G2_M68/scripts.inc (map removed)
Unused_G2_M68_Movement_Trigger1_3::
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
	walk_fast_down
	walk_fast_down
	step_end

@ ShinyGold: moved from data/maps/Unused_G2_M68/scripts.inc (map removed)
Unused_G2_M68_EventScript_Trigger3::
	call_if_set 0x1019, Unused_G2_M68_EventScript_Trigger3_1
	setflag 0x1018
	release
	end

@ ShinyGold: moved from data/maps/Unused_G2_M68/scripts.inc (map removed)
Unused_G2_M68_EventScript_Trigger3_1::
	release
	end

@ ShinyGold: moved from data/maps/Unused_G2_M68/scripts.inc (map removed)
Unused_G2_M68_EventScript_Trigger5::
	call_if_set 0x1025, Unused_G2_M68_EventScript_Trigger5_1
	release
	end

@ ShinyGold: moved from data/maps/Unused_G2_M68/scripts.inc (map removed)
Unused_G2_M68_EventScript_Trigger5_1::
	call_if_set 0x1028, Unused_G2_M68_EventScript_Trigger5_2
	applymovement 6, Unused_G2_M68_Movement_Trigger5_1
	delay 80
	msgbox Unused_G2_M68_Text_Trigger5_1, MSGBOX_NPC
	msgbox Unused_G2_M68_Text_Trigger5_2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Unused_G2_M68_EventScript_Trigger5_3
	msgbox Unused_G2_M68_Text_Trigger5_3, MSGBOX_NPC
	applymovement 6, Unused_G2_M68_Movement_Trigger5_2
	delay 80
	setflag 0x1028
	.byte 0xFF @ invalid opcode (script stops)

Unused_G2_M68_EventScript_Trigger5_2::
	release
	end

@ ShinyGold: moved from data/maps/Unused_G2_M68/scripts.inc (map removed)
Unused_G2_M68_EventScript_Trigger5_3::
	applymovement 6, Unused_G2_M68_Movement_Trigger5_2
	applymovement LOCALID_PLAYER, Unused_G2_M68_Movement_Trigger5_3
	delay 80
	special StartOldManTutorialBattle
	delay 80
	msgbox Unused_G2_M68_Text_Trigger5_4, MSGBOX_NPC
	setflag 0x1028
	.byte 0xFF @ invalid opcode (script stops)

Unused_G2_M68_Movement_Trigger5_1::
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

@ ShinyGold: moved from data/maps/Unused_G2_M68/scripts.inc (map removed)
Unused_G2_M68_Movement_Trigger5_2::
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

@ ShinyGold: moved from data/maps/Unused_G2_M68/scripts.inc (map removed)
Unused_G2_M68_Movement_Trigger5_3::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

@ ShinyGold: moved from data/maps/Unused_G2_M68/scripts.inc (map removed)
Unused_G2_M68_EventScript_Trigger7::
	call_if_set 0x1025, Unused_G2_M68_EventScript_Trigger7_1
	release
	end

@ ShinyGold: moved from data/maps/Unused_G2_M68/scripts.inc (map removed)
Unused_G2_M68_EventScript_Trigger7_1::
	call_if_set 0x1028, Unused_G2_M68_EventScript_Trigger5_2
	applymovement 6, Unused_G2_M68_Movement_Trigger7_1
	delay 80
	msgbox Unused_G2_M68_Text_Trigger5_1, MSGBOX_NPC
	msgbox Unused_G2_M68_Text_Trigger5_2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Unused_G2_M68_EventScript_Trigger7_2
	msgbox Unused_G2_M68_Text_Trigger5_3, MSGBOX_NPC
	applymovement 6, Unused_G2_M68_Movement_Trigger7_2
	delay 80
	setflag 0x1028
	.byte 0xFF @ invalid opcode (script stops)

Unused_G2_M68_EventScript_Trigger7_2::
	applymovement 6, Unused_G2_M68_Movement_Trigger7_2
	applymovement LOCALID_PLAYER, Unused_G2_M68_Movement_Trigger7_3
	delay 80
	special StartOldManTutorialBattle
	delay 80
	msgbox Unused_G2_M68_Text_Trigger5_4, MSGBOX_NPC
	setflag 0x1028
	.byte 0xFF @ invalid opcode (script stops)

Unused_G2_M68_Movement_Trigger7_1::
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

@ ShinyGold: moved from data/maps/Unused_G2_M68/scripts.inc (map removed)
Unused_G2_M68_Movement_Trigger7_2::
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

@ ShinyGold: moved from data/maps/Unused_G2_M68/scripts.inc (map removed)
Unused_G2_M68_Movement_Trigger7_3::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

@ ShinyGold: moved from data/maps/Unused_G2_M68/scripts.inc (map removed)
Unused_G2_M68_EventScript_Sign1::
	msgbox Unused_G2_M68_Text_Sign1, MSGBOX_NPC
	end
