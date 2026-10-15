Unused_PokemonLeague_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Unused_PokemonLeague_ChampionsRoom_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Unused_PokemonLeague_ChampionsRoom_OnFrame
	map_script MAP_SCRIPT_ON_FRAME_TABLE, 0x08162B6C  @ ShinyGold: shadowed by the first entry of this type (never used)
	.byte 0

Unused_PokemonLeague_ChampionsRoom_OnResume::
	release
	applymovement LOCALID_PLAYER, Unused_PokemonLeague_ChampionsRoom_Movement_OnResume
	delay 64
	end

Unused_PokemonLeague_ChampionsRoom_OnFrame::
	@ ShinyGold: overlapping data duplicated from 0x08162A02
	map_script_2 0x1212, 0x1212, 0x12121212  @ ShinyGold: always matches (constant operands)
	map_script_2 0x1112, 0x1111, 0x11111111  @ ShinyGold: can never match
	map_script_2 0xFE11, 0x5A6A, 0x0C800416  @ ShinyGold: reads past gSpecialVars (undefined behaviour, differs between builds)
	map_script_2 0x1600, VAR_0x8005, 0x74250002
	map_script_2 0x2B01, 0x4BB, 0x2AA10106  @ ShinyGold: can never match
	map_script_2 0x0816, 0x416, 0x16000C80  @ ShinyGold: can never match
	map_script_2 VAR_0x8005, 0, 0x16017325
	map_script_2 VAR_0x8004, 12, 0x01800516
	map_script_2 0x2500, 0x173, 0x07082C2B  @ ShinyGold: can never match
	map_script_2 0x7900, 0x162A, Unused_PokemonLeague_ChampionsRoom_EventScript_FrameScene10
	map_script_2 0x0107, 0x2A82, 0x03290816  @ ShinyGold: can never match
	map_script_2 0x2900, 5, 0x0708442B  @ ShinyGold: can never match
	map_script_2 0x8B00, 0x162A, Unused_PokemonLeague_ChampionsRoom_EventScript_FrameScene13  @ ShinyGold: reads past gSpecialVars (undefined behaviour, differs between builds)
	map_script_2 0x0107, 0x2A96, 0x052A0816  @ ShinyGold: can never match
	map_script_2 0x0500, 0x2AAB, 0x0F020816  @ ShinyGold: can never match
	map_script_2 0x6400, 0x1787, 0x03040908
	map_script_2 0x000F, 0x88BD, 0x04090817  @ ShinyGold: reads past gSpecialVars (undefined behaviour, differs between builds)
	map_script_2 0x5C03, 0x9D03, 0x15000001  @ ShinyGold: reads past gSpecialVars (undefined behaviour, differs between builds)
	map_script_2 0x178A, 0x308, 0x02E2035C  @ ShinyGold: can never match
	.2byte 0

Unused_PokemonLeague_ChampionsRoom_EventScript_FrameScene10::
	setvar 0x0000, 0x1620
	nop
	nop
	compare_ptr_to_ptr 0x20000016, 0x20000016
	setvar 0x0000, 32
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	compare_ptr_to_ptr 0x20000065, 0x20000000
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	playbgm MUS_DUMMY, 0
	playbgm MUS_DUMMY, 0
	nop
	nop
	nop
	compare_ptr_to_ptr 0x20000000, 0x20000000
	nop
	nop
	nop
	compare_ptr_to_ptr 0x200000A3, 0x00000000
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	compare_ptr_to_ptr 0x20000000, 0x20000000
	nop
	nop
	nop
	compare_ptr_to_ptr 0x20000000, 0x20000000
	nop
	nop
	nop
	compare_ptr_to_ptr 0x20000096, 0x20000000
	nop
	nop
	nop
	compare_ptr_to_ptr 0x20000000, 0x00000000
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	pokemartdecoration2 0x98729972
	drawbox
	resetobjectsubpriority 114, MAP_BATTLE_COLOSSEUM_2P
	nop
	nop
	nop
	nop
	nop
	setobjectsubpriority 43634, ((114 << 8) | 136), 114
	playslotmachine 114
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	loadbyte 80, 16
	applymovement 20496, 0x00007683, MAP_BATTLE_COLOSSEUM_2P
	nop
	nop
	nop
	nop
	loadbyte 80, 16
	applymovement 30338, 0x00007281, MAP_BATTLE_COLOSSEUM_2P
	nop
	nop
	nop
	nop
	loadbyte 80, 16
	applymovement 29313, 0x00007281, MAP_BATTLE_COLOSSEUM_2P
	nop
	nop
	nop
	nop
	loadbyte 80, 16
	applymovement 29313, 0x00007282, MAP_BATTLE_COLOSSEUM_2P
	nop
	nop
	nop
	nop
	loadbyte 80, 16
	applymovement 29315, 0x00005010, MAP_BATTLE_COLOSSEUM_2P
	nop
	nop
	nop
	nop
	pokemartdecoration 0x87728872
	drawbox
	pokemartdecoration2 0x00000072
	nop
	nop
	nop
	nop
	nop
	pokemartdecoration2 0x88728872
	drawbox
	pokemartdecoration2 0x00000072
	nop
	nop
	nop
	nop
	nop
	pokemartdecoration2 0x88728972
	drawbox
	playslotmachine 114
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	loadbyte 80, 147
	hidemonpic
	loadbyte 80, 163
	hidemonpic
	nop
	nop
	nop
	nop
	nop
	nop
	resetweather
	hidemonpic
	checkmoney 0xA2729176, 118
	playmoncry SPECIES_TANGELA, CRY_MODE_NORMAL
	nop
	nop
	nop
	nop
	nop
	removemoney 0xA1729172, 114
	playmoncry SPECIES_TANGELA, CRY_MODE_NORMAL
	nop
	nop
	nop
	nop
	nop
	removemoney 0xA1729272, 114
	setmetatile 114, 0, 0, 0
	nop
	showmoneybox 114, 16, 80
	resetweather
	drawbox
	loadbyte 80, 0
	nop
	nop
	nop
	resetweather
	drawbox
	nop
	nop
	pokemartdecoration 0x97728872
	drawbox
	fadescreenspeed 114, 0
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	pokemartdecoration2 0x98728872
	drawbox
	fadescreenspeed 114, 0
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	pokemartdecoration2 0x98729972
	drawbox
	setweather 0x72
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	loadbyte 80, 163
	hidemonpic
	loadbyte 80, 163
	hidemonpic
	nop
	nop
	resetweather
	hidemonpic
	nop
	nop
	resetweather
	hidemonpic
	bufferstdstring 114, 0x7285
	pokemartdecoration 0x00728872
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	bufferstring 114, 0x72887285
	pokemartdecoration2 0x00000072
	nop
	nop
	nop
	nop
	nop
	bufferstring 114, 0x72887286
	playslotmachine 114
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	resetweather
	drawbox
	loadbyte 80, 163
	drawbox
	loadbyte 80, 163
	drawbox
	nop
	nop
	resetweather
	drawbox
	nop
	nop
	fadescreen 114
	fadescreenspeed 114, 151
	drawbox
	fadescreenspeed 114, 0
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	fadescreenspeed 114, 152
	drawbox
	fadescreenspeed 114, 152
	drawbox
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	fadescreenspeed 114, 169
	drawbox
	fadescreenspeed 114, 169
	drawbox
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	loadbyte 88, 163
	hidemonpic
	loadbyte 88, 148
	drawbox
	nop
	gotostd 163

Unused_PokemonLeague_ChampionsRoom_EventScript_FrameScene13::
	nop
	waitmovement 40140
	bufferitemname STR_VAR_1, 0x9C7B
	setflashlevel 0xC6C9
	bufferboxname 153, 0x2299
	comparestat 156, 0xC99C1400
	waitmessage
	waitse
	animateflash 201
	removedecoration 108
	return

Unused_PokemonLeague_ChampionsRoom_Movement_OnResume::
	walk_up
	walk_up
	walk_up
	step_end
