CC = gcc
CFLAGS = -Wall -O1
PROGS = cs2-12 uadd_ok tadd_ok tsub_ok tmul_ok tmul32_ok\
		div16 byteOrdering put_byte cs2-61 isLogicalShift \
		cs2-63 any_even_one even_ones lower_bits rotate_right\
		fits_bits xbyte saturating_add signed_high_prod.o divide_power2\
		cs2-80
OBJS = cs2-12.o cs2-58.o 

all: $(PROGS)

uadd_ok: cs2-27.c
	$(CC) -o $@ $(CFLAGS) $^

tadd_ok: cs2-30.c
	$(CC) -o $@ $(CFLAGS) $^

tsub_ok: cs2-74.c
	$(CC) -o $@ $(CFLAGS) $^

tmul_ok: cs2-35.c
	$(CC) -o $@ $(CFLAGS) $^

tmul32_ok: cs2-36.c
	$(CC) -o $@ $(CFLAGS) $^

div16: cs2-42.c
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

xbyte: cs2-71.c
	$(CC) -o $@ $(CFLAGS) $^

saturating_add: cs2-73.c
	$(CC) -o $@ $(CFLAGS) $^

signed_high_prod.o: cs2-75.c
	$(CC) -c -o $@ $(CFLAGS) $^

divide_power2: cs2-77.c
	$(CC) -o $@ $(CFLAGS) $^

cs2-80: cs2-80.o bit.o
	$(CC) -o $@ $(CFLAGS) $^

cs2-80.o: cs2-80.c bit.h

bit.o: bit.c bit.h



clean:
	rm -f $(PROGS) $(OBJS) *.o *.out *~
