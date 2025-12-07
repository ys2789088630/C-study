#include <stdio.h>

int main(void)
{
    int N, i, rise = 0, down = 0;
    double temp[24], max, min, sum = 0.0;

    printf("请输入温度数据的数量N：");
    scanf("%d", &N);

    for (i = 0; i < N; ++i) {
        printf("请输入第%d小时的温度数据（摄氏度）：", i + 1);
        scanf("%lf", &temp[i]);
        sum += temp[i];
        if (i == 0) { max = min = temp[0]; }
        else {
            if (temp[i] > max) max = temp[i];
            if (temp[i] < min) min = temp[i];
            if (temp[i] > temp[i - 1]) ++rise;
            if (temp[i] < temp[i - 1]) ++down;
        }
    }

    printf("当天的最高温度为：%.2f\n", max);
    printf("当天的最低温度为：%.2f\n", min);
    printf("所有温度数据的平均值为：%.2f\n", sum / N);
    printf("温度升高的次数为：%d\n", rise);
    printf("温度降低的次数为：%d\n", down);

    return 0;
}