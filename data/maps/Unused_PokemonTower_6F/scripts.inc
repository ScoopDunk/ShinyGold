Unused_PokemonTower_6F_MapScripts::
	.byte 0

Unused_PokemonTower_6F_EventScript_MgDeliveryman::
	msgbox Unused_PokemonTower_6F_Text_MgDeliveryman, MSGBOX_NPC
	end

Unused_PokemonTower_6F_EventScript_MediumJennifer::
	trainerbattle_single TRAINER_MEDIUM_JENNIFER, Unused_PokemonTower_6F_Text_MediumJenniferIntro, Unused_PokemonTower_6F_Text_MediumJenniferDefeat
	msgbox Unused_PokemonTower_6F_Text_MediumJennifer, MSGBOX_AUTOCLOSE
	end

Unused_PokemonTower_6F_EventScript_OldMan1::
	msgbox Unused_PokemonTower_6F_Text_OldMan1, MSGBOX_NPC
	end

Unused_PokemonTower_6F_EventScript_Trigger1::
	lockall
	textcolor NPC_TEXT_COLOR_MON
	msgbox Unused_PokemonTower_6F_Text_Trigger1_1
	goto_if_questlog EventScript_ReleaseEnd
	setwildbattle SPECIES_MAROWAK, 30
	special StartMarowakBattle
	waitstate
	special QuestLog_CutRecording
	goto_if_eq VAR_RESULT, 0, Unused_PokemonTower_6F_EventScript_Trigger1_1
	applymovement LOCALID_PLAYER, Unused_PokemonTower_6F_Movement_Trigger1
	waitmovement 0
	releaseall
	end

Unused_PokemonTower_6F_EventScript_Trigger1_1::
	message Unused_PokemonTower_6F_Text_Trigger1_2
	waitmessage
	waitse
	playmoncry SPECIES_MAROWAK, CRY_MODE_NORMAL
	waitbuttonpress
	waitmoncry
	msgbox Unused_PokemonTower_6F_Text_Trigger1_3
	setvar 0x4059, 1
	releaseall
	end

Unused_PokemonTower_6F_Movement_Trigger1::
	walk_up
	step_end
