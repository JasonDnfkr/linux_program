#include "my.h"

int main()
{
    pid_t pid1, pid2, pid11, pid21;
    int fd_out;
    char buf[1024];
    const char* filename = "log.txt";

    fd_out = open(filename, O_WRONLY | O_CREAT | O_TRUNC, MODE);
    if (fd_out < 0)
    {
        fprintf(stderr, "failed to open %s,reason(%s)\n", filename, strerror(errno));
        return 1;
    }
    memset(buf, 0, 1024);
    pid1 = fork();
    if (pid1 < 0)
    {
        perror("fork failed!\n");
        exit(-1);
    }
    else if (pid1 == 0)
    {
        pid11 = fork();
        if (pid11 < 0)
        {
            perror("fork failed!\n");
            exit(-1);
        }
        else if (pid11 == 0)
        {
            print_info(buf, fd_out, getpid(), getppid());
            exit(0);
        }
        else
        {
            wait(NULL);
            print_info(buf, fd_out, getpid(), getppid());
            exit(0);
        }
    }
    else
    {
        pid2 = fork();
        if (pid2 < 0)
        {
            perror("fork failed!\n");
            exit(-1);
        }
        else if (pid2 == 0)
        {
            pid21 = fork();
            if (pid21 < 0)
            {
                perror("fork failed!\n");
                exit(-1);
            }
            else if (pid21 == 0)
            {
                print_info(buf, fd_out, getpid(), getppid());
                exit(0);
            }
            else
            {
                wait(NULL);
                print_info(buf, fd_out, getpid(), getppid());
                exit(0);
            }
        }
        else
        {
            wait(NULL);
            wait(NULL);
            print_info(buf, fd_out, getpid(), getppid());
            return 0;
        }
    }
}