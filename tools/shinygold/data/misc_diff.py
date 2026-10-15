import sys,struct
sys.path.insert(0,'/home/claude/sgx')
from core import *
from names import species, item, move
H=Rom(); V=Rom(VANILLA_ROM)
A=vanilla_addr('gSpeciesInfo')
fields=['hp','atk','def','spe','spa','spd','t1','t2','catch','exp','evs','i1','i2','gender','egg','fr','grow','eg1','eg2','ab1','ab2','safari','color']
def si(R,i):
    o=A+28*i
    v=struct.unpack_from('<6B2BBBH2HBBBBBBBBBB2x',R.d,o)
    return dict(zip(fields,v))
for i in range(412):
    h=si(H,i); v=si(V,i)
    if h!=v: print('SPECIESINFO',species(i), {k:(v[k],h[k]) for k in h if h[k]!=v[k]})
A=vanilla_addr('gEvolutionTable')
for i in range(412):
    def ev(R):
        return [struct.unpack_from('<HHH2x',R.d,A+40*i+8*j) for j in range(5)]
    h=ev(H); v=ev(V)
    if h!=v: print('EVO',species(i),'\n   van',[x for x in v if x[0]],'\n   hack',[x for x in h if x[0]])
A=vanilla_addr('gTrainerClassNames')
for i in range(107):
    h=decode_text(H,A+13*i)[0]; v=decode_text(V,A+13*i)[0]
    if H.d[A+13*i:A+13*i+13]!=V.d[A+13*i:A+13*i+13]: print('CLASS',i,repr(v),'->',repr(h), H.d[A+13*i:A+13*i+13].hex())
A=vanilla_addr('gTrainerMoneyTable')
for i in range(105):
    if H.d[A+4*i:A+4*i+4]!=V.d[A+4*i:A+4*i+4]: print('MONEY',i,V.d[A+4*i:A+4*i+4].hex(),'->',H.d[A+4*i:A+4*i+4].hex())
A=vanilla_addr('sTMHMMoves')
for i in range(58):
    h=H.u16(A+2*i); v=V.u16(A+2*i)
    if h!=v: print('TM%02d'%(i+1) if i<50 else 'HM%02d'%(i-49), move(v),'->',move(h))
