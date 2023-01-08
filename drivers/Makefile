DRIVERS=prcm
DRIVER_OBJ=$(addsuffix /output.o, $(DRIVERS))

PASS_OPTIONS=AS="$(AS)" CC="$(CC)" LD="$(LD)" AFLAGS="$(AFLAGS)" CFLAGS="$(CFLAGS)" LFLAGS="$(LFLAGS)" INC_PATH="$(INC_PATH)"

output.o: $(DRIVER_OBJ)
	$(LD) -r -o $@ $^

%/output.o: %
	cd $< && $(MAKE) $(PASS_OPTIONS)

clean: $(addprefix clean_, $(DRIVERS))
	rm output.o 2> /dev/null || true

clean_%: %
	cd $< && $(MAKE) clean
