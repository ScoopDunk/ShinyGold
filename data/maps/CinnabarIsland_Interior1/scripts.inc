CinnabarIsland_Interior1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_Interior1_OnTransition
	.byte 0

CinnabarIsland_Interior1_OnTransition::
	call_if_eq 0x406A, 1, CinnabarIsland_Interior1_EventScript_OnTransition_1
	end

CinnabarIsland_Interior1_EventScript_OnTransition_1::
	setvar 0x406A, 2
	return

CinnabarIsland_Interior1_EventScript_Scientist::
	msgbox CinnabarIsland_Interior1_Text_Scientist, MSGBOX_NPC
	end

CinnabarIsland_Interior1_EventScript_Sign1::
	msgbox CinnabarIsland_Interior1_Text_Sign1, MSGBOX_SIGN
	end

CinnabarIsland_Interior1_EventScript_Sign2::
	msgbox CinnabarIsland_Interior1_Text_Sign2, MSGBOX_SIGN
	end

CinnabarIsland_Interior1_EventScript_Sign3::
	msgbox CinnabarIsland_Interior1_Text_Sign3, MSGBOX_SIGN
	end

CinnabarIsland_Interior1_EventScript_Sign4::
	msgbox CinnabarIsland_Interior1_Text_Sign4, MSGBOX_SIGN
	end
