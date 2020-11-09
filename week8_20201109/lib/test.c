#include "../ch08.h"


// void mysort(int *arr, int n) {
//     for (int i = n - 1 ; i > 0; i--) {
//         for (int j = 0; j < i; j++) {
//             if (arr[j] > arr[j + 1]) {
//                 int tmp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = tmp;
//             }
//         }
//     }
// }

int main() {
    void *fpt = dlopen("./libdlib.so", RTLD_NOW);
    if (!fpt) {
        printf("dlopen failed!\n");
        exit(1);
    }

    void (*fp)() = dlsym(fpt, "dynamic_lib_fun_call");
    void (*fsort)(int *, int) = dlsym(fpt, "mysort");
    void (*fprint)(int *, int) = dlsym(fpt, "myprint");
    void (*frand)(int *, int) = dlsym(fpt, "myrand");

    if (!fp || !fsort || !fprint ||!frand) {
        printf("dlsym failed!\n");
        exit(1);
    }
    fp();

    const int MAX = 15;

    int arr[MAX];

    frand(arr, MAX);

    printf("Original Array: \n");
    fprint(arr, MAX);
    
    fsort(arr, MAX);

    printf("Sorted Array: \n");
    fprint(arr, MAX);

    dlclose(fpt);

    return 0;
}