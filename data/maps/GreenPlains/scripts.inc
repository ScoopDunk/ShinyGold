GreenPlains_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

GreenPlains_EventScript_Mew::
	lock
	waitse
	playmoncry SPECIES_MEW, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, 2
	setvar VAR_0x8004, 151
	setvar VAR_0x8005, 40
	setvar VAR_0x8006, 0
	special CreateEnemyEventMon
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	fadescreen FADE_TO_BLACK
	removeobject 1
	fadescreen FADE_FROM_BLACK
	setflag 0x1409
	release
	end

GreenPlains_EventScript_Sign1::
	msgbox GreenPlains_Text_Sign1, MSGBOX_SIGN
	end

GreenPlains_EventScript_Sign2::
	msgbox GreenPlains_Text_Sign2, MSGBOX_SIGN
	end

GreenPlains_EventScript_Sign3::
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, GreenPlains_EventScript_Sign3_1
	msgbox GreenPlains_Text_Sign3_1, MSGBOX_NPC
	giveitem ITEM_DEEP_SEA_TOOTH
	releaseall
	special DaisyMassageServices
	end

GreenPlains_EventScript_Sign3_1::
	msgbox GreenPlains_Text_Sign3_2, MSGBOX_NPC
	end

GreenPlains_EventScript_Sign4::
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, GreenPlains_EventScript_Sign3_1
	msgbox GreenPlains_Text_Sign4, MSGBOX_NPC
	giveitem ITEM_BLUE_SCARF
	releaseall
	special DaisyMassageServices
	end

GreenPlains_EventScript_Sign5::
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0x1F4, GreenPlains_EventScript_Sign3_1
	msgbox GreenPlains_Text_Sign5, MSGBOX_NPC
	giveitem ITEM_PERSIM_BERRY
	releaseall
	special DaisyMassageServices
	end
