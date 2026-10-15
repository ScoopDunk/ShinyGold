Route16_Interior3_MapScripts::
	.byte 0

Route16_Interior3_EventScript_Youngster::
	msgbox Route16_Interior3_Text_Youngster, MSGBOX_NPC
	end

Route16_Interior3_EventScript_Lass::
	msgbox Route16_Interior3_Text_Lass, MSGBOX_NPC
	end

Route16_Interior3_EventScript_BaldingMan::
	call_if_set 0x11E8, Route16_Interior3_EventScript_BaldingMan_1
	call_if_unset 0x117E, Route16_Interior3_EventScript_BaldingMan_2
	call_if_unset 0x117F, Route16_Interior3_EventScript_BaldingMan_2
	call_if_unset 0x1180, Route16_Interior3_EventScript_BaldingMan_2
	call_if_unset 0x1181, Route16_Interior3_EventScript_BaldingMan_2
	msgbox Route16_Interior3_Text_BaldingMan_1, MSGBOX_NPC
	giveitem ITEM_RED_FLUTE
	setflag 0x11E8
	msgbox Route16_Interior3_Text_BaldingMan_2, MSGBOX_NPC
	end

Route16_Interior3_EventScript_BaldingMan_1::
	msgbox Route16_Interior3_Text_BaldingMan_2, MSGBOX_NPC
	end

Route16_Interior3_EventScript_BaldingMan_2::
	msgbox Route16_Interior3_Text_BaldingMan_3, MSGBOX_NPC
	end

Route16_Interior3_EventScript_Sign1::
	msgbox Route16_Interior3_Text_Sign1, MSGBOX_SIGN
	end

Route16_Interior3_EventScript_Sign2::
	msgbox Route16_Interior3_Text_Sign2, MSGBOX_SIGN
	end
