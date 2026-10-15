#!/usr/bin/env python3
# dis.py [-v] ADDR LEN  : thumb disassembly of hack ROM (or vanilla with -v), annotating addresses with vanilla symbols
import sys,subprocess,bisect,re,struct,tempfile,os
rompath='/home/claude/work/shinygold_patched.gba'
args=sys.argv[1:]
arm=False
if args and args[0]=='-v': rompath='/home/claude/work/vanilla_fr10.gba'; args=args[1:]
if args and args[0]=='-a': arm=True; args=args[1:]
addr=int(args[0],16)&0x1FFFFFE; ln=int(args[1],0)
syms=[]
for line in open('/home/claude/work/vanilla_syms.txt'):
    p=line.split(); syms.append((int(p[0],16),p[-1],int(p[1],16) if len(p)==4 else 0))
syms.sort(); A=[s[0] for s in syms]
def name(v):
    if not (0x02000000<=v<0x0A000000): return None
    i=bisect.bisect_right(A,v)-1
    if i<0: return None
    a,n,s=syms[i]
    if v==a: return n
    if v-a < max(s,1) or (v-a<0x40 and s==0): return '%s+0x%x'%(n,v-a)
    return None
d=open(rompath,'rb').read()
tf=tempfile.NamedTemporaryFile(suffix='.bin',delete=False); tf.write(d[addr:addr+ln]); tf.close()
cmd=['arm-none-eabi-objdump','-D','-b','binary','-marm']+([] if arm else ['-Mforce-thumb'])+['--adjust-vma=0x%x'%(0x08000000+addr),tf.name]
out=subprocess.run(cmd,capture_output=True,text=True).stdout; os.unlink(tf.name)
for line in out.splitlines()[7:]:
    m=re.search(r'0x([0-9a-f]{7,8})',line)
    ann=''
    for h in re.findall(r'\b([0-9a-f]{8})\b',line):
        v=int(h,16); n=name(v) or name(v&~1)
        if n and 0x08000000<=v: ann+=' <%s>'%n
        elif n: ann+=' <%s>'%n
    m2=re.search(r';\s*\(0x([0-9a-f]+)\)',line) or re.search(r'; \(([0-9a-f]+)',line)
    # literal pool value
    mm=re.search(r'ldr\s+r\d+, \[pc, #\d+\]\s+@ \(0x([0-9a-f]+)\)',line) or re.search(r'@ \(0x([0-9a-f]+)\)',line)
    if mm:
        la=int(mm.group(1),16)-0x08000000
        if 0<=la<len(d)-4:
            val=struct.unpack_from('<I',d,la)[0]
            n=name(val) or name(val&~1)
            ann+='  =0x%08x%s'%(val,(' <'+n+'>') if n else '')
    print(line+ann)
