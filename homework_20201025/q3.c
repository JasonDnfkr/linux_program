#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>



int read_word(FILE *fp) {
    int n = 0;
    int x1 = fgetc(fp);
    int x2 = fgetc(fp);
    int x3 = fgetc(fp);
    int x4 = fgetc(fp);
    n = (x1 << 24) + (x2 << 16) + (x3 << 8) + x4;
    return n;
}

int main() {
    char* filename = "input1.txt";
    int k = 0;   
    int m = 0;
    int i,j;
    FILE *fp = NULL;
    fp = fopen(filename, "r");

    int n = read_word(fp);
    int *array;
    array = (int*)malloc(n * sizeof(int));

    for(i = 0; i < n; i++){
        array[i] = read_word(fp);
    }
    printf("在%d个记录中,想输出第几个数据：",n);
    scanf("%d", &k);
    for(int i = 0; i < k - 1; i++){
        fseek(fp, 4 * array[i], SEEK_CUR);
    }

    for(j = 0; j < array[k - 1]; j++){
        printf("%d", read_word(fp));
    }
    printf("\n");

    fclose(fp);
    return 0;
}