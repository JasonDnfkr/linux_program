#include "./ch11.h"

int main() {
    pid_t pid;
    pid_t pid2;
    pid = fork();
    if (pid < 0) {
        perror("fork pid error!\n");
        exit(-1);
    }
    else if (pid == 0) {
        printf("child: pid = %d, ppid = %d\n", getpid(), getppid());
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
            printf("r1 = %d, r2 = %d, pid = %d, pid2 = %d\n", r1, r2, pid, pid2);
            if (r1 == pid) printf("FIRST PID\n");
            if (r2 == pid2) printf("SECOND PID\n");
        }
    }
    return 0;
}