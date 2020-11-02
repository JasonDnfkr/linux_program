#include "ch07.h"
#include <string.h>

int to_int(char *str) {
    int n = 0;
    int cnt = 1;
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--) {
        n += (str[i] - '0') * cnt;
        cnt *= 10;
    }

    printf("aa: %d\n", n);

    return n;
}

int main(int argc, char **argv) {
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    if (argc < 3) {
        printf("Missing argument.\n");
        exit(-1);
    }

    printf("Answer: %d\n", to_int(argv[1]) + to_int(argv[2]));

    return 0;
}