SlowpokeWell_Cave2_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

SlowpokeWell_Cave2_EventScript_ItemTm18::
	finditem ITEM_TM18
	end

SlowpokeWell_Cave2_EventScript_PokeManiac::
	call_if_set 0x10D3, SlowpokeWell_Cave2_EventScript_PokeManiac_1
	msgbox SlowpokeWell_Cave2_Text_PokeManiac_1, MSGBOX_NPC
	lock
	faceplayer
	giveitem ITEM_KINGS_ROCK
	setflag 0x10D3
	msgbox SlowpokeWell_Cave2_Text_PokeManiac_2, MSGBOX_NPC
	end

SlowpokeWell_Cave2_EventScript_PokeManiac_1::
	msgbox SlowpokeWell_Cave2_Text_PokeManiac_2, MSGBOX_NPC
	end

SlowpokeWell_Cave2_EventScript_Gentleman::
	msgbox SlowpokeWell_Cave2_Text_Gentleman, MSGBOX_NPC
	end
