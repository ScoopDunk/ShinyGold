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

@ Pure Gold/Silver: the sleepy man gives the DREAM EATER TM as in G/S (pokegold ViridianCityDreamEaterFisher)
@ instead of FireRed's one-time move tutor. Flag 0x039 was the tutor's "taught" flag.
ViridianCity_EventScript_FatMan::
	lock
	faceplayer
	goto_if_set 0x039, ViridianCity_EventScript_FatMan_GotTM
	msgbox ViridianCity_Text_FatMan_DreamEaterFisher
	giveitem ITEM_TM43
	goto_if_eq VAR_RESULT, FALSE, ViridianCity_EventScript_FatMan_NoRoom
	setflag 0x039
ViridianCity_EventScript_FatMan_GotTM::
	msgbox ViridianCity_Text_FatMan_GotDreamEater
	release
	end

ViridianCity_EventScript_FatMan_NoRoom::
	release
	end

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

ViridianCity_EventScript_OldMan12::
	msgbox ViridianCity_Text_OldMan12, MSGBOX_NPC
	end

ViridianCity_EventScript_Boy::
	msgbox ViridianCity_Text_Boy, MSGBOX_NPC
	end

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
