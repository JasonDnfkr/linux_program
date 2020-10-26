#include "my.h"

void input(User *user) {
    scanf("%d", user->id);
    scanf("%s %s %s", user->name, user->htel, user->tel);

    printf("%d %s %s %s\n", user->id, user->name, user->htel, user->tel);
}
