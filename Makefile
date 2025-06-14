all: salary

salary: salary.o
	gcc salary.o -o salary

salary.o: salary.c
	gcc -c salary.c -o salary.o

clean:
	rm -f salary salary.o core *~