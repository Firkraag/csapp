CC = gcc
CFLAGS = -Wall -O2
PROGS = cs2-12 uadd_ok tadd_ok byteOrdering put_byte cs2-61 isLogicalShift \
		cs2-63 any_even_one even_ones lower_bits rotate_right\
		fits_bits
OBJS = cs2-12.o cs2-58.o 

all: $(PROGS)

uadd_ok: cs2-27.c
	$(CC) -o $@ $(CFLAGS) $^

tadd_ok: cs2-30.c
	$(CC) -o $@ $(CFLAGS) $^

byteOrdering: cs2-58.c 
	$(CC) -o $@ $(CFLAGS) $^

put_byte: cs2-60.c
	$(CC) -o $@ $(CFLAGS) $^


isLogicalShift: cs2-62.c
	$(CC) -o $@ $(CFLAGS) $^

any_even_one: cs2-64.c
	$(CC) -o $@ $(CFLAGS) $^

even_ones: cs2-65.c
	$(CC) -o $@ $(CFLAGS) $^

lower_bits: cs2-68.c
	$(CC) -o $@ $(CFLAGS) $^

rotate_right: cs2-69.c
	$(CC) -o $@ $(CFLAGS) $^

fits_bits: cs2-70.c
	$(CC) -o $@ $(CFLAGS) $^

bit.o: bit.c bit.h

clean:
	rm -f $(PROGS) $(OBJS) *.o *.out *~
