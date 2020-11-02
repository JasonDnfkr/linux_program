#include "ch07.h"

static void set_env_string() {
    char test_env[] = "test_env=test";
    if (putenv(test_env) != 0) {
        printf("putenv is failed!\n");
    }
    else {
        printf("1. The test_env = %s\n", getenv("test_env"));
    }
}

static void show_env_string() {
    printf("2. The test_env = %s\n ", getenv("test_env"));
}

int main() {
    set_env_string();
    show_env_string();
    return 0;
}
//