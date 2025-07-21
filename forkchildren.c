/*
    forkchildren.c - process activity with two children
    Name: Pablo Valdes
    Affirmation of Originality: This program is my own original work
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1 = fork();

    if (pid1 == 0) {
        // first child: run ls -l
        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls"); // just in case
        exit(1);
    }

    pid_t pid2 = fork();

    if (pid2 == 0) {
        // second child: run cat forkchildren.c
        execlp("cat", "cat", "forkchildren.c", NULL);
        perror("execlp cat"); // just in case
        exit(1);
    }

    // parent waits for both children
    wait(NULL);
    wait(NULL);

    printf("parent: both children finished\n");

    return 0;
}
