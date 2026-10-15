Route26_Interior1_MapScripts::
	.byte 0

Route26_Interior1_EventScript_Woman2::
	msgbox Route26_Interior1_Text_Woman2_1, MSGBOX_NPC
	closemessage
	call EventScript_OutOfCenterPartyHeal
	msgbox Route26_Interior1_Text_Woman2_2, MSGBOX_NPC
	.byte 0xFF @ invalid opcode (script stops)
