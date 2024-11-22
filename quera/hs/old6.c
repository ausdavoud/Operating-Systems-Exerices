#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Factorial(int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result = result * i;
    }
    return result;
}

int Combination(int n, int r)
{
    int result;
    result = Factorial(n) / (Factorial(n - r) * Factorial(r));
    return result;
}

int calculate(int a, int x, int n)
{
    int result;
    for (int k = 0; k <= n; k++)
    {
        result = result + (Combination(n, k) * pow(x, k) * pow(a, n - k));
    }
    return result;
}

int main()
{
    int a;
    int x;
    int n;
    scanf("%d %d %d", &a, &x, &n);
    printf("%d", calculate(a, x, n));
}