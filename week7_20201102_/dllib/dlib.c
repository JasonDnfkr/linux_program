#include "../ch07.h"

void dynamic_lib_call() {
    printf("dynamic_lib_call() is called\n");
}

void dsum(int max) {
    int i = 0;
    int sum = 0;
    for (i = 0; i <= max; i++) {
        sum += i;
    }
    printf("DYNAMIC SUM: %d\n", sum);
}