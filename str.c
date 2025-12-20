#include <stdio.h>

int main()
{
    int c, cnt =0;
    while ((c = getchar())!= EOF && c != '\n'){
        cnt++;
    }

    printf("%d",cnt);
    return 0;
}