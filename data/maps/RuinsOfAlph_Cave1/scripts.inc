RuinsOfAlph_Cave1_MapScripts::
	.byte 0

RuinsOfAlph_Cave1_EventScript_CableClubReceptionist::
	msgbox RuinsOfAlph_Cave1_Text_CableClubReceptionist, MSGBOX_NPC
	end

RuinsOfAlph_Cave1_EventScript_Sign1::
	msgbox RuinsOfAlph_Cave1_Text_Sign1, MSGBOX_NPC
	end

RuinsOfAlph_Cave1_EventScript_Sign2::
	msgbox RuinsOfAlph_Cave1_Text_Sign2_1, MSGBOX_NPC
	warp MAP_UNUSED_G2_M63, 0, 0xFF02, 0xFFFF

RuinsOfAlph_Interior4_EventScript_Scientist2::
	msgbox RuinsOfAlph_Cave1_Text_Sign2_2, MSGBOX_NPC
	end
