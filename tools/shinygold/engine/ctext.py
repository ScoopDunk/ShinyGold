import sys,re
sys.path.insert(0,'/home/claude/sgx')
from core import Rom, text_asm, vanilla_addr, vanilla_symbols
FONTS={'0x00':'FONT_SMALL','0x01':'FONT_NORMAL_COPY_1','0x02':'FONT_NORMAL','0x03':'FONT_NORMAL_COPY_2','0x04':'FONT_MALE','0x05':'FONT_FEMALE'}
def cstr(rom, off):
    asm,end=text_asm(rom, off, 'x')
    parts=re.findall(r'\.string "(.*)"', asm)
    s=''.join(parts)
    assert s.endswith('$'), s
    s=s[:-1]
    s=re.sub(r'\{FONT (0x0[0-5])\}', lambda m:'{%s}'%FONTS[m.group(1)], s)
    return s, end
