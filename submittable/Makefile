CC = gcc
CFLAGS = -g
LDFLAGS = -lm

randmst: randmst.o
	$(CC) randmst.o -o $@ $(LDFLAGS) $(LOADLIBES) $(LDLIBS)

clean:
	rm -f randmst.o randmst
