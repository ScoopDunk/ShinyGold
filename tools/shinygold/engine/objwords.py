import re,sys,struct,bisect
sys.path.insert(0,'/home/claude/sgx')
lines=open('/home/claude/vanilla/pokefirered.map').read().splitlines()
van=open('/home/claude/work/vanilla_fr10.gba','rb').read(); hack=open('/home/claude/work/shinygold_patched.gba','rb').read()
syms=[]
for line in open('/home/claude/work/vanilla_syms.txt'):
    p=line.split(); syms.append((int(p[0],16),p[-1]))
syms.sort(); A=[s[0] for s in syms]
def nm(a):
    i=bisect.bisect_right(A,a)-1
    if i<0: return '?'
    return '%s+0x%x'%(syms[i][1],a-syms[i][0]) if a!=syms[i][0] else syms[i][1]
want=sys.argv[1]
for l in lines:
    m=re.match(r'^ (\.text|\.rodata|\.data)\S*\s+0x([0-9a-f]+)\s+0x([0-9a-f]+)\s+(\S+)',l)
    if not m or want not in m.group(4): continue
    a,s=int(m.group(2),16),int(m.group(3),16)
    if not s or a<0x8000000: continue
    o=a-0x8000000
    for i in range(o&~3,o+s,4):
        v=struct.unpack_from('<I',van,i)[0]; h=struct.unpack_from('<I',hack,i)[0]
        if v!=h:
            print('%s %08x in %-40s van=%08x(%s) hack=%08x(%s)'%(m.group(1),0x8000000+i,nm(0x8000000+i),v,nm(v) if 0x8000000<=v<0xa000000 else '',h, nm(h) if 0x8000000<=h<0x8800000 else ''))
