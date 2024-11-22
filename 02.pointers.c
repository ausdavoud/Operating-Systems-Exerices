#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void set_zero(int a)
{
    int p_two = a * a;
    int p_three = p_two * a;
}

/**
 * @brief The main function
 * @author Davoud
 * @return an integer as state
 * @param void - nothing
 */
int main()
{
    int a = 1;
    int *c = &a;
    int **b = &c;

    char *s = "OS";
    char r[6] = "Hello";
    printf("This is s: %s\n", r);
    r[2] = '3';
    printf("This is s: %s\n", r);

    printf("This is s: %s\n", s);
    s = "Meow";
    printf("This is s: %s\n", s);

    return 0;
}