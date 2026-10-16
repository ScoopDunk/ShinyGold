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
