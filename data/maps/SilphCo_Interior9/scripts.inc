SilphCo_Interior9_MapScripts::
	.byte 0

SilphCo_Interior9_EventScript_Trigger::
	call_if_eq VAR_RESULT, 1, SilphCo_Interior9_EventScript_Trigger_1
	nop
	warp MAP_SILPH_CO_INTERIOR5, 2, 0xFF02, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

SilphCo_Interior9_EventScript_Trigger_1::
	nop
	warp MAP_SILPH_CO_INTERIOR5, 4, 0xFF02, 0x21FF
	endram

SilphCo_Interior9_EventScript_Sign::
	@ ShinyGold: overlapping data duplicated from 0x088098B8
	call_if_eq VAR_RESULT, 1, SilphCo_Interior9_EventScript_Sign_1
	msgbox SilphCo_Interior8_Text_Sign_1, MSGBOX_AUTOCLOSE
	playbgm SE_DING_DONG, 51
	delay 48
	playbgm MUS_FUCHSIA, 51
	msgbox SilphCo_Interior8_Text_Sign_2, MSGBOX_AUTOCLOSE
	setvar VAR_RESULT, 1
	end

SilphCo_Interior9_EventScript_Sign_1::
	msgbox SilphCo_Interior8_Text_Sign_3, MSGBOX_AUTOCLOSE
	playbgm SE_DING_DONG, 51
	delay 48
	playbgm MUS_FUCHSIA, 51
	msgbox SilphCo_Interior8_Text_Sign_4, MSGBOX_AUTOCLOSE
	setvar VAR_RESULT, 0
	end
