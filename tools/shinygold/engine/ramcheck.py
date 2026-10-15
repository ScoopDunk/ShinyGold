import subprocess,sys
def syms(elf):
    out=subprocess.run(['arm-none-eabi-nm','-S',elf],capture_output=True,text=True).stdout
    d={}
    for l in out.splitlines():
        p=l.split()
        if len(p)<3: continue
        a=int(p[0],16)
        if 0x02000000<=a<0x03008000:
            d.setdefault(p[-1],set()).add(a)
    return d
v=syms('/home/claude/vanilla/pokefirered.elf'); n=syms(sys.argv[1] if len(sys.argv)>1 else '/home/claude/wt/engine/pokefirered.elf')
bad=0
for k in v:
    if k in n and v[k]!=n[k] and k not in ('gHeap',):
        # static names may repeat
        print('MOVED',k,[hex(x) for x in v[k]],[hex(x) for x in n[k]]); bad+=1
    elif k not in n:
        print('MISSING',k,[hex(x) for x in v[k]])
new=[k for k in n if k not in v]
for k in new: print('NEW',k,[hex(x) for x in n[k]])
print('moved:',bad)
