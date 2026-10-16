SilphCo_Interior7_MapScripts::
	@ ShinyGold: 1 entry with invalid type(s) 0x6C dropped (inert: the engine skips them)
	.byte 0

SilphCo_Interior7_EventScript_OldMan2::
	call_if_set 0x1192, SilphCo_Interior7_EventScript_OldMan2_1
	msgbox SilphCo_Interior7_Text_OldMan2_1, MSGBOX_NPC
	removeitem ITEM_SCANNER
	giveitem ITEM_POKEBLOCK_CASE
	setflag 0x1192
	msgbox SilphCo_Interior7_Text_OldMan2_2, MSGBOX_NPC
	end

SilphCo_Interior7_EventScript_OldMan2_1::
	msgbox SilphCo_Interior7_Text_OldMan2_3, MSGBOX_NPC
	end

SilphCo_Interior7_EventScript_WorkerM::
	call_if_set 0x1192, SilphCo_Interior7_EventScript_WorkerM_1
	msgbox SilphCo_Interior7_Text_WorkerM_1, MSGBOX_NPC
	end

SilphCo_Interior7_EventScript_WorkerM_1::
	msgbox SilphCo_Interior7_Text_WorkerM_1, MSGBOX_NPC
	msgbox SilphCo_Interior7_Text_WorkerM_2, MSGBOX_NPC
	end

SilphCo_Interior7_EventScript_Sign1::
	msgbox SilphCo_Interior7_Text_Sign1, MSGBOX_AUTOCLOSE
	end

SilphCo_Interior7_EventScript_Sign2::
	msgbox SilphCo_Interior7_Text_Sign2, MSGBOX_AUTOCLOSE
	end
