import sys, bisect
sys.path.insert(0,'/home/claude/sgx')
from core import *
v=open('/home/claude/work/vanilla_fr10.gba','rb').read()
h=open('/home/claude/work/shinygold_patched.gba','rb').read()
by,rng=vanilla_symbols()
starts=[r[0] for r in rng]
lo,hi=int(sys.argv[1],16),int(sys.argv[2],16)
res={}
for a in range(lo,hi):
    if v[a]!=h[a]:
        i=bisect.bisect_right(starts,a)-1
        s=rng[i]
        key=(s[0],s[2],s[1])
        res.setdefault(key,[0,a])
        res[key][0]+=1
for (a,n,sz),(c,first) in sorted(res.items()):
    inside = a+sz>first
    print('%07x %-50s size=%x changed=%d first=%x %s'%(a,n,sz,c,first,'' if inside else 'BEYOND'))
