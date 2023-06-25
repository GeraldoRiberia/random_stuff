#include <stdio.h>    
int main ()    
{    
    int n=3, sumd=0;
    int a[n][n];
    int tr[n][n];
    printf("Enter matrix elements");
    for(int i =0; i<n;i++)
    {
        for(int j =0; j<n; j++)
        {
            printf("[%d][%d]",i,j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("\n");
    int nc=n;
    for(int i =0; i<n;i++)
    {
        for(int j =0; j<n; j++)
        {
            tr[i][j]=a[j][i];
        }
    }
    printf(" Transpose : \n");
    for(int i =0; i<n;i++)
    {
        for(int j =0; j<n; j++)
        {
            printf("%d  ",tr[i][j]);
        }
        printf("\n");
    }


}