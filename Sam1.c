#include <stdio.h>
#include <stdlib.h>

void giveUp(char *res);
void getResult(int num);
int main(int argc, char **argv)
{
    if (argc != 2) giveUp(argv[0]);
    getResult(atoi(argv[1]));

    return 0;
}

void giveUp(char *res)
{
    fprintf(stderr, "%s usage:", res);
}

void getResult(int num)
{
    if (num > 0)
    {
        for (int i = 0; i <= num; i++)
        {
            printf("%d\n", i);
        }
    } else
    {
        for (int i = 0; i >= num; i--)
        {
            printf("%d\n", i);
        }
    }
}