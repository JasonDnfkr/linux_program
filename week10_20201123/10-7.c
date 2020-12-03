#include "./ch10.h"

void foo() {
    fprintf(stderr, "foo says bye!\n");
}

void bar() {
    fprintf(stderr, "bar says bye!\n");
}

int main(int argc, char** argv) {
    atexit(foo);
    atexit(bar);

    fprintf(stdout, "Oop ~~~~ forgot a newline!");
    sleep(2);
    if (argc > 1 && !strcmp(argv[1], "exit")) exit(0);
    if (argc > 1 && !strcmp(argv[1], "_exit")) _exit(0);


    return 0;
}