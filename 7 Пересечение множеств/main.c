#include <stdio.h>
#include <stdlib.h>

//в первой строке файла - элементы первого множества
//во второй строке файла - элементы второго множества

int main()
{
    int A[1000] = {0}, B[1000] = {0}, C[1000] = {0}, i, a, k1 = 0, k2 = 0, k3 = 0, j, flag = 0;
    FILE *fin;
    fin = fopen("7 input.txt", "r");
    if (fin == NULL)
    {
        printf("Cannot open the file\n");
        return 0;
    }
    for (i = 0; i < 1000; i++)
    {
        fscanf(fin, "%d", &a);
        if (flag == 0 && a != -1)
        {
            A[k1] = a;
            k1 = k1 + 1;
        }
        if (a == -1 && flag == 1)
            break;
        if (a == -1 && flag == 0)
            flag = 1;
        else if (flag == 1 && a != -1)
            {
                B[k2] = a;
                k2 = k2 + 1;
            }
    }
    flag = 0;
    fclose(fin);
    for (i = 0; i < k1; i++)
    {
        for (j = 0; j < k2; j++)
        {
            if (A[i] == B[j])
            {
                for (a = 0; a < k3; a++)
                {
                    if (C[a] == A[i])
                        flag = 1;
                }
                if (flag == 0)
                {
                    C[k3] = A[i];
                    k3 = k3 + 1;
                }
            }
        }
    }

    FILE *fout;
    fout = fopen("7 output.txt", "w");
    if (fout == NULL)
    {
        printf("Cannot open the file\n");
        return 0;
    }
    if (k3 == 0)
        fprintf(fout, "Empty\n");
    else
        for (i = 0; i < k3; i++)
        {
            fprintf(fout, "%d ", C[i]);
        }
    fclose(fout);
    return 0;
}
