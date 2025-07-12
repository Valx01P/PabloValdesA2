all: parseline

parseline: parseline.o
	gcc parseline.o -o parseline

parseline.o: parseline.c
	gcc -c parseline.c -o parseline.o

clean:
	rm -f parseline parseline.o
