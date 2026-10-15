import sys,struct
sys.path.insert(0,'/home/claude/sgx')
from core import *
from names import species,item
H=Rom(); V=Rom(VANILLA_ROM)
A=vanilla_addr('sInGameTrades')
def tr(R,i):
    o=A+60*i
    return dict(nick=decode_text(R,o,11)[0], species=species(R.u16(o+12)), ivs=list(R.d[o+14:o+20]), ability=R.u8(o+20),
        otId=R.u32(o+24), cond=list(R.d[o+28:o+33]), pers=hex(R.u32(o+36)), item=item(R.u16(o+40)), mail=R.u8(o+42),
        otName=decode_text(R,o+43,11)[0], otGender=R.u8(o+54), sheen=R.u8(o+55), req=species(R.u16(o+56)), raw=R.d[o:o+60].hex())
for i in range(9):
    h=tr(H,i); v=tr(V,i)
    if h!=v:
        print(i, {k:(v[k],h[k]) for k in h if h[k]!=v[k] and k!='raw'})
        print('   v',v['raw']); print('   h',h['raw'])
