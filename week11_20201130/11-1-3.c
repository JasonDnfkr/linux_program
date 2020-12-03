#include "./ch11.h"

void exit_stat(int stat, pid_t pid) {
    if (WIFEXITED(stat)) {
        printf("Normal exit. PID = %d, Status Code = %d\n", pid, WEXITSTATUS(stat));
    }
    else if (WIFSIGNALED(stat)) {
        printf("Abnormal exit. PID = %d, Signal Code = %d\n", pid, WTERMSIG(stat));
    }
    else if (WIFSTOPPED(stat)) {
        printf("Stopped exit. PID = %d, Signal Code = %d\n", pid, WSTOPSIG(stat));
    }
}

int main() {
    pid_t pid;
    pid_t pid2;
    pid_t pid3;
    pid = fork();
    if (pid < 0) {
        perror("fork pid error!\n");
        exit(-1);
    }
    else if (pid == 0) {
        printf("child: pid = %d, ppid = %d\n", getpid(), getppid());
        exit(101);
    }
    else {
        // printf("parent: exit code = %d\n", WEXITSTATUS(s));
        pid2 = fork();
        if (pid2 < 0) {
            perror("pid2 error!!\n");
            exit(-1);
        }
        else if (pid2 == 0) {
            printf("child2: pid = %d, ppid = %d\n", getpid(), getppid());
            abort();
        }
        else {
            pid3 = fork();
            if (pid3 < 0) {
                perror("pid3 error!!\n");
                exit(-1);
            }
            else if (pid3 == 0) {
                printf("child3: pid = %d, ppid = %d\n", getpid(), getppid());
                sleep(404);
            }
            else {
                int s1, s2, s3, r1, r2, r3;
                r1 = wait(&s1);
                r2 = wait(&s2);
                r3 = wait(&s3);
                exit_stat(s1, r1);
                exit_stat(s2, r2);
                exit_stat(s3, r3);
            }
        }
    }
    return 0;
}