/*


# RAM

## PCB

|----------------------|
|                      |
|        Heap          |
|----------------------|
|                      |
|                      |
|                      |
|                      |
|----------------------|
|                      |
|                      |
|                      |
|----------------------|
|                      |
|        STACK         |
|                      |
|----------------------|
|                      |
|   Global Variables   |
|                      |
|----------------------|
|                      |
|        Text          |
|                      |
------------------------

What's in there?

- Text
- Global Variables
- Stack
- Heap
*/

/*
# What goes where?


// It's inside GLOBAL VARIABLES
int b = 2;

// It's inside the HEAP
const char *name = "David";

int
main()
{
    // Both are at stack
    int a = 0;

    int *c = &a;
}
*/

/*
#include<stdlib.h>
#include<stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    int b[a];

    return 0;
}

*/

/*
// int input is defined twice,
// once inside TEXT and once inside
// STACK. How to prevent it?
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int input;
    scanf("%d", &input);
    // malloc return an address
    int *a = (int *)malloc(sizeof(int) * input);
    free(a);
    return 0;
}
*/

/*
Fork

POSIX -> Mac, Linux, Solaris etc
*/

#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>

int 
main()
{
    printf("I'm Father, Me: %d, Parent: %d\n", getpid(), getppid());
    pid_t child_A = fork();

    if (0 == child_A) {
        // Child A
        printf("I'm child A Me: %d, Parent: %d\n", getpid(), getppid());
        pid_t child_C = fork();
        if (0 == child_C) {
            printf("I'm child C Me: %d, Parent: %d\n", getpid(), getppid());
        }
    }
    else {
        // Parent
        pid_t child_B = fork();
        if (0 == child_B) {
            // Child B
            printf("I'm child B Me: %d, Parent: %d\n", getpid(), getppid());

            pid_t child_D = fork();
            if (0 == child_D) {
                printf("I'm child D Me: %d, Parent: %d\n", getpid(), getppid());
            }
            else {
                pid_t child_E = fork();
                if (0 == child_E) {
                    printf("I'm child E Me: %d, Parent: %d\n", getpid(), getppid());
                }
            }
        }
    }
    return 0;
}