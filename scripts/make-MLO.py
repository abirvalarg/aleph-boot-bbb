import struct

with open('aleph-boot-bbb.bin', 'rb') as fp:
    contents = fp.read()

header = struct.pack('<II', len(contents), 0x402F0400)

with open('MLO', 'wb') as fp:
    fp.write(header)
    fp.write(contents)
