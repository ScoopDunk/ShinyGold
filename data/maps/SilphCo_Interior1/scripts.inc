SilphCo_Interior1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SilphCo_Interior1_OnTransition
	.byte 0

SilphCo_Interior1_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SILPH_CO_1F
	end

SilphCo_Interior1_EventScript_WorkerF::
	call_if_set 0x118E, SilphCo_Interior1_EventScript_WorkerF_1
	call_if_set 0x118D, SilphCo_Interior1_EventScript_WorkerF_2
	msgbox SilphCo_Interior1_Text_WorkerF_1, MSGBOX_NPC
	end

SilphCo_Interior1_EventScript_WorkerF_1::
	msgbox SilphCo_Interior1_Text_WorkerF_1, MSGBOX_NPC
	end

SilphCo_Interior1_EventScript_WorkerF_2::
	msgbox SilphCo_Interior1_Text_WorkerF_2, MSGBOX_NPC
	end

SilphCo_Interior1_EventScript_Policeman::
	call_if_set 0x118F, SilphCo_Interior1_EventScript_Policeman_1
	setflag 0x118F
	setflag 0x1191
	clearflag 0x1190
	msgbox SilphCo_Interior1_Text_Policeman_1, MSGBOX_NPC
	end

SilphCo_Interior1_EventScript_Policeman_1::
	msgbox SilphCo_Interior1_Text_Policeman_2, MSGBOX_NPC
	end

SilphCo_Interior1_EventScript_Policeman2::
	msgbox SilphCo_Interior1_Text_WorkerF_2, MSGBOX_AUTOCLOSE
	end

SilphCo_Interior1_EventScript_Policeman3::
	msgbox SilphCo_Interior1_Text_Policeman3, MSGBOX_NPC
	end

SilphCo_Interior1_EventScript_Trigger::
	goto_if_set 0x118E, SilphCo_Interior1_EventScript_Trigger_1
	warp MAP_SILPH_CO_INTERIOR2, 0, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

SilphCo_Interior1_EventScript_Trigger_1::
	warp MAP_SILPH_CO_INTERIOR3, 0, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

SilphCo_Interior1_EventScript_Sign::
	msgbox SilphCo_Interior1_Text_Sign, MSGBOX_AUTOCLOSE
	end
