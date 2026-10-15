import sys,re,os,subprocess,collections
sys.path.insert(0,'/home/claude/sgx')
from names import trainer_const
van={}
for l in open('/home/claude/vanilla/include/constants/opponents.h'):
    m=re.match(r'#define\s+(TRAINER_\w+)\s+(\d+)',l)
    if m: van[m.group(1)]=int(m.group(2))
vrev={v:k for k,v in van.items() if k.startswith('TRAINER_') and k not in('NUM_TRAINERS',)}
new={i:trainer_const(i) for i in range(743)}
newset={v:k for k,v in new.items()}
print(len(van), len(set(new.values())))
# vanilla names referenced outside opponents.h
out=subprocess.run(['grep','-rhoE',r'\bTRAINER_[A-Z0-9_]+\b','src','include','data','asm','--include=*.c','--include=*.h','--include=*.inc','--include=*.s','--include=*.json','--include=*.pory'],cwd='/home/claude/vanilla',capture_output=True,text=True).stdout.split()
refs=collections.Counter(out)
used=[n for n in van if n in refs and n not in ('NUM_TRAINERS','MAX_TRAINERS_COUNT')]
print('vanilla names referenced:',len(used))
conf=[(n,van[n],newset[n]) for n in van if n in newset and newset[n]!=van[n]]
print('conflicts',conf)
same=[n for n in van if n in newset and newset[n]==van[n]]
print('same',len(same),same[:20])
