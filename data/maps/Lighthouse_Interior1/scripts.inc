Lighthouse_Interior1_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerTower_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Lighthouse_Interior1_OnFrame
	.byte 0

Lighthouse_Interior1_OnFrame::
	map_script_2 VAR_TEMP_2, 0, TrainerTower_EventScript_EnterFloor
	.2byte 0

Lighthouse_Interior1_EventScript_Sign::
	lockall
	setvar VAR_0x8004, 6
	call_if_unset FLAG_TEMP_2, EventScript_GetElevatorFloor
	copyvar VAR_0x8005, VAR_ELEVATOR_FLOOR
	special DrawElevatorCurrentFloorWindow
	message Text_WantWhichFloor
	waitmessage
	setvar VAR_0x8004, 6
	specialvar VAR_RESULT, InitElevatorFloorSelectMenuPos
	switch VAR_RESULT
	case 0, Lighthouse_Interior1_EventScript_Sign_1
	case 1, Lighthouse_Interior1_EventScript_Sign_2
	end

Lighthouse_Interior1_EventScript_Sign_1::
	multichoicedefault 0, 0, MULTICHOICE_ROOFTOP_B1F, 0, 0
	goto Lighthouse_Interior1_EventScript_Sign_3

Lighthouse_Interior1_EventScript_Sign_2::
	multichoicedefault 0, 0, MULTICHOICE_ROOFTOP_B1F, 1, 0
	goto Lighthouse_Interior1_EventScript_Sign_3

Lighthouse_Interior1_EventScript_Sign_3::
	switch VAR_RESULT
	case 0, Lighthouse_Interior1_EventScript_Sign_4
	case 1, Lighthouse_Interior1_EventScript_Sign_5
	case 2, Lighthouse_Interior1_EventScript_Sign_6
	case 127, Lighthouse_Interior1_EventScript_Sign_6
	end

Lighthouse_Interior1_EventScript_Sign_4::
	goto Lighthouse_Interior1_EventScript_Sign_6

Lighthouse_Interior1_EventScript_Sign_5::
	setvar VAR_0x8006, 3
	setdynamicwarp MAP_VERMILION_CITY_INTERIOR9, 17, 8
	goto_if_eq VAR_ELEVATOR_FLOOR, 3, Lighthouse_Interior1_EventScript_Sign_6
	call Lighthouse_Interior1_EventScript_Sign_7
	setvar VAR_ELEVATOR_FLOOR, 3
	special CloseElevatorCurrentFloorWindow
	delay 25
	applymovement LOCALID_PLAYER, Lighthouse_Interior1_Movement_Sign
	waitmovement 0
	warp MAP_VERMILION_CITY_INTERIOR9, 17, 8
	waitstate
	releaseall
	end

Lighthouse_Interior1_EventScript_Sign_6::
	special CloseElevatorCurrentFloorWindow
	releaseall
	end

Lighthouse_Interior1_EventScript_Sign_7::
	special CloseElevatorCurrentFloorWindow
	closemessage
	waitse
	special AnimateElevator
	waitstate
	setflag FLAG_TEMP_2
	return

Lighthouse_Interior1_Movement_Sign::
	walk_in_place_faster_down
	delay_16
	walk_down
	walk_right
	walk_right
	walk_down
	step_end
