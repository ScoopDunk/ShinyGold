Unused_G34_M80_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

Unused_G34_M80_EventScript_GymSign::
	call_if_unset 0x1222, Unused_G34_M72_EventScript_GymSign_1
	clearflag FLAG_SYS_ON_CYCLING_ROAD
	msgbox Unused_G34_M72_Text_GymSign_1, MSGBOX_NPC
	msgbox Unused_G34_M80_Text_GymSign, MSGBOX_NPC
	call Unused_G34_M75_EventScript_GymSign_1
	end

Unused_G34_M80_EventScript_BikerLark::
	trainerbattle_single TRAINER_BIKER_LARK, Unused_G34_M80_Text_BikerLarkIntro, Unused_G34_M80_Text_BikerLarkDefeat
	msgbox Unused_G34_M80_Text_BikerLark, MSGBOX_AUTOCLOSE
	end

Unused_G34_M80_EventScript_BikerRowdy::
	trainerbattle_single TRAINER_BIKER_ROWDY, Unused_G34_M80_Text_BikerRowdyIntro, Unused_G34_M80_Text_BikerRowdyDefeat
	msgbox Unused_G34_M80_Text_BikerRowdy, MSGBOX_AUTOCLOSE
	end

Unused_G34_M80_EventScript_ItemSalacBerry::
	finditem ITEM_SALAC_BERRY
	end

Unused_G34_M80_EventScript_ItemMaxElixir::
	finditem ITEM_MAX_ELIXIR
	end

Unused_G34_M80_EventScript_Trigger1::
	checkitem ITEM_BICYCLE
	call_if_eq VAR_RESULT, 1, Unused_G34_M80_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, Unused_G34_M80_Movement_Trigger1
	delay 16
	loadword 0, Unused_G34_M80_Text_Trigger1

Unused_G34_M80_EventScript_Trigger1_1::
	special ForcePlayerOntoBike
	setflag FLAG_SYS_ON_CYCLING_ROAD
	release
	end

Unused_G34_M80_Movement_Trigger1::
	walk_fast_down
	step_end

Unused_G34_M80_EventScript_Trigger4::
	call_if_unset FLAG_SYS_ON_CYCLING_ROAD, Unused_G34_M80_EventScript_Trigger4_1
	clearflag FLAG_SYS_ON_CYCLING_ROAD
	release
	end

Unused_G34_M80_EventScript_Trigger4_1::
	release
	end

Unused_G34_M80_EventScript_Sign::
	msgbox Unused_G34_M72_Text_Sign, MSGBOX_NPC
	setflag 0x1222
	release
	end
