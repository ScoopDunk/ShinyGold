MaidensPeakDis_Interior4_MapScripts::
	.byte 0

MaidensPeakDis_Interior4_EventScript_Sign::
	lockall
	goto_if_unset 0x2A5, MaidensPeakDis_Interior4_EventScript_Sign_1
	setvar VAR_0x8004, 2
	call_if_unset FLAG_TEMP_2, EventScript_GetElevatorFloor
	copyvar VAR_0x8005, VAR_ELEVATOR_FLOOR
	special DrawElevatorCurrentFloorWindow
	message Text_WantWhichFloor
	waitmessage
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, InitElevatorFloorSelectMenuPos
	switch VAR_RESULT
	case 0, MaidensPeakDis_Interior4_EventScript_Sign_2
	case 1, MaidensPeakDis_Interior4_EventScript_Sign_3
	case 2, MaidensPeakDis_Interior4_EventScript_Sign_4
	end

MaidensPeakDis_Interior4_EventScript_Sign_1::
	msgbox MaidensPeakDis_Interior4_Text_Sign
	releaseall
	end

MaidensPeakDis_Interior4_EventScript_Sign_2::
	multichoicedefault 0, 0, MULTICHOICE_ROCKET_HIDEOUT_ELEVATOR, 0, 0
	goto MaidensPeakDis_Interior4_EventScript_Sign_5

MaidensPeakDis_Interior4_EventScript_Sign_3::
	multichoicedefault 0, 0, MULTICHOICE_ROCKET_HIDEOUT_ELEVATOR, 1, 0
	goto MaidensPeakDis_Interior4_EventScript_Sign_5

MaidensPeakDis_Interior4_EventScript_Sign_4::
	multichoicedefault 0, 0, MULTICHOICE_ROCKET_HIDEOUT_ELEVATOR, 2, 0
	goto MaidensPeakDis_Interior4_EventScript_Sign_5

MaidensPeakDis_Interior4_EventScript_Sign_5::
	switch VAR_RESULT
	case 0, MaidensPeakDis_Interior4_EventScript_Sign_6
	case 1, MaidensPeakDis_Interior4_EventScript_Sign_7
	case 2, MaidensPeakDis_Interior4_EventScript_Sign_8
	case 3, MaidensPeakDis_Interior4_EventScript_Sign_9
	case 127, MaidensPeakDis_Interior4_EventScript_Sign_9
	end

MaidensPeakDis_Interior4_EventScript_Sign_6::
	setvar VAR_0x8006, 3
	setdynamicwarp MAP_UNUSED_ROCKET_HIDEOUT_B1F, 24, 25
	goto_if_eq VAR_ELEVATOR_FLOOR, 3, MaidensPeakDis_Interior4_EventScript_Sign_9
	call MaidensPeakDis_Interior4_EventScript_Sign_10
	setvar VAR_ELEVATOR_FLOOR, 3
	goto MaidensPeakDis_Interior4_EventScript_Sign_9

MaidensPeakDis_Interior4_EventScript_Sign_7::
	setvar VAR_0x8006, 2
	setdynamicwarp MAP_UNUSED_ROCKET_HIDEOUT_B2F, 28, 16
	goto_if_eq VAR_ELEVATOR_FLOOR, 2, MaidensPeakDis_Interior4_EventScript_Sign_9
	call MaidensPeakDis_Interior4_EventScript_Sign_10
	setvar VAR_ELEVATOR_FLOOR, 2
	goto MaidensPeakDis_Interior4_EventScript_Sign_9

MaidensPeakDis_Interior4_EventScript_Sign_8::
	setvar VAR_0x8006, 0
	setdynamicwarp MAP_UNUSED_ROCKET_HIDEOUT_B4F, 20, 23
	goto_if_eq VAR_ELEVATOR_FLOOR, 0, MaidensPeakDis_Interior4_EventScript_Sign_9
	call MaidensPeakDis_Interior4_EventScript_Sign_10
	setvar VAR_ELEVATOR_FLOOR, 0
	goto MaidensPeakDis_Interior4_EventScript_Sign_9

MaidensPeakDis_Interior4_EventScript_Sign_9::
	special CloseElevatorCurrentFloorWindow
	releaseall
	end

MaidensPeakDis_Interior4_EventScript_Sign_10::
	special CloseElevatorCurrentFloorWindow
	closemessage
	waitse
	special AnimateElevator
	waitstate
	setflag FLAG_TEMP_2
	return
