Unused_SSAnne_1F_Room6_MapScripts::
	.byte 0

Unused_SSAnne_1F_Room6_EventScript_Woman2::
	lock
	faceplayer
	msgbox Unused_SSAnne_1F_Room6_Text_Woman2_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 0, Unused_SSAnne_1F_Room6_EventScript_Woman2_1
	closemessage
	call EventScript_OutOfCenterPartyHeal
	msgbox Unused_SSAnne_1F_Room6_Text_Woman2_2
	release
	end

Unused_SSAnne_1F_Room6_EventScript_Woman2_1::
	checkplayergender
	goto_if_eq VAR_RESULT, 0, Unused_SSAnne_1F_Room6_EventScript_Woman2_2
	msgbox Unused_SSAnne_1F_Room6_Text_Woman2_3
	release
	end

Unused_SSAnne_1F_Room6_EventScript_Woman2_2::
	msgbox Unused_SSAnne_1F_Room6_Text_Woman2_4
	release
	end
