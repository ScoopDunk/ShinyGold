EcruteakCity_Interior6_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

EcruteakCity_Interior6_EventScript_OldMan1::
	call_if_set FLAG_BADGE05_GET, EcruteakCity_Interior6_EventScript_OldMan1_1
	msgbox EcruteakCity_Interior6_Text_OldMan1_1, MSGBOX_NPC
	end

EcruteakCity_Interior6_EventScript_OldMan1_1::
	msgbox EcruteakCity_Interior6_Text_OldMan1_2, MSGBOX_NPC
	end

EcruteakCity_Interior6_EventScript_OldMan12::
	msgbox EcruteakCity_Interior6_Text_OldMan12, MSGBOX_NPC
	end

EcruteakCity_Interior6_EventScript_BaldingMan::
	msgbox EcruteakCity_Interior6_Text_BaldingMan, MSGBOX_NPC
	end

EcruteakCity_Interior6_EventScript_Trigger::
	call_if_set FLAG_BADGE05_GET, EcruteakCity_Interior6_EventScript_Trigger_1
	msgbox EcruteakCity_Interior6_Text_OldMan1_1, MSGBOX_NPC
	applymovement LOCALID_PLAYER, EcruteakCity_Interior6_Movement_Trigger
	end

EcruteakCity_Interior6_EventScript_Trigger_1::
	release
	end

EcruteakCity_Interior6_Movement_Trigger::
	walk_down
	step_end
