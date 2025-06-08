all: activity

activity: activity.o
	gcc activity.o -o activity

activity.o: activity.c
	gcc -c activity.c -o activity.o

clean:
	rm -f activity activity.o core *~