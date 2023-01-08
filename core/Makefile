SRC=$(wildcard src/*.c)
INC=$(wildcard src/*.h)
OBJ=$(SRC:src/%=obj/%.o)

output.o: $(OBJ)
	$(LD) -r -o $@ $^

obj/%.c.o: src/%.c $(INC)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -r output.o obj 2> /dev/null || true
