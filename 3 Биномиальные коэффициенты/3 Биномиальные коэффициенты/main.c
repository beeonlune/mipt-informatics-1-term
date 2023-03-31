#include <stdio.h>
#include <stdlib.h>

int binom(int n, int k)
{
    if (k == 0 || k == n) return 1;
    if (k > n) return 0;
    else return (binom(n-1, k-1) + binom(n-1, k));
}

int main()
{
    int n, k;
    printf("Enter n and k (n > k): \n");
    scanf("%d%d", &n, &k);
    if (n < 0 || k < 0 || k > n) printf("WRONG NUMBERS\n");
    else printf("%d\n", binom(n, k));
    return 0;
}
