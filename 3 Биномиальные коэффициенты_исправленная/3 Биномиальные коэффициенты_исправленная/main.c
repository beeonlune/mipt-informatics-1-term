#include <stdio.h>
#include <stdlib.h>

int binom2(int n, int k, long int mult, long int div)
{
    if (k == 0 || k == n)
        return mult/div;
    if (k > n)
        return 0;
    mult = mult * n;
    div = div * k;
    return binom2(n - 1, k - 1, mult, div);
}

int main()
{
    int n, k;
    long int mult = 1, div = 1;
    printf("Enter n and k (n > k): \n");
    scanf("%d%d", &n, &k);
    if (n < 0 || k < 0 || k > n)
    {
        printf("WRONG NUMBERS\n");
        return 0;
    }
    printf("%d\n", binom2(n, k, mult, div));
    return 0;
}
