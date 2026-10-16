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
	warp MAP_RUINS_OF_ALPH_INNER_CHAMBER, 0, 0xFF02, 0xFFFF
	@ ShinyGold fix: the engine keeps running a script during the warp fade, so the hack's leftover bytes
	@ that followed this warp executed (garbage calls, stray text, RAM writes). The script now ends here.
	end

RuinsOfAlph_Interior4_EventScript_Scientist2::
	msgbox RuinsOfAlph_Cave1_Text_Sign2_2, MSGBOX_NPC
	end
