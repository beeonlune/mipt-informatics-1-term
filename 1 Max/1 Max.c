#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, max, i, a, b; //max - максимальное число, a - считываемое в данный момент число
    printf("Enter the quantity of numbers: ");
    scanf("%d", &n);
    if (n > 0)
    {
        printf("\nEnter the numbers: \n");
        scanf("%d", &b);
        max = b;
        for (i = 0; i < n - 1; i++)
        {
            scanf("%d", &a);
            if (a > max)
                max = a;
        }
        printf("\nMax number: %d\n", max);
    }
    else
        printf("No numbers\n");
    return 0;
}

