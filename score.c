#include <stdio.h>

int main()
{
    int n, score,i,grade;
    int cnt[11] = {0};
    scanf("%d", &n);
    for (i = 0;i < n; i++){
        scanf("%d", &score);
        if (score < 0 || score > 100)
        continue;
        grade = score / 10;
        cnt[grade]++;

    }

    for (i = 0; i < 11; i++){
        printf("%d:%d\n", i, cnt[i]);
    }

    return 0;
}