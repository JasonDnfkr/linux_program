#include "./ch07.h"

char *p = "test_env=test";

static void set_env_string() {
    char test_env[] = "test_env=test";
    if (putenv(p) != 0) {
        printf("putenv is failed!\n");
    }
    else {
        p = getenv("test_env");
        printf("1. The test_env = %s\n", getenv("test_env"));
    }
}

static void show_env_string() {
    printf("2. The test_env = %s\n ", getenv("test_env"));
}

int main() {
    set_env_string();
    
    // printf("%s  \n", p);

    show_env_string();
    return 0;
}
/*

用putenv来设置环境变量， 必须要保证参数是一个长期存在的内容。 
因此，只能选择全局变量、常量或动态内存等。

*/