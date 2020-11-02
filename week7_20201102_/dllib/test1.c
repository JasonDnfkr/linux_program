#include "../ch07.h"

// extern void dynamic_lib_call();

int main() {
    void *dlib = dlopen("./libdlib.so", RTLD_NOW);
    if (!dlib) {
        printf("dlopen failed!\n");
        exit(-1);
    }
    void (*dfunc)() = dlsym(dlib, "dynamic_lib_call");
    if (!dfunc) {
        printf("dfunc is failed!\n");
        exit(-1);
    }

    dfunc();
    dlclose(dlib);

    return 0;
}
