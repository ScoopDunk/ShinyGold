// ShinyGold: regenerated from the hack ROM. Notes on hack data ported as-is:
//  * encounterMusic_gender: the hack's trainer editor stored the trainer pic index here for most trainers
//    (bit 7 is still the female flag). Values that are not a TRAINER_ENCOUNTER_MUSIC_* id fall through to
//    the default case of PlayTrainerEncounterMusic().
//  * trainerClass comments give the class name ShinyGold displays (gTrainerClassNames was edited).
const struct Trainer gTrainers[] = {
    [TRAINER_NONE] = {
        .trainerName = _(""),
    },

    [TRAINER_HIKER_JIM] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("JIM"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerJim),
    },

    [TRAINER_BIRD_KEEPER_ABE] = {
        .trainerClass = TRAINER_CLASS_RS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("ABE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperAbe),
    },

    [TRAINER_CAMPER_ROLAND] = {
        .trainerClass = TRAINER_CLASS_RS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("ROLAND"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CamperRoland),
    },

    [TRAINER_YOUNGSTER_GORDON] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("GORDON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungsterGordon),
    },

    [TRAINER_BLACK_BELT_HIKARU] = {
        .trainerClass = TRAINER_CLASS_RS_BLACK_BELT,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("HIKARU"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BlackBeltHikaru),
    },

    [TRAINER_BUG_CATCHER_JOSH] = {
        .trainerClass = TRAINER_CLASS_RS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("JOSH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcherJosh),
    },

    [TRAINER_HIKER_DANIEL] = {
        .trainerClass = TRAINER_CLASS_RS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("DANIEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerDaniel),
    },

    [TRAINER_POKEMANIAC_LARRY] = {
        .trainerClass = TRAINER_CLASS_RS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("LARRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokemaniacLarry),
    },

    [TRAINER_FIREBREATHER_RAY] = {
        .trainerClass = TRAINER_CLASS_KINDLER, // "FIREBREATHER"
        .encounterMusic_gender = 70,
        .trainerPic = TRAINER_PIC_RS_SIS_AND_BRO,
        .trainerName = _("RAY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FirebreatherRay),
    },

    [TRAINER_POKEMANIAC_SOUDA] = {
        .trainerClass = TRAINER_CLASS_RS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("SOUDA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokemaniacSouda),
    },

    [TRAINER_TEAM_ROCKET_GRUNT] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt),
    },

    [TRAINER_POKEFAN_BRANDON] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 32,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("BRANDON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokefanBrandon),
    },

    [TRAINER_OFFICER_KEITH] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_F, // "OFFICER"
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .trainerName = _("KEITH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_OfficerKeith),
    },

    [TRAINER_POKEMANIAC_ISSAC] = {
        .trainerClass = TRAINER_CLASS_RS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("ISSAC"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokemaniacIssac),
    },

    [TRAINER_LASS_CARRIE] = {
        .trainerClass = TRAINER_CLASS_RS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("CARRIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassCarrie),
    },

    [TRAINER_PICNICKER_KIM] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("KIM"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerKim),
    },

    [TRAINER_PICNICKER_BROOKE] = {
        .trainerClass = TRAINER_CLASS_RS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("BROOKE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerBrooke),
    },

    [TRAINER_POKEFAN_ROBERT] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 32,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("ROBERT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokefanRobert),
    },

    [TRAINER_PSYCHIC_GREG] = {
        .trainerClass = TRAINER_CLASS_RS_PSYCHIC,
        .encounterMusic_gender = 100,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("GREG"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PsychicGreg),
    },

    [TRAINER_POKEFAN_WILLIAM] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 32,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("WILLIAM"),
        .items = {ITEM_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokefanWilliam),
    },

    [TRAINER_KIMONO_GIRL_NAOKO] = {
        .trainerClass = TRAINER_CLASS_TEAM_AQUA, // "KIMONO GIRL"
        .encounterMusic_gender = 73,
        .trainerPic = TRAINER_PIC_MAGMA_ADMIN_M,
        .trainerName = _("NAOKO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_KimonoGirlNaoko),
    },

    [TRAINER_KIMONO_GIRL_SAYO] = {
        .trainerClass = TRAINER_CLASS_TEAM_AQUA, // "KIMONO GIRL"
        .encounterMusic_gender = 73,
        .trainerPic = TRAINER_PIC_MAGMA_ADMIN_M,
        .trainerName = _("SAYO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_KimonoGirlSayo),
    },

    [TRAINER_KIMONO_GIRL_ZUKI] = {
        .trainerClass = TRAINER_CLASS_TEAM_AQUA, // "KIMONO GIRL"
        .encounterMusic_gender = 22,
        .trainerPic = TRAINER_PIC_MAGMA_ADMIN_M,
        .trainerName = _("ZUKI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_KimonoGirlZuki),
    },

    [TRAINER_KIMONO_GIRL_KUNI] = {
        .trainerClass = TRAINER_CLASS_TEAM_AQUA, // "KIMONO GIRL"
        .encounterMusic_gender = 73,
        .trainerPic = TRAINER_PIC_MAGMA_ADMIN_M,
        .trainerName = _("KUNI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_KimonoGirlKuni),
    },

    [TRAINER_BIKER_HARRIS] = {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = 91,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("HARRIS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BikerHarris),
    },

    [TRAINER_PICNICKER_TANYA] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("TANYA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerTanya),
    },

    [TRAINER_BIKER_RILEY] = {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = 91,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("RILEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BikerRiley),
    },

    [TRAINER_BIRD_KEEPER_BOB] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("BOB"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperBob),
    },

    [TRAINER_YOUNGSTER_OWEN] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 28,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("OWEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungsterOwen),
    },

    [TRAINER_KIMONO_GIRL_MIKI] = {
        .trainerClass = TRAINER_CLASS_TEAM_AQUA, // "KIMONO GIRL"
        .encounterMusic_gender = 73,
        .trainerPic = TRAINER_PIC_MAGMA_ADMIN_M,
        .trainerName = _("MIKI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_KimonoGirlMiki),
    },

    [TRAINER_SAGE_PING] = {
        .trainerClass = TRAINER_CLASS_HEX_MANIAC, // "SAGE"
        .encounterMusic_gender = 72,
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_F,
        .trainerName = _("PING"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SagePing),
    },

    [TRAINER_FIREBREATHER_DICK] = {
        .trainerClass = TRAINER_CLASS_KINDLER, // "FIREBREATHER"
        .encounterMusic_gender = 70,
        .trainerPic = TRAINER_PIC_RS_SIS_AND_BRO,
        .trainerName = _("DICK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FirebreatherDick),
    },

    [TRAINER_SAILOR_HARRY] = {
        .trainerClass = TRAINER_CLASS_RS_SAILOR,
        .encounterMusic_gender = 85,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("HARRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SailorHarry),
    },

    [TRAINER_POKEFAN_RUTH] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 33,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("RUTH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokefanRuth),
    },

    [TRAINER_CAMPER_TED] = {
        .trainerClass = TRAINER_CLASS_RS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("TED"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CamperTed),
    },

    [TRAINER_POKEMANIAC_CALVIN] = {
        .trainerClass = TRAINER_CLASS_RS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("CALVIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokemaniacCalvin),
    },

    [TRAINER_COOLTRAINER_EMMA] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("EMMA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerEmma),
    },

    [TRAINER_PSYCHIC_NATHAN] = {
        .trainerClass = TRAINER_CLASS_RS_PSYCHIC,
        .encounterMusic_gender = 100,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("NATHAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PsychicNathan),
    },

    [TRAINER_SWIMMER_F_ELAINE] = {
        .trainerClass = TRAINER_CLASS_RS_SWIMMER_F,
        .encounterMusic_gender = 99,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("ELAINE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerFElaine),
    },

    [TRAINER_LASS_CONNIE] = {
        .trainerClass = TRAINER_CLASS_RS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("CONNIE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassConnie),
    },

    [TRAINER_COOLTRAINER_BRIAN] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("BRIAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerBrian),
    },

    [TRAINER_FISHERMAN_RYO] = {
        .trainerClass = TRAINER_CLASS_RS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("RYO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanRyo),
    },

    [TRAINER_PSYCHIC_RICHARD] = {
        .trainerClass = TRAINER_CLASS_RS_PSYCHIC,
        .encounterMusic_gender = 100,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("RICHARD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PsychicRichard),
    },

    [TRAINER_PSYCHIC_FIDEL] = {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = 43,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("FIDEL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PsychicFidel),
    },

    [TRAINER_BUG_CATCHER_DOUG] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 44,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("DOUG"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcherDoug),
    },

    [TRAINER_SWIMMER_M_BERKE] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = 95,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("BERKE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerMBerke),
    },

    [TRAINER_SWIMMER_F_DENISE] = {
        .trainerClass = TRAINER_CLASS_RS_SWIMMER_F,
        .encounterMusic_gender = 99,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("DENISE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerFDenise),
    },

    [TRAINER_SWIMMER_M_MATHEW] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = 95,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("MATHEW"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerMMathew),
    },

    [TRAINER_GENTLEMAN_ALFRED] = {
        .trainerClass = TRAINER_CLASS_RS_GENTLEMAN,
        .encounterMusic_gender = 123,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("ALFRED"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_GentlemanAlfred),
    },

    [TRAINER_SAILOR_TERRELL] = {
        .trainerClass = TRAINER_CLASS_RS_SAILOR,
        .encounterMusic_gender = 85,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("TERRELL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SailorTerrell),
    },

    [TRAINER_BIRD_KEEPER_PERRY] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("PERRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperPerry),
    },

    [TRAINER_BLACK_BELT_YOSHI] = {
        .trainerClass = TRAINER_CLASS_RS_BLACK_BELT,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("YOSHI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BlackBeltYoshi),
    },

    [TRAINER_BLACK_BELT_LAO] = {
        .trainerClass = TRAINER_CLASS_RS_BLACK_BELT,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("LAO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BlackBeltLao),
    },

    [TRAINER_HIKER_JITOU] = {
        .trainerClass = TRAINER_CLASS_RS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("JITOU"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerJitou),
    },

    [TRAINER_BLACK_BELT_KAZUO] = {
        .trainerClass = TRAINER_CLASS_RS_BLACK_BELT,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("KAZUO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BlackBeltKazuo),
    },

    [TRAINER_POKEMANIAC_RON] = {
        .trainerClass = TRAINER_CLASS_RS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("RON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokemaniacRon),
    },

    [TRAINER_POKEMANIAC_BEN] = {
        .trainerClass = TRAINER_CLASS_RS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("BEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokemaniacBen),
    },

    [TRAINER_FISHERMAN_ANDRE] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("ANDRE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanAndre),
    },

    [TRAINER_SKIER_ROXANNE] = {
        .trainerClass = TRAINER_CLASS_COLLECTOR, // "SKIER"
        .encounterMusic_gender = 18,
        .trainerPic = TRAINER_PIC_KINDLER,
        .trainerName = _("ROXANNE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SkierRoxanne),
    },

    [TRAINER_SKIER_CLARISSA] = {
        .trainerClass = TRAINER_CLASS_COLLECTOR, // "SKIER"
        .encounterMusic_gender = 18,
        .trainerPic = TRAINER_PIC_KINDLER,
        .trainerName = _("CLARISSA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SkierClarissa),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_2] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt2),
    },

    [TRAINER_POKEMANIAC_ZACH] = {
        .trainerClass = TRAINER_CLASS_RS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("ZACH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokemaniacZach),
    },

    [TRAINER_COOLTRAINER_ALLEN] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("ALLEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerAllen),
    },

    [TRAINER_COOLTRAINER_FRAN] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("FRAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerFran),
    },

    [TRAINER_COOLTRAINER_MIKE] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("MIKE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerMike),
    },

    [TRAINER_GUITARIST_CLYDE] = {
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .encounterMusic_gender = 17,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .trainerName = _("CLYDE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_GuitaristClyde),
    },

    [TRAINER_TEACHER_SHIRLEY] = {
        .trainerClass = TRAINER_CLASS_RS_RUIN_MANIAC, // "TEACHER"
        .encounterMusic_gender = 69,
        .trainerPic = TRAINER_PIC_OLD_COUPLE,
        .trainerName = _("SHIRLEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeacherShirley),
    },

    [TRAINER_GENTLEMAN_EDWARD] = {
        .trainerClass = TRAINER_CLASS_RS_GENTLEMAN,
        .encounterMusic_gender = 123,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("EDWARD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_GentlemanEdward),
    },

    [TRAINER_DRAGON_TAMER_AIRAT] = {
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
        .encounterMusic_gender = 45,
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .trainerName = _("AIRAT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_DragonTamerAirat),
    },

    [TRAINER_DRAGON_TAMER_GON] = {
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
        .encounterMusic_gender = 45,
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .trainerName = _("GON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_DragonTamerGon),
    },

    [TRAINER_DRAGON_TAMER_BRAVO] = {
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
        .encounterMusic_gender = 45,
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .trainerName = _("BRAVO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_DragonTamerBravo),
    },

    [TRAINER_POKEFAN_COLIN] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 32,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("COLIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokefanColin),
    },

    [TRAINER_PICNICKER_DEBRA] = {
        .trainerClass = TRAINER_CLASS_RS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("DEBRA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerDebra),
    },

    [TRAINER_PSYCHIC_FRANKLIN] = {
        .trainerClass = TRAINER_CLASS_RS_PSYCHIC,
        .encounterMusic_gender = 100,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("FRANKLIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PsychicFranklin),
    },

    [TRAINER_BIRD_KEEPER_BRET] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("BRET"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperBret),
    },

    [TRAINER_SAILOR_GARRETT] = {
        .trainerClass = TRAINER_CLASS_RS_SAILOR,
        .encounterMusic_gender = 85,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("GARRETT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SailorGarrett),
    },

    [TRAINER_POKEFAN_TREVOR] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("TREVOR"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokefanTrevor),
    },

    [TRAINER_TEACHER_COLETTE] = {
        .trainerClass = TRAINER_CLASS_RS_RUIN_MANIAC, // "TEACHER"
        .encounterMusic_gender = 71,
        .trainerPic = TRAINER_PIC_OLD_COUPLE,
        .trainerName = _("COLETTE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeacherColette),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_3] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt3),
    },

    [TRAINER_SUPER_NERD_PAT] = {
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = 89,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("PAT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SuperNerdPat),
    },

    [TRAINER_CAMPER_LLOYD] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("LLOYD!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CamperLloyd),
    },

    [TRAINER_SCHOOLBOY_DUDLEY] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("DUDLEY!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SchoolboyDudley),
    },

    [TRAINER_PSYCHIC_JUN] = {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = 100,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("JUN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PsychicJun),
    },

    [TRAINER_PICNICKER_CINDY] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("CINDY!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerCindy),
    },

    [TRAINER_CAMPER_BARRY] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("BARRY!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CamperBarry),
    },

    [TRAINER_COOLTRAINER_FIRIA] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("FIRIA!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerFiria),
    },

    [TRAINER_PSYCHIC_ZAHAAD] = {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = 100,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("ZAHAAD!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PsychicZahaad),
    },

    [TRAINER_BEAUTY_SERA] = {
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = 98,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("SERA!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BeautySera),
    },

    [TRAINER_YOUNGSTER_89] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _(" 1TRAINER/1"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Youngster89),
    },

    [TRAINER_HIKER_90] = {
        .trainerClass = TRAINER_CLASS_RS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("24TRAINER/2"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Hiker90),
    },

    [TRAINER_YOUNGSTER_JOSH] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("JOSH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungsterJosh),
    },

    [TRAINER_YOUNGSTER_TIMMY] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("TIMMY!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungsterTimmy),
    },

    [TRAINER_YOUNGSTER_MIKEY] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("MIKEY!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungsterMikey),
    },

    [TRAINER_HIKER_94] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("24TRAINER/4"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Hiker94),
    },

    [TRAINER_BUG_CATCHER_95] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _(" 9TRAINER/1"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcher95),
    },

    [TRAINER_BIRD_KEEPER_96] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("26TRAINER/3"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeper96),
    },

    [TRAINER_BIRD_KEEPER_97] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("26TRAINER/4"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeper97),
    },

    [TRAINER_YOUNGSTER_ALBERT] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("ALBERT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungsterAlbert),
    },

    [TRAINER_BIRD_KEEPER_99] = {
        .trainerClass = TRAINER_CLASS_RS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("22TRAINER/1"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeper99),
    },

    [TRAINER_OFFICER_DIRK] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_F, // "OFFICER"
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .trainerName = _("DIRK!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_OfficerDirk),
    },

    [TRAINER_YOUNGSTER_101] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _(" 1TRAINER/2"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Youngster101),
    },

    [TRAINER_BUG_CATCHER_DON] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("DON!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcherDon),
    },

    [TRAINER_SUPER_NERD_TOM] = {
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = 89,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("TOM!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SuperNerdTom),
    },

    [TRAINER_COOLTRAINER_104] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("27TRAINER/4"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Cooltrainer104),
    },

    [TRAINER_BUG_CATCHER_BENNY] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("BENNY!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcherBenny),
    },

    [TRAINER_YOUNGSTER_SAMUEL] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("SAMUEL!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungsterSamuel),
    },

    [TRAINER_BUG_CATCHER_AL] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("AL!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcherAl),
    },

    [TRAINER_YOUNGSTER_IAN] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("IAN!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungsterIan),
    },

    [TRAINER_HIKER_BENJAMIN] = {
        .trainerClass = TRAINER_CLASS_RS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("BENJAMIN!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerBenjamin),
    },

    [TRAINER_SUPER_NERD_TERU] = {
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = 89,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("TERU!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SuperNerdTeru),
    },

    [TRAINER_COOLTRAINER_NICK] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("NICK!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerNick),
    },

    [TRAINER_COOLTRAINER_112] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("27TRAINER/5"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Cooltrainer112),
    },

    [TRAINER_LASS_LAURA] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("LAURA!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassLaura),
    },

    [TRAINER_YOUNGSTER_JASON] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("JASON!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungsterJason),
    },

    [TRAINER_COOLTRAINER_PAUL] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("PAUL!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerPaul),
    },

    [TRAINER_PICNICKER_116] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("16TRAINER/1"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Picnicker116),
    },

    [TRAINER_LASS_KRISE] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("KRISE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassKrise),
    },

    [TRAINER_LASS_RAINA] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("RAINA!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassRaina),
    },

    [TRAINER_LASS_BRIDGET] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("BRIDGET!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassBridget),
    },

    [TRAINER_LASS_SANAE] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("SANAE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassSanae),
    },

    [TRAINER_COOLTRAINER_121] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("28TRAINER/3"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Cooltrainer121),
    },

    [TRAINER_LASS_122] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("13TRAINER/1"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Lass122),
    },

    [TRAINER_COOLTRAINER_MEGAN] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("MEGAN!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerMegan),
    },

    [TRAINER_HIKER_LEONARD] = {
        .trainerClass = TRAINER_CLASS_RS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("LEONARD!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerLeonard),
    },

    [TRAINER_COOLTRAINER_KELLY] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("KELLY!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerKelly),
    },

    [TRAINER_CAMPER_ELLIOT] = {
        .trainerClass = TRAINER_CLASS_RS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("ELLIOT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CamperElliot),
    },

    [TRAINER_POKEMANIAC_ANDREW] = {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("ANDREW!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokemaniacAndrew),
    },

    [TRAINER_COOLTRAINER_LOIS] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("LOIS!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerLois),
    },

    [TRAINER_SAILOR_EUGENE] = {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = 85,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("EUGENE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SailorEugene),
    },

    [TRAINER_LASS_MEGAN] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("MEGAN      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassMegan),
    },

    [TRAINER_COOLTRAINER_CYBIL] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("CYBIL!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerCybil),
    },

    [TRAINER_COOLTRAINER_JOYCE] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("JOYCE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerJoyce),
    },

    [TRAINER_FIREBREATHER_WALT] = {
        .trainerClass = TRAINER_CLASS_KINDLER, // "FIREBREATHER"
        .encounterMusic_gender = 70,
        .trainerPic = TRAINER_PIC_RS_SIS_AND_BRO,
        .trainerName = _("WALT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FirebreatherWalt),
    },

    [TRAINER_COOLTRAINER_CODY] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("CODY!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerCody),
    },

    [TRAINER_COOLTRAINER_JAKE] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("JAKE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerJake),
    },

    [TRAINER_COOLTRAINER_136] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("28TRAINER/4"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Cooltrainer136),
    },

    [TRAINER_SAGE_LI] = {
        .trainerClass = TRAINER_CLASS_HEX_MANIAC, // "SAGE"
        .encounterMusic_gender = 72,
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_F,
        .trainerName = _("LI!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SageLi),
    },

    [TRAINER_SAILOR_KENT] = {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = 85,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("KENT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SailorKent),
    },

    [TRAINER_SAGE_EDMOND] = {
        .trainerClass = TRAINER_CLASS_HEX_MANIAC, // "SAGE"
        .encounterMusic_gender = 72,
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_F,
        .trainerName = _("EDMOND"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SageEdmond),
    },

    [TRAINER_COOLTRAINER_140] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = 85,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("28TRAINER/5"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Cooltrainer140),
    },

    [TRAINER_SAILOR_JEFF] = {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = 85,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("JEFF!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SailorJeff),
    },

    [TRAINER_CAMPER_142] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("-EDIT-"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_Camper142),
    },

    [TRAINER_MEDIUM_REBECCA] = {
        .trainerClass = TRAINER_CLASS_CHANNELER, // "MEDIUM"
        .encounterMusic_gender = 126,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("REBECCA!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_MediumRebecca),
    },

    [TRAINER_CAMPER_ETHAN] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("ETHAN      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CamperEthan),
    },

    [TRAINER_POKEFAN_145] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 33,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("11TRAINER/1"),
        .items = {ITEM_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Pokefan145),
    },

    [TRAINER_FISHERMAN_146] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _(" 3TRAINER/1"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Fisherman146),
    },

    [TRAINER_POKEMANIAC_MARCO] = {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("MARCO!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokemaniacMarco),
    },

    [TRAINER_CAMPER_148] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _(" 6TRAINER/1"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Camper148),
    },

    [TRAINER_COOLTRAINER_GWEN] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("GWEN!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerGwen),
    },

    [TRAINER_PICNICKER_DIANA] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("DIANA      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerDiana),
    },

    [TRAINER_MEDIUM_DORIS] = {
        .trainerClass = TRAINER_CLASS_CHANNELER, // "MEDIUM"
        .encounterMusic_gender = 126,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("DORIS!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_MediumDoris),
    },

    [TRAINER_PICNICKER_152] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _(" 7TRAINER/1"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Picnicker152),
    },

    [TRAINER_PICNICKER_153] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _(" 4TRAINER/1"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Picnicker153),
    },

    [TRAINER_POKEFAN_154] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 32,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("15TRAINER/1"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Pokefan154),
    },

    [TRAINER_PICNICKER_CAITLIN] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("CAITLIN    "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerCaitlin),
    },

    [TRAINER_OFFICER_IZAWA] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_F, // "OFFICER"
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .trainerName = _("IZAWA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_OfficerIzawa),
    },

    [TRAINER_PICNICKER_EDNA] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("EDNA!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerEdna),
    },

    [TRAINER_CAMPER_IVAN] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("IVAN!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CamperIvan),
    },

    [TRAINER_LASS_ELLEN] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("ELLEN!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassEllen),
    },

    [TRAINER_SCHOOLBOY_JOE] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JOE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SchoolboyJoe),
    },

    [TRAINER_SAGE_PING_2] = {
        .trainerClass = TRAINER_CLASS_HEX_MANIAC, // "SAGE"
        .encounterMusic_gender = 72,
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_F,
        .trainerName = _("PING!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SagePing2),
    },

    [TRAINER_POKEMANIAC_DONALD] = {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("DONALD!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokemaniacDonald),
    },

    [TRAINER_HIKER_163] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _(" 5TRAINER/1"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Hiker163),
    },

    [TRAINER_SAILOR_ERNEST] = {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = 85,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("ERNEST!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SailorErnest),
    },

    [TRAINER_GENTLEMAN_PRESTON] = {
        .trainerClass = TRAINER_CLASS_RS_GENTLEMAN,
        .encounterMusic_gender = 123,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("PRESTON!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_GentlemanPreston),
    },

    [TRAINER_POKEMANIAC_WINSTON] = {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("WINSTON    "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokemaniacWinston),
    },

    [TRAINER_CAMPER_SPENCER] = {
        .trainerClass = TRAINER_CLASS_RS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("SPENCER!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CamperSpencer),
    },

    [TRAINER_POKEMANIAC_SHANE] = {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("SHANE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokemaniacShane),
    },

    [TRAINER_SUPER_NERD_ERIC] = {
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = 89,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("ERIC!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SuperNerdEric),
    },

    [TRAINER_BOARDER_RONALD] = {
        .trainerClass = TRAINER_CLASS_BOARDER,
        .encounterMusic_gender = 38,
        .trainerPic = TRAINER_PIC_RS_FISHERMAN,
        .trainerName = _("RONALD!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BoarderRonald),
    },

    [TRAINER_PKMN_THIEF_ASHLEE] = {
        .trainerClass = TRAINER_CLASS_RS_CHAMPION, // "PKMN THIEF"
        .encounterMusic_gender = 74,
        .trainerPic = TRAINER_PIC_MAGMA_ADMIN_F,
        .trainerName = _("ASHLEE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnThiefAshlee),
    },

    [TRAINER_HIKER_172] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("24TRAINER/1"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Hiker172),
    },

    [TRAINER_SUPER_NERD_LESLIE] = {
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = 89,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("LESLIE     "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_SuperNerdLeslie),
    },

    [TRAINER_BOARDER_DOUGLAS] = {
        .trainerClass = TRAINER_CLASS_BOARDER,
        .encounterMusic_gender = 38,
        .trainerPic = TRAINER_PIC_RS_FISHERMAN,
        .trainerName = _("DOUGLAS!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BoarderDouglas),
    },

    [TRAINER_SAILOR_KENNETH] = {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = 85,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("KENNETH!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SailorKenneth),
    },

    [TRAINER_BOARDER_BRAD] = {
        .trainerClass = TRAINER_CLASS_BOARDER,
        .encounterMusic_gender = 38,
        .trainerPic = TRAINER_PIC_RS_FISHERMAN,
        .trainerName = _("BRAD!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BoarderBrad),
    },

    [TRAINER_COOLTRAINER_AARON] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("AARON!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerAaron),
    },

    [TRAINER_FISHERMAN_MARVIN] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("MARVIN!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanMarvin),
    },

    [TRAINER_SUPER_NERD_DEREK] = {
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = 89,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("DEREK      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SuperNerdDerek),
    },

    [TRAINER_COOLTRAINER_RYAN] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("RYAN!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerRyan),
    },

    [TRAINER_HIKER_RUSELL] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("RUSELL!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerRusell),
    },

    [TRAINER_HIKER_NOLAND] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("NOLAND!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerNoland),
    },

    [TRAINER_HIKER_NOB] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("NOB        "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerNob),
    },

    [TRAINER_HIKER_WAYNE] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("WAYNE      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerWayne),
    },

    [TRAINER_LEADER_185] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("-EDIT-"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_Leader185),
    },

    [TRAINER_HIKER_PHILLIP] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("PHILLIP!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerPhillip),
    },

    [TRAINER_PKMN_TRAINER_187] = {
        .trainerClass = TRAINER_CLASS_NONE,
        .encounterMusic_gender = 70,
        .trainerPic = TRAINER_PIC_RS_SIS_AND_BRO,
        .trainerName = _("-EDIT-"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnTrainer187),
    },

    [TRAINER_POKEMANIAC_188] = {
        .trainerClass = TRAINER_CLASS_RS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("20TRAINER/1"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Pokemaniac188),
    },

    [TRAINER_PKMN_TRAINER_ARD] = {
        .trainerClass = TRAINER_CLASS_RS_ELITE_FOUR, // "PKMN TRAINER"
        .encounterMusic_gender = 67,
        .trainerPic = TRAINER_PIC_RS_HIKER,
        .trainerName = _("ARD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnTrainerArd),
    },

    [TRAINER_PKMN_THIEF_190] = {
        .trainerClass = TRAINER_CLASS_RS_CHAMPION, // "PKMN THIEF"
        .encounterMusic_gender = 74,
        .trainerPic = TRAINER_PIC_MAGMA_ADMIN_F,
        .trainerName = _("???"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnThief190),
    },

    [TRAINER_HIKER_TIMOTHY] = {
        .trainerClass = TRAINER_CLASS_RS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("TIMOTHY!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerTimothy),
    },

    [TRAINER_HIKER_YUZO] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("YUZO!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerYuzo),
    },

    [TRAINER_HIKER_MICHAEL] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("MICHAEL!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerMichael),
    },

    [TRAINER_PKMN_TRAINER_194] = {
        .trainerClass = TRAINER_CLASS_RS_ELITE_FOUR, // "PKMN TRAINER"
        .encounterMusic_gender = 28,
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .trainerName = _("???"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnTrainer194),
    },

    [TRAINER_PKMN_TRAINER_CARLOS] = {
        .trainerClass = TRAINER_CLASS_RS_ELITE_FOUR, // "PKMN TRAINER"
        .encounterMusic_gender = 28,
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .trainerName = _("CARLOS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnTrainerCarlos),
    },

    [TRAINER_PKMN_TRAINER_CARLOS_2] = {
        .trainerClass = TRAINER_CLASS_RS_ELITE_FOUR, // "PKMN TRAINER"
        .encounterMusic_gender = 28,
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .trainerName = _("CARLOS"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnTrainerCarlos2),
    },

    [TRAINER_PKMN_TRAINER_CARLOS_3] = {
        .trainerClass = TRAINER_CLASS_RS_ELITE_FOUR, // "PKMN TRAINER"
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .trainerName = _("CARLOS"),
        .items = {ITEM_FULL_RESTORE, ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_FULL_HEAL},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnTrainerCarlos3),
    },

    [TRAINER_PKMN_TRAINER_CARLOS_4] = {
        .trainerClass = TRAINER_CLASS_RS_ELITE_FOUR, // "PKMN TRAINER"
        .encounterMusic_gender = 28,
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .trainerName = _("CARLOS"),
        .items = {ITEM_SUPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnTrainerCarlos4),
    },

    [TRAINER_PKMN_TRAINER_ARD_2] = {
        .trainerClass = TRAINER_CLASS_RS_ELITE_FOUR, // "PKMN TRAINER"
        .encounterMusic_gender = 67,
        .trainerPic = TRAINER_PIC_RS_HIKER,
        .trainerName = _("ARD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnTrainerArd2),
    },

    [TRAINER_HIKER_DOUG] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 91,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("DOUG"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerDoug),
    },

    [TRAINER_BIKER_HIDEO] = {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = 91,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("HIDEO      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BikerHideo),
    },

    [TRAINER_PKMN_TRAINER_ARD_3] = {
        .trainerClass = TRAINER_CLASS_RS_ELITE_FOUR, // "PKMN TRAINER"
        .encounterMusic_gender = 67,
        .trainerPic = TRAINER_PIC_RS_HIKER,
        .trainerName = _("ARD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnTrainerArd3),
    },

    [TRAINER_BIKER_BILLY] = {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = 91,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("BILLY      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BikerBilly),
    },

    [TRAINER_COOL_COUPLE_DANTE_AND_RINA] = {
        .trainerClass = TRAINER_CLASS_RS_LEADER, // "COOL COUPLE"
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_COOL_COUPLE,
        .trainerName = _("DANTE&RINA"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_CoolCoupleDanteAndRina),
    },

    [TRAINER_PKMN_TRAINER_205] = {
        .trainerClass = TRAINER_CLASS_RS_ELITE_FOUR, // "PKMN TRAINER"
        .encounterMusic_gender = 65,
        .trainerPic = TRAINER_PIC_RS_LASS,
        .trainerName = _("???"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnTrainer205),
    },

    [TRAINER_PKMN_TRAINER_CARLOS_5] = {
        .trainerClass = TRAINER_CLASS_RS_ELITE_FOUR, // "PKMN TRAINER"
        .encounterMusic_gender = 28,
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .trainerName = _("CARLOS"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnTrainerCarlos5),
    },

    [TRAINER_PKMN_TRAINER_JESS_AND_JAMIE] = {
        .trainerClass = TRAINER_CLASS_RS_ELITE_FOUR, // "PKMN TRAINER"
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .trainerName = _("JESS&JAMIE"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnTrainerJessAndJamie),
    },

    [TRAINER_ROCKET_DUO_JESS_AND_JAMIE] = {
        .trainerClass = TRAINER_CLASS_TRIATHLETE, // "ROCKET DUO"
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .trainerName = _("JESS&JAMIE"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_RocketDuoJessAndJamie),
    },

    [TRAINER_ROCKET_DUO_JESS_AND_JAMIE_2] = {
        .trainerClass = TRAINER_CLASS_TRIATHLETE, // "ROCKET DUO"
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .trainerName = _("JESS&JAMIE"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_RocketDuoJessAndJamie2),
    },

    [TRAINER_FIREBREATHER_BILL] = {
        .trainerClass = TRAINER_CLASS_KINDLER, // "FIREBREATHER"
        .encounterMusic_gender = 70,
        .trainerPic = TRAINER_PIC_RS_SIS_AND_BRO,
        .trainerName = _("BILL!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FirebreatherBill),
    },

    [TRAINER_BURGLAR_FREDRICK] = {
        .trainerClass = TRAINER_CLASS_BURGLAR,
        .encounterMusic_gender = 92,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("FREDRICK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BurglarFredrick),
    },

    [TRAINER_COOLTRAINER_BLAKE] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("BLAKE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerBlake),
    },

    [TRAINER_FIREBREATHER_NED] = {
        .trainerClass = TRAINER_CLASS_KINDLER, // "FIREBREATHER"
        .encounterMusic_gender = 70,
        .trainerPic = TRAINER_PIC_RS_SIS_AND_BRO,
        .trainerName = _("NED!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FirebreatherNed),
    },

    [TRAINER_BURGLAR_RAMON] = {
        .trainerClass = TRAINER_CLASS_BURGLAR,
        .encounterMusic_gender = 92,
        .trainerPic = TRAINER_PIC_BURGLAR,
        .trainerName = _("RAMON      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BurglarRamon),
    },

    [TRAINER_BURGLAR_EDDIE] = {
        .trainerClass = TRAINER_CLASS_BURGLAR,
        .encounterMusic_gender = 92,
        .trainerPic = TRAINER_PIC_BURGLAR,
        .trainerName = _("EDDIE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BurglarEddie),
    },

    [TRAINER_SCHOOLBOY_NATE] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("NATE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SchoolboyNate),
    },

    [TRAINER_BIKER_ZEKE] = {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = 91,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("ZEKE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BikerZeke),
    },

    [TRAINER_BURGLAR_SIMON] = {
        .trainerClass = TRAINER_CLASS_BURGLAR,
        .encounterMusic_gender = 92,
        .trainerPic = TRAINER_PIC_BURGLAR,
        .trainerName = _("SIMON      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BurglarSimon),
    },

    [TRAINER_SCHOOLBOY_RICKY] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("RICKY!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SchoolboyRicky),
    },

    [TRAINER_SUPER_NERD_SAM] = {
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = 89,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("SAM!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SuperNerdSam),
    },

    [TRAINER_ENGINEER_BRAXTON] = {
        .trainerClass = TRAINER_CLASS_ENGINEER,
        .encounterMusic_gender = 93,
        .trainerPic = TRAINER_PIC_ENGINEER,
        .trainerName = _("BRAXTON    "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_EngineerBraxton),
    },

    [TRAINER_COOLTRAINER_222] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("28TRAINER/1"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Cooltrainer222),
    },

    [TRAINER_BURGLAR_DUNCAN] = {
        .trainerClass = TRAINER_CLASS_BURGLAR,
        .encounterMusic_gender = 92,
        .trainerPic = TRAINER_PIC_BURGLAR,
        .trainerName = _("DUNCAN!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BurglarDuncan),
    },

    [TRAINER_FISHERMAN_SCOTT] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("SCOTT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanScott),
    },

    [TRAINER_FIREBREATHER_LYLE] = {
        .trainerClass = TRAINER_CLASS_KINDLER, // "FIREBREATHER"
        .encounterMusic_gender = 70,
        .trainerPic = TRAINER_PIC_RS_SIS_AND_BRO,
        .trainerName = _("LYLE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FirebreatherLyle),
    },

    [TRAINER_FISHERMAN_HENRY] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("HENRY!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanHenry),
    },

    [TRAINER_FISHERMAN_HANK] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("HANK       "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanHank),
    },

    [TRAINER_JUGGLER_228] = {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = 102,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _(" 8TRAINER/1"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Juggler228),
    },

    [TRAINER_FISHERMAN_JUSTIN] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("JUSTIN!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanJustin),
    },

    [TRAINER_FISHERMAN_EDGAR] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("EDGAR!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanEdgar),
    },

    [TRAINER_POKEFAN_JOSHUA] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 32,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("JOSHUA!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokefanJoshua),
    },

    [TRAINER_COOLTRAINER_IRENE] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("IRENE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerIrene),
    },

    [TRAINER_COOLTRAINER_JENN] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("JENN!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerJenn),
    },

    [TRAINER_COOLTRAINER_KATE] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("KATE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerKate),
    },

    [TRAINER_SWIMMER_M_SIMON] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = 95,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("SIMON!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerMSimon),
    },

    [TRAINER_SWIMMER_M_RANDALL] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("RANDALL!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerMRandall),
    },

    [TRAINER_SWIMMER_M_KIRK] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = 95,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("KIRK!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerMKirk),
    },

    [TRAINER_FISHERMAN_RAYMOND] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("RAYMOND!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanRaymond),
    },

    [TRAINER_SWIMMER_M_CHARLIE] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = 95,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("CHARLIE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerMCharlie),
    },

    [TRAINER_POKEMANIAC_ETHAN] = {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("ETHAN!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokemaniacEthan),
    },

    [TRAINER_HIKER_BAILEY] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("BAILEY!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerBailey),
    },

    [TRAINER_BIKER_JOEL] = {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = 91,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("JOEL!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BikerJoel),
    },

    [TRAINER_SWIMMER_M_DEAN] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = 95,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("DEAN       "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerMDean),
    },

    [TRAINER_FISHERMAN_244] = {
        .trainerClass = TRAINER_CLASS_RS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("21TRAINER/1"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Fisherman244),
    },

    [TRAINER_FISHERMAN_MARTIN] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 95,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("MARTIN!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanMartin),
    },

    [TRAINER_SWIMMER_M_JACK] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = 95,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("JACK       "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerMJack),
    },

    [TRAINER_CAMPER_DEAN] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("DEAN!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CamperDean),
    },

    [TRAINER_SAILOR_STANLY] = {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = 85,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("STANLY!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SailorStanly),
    },

    [TRAINER_POKEFAN_JEREMY] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 32,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("JEREMY!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokefanJeremy),
    },

    [TRAINER_HIKER_SIDNEY] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("SIDNEY!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerSidney),
    },

    [TRAINER_PICNICKER_HEIDI] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("HEIDI!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerHeidi),
    },

    [TRAINER_BUG_CATCHER_ROB] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("ROB!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcherRob),
    },

    [TRAINER_BIRD_KEEPER_ROY] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("ROY!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperRoy),
    },

    [TRAINER_CUE_BALL_ZEEK] = {
        .trainerClass = TRAINER_CLASS_CUE_BALL,
        .encounterMusic_gender = 96,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = _("ZEEK       "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CueBallZeek),
    },

    [TRAINER_BURGLAR_CORY] = {
        .trainerClass = TRAINER_CLASS_BURGLAR,
        .encounterMusic_gender = 92,
        .trainerPic = TRAINER_PIC_BURGLAR,
        .trainerName = _("CORY!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BurglarCory),
    },

    [TRAINER_TEACHER_HILLARY] = {
        .trainerClass = TRAINER_CLASS_RS_RUIN_MANIAC, // "TEACHER"
        .encounterMusic_gender = 96,
        .trainerPic = TRAINER_PIC_OLD_COUPLE,
        .trainerName = _("HILLARY!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeacherHillary),
    },

    [TRAINER_SUPER_NERD_SHAWN] = {
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = 89,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("SHAWN!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SuperNerdShawn),
    },

    [TRAINER_SWIMMER_F_SUSIE] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = 99,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("SUSIE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerFSusie),
    },

    [TRAINER_SWIMMER_F_WENDY] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = 97,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("WENDY!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerFWendy),
    },

    [TRAINER_SWIMMER_F_KARA] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = 99,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("KARA!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerFKara),
    },

    [TRAINER_SAILOR_261] = {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = 85,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("17TRAINER/1"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Sailor261),
    },

    [TRAINER_JUGGLER_FRITZ] = {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = 102,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("FRITZ!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_JugglerFritz),
    },

    [TRAINER_LEADER_JANINE] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | 97,
        .trainerPic = TRAINER_PIC_LEADER_KOGA,
        .trainerName = _("JANINE"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_LeaderJanine),
    },

    [TRAINER_BEAUTY_CASSIE] = {
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = 98,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("CASSIE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BeautyCassie),
    },

    [TRAINER_SWIMMER_M_PARKER] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = 95,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("PARKER!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerMParker),
    },

    [TRAINER_BEAUTY_SAMANTHA] = {
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = 98,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("SAMANTHA!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BeautySamantha),
    },

    [TRAINER_BEAUTY_LORI] = {
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = 98,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("LORI       "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BeautyLori),
    },

    [TRAINER_BEAUTY_VICTORIA] = {
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = 98,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("VICTORIA!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BeautyVictoria),
    },

    [TRAINER_SAILOR_SHEILA] = {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = 85,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("SHEILA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SailorSheila),
    },

    [TRAINER_SWIMMER_F_DIANA] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = 99,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("DIANA!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerFDiana),
    },

    [TRAINER_SWIMMER_F_KAYLEE] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = 99,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("KAYLEE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerFKaylee),
    },

    [TRAINER_SWIMMER_F_PAULA] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = 99,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("PAULA!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerFPaula),
    },

    [TRAINER_COOLTRAINER_LOLA] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("LOLA!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerLola),
    },

    [TRAINER_BEAUTY_VALERIE] = {
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = 98,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("VALERIE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BeautyValerie),
    },

    [TRAINER_COOLTRAINER_CAROL] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("CAROL!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerCarol),
    },

    [TRAINER_BIRD_KEEPER_THEO] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("THEO!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperTheo),
    },

    [TRAINER_PSYCHIC_RODNEY] = {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = 100,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("RODNEY!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PsychicRodney),
    },

    [TRAINER_COOLTRAINER_SEAN] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("SEAN!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerSean),
    },

    [TRAINER_LASS_SHANNON] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("SHANNON!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassShannon),
    },

    [TRAINER_FISHERMAN_JONAH] = {
        .trainerClass = TRAINER_CLASS_RS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("JONAH!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanJonah),
    },

    [TRAINER_PSYCHIC_NORMAN] = {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = 100,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("NORMAN!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PsychicNorman),
    },

    [TRAINER_PSYCHIC_MARK] = {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("MARK!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PsychicMark),
    },

    [TRAINER_PSYCHIC_PRESTON] = {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = 100,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("PRESTON    "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PsychicPreston),
    },

    [TRAINER_PSYCHIC_GILBERT] = {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = 100,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("GILBERT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PsychicGilbert),
    },

    [TRAINER_SCHOOLBOY_285] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("14TRAINER/1"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Schoolboy285),
    },

    [TRAINER_SWIMMER_F_BRIANA] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = 99,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("BRIANA!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerFBriana),
    },

    [TRAINER_JUGGLER_HORTON] = {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = 102,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("HORTON!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_JugglerHorton),
    },

    [TRAINER_GUITARIST_VINCENT] = {
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .encounterMusic_gender = 17,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .trainerName = _("VINCENT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_GuitaristVincent),
    },

    [TRAINER_PSYCHIC_PHIL] = {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = 100,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("PHIL!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PsychicPhil),
    },

    [TRAINER_JUGGLER_GREGORY] = {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = 102,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("GREGORY    "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_JugglerGregory),
    },

    [TRAINER_ROCKET_DUO_JESS_AND_JAMIE_3] = {
        .trainerClass = TRAINER_CLASS_TRIATHLETE, // "ROCKET DUO"
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .trainerName = _("JESS&JAMIE"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_RocketDuoJessAndJamie3),
    },

    [TRAINER_JUGGLER_KAYDEN] = {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = 102,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("KAYDEN     "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_JugglerKayden),
    },

    [TRAINER_SCHOOLBOY_TOMMY] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("TOMMY!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SchoolboyTommy),
    },

    [TRAINER_MEDIUM_ERIS] = {
        .trainerClass = TRAINER_CLASS_CHANNELER, // "MEDIUM"
        .encounterMusic_gender = 126,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("ERIS!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_MediumEris),
    },

    [TRAINER_PSYCHIC_JARED] = {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = 100,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("JARED!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PsychicJared),
    },

    [TRAINER_TAMER_JASON] = {
        .trainerClass = TRAINER_CLASS_TAMER,
        .encounterMusic_gender = 103,
        .trainerPic = TRAINER_PIC_TAMER,
        .trainerName = _("JASON      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TamerJason),
    },

    [TRAINER_YOUNGSTER_FABRICIO] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("FABRICIO!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungsterFabricio),
    },

    [TRAINER_MEDIUM_SARINA] = {
        .trainerClass = TRAINER_CLASS_CHANNELER, // "MEDIUM"
        .encounterMusic_gender = 126,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("SARINA!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_MediumSarina),
    },

    [TRAINER_POKEFAN_GEORGIA] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 33,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("GEORGIA!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokefanGeorgia),
    },

    [TRAINER_BIRD_KEEPER_ROD] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("ROD!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperRod),
    },

    [TRAINER_SWIMMER_M_GEORGE] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = 95,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("GEORGE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerMGeorge),
    },

    [TRAINER_COOLTRAINER_302] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("27TRAINER/1"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Cooltrainer302),
    },

    [TRAINER_BIRD_KEEPER_DONALD] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("DONALD     "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperDonald),
    },

    [TRAINER_BIRD_KEEPER_BRYAN] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("BRYAN!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperBryan),
    },

    [TRAINER_BIKER_DWAYNE] = {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = 91,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("DWAYNE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BikerDwayne),
    },

    [TRAINER_SCHOOLBOY_306] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("10TRAINER/1"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Schoolboy306),
    },

    [TRAINER_CAMPER_RAOUL] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("RAOUL!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CamperRaoul),
    },

    [TRAINER_BIRD_KEEPER_RAMIRO] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("RAMIRO     "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperRamiro),
    },

    [TRAINER_BUG_CATCHER_309] = {
        .trainerClass = TRAINER_CLASS_RS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _(" 2TRAINER/1"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcher309),
    },

    [TRAINER_BIRD_KEEPER_PETER] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("PETER!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperPeter),
    },

    [TRAINER_FISHERMAN_STEPHEN] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("STEPHEN!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanStephen),
    },

    [TRAINER_BUG_CATCHER_KEN] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("KEN!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcherKen),
    },

    [TRAINER_BIRD_KEEPER_TOBY] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("TOBY!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperToby),
    },

    [TRAINER_HIKER_KENNY] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("KENNY!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerKenny),
    },

    [TRAINER_BIKER_ROWDY] = {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = 91,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("ROWDY!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BikerRowdy),
    },

    [TRAINER_BLACK_BELT_316] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("23TRAINER/1"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BlackBelt316),
    },

    [TRAINER_BLACK_BELT_KIYO] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("KIYO!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_BlackBeltKiyo),
    },

    [TRAINER_BIRD_KEEPER_DENIS] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("DENIS!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_BirdKeeperDenis),
    },

    [TRAINER_BLACK_BELT_NOB] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("NOB!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_BlackBeltNob),
    },

    [TRAINER_BLACK_BELT_AARON] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("AARON      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_BlackBeltAaron),
    },

    [TRAINER_BLACK_BELT_LUNG] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("LUNG!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_BlackBeltLung),
    },

    [TRAINER_DRAGON_TAMER_MIKAHIL] = {
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
        .encounterMusic_gender = 45,
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .trainerName = _("MIKAHIL!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_DragonTamerMikahil),
    },

    [TRAINER_BLACK_BELT_KIYO_2] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("KIYO       "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_BlackBeltKiyo2),
    },

    [TRAINER_BLACK_BELT_WAI] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("WAI!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_BlackBeltWai),
    },

    [TRAINER_HIKER_ERIK] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("ERIK!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_HikerErik),
    },

    [TRAINER_PKMN_TRAINER_326] = {
        .trainerClass = TRAINER_CLASS_RS_ELITE_FOUR, // "PKMN TRAINER"
        .encounterMusic_gender = 54,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("???"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PkmnTrainer326),
    },

    [TRAINER_PKMN_TRAINER_327] = {
        .trainerClass = TRAINER_CLASS_RS_ELITE_FOUR, // "PKMN TRAINER"
        .encounterMusic_gender = 54,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("???"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PkmnTrainer327),
    },

    [TRAINER_PKMN_TRAINER_328] = {
        .trainerClass = TRAINER_CLASS_RS_ELITE_FOUR, // "PKMN TRAINER"
        .encounterMusic_gender = 106,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("???"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PkmnTrainer328),
    },

    [TRAINER_RIVAL_329] = {
        .trainerClass = TRAINER_CLASS_RIVAL_EARLY,
        .encounterMusic_gender = 54,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("-EDIT-"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_Rival329),
    },

    [TRAINER_LEADER_CHUCK] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_INTERVIEWER,
        .trainerName = _("CHUCK"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_LeaderChuck),
    },

    [TRAINER_LEADER_JASMINE] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .trainerName = _("JASMINE"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_LeaderJasmine),
    },

    [TRAINER_RIVAL_TERRY] = {
        .trainerClass = TRAINER_CLASS_CHAMPION, // "RIVAL"
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("TERRY      "),
        .items = {ITEM_SUPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_RivalTerry),
    },

    [TRAINER_RIVAL_TERRY_2] = {
        .trainerClass = TRAINER_CLASS_CHAMPION, // "RIVAL"
        .encounterMusic_gender = 54,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("TERRY      "),
        .items = {ITEM_SUPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_RivalTerry2),
    },

    [TRAINER_RIVAL_TERRY_3] = {
        .trainerClass = TRAINER_CLASS_CHAMPION, // "RIVAL"
        .encounterMusic_gender = 54,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("TERRY      "),
        .items = {ITEM_SUPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_RivalTerry3),
    },

    [TRAINER_SAGE_GEN] = {
        .trainerClass = TRAINER_CLASS_HEX_MANIAC, // "SAGE"
        .encounterMusic_gender = 72,
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_F,
        .trainerName = _("GEN!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SageGen),
    },

    [TRAINER_LEADER_336] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = 107,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("-EDIT-"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_Leader336),
    },

    [TRAINER_SCIENTIST_JED] = {
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = 107,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("JED!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_ScientistJed),
    },

    [TRAINER_PKMN_THIEF_ASHLEE_2] = {
        .trainerClass = TRAINER_CLASS_RS_CHAMPION, // "PKMN THIEF"
        .encounterMusic_gender = 74,
        .trainerPic = TRAINER_PIC_MAGMA_ADMIN_F,
        .trainerName = _("ASHLEE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnThiefAshlee2),
    },

    [TRAINER_SCIENTIST_MITCH] = {
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = 107,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("MITCH!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_ScientistMitch),
    },

    [TRAINER_ROCKET_DUO_JESS_AND_JAMIE_4] = {
        .trainerClass = TRAINER_CLASS_TRIATHLETE, // "ROCKET DUO"
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .trainerName = _("JESS&JAMIE"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_RocketDuoJessAndJamie4),
    },

    [TRAINER_PKMN_TRAINER_CARLOS_6] = {
        .trainerClass = TRAINER_CLASS_RS_ELITE_FOUR, // "PKMN TRAINER"
        .encounterMusic_gender = 28,
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .trainerName = _("CARLOS"),
        .items = {ITEM_HYPER_POTION, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnTrainerCarlos6),
    },

    [TRAINER_SCIENTIST_ROSS] = {
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = 107,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("ROSS!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_ScientistRoss),
    },

    [TRAINER_SCIENTIST_PARKER] = {
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = 107,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("PARKER     "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_ScientistParker),
    },

    [TRAINER_PKMN_TRAINER_AMELIA] = {
        .trainerClass = TRAINER_CLASS_RS_ELITE_FOUR, // "PKMN TRAINER"
        .encounterMusic_gender = 65,
        .trainerPic = TRAINER_PIC_RS_LASS,
        .trainerName = _("AMELIA"),
        .items = {ITEM_HYPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnTrainerAmelia),
    },

    [TRAINER_SCIENTIST_TRAVIS] = {
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = 107,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("TRAVIS     "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_ScientistTravis),
    },

    [TRAINER_SCIENTIST_MARC] = {
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("MARC!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_ScientistMarc),
    },

    [TRAINER_SCIENTIST_RICH] = {
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = 107,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("RICH!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_ScientistRich),
    },

    [TRAINER_TEAM_ROCKET_EXECUTIVE] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
        .trainerName = _("EXECUTIVE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketExecutive),
    },

    [TRAINER_SCHOOLBOY_BILLY] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("BILLY!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SchoolboyBilly),
    },

    [TRAINER_LEADER_CLAIR] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = 53,
        .trainerPic = TRAINER_PIC_RS_SAILOR,
        .trainerName = _("CLAIR"),
        .items = {ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_FULL_HEAL},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_LeaderClair),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_4] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt4),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_5] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt5),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_6] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt6),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_7] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt7),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_8] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt8),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_9] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt9),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_10] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt10),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_11] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt11),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_12] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt12),
    },

    [TRAINER_PKMN_TRAINER_360] = {
        .trainerClass = TRAINER_CLASS_NONE,
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("-EDIT-"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnTrainer360),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_13] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt13),
    },

    [TRAINER_CLASS25_362] = {
        .trainerClass = TRAINER_CLASS_SCHOOL_KID, // ""
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("-EDIT-"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_Class25362),
    },

    [TRAINER_LEADER_MORTY] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = 97,
        .trainerPic = TRAINER_PIC_GAMER,
        .trainerName = _("MORTY"),
        .items = {ITEM_HYPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_LeaderMorty),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_14] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt14),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_15] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt15),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_16] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt16),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_17] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt17),
    },

    [TRAINER_ROCKET_DUO_368] = {
        .trainerClass = TRAINER_CLASS_INTERVIEWER, // "ROCKET DUO"
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .trainerName = _(""),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_RocketDuo368),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_18] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt18),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_19] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt19),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_20] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt20),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_21] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt21),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_22] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt22),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_23] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt23),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_24] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt24),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_25] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt25),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_26] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt26),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_27] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt27),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_28] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt28),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_29] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt29),
    },

    [TRAINER_TEAM_ROCKET_EXECUTIVE_2] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_AQUA_LEADER_ARCHIE,
        .trainerName = _("EXECUTIVE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketExecutive2),
    },

    [TRAINER_COOL_COUPLE_DANTE_AND_RINA_2] = {
        .trainerClass = TRAINER_CLASS_RS_LEADER, // "COOL COUPLE"
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_COOL_COUPLE,
        .trainerName = _("DANTE&RINA"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_CoolCoupleDanteAndRina2),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_30] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt30),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_31] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt31),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_32] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt32),
    },

    [TRAINER_TEAM_ROCKET_EXECUTIVE_3] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
        .trainerName = _("EXECUTIVE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketExecutive3),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_33] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt33),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_34] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt34),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_35] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt35),
    },

    [TRAINER_TEAM_ROCKET_EXECUTIVE_4] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_AQUA_LEADER_ARCHIE,
        .trainerName = _("EXECUTIVE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketExecutive4),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_36] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt36),
    },

    [TRAINER_RIVAL_TERRY_4] = {
        .trainerClass = TRAINER_CLASS_CHAMPION, // "RIVAL"
        .encounterMusic_gender = 54,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("TERRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_RivalTerry4),
    },

    [TRAINER_RIVAL_TERRY_5] = {
        .trainerClass = TRAINER_CLASS_CHAMPION, // "RIVAL"
        .encounterMusic_gender = 54,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("TERRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_RivalTerry5),
    },

    [TRAINER_RIVAL_TERRY_6] = {
        .trainerClass = TRAINER_CLASS_CHAMPION, // "RIVAL"
        .encounterMusic_gender = 54,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("TERRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_RivalTerry6),
    },

    [TRAINER_RIVAL_TERRY_7] = {
        .trainerClass = TRAINER_CLASS_CHAMPION, // "RIVAL"
        .encounterMusic_gender = 28,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("TERRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_RivalTerry7),
    },

    [TRAINER_RIVAL_TERRY_8] = {
        .trainerClass = TRAINER_CLASS_CHAMPION, // "RIVAL"
        .encounterMusic_gender = 54,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("TERRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_RivalTerry8),
    },

    [TRAINER_RIVAL_TERRY_9] = {
        .trainerClass = TRAINER_CLASS_CHAMPION, // "RIVAL"
        .encounterMusic_gender = 54,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("TERRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_RivalTerry9),
    },

    [TRAINER_LEADER_MISTY] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = 117,
        .trainerPic = TRAINER_PIC_LEADER_MISTY,
        .trainerName = _("MISTY"),
        .items = {ITEM_HYPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_LeaderMisty),
    },

    [TRAINER_LEADER_LT_SURGE] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = 118,
        .trainerPic = TRAINER_PIC_LEADER_LT_SURGE,
        .trainerName = _("LT.SURGE"),
        .items = {ITEM_HYPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_LeaderLtSurge),
    },

    [TRAINER_LEADER_SABRINA] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = 122,
        .trainerPic = TRAINER_PIC_LEADER_SABRINA,
        .trainerName = _("SABRINA"),
        .items = {ITEM_HYPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_LeaderSabrina),
    },

    [TRAINER_LEADER_ERIKA] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = 119,
        .trainerPic = TRAINER_PIC_LEADER_ERIKA,
        .trainerName = _("ERIKA"),
        .items = {ITEM_HYPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_LeaderErika),
    },

    [TRAINER_LEADER_JANINE_2] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = 120,
        .trainerPic = TRAINER_PIC_LEADER_KOGA,
        .trainerName = _("JANINE"),
        .items = {ITEM_HYPER_POTION, ITEM_DIRE_HIT},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_LeaderJanine2),
    },

    [TRAINER_LEADER_BLAINE] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = 111,
        .trainerPic = TRAINER_PIC_LEADER_BLAINE,
        .trainerName = _("BLAINE"),
        .items = {ITEM_HYPER_POTION, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_LeaderBlaine),
    },

    [TRAINER_LEADER_BLUE] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .trainerName = _("BLUE"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_LeaderBlue),
    },

    [TRAINER_PKMN_THIEF_ASHLEE_3] = {
        .trainerClass = TRAINER_CLASS_RS_CHAMPION, // "PKMN THIEF"
        .encounterMusic_gender = F_TRAINER_FEMALE | 111,
        .trainerPic = TRAINER_PIC_MAGMA_ADMIN_F,
        .trainerName = _("ASHLEE   "),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_PkmnThiefAshlee3),
    },

    [TRAINER_PKMN_TRAINER_AMELIA_2] = {
        .trainerClass = TRAINER_CLASS_RS_ELITE_FOUR, // "PKMN TRAINER"
        .encounterMusic_gender = 65,
        .trainerPic = TRAINER_PIC_RS_LASS,
        .trainerName = _("AMELIA"),
        .items = {ITEM_HYPER_POTION, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnTrainerAmelia2),
    },

    [TRAINER_PKMN_TRAINER_KOGA] = {
        .trainerClass = TRAINER_CLASS_RS_ELITE_FOUR, // "PKMN TRAINER"
        .encounterMusic_gender = 114,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_AGATHA,
        .trainerName = _("KOGA"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnTrainerKoga),
    },

    [TRAINER_LEADER_WHITNEY] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | 111,
        .trainerPic = TRAINER_PIC_RS_POKEMON_RANGER_M,
        .trainerName = _("WHITNEY"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_LeaderWhitney),
    },

    [TRAINER_LEADER_FALKNER] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = 111,
        .trainerPic = TRAINER_PIC_RS_POKEMANIAC,
        .trainerName = _("FALKNER"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_LeaderFalkner),
    },

    [TRAINER_ELITETRAINER_WILL] = {
        .trainerClass = TRAINER_CLASS_ELITE_FOUR, // "ELITETRAINER"
        .encounterMusic_gender = 112,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_LORELEI,
        .trainerName = _("WILL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_ElitetrainerWill),
    },

    [TRAINER_ELITETRAINER_BRUNO] = {
        .trainerClass = TRAINER_CLASS_ELITE_FOUR, // "ELITETRAINER"
        .encounterMusic_gender = 113,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_BRUNO,
        .trainerName = _("BRUNO"),
        .items = {ITEM_MAX_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_ElitetrainerBruno),
    },

    [TRAINER_ELITETRAINER_KOGA] = {
        .trainerClass = TRAINER_CLASS_ELITE_FOUR, // "ELITETRAINER"
        .encounterMusic_gender = 114,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_AGATHA,
        .trainerName = _("KOGA"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_ElitetrainerKoga),
    },

    [TRAINER_ELITETRAINER_KAREN] = {
        .trainerClass = TRAINER_CLASS_ELITE_FOUR, // "ELITETRAINER"
        .encounterMusic_gender = 115,
        .trainerPic = TRAINER_PIC_ELITE_FOUR_LANCE,
        .trainerName = _("KAREN"),
        .items = {ITEM_MAX_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_ElitetrainerKaren),
    },

    [TRAINER_LEADER_FALKNER_2] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = 14,
        .trainerPic = TRAINER_PIC_RS_POKEMANIAC,
        .trainerName = _("FALKNER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_LeaderFalkner2),
    },

    [TRAINER_LEADER_WHITNEY_2] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = 60,
        .trainerPic = TRAINER_PIC_RS_POKEMON_RANGER_M,
        .trainerName = _("WHITNEY"),
        .items = {ITEM_SUPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_LeaderWhitney2),
    },

    [TRAINER_LEADER_BUGSY] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PROFESSOR_OAK,
        .trainerName = _("BUGSY"),
        .items = {ITEM_SUPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_LeaderBugsy),
    },

    [TRAINER_LEADER_CHUCK_2] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_INTERVIEWER,
        .trainerName = _("CHUCK"),
        .items = {ITEM_SUPER_POTION, ITEM_FULL_HEAL},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_LeaderChuck2),
    },

    [TRAINER_LEADER_MORTY_2] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = 97,
        .trainerPic = TRAINER_PIC_GAMER,
        .trainerName = _("MORTY"),
        .items = {ITEM_SUPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_LeaderMorty2),
    },

    [TRAINER_LEADER_PRYCE] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = 62,
        .trainerPic = TRAINER_PIC_MAGMA_LEADER_MAXIE,
        .trainerName = _("PRYCE"),
        .items = {ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_FULL_HEAL},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_LeaderPryce),
    },

    [TRAINER_LEADER_JASMINE_2] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = 63,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
        .trainerName = _("JASMINE"),
        .items = {ITEM_HYPER_POTION, ITEM_SUPER_POTION, ITEM_FULL_HEAL},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_LeaderJasmine2),
    },

    [TRAINER_GENTLEMAN_THOMAS] = {
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = 123,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("THOMAS     "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_GentlemanThomas),
    },

    [TRAINER_GENTLEMAN_GREGORY] = {
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("GREGORY!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_GentlemanGregory),
    },

    [TRAINER_GENTLEMAN_TUCKER] = {
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = 123,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("TUCKER     "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_GentlemanTucker),
    },

    [TRAINER_GENTLEMAN_NORTON] = {
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = 123,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("NORTON     "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_GentlemanNorton),
    },

    [TRAINER_PICNICKER_CARRIE] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 123,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("CARRIE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerCarrie),
    },

    [TRAINER_SCHOOLBOY_KIPP] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 54,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("KIPP!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SchoolboyKipp),
    },

    [TRAINER_CHAMPION_427] = {
        .trainerClass = TRAINER_CLASS_RIVAL_LATE, // "CHAMPION"
        .encounterMusic_gender = 54,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _(""),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Champion427),
    },

    [TRAINER_CHAMPION_428] = {
        .trainerClass = TRAINER_CLASS_RIVAL_LATE, // "CHAMPION"
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _(""),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Champion428),
    },

    [TRAINER_CHAMPION_429] = {
        .trainerClass = TRAINER_CLASS_RIVAL_LATE, // "CHAMPION"
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _(""),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Champion429),
    },

    [TRAINER_CHAMPION_430] = {
        .trainerClass = TRAINER_CLASS_RIVAL_LATE, // "CHAMPION"
        .encounterMusic_gender = 54,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _(""),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Champion430),
    },

    [TRAINER_CHAMPION_431] = {
        .trainerClass = TRAINER_CLASS_RIVAL_LATE, // "CHAMPION"
        .encounterMusic_gender = 54,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _(""),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Champion431),
    },

    [TRAINER_PKMN_TRAINER_ARD_4] = {
        .trainerClass = TRAINER_CLASS_RS_ELITE_FOUR, // "PKMN TRAINER"
        .encounterMusic_gender = 64,
        .trainerPic = TRAINER_PIC_RS_HIKER,
        .trainerName = _("ARD"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_PkmnTrainerArd4),
    },

    [TRAINER_LEADER_BUGSY_2] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PROFESSOR_OAK,
        .trainerName = _("BUGSY"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_LeaderBugsy2),
    },

    [TRAINER_LEADER_PRYCE_2] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = 64,
        .trainerPic = TRAINER_PIC_MAGMA_LEADER_MAXIE,
        .trainerName = _("PRYCE"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_LeaderPryce2),
    },

    [TRAINER_RIVAL_TERRY_10] = {
        .trainerClass = TRAINER_CLASS_CHAMPION, // "RIVAL"
        .encounterMusic_gender = 54,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("TERRY      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_RivalTerry10),
    },

    [TRAINER_RIVAL_TERRY_11] = {
        .trainerClass = TRAINER_CLASS_CHAMPION, // "RIVAL"
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("TERRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_RivalTerry11),
    },

    [TRAINER_RIVAL_TERRY_12] = {
        .trainerClass = TRAINER_CLASS_CHAMPION, // "RIVAL"
        .encounterMusic_gender = 54,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("TERRY      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_RivalTerry12),
    },

    [TRAINER_ELITETRAINER_LANCE] = {
        .trainerClass = TRAINER_CLASS_ELITE_FOUR, // "ELITETRAINER"
        .encounterMusic_gender = 96,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = _("LANCE"),
        .items = {ITEM_FULL_RESTORE, ITEM_MAX_POTION, ITEM_FULL_HEAL},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_ElitetrainerLance),
    },

    [TRAINER_RIVAL_TERRY_13] = {
        .trainerClass = TRAINER_CLASS_CHAMPION, // "RIVAL"
        .encounterMusic_gender = 64,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .trainerName = _("TERRY      "),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_RivalTerry13),
    },

    [TRAINER_RIVAL_TERRY_14] = {
        .trainerClass = TRAINER_CLASS_CHAMPION, // "RIVAL"
        .encounterMusic_gender = 64,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .trainerName = _("TERRY      "),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_RivalTerry14),
    },

    [TRAINER_SAGE_JIN] = {
        .trainerClass = TRAINER_CLASS_HEX_MANIAC, // "SAGE"
        .encounterMusic_gender = 72,
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_F,
        .trainerName = _("JIN!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SageJin),
    },

    [TRAINER_SAGE_NEAL] = {
        .trainerClass = TRAINER_CLASS_HEX_MANIAC, // "SAGE"
        .encounterMusic_gender = 72,
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_F,
        .trainerName = _("NEAL!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SageNeal),
    },

    [TRAINER_MEDIUM_HOPE] = {
        .trainerClass = TRAINER_CLASS_CHANNELER, // "MEDIUM"
        .encounterMusic_gender = 126,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("HOPE       "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_MediumHope),
    },

    [TRAINER_MEDIUM_PAULA] = {
        .trainerClass = TRAINER_CLASS_CHANNELER, // "MEDIUM"
        .encounterMusic_gender = 126,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("PAULA      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_MediumPaula),
    },

    [TRAINER_SAGE_TROY] = {
        .trainerClass = TRAINER_CLASS_HEX_MANIAC, // "SAGE"
        .encounterMusic_gender = 72,
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_F,
        .trainerName = _("TROY!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SageTroy),
    },

    [TRAINER_MEDIUM_JODY] = {
        .trainerClass = TRAINER_CLASS_CHANNELER, // "MEDIUM"
        .encounterMusic_gender = 126,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("JODY       "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_MediumJody),
    },

    [TRAINER_MEDIUM_TAMMY] = {
        .trainerClass = TRAINER_CLASS_CHANNELER, // "MEDIUM"
        .encounterMusic_gender = 126,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("TAMMY      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_MediumTammy),
    },

    [TRAINER_MEDIUM_RUTH] = {
        .trainerClass = TRAINER_CLASS_CHANNELER, // "MEDIUM"
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("RUTH       "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_MediumRuth),
    },

    [TRAINER_MEDIUM_KARINA] = {
        .trainerClass = TRAINER_CLASS_CHANNELER, // "MEDIUM"
        .encounterMusic_gender = 126,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("KARINA     "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_MediumKarina),
    },

    [TRAINER_MEDIUM_JANAE] = {
        .trainerClass = TRAINER_CLASS_CHANNELER, // "MEDIUM"
        .encounterMusic_gender = 126,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("JANAE      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_MediumJanae),
    },

    [TRAINER_SAGE_CHOW] = {
        .trainerClass = TRAINER_CLASS_HEX_MANIAC, // "SAGE"
        .encounterMusic_gender = 72,
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_F,
        .trainerName = _("CHOW!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SageChow),
    },

    [TRAINER_MEDIUM_EMILIA] = {
        .trainerClass = TRAINER_CLASS_CHANNELER, // "MEDIUM"
        .encounterMusic_gender = 126,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("EMILIA     "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_MediumEmilia),
    },

    [TRAINER_MEDIUM_JENNIFER] = {
        .trainerClass = TRAINER_CLASS_CHANNELER, // "MEDIUM"
        .encounterMusic_gender = 126,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("JENNIFER   "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_MediumJennifer),
    },

    [TRAINER_LADY_MARIAM] = {
        .trainerClass = TRAINER_CLASS_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | 126,
        .trainerPic = TRAINER_PIC_LADY,
        .trainerName = _("MARIAM"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LadyMariam),
    },

    [TRAINER_BEAUTY_SHEA] = {
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("SHEA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BeautyShea),
    },

    [TRAINER_YOUNGSTER_FELIX] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("FELIX"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungsterFelix),
    },

    [TRAINER_COOLTRAINER_FEY] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("FEY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerFey),
    },

    [TRAINER_POKEFAN_MANN] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("MANN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokefanMann),
    },

    [TRAINER_MEDIUM_MARTHA] = {
        .trainerClass = TRAINER_CLASS_CHANNELER, // "MEDIUM"
        .encounterMusic_gender = 126,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("MARTHA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_MediumMartha),
    },

    [TRAINER_CAMPER_USHER] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = 126,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("USHER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CamperUsher),
    },

    [TRAINER_LASS_CAMILA] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("CAMILA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassCamila),
    },

    [TRAINER_MEDIUM_GRACE] = {
        .trainerClass = TRAINER_CLASS_CHANNELER, // "MEDIUM"
        .encounterMusic_gender = 126,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("GRACE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_MediumGrace),
    },

    [TRAINER_MEDIUM_STACY] = {
        .trainerClass = TRAINER_CLASS_CHANNELER, // "MEDIUM"
        .encounterMusic_gender = 126,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("STACY      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_MediumStacy),
    },

    [TRAINER_SAGE_NICO] = {
        .trainerClass = TRAINER_CLASS_HEX_MANIAC, // "SAGE"
        .encounterMusic_gender = 72,
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_F,
        .trainerName = _("NICO!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SageNico),
    },

    [TRAINER_FISHERMAN_465] = {
        .trainerClass = TRAINER_CLASS_RS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("18TRAINER/1"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Fisherman465),
    },

    [TRAINER_COOLTRAINER_KEVIN] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("KEVIN!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerKevin),
    },

    [TRAINER_PKMN_TRAINER_467] = {
        .trainerClass = TRAINER_CLASS_NONE,
        .encounterMusic_gender = 28,
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .trainerName = _(""),
        .items = {ITEM_HYPER_POTION, ITEM_FULL_RESTORE, ITEM_HYPER_POTION, ITEM_FULL_HEAL},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PkmnTrainer467),
    },

    [TRAINER_PICNICKER_VALERIE] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("VALERIE    "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerValerie),
    },

    [TRAINER_HIKER_GABRIEL] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("GABRIEL!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerGabriel),
    },

    [TRAINER_SAGE_470] = {
        .trainerClass = TRAINER_CLASS_HEX_MANIAC, // "SAGE"
        .encounterMusic_gender = 34,
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .trainerName = _("-EDIT-"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_Sage470),
    },

    [TRAINER_CAMPER_FLINT] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("FLINT      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CamperFlint),
    },

    [TRAINER_PICNICKER_472] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("19TRAINER/1"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Picnicker472),
    },

    [TRAINER_CAMPER_SID] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("SID!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CamperSid),
    },

    [TRAINER_HIKER_TIM] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("TIM!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerTim),
    },

    [TRAINER_ROCKET_DUO_475] = {
        .trainerClass = TRAINER_CLASS_INTERVIEWER, // "ROCKET DUO"
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .trainerName = _(""),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_RocketDuo475),
    },

    [TRAINER_PICNICKER_LEAH] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("LEAH       "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerLeah),
    },

    [TRAINER_CAMPER_JUSTIN] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("JUSTIN     "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CamperJustin),
    },

    [TRAINER_LASS_MICHELLE] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("MICHELLE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassMichelle),
    },

    [TRAINER_BEAUTY_JULIA] = {
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = 98,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("JULIA!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BeautyJulia),
    },

    [TRAINER_SCHOOLBOY_480] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("12TRAINER/1"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Schoolboy480),
    },

    [TRAINER_PICNICKER_CELIA] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("CELIA      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerCelia),
    },

    [TRAINER_GENTLEMAN_BROOKS] = {
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = 123,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("BROOKS     "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_GentlemanBrooks),
    },

    [TRAINER_GENTLEMAN_LAMAR] = {
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = 123,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("LAMAR      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_GentlemanLamar),
    },

    [TRAINER_TWINS_AMY_AND_MAY] = {
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = 127,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("AMY & MAY!"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TwinsAmyAndMay),
    },

    [TRAINER_LEADER_485] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = 127,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("-EDIT-"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_Leader485),
    },

    [TRAINER_TWINS_ANN_AND_ANNE] = {
        .trainerClass = TRAINER_CLASS_RS_TWINS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("ANN & ANNE!"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TwinsAnnAndAnne),
    },

    [TRAINER_TWINS_MEG_AND_PEG] = {
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = 127,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("MEG & PEG!"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TwinsMegAndPeg),
    },

    [TRAINER_TWINS_JO_AND_ZOE] = {
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("JO & ZOE!"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_TwinsJoAndZoe),
    },

    [TRAINER_YOUNG_COUPLE_LEA_AND_JED] = {
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .trainerName = _("LEA & JED  "),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungCoupleLeaAndJed),
    },

    [TRAINER_SIS_AND_BRO_LIA_AND_LUC] = {
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .trainerName = _("LIA & LUC  "),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SisAndBroLiaAndLuc),
    },

    [TRAINER_SIS_AND_BRO_LIL_AND_IAN] = {
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .trainerName = _("LIL & IAN  "),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SisAndBroLilAndIan),
    },

    [TRAINER_JUGGLER_RONGER] = {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("RONGER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_JugglerRonger),
    },

    [TRAINER_HIKER_HAYDEN] = {
        .trainerClass = TRAINER_CLASS_RS_HIKER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("HAYDEN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerHayden),
    },

    [TRAINER_CRUSH_GIRL_INGRID] = {
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .trainerName = _("INGRID"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CrushGirlIngrid),
    },

    [TRAINER_BIRD_KEEPER_HIRO] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("HIRO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperHiro),
    },

    [TRAINER_HIKER_GRANT] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("GRANT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerGrant),
    },

    [TRAINER_PICNICKER_MONA] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | 83,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("MONA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerMona),
    },

    [TRAINER_YOUNGSTER_498] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _(" 1TRAINER/3"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Youngster498),
    },

    [TRAINER_YOUNGSTER_499] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _(" 1TRAINER/4"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Youngster499),
    },

    [TRAINER_BUG_CATCHER_500] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _(" 9TRAINER/2"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcher500),
    },

    [TRAINER_LASS_501] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("13TRAINER/2"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Lass501),
    },

    [TRAINER_LASS_502] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("13TRAINER/3"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Lass502),
    },

    [TRAINER_BIKER_GLENN] = {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = 91,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("GLENN!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BikerGlenn),
    },

    [TRAINER_BIKER_CHARLES] = {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = 91,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("CHARLES!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BikerCharles),
    },

    [TRAINER_BIRD_KEEPER_BORIS] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("BORIS!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperBoris),
    },

    [TRAINER_BUG_CATCHER_506] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _(" 9TRAINER/3"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcher506),
    },

    [TRAINER_PICNICKER_507] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("16TRAINER/2"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Picnicker507),
    },

    [TRAINER_PICNICKER_508] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("16TRAINER/3"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Picnicker508),
    },

    [TRAINER_BUG_CATCHER_509] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _(" 9TRAINER/4"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcher509),
    },

    [TRAINER_HIKER_FRANKLIN] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("FRANKLIN   "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerFranklin),
    },

    [TRAINER_LEADER_BROCK] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_LEADER_BROCK,
        .trainerName = _("BROCK"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_LeaderBrock),
    },

    [TRAINER_LEADER_MISTY_2] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_LEADER_MISTY,
        .trainerName = _("MISTY"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_LeaderMisty2),
    },

    [TRAINER_LEADER_LT_SURGE_2] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_LEADER_LT_SURGE,
        .trainerName = _("LT. SURGE"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_LeaderLtSurge2),
    },

    [TRAINER_LEADER_SABRINA_2] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MAGMA,
        .trainerPic = TRAINER_PIC_LEADER_SABRINA,
        .trainerName = _("SABRINA"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_LeaderSabrina2),
    },

    [TRAINER_LEADER_ERIKA_2] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_LEADER_ERIKA,
        .trainerName = _("ERIKA"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_LeaderErika2),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_37] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt37),
    },

    [TRAINER_PKMN_TRAINER_517] = {
        .trainerClass = TRAINER_CLASS_RS_ELITE_FOUR, // "PKMN TRAINER"
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("-EDIT-"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnTrainer517),
    },

    [TRAINER_COOLTRAINER_518] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("25TRAINER/1"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_Cooltrainer518),
    },

    [TRAINER_FISHERMAN_KYLE] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("KYLE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanKyle),
    },

    [TRAINER_FISHERMAN_BARNEY] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("BARNEY!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanBarney),
    },

    [TRAINER_PKMN_RANGER_521] = {
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = F_TRAINER_FEMALE | 14,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .trainerName = _("-EDIT-"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnRanger521),
    },

    [TRAINER_PKMN_RANGER_522] = {
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = F_TRAINER_FEMALE | 15,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("-EDIT-"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnRanger522),
    },

    [TRAINER_AROMA_LADY_NIKKI] = {
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | 16,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .trainerName = _("NIKKI      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_AromaLadyNikki),
    },

    [TRAINER_PSYCHIC_HERMAN] = {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = 100,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("HERMAN!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PsychicHerman),
    },

    [TRAINER_LADY_JACKI] = {
        .trainerClass = TRAINER_CLASS_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | 18,
        .trainerPic = TRAINER_PIC_LADY,
        .trainerName = _("JACKI      "),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_LadyJacki),
    },

    [TRAINER_PAINTER_DAISY] = {
        .trainerClass = TRAINER_CLASS_PAINTER,
        .encounterMusic_gender = F_TRAINER_FEMALE | 19,
        .trainerPic = TRAINER_PIC_PAINTER,
        .trainerName = _("DAISY      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PainterDaisy),
    },

    [TRAINER_BIKER_527] = {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = 91,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("-EDIT-"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_Biker527),
    },

    [TRAINER_BIKER_GOON] = {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = 91,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("GOON       "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_BikerGoon),
    },

    [TRAINER_BIKER_529] = {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = 91,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("-EDIT-"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Biker529),
    },

    [TRAINER_BLACK_BELT_KAJI] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = 91,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("KAJI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BlackBeltKaji),
    },

    [TRAINER_BUG_CATCHER_ANTHONY] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("ANTHONY    "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcherAnthony),
    },

    [TRAINER_BUG_CATCHER_ED] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("ED!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcherEd),
    },

    [TRAINER_TWINS_ELI_AND_ANNE] = {
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = 127,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("ELI & ANNE "),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TwinsEliAndAnne),
    },

    [TRAINER_LASS_LINDA] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("LINDA!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassLinda),
    },

    [TRAINER_RIVAL_SILVER] = {
        .trainerClass = TRAINER_CLASS_CHAMPION, // "RIVAL"
        .encounterMusic_gender = 91,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .trainerName = _("SILVER"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_CUSTOM_MOVES(sParty_RivalSilver),
    },

    [TRAINER_TEAM_ROCKET_EXECUTIVE_5] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_AQUA_LEADER_ARCHIE,
        .trainerName = _("EXECUTIVE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketExecutive5),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_38] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt38),
    },

    [TRAINER_ROCKET_DUO_JESS_AND_JAMIE_5] = {
        .trainerClass = TRAINER_CLASS_INTERVIEWER, // "ROCKET DUO"
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .trainerName = _("JESS&JAMIE"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_RocketDuoJessAndJamie5),
    },

    [TRAINER_POKEFAN_ALEX] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 32,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("ALEX!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokefanAlex),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_39] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt39),
    },

    [TRAINER_TEAM_ROCKET_EXECUTIVE_6] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_AQUA_LEADER_ARCHIE,
        .trainerName = _("EXECUTIVE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketExecutive6),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_40] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt40),
    },

    [TRAINER_TEAM_ROCKET_543] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("-EDIT-"),
        .items = {ITEM_HYPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_TeamRocket543),
    },

    [TRAINER_LEADER_544] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("-EDIT-"),
        .items = {ITEM_HYPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_Leader544),
    },

    [TRAINER_SCIENTIST_545] = {
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = 107,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("-EDIT-"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_Scientist545),
    },

    [TRAINER_POKEFAN_CARTER] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 32,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("CARTER!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokefanCarter),
    },

    [TRAINER_SWIMMER_F_MARIA] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = 99,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("MARIA      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerFMaria),
    },

    [TRAINER_SCHOOLBOY_JOHNNY] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JOHNNY!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SchoolboyJohnny),
    },

    [TRAINER_BIRD_KEEPER_549] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("26TRAINER/1"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeper549),
    },

    [TRAINER_LASS_ALICE] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("ALICE!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassAlice),
    },

    [TRAINER_FISHERMAN_TOMMY] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("TOMMY      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanTommy),
    },

    [TRAINER_CRUSH_GIRL_TANYA] = {
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .trainerName = _("TANYA      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_CrushGirlTanya),
    },

    [TRAINER_BLACK_BELT_SHEA] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("SHEA       "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_BlackBeltShea),
    },

    [TRAINER_BLACK_BELT_HUGH] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("HUGH       "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_BlackBeltHugh),
    },

    [TRAINER_FISHERMAN_PHIL] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("PHIL!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanPhil),
    },

    [TRAINER_PICNICKER_CLAIRE] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("CLAIRE     "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerClaire),
    },

    [TRAINER_CRUSH_KIN_MIK_AND_KIA] = {
        .trainerClass = TRAINER_CLASS_CRUSH_KIN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .trainerName = _("MIK & KIA  "),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_CrushKinMikAndKia),
    },

    [TRAINER_LASS_REMI] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("REMI!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassRemi),
    },

    [TRAINER_TUBER_ALEXIS] = {
        .trainerClass = TRAINER_CLASS_TUBER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTERVIEWER,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .trainerName = _("ALEXIS     "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TuberAlexis),
    },

    [TRAINER_TWINS_JOY_AND_MEG] = {
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = 127,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("JOY & MEG  "),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TwinsJoyAndMeg),
    },

    [TRAINER_SWIMMER_F_TISHA] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = 99,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("TISHA      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerFTisha),
    },

    [TRAINER_PAINTER_CELINA] = {
        .trainerClass = TRAINER_CLASS_PAINTER,
        .encounterMusic_gender = F_TRAINER_FEMALE | 19,
        .trainerPic = TRAINER_PIC_PAINTER,
        .trainerName = _("CELINA     "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PainterCelina),
    },

    [TRAINER_PAINTER_RAYNA] = {
        .trainerClass = TRAINER_CLASS_PAINTER,
        .encounterMusic_gender = F_TRAINER_FEMALE | 19,
        .trainerPic = TRAINER_PIC_PAINTER,
        .trainerName = _("RAYNA      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PainterRayna),
    },

    [TRAINER_COOLTRAINER_REZO] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("REZO!"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_CooltrainerRezo),
    },

    [TRAINER_YOUNGSTER_DESTIN] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("DESTIN     "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungsterDestin),
    },

    [TRAINER_BLACK_BELT_RANDY] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = 95,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("RANDY!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BlackBeltRandy),
    },

    [TRAINER_COOLTRAINER_REIKA] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("REIKA!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerReika),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_41] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_TeamRocketGrunt41),
    },

    [TRAINER_BIKER_LARK] = {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("LARK!"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BikerLark),
    },

    [TRAINER_BIRD_KEEPER_MILO] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("MILO       "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperMilo),
    },

    [TRAINER_BIRD_KEEPER_CHAZ] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("CHAZ       "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperChaz),
    },

    [TRAINER_BIRD_KEEPER_HAROLD] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("HAROLD     "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperHarold),
    },

    [TRAINER_FISHERMAN_TYLOR] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("TYLOR      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanTylor),
    },

    [TRAINER_SWIMMER_M_MYMO] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = 95,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("MYMO       "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerMMymo),
    },

    [TRAINER_SWIMMER_F_NICOLE] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = 99,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("NICOLE     "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerFNicole),
    },

    [TRAINER_SIS_AND_BRO_AVA_AND_GEB] = {
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .trainerName = _("AVA & GEB  "),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SisAndBroAvaAndGeb),
    },

    [TRAINER_AROMA_LADY_ROSE] = {
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | 16,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .trainerName = _("ROSE       "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_AromaLadyRose),
    },

    [TRAINER_SWIMMER_M_SAMIR] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = 95,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("SAMIR      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerMSamir),
    },

    [TRAINER_SWIMMER_F_DENISE_2] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = 99,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("DENISE     "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerFDenise2),
    },

    [TRAINER_TWINS_MIU_AND_MIA] = {
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = 127,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("MIU & MIA  "),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TwinsMiuAndMia),
    },

    [TRAINER_HIKER_EARL] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("EARL       "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerEarl),
    },

    [TRAINER_RUIN_MANIAC_FOSTER] = {
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = F_TRAINER_FEMALE | 17,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("FOSTER     "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_RuinManiacFoster),
    },

    [TRAINER_RUIN_MANIAC_LARRY] = {
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = F_TRAINER_FEMALE | 17,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("LARRY      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_RuinManiacLarry),
    },

    [TRAINER_HIKER_DARYL] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("DARYL      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerDaryl),
    },

    [TRAINER_POKEMANIAC_HECTOR] = {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("HECTOR     "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokemaniacHector),
    },

    [TRAINER_PSYCHIC_DARIO] = {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = 100,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("DARIO      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PsychicDario),
    },

    [TRAINER_PSYCHIC_RODETTE] = {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("RODETTE    "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PsychicRodette),
    },

    [TRAINER_AROMA_LADY_MIAH] = {
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | 16,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .trainerName = _("MIAH       "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_AromaLadyMiah),
    },

    [TRAINER_YOUNG_COUPLE_EVE_AND_JON] = {
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .trainerName = _("EVE & JON  "),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungCoupleEveAndJon),
    },

    [TRAINER_ROCKET_DUO_590] = {
        .trainerClass = TRAINER_CLASS_TRIATHLETE, // "ROCKET DUO"
        .encounterMusic_gender = 102,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("-EDIT-"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_RocketDuo590),
    },

    [TRAINER_CRUSH_GIRL_CYNDY] = {
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .trainerName = _("CYNDY      "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_CrushGirlCyndy),
    },

    [TRAINER_CRUSH_GIRL_JOCELYN] = {
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .trainerName = _("JOCELYN    "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_CrushGirlJocelyn),
    },

    [TRAINER_TAMER_EVAN] = {
        .trainerClass = TRAINER_CLASS_TAMER,
        .encounterMusic_gender = 103,
        .trainerPic = TRAINER_PIC_TAMER,
        .trainerName = _("EVAN       "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TamerEvan),
    },

    [TRAINER_POKEMANIAC_MARK] = {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("MARK       "),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokemaniacMark),
    },

    [TRAINER_PKMN_RANGER_595] = {
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = F_TRAINER_FEMALE | 14,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .trainerName = _("-EDIT-"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnRanger595),
    },

    [TRAINER_PKMN_TRAINER_AMELIA_3] = {
        .trainerClass = TRAINER_CLASS_RS_ELITE_FOUR, // "PKMN TRAINER"
        .encounterMusic_gender = F_TRAINER_FEMALE | 14,
        .trainerPic = TRAINER_PIC_RS_LASS,
        .trainerName = _("AMELIA"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_PkmnTrainerAmelia3),
    },

    [TRAINER_PKMN_RANGER_BETH] = {
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = F_TRAINER_FEMALE | 15,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("BETH       "),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PkmnRangerBeth),
    },

    [TRAINER_PKMN_TRAINER_CARLOS_7] = {
        .trainerClass = TRAINER_CLASS_RS_ELITE_FOUR, // "PKMN TRAINER"
        .encounterMusic_gender = 15,
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .trainerName = _("CARLOS"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_PkmnTrainerCarlos7),
    },

    [TRAINER_RIVAL_SILVER_2] = {
        .trainerClass = TRAINER_CLASS_CHAMPION, // "RIVAL"
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .trainerName = _("SILVER"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_RivalSilver2),
    },

    [TRAINER_LEADER_CLAIR_2] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | 111,
        .trainerPic = TRAINER_PIC_RS_SAILOR,
        .trainerName = _("CLAIR"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_LeaderClair2),
    },

    [TRAINER_RIVAL_SILVER_3] = {
        .trainerClass = TRAINER_CLASS_CHAMPION, // "RIVAL"
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .trainerName = _("SILVER"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_RivalSilver3),
    },

    [TRAINER_HIKER_602] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("24TRAINER/3"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Hiker602),
    },

    [TRAINER_HIKER_603] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("-EDIT-"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_Hiker603),
    },

    [TRAINER_LEADER_MORTY_3] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = F_TRAINER_FEMALE | 19,
        .trainerPic = TRAINER_PIC_GAMER,
        .trainerName = _("MORTY"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_LeaderMorty3),
    },

    [TRAINER_BLACK_BELT_605] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("23TRAINER/5"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BlackBelt605),
    },

    [TRAINER_BLACK_BELT_EDITG] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("-EDITG-"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_CUSTOM_MOVES(sParty_BlackBeltEditg),
    },

    [TRAINER_BLACK_BELT_607] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("23TRAINER/4"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BlackBelt607),
    },

    [TRAINER_BLACK_BELT_608] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("23TRAINER/3"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BlackBelt608),
    },

    [TRAINER_BLACK_BELT_609] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("23TRAINER/2"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BlackBelt609),
    },

    [TRAINER_BIRD_KEEPER_610] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("22TRAINER/5"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeper610),
    },

    [TRAINER_BIRD_KEEPER_611] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("22TRAINER/4"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeper611),
    },

    [TRAINER_FISHERMAN_612] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("21TRAINER/5"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Fisherman612),
    },

    [TRAINER_FISHERMAN_613] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("21TRAINER/4"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Fisherman613),
    },

    [TRAINER_FISHERMAN_614] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("21TRAINER/3"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Fisherman614),
    },

    [TRAINER_POKEMANIAC_615] = {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("20TRAINER/5"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Pokemaniac615),
    },

    [TRAINER_POKEMANIAC_616] = {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("20TRAINER/4"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Pokemaniac616),
    },

    [TRAINER_POKEMANIAC_617] = {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("20TRAINER/3"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Pokemaniac617),
    },

    [TRAINER_PICNICKER_618] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("19TRAINER/5"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Picnicker618),
    },

    [TRAINER_PICNICKER_619] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("19TRAINER/4"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Picnicker619),
    },

    [TRAINER_FISHERMAN_620] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("18TRAINER/5"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Fisherman620),
    },

    [TRAINER_PICNICKER_621] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _(" 4TRAINER/2"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Picnicker621),
    },

    [TRAINER_FISHERMAN_622] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("18TRAINER/4"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Fisherman622),
    },

    [TRAINER_FISHERMAN_623] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("18TRAINER/3"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Fisherman623),
    },

    [TRAINER_POKEFAN_624] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 33,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("11TRAINER/2"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Pokefan624),
    },

    [TRAINER_POKEFAN_625] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("11TRAINER/3"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Pokefan625),
    },

    [TRAINER_POKEFAN_626] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 33,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("11TRAINER/4"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Pokefan626),
    },

    [TRAINER_FISHERMAN_627] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _(" 3TRAINER/2"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Fisherman627),
    },

    [TRAINER_FISHERMAN_628] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _(" 3TRAINER/3"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Fisherman628),
    },

    [TRAINER_FISHERMAN_629] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _(" 3TRAINER/4"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Fisherman629),
    },

    [TRAINER_PICNICKER_630] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _(" 7TRAINER/2"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Picnicker630),
    },

    [TRAINER_PICNICKER_631] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _(" 7TRAINER/3"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Picnicker631),
    },

    [TRAINER_PICNICKER_632] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _(" 7TRAINER/4"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Picnicker632),
    },

    [TRAINER_BIRD_KEEPER_633] = {
        .trainerClass = TRAINER_CLASS_RS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("22TRAINER/2"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeper633),
    },

    [TRAINER_BIRD_KEEPER_634] = {
        .trainerClass = TRAINER_CLASS_RS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("22TRAINER/3"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeper634),
    },

    [TRAINER_COOLTRAINER_635] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("28TRAINER/2"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Cooltrainer635),
    },

    [TRAINER_SAILOR_636] = {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = 85,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("17TRAINER/2"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Sailor636),
    },

    [TRAINER_SAILOR_637] = {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("17TRAINER/5"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Sailor637),
    },

    [TRAINER_SAILOR_638] = {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("17TRAINER/4"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Sailor638),
    },

    [TRAINER_SAILOR_639] = {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("17TRAINER/3"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Sailor639),
    },

    [TRAINER_POKEFAN_640] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 32,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("15TRAINER/2"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Pokefan640),
    },

    [TRAINER_POKEFAN_641] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("15TRAINER/3"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Pokefan641),
    },

    [TRAINER_POKEFAN_642] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("15TRAINER/4"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Pokefan642),
    },

    [TRAINER_FISHERMAN_643] = {
        .trainerClass = TRAINER_CLASS_RS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("18TRAINER/2"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Fisherman643),
    },

    [TRAINER_PICNICKER_644] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("16TRAINER/5"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Picnicker644),
    },

    [TRAINER_HIKER_645] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _(" 5TRAINER/2"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Hiker645),
    },

    [TRAINER_PICNICKER_646] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("16TRAINER/4"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Picnicker646),
    },

    [TRAINER_POKEMANIAC_647] = {
        .trainerClass = TRAINER_CLASS_RS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("20TRAINER/2"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Pokemaniac647),
    },

    [TRAINER_POKEFAN_648] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 32,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("15TRAINER/5"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Pokefan648),
    },

    [TRAINER_SCHOOLBOY_649] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("14TRAINER/5"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Schoolboy649),
    },

    [TRAINER_SCHOOLBOY_650] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("14TRAINER/4"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Schoolboy650),
    },

    [TRAINER_SCHOOLBOY_651] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("14TRAINER/3"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Schoolboy651),
    },

    [TRAINER_LASS_652] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("13TRAINER/5"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Lass652),
    },

    [TRAINER_JUGGLER_653] = {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = 102,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _(" 8TRAINER/2"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Juggler653),
    },

    [TRAINER_SCHOOLBOY_654] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("14TRAINER/2"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Schoolboy654),
    },

    [TRAINER_LASS_655] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 85,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("13TRAINER/4"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Lass655),
    },

    [TRAINER_COOLTRAINER_656] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("27TRAINER/2"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Cooltrainer656),
    },

    [TRAINER_COOLTRAINER_657] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("27TRAINER/3"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Cooltrainer657),
    },

    [TRAINER_SCHOOLBOY_658] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("12TRAINER/5"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Schoolboy658),
    },

    [TRAINER_POKEFAN_659] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 33,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("11TRAINER/5"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Pokefan659),
    },

    [TRAINER_SCHOOLBOY_660] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("10TRAINER/5"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Schoolboy660),
    },

    [TRAINER_SCHOOLBOY_661] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 91,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("10TRAINER/4"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Schoolboy661),
    },

    [TRAINER_SCHOOLBOY_662] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("10TRAINER/3"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Schoolboy662),
    },

    [TRAINER_BUG_CATCHER_663] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _(" 9TRAINER/5"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcher663),
    },

    [TRAINER_JUGGLER_664] = {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = 102,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _(" 8TRAINER/5"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Juggler664),
    },

    [TRAINER_JUGGLER_665] = {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _(" 8TRAINER/4"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Juggler665),
    },

    [TRAINER_JUGGLER_666] = {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = 98,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _(" 8TRAINER/3"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Juggler666),
    },

    [TRAINER_SCHOOLBOY_667] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("10TRAINER/2"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Schoolboy667),
    },

    [TRAINER_PICNICKER_668] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _(" 7TRAINER/5"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Picnicker668),
    },

    [TRAINER_SCHOOLBOY_669] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("12TRAINER/2"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Schoolboy669),
    },

    [TRAINER_SCHOOLBOY_670] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("12TRAINER/3"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Schoolboy670),
    },

    [TRAINER_SCHOOLBOY_671] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("12TRAINER/4"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Schoolboy671),
    },

    [TRAINER_CAMPER_672] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _(" 6TRAINER/5"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_Camper672),
    },

    [TRAINER_CAMPER_673] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _(" 6TRAINER/4"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_Camper673),
    },

    [TRAINER_CAMPER_674] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _(" 6TRAINER/3"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_Camper674),
    },

    [TRAINER_CAMPER_675] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _(" 6TRAINER/2"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Camper675),
    },

    [TRAINER_HIKER_676] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _(" 5TRAINER/5"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Hiker676),
    },

    [TRAINER_HIKER_677] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _(" 5TRAINER/4"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Hiker677),
    },

    [TRAINER_HIKER_678] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _(" 5TRAINER/3"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Hiker678),
    },

    [TRAINER_PICNICKER_679] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _(" 4TRAINER/5"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Picnicker679),
    },

    [TRAINER_BUG_CATCHER_680] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _(" 2TRAINER/2"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcher680),
    },

    [TRAINER_BUG_CATCHER_681] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _(" 2TRAINER/3"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcher681),
    },

    [TRAINER_PICNICKER_682] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 99,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _(" 4TRAINER/4"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Picnicker682),
    },

    [TRAINER_FISHERMAN_683] = {
        .trainerClass = TRAINER_CLASS_RS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("21TRAINER/2"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Fisherman683),
    },

    [TRAINER_PICNICKER_684] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("19TRAINER/2"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Picnicker684),
    },

    [TRAINER_PICNICKER_685] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("19TRAINER/3"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Picnicker685),
    },

    [TRAINER_PICNICKER_686] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _(" 4TRAINER/3"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Picnicker686),
    },

    [TRAINER_FISHERMAN_687] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _(" 3TRAINER/5"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_Fisherman687),
    },

    [TRAINER_BUG_CATCHER_688] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _(" 2TRAINER/5"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcher688),
    },

    [TRAINER_BUG_CATCHER_689] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _(" 2TRAINER/4"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcher689),
    },

    [TRAINER_BIRD_KEEPER_690] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("26TRAINER/2"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeper690),
    },

    [TRAINER_COOLTRAINER_691] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("25TRAINER/2"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_Cooltrainer691),
    },

    [TRAINER_COOLTRAINER_692] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("25TRAINER/3"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_Cooltrainer692),
    },

    [TRAINER_YOUNGSTER_693] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _(" 1TRAINER/5"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_Youngster693),
    },

    [TRAINER_CRUSH_GIRL_TANYA_2] = {
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .trainerName = _("TANYA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_CrushGirlTanya2),
    },

    [TRAINER_SCIENTIST_RYAN] = {
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = 107,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("RYAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_ScientistRyan),
    },

    [TRAINER_BLACK_BELT_SHEA_2] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("SHEA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BlackBeltShea2),
    },

    [TRAINER_BLACK_BELT_HUGH_2] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("HUGH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_BlackBeltHugh2),
    },

    [TRAINER_BLACK_BELT_HUGH_3] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("HUGH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_BlackBeltHugh3),
    },

    [TRAINER_CAMPER_JERRY] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("JERRY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_CamperJerry),
    },

    [TRAINER_LASS_KIA] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("KIA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassKia),
    },

    [TRAINER_TUBER_AMIRA] = {
        .trainerClass = TRAINER_CLASS_TUBER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .trainerName = _("AMIRA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TuberAmira),
    },

    [TRAINER_TWINS_JOY_AND_MEG_2] = {
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("JOY & MEG"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TwinsJoyAndMeg2),
    },

    [TRAINER_PAINTER_RAYNA_2] = {
        .trainerClass = TRAINER_CLASS_PAINTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_PAINTER,
        .trainerName = _("RAYNA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PainterRayna2),
    },

    [TRAINER_YOUNGSTER_DESTIN_2] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("DESTIN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungsterDestin2),
    },

    [TRAINER_RIVAL_SILVER_4] = {
        .trainerClass = TRAINER_CLASS_CHAMPION, // "RIVAL"
        .encounterMusic_gender = 64,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .trainerName = _("SILVER"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_RivalSilver4),
    },

    [TRAINER_RIVAL_SILVER_5] = {
        .trainerClass = TRAINER_CLASS_CHAMPION, // "RIVAL"
        .encounterMusic_gender = 64,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .trainerName = _("SILVER"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_RivalSilver5),
    },

    [TRAINER_RIVAL_SILVER_6] = {
        .trainerClass = TRAINER_CLASS_CHAMPION, // "RIVAL"
        .encounterMusic_gender = 64,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .trainerName = _("SILVER"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_RivalSilver6),
    },

    [TRAINER_BIRD_KEEPER_MILO_2] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("MILO"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperMilo2),
    },

    [TRAINER_PKMN_TRAINER_CAL] = {
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER,
        .encounterMusic_gender = 125,
        .trainerPic = TRAINER_PIC_RED,
        .trainerName = _("CAL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnTrainerCal),
    },

    [TRAINER_SWIMMER_F_NIKKI] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | 99,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("NIKKI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerFNikki),
    },

    [TRAINER_SWIMMER_F_NICOLE_2] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | 99,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("NICOLE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerFNicole2),
    },

    [TRAINER_SWIMMER_F_LORI] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | 99,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("LORI"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerFLori),
    },

    [TRAINER_SWIMMER_M_JEROME] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = 95,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("JEROME"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerMJerome),
    },

    [TRAINER_SWIMMER_M_TUCKER] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = 95,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("TUCKER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerMTucker),
    },

    [TRAINER_SWIMMER_M_HAROLD] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = 95,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("HAROLD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerMHarold),
    },

    [TRAINER_SWIMMER_M_CAMERON] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = 95,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("CAMERON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerMCameron),
    },

    [TRAINER_SWIMMER_M_SETH] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = 95,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("SETH"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerMSeth),
    },

    [TRAINER_PSYCHIC_RODETTE_2] = {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("RODETTE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PsychicRodette2),
    },

    [TRAINER_JUGGLER_MASON] = {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("MASON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_JugglerMason),
    },

    [TRAINER_FISHERMAN_ARNOLD] = {
        .trainerClass = TRAINER_CLASS_RS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("ARNOLD"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanArnold),
    },

    [TRAINER_PKMN_RANGER_MADELINE] = {
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("MADELINE"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PkmnRangerMadeline),
    },

    [TRAINER_CRUSH_GIRL_CYNDY_2] = {
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .trainerName = _("CYNDY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_CrushGirlCyndy2),
    },

    [TRAINER_SCHOOLBOY_DANNY] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("DANNY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SchoolboyDanny),
    },

    [TRAINER_PKMN_RANGER_JACKSON] = {
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .trainerName = _("JACKSON"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnRangerJackson),
    },

    [TRAINER_PKMN_RANGER_KATELYN] = {
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("KATELYN"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnRangerKatelyn),
    },

    [TRAINER_COOLTRAINER_LEROY] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("LEROY"),
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_CooltrainerLeroy),
    },

    [TRAINER_FIREBREATHER_BURT] = {
        .trainerClass = TRAINER_CLASS_KINDLER, // "FIREBREATHER"
        .encounterMusic_gender = F_TRAINER_FEMALE | 70,
        .trainerPic = TRAINER_PIC_RS_SIS_AND_BRO,
        .trainerName = _("BURT"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FirebreatherBurt),
    },

    [TRAINER_COOLTRAINER_QUINN] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("QUINN"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerQuinn),
    },

    [TRAINER_YOUNGSTER_WARREN] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("WARREN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungsterWarren),
    },

    [TRAINER_YOUNGSTER_JIMMY] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("JIMMY"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungsterJimmy),
    },

    [TRAINER_FIREBREATHER_OTIS] = {
        .trainerClass = TRAINER_CLASS_KINDLER, // "FIREBREATHER"
        .encounterMusic_gender = 70,
        .trainerPic = TRAINER_PIC_RS_SIS_AND_BRO,
        .trainerName = _("OTIS"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FirebreatherOtis),
    },

    [TRAINER_BIRD_KEEPER_HANK] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("HANK"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperHank),
    },

    [TRAINER_PICNICKER_HOPE] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("HOPE"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerHope),
    },

    [TRAINER_SWIMMER_F_DAWN] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = F_TRAINER_FEMALE | 99,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("DAWN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerFDawn),
    },

    [TRAINER_LEADER_BROCK_2] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = 116,
        .trainerPic = TRAINER_PIC_LEADER_BROCK,
        .trainerName = _("BROCK"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_LeaderBrock2),
    },

    [TRAINER_LEADER_BLAINE_2] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = 121,
        .trainerPic = TRAINER_PIC_LEADER_BLAINE,
        .trainerName = _("BLAINE"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_LeaderBlaine2),
    },

    [TRAINER_LEADER_BLUE_2] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = 124,
        .trainerPic = TRAINER_PIC_RIVAL_LATE,
        .trainerName = _("BLUE"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_LeaderBlue2),
    },

    [TRAINER_PKMN_TRAINER_RED] = {
        .trainerClass = TRAINER_CLASS_RS_ELITE_FOUR, // "PKMN TRAINER"
        .encounterMusic_gender = 71,
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_M,
        .trainerName = _("RED"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_PkmnTrainerRed),
    },

    [TRAINER_RIVAL_TERRY_15] = {
        .trainerClass = TRAINER_CLASS_CHAMPION, // "RIVAL"
        .encounterMusic_gender = 64,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .trainerName = _("TERRY"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_RivalTerry15),
    },

    [TRAINER_RIVAL_TERRY_16] = {
        .trainerClass = TRAINER_CLASS_CHAMPION, // "RIVAL"
        .encounterMusic_gender = 64,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .trainerName = _("TERRY"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_RivalTerry16),
    },

    [TRAINER_RIVAL_TERRY_17] = {
        .trainerClass = TRAINER_CLASS_CHAMPION, // "RIVAL"
        .encounterMusic_gender = 64,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .trainerName = _("TERRY"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_RivalTerry17),
    },

    [TRAINER_CUE_BALL_PAXTON] = {
        .trainerClass = TRAINER_CLASS_CUE_BALL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = _("PAXTON"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CueBallPaxton),
    },

};
