import sys
sys.path.insert(0,'/home/claude/sgx')
from core import *
H=Rom(); V=Rom(VANILLA_ROM)
def sym(n):
    a=vanilla_addr(n); 
    for x,s,nm in vanilla_symbols()[1]:
        if nm==n: return x,s
tabs=[('gTrainerClassNames',13),('gTrainers',40),('gSpeciesNames',11),('gMoveNames',13),('gTypeEffectiveness',3),('gTypeNames',7),
('gTrainerMoneyTable',4),('gAbilityDescriptionPointers',4),('gAbilityNames',13),('gBattleMoves',12),('sSpeciesToHoennPokedexNum',2),
('sSpeciesToNationalPokedexNum',2),('sHoennToNationalOrder',2),('gItemEffectTable',4),('sTMHMLearnsets',8),('gFacilityClassToPicIndex',1),
('gExperienceTables',4),('gSpeciesInfo',28),('gEvolutionTable',40),('gLevelUpLearnsets',4),('gEggMoves',2),('sInGameTrades',60),('gItems',44),
('gPokedexEntries',36),('sTutorLearnsets',2),('sTMHMMoves',2),('gMoveDescriptionPointers',4)]
for n,es in tabs:
    a,s=sym(n)
    diffs=[i for i in range(s//es) if H.d[a+i*es:a+(i+1)*es]!=V.d[a+i*es:a+(i+1)*es]]
    print('%-30s %7x size %5x n=%4d changed=%d %s'%(n,a,s,s//es,len(diffs),diffs[:20]))
