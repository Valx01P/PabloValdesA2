all: doublesort

doublesort: doublesort.o
	gcc doublesort.o -o doublesort

doublesort.o: doublesort.c
	gcc -c doublesort.c -o doublesort.o

clean:
	rm -f doublesort doublesort.o
