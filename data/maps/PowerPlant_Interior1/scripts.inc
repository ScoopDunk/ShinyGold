PowerPlant_Interior1_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, PowerPlant_Interior1_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, PowerPlant_Interior1_OnTransition
	.byte 0

PowerPlant_Interior1_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, PowerPlant_Interior1_EventScript_OnResume_1
	end

PowerPlant_Interior1_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_POWER_PLANT
	call_if_unset 0x2BF, PowerPlant_Interior1_EventScript_OnTransition_1
	call_if_unset 0x2D0, PowerPlant_Interior1_EventScript_OnTransition_2
	call_if_unset 0x2D1, PowerPlant_Interior1_EventScript_OnTransition_3
	end

PowerPlant_Interior1_EventScript_OnResume_1::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, 7, EventScript_Return
	removeobject VAR_LAST_TALKED
	return

PowerPlant_Interior1_EventScript_OnTransition_1::
	clearflag 0x05D
	return

PowerPlant_Interior1_EventScript_OnTransition_2::
	clearflag 0x085
	return

PowerPlant_Interior1_EventScript_OnTransition_3::
	clearflag 0x086
	return

PowerPlant_Interior1_EventScript_Policeman::
	call_if_set 0x1185, PowerPlant_Interior1_EventScript_Policeman_1
	goto_if_set 0x11C1, PowerPlant_Interior1_EventScript_Policeman_2
	msgbox PowerPlant_Interior1_Text_Policeman_1, MSGBOX_NPC
	end

PowerPlant_Interior1_EventScript_Policeman_1::
	msgbox PowerPlant_Interior1_Text_Policeman_2, MSGBOX_NPC
	end

PowerPlant_Interior1_EventScript_Policeman_2::
	msgbox PowerPlant_Interior1_Text_PhoneCall_2, MSGBOX_NPC
	end

PowerPlant_Interior1_EventScript_Scientist::
	call_if_set 0x1185, PowerPlant_Interior1_EventScript_Scientist_1
	msgbox PowerPlant_Interior1_Text_Scientist_1, MSGBOX_NPC
	end

PowerPlant_Interior1_EventScript_Scientist_1::
	msgbox PowerPlant_Interior1_Text_Scientist_2, MSGBOX_NPC
	end

PowerPlant_Interior1_EventScript_Scientist2::
	call_if_set 0x1185, PowerPlant_Interior1_EventScript_Scientist2_1
	msgbox PowerPlant_Interior1_Text_Scientist2_1, MSGBOX_NPC
	end

PowerPlant_Interior1_EventScript_Scientist2_1::
	msgbox PowerPlant_Interior1_Text_Scientist2_2, MSGBOX_NPC
	end

PowerPlant_Interior1_EventScript_Scientist3::
	call_if_set 0x1185, PowerPlant_Interior1_EventScript_Scientist3_1
	msgbox PowerPlant_Interior1_Text_Scientist3_1, MSGBOX_NPC
	end

PowerPlant_Interior1_EventScript_Scientist3_1::
	msgbox PowerPlant_Interior1_Text_Scientist3_2, MSGBOX_NPC
	end

PowerPlant_Interior1_EventScript_Policeman2::
	call_if_set 0x1185, PowerPlant_Interior1_EventScript_Policeman2_1
	msgbox PowerPlant_Interior1_Text_Policeman2_1, MSGBOX_NPC
	end

PowerPlant_Interior1_EventScript_Policeman2_1::
	msgbox PowerPlant_Interior1_Text_Policeman2_2, MSGBOX_NPC
	end

@ Pure Gold/Silver: the manager starts the MACHINE PART hunt (pokegold PowerPlant.asm, PowerPlantManager)
PowerPlant_Interior1_EventScript_BaldingMan::
	lock
	faceplayer
	goto_if_set 0x1185, PowerPlant_Interior1_EventScript_BaldingMan_1
	checkitem ITEM_SECRET_KEY
	goto_if_eq VAR_RESULT, TRUE, PowerPlant_Interior1_EventScript_BaldingMan_2
	goto_if_set 0x11C1, PowerPlant_Interior1_EventScript_BaldingMan_3
	msgbox PowerPlant_Interior1_Text_BaldingMan_1
	setflag 0x11C1
	clearflag 0x11C0
	clearflag 0x272
	setflag 0x11BF
	setvar VAR_GOLD_POWER_PLANT_SCENE, 1
	release
	end

PowerPlant_Interior1_EventScript_BaldingMan_1::
	msgbox PowerPlant_Interior1_Text_BaldingMan_2
	release
	end

PowerPlant_Interior1_EventScript_BaldingMan_2::
	msgbox PowerPlant_Interior1_Text_BaldingMan_3
	removeitem ITEM_SECRET_KEY
	setflag 0x1185
	setflag 0x11B9
	setvar VAR_GOLD_POWER_PLANT_SCENE, 2
	giveitem ITEM_TM07
	msgbox PowerPlant_Interior1_Text_BaldingMan_4
	release
	end

PowerPlant_Interior1_EventScript_BaldingMan_3::
	msgbox PowerPlant_Interior1_Text_BaldingMan_5
	release
	end

@ Pure Gold/Silver: after the player met the manager, the officer at the door gets word from Cerulean
@ (pokegold PowerPlant.asm, PowerPlantGuardPhoneScript)
PowerPlant_Interior1_EventScript_PhoneCall::
	lockall
	playse SE_POKENAV_ON
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	waitse
	delay 30
	msgbox PowerPlant_Interior1_Text_PhoneCall_1
	closemessage
	applymovement 1, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PowerPlant_Interior1_Text_PhoneCall_2
	closemessage
	applymovement 1, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	setvar VAR_GOLD_POWER_PLANT_SCENE, 2
	releaseall
	end
