#include <stdio.h>

int main()
{
    int n, m, q;
    if (scanf("%d%d%d", &n, &m, &q) != 3) return 0;

    static int p[101][101];        
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            int x;
            scanf("%d", &x);
            p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + x;
        }

    while (q--)
    {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        int ans = p[x2][y2]
                - p[x1-1][y2]
                - p[x2][y1-1]
                + p[x1-1][y1-1];
        printf("%d\n", ans);
    }
    return 0;
}