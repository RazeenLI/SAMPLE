#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int chaekatep(int start, int step, int finish);
void seq(int start, int step, int finish);
int main(int argc, char* argv[])
{
    assert(argc > 1);
    int start = 1, step = 1, finish = 1;
    if (argc == 2) 
    {
        finish = atoi(argv[1]);
        step = start > finish ? -1 : 1;
    } else if (argc == 3)
    {
        start = atoi(argv[1]);
        finish = atoi(argv[2]);
        step = start > finish ? -1 : 1;
    } else if (argc == 4)
    {
        start = atoi(argv[1]);
        step = atoi(argv[2]);
        finish = atoi(argv[3]);
    }
    if (!chaekatep(start, step, finish)) 
    {
        printf("errer\n");
        exit(1);
    }
    seq(start, step, finish);
    return 0;
}

void seq(int start, int step, int finish)
{ 
    for (int i = start; (start > finish) ? (i >= finish) : (i <= finish); i +=step) printf("%d   ", i);
    printf("\n");
}

int chaekatep(int start, int step, int finish) {
    if (step == 0) return 0;
    else if ((step >= 0 && finish >= start) || (step <= 0 && finish <= start)) return 1;
    return 0;
}