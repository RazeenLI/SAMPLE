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
    int * next;
    int size;
};

void swap(struct node * a, int i, int j);
int main() {
    struct node * array = malloc(sizeof(struct node) * 4);
    *(array[0].next) = 0;
    *(array[1].next) = 1;
    *(array[2].next) = 2;
    *(array[3].next) = 3;
    for (int i = 0; i < 4; i++) printf("%d", *(array[i].next));
    printf("\n");
    swap(array, 1, 3);
    for (int i = 0; i < 4; i++) printf("%d", *(array[i].next));
    printf("\n");

    return 0;
}

void swap(struct node * a, int i, int j)
{
    int * tmp;
    tmp = a[i].next;
    a[i].next = a[j].next;
    a[j].next = tmp;
}