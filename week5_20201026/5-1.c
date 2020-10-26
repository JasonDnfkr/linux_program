#include "ch05.h"
int main() {
	printf("hello world");
	while (1); //printf()是行缓冲，在return之前一直没有释放，所以没有输出
	return 0;
}

