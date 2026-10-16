RockTunnel_Cave2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RockTunnel_Cave2_OnTransition
	.byte 0

RockTunnel_Cave2_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ROCK_TUNNEL_1F
	end

RockTunnel_Cave2_EventScript_ItemElixir::
	finditem ITEM_ELIXIR
	end

RockTunnel_Cave2_EventScript_ItemTm47::
	finditem ITEM_TM47
	end

RockTunnel_Cave2_EventScript_ItemXAccuracy::
	finditem ITEM_X_ACCURACY
	end

RockTunnel_Cave2_EventScript_ItemXDefend::
	finditem ITEM_X_DEFEND
	end
