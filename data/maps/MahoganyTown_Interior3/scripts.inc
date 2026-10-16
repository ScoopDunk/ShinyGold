MahoganyTown_Interior3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MahoganyTown_Interior3_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MahoganyTown_Interior3_OnTransition::
	@ ShinyGold fix: the hack had this Pokémon Center set the other town's fly flag and heal point (Teleport
	@ went to the other town, Fly to Blackthorn opened before the Ice Path).
	setworldmapflag FLAG_WORLD_MAP_ROUTE10_POKEMON_CENTER_1F
	setrespawn HEAL_LOCATION_MAHOGANY_TOWN_2
	end

MahoganyTown_Interior3_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

MahoganyTown_Interior3_EventScript_Boy::
	msgbox MahoganyTown_Interior3_Text_Boy, MSGBOX_NPC
	end

MahoganyTown_Interior3_EventScript_BaldingMan::
	msgbox MahoganyTown_Interior3_Text_BaldingMan, MSGBOX_NPC
	end

MahoganyTown_Interior3_EventScript_Lass::
	msgbox MahoganyTown_Interior3_Text_Lass, MSGBOX_NPC
	end

MahoganyTown_Interior3_EventScript_Youngster::
	msgbox MahoganyTown_Interior3_Text_Youngster, MSGBOX_NPC
	end

MahoganyTown_Interior3_EventScript_Clipboard::
	lock
	msgbox MahoganyTown_Interior3_Text_Clipboard
	release
	end

MahoganyTown_Interior3_EventScript_Trigger1::
	call_if_set 0x1372, MtSilver_Interior1_EventScript_Trigger1
	clearflag FLAG_WORLD_MAP_ROUTE4_POKEMON_CENTER_1F
	call MtSilver_Interior1_EventScript_Trigger1
	end
