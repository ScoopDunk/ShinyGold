"""Compare warp destinations (map warps and script warps) of <tree> against <base tree>. usage: warpcheck.py <base> <tree>"""
import json,glob,re,sys
base,tree=sys.argv[1],sys.argv[2]
def load(t):
    maps={}
    for p in glob.glob(t+'/data/maps/*/map.json'):
        j=json.load(open(p)); maps[j['id']]=j
    return maps
M=load(base); G=load(tree)
def ival(s):
    try: return int(s,0)
    except: return None
def dest(maps,dm,i):
    d=maps.get(dm)
    if d is None: return ('gone',dm)
    if i is None: return (dm,'sym')
    ws=d.get('warp_events') or []
    if not(0<=i<len(ws)): return (dm,'none',i)
    return (dm,ws[i]['x'],ws[i]['y'])
bad=0
for mid,j in G.items():
    if mid not in M: continue
    old=M[mid].get('warp_events') or []; new=j.get('warp_events') or []
    oi={(w['x'],w['y'],w['dest_map']):w for w in old}
    for w in new:
        ow=oi.get((w['x'],w['y'],w['dest_map']))
        if ow is None: continue
        a=dest(M,ow['dest_map'],ival(ow['dest_warp_id'])); b=dest(G,w['dest_map'],ival(w['dest_warp_id']))
        if a!=b and a[0]!='gone': print('MAPWARP',j['name'],(w['x'],w['y']),'base',a,'now',b); bad+=1
pat=re.compile(r'^\s*(warp\w*|setwarp|setdynamicwarp|setescapewarp|setdivewarp|setholewarp)\s+(MAP_\w+),\s*([^,\n@]+)')
def swarps(t,maps):
    out={}
    for f in glob.glob(t+'/data/**/*.inc',recursive=True)+[t+'/data/event_scripts.s']:
        rel=f[len(t)+1:]; cur=None; n=0
        for l in open(f,errors='replace'):
            m=re.match(r'^(\w+)::',l)
            if m: cur=m.group(1); n=0
            m=pat.match(l)
            if m and l.split('@')[0].count(',')!=2:
                wid=ival(m.group(3).strip())
                if wid is None: continue
                out[(cur,n)]=(rel,l.strip(),dest(maps,m.group(2),wid)); n+=1
    return out
a=swarps(base,M); b=swarps(tree,G)
for k,v in b.items():
    if k in a and a[k][2]!=v[2] and a[k][2][0]!='gone': print('SCRIPTWARP',k,v[0],v[1],'base',a[k][2],'now',v[2]); bad+=1
for k,v in b.items():
    if v[2][0]=='gone' or v[2][1]=='none': print('DANGLING',k,v[0],v[1],v[2])
print(bad,'mismatches')
