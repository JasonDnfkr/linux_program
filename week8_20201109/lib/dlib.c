#include "../ch08.h"

void dynamic_lib_fun_call() {
    printf("Dynamic Lib Fun Called!\n");
}

void mysort(int *arr, int n) {
    for (int i = n - 1 ; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void myrand(int *arr, int n) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 99;
    }
}

void myprint(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}