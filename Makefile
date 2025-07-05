all: bits

bits: bits.o
	gcc bits.o -o bits

bits.o: bits.c
	gcc -c bits.c -o bits.o

clean:
	rm -f bits bits.o
