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
    pid_t child_A = fork();

    if (0 == child_A)
    {
        // Child A
        printf("I'm child A. Me: %d\n", getpid());
        pid_t child_C = fork();
        if (0 == child_C)
        {
            printf("I'm child C. Me: %d\n", getpid());
        }
        else {
            printf("I'm Father. Me: %d, Child C: %d\n", getpid(), child_C);
        }
    }
    else
    {
        printf("I'm Father, Me: %d, child A: %d\n", getpid(), child_A);
        // Parent
        pid_t child_B = fork();

        if (0 == child_B)
        {
            // Child B
            printf("I'm child B Me: %d\n", getpid());

            pid_t child_D = fork();
            if (0 == child_D)
            {
                printf("I'm child D Me: %d\n", getpid());
            }
            else
            {
                printf("I'm Father, Me: %d, Child D: %d\n", getpid(), child_D);
                pid_t child_E = fork();
                if (0 == child_E)
                {
                    printf("I'm child E Me: %d\n", getpid());
                }
                else {
                    printf("I'm Father, Me: %d, Child E: %d\n", getpid(), child_E);
                }
            }
        }
        else {
            printf("I'm Father, Me: %d, Child B: %d\n", getpid(), child_B);
        }
    }
    return 0;
}