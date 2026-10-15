SSAqua_Interior11_MapScripts::
	.byte 0

SSAqua_Interior11_EventScript_GentlemanEdward::
	trainerbattle_single TRAINER_GENTLEMAN_EDWARD, SSAqua_Interior11_Text_GentlemanEdwardIntro, SSAqua_Interior11_Text_GentlemanEdwardDefeat
	call_if_set 0x11A0, SSAqua_Interior11_EventScript_GentlemanEdward_1
	msgbox SSAqua_Interior11_Text_GentlemanEdward, MSGBOX_AUTOCLOSE
	end

SSAqua_Interior11_EventScript_GentlemanEdward_1::
	msgbox SSAqua_Interior11_Text_GentlemanEdwardIntro, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_GENTLEMAN_EDWARD, 0, SSAqua_Interior11_Text_GentlemanEdwardDefeat, SSAqua_Interior3_Text_FishermanJonahVictory
	clearflag 0x11A0
	end

SSAqua_Interior11_EventScript_BurglarCory::
	trainerbattle_single TRAINER_BURGLAR_CORY, SSAqua_Interior11_Text_BurglarCoryIntro, SSAqua_Interior11_Text_BurglarCoryDefeat
	call_if_set 0x1196, SSAqua_Interior11_EventScript_BurglarCory_1
	msgbox SSAqua_Interior11_Text_BurglarCory, MSGBOX_AUTOCLOSE
	end

SSAqua_Interior11_EventScript_BurglarCory_1::
	msgbox SSAqua_Interior11_Text_BurglarCoryIntro, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_BURGLAR_CORY, 0, SSAqua_Interior11_Text_BurglarCoryDefeat, SSAqua_Interior3_Text_FishermanJonahVictory
	clearflag 0x1196
	end

SSAqua_Interior11_EventScript_SailorStanly::
	msgbox SSAqua_Interior11_Text_SailorStanly_1, MSGBOX_NPC
	trainerbattle_earlyrival TRAINER_SAILOR_STANLY, 0, SSAqua_Interior11_Text_SailorStanlyDefeat, SSAqua_Interior11_Text_SailorStanlyVictory
	setflag 0x1169
	setflag 0x1167
	msgbox SSAqua_Interior11_Text_SailorStanly_2, MSGBOX_NPC
	call_if_eq VAR_TEMP_1, 1, SSAqua_Interior11_EventScript_SailorStanly_1
	call_if_eq VAR_TEMP_1, 2, SSAqua_Interior11_EventScript_SailorStanly_2
	end

SSAqua_Interior11_EventScript_SailorStanly_1::
	applymovement 3, SSAqua_Interior11_Movement_SailorStanly_1
	delay 48
	release
	end

SSAqua_Interior11_EventScript_SailorStanly_2::
	applymovement 3, SSAqua_Interior11_Movement_SailorStanly_2
	delay 80
	release
	end

SSAqua_Interior11_Movement_SailorStanly_1::
	walk_left
	walk_left
	face_up
	set_invisible
	walk_fast_up
	walk_fast_up
	step_end

SSAqua_Interior11_Movement_SailorStanly_2::
	walk_down
	walk_left
	walk_left
	walk_up
	set_invisible
	walk_fast_up
	walk_fast_up
	step_end

SSAqua_Interior11_EventScript_Trigger1::
	setvar VAR_TEMP_1, 1
	release
	end

SSAqua_Interior11_EventScript_Trigger2::
	setvar VAR_TEMP_1, 2
	release
	end
