#include "constants/global.h"
#include "constants/flags.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"
#include "constants/decorations.h"
#include "constants/items.h"
#include "constants/layouts.h"
#include "constants/maps.h"
#include "constants/metatile_labels.h"
#include "constants/pokemon.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/sound.h"
#include "constants/species.h"
#include "constants/vars.h"
#include "constants/battle.h"
#include "constants/heal_locations.h"
#include "constants/field_effects.h"
#include "constants/trainers.h"
#include "constants/trainer_tower.h"
#include "constants/fame_checker.h"
#include "constants/seagallop.h"
#include "constants/game_stat.h"
#include "constants/coins.h"
#include "constants/menu.h"
#include "constants/battle_setup.h"
#include "constants/map_scripts.h"
#include "constants/cable_club.h"
#include "constants/field_tasks.h"
#include "constants/field_weather.h"
#include "constants/weather.h"
#include "constants/union_room.h"
#include "constants/trade.h"
#include "constants/quest_log.h"
#include "constants/daycare.h"
#include "constants/easy_chat.h"
#include "constants/trainer_card.h"
#include "constants/help_system.h"
#include "constants/trainer_fan_club.h"
#include "constants/mystery_gift.h"
	.include "asm/macros.inc"
	.include "asm/macros/event.inc"
	.set FALSE, 0
	.set TRUE,  1

	.section script_data, "aw", %progbits

	.include "data/script_cmd_table.inc"

	.align 2
gSpecialVars::
	.4byte gSpecialVar_0x8000
	.4byte gSpecialVar_0x8001
	.4byte gSpecialVar_0x8002
	.4byte gSpecialVar_0x8003
	.4byte gSpecialVar_0x8004
	.4byte gSpecialVar_0x8005
	.4byte gSpecialVar_0x8006
	.4byte gSpecialVar_0x8007
	.4byte gSpecialVar_0x8008
	.4byte gSpecialVar_0x8009
	.4byte gSpecialVar_0x800A
	.4byte gSpecialVar_0x800B
	.4byte gSpecialVar_Facing
	.4byte gSpecialVar_Result
	.4byte gSpecialVar_ItemId
	.4byte gSpecialVar_LastTalked
	.4byte gSpecialVar_MonBoxId
	.4byte gSpecialVar_MonBoxPos
	.4byte gSpecialVar_TextColor
	.4byte gSpecialVar_PrevTextColor
	.4byte gSpecialVar_0x8014

	.include "data/specials.inc"

	.align 2
gStdScripts::
	.4byte Std_ObtainItem           @ STD_OBTAIN_ITEM
	.4byte Std_FindItem             @ STD_FIND_ITEM
	.4byte Std_MsgboxNPC            @ MSGBOX_NPC
	.4byte Std_MsgboxSign           @ MSGBOX_SIGN
	.4byte Std_MsgboxDefault        @ MSGBOX_DEFAULT
	.4byte Std_MsgboxYesNo          @ MSGBOX_YESNO
	.4byte Std_MsgboxAutoclose      @ MSGBOX_AUTOCLOSE
	.4byte Std_ObtainDecoration     @ STD_OBTAIN_DECORATION
	.4byte Std_PutItemAway          @ STD_PUT_ITEM_AWAY
	.4byte Std_ReceivedItem         @ STD_RECEIVED_ITEM
gStdScriptsEnd::

	.include "data/maps/BattleColosseum_2P/scripts.inc"
	.include "data/maps/TradeCenter/scripts.inc"
	.include "data/maps/RecordCorner/scripts.inc"
	.include "data/maps/BattleColosseum_4P/scripts.inc"
	.include "data/maps/UnionRoom/scripts.inc"
	.include "data/maps/MtMoon_Cave1/scripts.inc"
	.include "data/maps/MtSilver_Cave1/scripts.inc"
	.include "data/maps/SSAqua_Interior2/scripts.inc"
	.include "data/maps/SSAqua_Interior3/scripts.inc"
	.include "data/maps/SSAqua_Interior4/scripts.inc"
	.include "data/maps/SSAqua_Interior8/scripts.inc"
	.include "data/maps/SSAqua_Interior9/scripts.inc"
	.include "data/maps/SSAqua_Interior11/scripts.inc"
	.include "data/maps/SSAqua_Interior12/scripts.inc"
	.include "data/maps/SSAqua_Interior16/scripts.inc"
	.include "data/maps/SSAqua_Interior17/scripts.inc"
	.include "data/maps/SSAqua_Interior18/scripts.inc"
	.include "data/maps/SSAqua_Interior19/scripts.inc"
	.include "data/maps/Route5_Interior1/scripts.inc"
	.include "data/maps/SaffronCity_Interior1/scripts.inc"
	.include "data/maps/Route6_Interior1/scripts.inc"
	.include "data/maps/DiglettsCave_Cave1/scripts.inc"
	.include "data/maps/DiglettsCave_Cave2/scripts.inc"
	.include "data/maps/DiglettsCave_Cave3/scripts.inc"
	.include "data/maps/SilphCo_Interior1/scripts.inc"
	.include "data/maps/VictoryRoad_Cave1/scripts.inc"
	.include "data/maps/VictoryRoad_Cave2/scripts.inc"
	.include "data/maps/VictoryRoad_Cave3/scripts.inc"
	.include "data/maps/VictoryRoad_Cave4/scripts.inc"
	.include "data/maps/IndigoPlateau_Interior1/scripts.inc"
	.include "data/maps/IndigoPlateau_Interior2/scripts.inc"
	.include "data/maps/IndigoPlateau_Interior3/scripts.inc"
	.include "data/maps/IndigoPlateau_Interior4/scripts.inc"
	.include "data/maps/IndigoPlateau_HallOfFame/scripts.inc"
	.include "data/maps/RockTunnel_Cave2/scripts.inc"
	.include "data/maps/RockTunnel_Cave3/scripts.inc"
	.include "data/maps/Route28_Interior1/scripts.inc"
	.include "data/maps/MtSilver_Interior1/scripts.inc"
	.include "data/maps/PowerPlant_Interior1/scripts.inc"
	.include "data/maps/WhirlIslands_Cave1/scripts.inc"
	.include "data/maps/WhirlIslands_Cave2/scripts.inc"
	.include "data/maps/WhirlIslands_Cave3/scripts.inc"
	.include "data/maps/MtSilver_Cave2/scripts.inc"
	.include "data/maps/WhirlIslands_Cave4/scripts.inc"
	.include "data/maps/WhirlIslands_Cave5/scripts.inc"
	.include "data/maps/WhirlIslands_Cave6/scripts.inc"
	.include "data/maps/WhirlIslands_Cave7/scripts.inc"
	.include "data/maps/WhirlIslands_Cave8/scripts.inc"
	.include "data/maps/MtSilver_Cave3/scripts.inc"
	.include "data/maps/IcePath_Cave1/scripts.inc"
	.include "data/maps/IcePath_Cave2/scripts.inc"
	.include "data/maps/IcePath_Cave3/scripts.inc"
	.include "data/maps/IcePath_Cave4/scripts.inc"
	.include "data/maps/IcePath_Cave5/scripts.inc"
	.include "data/maps/IcePath_Cave6/scripts.inc"
	.include "data/maps/TohjoFalls_Cave1/scripts.inc"
	.include "data/maps/Route20_Interior1/scripts.inc"
	.include "data/maps/Route30_Interior1/scripts.inc"
	.include "data/maps/RuinsOfAlph/scripts.inc"
	.include "data/maps/UnionCave_Cave1/scripts.inc"
	.include "data/maps/UnionCave_Cave2/scripts.inc"
	.include "data/maps/UnionCave_Cave3/scripts.inc"
	.include "data/maps/SlowpokeWell_Cave1/scripts.inc"
	.include "data/maps/IlexForest_Interior1/scripts.inc"
	.include "data/maps/GoldenrodCity_Interior1/scripts.inc"
	.include "data/maps/GoldenrodCity_Interior2/scripts.inc"
	.include "data/maps/Route35/scripts.inc"
	.include "data/maps/LavenderTown_Cave1/scripts.inc"
	.include "data/maps/Route36/scripts.inc"
	.include "data/maps/Route31/scripts.inc"
	.include "data/maps/Route30/scripts.inc"
	.include "data/maps/RuinsOfAlph_Cave1/scripts.inc"
	.include "data/maps/RuinsOfAlph_Cave2/scripts.inc"
	.include "data/maps/RuinsOfAlph_Cave3/scripts.inc"
	.include "data/maps/Route37/scripts.inc"
	.include "data/maps/Route38/scripts.inc"
	.include "data/maps/Route39/scripts.inc"
	.include "data/maps/Route45/scripts.inc"
	.include "data/maps/Route40/scripts.inc"
	.include "data/maps/Route41/scripts.inc"
	.include "data/maps/MtMortar_Cave1/scripts.inc"
	.include "data/maps/MtMortar_Cave2/scripts.inc"
	.include "data/maps/MtMortar_Cave3/scripts.inc"
	.include "data/maps/MtMortar_Cave4/scripts.inc"
	.include "data/maps/LakeOfRage/scripts.inc"
	.include "data/maps/MahoganyTown_RocketBase_B1F/scripts.inc"
	.include "data/maps/MahoganyTown_RocketBase_B2F/scripts.inc"
	.include "data/maps/MahoganyTown_RocketBase_B3F/scripts.inc"
	.include "data/maps/Route44/scripts.inc"
	.include "data/maps/Route26/scripts.inc"
	.include "data/maps/Route27/scripts.inc"
	.include "data/maps/Route26_Area1/scripts.inc"
	.include "data/maps/SproutTower_Interior1/scripts.inc"
	.include "data/maps/RuinsOfAlph_InnerChamber/scripts.inc"
	.include "data/maps/RuinsOfAlph_Interior1/scripts.inc"
	.include "data/maps/Route29_Interior1/scripts.inc"
	.include "data/maps/Route29_Interior1/text.inc"
	.include "data/maps/DarkCave_Cave1/scripts.inc"
	.include "data/maps/DarkCave_Cave2/scripts.inc"
	.include "data/maps/DarkCave_Cave2/text.inc"
	.include "data/maps/Route33/scripts.inc"
	.include "data/maps/VioletCity_Interior1/scripts.inc"
	.include "data/maps/VioletCity_Interior1/text.inc"
	.include "data/maps/SproutTower_Interior2/scripts.inc"
	.include "data/maps/SproutTower_Interior2/text.inc"
	.include "data/maps/Route35_Interior1/scripts.inc"
	.include "data/maps/Route46/scripts.inc"
	.include "data/maps/EcruteakCity_Interior1/scripts.inc"
	.include "data/maps/EcruteakCity_Cave1/scripts.inc"
	.include "data/maps/EcruteakCity_Interior2/scripts.inc"
	.include "data/maps/SlowpokeWell_Cave2/scripts.inc"
	.include "data/maps/RuinsOfAlph_Interior2/scripts.inc"
	.include "data/maps/RuinsOfAlph_Interior3/scripts.inc"
	.include "data/maps/Lighthouse_Interior2/scripts.inc"
	.include "data/maps/EcruteakCity_Interior3/scripts.inc"
	.include "data/maps/MahoganyTown_Interior1/scripts.inc"
	.include "data/maps/MahoganyTown_Interior2/scripts.inc"
	.include "data/maps/Route43_Interior1/scripts.inc"
	.include "data/maps/DragonsDen_Cave3/scripts.inc"
	.include "data/maps/DragonsDen_Cave4/scripts.inc"
	.include "data/maps/NationalPark_BugContest/scripts.inc"
	.include "data/maps/NationalPark_BugContest/text.inc"
	.include "data/maps/NewBarkTown/scripts.inc"
	.include "data/maps/ViridianCity/scripts.inc"
	.include "data/maps/PewterCity/scripts.inc"
	.include "data/maps/CeruleanCity/scripts.inc"
	.include "data/maps/LavenderTown/scripts.inc"
	.include "data/maps/VermilionCity/scripts.inc"
	.include "data/maps/CeladonCity/scripts.inc"
	.include "data/maps/FuchsiaCity/scripts.inc"
	.include "data/maps/CinnabarIsland/scripts.inc"
	.include "data/maps/IndigoPlateau/scripts.inc"
	.include "data/maps/SaffronCity/scripts.inc"
	.include "data/maps/SaffronCity_Area1/scripts.inc"
	.include "data/maps/PalletTown/scripts.inc"
	.include "data/maps/VioletCity/scripts.inc"
	.include "data/maps/AzaleaTown/scripts.inc"
	.include "data/maps/GoldenrodCity/scripts.inc"
	.include "data/maps/EcruteakCity/scripts.inc"
	.include "data/maps/CianwoodCity/scripts.inc"
	.include "data/maps/OlivineCity/scripts.inc"
	.include "data/maps/Route1/scripts.inc"
	.include "data/maps/Route3/scripts.inc"
	.include "data/maps/Route4/scripts.inc"
	.include "data/maps/Route5/scripts.inc"
	.include "data/maps/Route6/scripts.inc"
	.include "data/maps/Route7/scripts.inc"
	.include "data/maps/Route8/scripts.inc"
	.include "data/maps/Route9/scripts.inc"
	.include "data/maps/Route10/scripts.inc"
	.include "data/maps/Route11/scripts.inc"
	.include "data/maps/Route12/scripts.inc"
	.include "data/maps/Route13/scripts.inc"
	.include "data/maps/Route14/scripts.inc"
	.include "data/maps/Route15/scripts.inc"
	.include "data/maps/Route16/scripts.inc"
	.include "data/maps/Route17/scripts.inc"
	.include "data/maps/Route18/scripts.inc"
	.include "data/maps/Route19/scripts.inc"
	.include "data/maps/Route20/scripts.inc"
	.include "data/maps/Route21/scripts.inc"
	.include "data/maps/Route22/scripts.inc"
	.include "data/maps/Route23/scripts.inc"
	.include "data/maps/Route24/scripts.inc"
	.include "data/maps/Route25/scripts.inc"
	.include "data/maps/NationalPark/scripts.inc"
	.include "data/maps/Route29/scripts.inc"
	.include "data/maps/Route29/text.inc"
	.include "data/maps/CherrygroveCity/scripts.inc"
	.include "data/maps/Route42/scripts.inc"
	.include "data/maps/Route32/scripts.inc"
	.include "data/maps/Route34/scripts.inc"
	.include "data/maps/MahoganyTown/scripts.inc"
	.include "data/maps/BlackthornCity/scripts.inc"
	.include "data/maps/Route2/scripts.inc"
	.include "data/maps/Route28/scripts.inc"
	.include "data/maps/MtSilver/scripts.inc"
	.include "data/maps/PalletTown_Area1/scripts.inc"
	.include "data/maps/Route43/scripts.inc"
	.include "data/maps/NewBarkTown_Interior1/scripts.inc"
	.include "data/maps/NewBarkTown_Interior2/scripts.inc"
	.include "data/maps/PalletTown_Interior1/scripts.inc"
	.include "data/maps/NewBarkTown_Interior3/scripts.inc"
	.include "data/maps/ViridianCity_Interior1/scripts.inc"
	.include "data/maps/ViridianCity_Interior2/scripts.inc"
	.include "data/maps/VioletCity_Interior2/scripts.inc"
	.include "data/maps/ViridianCity_Interior3/scripts.inc"
	.include "data/maps/ViridianCity_Interior4/scripts.inc"
	.include "data/maps/ViridianCity_Interior5/scripts.inc"
	.include "data/maps/PewterCity_Interior3/scripts.inc"
	.include "data/maps/PewterCity_Interior4/scripts.inc"
	.include "data/maps/PewterCity_Interior5/scripts.inc"
	.include "data/maps/PewterCity_Interior6/scripts.inc"
	.include "data/maps/PewterCity_Interior7/scripts.inc"
	.include "data/maps/PewterCity_Interior8/scripts.inc"
	.include "data/maps/CeruleanCity_Interior1/scripts.inc"
	.include "data/maps/ViridianCity_Interior6/scripts.inc"
	.include "data/maps/CeruleanCity_Interior2/scripts.inc"
	.include "data/maps/CeruleanCity_Interior3/scripts.inc"
	.include "data/maps/CeruleanCity_Interior4/scripts.inc"
	.include "data/maps/CeruleanCity_Gym/scripts.inc"
	.include "data/maps/MtMoon_Interior1/scripts.inc"
	.include "data/maps/CeruleanCity_Interior5/scripts.inc"
	.include "data/maps/CeruleanCity_Interior6/scripts.inc"
	.include "data/maps/CeruleanCity_Interior7/scripts.inc"
	.include "data/maps/LavenderTown_Interior3/scripts.inc"
	.include "data/maps/LavenderTown_Interior4/scripts.inc"
	.include "data/maps/GoldenrodCity_Interior3/scripts.inc"
	.include "data/maps/LavenderTown_Interior5/scripts.inc"
	.include "data/maps/VermilionCity_Interior10/scripts.inc"
	.include "data/maps/VermilionCity_Interior11/scripts.inc"
	.include "data/maps/VermilionCity_Interior12/scripts.inc"
	.include "data/maps/VermilionCity_Interior13/scripts.inc"
	.include "data/maps/VermilionCity_Interior14/scripts.inc"
	.include "data/maps/VermilionCity_Interior15/scripts.inc"
	.include "data/maps/VermilionCity_Interior16/scripts.inc"
	.include "data/maps/VermilionCity_Interior17/scripts.inc"
	.include "data/maps/CeladonCity_Interior1/scripts.inc"
	.include "data/maps/CeladonCity_Interior2/scripts.inc"
	.include "data/maps/CeladonCity_Interior3/scripts.inc"
	.include "data/maps/CeladonCity_Interior4/scripts.inc"
	.include "data/maps/CeladonCity_Interior5/scripts.inc"
	.include "data/maps/CeladonCity_Interior6/scripts.inc"
	.include "data/maps/CeladonCity_Interior7/scripts.inc"
	.include "data/maps/CeladonCity_Interior8/scripts.inc"
	.include "data/maps/CeladonCity_Interior9/scripts.inc"
	.include "data/maps/CeladonCity_Interior10/scripts.inc"
	.include "data/maps/CeladonCity_Interior11/scripts.inc"
	.include "data/maps/CeladonCity_Interior12/scripts.inc"
	.include "data/maps/CeladonCity_Interior13/scripts.inc"
	.include "data/maps/CeladonCity_Interior14/scripts.inc"
	.include "data/maps/FuchsiaCity_Interior5/scripts.inc"
	.include "data/maps/FuchsiaCity_Interior6/scripts.inc"
	.include "data/maps/FuchsiaCity_Interior7/scripts.inc"
	.include "data/maps/FuchsiaCity_Interior8/scripts.inc"
	.include "data/maps/FuchsiaCity_Interior9/scripts.inc"
	.include "data/maps/FuchsiaCity_Interior10/scripts.inc"
	.include "data/maps/FuchsiaCity_Interior11/scripts.inc"
	.include "data/maps/Route19_Interior1/scripts.inc"
	.include "data/maps/BlackthornCity_Interior1/scripts.inc"
	.include "data/maps/PalletTown_Interior2/scripts.inc"
	.include "data/maps/PalletTown_Interior3/scripts.inc"
	.include "data/maps/CinnabarIsland_Interior2/scripts.inc"
	.include "data/maps/CinnabarIsland_Interior3/scripts.inc"
	.include "data/maps/IndigoPlateau_Interior5/scripts.inc"
	.include "data/maps/IndigoPlateau_Interior6/scripts.inc"
	.include "data/maps/SaffronCity_Interior2/scripts.inc"
	.include "data/maps/SaffronCity_Interior3/scripts.inc"
	.include "data/maps/SaffronCity_Interior4/scripts.inc"
	.include "data/maps/SaffronCity_Interior5/scripts.inc"
	.include "data/maps/SaffronCity_Interior6/scripts.inc"
	.include "data/maps/SaffronCity_Interior7/scripts.inc"
	.include "data/maps/SaffronCity_Interior8/scripts.inc"
	.include "data/maps/SaffronCity_Interior9/scripts.inc"
	.include "data/maps/Route2_Interior2/scripts.inc"
	.include "data/maps/Route2_Interior4/scripts.inc"
	.include "data/maps/MahoganyTown_Interior3/scripts.inc"
	.include "data/maps/MahoganyTown_Interior4/scripts.inc"
	.include "data/maps/Route5_Interior2/scripts.inc"
	.include "data/maps/Route5_Interior3/scripts.inc"
	.include "data/maps/Route6_Interior2/scripts.inc"
	.include "data/maps/Route26_Interior1/scripts.inc"
	.include "data/maps/Route7_Interior1/scripts.inc"
	.include "data/maps/Route8_Interior1/scripts.inc"
	.include "data/maps/BlackthornCity_Interior3/scripts.inc"
	.include "data/maps/BlackthornCity_Interior4/scripts.inc"
	.include "data/maps/Route12_Interior1/scripts.inc"
	.include "data/maps/Route15_Interior1/scripts.inc"
	.include "data/maps/Route16_Interior1/scripts.inc"
	.include "data/maps/Route16_Interior2/scripts.inc"
	.include "data/maps/Route18_Interior1/scripts.inc"
	.include "data/maps/Route27_Interior1/scripts.inc"
	.include "data/maps/BlackthornCity_Interior5/scripts.inc"
	.include "data/maps/Route25_Interior1/scripts.inc"
	.include "data/maps/BlackthornCity_Interior6/scripts.inc"
	.include "data/maps/CianwoodCity_Interior1/scripts.inc"
	.include "data/maps/CianwoodCity_Interior2/scripts.inc"
	.include "data/maps/CianwoodCity_Interior3/scripts.inc"
	.include "data/maps/CianwoodCity_Interior3/text.inc"
	.include "data/maps/CianwoodCity_Interior4/scripts.inc"
	.include "data/maps/CherrygroveCity_Interior1/scripts.inc"
	.include "data/maps/CherrygroveCity_Interior2/scripts.inc"
	.include "data/maps/NewBarkTown_Interior4/scripts.inc"
	.include "data/maps/CianwoodCity_Interior5/scripts.inc"
	.include "data/maps/Route39_Interior1/scripts.inc"
	.include "data/maps/NewBarkTown_Interior5/scripts.inc"
	.include "data/maps/CherrygroveCity_Interior3/scripts.inc"
	.include "data/maps/VioletCity_Interior3/scripts.inc"
	.include "data/maps/VioletCity_Interior4/scripts.inc"
	.include "data/maps/CherrygroveCity_Interior4/scripts.inc"
	.include "data/maps/Route36_Interior1/scripts.inc"
	.include "data/maps/Route36_Interior1/text.inc"
	.include "data/maps/RuinsOfAlph_Interior4/scripts.inc"
	.include "data/maps/Route30_Interior2/scripts.inc"
	.include "data/maps/AzaleaTown_Interior1/scripts.inc"
	.include "data/maps/AzaleaTown_Interior2/scripts.inc"
	.include "data/maps/VioletCity_Interior5/scripts.inc"
	.include "data/maps/VioletCity_Interior6/scripts.inc"
	.include "data/maps/AzaleaTown_Interior3/scripts.inc"
	.include "data/maps/VioletCity_Interior7/scripts.inc"
	.include "data/maps/VioletCity_Interior8/scripts.inc"
	.include "data/maps/CherrygroveCity_Interior5/scripts.inc"
	.include "data/maps/Route32_Interior1/scripts.inc"
	.include "data/maps/Route32_Interior2/scripts.inc"
	.include "data/maps/AzaleaTown_Interior4/scripts.inc"
	.include "data/maps/AzaleaTown_Interior5/scripts.inc"
	.include "data/maps/AzaleaTown_Interior6/scripts.inc"
	.include "data/maps/AzaleaTown_Interior7/scripts.inc"
	.include "data/maps/IlexForest_Interior2/scripts.inc"
	.include "data/maps/GoldenrodCity_Interior4/scripts.inc"
	.include "data/maps/GoldenrodCity_Interior5/scripts.inc"
	.include "data/maps/GoldenrodCity_Interior6/scripts.inc"
	.include "data/maps/GoldenrodCity_Interior7/scripts.inc"
	.include "data/maps/GoldenrodCity_Interior8/scripts.inc"
	.include "data/maps/GoldenrodCity_Interior9/scripts.inc"
	.include "data/maps/GoldenrodCity_Interior10/scripts.inc"
	.include "data/maps/GoldenrodCity_Interior11/scripts.inc"
	.include "data/maps/GoldenrodCity_Interior12/scripts.inc"
	.include "data/maps/GoldenrodCity_Interior13/scripts.inc"
	.include "data/maps/GoldenrodCity_Interior14/scripts.inc"
	.include "data/maps/GoldenrodCity_Interior15/scripts.inc"
	.include "data/maps/RadioTower_Interior1/scripts.inc"
	.include "data/maps/RadioTower_Interior2/scripts.inc"
	.include "data/maps/GoldenrodCity_Interior16/scripts.inc"
	.include "data/maps/NationalPark_Interior1/scripts.inc"
	.include "data/maps/NationalPark_Interior1/text.inc"
	.include "data/maps/NationalPark_Interior2/scripts.inc"
	.include "data/maps/EcruteakCity_Interior4/scripts.inc"
	.include "data/maps/EcruteakCity_Interior5/scripts.inc"
	.include "data/maps/EcruteakCity_Interior6/scripts.inc"
	.include "data/maps/EcruteakCity_Interior7/scripts.inc"
	.include "data/maps/EcruteakCity_Interior8/scripts.inc"
	.include "data/maps/Route39_Interior2/scripts.inc"
	.include "data/maps/OlivineCity_Interior1/scripts.inc"
	.include "data/maps/OlivineCity_Area1/scripts.inc"
	.include "data/maps/OlivineCity_Interior2/scripts.inc"
	.include "data/maps/OlivineCity_Interior3/scripts.inc"
	.include "data/maps/CianwoodCity_Interior6/scripts.inc"
	.include "data/maps/CianwoodCity_Interior7/scripts.inc"
	.include "data/maps/MahoganyTown_Interior5/scripts.inc"
	.include "data/maps/RadioTower_Interior3/scripts.inc"
	.include "data/maps/RadioTower_Interior4/scripts.inc"
	.include "data/maps/RadioTower_Interior5/scripts.inc"
	.include "data/maps/GoldenrodCity_Interior17/scripts.inc"
	.include "data/maps/GoldenrodCity_Interior18/scripts.inc"
	.include "data/maps/TinTower_UpperFloors/scripts.inc"
	.include "data/maps/TinTower_Roof/scripts.inc"
	.include "data/maps/BlackthornCity_Interior7/scripts.inc"
	.include "data/maps/BlackthornCity_Interior8/scripts.inc"
	.include "data/maps/Route26_Interior2/scripts.inc"
	.include "data/maps/IndigoPlateau_Interior7/scripts.inc"
	.include "data/maps/VermilionCity_Interior18/scripts.inc"
	.include "data/maps/VermilionCity_Area1/scripts.inc"
	.include "data/maps/SaffronCity_Interior10/scripts.inc"
	.include "data/maps/Route10_Interior1/scripts.inc"
	.include "data/maps/Route10_Interior2/scripts.inc"
	.include "data/maps/LavenderTown_Interior6/scripts.inc"
	.include "data/maps/LavRadioTower_Interior1/scripts.inc"
	.include "data/maps/CeladonCity_Interior16/scripts.inc"
	.include "data/maps/CeladonCity_Interior17/scripts.inc"
	.include "data/maps/CeladonCity_Interior18/scripts.inc"
	.include "data/maps/CeladonCity_Interior19/scripts.inc"
	.include "data/maps/LavenderTown_Interior7/scripts.inc"
	.include "data/maps/LavenderTown_Interior8/scripts.inc"
	.include "data/maps/Route34_Interior1/scripts.inc"
	.include "data/maps/GoldenrodCity_Interior19/scripts.inc"
	.include "data/maps/GoldenrodCity_Interior19/text.inc"
	.include "data/maps/GoldenrodCity_Interior20/scripts.inc"
	.include "data/maps/GoldenrodCity_Interior21/scripts.inc"
	.include "data/maps/GoldenrodCity_Interior22/scripts.inc"
	.include "data/maps/GoldenrodCity_Interior23/scripts.inc"
	.include "data/maps/GoldenrodCity_Interior24/scripts.inc"
	.include "data/maps/EcruteakCity_Interior9/scripts.inc"
	.include "data/maps/EcruteakCity_Interior10/scripts.inc"
	.include "data/maps/EcruteakCity_Interior11/scripts.inc"
	.include "data/maps/OlivineCity_Interior4/scripts.inc"
	.include "data/maps/EcruteakCity_Interior12/scripts.inc"
	.include "data/maps/EcruteakCity_Interior13/scripts.inc"
	.include "data/maps/OlivineCity_Interior5/scripts.inc"
	.include "data/maps/OlivineCity_Interior6/scripts.inc"
	.include "data/maps/OlivineCity_Interior7/scripts.inc"
	.include "data/maps/OlivineCity_Interior8/scripts.inc"
	.include "data/maps/OlivineCity_Interior9/scripts.inc"
	.include "data/maps/MahoganyTown_Interior6/scripts.inc"
	.include "data/maps/CherrygroveCity_Interior6/scripts.inc"
	.include "data/maps/LakeOfRage_Interior1/scripts.inc"
	.include "data/maps/LakeOfRage_Interior2/scripts.inc"
	.include "data/maps/BlackthornCity_Interior9/scripts.inc"

	.include "data/maps/MtMoon_Cave1/text.inc"
	.include "data/maps/MtSilver_Cave1/text.inc"
	.include "data/maps/SSAqua_Interior2/text.inc"
	.include "data/maps/SSAqua_Interior3/text.inc"
	.include "data/maps/SSAqua_Interior4/text.inc"
	.include "data/maps/SSAqua_Interior8/text.inc"
	.include "data/maps/SSAqua_Interior9/text.inc"
	.include "data/maps/SSAqua_Interior11/text.inc"
	.include "data/maps/SSAqua_Interior12/text.inc"
	.include "data/maps/SSAqua_Interior16/text.inc"
	.include "data/maps/SSAqua_Interior17/text.inc"
	.include "data/maps/SSAqua_Interior18/text.inc"
	.include "data/maps/SSAqua_Interior19/text.inc"
	.include "data/maps/Route5_Interior1/text.inc"
	.include "data/maps/Route6_Interior1/text.inc"
	.include "data/maps/DiglettsCave_Cave1/text.inc"
	.include "data/maps/DiglettsCave_Cave2/text.inc"
	.include "data/maps/DiglettsCave_Cave3/text.inc"
	.include "data/maps/SilphCo_Interior1/text.inc"
	.include "data/maps/VictoryRoad_Cave1/text.inc"
	.include "data/maps/VictoryRoad_Cave2/text.inc"
	.include "data/maps/VictoryRoad_Cave4/text.inc"
	.include "data/maps/IndigoPlateau_Interior1/text.inc"
	.include "data/maps/IndigoPlateau_Interior2/text.inc"
	.include "data/maps/IndigoPlateau_Interior3/text.inc"
	.include "data/maps/IndigoPlateau_Interior4/text.inc"
	.include "data/maps/IndigoPlateau_HallOfFame/text.inc"
	.include "data/maps/RockTunnel_Cave2/text.inc"
	.include "data/maps/Route28_Interior1/text.inc"
	.include "data/maps/MtSilver_Interior1/text.inc"
	.include "data/maps/PowerPlant_Interior1/text.inc"
	.include "data/maps/MtSilver_Cave3/text.inc"
	.include "data/maps/Route20_Interior1/text.inc"
	.include "data/maps/Route30_Interior1/text.inc"
	.include "data/maps/RuinsOfAlph/text.inc"
	.include "data/maps/UnionCave_Cave1/text.inc"
	.include "data/maps/UnionCave_Cave2/text.inc"
	.include "data/maps/UnionCave_Cave3/text.inc"
	.include "data/maps/SlowpokeWell_Cave1/text.inc"
	.include "data/maps/IlexForest_Interior1/text.inc"
	.include "data/maps/GoldenrodCity_Interior1/text.inc"
	.include "data/maps/GoldenrodCity_Interior2/text.inc"
	.include "data/maps/Route35/text.inc"
	.include "data/maps/LavenderTown_Cave1/text.inc"
	.include "data/maps/Route36/text.inc"
	.include "data/maps/Route31/text.inc"
	.include "data/maps/Route30/text.inc"
	.include "data/maps/RuinsOfAlph_Cave1/text.inc"
	.include "data/maps/RuinsOfAlph_Cave2/text.inc"
	.include "data/maps/Route37/text.inc"
	.include "data/maps/Route38/text.inc"
	.include "data/maps/Route39/text.inc"
	.include "data/maps/Route45/text.inc"
	.include "data/maps/Route40/text.inc"
	.include "data/maps/Route41/text.inc"
	.include "data/maps/MtMortar_Cave2/text.inc"
	.include "data/maps/MtMortar_Cave4/text.inc"
	.include "data/maps/LakeOfRage/text.inc"
	.include "data/maps/MahoganyTown_RocketBase_B1F/text.inc"
	.include "data/maps/MahoganyTown_RocketBase_B2F/text.inc"
	.include "data/maps/MahoganyTown_RocketBase_B3F/text.inc"
	.include "data/maps/Route44/text.inc"
	.include "data/maps/Route26/text.inc"
	.include "data/maps/Route27/text.inc"
	.include "data/maps/Route26_Area1/text.inc"
	.include "data/maps/SproutTower_Interior1/text.inc"
	.include "data/maps/RuinsOfAlph_Interior1/text.inc"
	.include "data/maps/DarkCave_Cave1/text.inc"
	.include "data/maps/Route33/text.inc"
	.include "data/maps/Route35_Interior1/text.inc"
	.include "data/maps/Route46/text.inc"
	.include "data/maps/EcruteakCity_Interior1/text.inc"
	.include "data/maps/EcruteakCity_Cave1/text.inc"
	.include "data/maps/EcruteakCity_Interior2/text.inc"
	.include "data/maps/SlowpokeWell_Cave2/text.inc"
	.include "data/maps/Lighthouse_Interior2/text.inc"
	.include "data/maps/EcruteakCity_Interior3/text.inc"
	.include "data/maps/MahoganyTown_Interior1/text.inc"
	.include "data/maps/MahoganyTown_Interior2/text.inc"
	.include "data/maps/Route43_Interior1/text.inc"
	.include "data/maps/DragonsDen_Cave4/text.inc"
	.include "data/maps/NewBarkTown/text.inc"
	.include "data/maps/ViridianCity/text.inc"
	.include "data/maps/PewterCity/text.inc"
	.include "data/maps/CeruleanCity/text.inc"
	.include "data/maps/LavenderTown/text.inc"
	.include "data/maps/VermilionCity/text.inc"
	.include "data/maps/CeladonCity/text.inc"
	.include "data/maps/FuchsiaCity/text.inc"
	.include "data/maps/CinnabarIsland/text.inc"
	.include "data/maps/SaffronCity/text.inc"
	.include "data/maps/PalletTown/text.inc"
	.include "data/maps/VioletCity/text.inc"
	.include "data/maps/AzaleaTown/text.inc"
	.include "data/maps/GoldenrodCity/text.inc"
	.include "data/maps/EcruteakCity/text.inc"
	.include "data/maps/CianwoodCity/text.inc"
	.include "data/maps/OlivineCity/text.inc"
	.include "data/maps/Route1/text.inc"
	.include "data/maps/Route3/text.inc"
	.include "data/maps/Route4/text.inc"
	.include "data/maps/Route5/text.inc"
	.include "data/maps/Route6/text.inc"
	.include "data/maps/Route7/text.inc"
	.include "data/maps/Route8/text.inc"
	.include "data/maps/Route9/text.inc"
	.include "data/maps/Route10/text.inc"
	.include "data/maps/Route11/text.inc"
	.include "data/maps/Route12/text.inc"
	.include "data/maps/Route13/text.inc"
	.include "data/maps/Route14/text.inc"
	.include "data/maps/Route15/text.inc"
	.include "data/maps/Route16/text.inc"
	.include "data/maps/Route17/text.inc"
	.include "data/maps/Route18/text.inc"
	.include "data/maps/Route19/text.inc"
	.include "data/maps/Route20/text.inc"
	.include "data/maps/Route21/text.inc"
	.include "data/maps/Route22/text.inc"
	.include "data/maps/Route23/text.inc"
	.include "data/maps/Route24/text.inc"
	.include "data/maps/Route25/text.inc"
	.include "data/maps/NationalPark/text.inc"
	.include "data/maps/CherrygroveCity/text.inc"
	.include "data/maps/Route42/text.inc"
	.include "data/maps/Route32/text.inc"
	.include "data/maps/Route34/text.inc"
	.include "data/maps/MahoganyTown/text.inc"
	.include "data/maps/BlackthornCity/text.inc"
	.include "data/maps/Route2/text.inc"
	.include "data/maps/Route28/text.inc"
	.include "data/maps/MtSilver/text.inc"
	.include "data/maps/PalletTown_Area1/text.inc"
	.include "data/maps/Route43/text.inc"
	.include "data/maps/NewBarkTown_Interior1/text.inc"
	.include "data/maps/NewBarkTown_Interior2/text.inc"
	.include "data/maps/PalletTown_Interior1/text.inc"
	.include "data/maps/NewBarkTown_Interior3/text.inc"
	.include "data/maps/ViridianCity_Interior1/text.inc"
	.include "data/maps/ViridianCity_Interior2/text.inc"
	.include "data/maps/VioletCity_Interior2/text.inc"
	.include "data/maps/ViridianCity_Interior3/text.inc"
	.include "data/maps/ViridianCity_Interior4/text.inc"
	.include "data/maps/PewterCity_Interior3/text.inc"
	.include "data/maps/PewterCity_Interior4/text.inc"
	.include "data/maps/PewterCity_Interior5/text.inc"
	.include "data/maps/PewterCity_Interior6/text.inc"
	.include "data/maps/PewterCity_Interior8/text.inc"
	.include "data/maps/CeruleanCity_Interior1/text.inc"
	.include "data/maps/ViridianCity_Interior6/text.inc"
	.include "data/maps/CeruleanCity_Interior2/text.inc"
	.include "data/maps/CeruleanCity_Interior3/text.inc"
	.include "data/maps/CeruleanCity_Gym/text.inc"
	.include "data/maps/MtMoon_Interior1/text.inc"
	.include "data/maps/CeruleanCity_Interior5/text.inc"
	.include "data/maps/CeruleanCity_Interior6/text.inc"
	.include "data/maps/LavenderTown_Interior3/text.inc"
	.include "data/maps/LavenderTown_Interior4/text.inc"
	.include "data/maps/LavenderTown_Interior5/text.inc"
	.include "data/maps/VermilionCity_Interior10/text.inc"
	.include "data/maps/VermilionCity_Interior11/text.inc"
	.include "data/maps/VermilionCity_Interior13/text.inc"
	.include "data/maps/VermilionCity_Interior14/text.inc"
	.include "data/maps/VermilionCity_Interior15/text.inc"
	.include "data/maps/VermilionCity_Interior16/text.inc"
	.include "data/maps/VermilionCity_Interior17/text.inc"
	.include "data/maps/CeladonCity_Interior1/text.inc"
	.include "data/maps/CeladonCity_Interior2/text.inc"
	.include "data/maps/CeladonCity_Interior3/text.inc"
	.include "data/maps/CeladonCity_Interior4/text.inc"
	.include "data/maps/CeladonCity_Interior5/text.inc"
	.include "data/maps/CeladonCity_Interior6/text.inc"
	.include "data/maps/CeladonCity_Interior8/text.inc"
	.include "data/maps/CeladonCity_Interior9/text.inc"
	.include "data/maps/CeladonCity_Interior11/text.inc"
	.include "data/maps/CeladonCity_Interior12/text.inc"
	.include "data/maps/CeladonCity_Interior13/text.inc"
	.include "data/maps/CeladonCity_Interior14/text.inc"
	.include "data/maps/FuchsiaCity_Interior5/text.inc"
	.include "data/maps/FuchsiaCity_Interior6/text.inc"
	.include "data/maps/FuchsiaCity_Interior7/text.inc"
	.include "data/maps/FuchsiaCity_Interior8/text.inc"
	.include "data/maps/FuchsiaCity_Interior9/text.inc"
	.include "data/maps/FuchsiaCity_Interior11/text.inc"
	.include "data/maps/Route19_Interior1/text.inc"
	.include "data/maps/BlackthornCity_Interior1/text.inc"
	.include "data/maps/PalletTown_Interior2/text.inc"
	.include "data/maps/PalletTown_Interior3/text.inc"
	.include "data/maps/CinnabarIsland_Interior2/text.inc"
	.include "data/maps/IndigoPlateau_Interior5/text.inc"
	.include "data/maps/SaffronCity_Interior2/text.inc"
	.include "data/maps/SaffronCity_Interior3/text.inc"
	.include "data/maps/SaffronCity_Interior4/text.inc"
	.include "data/maps/SaffronCity_Interior5/text.inc"
	.include "data/maps/SaffronCity_Interior6/text.inc"
	.include "data/maps/SaffronCity_Interior7/text.inc"
	.include "data/maps/SaffronCity_Interior9/text.inc"
	.include "data/maps/Route2_Interior2/text.inc"
	.include "data/maps/Route2_Interior4/text.inc"
	.include "data/maps/MahoganyTown_Interior3/text.inc"
	.include "data/maps/Route5_Interior2/text.inc"
	.include "data/maps/Route5_Interior3/text.inc"
	.include "data/maps/Route6_Interior2/text.inc"
	.include "data/maps/Route26_Interior1/text.inc"
	.include "data/maps/Route7_Interior1/text.inc"
	.include "data/maps/Route8_Interior1/text.inc"
	.include "data/maps/BlackthornCity_Interior3/text.inc"
	.include "data/maps/Route12_Interior1/text.inc"
	.include "data/maps/Route15_Interior1/text.inc"
	.include "data/maps/Route16_Interior1/text.inc"
	.include "data/maps/Route16_Interior2/text.inc"
	.include "data/maps/Route18_Interior1/text.inc"
	.include "data/maps/Route27_Interior1/text.inc"
	.include "data/maps/Route25_Interior1/text.inc"
	.include "data/maps/BlackthornCity_Interior6/text.inc"
	.include "data/maps/CianwoodCity_Interior1/text.inc"
	.include "data/maps/CianwoodCity_Interior4/text.inc"
	.include "data/maps/CherrygroveCity_Interior1/text.inc"
	.include "data/maps/NewBarkTown_Interior4/text.inc"
	.include "data/maps/Route39_Interior1/text.inc"
	.include "data/maps/NewBarkTown_Interior5/text.inc"
	.include "data/maps/CherrygroveCity_Interior3/text.inc"
	.include "data/maps/VioletCity_Interior3/text.inc"
	.include "data/maps/CherrygroveCity_Interior4/text.inc"
	.include "data/maps/RuinsOfAlph_Interior4/text.inc"
	.include "data/maps/Route30_Interior2/text.inc"
	.include "data/maps/VioletCity_Interior5/text.inc"
	.include "data/maps/VioletCity_Interior6/text.inc"
	.include "data/maps/AzaleaTown_Interior3/text.inc"
	.include "data/maps/VioletCity_Interior7/text.inc"
	.include "data/maps/VioletCity_Interior8/text.inc"
	.include "data/maps/CherrygroveCity_Interior5/text.inc"
	.include "data/maps/Route32_Interior1/text.inc"
	.include "data/maps/AzaleaTown_Interior4/text.inc"
	.include "data/maps/AzaleaTown_Interior5/text.inc"
	.include "data/maps/AzaleaTown_Interior6/text.inc"
	.include "data/maps/AzaleaTown_Interior7/text.inc"
	.include "data/maps/IlexForest_Interior2/text.inc"
	.include "data/maps/GoldenrodCity_Interior4/text.inc"
	.include "data/maps/GoldenrodCity_Interior5/text.inc"
	.include "data/maps/GoldenrodCity_Interior6/text.inc"
	.include "data/maps/GoldenrodCity_Interior7/text.inc"
	.include "data/maps/GoldenrodCity_Interior8/text.inc"
	.include "data/maps/GoldenrodCity_Interior9/text.inc"
	.include "data/maps/GoldenrodCity_Interior10/text.inc"
	.include "data/maps/GoldenrodCity_Interior11/text.inc"
	.include "data/maps/GoldenrodCity_Interior12/text.inc"
	.include "data/maps/GoldenrodCity_Interior13/text.inc"
	.include "data/maps/GoldenrodCity_Interior14/text.inc"
	.include "data/maps/GoldenrodCity_Interior15/text.inc"
	.include "data/maps/RadioTower_Interior1/text.inc"
	.include "data/maps/RadioTower_Interior2/text.inc"
	.include "data/maps/GoldenrodCity_Interior16/text.inc"
	.include "data/maps/NationalPark_Interior2/text.inc"
	.include "data/maps/EcruteakCity_Interior4/text.inc"
	.include "data/maps/EcruteakCity_Interior5/text.inc"
	.include "data/maps/EcruteakCity_Interior6/text.inc"
	.include "data/maps/EcruteakCity_Interior8/text.inc"
	.include "data/maps/Route39_Interior2/text.inc"
	.include "data/maps/OlivineCity_Area1/text.inc"
	.include "data/maps/OlivineCity_Interior2/text.inc"
	.include "data/maps/OlivineCity_Interior3/text.inc"
	.include "data/maps/CianwoodCity_Interior6/text.inc"
	.include "data/maps/CianwoodCity_Interior7/text.inc"
	.include "data/maps/MahoganyTown_Interior5/text.inc"
	.include "data/maps/RadioTower_Interior3/text.inc"
	.include "data/maps/RadioTower_Interior4/text.inc"
	.include "data/maps/RadioTower_Interior5/text.inc"
	.include "data/maps/GoldenrodCity_Interior17/text.inc"
	.include "data/maps/GoldenrodCity_Interior18/text.inc"
	.include "data/maps/BlackthornCity_Interior7/text.inc"
	.include "data/maps/BlackthornCity_Interior8/text.inc"
	.include "data/maps/Route26_Interior2/text.inc"
	.include "data/maps/IndigoPlateau_Interior7/text.inc"
	.include "data/maps/VermilionCity_Interior18/text.inc"
	.include "data/maps/VermilionCity_Area1/text.inc"
	.include "data/maps/SaffronCity_Interior10/text.inc"
	.include "data/maps/Route10_Interior1/text.inc"
	.include "data/maps/LavenderTown_Interior6/text.inc"
	.include "data/maps/LavRadioTower_Interior1/text.inc"
	.include "data/maps/CeladonCity_Interior16/text.inc"
	.include "data/maps/CeladonCity_Interior17/text.inc"
	.include "data/maps/CeladonCity_Interior18/text.inc"
	.include "data/maps/CeladonCity_Interior19/text.inc"
	.include "data/maps/GoldenrodCity_Interior21/text.inc"
	.include "data/maps/GoldenrodCity_Interior22/text.inc"
	.include "data/maps/GoldenrodCity_Interior23/text.inc"
	.include "data/maps/GoldenrodCity_Interior24/text.inc"
	.include "data/maps/EcruteakCity_Interior9/text.inc"
	.include "data/maps/EcruteakCity_Interior10/text.inc"
	.include "data/maps/OlivineCity_Interior4/text.inc"
	.include "data/maps/EcruteakCity_Interior12/text.inc"
	.include "data/maps/EcruteakCity_Interior13/text.inc"
	.include "data/maps/OlivineCity_Interior5/text.inc"
	.include "data/maps/OlivineCity_Interior7/text.inc"
	.include "data/maps/OlivineCity_Interior8/text.inc"
	.include "data/maps/OlivineCity_Interior9/text.inc"
	.include "data/maps/MahoganyTown_Interior6/text.inc"
	.include "data/maps/CherrygroveCity_Interior6/text.inc"
	.include "data/maps/LakeOfRage_Interior1/text.inc"
	.include "data/maps/LakeOfRage_Interior2/text.inc"
	.include "data/maps/BlackthornCity_Interior9/text.inc"

	.include "data/scripts/std_msgbox.inc"
	.include "data/scripts/trainer_battle.inc"

@ Unused
Text_WouldYouLikeToMixRecords::
	.string "Would you like to mix records with\n"
	.string "other TRAINERS?$"

@ Unused
Text_WeHopeToSeeYouAgain2::
	.string "We hope to see you again!$"

	.include "data/text/pc.inc"

@ Unused
Text_WelcomeTradeCenter::
	.string "Welcome to the POKéMON CABLE CLUB\n"
	.string "TRADE CENTER.$"

@ Unused
Text_WelcomeColosseum::
	.string "Welcome to the POKéMON CABLE CLUB\n"
	.string "COLOSSEUM.$"

@ Unused
Text_WelcomeTimeCapsule::
	.string "Welcome to the POKéMON CABLE CLUB\n"
	.string "TIME CAPSULE.$"

Text_PleaseComeAgain::
	.string "Please come again!$"

@ Unused
Text_HavingDiscountSaleToday::
	.string "Welcome!\p"
	.string "We're having a discount sale today!$"

@ Unused
Text_PlayerWhatCanIDoForYou::
	.string "{PLAYER}{KUN}, welcome!\p"
	.string "What can I do for you?$"

	.include "data/text/obtain_item.inc"

Text_MakingPreparations::
	.string "じゅんびちゅうです！$"

Text_WantWhichFloor::
	.string "Which floor do you want?$"

Text_BagItemCanBeRegistered::
	.string "An item in the BAG can be\n"
	.string "registered to SELECT for easy use.$"

@ Unused (email from R/S Rivals computer)
Text_TrainerSchoolEmail::
	.string "パソコンに\n"
	.string "ポケモン　トレーナー　こうざの\l"
	.string "メールが　きている！\p"
	.string "‥‥　‥‥　‥‥\p"
	.string "ポケモンが　おぼえられる　わざは　4つ！\p"
	.string "どんな　わざを　おぼえさせるかで\n"
	.string "トレーナーの　じつりょくが　とわれます！\p"
	.string "‥‥　‥‥　‥‥$"

Text_PlayerBootedUpPC::
	.string "{PLAYER} booted up the PC.$"

@ Unused
Text_LinkWasCanceled::
	.string "つうしんは　キャンセルされました$"

@ Unused
Text_GiveNicknameToReceivedMon::
	.string "Want to give a nickname to the\n"
	.string "{STR_VAR_2} you received?$"

gText_PkmnFainted3::
	.string "{STR_VAR_1} fainted…\p"
	.string "$"

Text_WelcomeWantToHealPkmn::
	.string "Welcome to our POKéMON CENTER!\p"
	.string "Would you like me to heal your\n"
	.string "POKéMON back to perfect health?$"

Text_TakeYourPkmnForFewSeconds::
	.string "Okay, I'll take your POKéMON for a\n"
	.string "few seconds.$"

Text_WeHopeToSeeYouAgain::
	.string "We hope to see you again!$"

Text_RestoredPkmnToFullHealth::
	.string "Thank you for waiting.\n"
	.string "We've restored your POKéMON to\l"
	.string "full health.$"

	.include "data/text/surf.inc"

@ Unused, from R/S
Text_DoorOpenedFarAway::
	.string "どこか　とおくの　とびらが\n"
	.string "ひらいたような　おとだ‥‥$"

@ Unused, from R/S
Text_BigHoleInTheWall::
	.string "かべに\n"
	.string "おおきな　あなが　あいている！$"

Text_WirelessClubUndergoingAdjustments::
	.string "I'm terribly sorry.\n"
	.string "The POKéMON WIRELESS CLUB is\l"
	.string "undergoing adjustments now.$"

Text_AppearsToBeUndergoingAdjustments::
	.string "It appears to be undergoing\n"
	.string "adjustments…$"

Text_HandedOverItem::
	.string "{PLAYER} handed over the\n"
	.string "{STR_VAR_1}.$"

Text_GiveNicknameToThisMon::
	.string "Do you want to give a nickname to\n"
	.string "this {STR_VAR_1}?$"

	.include "data/text/itemfinder.inc"
	.include "data/text/route23.inc"
	.include "data/text/aide.inc"
	.include "data/text/ingame_trade.inc"

Text_CardKeyOpenedDoor::
	.string "Bingo!\n"
	.string "The CARD KEY opened the door!$"

Text_ItNeedsCardKey::
	.string "No!\n"
	.string "It needs a CARD KEY!$"

Text_AccessedProfOaksPC::
	.string "Accessed PROF. OAK's PC…\p"
	.string "Accessed the POKéDEX Rating\n"
	.string "System…$"

Text_HavePokedexRated::
	.string "Would you like to have your\n"
	.string "POKéDEX rated?$"

Text_ClosedLinkToProfOaksPC::
	.string "Closed link to PROF. OAK's PC.$"

Text_VoiceRangOutDontRunAway::
	.string "Someone's voice rang out,\n"
	.string "“Don't run away!”$"

@ Uncear what the below unused JP texts were for
Text_IdLikeToSeeRequest::
	.string "えっとー\n"
	.string "{STR_VAR_2}が　みてみたいなー\p"
	.string "それも　{STR_VAR_1}{STR_VAR_3}\n"
	.string "{STR_VAR_2}が　みてみたいなー$"

Text_ThankYouForShowingMe::
	.string "わぁー　すごい！\n"
	.string "{STR_VAR_1}{STR_VAR_3}{STR_VAR_2}だー！\p"
	.string "ありがとー\n"
	.string "また　よろしくねー！$"

Text_ThatsNotRight::
	.string "それっ　ちがうよー！$"

Text_ISee::
	.string "そっか‥$"

Text_TheDoorIsClosed::
	.string "ドアは　しまっている‥$"

Text_TheDoorIsOpen::
	.string "The door is open…$"

	.include "data/text/pc_transfer.inc"
	.include "data/text/white_out.inc"
	.include "data/text/poke_mart.inc"

Text_MonFlewAway::
	.string "The {STR_VAR_1} flew away!$"

Text_TheresBedLetsRest::
	.string "ベッドが　ある‥‥\n"
	.string "やすんでいこう$"

Text_FoundTMHMContainsMove::
	.string "{PLAYER} found a {STR_VAR_2}!\n"
	.string "It contains {STR_VAR_1}.$"

	.include "data/text/seagallop.inc"

@ Call for legendary bird trio
Text_Gyaoo::
	.string "Gyaoo!$"

Text_MoveCanOnlyBeLearnedOnce::
	.string "This move can be learned only\n"
	.string "once. Is that okay?$"

EventScript_ResetAllMapFlags::
	setflag FLAG_HIDE_OAK_IN_HIS_LAB
	setflag FLAG_HIDE_OAK_IN_PALLET_TOWN
	setflag FLAG_HIDE_BILL_HUMAN_SEA_COTTAGE
	setflag FLAG_HIDE_PEWTER_CITY_RUNNING_SHOES_GUY
	setflag FLAG_HIDE_POKEHOUSE_FUJI
	setflag FLAG_HIDE_LIFT_KEY
	setflag FLAG_HIDE_SILPH_SCOPE
	setflag FLAG_HIDE_CERULEAN_RIVAL
	setflag FLAG_HIDE_SS_ANNE_RIVAL
	setflag FLAG_HIDE_VERMILION_CITY_OAKS_AIDE
	setflag FLAG_HIDE_SAFFRON_CIVILIANS
	setflag FLAG_HIDE_ROUTE_22_RIVAL
	setflag FLAG_HIDE_OAK_IN_CHAMP_ROOM
	setflag FLAG_HIDE_CREDITS_RIVAL
	setflag FLAG_HIDE_CREDITS_OAK
	setflag FLAG_HIDE_CINNABAR_BILL
	setflag FLAG_HIDE_CINNABAR_SEAGALLOP
	setflag FLAG_HIDE_CINNABAR_POKECENTER_BILL
	setflag FLAG_HIDE_LORELEI_IN_HER_HOUSE
	setflag FLAG_HIDE_SAFFRON_FAN_CLUB_BLACK_BELT
	setflag FLAG_HIDE_SAFFRON_FAN_CLUB_ROCKER
	setflag FLAG_HIDE_SAFFRON_FAN_CLUB_WOMAN
	setflag FLAG_HIDE_SAFFRON_FAN_CLUB_BEAUTY
	setflag FLAG_HIDE_TWO_ISLAND_GAME_CORNER_LOSTELLE
	setflag FLAG_HIDE_TWO_ISLAND_GAME_CORNER_BIKER
	setflag FLAG_HIDE_TWO_ISLAND_WOMAN
	setflag FLAG_HIDE_TWO_ISLAND_BEAUTY
	setflag FLAG_HIDE_TWO_ISLAND_POKE_MANIAC
	setflag FLAG_HIDE_LOSTELLE_IN_HER_HOME
	setflag FLAG_HIDE_THREE_ISLAND_LONE_BIKER
	setflag FLAG_HIDE_FOUR_ISLAND_RIVAL
	setflag FLAG_HIDE_DOTTED_HOLE_SCIENTIST
	setflag FLAG_HIDE_RESORT_GORGEOUS_SELPHY
	setflag FLAG_HIDE_RESORT_GORGEOUS_INSIDE_SELPHY
	setflag FLAG_HIDE_SELPHYS_BUTLER
	setflag FLAG_HIDE_DEOXYS
	setflag FLAG_HIDE_LORELEI_HOUSE_MEOWTH_DOLL
	setflag FLAG_HIDE_LORELEI_HOUSE_CHANSEY_DOLL
	setflag FLAG_HIDE_LORELEIS_HOUSE_NIDORAN_F_DOLL
	setflag FLAG_HIDE_LORELEI_HOUSE_JIGGLYPUFF_DOLL
	setflag FLAG_HIDE_LORELEIS_HOUSE_NIDORAN_M_DOLL
	setflag FLAG_HIDE_LORELEIS_HOUSE_FEAROW_DOLL
	setflag FLAG_HIDE_LORELEIS_HOUSE_PIDGEOT_DOLL
	setflag FLAG_HIDE_LORELEIS_HOUSE_LAPRAS_DOLL
	setflag FLAG_HIDE_POSTGAME_GOSSIPERS
	setflag FLAG_HIDE_FAME_CHECKER_ERIKA_JOURNALS
	setflag FLAG_HIDE_FAME_CHECKER_KOGA_JOURNAL
	setflag FLAG_HIDE_FAME_CHECKER_LT_SURGE_JOURNAL
	setflag FLAG_HIDE_SAFFRON_CITY_POKECENTER_SABRINA_JOURNALS
	setvar VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 500
	end

	.include "data/scripts/hall_of_fame.inc"
	.include "data/scripts/pkmn_center_nurse.inc"
	.include "data/scripts/obtain_item.inc"
	.include "data/scripts/pc.inc"

Common_ShowEasyChatScreen::
	fadescreen FADE_TO_BLACK
	special ShowEasyChatScreen
	fadescreen FADE_FROM_BLACK
	return

	.include "data/scripts/surf.inc"
	.include "data/scripts/set_gym_trainers.inc"
	.include "data/scripts/bag_full.inc"

@ Unused
EventScript_GymBadgeFanfare::
	playfanfare MUS_OBTAIN_BADGE
	waitfanfare
	return

EventScript_OutOfCenterPartyHeal::
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen FADE_FROM_BLACK
	return

EventScript_WallTownMap::
	lockall
	msgbox Text_ATownMap
	goto_if_questlog EventScript_ReleaseEnd
	fadescreen FADE_TO_BLACK
	special ShowTownMap
	waitstate
	releaseall
	end

	.include "data/text/pokedex_rating.inc"
	.include "data/scripts/pokedex_rating.inc"
	.include "data/scripts/cave_of_origin.inc"

EventScript_ChangePokemonNickname::
	fadescreen FADE_TO_BLACK
	special ChangePokemonNickname
	waitstate
	return

@ Unused
EventScript_HandOverItem::
	bufferitemname STR_VAR_1, VAR_0x8004
	playfanfare MUS_OBTAIN_TMHM
	message Text_HandedOverItem
	waitmessage
	waitfanfare
	removeitem VAR_0x8004
	return

	.include "data/scripts/pokemon_league.inc"
	.include "data/scripts/movement.inc"
	.include "data/scripts/flavor_text.inc"
	.include "data/scripts/questionnaire.inc"

EventScript_BagItemCanBeRegistered::
	msgbox Text_BagItemCanBeRegistered, MSGBOX_SIGN
	end

EventScript_Return::
	return

EventScript_SetResultTrue::
	setvar VAR_RESULT, TRUE
	return

EventScript_SetResultFalse::
	setvar VAR_RESULT, FALSE
	return

EventScript_SetExitingCyclingRoad::
	lockall
	clearflag FLAG_SYS_ON_CYCLING_ROAD
	setvar VAR_MAP_SCENE_ROUTE16, 0
	releaseall
	end

EventScript_SetEnteringCyclingRoad::
	lockall
	setvar VAR_MAP_SCENE_ROUTE16, 1
	releaseall
	end

	.include "data/scripts/route23.inc"

EventScript_GetElevatorFloor::
	special GetElevatorFloor
	return

	.include "data/scripts/aide.inc"

EventScript_CancelMessageBox::
	special DoPicboxCancel
	release
	end

EventScript_ReleaseEnd::
	release
	end

	.include "data/scripts/pokemon_mansion.inc"

@ Unused
EventScript_DelayedLookAround::
	lockall
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 20
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 20
	releaseall
	end

	.include "data/scripts/silphco_doors.inc"
	.include "data/scripts/pc_transfer.inc"

EventScript_GetInGameTradeSpeciesInfo::
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	return

EventScript_ChooseMonForInGameTrade::
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	copyvar VAR_0x800A, VAR_0x8004
	return

EventScript_GetInGameTradeSpecies::
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	return

EventScript_DoInGameTrade::
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	lock
	faceplayer
	return

EventScript_VsSeekerChargingDone::
	special VsSeekerFreezeObjectsAfterChargeComplete
	waitstate
	special VsSeekerResetObjectMovementAfterChargeComplete
	releaseall
	end

Common_EventScript_UnionRoomAttendant::
	call CableClub_EventScript_UnionRoomAttendant
	end

Common_EventScript_WirelessClubAttendant::
	call CableClub_EventScript_WirelessClubAttendant
	end

Common_EventScript_DirectCornerAttendant::
	call CableClub_EventScript_DirectCornerAttendant
	end

VermilionCity_PokemonCenter_1F_EventScript_VSSeekerWoman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_VS_SEEKER, VermilionCity_PokemonCenter_1F_EventScript_ExplainVSSeeker
	msgbox VermilionCity_PokemonCenter_1F_Text_UrgeToBattleSomeoneAgain
	setflag FLAG_GOT_VS_SEEKER
	giveitem ITEM_VS_SEEKER
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	msgbox VermilionCity_PokemonCenter_1F_Text_UseDeviceForRematches
	release
	end

VermilionCity_PokemonCenter_1F_EventScript_ExplainVSSeeker::
	msgbox VermilionCity_PokemonCenter_1F_Text_ExplainVSSeeker
	release
	end

	.include "data/scripts/itemfinder.inc"
	.include "data/scripts/white_out.inc"

Std_PutItemAway::
	bufferitemnameplural STR_VAR_2, VAR_0x8000, VAR_0x8001
	checkitemtype VAR_0x8000
	call EventScript_BufferPutAwayPocketName
	msgbox Text_PutItemAway
	return

EventScript_BufferPutAwayPocketName::
	switch VAR_RESULT
	case POCKET_ITEMS,       EventScript_BufferPutAwayPocketItems
	case POCKET_KEY_ITEMS,   EventScript_BufferPutAwayPocketKeyItems
	case POCKET_POKE_BALLS,  EventScript_BufferPutAwayPocketPokeBalls
	case POCKET_TM_CASE,     EventScript_BufferPutAwayPocketTMCase
	case POCKET_BERRY_POUCH, EventScript_BufferPutAwayPocketBerryPouch
	end

EventScript_BufferPutAwayPocketItems::
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS_POCKET
	return

EventScript_BufferPutAwayPocketKeyItems::
	bufferstdstring STR_VAR_3, STDSTRING_KEY_ITEMS_POCKET
	return

EventScript_BufferPutAwayPocketPokeBalls::
	bufferstdstring STR_VAR_3, STDSTRING_POKEBALLS_POCKET
	return

EventScript_BufferPutAwayPocketTMCase::
	bufferstdstring STR_VAR_3, STDSTRING_TM_CASE
	return

EventScript_BufferPutAwayPocketBerryPouch::
	bufferstdstring STR_VAR_3, STDSTRING_BERRY_POUCH
	return

	.include "data/scripts/seagallop.inc"
	.include "data/scripts/static_pokemon.inc"

EventScript_TryDarkenRuins::
	goto_if_set FLAG_SYS_UNLOCKED_TANOBY_RUINS, EventScript_Return
	setweather WEATHER_SHADE
	doweather
	return

EventScript_BrailleCursorWaitButton::
	special BrailleCursorToggle
	waitbuttonpress
	playse SE_SELECT
	setvar VAR_0x8006, 1
	special BrailleCursorToggle
	return

EventScript_NoMoreRoomForPokemon::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox Text_NoMoreRoomForPokemon
	release
	end

	.include "data/text/braille.inc"
	.include "data/scripts/trainers.inc"

@ Test message!
@ Welcome to the world of Pokémon!
Text_TestMsg::
	.string "テストよう　メッセージです！\n"
	.string "ポケモンの　せかいへ　ようこそ！$"

	.include "data/scripts/fame_checker.inc"
	.include "data/text/fame_checker.inc"
	.include "data/text/sign_lady.inc"
	.include "data/text/trainer_card.inc"
	.include "data/scripts/trainer_card.inc"
	.include "data/text/help_system.inc"
	.include "data/scripts/cable_club.inc"
	.include "data/scripts/field_moves.inc"
	.include "data/scripts/item_ball_scripts.inc"
	.include "data/scripts/mystery_event_club.inc"
	.include "data/scripts/day_care.inc"
	.include "data/text/day_care.inc"
	.include "data/scripts/flash.inc"
	.include "data/scripts/repel.inc"
	.include "data/scripts/safari_zone.inc"
	.include "data/text/safari_zone.inc"
	.include "data/text/competitive_brothers.inc"
	.include "data/text/eon_ticket.inc"
	.include "data/text/berries.inc"
	.include "data/text/flavor_text.inc"
	.include "data/scripts/hole.inc"
	.include "data/text/trainers.inc"
	.include "data/scripts/move_tutors.inc"
	.include "data/scripts/trainer_tower.inc"
	.include "data/scripts/test.inc"
	.include "data/text/save.inc"
	.include "data/text/new_game_intro.inc"
	.include "data/text/pokedude.inc"

@ ShinyGold: new shared content and vanilla per-map labels kept for C code / shared scripts
	.include "data/scripts/shinygold_shared.inc"
	.include "data/scripts/shinygold_compat.inc"
	.include "data/text/shinygold_shared.inc"
	.include "data/text/shinygold_compat.inc"
