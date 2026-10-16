LavRadioTower_Interior1_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

LavRadioTower_Interior1_EventScript_WorkerM::
	msgbox LavRadioTower_Interior1_Text_WorkerM, MSGBOX_NPC
	end

LavRadioTower_Interior1_EventScript_Gentleman::
	call_if_set 0x11E2, LavRadioTower_Interior1_EventScript_Gentleman_1
	call_if_set 0x1185, LavRadioTower_Interior1_EventScript_Gentleman_2
	msgbox LavRadioTower_Interior1_Text_Gentleman_1, MSGBOX_NPC
	end

LavRadioTower_Interior1_EventScript_Gentleman_1::
	msgbox LavRadioTower_Interior1_Text_Gentleman_2, MSGBOX_NPC
	end

LavRadioTower_Interior1_EventScript_Gentleman_2::
	msgbox LavRadioTower_Interior1_Text_Gentleman_3, MSGBOX_NPC
	checkitem ITEM_TEACHY_TV
	call_if_eq VAR_RESULT, 1, LavRadioTower_Interior1_EventScript_Gentleman_3
	msgbox LavRadioTower_Interior1_Text_Gentleman_4, MSGBOX_NPC
	end

LavRadioTower_Interior1_EventScript_Gentleman_3::
	giveitem ITEM_POKE_FLUTE
	msgbox LavRadioTower_Interior1_Text_Gentleman_2, MSGBOX_NPC
	setflag 0x11E2
	release
	end

LavRadioTower_Interior1_EventScript_Man::
	call_if_set 0x11E2, LavRadioTower_Interior1_EventScript_Man_1
	msgbox LavRadioTower_Interior1_Text_Man_1, MSGBOX_NPC
	end

LavRadioTower_Interior1_EventScript_Man_1::
	msgbox LavRadioTower_Interior1_Text_Man_2, MSGBOX_NPC
	end

LavRadioTower_Interior1_EventScript_CableClubReceptionist::
	msgbox LavRadioTower_Interior1_Text_CableClubReceptionist, MSGBOX_NPC
	end

LavRadioTower_Interior1_EventScript_Policeman::
	msgbox LavRadioTower_Interior1_Text_Policeman, MSGBOX_NPC
	end

LavRadioTower_Interior1_EventScript_Sign1::
	msgbox LavRadioTower_Interior1_Text_Sign1, MSGBOX_AUTOCLOSE
	end

LavRadioTower_Interior1_EventScript_Sign2::
	msgbox LavRadioTower_Interior1_Text_Sign2, MSGBOX_AUTOCLOSE
	end
