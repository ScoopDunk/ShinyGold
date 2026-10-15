Route19_Interior1_MapScripts::
	.byte 0

Route19_Interior1_EventScript_MgDeliveryman::
	goto_if_set 0x056, Route19_Interior1_EventScript_MgDeliveryman_1
	msgbox Route19_Interior1_Text_MgDeliveryman_1, MSGBOX_NPC
	release
	end

Route19_Interior1_EventScript_MgDeliveryman_1::
	msgbox Route19_Interior1_Text_MgDeliveryman_2, MSGBOX_NPC
	release
	end
