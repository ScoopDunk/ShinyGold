OlivineCity_Interior5_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OlivineCity_Interior5_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

OlivineCity_Interior5_EventScript_FatMan::
	msgbox OlivineCity_Interior5_Text_FatMan, MSGBOX_NPC
	end

OlivineCity_Interior5_EventScript_WorkerF::
	msgbox OlivineCity_Interior5_Text_WorkerF, MSGBOX_NPC
	end

OlivineCity_Interior5_EventScript_Fisher::
	msgbox OlivineCity_Interior5_Text_Fisher, MSGBOX_NPC
	end
