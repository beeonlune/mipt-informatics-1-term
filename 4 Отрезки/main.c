#include <stdio.h>
#include <stdlib.h>
#define max_end 10000

typedef struct ty_otrezok
{
    int _beg;
    int _end;
} ty_otrezok;

int main()
{
    int quant, i, n = 0, k = 0;
    ty_otrezok *lt_otr;
    ty_otrezok ls_otr, ls_otrezok;
    printf("Enter the number of segments: ");
    scanf("%d", &quant);
    if (quant <= 0)
    {
        printf("No segments\n");
        return 0;
    }
    lt_otr = (ty_otrezok*)malloc(quant*sizeof(ty_otrezok));
    printf("Enter the coordinates of the segments: \n");
    for (i = 0; i < quant; i++)
    {
        scanf("%d %d", &ls_otr._beg, &ls_otr._end);
        if (ls_otr._beg <= max_end && ls_otr._end > 0)
            {
                lt_otr[k]._beg = ls_otr._beg;
                lt_otr[k]._end = ls_otr._end;
                k++;
            }
    }
    printf("\n");
    ls_otrezok._end = 0;
    ls_otrezok._beg = 0;
    while (ls_otrezok._end < max_end)
    {
        ls_otr = ls_otrezok;
        for (i = 0; i < k; i++)
        {
            if (lt_otr[i]._beg > ls_otr._end)
                continue;
            if (lt_otr[i]._end > ls_otrezok._end)
                ls_otrezok = lt_otr[i];
        }
        if (ls_otr._beg == ls_otrezok._beg && ls_otr._end == ls_otrezok._end)
            break;
        n = n + 1;
        printf("Segment (n = %d): [%d, %d] \n", n, ls_otrezok._beg, ls_otrezok._end); //отрезки
    }

    if (ls_otrezok._end >= max_end)
        printf("Number of covering segments: n = %d\n", n); //количество покрывающих отрезков
    else
        printf("Number of covering segments: n = 0\n");
    free(lt_otr);
}
