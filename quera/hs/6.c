#include <stdio.h>

int 
factorial(int num)
{
    if (num == 0)
    {
    return 1;
    }
    return num * factorial(num - 1);
}

int 
main()
{
    int number;
    scanf("%d", &number);
    printf("%d\n", factorial(number));
    return 0;
}