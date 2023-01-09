CROSS_COMPILE=arm-none-eabi-
AS=$(CROSS_COMPILE)as
CC=$(CROSS_COMPILE)gcc
LD=$(CROSS_COMPILE)ld

AFLAGS=-mcpu=cortex-a8
CFLAGS= -ffunction-sections -fdata-sections -mcpu=cortex-a8 -c -O2 -std=gnu17
LFLAGS=-gc-sections

SRC=$(wildcard src/*.c) $(wildcard src/*.s)
INC=$(wildcard src/*.h)
OBJ=$(SRC:src/%=obj/%.o)

MLO: aleph-boot-bbb.bin scripts/make-MLO.py
	python scripts/make-MLO.py

aleph-boot-bbb.bin: aleph-boot-bbb
	$(CROSS_COMPILE)objcopy -O binary $< $@

aleph-boot-bbb: $(OBJ) memmap.ld
	$(LD) $(LFLAGS) -Tmemmap.ld -o $@ $(OBJ)

obj/%.c.o: src/%.c $(INC)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $<

obj/%.s.o: src/%.s
	@mkdir -p $(@D)
	$(AS) $(AFLAGS) -o $@ $<

dump: aleph-boot-bbb
	$(CROSS_COMPILE)objdump -D $<

clean:
	rm -r aleph-boot-bbb* MLO obj 2> /dev/null || true
