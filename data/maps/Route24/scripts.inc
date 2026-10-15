Route24_MapScripts::
	.byte 0

Route24_EventScript_TeamRocketGrunt3::
	playbgm MUS_SILPH, 51
	msgbox Route24_Text_TeamRocketGrunt3_1, MSGBOX_NPC
	call SilphCo_Interior6_EventScript_Trigger1_1
	trainerbattle_earlyrival TRAINER_TEAM_ROCKET_GRUNT_3, 0, Route24_Text_TeamRocketGrunt3Defeat, Route24_Text_TeamRocketGrunt3Victory
	playbgm MUS_SILPH, 51
	setflag 0x11B9
	call SilphCo_Interior6_EventScript_Trigger1_2
	msgbox Route24_Text_TeamRocketGrunt3_2, MSGBOX_NPC
	playbgm MUS_NONE, 51
	msgbox Route24_Text_TeamRocketGrunt3_3, MSGBOX_NPC
	warp MAP_ROUTE24, 0, 0x26C, 0xFFFF
	.byte 0xFF @ invalid opcode (script stops)

Route24_EventScript_Trigger1::
	call_if_set 0x11B8, Route24_EventScript_Trigger1_1
	setflag 0x11B9
	release
	end

Route24_EventScript_Trigger1_1::
	release
	end
