#include <stdio.h>
#include <stdlib.h>

//рекурсивный способ

int fib(int n)
{
    if (n == 1 || n == 2) return(1);
    else return(fib(n-1)+fib(n-2));
}

int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    if (n <= 0) printf("WRONG NUMBER\n");
    else printf("%d\n", fib(n));
    return 0;
}
