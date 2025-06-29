/*
    mystruct.c – Struct Activity
    Name: Pablo Valdes
    Affirmation of Originality: This program is my own original work
*/

#include <stdio.h>

typedef struct {
    int   x;
    int   y;
    char  alpha;
    float z;
} MyStruct;

int main(void) {
    MyStruct s;          /* one element of the struct */
    MyStruct *p = &s;    /* pointer for indirect selection */

    /* fill with data */
    s.x     = 99;
    s.y     = 67;
    s.alpha = 'C';
    s.z     = 3.74f;

    /* direct selection */
    printf("X: %d\n",     s.x);
    printf("Y: %d\n",     s.y);
    printf("alpha: %c\n", s.alpha);
    printf("Z: %.2f\n\n", s.z);

    /* indirect selection */
    printf("X: %d\n",     p->x);
    printf("Y: %d\n",     p->y);
    printf("alpha: %c\n", p->alpha);
    printf("Z: %.2f\n",   p->z);

    return 0;
}
