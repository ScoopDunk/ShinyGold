GreenRoute_MapScripts::
	@ ShinyGold: map script header pointer was NULL
	.byte 0

GreenRoute_EventScript_Man::
	lock
	goto_if_set 0x236, GreenRoute_EventScript_Man_1
	goto_if_set 0x2D7, GreenRoute_EventScript_Man_2
	msgbox GreenRoute_Text_Man_1
	closemessage
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	delay 45
	msgbox GreenRoute_Text_Man_2
	applymovement 1, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox GreenRoute_Text_Man_3
	release
	end

GreenRoute_EventScript_Man_1::
	msgbox GreenRoute_Text_Man_4
	release
	end

GreenRoute_EventScript_Man_2::
	msgbox GreenRoute_Text_Man_5
	giveitem ITEM_TM42
	goto_if_eq VAR_RESULT, 0, GreenRoute_EventScript_Man_3
	call GreenRoute_EventScript_Man_4
	release
	end

GreenRoute_EventScript_Man_3::
	setflag 0x2D7
	msgbox GreenRoute_Text_Man_6
	releaseall
	end

GreenRoute_EventScript_Man_4::
	msgbox GreenRoute_Text_Man_7
	applymovement 1, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	setflag 0x236
	return

GreenRoute_EventScript_BirdKeeperHiro::
	trainerbattle_single TRAINER_BIRD_KEEPER_HIRO, GreenRoute_Text_BirdKeeperHiroIntro, FiveIsland_MemorialPillar_Text_HaroldDefeat
	msgbox FiveIsland_MemorialPillar_Text_HaroldPostBattle, MSGBOX_AUTOCLOSE
	end

GreenRoute_EventScript_ItemStarPiece::
	finditem ITEM_STAR_PIECE
	end

GreenRoute_EventScript_Sign1::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lockall
	goto_if_set 0x236, GreenRoute_EventScript_Sign1_1
	goto_if_set 0x2D7, GreenRoute_EventScript_Sign1_1
	msgbox GreenRoute_Text_Sign1_1
	checkitem ITEM_LEMONADE
	goto_if_eq VAR_RESULT, 1, GreenRoute_EventScript_Sign1_2
	releaseall
	end

GreenRoute_EventScript_Sign1_1::
	msgbox GreenRoute_Text_Sign1_2
	releaseall
	end

GreenRoute_EventScript_Sign1_2::
	msgbox GreenRoute_Text_Sign1_3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 1, GreenRoute_EventScript_Sign1_3
	releaseall
	end

GreenRoute_EventScript_Sign1_3::
	removeitem ITEM_LEMONADE
	msgbox GreenRoute_Text_Sign1_4
	closemessage
	applymovement 1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 45
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox GreenRoute_Text_Sign1_5
	giveitem ITEM_TM42
	goto_if_eq VAR_RESULT, 0, GreenRoute_EventScript_Man_3
	call GreenRoute_EventScript_Man_4
	releaseall
	end
