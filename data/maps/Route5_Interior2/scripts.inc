Route5_Interior2_MapScripts::
	.byte 0

Route5_Interior2_EventScript_OldWoman::
	call_if_set 0x11D1, Route5_Interior2_EventScript_OldWoman_1
	msgbox Route5_Interior2_Text_OldWoman_1, MSGBOX_NPC
	giveitem ITEM_CLEANSE_TAG
	setflag 0x11D1
	msgbox Route5_Interior2_Text_OldWoman_2, MSGBOX_NPC
	end

Route5_Interior2_EventScript_OldWoman_1::
	msgbox Route5_Interior2_Text_OldWoman_2, MSGBOX_NPC
	end

Route5_Interior2_EventScript_Lass::
	msgbox Route5_Interior2_Text_Lass, MSGBOX_NPC
	end
