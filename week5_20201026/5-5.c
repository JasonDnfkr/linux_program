#include "ch05.h"

int main() {
    char buf[20];
    int ret;

    FILE *fp = fopen("./tmp.txt", "w+");
    if (!fp) {
        printf("Fail to open file!\n");
        exit(-1);
    }
    ret = fwrite("123", sizeof("123"), 1, fp); //文件指针被拨动，所以读不出来
    printf("We wrote %d block\n", ret);

    memset(buf, 0, sizeof(buf));
    
    fseek(fp, 0, SEEK_SET);
    ret = fread(buf, sizeof("123"), 1, fp);
    printf("We read %s, ret is %d\n", buf, ret);

    fwrite("456", sizeof("456"), 1, fp);
    fclose(fp);

    printf("\n");

    return 0;
}