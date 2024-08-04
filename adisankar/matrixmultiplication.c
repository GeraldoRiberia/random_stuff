#include<stdio.h>
int main()
{
    int n;
    printf("Enter matrix size : ");
    scanf("%d",&n);
    int b[n][n],a[n][n];
    int c[n][n],sum=0;
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
        for(int j =0;j<n;j++)
        {
            sum =0;
            for(int k =0; k<n;k++)
            {
                sum=sum +(a[i][k]*b[k][j]);
            }
            c[i][j]=sum;
        }
    }
    printf("\n");

    printf("The multiplied matrix : \n");
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            printf("%d  ",c[i][j]);
        }
        printf("\n");
    }

}