/*
    pointers.c - pointer activity
    Name: Pablo Valdes
    Affirmation of Originality: This program is my own original work
*/

#include <stdio.h>

int main() {
    char c;
    char str[100];
    int i;
    float f;

    char *pc = &c;
    char *pstr = str;
    int *pi = &i;
    float *pf = &f;

    printf("enter a single character: ");
    scanf(" %c", pc);

    printf("enter a string: ");
    scanf(" %99s", pstr);

    printf("enter an integer: ");
    scanf("%d", pi);

    printf("enter a floating point number: ");
    scanf("%f", pf);

    printf("\nCharacter: %c\n", *pc);
    printf("Integer: %d\n", *pi);
    printf("String: %s\n", pstr);
    printf("Floating Point: %.1f\n", *pf);

    printf("Character Pointer: %p\n", (void*)pc);
    printf("Integer Pointer: %p\n", (void*)pi);
    printf("String Pointer: %p\n", (void*)pstr);
    printf("Floating Point Pointer: %p\n", (void*)pf);

    return 0;
}
