#include "../ch11.h"

int main() {
    pid_t pid1;
    pid_t pid2;
    
    pid_t pid21;
    pid1 = fork();
    if (pid1 < 0) {
        perror("fork pid1 error!\n");
        exit(-1);
    }
    else if (pid1 == 0) {
        printf("child1: pid = %d, ppid = %d\n", getpid(), getppid());
        pid_t pid11;
        pid11 = fork();
        if (pid11 < 0) {
            perror("fork pid11 error!\n");
            exit(-1);
        }
        else if (pid11 == 0) {
            printf("child11: pid = %d, ppid = %d\n", getpid(), getppid());
            exit(0);
        }
        else {
            printf("child111: pid = %d, ppid = %d\n", getpid(), getppid());
        }
        exit(0);
    }
    else {
        pid2 = fork();
        if (pid2 < 0) {
            perror("error!!\n");
            exit(-1);
        }
        else if (pid2 == 0) {
            printf("child2: pid = %d, ppid = %d\n", getpid(), getppid());
            exit(0);
        }
        else {
            int r1 = wait(NULL);
            int r2 = wait(NULL);
            // printf("r1 = %d, r2 = %d, pid = %d, pid2 = %d\n", r1, r2, pid1, pid2);
            if (r1 == pid1) printf("FIRST PID\n");
            if (r2 == pid2) printf("SECOND PID\n");
        }
    }
    return 0;
}