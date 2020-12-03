#include "../ch11.h"

int main() {
    pid_t pid1;
    pid_t pid2;
    pid_t pid11;
    pid_t pid21;

    pid1 = fork();

    if (pid1 < 0) {
        printf("pid1 error!\n");
        exit(-1);
    }
    else if (pid1 == 0) {
        pid11 = fork();
        if (pid11 < 0) {
            printf("pid11 error!\n");
            exit(-1);
        }
        else if (pid11 == 0) {
            printf("child11: pid = %d, ppid = %d\n", getpid(), getppid());
            exit(0);
        }
        else {
            printf("child1: pid = %d, ppid = %d\n", getpid(), getppid());
            exit(0);
        }
    }
    else {
        printf("???\n");
    }

    return 0;
}