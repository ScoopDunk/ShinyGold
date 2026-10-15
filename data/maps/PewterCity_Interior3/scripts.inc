PewterCity_Interior3_MapScripts::
	.byte 0

PewterCity_Interior3_EventScript_LeaderBrock2::
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	special UpdatePickStateFromSpecialVar8005
	call PewterCity_Interior3_EventScript_LeaderBrock2_1
	trainerbattle_single TRAINER_LEADER_BROCK_2, PewterCity_Interior3_Text_LeaderBrock2Intro, PewterCity_Interior3_Text_LeaderBrock2Defeat, PewterCity_Interior3_EventScript_LeaderBrock2Continue, NO_MUSIC
	msgbox PewterCity_Interior3_Text_LeaderBrock2_1, MSGBOX_NPC
	end

PewterCity_Interior3_EventScript_LeaderBrock2_1::
	setvar 0x7030, 0x128
	setvar 0x7033, 0x109
	release
	return

PewterCity_Interior3_EventScript_LeaderBrock2Continue::
	setflag 0x02E
	call PewterCity_Interior3_EventScript_LeaderBrock2_2
	msgbox PewterCity_Interior3_Text_LeaderBrock2_2, MSGBOX_NPC
	end

PewterCity_Interior3_EventScript_LeaderBrock2_2::
	setvar 0x7030, 0x129
	setvar 0x7033, 0x10A
	release
	return

PewterCity_Interior3_EventScript_CamperJerry::
	trainerbattle_single TRAINER_CAMPER_JERRY, PewterCity_Interior3_Text_CamperJerryIntro, PewterCity_Interior3_Text_CamperJerryDefeat
	msgbox PewterCity_Interior3_Text_CamperJerry, MSGBOX_AUTOCLOSE
	end

PewterCity_Interior3_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set 0x02E, PewterCity_Interior3_EventScript_GymGuy_1
	msgbox PewterCity_Interior3_Text_GymGuy_1
	release
	end

PewterCity_Interior3_EventScript_GymGuy_1::
	msgbox PewterCity_Interior3_Text_GymGuy_2
	release
	end

PewterCity_Interior3_EventScript_Sign1::
	lockall
	goto_if_set 0x02E, PewterCity_Interior3_EventScript_Sign1_1
	msgbox PewterCity_Interior3_Text_Sign1_1
	releaseall
	end

PewterCity_Interior3_EventScript_Sign1_1::
	msgbox PewterCity_Interior3_Text_Sign1_2
	releaseall
	end
