#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char *Pythagoras(int a, int b, int c)
{
    if (a > b && a > c)
    {
        if (pow(a, 2) == pow(b, 2) + pow(c, 2))
        {
            return "YES";
        }
        else
        {
            return "NO";
        }
    }
    else if (b > a && b > c)
    {
        if (pow(b, 2) == pow(a, 2) + pow(c, 2))
        {
            return "YES";
        }
        else
        {
            return "NO";
        }
    }
    else
    {
        if (pow(c, 2) == pow(a, 2) + pow(b, 2))
        {
            return "YES";
        }
        else
        {
            return "NO";
        }
    }
}

int main()
{
    int a;
    int b;
    int c;
    scanf("%d\n%d\n%d", &a, &b, &c);
    printf("result: %s\n", Pythagoras(a, b, c));
}