/*
4014013109 - Nosrati
4014013055 - Soltanolkottabi
4014013059 - Salimi
*/
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
    printf("I'm Father, Me: %d, Parent: %d\n", getpid(), getppid());
    pid_t child_A = fork();

    if (0 == child_A)
    {
        // Child A
        printf("I'm child A Me: %d, Parent: %d\n", getpid(), getppid());
        pid_t child_C = fork();
        if (0 == child_C)
        {
            printf("I'm child C Me: %d, Parent: %d\n", getpid(), getppid());
        }
    }
    else
    {
        // Parent
        pid_t child_B = fork();
        if (0 == child_B)
        {
            // Child B
            printf("I'm child B Me: %d, Parent: %d\n", getpid(), getppid());

            pid_t child_D = fork();
            if (0 == child_D)
            {
                printf("I'm child D Me: %d, Parent: %d\n", getpid(), getppid());
            }
            else
            {
                pid_t child_E = fork();
                if (0 == child_E)
                {
                    printf("I'm child E Me: %d, Parent: %d\n", getpid(), getppid());
                }
            }
        }
    }
    return 0;
}