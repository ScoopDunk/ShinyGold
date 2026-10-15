import sys, struct, re
sys.path.insert(0, '/home/claude/work/engine/tools'); sys.path.insert(0, '/home/claude/sgx')
from verify import *
from core import vanilla_addr, Rom, text_asm

H = HACK.d
V = Rom('/home/claude/work/vanilla_fr10.gba')

def va(n):
    return vanilla_addr(n) + 0x08000000

# --- title screen / intro / oak speech / naming screen / trainer card graphics
lzchecks = [
    ('gGraphics_TitleScreen_GameTitleLogoTiles', va('gGraphics_TitleScreen_GameTitleLogoTiles')),
    ('gGraphics_TitleScreen_GameTitleLogoMap', va('gGraphics_TitleScreen_GameTitleLogoMap')),
    ('gGraphics_TitleScreen_BoxArtMonTiles', va('gGraphics_TitleScreen_BoxArtMonTiles')),
    ('gGraphics_TitleScreen_BoxArtMonMap', va('gGraphics_TitleScreen_BoxArtMonMap')),
    ('gGraphics_TitleScreen_CopyrightPressStartTiles', 0x087E5400),
    ('gGraphics_TitleScreen_CopyrightPressStartMap', 0x087E57A0),
    ('sFlames_Gfx', va('sFlames_Gfx')),
    ('sCopyright_Gfx', va('sCopyright_Gfx')),
    ('sGameFreakText_Gfx', va('sGameFreakText_Gfx')),
    ('sGameFreakLogo_Gfx', va('sGameFreakLogo_Gfx')),
    ('sOakSpeech_Red_Tiles', 0x088107F0),
    ('sOakSpeech_Leaf_Tiles', va('sOakSpeech_Leaf_Tiles')),
    ('sOakSpeech_Rival_Tiles', 0x08827E70),
    ('sKantoTrainerCardBadges_Gfx', 0x08777D10),
]
for sym, hp in lzchecks:
    check('%s (decompressed) == hack %08x' % (sym, hp), lz_built(sym) == lz_hack(hp))
rawchecks = [
    ('gGraphics_TitleScreen_GameTitleLogoPals', 0x200),
    ('gGraphics_TitleScreen_BoxArtMonPals', 0x20),
    ('gGraphics_TitleScreen_BackgroundPals', 0x20),
    ('sFlames_Pal', 0x20),
    ('sOakSpeech_Red_Pal', 0x40), ('sOakSpeech_Leaf_Pal', 0x40), ('sOakSpeech_Rival_Pal', 0x40),
    ('sCopyright_Pal', 0x20), ('sGameFreakLogo_Pal', 0x20), ('sKantoTrainerCardBadges_Pal', 0x20),
    ('sRival_Gfx', 0x900),
]
for sym, n in rawchecks:
    a = vanilla_addr(sym)
    check('%s bytes == hack (in place)' % sym, built_bytes(sym, n) == H[a:a + n])

# --- oak speech / intro texts (effective text per label)
eff = {'gOakSpeech_Text_IStudyPokemon': 0x0871A3E9, 'gOakSpeech_Text_LetsGo': 0x0871A4D9,
       'gPikachuIntro_Text_Page3': 0x08737B19, 'gNameChoice_Silver': 0x086fc3ad}
labels = re.findall(r'^(\w+)::', open('/home/claude/wt/engine/data/text/new_game_intro.inc').read(), re.M)
bad = []
for l in labels:
    if l == 'gNameChoice_Green':
        continue  # dead in FireRed, see report
    hp = eff[l] if l in eff else (va(l) if vanilla_addr(l) is not None else None)
    if hp is None:
        bad.append(l); continue
    if text_built(addr(l)) != text_hack(hp):
        bad.append(l)
check('new_game_intro.inc texts == hack effective texts (%d labels)' % len(labels), not bad, str(bad))
# strings.c texts
names = [l.split()[2] for l in open('/home/claude/work/changed_syms.txt') if 0x417000 <= int(l.split()[0], 16) < 0x41a000]
bad = [n for n in names if text_built(addr(n)) != text_hack(va(n))]
check('strings.c changed texts == hack (%d)' % len(names), not bad, str(bad))
# multichoice table: same lists/texts as the hack table (0x08828514, 70 entries)
bad = []
mc = addr('sMultichoiceLists')
for i in range(70):
    bp, bc = struct.unpack_from('<IB', BUILT.d, mc - 0x08000000 + 8 * i)
    hp, hc = struct.unpack_from('<IB', H, 0x828514 + 8 * i)
    if bc != hc:
        bad.append((i, 'count')); continue
    if hp & 1:
        # hack bug: misaligned list (66-69); compare with the intended list at the odd address
        hp2 = hp
    else:
        hp2 = hp
    for k in range(bc):
        bt = struct.unpack_from('<I', BUILT.d, bp - 0x08000000 + 8 * k)[0]
        ht = struct.unpack_from('<I', H, hp2 - 0x08000000 + 8 * k)[0]
        if text_built(bt) != text_hack(ht):
            bad.append((i, k))
check('sMultichoiceLists (70 entries) texts == hack (66-69: intended lists)', not bad, str(bad[:5]))
