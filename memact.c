/*
    memact.c - memory activity
    Name: Pablo Valdes
    Affirmation of Originality: This program is my own original work
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *pc = (char *)malloc(sizeof(char));
    char *pstr = (char *)malloc(100 * sizeof(char));
    int *pi = (int *)malloc(sizeof(int));
    float *pf = (float *)malloc(sizeof(float));
    int *parr = (int *)malloc(10 * sizeof(int));

    if (!pc || !pstr || !pi || !pf || !parr) {
        printf("failed to allocate memory\n");
        return 1;
    }

    *pc = 'E';
    strcpy(pstr, "Valdes");
    *pi = 25;
    *pf = 32.76;

    for (int j = 0; j < 10; j++) {
        parr[j] = j;
    }

    printf("Character: %c\n", *pc);
    printf("Integer: %d\n", *pi);
    printf("String: %s\n", pstr);
    printf("Floating Point: %.2f\n", *pf);
    printf("Array of Integers: ");
    for (int j = 0; j < 10; j++) {
        printf("%d ", parr[j]);
    }
    printf("\n");

    free(pc);
    free(pstr);
    free(pi);
    free(pf);
    free(parr);

    return 0;
}
