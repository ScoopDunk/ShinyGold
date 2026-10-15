CianwoodCity_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CianwoodCity_OnFrame
	.byte 0

CianwoodCity_OnFrame::
	map_script_2 0x7040, 0, CianwoodCity_EventScript_FrameScene
	.2byte 0

CianwoodCity_EventScript_FrameScene::
	setflag 0x1370
	setvar 0x7040, 1
	call NewBarkTown_EventScript_FrameScene_1
	end

CianwoodCity_EventScript_Woman3::
	call_if_set 0x10CE, CianwoodCity_EventScript_Woman3_1
	call_if_set FLAG_BADGE03_GET, CianwoodCity_EventScript_Woman3_2
	msgbox CianwoodCity_Text_Woman3_1, MSGBOX_NPC
	end

CianwoodCity_EventScript_Woman3_1::
	msgbox CianwoodCity_Text_Woman3_2, MSGBOX_NPC
	end

CianwoodCity_EventScript_Woman3_2::
	setflag 0x10CE
	msgbox CianwoodCity_Text_Woman3_3, MSGBOX_NPC
	faceplayer
	lock
	giveitem ITEM_HM02
	msgbox CianwoodCity_Text_Woman3_4, MSGBOX_NPC
	msgbox CianwoodCity_Text_Woman3_2, MSGBOX_NPC
	end

CianwoodCity_EventScript_Woman2::
	msgbox CianwoodCity_Text_Woman2, MSGBOX_NPC
	end

CianwoodCity_EventScript_Youngster::
	msgbox CianwoodCity_Text_Youngster, MSGBOX_NPC
	end

CianwoodCity_EventScript_FatMan::
	msgbox CianwoodCity_Text_FatMan, MSGBOX_NPC
	end

CianwoodCity_EventScript_ItemRevive::
	finditem ITEM_REVIVE
	end

CianwoodCity_EventScript_ItemMaxEther::
	finditem ITEM_MAX_ETHER
	end

CianwoodCity_EventScript_PkmnTrainer205::
	msgbox CianwoodCity_Text_PkmnTrainer205_1, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_PKMN_TRAINER_205, 0, CianwoodCity_Text_PkmnTrainer205Defeat, CianwoodCity_Text_PkmnTrainer205Victory
	delay 32
	setflag 0x10CA
	msgbox CianwoodCity_Text_PkmnTrainer205_2, MSGBOX_NPC
	applymovement 13, CianwoodCity_Movement_PkmnTrainer205
	delay 48
	release
	end

CianwoodCity_Movement_PkmnTrainer205::
	walk_up
	set_invisible
	walk_up
	walk_up
	step_end

CianwoodCity_EventScript_Trigger1::
	call_if_unset FLAG_BADGE08_GET, CianwoodCity_EventScript_Trigger1_1
	call_if_unset FLAG_BADGE03_GET, CianwoodCity_EventScript_Trigger1_1
	call_if_unset FLAG_BADGE06_GET, CianwoodCity_EventScript_Trigger1_1
	call_if_set 0x110A, CianwoodCity_EventScript_Trigger1_1
	setflag 0x110A
	setflag 0x10BF
	clearflag 0x10BD
	setflag 0x110B
	setflag 0x1098
	clearflag 0x1099
	call Route30_EventScript_Trigger3_2
	msgbox CianwoodCity_Text_Trigger1, MSGBOX_NPC
	release
	end

CianwoodCity_EventScript_Trigger1_1::
	release
	end

CianwoodCity_EventScript_Sign1::
	msgbox CianwoodCity_Text_Sign1, MSGBOX_AUTOCLOSE
	end

CianwoodCity_EventScript_Sign2::
	msgbox CianwoodCity_Text_Sign2, MSGBOX_AUTOCLOSE
	end

CianwoodCity_EventScript_Sign3::
	msgbox CianwoodCity_Text_Sign3, MSGBOX_AUTOCLOSE
	end

CianwoodCity_EventScript_Sign4::
	msgbox CianwoodCity_Text_Sign4, MSGBOX_AUTOCLOSE
	end
