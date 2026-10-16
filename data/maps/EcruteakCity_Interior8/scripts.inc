EcruteakCity_Interior8_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_Interior8_OnTransition
	.byte 0

@ Pure Gold: TIN TOWER 1F. The sage who blocks the way up is gone once the player has the RAINBOW WING, as in Gold
@ (pokegold TinTower1F: he disappears with EVENT_TEAM_ROCKET_DISBANDED, set when the RADIO TOWER director gives the
@ RAINBOW WING). ShinyGold had him say a custom line and walk away when talked to.
EcruteakCity_Interior8_OnTransition::
	checkitem ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, FALSE, EcruteakCity_Interior8_EventScript_OnTransitionEnd
	setflag 0x1040
EcruteakCity_Interior8_EventScript_OnTransitionEnd::
	end

EcruteakCity_Interior8_EventScript_OldMan1::
	msgbox EcruteakCity_Interior8_Text_OldMan1_1, MSGBOX_NPC
	end

EcruteakCity_Interior8_EventScript_Trigger::
	warp MAP_TIN_TOWER_UPPER_FLOORS, 0, 0x3402, 0x3900
	compare_var_to_var 0x0126, 0xFF02
	.byte 0xFF @ invalid opcode (script stops)
