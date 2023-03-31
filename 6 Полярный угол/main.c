#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x1, x2, y1, y2;
    double alpha;
    printf("Enter the coordinates of the vectors: first the x and y coordinates of the first vector, then the second: ");
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if ((x1 == 0 && y1 == 0) || (x2 == 0 && y2 == 0))
        printf("\n0.00\n");
    else
    {
        alpha = (x1 * x2 + y1 * y2)/(sqrt(x1 * x1 + y1 * y1) * sqrt(x2 * x2 + y2*y2));
        printf("\n%.2lf\n", acos(alpha));
    }
    return 0;
}
