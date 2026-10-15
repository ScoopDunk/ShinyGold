import re,sys
sys.path.insert(0,'/home/claude/sgx')
from core import vanilla_name_at
import bisect
lines=open('/home/claude/vanilla/pokefirered.map').read().splitlines()
van=open('/home/claude/work/vanilla_fr10.gba','rb').read(); hack=open('/home/claude/work/shinygold_patched.gba','rb').read()
syms=[]
for line in open('/home/claude/work/vanilla_syms.txt'):
    p=line.split(); syms.append((int(p[0],16),p[-1]))
syms.sort(); A=[s[0] for s in syms]
def nm(a):
    i=bisect.bisect_right(A,a)-1
    return '%s+0x%x'%(syms[i][1],a-syms[i][0])
for l in lines:
    m=re.match(r'^ (\.text)\S*\s+0x([0-9a-f]+)\s+0x([0-9a-f]+)\s+(\S+)',l)
    if not m: continue
    a,s,obj=int(m.group(2),16),int(m.group(3),16),m.group(4)
    if s==0 or not (0x08000000<=a<0x0A000000): continue
    o=a-0x08000000
    i=o
    while i<o+s:
        if van[i]!=hack[i]:
            j=i
            while j<o+s and (van[j]!=hack[j] or (j+1<o+s and van[j+1]!=hack[j+1]) or (j+2<o+s and van[j+2]!=hack[j+2])): j+=1
            print('%s 0x%07x-0x%07x %-45s van=%s hack=%s'%(obj,0x8000000+i,0x8000000+j,nm(0x8000000+i),van[i:j].hex(),hack[i:j].hex()))
            i=j
        else: i+=1
