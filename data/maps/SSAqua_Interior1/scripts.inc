SSAqua_Interior1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SSAqua_Interior1_OnTransition
	.byte 0

SSAqua_Interior1_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SSANNE_EXTERIOR
	end

SSAqua_Interior1_EventScript_SsAnne::
	msgbox SSAqua_Interior1_Text_SsAnne_1, MSGBOX_AUTOCLOSE
	closemessage
	call EventScript_OutOfCenterPartyHeal
	msgbox SSAqua_Interior1_Text_SsAnne_2, MSGBOX_AUTOCLOSE
	call_if_unset 0x117D, SSAqua_Interior1_EventScript_SsAnne_1
	playse SE_DING_DONG @ ShinyGold fix: was playbgm (the sound effect replaced the map music until the next map)
	delay 80
	playbgm MUS_CELADON, 51
	call_if_set 0x1165, SSAqua_Interior1_EventScript_SsAnne_2
	msgbox SSAqua_Interior1_Text_SsAnne_3, MSGBOX_AUTOCLOSE
	setflag 0x11A9
	release
	end

SSAqua_Interior1_EventScript_SsAnne_1::
	release
	end

SSAqua_Interior1_EventScript_SsAnne_2::
	msgbox SSAqua_Interior1_Text_SsAnne_4, MSGBOX_AUTOCLOSE
	setflag 0x11A9
	release
	end
