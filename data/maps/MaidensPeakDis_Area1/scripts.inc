MaidensPeakDis_Area1_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

MaidensPeakDis_Area1_EventScript_RocketM::
	lock
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_38, MaidensPeakDis_Area1_EventScript_RocketM_1
	goto_if_eq 0x4076, 4, MaidensPeakDis_Area1_EventScript_RocketM_2
	msgbox MaidensPeakDis_Area1_Text_RocketM_1
	release
	end

MaidensPeakDis_Area1_EventScript_RocketM_1::
	msgbox MaidensPeakDis_Area1_Text_RocketM_2
	release
	end

MaidensPeakDis_Area1_EventScript_RocketM_2::
	applymovement 2, Common_Movement_FacePlayer
	waitmovement 0
	playbgm MUS_ENCOUNTER_ROCKET, 0
	msgbox MaidensPeakDis_Area1_Text_RocketM_3
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_38, MaidensPeakDis_Area1_Text_RocketMDefeat
	msgbox MaidensPeakDis_Area1_Text_RocketM_2
	goto_if_defeated TRAINER_ROCKET_DUO_JESS_AND_JAMIE_5, MaidensPeakDis_Area1_EventScript_RocketM_3
	release
	end

MaidensPeakDis_Area1_EventScript_RocketM_3::
	msgbox MaidensPeakDis_Area1_Text_RocketM_4
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject 2
	removeobject 3
	fadescreen FADE_FROM_BLACK
	release
	end

MaidensPeakDis_Area1_EventScript_DeoxysN::
	lock
	waitse
	playmoncry SPECIES_DEOXYS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, 2
	setvar VAR_0x8004, 0x19A
	setvar VAR_0x8005, 40
	setvar VAR_0x8006, 0
	special CreateEnemyEventMon
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	fadescreen FADE_TO_BLACK
	removeobject 3
	fadescreen FADE_FROM_BLACK
	setflag 0x1410
	release
	end

MaidensPeakDis_Area1_EventScript_CrushGirlJocelyn::
	trainerbattle_single TRAINER_CRUSH_GIRL_JOCELYN, MaidensPeakDis_Area1_Text_CrushGirlJocelynIntro, MaidensPeakDis_Area1_Text_CrushGirlJocelynDefeat
	msgbox MaidensPeakDis_Area1_Text_CrushGirlJocelyn, MSGBOX_AUTOCLOSE
	end

MaidensPeakDis_Area1_EventScript_PkmnRanger595::
	trainerbattle_single TRAINER_PKMN_RANGER_595, MaidensPeakDis_Area1_Text_PkmnRanger595Intro, MaidensPeakDis_Area1_Text_PkmnRanger595Defeat
	msgbox MaidensPeakDis_Area1_Text_PkmnRanger595, MSGBOX_AUTOCLOSE
	end

MaidensPeakDis_Area1_EventScript_Cooltrainer121::
	trainerbattle_single TRAINER_COOLTRAINER_121, MaidensPeakDis_Area1_Text_Cooltrainer121Intro, MaidensPeakDis_Area1_Text_Cooltrainer121Defeat
	msgbox MaidensPeakDis_Area1_Text_Cooltrainer121, MSGBOX_AUTOCLOSE
	end

MaidensPeakDis_Area1_EventScript_Trigger1::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox MaidensPeakDis_Area1_Text_Trigger1_1
	message MaidensPeakDis_Area1_Text_Trigger1_2
	waitmessage
	playse SE_PIN
	applymovement 3, Common_Movement_QuestionMark
	waitmovement 0
	waitbuttonpress
	msgbox MaidensPeakDis_Area1_Text_Trigger1_3
	applymovement 2, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 3, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	call MaidensPeakDis_Area1_EventScript_Trigger1_1
	msgbox MaidensPeakDis_Area1_Text_Trigger1_4
	setvar 0x407F, 2
	releaseall
	end

MaidensPeakDis_Area1_EventScript_Trigger1_1::
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_DOWN
	return
