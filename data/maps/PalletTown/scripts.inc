PalletTown_MapScripts::
PalletTown_Area1_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PalletTown_OnFrame
	.byte 0

PalletTown_OnFrame::
	map_script_2 0x7041, 0, PalletTown_EventScript_FrameScene
	.2byte 0

PalletTown_EventScript_FrameScene::
	setflag 0x1360
	setvar 0x7041, 1
	call NewBarkTown_EventScript_FrameScene_1
	end

PalletTown_EventScript_FatMan::
	lock
	faceplayer
	goto_if_set FLAG_SYS_CAN_LINK_WITH_RS, PalletTown_EventScript_FatMan_1
	goto_if_set 0x2A1, PalletTown_EventScript_FatMan_2
	msgbox PalletTown_Text_FatMan_1
	release
	end

PalletTown_EventScript_FatMan_1::
	msgbox PalletTown_Text_FatMan_2
	release
	end

PalletTown_EventScript_FatMan_2::
	msgbox PalletTown_Text_FatMan_3
	release
	end
