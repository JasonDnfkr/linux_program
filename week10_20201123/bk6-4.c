#include "bk6-3.c"

int zero = 0;

int main() {
    pid_t pid;
    int status;
    if ((pid = fork()) == 0) exit(0);
    if ((pid = fork()) == 0) abort();
    if ((pid = fork()) == 0) {
        status /= zero;
        exit(0);
    }
    
    while ((pid = wait(&status)) >= 0) pr_exit(status, pid);

    perror("wait over");
    exit(EXIT_SUCCESS);

    return 0;
}