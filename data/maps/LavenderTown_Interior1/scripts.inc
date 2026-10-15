LavenderTown_Interior1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_Interior1_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LavenderTown_Interior1_OnTransition::
	setrespawn HEAL_LOCATION_LAVENDER_TOWN
	end

LavenderTown_Interior1_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

LavenderTown_Interior1_EventScript_WorkerF::
	msgbox LavenderTown_Interior1_Text_WorkerF, MSGBOX_NPC
	end

LavenderTown_Interior1_EventScript_Gentleman::
	msgbox LavenderTown_Interior1_Text_Gentleman, MSGBOX_NPC
	end

LavenderTown_Interior1_EventScript_Youngster::
	call_if_set 0x1185, LavenderTown_Interior1_EventScript_Youngster_1
	msgbox LavenderTown_Interior1_Text_Youngster_1, MSGBOX_NPC
	end

LavenderTown_Interior1_EventScript_Youngster_1::
	msgbox LavenderTown_Interior1_Text_Youngster_2, MSGBOX_NPC
	end
