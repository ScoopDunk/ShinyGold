CeladonCity_Interior7_MapScripts::
	.byte 0

CeladonCity_Interior7_EventScript_Sign1::
	lockall
	setvar VAR_0x8004, 3
	call_if_unset FLAG_TEMP_2, EventScript_GetElevatorFloor
	copyvar VAR_0x8005, VAR_ELEVATOR_FLOOR
	special DrawElevatorCurrentFloorWindow
	message Text_WantWhichFloor
	waitmessage
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, InitElevatorFloorSelectMenuPos
	switch VAR_RESULT
	case 0, CeladonCity_Interior7_EventScript_Sign1_1
	case 1, CeladonCity_Interior7_EventScript_Sign1_2
	case 2, CeladonCity_Interior7_EventScript_Sign1_3
	case 3, CeladonCity_Interior7_EventScript_Sign1_4
	case 4, CeladonCity_Interior7_EventScript_Sign1_5
	end

CeladonCity_Interior7_EventScript_Sign1_1::
	multichoicedefault 0, 0, MULTICHOICE_DEPT_STORE_ELEVATOR, 0, 0
	goto CeladonCity_Interior7_EventScript_Sign1_6

CeladonCity_Interior7_EventScript_Sign1_2::
	multichoicedefault 0, 0, MULTICHOICE_DEPT_STORE_ELEVATOR, 1, 0
	goto CeladonCity_Interior7_EventScript_Sign1_6

CeladonCity_Interior7_EventScript_Sign1_3::
	multichoicedefault 0, 0, MULTICHOICE_DEPT_STORE_ELEVATOR, 2, 0
	goto CeladonCity_Interior7_EventScript_Sign1_6

CeladonCity_Interior7_EventScript_Sign1_4::
	multichoicedefault 0, 0, MULTICHOICE_DEPT_STORE_ELEVATOR, 3, 0
	goto CeladonCity_Interior7_EventScript_Sign1_6

CeladonCity_Interior7_EventScript_Sign1_5::
	multichoicedefault 0, 0, MULTICHOICE_DEPT_STORE_ELEVATOR, 4, 0
	goto CeladonCity_Interior7_EventScript_Sign1_6

CeladonCity_Interior7_EventScript_Sign1_6::
	switch VAR_RESULT
	case 0, CeladonCity_Interior7_EventScript_Sign1_7
	case 1, CeladonCity_Interior7_EventScript_Sign1_8
	case 2, CeladonCity_Interior7_EventScript_Sign1_9
	case 3, CeladonCity_Interior7_EventScript_Sign1_10
	case 4, CeladonCity_Interior7_EventScript_Sign1_11
	case 5, CeladonCity_Interior7_EventScript_Sign1_12
	case 127, CeladonCity_Interior7_EventScript_Sign1_12
	end

CeladonCity_Interior7_EventScript_Sign1_7::
	setvar VAR_0x8006, 8
	setdynamicwarp MAP_CELADON_CITY_INTERIOR5, 6, 1
	goto_if_eq VAR_ELEVATOR_FLOOR, 8, CeladonCity_Interior7_EventScript_Sign1_12
	call CeladonCity_Interior7_EventScript_Sign1_13
	setvar VAR_ELEVATOR_FLOOR, 8
	goto CeladonCity_Interior7_EventScript_Sign1_12

CeladonCity_Interior7_EventScript_Sign1_8::
	setvar VAR_0x8006, 7
	setdynamicwarp MAP_CELADON_CITY_INTERIOR4, 6, 1
	goto_if_eq VAR_ELEVATOR_FLOOR, 7, CeladonCity_Interior7_EventScript_Sign1_12
	call CeladonCity_Interior7_EventScript_Sign1_13
	setvar VAR_ELEVATOR_FLOOR, 7
	goto CeladonCity_Interior7_EventScript_Sign1_12

CeladonCity_Interior7_EventScript_Sign1_9::
	setvar VAR_0x8006, 6
	setdynamicwarp MAP_CELADON_CITY_INTERIOR3, 6, 1
	goto_if_eq VAR_ELEVATOR_FLOOR, 6, CeladonCity_Interior7_EventScript_Sign1_12
	call CeladonCity_Interior7_EventScript_Sign1_13
	setvar VAR_ELEVATOR_FLOOR, 6
	goto CeladonCity_Interior7_EventScript_Sign1_12

CeladonCity_Interior7_EventScript_Sign1_10::
	setvar VAR_0x8006, 5
	setdynamicwarp MAP_CELADON_CITY_INTERIOR2, 6, 1
	goto_if_eq VAR_ELEVATOR_FLOOR, 5, CeladonCity_Interior7_EventScript_Sign1_12
	call CeladonCity_Interior7_EventScript_Sign1_13
	setvar VAR_ELEVATOR_FLOOR, 5
	goto CeladonCity_Interior7_EventScript_Sign1_12

CeladonCity_Interior7_EventScript_Sign1_11::
	setvar VAR_0x8006, 4
	setdynamicwarp MAP_CELADON_CITY_INTERIOR1, 6, 1
	goto_if_eq VAR_ELEVATOR_FLOOR, 4, CeladonCity_Interior7_EventScript_Sign1_12
	call CeladonCity_Interior7_EventScript_Sign1_13
	setvar VAR_ELEVATOR_FLOOR, 4
	goto CeladonCity_Interior7_EventScript_Sign1_12

CeladonCity_Interior7_EventScript_Sign1_12::
	special CloseElevatorCurrentFloorWindow
	releaseall
	end

CeladonCity_Interior7_EventScript_Sign1_13::
	special CloseElevatorCurrentFloorWindow
	closemessage
	waitse
	special AnimateElevator
	waitstate
	setflag FLAG_TEMP_2
	return
