GoldenrodCity_Interior19_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_Interior19_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodCity_Interior19_OnFrame
	.byte 0

GoldenrodCity_Interior19_OnTransition::
	setrespawn HEAL_LOCATION_GOLDENROD_CITY
	setflag FLAG_GOLD_HIDE_GS_BALL_RECEPTIONIST
	end

GoldenrodCity_Interior19_OnFrame::
	map_script_2 VAR_TEMP_1, 0, GoldenrodCity_Interior19_EventScript_GSBallCheck
	.2byte 0

@ Pure Gold: the GS Ball, as in Crystal (pokecrystal GoldenrodPokecenter1F_GSBallSceneLeft/Right). Once the player has
@ entered the HALL OF FAME, a receptionist comes down from the 2nd floor when the player walks in, and gives the GS BALL.
@ It starts the GS Ball event (VAR_GOLD_GS_BALL): KURT (AzaleaTown_Interior5), AZALEA TOWN, ILEX FOREST shrine.
GoldenrodCity_Interior19_EventScript_GSBallCheck::
	setvar VAR_TEMP_1, 1
	goto_if_unset FLAG_SYS_GAME_CLEAR, GoldenrodCity_Interior19_EventScript_GSBallCheckEnd
	goto_if_ne VAR_GOLD_GS_BALL, GS_BALL_NOT_RECEIVED, GoldenrodCity_Interior19_EventScript_GSBallCheckEnd
	@ ShinyGold saves: the hack's own GS Ball story (the ball was found in the removed SEA CAVERN) may be over (flag
	@ 0x11B3: the ball was put in the shrine) or under way (the player has the ball)
	goto_if_set 0x11B3, GoldenrodCity_Interior19_EventScript_GSBallOldSaveDone
	checkitem ITEM_RED_ORB
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_Interior19_EventScript_GSBallOldSaveHasBall
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_ne VAR_0x8004, 7, GoldenrodCity_Interior19_EventScript_GSBallCheckEnd
	goto_if_ne VAR_0x8005, 8, GoldenrodCity_Interior19_EventScript_GSBallCheckEnd
	lockall
	playse SE_EXIT
	clearflag FLAG_GOLD_HIDE_GS_BALL_RECEPTIONIST
	addobject 5
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement 5, GoldenrodCity_Interior19_Movement_ReceptionistApproach
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox GoldenrodCity_Interior19_Text_PleaseAcceptGSBall
	giveitem ITEM_RED_ORB
	setvar VAR_GOLD_GS_BALL, GS_BALL_RECEIVED
	msgbox GoldenrodCity_Interior19_Text_PleaseDoComeAgain
	closemessage
	applymovement 5, GoldenrodCity_Interior19_Movement_ReceptionistLeave
	waitmovement 0
	fadedefaultbgm
	playse SE_EXIT
	removeobject 5
	releaseall
	end

GoldenrodCity_Interior19_EventScript_GSBallOldSaveDone::
	setvar VAR_GOLD_GS_BALL, GS_BALL_USED
	end

GoldenrodCity_Interior19_EventScript_GSBallOldSaveHasBall::
	setvar VAR_GOLD_GS_BALL, GS_BALL_RECEIVED
	end

GoldenrodCity_Interior19_EventScript_GSBallCheckEnd::
	end

GoldenrodCity_Interior19_Movement_ReceptionistApproach::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	step_end

GoldenrodCity_Interior19_Movement_ReceptionistLeave::
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ ShinyGold: moved from data/maps/Unused_G2_M70/scripts.inc (map removed)
Unused_G2_M70_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

@ ShinyGold: moved from data/maps/Unused_G2_M70/scripts.inc (map removed)
Unused_G2_M70_EventScript_Man::
	msgbox Unused_G2_M70_Text_Man, MSGBOX_NPC
	end

@ ShinyGold: moved from data/maps/Unused_G2_M70/scripts.inc (map removed)
Unused_G2_M70_EventScript_Woman3::
	msgbox Unused_G2_M70_Text_Woman3, MSGBOX_NPC
	end

@ ShinyGold: moved from data/maps/Unused_G2_M70/scripts.inc (map removed)
Unused_G2_M70_EventScript_Gentleman::
	msgbox Unused_G2_M70_Text_Gentleman, MSGBOX_NPC
	end
