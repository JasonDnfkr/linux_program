#include "./ch10.h"

int main() {
    int c1;
    int c2;
    int c3;
    int c11;
    c1 = fork();
    if (c1 < 0) {
        perror("Fork Failed!\n");
        exit(-1);
    }
    else if (c1 == 0) {
        printf("child 1: pid = %d, ppid = %d\n", getpid(), getppid());

        c11 = fork();
        if (c11 < 0) {
            exit(-1);
        }
        else if (c11 == 0) {
            printf("child 11: pid = %d, ppid = %d\n", getpid(), getppid());
            exit(0);
        }
        else {
            // printf("parent: pid = %d, ppid = %d\n", getpid(), getppid());
            wait(NULL);
            exit(0);
        }

        exit(0);
    }
    else {
        c2 = fork();
        if (c2 < 0) {
            perror("fork2 failed!\n");
            exit(-1);
        }
        else if (c2 == 0) {
            printf("child 2: pid = %d, ppid = %d\n", getpid(), getppid());
            exit(0);
        }
        else {
            // wait(NULL);
            c3 = fork();
            if (c3 < 0) {
                exit(-1);
            }
            else if (c3 == 0) {
                printf("child 3: pid = %d, ppid = %d\n", getpid(), getppid());
                exit(0);
            }
            else {
                wait(NULL);
                wait(NULL);
                wait(NULL);
                printf("parent: pid = %d, ppid = %d\n", getpid(), getppid());
                exit(0);
            }

            // printf("parent: pid = %d, ppid = %d\n", getpid(), getppid());
            // exit(0);
        }
    }

    return 0;
}