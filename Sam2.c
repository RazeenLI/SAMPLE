#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <glob.h>
#include <assert.h>
#include <fcntl.h>
#include <errno.h>
struct node {
    struct node * next;
    int value;
};
struct node * creatArray(struct node * end);
int sumAll(struct node * array);
int main(int argc, char *argv[]) 
{
    struct node * array1 = creatArray(NULL);
    struct node * array2 = creatArray(array1);
    struct node * array3 = creatArray(array2);
    struct node * array4 = creatArray(array3);
    struct node * pointer = array4;
    int i = 0;
    while (pointer != NULL)
    {
        pointer->value = atoi(argv[i + 1]);
        i++;
        pointer = pointer->next;
    }
    for (pointer = array4; pointer != NULL; pointer = pointer->next) printf(" %d\n", pointer->value);
    int sum = sumAll(array4);
    printf("%d\n", sum);
    return 0;
}

int sumAll(struct node * array)
{
    int sum = 0;
    struct node * pointer = array;
    for (sum = 0; pointer != NULL; pointer = pointer->next)
    {
        sum += pointer->value;
    }
    return sum;
}

struct node * creatArray(struct node * end) 
{
    struct node * array = malloc(sizeof(struct node));
    assert(array != NULL);
    array->next = end;
    return array;
}