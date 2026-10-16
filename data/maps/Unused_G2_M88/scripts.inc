@ The Bug-Catching Contest (National Park during the contest).
@ ShinyGold gold: wild bugs and judging as in Gold/Silver (src/gold_bug_contest.c). The hack's own rules stay:
@ you enter with one POKéMON, and catching a bug ends the contest. The hack has no clock, so the contest is
@ open after certain story events instead of on Tuesdays, Thursdays and Saturdays (see NationalPark_Interior1).
Unused_G2_M88_MapScripts::
	.byte 0

@ The guard at the gate: talk to him to finish early.
Unused_G2_M88_EventScript_Guard::
	lock
	faceplayer
	msgbox Unused_G2_M88_Text_FinishNow, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Unused_G2_M88_EventScript_Judging
	release
	end

@ Every grass tile with a coord event. The hack's encounter pacing (four steps out of five) is kept;
@ the POKéMON and its level come from the G/S contest table.
Unused_G2_M88_EventScript_Grass::
	random 5
	goto_if_eq VAR_RESULT, 0, Unused_G2_M88_EventScript_NoEncounter
	callnative BugContest_CreateEncounter
	dowildbattle
	getpartysize
	goto_if_ge VAR_RESULT, 2, Unused_G2_M88_EventScript_CaughtBug
	end

Unused_G2_M88_EventScript_NoEncounter::
	end

Unused_G2_M88_EventScript_CaughtBug::
	lockall
	playse SE_DING_DONG
	msgbox Unused_G2_M88_Text_CaughtBug
	goto Unused_G2_M88_EventScript_Judging

@ pokegold BugContestResultsScript
Unused_G2_M88_EventScript_Judging::
	lockall
	msgbox Unused_G2_M88_Text_ReadyToJudge
	callnative BugContest_Judge
	copyvar VAR_0x8008, VAR_RESULT
	setvar VAR_0x8004, 3
	callnative BugContest_BufferPlace
	message Unused_G2_M88_Text_ThirdPlace
	waitmessage
	playfanfare MUS_LEVEL_UP
	waitfanfare
	msgbox Unused_G2_M88_Text_Score
	setvar VAR_0x8004, 2
	callnative BugContest_BufferPlace
	message Unused_G2_M88_Text_SecondPlace
	waitmessage
	playfanfare MUS_LEVEL_UP
	waitfanfare
	msgbox Unused_G2_M88_Text_Score
	setvar VAR_0x8004, 1
	callnative BugContest_BufferPlace
	message Unused_G2_M88_Text_FirstPlace
	waitmessage
	playfanfare MUS_LEVEL_UP
	waitfanfare
	msgbox Unused_G2_M88_Text_WinningScore
	goto_if_eq VAR_0x8008, 1, Unused_G2_M88_EventScript_FirstPrize
	goto_if_eq VAR_0x8008, 2, Unused_G2_M88_EventScript_SecondPrize
	goto_if_eq VAR_0x8008, 3, Unused_G2_M88_EventScript_ThirdPrize
	msgbox Unused_G2_M88_Text_ConsolationPrize
	giveitem ITEM_ORAN_BERRY
	msgbox Unused_G2_M88_Text_DidNotWin
	goto Unused_G2_M88_EventScript_LeavePark

Unused_G2_M88_EventScript_FirstPrize::
	msgbox Unused_G2_M88_Text_FirstPrize
	giveitem ITEM_SUN_STONE
	goto Unused_G2_M88_EventScript_JoinUsNextTime

Unused_G2_M88_EventScript_SecondPrize::
	msgbox Unused_G2_M88_Text_SecondPrize
	giveitem ITEM_EVERSTONE
	goto Unused_G2_M88_EventScript_JoinUsNextTime

Unused_G2_M88_EventScript_ThirdPrize::
	msgbox Unused_G2_M88_Text_ThirdPrize
	giveitem ITEM_SITRUS_BERRY
	goto Unused_G2_M88_EventScript_JoinUsNextTime

Unused_G2_M88_EventScript_JoinUsNextTime::
	msgbox Unused_G2_M88_Text_JoinUsNextTime
Unused_G2_M88_EventScript_LeavePark::
	closemessage
	callnative BugContest_TakeParkBalls
	warp MAP_NATIONAL_PARK_INTERIOR1, 1
	waitstate
	releaseall
	end

Unused_G2_M88_EventScript_Josh::
	msgbox Unused_G2_M88_Text_Josh, MSGBOX_NPC
	end

Unused_G2_M88_EventScript_Samuel::
	msgbox Unused_G2_M88_Text_Samuel, MSGBOX_NPC
	end

Unused_G2_M88_EventScript_Barry::
	msgbox Unused_G2_M88_Text_Barry, MSGBOX_NPC
	end

Unused_G2_M88_EventScript_Ed::
	msgbox Unused_G2_M88_Text_Ed, MSGBOX_NPC
	end

Unused_G2_M88_EventScript_William::
	msgbox Unused_G2_M88_Text_William, MSGBOX_NPC
	end
