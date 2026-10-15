import sys,struct,collections
sys.path.insert(0,'/home/claude/sgx')
from core import *
TR=0x23EAC8; NT=743
MONSZ={0:8,1:16,2:8,3:16}
def read_trainer(R,i):
    o=TR+40*i
    t=dict(flags=R.u8(o), cls=R.u8(o+1), music=R.u8(o+2), pic=R.u8(o+3), name_raw=R.d[o+4:o+16],
           items=[R.u16(o+16+2*k) for k in range(4)], double=R.u8(o+24), pad=R.d[o+25:o+28], ai=R.u32(o+28), size=R.u8(o+32),
           pad2=R.d[o+33:o+36], party=R.u32(o+36))
    t['name']=decode_text(R,o+4,12)[0]
    po=t['party']-0x8000000
    mons=[]
    if 0<=po<len(R.d):
        for k in range(t['size']):
            m=po+MONSZ[t['flags']&3]*k
            d=dict(iv=R.u16(m), lvl=R.u8(m+2), pad=R.u8(m+3), species=R.u16(m+4))
            p=m+6
            if t['flags']&2: d['item']=R.u16(p); p+=2
            if t['flags']&1: d['moves']=[R.u16(p+2*j) for j in range(4)]; p+=8
            if (t['flags']&3)==2: d['pad2']=R.u16(m+6) if False else None
            mons.append(d)
    t['mons']=mons
    return t
