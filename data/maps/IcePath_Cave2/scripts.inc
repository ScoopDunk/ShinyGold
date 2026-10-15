IcePath_Cave2_MapScripts::
	.byte 0

IcePath_Cave2_EventScript_ItemIron::
	finditem ITEM_IRON
	end

IcePath_Cave2_EventScript_ItemMaxPotion::
	finditem ITEM_MAX_POTION
	end

IcePath_Cave2_EventScript_Trigger1::
	call_if_unset 0x040, IcePath_Cave2_EventScript_Trigger1_1
	clearflag 0x112E
	call IcePath_Cave2_EventScript_Trigger1_1
	end

IcePath_Cave2_EventScript_Trigger1_1::
	call_if_unset 0x041, IcePath_Cave2_EventScript_Trigger1_2
	clearflag 0x112F
	call IcePath_Cave2_EventScript_Trigger1_2
	end

IcePath_Cave2_EventScript_Trigger1_2::
	call_if_unset 0x042, IcePath_Cave2_EventScript_Trigger1_3
	clearflag 0x1130
	call IcePath_Cave2_EventScript_Trigger1_3
	end

IcePath_Cave2_EventScript_Trigger1_3::
	call_if_unset 0x043, IcePath_Cave2_EventScript_Trigger1_4
	clearflag 0x1131
	call IcePath_Cave2_EventScript_Trigger1_4
	end

IcePath_Cave2_EventScript_Trigger1_4::
	release
	end

IcePath_Cave2_EventScript_Trigger17::
	@ ShinyGold: overlapping data duplicated from 0x0878BB90
	gotostd MSGBOX_NPC
