#include <stdio.h>

int Add(int x, int y)
{
    return x + y;
}

int main(void)
{
    int a = 10;
    int b = 20;
    int c = Add(a, b);   // 用函数完成加法
    printf("%d\n", c);
    return 0;
}