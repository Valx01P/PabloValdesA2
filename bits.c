/*
    bits.c - bitwise shift activity
    Name: Pablo Valdes
    Affirmation of Originality: This program is my own original work
*/

#include <stdio.h>

int main() {
    unsigned int num;
    int direction;
    int amount;

    printf("Enter an unsigned integer: ");
    scanf("%u", &num);

    printf("Enter 1 for left shift or 2 for right shift: ");
    scanf("%d", &direction);

    printf("Enter how many bits to shift: ");
    scanf("%d", &amount);

    if (direction == 1) {
        num = num << amount;
    } else if (direction == 2) {
        num = num >> amount;
    } else {
        printf("Invalid direction.\n");
        return 1;
    }

    printf("Result after shift: %u\n", num);

    return 0;
}
