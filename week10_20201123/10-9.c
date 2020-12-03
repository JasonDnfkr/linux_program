#include "./ch10.h"

int main() {
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        printf("error!\n");
        exit(-1);
    }
    else if (pid == 0) {
        printf("child 1 %d is running!\n", getpid());
        exit(108);
    }
    else {
        int r1, r2, s1, s2, y;
        y = fork();
        if (y < 0) {
            printf("error!\n");
            exit(-1);
        }
        else if (y == 0) {
            printf("child 2 %d is running!\n", getpid());
            exit(99);
        }
        else {
            r1 = waitpid(pid, &s1, 0);

            r2 = waitpid(y, &s2, 0);
            printf("parent %d will exit now. r1 = %d, s1 = %d\n", getpid(), r1, WEXITSTATUS(s1));
            printf("parent %d will exit now. r2 = %d, s2 = %d\n", getpid(), r2, WEXITSTATUS(s2));
            exit(0);
        }
    }
}