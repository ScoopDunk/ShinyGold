AzaleaTown_Interior3_MapScripts::
	.byte 0

AzaleaTown_Interior3_EventScript_Rocker::
	call_if_set 0x1072, AzaleaTown_Interior3_EventScript_Rocker_1
	call_if_set 0x1061, AzaleaTown_Interior3_EventScript_Rocker_2
	msgbox AzaleaTown_Interior3_Text_Rocker_1, MSGBOX_NPC
	end

AzaleaTown_Interior3_EventScript_Rocker_1::
	msgbox AzaleaTown_Interior3_Text_Rocker_2, MSGBOX_NPC
	end

AzaleaTown_Interior3_EventScript_Rocker_2::
	msgbox AzaleaTown_Interior3_Text_Rocker_3, MSGBOX_NPC
	end

AzaleaTown_Interior3_EventScript_Boy::
	call_if_set 0x1061, AzaleaTown_Interior3_EventScript_Boy_1
	msgbox AzaleaTown_Interior3_Text_Boy_1, MSGBOX_NPC
	end

AzaleaTown_Interior3_EventScript_Boy_1::
	call_if_set 0x1076, AzaleaTown_Interior3_EventScript_Boy_2
	setflag 0x1076
	msgbox AzaleaTown_Interior3_Text_Boy_2, MSGBOX_NPC
	lock
	faceplayer
	giveitem ITEM_CHARCOAL
	msgbox AzaleaTown_Interior3_Text_Boy_3, MSGBOX_NPC
	release
	end

AzaleaTown_Interior3_EventScript_Boy_2::
	msgbox AzaleaTown_Interior3_Text_Boy_3, MSGBOX_NPC
	end

AzaleaTown_Interior3_EventScript_Fearow::
	msgbox IlexForest_Interior1_Text_Fearow2, MSGBOX_NPC
	waitse
	playmoncry SPECIES_FARFETCHD, 0x201
	end
