#include <stdio.h>


// write a function that recieves an integer n
// and then starts from 1 to n, printing + if it is 
// a fibonacchi number and - otherwise
int main() {
    int n;
    scanf("%d", &n);
    if (n == 1){
        printf("+\n");
        return 0;
    }
    else if (n == 2)
    {
        printf("+\n");
        return 0;
    }
    int a = 1;
    int b = 2;
    int c = a + b;
    printf("++");

    while (c <= n)
    {
        printf("+");
        a = b;
        b = c;
        c = a + b;
        for (int i = b + 1; i < c && i <= n; i++)
        {
            printf("-");
        }
    }
    printf("\n");
}