#include <stdio.h>
#include <sys/stat.h>

void write_word(FILE *fp, int n) {
    int x1 = n >> 24;
    int x2 = (n << 8)>>24;
    int x3 = (n << 16)>>24;
    int x4 = (n << 24)>>24;
    // char word[4];
    // snprintf(word,sizeof(word),"%c%c%c%c",x1,x2,x3,x4);
    fprintf(fp, "%c%c%c%c", x1, x2, x3, x4);
}

int file_size(char* filename) {
    struct stat statbuf;
    stat(filename, &statbuf);
    int size = statbuf.st_size;
    return size;
}

int main() {
    char* filename = "input1.txt";
    FILE *fp = NULL;
    fp = fopen(filename, "w+");

    write_word(fp, 3);
    write_word(fp, 1);
    write_word(fp, 2);
    write_word(fp, 3);

    write_word(fp, 5);
    write_word(fp, 6);
    write_word(fp, 6);
    write_word(fp, 7);
    write_word(fp, 7);
    write_word(fp, 7);
 
    fclose(fp);

    printf("%d", file_size(filename));
}