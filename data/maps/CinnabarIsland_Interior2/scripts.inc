CinnabarIsland_Interior2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_Interior2_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

CinnabarIsland_Interior2_OnTransition::
	setrespawn HEAL_LOCATION_CINNABAR_ISLAND
	end

CinnabarIsland_Interior2_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

CinnabarIsland_Interior2_EventScript_FatMan::
	msgbox CinnabarIsland_Interior2_Text_FatMan, MSGBOX_NPC
	end

CinnabarIsland_Interior2_EventScript_CooltrainerF::
	msgbox CinnabarIsland_Interior2_Text_CooltrainerF, MSGBOX_NPC
	end

CinnabarIsland_Interior2_EventScript_Youngster::
	msgbox CinnabarIsland_Interior2_Text_Youngster, MSGBOX_NPC
	end

CinnabarIsland_Interior2_EventScript_Bill::
	lock
	faceplayer
	msgbox CinnabarIsland_Interior2_Text_Bill_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 0, CinnabarIsland_Interior2_EventScript_Bill_1
	msgbox CinnabarIsland_Interior2_Text_Bill_2
	closemessage
	playbgm MUS_FOLLOW_ME, 1
	savebgm MUS_FOLLOW_ME
	setflag FLAG_DONT_TRANSITION_MUSIC
	setflag 0x0A2
	delay 20
	call_if_eq VAR_FACING, 1, CinnabarIsland_Interior2_EventScript_Bill_2
	call_if_eq VAR_FACING, 4, CinnabarIsland_Interior2_EventScript_Bill_3
	call_if_eq VAR_FACING, 3, CinnabarIsland_Interior2_EventScript_Bill_4
	removeobject 7
	setvar 0x408A, 1
	clearflag 0x062
	warp MAP_CINNABAR_ISLAND, 14, 11
	waitstate
	release
	end

CinnabarIsland_Interior2_EventScript_Bill_1::
	msgbox CinnabarIsland_Interior2_Text_Bill_3
	release
	end

CinnabarIsland_Interior2_EventScript_Bill_2::
	applymovement 7, CinnabarIsland_Interior2_Movement_Bill_1
	applymovement LOCALID_PLAYER, CinnabarIsland_Interior2_Movement_Bill_2
	waitmovement 0
	return

CinnabarIsland_Interior2_EventScript_Bill_3::
	applymovement 7, CinnabarIsland_Interior2_Movement_Bill_3
	applymovement LOCALID_PLAYER, CinnabarIsland_Interior2_Movement_Bill_4
	waitmovement 0
	return

CinnabarIsland_Interior2_EventScript_Bill_4::
	applymovement 7, CinnabarIsland_Interior2_Movement_Bill_1
	applymovement LOCALID_PLAYER, CinnabarIsland_Interior2_Movement_Bill_5
	waitmovement 0
	return

CinnabarIsland_Interior2_Movement_Bill_1::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	delay_8
	set_invisible
	step_end

CinnabarIsland_Interior2_Movement_Bill_2::
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	delay_16
	walk_down
	step_end

CinnabarIsland_Interior2_Movement_Bill_3::
	walk_up
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	delay_8
	set_invisible
	step_end

CinnabarIsland_Interior2_Movement_Bill_4::
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	delay_8
	walk_down
	delay_8
	set_invisible
	step_end

CinnabarIsland_Interior2_Movement_Bill_5::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	delay_16
	walk_down
	step_end
