#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define TRUE 1

void set_zero(int a){
    a = 0;
}

/**
 * @brief The main function
 * @author Davoud 
 * @return an integer as state
 * @param void - nothing
*/
int main() {
    // AND OPERATOR
    /*
        &: checks both states
        &&: fast fail
    */
    
    // SWITCH
    /* switch (expression)
    {
    case constant-expression:
        code
        break;
    
    default:
        break;
    } */

    
    /* for (int i = 0; i < 10; i++)
    {
    
    } */

    // GO TO
    /* goto exit_failure;
    int a = 1;

    puts("hello");

exit:
    return 0;
exit_failure:
    return 1; */

    // POINTER
    int a = 1;

    printf("This is a: %d\n", a);

    set_zero(a);

    printf("This is a: %d\n", a);

    return 0;
}