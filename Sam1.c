#include <stdio.h>
#include <stdlib.h>

void giveUp(char *array);
void getResult(int num, int rem);
int main(int argc, char **argv)
{
    if (argc != 3) giveUp(argv[0]);
    getResult(atoi(argv[1]), atoi(argv[2]));
    return 0;
}

void getResult(int num, int rem) 
{
    int res[4];
    res[0] = num % rem;
    res[1] = (num + 1) % rem;
    res[3] = (num + 2) % rem;
    res[2] = (num + 3) % rem;

    printf("%2d---------%2d\n", res[0], res[1]);
    printf("|           |\n|           |\n|           |\n");
    printf("|           |\n|           |\n|           |\n");
    printf("|           |\n|           |\n|           |\n");
    printf("%2d---------%2d\n", res[2], res[3]);
}

void giveUp(char *array)
{
    fprintf(stderr, "usage: %s must enter two number", array);
    exit(0);
}