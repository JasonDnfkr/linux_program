#include "ch05.h"
int main() {
    char buffer[BUFSIZ];
    int fd;
    setbuf(stdout, buffer);

    puts("test...");

    return 0;
}