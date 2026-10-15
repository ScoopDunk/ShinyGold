RadioTower_Cave1_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, RadioTower_Cave1_OnResume
	map_script MAP_SCRIPT_ON_LOAD, RadioTower_Cave1_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RadioTower_Cave1_OnFrame
	.byte 0

RadioTower_Cave1_OnResume::
	setstepcallback STEP_CB_ICE
	end

RadioTower_Cave1_OnLoad::
	special SetIcefallCaveCrackedIceMetatiles
	end

RadioTower_Cave1_OnFrame::
	map_script_2 VAR_TEMP_1, 1, RadioTower_Cave1_EventScript_FrameScene
	.2byte 0

RadioTower_Cave1_EventScript_FrameScene::
	lockall
	delay 20
	applymovement LOCALID_PLAYER, RadioTower_Cave1_Movement_FrameScene
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_UNUSED_FOUR_ISLAND_ICEFALL_CAVE_B1F
	waitstate
	releaseall
	end

RadioTower_Cave1_Movement_FrameScene::
	set_invisible
	step_end

RadioTower_Cave1_EventScript_Boy::
	msgbox RadioTower_Cave1_Text_Boy, MSGBOX_NPC
	end

RadioTower_Cave1_EventScript_MgDeliveryman::
	msgbox RadioTower_Cave1_Text_MgDeliveryman, MSGBOX_NPC
	end
