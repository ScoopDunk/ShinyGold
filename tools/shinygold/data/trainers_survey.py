from trainers_lib import *
H=Rom(); V=Rom(VANILLA_ROM)
ht=[read_trainer(H,i) for i in range(NT)]
vt=[read_trainer(V,i) for i in range(NT)]
loc=collections.Counter()
users=collections.defaultdict(list)
for i,t in enumerate(ht):
    po=t['party']-0x8000000
    nm=vanilla_name_at(po)
    region='vanilla_party' if 0x23a000<=po<0x23eac8 else ('free>0x71a000' if po>=0x71a000 else 'other_vanilla:%s'%vanilla_name_at(po))
    loc[region if not region.startswith('other') else 'other_vanilla']+=1
    users[(t['party'],t['flags'])].append(i)
    if region.startswith('other'): print(i,hex(po),region, t['size'])
print(loc)
shared=[(hex(k[0]),v) for k,v in users.items() if len(v)>1]
print('shared',len(shared),shared[:30])
print('flags',collections.Counter(t['flags'] for t in ht))
print('sizes',collections.Counter(t['size'] for t in ht))
print('pads',collections.Counter((t['pad'].hex(),t['pad2'].hex()) for t in ht))
print('monpads',collections.Counter(m['pad'] for t in ht for m in t['mons']))
print('double',collections.Counter(t['double'] for t in ht))
print('ai',collections.Counter(hex(t['ai']) for t in ht))
print('maxspecies',max(m['species'] for t in ht for m in t['mons']), 'maxlvl',max(m['lvl'] for t in ht for m in t['mons']))
print('ivs',collections.Counter(m['iv'] for t in ht for m in t['mons']))
u2=collections.defaultdict(list)
for i,t in enumerate(ht): u2[t['party']].append(i)
print('shared by ptr',[(hex(k),[(j,ht[j]['flags'],ht[j]['size']) for j in v]) for k,v in u2.items() if len(v)>1])
# overlapping parties
iv=[]
for i,t in enumerate(ht):
    if t['party']==0: continue
    s=t['party']; e=s+t['size']*MONSZ[t['flags']&3]
    iv.append((s,e,i))
iv.sort()
for a,b in zip(iv,iv[1:]):
    if b[0]<a[1]: print('overlap',hex(a[0]),hex(a[1]),a[2],hex(b[0]),b[2])
