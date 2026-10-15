import sys,struct
sys.path.insert(0,'/home/claude/sgx')
from core import *
H=Rom(); V=Rom(VANILLA_ROM)
import re
names=['Thunderbolt','LightScreen','Hail','Torment','Facade','FocusPunch','Taunt','BrickBreak','SkillSwap','Snatch','SecretPower','Overheat','RockTomb','BulletSeed','AerialAce','DragonClaw','BulkUp','CalmMind','ShockWave','WaterPulse']
for n in names:
    a=vanilla_addr('gMoveDescription_'+n)
    w=struct.pack('<I',a+0x8000000)
    hv=[m.start() for m in re.finditer(re.escape(w),H.d) if m.start()%4==0]
    vv=[m.start() for m in re.finditer(re.escape(w),V.d) if m.start()%4==0]
    print(n, hex(a), 'hack:',[ (hex(x),vanilla_name_at(x)) for x in hv], 'van:',[hex(x) for x in vv])
