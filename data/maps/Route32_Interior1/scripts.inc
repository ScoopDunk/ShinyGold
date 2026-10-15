Route32_Interior1_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

Route32_Interior1_EventScript_Fisher::
	call_if_set 0x1053, Route32_Interior1_EventScript_Fisher_1
	faceplayer
	msgbox Route32_Interior1_Text_Fisher_1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route32_Interior1_EventScript_Fisher_2
	msgbox Route32_Interior1_Text_Fisher_2, MSGBOX_NPC
	end

Route32_Interior1_EventScript_Fisher_1::
	msgbox Route32_Interior1_Text_Fisher_3, MSGBOX_NPC
	end

Route32_Interior1_EventScript_Fisher_2::
	msgbox Route32_Interior1_Text_Fisher_4, MSGBOX_NPC
	giveitem ITEM_OLD_ROD
	msgbox Route32_Interior1_Text_Fisher_5, MSGBOX_NPC
	setflag 0x1053
	end

Route32_Interior1_EventScript_Lass::
	msgbox Route32_Interior1_Text_Lass, MSGBOX_NPC
	end
