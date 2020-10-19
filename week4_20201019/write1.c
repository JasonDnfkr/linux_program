#include "ch03.h"
int main() {
    int n, i, fd;
    char buf;
    fd = open("./test.dat", O_CREAT|O_TRUNC|O_WRONLY, 0644);
    for (i = 0; i < 2; i++) {
        srand(time(NULL));
        n = rand() % 26;
        buf = (char)('a' + n);
        printf("write1: %c\n", buf);
        write(fd, &buf, 1);
        lseek(fd, 10, SEEK_SET);
        sleep(7);
    }
    close(fd);

    return 0;
}