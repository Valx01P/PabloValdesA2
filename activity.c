/*
    activity.c - modified version of getopt example for assignment
    usage: activity [-r] -b bval value
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    extern char *optarg;
    extern int optind;
    int c, err = 0; 
    int rflag = 0, bflag = 0;
    char *bval;
    int bvalint = 0;
    int valint = 0;
    static char usage[] = "usage: %s [-r] -b bval value\n";

    while ((c = getopt(argc, argv, "rb:")) != -1) {
        switch (c) {
            case 'r':
                rflag = 1;
                break;
            case 'b':
                bflag = 1;
                bval = optarg;
                bvalint = atoi(bval);
                break;
            case '?':
                err = 1;
                break;
        }
    }

    if (bflag == 0) {  // -b is mandatory
        fprintf(stderr, "%s: missing -b option\n", argv[0]);
        fprintf(stderr, usage, argv[0]);
        exit(1);
    } else if ((optind + 1) != argc) {  // Expect exactly one remaining value
        fprintf(stderr, "%s: exactly one value argument required\n", argv[0]);
        fprintf(stderr, usage, argv[0]);
        exit(1);
    } else if (err) {
        fprintf(stderr, usage, argv[0]);
        exit(1);
    }

    valint = atoi(argv[optind]);
    int result = bvalint + valint;

    printf("Total = %d\n", result);
    return 0;
}
