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
