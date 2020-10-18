#include "ch02.h"

int main() {
    FILE *fp;
    char buffer[80];
    int ret;
    memset(buffer, 0, sizeof(buffer));
    if ((fp = fopen("./test1.txt", "w")) == NULL) {
        perror("open failed!\n");
    }
    fgets(buffer, sizeof(buffer), stdin);
    printf("Content is %s\nThe size of stream is %ld bytes/ \n",  buffer, sizeof(buffer));
    
    ret = fwrite(buffer, sizeof(buffer), sizeof(buffer[0]), fp);

    printf("Actual writing number: %d\n", ret);

    fclose(fp);
    return 0;
}