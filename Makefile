all: memact

memact: memact.o
	gcc memact.o -o memact

memact.o: memact.c
	gcc -c memact.c -o memact.o

clean:
	rm -f memact memact.o
