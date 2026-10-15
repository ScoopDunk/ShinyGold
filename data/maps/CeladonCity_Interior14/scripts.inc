CeladonCity_Interior14_MapScripts::
	.byte 0

CeladonCity_Interior14_EventScript_Chef::
	msgbox CeladonCity_Interior14_Text_Chef, MSGBOX_NPC
	end

CeladonCity_Interior14_EventScript_FatMan::
	applymovement 2, CeladonCity_Interior14_Movement_FatMan
	delay 1
	msgbox CeladonCity_Interior14_Text_FatMan_1, MSGBOX_AUTOCLOSE
	delay 16
	msgbox CeladonCity_Interior14_Text_FatMan_2, MSGBOX_NPC
	end

CeladonCity_Interior14_Movement_FatMan::
	face_left
	step_end

CeladonCity_Interior14_EventScript_Woman3::
	applymovement 3, CeladonCity_Interior14_Movement_FatMan
	msgbox CeladonCity_Interior14_Text_Woman3_1, MSGBOX_AUTOCLOSE
	delay 16
	applymovement 3, CeladonCity_Interior14_Movement_Woman3
	msgbox CeladonCity_Interior14_Text_Woman3_2, MSGBOX_AUTOCLOSE
	end

CeladonCity_Interior14_Movement_Woman3::
	face_right
	step_end

CeladonCity_Interior14_EventScript_BaldingMan::
	applymovement 4, CeladonCity_Interior14_Movement_Woman3
	delay 1
	msgbox CeladonCity_Interior14_Text_BaldingMan_1, MSGBOX_AUTOCLOSE
	delay 16
	msgbox CeladonCity_Interior14_Text_BaldingMan_2, MSGBOX_NPC
	end

CeladonCity_Interior14_EventScript_FatMan2::
	applymovement 5, CeladonCity_Interior14_Movement_Woman3
	delay 1
	msgbox CeladonCity_Interior14_Text_FatMan2_1, MSGBOX_AUTOCLOSE
	delay 16
	msgbox CeladonCity_Interior14_Text_FatMan2_2, MSGBOX_NPC
	end

CeladonCity_Interior14_EventScript_ItemLeftovers::
	finditem ITEM_LEFTOVERS
	end
