#include "ch02.h"

int main(int argc, char **argv) {
    FILE *fp;
    char buffer[80];
    int ret;
    memset(buffer, '\0', sizeof(argv));
    if ((fp = fopen("./test1.txt", "w")) == NULL) {
        perror("open failed!\n");
    }

    for (int i = 0; i < argc; i++) {
        strcat(buffer, argv[i]);
        strcat(buffer, "\n");
    }

    // fgets(buffer, sizeof(buffer), stdin);
    printf("Content is %s\nThe size of stream is %ld bytes/ \n",  buffer, sizeof(buffer));
    
    ret = fwrite(buffer, 4, sizeof(buffer) / 4, fp);

    printf("Actual writing times: %d\n", ret);

    fclose(fp);
    return 0;
}