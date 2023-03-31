#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_max_subc(char *str1, char *str2, int m, int n)
{
    int i, j, index, max_len = 0;
    int ARRAY[m + 1][n + 1];
    for (i = 0; i <= m; i++)
        ARRAY[i][0] = 0;
    for (j = 0; j <= n; j++)
        ARRAY[0][j] = 0;
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                ARRAY[i][j] = ARRAY[i - 1][j - 1] + 1;
            }
            else if (ARRAY[i - 1][j] >= ARRAY[i][j - 1])
            {
                ARRAY[i][j] = ARRAY[i - 1][j];
            }
            else
            {
                ARRAY[i][j] = ARRAY[i][j - 1];
            }
            if (max_len < ARRAY[i][j])
                max_len = ARRAY[i][j];
        }
    if (max_len == 0)
        printf("No common subsequence\n");
    else
    {
        index = ARRAY[m][n];
        char print_max_subc[index + 1];
        print_max_subc[index] = '\0';
        i = m;
        j = n;
        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                print_max_subc[index - 1] = str1[i - 1];
                i--;
                j--;
                index--;
            }
            else if (ARRAY[i - 1][j] > ARRAY[i][j - 1])
                i--;
            else
                j--;
        }
        printf("Longest common subsequence: %s\n", print_max_subc);
    }
}

int main()
{
    char *str1 = (char*)malloc((1025) * sizeof(char));
    char *str2 = (char*)malloc((1025) * sizeof(char));
    int m, n;
    printf("Enter the sequences: \n"); //каждая с новой строки
    gets(str1);
    m = strlen(str1);
    gets(str2);
    n = strlen(str2);
    print_max_subc(str1, str2, m, n);
    free(str1);
	free(str2);
	return 0;
}
