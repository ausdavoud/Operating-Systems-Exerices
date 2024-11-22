#include <stdio.h>
#include <math.h>

// write a method for combination 
int combination(int n, int k)
{
    if (k == 0 || k == n)
    {
        return 1;
    }
    return combination(n - 1, k - 1) + combination(n - 1, k);
}

int main()
{
    int a, x, n;
    scanf("%d %d %d", &a, &x, &n);

    int sum = 0;
    for (int k = 0; k <= n; k++)
    {
        sum += combination(n, k) * pow(x, k) * pow(a, n - k);
    }

    printf("%d\n", sum);
}