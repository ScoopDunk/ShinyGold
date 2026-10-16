OlivineCity_Area1_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

@ Pure Gold/Silver: the S.S.AQUA sails from OLIVINE whenever the player has the S.S.TICKET (pokegold OlivinePort.asm).
@ G/S only sails on Mondays and Fridays; this hack has no clock, so the ship is always in port.
OlivineCity_Area1_EventScript_Sailor::
	lock
	faceplayer
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, OlivineCity_Area1_EventScript_Sailor_1
	msgbox OlivineCity_Area1_Text_Sailor_4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OlivineCity_Area1_EventScript_Sailor_3
	msgbox OlivineCity_Area1_Text_Sailor_6
	closemessage
	applymovement LOCALID_PLAYER, OlivineCity_Area1_Movement_Sailor_2
	waitmovement 0
	msgbox OlivineCity_Area1_Text_Sailor_7
	closemessage
	call OlivineCity_Area1_EventScript_Sailor_6
	warp MAP_SS_AQUA_INTERIOR2, 2
	waitstate
	release
	end

OlivineCity_Area1_EventScript_Sailor_1::
	msgbox OlivineCity_Area1_Text_Sailor_2
	closemessage
	applymovement LOCALID_PLAYER, OlivineCity_Area1_Movement_Sailor_1
	waitmovement 0
	release
	end

OlivineCity_Area1_EventScript_Sailor_3::
	msgbox OlivineCity_Area1_Text_Sailor_5
	closemessage
	applymovement LOCALID_PLAYER, OlivineCity_Area1_Movement_Sailor_1
	waitmovement 0
	release
	end

OlivineCity_Area1_Movement_Sailor_1::
	walk_up
	step_end

OlivineCity_Area1_Movement_Sailor_2::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

@ Eastbound trip (OLIVINE to VERMILION). On the first trip the lost-granddaughter story is set up.
OlivineCity_Area1_EventScript_Sailor_6::
	clearflag 0x1164
	clearflag 0x1165
	clearflag 0x1173
	clearflag 0x11A9
	setflag 0x1171
	goto_if_set 0x1177, EventScript_Return
	clearflag 0x1166
	clearflag 0x1167
	clearflag 0x1168
	setflag 0x1169
	clearflag 0x1170
	clearflag 0x1176
	return

OlivineCity_Area1_EventScript_Fisher::
	msgbox OlivineCity_Area1_Text_Fisher, MSGBOX_NPC
	end

OlivineCity_Area1_EventScript_Fisher2::
	msgbox OlivineCity_Area1_Text_Fisher2, MSGBOX_NPC
	end

OlivineCity_Area1_EventScript_ItemProtein::
	finditem ITEM_PROTEIN
	end

OlivineCity_Area1_EventScript_Sailor2::
	msgbox OlivineCity_Area1_Text_Sailor2, MSGBOX_NPC
	end

OlivineCity_Area1_EventScript_Trigger2::
	goto_if_set 0x11A9, OlivineCity_Area1_EventScript_Trigger2_1
	release
	end

OlivineCity_Area1_EventScript_Trigger2_1::
	clearflag 0x11A9
	applymovement LOCALID_PLAYER, OlivineCity_Area1_Movement_Trigger2
	delay 32
	end

OlivineCity_Area1_Movement_Trigger2::
	walk_right
	walk_up
	walk_up
	step_end

OlivineCity_Area1_EventScript_Trigger3::
	goto_if_set 0x11A9, OlivineCity_Area1_EventScript_Trigger3_1
	release
	end

OlivineCity_Area1_EventScript_Trigger3_1::
	clearflag 0x11A9
	applymovement LOCALID_PLAYER, OlivineCity_Area1_Movement_Trigger3
	delay 32
	end

OlivineCity_Area1_Movement_Trigger3::
	walk_up
	walk_up
	step_end
