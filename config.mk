# Default variables

GAME_VERSION  ?= FIRERED
GAME_REVISION ?= 0
GAME_LANGUAGE ?= ENGLISH

# ShinyGold: the game must always identify as FireRed (title POKEMON FIRE, game code BPRE, gGameVersion
# VERSION_FIRE_RED) so other games, link partners, save tools and flash carts recognize it.
ifneq ($(GAME_VERSION),FIRERED)
  $(error ShinyGold only builds as FireRed: GAME_VERSION must be FIRERED, not $(GAME_VERSION))
endif

# Builds the ROM using a modern compiler
MODERN        ?= 0
# Compares the ROM to a checksum of the original - only makes sense using when non-modern
COMPARE       ?= 0

KEEP_TEMPS    ?= 0

ifeq (modern,$(MAKECMDGOALS))
  MODERN := 1
endif
ifeq (compare,$(MAKECMDGOALS))
  COMPARE := 1
endif

# For gbafix
MAKER_CODE := 01

BUILD_DIR := build

# Version
ifeq ($(GAME_VERSION),FIRERED)
  TITLE       := POKEMON FIRE
  GAME_CODE   := BPR
  BUILD_NAME  := firered
else
ifeq ($(GAME_VERSION),LEAFGREEN)
  TITLE       := POKEMON LEAF
  GAME_CODE   := BPG
  BUILD_NAME  := leafgreen
else
  $(error unknown version $(GAME_VERSION))
endif
endif

# Revision
ifeq ($(GAME_REVISION),1)
  BUILD_NAME  := $(BUILD_NAME)_rev1
endif

ifeq ($(GAME_REVISION),10)
  BUILD_NAME  := $(BUILD_NAME)_switch
endif

# Modern GCC
ifeq ($(MODERN),1)
  BUILD_NAME := $(BUILD_NAME)_modern
endif

# Language
ifeq ($(GAME_LANGUAGE),ENGLISH)
  GAME_CODE  := $(GAME_CODE)E
endif
