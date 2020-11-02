#include "ch07.h"

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
    printf("---main exit---\n");
    // exit(0);
    exit(0); //强制退出，不清空缓存
    return 0;
}