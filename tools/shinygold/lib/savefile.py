"""FRLG battery save reader/editor (128 KiB flash). Sectors: 4 KiB; footer at 0xFF4: id u16, checksum u16, sig u32, counter u32."""
import struct
SIG = 0x08012025
SECTOR_SIZES = {0: 0xF24, 1: 0xFF0, 2: 0xFF0, 3: 0xFF0, 4: 0xD98}  # vanilla FR data sizes for SaveBlock2/1 sectors
for i in range(5, 14): SECTOR_SIZES[i] = 0xFF0 if i < 13 else 0x7D0

def checksum(data, size):
    s = 0
    for i in range(0, size, 4):
        s = (s + struct.unpack_from('<I', data, i)[0]) & 0xFFFFFFFF
    return ((s >> 16) + (s & 0xFFFF)) & 0xFFFF

class Save:
    def __init__(self, path):
        self.d = bytearray(open(path, 'rb').read())
    def sectors(self, slot):
        out = {}
        for i in range(14):
            o = (slot * 14 + i) * 0x1000
            sid, cs, sig, ctr = struct.unpack_from('<HHII', self.d, o + 0xFF4)
            out[sid] = (o, cs, sig, ctr)
        return out
    def current_slot(self):
        best = None
        for slot in (0, 1):
            s = self.sectors(slot)
            ctrs = [v[3] for v in s.values() if v[2] == SIG]
            if len(ctrs) == 14:
                c = ctrs[0]
                if best is None or c > best[1]: best = (slot, c)
        return best[0]
    def block(self, sid):
        o = self.sectors(self.current_slot())[sid][0]
        return o
    def fix_checksums(self, size_override=None):
        slot = self.current_slot()
        for sid, (o, cs, sig, ctr) in self.sectors(slot).items():
            sz = (size_override or {}).get(sid, SECTOR_SIZES[sid])
            struct.pack_into('<H', self.d, o + 0xFF6, checksum(self.d[o:o + 0x1000], sz))
    def write(self, path):
        open(path, 'wb').write(self.d)
