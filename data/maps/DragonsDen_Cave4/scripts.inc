DragonsDen_Cave4_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

DragonsDen_Cave4_EventScript_ItemRevive::
	finditem ITEM_REVIVE
	end

DragonsDen_Cave4_EventScript_ItemMaxPotion::
	finditem ITEM_MAX_POTION
	end

DragonsDen_Cave4_EventScript_ItemDragonFang::
	finditem ITEM_DRAGON_FANG
	clearflag 0x114B
	call_if_eq VAR_TEMP_1, 1, DragonsDen_Cave4_EventScript_ItemDragonFang_1
	call_if_eq VAR_TEMP_1, 2, DragonsDen_Cave4_EventScript_ItemDragonFang_2
	end

DragonsDen_Cave4_EventScript_ItemDragonFang_1::
	applymovement LOCALID_PLAYER, DragonsDen_Cave4_Movement_ItemDragonFang_1
	delay 16
	applymovement 5, DragonsDen_Cave4_Movement_ItemDragonFang_2
	delay 80
	call DragonsDen_Cave4_EventScript_ItemDragonFang_3
	end

DragonsDen_Cave4_EventScript_ItemDragonFang_2::
	applymovement LOCALID_PLAYER, DragonsDen_Cave4_Movement_ItemDragonFang_1
	delay 16
	applymovement 5, DragonsDen_Cave4_Movement_ItemDragonFang_3
	delay 96
	call DragonsDen_Cave4_EventScript_ItemDragonFang_3
	end

DragonsDen_Cave4_EventScript_ItemDragonFang_3::
	setflag FLAG_BADGE07_GET
	msgbox DragonsDen_Cave4_Text_ItemDragonFang_1, MSGBOX_NPC
	msgbox DragonsDen_Cave4_Text_ItemDragonFang_2, MSGBOX_NPC
	giveitem ITEM_TM24
	msgbox DragonsDen_Cave4_Text_ItemDragonFang_3, MSGBOX_NPC
	msgbox DragonsDen_Cave4_Text_ItemDragonFang_4, MSGBOX_NPC
	applymovement 5, DragonsDen_Cave4_Movement_ItemDragonFang_4
	delay 112
	setflag 0x114B
	release
	end

DragonsDen_Cave4_Movement_ItemDragonFang_1::
	walk_down
	step_end

DragonsDen_Cave4_Movement_ItemDragonFang_2::
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cave4_Movement_ItemDragonFang_3::
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cave4_Movement_ItemDragonFang_4::
	walk_down
	walk_down
	walk_down
	walk_down
	set_invisible
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

DragonsDen_Cave4_EventScript_ItemMaxElixir::
	finditem ITEM_MAX_ELIXIR
	end

DragonsDen_Cave4_EventScript_RsBrendan::
	goto_if_set 0x08F, DragonsDen_Cave4_EventScript_RsBrendan_1
	msgbox DragonsDen_Cave4_Text_RsBrendan_1, MSGBOX_NPC
	setflag 0x08F
	release
	end

DragonsDen_Cave4_EventScript_RsBrendan_1::
	msgbox DragonsDen_Cave4_Text_RsBrendan_2, MSGBOX_NPC
	release
	end

DragonsDen_Cave4_EventScript_Trigger2::
	setvar VAR_TEMP_1, 2
	release
	end

DragonsDen_Cave4_EventScript_Trigger3::
	setvar VAR_TEMP_1, 1
	release
	end

DragonsDen_Cave4_EventScript_Sign::
	msgbox DragonsDen_Cave4_Text_Sign, MSGBOX_AUTOCLOSE
	end
