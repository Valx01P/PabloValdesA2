all: forkchildren

forkchildren: forkchildren.o
	gcc -o forkchildren forkchildren.o

forkchildren.o: forkchildren.c
	gcc -c forkchildren.c

clean:
	rm -f forkchildren forkchildren.o
