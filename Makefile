CROSS_COMPILE=arm-none-eabi-
AS=$(CROSS_COMPILE)as
CC=$(CROSS_COMPILE)gcc
LD=$(CROSS_COMPILE)ld
OBJCOPY=$(CROSS_COMPILE)objcopy

DRIVERS=prcm

INC_PATH=$(addprefix $(PWD)/drivers/, $(addsuffix /include, $(DRIVERS)))

COMMON_FLAGS=
AFLAGS=$(COMMON_FLAGS) -mcpu=cortex-a8
CFLAGS=$(COMMON_FLAGS) -O2 -c -mcpu=cortex-a8 -std=gnu17 $(addprefix -I, $(INC_PATH))
LFLAGS=$(COMMON_FLAGS) -O2

PASS_OPTIONS=AS="$(AS)" CC="$(CC)" LD="$(LD)" AFLAGS="$(AFLAGS)" CFLAGS="$(CFLAGS)" LFLAGS="$(LFLAGS)"

MODULES=boot core drivers
MOD_ARS=$(addsuffix /output.o, $(MODULES))
OUTPUT=MLO

all: $(OUTPUT)

$(OUTPUT): aleph-boot-bbb.bin
	python scripts/make-MLO.py

aleph-boot-bbb.bin: aleph-boot-bbb
	$(OBJCOPY) -O binary $< $@

aleph-boot-bbb: $(MOD_ARS)
	$(LD) $(LFLAGS) -Tmemmap.ld -o $@ $^

%/output.o: %
	cd $< && $(MAKE) $(PASS_OPTIONS)

dump: aleph-boot-bbb
	$(CROSS_COMPILE)objdump -D $<

clean: $(addprefix clean_, $(MODULES))
	rm aleph-boot-bbb{,.bin} MLO 2> /dev/null || true

clean_%: %
	cd $< && $(MAKE) $(PASS_OPTIONS) clean

# .PHONY: all dump clean $(addprefix clean_, $(MODULES))
