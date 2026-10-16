ViridianCity_Interior2_MapScripts::
	.byte 0

ViridianCity_Interior2_EventScript_LeaderBlue2::
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	special UpdatePickStateFromSpecialVar8005
	call ViridianCity_Interior2_EventScript_LeaderBlue2_1
	trainerbattle_single TRAINER_LEADER_BLUE_2, ViridianCity_Interior2_Text_LeaderBlue2Intro, ViridianCity_Interior2_Text_LeaderBlue2Defeat, ViridianCity_Interior2_EventScript_LeaderBlue2Continue, NO_MUSIC
	msgbox ViridianCity_Interior2_Text_LeaderBlue2_1, MSGBOX_NPC
	end

ViridianCity_Interior2_EventScript_LeaderBlue2_1::
	setvar 0x7030, 0x128
	setvar 0x7033, 0x109
	release
	return

ViridianCity_Interior2_EventScript_LeaderBlue2Continue::
	setflag 0x030
	call ViridianCity_Interior2_EventScript_LeaderBlue2_2
	msgbox ViridianCity_Interior2_Text_LeaderBlue2_2, MSGBOX_NPC
	end

ViridianCity_Interior2_EventScript_LeaderBlue2_2::
	setvar 0x7030, 0x129
	setvar 0x7033, 0x10A
	release
	return

ViridianCity_Interior2_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set 0x030, ViridianCity_Interior2_EventScript_GymGuy_1
	msgbox ViridianCity_Interior2_Text_GymGuy_1
	release
	end

ViridianCity_Interior2_EventScript_GymGuy_1::
	msgbox ViridianCity_Interior2_Text_GymGuy_2
	release
	end

ViridianCity_Interior2_EventScript_Sign1::
	lockall
	goto_if_set 0x030, ViridianCity_Interior2_EventScript_Sign1_1
	msgbox ViridianCity_Interior2_Text_Sign1_1
	releaseall
	end

ViridianCity_Interior2_EventScript_Sign1_1::
	msgbox ViridianCity_Interior2_Text_Sign1_2
	releaseall
	end
