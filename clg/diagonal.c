#include <stdio.h>    
int main ()    
{    
    int n=3, sumd=0;
    int b[n][n],a[n][n];
    int c[n][n],sum=0;
    printf("Enter matrix elements");
    for(int i =0; i<n;i++)
    {
        for(int j =0; j<n; j++)
        {
            printf("[%d][%d]",i,j);
            scanf("%d", &a[i][j]);
        }
    }

    for(int i =0; i<n;i++)
    {
        for(int j =0; j<n; j++)
        {
            if(i==j)
            {
                sumd= sumd+a[i][j];
            }
        }
    }

    printf("diagonal sum = %d",sumd);
    return 0;
}    