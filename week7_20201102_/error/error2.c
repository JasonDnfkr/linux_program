#include "../ch07.h"

#define N 10

int a[N], i;

int main() {
    for (i = 0; i < N; i++) {
        a[i] = i + 1;
    }
    a[N] = 123456789;
    printf("i = %d\n", i);
    printf("%d\n", a[i]);


/*
    全局变量声明在静态区(BSS段)，数组的十个元素地址空间后接了整型变量i的地址，数组a[10]的地址是变量i的地址，
    因此对a[10]的赋值会导致i变化。

    BSS段在程序生成时根据静态区的内容确定大小。a[123456789]超过了BSS段的内存空间，所以会segment fault。
*/

    return 0;
}