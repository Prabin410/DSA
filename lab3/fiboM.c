#include <stdio.h>
long int table[100] = {0};
long int fiboM(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
    {
        if (table[n] == 0)
        {
            table[n] = fiboM(n - 1) + fiboM(n - 2);
        }
        return table[n];
    }
}
long int fibo(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return fibo(n - 1) + fibo(n - 2);
}

int main()
{
    int n;
    printf("Enter n ");
    scanf("%d", &n);
    long int result = fiboM(n);
    printf("%ld\n", result);
    return 0;
}