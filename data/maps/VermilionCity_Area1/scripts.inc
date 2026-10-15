VermilionCity_Area1_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

VermilionCity_Area1_EventScript_Sailor::
	goto_if_set 0x117D, VermilionCity_Area1_EventScript_Sailor_1
	msgbox VermilionCity_Area1_Text_Sailor, MSGBOX_NPC
	applymovement LOCALID_PLAYER, OlivineCity_Area1_Movement_Sailor_1
	delay 16
	end

VermilionCity_Area1_EventScript_Sailor_1::
	special QuestLog_CutRecording
	goto_if_eq VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, VermilionCity_Area1_EventScript_Sailor_2
	msgbox OlivineCity_Area1_Text_Sailor_3, MSGBOX_NPC
	applymovement LOCALID_PLAYER, OlivineCity_Area1_Movement_Sailor_1
	delay 16
	release
	end

VermilionCity_Area1_EventScript_Sailor_2::
	call VermilionCity_Area1_EventScript_Sailor_3
	end

VermilionCity_Area1_EventScript_Sailor_3::
	faceplayer
	msgbox OlivineCity_Area1_Text_Sailor_4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 1, VermilionCity_Area1_EventScript_Sailor_4
	msgbox OlivineCity_Area1_Text_Sailor_5, MSGBOX_NPC
	applymovement LOCALID_PLAYER, OlivineCity_Area1_Movement_Sailor_1
	delay 16
	end

VermilionCity_Area1_EventScript_Sailor_4::
	msgbox OlivineCity_Area1_Text_Sailor_6, MSGBOX_NPC
	applymovement LOCALID_PLAYER, OlivineCity_Area1_Movement_Sailor_2
	delay 128
	msgbox OlivineCity_Area1_Text_Sailor_7, MSGBOX_NPC
	call VermilionCity_Area1_EventScript_Sailor_5
	warp MAP_SS_AQUA_INTERIOR2, 2, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

VermilionCity_Area1_EventScript_Sailor_5::
	clearflag 0x1164
	clearflag 0x1173
	setflag 0x1165
	warp MAP_SS_AQUA_INTERIOR2, 2, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

VermilionCity_Area1_EventScript_Boy::
	msgbox VermilionCity_Area1_Text_Boy, MSGBOX_NPC
	end

VermilionCity_Area1_EventScript_ItemIron::
	finditem ITEM_IRON
	end

VermilionCity_Area1_EventScript_Trigger1::
	applymovement LOCALID_PLAYER, OlivineCity_Area1_Movement_Trigger1_1
	delay 1
	applymovement 2, OlivineCity_Area1_Movement_Trigger1_2
	delay 1
	goto_if_set 0x117D, VermilionCity_Area1_EventScript_Trigger1_1
	msgbox VermilionCity_Area1_Text_Sailor, MSGBOX_NPC
	applymovement LOCALID_PLAYER, OlivineCity_Area1_Movement_Sailor_1
	delay 16
	end

VermilionCity_Area1_EventScript_Trigger1_1::
	applymovement LOCALID_PLAYER, OlivineCity_Area1_Movement_Trigger1_1
	delay 1
	applymovement 2, OlivineCity_Area1_Movement_Trigger1_2
	delay 1
	special QuestLog_CutRecording
	goto_if_eq VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, VermilionCity_Area1_EventScript_Trigger1_2
	msgbox OlivineCity_Area1_Text_Sailor_3, MSGBOX_NPC
	applymovement LOCALID_PLAYER, OlivineCity_Area1_Movement_Sailor_1
	delay 16
	end

VermilionCity_Area1_EventScript_Trigger1_2::
	call VermilionCity_Area1_EventScript_Trigger1_3
	end

VermilionCity_Area1_EventScript_Trigger1_3::
	msgbox OlivineCity_Area1_Text_Sailor_4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 1, VermilionCity_Area1_EventScript_Trigger1_4
	msgbox OlivineCity_Area1_Text_Sailor_5, MSGBOX_NPC
	applymovement LOCALID_PLAYER, OlivineCity_Area1_Movement_Sailor_1
	delay 16
	end

VermilionCity_Area1_EventScript_Trigger1_4::
	msgbox OlivineCity_Area1_Text_Sailor_6, MSGBOX_NPC
	applymovement LOCALID_PLAYER, VermilionCity_Area1_Movement_Trigger1
	delay 112
	msgbox OlivineCity_Area1_Text_Sailor_7, MSGBOX_NPC
	call VermilionCity_Area1_EventScript_Sailor_5
	warp MAP_SS_AQUA_INTERIOR2, 2, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

VermilionCity_Area1_Movement_Trigger1::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
