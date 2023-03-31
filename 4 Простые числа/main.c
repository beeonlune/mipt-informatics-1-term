#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//сложность - O(sqrt(N))

int is_prime(int n)
{
    int i;
    if (abs(n) < 2) return 0;
    else
    {
        for (i = 2; i*i <= abs(n); i++)
        {
            if (abs(n) % i == 0) return 0;
        }
        return 1;
    }
}

int main()
{
    int n;
    printf("Enter the number: \n");
    scanf("%d", &n);
    if (is_prime(n) == 1) printf("YES\n"); //простое
    else printf("NO\n");                   //не простое
    return 0;
}
