VermilionCity_Area1_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

@ Pure Gold/Silver: the S.S.AQUA sails back to OLIVINE whenever the player has the S.S.TICKET (pokegold VermilionPort.asm).
@ G/S only sails on Wednesdays and Sundays; this hack has no clock, so the ship is always in port.
VermilionCity_Area1_EventScript_Sailor::
	lock
	faceplayer
	goto VermilionCity_Area1_EventScript_AskBoard

VermilionCity_Area1_EventScript_Trigger1::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement 2, Common_Movement_FaceRight
	waitmovement 0
	goto VermilionCity_Area1_EventScript_AskBoard

VermilionCity_Area1_EventScript_AskBoard::
	msgbox OlivineCity_Area1_Text_Sailor_4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_Area1_EventScript_NotBoarding
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_Area1_EventScript_NoTicket
	msgbox OlivineCity_Area1_Text_Sailor_6
	closemessage
	getplayerxy VAR_0x8004, VAR_0x8005
	call_if_eq VAR_0x8004, 15, VermilionCity_Area1_EventScript_WalkToShip
	call_if_ne VAR_0x8004, 15, VermilionCity_Area1_EventScript_WalkToShipFromSailor
	msgbox OlivineCity_Area1_Text_Sailor_7
	closemessage
	call VermilionCity_Area1_EventScript_SetUpTrip
	warp MAP_SS_AQUA_INTERIOR2, 2
	waitstate
	releaseall
	end

VermilionCity_Area1_EventScript_NotBoarding::
	msgbox OlivineCity_Area1_Text_Sailor_5
	closemessage
	applymovement LOCALID_PLAYER, OlivineCity_Area1_Movement_Sailor_1
	waitmovement 0
	releaseall
	end

VermilionCity_Area1_EventScript_NoTicket::
	msgbox VermilionCity_Area1_Text_NoTicket
	closemessage
	applymovement LOCALID_PLAYER, OlivineCity_Area1_Movement_Sailor_1
	waitmovement 0
	releaseall
	end

VermilionCity_Area1_EventScript_WalkToShip::
	applymovement LOCALID_PLAYER, VermilionCity_Area1_Movement_Trigger1
	waitmovement 0
	return

VermilionCity_Area1_EventScript_WalkToShipFromSailor::
	applymovement LOCALID_PLAYER, OlivineCity_Area1_Movement_Sailor_2
	waitmovement 0
	return

@ Westbound trip (VERMILION to OLIVINE)
VermilionCity_Area1_EventScript_SetUpTrip::
	clearflag 0x1164
	setflag 0x1165
	clearflag 0x1173
	clearflag 0x11A9
	setflag 0x1171
	return

VermilionCity_Area1_EventScript_Boy::
	msgbox VermilionCity_Area1_Text_Boy, MSGBOX_NPC
	end

VermilionCity_Area1_EventScript_ItemIron::
	finditem ITEM_IRON
	end

VermilionCity_Area1_Movement_Trigger1::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
