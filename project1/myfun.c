#include "my.h"
#include <math.h>

#define MAX_NUM 64

const char *filename = "./user.dat";

void input() {
    User *pt = NULL;
    pt = (User *)malloc(sizeof(User));

    printf("输入id：\n");
    scanf("%d", &pt->id);

    printf("输入name：\n");
    scanf("%s", pt->name);

    printf("输入htel：\n");
    scanf("%s", pt->htel);

    printf("输入tel：\n");
    scanf("%s", pt->tel);
    // printf("你输入的：\n%d %s %s %s\n", pt->id, pt->name, pt->htel, pt->tel);

    save(pt);
    
}

void save(User *user) {
    FILE *fp = fopen(filename, "a+");

    if (!fp) {
        printf("Fail to open file!\n");
        exit(-1);
    }

    fprintf(fp, "%d %s %s %s\n", user->id, user->name, user->htel, user->tel);

    fclose(fp);
}

void output(FILE *fp) {
    printf("显示数据：\n");
    printf("%5s %8s %12s %12s\n", "id", "name", "htel", "tel");
    while (1) {
        User *pt = NULL;
        pt = (User *)malloc(sizeof(User));
        if (fscanf(fp, "%d %s %s %s", &pt->id, pt->name, pt->htel, pt->tel) == EOF) break;
        printf("%5d %8s %12s %12s\n", pt->id, pt->name, pt->htel, pt->tel);
        free(pt);
    }
    // fscanf(fp, "%5d %10s %10s %10s\n", user->id, user->name, user->htel, user->tel);
}



int cmp(const void *a, const void *b) {
    return strcmp(((User *)a)->name, ((User *)b)->name) > 0 ? 1 : -1;
}

int max_fun(int a, int b) {
    if (a > b) return a;
    else return b;
}

void mysort(FILE *fp) {
    int max_num = 0;
    int cnt = 0;
    User user[MAX_NUM];

    while (1) {
        User *pt = NULL;
        pt = (User *)malloc(sizeof(User));
        if (fscanf(fp, "%d %s %s %s", &pt->id, pt->name, pt->htel, pt->tel) == EOF) break;
        printf("%d %s %s %s\n", pt->id, pt->name, pt->htel, pt->tel);
        user[cnt].id = pt->id;
        strcpy(user[cnt].name, pt->name);
        strcpy(user[cnt].htel, pt->htel);
        strcpy(user[cnt].tel, pt->tel);
        cnt++;
        max_num = max_fun(max_num, pt->id);
        free(pt);
    }

    qsort(user, max_num, sizeof(User), cmp);

    for (int i = 0; i < max_num; i++) {
        printf("%d %s %s %s\n", user[i].id, user[i].name, user[i].htel, user[i].tel);
    }
}
