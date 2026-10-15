VictoryRoad_Cave4_MapScripts::
	@ ShinyGold: 1 entry with invalid type(s) 0x6C dropped (inert: the engine skips them)
	.byte 0

VictoryRoad_Cave4_EventScript_ItemTimerBall::
	finditem ITEM_TIMER_BALL
	end

VictoryRoad_Cave4_EventScript_ItemFullHeal::
	finditem ITEM_FULL_HEAL
	end

VictoryRoad_Cave4_EventScript_RedNormal::
	special GetQuestLogState
	call_if_eq VAR_RESULT, 2, EventScript_ReleaseEnd
	lockall
	checkpartymove MOVE_HEADBUTT
	call_if_eq VAR_RESULT, 6, VictoryRoad_Cave4_EventScript_RedNormal_1
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_1, MOVE_ROCK_SMASH
	msgbox VictoryRoad_Cave4_Text_RedNormal, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 0, EventScript_DontSmashRock
	closemessage
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	goto EventScript_UseRockSmash

VictoryRoad_Cave4_EventScript_RedNormal_1::
	release
	end
