Route12_Interior1_MapScripts::
	.byte 0

Route12_Interior1_EventScript_Fisher::
	call_if_set 0x11EB, Route12_Interior1_EventScript_Fisher_1
	msgbox Route12_Interior1_Text_Fisher_1, MSGBOX_NPC
	msgbox Route12_Interior1_Text_Fisher_2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route12_Interior1_EventScript_Fisher_2
	msgbox Route12_Interior1_Text_Fisher_3, MSGBOX_NPC
	end

Route12_Interior1_EventScript_Fisher_1::
	msgbox Route12_Interior1_Text_Fisher_4, MSGBOX_NPC
	end

Route12_Interior1_EventScript_Fisher_2::
	msgbox Route12_Interior1_Text_Fisher_5, MSGBOX_NPC
	giveitem ITEM_SUPER_ROD
	msgbox Route12_Interior1_Text_Fisher_4, MSGBOX_NPC
	setflag 0x11EB
	release
	end

Route12_Interior1_EventScript_Sign::
	lockall
	goto_if_set 0x29C, Route12_Interior1_EventScript_Sign_1
	msgbox Route12_Interior1_Text_Sign_1
	releaseall
	end

Route12_Interior1_EventScript_Sign_1::
	special GetMagikarpSizeRecordInfo
	msgbox Route12_Interior1_Text_Sign_2
	releaseall
	end
