SSAqua_Interior8_MapScripts::
	.byte 0

SSAqua_Interior8_EventScript_Captain::
	call_if_set 0x1177, SSAqua_Interior8_EventScript_Captain_1
	msgbox SSAqua_Interior8_Text_Captain_1, MSGBOX_NPC
	end

SSAqua_Interior8_EventScript_Captain_1::
	msgbox SSAqua_Interior8_Text_Captain_2, MSGBOX_NPC
	end

@ Pure Gold/Silver: the lost granddaughter runs back to her grandpa's cabin, where the reunion scene plays
@ (pokegold FastShipCabins_SE_SSE_CaptainsCabin.asm, SSAquaGranddaughterBefore)
SSAqua_Interior8_EventScript_Woman1::
	lock
	applymovement 2, SSAqua_Interior8_Movement_Woman1
	waitmovement 0
	msgbox SSAqua_Interior8_Text_Woman1_1
	closemessage
	applymovement 2, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SSAqua_Interior8_Text_Woman1_2
	closemessage
	setflag 0x1170
	clearflag 0x1171
	setvar VAR_GOLD_SS_AQUA_SCENE, 1
	warp MAP_SS_AQUA_INTERIOR16, 3, 4
	waitstate
	release
	end

SSAqua_Interior8_Movement_Woman1::
	face_left
	step_end
