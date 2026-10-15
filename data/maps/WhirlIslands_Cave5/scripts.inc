WhirlIslands_Cave5_MapScripts::
	.byte 0

WhirlIslands_Cave5_EventScript_ItemMaxElixir::
	finditem ITEM_MAX_ELIXIR
	end

WhirlIslands_Cave5_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE
	end

WhirlIslands_Cave5_EventScript_ItemFullRestore::
	finditem ITEM_FULL_RESTORE
	end

WhirlIslands_Cave5_EventScript_Trigger::
	call_if_set 0x112D, WhirlIslands_Cave5_EventScript_Trigger_1
	checkitem ITEM_MYSTIC_TICKET
	call_if_eq VAR_RESULT, 1, WhirlIslands_Cave5_EventScript_Trigger_2
	setflag 0x112C
	end

WhirlIslands_Cave5_EventScript_Trigger_1::
	release
	end

WhirlIslands_Cave5_EventScript_Trigger_2::
	clearflag 0x112C
	release
	end
