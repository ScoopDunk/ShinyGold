EventScript_AfterWhiteOutHeal::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox Text_FirstShouldRestoreMonsHealth
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn
	call_if_unset FLAG_DEFEATED_BROCK, EventScript_AfterWhiteOutHealMsgPreBrock
	call_if_set FLAG_DEFEATED_BROCK, EventScript_AfterWhiteOutHealMsg
	applymovement VAR_LAST_TALKED, Movement_Bow
	waitmovement 0
	fadedefaultbgm
	releaseall
	end

EventScript_AfterWhiteOutHealMsgPreBrock::
	msgbox Text_MonsHealedShouldBuyPotions
	return

@ ShinyGold: modified in place by the hack
EventScript_AfterWhiteOutHealMsg::
	loadword 155, 0x9081A5F
	call 0x00C76903
	call_if_set 0x1023, SG_EventScript_AfterWhiteOutHealMsg_1
	call_if_set 0x1015, SG_EventScript_AfterWhiteOutHealMsg_2
	call SG_EventScript_AfterWhiteOutHealMsg_1
	end

@ ShinyGold: modified in place by the hack
EventScript_AfterWhiteOutMomHeal::
	@ ShinyGold: overlapping data duplicated from 0x081A8DD8
	textcolor NPC_TEXT_COLOR_MALE
	call_if_set 0x1023, SG_EventScript_AfterWhiteOutHealMsg_1
	call_if_set 0x1015, SG_EventScript_AfterWhiteOutHealMsg_2
	call SG_EventScript_AfterWhiteOutHealMsg_1
	end

EventScript_FieldPoison::
	lockall
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special TryFieldPoisonWhiteOut
	waitstate
	goto_if_eq VAR_RESULT, TRUE, EventScript_FieldWhiteOut
	releaseall
	end

EventScript_FieldWhiteOut::
	checkmoney 1
	goto_if_eq VAR_RESULT, FALSE, EventScript_FieldWhiteOutNoMoney
	goto_if_eq VAR_RESULT, TRUE, EventScript_FieldWhiteOutHasMoney
	end

EventScript_FieldWhiteOutNoMoney::
	msgbox Text_WhitedOut
	goto EventScript_FieldWhiteOutFade
	end

EventScript_FieldWhiteOutHasMoney::
	special OverworldWhiteOutGetMoneyLoss
	msgbox Text_WhitedOutLostMoney
	goto EventScript_FieldWhiteOutFade
	end

EventScript_FieldWhiteOutFade::
	special Script_FadeOutMapMusic
	waitstate
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	waitstate
	end
