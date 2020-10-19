#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main() {
    int fd;
    fd = open("./test1.txt", O_CREAT, 0644);
    printf("file fd = %d\n", fd);   //文件描述符
    close(fd);

    return 0;
}