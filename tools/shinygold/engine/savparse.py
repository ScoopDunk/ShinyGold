import struct,sys
LAYOUT=[(0,0xf24)]+[(i*0xff0, min(0x3d68-i*0xff0,0xff0)) for i in range(4)]+[(i*0xff0, min(0x83d0-i*0xff0,0xff0)) for i in range(9)]
def checksum(b):
    s=0
    for i in range(len(b)//4): s=(s+struct.unpack_from('<I',b,4*i)[0])&0xffffffff
    return ((s>>16)+s)&0xffff
def slots(sav):
    res={}
    for phys in range(28):
        sec=sav[phys*0x1000:(phys+1)*0x1000]
        sid,cs,sig,cnt=struct.unpack_from('<HHII',sec,0xff4)
        if sig!=0x08012025: continue
        ok = sid<14 and checksum(sec[:LAYOUT[sid][1]])==cs
        res.setdefault(phys//14,{})[sid]=(sec,cnt,ok)
    return res
def ext_from_slot(slot):
    out=b''
    for sid,size in ((0,0xcc),(4,0x258),(13,0xba0)):
        sec=slot[sid][0]; out+=sec[0xff0-size:0xff0]
    return out
def latest(sav):
    s=slots(sav)
    best=max(s.items(), key=lambda kv: max(v[1] for v in kv[1].values()))
    return best[1]
if __name__=='__main__':
    sav=open(sys.argv[1],'rb').read()
    for k,v in slots(sav).items():
        print('slot',k,'sectors',len(v),'counters',set(x[1] for x in v.values()),'all checksums ok',all(x[2] for x in v.values()))
    ext=ext_from_slot(latest(sav))
    if len(sys.argv)>2:
        ref=open(sys.argv[2],'rb').read()
        print('ext equals ref:', ext==ref, 'len', len(ext), len(ref))
        if ext!=ref:
            print([hex(i) for i in range(len(ext)) if ext[i]!=ref[i]][:20])
