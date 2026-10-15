TohjoFalls_Cave1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TohjoFalls_Cave1_OnTransition
	.byte 0

TohjoFalls_Cave1_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_NAVEL_ROCK_EXTERIOR
	end

TohjoFalls_Cave1_EventScript_ItemMoonStone::
	finditem ITEM_MOON_STONE
	end
