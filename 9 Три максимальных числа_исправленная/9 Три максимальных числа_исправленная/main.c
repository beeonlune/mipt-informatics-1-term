#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, max1 = -32000, max2 = -32000, max3 = -32000, min1 = 32000, min2 = 32000, num, i, p1, p2;
    printf("Enter the quantity of numbers: ");
    scanf("%d", &n);
    if (n < 3)
    {
        printf("Error: not enough numbers!\n");
        return 0;
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num);
        if (num >= max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = num;
        }

        else if (num >= max2)
        {
            max3 = max2;
            max2 = num;
        }
        else if (num >= max3)
            max3 = num;
        if (num <= min1)
        {
            min2 = min1;
            min1 = num;
        }
        else if (num <= min2)
            min2 = num;
    }
    p1 = max1 * max2 * max3;
    p2 = max1 * min1 * min2;
    if (p1 >= p2)
        printf("%d, %d, %d\n", max1, max2, max3);
    else
        printf("%d, %d, %d\n", max1, min1, min2);
    return 0;
}
