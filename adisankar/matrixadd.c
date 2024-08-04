#include<stdio.h>
int main()
{
    int r,c;
    printf("Enter no of rows and columns");
    scanf("%d %d",&r,&c);
    int a[100][100],b[100][100];
    int s[100][100];
    printf("Enter matrix a");
    for(int i =0; i<r;i++)
    {
        for(int j =0;j<c; j++)
        {
            printf("a[%d][%d]",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter matrix b");
    for(int i =0; i<r;i++)
    {
        for(int j =0;j<c; j++)
        {
            printf("b[%d][%d]",i,j);
            scanf("%d",&b[i][j]);
        }
    }

    for(int i =0; i<r;i++)
    {
        for(int j =0;j<c; j++)
        {
            int sum = a[i][j]+b[i][j];
            s[i][j]=sum;
        }
    }
    for(int i =0; i<r;i++)
    {
        for(int j =0;j<c; j++)
        {
            printf("%d \t",s[i][j]);
        }
        printf("\n");
    }

    return 0;
}