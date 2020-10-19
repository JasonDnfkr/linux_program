#include "ch03.h"

int main() {
    int d1;
    d1 = open("./out.info", O_CREAT|O_TRUNC|O_WRONLY, 0644);
    dup2(d1, 1);    //输出重定向，把打印在屏幕上的输出转到文件

    printf("Redirect stdout file!\n");
    return 0;
}