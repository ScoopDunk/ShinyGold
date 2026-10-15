Unused_ThreeIsland_House5_MapScripts::
	.byte 0

Unused_ThreeIsland_House5_EventScript_LittleGirl::
	lock
	faceplayer
	goto_if_set 0x2A3, Unused_ThreeIsland_House5_EventScript_LittleGirl_1
	msgbox Unused_ThreeIsland_House5_Text_LittleGirl_1
	release
	end

Unused_ThreeIsland_House5_EventScript_LittleGirl_1::
	msgbox Unused_ThreeIsland_House5_Text_LittleGirl_2
	release
	end
