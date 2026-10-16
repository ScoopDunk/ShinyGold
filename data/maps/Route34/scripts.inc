Route34_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route34_OnFrame
	.byte 0

Route34_OnFrame::
	map_script_2 0x7015, 0, Route34_EventScript_FrameScene
	.2byte 0

Route34_EventScript_FrameScene::
	setvar 0x7015, 1
	call Route34_EventScript_FrameScene_1
	call Route35_EventScript_FrameScene_2
	end

Route34_EventScript_FrameScene_1::
	setvar 0x7010, 0
	setvar 0x7011, 0
	setvar 0x7012, 0
	setvar 0x7013, 0
	setvar 0x7014, 0
	setvar 0x7016, 0
	setvar 0x7017, 0
	setvar 0x7018, 0
	setvar 0x7019, 0
	setvar 0x701A, 0
	setvar 0x701B, 0
	setvar 0x701C, 0
	setvar 0x701D, 0
	setvar 0x701E, 0
	setvar 0x701F, 0
	setvar 0x7020, 0
	setvar 0x7021, 0
	setvar 0x7022, 0
	setvar 0x7023, 0
	setvar 0x7024, 0
	setvar 0x7025, 0
	setvar 0x7026, 0
	setvar 0x7027, 0
	setvar 0x7028, 0
	return

Route34_EventScript_YoungsterSamuel::
	trainerbattle_single TRAINER_YOUNGSTER_SAMUEL, Route34_Text_YoungsterSamuelIntro, Route34_Text_YoungsterSamuelDefeat
	msgbox Route34_Text_YoungsterSamuel, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_PokefanBrandon::
	trainerbattle_single TRAINER_POKEFAN_BRANDON, Route34_Text_PokefanBrandonIntro, Route34_Text_PokefanBrandonDefeat
	msgbox Route34_Text_PokefanBrandon, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_YoungsterIan::
	trainerbattle_single TRAINER_YOUNGSTER_IAN, Route34_Text_YoungsterIanIntro, Route34_Text_YoungsterIanDefeat
	msgbox Route34_Text_YoungsterIan, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_OfficerKeith::
	trainerbattle_single TRAINER_OFFICER_KEITH, Route34_Text_OfficerKeithIntro, Route34_Text_OfficerKeithDefeat
	msgbox Route34_Text_OfficerKeith, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Camper148::
	trainerbattle_single TRAINER_CAMPER_TODD, Route34_Text_Camper148Intro, Route34_Text_Camper148Defeat
	call_if_set 0x1306, Route34_EventScript_Camper148_1
	setvar 0x700C, 6
	setvar 0x700D, 0
	call_if_set 0x1336, Route35_EventScript_Juggler228_2
	msgbox Route34_Text_Camper148, MSGBOX_NPC
	setflag 0x1336
	call Route35_EventScript_Juggler228_3
	end

Route34_EventScript_Camper148_1::
	clearflag 0x1306
	msgbox Route35_Text_Juggler228_2, MSGBOX_NPC
	call_if_set 0x030, Route34_EventScript_Camper148_2
	call_if_set 0x115F, Route34_EventScript_Camper148_3
	call_if_set 0x110A, Route34_EventScript_Camper148_4
	call_if_set FLAG_BADGE05_GET, Route34_EventScript_Camper148_5
	trainerbattle_earlyrival TRAINER_CAMPER_TODD, 0, Route34_Text_Camper148Defeat, Route35_Text_Juggler228Victory
	release
	end

Route34_EventScript_Camper148_2::
	trainerbattle_earlyrival TRAINER_CAMPER_TODD_2, 0, Route34_Text_Camper148Defeat, Route35_Text_Juggler228Victory
	release
	end

Route34_EventScript_Camper148_3::
	trainerbattle_earlyrival TRAINER_CAMPER_TODD_3, 0, Route34_Text_Camper148Defeat, Route35_Text_Juggler228Victory
	release
	end

Route34_EventScript_Camper148_4::
	trainerbattle_earlyrival TRAINER_CAMPER_TODD_4, 0, Route34_Text_Camper148Defeat, Route35_Text_Juggler228Victory
	release
	end

Route34_EventScript_Camper148_5::
	trainerbattle_earlyrival TRAINER_CAMPER_TODD_5, 0, Route34_Text_Camper148Defeat, Route35_Text_Juggler228Victory
	release
	end

Route34_EventScript_Picnicker152::
	trainerbattle_single TRAINER_PICNICKER_GINA, Route34_Text_Picnicker152Intro, Route34_Text_Picnicker152Defeat
	call_if_set 0x1307, Route34_EventScript_Picnicker152_1
	setvar 0x700C, 7
	setvar 0x700D, 0
	call_if_set 0x1337, Route35_EventScript_Juggler228_2
	msgbox Route34_Text_Picnicker152, MSGBOX_NPC
	setflag 0x1337
	call Route35_EventScript_Juggler228_3
	end

Route34_EventScript_Picnicker152_1::
	clearflag 0x1307
	msgbox Route35_Text_Juggler228_2, MSGBOX_NPC
	call_if_set 0x030, Route34_EventScript_Picnicker152_2
	call_if_set 0x115F, Route34_EventScript_Picnicker152_3
	call_if_set 0x110A, Route34_EventScript_Picnicker152_4
	call_if_set FLAG_BADGE05_GET, Route34_EventScript_Picnicker152_5
	trainerbattle_earlyrival TRAINER_PICNICKER_GINA, 0, Route34_Text_Picnicker152Defeat, Route35_Text_Juggler228Victory
	release
	end

Route34_EventScript_Picnicker152_2::
	trainerbattle_earlyrival TRAINER_PICNICKER_GINA_5, 0, Route34_Text_Picnicker152Defeat, Route35_Text_Juggler228Victory
	release
	end

Route34_EventScript_Picnicker152_3::
	trainerbattle_earlyrival TRAINER_PICNICKER_GINA_4, 0, Route34_Text_Picnicker152Defeat, Route35_Text_Juggler228Victory
	release
	end

Route34_EventScript_Picnicker152_4::
	trainerbattle_earlyrival TRAINER_PICNICKER_GINA_3, 0, Route34_Text_Picnicker152Defeat, Route35_Text_Juggler228Victory
	release
	end

Route34_EventScript_Picnicker152_5::
	trainerbattle_earlyrival TRAINER_PICNICKER_GINA_2, 0, Route34_Text_Picnicker152Defeat, Route35_Text_Juggler228Victory
	release
	end

Route34_EventScript_OldMan1::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, 1, Route34_EventScript_OldMan1_1
	goto_if_eq VAR_RESULT, 2, Route34_EventScript_OldMan1_2
	goto_if_eq VAR_RESULT, 3, Route34_EventScript_OldMan1_3
	msgbox DayCare_Text_ImDaycareManSpeakToMyWife
	release
	end

Route34_EventScript_OldMan1_1::
	msgbox DayCare_Text_DoYouWantEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 1, Route34_EventScript_OldMan1_4
	msgbox DayCare_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 1, Route34_EventScript_OldMan1_4
	msgbox DayCare_Text_IllKeepIt
	clearflag FLAG_PENDING_DAYCARE_EGG
	special RejectEggFromDayCare
	release
	end

Route34_EventScript_OldMan1_2::
	special GetDaycareMonNicknames
	msgbox DayCare_Text_YourMonIsDoingFine
	release
	end

Route34_EventScript_OldMan1_3::
	special GetDaycareMonNicknames
	msgbox DayCare_Text_YourMonsAreDoingFine
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	release
	end

Route34_EventScript_OldMan1_4::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, 6, Route34_EventScript_OldMan1_5
	msgbox DayCare_Text_YouHaveNoRoomForIt
	release
	end

Route34_EventScript_OldMan1_5::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message DayCare_Text_ReceivedEgg
	call EventScript_RestorePrevTextColor
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	msgbox DayCare_Text_TakeGoodCareOfIt
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
	release
	end

Route34_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY
	end

Route34_EventScript_CooltrainerIrene::
	trainerbattle_single TRAINER_COOLTRAINER_IRENE, Route34_Text_CooltrainerIreneIntro, Route34_Text_CooltrainerIreneDefeat
	call_if_set 0x10BB, Route34_EventScript_CooltrainerIrene_1
	msgbox Route34_Text_CooltrainerIrene_1, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_CooltrainerIrene_1::
	msgbox Route34_Text_CooltrainerIrene_2, MSGBOX_NPC
	end

Route34_EventScript_CooltrainerJenn::
	trainerbattle_single TRAINER_COOLTRAINER_JENN, Route34_Text_CooltrainerJennIntro, Route34_Text_CooltrainerJennDefeat
	call_if_set 0x10BB, Route34_EventScript_CooltrainerJenn_1
	msgbox Route34_Text_CooltrainerJenn_1, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_CooltrainerJenn_1::
	msgbox Route34_Text_CooltrainerJenn_2, MSGBOX_NPC
	end

Route34_EventScript_CooltrainerKate::
	trainerbattle_single TRAINER_COOLTRAINER_KATE, Route34_Text_CooltrainerKateIntro, Route34_Text_CooltrainerKateDefeat
	call_if_set 0x10BB, Route34_EventScript_CooltrainerKate_1
	setflag 0x10BB
	msgbox Route34_Text_CooltrainerKate_1, MSGBOX_NPC
	giveitem ITEM_SOFT_SAND
	msgbox Route34_Text_CooltrainerKate_2, MSGBOX_NPC
	end

Route34_EventScript_CooltrainerKate_1::
	msgbox Route34_Text_CooltrainerKate_2, MSGBOX_NPC
	end

Route34_EventScript_Sign1::
	msgbox Route34_Text_Sign1, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Sign2::
	msgbox Route34_Text_Sign2, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Sign3::
	msgbox Route34_Text_Sign3, MSGBOX_AUTOCLOSE
	end
