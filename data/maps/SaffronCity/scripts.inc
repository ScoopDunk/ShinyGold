SaffronCity_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SaffronCity_OnFrame
	.byte 0

SaffronCity_OnFrame::
	map_script_2 0x704B, 0, SaffronCity_EventScript_FrameScene
	.2byte 0

SaffronCity_EventScript_FrameScene::
	setflag 0x136A
	setvar 0x704B, 1
	call NewBarkTown_EventScript_FrameScene_1
	end

SaffronCity_EventScript_BaldingMan::
	msgbox SaffronCity_Text_BaldingMan, MSGBOX_NPC
	end

SaffronCity_EventScript_CrushGirl_2::
	msgbox SaffronCity_Text_CrushGirl, MSGBOX_NPC
	end

SaffronCity_EventScript_WorkerM::
	msgbox SaffronCity_Text_WorkerM, MSGBOX_NPC
	end

SaffronCity_EventScript_Woman2::
	call_if_set 0x1185, SaffronCity_EventScript_Woman2_1
	msgbox SaffronCity_Text_Woman2_1, MSGBOX_NPC
	end

SaffronCity_EventScript_Woman2_1::
	msgbox SaffronCity_Text_Woman2_2, MSGBOX_NPC
	end

SaffronCity_EventScript_Boy::
	msgbox SaffronCity_Text_Boy, MSGBOX_NPC
	end

SaffronCity_EventScript_FatMan::
	goto_if_set 0x1185, SaffronCity_EventScript_FatMan_1
	msgbox SaffronCity_Text_FatMan_1, MSGBOX_NPC
	end

SaffronCity_EventScript_FatMan_1::
	msgbox SaffronCity_Text_FatMan_2, MSGBOX_NPC
	end

SaffronCity_EventScript_WorkerF::
	msgbox SaffronCity_Text_WorkerF, MSGBOX_NPC
	end

SaffronCity_EventScript_BlackBelt::
	msgbox SaffronCity_Text_BlackBelt, MSGBOX_NPC
	end

@ Invisible blockers out of reach on Saffron City and Route 9 (their custom "MESSAGE FROM ZEL" is gone)
SaffronCity_EventScript_LaprasDoll::
	end

SaffronCity_EventScript_Trigger2::
	call_if_set 0x1185, SaffronCity_EventScript_Trigger2_1
	setflag 0x11D0
	release
	end

SaffronCity_EventScript_Trigger2_1::
	clearflag 0x11D0
	release
	end

SaffronCity_EventScript_Sign2::
	msgbox SaffronCity_Text_Sign2, MSGBOX_AUTOCLOSE
	end

SaffronCity_EventScript_Sign3::
	msgbox SaffronCity_Text_Sign3, MSGBOX_AUTOCLOSE
	end

SaffronCity_EventScript_Sign4::
	msgbox SaffronCity_Text_Sign4, MSGBOX_AUTOCLOSE
	end

SaffronCity_EventScript_Sign5::
	msgbox SaffronCity_Text_Sign5, MSGBOX_AUTOCLOSE
	end

SaffronCity_EventScript_Sign6::
	msgbox SaffronCity_Text_Sign6, MSGBOX_AUTOCLOSE
	end
