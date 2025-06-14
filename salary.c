/*
    salary.c - calculates salary 
    Name: Pablo Valdes
    Affirmation of Originality: This program is my own original work.
    Description: This program calculates salary with hours and rate and stuff
    Usage: salary [-p] -h hours [-b bonus] hourlyrate
    Ex: ./salary -p -h 40 -b 100 15.00
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    // for parsing command line
    extern char *optarg;
    extern int optind;
    int c, err = 0; 
    int pflag = 0, hflag = 0, bflag = 0;
    char *hval, *bval;
    int hours = 0;
    int bonus = 0;
    double hourlyrate = 0.0;
    double salary = 0.0;
    static char usage[] = "usage: %s [-p] -h hours [-b bonus] hourlyrate\n";
    
    // go through command line options
    while ((c = getopt(argc, argv, "ph:b:")) != -1) {
        switch (c) {
            case 'p':
                pflag = 1; // set flag for percentage
                break;
            case 'h':
                hflag = 1; // set flag for hours
                hval = optarg;
                hours = atoi(hval);
                break;
            case 'b':
                bflag = 1; // set flag for bonus
                bval = optarg;
                bonus = atoi(bval);
                break;
            case '?':
                err = 1; // error happened
                break;
        }
    }
    
    // make sure -h was used
    if (hflag == 0) {
        fprintf(stderr, "%s: missing -h option\n", argv[0]);
        fprintf(stderr, usage, argv[0]);
        exit(1);
    }
    
    // need exactly one more argument for hourly rate
    if ((optind + 1) != argc) {
        fprintf(stderr, "%s: hourly rate required\n", argv[0]);
        fprintf(stderr, usage, argv[0]);
        exit(1);
    }
    
    // if error happened print usage
    if (err) {
        fprintf(stderr, usage, argv[0]);
        exit(1);
    }
    
    // get hourly rate from the end
    hourlyrate = atof(argv[optind]);
    
    // hours cant be more than 80
    if (hours > 80) {
        fprintf(stderr, "%s: hours cannot be more than 80\n", argv[0]);
        fprintf(stderr, usage, argv[0]);
        exit(1);
    }
    
    // hours must be positive
    if (hours < 0) {
        fprintf(stderr, "%s: hours must be positive\n", argv[0]);
        fprintf(stderr, usage, argv[0]);
        exit(1);
    }
    
    // rate times hours
    salary = hourlyrate * hours;
    
    // add 10% if -p was used
    if (pflag) {
        salary = salary * 1.10;
    }
    
    // check if bonus is too big (greater than 50% of salary)
    if (bflag && bonus > (salary * 0.5)) {
        fprintf(stderr, "%s: bonus cannot be greater than 50%% of calculated salary\n", argv[0]);
        fprintf(stderr, usage, argv[0]);
        exit(1);
    }
    
    // bonus cant be negative
    if (bflag && bonus < 0) {
        fprintf(stderr, "%s: bonus must be positive\n", argv[0]);
        fprintf(stderr, usage, argv[0]);
        exit(1);
    }
    
    // add bonus if we have one
    if (bflag) {
        salary = salary + bonus;
    }
    
    // print the result like they want it
    printf("The salary for this period is $%.2f\n", salary);
    
    return 0;
}