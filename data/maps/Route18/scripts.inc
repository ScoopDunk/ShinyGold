Route18_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route18_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route18_OnWarp
	.byte 0

Route18_OnTransition::
	call_if_eq VAR_MAP_SCENE_ROUTE16, 1, Route18_EventScript_OnTransition_1
	end

Route18_EventScript_OnTransition_1::
	setflag FLAG_SYS_ON_CYCLING_ROAD
	return

Route18_OnWarp::
	map_script_2 VAR_MAP_SCENE_ROUTE16, 1, Route18_EventScript_WarpScene
	.2byte 0

Route18_EventScript_WarpScene::
	special ForcePlayerOntoBike
	end

Route18_EventScript_BirdKeeperBob::
	trainerbattle_single TRAINER_BIRD_KEEPER_BOB, Route18_Text_BirdKeeperBobIntro, Route18_Text_BirdKeeperBobDefeat
	msgbox Route18_Text_BirdKeeperBob, MSGBOX_AUTOCLOSE
	end

Route18_EventScript_BirdKeeperBoris::
	trainerbattle_single TRAINER_BIRD_KEEPER_BORIS, Route18_Text_BirdKeeperBorisIntro, Route18_Text_BirdKeeperBorisDefeat
	msgbox Route18_Text_BirdKeeperBoris, MSGBOX_AUTOCLOSE
	end

Route18_EventScript_Sign::
	msgbox Route18_Text_Sign, MSGBOX_AUTOCLOSE
	end
