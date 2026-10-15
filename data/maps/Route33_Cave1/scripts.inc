Route33_Cave1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route33_Cave1_OnTransition
	.byte 0

Route33_Cave1_OnTransition::
	call EventScript_TryDarkenRuins
	end
