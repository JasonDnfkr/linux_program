#include "./ch10.h"

int main() {
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        perror("fork failed!\n");
        exit(-1);
    }
    else if (pid == 0) {
        printf("10-6 child: pid = %d, ppid = %d", getpid(), getppid());
        execl("./test", "./test", "hello", "world", NULL);
        printf("10-6 child end!\n");
        exit(0);
    }
    else {
        int r, s;
        r = wait(&s);
        printf("10-6: r = %d, status(s) = %d\n", r, WEXITSTATUS(s));
        return 0;
    }

    return 0;
}