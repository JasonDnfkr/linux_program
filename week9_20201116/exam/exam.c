#include "../ch09.h"

int g = 0;
const char *filename = "./out.txt";

int fd_out;
char buf[1024];

int main() {
    pid_t A;
    pid_t B;
    
    memset(buf, 0, sizeof(buf));

    fd_out = open(filename, O_WRONLY|O_CREAT|O_TRUNC, MODE);
    if (fd_out < 0) {
        fprintf(stderr, "failed to open %s, reason(%s)\n", OUTFILE, strerror(errno));
        return 1;
    }

    A = vfork();
    if (A) {
        printf("A: %d\n", A);
        B = vfork();
    }
    printf("A: %d\n", A);

    if (A < 0 || B < 0) {
        fprintf(stderr, "failed to fork. Reason (%s).", strerror(errno));
        exit(-1);
    }
    else if (A == 0) {
        // sleep(1);
        g++;
        printf("[Progess A] pid = %d, ppid = %d, g = %d\n", getpid(), getppid(), g);
        sprintf(buf, "[Progess A] pid = %d, ppid = %d, g = %d\n", getpid(), getppid(), g);
        write(fd_out, buf, strlen(buf));
        memset(buf, 0, 1024);
        pid_t A1;
        pid_t A2;
        A1 = vfork();
        if (A1) A2 = vfork();
        if (A1 < 0 || A2 < 0) {
            fprintf(stderr, "failed to fork. Reason (%s).", strerror(errno));
            exit(-1);
        }
        else if (A1 == 0) {
            g++;
            printf("[Progess A1] pid = %d, ppid = %d, g = %d\n", getpid(), getppid(), g);
            sprintf(buf, "[Progess A1] pid = %d, ppid = %d, g = %d\n", getpid(), getppid(), g);
            write(fd_out, buf, strlen(buf));
            memset(buf, 0, 1024);
            exit(0);
        }
        else if (A2 == 0) {
            g++;
            printf("[Progess A2] pid = %d, ppid = %d, g = %d\n", getpid(), getppid(), g);
            sprintf(buf, "[Progess A2] pid = %d, ppid = %d, g = %d\n", getpid(), getppid(), g);
            write(fd_out, buf, strlen(buf));
            memset(buf, 0, 1024);
            exit(0);
        }
        exit(0);
    }
    else if (B == 0) {
        printf("A in B: %d", A);
        // sleep(1);
        g++;
        printf("[Progess B] pid = %d, ppid = %d, g = %d\n", getpid(), getppid(), g);
        sprintf(buf, "[Progess B] pid = %d, ppid = %d, g = %d\n", getpid(), getppid(), g);
        write(fd_out, buf, strlen(buf));
        memset(buf, 0, 1024);
        exit(0);
    }
    else {
        // sleep(1);
        g++;
        printf("[Progess Parent] pid = %d, ppid = %d, g = %d\n", getpid(), getppid(), g);
        sprintf(buf, "[Progess Parent] pid = %d, ppid = %d, g = %d\n", getpid(), getppid(), g);
        write(fd_out, buf, strlen(buf));
        memset(buf, 0, 1024);
        exit(0);
    }

    return 0;
}