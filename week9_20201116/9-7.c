#include "./ch09.h"

int main() {
    int pid;
    int s;
    pid = fork();
    if (pid < 0) {
        perror("Fork failed!\n");
        exit(-1);
    }
    else if (pid == 0) {
        printf("child pid = %d, ppid = %d\n", getpid(), getppid());
        exit(23);
    }
    else {
        int y;
        y = wait(&s);
        if (WIFEXITED(s)) {
            printf("child %d is normal back. The exit code = %d\n", y, WEXITSTATUS(s));
        }
        return 0;
    }

    return 0;
}