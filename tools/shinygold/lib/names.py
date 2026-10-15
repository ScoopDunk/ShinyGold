"""Shared constant-naming contract for all ShinyGold extraction workers.

Every worker that emits a constant for one of these value kinds MUST use these functions so that
independently produced files agree.  Functions return a string usable in pokefirered asm / C / JSON.
"""
import json, re, os, functools, glob, subprocess, sys
sys.path.insert(0, '/home/claude/sgx')
from core import *

MAP_NAMES_JSON = '/home/claude/work/map_names.json'


@functools.lru_cache(None)
def _consts():
    return c_constants()[0]


@functools.lru_cache(None)
def _rev(prefix, file=None):
    def excl(n):
        return n.endswith('_COUNT') or n.endswith('_START') or n.endswith('_END') or n.startswith(prefix + 'NUM_')
    return reverse_constants(prefix, file=file, exclude=excl)


@functools.lru_cache(None)
def _engine_refs():
    """FLAG_/VAR_ names referenced by engine code (src/, non-constant headers, asm macros, shared scripts)."""
    out = set()
    roots = [os.path.join(VANILLA_DIR, 'src'), os.path.join(VANILLA_DIR, 'include')]
    for r in roots:
        for dp, dn, fn in os.walk(r):
            if dp.endswith('include/constants'): continue
            for f in fn:
                if f.endswith(('.c', '.h')):
                    s = open(os.path.join(dp, f), errors='replace').read()
                    out.update(re.findall(r'\b(?:FLAG|VAR)_[A-Z0-9_]+', s))
    return out


def _engine_name(v, prefix, generic_re):
    rev = {}
    vals = _consts()
    eng = _engine_refs()
    best = None
    for n, val in vals.items():
        if val != v or not n.startswith(prefix): continue
        if n.endswith('_START') or n.endswith('_END') or n.endswith('_COUNT'): continue
        if re.match(generic_re, n) or n in eng:
            if best is None or len(n) < len(best): best = n
    return best


@functools.lru_cache(None)
def flag_name(v):
    if v == 0: return '0'
    n = _engine_name(v, 'FLAG_', r'^FLAG_(TEMP_|SYS_|BADGE|HIDE_MAP_NAME_POPUP|DONT_|SPECIAL_FLAG)')
    return n if n else '0x%03X' % v


@functools.lru_cache(None)
def var_name(v):
    vals = _consts()
    for n in ['VAR_RESULT', 'VAR_FACING', 'VAR_ITEM_ID', 'VAR_LAST_TALKED', 'VAR_MON_BOX_ID', 'VAR_MON_BOX_POS',
              'VAR_TEXT_COLOR', 'VAR_PREV_TEXT_COLOR']:
        if vals.get(n) == v: return n
    if 0x8000 <= v <= 0x8014:
        nm = 'VAR_0x%04X' % v
        if nm in vals: return nm
    n = _engine_name(v, 'VAR_', r'^VAR_(TEMP_|OBJ_GFX_ID_|0x)')
    return n if n else '0x%04X' % v


def value_or_var(v):
    """For setorcopyvar/compare-style args that may be a var id or a literal value."""
    if 0x4000 <= v <= 0x40FF or 0x8000 <= v <= 0x8014:
        return var_name(v)
    return '0x%X' % v if v > 9 else str(v)


# ----------------------------------------------------------------- maps / layouts / mapsecs
@functools.lru_cache(None)
def _map_names():
    return json.load(open(MAP_NAMES_JSON))


def map_const(group, num):
    e = _map_names().get('%d.%d' % (group, num))
    if e: return e['id']
    if group == 0x7F and num == 0x7F: return 'MAP_DYNAMIC'
    if group == 0xFF and num == 0xFF: return 'MAP_UNDEFINED'
    return '((%d << 8) | %d)' % (group, num)


def map_name(group, num):
    e = _map_names().get('%d.%d' % (group, num))
    return e['name'] if e else None


@functools.lru_cache(None)
def _layout_names():
    """layout id -> (Name_Layout label, LAYOUT_ const) ; name taken from first map (group/num order) using it."""
    sys.path.insert(0, '/home/claude/sgx')
    from maps import load_map_headers, load_layouts
    r = Rom()
    groups, maps = load_map_headers(r)
    maxid = max(m.layout_id for m in maps)
    T, lays = load_layouts(Rom(), maxid)
    first = {}
    for m in maps:
        first.setdefault(m.layout_id, (m.group, m.num))
    out = {}
    for lid in range(1, maxid + 1):
        if lid in first:
            nm = map_name(*first[lid])
        elif lays.get(lid) is not None:
            nm = 'Unused_Layout%d' % lid
        else:
            continue
        cid = 'LAYOUT_' + re.sub(r'([A-Z])([A-Z][a-z])', r'\1_\2', re.sub(r'([a-z])([A-Z])', r'\1_\2', nm)).upper().replace('__', '_')
        out[lid] = (nm + '_Layout', cid, nm)
    return out


def layout_const(lid):
    e = _layout_names().get(lid)
    return e[1] if e else str(lid)


def layout_dirname(lid):
    e = _layout_names().get(lid)
    return e[2] if e else None


@functools.lru_cache(None)
def _mapsec_names():
    sys.path.insert(0, '/home/claude/sgx')
    from maps import mapsec_names
    return mapsec_names(Rom())


@functools.lru_cache(None)
def _mapsec_table():
    """value -> MAPSEC_ const. Values < 0x58 and >= 0xC5 keep vanilla names; 0x58..0xC4 named after the hack's names."""
    van = {}
    j = json.load(open(os.path.join(VANILLA_DIR, 'src/data/region_map/region_map_sections.json')))
    for i, e in enumerate(j['map_sections']):
        van[i] = e['id']
    names = _mapsec_names()
    out = {}
    used = {}
    for v in range(len(van)):
        if 0x58 <= v < 0xC5 and names.get(v):
            s = names[v].replace('’', '').replace("'", '').replace('.', ' ').replace('é', 'E').replace('É', 'E')
            base = 'MAPSEC_' + '_'.join(re.findall(r'[A-Za-z0-9]+', s)).upper()
            nm = base
            k = 2
            while nm in used.values() or nm in van.values() and nm != van[v]:
                nm = '%s_%d' % (base, k); k += 1
            out[v] = nm
        else:
            out[v] = van[v]
        used[v] = out[v]
    out[len(van)] = 'MAPSEC_NONE'
    return out


def mapsec_const(v):
    return _mapsec_table().get(v, '0x%02X' % v)


# ----------------------------------------------------------------- trainers
TRAINERS_OFF = 0x23EAC8
NUM_TRAINERS = 743
CLASS_NAMES_OFF = 0x23E558


@functools.lru_cache(None)
def _trainer_consts():
    r = Rom()
    out = {0: 'TRAINER_NONE'}
    used = {'TRAINER_NONE'}
    def ident(s):
        s = s.replace('♂', '_M').replace('♀', '_F').replace('é', 'E').replace('&', '_AND_').replace('{PKMN}', 'PKMN')
        return '_'.join(re.findall(r'[A-Za-z0-9]+', s)).upper()
    for i in range(1, NUM_TRAINERS):
        o = TRAINERS_OFF + 40 * i
        cls = r.u8(o + 1)
        cname = decode_text(r, CLASS_NAMES_OFF + 13 * cls)[0] or 'CLASS%d' % cls
        name = decode_text(r, o + 4, 12)[0] or ''
        nm = name.strip().rstrip('!')
        placeholder = (not nm) or nm in ('-EDIT-', '???') or re.match(r'^\s*\d+TRAINER/\d+$', name.strip()) is not None
        base = 'TRAINER_' + ident(cname)
        base = base + '_' + (ident(nm) if not placeholder and ident(nm) else str(i))
        c = base; k = 2
        while c in used:
            c = '%s_%d' % (base, k); k += 1
        used.add(c); out[i] = c
    return out


def trainer_const(i):
    if i == 0: return 'TRAINER_NONE'
    return _trainer_consts().get(i, str(i))


# ----------------------------------------------------------------- misc engine constants (vanilla names)
def _vanilla_or_hex(prefix, v, width=2, file=None):
    n = _rev(prefix, file).get(v)
    return n if n else ('0x%0*X' % (width, v))


def species(v): return _vanilla_or_hex('SPECIES_', v, 3, 'species.h')
def item(v): return _vanilla_or_hex('ITEM_', v, 3, 'items.h')
def move(v): return _vanilla_or_hex('MOVE_', v, 3, 'moves.h')
def obj_gfx(v): return _vanilla_or_hex('OBJ_EVENT_GFX_', v, 2, 'event_objects.h')
def movement_type(v): return _vanilla_or_hex('MOVEMENT_TYPE_', v, 2, 'event_object_movement.h')
def trainer_type(v): return _vanilla_or_hex('TRAINER_TYPE_', v, 1, 'trainer_types.h')
def weather(v): return _vanilla_or_hex('WEATHER_', v, 1, 'weather.h')
def battle_scene(v): return _vanilla_or_hex('MAP_BATTLE_SCENE_', v, 1, 'map_types.h')
def map_type(v): return _vanilla_or_hex('MAP_TYPE_', v, 1, 'map_types.h')


@functools.lru_cache(None)
def _songs():
    rev = {}
    for line in open(os.path.join(VANILLA_DIR, 'include/constants/songs.h')):
        m = re.match(r'#define\s+((?:MUS|SE)_\w+)\s+(\d+)', line)
        if m: rev.setdefault(int(m.group(2)), m.group(1))
    return rev


def song(v):
    if v == 0xFFFF: return 'MUS_NONE' if 'MUS_NONE' in _consts() else '0xFFFF'
    return _songs().get(v, str(v))


@functools.lru_cache(None)
def _vanilla_multichoice():
    rev = {}
    p = os.path.join(VANILLA_DIR, 'include/constants/menu.h')
    for line in open(p):
        m = re.match(r'#define\s+(MULTICHOICE_\w+)\s+(\d+)', line)
        if m: rev.setdefault(int(m.group(2)), m.group(1))
    return rev


def multichoice_const(v):
    n = _vanilla_multichoice().get(v)
    return n if n else 'MULTICHOICE_SG_%d' % v


def special_name(idx):
    sl = specials_list()
    return sl[idx] if idx < len(sl) else None


HEAL_TABLE = 0xA002EC   # hack's sHealLocations (repointed); 24 entries of 8 bytes, 1-based ids


@functools.lru_cache(None)
def _heal_consts():
    r = Rom()
    out = {}
    used = set()
    van = {}
    for line in open(os.path.join(VANILLA_DIR, 'include/constants/heal_locations.h')) if os.path.exists(os.path.join(VANILLA_DIR, 'include/constants/heal_locations.h')) else []:
        m = re.match(r'#define\s+(HEAL_LOCATION_\w+)\s+(\d+)', line)
        if m: van[int(m.group(2))] = m.group(1)
    for i in range(24):
        o = HEAL_TABLE + 8 * i
        g, n = r.s8(o), r.s8(o + 1)
        mc = map_const(g, n)
        base = 'HEAL_LOCATION_' + mc[4:] if mc.startswith('MAP_') else 'HEAL_LOCATION_%d' % (i + 1)
        c = base; k = 2
        while c in used: c = '%s_%d' % (base, k); k += 1
        used.add(c); out[i + 1] = c
    return out


def heal_location_const(v):
    if v == 0: return 'HEAL_LOCATION_NONE'
    return _heal_consts().get(v, str(v))
