all: threadact

threadact: threadact.o
	gcc -o threadact threadact.o -pthread

threadact.o: threadact.c
	gcc -c threadact.c

clean:
	rm -f threadact threadact.o
