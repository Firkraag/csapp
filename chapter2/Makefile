CC = gcc
CFLAGS = -Wall -O2
PROGS = cs2-12 byteOrdering put_byte
OBJS = cs2-12.o cs2-58.o 

all: $(PROGS)

byteOrdering: cs2-58.c 
	$(CC) -o $@ $(CFLAGS) $^

put_byte: cs2-60.c
	$(CC) -o $@ $(CFLAGS) $^



clean:
	rm -f $(PROGS) $(OBJS) *.o *.out *~
