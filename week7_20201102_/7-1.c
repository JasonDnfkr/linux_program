#include "ch07.h"

static void __attribute__ ((constructor)) before_main() {
    printf("---Before main---\n");
}

static void __attribute__ ((destructor)) after_main() {
    printf("---After main---\n");
}

int main() {
    printf("---Main Function---\n");

    return 0;
}