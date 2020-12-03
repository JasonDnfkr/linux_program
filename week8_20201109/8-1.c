#include "./ch08.h"

static int g = 100, k;

void fun() {
    int x;
    int y;
    int *p = (int *)malloc(sizeof(int));
    printf("fun: address of x = %x, y = %x\n", &x, &y);
    printf("fun: address of p = %x\n", p);
    sleep(20);
    return;
}

int main() {
    int i = 0;
    int j = 0;
    int a[10] = {1};

    static int w = 100;

    int *pt = (int *)malloc(sizeof(int) * 10);

    printf("address of g = %x, k = %x\n", &g, &k);
    printf("address of i = %x, j = %x, a = %x\n", &i, &j, a);
    printf("address of w = %x\n", &w);
    printf("address of pt = %x\n", pt);

    fun();

    return 0;
}