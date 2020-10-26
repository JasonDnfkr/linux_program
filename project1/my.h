#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct user {
    int id;
    char name[8];
    char htel[12];
    char tel[12];
} User;

void input();
void save(User *);
void output(FILE *fp);
void mysort(FILE *fp);