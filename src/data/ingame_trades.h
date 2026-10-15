static const struct InGameTrade sInGameTrades[] = {
    [INGAME_TRADE_MR_MIME] = 
    {
        // ShinyGold: trade rewritten by the hack
        .nickname = _("ROCKY"),
        .species = SPECIES_ONIX,
        .ivs = {20, 15, 17, 24, 23, 22},
        .abilityNum = 0,
        .otId = 1985,
        .conditions = {5, 5, 5, 30, 5},
        .personality = 0x00009cae,
        .heldItem = ITEM_PERSIM_BERRY,
        .mailNum = 255,
        .otName = _("KYLE"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_BELLSPROUT
    }, 
    [INGAME_TRADE_JYNX] = 
    {
        // ShinyGold: trade rewritten by the hack
        .nickname = _("MUSCLE"),
        .species = SPECIES_MACHOP,
        .ivs = {18, 17, 18, 22, 25, 21},
        .abilityNum = 0,
        .otId = 36728,
        .conditions = {5, 30, 5, 5, 5},
        .personality = 0x498a2e1d,
        .heldItem = ITEM_SITRUS_BERRY,
        .mailNum = 0,
        .otName = _("MIKE"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_DROWZEE
    }, 
    [INGAME_TRADE_NIDORAN] = 
    {
#if defined(FIRERED)
        .nickname = _("MS. NIDO"),
        .species = SPECIES_NIDORAN_F,
        .ivs = {22, 18, 25, 19, 15, 22},
        .abilityNum = 0,
        .otId = 63184,
        .conditions = {5, 5, 5, 5, 30},
        .personality = 0x4c970b89,
        .heldItem = ITEM_TINY_MUSHROOM,
        .mailNum = 255,
        .otName = _("SAIGE"),
        .otGender = FEMALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_NIDORAN_M
#elif defined(LEAFGREEN)
        .nickname = _("MR. NIDO"),
        .species = SPECIES_NIDORAN_M,
        .ivs = {19, 25, 18, 22, 22, 15},
        .abilityNum = 0,
        .otId = 63184,
        .conditions = {30, 5, 5, 5, 5},
        .personality = 0x4c970b9e,
        .heldItem = ITEM_TINY_MUSHROOM,
        .mailNum = 255,
        .otName = _("SAIGE"),
        .otGender = FEMALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_NIDORAN_F
#endif
    }, 
    [INGAME_TRADE_FARFETCHD] = 
    {
        // ShinyGold: trade rewritten by the hack
        .nickname = _("VOLTY"),
        .species = SPECIES_VOLTORB,
        .ivs = {20, 25, 21, 24, 15, 20},
        .abilityNum = 0,
        .otId = 8810,
        .conditions = {30, 5, 5, 5, 5},
        .personality = 0x151943d7,
        .heldItem = ITEM_CHERI_BERRY,
        .mailNum = 255,
        .otName = _("TIM"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_KRABBY
    }, 
    [INGAME_TRADE_NIDORINOA] = 
    {
        // ShinyGold: trade rewritten by the hack
        .nickname = _("AEROY"),
        .species = SPECIES_AERODACTYL,
        .ivs = {22, 25, 18, 19, 22, 15},
        .abilityNum = 0,
        .otId = 13637,
        .conditions = {5, 5, 30, 5, 5},
        .personality = 0x00eeca15,
        .heldItem = ITEM_SITRUS_BERRY,
        .mailNum = 255,
        .otName = _("KIM"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_CHANSEY
    }, 
    [INGAME_TRADE_LICKITUNG] = 
    {
        // ShinyGold: trade rewritten by the hack
        .nickname = _("DON"),
        .species = SPECIES_RHYDON,
        .ivs = {24, 19, 21, 15, 23, 21},
        .abilityNum = 0,
        .otId = 1239,
        .conditions = {5, 5, 5, 5, 30},
        .personality = 0x451308ab,
        .heldItem = ITEM_PERSIM_BERRY,
        .mailNum = 255,
        .otName = _("EMY"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_DRAGONAIR
    }, 
    [INGAME_TRADE_ELECTRODE] = 
    {
        .nickname = _("ESPHERE"),
        .species = SPECIES_ELECTRODE,
        .ivs = {19, 16, 18, 25, 25, 19},
        .abilityNum = 1,
        .otId = 50298,
        .conditions = {30, 5, 5, 5, 5},
        .personality = 0x06341016,
        .heldItem = ITEM_NONE,
        .mailNum = 255,
        .otName = _("CLIFTON"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_RAICHU
    }, 
    [INGAME_TRADE_TANGELA] = 
    {
        .nickname = _("TANGENY"),
        .species = SPECIES_TANGELA,
        .ivs = {22, 17, 25, 16, 23, 20},
        .abilityNum = 0,
        .otId = 60042,
        .conditions = {5, 5, 30, 5, 5},
        .personality = 0x5c77ecfa,
        .heldItem = ITEM_STARDUST,
        .mailNum = 255,
        .otName = _("NORMA"),
        .otGender = FEMALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_VENONAT
    },
    [INGAME_TRADE_SEEL] = 
    {
        .nickname = _("SEELOR"),
        .species = SPECIES_SEEL,
        .ivs = {24, 15, 22, 16, 23, 22},
        .abilityNum = 0,
        .otId = 9853,
        .conditions = {5, 5, 5, 5, 30},
        .personality = 0x482cac89,
        .heldItem = ITEM_NONE,
        .mailNum = 255,
        .otName = _("GARETT"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_PONYTA
    }
};

static const u16 sInGameTradeMailMessages[][10] = {
    {
        EC_WORD_THAT_S,
        EC_WORD_A,
        EC_WORD_HEALTHY,
        EC_POKEMON(JYNX),
        EC_WORD_EXCL,
        EC_WORD_BE,
        EC_WORD_KIND,
        EC_WORD_TO,
        EC_WORD_IT
    }
};
