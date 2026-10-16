SSAqua_Interior16_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SSAqua_Interior16_OnFrame
	.byte 0

SSAqua_Interior16_OnFrame::
	map_script_2 VAR_GOLD_SS_AQUA_SCENE, 1, SSAqua_Interior16_EventScript_Reunion
	.2byte 0

@ Pure Gold/Silver: the granddaughter is back with her grandpa, who gives the METAL COAT; then the ship arrives
@ in VERMILION CITY (pokegold FastShipCabins_SE_SSE_CaptainsCabin.asm, SSAquaGranddaughterBefore)
SSAqua_Interior16_EventScript_Reunion::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, SSAqua_Interior16_Movement_GirlToGrandpa
	waitmovement 0
	applymovement 2, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SSAqua_Interior16_Text_Granddaughter_1
	closemessage
	applymovement 2, SSAqua_Interior16_Movement_GrandpaToPlayer
	waitmovement 0
	msgbox SSAqua_Interior16_Text_Grandpa_2
	call SSAqua_Interior16_EventScript_GiveMetalCoat
	setvar VAR_GOLD_SS_AQUA_SCENE, 0
	playse SE_DING_DONG
	waitse
	delay 30
	msgbox SSAqua_Interior4_Text_ArrivedVermilion
	closemessage
	setflag 0x11A9
	releaseall
	end

SSAqua_Interior16_EventScript_GiveMetalCoat::
	msgbox SSAqua_Interior16_Text_Grandpa_3
	giveitem ITEM_METAL_COAT
	goto_if_eq VAR_0x8007, FALSE, EventScript_Return
	setflag 0x117B
	return

SSAqua_Interior16_Movement_GirlToGrandpa::
	walk_left
	walk_up
	face_up
	step_end

SSAqua_Interior16_Movement_GrandpaToPlayer::
	face_right
	walk_right
	step_end

SSAqua_Interior16_EventScript_Gentleman::
	lock
	faceplayer
	goto_if_set 0x117B, SSAqua_Interior16_EventScript_Gentleman_2
	goto_if_set 0x1170, SSAqua_Interior16_EventScript_Gentleman_1
	msgbox SSAqua_Interior16_Text_Gentleman
	release
	end

SSAqua_Interior16_EventScript_Gentleman_1::
	call SSAqua_Interior16_EventScript_GiveMetalCoat
	release
	end

SSAqua_Interior16_EventScript_Gentleman_2::
	msgbox SSAqua_Interior16_Text_Grandpa_4
	release
	end

SSAqua_Interior16_EventScript_Granddaughter::
	msgbox SSAqua_Interior16_Text_Granddaughter_2, MSGBOX_NPC
	end

SSAqua_Interior16_EventScript_SuperNerdShawn::
	trainerbattle_single TRAINER_SUPER_NERD_SHAWN, SSAqua_Interior16_Text_SuperNerdShawnIntro, SSAqua_Interior16_Text_SuperNerdShawnDefeat
	call_if_set 0x11A3, SSAqua_Interior16_EventScript_SuperNerdShawn_1
	msgbox SSAqua_Interior16_Text_SuperNerdShawn, MSGBOX_AUTOCLOSE
	end

SSAqua_Interior16_EventScript_SuperNerdShawn_1::
	msgbox SSAqua_Interior16_Text_SuperNerdShawnIntro, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_SUPER_NERD_SHAWN, 0, SSAqua_Interior16_Text_SuperNerdShawnDefeat, SSAqua_Interior3_Text_FishermanJonahVictory
	clearflag 0x11A3
	end
