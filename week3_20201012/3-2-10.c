#include "ch02.h"

int main() {
    FILE *fp;
    char buffer[80];
    memset(buffer, 0, sizeof(buffer));

    fp = fopen("./test1.txt", "w");
    fputs("\tappends new information!", fp);

    fp = freopen("./test1.txt", "r", fp);
    fgets(buffer, sizeof(buffer), fp);
    printf("Content of file: %s\n", buffer);

    fclose(fp);
    return 0;
}