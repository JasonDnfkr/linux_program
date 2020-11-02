#include "../ch07.h"

int *p;
int x;

int main() {
    int *q;

    p = &x;
    q = (int *)malloc(sizeof(int));

    *p = 1;
    *q = 2;
    printf("*p = %d, *q = %d\n", *p, *q);


    return 0;
}