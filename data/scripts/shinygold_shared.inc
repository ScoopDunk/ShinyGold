SG_EventScript_AfterWhiteOutHealMsg_1::
	applymovement 1, Common_Movement_WalkInPlaceFasterDown
	msgbox Text_HadQuiteAnExperienceTakeRest
	call EventScript_OutOfCenterPartyHeal
	msgbox Text_MomExplainHPGetPotions
	fadedefaultbgm
	releaseall
	end

SG_EventScript_AfterWhiteOutHealMsg_2::
	warp MAP_CHERRYGROVE_CITY, 0, 0xFF02, 0xFF00
	.byte 0xFF @ invalid opcode (script stops)

SG_EventScript_SetDefeatedEliteFourFlagsVars_1::
	clearflag 0x02F
	clearflag 0x4B8
	clearflag 0x4B9
	clearflag 0x4BA
	clearflag 0x4BB
	clearflag 0x4BC
	cleartrainerflag TRAINER_ELITETRAINER_LANCE
	cleartrainerflag TRAINER_RIVAL_TERRY_13
	cleartrainerflag TRAINER_RIVAL_TERRY_14
	cleartrainerflag TRAINER_RIVAL_TERRY_15
	cleartrainerflag TRAINER_RIVAL_TERRY_16
	cleartrainerflag TRAINER_RIVAL_TERRY_17
	setvar 0x4068, 0
	return
