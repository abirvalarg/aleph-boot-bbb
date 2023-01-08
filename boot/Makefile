SRC=$(wildcard src/*.s)
OBJ=$(SRC:src/%=obj/%.o)

output.o: $(OBJ)
	$(LD) -r -o $@ $^

obj/%.s.o: src/%.s
	@mkdir -p $(@D)
	$(AS) $(AFLAGS) -o $@ $<

clean:
	rm -r obj output.o 2> /dev/null || true
