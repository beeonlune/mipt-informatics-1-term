#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char check(char **s)
{
    char wait;
    char c = *(*s)++;
    switch(c)
    {
        case '{': wait = '}'; break;
        case '[': wait = ']'; break;
        case '(': wait = ')'; break;
        case '<': wait = '>'; break;
        case '}': case ']': case ')': case '>': case '\0': return c;
        default:
            return check(s);
    }
    return check(s) != wait ? -1 : check(s);
}

int main()
{
    char buf[10000];
    char *s = fgets(buf, sizeof(buf), stdin);
    int i, j, flag = 0, k;
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == '\"')
            for (j = i + 1; j < strlen(s); j++)
            {
                if (s[j] == '\"')
                {
                    flag = 1;
                    break;
                }
            }
        if (flag == 1)
            break;
    }

    if (flag == 1)
    {
        for (k = i; k < j; k++)
        {
            if (s[k] == '(' || s[k] == '{' || s[k] == '[' || s[k] == '<' || s[k] == ')' || s[k] == '}' || s[k] == ']' || s[k] == '>')
                s[k] = 'a';
        }
    }
    if (!check(&s))
        printf("OK\n");
    else
        printf("NOT OK\n");
    return 0;
}

