GoldenrodCity_Interior2_MapScripts::
	.byte 0

GoldenrodCity_Interior2_EventScript_SuperNerdEric::
	trainerbattle_single TRAINER_SUPER_NERD_ERIC, GoldenrodCity_Interior2_Text_SuperNerdEricIntro, GoldenrodCity_Interior2_Text_SuperNerdEricDefeat
	msgbox GoldenrodCity_Interior2_Text_SuperNerdEric, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Interior2_EventScript_PokemaniacIssac::
	trainerbattle_single TRAINER_POKEMANIAC_ISSAC, GoldenrodCity_Interior2_Text_PokemaniacIssacIntro, GoldenrodCity_Interior2_Text_PokemaniacIssacDefeat
	msgbox GoldenrodCity_Interior2_Text_PokemaniacIssac, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Interior2_EventScript_ItemBall::
	setflag 0x243
	finditem ITEM_COIN_CASE
	end

GoldenrodCity_Interior2_EventScript_OldWoman::
	lock
	faceplayer
	setptr 98, 0x8E66081A
	msgbox GoldenrodCity_Interior2_Text_OldWoman_1, MSGBOX_NPC
	pokemart GoldenrodCity_Interior2_Items_OldWoman
	msgbox GoldenrodCity_Interior2_Text_OldWoman_2, MSGBOX_NPC
	release
	end

	.align 1
GoldenrodCity_Interior2_Items_OldWoman::
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_REVIVAL_HERB
	.2byte ITEM_NONE

GoldenrodCity_Interior2_EventScript_ItemSuperPotion::
	finditem ITEM_SUPER_POTION
	end

GoldenrodCity_Interior2_EventScript_Man::
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, GoldenrodCity_Interior2_EventScript_Man_1
	showmoneybox 0, 0
	msgbox GoldenrodCity_Interior2_Text_Man_1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, GoldenrodCity_Interior2_EventScript_Man_2
	msgbox GoldenrodCity_Interior2_Text_Man_2, MSGBOX_NPC
	.byte 0x94 @ hidemoneybox (FRLG consumes no argument bytes)
	nop
	nop1
	releaseall
	end

GoldenrodCity_Interior2_EventScript_Man_1::
	msgbox GoldenrodCity_Interior2_Text_Man_3, MSGBOX_NPC
	end

GoldenrodCity_Interior2_EventScript_Man_2::
	checkmoney 0x12C
	call_if_eq VAR_RESULT, 0, GoldenrodCity_Interior2_EventScript_Man_3
	removemoney 0x12C
	updatemoneybox
	textcolor 104
	.byte 0x94 @ hidemoneybox (FRLG consumes no argument bytes)
	releaseall
	call GoldenrodCity_Interior2_EventScript_Man_4
	end

GoldenrodCity_Interior2_EventScript_Man_3::
	msgbox GoldenrodCity_Interior2_Text_Man_4, MSGBOX_NPC
	closemessage
	.byte 0x94 @ hidemoneybox (FRLG consumes no argument bytes)
	nop
	nop1
	releaseall
	end

GoldenrodCity_Interior2_EventScript_Man_4::
	msgbox GoldenrodCity_Interior2_Text_Man_5, MSGBOX_NPC
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	call_if_ge VAR_0x8004, 6, GoldenrodCity_Interior2_EventScript_Man_5
	specialvar VAR_RESULT, GetPartyMonSpecies
	call_if_eq VAR_RESULT, 0x19C, GoldenrodCity_Interior2_EventScript_Man_6
	msgbox GoldenrodCity_Interior2_Text_Man_6, MSGBOX_NPC
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special DaisyMassageServices
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox GoldenrodCity_Interior2_Text_Man_7, MSGBOX_NPC
	release
	end

GoldenrodCity_Interior2_EventScript_Man_5::
	msgbox GoldenrodCity_Interior2_Text_Man_2, MSGBOX_NPC
	end

GoldenrodCity_Interior2_EventScript_Man_6::
	msgbox GoldenrodCity_Interior2_Text_Man_8, MSGBOX_NPC
	end

GoldenrodCity_Interior2_EventScript_GymSign::
	checkitem ITEM_CARD_KEY
	call_if_eq VAR_RESULT, 1, GoldenrodCity_Interior2_EventScript_GymSign_1
	msgbox GoldenrodCity_Interior2_Text_GymSign_1, MSGBOX_NPC
	end

GoldenrodCity_Interior2_EventScript_GymSign_1::
	msgbox GoldenrodCity_Interior2_Text_GymSign_2, MSGBOX_NPC
	applymovement 7, GoldenrodCity_Interior2_Movement_GymSign
	delay 16
	end

GoldenrodCity_Interior2_Movement_GymSign::
	set_invisible
	walk_fast_up
	walk_fast_up
	step_end

GoldenrodCity_Interior2_EventScript_ItemParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

GoldenrodCity_Interior2_EventScript_OldMan1::
	call_if_set 0x10C2, GoldenrodCity_Interior2_EventScript_OldMan1_1
	textcolor NPC_TEXT_COLOR_MALE
	showmoneybox 0, 0
	msgbox GoldenrodCity_Interior2_Text_OldMan1_1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 1, GoldenrodCity_Interior2_EventScript_OldMan1_2
	msgbox GoldenrodCity_Interior2_Text_OldMan1_2, MSGBOX_NPC
	.byte 0x94 @ hidemoneybox (FRLG consumes no argument bytes)
	nop
	nop1
	releaseall
	end

GoldenrodCity_Interior2_EventScript_OldMan1_1::
	msgbox GoldenrodCity_Interior2_Text_OldMan1_3, MSGBOX_NPC
	end

GoldenrodCity_Interior2_EventScript_OldMan1_2::
	checkmoney 0x1194
	call_if_eq VAR_RESULT, 0, GoldenrodCity_Interior2_EventScript_OldMan1_3
	removemoney 0x1194
	updatemoneybox
	textcolor NPC_TEXT_COLOR_NEUTRAL
	closemessage
	.byte 0x94 @ hidemoneybox (FRLG consumes no argument bytes)
	giveitem ITEM_NUGGET
	msgbox GoldenrodCity_Interior2_Text_OldMan1_4, MSGBOX_NPC
	setflag 0x10C2
	releaseall
	end

GoldenrodCity_Interior2_EventScript_OldMan1_3::
	msgbox GoldenrodCity_Interior2_Text_OldMan1_5, MSGBOX_NPC
	closemessage
	.byte 0x94 @ hidemoneybox (FRLG consumes no argument bytes)
	nop
	nop1
	releaseall
	end

GoldenrodCity_Interior2_EventScript_SuperNerdTeru::
	trainerbattle_single TRAINER_SUPER_NERD_TERU, GoldenrodCity_Interior2_Text_SuperNerdTeruIntro, GoldenrodCity_Interior2_Text_SuperNerdTeruDefeat
	msgbox GoldenrodCity_Interior2_Text_SuperNerdTeru, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Interior2_EventScript_ItemAntidote::
	finditem ITEM_ANTIDOTE
	end

GoldenrodCity_Interior2_EventScript_PokemaniacDonald::
	trainerbattle_single TRAINER_POKEMANIAC_DONALD, GoldenrodCity_Interior2_Text_PokemaniacDonaldIntro, GoldenrodCity_Interior2_Text_PokemaniacDonaldDefeat
	msgbox GoldenrodCity_Interior2_Text_PokemaniacDonald, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Interior2_EventScript_Trigger::
	call_if_set 0x110D, GoldenrodCity_Interior2_EventScript_Trigger_1
	setflag 0x110E
	release
	end

GoldenrodCity_Interior2_EventScript_Trigger_1::
	release
	end
