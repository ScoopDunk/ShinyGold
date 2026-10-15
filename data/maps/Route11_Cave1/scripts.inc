Route11_Cave1_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

Route11_Cave1_EventScript_OldMan1::
	call_if_set 0x11ED, Route11_Cave1_EventScript_OldMan1_1
	msgbox Route11_Cave1_Text_OldMan1_1, MSGBOX_NPC
	msgbox Route11_Cave1_Text_OldMan1_2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route11_Cave1_EventScript_OldMan1_2
	msgbox Route11_Cave1_Text_OldMan1_3, MSGBOX_NPC
	end

Route11_Cave1_EventScript_OldMan1_1::
	msgbox Route11_Cave1_Text_OldMan1_4, MSGBOX_NPC
	end

Route11_Cave1_EventScript_OldMan1_2::
	getpartysize
	call_if_lt VAR_RESULT, 6, Route11_Cave1_EventScript_OldMan1_3
	msgbox Route11_Cave1_Text_OldMan1_5, MSGBOX_NPC
	end

Route11_Cave1_EventScript_OldMan1_3::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, Route11_Cave1_EventScript_OldMan1_4
	call_if_eq VAR_0x8008, 1, Route11_Cave1_EventScript_OldMan1_5
	call_if_eq VAR_0x8008, 2, Route11_Cave1_EventScript_OldMan1_6
	compare VAR_0x8008, 3
	call_if 199, 0x010D3103
	msgbox Route14_Text_Sign1_3
	waitfanfare
	textcolor NPC_TEXT_COLOR_MALE
	giveegg SPECIES_ELEKID
	msgbox Route11_Cave1_Text_OldMan1_6, MSGBOX_NPC
	setflag 0x11ED
	release
	end

Route11_Cave1_EventScript_OldMan1_4::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_SLOTS_WIN
	msgbox Route14_Text_Sign1_3
	waitfanfare
	textcolor NPC_TEXT_COLOR_MALE
	giveegg SPECIES_PICHU
	msgbox Route11_Cave1_Text_OldMan1_6, MSGBOX_NPC
	setflag 0x11ED
	release
	end

Route11_Cave1_EventScript_OldMan1_5::
	@ ShinyGold: overlapping data duplicated from 0x0887CC60
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_SLOTS_WIN
	msgbox Route14_Text_Sign1_3
	waitfanfare
	textcolor NPC_TEXT_COLOR_MALE
	giveegg SPECIES_ELEKID
	msgbox Route11_Cave1_Text_OldMan1_6, MSGBOX_NPC
	setflag 0x11ED
	release
	end

Route11_Cave1_EventScript_OldMan1_6::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_SLOTS_WIN
	msgbox Route14_Text_Sign1_3
	waitfanfare
	textcolor NPC_TEXT_COLOR_MALE
	giveegg SPECIES_MAGBY
	msgbox Route11_Cave1_Text_OldMan1_6, MSGBOX_NPC
	setflag 0x11ED
	release
	end
