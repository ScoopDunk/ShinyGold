Route23_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route23_OnTransition
	.byte 0

Route23_OnTransition::
	clearflag 0x059
	setflag 0x058
	setvar 0x4064, 0
	setvar 0x4065, 0
	setvar 0x4066, 0
	setvar 0x4067, 0
	end

Route23_EventScript_Sign::
	msgbox Route23_Text_Sign, MSGBOX_AUTOCLOSE
	end
