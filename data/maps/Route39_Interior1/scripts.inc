Route39_Interior1_MapScripts::
	.byte 0

Route39_Interior1_EventScript_Woman3::
	call_if_set 0x10B2, Route39_Interior1_EventScript_Woman3_1
	call_if_set 0x10B1, Route39_Interior1_EventScript_Woman3_2
	msgbox Route39_Interior1_Text_Woman3_1, MSGBOX_NPC
	end

Route39_Interior1_EventScript_Woman3_1::
	msgbox Route39_Interior1_Text_Woman3_2, MSGBOX_NPC
	end

Route39_Interior1_EventScript_Woman3_2::
	setflag 0x10B2
	msgbox Route39_Interior1_Text_Woman3_3, MSGBOX_NPC
	giveitem ITEM_TM44
	msgbox Route39_Interior1_Text_Woman3_2, MSGBOX_NPC
	end

Route39_Interior1_EventScript_BaldingMan::
	call_if_set 0x10B1, Route39_Interior1_EventScript_BaldingMan_1
	msgbox Route39_Interior1_Text_BaldingMan_1, MSGBOX_NPC
	end

Route39_Interior1_EventScript_BaldingMan_1::
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, Route39_Interior1_EventScript_BaldingMan_2
	showmoneybox 0, 0
	lock
	faceplayer
	msgbox Route39_Interior1_Text_BaldingMan_2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route39_Interior1_EventScript_BaldingMan_3
	msgbox Route39_Interior1_Text_BaldingMan_3, MSGBOX_NPC
	.byte 0x94 @ hidemoneybox (FRLG consumes no argument bytes)
	nop
	nop1
	releaseall
	end

Route39_Interior1_EventScript_BaldingMan_2::
	msgbox Route39_Interior1_Text_BaldingMan_4, MSGBOX_NPC
	end

Route39_Interior1_EventScript_BaldingMan_3::
	checkmoney 0x1F4
	call_if_eq VAR_RESULT, 0, Route39_Interior1_EventScript_BaldingMan_4
	removemoney 0x1F4
	updatemoneybox
	msgbox Route39_Interior1_Text_BaldingMan_5, MSGBOX_NPC
	giveitem ITEM_MOOMOO_MILK
	textcolor 104
	.byte 0x94 @ hidemoneybox (FRLG consumes no argument bytes)
	releaseall
	special DaisyMassageServices
	end

Route39_Interior1_EventScript_BaldingMan_4::
	msgbox Route39_Interior1_Text_BaldingMan_6, MSGBOX_NPC
	closemessage
	.byte 0x94 @ hidemoneybox (FRLG consumes no argument bytes)
	nop
	nop1
	releaseall
	end
