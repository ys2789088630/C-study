#include <stdio.h>
#include <string.h>

int is_palindrome(const char *s, int len)
{
    for (int i = 0; i < len / 2; ++i)
        if (s[i] != s[len - 1 - i])
            return 0;
    return 1;
}

int main(void)
{
    int n;
    if (scanf("%d ", &n) != 1) return 0;  

    for (int k = 0; k < n; ++k)
    {
        char buf[256];               
        if (!fgets(buf, sizeof(buf), stdin)) break;
        buf[strcspn(buf, "\n")] = '\0';   

        int len = strlen(buf);
        printf("%s\n", is_palindrome(buf, len) ? "YES" : "NO");
    }
    return 0;
}