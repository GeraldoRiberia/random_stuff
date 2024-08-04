#include<stdio.h>
void main()
{
    int a[30],n;
    printf("Enter array size");
    scanf("%d",&n);
    for(int i =0; i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    for(int i =0; i<n-1;i++)
    {
        for(int j =0; j<n-1-i; j++)
        {
            if(a[j]>a[j+1])
            {
                a[j]=a[j]+a[j+1];
                a[j+1]=a[j]-a[j+1];
                a[j]=a[j]-a[j+1];
            }
        }
    }

    for(int i =0; i<n;i++)
    {
        printf("%d, ",a[i]);
    }
    
}