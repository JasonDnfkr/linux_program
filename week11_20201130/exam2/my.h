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
#include <wait.h>
#include <errno.h>

#define MODE S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH

void print_info(char*, const int, const int, const int);