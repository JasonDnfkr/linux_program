#include "my.h"


int main() {
    const char *filename = "./user.dat";
    const char *filehelp = "./help.txt";
    
    // input();
    
    FILE *fp = fopen(filename, "a+");
    FILE *fp_help = fopen(filehelp, "r");
    char help_str[100];
    int key;
    // fscanf(fp_help, "%s", help_str);

    while (1) {
        puts("1: input()\n2: output()\n3: mysort()\n4: randdat()\n0: exit\n\nInput your choice:\n");
        

        scanf("%d", &key);
        fflush(stdin);
        switch (key) {
            case 0: 
                return 0;
            case 1:
                input();
                break;
            case 2:
                output(fp);
                break;
            case 3:
                mysort();
                break;
            case 4:
                randdat();
                break;
            default:
                break;
        }
    }
    return 0;
}

// 