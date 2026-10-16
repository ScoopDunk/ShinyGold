FuchsiaCity_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FuchsiaCity_OnFrame
	.byte 0

FuchsiaCity_OnFrame::
	map_script_2 0x7048, 0, FuchsiaCity_EventScript_FrameScene
	.2byte 0

FuchsiaCity_EventScript_FrameScene::
	call CeruleanCity_EventScript_Trigger1
	setflag 0x1367
	setvar 0x7048, 1
	call NewBarkTown_EventScript_FrameScene_1
	end

FuchsiaCity_EventScript_Camper::
	msgbox FuchsiaCity_Text_Camper, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Woman2::
	msgbox FuchsiaCity_Text_Woman2, MSGBOX_NPC
	end

FuchsiaCity_EventScript_ItemRepeatBall::
	finditem ITEM_REPEAT_BALL
	end

FuchsiaCity_EventScript_BaldingMan::
	msgbox FuchsiaCity_Text_BaldingMan, MSGBOX_NPC
	end

FuchsiaCity_EventScript_ItemFullRestore::
	finditem ITEM_FULL_RESTORE
	end

FuchsiaCity_EventScript_Sign1::
	msgbox FuchsiaCity_Text_Sign1, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_EventScript_Sign2::
	msgbox FuchsiaCity_Text_Sign2, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_EventScript_Sign3::
	msgbox FuchsiaCity_Text_Sign3, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_EventScript_Sign4::
	msgbox FuchsiaCity_Text_Sign4, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_EventScript_Sign5::
	msgbox FuchsiaCity_Text_Sign5, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_EventScript_Sign7::
	msgbox FuchsiaCity_Text_Sign7, MSGBOX_AUTOCLOSE
	end
