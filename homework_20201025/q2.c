#include <stdio.h>
#include <string.h>

#define BUF_SIZE 8

int main() {
    FILE *fd;
    int fgets_yes;

    char buf[BUF_SIZE];
    char others[BUF_SIZE];

    memset(buf, '\0' ,sizeof(buf));
    memset(others, '\0', sizeof(others)); 
    printf("input:\n");
    gets(buf);
    printf("gets(): %s\n", buf);
    
    printf("overflowed: %s\n", others);
    exit(0);
}