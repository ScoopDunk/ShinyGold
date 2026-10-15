import sys,struct
sys.path.insert(0,'/home/claude/sgx')
from core import *
H=Rom(); V=Rom(VANILLA_ROM)
A=vanilla_addr('gItems')
def item(R,i):
    o=A+44*i
    d=dict(name=decode_text(R,o,14)[0], id=R.u16(o+14), price=R.u16(o+16), he=R.u8(o+18), hep=R.u8(o+19),
           desc=R.u32(o+20), imp=R.u8(o+24), reg=R.u8(o+25), pocket=R.u8(o+26), type=R.u8(o+27), fuf=R.u32(o+28),
           bu=R.u32(o+32), buf=R.u32(o+36), sec=R.u32(o+40))
    d['desctext']=decode_text(R,d['desc']-0x8000000)[0]
    d['descsym']=vanilla_name_at(d['desc']-0x8000000)
    return d
for i in range(375):
    h=item(H,i); v=item(V,i)
    if h!=v:
        print(i, reverse_constants('ITEM_',file='items.h').get(i))
        for k in h:
            if h[k]!=v[k]: print('   %s: %r -> %r'%(k, v[k], h[k]))
    # check raw bytes of name beyond terminator
    o=A+44*i
    if H.d[o:o+14]!=V.d[o:o+14] and h['name']==v['name']: print('  name raw differs', i)
