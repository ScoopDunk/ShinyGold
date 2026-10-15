import sys,re,os,subprocess,collections
sys.path.insert(0,'/home/claude/sgx')
van={}
for l in open('/home/claude/vanilla/include/constants/opponents.h'):
    m=re.match(r'#define\s+(TRAINER_\w+)\s+(\d+)',l)
    if m: van[m.group(1)]=int(m.group(2))
out=subprocess.run('grep -rnoE "\\bTRAINER_[A-Z0-9_]+\\b" src include data asm --include=*.c --include=*.h --include=*.inc --include=*.s --include=*.json',shell=True,cwd='/home/claude/vanilla',capture_output=True,text=True).stdout.splitlines()
files=collections.Counter()
for l in out:
    f,ln,n=l.split(':',2)
    if n in van and f!='include/constants/opponents.h':
        files[f.split('/')[0]+'/'+f.split('/')[1] if f.startswith('data/maps') else f]+=1
print(files.most_common())
