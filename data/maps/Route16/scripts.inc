Route16_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route16_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route16_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route16_OnWarp
	.byte 0

Route16_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, Route16_EventScript_OnResume_1
	end

Route16_OnTransition::
	call_if_eq VAR_MAP_SCENE_ROUTE16, 1, Route16_EventScript_OnTransition_1
	end

Route16_EventScript_OnResume_1::
	removeobject VAR_LAST_TALKED
	return

Route16_EventScript_OnTransition_1::
	setflag FLAG_SYS_ON_CYCLING_ROAD
	return

Route16_OnWarp::
	map_script_2 VAR_MAP_SCENE_ROUTE16, 1, Route16_EventScript_WarpScene
	.2byte 0

Route16_EventScript_WarpScene::
	special ForcePlayerOntoBike
	end

Route16_EventScript_Sign::
	msgbox Route16_Text_Sign, MSGBOX_AUTOCLOSE
	end
