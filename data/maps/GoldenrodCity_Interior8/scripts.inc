GoldenrodCity_Interior8_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

GoldenrodCity_Interior8_EventScript_CableClubReceptionist::
	msgbox GoldenrodCity_Interior8_Text_CableClubReceptionist, MSGBOX_NPC
	end

GoldenrodCity_Interior8_EventScript_LittleBoy::
	msgbox GoldenrodCity_Interior8_Text_LittleBoy, MSGBOX_NPC
	end

GoldenrodCity_Interior8_EventScript_Woman3::
	msgbox GoldenrodCity_Interior8_Text_Woman3, MSGBOX_NPC
	end

GoldenrodCity_Interior8_EventScript_Gentleman::
	msgbox GoldenrodCity_Interior8_Text_Gentleman, MSGBOX_NPC
	end

GoldenrodCity_Interior8_EventScript_Trigger::
	setvar VAR_RESULT, 1
	release
	end

GoldenrodCity_Interior8_EventScript_Sign::
	msgbox GoldenrodCity_Interior8_Text_Sign, MSGBOX_AUTOCLOSE
	end
