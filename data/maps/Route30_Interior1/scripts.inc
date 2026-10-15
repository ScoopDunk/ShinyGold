Route30_Interior1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route30_Interior1_OnTransition
	.byte 0

Route30_Interior1_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_FIVE_ISLAND_LOST_CAVE_ENTRANCE
	end

Route30_Interior1_EventScript_Chef::
	call_if_set 0x3EF, Route30_Interior1_EventScript_Chef_1
	msgbox Route30_Interior1_Text_Chef_1, MSGBOX_NPC
	giveitem ITEM_ORAN_BERRY
	setflag 0x3EF

Route30_Interior1_EventScript_Chef_1::
	msgbox Route30_Interior1_Text_Chef_2, MSGBOX_NPC
	release
	end
