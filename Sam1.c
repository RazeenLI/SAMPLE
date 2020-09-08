#include <stdio.h>
#include <stdlib.h>

char *getMonth(int num);
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "must enter 12 number");
        exit(0);
    } else if (atoi(argv[1]) > 12 || atoi(argv[1]) < 1) 
    {
        fprintf(stderr, "must enter a number between 1 to 12");
        exit(0);
    }
    printf("%s\n", getMonth(atoi(argv[1])));
    return 0;
}

char *getMonth(int num) 
{
    char *month[13] = {"????",  "January", "February", "March",
		                "April", "May", "June", "July", "August",
		                "September", "October", "November", "December"};
    return month[num];
}