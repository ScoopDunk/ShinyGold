MtSilver_Cave1_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

MtSilver_Cave1_EventScript_PkmnTrainerRed::
	lockall
	faceplayer
	setvar 0x7030, 0x129
	setvar 0x7033, 0x158
	msgbox MtSilver_Cave1_Text_PkmnTrainerRed_1, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_PKMN_TRAINER_RED, 0, MtSilver_Cave1_Text_PkmnTrainerRedDefeat, MtSilver_Cave1_Text_PkmnTrainerRedDefeat
	setvar 0x7030, 0x158
	setvar 0x7033, 0x129
	msgbox MtSilver_Cave1_Text_PkmnTrainerRed_2, MSGBOX_NPC
	fadescreen FADE_TO_BLACK
	setflag 0x02F
	setflag 0x05E
	cleartrainerflag TRAINER_PKMN_TRAINER_RED
	removeobject 1
	fadescreen FADE_FROM_BLACK
	setrespawn HEAL_LOCATION_NEW_BARK_TOWN
	fadescreenspeed FADE_TO_BLACK, 24
	special EnterHallOfFame
	waitstate
	releaseall
	end

MtSilver_Cave1_EventScript_Fossil::
	lock
	faceplayer
	msgbox MtSilver_Cave1_Text_Fossil_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 0, MtSilver_Cave1_EventScript_Fossil_1
	removeobject 2
	giveitem_msg MtSilver_Cave1_Text_Fossil_2, ITEM_HELIX_FOSSIL, 1, 0x13E
	closemessage
	special QuestLog_CutRecording
	delay 10
	applymovement 3, MtSilver_Cave1_Movement_Fossil
	waitmovement 0
	copyobjectxytoperm 3
	textcolor NPC_TEXT_COLOR_MALE
	playfanfare MUS_OBTAIN_KEY_ITEM
	message MtSilver_Cave1_Text_Fossil_3
	waitmessage
	waitfanfare
	removeobject 1
	setflag 0x273
	setflag 0x232
	release
	end

MtSilver_Cave1_EventScript_Fossil_1::
	release
	end

MtSilver_Cave1_Movement_Fossil::
	walk_up
	walk_up
	walk_up
	step_end

MtSilver_Cave1_EventScript_Scientist::
	lock
	faceplayer
	goto_if_set 0x232, MtSilver_Cave1_EventScript_Scientist_1
	goto_if_defeated TRAINER_BOARDER_RONALD, MtSilver_Cave1_EventScript_Scientist_2
	call MtSilver_Cave1_EventScript_Scientist_3
	release
	end

MtSilver_Cave1_EventScript_Scientist_1::
	msgbox MtSilver_Cave1_Text_Scientist_1
	release
	end

MtSilver_Cave1_EventScript_Scientist_2::
	msgbox MtSilver_Cave1_Text_Scientist_2
	release
	end

MtSilver_Cave1_EventScript_Scientist_3::
	textcolor NPC_TEXT_COLOR_MALE
	message MtSilver_Cave1_Text_Scientist_3
	waitmessage
	playbgm MUS_ENCOUNTER_GYM_LEADER, 0
	waitbuttonpress
	setvar VAR_LAST_TALKED, 3
	trainerbattle_no_intro TRAINER_BOARDER_RONALD, MtSilver_Cave1_Text_ScientistDefeat
	setvar 0x408B, 1
	msgbox MtSilver_Cave1_Text_Scientist_2
	return

MtSilver_Cave1_EventScript_TeamRocketGrunt7::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_7, MtSilver_Cave1_Text_TeamRocketGrunt7Intro, MtSilver_Cave1_Text_TeamRocketGrunt7Defeat
	msgbox MtSilver_Cave1_Text_TeamRocketGrunt7, MSGBOX_AUTOCLOSE
	end

MtSilver_Cave1_EventScript_TeamRocketGrunt4::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_4, MtSilver_Cave1_Text_TeamRocketGrunt4Intro, MtSilver_Cave1_Text_TeamRocketGrunt4Defeat
	msgbox MtSilver_Cave1_Text_TeamRocketGrunt4, MSGBOX_AUTOCLOSE
	end

MtSilver_Cave1_EventScript_TeamRocketGrunt6::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_6, MtSilver_Cave1_Text_TeamRocketGrunt6Intro, MtSilver_Cave1_Text_TeamRocketGrunt6Defeat
	msgbox MtSilver_Cave1_Text_TeamRocketGrunt6, MSGBOX_AUTOCLOSE
	end

MtSilver_Cave1_EventScript_TeamRocketGrunt5::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_5, MtSilver_Cave1_Text_TeamRocketGrunt5Intro, MtSilver_Cave1_Text_TeamRocketGrunt5Defeat
	msgbox MtSilver_Cave1_Text_TeamRocketGrunt5, MSGBOX_AUTOCLOSE
	end

MtSilver_Cave1_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE
	end

MtSilver_Cave1_EventScript_ItemFullRestore::
	finditem ITEM_FULL_RESTORE
	end

MtSilver_Cave1_EventScript_Trigger::
	lockall
	applymovement 3, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call MtSilver_Cave1_EventScript_Scientist_3
	releaseall
	end
