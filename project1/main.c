#include "my.h"


int main() {
    const char *filename = "./user.dat";
    
    // input();
    
    FILE *fp = fopen(filename, "a+");
    // output(fp);
    mysort(fp);
    
    return 0;
}

// 