all: pointers

pointers: pointers.o
	gcc pointers.o -o pointers

pointers.o: pointers.c
	gcc -c pointers.c -o pointers.o

clean:
	rm -f pointers pointers.o
