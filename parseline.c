/*
    parseline.c - a shell program that parses a string with pipes and redirection
    Name: Pablo Valdes
    Affirmation of Originality: This program is my own original work
*/

#include <stdio.h>
#include <string.h>

int main() {
    char input[256];
    char *token;

    printf("Enter a command line string: ");
    fgets(input, sizeof(input), stdin);

    // remove newline from fgets
    input[strcspn(input, "\n")] = 0;

    token = strtok(input, " ");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    return 0;
}
