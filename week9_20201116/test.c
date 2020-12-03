#include "./ch09.h"



int main(int argc, char** argv) {
    extern char** environ;
    char** env = environ;
    for (int i = 1; i < argc; i++) {
        printf("%s ", argv[i]);
    }

    while (*env) {
        printf("%s\n", *env);
        env++;
    }

    

    return 0;
}