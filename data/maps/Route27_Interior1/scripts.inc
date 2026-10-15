Route27_Interior1_MapScripts::
	.byte 0

Route27_Interior1_EventScript_OldWoman::
	call_if_set 0x1157, Route27_Interior1_EventScript_OldWoman_1
	msgbox Route27_Interior1_Text_OldWoman_1, MSGBOX_NPC
	specialvar VAR_RESULT, GetLeadMonFriendship
	switch VAR_RESULT
	call_if_eq VAR_0x8000, 5, Route27_Interior1_EventScript_OldWoman_2
	call_if_eq VAR_0x8000, 6, Route27_Interior1_EventScript_OldWoman_2
	msgbox Route27_Interior1_Text_OldWoman_2, MSGBOX_NPC
	end

Route27_Interior1_EventScript_OldWoman_1::
	msgbox Route27_Interior1_Text_OldWoman_3, MSGBOX_NPC
	end

Route27_Interior1_EventScript_OldWoman_2::
	setflag 0x1157
	msgbox Route27_Interior1_Text_OldWoman_4, MSGBOX_NPC
	giveitem ITEM_TM37
	msgbox Route27_Interior1_Text_OldWoman_3, MSGBOX_NPC
	end
