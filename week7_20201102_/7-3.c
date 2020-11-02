#include "ch07.h"

int main() {
    printf("---data in buffer---");
    // exit(0);
    _exit(0); //强制退出，不清空缓存
    return 0;
}