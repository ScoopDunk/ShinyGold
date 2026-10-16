PalletTown_MapScripts::
	@ ShinyGold: unreachable map, emptied (the slot is kept so map ids stay the same)
	.byte 0
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
