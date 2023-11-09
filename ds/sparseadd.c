#include<stdio.h>

int a1[10][3],a[10][10],m,n;

void sparse_tuple()
{
    int k =1;
    a1[0][0]=n;
    a1[0][1]=m;
    for(int i =0;i<n;i++)
    {
        for(int j =0; j<m;i++)
        {
            if(a[i][j]!=0)
            {
                a1[k][0]=i;
                a1[k][1]=j;
                a1[k][2]=a[i][j];
                k++;
            }
        }
    }
    a1[0][2]=k-1;
}
void display()
{
    for(int i =0; i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            if(j == a1[i][1]){
                printf("%d  ",a1[i][1]);
            }
            else{
                printf("0  ");
            }
        }
    }
}

void main()
{   
    printf("Enter number of rows and columns");
    scanf("%d %d",&n,&m);
    printf("Enter matrix");
    for(int i =0; i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    sparse_tuple();

}