#include "./ch09.h"

int g_int = 1;

int main() {
    pid_t pid;

    int l_int = 99;
    int *pt = (int*)malloc(sizeof(int));

    char *string = "test string!";
    *pt = 9999;
    printf("%d------Before Fork------\n", getpid());

    pid = vfork();
    if (pid < 0) {
        fprintf(stderr, "failed to fork. Reason (%s).", strerror(errno));
        exit(-1);
    }
    else if (pid == 0) {
        printf("child: pid = %d, ppid = %d return from fork() = %d\n", getpid(), getppid(), pid);
        printf("child: init g = %d - %x, l = %d - %x, pt = %d - %x\n", g_int, &g_int, l_int, &l_int, *pt, pt);
        g_int++;
        l_int++;
        (*pt)++;
        printf("child: g = %d, l = %d, *pt = %d\n", g_int, l_int, *pt);
        printf("child: string = %s\n", string);
        exit(0); //return 0;
    }
    else {
        sleep(1);
        printf("parent: pid = %d, ppid = %d return from fork() = %d\n", getpid(), getppid(), pid);
        printf("parent: init g = %d - %x, l = %d - %x, pt = %d - %x\n", g_int, &g_int, l_int, &l_int, *pt, pt);
        g_int++;
        l_int++;
        (*pt)++;
        printf("parent: g = %d, l = %d, *pt = %d\n", g_int, l_int, *pt);

        printf("parent: parent string = %s\n", string);
    }

    return 0;
}