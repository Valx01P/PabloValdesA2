all: mystruct

mystruct: mystruct.o
	gcc mystruct.o -o mystruct

mystruct.o: mystruct.c
	gcc -c mystruct.c -o mystruct.o

clean:
	rm -f mystruct mystruct.o
