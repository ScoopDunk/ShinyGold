MtSilver_Cave3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_Cave3_OnTransition
	.byte 0

MtSilver_Cave3_OnTransition::
	call_if_eq 0x4080, 1, MtSilver_Cave3_EventScript_OnTransition_1
	end

MtSilver_Cave3_EventScript_OnTransition_1::
	setflag 0x08B
	return

MtSilver_Cave3_EventScript_ItemUltraBall::
	finditem ITEM_ULTRA_BALL
	end

MtSilver_Cave3_EventScript_ItemMaxElixir::
	finditem ITEM_MAX_ELIXIR
	end

MtSilver_Cave3_EventScript_ItemProtein::
	finditem ITEM_PROTEIN
	end

MtSilver_Cave3_EventScript_ItemEscapeRope::
	finditem ITEM_ESCAPE_ROPE
	end
