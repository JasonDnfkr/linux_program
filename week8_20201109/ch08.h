#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <dlfcn.h>

#include <setjmp.h>

void err_exit(char *s) {
    printf("%s", s);
    exit(1);
}

int randomSpawn(int l_bound, int h_bound) {
    srand(time(NULL));
    return (rand() % (h_bound - l_bound)) + l_bound;
}