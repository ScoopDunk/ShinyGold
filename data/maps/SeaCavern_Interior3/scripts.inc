SeaCavern_Interior3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SeaCavern_Interior3_OnTransition
	.byte 0

SeaCavern_Interior3_OnTransition::
	call EventScript_TryDarkenRuins
	end
