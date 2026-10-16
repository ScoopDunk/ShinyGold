SSAqua_Interior4_MapScripts::
	.byte 0

@ Pure Gold/Silver: the player's cabin bed heals the party; on later trips (and once the lost girl was found on the
@ first one) the ship arrives while the player sleeps (pokegold FastShipCabins_SW_SSW_NW.asm, FastShipBed)
SSAqua_Interior4_EventScript_Bed::
	lockall
	msgbox SSAqua_Interior4_Text_Bed_1
	closemessage
	call EventScript_OutOfCenterPartyHeal
	msgbox SSAqua_Interior4_Text_Bed_2
	closemessage
	goto_if_set 0x11A9, SSAqua_Interior4_EventScript_Bed_End
	goto_if_set 0x1177, SSAqua_Interior4_EventScript_Bed_Arrive
	goto_if_set 0x1170, SSAqua_Interior4_EventScript_Bed_Arrive
SSAqua_Interior4_EventScript_Bed_End::
	releaseall
	end

SSAqua_Interior4_EventScript_Bed_Arrive::
	playse SE_DING_DONG
	waitse
	delay 30
	goto_if_set 0x1165, SSAqua_Interior4_EventScript_Bed_ArriveOlivine
	msgbox SSAqua_Interior4_Text_ArrivedVermilion
	setflag 0x11A9
	releaseall
	end

SSAqua_Interior4_EventScript_Bed_ArriveOlivine::
	msgbox SSAqua_Interior4_Text_ArrivedOlivine
	setflag 0x11A9
	releaseall
	end
