#include<stdio.h>
#include<unistd.h>
#include<math.h>
#include"03_math.h"


int main() {
    /*
    /// scanf and friends

    int a, b;
    char c;
    int result = scanf("%d, %c - %d", &a, &c, &b);
    printf("%d, %c - %d\n", a, c, b);
    printf("This is the result %d\n", );
    return 0;
    */

    /*
    /// pointers are defined by int *<var name> 

    int a, b;
    int *x = &a;
    int *y = &b;


    if (2 == scanf("%d %d", x, y))
    {
        printf("%f\n", pow(a, b));
    }

    return 0;
    */


    /*
    /// str is a pointer, don't reference it by *str
    /// char* is a pointer, so you don't point to it
    /// char* is obviously a type for pointers

    char *str;
    if (scanf("%s", str))
    {
        printf("%s\n", str);
    }

    return 0;
    */

    /*
    /// getline for multiple words separated by whitespace

    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    while ((nread = getline(&line, &len, stdin)) != 1)
    {
        printf("Retrieved line of length %zd:\n", nread);
        fwrite(line, nread, 1, stdout);
    }

    return 0;
    */

    /*
    /// Bitwise

    int a = 0b00011;
    int b = 0b01010;

    int c = a & c;

    printf("%d\n",c);

    */

    int a = 1;
    int b = 2;

    printf("%d\n", my_add(a, b));
}
