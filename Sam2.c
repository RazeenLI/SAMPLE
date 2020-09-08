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

int main() {
    int num1 = 1, num2 = 1;
    double num3 = 0;
    do {
        num3 = num3 + num1 + num2;
        num3 = num3 / num2;
        num3 += num1;
        num3 *= 2;
        num1++;
        num2++;
        printf("%lf\n", num3);
    } while (num3 < 50);
    return 0;
}