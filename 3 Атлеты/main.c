#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct athlets
{
    int m, p;
} athlets;

int compare(const void *aa, const void *bb)
{
    athlets *a = (athlets *)aa;
    athlets *b = (athlets *)bb;
    return (a->m == b->m ? a->p - b->p : a->m - b->m);
}

int main()
{
    int n, i;
    athlets *mass;
    scanf("%d", &n);
    mass = (athlets*)malloc(n*sizeof(athlets));
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &mass[i].m, &mass[i].p);
    }
    qsort(mass, n, sizeof(athlets), compare); //сортировка массы по возрастанию. Дальнейшая сортировка не нужна, т.к. если атлет тяжелее, то он точно сильнее (по условию)
    for (i = 0; i < n; i++)
    {
        printf("%d %d\n", mass[i].m, mass[i].p);
    }
    free(mass);
    return 0;
}
