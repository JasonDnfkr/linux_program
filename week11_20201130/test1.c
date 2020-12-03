#include "./ch11.h"

void write_info(FILE* fp, const int pid, const int ppid) {
    time_t* time_p = malloc(sizeof(*time_p));
    time(time_p);
    char *time_str = ctime(time_p);
    fprintf(fp, "pid = %d, ppid = %d, exit_time: %s\n", pid, ppid, time_str);
}

int main() {
    pid_t pid1;
    pid_t pid2;
    pid_t pid11;
    pid_t pid21;

    const char* filename = "log.txt";
    char buf[1024];

    FILE* fp = fopen(filename, "w+");

    pid1 = fork();

    if (pid1 < 0) {
        perror("pid1 ERROR!!!\n");
        exit(-1);
    }
    else if (pid1 == 0) {
        pid11 = fork();
        if (pid11 < 0) {
            perror("pid11 ERROR!!!\n");
            exit(-1);
        }
        else if (pid11 == 0) {
            write_info(fp, getpid(), getppid());
            printf("child 11: pid = %d, ppid = %d\n", getpid(), getppid());
            exit(0);
        }
        else {
            wait(NULL);
            write_info(fp, getpid(), getppid());
            printf("child 1: pid = %d, ppid = %d\n", getpid(), getppid());
        }
        exit(0);
    }
    else {
        pid2 = fork();
        if (pid2 < 0) {
            perror("pid2 ERROR!!!\n");
            exit(-1);
        }
        else if (pid2 == 0) {
            pid21 = fork();
            if (pid21 < 0) {
                perror("pid21 ERROR!!!\n");
                exit(-1);
            }
            else if (pid21 == 0) {
                write_info(fp, getpid(), getppid());
                printf("child 21: pid = %d, ppid = %d\n", getpid(), getppid());
                exit(0);
            }
            else {
                sleep(1);
                wait(NULL);
                write_info(fp, getpid(), getppid());
                printf("child 2: pid = %d, ppid = %d\n", getpid(), getppid());
                exit(0);
            }
        }
        
        wait(NULL);
        wait(NULL);

        write_info(fp, getpid(), getppid());
        printf("parent: pid = %d, ppid = %d\n", getpid(), getppid());
    }

    fclose(fp);
    return 0;
}