#include "my.h"

void input(User *user) {
    scanf("%d", &user->id);
    scanf("%s %s %s", user->name, user->htel, user->tel);

    printf("%d %s %s %s\n", user->id, user->name, user->htel, user->tel);

    char id_str[11];
    sprintf(id_str, "%d", user->id);

    FILE *fp;
    fp = fopen("./user.dat", "a+");
    if (!fp) {
        printf("Fail to open file!\n");
        exit(-1);
    }
    fprintf(fp, "%d %s %s %s\n", user->id, user->name, user->htel, user->tel);
    fclose(fp);
}

void output() {
    FILE *fp = fopen("./user.dat", "r");
    while (1) {
        User user;
        if (fscanf(fp,"%d %s %s %s", &user.id, user.name, user.htel, user.tel) == EOF) break;
        printf("%5d %10s %10s %10s\n", user.id, user.name, user.htel, user.tel);
    }
    fclose(fp);
}