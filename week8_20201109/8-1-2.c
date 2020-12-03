#include "./ch08.h"

void recursion(int x) {
    int a, b;
    
    if (x % 32 == 0) {
        printf("recursion: %d ADDRESS: [a = %x] [b = %x]\n", x, &a, &b);
    }
    recursion(x + 1);
}

int main() {
    recursion(1);
    return 0;
}