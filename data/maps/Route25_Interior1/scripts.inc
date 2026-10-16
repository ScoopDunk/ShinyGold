Route25_Interior1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route25_Interior1_OnTransition
	.byte 0

Route25_Interior1_OnTransition::
	call_if_unset 0x233, Route25_Interior1_EventScript_OnTransition_1
	call_if_set 0x234, Route25_Interior1_EventScript_OnTransition_2
	end

Route25_Interior1_EventScript_OnTransition_1::
	clearflag 0x032
	setobjectxyperm 1, 3, 3
	return

Route25_Interior1_EventScript_OnTransition_2::
	setflag FLAG_TEMP_3
	return

Route25_Interior1_EventScript_OldMan2::
	.byte 0xE3 @ invalid opcode (script stops)

Route25_Interior1_EventScript_OldMan22::
	call_if_set 0x11CA, Route25_Interior1_EventScript_OldMan22_1
	call_if_set 0x11C9, Route25_Interior1_EventScript_OldMan22_5
	call_if_set 0x11C8, Route25_Interior1_EventScript_OldMan22_6
	call_if_set 0x11C7, Route25_Interior1_EventScript_OldMan22_7
	call_if_set 0x11C6, Route25_Interior1_EventScript_OldMan22_8
	call_if_set 0x11C5, Route25_Interior1_EventScript_OldMan22_9
	setflag 0x11C5
	msgbox Route25_Interior1_Text_OldMan22_1, MSGBOX_NPC
	call Route25_Interior1_EventScript_OldMan22_9
	end

Route25_Interior1_EventScript_OldMan22_1::
	msgbox Route25_Interior1_Text_OldMan22_2, MSGBOX_NPC
	end

Route25_Interior1_EventScript_OldMan22_5::
	msgbox Route25_Interior1_Text_OldMan22_8, MSGBOX_NPC
	msgbox Route25_Interior1_Text_OldMan22_4, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route25_Interior1_EventScript_OldMan22_13
	msgbox Route25_Interior1_Text_OldMan22_5, MSGBOX_NPC
	end

Route25_Interior1_EventScript_OldMan22_6::
	msgbox Route25_Interior1_Text_OldMan22_9, MSGBOX_NPC
	msgbox Route25_Interior1_Text_OldMan22_4, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route25_Interior1_EventScript_OldMan22_14
	msgbox Route25_Interior1_Text_OldMan22_5, MSGBOX_NPC
	end

Route25_Interior1_EventScript_OldMan22_7::
	msgbox Route25_Interior1_Text_OldMan22_10, MSGBOX_NPC
	msgbox Route25_Interior1_Text_OldMan22_4, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route25_Interior1_EventScript_OldMan22_15
	msgbox Route25_Interior1_Text_OldMan22_5, MSGBOX_NPC
	end

Route25_Interior1_EventScript_OldMan22_8::
	msgbox Route25_Interior1_Text_OldMan22_11, MSGBOX_NPC
	msgbox Route25_Interior1_Text_OldMan22_4, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route25_Interior1_EventScript_OldMan22_16
	msgbox Route25_Interior1_Text_OldMan22_5, MSGBOX_NPC
	end

Route25_Interior1_EventScript_OldMan22_9::
	msgbox Route25_Interior1_Text_OldMan22_12, MSGBOX_NPC
	msgbox Route25_Interior1_Text_OldMan22_4, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, Route25_Interior1_EventScript_OldMan22_17
	msgbox Route25_Interior1_Text_OldMan22_5, MSGBOX_NPC
	end

Route25_Interior1_EventScript_OldMan22_13::
	msgbox Route25_Interior1_Text_OldMan22_13, MSGBOX_NPC
	setvar VAR_RESORT_GORGEOUS_REQUESTED_MON, 172
	copyvar VAR_0x8004, VAR_RESORT_GORGEOUS_REQUESTED_MON
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	call_if_eq VAR_RESULT, 1, Route25_Interior1_EventScript_OldMan22_21
	msgbox Route25_Interior1_Text_OldMan22_5, MSGBOX_NPC
	end

Route25_Interior1_EventScript_OldMan22_14::
	msgbox Route25_Interior1_Text_OldMan22_13, MSGBOX_NPC
	setvar VAR_RESORT_GORGEOUS_REQUESTED_MON, 58
	copyvar VAR_0x8004, VAR_RESORT_GORGEOUS_REQUESTED_MON
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	call_if_eq VAR_RESULT, 1, Route25_Interior1_EventScript_OldMan22_22
	msgbox Route25_Interior1_Text_OldMan22_5, MSGBOX_NPC
	end

Route25_Interior1_EventScript_OldMan22_15::
	msgbox Route25_Interior1_Text_OldMan22_13, MSGBOX_NPC
	setvar VAR_RESORT_GORGEOUS_REQUESTED_MON, 120
	copyvar VAR_0x8004, VAR_RESORT_GORGEOUS_REQUESTED_MON
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	call_if_eq VAR_RESULT, 1, Route25_Interior1_EventScript_OldMan22_23
	msgbox Route25_Interior1_Text_OldMan22_5, MSGBOX_NPC
	end

Route25_Interior1_EventScript_OldMan22_16::
	msgbox Route25_Interior1_Text_OldMan22_13, MSGBOX_NPC
	setvar VAR_RESORT_GORGEOUS_REQUESTED_MON, 43
	copyvar VAR_0x8004, VAR_RESORT_GORGEOUS_REQUESTED_MON
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	call_if_eq VAR_RESULT, 1, Route25_Interior1_EventScript_OldMan22_24
	special GetHeracrossSizeRecordInfo
	msgbox Route25_Interior1_Text_OldMan22_5, MSGBOX_NPC
	end

Route25_Interior1_EventScript_OldMan22_17::
	msgbox Route25_Interior1_Text_OldMan22_13, MSGBOX_NPC
	setvar VAR_RESORT_GORGEOUS_REQUESTED_MON, 108
	copyvar VAR_0x8004, VAR_RESORT_GORGEOUS_REQUESTED_MON
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	call_if_eq VAR_RESULT, 1, Route25_Interior1_EventScript_OldMan22_25
	msgbox Route25_Interior1_Text_OldMan22_5, MSGBOX_NPC
	end

Route25_Interior1_EventScript_OldMan22_21::
	setflag 0x11CA
	msgbox Route25_Interior1_Text_OldMan22_18, MSGBOX_NPC
	msgbox Route25_Interior1_Text_OldMan22_15, MSGBOX_NPC
	giveitem ITEM_THUNDER_STONE
	release
	end

Route25_Interior1_EventScript_OldMan22_22::
	setflag 0x11C9
	msgbox Route25_Interior1_Text_OldMan22_19, MSGBOX_NPC
	msgbox Route25_Interior1_Text_OldMan22_15, MSGBOX_NPC
	giveitem ITEM_FIRE_STONE
	release
	end

Route25_Interior1_EventScript_OldMan22_23::
	setflag 0x11C8
	msgbox Route25_Interior1_Text_OldMan22_20, MSGBOX_NPC
	msgbox Route25_Interior1_Text_OldMan22_15, MSGBOX_NPC
	giveitem ITEM_WATER_STONE
	release
	end

Route25_Interior1_EventScript_OldMan22_24::
	setflag 0x11C7
	msgbox Route25_Interior1_Text_OldMan22_21, MSGBOX_NPC
	msgbox Route25_Interior1_Text_OldMan22_15, MSGBOX_NPC
	giveitem ITEM_LEAF_STONE
	release
	end

Route25_Interior1_EventScript_OldMan22_25::
	setflag 0x11C6
	msgbox Route25_Interior1_Text_OldMan22_22, MSGBOX_NPC
	msgbox Route25_Interior1_Text_OldMan22_15, MSGBOX_NPC
	giveitem ITEM_EVERSTONE
	release
	end
