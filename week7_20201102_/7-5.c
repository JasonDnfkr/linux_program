#include "ch07.h"

static void __attribute__ ((constructor)) before_main() {
    printf("---Before main---\n");
}

static void __attribute__ ((destructor)) after_main() {
    printf("---After main---\n");
}

static void callback1() {
    printf("----Callback1----\n");
}

static void callback2() {
    printf("----Callback2----\n");
}

static void callback3() {
    printf("----Callback3----\n");
}

int main() {
    atexit(callback1);
    atexit(callback2);
    atexit(callback3);
    while (1) {
        sleep(1);
    }
    printf("---main exit---\n");
    // exit(0);
    _exit(0); //强制退出，不清空缓存
    return 0;
}