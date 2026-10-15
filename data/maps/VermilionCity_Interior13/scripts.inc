VermilionCity_Interior13_MapScripts::
	.byte 0

VermilionCity_Interior13_EventScript_Gentleman::
	lock
	faceplayer
	goto_if_set 0x117C, VermilionCity_Interior13_EventScript_Gentleman_1
	msgbox VermilionCity_Interior13_Text_Gentleman_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 1, VermilionCity_Interior13_EventScript_Gentleman_2
	msgbox VermilionCity_Interior13_Text_Gentleman_2, MSGBOX_NPC
	end

VermilionCity_Interior13_EventScript_Gentleman_1::
	msgbox VermilionCity_Interior13_Text_Gentleman_3, MSGBOX_NPC
	end

VermilionCity_Interior13_EventScript_Gentleman_2::
	msgbox VermilionCity_Interior13_Text_Gentleman_4, MSGBOX_NPC
	delay 16
	msgbox VermilionCity_Interior13_Text_Gentleman_5, MSGBOX_NPC
	setflag 0x117C
	giveitem ITEM_RARE_CANDY
	msgbox VermilionCity_Interior13_Text_Gentleman_6, MSGBOX_NPC
	end

VermilionCity_Interior13_EventScript_Beauty::
	msgbox VermilionCity_Interior13_Text_Beauty, MSGBOX_NPC
	end

VermilionCity_Interior13_EventScript_Chansey::
	msgbox VermilionCity_Interior13_Text_Chansey, MSGBOX_NPC
	waitse
	playmoncry SPECIES_CHANSEY, 0x200
	.byte 0xFF @ invalid opcode (script stops)

VermilionCity_Interior13_EventScript_Clefairy::
	msgbox VermilionCity_Interior13_Text_Clefairy, MSGBOX_AUTOCLOSE
	end

VermilionCity_Interior13_EventScript_FatMan::
	call_if_set 0x1189, VermilionCity_Interior13_EventScript_FatMan_1
	call_if_set 0x11CE, VermilionCity_Interior13_EventScript_FatMan_2
	call_if_set 0x1185, VermilionCity_Interior13_EventScript_FatMan_3
	msgbox VermilionCity_Interior13_Text_FatMan_1, MSGBOX_NPC
	end

VermilionCity_Interior13_EventScript_FatMan_1::
	msgbox VermilionCity_Interior13_Text_FatMan_2, MSGBOX_NPC
	end

VermilionCity_Interior13_EventScript_FatMan_2::
	msgbox VermilionCity_Interior13_Text_FatMan_3, MSGBOX_NPC
	msgbox VermilionCity_Interior13_Text_FatMan_4, MSGBOX_NPC
	applymovement 4, VermilionCity_Interior13_Movement_FatMan
	delay 48
	giveitem ITEM_METEORITE
	setflag 0x1189
	release
	end

VermilionCity_Interior13_EventScript_FatMan_3::
	msgbox VermilionCity_Interior13_Text_FatMan_3, MSGBOX_NPC
	end

VermilionCity_Interior13_Movement_FatMan::
	set_invisible
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

VermilionCity_Interior13_EventScript_Woman2::
	msgbox VermilionCity_Interior13_Text_Woman2, MSGBOX_NPC
	end

VermilionCity_Interior13_EventScript_Sign1::
	msgbox VermilionCity_Interior13_Text_Sign1, MSGBOX_AUTOCLOSE
	end

VermilionCity_Interior13_EventScript_Sign2::
	msgbox VermilionCity_Interior13_Text_Sign2, MSGBOX_AUTOCLOSE
	end
