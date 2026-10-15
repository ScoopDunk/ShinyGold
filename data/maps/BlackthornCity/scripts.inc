BlackthornCity_MapScripts::
	@ ShinyGold: overlapping data duplicated from 0x0888CE18
	@ ShinyGold: 7 entries with invalid type(s) 0xFF, 0xBD, 0xFF, 0xFF, 0x10, 0xFF, 0xFF dropped (inert: the engine skips them)
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BlackthornCity_OnFrame
	.byte 0

BlackthornCity_OnFrame::
	map_script_2 0x7028, 0, BlackthornCity_EventScript_FrameScene
	.2byte 0

BlackthornCity_EventScript_FrameScene::
	setflag 0x1372
	call NewBarkTown_EventScript_FrameScene_1
	setvar 0x7028, 1
	call BlackthornCity_EventScript_FrameScene_1
	call Route35_EventScript_FrameScene_2
	end

BlackthornCity_EventScript_FrameScene_1::
	setvar 0x7010, 0
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
	return

BlackthornCity_EventScript_Rocker::
	call_if_set 0x1123, BlackthornCity_EventScript_Rocker_1
	msgbox BlackthornCity_Text_Rocker_1, MSGBOX_NPC
	end

BlackthornCity_EventScript_Rocker_1::
	msgbox BlackthornCity_Text_Rocker_2, MSGBOX_NPC
	end

BlackthornCity_EventScript_Woman2::
	msgbox BlackthornCity_Text_Woman2, MSGBOX_NPC
	end

BlackthornCity_EventScript_Lass::
	msgbox BlackthornCity_Text_Lass, MSGBOX_NPC
	end

BlackthornCity_EventScript_OldMan1::
	msgbox BlackthornCity_Text_OldMan1, MSGBOX_NPC
	end

BlackthornCity_EventScript_Man::
	call_if_set 0x114A, BlackthornCity_EventScript_Man_1
	msgbox BlackthornCity_Text_Man_1, MSGBOX_NPC
	end

BlackthornCity_EventScript_Man_1::
	msgbox BlackthornCity_Text_Man_2, MSGBOX_NPC
	end

BlackthornCity_EventScript_Youngster::
	msgbox BlackthornCity_Text_Youngster, MSGBOX_NPC
	end

BlackthornCity_EventScript_ItemBall::
	setflag FLAG_SYS_CAN_LINK_WITH_RS
	release
	end

BlackthornCity_EventScript_Man2::
	msgbox BlackthornCity_Text_Man2, MSGBOX_NPC
	end

BlackthornCity_EventScript_RedNormal::
	@ ShinyGold: overlapping data duplicated from 0x08873370
	.byte 0xD9 @ invalid opcode (script stops)

BlackthornCity_EventScript_Trigger1::
	call_if_set 0x114A, BlackthornCity_EventScript_Trigger1_1
	setflag 0x1141
	setflag 0x1142
	setflag 0x1143
	setflag 0x1144
	setflag 0x1145
	setflag 0x1146
	clearflag 0x044
	clearflag 0x045
	clearflag 0x046
	clearflag 0x047
	clearflag 0x1147
	clearflag 0x1148
	release
	end

BlackthornCity_EventScript_Trigger1_1::
	release
	end

BlackthornCity_EventScript_Trigger3::
	call_if_set 0x1151, BlackthornCity_EventScript_Trigger3_1
	call_if_set 0x114F, BlackthornCity_EventScript_Trigger3_1
	call_if_set FLAG_BADGE07_GET, BlackthornCity_EventScript_Trigger3_2
	release
	end

BlackthornCity_EventScript_Trigger3_1::
	release
	end

BlackthornCity_EventScript_Trigger3_2::
	call Route30_EventScript_Trigger3_2
	msgbox BlackthornCity_Text_Trigger3, MSGBOX_NPC
	setflag 0x114F
	release
	end

BlackthornCity_EventScript_Trigger4::
	call_if_set FLAG_BADGE07_GET, BlackthornCity_EventScript_Trigger4_1
	setflag 0x114B
	release
	end

BlackthornCity_EventScript_Trigger4_1::
	release
	end

BlackthornCity_EventScript_Sign1::
	msgbox BlackthornCity_Text_Sign1, MSGBOX_AUTOCLOSE
	end

BlackthornCity_EventScript_Sign2::
	msgbox BlackthornCity_Text_Sign2, MSGBOX_AUTOCLOSE
	end

BlackthornCity_EventScript_Sign3::
	msgbox BlackthornCity_Text_Sign3, MSGBOX_AUTOCLOSE
	end

BlackthornCity_EventScript_Sign4::
	msgbox BlackthornCity_Text_Sign4, MSGBOX_AUTOCLOSE
	end

BlackthornCity_EventScript_Sign5::
	msgbox BlackthornCity_Text_Sign5, MSGBOX_AUTOCLOSE
	end

BlackthornCity_EventScript_Sign6::
	msgbox BlackthornCity_Text_Sign6, MSGBOX_AUTOCLOSE
	end
