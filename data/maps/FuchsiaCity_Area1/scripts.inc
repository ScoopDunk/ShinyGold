FuchsiaCity_Area1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_Area1_OnTransition
	.byte 0

FuchsiaCity_Area1_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SAFARI_ZONE_CENTER
	end

FuchsiaCity_Area1_EventScript_ItemElixir::
	finditem ITEM_ELIXIR
	end

FuchsiaCity_Area1_EventScript_ItemUltraBall::
	finditem ITEM_ULTRA_BALL
	end

FuchsiaCity_Area1_EventScript_ItemLeafStone::
	finditem ITEM_LEAF_STONE
	end

FuchsiaCity_Area1_EventScript_ItemMaxElixir::
	finditem ITEM_MAX_ELIXIR
	end

FuchsiaCity_Area1_EventScript_Sign1::
	msgbox FuchsiaCity_Area1_Text_Sign1, MSGBOX_SIGN
	end

FuchsiaCity_Area1_EventScript_Sign2::
	msgbox FuchsiaCity_Area1_Text_Sign2, MSGBOX_SIGN
	end

FuchsiaCity_Area1_EventScript_Sign3::
	msgbox FuchsiaCity_Area1_Text_Sign3, MSGBOX_AUTOCLOSE
	end
