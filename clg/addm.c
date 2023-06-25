#include<stdio.h>
int main()
{
    int n=3;
    int a[n][n],b[n][n];
    int c[n][n];
    printf("Enter 1 matrix elements");
    for(int i =0; i<n;i++)
    {
        for(int j =0; j<n; j++)
        {
            printf("[%d][%d]",i,j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter 2 matrix elements");
    for(int i =0; i<n;i++)
    {
        for(int j =0; j<n; j++)
        {
            printf("[%d][%d]",i,j);
            scanf("%d", &b[i][j]);
        }
    }

    for(int i =0; i<n;i++)
    {
        for(int j =0; j<n; j++)
        {
            c[i][j] =a[i][j]+b[i][j];
        }
    }

    printf(" Added matrix : \n");
    for(int i =0; i<n;i++)
    {
        for(int j =0; j<n; j++)
        {
            printf("%d  ",c[i][j]);
        }
        printf("\n");
    }
    
}