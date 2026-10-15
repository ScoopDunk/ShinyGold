VermilionCity_Interior9_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

VermilionCity_Interior9_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

VermilionCity_Interior9_EventScript_UnionRoomReceptionist::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	pokemart VermilionCity_Interior9_Items_UnionRoomReceptionist
	msgbox Text_PleaseComeAgain
	release
	end

	.align 1
VermilionCity_Interior9_Items_UnionRoomReceptionist::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE

VermilionCity_Interior9_EventScript_WorkerF::
	lock
	faceplayer
	msgbox VermilionCity_Interior9_Text_WorkerF_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 1, VermilionCity_Interior9_EventScript_WorkerF_1
	msgbox VermilionCity_Interior9_Text_WorkerF_2, MSGBOX_AUTOCLOSE
	release
	end

VermilionCity_Interior9_EventScript_WorkerF_1::
	msgbox VermilionCity_Interior9_Text_WorkerF_3, MSGBOX_AUTOCLOSE
	cleartrainerflag TRAINER_YOUNGSTER_DESTIN_2
	cleartrainerflag TRAINER_LASS_KIA
	cleartrainerflag TRAINER_JUGGLER_MASON
	cleartrainerflag TRAINER_PKMN_RANGER_MADELINE
	cleartrainerflag TRAINER_BLACK_BELT_SHEA_2
	cleartrainerflag TRAINER_PSYCHIC_RODETTE_2
	cleartrainerflag TRAINER_SCIENTIST_RYAN
	warp MAP_VERMILION_CITY_INTERIOR1, 1, 255, 255
	waitstate
	release
	end

VermilionCity_Interior9_EventScript_CooltrainerF::
	msgbox VermilionCity_Interior9_Text_CooltrainerF, MSGBOX_NPC
	end

VermilionCity_Interior9_EventScript_BaldingMan::
	msgbox VermilionCity_Interior9_Text_BaldingMan, MSGBOX_NPC
	end

VermilionCity_Interior9_EventScript_Trigger::
	lockall
	applymovement LOCALID_PLAYER, VermilionCity_Interior9_Movement_Trigger_1
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox VermilionCity_Interior9_Text_Trigger_1
	setvar VAR_0x8004, 17
	special CallTrainerTowerFunc
	goto_if_eq VAR_RESULT, 0, VermilionCity_Interior9_EventScript_Trigger_1
	msgbox VermilionCity_Interior9_Text_Trigger_2
	goto VermilionCity_Interior9_EventScript_Trigger_2

VermilionCity_Interior9_EventScript_Trigger_1::
	msgbox VermilionCity_Interior9_Text_Trigger_3

VermilionCity_Interior9_EventScript_Trigger_2::
	message VermilionCity_Interior9_Text_Trigger_4
	waitmessage
	multichoice 18, 6, MULTICHOICE_YES_NO_INFO, 0
	switch VAR_RESULT
	case 0, VermilionCity_Interior9_EventScript_Trigger_3
	case 1, VermilionCity_Interior9_EventScript_Trigger_4
	case 2, VermilionCity_Interior9_EventScript_Trigger_5
	case 127, VermilionCity_Interior9_EventScript_Trigger_4
	end

VermilionCity_Interior9_Movement_Trigger_1::
	face_right
	step_end

VermilionCity_Interior9_EventScript_Trigger_3::
	multichoice 13, 3, MULTICHOICE_TRAINER_TOWER_MODE, 0
	switch VAR_RESULT
	case 0, VermilionCity_Interior9_EventScript_Trigger_6
	case 1, VermilionCity_Interior9_EventScript_Trigger_6
	case 2, VermilionCity_Interior9_EventScript_Trigger_6
	case 3, VermilionCity_Interior9_EventScript_Trigger_6
	case 4, VermilionCity_Interior9_EventScript_Trigger_4
	case 127, VermilionCity_Interior9_EventScript_Trigger_4
	end

VermilionCity_Interior9_EventScript_Trigger_4::
	msgbox VermilionCity_Interior9_Text_Trigger_5
	closemessage
	applymovement LOCALID_PLAYER, VermilionCity_Interior9_Movement_Trigger_2
	waitmovement 0
	releaseall
	end

VermilionCity_Interior9_EventScript_Trigger_5::
	msgbox VermilionCity_Interior9_Text_Trigger_6
	goto VermilionCity_Interior9_EventScript_Trigger_2

VermilionCity_Interior9_EventScript_Trigger_6::
	copyvar VAR_0x8005, VAR_RESULT
	setvar VAR_MAP_SCENE_TRAINER_TOWER, 1
	special HealPlayerParty
	msgbox VermilionCity_Interior9_Text_Trigger_7
	setvar VAR_0x8004, 6
	special CallTrainerTowerFunc
	releaseall
	end

VermilionCity_Interior9_Movement_Trigger_2::
	walk_down
	step_end

VermilionCity_Interior9_EventScript_Sign::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 1
	special ShowBattleRecords
	waitstate
	releaseall
	end
