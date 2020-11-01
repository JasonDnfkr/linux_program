#include "my.h"
#include <math.h>

#define MAX_NUM 64

const char *filename = "./user.dat";
const unsigned int UINT_MAX = 4294967295;
const char telnum_pre [42][3] = {
    "133", "149", "153", "173", "177", "180", "181", "189", "199", "130", "131", "132", "145", "155", "156", "166", "171", "175", "176", "185", "186", "166", "134", "135", "136", "137", "138", "139", "147", "150", "151", "152", "157", "158", "159", "172", "178", "182", "183", "187", "188", "198"
};

void input() {
    User *pt = NULL;
    pt = (User *)malloc(sizeof(User));

    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Fail to open file!\n");
        exit(-1);
    }

    printf("Please input id：\n");
    scanf("%d", &pt->id);

    int id;
    char temp_str[16];
    while (fscanf(fp, "%d %s %s %s", &id, temp_str, temp_str, temp_str) != EOF) {
        if (pt->id == id) {
            printf("Error! ID %d exists.\n", id);
            fclose(fp);
            free(pt);
            return;
        }
    }

    printf("Please input name：\n");
    scanf("%s", pt->name);

    printf("Please input htel：\n");
    scanf("%s", pt->htel);

    printf("Please input tel：\n");
    scanf("%s", pt->tel);
    // printf("你输入的：\n%d %s %s %s\n", pt->id, pt->name, pt->htel, pt->tel);

    save(pt);
    free(pt);
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
    printf("Data：\n");
    printf("%10s %14s %16s %12s\n", "[id]", "[name]", "[htel]", "[tel]");
    while (1) {
        User *pt = NULL;
        pt = (User *)malloc(sizeof(User));
        if (fscanf(fp, "%d %s %s %s", &pt->id, pt->name, pt->htel, pt->tel) == EOF) break;
        printf("%10d %14s %16s %12s\n", pt->id, pt->name, pt->htel, pt->tel);
        free(pt);
    }

    fseek(fp, SEEK_SET, 0);
    // fscanf(fp, "%5d %10s %10s %10s\n", user->id, user->name, user->htel, user->tel);
}



int cmp(const void *a, const void *b) {
    return strcmp(((User *)a)->name, ((User *)b)->name) > 0 ? 1 : -1;
}

int max_fun(int a, int b) {
    if (a > b) return a;
    else return b;
}

void mysort() {
    FILE *fp = fopen(filename, "r+");
    int max_num = 0;
    int cnt = 0;
    User user[MAX_NUM];

    while (1) {
        User *pt = NULL;
        pt = (User *)malloc(sizeof(User));
        if (fscanf(fp, "%d %s %s %s", &pt->id, pt->name, pt->htel, pt->tel) == EOF) break;
        printf("读取：%d %s %s %s\n", pt->id, pt->name, pt->htel, pt->tel);
        
        // printf("%d %s %s %s\n", pt->id, pt->name, pt->htel, pt->tel);
        user[cnt].id = pt->id;
        strcpy(user[cnt].name, pt->name);
        strcpy(user[cnt].htel, pt->htel);
        strcpy(user[cnt].tel, pt->tel);
        cnt++;
        max_num = max_fun(max_num, pt->id);
        free(pt);
    }

    // printf("???\n");
    qsort(user, cnt, sizeof(User), cmp);
    // printf("???\n");

    // fseek(fp, SEEK_SET, 0);

    for (int i = 0; i < cnt; i++) {
        fprintf(stdout, "%10d %14s %16s %12s\n", user[i].id, user[i].name, user[i].htel, user[i].tel);
    }

    printf("Sort successful.\n");
    fclose(fp);
}

void randdat() {
    FILE *fp = fopen(filename, "a+");
    User *t_struct = (User *)malloc(sizeof(User));
    srand(time(NULL));
    t_struct->id = rand();
    int max_strlen = 1;
    while (max_strlen <= 1) {
        max_strlen = rand() % 8;
    }

    strncpy(t_struct->htel, "0791-", 5);
 
    for (int i = 0; i < max_strlen; i++) {
        t_struct->name[i] = (char)(rand() % 26 + 'a');
        if (!i) t_struct->name[i] -= 32;
    }
    t_struct->name[max_strlen] = '\0';

    for (int i = 5; i < 13; i++) {
        t_struct->htel[i] = (char)(rand() % 10 + '0');
    }
    t_struct->htel[13] = '\0';
    if (t_struct->htel[5] == '0') t_struct->htel[0]++;

    strncpy(t_struct->tel, telnum_pre[rand() % 42], 3);

    for (int i = 3; i < 11; i++) {
        t_struct->tel[i] = (char)(rand() % 10 + '0');
    }
    t_struct->tel[11] = '\0';

    fprintf(fp, "%d %s %s %s\n", t_struct->id, t_struct->name, t_struct->htel, t_struct->tel);
    // fprintf(fp, "%s\n", "sss");

    printf("Successfully get a random data\n");

    free(t_struct);
    fclose(fp);

}