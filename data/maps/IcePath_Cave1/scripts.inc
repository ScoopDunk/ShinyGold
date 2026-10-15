IcePath_Cave1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IcePath_Cave1_OnTransition
	.byte 0

IcePath_Cave1_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SIX_ISLAND_DOTTED_HOLE_1F
	end

IcePath_Cave1_EventScript_ItemHm07::
	finditem ITEM_HM07
	end

IcePath_Cave1_EventScript_ItemHpUp::
	finditem ITEM_HP_UP
	end

IcePath_Cave1_EventScript_ItemPpUp::
	finditem ITEM_PP_UP
	end

IcePath_Cave1_EventScript_ItemBlueFlute::
	finditem ITEM_BLUE_FLUTE
	end

IcePath_Cave1_EventScript_Trigger1::
	call_if_set 0x114A, IcePath_Cave1_EventScript_Trigger1_1
	setflag 0x112E
	setflag 0x112F
	setflag 0x1130
	setflag 0x1131
	clearflag 0x040
	clearflag 0x041
	clearflag 0x042
	clearflag 0x043
	release
	end

IcePath_Cave1_EventScript_Trigger1_1::
	release
	end
