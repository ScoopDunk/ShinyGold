OlivineCity_Interior2_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

OlivineCity_Interior2_EventScript_Gentleman::
	msgbox OlivineCity_Interior2_Text_Gentleman, MSGBOX_NPC
	end

OlivineCity_Interior2_EventScript_Sailor::
	call_if_set 0x10C7, OlivineCity_Interior2_EventScript_Sailor_1
	msgbox OlivineCity_Interior2_Text_Sailor_1, MSGBOX_NPC
	giveitem ITEM_HM04
	msgbox OlivineCity_Interior2_Text_Sailor_2, MSGBOX_NPC
	setflag 0x10C7
	end

OlivineCity_Interior2_EventScript_Sailor_1::
	msgbox OlivineCity_Interior2_Text_Sailor_2, MSGBOX_NPC
	end
