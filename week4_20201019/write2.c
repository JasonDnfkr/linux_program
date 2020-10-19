#include "ch03.h"
int main() {
    int n, i, fd;
    char buf;
    fd = open("./test.dat", O_CREAT|O_WRONLY, 0644);
    for (i = 0; i < 2; i++) {
        srand(time(NULL));
        n = rand() % 26;
        buf = (char)('A' + n);
        printf("write2: %c\n", buf);
        write(fd, &buf, 1);
        lseek(fd, 10, SEEK_SET);
        sleep(10);
    }
    close(fd);

    return 0;
}