#include <stdio.h> 
#include <math.h>

int
main () {
    int a, b, c;
    scanf("%d\n%d\n%d", &a, &b, &c);

    int con1 = pow(a, 2) == pow(b, 2) + pow(c, 2);
    int con2 = pow(b, 2) == pow(a, 2) + pow(c, 2);
    int con3 = pow(c, 2) == pow(a, 2) + pow(b, 2);

    if (con1 || con2 || con3)
    {
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}