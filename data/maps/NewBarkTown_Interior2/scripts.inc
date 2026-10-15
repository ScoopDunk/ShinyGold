NewBarkTown_Interior2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_Interior2_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, NewBarkTown_Interior2_OnWarp
	.byte 0

NewBarkTown_Interior2_OnTransition::
	call_if_eq 0x4056, 0, NewBarkTown_Interior2_EventScript_OnTransition_1
	end

NewBarkTown_Interior2_EventScript_OnTransition_1::
	setrespawn HEAL_LOCATION_PALLET_TOWN_AREA1
	return

NewBarkTown_Interior2_OnWarp::
	map_script_2 0x4056, 0, NewBarkTown_Interior2_EventScript_WarpScene
	.2byte 0

NewBarkTown_Interior2_EventScript_WarpScene::
	turnobject LOCALID_PLAYER, DIR_NORTH
	setvar 0x4056, 1
	end

NewBarkTown_Interior2_EventScript_Sign1::
	msgbox NewBarkTown_Interior2_Text_Sign1, MSGBOX_SIGN
	end

NewBarkTown_Interior2_EventScript_Sign2::
PalletTown_PlayersHouse_2F_EventScript_PC::
	goto_if_questlog EventScript_ReleaseEnd
	lockall
	setvar VAR_0x8004, 32
	special Script_SetHelpContext
	setvar VAR_0x8004, 1
	special AnimatePcTurnOn
	playse SE_PC_ON
	msgbox Text_PlayerBootedUpPC
	special BedroomPC
	waitstate
	special SetHelpContextForMap
	releaseall
	end

NewBarkTown_Interior2_EventScript_Sign3::
	msgbox NewBarkTown_Interior2_Text_Sign3, MSGBOX_SIGN
	end
