#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max_of_three(double a, double b, double c)
{
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    else if (c >= a && c >= b)
        return c;
}

int main()
{
    double Xa, Ya, Xb, Yb, Xc, Yc, Xd, Yd, ab, ac, ad;
    FILE *fin;
    fin = fopen("1 input.txt", "r");
    if (fin == NULL)
    {
        printf("Cannot open the file\n");
        return 0;
    }
    fscanf(fin, "%lf %lf %lf %lf %lf %lf %lf %lf", &Xa, &Ya, &Xb, &Yb, &Xc, &Yc, &Xd, &Yd);
    ab = sqrt((Xb - Xa)*(Xb - Xa) + (Yb - Ya)*(Yb - Ya));
    ac = sqrt((Xc - Xa)*(Xc - Xa) + (Yc - Ya)*(Yc - Ya));
    ad = sqrt((Xd - Xa)*(Xd - Xa) + (Yd - Ya)*(Yd - Ya));
    printf("The area of the rectangle is approximately equal to %.2lf\n", ab * ac * ad / max_of_three(ab, ac, ad));
    fclose(fin);
    return 0;
}
