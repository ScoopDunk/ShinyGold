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
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt3),
    },

    [TRAINER_SUPER_NERD_PAT] = {
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = 89,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("PAT"),  // ShinyGold fix: was "PAT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SuperNerdPat),
    },

    [TRAINER_CAMPER_LLOYD] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("LLOYD"),  // ShinyGold fix: was "LLOYD!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CamperLloyd),
    },

    [TRAINER_SCHOOLBOY_DUDLEY] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("DUDLEY"),  // ShinyGold fix: was "DUDLEY!" (removed stray trailing characters)
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
        .trainerName = _("CINDY"),  // ShinyGold fix: was "CINDY!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerCindy),
    },

    [TRAINER_CAMPER_BARRY] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("BARRY"),  // ShinyGold fix: was "BARRY!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CamperBarry),
    },

    [TRAINER_COOLTRAINER_FIRIA] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("FIRIA"),  // ShinyGold fix: was "FIRIA!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerFiria),
    },

    [TRAINER_PSYCHIC_ZAHAAD] = {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = 100,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("ZAHAAD"),  // ShinyGold fix: was "ZAHAAD!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PsychicZahaad),
    },

    [TRAINER_BEAUTY_SERA] = {
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = 98,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("SERA"),  // ShinyGold fix: was "SERA!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BeautySera),
    },

    [TRAINER_YOUNGSTER_JOEY_2] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("JOEY"),  // ShinyGold fix: was " 1TRAINER/1" (G/S phone contact #1, rematch tier 1)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungsterJoey2),
    },

    [TRAINER_HIKER_PARRY] = {
        .trainerClass = TRAINER_CLASS_RS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("PARRY"),  // ShinyGold fix: was "24TRAINER/2" (G/S phone contact #24, rematch tier 2)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerParry),
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
        .trainerName = _("TIMMY"),  // ShinyGold fix: was "TIMMY!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungsterTimmy),
    },

    [TRAINER_YOUNGSTER_MIKEY] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("MIKEY"),  // ShinyGold fix: was "MIKEY!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungsterMikey),
    },

    [TRAINER_HIKER_PARRY_2] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("PARRY"),  // ShinyGold fix: was "24TRAINER/4" (G/S phone contact #24, rematch tier 4)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerParry2),
    },

    [TRAINER_BUG_CATCHER_ARNIE] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("ARNIE"),  // ShinyGold fix: was " 9TRAINER/1" (G/S phone contact #9, rematch tier 1)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcherArnie),
    },

    [TRAINER_BIRD_KEEPER_JOSE] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("JOSE"),  // ShinyGold fix: was "26TRAINER/3" (G/S phone contact #26, rematch tier 3)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperJose),
    },

    [TRAINER_BIRD_KEEPER_JOSE_2] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("JOSE"),  // ShinyGold fix: was "26TRAINER/4" (G/S phone contact #26, rematch tier 4)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperJose2),
    },

    [TRAINER_YOUNGSTER_ALBERT] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("ALBERT"),  // ShinyGold fix: was "ALBERT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungsterAlbert),
    },

    [TRAINER_BIRD_KEEPER_VANCE] = {
        .trainerClass = TRAINER_CLASS_RS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("VANCE"),  // ShinyGold fix: was "22TRAINER/1" (G/S phone contact #22, rematch tier 1)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperVance),
    },

    [TRAINER_OFFICER_DIRK] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_F, // "OFFICER"
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_M,
        .trainerName = _("DIRK"),  // ShinyGold fix: was "DIRK!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_OfficerDirk),
    },

    [TRAINER_YOUNGSTER_JOEY_3] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("JOEY"),  // ShinyGold fix: was " 1TRAINER/2" (G/S phone contact #1, rematch tier 2)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungsterJoey3),
    },

    [TRAINER_BUG_CATCHER_DON] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("DON"),  // ShinyGold fix: was "DON!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcherDon),
    },

    [TRAINER_SUPER_NERD_TOM] = {
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = 89,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("TOM"),  // ShinyGold fix: was "TOM!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SuperNerdTom),
    },

    [TRAINER_COOLTRAINER_GAVEN] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("GAVEN"),  // ShinyGold fix: was "27TRAINER/4" (G/S phone contact #27, rematch tier 4)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerGaven),
    },

    [TRAINER_BUG_CATCHER_BENNY] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("BENNY"),  // ShinyGold fix: was "BENNY!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcherBenny),
    },

    [TRAINER_YOUNGSTER_SAMUEL] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("SAMUEL"),  // ShinyGold fix: was "SAMUEL!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungsterSamuel),
    },

    [TRAINER_BUG_CATCHER_AL] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("AL"),  // ShinyGold fix: was "AL!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcherAl),
    },

    [TRAINER_YOUNGSTER_IAN] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("IAN"),  // ShinyGold fix: was "IAN!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungsterIan),
    },

    [TRAINER_HIKER_BENJAMIN] = {
        .trainerClass = TRAINER_CLASS_RS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("BENJAMIN"),  // ShinyGold fix: was "BENJAMIN!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerBenjamin),
    },

    [TRAINER_SUPER_NERD_TERU] = {
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = 89,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("TERU"),  // ShinyGold fix: was "TERU!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SuperNerdTeru),
    },

    [TRAINER_COOLTRAINER_NICK] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("NICK"),  // ShinyGold fix: was "NICK!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerNick),
    },

    [TRAINER_COOLTRAINER_GAVEN_2] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("GAVEN"),  // ShinyGold fix: was "27TRAINER/5" (G/S phone contact #27, rematch tier 5)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerGaven2),
    },

    [TRAINER_LASS_LAURA] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("LAURA"),  // ShinyGold fix: was "LAURA!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassLaura),
    },

    [TRAINER_YOUNGSTER_JASON] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("JASON"),  // ShinyGold fix: was "JASON!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungsterJason),
    },

    [TRAINER_COOLTRAINER_PAUL] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("PAUL"),  // ShinyGold fix: was "PAUL!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerPaul),
    },

    [TRAINER_PICNICKER_ERIN] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("ERIN"),  // ShinyGold fix: was "16TRAINER/1" (G/S phone contact #16, rematch tier 1)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerErin),
    },

    [TRAINER_LASS_KRISE] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("KRISE"),  // ShinyGold fix: was "KRISE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassKrise),
    },

    [TRAINER_LASS_RAINA] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("RAINA"),  // ShinyGold fix: was "RAINA!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassRaina),
    },

    [TRAINER_LASS_BRIDGET] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("BRIDGET"),  // ShinyGold fix: was "BRIDGET!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassBridget),
    },

    [TRAINER_LASS_SANAE] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("SANAE"),  // ShinyGold fix: was "SANAE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassSanae),
    },

    [TRAINER_COOLTRAINER_REENA] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("REENA"),  // ShinyGold fix: was "28TRAINER/3" (G/S phone contact #28, rematch tier 3)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerReena),
    },

    [TRAINER_LASS_DANA] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("DANA"),  // ShinyGold fix: was "13TRAINER/1" (G/S phone contact #13, rematch tier 1)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassDana),
    },

    [TRAINER_COOLTRAINER_MEGAN] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("MEGAN"),  // ShinyGold fix: was "MEGAN!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerMegan),
    },

    [TRAINER_HIKER_LEONARD] = {
        .trainerClass = TRAINER_CLASS_RS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("LEONARD"),  // ShinyGold fix: was "LEONARD!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerLeonard),
    },

    [TRAINER_COOLTRAINER_KELLY] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("KELLY"),  // ShinyGold fix: was "KELLY!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerKelly),
    },

    [TRAINER_CAMPER_ELLIOT] = {
        .trainerClass = TRAINER_CLASS_RS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("ELLIOT"),  // ShinyGold fix: was "ELLIOT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CamperElliot),
    },

    [TRAINER_POKEMANIAC_ANDREW] = {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("ANDREW"),  // ShinyGold fix: was "ANDREW!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokemaniacAndrew),
    },

    [TRAINER_COOLTRAINER_LOIS] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("LOIS"),  // ShinyGold fix: was "LOIS!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerLois),
    },

    [TRAINER_SAILOR_EUGENE] = {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = 85,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("EUGENE"),  // ShinyGold fix: was "EUGENE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SailorEugene),
    },

    [TRAINER_LASS_MEGAN] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("MEGAN"),  // ShinyGold fix: was "MEGAN      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassMegan),
    },

    [TRAINER_COOLTRAINER_CYBIL] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("CYBIL"),  // ShinyGold fix: was "CYBIL!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerCybil),
    },

    [TRAINER_COOLTRAINER_JOYCE] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("JOYCE"),  // ShinyGold fix: was "JOYCE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerJoyce),
    },

    [TRAINER_FIREBREATHER_WALT] = {
        .trainerClass = TRAINER_CLASS_KINDLER, // "FIREBREATHER"
        .encounterMusic_gender = 70,
        .trainerPic = TRAINER_PIC_RS_SIS_AND_BRO,
        .trainerName = _("WALT"),  // ShinyGold fix: was "WALT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FirebreatherWalt),
    },

    [TRAINER_COOLTRAINER_CODY] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("CODY"),  // ShinyGold fix: was "CODY!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerCody),
    },

    [TRAINER_COOLTRAINER_JAKE] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("JAKE"),  // ShinyGold fix: was "JAKE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerJake),
    },

    [TRAINER_COOLTRAINER_REENA_2] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("REENA"),  // ShinyGold fix: was "28TRAINER/4" (G/S phone contact #28, rematch tier 4)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerReena2),
    },

    [TRAINER_SAGE_LI] = {
        .trainerClass = TRAINER_CLASS_HEX_MANIAC, // "SAGE"
        .encounterMusic_gender = 72,
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_F,
        .trainerName = _("LI"),  // ShinyGold fix: was "LI!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SageLi),
    },

    [TRAINER_SAILOR_KENT] = {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = 85,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("KENT"),  // ShinyGold fix: was "KENT!" (removed stray trailing characters)
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

    [TRAINER_COOLTRAINER_REENA_3] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = 85,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("REENA"),  // ShinyGold fix: was "28TRAINER/5" (G/S phone contact #28, rematch tier 5)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerReena3),
    },

    [TRAINER_SAILOR_JEFF] = {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = 85,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("JEFF"),  // ShinyGold fix: was "JEFF!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SailorJeff),
    },

    [TRAINER_CAMPER_ELLIOT_2] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("ELLIOT"),  // ShinyGold fix: was "-EDIT-" (exact G/S party match (Camper))
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_CamperElliot2),
    },

    [TRAINER_MEDIUM_REBECCA] = {
        .trainerClass = TRAINER_CLASS_CHANNELER, // "MEDIUM"
        .encounterMusic_gender = 126,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("REBECCA"),  // ShinyGold fix: was "REBECCA!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_MediumRebecca),
    },

    [TRAINER_CAMPER_ETHAN] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("ETHAN"),  // ShinyGold fix: was "ETHAN      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CamperEthan),
    },

    [TRAINER_POKEFAN_BEVERLY] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 33,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("BEVERLY"),  // ShinyGold fix: was "11TRAINER/1" (G/S phone contact #11, rematch tier 1)
        .items = {ITEM_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokefanBeverly),
    },

    [TRAINER_FISHERMAN_RALPH] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("RALPH"),  // ShinyGold fix: was " 3TRAINER/1" (G/S phone contact #3, rematch tier 1)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanRalph),
    },

    [TRAINER_POKEMANIAC_MARCO] = {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("MARCO"),  // ShinyGold fix: was "MARCO!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokemaniacMarco),
    },

    [TRAINER_CAMPER_TODD] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("TODD"),  // ShinyGold fix: was " 6TRAINER/1" (G/S phone contact #6, rematch tier 1)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CamperTodd),
    },

    [TRAINER_COOLTRAINER_GWEN] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("GWEN"),  // ShinyGold fix: was "GWEN!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerGwen),
    },

    [TRAINER_PICNICKER_DIANA] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("DIANA"),  // ShinyGold fix: was "DIANA      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerDiana),
    },

    [TRAINER_MEDIUM_DORIS] = {
        .trainerClass = TRAINER_CLASS_CHANNELER, // "MEDIUM"
        .encounterMusic_gender = 126,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("DORIS"),  // ShinyGold fix: was "DORIS!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_MediumDoris),
    },

    [TRAINER_PICNICKER_GINA] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("GINA"),  // ShinyGold fix: was " 7TRAINER/1" (G/S phone contact #7, rematch tier 1)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerGina),
    },

    [TRAINER_PICNICKER_LIZ] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("LIZ"),  // ShinyGold fix: was " 4TRAINER/1" (G/S phone contact #4, rematch tier 1)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerLiz),
    },

    [TRAINER_POKEFAN_DEREK] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 32,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("DEREK"),  // ShinyGold fix: was "15TRAINER/1" (G/S phone contact #15, rematch tier 1)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokefanDerek),
    },

    [TRAINER_PICNICKER_CAITLIN] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("CAITLIN"),  // ShinyGold fix: was "CAITLIN    " (removed stray trailing characters)
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
        .trainerName = _("EDNA"),  // ShinyGold fix: was "EDNA!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerEdna),
    },

    [TRAINER_CAMPER_IVAN] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("IVAN"),  // ShinyGold fix: was "IVAN!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CamperIvan),
    },

    [TRAINER_LASS_ELLEN] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("ELLEN"),  // ShinyGold fix: was "ELLEN!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassEllen),
    },

    [TRAINER_SCHOOLBOY_JOE] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JOE"),  // ShinyGold fix: was "JOE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SchoolboyJoe),
    },

    [TRAINER_SAGE_PING_2] = {
        .trainerClass = TRAINER_CLASS_HEX_MANIAC, // "SAGE"
        .encounterMusic_gender = 72,
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_F,
        .trainerName = _("PING"),  // ShinyGold fix: was "PING!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SagePing2),
    },

    [TRAINER_POKEMANIAC_DONALD] = {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("DONALD"),  // ShinyGold fix: was "DONALD!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokemaniacDonald),
    },

    [TRAINER_HIKER_ANTHONY] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("ANTHONY"),  // ShinyGold fix: was " 5TRAINER/1" (G/S phone contact #5, rematch tier 1)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerAnthony),
    },

    [TRAINER_SAILOR_ERNEST] = {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = 85,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("ERNEST"),  // ShinyGold fix: was "ERNEST!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SailorErnest),
    },

    [TRAINER_GENTLEMAN_PRESTON] = {
        .trainerClass = TRAINER_CLASS_RS_GENTLEMAN,
        .encounterMusic_gender = 123,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("PRESTON"),  // ShinyGold fix: was "PRESTON!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_GentlemanPreston),
    },

    [TRAINER_POKEMANIAC_WINSTON] = {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("WINSTON"),  // ShinyGold fix: was "WINSTON    " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokemaniacWinston),
    },

    [TRAINER_CAMPER_SPENCER] = {
        .trainerClass = TRAINER_CLASS_RS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("SPENCER"),  // ShinyGold fix: was "SPENCER!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CamperSpencer),
    },

    [TRAINER_POKEMANIAC_SHANE] = {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("SHANE"),  // ShinyGold fix: was "SHANE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokemaniacShane),
    },

    [TRAINER_SUPER_NERD_ERIC] = {
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = 89,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("ERIC"),  // ShinyGold fix: was "ERIC!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SuperNerdEric),
    },

    [TRAINER_BOARDER_RONALD] = {
        .trainerClass = TRAINER_CLASS_BOARDER,
        .encounterMusic_gender = 38,
        .trainerPic = TRAINER_PIC_RS_FISHERMAN,
        .trainerName = _("RONALD"),  // ShinyGold fix: was "RONALD!" (removed stray trailing characters)
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

    [TRAINER_HIKER_PARRY_3] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("PARRY"),  // ShinyGold fix: was "24TRAINER/1" (G/S phone contact #24, rematch tier 1)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerParry3),
    },

    [TRAINER_SUPER_NERD_LESLIE] = {
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = 89,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("LESLIE"),  // ShinyGold fix: was "LESLIE     " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_SuperNerdLeslie),
    },

    [TRAINER_BOARDER_DOUGLAS] = {
        .trainerClass = TRAINER_CLASS_BOARDER,
        .encounterMusic_gender = 38,
        .trainerPic = TRAINER_PIC_RS_FISHERMAN,
        .trainerName = _("DOUGLAS"),  // ShinyGold fix: was "DOUGLAS!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BoarderDouglas),
    },

    [TRAINER_SAILOR_KENNETH] = {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = 85,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("KENNETH"),  // ShinyGold fix: was "KENNETH!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SailorKenneth),
    },

    [TRAINER_BOARDER_BRAD] = {
        .trainerClass = TRAINER_CLASS_BOARDER,
        .encounterMusic_gender = 38,
        .trainerPic = TRAINER_PIC_RS_FISHERMAN,
        .trainerName = _("BRAD"),  // ShinyGold fix: was "BRAD!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BoarderBrad),
    },

    [TRAINER_COOLTRAINER_AARON] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("AARON"),  // ShinyGold fix: was "AARON!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerAaron),
    },

    [TRAINER_FISHERMAN_MARVIN] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("MARVIN"),  // ShinyGold fix: was "MARVIN!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanMarvin),
    },

    [TRAINER_SUPER_NERD_DEREK] = {
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = 89,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("DEREK"),  // ShinyGold fix: was "DEREK      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SuperNerdDerek),
    },

    [TRAINER_COOLTRAINER_RYAN] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("RYAN"),  // ShinyGold fix: was "RYAN!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerRyan),
    },

    [TRAINER_HIKER_RUSELL] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("RUSELL"),  // ShinyGold fix: was "RUSELL!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerRusell),
    },

    [TRAINER_HIKER_NOLAND] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("NOLAND"),  // ShinyGold fix: was "NOLAND!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerNoland),
    },

    [TRAINER_HIKER_NOB] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("NOB"),  // ShinyGold fix: was "NOB        " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerNob),
    },

    [TRAINER_HIKER_WAYNE] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("WAYNE"),  // ShinyGold fix: was "WAYNE      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerWayne),
    },

    [TRAINER_LEADER_LEONARD] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("LEONARD"),  // ShinyGold fix: was "-EDIT-" (exact G/S party match (Hiker))
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_LeaderLeonard),
    },

    [TRAINER_HIKER_PHILLIP] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("PHILLIP"),  // ShinyGold fix: was "PHILLIP!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerPhillip),
    },

    [TRAINER_PKMN_TRAINER_CLARK] = {
        .trainerClass = TRAINER_CLASS_NONE,
        .encounterMusic_gender = 70,
        .trainerPic = TRAINER_PIC_RS_SIS_AND_BRO,
        .trainerName = _("CLARK"),  // ShinyGold fix: was "-EDIT-" (vanilla FireRed name of this trainer slot)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnTrainerClark),
    },

    [TRAINER_POKEMANIAC_BRENT] = {
        .trainerClass = TRAINER_CLASS_RS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("BRENT"),  // ShinyGold fix: was "20TRAINER/1" (G/S phone contact #20, rematch tier 1)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokemaniacBrent),
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
        .trainerName = _("TIMOTHY"),  // ShinyGold fix: was "TIMOTHY!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerTimothy),
    },

    [TRAINER_HIKER_YUZO] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("YUZO"),  // ShinyGold fix: was "YUZO!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerYuzo),
    },

    [TRAINER_HIKER_MICHAEL] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("MICHAEL"),  // ShinyGold fix: was "MICHAEL!" (removed stray trailing characters)
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
        .trainerName = _("HIDEO"),  // ShinyGold fix: was "HIDEO      " (removed stray trailing characters)
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
        .trainerName = _("BILLY"),  // ShinyGold fix: was "BILLY      " (removed stray trailing characters)
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
        .trainerName = _("BILL"),  // ShinyGold fix: was "BILL!" (removed stray trailing characters)
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
        .trainerName = _("BLAKE"),  // ShinyGold fix: was "BLAKE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerBlake),
    },

    [TRAINER_FIREBREATHER_NED] = {
        .trainerClass = TRAINER_CLASS_KINDLER, // "FIREBREATHER"
        .encounterMusic_gender = 70,
        .trainerPic = TRAINER_PIC_RS_SIS_AND_BRO,
        .trainerName = _("NED"),  // ShinyGold fix: was "NED!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FirebreatherNed),
    },

    [TRAINER_BURGLAR_RAMON] = {
        .trainerClass = TRAINER_CLASS_BURGLAR,
        .encounterMusic_gender = 92,
        .trainerPic = TRAINER_PIC_BURGLAR,
        .trainerName = _("RAMON"),  // ShinyGold fix: was "RAMON      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BurglarRamon),
    },

    [TRAINER_BURGLAR_EDDIE] = {
        .trainerClass = TRAINER_CLASS_BURGLAR,
        .encounterMusic_gender = 92,
        .trainerPic = TRAINER_PIC_BURGLAR,
        .trainerName = _("EDDIE"),  // ShinyGold fix: was "EDDIE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BurglarEddie),
    },

    [TRAINER_SCHOOLBOY_NATE] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("NATE"),  // ShinyGold fix: was "NATE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SchoolboyNate),
    },

    [TRAINER_BIKER_ZEKE] = {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = 91,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("ZEKE"),  // ShinyGold fix: was "ZEKE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BikerZeke),
    },

    [TRAINER_BURGLAR_SIMON] = {
        .trainerClass = TRAINER_CLASS_BURGLAR,
        .encounterMusic_gender = 92,
        .trainerPic = TRAINER_PIC_BURGLAR,
        .trainerName = _("SIMON"),  // ShinyGold fix: was "SIMON      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BurglarSimon),
    },

    [TRAINER_SCHOOLBOY_RICKY] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("RICKY"),  // ShinyGold fix: was "RICKY!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SchoolboyRicky),
    },

    [TRAINER_SUPER_NERD_SAM] = {
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = 89,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("SAM"),  // ShinyGold fix: was "SAM!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SuperNerdSam),
    },

    [TRAINER_ENGINEER_BRAXTON] = {
        .trainerClass = TRAINER_CLASS_ENGINEER,
        .encounterMusic_gender = 93,
        .trainerPic = TRAINER_PIC_ENGINEER,
        .trainerName = _("BRAXTON"),  // ShinyGold fix: was "BRAXTON    " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_EngineerBraxton),
    },

    [TRAINER_COOLTRAINER_REENA_4] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("REENA"),  // ShinyGold fix: was "28TRAINER/1" (G/S phone contact #28, rematch tier 1)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerReena4),
    },

    [TRAINER_BURGLAR_DUNCAN] = {
        .trainerClass = TRAINER_CLASS_BURGLAR,
        .encounterMusic_gender = 92,
        .trainerPic = TRAINER_PIC_BURGLAR,
        .trainerName = _("DUNCAN"),  // ShinyGold fix: was "DUNCAN!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BurglarDuncan),
    },

    [TRAINER_FISHERMAN_SCOTT] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("SCOTT"),  // ShinyGold fix: was "SCOTT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanScott),
    },

    [TRAINER_FIREBREATHER_LYLE] = {
        .trainerClass = TRAINER_CLASS_KINDLER, // "FIREBREATHER"
        .encounterMusic_gender = 70,
        .trainerPic = TRAINER_PIC_RS_SIS_AND_BRO,
        .trainerName = _("LYLE"),  // ShinyGold fix: was "LYLE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FirebreatherLyle),
    },

    [TRAINER_FISHERMAN_HENRY] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("HENRY"),  // ShinyGold fix: was "HENRY!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanHenry),
    },

    [TRAINER_FISHERMAN_HANK] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("HANK"),  // ShinyGold fix: was "HANK       " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanHank),
    },

    [TRAINER_JUGGLER_IRWIN] = {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = 102,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("IRWIN"),  // ShinyGold fix: was " 8TRAINER/1" (G/S phone contact #8, rematch tier 1)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_JugglerIrwin),
    },

    [TRAINER_FISHERMAN_JUSTIN] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("JUSTIN"),  // ShinyGold fix: was "JUSTIN!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanJustin),
    },

    [TRAINER_FISHERMAN_EDGAR] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("EDGAR"),  // ShinyGold fix: was "EDGAR!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanEdgar),
    },

    [TRAINER_POKEFAN_JOSHUA] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 32,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("JOSHUA"),  // ShinyGold fix: was "JOSHUA!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokefanJoshua),
    },

    [TRAINER_COOLTRAINER_IRENE] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("IRENE"),  // ShinyGold fix: was "IRENE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerIrene),
    },

    [TRAINER_COOLTRAINER_JENN] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("JENN"),  // ShinyGold fix: was "JENN!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerJenn),
    },

    [TRAINER_COOLTRAINER_KATE] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("KATE"),  // ShinyGold fix: was "KATE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerKate),
    },

    [TRAINER_SWIMMER_M_SIMON] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = 95,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("SIMON"),  // ShinyGold fix: was "SIMON!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerMSimon),
    },

    [TRAINER_SWIMMER_M_RANDALL] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SWIMMER,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("RANDALL"),  // ShinyGold fix: was "RANDALL!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerMRandall),
    },

    [TRAINER_SWIMMER_M_KIRK] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = 95,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("KIRK"),  // ShinyGold fix: was "KIRK!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerMKirk),
    },

    [TRAINER_FISHERMAN_RAYMOND] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("RAYMOND"),  // ShinyGold fix: was "RAYMOND!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanRaymond),
    },

    [TRAINER_SWIMMER_M_CHARLIE] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = 95,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("CHARLIE"),  // ShinyGold fix: was "CHARLIE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerMCharlie),
    },

    [TRAINER_POKEMANIAC_ETHAN] = {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("ETHAN"),  // ShinyGold fix: was "ETHAN!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokemaniacEthan),
    },

    [TRAINER_HIKER_BAILEY] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("BAILEY"),  // ShinyGold fix: was "BAILEY!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerBailey),
    },

    [TRAINER_BIKER_JOEL] = {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = 91,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("JOEL"),  // ShinyGold fix: was "JOEL!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BikerJoel),
    },

    [TRAINER_SWIMMER_M_DEAN] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = 95,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("DEAN"),  // ShinyGold fix: was "DEAN       " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerMDean),
    },

    [TRAINER_FISHERMAN_WILTON] = {
        .trainerClass = TRAINER_CLASS_RS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("WILTON"),  // ShinyGold fix: was "21TRAINER/1" (G/S phone contact #21, rematch tier 1)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanWilton),
    },

    [TRAINER_FISHERMAN_MARTIN] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 95,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("MARTIN"),  // ShinyGold fix: was "MARTIN!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanMartin),
    },

    [TRAINER_SWIMMER_M_JACK] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = 95,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("JACK"),  // ShinyGold fix: was "JACK       " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerMJack),
    },

    [TRAINER_CAMPER_DEAN] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("DEAN"),  // ShinyGold fix: was "DEAN!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CamperDean),
    },

    [TRAINER_SAILOR_STANLY] = {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = 85,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("STANLY"),  // ShinyGold fix: was "STANLY!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SailorStanly),
    },

    [TRAINER_POKEFAN_JEREMY] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 32,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("JEREMY"),  // ShinyGold fix: was "JEREMY!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokefanJeremy),
    },

    [TRAINER_HIKER_SIDNEY] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("SIDNEY"),  // ShinyGold fix: was "SIDNEY!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerSidney),
    },

    [TRAINER_PICNICKER_HEIDI] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("HEIDI"),  // ShinyGold fix: was "HEIDI!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerHeidi),
    },

    [TRAINER_BUG_CATCHER_ROB] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("ROB"),  // ShinyGold fix: was "ROB!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcherRob),
    },

    [TRAINER_BIRD_KEEPER_ROY] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("ROY"),  // ShinyGold fix: was "ROY!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperRoy),
    },

    [TRAINER_CUE_BALL_ZEEK] = {
        .trainerClass = TRAINER_CLASS_CUE_BALL,
        .encounterMusic_gender = 96,
        .trainerPic = TRAINER_PIC_CUE_BALL,
        .trainerName = _("ZEEK"),  // ShinyGold fix: was "ZEEK       " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CueBallZeek),
    },

    [TRAINER_BURGLAR_CORY] = {
        .trainerClass = TRAINER_CLASS_BURGLAR,
        .encounterMusic_gender = 92,
        .trainerPic = TRAINER_PIC_BURGLAR,
        .trainerName = _("CORY"),  // ShinyGold fix: was "CORY!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BurglarCory),
    },

    [TRAINER_TEACHER_HILLARY] = {
        .trainerClass = TRAINER_CLASS_RS_RUIN_MANIAC, // "TEACHER"
        .encounterMusic_gender = 96,
        .trainerPic = TRAINER_PIC_OLD_COUPLE,
        .trainerName = _("HILLARY"),  // ShinyGold fix: was "HILLARY!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeacherHillary),
    },

    [TRAINER_SUPER_NERD_SHAWN] = {
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = 89,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("SHAWN"),  // ShinyGold fix: was "SHAWN!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SuperNerdShawn),
    },

    [TRAINER_SWIMMER_F_SUSIE] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = 99,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("SUSIE"),  // ShinyGold fix: was "SUSIE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerFSusie),
    },

    [TRAINER_SWIMMER_F_WENDY] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = 97,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("WENDY"),  // ShinyGold fix: was "WENDY!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerFWendy),
    },

    [TRAINER_SWIMMER_F_KARA] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = 99,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("KARA"),  // ShinyGold fix: was "KARA!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerFKara),
    },

    [TRAINER_SAILOR_HUEY_2] = {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = 85,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("HUEY"),  // ShinyGold fix: was "17TRAINER/1" (G/S phone contact #17, rematch tier 1)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SailorHuey2),
    },

    [TRAINER_JUGGLER_FRITZ] = {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = 102,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("FRITZ"),  // ShinyGold fix: was "FRITZ!" (removed stray trailing characters)
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
        .trainerName = _("CASSIE"),  // ShinyGold fix: was "CASSIE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BeautyCassie),
    },

    [TRAINER_SWIMMER_M_PARKER] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = 95,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("PARKER"),  // ShinyGold fix: was "PARKER!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerMParker),
    },

    [TRAINER_BEAUTY_SAMANTHA] = {
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = 98,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("SAMANTHA"),  // ShinyGold fix: was "SAMANTHA!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BeautySamantha),
    },

    [TRAINER_BEAUTY_LORI] = {
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = 98,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("LORI"),  // ShinyGold fix: was "LORI       " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BeautyLori),
    },

    [TRAINER_BEAUTY_VICTORIA] = {
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = 98,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("VICTORIA"),  // ShinyGold fix: was "VICTORIA!" (removed stray trailing characters)
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
        .trainerName = _("DIANA"),  // ShinyGold fix: was "DIANA!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerFDiana),
    },

    [TRAINER_SWIMMER_F_KAYLEE] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = 99,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("KAYLEE"),  // ShinyGold fix: was "KAYLEE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerFKaylee),
    },

    [TRAINER_SWIMMER_F_PAULA] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = 99,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("PAULA"),  // ShinyGold fix: was "PAULA!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerFPaula),
    },

    [TRAINER_COOLTRAINER_LOLA] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("LOLA"),  // ShinyGold fix: was "LOLA!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerLola),
    },

    [TRAINER_BEAUTY_VALERIE] = {
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = 98,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("VALERIE"),  // ShinyGold fix: was "VALERIE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BeautyValerie),
    },

    [TRAINER_COOLTRAINER_CAROL] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("CAROL"),  // ShinyGold fix: was "CAROL!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerCarol),
    },

    [TRAINER_BIRD_KEEPER_THEO] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("THEO"),  // ShinyGold fix: was "THEO!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperTheo),
    },

    [TRAINER_PSYCHIC_RODNEY] = {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = 100,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("RODNEY"),  // ShinyGold fix: was "RODNEY!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PsychicRodney),
    },

    [TRAINER_COOLTRAINER_SEAN] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("SEAN"),  // ShinyGold fix: was "SEAN!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerSean),
    },

    [TRAINER_LASS_SHANNON] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("SHANNON"),  // ShinyGold fix: was "SHANNON!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassShannon),
    },

    [TRAINER_FISHERMAN_JONAH] = {
        .trainerClass = TRAINER_CLASS_RS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("JONAH"),  // ShinyGold fix: was "JONAH!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanJonah),
    },

    [TRAINER_PSYCHIC_NORMAN] = {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = 100,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("NORMAN"),  // ShinyGold fix: was "NORMAN!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PsychicNorman),
    },

    [TRAINER_PSYCHIC_MARK] = {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("MARK"),  // ShinyGold fix: was "MARK!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PsychicMark),
    },

    [TRAINER_PSYCHIC_PRESTON] = {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = 100,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("PRESTON"),  // ShinyGold fix: was "PRESTON    " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PsychicPreston),
    },

    [TRAINER_PSYCHIC_GILBERT] = {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = 100,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("GILBERT"),  // ShinyGold fix: was "GILBERT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PsychicGilbert),
    },

    [TRAINER_SCHOOLBOY_CHAD] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("CHAD"),  // ShinyGold fix: was "14TRAINER/1" (G/S phone contact #14, rematch tier 1)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SchoolboyChad),
    },

    [TRAINER_SWIMMER_F_BRIANA] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = 99,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("BRIANA"),  // ShinyGold fix: was "BRIANA!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerFBriana),
    },

    [TRAINER_JUGGLER_HORTON] = {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = 102,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("HORTON"),  // ShinyGold fix: was "HORTON!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_JugglerHorton),
    },

    [TRAINER_GUITARIST_VINCENT] = {
        .trainerClass = TRAINER_CLASS_GUITARIST,
        .encounterMusic_gender = 17,
        .trainerPic = TRAINER_PIC_GUITARIST,
        .trainerName = _("VINCENT"),  // ShinyGold fix: was "VINCENT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_GuitaristVincent),
    },

    [TRAINER_PSYCHIC_PHIL] = {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = 100,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("PHIL"),  // ShinyGold fix: was "PHIL!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PsychicPhil),
    },

    [TRAINER_JUGGLER_GREGORY] = {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = 102,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("GREGORY"),  // ShinyGold fix: was "GREGORY    " (removed stray trailing characters)
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
        .trainerName = _("KAYDEN"),  // ShinyGold fix: was "KAYDEN     " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_JugglerKayden),
    },

    [TRAINER_SCHOOLBOY_TOMMY] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("TOMMY"),  // ShinyGold fix: was "TOMMY!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SchoolboyTommy),
    },

    [TRAINER_MEDIUM_ERIS] = {
        .trainerClass = TRAINER_CLASS_CHANNELER, // "MEDIUM"
        .encounterMusic_gender = 126,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("ERIS"),  // ShinyGold fix: was "ERIS!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_MediumEris),
    },

    [TRAINER_PSYCHIC_JARED] = {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = 100,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("JARED"),  // ShinyGold fix: was "JARED!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PsychicJared),
    },

    [TRAINER_TAMER_JASON] = {
        .trainerClass = TRAINER_CLASS_TAMER,
        .encounterMusic_gender = 103,
        .trainerPic = TRAINER_PIC_TAMER,
        .trainerName = _("JASON"),  // ShinyGold fix: was "JASON      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TamerJason),
    },

    [TRAINER_YOUNGSTER_FABRICIO] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("FABRICIO"),  // ShinyGold fix: was "FABRICIO!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungsterFabricio),
    },

    [TRAINER_MEDIUM_SARINA] = {
        .trainerClass = TRAINER_CLASS_CHANNELER, // "MEDIUM"
        .encounterMusic_gender = 126,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("SARINA"),  // ShinyGold fix: was "SARINA!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_MediumSarina),
    },

    [TRAINER_POKEFAN_GEORGIA] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 33,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("GEORGIA"),  // ShinyGold fix: was "GEORGIA!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokefanGeorgia),
    },

    [TRAINER_BIRD_KEEPER_ROD] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("ROD"),  // ShinyGold fix: was "ROD!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperRod),
    },

    [TRAINER_SWIMMER_M_GEORGE] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = 95,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("GEORGE"),  // ShinyGold fix: was "GEORGE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerMGeorge),
    },

    [TRAINER_COOLTRAINER_GAVEN_3] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("GAVEN"),  // ShinyGold fix: was "27TRAINER/1" (G/S phone contact #27, rematch tier 1)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerGaven3),
    },

    [TRAINER_BIRD_KEEPER_DONALD] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("DONALD"),  // ShinyGold fix: was "DONALD     " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperDonald),
    },

    [TRAINER_BIRD_KEEPER_BRYAN] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("BRYAN"),  // ShinyGold fix: was "BRYAN!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperBryan),
    },

    [TRAINER_BIKER_DWAYNE] = {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = 91,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("DWAYNE"),  // ShinyGold fix: was "DWAYNE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BikerDwayne),
    },

    [TRAINER_SCHOOLBOY_ALAN] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("ALAN"),  // ShinyGold fix: was "10TRAINER/1" (G/S phone contact #10, rematch tier 1)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SchoolboyAlan),
    },

    [TRAINER_CAMPER_RAOUL] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("RAOUL"),  // ShinyGold fix: was "RAOUL!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CamperRaoul),
    },

    [TRAINER_BIRD_KEEPER_RAMIRO] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("RAMIRO"),  // ShinyGold fix: was "RAMIRO     " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperRamiro),
    },

    [TRAINER_BUG_CATCHER_WADE] = {
        .trainerClass = TRAINER_CLASS_RS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("WADE"),  // ShinyGold fix: was " 2TRAINER/1" (G/S phone contact #2, rematch tier 1)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcherWade),
    },

    [TRAINER_BIRD_KEEPER_PETER] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("PETER"),  // ShinyGold fix: was "PETER!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperPeter),
    },

    [TRAINER_FISHERMAN_STEPHEN] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("STEPHEN"),  // ShinyGold fix: was "STEPHEN!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanStephen),
    },

    [TRAINER_BUG_CATCHER_KEN] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("KEN"),  // ShinyGold fix: was "KEN!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcherKen),
    },

    [TRAINER_BIRD_KEEPER_TOBY] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("TOBY"),  // ShinyGold fix: was "TOBY!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperToby),
    },

    [TRAINER_HIKER_KENNY] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("KENNY"),  // ShinyGold fix: was "KENNY!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerKenny),
    },

    [TRAINER_BIKER_ROWDY] = {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = 91,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("ROWDY"),  // ShinyGold fix: was "ROWDY!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BikerRowdy),
    },

    [TRAINER_BLACK_BELT_KENJI] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("KENJI"),  // ShinyGold fix: was "23TRAINER/1" (G/S phone contact #23, rematch tier 1)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BlackBeltKenji),
    },

    [TRAINER_BLACK_BELT_KIYO] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("KIYO"),  // ShinyGold fix: was "KIYO!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_BlackBeltKiyo),
    },

    [TRAINER_BIRD_KEEPER_DENIS] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("DENIS"),  // ShinyGold fix: was "DENIS!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_BirdKeeperDenis),
    },

    [TRAINER_BLACK_BELT_NOB] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("NOB"),  // ShinyGold fix: was "NOB!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_BlackBeltNob),
    },

    [TRAINER_BLACK_BELT_AARON] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("AARON"),  // ShinyGold fix: was "AARON      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_BlackBeltAaron),
    },

    [TRAINER_BLACK_BELT_LUNG] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("LUNG"),  // ShinyGold fix: was "LUNG!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_BlackBeltLung),
    },

    [TRAINER_DRAGON_TAMER_MIKAHIL] = {
        .trainerClass = TRAINER_CLASS_DRAGON_TAMER,
        .encounterMusic_gender = 45,
        .trainerPic = TRAINER_PIC_DRAGON_TAMER,
        .trainerName = _("MIKAHIL"),  // ShinyGold fix: was "MIKAHIL!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_DragonTamerMikahil),
    },

    [TRAINER_BLACK_BELT_KIYO_2] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("KIYO"),  // ShinyGold fix: was "KIYO       " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_BlackBeltKiyo2),
    },

    [TRAINER_BLACK_BELT_WAI] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("WAI"),  // ShinyGold fix: was "WAI!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_BlackBeltWai),
    },

    [TRAINER_HIKER_ERIK] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("ERIK"),  // ShinyGold fix: was "ERIK!" (removed stray trailing characters)
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

    [TRAINER_RIVAL_SILVER_7] = {
        .trainerClass = TRAINER_CLASS_RIVAL_EARLY,
        .encounterMusic_gender = 54,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("SILVER"),  // ShinyGold fix: was "-EDIT-" (rival class (name is replaced by the rival name in battle))
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_RivalSilver7),
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
        .trainerName = _("TERRY"),  // ShinyGold fix: was "TERRY      " (removed stray trailing characters)
        .items = {ITEM_SUPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_RivalTerry),
    },

    [TRAINER_RIVAL_TERRY_2] = {
        .trainerClass = TRAINER_CLASS_CHAMPION, // "RIVAL"
        .encounterMusic_gender = 54,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("TERRY"),  // ShinyGold fix: was "TERRY      " (removed stray trailing characters)
        .items = {ITEM_SUPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_RivalTerry2),
    },

    [TRAINER_RIVAL_TERRY_3] = {
        .trainerClass = TRAINER_CLASS_CHAMPION, // "RIVAL"
        .encounterMusic_gender = 54,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("TERRY"),  // ShinyGold fix: was "TERRY      " (removed stray trailing characters)
        .items = {ITEM_SUPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_RivalTerry3),
    },

    [TRAINER_SAGE_GEN] = {
        .trainerClass = TRAINER_CLASS_HEX_MANIAC, // "SAGE"
        .encounterMusic_gender = 72,
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_F,
        .trainerName = _("GEN"),  // ShinyGold fix: was "GEN!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SageGen),
    },

    [TRAINER_LEADER_CONNOR] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = 107,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("CONNOR"),  // ShinyGold fix: was "-EDIT-" (vanilla FireRed name of this trainer slot)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_LeaderConnor),
    },

    [TRAINER_SCIENTIST_JED] = {
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = 107,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("JED"),  // ShinyGold fix: was "JED!" (removed stray trailing characters)
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
        .trainerName = _("MITCH"),  // ShinyGold fix: was "MITCH!" (removed stray trailing characters)
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
        .trainerName = _("ROSS"),  // ShinyGold fix: was "ROSS!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_ScientistRoss),
    },

    [TRAINER_SCIENTIST_PARKER] = {
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = 107,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("PARKER"),  // ShinyGold fix: was "PARKER     " (removed stray trailing characters)
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
        .trainerName = _("TRAVIS"),  // ShinyGold fix: was "TRAVIS     " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_ScientistTravis),
    },

    [TRAINER_SCIENTIST_MARC] = {
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("MARC"),  // ShinyGold fix: was "MARC!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_ScientistMarc),
    },

    [TRAINER_SCIENTIST_RICH] = {
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = 107,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("RICH"),  // ShinyGold fix: was "RICH!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_ScientistRich),
    },

    [TRAINER_TEAM_ROCKET_EXECUTIVE] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
        .trainerName = _("EXECUTIVE"),  // ShinyGold fix: was "EXECUTIVE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketExecutive),
    },

    [TRAINER_SCHOOLBOY_BILLY] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("BILLY"),  // ShinyGold fix: was "BILLY!" (removed stray trailing characters)
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
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt4),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_5] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt5),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_6] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt6),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_7] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt7),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_8] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt8),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_9] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt9),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_10] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt10),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_11] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt11),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_12] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt12),
    },

    [TRAINER_PKMN_TRAINER_GRUNT] = {
        .trainerClass = TRAINER_CLASS_NONE,
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "-EDIT-" (vanilla FireRed name of this trainer slot)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnTrainerGrunt),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_13] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt13),
    },

    [TRAINER_CLASS25_GRUNT] = {
        .trainerClass = TRAINER_CLASS_SCHOOL_KID, // ""
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "-EDIT-" (vanilla FireRed name of this trainer slot)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_Class25Grunt),
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
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt14),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_15] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt15),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_16] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt16),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_17] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt17),
    },

    [TRAINER_ROCKET_DUO_GRUNT] = {
        .trainerClass = TRAINER_CLASS_INTERVIEWER, // "ROCKET DUO"
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "" (vanilla FireRed name of this trainer slot)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_RocketDuoGrunt),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_18] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt18),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_19] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt19),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_20] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt20),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_21] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt21),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_22] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt22),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_23] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt23),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_24] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt24),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_25] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt25),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_26] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt26),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_27] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt27),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_28] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt28),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_29] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt29),
    },

    [TRAINER_TEAM_ROCKET_EXECUTIVE_2] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_AQUA_LEADER_ARCHIE,
        .trainerName = _("EXECUTIVE"),  // ShinyGold fix: was "EXECUTIVE!" (removed stray trailing characters)
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
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt30),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_31] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt31),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_32] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt32),
    },

    [TRAINER_TEAM_ROCKET_EXECUTIVE_3] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
        .trainerName = _("EXECUTIVE"),  // ShinyGold fix: was "EXECUTIVE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketExecutive3),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_33] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt33),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_34] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt34),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_35] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt35),
    },

    [TRAINER_TEAM_ROCKET_EXECUTIVE_4] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_AQUA_LEADER_ARCHIE,
        .trainerName = _("EXECUTIVE"),  // ShinyGold fix: was "EXECUTIVE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketExecutive4),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_36] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
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
        .trainerName = _("ASHLEE"),  // ShinyGold fix: was "ASHLEE   " (removed stray trailing characters)
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
        .trainerName = _("THOMAS"),  // ShinyGold fix: was "THOMAS     " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_GentlemanThomas),
    },

    [TRAINER_GENTLEMAN_GREGORY] = {
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("GREGORY"),  // ShinyGold fix: was "GREGORY!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_GentlemanGregory),
    },

    [TRAINER_GENTLEMAN_TUCKER] = {
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = 123,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("TUCKER"),  // ShinyGold fix: was "TUCKER     " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_GentlemanTucker),
    },

    [TRAINER_GENTLEMAN_NORTON] = {
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = 123,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("NORTON"),  // ShinyGold fix: was "NORTON     " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_GentlemanNorton),
    },

    [TRAINER_PICNICKER_CARRIE] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 123,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("CARRIE"),  // ShinyGold fix: was "CARRIE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerCarrie),
    },

    [TRAINER_SCHOOLBOY_KIPP] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 54,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("KIPP"),  // ShinyGold fix: was "KIPP!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SchoolboyKipp),
    },

    [TRAINER_CHAMPION_SILVER] = {
        .trainerClass = TRAINER_CLASS_RIVAL_LATE, // "CHAMPION"
        .encounterMusic_gender = 54,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("SILVER"),  // ShinyGold fix: was "" (rival class)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_ChampionSilver),
    },

    [TRAINER_CHAMPION_SILVER_2] = {
        .trainerClass = TRAINER_CLASS_RIVAL_LATE, // "CHAMPION"
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("SILVER"),  // ShinyGold fix: was "" (rival class)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_ChampionSilver2),
    },

    [TRAINER_CHAMPION_SILVER_3] = {
        .trainerClass = TRAINER_CLASS_RIVAL_LATE, // "CHAMPION"
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("SILVER"),  // ShinyGold fix: was "" (rival class)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_ChampionSilver3),
    },

    [TRAINER_CHAMPION_SILVER_4] = {
        .trainerClass = TRAINER_CLASS_RIVAL_LATE, // "CHAMPION"
        .encounterMusic_gender = 54,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("SILVER"),  // ShinyGold fix: was "" (rival class)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_ChampionSilver4),
    },

    [TRAINER_CHAMPION_SILVER_5] = {
        .trainerClass = TRAINER_CLASS_RIVAL_LATE, // "CHAMPION"
        .encounterMusic_gender = 54,
        .trainerPic = TRAINER_PIC_COLLECTOR,
        .trainerName = _("SILVER"),  // ShinyGold fix: was "" (rival class)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_ChampionSilver5),
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
        .trainerName = _("TERRY"),  // ShinyGold fix: was "TERRY      " (removed stray trailing characters)
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
        .trainerName = _("TERRY"),  // ShinyGold fix: was "TERRY      " (removed stray trailing characters)
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
        .trainerName = _("TERRY"),  // ShinyGold fix: was "TERRY      " (removed stray trailing characters)
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_RivalTerry13),
    },

    [TRAINER_RIVAL_TERRY_14] = {
        .trainerClass = TRAINER_CLASS_CHAMPION, // "RIVAL"
        .encounterMusic_gender = 64,
        .trainerPic = TRAINER_PIC_MAGMA_GRUNT_F,
        .trainerName = _("TERRY"),  // ShinyGold fix: was "TERRY      " (removed stray trailing characters)
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = ITEM_CUSTOM_MOVES(sParty_RivalTerry14),
    },

    [TRAINER_SAGE_JIN] = {
        .trainerClass = TRAINER_CLASS_HEX_MANIAC, // "SAGE"
        .encounterMusic_gender = 72,
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_F,
        .trainerName = _("JIN"),  // ShinyGold fix: was "JIN!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SageJin),
    },

    [TRAINER_SAGE_NEAL] = {
        .trainerClass = TRAINER_CLASS_HEX_MANIAC, // "SAGE"
        .encounterMusic_gender = 72,
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_F,
        .trainerName = _("NEAL"),  // ShinyGold fix: was "NEAL!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SageNeal),
    },

    [TRAINER_MEDIUM_HOPE] = {
        .trainerClass = TRAINER_CLASS_CHANNELER, // "MEDIUM"
        .encounterMusic_gender = 126,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("HOPE"),  // ShinyGold fix: was "HOPE       " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_MediumHope),
    },

    [TRAINER_MEDIUM_PAULA] = {
        .trainerClass = TRAINER_CLASS_CHANNELER, // "MEDIUM"
        .encounterMusic_gender = 126,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("PAULA"),  // ShinyGold fix: was "PAULA      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_MediumPaula),
    },

    [TRAINER_SAGE_TROY] = {
        .trainerClass = TRAINER_CLASS_HEX_MANIAC, // "SAGE"
        .encounterMusic_gender = 72,
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_F,
        .trainerName = _("TROY"),  // ShinyGold fix: was "TROY!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SageTroy),
    },

    [TRAINER_MEDIUM_JODY] = {
        .trainerClass = TRAINER_CLASS_CHANNELER, // "MEDIUM"
        .encounterMusic_gender = 126,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("JODY"),  // ShinyGold fix: was "JODY       " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_MediumJody),
    },

    [TRAINER_MEDIUM_TAMMY] = {
        .trainerClass = TRAINER_CLASS_CHANNELER, // "MEDIUM"
        .encounterMusic_gender = 126,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("TAMMY"),  // ShinyGold fix: was "TAMMY      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_MediumTammy),
    },

    [TRAINER_MEDIUM_RUTH] = {
        .trainerClass = TRAINER_CLASS_CHANNELER, // "MEDIUM"
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("RUTH"),  // ShinyGold fix: was "RUTH       " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_MediumRuth),
    },

    [TRAINER_MEDIUM_KARINA] = {
        .trainerClass = TRAINER_CLASS_CHANNELER, // "MEDIUM"
        .encounterMusic_gender = 126,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("KARINA"),  // ShinyGold fix: was "KARINA     " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_MediumKarina),
    },

    [TRAINER_MEDIUM_JANAE] = {
        .trainerClass = TRAINER_CLASS_CHANNELER, // "MEDIUM"
        .encounterMusic_gender = 126,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("JANAE"),  // ShinyGold fix: was "JANAE      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_MediumJanae),
    },

    [TRAINER_SAGE_CHOW] = {
        .trainerClass = TRAINER_CLASS_HEX_MANIAC, // "SAGE"
        .encounterMusic_gender = 72,
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_F,
        .trainerName = _("CHOW"),  // ShinyGold fix: was "CHOW!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SageChow),
    },

    [TRAINER_MEDIUM_EMILIA] = {
        .trainerClass = TRAINER_CLASS_CHANNELER, // "MEDIUM"
        .encounterMusic_gender = 126,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("EMILIA"),  // ShinyGold fix: was "EMILIA     " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_MediumEmilia),
    },

    [TRAINER_MEDIUM_JENNIFER] = {
        .trainerClass = TRAINER_CLASS_CHANNELER, // "MEDIUM"
        .encounterMusic_gender = 126,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("JENNIFER"),  // ShinyGold fix: was "JENNIFER   " (removed stray trailing characters)
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
        .trainerName = _("GRACE"),  // ShinyGold fix: was "GRACE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_MediumGrace),
    },

    [TRAINER_MEDIUM_STACY] = {
        .trainerClass = TRAINER_CLASS_CHANNELER, // "MEDIUM"
        .encounterMusic_gender = 126,
        .trainerPic = TRAINER_PIC_CHANNELER,
        .trainerName = _("STACY"),  // ShinyGold fix: was "STACY      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_MediumStacy),
    },

    [TRAINER_SAGE_NICO] = {
        .trainerClass = TRAINER_CLASS_HEX_MANIAC, // "SAGE"
        .encounterMusic_gender = 72,
        .trainerPic = TRAINER_PIC_AQUA_ADMIN_F,
        .trainerName = _("NICO"),  // ShinyGold fix: was "NICO!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SageNico),
    },

    [TRAINER_FISHERMAN_CHRIS] = {
        .trainerClass = TRAINER_CLASS_RS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("CHRIS"),  // ShinyGold fix: was "18TRAINER/1" (G/S phone contact #18, rematch tier 1)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanChris),
    },

    [TRAINER_COOLTRAINER_KEVIN] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("KEVIN"),  // ShinyGold fix: was "KEVIN!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerKevin),
    },

    [TRAINER_PKMN_TRAINER_SUSIE] = {
        .trainerClass = TRAINER_CLASS_NONE,
        .encounterMusic_gender = 28,
        .trainerPic = TRAINER_PIC_LEADER_TATE_AND_LIZA,
        .trainerName = _("SUSIE"),  // ShinyGold fix: was "" (vanilla FireRed name of this trainer slot)
        .items = {ITEM_HYPER_POTION, ITEM_FULL_RESTORE, ITEM_HYPER_POTION, ITEM_FULL_HEAL},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PkmnTrainerSusie),
    },

    [TRAINER_PICNICKER_VALERIE] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("VALERIE"),  // ShinyGold fix: was "VALERIE    " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerValerie),
    },

    [TRAINER_HIKER_GABRIEL] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("GABRIEL"),  // ShinyGold fix: was "GABRIEL!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerGabriel),
    },

    [TRAINER_SAGE_VIRGIL] = {
        .trainerClass = TRAINER_CLASS_HEX_MANIAC, // "SAGE"
        .encounterMusic_gender = 34,
        .trainerPic = TRAINER_PIC_EXPERT_M,
        .trainerName = _("VIRGIL"),  // ShinyGold fix: was "-EDIT-" (vanilla FireRed name of this trainer slot)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_SageVirgil),
    },

    [TRAINER_CAMPER_FLINT] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("FLINT"),  // ShinyGold fix: was "FLINT      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CamperFlint),
    },

    [TRAINER_PICNICKER_TIFFANY] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("TIFFANY"),  // ShinyGold fix: was "19TRAINER/1" (G/S phone contact #19, rematch tier 1)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerTiffany),
    },

    [TRAINER_CAMPER_SID] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("SID"),  // ShinyGold fix: was "SID!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CamperSid),
    },

    [TRAINER_HIKER_TIM] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("TIM"),  // ShinyGold fix: was "TIM!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerTim),
    },

    [TRAINER_ROCKET_DUO_JESS_AND_JAMIE_6] = {
        .trainerClass = TRAINER_CLASS_INTERVIEWER, // "ROCKET DUO"
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .trainerName = _("JESS&JAMIE"),  // ShinyGold fix: was "" (Team Rocket duo party; same name as the hack's other ROCKET DUO trainer)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_RocketDuoJessAndJamie6),
    },

    [TRAINER_PICNICKER_LEAH] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("LEAH"),  // ShinyGold fix: was "LEAH       " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerLeah),
    },

    [TRAINER_CAMPER_JUSTIN] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("JUSTIN"),  // ShinyGold fix: was "JUSTIN     " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CamperJustin),
    },

    [TRAINER_LASS_MICHELLE] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("MICHELLE"),  // ShinyGold fix: was "MICHELLE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassMichelle),
    },

    [TRAINER_BEAUTY_JULIA] = {
        .trainerClass = TRAINER_CLASS_BEAUTY,
        .encounterMusic_gender = 98,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("JULIA"),  // ShinyGold fix: was "JULIA!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BeautyJulia),
    },

    [TRAINER_SCHOOLBOY_JACK] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JACK"),  // ShinyGold fix: was "12TRAINER/1" (G/S phone contact #12, rematch tier 1)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SchoolboyJack),
    },

    [TRAINER_PICNICKER_CELIA] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("CELIA"),  // ShinyGold fix: was "CELIA      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerCelia),
    },

    [TRAINER_GENTLEMAN_BROOKS] = {
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = 123,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("BROOKS"),  // ShinyGold fix: was "BROOKS     " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_GentlemanBrooks),
    },

    [TRAINER_GENTLEMAN_LAMAR] = {
        .trainerClass = TRAINER_CLASS_GENTLEMAN,
        .encounterMusic_gender = 123,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("LAMAR"),  // ShinyGold fix: was "LAMAR      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_GentlemanLamar),
    },

    [TRAINER_TWINS_AMY_AND_MAY] = {
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = 127,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("AMY & MAY"),  // ShinyGold fix: was "AMY & MAY!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TwinsAmyAndMay),
    },

    [TRAINER_LEADER_ANN_AND_ANNE] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = 127,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("ANN & ANNE"),  // ShinyGold fix: was "-EDIT-" (exact G/S party match (Twins))
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_LeaderAnnAndAnne),
    },

    [TRAINER_TWINS_ANN_AND_ANNE] = {
        .trainerClass = TRAINER_CLASS_RS_TWINS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("ANN & ANNE"),  // ShinyGold fix: was "ANN & ANNE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TwinsAnnAndAnne),
    },

    [TRAINER_TWINS_MEG_AND_PEG] = {
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = 127,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("MEG & PEG"),  // ShinyGold fix: was "MEG & PEG!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TwinsMegAndPeg),
    },

    [TRAINER_TWINS_JO_AND_ZOE] = {
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("JO & ZOE"),  // ShinyGold fix: was "JO & ZOE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_TwinsJoAndZoe),
    },

    [TRAINER_YOUNG_COUPLE_LEA_AND_JED] = {
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .trainerName = _("LEA & JED"),  // ShinyGold fix: was "LEA & JED  " (removed stray trailing characters)
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungCoupleLeaAndJed),
    },

    [TRAINER_SIS_AND_BRO_LIA_AND_LUC] = {
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .trainerName = _("LIA & LUC"),  // ShinyGold fix: was "LIA & LUC  " (removed stray trailing characters)
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SisAndBroLiaAndLuc),
    },

    [TRAINER_SIS_AND_BRO_LIL_AND_IAN] = {
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .trainerName = _("LIL & IAN"),  // ShinyGold fix: was "LIL & IAN  " (removed stray trailing characters)
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

    [TRAINER_YOUNGSTER_JOEY_4] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("JOEY"),  // ShinyGold fix: was " 1TRAINER/3" (G/S phone contact #1, rematch tier 3)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungsterJoey4),
    },

    [TRAINER_YOUNGSTER_JOEY_5] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("JOEY"),  // ShinyGold fix: was " 1TRAINER/4" (G/S phone contact #1, rematch tier 4)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungsterJoey5),
    },

    [TRAINER_BUG_CATCHER_ARNIE_2] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("ARNIE"),  // ShinyGold fix: was " 9TRAINER/2" (G/S phone contact #9, rematch tier 2)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcherArnie2),
    },

    [TRAINER_LASS_DANA_2] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("DANA"),  // ShinyGold fix: was "13TRAINER/2" (G/S phone contact #13, rematch tier 2)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassDana2),
    },

    [TRAINER_LASS_DANA_3] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("DANA"),  // ShinyGold fix: was "13TRAINER/3" (G/S phone contact #13, rematch tier 3)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassDana3),
    },

    [TRAINER_BIKER_GLENN] = {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = 91,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("GLENN"),  // ShinyGold fix: was "GLENN!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BikerGlenn),
    },

    [TRAINER_BIKER_CHARLES] = {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = 91,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("CHARLES"),  // ShinyGold fix: was "CHARLES!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BikerCharles),
    },

    [TRAINER_BIRD_KEEPER_BORIS] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("BORIS"),  // ShinyGold fix: was "BORIS!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperBoris),
    },

    [TRAINER_BUG_CATCHER_ARNIE_3] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("ARNIE"),  // ShinyGold fix: was " 9TRAINER/3" (G/S phone contact #9, rematch tier 3)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcherArnie3),
    },

    [TRAINER_PICNICKER_ERIN_2] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("ERIN"),  // ShinyGold fix: was "16TRAINER/2" (G/S phone contact #16, rematch tier 2)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerErin2),
    },

    [TRAINER_PICNICKER_ERIN_3] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("ERIN"),  // ShinyGold fix: was "16TRAINER/3" (G/S phone contact #16, rematch tier 3)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerErin3),
    },

    [TRAINER_BUG_CATCHER_ARNIE_4] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("ARNIE"),  // ShinyGold fix: was " 9TRAINER/4" (G/S phone contact #9, rematch tier 4)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcherArnie4),
    },

    [TRAINER_HIKER_FRANKLIN] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("FRANKLIN"),  // ShinyGold fix: was "FRANKLIN   " (removed stray trailing characters)
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
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt37),
    },

    [TRAINER_PKMN_TRAINER_JACLYN] = {
        .trainerClass = TRAINER_CLASS_RS_ELITE_FOUR, // "PKMN TRAINER"
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("JACLYN"),  // ShinyGold fix: was "-EDIT-" (vanilla FireRed name of this trainer slot)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnTrainerJaclyn),
    },

    [TRAINER_COOLTRAINER_BETH] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("BETH"),  // ShinyGold fix: was "25TRAINER/1" (G/S phone contact #25, rematch tier 1)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_CooltrainerBeth),
    },

    [TRAINER_FISHERMAN_KYLE] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("KYLE"),  // ShinyGold fix: was "KYLE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanKyle),
    },

    [TRAINER_FISHERMAN_BARNEY] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("BARNEY"),  // ShinyGold fix: was "BARNEY!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanBarney),
    },

    [TRAINER_PKMN_RANGER_NICOLAS_3] = {
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = F_TRAINER_FEMALE | 14,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .trainerName = _("NICOLAS"),  // ShinyGold fix: was "-EDIT-" (vanilla FireRed name of this trainer slot)
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnRangerNicolas3),
    },

    [TRAINER_PKMN_RANGER_MADELINE_3] = {
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = F_TRAINER_FEMALE | 15,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_F,
        .trainerName = _("MADELINE"),  // ShinyGold fix: was "-EDIT-" (vanilla FireRed name of this trainer slot)
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnRangerMadeline3),
    },

    [TRAINER_AROMA_LADY_NIKKI] = {
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | 16,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .trainerName = _("NIKKI"),  // ShinyGold fix: was "NIKKI      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_AromaLadyNikki),
    },

    [TRAINER_PSYCHIC_HERMAN] = {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = 100,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("HERMAN"),  // ShinyGold fix: was "HERMAN!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PsychicHerman),
    },

    [TRAINER_LADY_JACKI] = {
        .trainerClass = TRAINER_CLASS_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | 18,
        .trainerPic = TRAINER_PIC_LADY,
        .trainerName = _("JACKI"),  // ShinyGold fix: was "JACKI      " (removed stray trailing characters)
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_LadyJacki),
    },

    [TRAINER_PAINTER_DAISY] = {
        .trainerClass = TRAINER_CLASS_PAINTER,
        .encounterMusic_gender = F_TRAINER_FEMALE | 19,
        .trainerPic = TRAINER_PIC_PAINTER,
        .trainerName = _("DAISY"),  // ShinyGold fix: was "DAISY      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PainterDaisy),
    },

    [TRAINER_BIKER_GOON_4] = {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = 91,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("GOON"),  // ShinyGold fix: was "-EDIT-" (vanilla FireRed name of this trainer slot)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_BikerGoon4),
    },

    [TRAINER_BIKER_GOON] = {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = 91,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("GOON"),  // ShinyGold fix: was "GOON       " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_BikerGoon),
    },

    [TRAINER_BIKER_GOON_5] = {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = 91,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("GOON"),  // ShinyGold fix: was "-EDIT-" (vanilla FireRed name of this trainer slot)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BikerGoon5),
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
        .trainerName = _("ANTHONY"),  // ShinyGold fix: was "ANTHONY    " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcherAnthony),
    },

    [TRAINER_BUG_CATCHER_ED] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("ED"),  // ShinyGold fix: was "ED!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcherEd),
    },

    [TRAINER_TWINS_ELI_AND_ANNE] = {
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = 127,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("ELI & ANNE"),  // ShinyGold fix: was "ELI & ANNE " (removed stray trailing characters)
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TwinsEliAndAnne),
    },

    [TRAINER_LASS_LINDA] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("LINDA"),  // ShinyGold fix: was "LINDA!" (removed stray trailing characters)
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
        .trainerName = _("EXECUTIVE"),  // ShinyGold fix: was "EXECUTIVE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketExecutive5),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_38] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
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
        .trainerName = _("ALEX"),  // ShinyGold fix: was "ALEX!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokefanAlex),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_39] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt39),
    },

    [TRAINER_TEAM_ROCKET_EXECUTIVE_6] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_AQUA_LEADER_ARCHIE,
        .trainerName = _("EXECUTIVE"),  // ShinyGold fix: was "EXECUTIVE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketExecutive6),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_40] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TeamRocketGrunt40),
    },

    [TRAINER_TEAM_ROCKET_ADMIN_3] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("ADMIN"),  // ShinyGold fix: was "-EDIT-" (vanilla FireRed name of this trainer slot)
        .items = {ITEM_HYPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_TeamRocketAdmin3),
    },

    [TRAINER_LEADER_ADMIN] = {
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("ADMIN"),  // ShinyGold fix: was "-EDIT-" (vanilla FireRed name of this trainer slot)
        .items = {ITEM_HYPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_LeaderAdmin),
    },

    [TRAINER_SCIENTIST_GIDEON_2] = {
        .trainerClass = TRAINER_CLASS_SCIENTIST,
        .encounterMusic_gender = 107,
        .trainerPic = TRAINER_PIC_SCIENTIST,
        .trainerName = _("GIDEON"),  // ShinyGold fix: was "-EDIT-" (vanilla FireRed name of this trainer slot)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_ScientistGideon2),
    },

    [TRAINER_POKEFAN_CARTER] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 32,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("CARTER"),  // ShinyGold fix: was "CARTER!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokefanCarter),
    },

    [TRAINER_SWIMMER_F_MARIA] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = 99,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("MARIA"),  // ShinyGold fix: was "MARIA      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerFMaria),
    },

    [TRAINER_SCHOOLBOY_JOHNNY] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JOHNNY"),  // ShinyGold fix: was "JOHNNY!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SchoolboyJohnny),
    },

    [TRAINER_BIRD_KEEPER_JOSE_3] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("JOSE"),  // ShinyGold fix: was "26TRAINER/1" (G/S phone contact #26, rematch tier 1)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperJose3),
    },

    [TRAINER_LASS_ALICE] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("ALICE"),  // ShinyGold fix: was "ALICE!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassAlice),
    },

    [TRAINER_FISHERMAN_TOMMY] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("TOMMY"),  // ShinyGold fix: was "TOMMY      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanTommy),
    },

    [TRAINER_CRUSH_GIRL_TANYA] = {
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .trainerName = _("TANYA"),  // ShinyGold fix: was "TANYA      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_CrushGirlTanya),
    },

    [TRAINER_BLACK_BELT_SHEA] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("SHEA"),  // ShinyGold fix: was "SHEA       " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_BlackBeltShea),
    },

    [TRAINER_BLACK_BELT_HUGH] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("HUGH"),  // ShinyGold fix: was "HUGH       " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_BlackBeltHugh),
    },

    [TRAINER_FISHERMAN_PHIL] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("PHIL"),  // ShinyGold fix: was "PHIL!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanPhil),
    },

    [TRAINER_PICNICKER_CLAIRE] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("CLAIRE"),  // ShinyGold fix: was "CLAIRE     " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerClaire),
    },

    [TRAINER_CRUSH_KIN_MIK_AND_KIA] = {
        .trainerClass = TRAINER_CLASS_CRUSH_KIN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_CRUSH_KIN,
        .trainerName = _("MIK & KIA"),  // ShinyGold fix: was "MIK & KIA  " (removed stray trailing characters)
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_CrushKinMikAndKia),
    },

    [TRAINER_LASS_REMI] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("REMI"),  // ShinyGold fix: was "REMI!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassRemi),
    },

    [TRAINER_TUBER_ALEXIS] = {
        .trainerClass = TRAINER_CLASS_TUBER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_INTERVIEWER,
        .trainerPic = TRAINER_PIC_TUBER_F,
        .trainerName = _("ALEXIS"),  // ShinyGold fix: was "ALEXIS     " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TuberAlexis),
    },

    [TRAINER_TWINS_JOY_AND_MEG] = {
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = 127,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("JOY & MEG"),  // ShinyGold fix: was "JOY & MEG  " (removed stray trailing characters)
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TwinsJoyAndMeg),
    },

    [TRAINER_SWIMMER_F_TISHA] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = 99,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("TISHA"),  // ShinyGold fix: was "TISHA      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerFTisha),
    },

    [TRAINER_PAINTER_CELINA] = {
        .trainerClass = TRAINER_CLASS_PAINTER,
        .encounterMusic_gender = F_TRAINER_FEMALE | 19,
        .trainerPic = TRAINER_PIC_PAINTER,
        .trainerName = _("CELINA"),  // ShinyGold fix: was "CELINA     " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PainterCelina),
    },

    [TRAINER_PAINTER_RAYNA] = {
        .trainerClass = TRAINER_CLASS_PAINTER,
        .encounterMusic_gender = F_TRAINER_FEMALE | 19,
        .trainerPic = TRAINER_PIC_PAINTER,
        .trainerName = _("RAYNA"),  // ShinyGold fix: was "RAYNA      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PainterRayna),
    },

    [TRAINER_COOLTRAINER_REZO] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("REZO"),  // ShinyGold fix: was "REZO!" (removed stray trailing characters)
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_CooltrainerRezo),
    },

    [TRAINER_YOUNGSTER_DESTIN] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("DESTIN"),  // ShinyGold fix: was "DESTIN     " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungsterDestin),
    },

    [TRAINER_BLACK_BELT_RANDY] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = 95,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("RANDY"),  // ShinyGold fix: was "RANDY!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BlackBeltRandy),
    },

    [TRAINER_COOLTRAINER_REIKA] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("REIKA"),  // ShinyGold fix: was "REIKA!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerReika),
    },

    [TRAINER_TEAM_ROCKET_GRUNT_41] = {
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = 109,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("GRUNT"),  // ShinyGold fix: was "GRUNT      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_TeamRocketGrunt41),
    },

    [TRAINER_BIKER_LARK] = {
        .trainerClass = TRAINER_CLASS_BIKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_BIKER,
        .trainerName = _("LARK"),  // ShinyGold fix: was "LARK!" (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BikerLark),
    },

    [TRAINER_BIRD_KEEPER_MILO] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("MILO"),  // ShinyGold fix: was "MILO       " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperMilo),
    },

    [TRAINER_BIRD_KEEPER_CHAZ] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_COOL,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("CHAZ"),  // ShinyGold fix: was "CHAZ       " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperChaz),
    },

    [TRAINER_BIRD_KEEPER_HAROLD] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("HAROLD"),  // ShinyGold fix: was "HAROLD     " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperHarold),
    },

    [TRAINER_FISHERMAN_TYLOR] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("TYLOR"),  // ShinyGold fix: was "TYLOR      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanTylor),
    },

    [TRAINER_SWIMMER_M_MYMO] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = 95,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("MYMO"),  // ShinyGold fix: was "MYMO       " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerMMymo),
    },

    [TRAINER_SWIMMER_F_NICOLE] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = 99,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("NICOLE"),  // ShinyGold fix: was "NICOLE     " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerFNicole),
    },

    [TRAINER_SIS_AND_BRO_AVA_AND_GEB] = {
        .trainerClass = TRAINER_CLASS_SIS_AND_BRO,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SIS_AND_BRO,
        .trainerName = _("AVA & GEB"),  // ShinyGold fix: was "AVA & GEB  " (removed stray trailing characters)
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SisAndBroAvaAndGeb),
    },

    [TRAINER_AROMA_LADY_ROSE] = {
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | 16,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .trainerName = _("ROSE"),  // ShinyGold fix: was "ROSE       " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_AromaLadyRose),
    },

    [TRAINER_SWIMMER_M_SAMIR] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_M,
        .encounterMusic_gender = 95,
        .trainerPic = TRAINER_PIC_SWIMMER_M,
        .trainerName = _("SAMIR"),  // ShinyGold fix: was "SAMIR      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerMSamir),
    },

    [TRAINER_SWIMMER_F_DENISE_2] = {
        .trainerClass = TRAINER_CLASS_SWIMMER_F,
        .encounterMusic_gender = 99,
        .trainerPic = TRAINER_PIC_SWIMMER_F,
        .trainerName = _("DENISE"),  // ShinyGold fix: was "DENISE     " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SwimmerFDenise2),
    },

    [TRAINER_TWINS_MIU_AND_MIA] = {
        .trainerClass = TRAINER_CLASS_TWINS,
        .encounterMusic_gender = 127,
        .trainerPic = TRAINER_PIC_TWINS,
        .trainerName = _("MIU & MIA"),  // ShinyGold fix: was "MIU & MIA  " (removed stray trailing characters)
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TwinsMiuAndMia),
    },

    [TRAINER_HIKER_EARL] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("EARL"),  // ShinyGold fix: was "EARL       " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerEarl),
    },

    [TRAINER_RUIN_MANIAC_FOSTER] = {
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = F_TRAINER_FEMALE | 17,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("FOSTER"),  // ShinyGold fix: was "FOSTER     " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_RuinManiacFoster),
    },

    [TRAINER_RUIN_MANIAC_LARRY] = {
        .trainerClass = TRAINER_CLASS_RUIN_MANIAC,
        .encounterMusic_gender = F_TRAINER_FEMALE | 17,
        .trainerPic = TRAINER_PIC_RUIN_MANIAC,
        .trainerName = _("LARRY"),  // ShinyGold fix: was "LARRY      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_RuinManiacLarry),
    },

    [TRAINER_HIKER_DARYL] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("DARYL"),  // ShinyGold fix: was "DARYL      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerDaryl),
    },

    [TRAINER_POKEMANIAC_HECTOR] = {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("HECTOR"),  // ShinyGold fix: was "HECTOR     " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokemaniacHector),
    },

    [TRAINER_PSYCHIC_DARIO] = {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = 100,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("DARIO"),  // ShinyGold fix: was "DARIO      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PsychicDario),
    },

    [TRAINER_PSYCHIC_RODETTE] = {
        .trainerClass = TRAINER_CLASS_PSYCHIC,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_PSYCHIC_F,
        .trainerName = _("RODETTE"),  // ShinyGold fix: was "RODETTE    " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PsychicRodette),
    },

    [TRAINER_AROMA_LADY_MIAH] = {
        .trainerClass = TRAINER_CLASS_AROMA_LADY,
        .encounterMusic_gender = F_TRAINER_FEMALE | 16,
        .trainerPic = TRAINER_PIC_AROMA_LADY,
        .trainerName = _("MIAH"),  // ShinyGold fix: was "MIAH       " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_AromaLadyMiah),
    },

    [TRAINER_YOUNG_COUPLE_EVE_AND_JON] = {
        .trainerClass = TRAINER_CLASS_YOUNG_COUPLE,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_YOUNG_COUPLE,
        .trainerName = _("EVE & JON"),  // ShinyGold fix: was "EVE & JON  " (removed stray trailing characters)
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_YoungCoupleEveAndJon),
    },

    [TRAINER_ROCKET_DUO_MASON] = {
        .trainerClass = TRAINER_CLASS_TRIATHLETE, // "ROCKET DUO"
        .encounterMusic_gender = 102,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("MASON"),  // ShinyGold fix: was "-EDIT-" (vanilla FireRed name of this trainer slot)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_RocketDuoMason),
    },

    [TRAINER_CRUSH_GIRL_CYNDY] = {
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .trainerName = _("CYNDY"),  // ShinyGold fix: was "CYNDY      " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_CrushGirlCyndy),
    },

    [TRAINER_CRUSH_GIRL_JOCELYN] = {
        .trainerClass = TRAINER_CLASS_CRUSH_GIRL,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_CRUSH_GIRL,
        .trainerName = _("JOCELYN"),  // ShinyGold fix: was "JOCELYN    " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_CrushGirlJocelyn),
    },

    [TRAINER_TAMER_EVAN] = {
        .trainerClass = TRAINER_CLASS_TAMER,
        .encounterMusic_gender = 103,
        .trainerPic = TRAINER_PIC_TAMER,
        .trainerName = _("EVAN"),  // ShinyGold fix: was "EVAN       " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_TamerEvan),
    },

    [TRAINER_POKEMANIAC_MARK] = {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("MARK"),  // ShinyGold fix: was "MARK       " (removed stray trailing characters)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokemaniacMark),
    },

    [TRAINER_PKMN_RANGER_LOGAN_2] = {
        .trainerClass = TRAINER_CLASS_PKMN_RANGER,
        .encounterMusic_gender = F_TRAINER_FEMALE | 14,
        .trainerPic = TRAINER_PIC_POKEMON_RANGER_M,
        .trainerName = _("LOGAN"),  // ShinyGold fix: was "-EDIT-" (vanilla FireRed name of this trainer slot)
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_PkmnRangerLogan2),
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
        .trainerName = _("BETH"),  // ShinyGold fix: was "BETH       " (removed stray trailing characters)
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

    [TRAINER_HIKER_PARRY_4] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("PARRY"),  // ShinyGold fix: was "24TRAINER/3" (G/S phone contact #24, rematch tier 3)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerParry4),
    },

    [TRAINER_HIKER_PARRY_5] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("PARRY"),  // ShinyGold fix: was "-EDIT-" (G/S Hiker Parry (Route 45 phone contact) party)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_CUSTOM_MOVES(sParty_HikerParry5),
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

    [TRAINER_BLACK_BELT_KENJI_2] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("KENJI"),  // ShinyGold fix: was "23TRAINER/5" (G/S phone contact #23, rematch tier 5)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BlackBeltKenji2),
    },

    [TRAINER_BLACK_BELT_KENJI_3] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("KENJI"),  // ShinyGold fix: was "-EDITG-" (G/S Black Belt Kenji rematch party)
        .items = {ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_CUSTOM_MOVES(sParty_BlackBeltKenji3),
    },

    [TRAINER_BLACK_BELT_KENJI_4] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("KENJI"),  // ShinyGold fix: was "23TRAINER/4" (G/S phone contact #23, rematch tier 4)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BlackBeltKenji4),
    },

    [TRAINER_BLACK_BELT_KENJI_5] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("KENJI"),  // ShinyGold fix: was "23TRAINER/3" (G/S phone contact #23, rematch tier 3)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BlackBeltKenji5),
    },

    [TRAINER_BLACK_BELT_KENJI_6] = {
        .trainerClass = TRAINER_CLASS_BLACK_BELT,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("KENJI"),  // ShinyGold fix: was "23TRAINER/2" (G/S phone contact #23, rematch tier 2)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BlackBeltKenji6),
    },

    [TRAINER_BIRD_KEEPER_VANCE_2] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_RICH,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("VANCE"),  // ShinyGold fix: was "22TRAINER/5" (G/S phone contact #22, rematch tier 5)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperVance2),
    },

    [TRAINER_BIRD_KEEPER_VANCE_3] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("VANCE"),  // ShinyGold fix: was "22TRAINER/4" (G/S phone contact #22, rematch tier 4)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperVance3),
    },

    [TRAINER_FISHERMAN_WILTON_2] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("WILTON"),  // ShinyGold fix: was "21TRAINER/5" (G/S phone contact #21, rematch tier 5)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanWilton2),
    },

    [TRAINER_FISHERMAN_WILTON_3] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("WILTON"),  // ShinyGold fix: was "21TRAINER/4" (G/S phone contact #21, rematch tier 4)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanWilton3),
    },

    [TRAINER_FISHERMAN_WILTON_4] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("WILTON"),  // ShinyGold fix: was "21TRAINER/3" (G/S phone contact #21, rematch tier 3)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanWilton4),
    },

    [TRAINER_POKEMANIAC_BRENT_2] = {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("BRENT"),  // ShinyGold fix: was "20TRAINER/5" (G/S phone contact #20, rematch tier 5)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokemaniacBrent2),
    },

    [TRAINER_POKEMANIAC_BRENT_3] = {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("BRENT"),  // ShinyGold fix: was "20TRAINER/4" (G/S phone contact #20, rematch tier 4)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokemaniacBrent3),
    },

    [TRAINER_POKEMANIAC_BRENT_4] = {
        .trainerClass = TRAINER_CLASS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("BRENT"),  // ShinyGold fix: was "20TRAINER/3" (G/S phone contact #20, rematch tier 3)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokemaniacBrent4),
    },

    [TRAINER_PICNICKER_TIFFANY_2] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("TIFFANY"),  // ShinyGold fix: was "19TRAINER/5" (G/S phone contact #19, rematch tier 5)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerTiffany2),
    },

    [TRAINER_PICNICKER_TIFFANY_3] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("TIFFANY"),  // ShinyGold fix: was "19TRAINER/4" (G/S phone contact #19, rematch tier 4)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerTiffany3),
    },

    [TRAINER_FISHERMAN_CHRIS_2] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("CHRIS"),  // ShinyGold fix: was "18TRAINER/5" (G/S phone contact #18, rematch tier 5)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanChris2),
    },

    [TRAINER_PICNICKER_LIZ_2] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("LIZ"),  // ShinyGold fix: was " 4TRAINER/2" (G/S phone contact #4, rematch tier 2)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerLiz2),
    },

    [TRAINER_FISHERMAN_CHRIS_3] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("CHRIS"),  // ShinyGold fix: was "18TRAINER/4" (G/S phone contact #18, rematch tier 4)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanChris3),
    },

    [TRAINER_FISHERMAN_CHRIS_4] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("CHRIS"),  // ShinyGold fix: was "18TRAINER/3" (G/S phone contact #18, rematch tier 3)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanChris4),
    },

    [TRAINER_POKEFAN_BEVERLY_2] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 33,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("BEVERLY"),  // ShinyGold fix: was "11TRAINER/2" (G/S phone contact #11, rematch tier 2)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokefanBeverly2),
    },

    [TRAINER_POKEFAN_BEVERLY_3] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("BEVERLY"),  // ShinyGold fix: was "11TRAINER/3" (G/S phone contact #11, rematch tier 3)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokefanBeverly3),
    },

    [TRAINER_POKEFAN_BEVERLY_4] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 33,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("BEVERLY"),  // ShinyGold fix: was "11TRAINER/4" (G/S phone contact #11, rematch tier 4)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokefanBeverly4),
    },

    [TRAINER_FISHERMAN_RALPH_2] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("RALPH"),  // ShinyGold fix: was " 3TRAINER/2" (G/S phone contact #3, rematch tier 2)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanRalph2),
    },

    [TRAINER_FISHERMAN_RALPH_3] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("RALPH"),  // ShinyGold fix: was " 3TRAINER/3" (G/S phone contact #3, rematch tier 3)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanRalph3),
    },

    [TRAINER_FISHERMAN_RALPH_4] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("RALPH"),  // ShinyGold fix: was " 3TRAINER/4" (G/S phone contact #3, rematch tier 4)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanRalph4),
    },

    [TRAINER_PICNICKER_GINA_2] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("GINA"),  // ShinyGold fix: was " 7TRAINER/2" (G/S phone contact #7, rematch tier 2)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerGina2),
    },

    [TRAINER_PICNICKER_GINA_3] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("GINA"),  // ShinyGold fix: was " 7TRAINER/3" (G/S phone contact #7, rematch tier 3)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerGina3),
    },

    [TRAINER_PICNICKER_GINA_4] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("GINA"),  // ShinyGold fix: was " 7TRAINER/4" (G/S phone contact #7, rematch tier 4)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerGina4),
    },

    [TRAINER_BIRD_KEEPER_VANCE_4] = {
        .trainerClass = TRAINER_CLASS_RS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("VANCE"),  // ShinyGold fix: was "22TRAINER/2" (G/S phone contact #22, rematch tier 2)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperVance4),
    },

    [TRAINER_BIRD_KEEPER_VANCE_5] = {
        .trainerClass = TRAINER_CLASS_RS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("VANCE"),  // ShinyGold fix: was "22TRAINER/3" (G/S phone contact #22, rematch tier 3)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperVance5),
    },

    [TRAINER_COOLTRAINER_REENA_5] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("REENA"),  // ShinyGold fix: was "28TRAINER/2" (G/S phone contact #28, rematch tier 2)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerReena5),
    },

    [TRAINER_SAILOR_HUEY_3] = {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = 85,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("HUEY"),  // ShinyGold fix: was "17TRAINER/2" (G/S phone contact #17, rematch tier 2)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SailorHuey3),
    },

    [TRAINER_SAILOR_HUEY_4] = {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("HUEY"),  // ShinyGold fix: was "17TRAINER/5" (G/S phone contact #17, rematch tier 5)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SailorHuey4),
    },

    [TRAINER_SAILOR_HUEY_5] = {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("HUEY"),  // ShinyGold fix: was "17TRAINER/4" (G/S phone contact #17, rematch tier 4)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SailorHuey5),
    },

    [TRAINER_SAILOR_HUEY_6] = {
        .trainerClass = TRAINER_CLASS_SAILOR,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_SAILOR,
        .trainerName = _("HUEY"),  // ShinyGold fix: was "17TRAINER/3" (G/S phone contact #17, rematch tier 3)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SailorHuey6),
    },

    [TRAINER_POKEFAN_DEREK_2] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 32,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("DEREK"),  // ShinyGold fix: was "15TRAINER/2" (G/S phone contact #15, rematch tier 2)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokefanDerek2),
    },

    [TRAINER_POKEFAN_DEREK_3] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("DEREK"),  // ShinyGold fix: was "15TRAINER/3" (G/S phone contact #15, rematch tier 3)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokefanDerek3),
    },

    [TRAINER_POKEFAN_DEREK_4] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("DEREK"),  // ShinyGold fix: was "15TRAINER/4" (G/S phone contact #15, rematch tier 4)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokefanDerek4),
    },

    [TRAINER_FISHERMAN_CHRIS_5] = {
        .trainerClass = TRAINER_CLASS_RS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("CHRIS"),  // ShinyGold fix: was "18TRAINER/2" (G/S phone contact #18, rematch tier 2)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanChris5),
    },

    [TRAINER_PICNICKER_ERIN_4] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("ERIN"),  // ShinyGold fix: was "16TRAINER/5" (G/S phone contact #16, rematch tier 5)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerErin4),
    },

    [TRAINER_HIKER_ANTHONY_2] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("ANTHONY"),  // ShinyGold fix: was " 5TRAINER/2" (G/S phone contact #5, rematch tier 2)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerAnthony2),
    },

    [TRAINER_PICNICKER_ERIN_5] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("ERIN"),  // ShinyGold fix: was "16TRAINER/4" (G/S phone contact #16, rematch tier 4)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerErin5),
    },

    [TRAINER_POKEMANIAC_BRENT_5] = {
        .trainerClass = TRAINER_CLASS_RS_POKEMANIAC,
        .encounterMusic_gender = 88,
        .trainerPic = TRAINER_PIC_POKEMANIAC,
        .trainerName = _("BRENT"),  // ShinyGold fix: was "20TRAINER/2" (G/S phone contact #20, rematch tier 2)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokemaniacBrent5),
    },

    [TRAINER_POKEFAN_DEREK_5] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 32,
        .trainerPic = TRAINER_PIC_POKEFAN_M,
        .trainerName = _("DEREK"),  // ShinyGold fix: was "15TRAINER/5" (G/S phone contact #15, rematch tier 5)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokefanDerek5),
    },

    [TRAINER_SCHOOLBOY_CHAD_2] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("CHAD"),  // ShinyGold fix: was "14TRAINER/5" (G/S phone contact #14, rematch tier 5)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SchoolboyChad2),
    },

    [TRAINER_SCHOOLBOY_CHAD_3] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("CHAD"),  // ShinyGold fix: was "14TRAINER/4" (G/S phone contact #14, rematch tier 4)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SchoolboyChad3),
    },

    [TRAINER_SCHOOLBOY_CHAD_4] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("CHAD"),  // ShinyGold fix: was "14TRAINER/3" (G/S phone contact #14, rematch tier 3)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SchoolboyChad4),
    },

    [TRAINER_LASS_DANA_4] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 20,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("DANA"),  // ShinyGold fix: was "13TRAINER/5" (G/S phone contact #13, rematch tier 5)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassDana4),
    },

    [TRAINER_JUGGLER_IRWIN_2] = {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = 102,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("IRWIN"),  // ShinyGold fix: was " 8TRAINER/2" (G/S phone contact #8, rematch tier 2)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_JugglerIrwin2),
    },

    [TRAINER_SCHOOLBOY_CHAD_5] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("CHAD"),  // ShinyGold fix: was "14TRAINER/2" (G/S phone contact #14, rematch tier 2)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SchoolboyChad5),
    },

    [TRAINER_LASS_DANA_5] = {
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = 85,
        .trainerPic = TRAINER_PIC_BUG_MANIAC,
        .trainerName = _("DANA"),  // ShinyGold fix: was "13TRAINER/4" (G/S phone contact #13, rematch tier 4)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_LassDana5),
    },

    [TRAINER_COOLTRAINER_GAVEN_4] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("GAVEN"),  // ShinyGold fix: was "27TRAINER/2" (G/S phone contact #27, rematch tier 2)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerGaven4),
    },

    [TRAINER_COOLTRAINER_GAVEN_5] = {
        .trainerClass = TRAINER_CLASS_COOLTRAINER,
        .encounterMusic_gender = 110,
        .trainerPic = TRAINER_PIC_COOLTRAINER_M,
        .trainerName = _("GAVEN"),  // ShinyGold fix: was "27TRAINER/3" (G/S phone contact #27, rematch tier 3)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CooltrainerGaven5),
    },

    [TRAINER_SCHOOLBOY_JACK_2] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JACK"),  // ShinyGold fix: was "12TRAINER/5" (G/S phone contact #12, rematch tier 5)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SchoolboyJack2),
    },

    [TRAINER_POKEFAN_BEVERLY_5] = {
        .trainerClass = TRAINER_CLASS_POKEFAN,
        .encounterMusic_gender = 33,
        .trainerPic = TRAINER_PIC_POKEFAN_F,
        .trainerName = _("BEVERLY"),  // ShinyGold fix: was "11TRAINER/5" (G/S phone contact #11, rematch tier 5)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PokefanBeverly5),
    },

    [TRAINER_SCHOOLBOY_ALAN_2] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("ALAN"),  // ShinyGold fix: was "10TRAINER/5" (G/S phone contact #10, rematch tier 5)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SchoolboyAlan2),
    },

    [TRAINER_SCHOOLBOY_ALAN_3] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 91,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("ALAN"),  // ShinyGold fix: was "10TRAINER/4" (G/S phone contact #10, rematch tier 4)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SchoolboyAlan3),
    },

    [TRAINER_SCHOOLBOY_ALAN_4] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("ALAN"),  // ShinyGold fix: was "10TRAINER/3" (G/S phone contact #10, rematch tier 3)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SchoolboyAlan4),
    },

    [TRAINER_BUG_CATCHER_ARNIE_5] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("ARNIE"),  // ShinyGold fix: was " 9TRAINER/5" (G/S phone contact #9, rematch tier 5)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcherArnie5),
    },

    [TRAINER_JUGGLER_IRWIN_3] = {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = 102,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("IRWIN"),  // ShinyGold fix: was " 8TRAINER/5" (G/S phone contact #8, rematch tier 5)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_JugglerIrwin3),
    },

    [TRAINER_JUGGLER_IRWIN_4] = {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = 105,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("IRWIN"),  // ShinyGold fix: was " 8TRAINER/4" (G/S phone contact #8, rematch tier 4)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_JugglerIrwin4),
    },

    [TRAINER_JUGGLER_IRWIN_5] = {
        .trainerClass = TRAINER_CLASS_JUGGLER,
        .encounterMusic_gender = 98,
        .trainerPic = TRAINER_PIC_JUGGLER,
        .trainerName = _("IRWIN"),  // ShinyGold fix: was " 8TRAINER/3" (G/S phone contact #8, rematch tier 3)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_JugglerIrwin5),
    },

    [TRAINER_SCHOOLBOY_ALAN_5] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("ALAN"),  // ShinyGold fix: was "10TRAINER/2" (G/S phone contact #10, rematch tier 2)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SchoolboyAlan5),
    },

    [TRAINER_PICNICKER_GINA_5] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("GINA"),  // ShinyGold fix: was " 7TRAINER/5" (G/S phone contact #7, rematch tier 5)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerGina5),
    },

    [TRAINER_SCHOOLBOY_JACK_3] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JACK"),  // ShinyGold fix: was "12TRAINER/2" (G/S phone contact #12, rematch tier 2)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SchoolboyJack3),
    },

    [TRAINER_SCHOOLBOY_JACK_4] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JACK"),  // ShinyGold fix: was "12TRAINER/3" (G/S phone contact #12, rematch tier 3)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SchoolboyJack4),
    },

    [TRAINER_SCHOOLBOY_JACK_5] = {
        .trainerClass = TRAINER_CLASS_RS_TUBER_M, // "SCHOOLBOY"
        .encounterMusic_gender = 29,
        .trainerPic = TRAINER_PIC_SCHOOL_KID_M,
        .trainerName = _("JACK"),  // ShinyGold fix: was "12TRAINER/4" (G/S phone contact #12, rematch tier 4)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_SchoolboyJack5),
    },

    [TRAINER_CAMPER_TODD_2] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("TODD"),  // ShinyGold fix: was " 6TRAINER/5" (G/S phone contact #6, rematch tier 5)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_CamperTodd2),
    },

    [TRAINER_CAMPER_TODD_3] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_INTENSE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("TODD"),  // ShinyGold fix: was " 6TRAINER/4" (G/S phone contact #6, rematch tier 4)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_CamperTodd3),
    },

    [TRAINER_CAMPER_TODD_4] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_GIRL,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("TODD"),  // ShinyGold fix: was " 6TRAINER/3" (G/S phone contact #6, rematch tier 3)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_CamperTodd4),
    },

    [TRAINER_CAMPER_TODD_5] = {
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = 86,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("TODD"),  // ShinyGold fix: was " 6TRAINER/2" (G/S phone contact #6, rematch tier 2)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_CamperTodd5),
    },

    [TRAINER_HIKER_ANTHONY_3] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("ANTHONY"),  // ShinyGold fix: was " 5TRAINER/5" (G/S phone contact #5, rematch tier 5)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerAnthony3),
    },

    [TRAINER_HIKER_ANTHONY_4] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("ANTHONY"),  // ShinyGold fix: was " 5TRAINER/4" (G/S phone contact #5, rematch tier 4)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerAnthony4),
    },

    [TRAINER_HIKER_ANTHONY_5] = {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = 90,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("ANTHONY"),  // ShinyGold fix: was " 5TRAINER/3" (G/S phone contact #5, rematch tier 3)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_HikerAnthony5),
    },

    [TRAINER_PICNICKER_LIZ_3] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("LIZ"),  // ShinyGold fix: was " 4TRAINER/5" (G/S phone contact #4, rematch tier 5)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerLiz3),
    },

    [TRAINER_BUG_CATCHER_WADE_2] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("WADE"),  // ShinyGold fix: was " 2TRAINER/2" (G/S phone contact #2, rematch tier 2)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcherWade2),
    },

    [TRAINER_BUG_CATCHER_WADE_3] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("WADE"),  // ShinyGold fix: was " 2TRAINER/3" (G/S phone contact #2, rematch tier 3)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcherWade3),
    },

    [TRAINER_PICNICKER_LIZ_4] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 99,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("LIZ"),  // ShinyGold fix: was " 4TRAINER/4" (G/S phone contact #4, rematch tier 4)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerLiz4),
    },

    [TRAINER_FISHERMAN_WILTON_5] = {
        .trainerClass = TRAINER_CLASS_RS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("WILTON"),  // ShinyGold fix: was "21TRAINER/2" (G/S phone contact #21, rematch tier 2)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanWilton5),
    },

    [TRAINER_PICNICKER_TIFFANY_4] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("TIFFANY"),  // ShinyGold fix: was "19TRAINER/2" (G/S phone contact #19, rematch tier 2)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerTiffany4),
    },

    [TRAINER_PICNICKER_TIFFANY_5] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 87,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("TIFFANY"),  // ShinyGold fix: was "19TRAINER/3" (G/S phone contact #19, rematch tier 3)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerTiffany5),
    },

    [TRAINER_PICNICKER_LIZ_5] = {
        .trainerClass = TRAINER_CLASS_PICNICKER,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_PICNICKER,
        .trainerName = _("LIZ"),  // ShinyGold fix: was " 4TRAINER/3" (G/S phone contact #4, rematch tier 3)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_PicnickerLiz5),
    },

    [TRAINER_FISHERMAN_RALPH_5] = {
        .trainerClass = TRAINER_CLASS_FISHERMAN,
        .encounterMusic_gender = 94,
        .trainerPic = TRAINER_PIC_FISHERMAN,
        .trainerName = _("RALPH"),  // ShinyGold fix: was " 3TRAINER/5" (G/S phone contact #3, rematch tier 5)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_FishermanRalph5),
    },

    [TRAINER_BUG_CATCHER_WADE_4] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("WADE"),  // ShinyGold fix: was " 2TRAINER/5" (G/S phone contact #2, rematch tier 5)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcherWade4),
    },

    [TRAINER_BUG_CATCHER_WADE_5] = {
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = 83,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("WADE"),  // ShinyGold fix: was " 2TRAINER/4" (G/S phone contact #2, rematch tier 4)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BugCatcherWade5),
    },

    [TRAINER_BIRD_KEEPER_JOSE_4] = {
        .trainerClass = TRAINER_CLASS_BIRD_KEEPER,
        .encounterMusic_gender = 104,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("JOSE"),  // ShinyGold fix: was "26TRAINER/2" (G/S phone contact #26, rematch tier 2)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = NO_ITEM_DEFAULT_MOVES(sParty_BirdKeeperJose4),
    },

    [TRAINER_COOLTRAINER_BETH_2] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("BETH"),  // ShinyGold fix: was "25TRAINER/2" (G/S phone contact #25, rematch tier 2)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_CooltrainerBeth2),
    },

    [TRAINER_COOLTRAINER_BETH_3] = {
        .trainerClass = TRAINER_CLASS_RS_COOLTRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_TWINS,
        .trainerPic = TRAINER_PIC_RS_COOLTRAINER_F,
        .trainerName = _("BETH"),  // ShinyGold fix: was "25TRAINER/3" (G/S phone contact #25, rematch tier 3)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_CooltrainerBeth3),
    },

    [TRAINER_YOUNGSTER_JOEY_6] = {
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = 82,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("JOEY"),  // ShinyGold fix: was " 1TRAINER/5" (G/S phone contact #1, rematch tier 5)
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE,
        .party = ITEM_DEFAULT_MOVES(sParty_YoungsterJoey6),
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
