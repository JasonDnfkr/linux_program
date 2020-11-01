#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


typedef struct user {
    int id;
    char name[16];
    char htel[16];
    char tel[12];
} User;


void input();

void save(User *);

void output(FILE *);

void mysort();



int cmp(const void *, const void *);

int max_fun(int, int);

void randdat();