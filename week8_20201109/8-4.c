#include "./ch08.h"

static void func1();
static void func2();
static jmp_buf g_stack_env;

/*
    setjmp(..)
    1 设定回跳点
      并将回跳的变量内容入栈
    2 返回值为 0

    longjmp(.., ..,)
    1 从longjmp处跳至setjmp处
    2 返回值为 1
*/

int main() {
    if (setjmp(g_stack_env) == 0) {
        printf("main() Normal flow!\n");
        func1();
        printf("Normal flow back from func1!\n");
    }
    else {
        printf("Back from long jump!\n");
    }

    // printf("main() continue!\n");

    return 0;
}

static void func1() {
    printf("Enter func1!\n");
    func2();
    printf("Leave func1!\n");
}

static void func2() {
    printf("Enter func2!\n");
    longjmp(g_stack_env, 1);
    printf("Leave func2!\n");
}