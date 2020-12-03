#include "my.h"

void print_info(char* buf, const int fd, const int pid, const int ppid) 
{
    time_t *timep = malloc(sizeof(*timep));
    time(timep);
    char *s = ctime(timep);
    sprintf(buf, "child: pid = %d, ppid = %d, exit_time: %s\n", pid, ppid, s);
    write(fd, buf, strlen(buf));
    memset(buf, 0, 1024);
}
