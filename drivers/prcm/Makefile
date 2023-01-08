SRC=$(wildcard src/*.c)
INC=$(wildcard src/*.h)
OBJ=$(SRC:src/%=obj/%.o)

output.o: $(OBJ)
	$(LD) -r -o $@ $^

obj/%.c.o: src/%.c $(INC)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -r obj output.o 2> /dev/null || true
