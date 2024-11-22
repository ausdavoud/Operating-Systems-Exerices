#include<stdio.h>

int 
main() {
    int n;
    scanf("%d", &n);

    int tri[n][n];
    
    // first column
    for (int i = 0; i < n;i++){
        tri[i][0] = 1;
    }

    //diagonal
    for (int i = 0; i < n; i++)
    {
        tri[i][i] = 1;
    }

    //others
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j];
        }
    }

    //print array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", tri[i][j]);
        }
        printf("\n");
    }
}