#include <stdio.h>
#include <stdlib.h>

//нерекурсивный способ

int main()
{
    int n, i, f, f_pre1, f_pre2;
    printf("Enter the number: ");
    scanf("%d", &n);
    if (n <= 0) printf("WRONG NUMBER\n");
    if (n == 1 || n == 2) printf("1\n");
    if (n > 2)
    {
        f_pre1 = 1;
        f_pre2 = 1;
        for (i = 3; i <= n; i++)
        {
            f = f_pre1 + f_pre2;
            f_pre2 = f_pre1;
            f_pre1 = f;
        }
        printf("%d\n", f);
    }
    return 0;
}
