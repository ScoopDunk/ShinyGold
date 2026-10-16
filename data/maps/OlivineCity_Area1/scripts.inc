OlivineCity_Area1_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

OlivineCity_Area1_EventScript_Sailor::
	call_if_set 0x117D, OlivineCity_Area1_EventScript_Sailor_1
	call_if_unset 0x1177, OlivineCity_Area1_EventScript_Sailor_1
	msgbox OlivineCity_Area1_Text_Sailor_1, MSGBOX_NPC
	applymovement LOCALID_PLAYER, OlivineCity_Area1_Movement_Sailor_1
	delay 16
	end

OlivineCity_Area1_EventScript_Sailor_1::
	checkitem ITEM_SS_TICKET
	call_if_eq VAR_RESULT, 1, OlivineCity_Area1_EventScript_Sailor_2
	msgbox OlivineCity_Area1_Text_Sailor_2, MSGBOX_NPC
	applymovement LOCALID_PLAYER, OlivineCity_Area1_Movement_Sailor_1
	delay 16
	end

OlivineCity_Area1_EventScript_Sailor_2::
	special QuestLog_CutRecording
	call_if_eq VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, OlivineCity_Area1_EventScript_Sailor_3
	msgbox OlivineCity_Area1_Text_Sailor_3, MSGBOX_NPC
	applymovement LOCALID_PLAYER, OlivineCity_Area1_Movement_Sailor_1
	delay 16
	end

OlivineCity_Area1_Movement_Sailor_1::
	walk_up
	step_end

OlivineCity_Area1_EventScript_Sailor_3::
	call OlivineCity_Area1_EventScript_Sailor_4
	end

OlivineCity_Area1_EventScript_Sailor_4::
	faceplayer
	msgbox OlivineCity_Area1_Text_Sailor_4, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, OlivineCity_Area1_EventScript_Sailor_5
	msgbox OlivineCity_Area1_Text_Sailor_5, MSGBOX_NPC
	applymovement LOCALID_PLAYER, OlivineCity_Area1_Movement_Sailor_1
	delay 16
	end

OlivineCity_Area1_EventScript_Sailor_5::
	msgbox OlivineCity_Area1_Text_Sailor_6, MSGBOX_NPC
	applymovement LOCALID_PLAYER, OlivineCity_Area1_Movement_Sailor_2
	delay 128
	msgbox OlivineCity_Area1_Text_Sailor_7, MSGBOX_NPC
	call OlivineCity_Area1_EventScript_Sailor_6
	warp MAP_SS_AQUA_INTERIOR2, 2, 0x26C, 0x205
	release
	end

OlivineCity_Area1_EventScript_Sailor_6::
	call_if_set 0x1177, OlivineCity_Area1_EventScript_Sailor_7
	clearflag 0x1164
	clearflag 0x1166
	setflag 0x116A
	setflag 0x116B
	setflag 0x116C
	setflag 0x116D
	clearflag 0x1167
	clearflag 0x1168
	setflag 0x1169
	clearflag 0x1173
	clearflag 0x1176
	setflag 0x1171
	clearflag 0x1170
	clearflag 0x1172
	clearflag 0x1178
	clearflag 0x1179
	clearflag 0x117A
	return

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

OlivineCity_Area1_EventScript_Sailor_7::
	clearflag 0x1164
	clearflag 0x1173
	warp MAP_SS_AQUA_INTERIOR2, 2, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

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

OlivineCity_Area1_EventScript_Trigger1::
	call_if_set 0x117D, OlivineCity_Area1_EventScript_Trigger1_1
	call_if_unset 0x1177, OlivineCity_Area1_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, OlivineCity_Area1_Movement_Trigger1_1
	delay 1
	applymovement 2, OlivineCity_Area1_Movement_Trigger1_2
	delay 1
	msgbox OlivineCity_Area1_Text_Sailor_1, MSGBOX_NPC
	applymovement LOCALID_PLAYER, OlivineCity_Area1_Movement_Sailor_1
	delay 16
	end

@ ShinyGold fix: the S.S. Aqua sailor's step trigger. The hack points this branch 3 bytes into its code (the first
@ instruction was overwritten by the end of a text), so the engine reads "copylocal", skips an out-of-range
@ "gotostd" and runs on into the rest of the block. The port stopped at the "gotostd" and fell into the next
@ data, which ended the script, so the sailor let the player walk past to the ship at any time. This is the
@ hack's block again (with its first instruction), plus the boarding code it calls when the ship is in.
OlivineCity_Area1_EventScript_Trigger1_1::
	applymovement LOCALID_PLAYER, OlivineCity_Area1_Movement_Trigger1_1
	delay 1
	applymovement 2, OlivineCity_Area1_Movement_Trigger1_2
	delay 1
	special QuestLog_CutRecording
	call_if_eq VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, OlivineCity_Area1_EventScript_Trigger1_2
	msgbox OlivineCity_Area1_Text_Sailor_3, MSGBOX_NPC
	applymovement LOCALID_PLAYER, OlivineCity_Area1_Movement_Sailor_1
	delay 16
	end

@ The hack's 0x08803880 (ticket check) and the code it reaches, which the port never decoded.
OlivineCity_Area1_EventScript_Trigger1_2::
	checkitem ITEM_SS_TICKET
	call_if_eq VAR_RESULT, 1, OlivineCity_Area1_EventScript_Trigger1_3
	msgbox OlivineCity_Area1_Text_Sailor_2, MSGBOX_NPC
	applymovement LOCALID_PLAYER, OlivineCity_Area1_Movement_Sailor_1
	delay 16
	end

OlivineCity_Area1_EventScript_Trigger1_3::
	msgbox OlivineCity_Area1_Text_Sailor_4, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, OlivineCity_Area1_EventScript_Trigger1_4
	msgbox OlivineCity_Area1_Text_Sailor_5, MSGBOX_NPC
	applymovement LOCALID_PLAYER, OlivineCity_Area1_Movement_Sailor_1
	delay 16
	end

OlivineCity_Area1_EventScript_Trigger1_4::
	msgbox OlivineCity_Area1_Text_Sailor_6, MSGBOX_NPC
	applymovement LOCALID_PLAYER, OlivineCity_Area1_Movement_Trigger1_3
	delay 112
	msgbox OlivineCity_Area1_Text_Sailor_7, MSGBOX_NPC
	call OlivineCity_Area1_EventScript_Sailor_6
	warp MAP_SS_AQUA_INTERIOR2, 2, 0x26C, 0x205
	release
	end

OlivineCity_Area1_Movement_Trigger1_3::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

OlivineCity_Area1_Movement_Trigger1_1::
	face_left
	step_end

OlivineCity_Area1_Movement_Trigger1_2::
	face_right
	step_end

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
