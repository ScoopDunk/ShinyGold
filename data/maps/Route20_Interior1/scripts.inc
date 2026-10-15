Route20_Interior1_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

Route20_Interior1_EventScript_LeaderBlaine2::
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	special UpdatePickStateFromSpecialVar8005
	call Route20_Interior1_EventScript_LeaderBlaine2_1
	trainerbattle_single TRAINER_LEADER_BLAINE_2, Route20_Interior1_Text_LeaderBlaine2Intro, Route20_Interior1_Text_LeaderBlaine2Defeat, Route20_Interior1_EventScript_LeaderBlaine2Continue, NO_MUSIC
	msgbox Route20_Interior1_Text_LeaderBlaine2_1, MSGBOX_NPC
	end

Route20_Interior1_EventScript_LeaderBlaine2_1::
	setvar 0x7030, 0x128
	setvar 0x7033, 0x109
	release
	return

Route20_Interior1_EventScript_LeaderBlaine2Continue::
	setflag 0x056
	call Route20_Interior1_EventScript_LeaderBlaine2_2
	clearflag 0x062
	addobject 2
	msgbox Route20_Interior1_Text_LeaderBlaine2_2, MSGBOX_NPC
	end

Route20_Interior1_EventScript_LeaderBlaine2_2::
	setvar 0x7030, 0x129
	setvar 0x7033, 0x10A
	release
	return

Route20_Interior1_EventScript_GymGuy::
	goto_if_set 0x07A, Route20_Interior1_EventScript_GymGuy_1
	msgbox Route20_Interior1_Text_GymGuy_1, MSGBOX_NPC
	setflag 0x07A
	release
	end

Route20_Interior1_EventScript_GymGuy_1::
	msgbox Route20_Interior1_Text_GymGuy_2, MSGBOX_NPC
	release
	end
