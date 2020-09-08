#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void giveUp(char *res);
void printNum(char *string, int from, int end);
int main(int argc, char **argv)
{
    if (argc != 4) giveUp(argv[0]);
    printNum(argv[1], atoi(argv[2]), atoi(argv[3]));
    return 0;
}

void giveUp(char *res)
{
    fprintf(stderr, "%s usage:", res);
}

void printNum(char *string, int from, int end) 
{
    int stop = strlen(string);
    int sign = 0;
    for (int i = 0; i < end; i++) {
        printf("%c", string[from]);
        if (from == stop - 1)
        {
            sign = 1;
        } else if (from == 0)
        {
            sign = 0;
        }
        switch (sign)
        {
            case 1:
                from--;
                break;
            case 0:
                from++;
        }
    }
    printf("\n");
}