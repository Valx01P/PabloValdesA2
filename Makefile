all: bitflip

bitflip: bitflip.o
	gcc -o bitflip bitflip.o

bitflip.o: bitflip.c
	gcc -c bitflip.c

clean:
	rm -f bitflip bitflip.o
