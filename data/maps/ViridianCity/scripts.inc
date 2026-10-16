ViridianCity_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ViridianCity_OnFrame
	.byte 0

ViridianCity_OnFrame::
	map_script_2 0x7042, 0, ViridianCity_EventScript_FrameScene
	.2byte 0

ViridianCity_EventScript_FrameScene::
	setflag 0x1361
	setvar 0x7042, 1
	call NewBarkTown_EventScript_FrameScene_1
	end

ViridianCity_EventScript_FatMan::
	goto EventScript_DreamEaterTutor

ViridianCity_EventScript_OldMan1::
	lock
	faceplayer
	goto_if_set 0x055, ViridianCity_EventScript_OldMan1_1
	msgbox ViridianCity_Text_OldMan1_1, MSGBOX_AUTOCLOSE
	release
	end

ViridianCity_EventScript_OldMan1_1::
	msgbox ViridianCity_Text_OldMan1_2, MSGBOX_AUTOCLOSE
	release
	end

ViridianCity_EventScript_Vars::
	lock
	faceplayer
	goto_if_set FLAG_BADGE01_GET, ViridianCity_EventScript_Vars_1
	goto_if_ge 0x4051, 2, ViridianCity_EventScript_Vars_2
	goto_if_eq 0x4051, 1, ViridianCity_EventScript_Vars_3
	goto_if_eq 0x4051, 0, ViridianCity_EventScript_Vars_4
	end

ViridianCity_EventScript_Vars_1::
	msgbox ViridianCity_Text_Vars_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 0, ViridianCity_EventScript_Vars_5
	msgbox ViridianCity_Text_Vars_2
	release
	end

ViridianCity_EventScript_Vars_2::
	msgbox ViridianCity_Text_Vars_3
	release
	end

ViridianCity_EventScript_Vars_3::
	call ViridianCity_EventScript_Vars_6
	release
	end

ViridianCity_EventScript_Vars_4::
	msgbox ViridianCity_Text_Vars_4
	closemessage
	release
	end

ViridianCity_EventScript_Vars_5::
	msgbox ViridianCity_Text_Vars_5
	release
	end

ViridianCity_EventScript_Vars_6::
	msgbox ViridianCity_Text_Vars_6
	closemessage
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	special StartOldManTutorialBattle
	waitstate
	lock
	faceplayer
	msgbox ViridianCity_Text_Vars_7
	setvar 0x4051, 2
	giveitem ITEM_TEACHY_TV
	msgbox ViridianCity_Text_Vars_8
	return

ViridianCity_EventScript_OldMan12::
	msgbox ViridianCity_Text_OldMan12, MSGBOX_NPC
	end

ViridianCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox ViridianCity_Text_Youngster_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 1, ViridianCity_EventScript_Youngster_1
	goto_if_eq VAR_RESULT, 0, ViridianCity_EventScript_Youngster_2
	end

ViridianCity_EventScript_Youngster_1::
	msgbox ViridianCity_Text_Youngster_2
	release
	end

ViridianCity_EventScript_Youngster_2::
	msgbox ViridianCity_Text_Youngster_3
	release
	end

ViridianCity_EventScript_Boy::
	msgbox ViridianCity_Text_Boy, MSGBOX_NPC
	end

ViridianCity_EventScript_Trigger2::
	lockall
	textcolor NPC_TEXT_COLOR_NEUTRAL
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	msgbox ViridianCity_Text_Trigger2
	closemessage
	applymovement LOCALID_PLAYER, ViridianCity_Movement_Trigger2
	waitmovement 0
	releaseall
	end

ViridianCity_Movement_Trigger2::
	jump_2_down
	step_end

ViridianCity_EventScript_Sign1::
	msgbox ViridianCity_Text_Sign1, MSGBOX_SIGN
	end

ViridianCity_EventScript_Sign2::
	msgbox ViridianCity_Text_Sign2, MSGBOX_SIGN
	end

ViridianCity_EventScript_Sign3::
	msgbox ViridianCity_Text_Sign3, MSGBOX_SIGN
	end

ViridianCity_EventScript_Sign4::
	msgbox ViridianCity_Text_Sign4, MSGBOX_SIGN
	end

ViridianCity_EventScript_Sign5::
	msgbox ViridianCity_Text_Trigger2, MSGBOX_SIGN
	end
