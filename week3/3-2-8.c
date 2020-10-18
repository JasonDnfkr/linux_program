#include "ch02.h"

int main() {
    FILE *fp;
    fp = fdopen(1, "w+");
    fprintf(fp, "test data %s\n", "hello world");
    fclose(fp);

    return 0;
}