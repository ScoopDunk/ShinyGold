CeladonCity_Interior17_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

CeladonCity_Interior17_EventScript_Man::
	msgbox CeladonCity_Interior17_Text_Man_1, MSGBOX_NPC
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, CeladonCity_Interior17_EventScript_Man_1
	call_if_eq VAR_0x8008, 1, CeladonCity_Interior17_EventScript_Man_2
	call_if_eq VAR_0x8008, 2, CeladonCity_Interior17_EventScript_Man_3
	call_if_eq VAR_0x8008, 3, CeladonCity_Interior17_EventScript_Man_4
	end

CeladonCity_Interior17_EventScript_Man_1::
	msgbox CeladonCity_Interior17_Text_Man_2, MSGBOX_NPC
	end

CeladonCity_Interior17_EventScript_Man_2::
	msgbox CeladonCity_Interior17_Text_Man_3, MSGBOX_NPC
	end

CeladonCity_Interior17_EventScript_Man_3::
	msgbox CeladonCity_Interior17_Text_Man_4, MSGBOX_NPC
	end

CeladonCity_Interior17_EventScript_Man_4::
	msgbox CeladonCity_Interior17_Text_Man_5, MSGBOX_NPC
	end

CeladonCity_Interior17_EventScript_Sign::
	msgbox CeladonCity_Interior17_Text_Sign, MSGBOX_AUTOCLOSE
	end
