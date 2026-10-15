SSAqua_Interior1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SSAqua_Interior1_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SSAqua_Interior1_OnFrame
	.byte 0

SSAqua_Interior1_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SSANNE_EXTERIOR
	end

SSAqua_Interior1_OnFrame::
	map_script_2 0x407E, 1, SSAqua_Interior1_EventScript_FrameScene
	.2byte 0

SSAqua_Interior1_EventScript_FrameScene::
	lockall
	getplayerxy VAR_0x8004, VAR_0x8005
	call_if_le VAR_0x8005, 6, SSAqua_Interior1_EventScript_FrameScene_1
	call_if_ge VAR_0x8005, 7, SSAqua_Interior1_EventScript_FrameScene_2
	fadenewbgm MUS_SURF
	delay 50
	special DoSSAnneDepartureCutscene
	waitstate
	removeobject 1
	applymovement LOCALID_PLAYER, SSAqua_Interior1_Movement_FrameScene_1
	waitmovement 0
	setvar 0x407E, 2
	setvar 0x4053, 0
	warp MAP_VERMILION_CITY, 23, 34
	waitstate
	releaseall
	end

SSAqua_Interior1_EventScript_FrameScene_1::
	applymovement LOCALID_PLAYER, SSAqua_Interior1_Movement_FrameScene_2
	waitmovement 0
	return

SSAqua_Interior1_EventScript_FrameScene_2::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

SSAqua_Interior1_Movement_FrameScene_1::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SSAqua_Interior1_Movement_FrameScene_2::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SSAqua_Interior1_EventScript_SsAnne::
	msgbox SSAqua_Interior1_Text_SsAnne_1, MSGBOX_AUTOCLOSE
	closemessage
	call EventScript_OutOfCenterPartyHeal
	msgbox SSAqua_Interior1_Text_SsAnne_2, MSGBOX_AUTOCLOSE
	call_if_unset 0x117D, SSAqua_Interior1_EventScript_SsAnne_1
	playbgm SE_DING_DONG, 51
	delay 80
	playbgm MUS_CELADON, 51
	call_if_set 0x1165, SSAqua_Interior1_EventScript_SsAnne_2
	msgbox SSAqua_Interior1_Text_SsAnne_3, MSGBOX_AUTOCLOSE
	setflag 0x11A9
	release
	end

SSAqua_Interior1_EventScript_SsAnne_1::
	release
	end

SSAqua_Interior1_EventScript_SsAnne_2::
	msgbox SSAqua_Interior1_Text_SsAnne_4, MSGBOX_AUTOCLOSE
	setflag 0x11A9
	release
	end
