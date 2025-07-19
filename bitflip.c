/*
    bitflip.c - flip specific bits in a uint16_t
    Name: Pablo Valdes
    Panther ID: 6523235
    Affirmation of Originality: This program is my own original work
    Description: This program takes an unsigned 16-bit integer as input and performs bitwise operations
    to flip even, odd, or all bits based on command line options. It optionally writes output to a file
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>

void print_or_write(FILE *out, const char *label, uint16_t value) {
    fprintf(out, "%s: %u\n", label, value);
}

int main(int argc, char *argv[]) {
    int opt;
    int eflag = 0, fflag = 0, aflag = 0;
    char *outfile = NULL;
    FILE *out = stdout;
    uint16_t num;

    // parse options
    while ((opt = getopt(argc, argv, "efao:")) != -1) {
        switch (opt) {
            case 'e': eflag = 1; break;
            case 'f': fflag = 1; break;
            case 'a': aflag = 1; break;
            case 'o': outfile = optarg; break;
            case '?':
                fprintf(stderr, "usage: %s [-e] [-f] [-a] [-o outputfilename] intval\n", argv[0]);
                return 1;
        }
    }

    // check for single positional argument
    if (optind >= argc) {
        fprintf(stderr, "%s: missing integer argument\n", argv[0]);
        fprintf(stderr, "usage: %s [-e] [-f] [-a] [-o outputfilename] intval\n", argv[0]);
        return 1;
    }

    int val = atoi(argv[optind]);
    if (val < 1 || val > 20000) {
        fprintf(stderr, "%s: integer must be between 1 and 20000\n", argv[0]);
        return 1;
    }
    num = (uint16_t)val;

    // open output file if needed
    if (outfile) {
        out = fopen(outfile, "w");
        if (!out) {
            perror("fopen");
            return 1;
        }
    }

    // print original
    print_or_write(out, "Value", num);

    // flip even bits
    if (eflag) {
        uint16_t mask = 0x5555; // binary 0101010101010101
        print_or_write(out, "Even bits flipped", num ^ mask);
    }

    // flip odd bits
    if (fflag) {
        uint16_t mask = 0xAAAA; // binary 1010101010101010
        print_or_write(out, "Odd bits flipped", num ^ mask);
    }

    // flip all bits
    if (aflag) {
        print_or_write(out, "All bits flipped", ~num);
    }

    if (outfile) fclose(out);

    return 0;
}